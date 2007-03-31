begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Attilio Rao<attilio@freebsd.org>  * Copyright (c) 2001 Jason Evans<jasone@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible   *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SX_H_
end_define

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_sx.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
comment|/*  * In general, the sx locks and rwlocks use very similar algorithms.  * The main difference in the implementations is how threads are  * blocked when a lock is unavailable.  For this, sx locks use sleep  * queues which do not support priority propagation, and rwlocks use  * turnstiles which do.  *  * The sx_lock field consists of several fields.  The low bit  * indicates if the lock is locked with a shared or exclusive lock.  A  * value of 0 indicates an exclusive lock, and a value of 1 indicates  * a shared lock.  Bit 1 is a boolean indicating if there are any  * threads waiting for a shared lock.  Bit 2 is a boolean indicating  * if there are any threads waiting for an exclusive lock.  Bit 3 is a  * boolean indicating if an exclusive lock is recursively held.  The  * rest of the variable's definition is dependent on the value of the  * first bit.  For an exclusive lock, it is a pointer to the thread  * holding the lock, similar to the mtx_lock field of mutexes.  For  * shared locks, it is a count of read locks that are held.  *  * When the lock is not locked by any thread, it is encoded as a  * shared lock with zero waiters.  *  * A note about memory barriers.  Exclusive locks need to use the same  * memory barriers as mutexes: _acq when acquiring an exclusive lock  * and _rel when releasing an exclusive lock.  On the other side,  * shared lock needs to use an _acq barrier when acquiring the lock  * but, since they don't update any locked data, no memory barrier is  * needed when releasing a shared lock.  */
end_comment

begin_define
define|#
directive|define
name|SX_LOCK_SHARED
value|0x01
end_define

begin_define
define|#
directive|define
name|SX_LOCK_SHARED_WAITERS
value|0x02
end_define

begin_define
define|#
directive|define
name|SX_LOCK_EXCLUSIVE_WAITERS
value|0x04
end_define

begin_define
define|#
directive|define
name|SX_LOCK_RECURSED
value|0x08
end_define

begin_define
define|#
directive|define
name|SX_LOCK_FLAGMASK
define|\
value|(SX_LOCK_SHARED | SX_LOCK_SHARED_WAITERS |			\ 	SX_LOCK_EXCLUSIVE_WAITERS | SX_LOCK_RECURSED)
end_define

begin_define
define|#
directive|define
name|SX_OWNER
parameter_list|(
name|x
parameter_list|)
value|((x)& ~SX_LOCK_FLAGMASK)
end_define

begin_define
define|#
directive|define
name|SX_SHARERS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SX_SHARERS
parameter_list|(
name|x
parameter_list|)
value|(SX_OWNER(x)>> SX_SHARERS_SHIFT)
end_define

begin_define
define|#
directive|define
name|SX_SHARERS_LOCK
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)<< SX_SHARERS_SHIFT | SX_LOCK_SHARED)
end_define

begin_define
define|#
directive|define
name|SX_ONE_SHARER
value|(1<< SX_SHARERS_SHIFT)
end_define

