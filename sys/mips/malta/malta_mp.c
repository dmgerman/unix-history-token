begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/hwfunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_define
define|#
directive|define
name|MALTA_MAXCPU
value|2
end_define

begin_decl_stmt
name|unsigned
name|malta_ap_boot
init|=
operator|~
literal|0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|C_SW0
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|C_SW1
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|C_IRQ0
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|C_IRQ1
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|C_IRQ2
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|C_IRQ3
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|C_IRQ4
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|C_IRQ5
value|(1<< 15)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|ehb
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile(
literal|"	.set mips32r2	\n"
literal|"	ehb		\n"
literal|"	.set mips0	\n"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|mttc0
parameter_list|(
name|rd
parameter_list|,
name|sel
parameter_list|,
name|val
parameter_list|)
define|\
value|({									\ 	__asm __volatile(						\ 	"	.set push					\n"	\ 	"	.set mips32r2					\n"	\ 	"	.set noat					\n"	\ 	"	move	$1, %0					\n"	\ 	"	.word 0x41810000 | (" #rd "<< 11) | " #sel "	\n"	\ 	"	.set pop					\n"	\ 	:: "r" (val));							\ })
end_define

begin_define
define|#
directive|define
name|mftc0
parameter_list|(
name|rt
parameter_list|,
name|sel
parameter_list|)
define|\
value|({									\ 	unsigned long __res;						\ 	__asm __volatile(						\ 	"	.set push					\n"	\ 	"	.set mips32r2					\n"	\ 	"	.set noat					\n"	\ 	"	.word 0x41000800 | (" #rt "<< 16) | " #sel "	\n"	\ 	"	move	%0, $1					\n"	\ 	"	.set pop					\n"	\ 	: "=r" (__res));						\ 	 __res;								\ })
end_define

begin_define
define|#
directive|define
name|write_c0_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|,
name|val
parameter_list|)
define|\
value|({									\ 	__asm __volatile(						\ 	"	.set push					\n"	\ 	"	.set mips32					\n"	\ 	"	mtc0	%0, $%1, %2				\n"	\ 	"	.set pop					\n"	\ 	:: "r" (val), "i" (reg), "i" (sel));				\ })
end_define

begin_define
define|#
directive|define
name|read_c0_register32
parameter_list|(
name|reg
parameter_list|,
name|sel
parameter_list|)
define|\
value|({									\ 	uint32_t __retval;						\ 	__asm __volatile(						\ 	"	.set push					\n"	\ 	"	.set mips32					\n"	\ 	"	mfc0	%0, $%1, %2				\n"	\ 	"	.set pop					\n"	\ 	: "=r" (__retval) : "i" (reg), "i" (sel));			\ 	__retval;							\ })
end_define

begin_macro
unit|void
name|platform_ipi_send
argument_list|(
argument|int cpuid
argument_list|)
end_macro

begin_block
block|{
name|uint32_t
name|reg
decl_stmt|;
comment|/* 	 * Set thread context. 	 * Note this is not global, so we don't need lock. 	 */
name|reg
operator|=
name|read_c0_register32
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
literal|0xff
operator|)
expr_stmt|;
name|reg
operator||=
name|cpuid
expr_stmt|;
name|write_c0_register32
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|ehb
argument_list|()
expr_stmt|;
comment|/* Set cause */
name|reg
operator|=
name|mftc0
argument_list|(
literal|13
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mttc0
argument_list|(
literal|13
argument_list|,
literal|0
argument_list|,
operator|(
name|reg
operator||
name|C_SW1
operator|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|void
name|platform_ipi_clear
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|reg
decl_stmt|;
name|reg
operator|=
name|mips_rd_cause
argument_list|()
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|C_SW1
operator|)
expr_stmt|;
name|mips_wr_cause
argument_list|(
name|reg
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|platform_ipi_hardintr_num
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|int
name|platform_ipi_softintr_num
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|void
name|platform_init_ap
parameter_list|(
name|int
name|cpuid
parameter_list|)
block|{
name|uint32_t
name|clock_int_mask
decl_stmt|;
name|uint32_t
name|ipi_intr_mask
decl_stmt|;
comment|/* 	 * Clear any pending IPIs. 	 */
name|platform_ipi_clear
argument_list|()
expr_stmt|;
comment|/* 	 * Unmask the clock and ipi interrupts. 	 */
name|ipi_intr_mask
operator|=
name|soft_int_mask
argument_list|(
name|platform_ipi_softintr_num
argument_list|()
argument_list|)
expr_stmt|;
name|clock_int_mask
operator|=
name|hard_int_mask
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|set_intr_mask
argument_list|(
name|ipi_intr_mask
operator||
name|clock_int_mask
argument_list|)
expr_stmt|;
name|mips_wbflush
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|platform_cpu_mask
parameter_list|(
name|cpuset_t
modifier|*
name|mask
parameter_list|)
block|{
name|uint32_t
name|i
decl_stmt|,
name|m
decl_stmt|;
name|CPU_ZERO
argument_list|(
name|mask
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|m
operator|=
literal|1
init|;
name|i
operator|<
name|MALTA_MAXCPU
condition|;
name|i
operator|++
operator|,
name|m
operator|<<=
literal|1
control|)
name|CPU_SET
argument_list|(
name|i
argument_list|,
name|mask
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|struct
name|cpu_group
modifier|*
name|platform_smp_topo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|smp_topo_none
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
name|int
name|platform_start_ap
parameter_list|(
name|int
name|cpuid
parameter_list|)
block|{
name|int
name|timeout
decl_stmt|;
if|if
condition|(
name|atomic_cmpset_32
argument_list|(
operator|&
name|malta_ap_boot
argument_list|,
operator|~
literal|0
argument_list|,
name|cpuid
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|printf
argument_list|(
literal|"Waiting for cpu%d to start\n"
argument_list|,
name|cpuid
argument_list|)
expr_stmt|;
name|timeout
operator|=
literal|100
expr_stmt|;
do|do
block|{
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
if|if
condition|(
name|atomic_cmpset_32
argument_list|(
operator|&
name|malta_ap_boot
argument_list|,
literal|0
argument_list|,
operator|~
literal|0
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"CPU %d started\n"
argument_list|,
name|cpuid
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
do|while
condition|(
name|timeout
operator|--
condition|)
do|;
name|printf
argument_list|(
literal|"CPU %d failed to start\n"
argument_list|,
name|cpuid
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

