begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from BSDI $Id: mutex.h,v 2.7.2.35 2000/04/27 03:10:26 cp Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MUTEX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MUTEX_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
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
file|<sys/lock_profile.h>
end_include

begin_include
include|#
directive|include
file|<sys/lockstat.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_comment
comment|/*  * Mutex types and options passed to mtx_init().  MTX_QUIET and MTX_DUPOK  * can also be passed in.  */
end_comment

begin_define
define|#
directive|define
name|MTX_DEF
value|0x00000000
end_define

begin_comment
comment|/* DEFAULT (sleep) lock */
end_comment

begin_define
define|#
directive|define
name|MTX_SPIN
value|0x00000001
end_define

begin_comment
comment|/* Spin lock (disables interrupts) */
end_comment

begin_define
define|#
directive|define
name|MTX_RECURSE
value|0x00000004
end_define

begin_comment
comment|/* Option: lock allowed to recurse */
end_comment

begin_define
define|#
directive|define
name|MTX_NOWITNESS
value|0x00000008
end_define

begin_comment
comment|/* Don't do any witness checking. */
end_comment

begin_define
define|#
directive|define
name|MTX_NOPROFILE
value|0x00000020
end_define

begin_comment
comment|/* Don't profile this lock */
end_comment

begin_comment
comment|/*  * Option flags passed to certain lock/unlock routines, through the use  * of corresponding mtx_{lock,unlock}_flags() interface macros.  */
end_comment

begin_define
define|#
directive|define
name|MTX_QUIET
value|LOP_QUIET
end_define

begin_comment
comment|/* Don't log a mutex event */
end_comment

begin_define
define|#
directive|define
name|MTX_DUPOK
value|LOP_DUPOK
end_define

begin_comment
comment|/* Don't log a duplicate acquire */
end_comment

begin_comment
comment|/*  * State bits kept in mutex->mtx_lock, for the DEFAULT lock type. None of this,  * with the exception of MTX_UNOWNED, applies to spin locks.  */
end_comment

begin_define
define|#
directive|define
name|MTX_RECURSED
value|0x00000001
end_define

begin_comment
comment|/* lock recursed (for MTX_DEF only) */
end_comment

begin_define
define|#
directive|define
name|MTX_CONTESTED
value|0x00000002
end_define

begin_comment
comment|/* lock contested (for MTX_DEF only) */
end_comment

begin_define
define|#
directive|define
name|MTX_UNOWNED
value|0x00000004
end_define

begin_comment
comment|/* Cookie for free mutex */
end_comment

begin_define
define|#
directive|define
name|MTX_FLAGMASK
value|(MTX_RECURSED | MTX_CONTESTED | MTX_UNOWNED)
end_define

begin_comment
comment|/*  * Value stored in mutex->mtx_lock to denote a destroyed mutex.  */
end_comment

begin_define
define|#
directive|define
name|MTX_DESTROYED
value|(MTX_CONTESTED | MTX_UNOWNED)
end_define

begin_comment
comment|/*  * Prototypes  *  * NOTE: Functions prepended with `_' (underscore) are exported to other parts  *	 of the kernel via macros, thus allowing us to use the cpp LOCK_FILE  *	 and LOCK_LINE or for hiding the lock cookie crunching to the  *	 consumers. These functions should not be called directly by any  *	 code using the API. Their macros cover their functionality.  *	 Functions with a `_' suffix are the entrypoint for the common  *	 KPI covering both compat shims and fast path case.  These can be  *	 used by consumers willing to pass options, file and line  *	 informations, in an option-independent way.  *  * [See below for descriptions]  *  */
end_comment

begin_function_decl
name|void
name|_mtx_init
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
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|int
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mtx_destroy
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
name|mtx_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_mtx_trylock_flags_
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|int
name|opts
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
name|mutex_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__mtx_lock_sleep
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|uintptr_t
name|tid
parameter_list|,
name|int
name|opts
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
name|__mtx_unlock_sleep
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|int
name|opts
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

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_function_decl
name|void
name|_mtx_lock_spin_cookie
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|uintptr_t
name|tid
parameter_list|,
name|int
name|opts
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

