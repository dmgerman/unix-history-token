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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Global locks */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|clock_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Assembly macros (for internal use only)  *------------------------------------------------------------------------------  */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* #ifndef I386_CPU */
end_comment

begin_comment
comment|/*  * For 486 and newer processors.  */
end_comment

begin_comment
comment|/* Get a sleep lock, deal with recursion inline. */
end_comment

begin_define
define|#
directive|define
name|_getlock_sleep
parameter_list|(
name|mtxp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|({				\ 	int	_res = MTX_UNOWNED;					\ 									\ 	__asm __volatile (						\ "	" __XSTRING(MPLOCKED) ""					\ "	cmpxchgl %3,%1;"
comment|/* Try */
value|\ "	jz	1f;"
comment|/* Got it */
value|\ "	andl	$" _V(MTX_FLAGMASK) ",%0;"
comment|/* turn off spec bits */
value|\ "	cmpl	%0,%3;"
comment|/* already have it? */
value|\ "	je	2f;"
comment|/* yes, recurse */
value|\ "	pushl	%4;"							\ "	pushl	%5;"							\ "	call	mtx_enter_hard;"					\ "	addl	$8,%%esp;"						\ "	jmp	1f;"							\ "2:"									\ "	" __XSTRING(MPLOCKED) ""					\ "	orl $" _V(MTX_RECURSE) ",%1;"					\ "	incl	%2;"							\ "1:"									\ "# getlock_sleep"							\ 	: "+a" (_res),
comment|/* 0 */
value|\ 	  "+m" (mtxp->mtx_lock),
comment|/* 1 */
value|\ 	  "+m" (mtxp->mtx_recurse)
comment|/* 2 */
value|\ 	: "r" (tid),
comment|/* 3 (input) */
value|\ 	  "gi" (type),
comment|/* 4 */
value|\ 	  "g" (mtxp)
comment|/* 5 */
value|\ 	: "cc", "memory", "ecx", "edx"
comment|/* used */
value|);		\ })
end_define

begin_comment
comment|/* Get a spin lock, handle recursion inline (as the less common case) */
end_comment

begin_define
define|#
directive|define
name|_getlock_spin_block
parameter_list|(
name|mtxp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|({				\ 	int	_res = MTX_UNOWNED;					\ 									\ 	__asm __volatile (						\ "	pushfl;"							\ "	cli;"								\ "	" __XSTRING(MPLOCKED) ""					\ "	cmpxchgl %3,%1;"
comment|/* Try */
value|\ "	jz	2f;"
comment|/* got it */
value|\ "	pushl	%4;"							\ "	pushl	%5;"							\ "	call	mtx_enter_hard;"
comment|/* mtx_enter_hard(mtxp, type, oflags) */
value|\ "	addl	$12,%%esp;"						\ "	jmp	1f;"							\ "2:	popl	%2;"
comment|/* save flags */
value|\ "1:"									\ "# getlock_spin_block"							\ 	: "+a" (_res),
comment|/* 0 */
value|\ 	  "+m" (mtxp->mtx_lock),
comment|/* 1 */
value|\ 	  "=m" (mtxp->mtx_savecrit)
comment|/* 2 */
value|\ 	: "r" (tid),
comment|/* 3 (input) */
value|\ 	  "gi" (type),
comment|/* 4 */
value|\ 	  "g" (mtxp)
comment|/* 5 */
value|\ 	: "cc", "memory", "ecx", "edx"
comment|/* used */
value|);		\ })
end_define

begin_comment
comment|/*  * Get a lock without any recursion handling. Calls the hard enter function if  * we can't get it inline.  */
end_comment

begin_define
define|#
directive|define
name|_getlock_norecurse
parameter_list|(
name|mtxp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|({				\ 	int	_res = MTX_UNOWNED;					\ 									\ 	__asm __volatile (						\ "	" __XSTRING(MPLOCKED) ""					\ "	cmpxchgl %2,%1;"
comment|/* Try */
value|\ "	jz	1f;"
comment|/* got it */
value|\ "	pushl	%3;"							\ "	pushl	%4;"							\ "	call	mtx_enter_hard;"
comment|/* mtx_enter_hard(mtxp, type) */
value|\ "	addl	$8,%%esp;"						\ "1:"									\ "# getlock_norecurse"							\ 	: "+a" (_res),
comment|/* 0 */
value|\ 	  "+m" (mtxp->mtx_lock)
comment|/* 1 */
value|\ 	: "r" (tid),
comment|/* 2 (input) */
value|\ 	  "gi" (type),
comment|/* 3 */
value|\ 	  "g" (mtxp)
comment|/* 4 */
value|\ 	: "cc", "memory", "ecx", "edx"
comment|/* used */
value|);		\ })
end_define

begin_comment
comment|/*  * Release a sleep lock assuming we haven't recursed on it, recursion is handled  * in the hard function.  */
end_comment

begin_define
define|#
directive|define
name|_exitlock_norecurse
parameter_list|(
name|mtxp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|({				\ 	int	_tid = (int)(tid);					\ 									\ 	__asm __volatile (						\ "	" __XSTRING(MPLOCKED) ""					\ "	cmpxchgl %4,%0;"
comment|/* try easy rel */
value|\ "	jz	1f;"
comment|/* released! */
value|\ "	pushl	%2;"							\ "	pushl	%3;"							\ "	call	mtx_exit_hard;"						\ "	addl	$8,%%esp;"						\ "1:"									\ "# exitlock_norecurse"							\ 	: "+m" (mtxp->mtx_lock),
comment|/* 0 */
value|\ 	  "+a" (_tid)
comment|/* 1 */
value|\ 	: "gi" (type),
comment|/* 2 (input) */
value|\ 	  "g" (mtxp),
comment|/* 3 */
value|\ 	  "r" (MTX_UNOWNED)
comment|/* 4 */
value|\ 	: "cc", "memory", "ecx", "edx"
comment|/* used */
value|);		\ })
end_define

begin_comment
comment|/*  * Release a sleep lock when its likely we recursed (the code to  * deal with simple recursion is inline).  */
end_comment

begin_define
define|#
directive|define
name|_exitlock
parameter_list|(
name|mtxp
parameter_list|,
name|tid
parameter_list|,
name|type
parameter_list|)
value|({					\ 	int	_tid = (int)(tid);					\ 									\ 	__asm __volatile (						\ "	" __XSTRING(MPLOCKED) ""					\ "	cmpxchgl %5,%0;"
comment|/* try easy rel */
value|\ "	jz	1f;"
comment|/* released! */
value|\ "	testl	$" _V(MTX_RECURSE) ",%%eax;"
comment|/* recursed? */
value|\ "	jnz	3f;"
comment|/* handle recursion */
value|\
comment|/* Lock not recursed and contested: do the hard way */
value|\ "	pushl	%3;"							\ "	pushl	%4;"							\ "	call	mtx_exit_hard;"
comment|/* mtx_exit_hard(mtxp,type) */
value|\ "	addl	$8,%%esp;"						\ "	jmp	1f;"							\
comment|/* lock recursed, lower recursion level */
value|\ "3:	decl	%1;"
comment|/* one less level */
value|\ "	jnz	1f;"
comment|/* still recursed, done */
value|\ "	lock; andl $~" _V(MTX_RECURSE) ",%0;"
comment|/* turn off recurse flag */
value|\ "1:"									\ "# exitlock"								\ 	: "+m" (mtxp->mtx_lock),
comment|/* 0 */
value|\ 	  "+m" (mtxp->mtx_recurse),
comment|/* 1 */
value|\ 	  "+a" (_tid)
comment|/* 2 */
value|\ 	: "gi" (type),
comment|/* 3 (input) */
value|\ 	  "g" (mtxp),
comment|/* 4 */
value|\ 	  "r" (MTX_UNOWNED)
comment|/* 5 */
value|\ 	: "cc", "memory", "ecx", "edx"
comment|/* used */
value|);		\ })
end_define

begin_comment
comment|/*  * Release a spin lock (with possible recursion).  *  * We use xchgl to clear lock (instead of simple store) to flush posting  * buffers and make the change visible to other CPU's.  */
end_comment

begin_define
define|#
directive|define
name|_exitlock_spin
parameter_list|(
name|mtxp
parameter_list|)
value|({						\ 	int	_res;							\ 									\ 	__asm __volatile (						\ "	movl	%1,%2;"							\ "	decl	%2;"							\ "	js	1f;"							\ "	movl	%2,%1;"							\ "	jmp	2f;"							\ "1:	movl	$ " _V(MTX_UNOWNED) ",%2;"				\ "	pushl	%3;"							\ "	xchgl	%2,%0;"					  		\ "	popfl;"								\ "2:"									\ "# exitlock_spin"							\ 	: "+m" (mtxp->mtx_lock),
comment|/* 0 */
value|\ 	  "+m" (mtxp->mtx_recurse),
comment|/* 1 */
value|\ 	  "=r" (_res)
comment|/* 2 */
value|\ 	: "g"  (mtxp->mtx_savecrit)
comment|/* 3 */
value|\ 	: "cc", "memory", "ecx"
comment|/* used */
value|);			\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I386_CPU */
end_comment

begin_undef
undef|#
directive|undef
name|_V
end_undef

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
comment|/*  * Simple assembly macros to get and release mutexes.  *  * Note: All of these macros accept a "flags" argument and are analoguous  *	 to the mtx_lock_flags and mtx_unlock_flags general macros. If one  *	 desires to not pass a flag, the value 0 may be passed as second  *	 argument.  *  * XXX: We only have MTX_LOCK_SPIN and MTX_UNLOCK_SPIN for now, since that's  *	all we use right now. We should add MTX_LOCK and MTX_UNLOCK (for sleep  *	locks) in the near future, however.  */
end_comment

begin_define
define|#
directive|define
name|MTX_LOCK_SPIN
parameter_list|(
name|lck
parameter_list|,
name|flags
parameter_list|)
define|\
value|pushl $0 ;							\ 	pushl $0 ;							\ 	pushl $flags ;							\ 	pushl $lck ;							\ 	call _mtx_lock_spin_flags ;					\ 	addl $0x10, %esp ;						\  #define MTX_UNLOCK_SPIN(lck)						\ 	pushl $0 ;							\ 	pushl $0 ;							\ 	pushl $0 ;							\ 	pushl $lck ;							\ 	call _mtx_unlock_spin_flags ;					\ 	addl $0x10, %esp ;
end_define

begin_comment
unit|\
comment|/*  * XXX: These two are broken right now and need to be made to work for  * XXX: sleep locks, as the above two work for spin locks. We're not in  * XXX: too much of a rush to do these as we do not use them right now.  */
end_comment

begin_define
define|#
directive|define
name|MTX_ENTER
parameter_list|(
name|lck
parameter_list|,
name|type
parameter_list|)
define|\
value|pushl	$0 ;
comment|/* dummy __LINE__ */
value|\ 	pushl	$0 ;
comment|/* dummy __FILE__ */
value|\ 	pushl	$type ;							\ 	pushl	$lck ;							\ 	call	_mtx_lock_XXX ;						\ 	addl	$16,%esp
end_define

begin_define
define|#
directive|define
name|MTX_EXIT
parameter_list|(
name|lck
parameter_list|,
name|type
parameter_list|)
define|\
value|pushl	$0 ;
comment|/* dummy __LINE__ */
value|\ 	pushl	$0 ;
comment|/* dummy __FILE__ */
value|\ 	pushl	$type ;							\ 	pushl	$lck ;							\ 	call	_mtx_unlock_XXX ;					\ 	addl	$16,%esp
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

