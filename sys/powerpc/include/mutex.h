begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from BSDI $Id: mutex.h,v 2.7.2.35 2000/04/27 03:10:26 cp Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MUTEX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MUTEX_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
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
file|<machine/globaldata.h>
end_include

begin_include
include|#
directive|include
file|<machine/globals.h>
end_include

begin_comment
comment|/*  * If kern_mutex.c is being built, compile non-inlined versions of various  * functions so that kernel modules can use them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERN_MUTEX_C_
end_ifndef

begin_define
define|#
directive|define
name|_MTX_INLINE
value|static __inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_MTX_INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Mutex flags  *  * Types  */
end_comment

begin_define
define|#
directive|define
name|MTX_DEF
value|0x1
end_define

begin_comment
comment|/* Default (spin/sleep) */
end_comment

begin_define
define|#
directive|define
name|MTX_SPIN
value|0x2
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
name|MTX_RLIKELY
value|0x4
end_define

begin_comment
comment|/* (opt) Recursion likely */
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

begin_comment
comment|/* options that should be passed on to mtx_enter_hard, mtx_exit_hard */
end_comment

begin_define
define|#
directive|define
name|MTX_HARDOPTS
value|(MTX_DEF | MTX_SPIN | MTX_FIRST | MTX_TOPHALF | MTX_NOSWITCH)
end_define

begin_comment
comment|/* Flags/value used in mtx_lock */
end_comment

begin_define
define|#
directive|define
name|MTX_RECURSE
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
value|~(MTX_RECURSE | MTX_CONTESTED)
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

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Sleep/spin mutex  */
end_comment

