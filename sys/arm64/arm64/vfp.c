begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VFP
end_ifdef

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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/vfp.h>
end_include

begin_comment
comment|/* Sanity check we can store all the VFP registers */
end_comment

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
operator|(
operator|(
expr|struct
name|pcb
operator|*
operator|)
literal|0
operator|)
operator|->
name|pcb_vfp
argument_list|)
operator|==
literal|16
operator|*
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|vfp_enable
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|cpacr
decl_stmt|;
name|cpacr
operator|=
name|READ_SPECIALREG
argument_list|(
name|cpacr_el1
argument_list|)
expr_stmt|;
name|cpacr
operator|=
operator|(
name|cpacr
operator|&
operator|~
name|CPACR_FPEN_MASK
operator|)
operator||
name|CPACR_FPEN_TRAP_NONE
expr_stmt|;
name|WRITE_SPECIALREG
argument_list|(
name|cpacr_el1
argument_list|,
name|cpacr
argument_list|)
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|vfp_disable
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|cpacr
decl_stmt|;
name|cpacr
operator|=
name|READ_SPECIALREG
argument_list|(
name|cpacr_el1
argument_list|)
expr_stmt|;
name|cpacr
operator|=
operator|(
name|cpacr
operator|&
operator|~
name|CPACR_FPEN_MASK
operator|)
operator||
name|CPACR_FPEN_TRAP_ALL1
expr_stmt|;
name|WRITE_SPECIALREG
argument_list|(
name|cpacr_el1
argument_list|,
name|cpacr
argument_list|)
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Called when the thread is dying. If the thread was the last to use the  * VFP unit mark it as unused to tell the kernel the fp state is unowned.  * Ensure the VFP unit is off so we get an exception on the next access.  */
end_comment

