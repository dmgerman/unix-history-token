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
comment|/*  * Mutex types and options stored in mutex->mtx_flags   */
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
value|0x00000002
end_define

begin_comment
comment|/* Option: lock allowed to recurse */
end_comment

begin_comment
comment|/*  * Option flags passed to certain lock/unlock routines, through the use  * of corresponding mtx_{lock,unlock}_flags() interface macros.  *  * XXX: The only reason we make these bits not interfere with the above "types  *	and options" bits is because we have to pass both to the witness  *	routines right now; if/when we clean up the witness interface to  *	not check for mutex type from the passed in flag, but rather from  *	the mutex lock's mtx_flags field, then we can change these values to  *	0x1, 0x2, ...   */
end_comment

begin_define
define|#
directive|define
name|MTX_NOSWITCH
value|0x00000004
end_define

begin_comment
comment|/* Do not switch on release */
end_comment

begin_define
define|#
directive|define
name|MTX_QUIET
value|0x00000008
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

begin_struct_decl
struct_decl|struct
name|mtx_debug
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Sleep/spin mutex  */
end_comment

begin_struct
struct|struct
name|mtx
block|{
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
name|u_int
name|mtx_saveintr
decl_stmt|;
comment|/* saved flags (for spin locks) */
name|int
name|mtx_flags
decl_stmt|;
comment|/* flags passed to mtx_init() */
specifier|const
name|char
modifier|*
name|mtx_description
decl_stmt|;
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
name|struct
name|mtx
modifier|*
name|mtx_next
decl_stmt|;
comment|/* all existing locks 	*/
name|struct
name|mtx
modifier|*
name|mtx_prev
decl_stmt|;
comment|/*  in system...	*/
name|struct
name|mtx_debug
modifier|*
name|mtx_debug
decl_stmt|;
comment|/* debugging information... */
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
comment|/*  * Strings for KTR_LOCK tracing.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_lock_slp
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_lock_spn
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_unlock_slp
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_unlock_spn
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes  *  * NOTE: Functions prepended with `_' (underscore) are exported to other parts  *	 of the kernel via macros, thus allowing us to use the cpp __FILE__  *	 and __LINE__. These functions should not be called directly by any  *	 code using the IPI. Their macros cover their functionality.  *  * [See below for descriptions]  *  */
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
name|u_int
name|mtx_intr
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
parameter_list|)
value|do {				\ 	if (!_obtain_lock((mp), (tid)))					\ 		_mtx_lock_sleep((mp), (opts), __FILE__, __LINE__);	\ } while (0)
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
parameter_list|)
value|do {				\ 	u_int _mtx_intr = save_intr();					\ 	disable_intr();							\ 	if (!_obtain_lock((mp), (tid))) {				\ 		if ((mp)->mtx_lock == (uintptr_t)(tid))			\ 			(mp)->mtx_recurse++;				\ 		else							\ 			_mtx_lock_spin((mp), (opts), _mtx_intr,		\ 			    __FILE__, __LINE__);			\ 	} else								\ 		(mp)->mtx_saveintr = _mtx_intr;				\ } while (0)
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
parameter_list|)
value|do {				\ 	if (!_release_lock((mp), (tid)))				\ 		_mtx_unlock_sleep((mp), (opts), __FILE__, __LINE__);	\ } while (0)
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
value|do {						\ 	u_int _mtx_intr = (mp)->mtx_saveintr;				\ 	if (mtx_recursed((mp)))						\ 		(mp)->mtx_recurse--;					\ 	else {								\ 		_release_lock_quick((mp));				\ 		restore_intr(_mtx_intr);				\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Exported lock manipulation interface.  *  * mtx_lock(m) locks MTX_DEF mutex `m'  *  * mtx_lock_spin(m) locks MTX_SPIN mutex `m'  *  * mtx_unlock(m) unlocks MTX_DEF mutex `m'  *  * mtx_unlock_spin(m) unlocks MTX_SPIN mutex `m'  *  * mtx_lock_spin_flags(m, opts) and mtx_lock_flags(m, opts) locks mutex `m'  *     and passes option flags `opts' to the "hard" function, if required.  *     With these routines, it is possible to pass flags such as MTX_QUIET  *     and/or MTX_NOSWITCH to the appropriate lock manipulation routines.  *  * mtx_trylock(m) attempts to acquire MTX_DEF mutex `m' but doesn't sleep if  *     it cannot. Rather, it returns 0 on failure and non-zero on success.  *     It does NOT handle recursion as we assume that if a caller is properly  *     using this part of the interface, he will know that the lock in question  *     is _not_ recursed.  *  * mtx_trylock_flags(m, opts) is used the same way as mtx_trylock() but accepts  *     relevant option flags `opts.'  *  * mtx_owned(m) returns non-zero if the current thread owns the lock `m'  *  * mtx_recursed(m) returns non-zero if the lock `m' is presently recursed.  */
end_comment

begin_define
define|#
directive|define
name|mtx_lock
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	MPASS(curproc != NULL);						\ 	_get_sleep_lock((m), curproc, 0);				\ 	CTR5(KTR_LOCK, STR_mtx_lock_slp, (m)->mtx_description, (m),	\ 	    (m)->mtx_recurse, __FILE__,	__LINE__);			\ 	WITNESS_ENTER((m), (m)->mtx_flags, __FILE__, __LINE__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|mtx_lock_spin
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	MPASS(curproc != NULL);						\ 	_get_spin_lock((m), curproc, 0);				\ 	CTR5(KTR_LOCK, STR_mtx_lock_spn, (m)->mtx_description, (m),	\ 	    (m)->mtx_recurse, __FILE__,	__LINE__);			\ 	WITNESS_ENTER((m), (m)->mtx_flags, __FILE__, __LINE__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|mtx_unlock
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	MPASS(curproc != NULL);						\ 	WITNESS_EXIT((m), (m)->mtx_flags, __FILE__, __LINE__);		\ 	mtx_assert((m), MA_OWNED);					\ 	_rel_sleep_lock((m), curproc, 0);				\ 	CTR5(KTR_LOCK, STR_mtx_unlock_slp, (m)->mtx_description, (m),	\ 	    (m)->mtx_recurse, __FILE__,	__LINE__);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|mtx_unlock_spin
parameter_list|(
name|m
parameter_list|)
value|do {						\ 	MPASS(curproc != NULL);						\ 	WITNESS_EXIT((m), (m)->mtx_flags, __FILE__, __LINE__);		\ 	mtx_assert((m), MA_OWNED);					\ 	_rel_spin_lock((m));						\ 	CTR5(KTR_LOCK, STR_mtx_unlock_spn, (m)->mtx_description, (m),	\ 	    (m)->mtx_recurse, __FILE__,	__LINE__);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|mtx_lock_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|)
value|do {					\ 	MPASS(curproc != NULL);						\ 	_get_sleep_lock((m), curproc, (opts));				\ 	if (((opts)& MTX_QUIET) == 0)					\ 		CTR5(KTR_LOCK, STR_mtx_lock_slp,			\ 		    (m)->mtx_description, (m), (m)->mtx_recurse, 	\ 		    __FILE__, __LINE__);				\ 	WITNESS_ENTER((m), ((m)->mtx_flags | (opts)), __FILE__,		\ 	    __LINE__);							\ } while (0)
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
value|do {				\ 	MPASS(curproc != NULL);						\ 	_get_spin_lock((m), curproc, (opts));				\ 	if (((opts)& MTX_QUIET) == 0)					\ 		CTR5(KTR_LOCK, STR_mtx_lock_spn,			\ 		    (m)->mtx_description, (m), (m)->mtx_recurse, 	\ 		    __FILE__, __LINE__);				\ 	WITNESS_ENTER((m), ((m)->mtx_flags | (opts)), __FILE__,		\ 	    __LINE__);							\ } while (0)
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
value|do {					\ 	MPASS(curproc != NULL);						\ 	WITNESS_EXIT((m), ((m)->mtx_flags | (opts)), __FILE__,		\ 	    __LINE__);							\ 	mtx_assert((m), MA_OWNED);					\ 	_rel_sleep_lock((m), curproc, (opts));				\ 	if (((opts)& MTX_QUIET) == 0)					\ 		CTR5(KTR_LOCK, STR_mtx_unlock_slp,			\ 		    (m)->mtx_description, (m), (m)->mtx_recurse, 	\ 		    __FILE__, __LINE__);				\ } while (0)
end_define

begin_comment
comment|/*  * The MTX_SPIN unlock case is all inlined, so we handle the MTX_QUIET  * flag right in the macro. Not a problem as if we don't have KTR_LOCK, this  * check will be optimized out.  */
end_comment

begin_define
define|#
directive|define
name|mtx_unlock_spin_flags
parameter_list|(
name|m
parameter_list|,
name|opts
parameter_list|)
value|do {				\ 	MPASS(curproc != NULL);						\ 	WITNESS_EXIT((m), ((m)->mtx_flags | (opts)), __FILE__,		\ 	    __LINE__);							\ 	mtx_assert((m), MA_OWNED);					\ 	_rel_spin_lock((m));						\ 	if (((opts)& MTX_QUIET) == 0)					\ 		CTR5(KTR_LOCK, STR_mtx_unlock_spn,			\ 		    (m)->mtx_description, (m), (m)->mtx_recurse, 	\ 		    __FILE__, __LINE__);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|mtx_trylock
parameter_list|(
name|m
parameter_list|)
define|\
value|_mtx_trylock((m), 0, __FILE__, __LINE__)
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
value|do {									\ 	int _giantcnt;							\ 	WITNESS_SAVE_DECL(Giant);					\ 									\ 	if (mtx_owned(&Giant))						\ 		WITNESS_SAVE(&Giant, Giant);				\ 	for (_giantcnt = 0; mtx_owned(&Giant); _giantcnt++)		\ 		mtx_unlock_flags(&Giant, MTX_NOSWITCH)
end_define

begin_define
define|#
directive|define
name|DROP_GIANT
parameter_list|()
define|\
value|do {									\ 	int _giantcnt;							\ 	WITNESS_SAVE_DECL(Giant);					\ 									\ 	if (mtx_owned(&Giant))						\ 		WITNESS_SAVE(&Giant, Giant);				\ 	for (_giantcnt = 0; mtx_owned(&Giant); _giantcnt++)		\ 		mtx_unlock(&Giant)
end_define

begin_define
define|#
directive|define
name|PICKUP_GIANT
parameter_list|()
define|\
value|mtx_assert(&Giant, MA_NOTOWNED);				\ 	while (_giantcnt--)						\ 		mtx_lock(&Giant);					\ 	if (mtx_owned(&Giant))						\ 		WITNESS_RESTORE(&Giant, Giant);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|PARTIAL_PICKUP_GIANT
parameter_list|()
define|\
value|mtx_assert(&Giant, MA_NOTOWNED);				\ 	while (_giantcnt--)						\ 		mtx_lock(&Giant);					\ 	if (mtx_owned(&Giant))						\ 		WITNESS_RESTORE(&Giant, Giant)
end_define

begin_comment
comment|/*  * The INVARIANTS-enabled mtx_assert() functionality.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
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

begin_comment
comment|/*  * The MUTEX_DEBUG-enabled MPASS*() extra sanity-check macros.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MUTEX_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|MPASS
parameter_list|(
name|ex
parameter_list|)
define|\
value|if (!(ex))							\ 		panic("Assertion %s failed at %s:%d", #ex, __FILE__,	\ 		    __LINE__)
end_define

begin_define
define|#
directive|define
name|MPASS2
parameter_list|(
name|ex
parameter_list|,
name|what
parameter_list|)
define|\
value|if (!(ex))							\ 		panic("Assertion %s failed at %s:%d", what, __FILE__,	\ 		    __LINE__)
end_define

begin_define
define|#
directive|define
name|MPASS3
parameter_list|(
name|ex
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|if (!(ex))							\ 		panic("Assertion %s failed at %s:%d", #ex, file, line)
end_define

begin_define
define|#
directive|define
name|MPASS4
parameter_list|(
name|ex
parameter_list|,
name|what
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|if (!(ex))							\ 		panic("Assertion %s failed at %s:%d", what, file, line)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MUTEX_DEBUG */
end_comment

begin_define
define|#
directive|define
name|MPASS
parameter_list|(
name|ex
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MPASS2
parameter_list|(
name|ex
parameter_list|,
name|what
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MPASS3
parameter_list|(
name|ex
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MPASS4
parameter_list|(
name|ex
parameter_list|,
name|what
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MUTEX_DEBUG */
end_comment

begin_comment
comment|/*  * Exported WITNESS-enabled functions and corresponding wrapper macros.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITNESS
end_ifdef

begin_function_decl
name|void
name|witness_save
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_restore
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_enter
parameter_list|(
name|struct
name|mtx
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

begin_function_decl
name|void
name|witness_try_enter
parameter_list|(
name|struct
name|mtx
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

begin_function_decl
name|void
name|witness_exit
parameter_list|(
name|struct
name|mtx
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

begin_function_decl
name|int
name|witness_list
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|witness_sleep
parameter_list|(
name|int
parameter_list|,
name|struct
name|mtx
modifier|*
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
name|WITNESS_ENTER
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|witness_enter((m), (t), (f), (l))
end_define

begin_define
define|#
directive|define
name|WITNESS_EXIT
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|witness_exit((m), (t), (f), (l))
end_define

begin_define
define|#
directive|define
name|WITNESS_SLEEP
parameter_list|(
name|check
parameter_list|,
name|m
parameter_list|)
define|\
value|witness_sleep(check, (m), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|WITNESS_SAVE_DECL
parameter_list|(
name|n
parameter_list|)
define|\
value|const char * __CONCAT(n, __wf);					\ 	int __CONCAT(n, __wl)
end_define

begin_define
define|#
directive|define
name|WITNESS_SAVE
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|witness_save(m,&__CONCAT(n, __wf),&__CONCAT(n, __wl))
end_define

begin_define
define|#
directive|define
name|WITNESS_RESTORE
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|witness_restore(m, __CONCAT(n, __wf), __CONCAT(n, __wl))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WITNESS */
end_comment

begin_define
define|#
directive|define
name|witness_enter
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|witness_tryenter
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|witness_exit
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|witness_list
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|witness_sleep
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_ENTER
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_EXIT
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_SLEEP
parameter_list|(
name|check
parameter_list|,
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_SAVE_DECL
parameter_list|(
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_SAVE
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_RESTORE
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITNESS */
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

