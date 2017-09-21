begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 John Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RWLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RWLOCK_H_
end_define

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_rwlock.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock_profile.h>
end_include

begin_include
include|#
directive|include
file|<sys/lockstat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The rw_lock field consists of several fields.  The low bit indicates  * if the lock is locked with a read (shared) or write (exclusive) lock.  * A value of 0 indicates a write lock, and a value of 1 indicates a read  * lock.  Bit 1 is a boolean indicating if there are any threads waiting  * for a read lock.  Bit 2 is a boolean indicating if there are any threads  * waiting for a write lock.  The rest of the variable's definition is  * dependent on the value of the first bit.  For a write lock, it is a  * pointer to the thread holding the lock, similar to the mtx_lock field of  * mutexes.  For read locks, it is a count of read locks that are held.  *  * When the lock is not locked by any thread, it is encoded as a read lock  * with zero waiters.  */
end_comment

begin_define
define|#
directive|define
name|RW_LOCK_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|RW_LOCK_READ_WAITERS
value|0x02
end_define

begin_define
define|#
directive|define
name|RW_LOCK_WRITE_WAITERS
value|0x04
end_define

begin_define
define|#
directive|define
name|RW_LOCK_WRITE_SPINNER
value|0x08
end_define

begin_define
define|#
directive|define
name|RW_LOCK_FLAGMASK
define|\
value|(RW_LOCK_READ | RW_LOCK_READ_WAITERS | RW_LOCK_WRITE_WAITERS |	\ 	RW_LOCK_WRITE_SPINNER)
end_define

begin_define
define|#
directive|define
name|RW_LOCK_WAITERS
value|(RW_LOCK_READ_WAITERS | RW_LOCK_WRITE_WAITERS)
end_define

begin_define
define|#
directive|define
name|RW_OWNER
parameter_list|(
name|x
parameter_list|)
value|((x)& ~RW_LOCK_FLAGMASK)
end_define

begin_define
define|#
directive|define
name|RW_READERS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RW_READERS
parameter_list|(
name|x
parameter_list|)
value|(RW_OWNER((x))>> RW_READERS_SHIFT)
end_define

begin_define
define|#
directive|define
name|RW_READERS_LOCK
parameter_list|(
name|x
parameter_list|)
value|((x)<< RW_READERS_SHIFT | RW_LOCK_READ)
end_define

begin_define
define|#
directive|define
name|RW_ONE_READER
value|(1<< RW_READERS_SHIFT)
end_define

begin_define
define|#
directive|define
name|RW_UNLOCKED
value|RW_READERS_LOCK(0)
end_define

begin_define
define|#
directive|define
name|RW_DESTROYED
value|(RW_LOCK_READ_WAITERS | RW_LOCK_WRITE_WAITERS)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|rw_recurse
value|lock_object.lo_data
end_define

begin_comment
comment|/* Very simple operations on rw_lock. */
end_comment

begin_comment
comment|/* Try to obtain a write lock once. */
end_comment

begin_define
define|#
directive|define
name|_rw_write_lock
parameter_list|(
name|rw
parameter_list|,
name|tid
parameter_list|)
define|\
value|atomic_cmpset_acq_ptr(&(rw)->rw_lock, RW_UNLOCKED, (tid))
end_define

begin_comment
comment|/* Release a write lock quickly if there are no waiters. */
end_comment

begin_define
define|#
directive|define
name|_rw_write_unlock
parameter_list|(
name|rw
parameter_list|,
name|tid
parameter_list|)
define|\
value|atomic_cmpset_rel_ptr(&(rw)->rw_lock, (tid), RW_UNLOCKED)
end_define

begin_comment
comment|/*  * Full lock operations that are suitable to be inlined in non-debug  * kernels.  If the lock cannot be acquired or released trivially then  * the work is deferred to another function.  */
end_comment

begin_comment
comment|/* Acquire a write lock. */
end_comment