begin_define
define|#
directive|define
name|SX_LOCK_UNLOCKED
value|SX_SHARERS_LOCK(0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Full lock operations that are suitable to be inlined in non-debug kernels.  * If the lock can't be acquired or released trivially then the work is  * deferred to 'tougher' functions.  */
end_comment

begin_comment
comment|/* Acquire an exclusive lock. */
end_comment

begin_define
define|#
directive|define
name|__sx_xlock
parameter_list|(
name|sx
parameter_list|,
name|tid
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {				\ 	uintptr_t _tid = (uintptr_t)(tid);				\ 	int contested = 0;                                              \         uint64_t waitstart = 0;                                         \ 									\ 	if (!atomic_cmpset_acq_ptr(&(sx)->sx_lock, SX_LOCK_UNLOCKED,	\ 	    _tid)) {							\ 		lock_profile_obtain_lock_failed(&(sx)->lock_object,	\&contested,&waitstart);				\ 		_sx_xlock_hard((sx), _tid, (file), (line));		\ 	}								\ 	lock_profile_obtain_lock_success(&(sx)->lock_object, contested,	\ 	    waitstart, (file), (line));					\ } while (0)
end_define

begin_comment
comment|/* Release an exclusive lock. */
end_comment

begin_define
define|#
directive|define
name|__sx_xunlock
parameter_list|(
name|sx
parameter_list|,
name|tid
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {				\ 	uintptr_t _tid = (uintptr_t)(tid);				\ 									\ 	if (!atomic_cmpset_rel_ptr(&(sx)->sx_lock, _tid,		\ 	    SX_LOCK_UNLOCKED))						\ 		_sx_xunlock_hard((sx), _tid, (file), (line));		\ } while (0)
end_define

begin_comment
comment|/* Acquire a shared lock. */
end_comment

begin_define
define|#
directive|define
name|__sx_slock
parameter_list|(
name|sx
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {					\ 	uintptr_t x = (sx)->sx_lock;					\ 	int contested = 0;                                              \         uint64_t waitstart = 0;                                         \ 									\ 	if (!(x& SX_LOCK_SHARED) ||					\ 	    !atomic_cmpset_acq_ptr(&(sx)->sx_lock, x,			\ 	    x + SX_ONE_SHARER)) {					\ 		lock_profile_obtain_lock_failed(&(sx)->lock_object,	\&contested,&waitstart);				\ 		_sx_slock_hard((sx), (file), (line));			\ 	}								\ 	lock_profile_obtain_lock_success(&(sx)->lock_object, contested,	\ 	    waitstart, (file), (line));					\ } while (0)
end_define

begin_comment
comment|/*  * Release a shared lock.  We can just drop a single shared lock so  * long as we aren't trying to drop the last shared lock when other  * threads are waiting for an exclusive lock.  This takes advantage of  * the fact that an unlocked lock is encoded as a shared lock with a  * count of 0.  */
end_comment

begin_define
define|#
directive|define
name|__sx_sunlock
parameter_list|(
name|sx
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {				\ 	uintptr_t x = (sx)->sx_lock;					\ 									\ 	if (x == (SX_SHARERS_LOCK(1) | SX_LOCK_EXCLUSIVE_WAITERS) ||	\ 	    !atomic_cmpset_ptr(&(sx)->sx_lock, x, x - SX_ONE_SHARER))	\ 		_sx_sunlock_hard((sx), (file), (line));			\ } while (0)
end_define

begin_comment
comment|/*  * Function prototipes.  Routines that start with an underscore are not part  * of the public interface and are wrappered with a macro.  */
end_comment

begin_function_decl
name|void
name|sx_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sx_init
parameter_list|(
name|sx
parameter_list|,
name|desc
parameter_list|)
value|sx_init_flags((sx), (desc), 0)
end_define

begin_function_decl
name|void
name|sx_init_flags
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|,
name|int
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sx_destroy
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_sx_slock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_xlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_try_slock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_try_xlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_sunlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_xunlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_try_upgrade
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_downgrade
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_xlock_hard
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_slock_hard
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_xunlock_hard
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_sunlock_hard
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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
name|_sx_assert
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
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

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_function_decl
name|int
name|sx_chain
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|thread
modifier|*
modifier|*
name|ownerp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|sx_args
block|{
name|struct
name|sx
modifier|*
name|sa_sx
decl_stmt|;
specifier|const
name|char
modifier|*
name|sa_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SX_SYSINIT
parameter_list|(
name|name
parameter_list|,
name|sxa
parameter_list|,
name|desc
parameter_list|)
define|\
value|static struct sx_args name##_args = {				\ 		(sxa),							\ 		(desc)							\ 	};								\ 	SYSINIT(name##_sx_sysinit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    sx_sysinit,&name##_args);					\ 	SYSUNINIT(name##_sx_sysuninit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    sx_destroy, (sxa))
end_define

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
literal|"LOCK_DEBUG not defined, include<sys/lock.h> before<sys/sx.h>"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|LOCK_DEBUG
operator|>
literal|0
operator|)
operator|||
name|defined
argument_list|(
name|SX_NOINLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|sx_xlock
parameter_list|(
name|sx
parameter_list|)
value|_sx_xlock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_xunlock
parameter_list|(
name|sx
parameter_list|)
value|_sx_xunlock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_slock
parameter_list|(
name|sx
parameter_list|)
value|_sx_slock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_sunlock
parameter_list|(
name|sx
parameter_list|)
value|_sx_sunlock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sx_xlock
parameter_list|(
name|sx
parameter_list|)
define|\
value|__sx_xlock((sx), curthread, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_xunlock
parameter_list|(
name|sx
parameter_list|)
define|\
value|__sx_xunlock((sx), curthread, LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_slock
parameter_list|(
name|sx
parameter_list|)
value|__sx_slock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_sunlock
parameter_list|(
name|sx
parameter_list|)
value|__sx_sunlock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCK_DEBUG> 0 || SX_NOINLINE */
end_comment

begin_define
define|#
directive|define
name|sx_try_slock
parameter_list|(
name|sx
parameter_list|)
value|_sx_try_slock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_try_xlock
parameter_list|(
name|sx
parameter_list|)
value|_sx_try_xlock((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_try_upgrade
parameter_list|(
name|sx
parameter_list|)
value|_sx_try_upgrade((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_downgrade
parameter_list|(
name|sx
parameter_list|)
value|_sx_downgrade((sx), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|sx_xlocked
parameter_list|(
name|sx
parameter_list|)
define|\
value|(((sx)->sx_lock& ~(SX_LOCK_FLAGMASK& ~SX_LOCK_SHARED)) ==	\ 	    (uintptr_t)curthread)
end_define

begin_define
define|#
directive|define
name|sx_unlock
parameter_list|(
name|sx
parameter_list|)
value|do {						\ 	if (sx_xlocked(sx))						\ 		sx_xunlock(sx);						\ 	else								\ 		sx_sunlock(sx);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|sx_sleep
parameter_list|(
name|chan
parameter_list|,
name|sx
parameter_list|,
name|pri
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|_sleep((chan),&(sx)->lock_object, (pri), (wmesg), (timo))
end_define

begin_comment
comment|/*  * Options passed to sx_init_flags().  */
end_comment

begin_define
define|#
directive|define
name|SX_DUPOK
value|0x01
end_define

begin_define
define|#
directive|define
name|SX_NOPROFILE
value|0x02
end_define

begin_define
define|#
directive|define
name|SX_NOWITNESS
value|0x04
end_define

begin_define
define|#
directive|define
name|SX_QUIET
value|0x08
end_define

begin_define
define|#
directive|define
name|SX_ADAPTIVESPIN
value|0x10
end_define

begin_comment
comment|/*  * XXX: These options should be renamed as SA_*  */
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
name|SX_LOCKED
value|LA_LOCKED
end_define

begin_define
define|#
directive|define
name|SX_SLOCKED
value|LA_SLOCKED
end_define

begin_define
define|#
directive|define
name|SX_XLOCKED
value|LA_XLOCKED
end_define

begin_define
define|#
directive|define
name|SX_UNLOCKED
value|LA_UNLOCKED
end_define

begin_define
define|#
directive|define
name|SX_RECURSED
value|LA_RECURSED
end_define

begin_define
define|#
directive|define
name|SX_NOTRECURSED
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
name|sx_assert
parameter_list|(
name|sx
parameter_list|,
name|what
parameter_list|)
value|_sx_assert((sx), (what), LOCK_FILE, LOCK_LINE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sx_assert
parameter_list|(
name|sx
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
comment|/* !_SYS_SX_H_ */
end_comment

end_unit