begin_function
name|void
name|vfp_discard
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
if|if
condition|(
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
operator|==
name|td
condition|)
name|PCPU_SET
argument_list|(
name|fpcurthread
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|vfp_disable
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|vfp_save_state
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|__int128_t
modifier|*
name|vfp_state
decl_stmt|;
name|uint64_t
name|fpcr
decl_stmt|,
name|fpsr
decl_stmt|;
name|uint32_t
name|cpacr
decl_stmt|;
name|critical_enter
argument_list|()
expr_stmt|;
comment|/* 	 * Only store the registers if the VFP is enabled, 	 * i.e. return if we are trapping on FP access. 	 */
name|cpacr
operator|=
name|READ_SPECIALREG
argument_list|(
name|cpacr_el1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|cpacr
operator|&
name|CPACR_FPEN_MASK
operator|)
operator|==
name|CPACR_FPEN_TRAP_NONE
condition|)
block|{
name|vfp_state
operator|=
name|td
operator|->
name|td_pcb
operator|->
name|pcb_vfp
expr_stmt|;
asm|__asm __volatile(
literal|"mrs	%0, fpcr		\n"
literal|"mrs	%1, fpsr		\n"
literal|"stp	q0,  q1,  [%2, #16 *  0]\n"
literal|"stp	q2,  q3,  [%2, #16 *  2]\n"
literal|"stp	q4,  q5,  [%2, #16 *  4]\n"
literal|"stp	q6,  q7,  [%2, #16 *  6]\n"
literal|"stp	q8,  q9,  [%2, #16 *  8]\n"
literal|"stp	q10, q11, [%2, #16 * 10]\n"
literal|"stp	q12, q13, [%2, #16 * 12]\n"
literal|"stp	q14, q15, [%2, #16 * 14]\n"
literal|"stp	q16, q17, [%2, #16 * 16]\n"
literal|"stp	q18, q19, [%2, #16 * 18]\n"
literal|"stp	q20, q21, [%2, #16 * 20]\n"
literal|"stp	q22, q23, [%2, #16 * 22]\n"
literal|"stp	q24, q25, [%2, #16 * 24]\n"
literal|"stp	q26, q27, [%2, #16 * 26]\n"
literal|"stp	q28, q29, [%2, #16 * 28]\n"
literal|"stp	q30, q31, [%2, #16 * 30]\n"
operator|:
literal|"=&r"
operator|(
name|fpcr
operator|)
operator|,
literal|"=&r"
operator|(
name|fpsr
operator|)
operator|:
literal|"r"
operator|(
name|vfp_state
operator|)
block|)
empty_stmt|;
name|td
operator|->
name|td_pcb
operator|->
name|pcb_fpcr
operator|=
name|fpcr
expr_stmt|;
name|td
operator|->
name|td_pcb
operator|->
name|pcb_fpsr
operator|=
name|fpsr
expr_stmt|;
name|dsb
argument_list|(
name|ish
argument_list|)
expr_stmt|;
name|vfp_disable
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|critical_exit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
unit|}  void
name|vfp_restore_state
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|__int128_t
modifier|*
name|vfp_state
decl_stmt|;
name|uint64_t
name|fpcr
decl_stmt|,
name|fpsr
decl_stmt|;
name|struct
name|pcb
modifier|*
name|curpcb
decl_stmt|;
name|u_int
name|cpu
decl_stmt|;
name|critical_enter
argument_list|()
expr_stmt|;
name|cpu
operator|=
name|PCPU_GET
argument_list|(
name|cpuid
argument_list|)
expr_stmt|;
name|curpcb
operator|=
name|curthread
operator|->
name|td_pcb
expr_stmt|;
name|curpcb
operator|->
name|pcb_fpflags
operator||=
name|PCB_FP_STARTED
expr_stmt|;
name|vfp_enable
argument_list|()
expr_stmt|;
if|if
condition|(
name|PCPU_GET
argument_list|(
name|fpcurthread
argument_list|)
operator|!=
name|curthread
operator|&&
name|cpu
operator|!=
name|curpcb
operator|->
name|pcb_vfpcpu
condition|)
block|{
name|vfp_state
operator|=
name|curthread
operator|->
name|td_pcb
operator|->
name|pcb_vfp
expr_stmt|;
name|fpcr
operator|=
name|curthread
operator|->
name|td_pcb
operator|->
name|pcb_fpcr
expr_stmt|;
name|fpsr
operator|=
name|curthread
operator|->
name|td_pcb
operator|->
name|pcb_fpsr
expr_stmt|;
asm|__asm __volatile(
literal|"ldp	q0,  q1,  [%2, #16 *  0]\n"
literal|"ldp	q2,  q3,  [%2, #16 *  2]\n"
literal|"ldp	q4,  q5,  [%2, #16 *  4]\n"
literal|"ldp	q6,  q7,  [%2, #16 *  6]\n"
literal|"ldp	q8,  q9,  [%2, #16 *  8]\n"
literal|"ldp	q10, q11, [%2, #16 * 10]\n"
literal|"ldp	q12, q13, [%2, #16 * 12]\n"
literal|"ldp	q14, q15, [%2, #16 * 14]\n"
literal|"ldp	q16, q17, [%2, #16 * 16]\n"
literal|"ldp	q18, q19, [%2, #16 * 18]\n"
literal|"ldp	q20, q21, [%2, #16 * 20]\n"
literal|"ldp	q22, q23, [%2, #16 * 22]\n"
literal|"ldp	q24, q25, [%2, #16 * 24]\n"
literal|"ldp	q26, q27, [%2, #16 * 26]\n"
literal|"ldp	q28, q29, [%2, #16 * 28]\n"
literal|"ldp	q30, q31, [%2, #16 * 30]\n"
literal|"msr	fpcr, %0		\n"
literal|"msr	fpsr, %1		\n"
operator|:
operator|:
literal|"r"
operator|(
name|fpcr
operator|)
operator|,
literal|"r"
operator|(
name|fpsr
operator|)
operator|,
literal|"r"
operator|(
name|vfp_state
operator|)
block|)
empty_stmt|;
name|PCPU_SET
argument_list|(
name|fpcurthread
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
name|curpcb
operator|->
name|pcb_vfpcpu
operator|=
name|cpu
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|critical_exit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
unit|}  void
name|vfp_init
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|uint64_t
name|pfr
decl_stmt|;
comment|/* Check if there is a vfp unit present */
name|pfr
operator|=
name|READ_SPECIALREG
argument_list|(
name|id_aa64pfr0_el1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pfr
operator|&
name|ID_AA64PFR0_FP_MASK
operator|)
operator|==
name|ID_AA64PFR0_FP_NONE
condition|)
return|return;
comment|/* Disable to be enabled when it's used */
name|vfp_disable
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|SYSINIT
argument_list|(
name|vfp
argument_list|,
name|SI_SUB_CPU
argument_list|,
name|SI_ORDER_ANY
argument_list|,
name|vfp_init
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