begin_define
define|#
directive|define
name|__rw_wlock
parameter_list|(
name|rw
parameter_list|,
name|tid
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {				\ 	uintptr_t _tid = (uintptr_t)(tid);				\ 						                        \ 	if ((rw)->rw_lock != RW_UNLOCKED || !_rw_write_lock((rw), _tid))\ 		_rw_wlock_hard((rw), _tid, (file), (line));		\ 	else 								\ 		LOCKSTAT_PROFILE_OBTAIN_LOCK_SUCCESS(LS_RW_WLOCK_ACQUIRE, \ 		    rw, 0, 0, (file), (line));				\ } while (0)
end_define

begin_comment
comment|/* Release a write lock. */
end_comment

begin_define
define|#
directive|define
name|__rw_wunlock
parameter_list|(
name|rw
parameter_list|,
name|tid
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {				\ 	uintptr_t _tid = (uintptr_t)(tid);				\ 									\ 	if ((rw)->rw_recurse)						\ 		(rw)->rw_recurse--;					\ 	else if (!_rw_write_unlock((rw), _tid))				\ 		_rw_wunlock_hard((rw), _tid, (file), (line));		\ } while (0)
end_define

begin_comment
comment|/*  * Function prototypes.  Routines that start with _ are not part of the  * external API and should not be called directly.  Wrapper macros should  * be used instead.  */
end_comment

begin_function_decl
name|void
name|_rw_init_flags
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_rw_destroy
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rw_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rw_sysinit_flags
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_rw_wowned
parameter_list|(
specifier|const
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_rw_wlock_cookie
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rw_try_wlock
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_rw_wunlock_cookie
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__rw_rlock
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rw_try_rlock
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_rw_runlock_cookie
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__rw_wlock_hard
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|uintptr_t
name|tid
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__rw_wunlock_hard
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|uintptr_t
name|tid
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rw_try_upgrade
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__rw_downgrade
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
end_if

begin_function_decl
name|void
name|__rw_assert
parameter_list|(
specifier|const
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|int
name|what
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Top-level macros to provide lock cookie once the actual rwlock is passed.  * They will also prevent passing a malformed object to the rwlock KPI by  * failing compilation as the rw_lock reserved member will not be found.  */
end_comment

begin_define
define|#
directive|define
name|rw_init
parameter_list|(
name|rw
parameter_list|,
name|n
parameter_list|)
define|\
value|_rw_init_flags(&(rw)->rw_lock, n, 0)
end_define

begin_define
define|#
directive|define
name|rw_init_flags
parameter_list|(
name|rw
parameter_list|,
name|n
parameter_list|,
name|o
parameter_list|)
define|\
value|_rw_init_flags(&(rw)->rw_lock, n, o)
end_define

begin_define
define|#
directive|define
name|rw_destroy
parameter_list|(
name|rw
parameter_list|)
define|\
value|_rw_destroy(&(rw)->rw_lock)
end_define

begin_define
define|#
directive|define
name|rw_wowned
parameter_list|(
name|rw
parameter_list|)
define|\
value|_rw_wowned(&(rw)->rw_lock)
end_define

begin_define
define|#
directive|define
name|_rw_wlock
parameter_list|(
name|rw
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|_rw_wlock_cookie(&(rw)->rw_lock, f, l)
end_define

begin_define
define|#
directive|define
name|_rw_try_wlock
parameter_list|(
name|rw
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__rw_try_wlock(&(rw)->rw_lock, f, l)
end_define

begin_define
define|#
directive|define
name|_rw_wunlock
parameter_list|(
name|rw
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|_rw_wunlock_cookie(&(rw)->rw_lock, f, l)
end_define

begin_define
define|#
directive|define
name|_rw_rlock
parameter_list|(
name|rw
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__rw_rlock(&(rw)->rw_lock, f, l)
end_define

begin_define
define|#
directive|define
name|_rw_try_rlock
parameter_list|(
name|rw
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__rw_try_rlock(&(rw)->rw_lock, f, l)
end_define

begin_define
define|#
directive|define
name|_rw_runlock
parameter_list|(
name|rw
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|_rw_runlock_cookie(&(rw)->rw_lock, f, l)
end_define

begin_define
define|#
directive|define
name|_rw_wlock_hard
parameter_list|(
name|rw
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__rw_wlock_hard(&(rw)->rw_lock, t, f, l)
end_define

begin_define
define|#
directive|define
name|_rw_wunlock_hard
parameter_list|(
name|rw
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__rw_wunlock_hard(&(rw)->rw_lock, t, f, l)
end_define

begin_define
define|#
directive|define
name|_rw_try_upgrade
parameter_list|(
name|rw
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__rw_try_upgrade(&(rw)->rw_lock, f, l)
end_define

begin_define
define|#
directive|define
name|_rw_downgrade
parameter_list|(
name|rw
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__rw_downgrade(&(rw)->rw_lock, f, l)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|_rw_assert
parameter_list|(
name|rw
parameter_list|,
name|w
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__rw_assert(&(rw)->rw_lock, w, f, l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Public interface for lock operations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_DEBUG
end_ifndef

begin_error
error|#
directive|error
error|LOCK_DEBUG not defined, include<sys/lock.h> before<sys/rwlock.h>
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LOCK_DEBUG
operator|>
literal|0
operator|||
name|defined
argument_list|(
name|RWLOCK_NOINLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|rw_wlock
parameter_list|(
name|rw
parameter_list|)
value|_rw_wlock((rw), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rw_wunlock
parameter_list|(
name|rw
parameter_list|)
value|_rw_wunlock((rw), LOCK_FILE, LOCK_LINE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rw_wlock
parameter_list|(
name|rw
parameter_list|)
define|\
value|__rw_wlock((rw), curthread, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rw_wunlock
parameter_list|(
name|rw
parameter_list|)
define|\
value|__rw_wunlock((rw), curthread, LOCK_FILE, LOCK_LINE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|rw_rlock
parameter_list|(
name|rw
parameter_list|)
value|_rw_rlock((rw), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rw_runlock
parameter_list|(
name|rw
parameter_list|)
value|_rw_runlock((rw), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rw_try_rlock
parameter_list|(
name|rw
parameter_list|)
value|_rw_try_rlock((rw), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rw_try_upgrade
parameter_list|(
name|rw
parameter_list|)
value|_rw_try_upgrade((rw), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rw_try_wlock
parameter_list|(
name|rw
parameter_list|)
value|_rw_try_wlock((rw), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rw_downgrade
parameter_list|(
name|rw
parameter_list|)
value|_rw_downgrade((rw), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|rw_unlock
parameter_list|(
name|rw
parameter_list|)
value|do {						\ 	if (rw_wowned(rw))						\ 		rw_wunlock(rw);						\ 	else								\ 		rw_runlock(rw);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|rw_sleep
parameter_list|(
name|chan
parameter_list|,
name|rw
parameter_list|,
name|pri
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|_sleep((chan),&(rw)->lock_object, (pri), (wmesg),		\ 	    tick_sbt * (timo), 0, C_HARDCLOCK)
end_define

begin_define
define|#
directive|define
name|rw_initialized
parameter_list|(
name|rw
parameter_list|)
value|lock_initalized(&(rw)->lock_object)
end_define

begin_struct
struct|struct
name|rw_args
block|{
name|void
modifier|*
name|ra_rw
decl_stmt|;
specifier|const
name|char
modifier|*
name|ra_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rw_args_flags
block|{
name|void
modifier|*
name|ra_rw
decl_stmt|;
specifier|const
name|char
modifier|*
name|ra_desc
decl_stmt|;
name|int
name|ra_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RW_SYSINIT
parameter_list|(
name|name
parameter_list|,
name|rw
parameter_list|,
name|desc
parameter_list|)
define|\
value|static struct rw_args name##_args = {				\ 		(rw),							\ 		(desc),							\ 	};								\ 	SYSINIT(name##_rw_sysinit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    rw_sysinit,&name##_args);					\ 	SYSUNINIT(name##_rw_sysuninit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    _rw_destroy, __DEVOLATILE(void *,&(rw)->rw_lock))
end_define

begin_define
define|#
directive|define
name|RW_SYSINIT_FLAGS
parameter_list|(
name|name
parameter_list|,
name|rw
parameter_list|,
name|desc
parameter_list|,
name|flags
parameter_list|)
define|\
value|static struct rw_args_flags name##_args = {			\ 		(rw),							\ 		(desc),							\ 		(flags),						\ 	};								\ 	SYSINIT(name##_rw_sysinit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    rw_sysinit_flags,&name##_args);				\ 	SYSUNINIT(name##_rw_sysuninit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    _rw_destroy, __DEVOLATILE(void *,&(rw)->rw_lock))
end_define

begin_comment
comment|/*  * Options passed to rw_init_flags().  */
end_comment

begin_define
define|#
directive|define
name|RW_DUPOK
value|0x01
end_define

begin_define
define|#
directive|define
name|RW_NOPROFILE
value|0x02
end_define

begin_define
define|#
directive|define
name|RW_NOWITNESS
value|0x04
end_define

begin_define
define|#
directive|define
name|RW_QUIET
value|0x08
end_define

begin_define
define|#
directive|define
name|RW_RECURSE
value|0x10
end_define

begin_define
define|#
directive|define
name|RW_NEW
value|0x20
end_define

begin_comment
comment|/*  * The INVARIANTS-enabled rw_assert() functionality.  *  * The constants need to be defined for INVARIANT_SUPPORT infrastructure  * support as _rw_assert() itself uses them and the latter implies that  * _rw_assert() must build.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|RA_LOCKED
value|LA_LOCKED
end_define

begin_define
define|#
directive|define
name|RA_RLOCKED
value|LA_SLOCKED
end_define

begin_define
define|#
directive|define
name|RA_WLOCKED
value|LA_XLOCKED
end_define

begin_define
define|#
directive|define
name|RA_UNLOCKED
value|LA_UNLOCKED
end_define

begin_define
define|#
directive|define
name|RA_RECURSED
value|LA_RECURSED
end_define

begin_define
define|#
directive|define
name|RA_NOTRECURSED
value|LA_NOTRECURSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|rw_assert
parameter_list|(
name|rw
parameter_list|,
name|what
parameter_list|)
value|_rw_assert((rw), (what), LOCK_FILE, LOCK_LINE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rw_assert
parameter_list|(
name|rw
parameter_list|,
name|what
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_RWLOCK_H_ */
end_comment

end_unit