begin_struct
struct|struct
name|mtx
block|{
specifier|volatile
name|u_int64_t
name|mtx_lock
decl_stmt|;
comment|/* lock owner/gate/flags */
specifier|volatile
name|u_int32_t
name|mtx_recurse
decl_stmt|;
comment|/* number of recursive holds */
name|u_int32_t
name|mtx_saveipl
decl_stmt|;
comment|/* saved ipl (for spin locks) */
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
ifdef|#
directive|ifdef
name|SMP_DEBUG
comment|/* If you add anything here, adjust the mtxf_t definition below */
name|struct
name|witness
modifier|*
name|mtx_witness
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|mtx
argument_list|)
name|mtx_held
expr_stmt|;
specifier|const
name|char
modifier|*
name|mtx_file
decl_stmt|;
name|int
name|mtx_line
decl_stmt|;
endif|#
directive|endif
comment|/* SMP_DEBUG */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Filler for structs which need to remain the same size  * whether or not SMP_DEBUG is turned on.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mtxf
block|{
ifdef|#
directive|ifdef
name|SMP_DEBUG
name|char
name|mtxf_data
index|[
literal|0
index|]
decl_stmt|;
else|#
directive|else
name|char
name|mtxf_data
index|[
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
endif|#
directive|endif
block|}
name|mtxf_t
typedef|;
end_typedef

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
comment|/* Misc */
end_comment

begin_define
define|#
directive|define
name|CURTHD
value|((u_int64_t)CURPROC)
end_define

begin_comment
comment|/* Current thread ID */
end_comment

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
name|mtx_enter_hard
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|ipl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mtx_exit_hard
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|,
name|int
name|type
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

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERN_MUTEX_C_
argument_list|)
operator|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

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
value|do {					\ 	mtx_exit(&Giant, MTX_DEF);	\ 	return (a);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|VEGAR
define|\
value|do {					\ 	mtx_exit(&Giant, MTX_DEF);	\ 	return;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|DROP_GIANT
parameter_list|()
define|\
value|do {								\ 	int _giantcnt;						\ 	WITNESS_SAVE_DECL(Giant);				\ 								\ 	WITNESS_SAVE(&Giant, Giant);				\ 	for (_giantcnt = 0; mtx_owned(&Giant); _giantcnt++)	\ 		mtx_exit(&Giant, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|PICKUP_GIANT
parameter_list|()
define|\
value|mtx_assert(&Giant, MA_NOTOWNED);			\ 	while (_giantcnt--)					\ 		mtx_enter(&Giant, MTX_DEF);			\ 	WITNESS_RESTORE(&Giant, Giant);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|PARTIAL_PICKUP_GIANT
parameter_list|()
define|\
value|mtx_assert(&Giant, MA_NOTOWNED);			\ 	while (_giantcnt--)					\ 		mtx_enter(&Giant, MTX_DEF);			\ 	WITNESS_RESTORE(&Giant, Giant)
end_define

begin_comment
comment|/*  * Debugging  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMP_DEBUG
end_ifndef

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SMP_DEBUG */
end_comment

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
name|mtx_assert
parameter_list|(
name|m
parameter_list|,
name|what
parameter_list|)
value|{						\ 	switch ((what)) {						\ 	case MA_OWNED:							\ 		ASS(mtx_owned((m)));					\ 		break;							\ 	case MA_NOTOWNED:						\ 		ASS(!mtx_owned((m)));					\ 		break;							\ 	default:							\ 		panic("unknown mtx_assert at %s:%d", __FILE__, __LINE__); \ 	}								\ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|ASS
parameter_list|(
name|ex
parameter_list|)
value|MPASS(ex)
end_define

begin_define
define|#
directive|define
name|MPASS
parameter_list|(
name|ex
parameter_list|)
value|if (!(ex)) panic("Assertion %s failed at %s:%d", \                 #ex, __FILE__, __LINE__)
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
value|if (!(ex)) panic("Assertion %s failed at %s:%d", \                 what, __FILE__, __LINE__)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MTX_STRS
end_ifdef

begin_decl_stmt
name|char
name|STR_IEN
index|[]
init|=
literal|"fl& 0x200"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_IDIS
index|[]
init|=
literal|"!(fl& 0x200)"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MTX_STRS */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|STR_IEN
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|STR_IDIS
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MTX_STRS */
end_comment

begin_define
define|#
directive|define
name|ASS_IEN
value|MPASS2((alpha_pal_rdps()& ALPHA_PSL_IPL_MASK)	\ 			       == ALPHA_PSL_IPL_HIGH, STR_IEN)
end_define

begin_define
define|#
directive|define
name|ASS_IDIS
value|MPASS2((alpha_pal_rdps()& ALPHA_PSL_IPL_MASK)	\ 			       != ALPHA_PSL_IPL_HIGH, STR_IDIS)
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
comment|/* SMP_DEBUG */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SMP_DEBUG
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASS
parameter_list|(
name|ex
parameter_list|)
end_define

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
name|where
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASS_IEN
end_define

begin_define
define|#
directive|define
name|ASS_IDIS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(SMP_DEBUG) || !defined(INVARIANTS) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITNESS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SMP_DEBUG
end_ifndef

begin_error
error|#
directive|error
error|WITNESS requires SMP_DEBUG
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP_DEBUG */
end_comment

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
value|if ((m)->mtx_witness != NULL)					\ 		witness_enter((m), (t), (f), (l))
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
value|if ((m)->mtx_witness != NULL)					\ 		witness_exit((m), (t), (f), (l))
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
value|do {									\ 	if ((m)->mtx_witness != NULL) 					\ 	    witness_save(m,&__CONCAT(n, __wf),&__CONCAT(n, __wl));	\ } while (0)
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
value|do {									\ 	if ((m)->mtx_witness != NULL)					\ 	    witness_restore(m, __CONCAT(n, __wf), __CONCAT(n, __wl));	\ } while (0)
end_define

begin_function_decl
name|void
name|witness_init
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_destroy
parameter_list|(
name|struct
name|mtx
modifier|*
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
name|void
name|witness_display
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
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

begin_comment
comment|/*  * flag++ is slezoid way of shutting up unused parameter warning  * in mtx_init()  */
end_comment

begin_define
define|#
directive|define
name|witness_init
parameter_list|(
name|m
parameter_list|,
name|flag
parameter_list|)
value|flag++
end_define

begin_define
define|#
directive|define
name|witness_destroy
parameter_list|(
name|m
parameter_list|)
end_define

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
name|witness_try_enter
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITNESS */
end_comment

begin_comment
comment|/*  * Assembly macros (for internal use only)  *--------------------------------------------------------------------------  */
end_comment

begin_comment
comment|/*  * Get a sleep lock, deal with recursion inline  */
end_comment

begin_define
define|#
directive|define
name|_V
parameter_list|(
name|x
parameter_list|)
value|__STRING(x)
end_define

begin_define
define|#
directive|define
name|_getlock_sleep
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|do {				     \ 	if (atomic_cmpset_64(&(mp)->mtx_lock, MTX_UNOWNED, (tid)) == 0) {    \ 		if (((mp)->mtx_lock& MTX_FLAGMASK) != (tid))		     \ 			mtx_enter_hard(mp, (type)& MTX_HARDOPTS, 0);	     \ 		else {							     \ 			atomic_set_64(&(mp)->mtx_lock, MTX_RECURSE);	     \ 			(mp)->mtx_recurse++;				     \ 		}							     \ 	} else {							     \ 		alpha_mb();						     \ 	}								     \ } while (0)
end_define

begin_comment
comment|/*  * Get a spin lock, handle recusion inline (as the less common case)  */
end_comment

begin_define
define|#
directive|define
name|_getlock_spin_block
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|do {				\ 	u_int _ipl = alpha_pal_swpipl(ALPHA_PSL_IPL_HIGH);		\ 	if (atomic_cmpset_64(&(mp)->mtx_lock, MTX_UNOWNED, (tid)) == 0) \ 		mtx_enter_hard(mp, (type)& MTX_HARDOPTS, _ipl);	\ 	else {								\ 		alpha_mb();						\ 		(mp)->mtx_saveipl = _ipl;				\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * Get a lock without any recursion handling. Calls the hard enter  * function if we can't get it inline.  */
end_comment

begin_define
define|#
directive|define
name|_getlock_norecurse
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|do {				\ 	if (atomic_cmpset_64(&(mp)->mtx_lock, MTX_UNOWNED, (tid)) == 0)	\ 		mtx_enter_hard((mp), (type)& MTX_HARDOPTS, 0);		\ 	else								\ 		alpha_mb();						\ } while (0)
end_define

begin_comment
comment|/*  * Release a sleep lock assuming we haven't recursed on it, recursion is  * handled in the hard function.  */
end_comment

begin_define
define|#
directive|define
name|_exitlock_norecurse
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|do {				\ 	alpha_mb();							\ 	if (atomic_cmpset_64(&(mp)->mtx_lock, (tid), MTX_UNOWNED) == 0)	\ 		mtx_exit_hard((mp), (type)& MTX_HARDOPTS);		\ } while (0)
end_define

begin_comment
comment|/*  * Release a sleep lock when its likely we recursed (the code to  * deal with simple recursion is inline).  */
end_comment

begin_define
define|#
directive|define
name|_exitlock
parameter_list|(
name|mp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|do {					\ 	alpha_mb();							\ 	if (atomic_cmpset_64(&(mp)->mtx_lock, (tid), MTX_UNOWNED) == 0) {\ 		if (((mp)->mtx_lock& MTX_RECURSE)&&			\ 		    (--(mp)->mtx_recurse == 0))				\ 			atomic_clear_64(&(mp)->mtx_lock, MTX_RECURSE);	\ 		else							\ 			mtx_exit_hard((mp), (type)& MTX_HARDOPTS);	\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * Release a spin lock (with possible recursion)  */
end_comment

begin_define
define|#
directive|define
name|_exitlock_spin
parameter_list|(
name|mp
parameter_list|)
value|do {						\ 	alpha_mb();							\ 	if ((mp)->mtx_recurse == 0) {					\ 		int _ipl = (mp)->mtx_saveipl;				\ 		atomic_cmpset_64(&(mp)->mtx_lock, (mp)->mtx_lock,	\ 		    MTX_UNOWNED);					\ 		alpha_pal_swpipl(_ipl);					\ 	} else {							\ 		(mp)->mtx_recurse--;					\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * Externally visible mutex functions  *------------------------------------------------------------------------  */
end_comment

begin_comment
comment|/*  * Return non-zero if a mutex is already owned by the current thread  */
end_comment

begin_define
define|#
directive|define
name|mtx_owned
parameter_list|(
name|m
parameter_list|)
value|(((m)->mtx_lock& MTX_FLAGMASK) == CURTHD)
end_define

begin_comment
comment|/* Common strings */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MTX_STRS
end_ifdef

begin_decl_stmt
name|char
name|STR_mtx_enter_fmt
index|[]
init|=
literal|"GOT %s [%p] at %s:%d r=%d"
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
name|STR_mtx_exit_fmt
index|[]
init|=
literal|"REL %s [%p] at %s:%d r=%d"
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

begin_decl_stmt
name|char
name|STR_mtx_try_enter_fmt
index|[]
init|=
literal|"TRY_ENTER %s [%p] at %s:%d result=%d"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MTX_STRS */
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
comment|/* MTX_STRS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KLD_MODULE
end_ifndef

begin_comment
comment|/*  * Get lock 'm', the macro handles the easy (and most common cases) and  * leaves the slow stuff to the mtx_enter_hard() function.  *  * Note: since type is usually a constant much of this code is optimized out  */
end_comment

begin_function
name|_MTX_INLINE
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
block|{
name|struct
name|mtx
modifier|*
name|mpp
init|=
name|mtxp
decl_stmt|;
comment|/* bits only valid on mtx_exit() */
name|MPASS2
argument_list|(
operator|(
operator|(
name|type
operator|)
operator|&
operator|(
name|MTX_NORECURSE
operator||
name|MTX_NOSWITCH
operator|)
operator|)
operator|==
literal|0
argument_list|,
name|STR_mtx_bad_type
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|type
operator|)
operator|&
name|MTX_SPIN
condition|)
block|{
comment|/* 		 * Easy cases of spin locks: 		 * 		 * 1) We already own the lock and will simply recurse on it (if 		 *    RLIKELY) 		 * 		 * 2) The lock is free, we just get it 		 */
if|if
condition|(
operator|(
name|type
operator|)
operator|&
name|MTX_RLIKELY
condition|)
block|{
comment|/* 			 * Check for recursion, if we already have this lock we 			 * just bump the recursion count. 			 */
if|if
condition|(
name|mpp
operator|->
name|mtx_lock
operator|==
name|CURTHD
condition|)
block|{
name|mpp
operator|->
name|mtx_recurse
operator|++
expr_stmt|;
goto|goto
name|done
goto|;
block|}
block|}
if|if
condition|(
operator|(
operator|(
name|type
operator|)
operator|&
name|MTX_TOPHALF
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* 			 * If an interrupt thread uses this we must block 			 * interrupts here. 			 */
name|_getlock_spin_block
argument_list|(
name|mpp
argument_list|,
name|CURTHD
argument_list|,
operator|(
name|type
operator|)
operator|&
name|MTX_HARDOPTS
argument_list|)
expr_stmt|;
block|}
else|else
name|_getlock_norecurse
argument_list|(
name|mpp
argument_list|,
name|CURTHD
argument_list|,
operator|(
name|type
operator|)
operator|&
name|MTX_HARDOPTS
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Sleep locks */
if|if
condition|(
operator|(
name|type
operator|)
operator|&
name|MTX_RLIKELY
condition|)
name|_getlock_sleep
argument_list|(
name|mpp
argument_list|,
name|CURTHD
argument_list|,
operator|(
name|type
operator|)
operator|&
name|MTX_HARDOPTS
argument_list|)
expr_stmt|;
else|else
name|_getlock_norecurse
argument_list|(
name|mpp
argument_list|,
name|CURTHD
argument_list|,
operator|(
name|type
operator|)
operator|&
name|MTX_HARDOPTS
argument_list|)
expr_stmt|;
block|}
name|done
label|:
name|WITNESS_ENTER
argument_list|(
name|mpp
argument_list|,
name|type
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|CTR5
argument_list|(
name|KTR_LOCK
argument_list|,
name|STR_mtx_enter_fmt
argument_list|,
name|mpp
operator|->
name|mtx_description
argument_list|,
name|mpp
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|mpp
operator|->
name|mtx_recurse
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Attempt to get MTX_DEF lock, return non-zero if lock acquired  *  * XXX DOES NOT HANDLE RECURSION  */
end_comment

begin_function
name|_MTX_INLINE
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
block|{
name|struct
name|mtx
modifier|*
specifier|const
name|mpp
init|=
name|mtxp
decl_stmt|;
name|int
name|rval
decl_stmt|;
name|rval
operator|=
name|atomic_cmpset_64
argument_list|(
operator|&
name|mpp
operator|->
name|mtx_lock
argument_list|,
name|MTX_UNOWNED
argument_list|,
name|CURTHD
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SMP_DEBUG
if|if
condition|(
name|rval
operator|&&
name|mpp
operator|->
name|mtx_witness
operator|!=
name|NULL
condition|)
block|{
name|ASS
argument_list|(
name|mpp
operator|->
name|mtx_recurse
operator|==
literal|0
argument_list|)
expr_stmt|;
name|witness_try_enter
argument_list|(
name|mpp
argument_list|,
name|type
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|CTR5
argument_list|(
name|KTR_LOCK
argument_list|,
name|STR_mtx_try_enter_fmt
argument_list|,
name|mpp
operator|->
name|mtx_description
argument_list|,
name|mpp
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|rval
argument_list|)
expr_stmt|;
return|return
name|rval
return|;
block|}
end_function

begin_comment
comment|/*  * Release lock m  */
end_comment

begin_function
name|_MTX_INLINE
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
block|{
name|struct
name|mtx
modifier|*
specifier|const
name|mpp
init|=
name|mtxp
decl_stmt|;
name|MPASS2
argument_list|(
name|mtx_owned
argument_list|(
name|mpp
argument_list|)
argument_list|,
name|STR_mtx_owned
argument_list|)
expr_stmt|;
name|WITNESS_EXIT
argument_list|(
name|mpp
argument_list|,
name|type
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|CTR5
argument_list|(
name|KTR_LOCK
argument_list|,
name|STR_mtx_exit_fmt
argument_list|,
name|mpp
operator|->
name|mtx_description
argument_list|,
name|mpp
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|mpp
operator|->
name|mtx_recurse
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|type
operator|)
operator|&
name|MTX_SPIN
condition|)
block|{
if|if
condition|(
operator|(
name|type
operator|)
operator|&
name|MTX_NORECURSE
condition|)
block|{
name|MPASS2
argument_list|(
name|mpp
operator|->
name|mtx_recurse
operator|==
literal|0
argument_list|,
name|STR_mtx_recurse
argument_list|)
expr_stmt|;
name|atomic_cmpset_64
argument_list|(
operator|&
name|mpp
operator|->
name|mtx_lock
argument_list|,
name|mpp
operator|->
name|mtx_lock
argument_list|,
name|MTX_UNOWNED
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|type
operator|)
operator|&
name|MTX_TOPHALF
operator|)
operator|==
literal|0
condition|)
name|alpha_pal_swpipl
argument_list|(
name|mpp
operator|->
name|mtx_saveipl
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|type
operator|)
operator|&
name|MTX_TOPHALF
condition|)
block|{
name|_exitlock_norecurse
argument_list|(
name|mpp
argument_list|,
name|CURTHD
argument_list|,
operator|(
name|type
operator|)
operator|&
name|MTX_HARDOPTS
argument_list|)
expr_stmt|;
block|}
else|else
name|_exitlock_spin
argument_list|(
name|mpp
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Handle sleep locks */
if|if
condition|(
operator|(
name|type
operator|)
operator|&
name|MTX_RLIKELY
condition|)
name|_exitlock
argument_list|(
name|mpp
argument_list|,
name|CURTHD
argument_list|,
operator|(
name|type
operator|)
operator|&
name|MTX_HARDOPTS
argument_list|)
expr_stmt|;
else|else
block|{
name|_exitlock_norecurse
argument_list|(
name|mpp
argument_list|,
name|CURTHD
argument_list|,
operator|(
name|type
operator|)
operator|&
name|MTX_HARDOPTS
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KLD_MODULE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !LOCORE */
end_comment

begin_comment
comment|/*  * Simple assembly macros to get and release non-recursive spin locks  */
end_comment

begin_define
define|#
directive|define
name|MTX_ENTER
parameter_list|(
name|lck
parameter_list|)
define|\
value|ldiq	a0, ALPHA_PSL_IPL_HIGH;		\ 	call_pal PAL_OSF1_swpipl;		\ 1:	ldq_l	a0, lck+MTX_LOCK;		\ 	cmpeq	a0, MTX_UNOWNED, a1;		\ 	beq	a1, 1b;				\ 	ldq	a0, PC_CURPROC(globalp);	\ 	stq_c	a0, lck+MTX_LOCK;		\ 	beq	a0, 1b;				\ 	mb;					\ 	stl	v0, lck+MTX_SAVEIPL
end_define

begin_define
define|#
directive|define
name|MTX_EXIT
parameter_list|(
name|lck
parameter_list|)
define|\
value|mb;					\ 	ldiq	a0, MTX_UNOWNED;		\ 	stq	a0, lck+MTX_LOCK;		\ 	ldl	a0, lck+MTX_SAVEIPL;		\ 	call_pal PAL_OSF1_swpipl
end_define

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
comment|/* __MACHINE_MUTEX_H */
end_comment

end_unit

