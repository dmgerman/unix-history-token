begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_define
define|#
directive|define
name|SCU_PHYSBASE
value|0xFFFEC000
end_define

begin_define
define|#
directive|define
name|SCU_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|SCU_CONTROL_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|SCU_CONTROL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SCU_CONFIG_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|SCU_CONFIG_REG_NCPU_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|SCU_CPUPOWER_REG
value|0x08
end_define

begin_define
define|#
directive|define
name|SCU_INV_TAGS_REG
value|0x0c
end_define

begin_define
define|#
directive|define
name|SCU_DIAG_CONTROL
value|0x30
end_define

begin_define
define|#
directive|define
name|SCU_DIAG_DISABLE_MIGBIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SCU_FILTER_START_REG
value|0x40
end_define

begin_define
define|#
directive|define
name|SCU_FILTER_END_REG
value|0x44
end_define

begin_define
define|#
directive|define
name|SCU_SECURE_ACCESS_REG
value|0x50
end_define

begin_define
define|#
directive|define
name|SCU_NONSECURE_ACCESS_REG
value|0x54
end_define

begin_define
define|#
directive|define
name|RSTMGR_PHYSBASE
value|0xFFD05000
end_define

begin_define
define|#
directive|define
name|RSTMGR_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|MPUMODRST
value|0x10
end_define

begin_define
define|#
directive|define
name|MPUMODRST_CPU1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RAM_PHYSBASE
value|0x0
end_define

begin_define
define|#
directive|define
name|RAM_SIZE
value|0x1000
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mpentry_addr
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|socfpga_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|socfpga_trampoline
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile(
literal|"ldr pc, 1f\n"
literal|".globl mpentry_addr\n"
literal|"mpentry_addr:\n"
literal|"1: .space 4\n"
block|)
function|;
end_function

begin_macro
unit|}  void
name|platform_mp_init_secondary
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|intr_pic_init_secondary
argument_list|()
expr_stmt|;
block|}
end_block

begin_function
name|void
name|platform_mp_setmaxid
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|hwcpu
decl_stmt|,
name|ncpu
decl_stmt|;
comment|/* If we've already set this don't bother to do it again. */
if|if
condition|(
name|mp_ncpus
operator|!=
literal|0
condition|)
return|return;
name|hwcpu
operator|=
literal|2
expr_stmt|;
name|ncpu
operator|=
name|hwcpu
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"hw.ncpu"
argument_list|,
operator|&
name|ncpu
argument_list|)
expr_stmt|;
if|if
condition|(
name|ncpu
operator|<
literal|1
operator|||
name|ncpu
operator|>
name|hwcpu
condition|)
name|ncpu
operator|=
name|hwcpu
expr_stmt|;
name|mp_ncpus
operator|=
name|ncpu
expr_stmt|;
name|mp_maxid
operator|=
name|ncpu
operator|-
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|int
name|platform_mp_probe
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|mp_ncpus
operator|==
literal|0
condition|)
name|platform_mp_setmaxid
argument_list|()
expr_stmt|;
return|return
operator|(
name|mp_ncpus
operator|>
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|void
name|platform_mp_start_ap
parameter_list|(
name|void
parameter_list|)
block|{
name|bus_space_handle_t
name|scu
decl_stmt|,
name|rst
decl_stmt|,
name|ram
decl_stmt|;
name|int
name|reg
decl_stmt|;
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|SCU_PHYSBASE
argument_list|,
name|SCU_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|scu
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"Couldn't map the SCU\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|RSTMGR_PHYSBASE
argument_list|,
name|RSTMGR_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|rst
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"Couldn't map the reset manager (RSTMGR)\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|RAM_PHYSBASE
argument_list|,
name|RAM_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|ram
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"Couldn't map the first physram page\n"
argument_list|)
expr_stmt|;
comment|/* Invalidate SCU cache tags */
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu
argument_list|,
name|SCU_INV_TAGS_REG
argument_list|,
literal|0x0000ffff
argument_list|)
expr_stmt|;
comment|/* 	 * Erratum ARM/MP: 764369 (problems with cache maintenance). 	 * Setting the "disable-migratory bit" in the undocumented SCU 	 * Diagnostic Control Register helps work around the problem. 	 */
name|reg
operator|=
name|bus_space_read_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu
argument_list|,
name|SCU_DIAG_CONTROL
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|SCU_DIAG_DISABLE_MIGBIT
operator|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu
argument_list|,
name|SCU_DIAG_CONTROL
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Put CPU1 to reset state */
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|rst
argument_list|,
name|MPUMODRST
argument_list|,
name|MPUMODRST_CPU1
argument_list|)
expr_stmt|;
comment|/* Enable the SCU, then clean the cache on this core */
name|reg
operator|=
name|bus_space_read_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu
argument_list|,
name|SCU_CONTROL_REG
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|SCU_CONTROL_ENABLE
operator|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu
argument_list|,
name|SCU_CONTROL_REG
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Set up trampoline code */
name|mpentry_addr
operator|=
operator|(
name|char
operator|*
operator|)
name|pmap_kextract
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|mpentry
argument_list|)
expr_stmt|;
name|bus_space_write_region_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|ram
argument_list|,
literal|0
argument_list|,
operator|(
name|uint32_t
operator|*
operator|)
operator|&
name|socfpga_trampoline
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
name|cpu_l2cache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* Put CPU1 out from reset */
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|rst
argument_list|,
name|MPUMODRST
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|armv7_sev
argument_list|()
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu
argument_list|,
name|SCU_SIZE
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|rst
argument_list|,
name|RSTMGR_SIZE
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|ram
argument_list|,
name|RAM_SIZE
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|platform_ipi_send
parameter_list|(
name|cpuset_t
name|cpus
parameter_list|,
name|u_int
name|ipi
parameter_list|)
block|{
name|pic_ipi_send
argument_list|(
name|cpus
argument_list|,
name|ipi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

