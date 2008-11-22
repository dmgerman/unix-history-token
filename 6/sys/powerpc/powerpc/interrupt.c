begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2002 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<machine/fpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
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
file|<machine/spr.h>
end_include

begin_include
include|#
directive|include
file|<machine/sr.h>
end_include

begin_include
include|#
directive|include
file|<machine/interruptvar.h>
end_include

begin_function_decl
name|void
name|powerpc_interrupt
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * External interrupt install routines  */
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|powerpc_extintr_handler
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|ext_intr_install
parameter_list|(
name|void
function_decl|(
modifier|*
name|new_extint
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|powerpc_extintr_handler
operator|=
name|new_extint
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|decr_intr
parameter_list|(
name|struct
name|clockframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|trap
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * A very short dispatch, to try and maximise assembler code use  * between all exception types. Maybe 'true' interrupts should go  * here, and the trap code can come in separately  */
end_comment

begin_function
name|void
name|powerpc_interrupt
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
name|clockframe
name|ckframe
decl_stmt|;
name|td
operator|=
name|curthread
expr_stmt|;
switch|switch
condition|(
name|framep
operator|->
name|exc
condition|)
block|{
case|case
name|EXC_EXI
case|:
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
call|(
modifier|*
name|powerpc_extintr_handler
call|)
argument_list|()
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
break|break;
case|case
name|EXC_DECR
case|:
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
name|ckframe
operator|.
name|srr0
operator|=
name|framep
operator|->
name|srr0
expr_stmt|;
name|ckframe
operator|.
name|srr1
operator|=
name|framep
operator|->
name|srr1
expr_stmt|;
name|decr_intr
argument_list|(
operator|&
name|ckframe
argument_list|)
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
break|break;
default|default:
comment|/* 		 * Re-enable interrupts and call the generic trap code 		 */
if|#
directive|if
literal|0
block|printf("powerpc_interrupt: got trap\n"); 		mtmsr(mfmsr() | PSL_EE); 		isync();
endif|#
directive|endif
name|trap
argument_list|(
name|framep
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

