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
comment|/*  * Mutex flags  *  * Types  */
end_comment

begin_define
define|#
directive|define
name|MTX_DEF
value|0x0
end_define

begin_comment
comment|/* Default (spin/sleep) */
end_comment

begin_define
define|#
directive|define
name|MTX_SPIN
value|0x1
end_define

begin_comment
comment|/* Spin only lock */
end_comment

begin_comment
comment|/* Options */
end_comment

begin_define
define|#
directive|define
name|MTX_RECURSE
value|0x2
end_define

begin_comment
comment|/* Recursive lock (for mtx_init) */
end_comment

begin_define
define|#
directive|define
name|MTX_RLIKELY
value|0x4
end_define

begin_comment
comment|/* Recursion likely */
end_comment

begin_define
define|#
directive|define
name|MTX_NORECURSE
value|0x8
end_define

begin_comment
comment|/* No recursion possible */
end_comment

begin_define
define|#
directive|define
name|MTX_NOSPIN
value|0x10
end_define

begin_comment
comment|/* Don't spin before sleeping */
end_comment

begin_define
define|#
directive|define
name|MTX_NOSWITCH
value|0x20
end_define

begin_comment
comment|/* Do not switch on release */
end_comment

begin_define
define|#
directive|define
name|MTX_FIRST
value|0x40
end_define

begin_comment
comment|/* First spin lock holder */
end_comment

begin_define
define|#
directive|define
name|MTX_TOPHALF
value|0x80
end_define

begin_comment
comment|/* Interrupts not disabled on spin */
end_comment

begin_define
define|#
directive|define
name|MTX_QUIET
value|0x100
end_define

begin_comment
comment|/* Don't log a mutex event */
end_comment

begin_comment
comment|/* options that should be passed on to mtx_enter_hard, mtx_exit_hard */
end_comment

begin_define
define|#
directive|define
name|MTX_HARDOPTS
value|(MTX_SPIN | MTX_FIRST | MTX_TOPHALF | MTX_NOSWITCH)
end_define

begin_comment
comment|/* Flags/value used in mtx_lock */
end_comment

begin_define
define|#
directive|define
name|MTX_RECURSED
value|0x01
end_define

begin_comment
comment|/* (non-spin) lock held recursively */
end_comment

begin_define
define|#
directive|define
name|MTX_CONTESTED
value|0x02
end_define

begin_comment
comment|/* (non-spin) lock contested */
end_comment

begin_define
define|#
directive|define
name|MTX_FLAGMASK
value|~(MTX_RECURSED | MTX_CONTESTED)
end_define

begin_define
define|#
directive|define
name|MTX_UNOWNED
value|0x8
end_define

begin_comment
comment|/* Cookie for free mutex */
end_comment

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
comment|/* lock owner/gate/flags */
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
union|union
block|{
name|struct
name|mtx_debug
modifier|*
name|mtxu_debug
decl_stmt|;
specifier|const
name|char
modifier|*
name|mtxu_description
decl_stmt|;
block|}
name|mtx_union
union|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|proc
argument_list|)
name|mtx_blocked
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|mtx
argument_list|)
name|mtx_contested
expr_stmt|;
name|struct
name|mtx
modifier|*
name|mtx_next
decl_stmt|;
comment|/* all locks in system */
name|struct
name|mtx
modifier|*
name|mtx_prev
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* Prototypes */
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
name|flag
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

begin_comment
comment|/*  * Wrap the following functions with cpp macros so that filenames and line  * numbers are embedded in the code correctly.  */
end_comment

