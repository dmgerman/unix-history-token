begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1996 Wolfgang Solfrank.  * Copyright (C) 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: fpu.c,v 1.5 2001/07/22 11:29:46 wiz Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<machine/fpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_function
name|void
name|enable_fpu
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|int
name|msr
decl_stmt|,
name|scratch
decl_stmt|;
name|struct
name|pcb
modifier|*
name|pcb
decl_stmt|;
name|struct
name|trapframe
modifier|*
name|tf
decl_stmt|;
name|pcb
operator|=
name|td
operator|->
name|td_pcb
expr_stmt|;
name|tf
operator|=
name|trapframe
argument_list|(
name|td
argument_list|)
expr_stmt|;
name|tf
operator|->
name|srr1
operator||=
name|PSL_FP
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|pcb
operator|->
name|pcb_flags
operator|&
name|PCB_FPU
operator|)
condition|)
block|{
name|memset
argument_list|(
operator|&
name|pcb
operator|->
name|pcb_fpu
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|pcb
operator|->
name|pcb_fpu
argument_list|)
expr_stmt|;
name|pcb
operator|->
name|pcb_flags
operator||=
name|PCB_FPU
expr_stmt|;
block|}
asm|__asm __volatile ("mfmsr %0; ori %1,%0,%2; mtmsr %1; isync"
block|:
literal|"=r"
operator|(
name|msr
operator|)
operator|,
literal|"=r"
operator|(
name|scratch
operator|)
operator|:
literal|"K"
operator|(
name|PSL_FP
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile ("lfd 0,0(%0); mtfsf 0xff,0"
end_asm

begin_expr_stmt
operator|::
literal|"b"
operator|(
operator|&
name|pcb
operator|->
name|pcb_fpu
operator|.
name|fpscr
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm ("lfd 0,0(%0);"
end_asm

begin_expr_stmt
literal|"lfd 1,8(%0);"
literal|"lfd 2,16(%0);"
literal|"lfd 3,24(%0);"
literal|"lfd 4,32(%0);"
literal|"lfd 5,40(%0);"
literal|"lfd 6,48(%0);"
literal|"lfd 7,56(%0);"
literal|"lfd 8,64(%0);"
literal|"lfd 9,72(%0);"
literal|"lfd 10,80(%0);"
literal|"lfd 11,88(%0);"
literal|"lfd 12,96(%0);"
literal|"lfd 13,104(%0);"
literal|"lfd 14,112(%0);"
literal|"lfd 15,120(%0);"
literal|"lfd 16,128(%0);"
literal|"lfd 17,136(%0);"
literal|"lfd 18,144(%0);"
literal|"lfd 19,152(%0);"
literal|"lfd 20,160(%0);"
literal|"lfd 21,168(%0);"
literal|"lfd 22,176(%0);"
literal|"lfd 23,184(%0);"
literal|"lfd 24,192(%0);"
literal|"lfd 25,200(%0);"
literal|"lfd 26,208(%0);"
literal|"lfd 27,216(%0);"
literal|"lfd 28,224(%0);"
literal|"lfd 29,232(%0);"
literal|"lfd 30,240(%0);"
literal|"lfd 31,248(%0)"
operator|::
literal|"b"
operator|(
operator|&
name|pcb
operator|->
name|pcb_fpu
operator|.
name|fpr
index|[
literal|0
index|]
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm __volatile ("mtmsr %0; isync" :: "r"(msr));
end_asm

begin_macro
unit|}  void
name|save_fpu
argument_list|(
argument|struct thread *td
argument_list|)
end_macro

begin_block
block|{
name|int
name|msr
decl_stmt|,
name|scratch
decl_stmt|;
name|struct
name|pcb
modifier|*
name|pcb
decl_stmt|;
name|pcb
operator|=
name|td
operator|->
name|td_pcb
expr_stmt|;
asm|__asm __volatile ("mfmsr %0; ori %1,%0,%2; mtmsr %1; isync"
block|:
literal|"=r"
operator|(
name|msr
operator|)
operator|,
literal|"=r"
operator|(
name|scratch
operator|)
operator|:
literal|"K"
operator|(
name|PSL_FP
operator|)
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm ("stfd 0,0(%0);"
end_asm

begin_expr_stmt
literal|"stfd 1,8(%0);"
literal|"stfd 2,16(%0);"
literal|"stfd 3,24(%0);"
literal|"stfd 4,32(%0);"
literal|"stfd 5,40(%0);"
literal|"stfd 6,48(%0);"
literal|"stfd 7,56(%0);"
literal|"stfd 8,64(%0);"
literal|"stfd 9,72(%0);"
literal|"stfd 10,80(%0);"
literal|"stfd 11,88(%0);"
literal|"stfd 12,96(%0);"
literal|"stfd 13,104(%0);"
literal|"stfd 14,112(%0);"
literal|"stfd 15,120(%0);"
literal|"stfd 16,128(%0);"
literal|"stfd 17,136(%0);"
literal|"stfd 18,144(%0);"
literal|"stfd 19,152(%0);"
literal|"stfd 20,160(%0);"
literal|"stfd 21,168(%0);"
literal|"stfd 22,176(%0);"
literal|"stfd 23,184(%0);"
literal|"stfd 24,192(%0);"
literal|"stfd 25,200(%0);"
literal|"stfd 26,208(%0);"
literal|"stfd 27,216(%0);"
literal|"stfd 28,224(%0);"
literal|"stfd 29,232(%0);"
literal|"stfd 30,240(%0);"
literal|"stfd 31,248(%0)"
operator|::
literal|"b"
operator|(
operator|&
name|pcb
operator|->
name|pcb_fpu
operator|.
name|fpr
index|[
literal|0
index|]
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm __volatile ("mffs 0; stfd 0,0(%0)" :: "b"(&pcb->pcb_fpu.fpscr));
end_asm

begin_asm
asm|__asm __volatile ("mtmsr %0; isync" :: "r"(msr));
end_asm

begin_expr_stmt
name|pcb
operator|->
name|pcb_fpcpu
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PCPU_SET
argument_list|(
name|fputhread
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

unit|}
end_unit

