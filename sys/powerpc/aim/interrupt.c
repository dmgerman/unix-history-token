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
file|"opt_hwpmc_hooks.h"
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|HWPMC_HOOKS
end_ifdef

begin_include
include|#
directive|include
file|<sys/pmckern.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<machine/clock.h>
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
file|"pic_if.h"
end_include

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
name|trapframe
modifier|*
name|oldframe
decl_stmt|;
name|register_t
name|ee
decl_stmt|;
name|td
operator|=
name|curthread
expr_stmt|;
name|CTR2
argument_list|(
name|KTR_INTR
argument_list|,
literal|"%s: EXC=%x"
argument_list|,
name|__func__
argument_list|,
name|framep
operator|->
name|exc
argument_list|)
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
break|break;
case|case
name|EXC_DECR
case|:
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
break|break;
ifdef|#
directive|ifdef
name|HWPMC_HOOKS
case|case
name|EXC_PERF
case|:
name|critical_enter
argument_list|()
expr_stmt|;
name|KASSERT
argument_list|(
name|pmc_intr
operator|!=
name|NULL
argument_list|,
operator|(
literal|"Performance exception, but no handler!"
operator|)
argument_list|)
expr_stmt|;
call|(
modifier|*
name|pmc_intr
call|)
argument_list|(
name|PCPU_GET
argument_list|(
name|cpuid
argument_list|)
argument_list|,
name|framep
argument_list|)
expr_stmt|;
if|if
condition|(
name|pmc_hook
operator|&&
operator|(
name|PCPU_GET
argument_list|(
name|curthread
argument_list|)
operator|->
name|td_pflags
operator|&
name|TDP_CALLCHAIN
operator|)
condition|)
name|pmc_hook
argument_list|(
name|PCPU_GET
argument_list|(
name|curthread
argument_list|)
argument_list|,
name|PMC_FN_USER_CALLCHAIN
argument_list|,
name|framep
argument_list|)
expr_stmt|;
name|critical_exit
argument_list|()
expr_stmt|;
break|break;
endif|#
directive|endif
default|default:
comment|/* Re-enable interrupts if applicable. */
name|ee
operator|=
name|framep
operator|->
name|srr1
operator|&
name|PSL_EE
expr_stmt|;
if|if
condition|(
name|ee
operator|!=
literal|0
condition|)
name|mtmsr
argument_list|(
name|mfmsr
argument_list|()
operator||
name|ee
argument_list|)
expr_stmt|;
name|trap
argument_list|(
name|framep
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

