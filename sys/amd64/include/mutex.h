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

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

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
comment|/*  * Debugging  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MUTEX_DEBUG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERN_MUTEX_C_
end_ifdef

begin_decl_stmt
name|char
name|STR_IEN
index|[]
init|=
literal|"fl& PSL_I"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_IDIS
index|[]
init|=
literal|"!(fl& PSL_I)"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|STR_SIEN
index|[]
init|=
literal|"mpp->mtx_saveintr& PSL_I"
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

begin_decl_stmt
specifier|extern
name|char
name|STR_SIEN
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MUTEX_DEBUG */
end_comment

begin_define
define|#
directive|define
name|ASS_IEN
value|MPASS2(read_eflags()& PSL_I, STR_IEN)
end_define

begin_define
define|#
directive|define
name|ASS_IDIS
value|MPASS2((read_eflags()& PSL_I) == 0, STR_IDIS)
end_define

begin_define
define|#
directive|define
name|ASS_SIEN
parameter_list|(
name|mpp
parameter_list|)
value|MPASS2((mpp)->mtx_saveintr& PSL_I, STR_SIEN)
end_define

begin_define
define|#
directive|define
name|mtx_legal2block
parameter_list|()
value|(read_eflags()& PSL_I)
end_define

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
value|({				\ 	int	_res;							\ 									\ 	__asm __volatile (						\ "	movl	$" _V(MTX_UNOWNED) ",%%eax;"
comment|/* Unowned cookie */
value|\ "	" MPLOCKED ""							\ "	cmpxchgl %3,%1;"
comment|/* Try */
value|\ "	jz	1f;"
comment|/* Got it */
value|\ "	andl	$" _V(MTX_FLAGMASK) ",%%eax;"
comment|/* turn off spec bits */
value|\ "	cmpl	%%eax,%3;"
comment|/* already have it? */
value|\ "	je	2f;"
comment|/* yes, recurse */
value|\ "	pushl	%4;"							\ "	pushl	%5;"							\ "	call	mtx_enter_hard;"					\ "	addl	$8,%%esp;"						\ "	jmp	1f;"							\ "2:"									\ "	" MPLOCKED ""							\ "	orl $" _V(MTX_RECURSE) ",%1;"					\ "	incl	%2;"							\ "1:"									\ "# getlock_sleep"							\ 	: "=&a" (_res),
comment|/* 0 (dummy output) */
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
value|\ 	: "memory"
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
value|({				\ 	int	_res;							\ 									\ 	__asm __volatile (						\ "	pushfl;"							\ "	cli;"								\ "	movl	$" _V(MTX_UNOWNED) ",%%eax;"
comment|/* Unowned cookie */
value|\ "	" MPLOCKED ""							\ "	cmpxchgl %3,%1;"
comment|/* Try */
value|\ "	jz	2f;"
comment|/* got it */
value|\ "	pushl	%4;"							\ "	pushl	%5;"							\ "	call	mtx_enter_hard;"
comment|/* mtx_enter_hard(mtxp, type, oflags) */
value|\ "	addl	$12,%%esp;"						\ "	jmp	1f;"							\ "2:	popl	%2;"
comment|/* save flags */
value|\ "1:"									\ "# getlock_spin_block"							\ 	: "=&a" (_res),
comment|/* 0 (dummy output) */
value|\ 	  "+m" (mtxp->mtx_lock),
comment|/* 1 */
value|\ 	  "=m" (mtxp->mtx_saveintr)
comment|/* 2 */
value|\ 	: "r" (tid),
comment|/* 3 (input) */
value|\ 	  "gi" (type),
comment|/* 4 */
value|\ 	  "g" (mtxp)
comment|/* 5 */
value|\ 	: "memory"
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
value|({				\ 	int	_res;							\ 									\ 	__asm __volatile (						\ "	movl	$" _V(MTX_UNOWNED) ",%%eax;"
comment|/* Unowned cookie */
value|\ "	" MPLOCKED ""							\ "	cmpxchgl %2,%1;"
comment|/* Try */
value|\ "	jz	1f;"
comment|/* got it */
value|\ "	pushl	%3;"							\ "	pushl	%4;"							\ "	call	mtx_enter_hard;"
comment|/* mtx_enter_hard(mtxp, type) */
value|\ "	addl	$8,%%esp;"						\ "1:"									\ "# getlock_norecurse"							\ 	: "=&a" (_res),
comment|/* 0 (dummy output) */
value|\ 	  "+m" (mtxp->mtx_lock)
comment|/* 1 */
value|\ 	: "r" (tid),
comment|/* 2 (input) */
value|\ 	  "gi" (type),
comment|/* 3 */
value|\ 	  "g" (mtxp)
comment|/* 4 */
value|\ 	: "memory"
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
value|({				\ 	int	_tid = (int)(tid);					\ 									\ 	__asm __volatile (						\ "	" MPLOCKED ""							\ "	cmpxchgl %4,%0;"
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
value|\ 	: "memory"
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
value|({					\ 	int	_tid = (int)(tid);					\ 									\ 	__asm __volatile (						\ "	" MPLOCKED ""							\ "	cmpxchgl %5,%0;"
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
value|\ 	: "memory"
comment|/* used */
value|);		\ })
end_define

begin_comment
comment|/*  * Release a spin lock (with possible recursion).  *  * We use cmpxchgl to clear lock (instead of simple store) to flush posting  * buffers and make the change visible to other CPU's.  */
end_comment

begin_define
define|#
directive|define
name|_exitlock_spin
parameter_list|(
name|mtxp
parameter_list|)
value|({						\ 	int	_res;							\ 									\ 	__asm __volatile (						\ "	movl	%1,%2;"							\ "	decl	%2;"							\ "	js	1f;"							\ "	movl	%2,%1;"							\ "	jmp	2f;"							\ "1:	movl	%0,%2;"							\ "	pushl	%3;"							\ "	" MPLOCKED ""							\ "	cmpxchgl %4,%0;"				  		\ "	popfl;"								\ "2:"									\ "# exitlock_spin"							\ 	: "+m" (mtxp->mtx_lock),
comment|/* 0 */
value|\ 	  "+m" (mtxp->mtx_recurse),
comment|/* 1 */
value|\ 	  "=&a" (_res)
comment|/* 2 */
value|\ 	: "g"  (mtxp->mtx_saveintr),
comment|/* 3 */
value|\ 	  "r" (MTX_UNOWNED)
comment|/* 4 */
value|\ 	: "memory"
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
comment|/*  * Simple assembly macros to get and release spin locks  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I386_CPU
argument_list|)
end_if

begin_define
define|#
directive|define
name|MTX_ENTER
parameter_list|(
name|lck
parameter_list|,
name|reg
parameter_list|)
define|\
value|movl	_curproc,reg;						\ 	pushfl;								\ 	cli;								\ 	movl	reg,lck+MTX_LOCK;					\ 	popl	lck+MTX_SAVEINTR;
end_define

begin_define
define|#
directive|define
name|MTX_EXIT
parameter_list|(
name|lck
parameter_list|,
name|reg
parameter_list|)
define|\
value|pushl	lck+MTX_SAVEINTR;					\ 	movl	$ MTX_UNOWNED,lck+MTX_LOCK;				\ 	popfl;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* I386_CPU */
end_comment

begin_define
define|#
directive|define
name|MTX_ENTER
parameter_list|(
name|lck
parameter_list|,
name|reg
parameter_list|)
define|\
value|movl	_curproc,reg;						\ 	pushfl;								\ 	cli;								\ 9:	movl	$ MTX_UNOWNED,%eax;					\ 	MPLOCKED							\ 	cmpxchgl reg,lck+MTX_LOCK;					\ 	jnz	9b;							\ 	popl	lck+MTX_SAVEINTR;
end_define

begin_comment
comment|/* Must use locked bus op (cmpxchg) when setting to unowned (barrier) */
end_comment

begin_define
define|#
directive|define
name|MTX_EXIT
parameter_list|(
name|lck
parameter_list|,
name|reg
parameter_list|)
define|\
value|pushl	lck+MTX_SAVEINTR;					\ 	movl	lck+MTX_LOCK,%eax;					\ 	movl	$ MTX_UNOWNED,reg;					\ 	MPLOCKED							\ 	cmpxchgl reg,lck+MTX_LOCK;					\ 	popfl;
end_define

begin_define
define|#
directive|define
name|MTX_ENTER_WITH_RECURSION
parameter_list|(
name|lck
parameter_list|,
name|reg
parameter_list|)
define|\
value|pushf;								\ 	cli;								\ 	movl	lck+MTX_LOCK,%eax;					\ 	cmpl	_curproc,%eax;						\ 	jne	7f;							\ 	incl	lck+MTX_RECURSE;					\ 	jmp	8f;							\ 7:	movl	$ MTX_UNOWNED,%eax;					\ 	MPLOCKED							\ 	cmpxchgl reg,lck+MTX_LOCK;      				\ 	jnz	9b;							\ 	popl	lck+MTX_SAVEINTR;					\ 	jmp	9f;							\ 8:	add	$4,%esp;						\ 9:
end_define

begin_define
define|#
directive|define
name|MTX_EXIT_WITH_RECURSION
parameter_list|(
name|lck
parameter_list|,
name|reg
parameter_list|)
define|\
value|movl	lck+MTX_RECURSE,%eax;					\ 	decl	%eax;							\ 	js	8f;							\ 	movl	%eax,lck+MTX_RECURSE;					\ 	jmp	9f;							\ 8:	pushl	lck+MTX_SAVEINTR;					\ 	movl	lck+MTX_LOCK,%eax;					\ 	movl	$ MTX_UNOWNED,reg;					\ 	MPLOCKED							\ 	cmpxchgl reg,lck+MTX_LOCK;					\ 	popf;								\ 9:
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I386_CPU */
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
comment|/* __MACHINE_MUTEX_H */
end_comment

end_unit

