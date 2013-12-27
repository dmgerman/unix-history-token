begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2006 Semihalf, Rafal Jaworowski<raj@semihalf.com>  * Copyright 2002 by Peter Grehan.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * Interrupts are dispatched to here from locore asm  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* RCS ID& Copyright macro defns */
end_comment

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/db_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_include
include|#
directive|include
file|"pic_if.h"
end_include

begin_function_decl
specifier|extern
name|void
name|decr_intr
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|powerpc_decr_interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|powerpc_extr_interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|powerpc_crit_interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|powerpc_mchk_interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|dump_frame
parameter_list|(
name|struct
name|trapframe
modifier|*
name|framep
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|dump_frame
parameter_list|(
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"\n*** *** STACK FRAME DUMP *** ***\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  exc  = 0x%x\n"
argument_list|,
name|frame
operator|->
name|exc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  srr0 = 0x%08x\n"
argument_list|,
name|frame
operator|->
name|srr0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  srr1 = 0x%08x\n"
argument_list|,
name|frame
operator|->
name|srr1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  dear = 0x%08x\n"
argument_list|,
name|frame
operator|->
name|cpu
operator|.
name|booke
operator|.
name|dear
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  esr  = 0x%08x\n"
argument_list|,
name|frame
operator|->
name|cpu
operator|.
name|booke
operator|.
name|esr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  lr   = 0x%08x\n"
argument_list|,
name|frame
operator|->
name|lr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  cr   = 0x%08x\n"
argument_list|,
name|frame
operator|->
name|cr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  sp   = 0x%08x\n"
argument_list|,
name|frame
operator|->
name|fixreg
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
name|i
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"  R%02d = 0x%08x"
argument_list|,
name|i
argument_list|,
name|frame
operator|->
name|fixreg
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|&
literal|0x3
operator|)
operator|==
literal|3
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|powerpc_crit_interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
name|framep
parameter_list|)
block|{
name|printf
argument_list|(
literal|"powerpc_crit_interrupt: critical interrupt!\n"
argument_list|)
expr_stmt|;
name|dump_frame
argument_list|(
name|framep
argument_list|)
expr_stmt|;
name|trap
argument_list|(
name|framep
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|powerpc_mchk_interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
name|framep
parameter_list|)
block|{
name|printf
argument_list|(
literal|"powerpc_mchk_interrupt: machine check interrupt!\n"
argument_list|)
expr_stmt|;
name|dump_frame
argument_list|(
name|framep
argument_list|)
expr_stmt|;
name|trap
argument_list|(
name|framep
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Decrementer interrupt routine  */
end_comment

begin_function
name|void
name|powerpc_decr_interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
name|framep
parameter_list|)
block|{
name|struct
name|thread
modifier|*
name|td
decl_stmt|;
name|struct
name|trapframe
modifier|*
name|oldframe
decl_stmt|;
name|td
operator|=
name|curthread
expr_stmt|;
name|critical_enter
argument_list|()
expr_stmt|;
name|atomic_add_int
argument_list|(
operator|&
name|td
operator|->
name|td_intr_nesting_level
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|oldframe
operator|=
name|td
operator|->
name|td_intr_frame
expr_stmt|;
name|td
operator|->
name|td_intr_frame
operator|=
name|framep
expr_stmt|;
name|decr_intr
argument_list|(
name|framep
argument_list|)
expr_stmt|;
name|td
operator|->
name|td_intr_frame
operator|=
name|oldframe
expr_stmt|;
name|atomic_subtract_int
argument_list|(
operator|&
name|td
operator|->
name|td_intr_nesting_level
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|critical_exit
argument_list|()
expr_stmt|;
name|framep
operator|->
name|srr1
operator|&=
operator|~
name|PSL_WE
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * External input interrupt routine  */
end_comment

begin_function
name|void
name|powerpc_extr_interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
name|framep
parameter_list|)
block|{
name|critical_enter
argument_list|()
expr_stmt|;
name|PIC_DISPATCH
argument_list|(
name|root_pic
argument_list|,
name|framep
argument_list|)
expr_stmt|;
name|critical_exit
argument_list|()
expr_stmt|;
name|framep
operator|->
name|srr1
operator|&=
operator|~
name|PSL_WE
expr_stmt|;
block|}
end_function

end_unit