begin_function_decl
name|void
name|__mtx_lock_flags
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|int
name|opts
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
name|__mtx_unlock_flags
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|int
name|opts
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
name|__mtx_lock_spin_flags
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|int
name|opts
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
name|__mtx_unlock_spin_flags
parameter_list|(
specifier|volatile
name|uintptr_t
modifier|*
name|c
parameter_list|,
name|int
name|opts
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
name|__mtx_assert
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

begin_function_decl
name|void
name|thread_lock_flags_
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|thread_lock
parameter_list|(
name|tdp
parameter_list|)
define|\
value|thread_lock_flags_((tdp), 0, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|thread_lock_flags
parameter_list|(
name|tdp
parameter_list|,
name|opt
parameter_list|)
define|\
value|thread_lock_flags_((tdp), (opt), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|thread_unlock
parameter_list|(
name|tdp
parameter_list|)
define|\
value|mtx_unlock_spin((tdp)->td_lock)
end_define

begin_comment
comment|/*  * Top-level macros to provide lock cookie once the actual mtx is passed.  * They will also prevent passing a malformed object to the mtx KPI by  * failing compilation as the mtx_lock reserved member will not be found.  */
end_comment

begin_define
define|#
directive|define
name|mtx_init
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|,
name|o
parameter_list|)
define|\
value|_mtx_init(&(m)->mtx_lock, n, t, o)
end_define

begin_define
define|#
directive|define
name|mtx_destroy
parameter_list|(
name|m
parameter_list|)
define|\
value|_mtx_destroy(&(m)->mtx_lock)
end_define

begin_define
define|#
directive|define
name|mtx_trylock_flags_
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|_mtx_trylock_flags_(&(m)->mtx_lock, o, f, l)
end_define

begin_define
define|#
directive|define
name|_mtx_lock_sleep
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|o
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__mtx_lock_sleep(&(m)->mtx_lock, t, o, f, l)
end_define

begin_define
define|#
directive|define
name|_mtx_unlock_sleep
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__mtx_unlock_sleep(&(m)->mtx_lock, o, f, l)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|_mtx_lock_spin
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|o
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|_mtx_lock_spin_cookie(&(m)->mtx_lock, t, o, f, l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_mtx_lock_flags
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__mtx_lock_flags(&(m)->mtx_lock, o, f, l)
end_define

begin_define
define|#
directive|define
name|_mtx_unlock_flags
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__mtx_unlock_flags(&(m)->mtx_lock, o, f, l)
end_define

begin_define
define|#
directive|define
name|_mtx_lock_spin_flags
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__mtx_lock_spin_flags(&(m)->mtx_lock, o, f, l)
end_define

begin_define
define|#
directive|define
name|_mtx_unlock_spin_flags
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__mtx_unlock_spin_flags(&(m)->mtx_lock, o, f, l)
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
name|_mtx_assert
parameter_list|(
name|m
parameter_list|,
name|w
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|__mtx_assert(&(m)->mtx_lock, w, f, l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mtx_recurse
value|lock_object.lo_data
end_define

begin_comment
comment|/* Very simple operations on mtx_lock. */
end_comment

begin_comment
comment|/* Try to obtain mtx_lock once. */
end_comment

begin_define
define|#
directive|define
name|_mtx_obtain_lock
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|)
define|\
value|atomic_cmpset_acq_ptr(&(mp)->mtx_lock, MTX_UNOWNED, (tid))
end_define

begin_comment
comment|/* Try to release mtx_lock if it is unrecursed and uncontested. */
end_comment

begin_define
define|#
directive|define
name|_mtx_release_lock
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|)
define|\
value|atomic_cmpset_rel_ptr(&(mp)->mtx_lock, (tid), MTX_UNOWNED)
end_define

begin_comment
comment|/* Release mtx_lock quickly, assuming we own it. */
end_comment

begin_define
define|#
directive|define
name|_mtx_release_lock_quick
parameter_list|(
name|mp
parameter_list|)
define|\
value|atomic_store_rel_ptr(&(mp)->mtx_lock, MTX_UNOWNED)
end_define

begin_comment
comment|/*  * Full lock operations that are suitable to be inlined in non-debug  * kernels.  If the lock cannot be acquired or released trivially then  * the work is deferred to another function.  */
end_comment

begin_comment
comment|/* Lock a normal mutex. */
end_comment

begin_define
define|#
directive|define
name|__mtx_lock
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {			\ 	uintptr_t _tid = (uintptr_t)(tid);				\ 									\ 	if (!_mtx_obtain_lock((mp), _tid))				\ 		_mtx_lock_sleep((mp), _tid, (opts), (file), (line));	\ 	else								\               	LOCKSTAT_PROFILE_OBTAIN_LOCK_SUCCESS(LS_MTX_LOCK_ACQUIRE, \ 		    mp, 0, 0, (file), (line));				\ } while (0)
end_define

begin_comment
comment|/*  * Lock a spin mutex.  For spinlocks, we handle recursion inline (it  * turns out that function calls can be significantly expensive on  * some architectures).  Since spin locks are not _too_ common,  * inlining this code is not too big a deal.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|__mtx_lock_spin
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {			\ 	uintptr_t _tid = (uintptr_t)(tid);				\ 									\ 	spinlock_enter();						\ 	if (!_mtx_obtain_lock((mp), _tid)) {				\ 		if ((mp)->mtx_lock == _tid)				\ 			(mp)->mtx_recurse++;				\ 		else							\ 			_mtx_lock_spin((mp), _tid, (opts), (file), (line)); \ 	} else 								\               	LOCKSTAT_PROFILE_OBTAIN_LOCK_SUCCESS(LS_MTX_SPIN_LOCK_ACQUIRE, \ 		    mp, 0, 0, (file), (line));				\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|__mtx_lock_spin
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {			\ 	uintptr_t _tid = (uintptr_t)(tid);				\ 									\ 	spinlock_enter();						\ 	if ((mp)->mtx_lock == _tid)					\ 		(mp)->mtx_recurse++;					\ 	else {								\ 		KASSERT((mp)->mtx_lock == MTX_UNOWNED, ("corrupt spinlock")); \ 		(mp)->mtx_lock = _tid;					\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_comment
comment|/* Unlock a normal mutex. */
end_comment

begin_define
define|#
directive|define
name|__mtx_unlock
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {			\ 	uintptr_t _tid = (uintptr_t)(tid);				\ 									\ 	if ((mp)->mtx_recurse == 0)					\ 		 LOCKSTAT_PROFILE_RELEASE_LOCK(LS_MTX_UNLOCK_RELEASE,	\ 		    (mp));						\ 	if (!_mtx_release_lock((mp), _tid))				\ 		_mtx_unlock_sleep((mp), (opts), (file), (line));	\ } while (0)
end_define

begin_comment
comment|/*  * Unlock a spin mutex.  For spinlocks, we can handle everything  * inline, as it's pretty simple and a function call would be too  * expensive (at least on some architectures).  Since spin locks are  * not _too_ common, inlining this code is not too big a deal.  *  * Since we always perform a spinlock_enter() when attempting to acquire a  * spin lock, we need to always perform a matching spinlock_exit() when  * releasing a spin lock.  This includes the recursion cases.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|__mtx_unlock_spin
parameter_list|(
name|mp
parameter_list|)
value|do {					\ 	if (mtx_recursed((mp)))						\ 		(mp)->mtx_recurse--;					\ 	else {								\ 		LOCKSTAT_PROFILE_RELEASE_LOCK(LS_MTX_SPIN_UNLOCK_RELEASE, \ 			mp);						\ 		_mtx_release_lock_quick((mp));				\ 	}                                                               \ 	spinlock_exit();				                \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|__mtx_unlock_spin
parameter_list|(
name|mp
parameter_list|)
value|do {					\ 	if (mtx_recursed((mp)))						\ 		(mp)->mtx_recurse--;					\ 	else {								\ 		LOCKSTAT_PROFILE_RELEASE_LOCK(LS_MTX_SPIN_UNLOCK_RELEASE, \ 			mp);						\ 		(mp)->mtx_lock = MTX_UNOWNED;				\ 	}                                                               \ 	spinlock_exit();						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_comment
comment|/*  * Exported lock manipulation interface.  *  * mtx_lock(m) locks MTX_DEF mutex `m'  *  * mtx_lock_spin(m) locks MTX_SPIN mutex `m'  *  * mtx_unlock(m) unlocks MTX_DEF mutex `m'  *  * mtx_unlock_spin(m) unlocks MTX_SPIN mutex `m'  *  * mtx_lock_spin_flags(m, opts) and mtx_lock_flags(m, opts) locks mutex `m'  *     and passes option flags `opts' to the "hard" function, if required.  *     With these routines, it is possible to pass flags such as MTX_QUIET  *     to the appropriate lock manipulation routines.  *  * mtx_trylock(m) attempts to acquire MTX_DEF mutex `m' but doesn't sleep if  *     it cannot. Rather, it returns 0 on failure and non-zero on success.  *     It does NOT handle recursion as we assume that if a caller is properly  *     using this part of the interface, he will know that the lock in question  *     is _not_ recursed.  *  * mtx_trylock_flags(m, opts) is used the same way as mtx_trylock() but accepts  *     relevant option flags `opts.'  *  * mtx_initialized(m) returns non-zero if the lock `m' has been initialized.  *  * mtx_owned(m) returns non-zero if the current thread owns the lock `m'  *  * mtx_recursed(m) returns non-zero if the lock `m' is presently recursed.  */
end_comment

begin_define
define|#
directive|define
name|mtx_lock
parameter_list|(
name|m
parameter_list|)
value|mtx_lock_flags((m), 0)
end_define

begin_define
define|#
directive|define
name|mtx_lock_spin
parameter_list|(
name|m
parameter_list|)
value|mtx_lock_spin_flags((m), 0)
end_define

begin_define
define|#
directive|define
name|mtx_trylock
parameter_list|(
name|m
parameter_list|)
value|mtx_trylock_flags((m), 0)
end_define

begin_define
define|#
directive|define
name|mtx_unlock
parameter_list|(
name|m
parameter_list|)
value|mtx_unlock_flags((m), 0)
end_define

begin_define
define|#
directive|define
name|mtx_unlock_spin
parameter_list|(
name|m
parameter_list|)
value|mtx_unlock_spin_flags((m), 0)
end_define

begin_struct_decl
struct_decl|struct
name|mtx_pool
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|mtx_pool
modifier|*
name|mtx_pool_create
parameter_list|(
specifier|const
name|char
modifier|*
name|mtx_name
parameter_list|,
name|int
name|pool_size
parameter_list|,
name|int
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mtx_pool_destroy
parameter_list|(
name|struct
name|mtx_pool
modifier|*
modifier|*
name|poolp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mtx
modifier|*
name|mtx_pool_find
parameter_list|(
name|struct
name|mtx_pool
modifier|*
name|pool
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mtx
modifier|*
name|mtx_pool_alloc
parameter_list|(
name|struct
name|mtx_pool
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|mtx_pool_lock
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|)
define|\
value|mtx_lock(mtx_pool_find((pool), (ptr)))
end_define

begin_define
define|#
directive|define
name|mtx_pool_lock_spin
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|)
define|\
value|mtx_lock_spin(mtx_pool_find((pool), (ptr)))
end_define

begin_define
define|#
directive|define
name|mtx_pool_unlock
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|)
define|\
value|mtx_unlock(mtx_pool_find((pool), (ptr)))
end_define

begin_define
define|#
directive|define
name|mtx_pool_unlock_spin
parameter_list|(
name|pool
parameter_list|,
name|ptr
parameter_list|)
define|\
value|mtx_unlock_spin(mtx_pool_find((pool), (ptr)))
end_define

begin_comment
comment|/*  * mtxpool_sleep is a general purpose pool of sleep mutexes.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx_pool
modifier|*
name|mtxpool_sleep
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_DEBUG
end_ifndef

begin_error
error|#
directive|error
error|LOCK_DEBUG not defined, include<sys/lock.h> before<sys/mutex.h>
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
name|MUTEX_NOINLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|mtx_lock_flags_
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|_mtx_lock_flags((m), (opts), (file), (line))
end_define

begin_define
define|#
directive|define
name|mtx_unlock_flags_
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|_mtx_unlock_flags((m), (opts), (file), (line))
end_define

begin_define
define|#
directive|define
name|mtx_lock_spin_flags_
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|_mtx_lock_spin_flags((m), (opts), (file), (line))
end_define

begin_define
define|#
directive|define
name|mtx_unlock_spin_flags_
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|_mtx_unlock_spin_flags((m), (opts), (file), (line))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LOCK_DEBUG == 0&& !MUTEX_NOINLINE */
end_comment

begin_define
define|#
directive|define
name|mtx_lock_flags_
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|__mtx_lock((m), curthread, (opts), (file), (line))
end_define

begin_define
define|#
directive|define
name|mtx_unlock_flags_
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|__mtx_unlock((m), curthread, (opts), (file), (line))
end_define

begin_define
define|#
directive|define
name|mtx_lock_spin_flags_
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|__mtx_lock_spin((m), curthread, (opts), (file), (line))
end_define

begin_define
define|#
directive|define
name|mtx_unlock_spin_flags_
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|__mtx_unlock_spin((m))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCK_DEBUG> 0 || MUTEX_NOINLINE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|mtx_assert_
parameter_list|(
name|m
parameter_list|,
name|what
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|_mtx_assert((m), (what), (file), (line))
end_define

begin_define
define|#
directive|define
name|GIANT_REQUIRED
value|mtx_assert_(&Giant, MA_OWNED, __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* INVARIANTS */
end_comment

begin_define
define|#
directive|define
name|mtx_assert_
parameter_list|(
name|m
parameter_list|,
name|what
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|GIANT_REQUIRED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INVARIANTS */
end_comment

begin_define
define|#
directive|define
name|mtx_lock_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|)
define|\
value|mtx_lock_flags_((m), (opts), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|mtx_unlock_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|)
define|\
value|mtx_unlock_flags_((m), (opts), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|mtx_lock_spin_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|)
define|\
value|mtx_lock_spin_flags_((m), (opts), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|mtx_unlock_spin_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|)
define|\
value|mtx_unlock_spin_flags_((m), (opts), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|mtx_trylock_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|)
define|\
value|mtx_trylock_flags_((m), (opts), LOCK_FILE, LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|mtx_assert
parameter_list|(
name|m
parameter_list|,
name|what
parameter_list|)
define|\
value|mtx_assert_((m), (what), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|mtx_sleep
parameter_list|(
name|chan
parameter_list|,
name|mtx
parameter_list|,
name|pri
parameter_list|,
name|wmesg
parameter_list|,
name|timo
parameter_list|)
define|\
value|_sleep((chan),&(mtx)->lock_object, (pri), (wmesg),		\ 	    tick_sbt * (timo), 0, C_HARDCLOCK)
end_define

begin_define
define|#
directive|define
name|mtx_initialized
parameter_list|(
name|m
parameter_list|)
value|lock_initialized(&(m)->lock_object)
end_define

begin_define
define|#
directive|define
name|mtx_owned
parameter_list|(
name|m
parameter_list|)
value|(((m)->mtx_lock& ~MTX_FLAGMASK) == (uintptr_t)curthread)
end_define

begin_define
define|#
directive|define
name|mtx_recursed
parameter_list|(
name|m
parameter_list|)
value|((m)->mtx_recurse != 0)
end_define

begin_define
define|#
directive|define
name|mtx_name
parameter_list|(
name|m
parameter_list|)
value|((m)->lock_object.lo_name)
end_define

begin_comment
comment|/*  * Global locks.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|Giant
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|blocked_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Giant lock manipulation and clean exit macros.  * Used to replace return with an exit Giant and return.  *  * Note that DROP_GIANT*() needs to be paired with PICKUP_GIANT()   * The #ifndef is to allow lint-like tools to redefine DROP_GIANT.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DROP_GIANT
end_ifndef

begin_define
define|#
directive|define
name|DROP_GIANT
parameter_list|()
define|\
value|do {									\ 	int _giantcnt = 0;						\ 	WITNESS_SAVE_DECL(Giant);					\ 									\ 	if (mtx_owned(&Giant)) {					\ 		WITNESS_SAVE(&Giant.lock_object, Giant);		\ 		for (_giantcnt = 0; mtx_owned(&Giant)&&		\ 		    !SCHEDULER_STOPPED(); _giantcnt++)			\ 			mtx_unlock(&Giant);				\ 	}
end_define

begin_define
define|#
directive|define
name|PICKUP_GIANT
parameter_list|()
define|\
value|PARTIAL_PICKUP_GIANT();						\ } while (0)
end_define

begin_define
define|#
directive|define
name|PARTIAL_PICKUP_GIANT
parameter_list|()
define|\
value|mtx_assert(&Giant, MA_NOTOWNED);				\ 	if (_giantcnt> 0) {						\ 		while (_giantcnt--)					\ 			mtx_lock(&Giant);				\ 		WITNESS_RESTORE(&Giant.lock_object, Giant);		\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|mtx_args
block|{
name|void
modifier|*
name|ma_mtx
decl_stmt|;
specifier|const
name|char
modifier|*
name|ma_desc
decl_stmt|;
name|int
name|ma_opts
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MTX_SYSINIT
parameter_list|(
name|name
parameter_list|,
name|mtx
parameter_list|,
name|desc
parameter_list|,
name|opts
parameter_list|)
define|\
value|static struct mtx_args name##_args = {				\ 		(mtx),							\ 		(desc),							\ 		(opts)							\ 	};								\ 	SYSINIT(name##_mtx_sysinit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    mtx_sysinit,&name##_args);					\ 	SYSUNINIT(name##_mtx_sysuninit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    _mtx_destroy, __DEVOLATILE(void *,&(mtx)->mtx_lock))
end_define

begin_comment
comment|/*  * The INVARIANTS-enabled mtx_assert() functionality.  *  * The constants need to be defined for INVARIANT_SUPPORT infrastructure  * support as _mtx_assert() itself uses them and the latter implies that  * _mtx_assert() must build.  */
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
name|MA_OWNED
value|LA_XLOCKED
end_define

begin_define
define|#
directive|define
name|MA_NOTOWNED
value|LA_UNLOCKED
end_define

begin_define
define|#
directive|define
name|MA_RECURSED
value|LA_RECURSED
end_define

begin_define
define|#
directive|define
name|MA_NOTRECURSED
value|LA_NOTRECURSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Common lock type names.  */
end_comment

begin_define
define|#
directive|define
name|MTX_NETWORK_LOCK
value|"network driver"
end_define

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
comment|/* _SYS_MUTEX_H_ */
end_comment

end_unit