begin_function_decl
name|void
name|_mtx_enter
parameter_list|(
name|struct
name|mtx
modifier|*
name|mtxp
parameter_list|,
name|int
name|type
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
name|_mtx_try_enter
parameter_list|(
name|struct
name|mtx
modifier|*
name|mtxp
parameter_list|,
name|int
name|type
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
name|_mtx_exit
parameter_list|(
name|struct
name|mtx
modifier|*
name|mtxp
parameter_list|,
name|int
name|type
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
name|mtx_enter
parameter_list|(
name|mtxp
parameter_list|,
name|type
parameter_list|)
define|\
value|_mtx_enter((mtxp), (type), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|mtx_try_enter
parameter_list|(
name|mtxp
parameter_list|,
name|type
parameter_list|)
define|\
value|_mtx_try_enter((mtxp), (type), __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|mtx_exit
parameter_list|(
name|mtxp
parameter_list|,
name|type
parameter_list|)
define|\
value|_mtx_exit((mtxp), (type), __FILE__, __LINE__)
end_define

begin_comment
comment|/* Global locks */
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
comment|/*  * Used to replace return with an exit Giant and return.  */
end_comment

begin_define
define|#
directive|define
name|EGAR
parameter_list|(
name|a
parameter_list|)
define|\
value|do {									\ 	mtx_exit(&Giant, MTX_DEF);					\ 	return (a);							\ } while (0)
end_define

begin_define
define|#
directive|define
name|VEGAR
define|\
value|do {									\ 	mtx_exit(&Giant, MTX_DEF);					\ 	return;								\ } while (0)
end_define

begin_define
define|#
directive|define
name|DROP_GIANT_NOSWITCH
parameter_list|()
define|\
value|do {									\ 	int _giantcnt;							\ 	WITNESS_SAVE_DECL(Giant);					\ 									\ 	if (mtx_owned(&Giant))						\ 		WITNESS_SAVE(&Giant, Giant);				\ 	for (_giantcnt = 0; mtx_owned(&Giant); _giantcnt++)		\ 		mtx_exit(&Giant, MTX_DEF | MTX_NOSWITCH)
end_define

begin_define
define|#
directive|define
name|DROP_GIANT
parameter_list|()
define|\
value|do {									\ 	int _giantcnt;							\ 	WITNESS_SAVE_DECL(Giant);					\ 									\ 	if (mtx_owned(&Giant))						\ 		WITNESS_SAVE(&Giant, Giant);				\ 	for (_giantcnt = 0; mtx_owned(&Giant); _giantcnt++)		\ 		mtx_exit(&Giant, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|PICKUP_GIANT
parameter_list|()
define|\
value|mtx_assert(&Giant, MA_NOTOWNED);				\ 	while (_giantcnt--)						\ 		mtx_enter(&Giant, MTX_DEF);				\ 	if (mtx_owned(&Giant))						\ 		WITNESS_RESTORE(&Giant, Giant);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|PARTIAL_PICKUP_GIANT
parameter_list|()
define|\
value|mtx_assert(&Giant, MA_NOTOWNED);				\ 	while (_giantcnt--)						\ 		mtx_enter(&Giant, MTX_DEF);				\ 	if (mtx_owned(&Giant))						\ 		WITNESS_RESTORE(&Giant, Giant)
end_define

begin_comment
comment|/*  * Debugging  */
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
value|1
end_define

begin_define
define|#
directive|define
name|MA_NOTOWNED
value|2
end_define

begin_define
define|#
directive|define
name|MA_RECURSED
value|4
end_define

begin_define
define|#
directive|define
name|MA_NOTRECURSED
value|8
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
value|if (!(ex))							\ 		panic("Assertion %s failed at %s:%d", #ex, __FILE__, __LINE__)
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
value|if (!(ex))							\ 		panic("Assertion %s failed at %s:%d", what, __FILE__, __LINE__)
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
comment|/*  * Externally visible mutex functions.  *------------------------------------------------------------------------------  */
end_comment

begin_comment
comment|/*  * Return non-zero if a mutex is already owned by the current thread.  */
end_comment

begin_define
define|#
directive|define
name|mtx_owned
parameter_list|(
name|m
parameter_list|)
value|(((m)->mtx_lock& MTX_FLAGMASK) == (uintptr_t)CURTHD)
end_define

begin_comment
comment|/*  * Return non-zero if a mutex has been recursively acquired.  */
end_comment

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
comment|/* Common strings */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERN_MUTEX_C_
end_ifdef

begin_decl_stmt
name|char
name|STR_mtx_enter_fmt
index|[]
init|=
literal|"GOT %s [%p] r=%d at %s:%d"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_mtx_exit_fmt
index|[]
init|=
literal|"REL %s [%p] r=%d at %s:%d"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_mtx_try_enter_fmt
index|[]
init|=
literal|"TRY_ENTER %s [%p] result=%d at %s:%d"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_mtx_bad_type
index|[]
init|=
literal|"((type)& (MTX_NORECURSE | MTX_NOSWITCH)) == 0"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_mtx_owned
index|[]
init|=
literal|"mtx_owned(mpp)"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_mtx_recurse
index|[]
init|=
literal|"mpp->mtx_recurse == 0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERN_MUTEX_C_ */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_enter_fmt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_bad_type
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_exit_fmt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_owned
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_recurse
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_mtx_try_enter_fmt
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERN_MUTEX_C_ */
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

