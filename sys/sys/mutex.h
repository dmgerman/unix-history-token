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

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/ktr.h>
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

begin_include
include|#
directive|include
file|<machine/globals.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_include
include|#
directive|include
file|<machine/mutex.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Mutex types and options passed to mtx_init().  MTX_QUIET can also be  * passed in.  */
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
name|MTX_SLEEPABLE
value|0x00000010
end_define

begin_comment
comment|/* We can sleep with this lock. */
end_comment

begin_comment
comment|/*  * Option flags passed to certain lock/unlock routines, through the use  * of corresponding mtx_{lock,unlock}_flags() interface macros.  */
end_comment

begin_define
define|#
directive|define
name|MTX_NOSWITCH
value|LOP_NOSWITCH
end_define

begin_comment
comment|/* Do not switch on release */
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
value|~(MTX_RECURSED | MTX_CONTESTED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Sleep/spin mutex  */
end_comment

begin_struct_decl
struct_decl|struct
name|lock_object
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|mtx
block|{
name|struct
name|lock_object
name|mtx_object
decl_stmt|;
comment|/* Common lock properties. */
specifier|volatile
name|uintptr_t
name|mtx_lock
decl_stmt|;
comment|/* owner (and state for sleep locks) */
specifier|volatile
name|u_int
name|mtx_recurse
decl_stmt|;
comment|/* number of recursive holds */
name|critical_t
name|mtx_savecrit
decl_stmt|;
comment|/* saved flags (for spin locks) */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|proc
argument_list|)
name|mtx_blocked
expr_stmt|;
comment|/* threads blocked on this lock */
name|LIST_ENTRY
argument_list|(
argument|mtx
argument_list|)
name|mtx_contested
expr_stmt|;
comment|/* list of all contested locks */
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXX: Friendly reminder to fix things in MP code that is presently being  * XXX: worked on.  */
end_comment

begin_define
define|#
directive|define
name|mp_fixme
parameter_list|(
name|string
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Prototypes  *  * NOTE: Functions prepended with `_' (underscore) are exported to other parts  *	 of the kernel via macros, thus allowing us to use the cpp __FILE__  *	 and __LINE__. These functions should not be called directly by any  *	 code using the API. Their macros cover their functionality.  *  * [See below for descriptions]  *  */
end_comment

begin_function_decl
name|void
name|mtx_init
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|mtx_destroy
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_mtx_lock_sleep
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|_mtx_unlock_sleep
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|_mtx_lock_spin
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
parameter_list|,
name|int
name|opts
parameter_list|,
name|critical_t
name|mtx_crit
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
name|_mtx_unlock_spin
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|int
name|_mtx_trylock
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|_mtx_lock_flags
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|_mtx_unlock_flags
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|_mtx_lock_spin_flags
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|_mtx_unlock_spin_flags
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|INVARIANT_SUPPORT
end_ifdef

begin_function_decl
name|void
name|_mtx_assert
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
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
name|WITNESS
end_ifdef

begin_function_decl
name|void
name|_mtx_update_flags
parameter_list|(
name|struct
name|mtx
modifier|*
name|m
parameter_list|,
name|int
name|locking
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We define our machine-independent (unoptimized) mutex micro-operations  * here, if they are not already defined in the machine-dependent mutex.h   */
end_comment

begin_comment
comment|/* Actually obtain mtx_lock */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_obtain_lock
end_ifndef

begin_define
define|#
directive|define
name|_obtain_lock
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|)
define|\
value|atomic_cmpset_acq_ptr(&(mp)->mtx_lock, (void *)MTX_UNOWNED, (tid))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Actually release mtx_lock */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_release_lock
end_ifndef

begin_define
define|#
directive|define
name|_release_lock
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|)
define|\
value|atomic_cmpset_rel_ptr(&(mp)->mtx_lock, (tid), (void *)MTX_UNOWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Actually release mtx_lock quickly, assuming we own it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_release_lock_quick
end_ifndef

begin_define
define|#
directive|define
name|_release_lock_quick
parameter_list|(
name|mp
parameter_list|)
define|\
value|atomic_store_rel_ptr(&(mp)->mtx_lock, (void *)MTX_UNOWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Obtain a sleep lock inline, or call the "hard" function if we can't get it  * easy.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_get_sleep_lock
end_ifndef

begin_define
define|#
directive|define
name|_get_sleep_lock
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
value|do {			\ 	if (!_obtain_lock((mp), (tid)))					\ 		_mtx_lock_sleep((mp), (opts), (file), (line));		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Obtain a spin lock inline, or call the "hard" function if we can't get it  * easy. For spinlocks, we handle recursion inline (it turns out that function  * calls can be significantly expensive on some architectures).  * Since spin locks are not _too_ common, inlining this code is not too big   * a deal.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_get_spin_lock
end_ifndef

begin_define
define|#
directive|define
name|_get_spin_lock
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
value|do {			\ 	critical_t _mtx_crit;						\ 	_mtx_crit = critical_enter();					\ 	if (!_obtain_lock((mp), (tid))) {				\ 		if ((mp)->mtx_lock == (uintptr_t)(tid))			\ 			(mp)->mtx_recurse++;				\ 		else							\ 			_mtx_lock_spin((mp), (opts), _mtx_crit, (file),	\ 			    (line));					\ 	} else								\ 		(mp)->mtx_savecrit = _mtx_crit;				\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Release a sleep lock inline, or call the "hard" function if we can't do it  * easy.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_rel_sleep_lock
end_ifndef

begin_define
define|#
directive|define
name|_rel_sleep_lock
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
value|do {			\ 	if (!_release_lock((mp), (tid)))				\ 		_mtx_unlock_sleep((mp), (opts), (file), (line));	\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For spinlocks, we can handle everything inline, as it's pretty simple and  * a function call would be too expensive (at least on some architectures).  * Since spin locks are not _too_ common, inlining this code is not too big   * a deal.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_rel_spin_lock
end_ifndef

begin_define
define|#
directive|define
name|_rel_spin_lock
parameter_list|(
name|mp
parameter_list|)
value|do {						\ 	critical_t _mtx_crit = (mp)->mtx_savecrit;			\ 	if (mtx_recursed((mp)))						\ 		(mp)->mtx_recurse--;					\ 	else {								\ 		_release_lock_quick((mp));				\ 		critical_exit(_mtx_crit);				\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Update the lock object flags based on the current mutex state.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITNESS
end_ifdef

begin_define
define|#
directive|define
name|mtx_update_flags
parameter_list|(
name|m
parameter_list|,
name|locking
parameter_list|)
value|_mtx_update_flags((m), (locking))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mtx_update_flags
parameter_list|(
name|m
parameter_list|,
name|locking
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Exported lock manipulation interface.  *  * mtx_lock(m) locks MTX_DEF mutex `m'  *  * mtx_lock_spin(m) locks MTX_SPIN mutex `m'  *  * mtx_unlock(m) unlocks MTX_DEF mutex `m'  *  * mtx_unlock_spin(m) unlocks MTX_SPIN mutex `m'  *  * mtx_lock_spin_flags(m, opts) and mtx_lock_flags(m, opts) locks mutex `m'  *     and passes option flags `opts' to the "hard" function, if required.  *     With these routines, it is possible to pass flags such as MTX_QUIET  *     and/or MTX_NOSWITCH to the appropriate lock manipulation routines.  *  * mtx_trylock(m) attempts to acquire MTX_DEF mutex `m' but doesn't sleep if  *     it cannot. Rather, it returns 0 on failure and non-zero on success.  *     It does NOT handle recursion as we assume that if a caller is properly  *     using this part of the interface, he will know that the lock in question  *     is _not_ recursed.  *  * mtx_trylock_flags(m, opts) is used the same way as mtx_trylock() but accepts  *     relevant option flags `opts.'  *  * mtx_initialized(m) returns non-zero if the lock `m' has been initialized.  *  * mtx_owned(m) returns non-zero if the current thread owns the lock `m'  *  * mtx_recursed(m) returns non-zero if the lock `m' is presently recursed.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KLD_MODULE
end_ifdef

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
value|_mtx_lock_flags((m), (opts), __FILE__, __LINE__)
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
value|_mtx_unlock_flags((m), (opts), __FILE__, __LINE__)
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
value|_mtx_lock_spin_flags((m), (opts), __FILE__, __LINE__)
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
value|_mtx_unlock_spin_flags((m), (opts), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

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
value|__mtx_lock_flags((m), (opts), __FILE__, __LINE__)
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
value|__mtx_unlock_flags((m), (opts), __FILE__, __LINE__)
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
value|__mtx_lock_spin_flags((m), (opts), __FILE__, __LINE__)
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
value|__mtx_unlock_spin_flags((m), (opts), __FILE__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__mtx_lock_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {			\ 	MPASS(curproc != NULL);						\ 	KASSERT(((opts)& MTX_NOSWITCH) == 0,				\ 	    ("MTX_NOSWITCH used at %s:%d", (file), (line)));		\ 	_get_sleep_lock((m), curproc, (opts), (file), (line));		\ 	LOCK_LOG_LOCK("LOCK",&(m)->mtx_object, opts, m->mtx_recurse,	\ 	    (file), (line));						\ 	mtx_update_flags((m), 1);					\ 	WITNESS_LOCK(&(m)->mtx_object, (opts), (file), (line));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|__mtx_lock_spin_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {			\ 	MPASS(curproc != NULL);						\ 	_get_spin_lock((m), curproc, (opts), (file), (line));		\ 	LOCK_LOG_LOCK("LOCK",&(m)->mtx_object, opts, m->mtx_recurse,	\ 	    (file), (line));						\ 	mtx_update_flags((m), 1);					\ 	WITNESS_LOCK(&(m)->mtx_object, (opts), (file), (line));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|__mtx_unlock_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {			\ 	MPASS(curproc != NULL);						\ 	mtx_assert((m), MA_OWNED);					\ 	mtx_update_flags((m), 0);					\ 	WITNESS_UNLOCK(&(m)->mtx_object, (opts), (file), (line));	\ 	_rel_sleep_lock((m), curproc, (opts), (file), (line));		\ 	LOCK_LOG_LOCK("UNLOCK",&(m)->mtx_object, (opts),		\ 	    (m)->mtx_recurse, (file), (line));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|__mtx_unlock_spin_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {		\ 	MPASS(curproc != NULL);						\ 	mtx_assert((m), MA_OWNED);					\ 	mtx_update_flags((m), 0);					\ 	WITNESS_UNLOCK(&(m)->mtx_object, (opts), (file), (line));	\ 	_rel_spin_lock((m));						\ 	LOCK_LOG_LOCK("UNLOCK",&(m)->mtx_object, (opts),		\ 	    (m)->mtx_recurse, (file), (line));				\ } while (0)
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
value|_mtx_trylock((m), (opts), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|mtx_initialized
parameter_list|(
name|m
parameter_list|)
value|((m)->mtx_object.lo_flags& LO_INITIALIZED)
end_define

begin_define
define|#
directive|define
name|mtx_owned
parameter_list|(
name|m
parameter_list|)
value|(((m)->mtx_lock& MTX_FLAGMASK) == (uintptr_t)curproc)
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

begin_comment
comment|/*  * Global locks.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|sched_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|Giant
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Giant lock manipulation and clean exit macros.  * Used to replace return with an exit Giant and return.  *  * Note that DROP_GIANT*() needs to be paired with PICKUP_GIANT()   */
end_comment

begin_define
define|#
directive|define
name|DROP_GIANT_NOSWITCH
parameter_list|()
define|\
value|do {									\ 	int _giantcnt;							\ 	WITNESS_SAVE_DECL(Giant);					\ 									\ 	if (mtx_owned(&Giant))						\ 		WITNESS_SAVE(&Giant.mtx_object, Giant);			\ 	for (_giantcnt = 0; mtx_owned(&Giant); _giantcnt++)		\ 		mtx_unlock_flags(&Giant, MTX_NOSWITCH)
end_define

begin_define
define|#
directive|define
name|DROP_GIANT
parameter_list|()
define|\
value|do {									\ 	int _giantcnt;							\ 	WITNESS_SAVE_DECL(Giant);					\ 									\ 	if (mtx_owned(&Giant))						\ 		WITNESS_SAVE(&Giant.mtx_object, Giant);			\ 	for (_giantcnt = 0; mtx_owned(&Giant); _giantcnt++)		\ 		mtx_unlock(&Giant)
end_define

begin_define
define|#
directive|define
name|PICKUP_GIANT
parameter_list|()
define|\
value|mtx_assert(&Giant, MA_NOTOWNED);				\ 	while (_giantcnt--)						\ 		mtx_lock(&Giant);					\ 	if (mtx_owned(&Giant))						\ 		WITNESS_RESTORE(&Giant.mtx_object, Giant);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|PARTIAL_PICKUP_GIANT
parameter_list|()
define|\
value|mtx_assert(&Giant, MA_NOTOWNED);				\ 	while (_giantcnt--)						\ 		mtx_lock(&Giant);					\ 	if (mtx_owned(&Giant))						\ 		WITNESS_RESTORE(&Giant.mtx_object, Giant)
end_define

begin_comment
comment|/*  * The INVARIANTS-enabled mtx_assert() functionality.  *  * The constants need to be defined for INVARIANT_SUPPORT infrastructure  * support as _mtx_assert() itself uses them and the latter implies that  * _mtx_assert() must build.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANT_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|MA_OWNED
value|0x01
end_define

begin_define
define|#
directive|define
name|MA_NOTOWNED
value|0x02
end_define

begin_define
define|#
directive|define
name|MA_RECURSED
value|0x04
end_define

begin_define
define|#
directive|define
name|MA_NOTRECURSED
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INVARIANT_SUPPORT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

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
value|_mtx_assert((m), (what), __FILE__, __LINE__)
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
name|mtx_assert
parameter_list|(
name|m
parameter_list|,
name|what
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INVARIANTS */
end_comment

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
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_MUTEX_H_ */
end_comment

end_unit

