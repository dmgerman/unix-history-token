begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Thomas Skibo.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

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
file|<machine/cpu.h>
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

begin_include
include|#
directive|include
file|<machine/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<arm/xilinx/zy7_mp.h>
end_include

begin_include
include|#
directive|include
file|<arm/xilinx/zy7_reg.h>
end_include

begin_define
define|#
directive|define
name|ZYNQ7_CPU1_ENTRY
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|SCU_CONTROL_REG
value|0xf8f00000
end_define

begin_define
define|#
directive|define
name|SCU_CONTROL_ENABLE
value|(1<< 0)
end_define

begin_function
name|void
name|zynq7_mp_setmaxid
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|mp_maxid
operator|=
literal|1
expr_stmt|;
name|mp_ncpus
operator|=
literal|2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|zynq7_mp_start_ap
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|bus_space_handle_t
name|scu_handle
decl_stmt|;
name|bus_space_handle_t
name|ocm_handle
decl_stmt|;
name|uint32_t
name|scu_ctrl
decl_stmt|;
comment|/* Map in SCU control register. */
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|SCU_CONTROL_REG
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
operator|&
name|scu_handle
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"platform_mp_start_ap: Couldn't map SCU config reg\n"
argument_list|)
expr_stmt|;
comment|/* Set SCU enable bit. */
name|scu_ctrl
operator|=
name|bus_space_read_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu_handle
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|scu_ctrl
operator||=
name|SCU_CONTROL_ENABLE
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu_handle
argument_list|,
literal|0
argument_list|,
name|scu_ctrl
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|scu_handle
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|/* Map in magic location to give entry address to CPU1. */
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|ZYNQ7_CPU1_ENTRY
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
operator|&
name|ocm_handle
argument_list|)
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"platform_mp_start_ap: Couldn't map OCM\n"
argument_list|)
expr_stmt|;
comment|/* Write start address for CPU1. */
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|ocm_handle
argument_list|,
literal|0
argument_list|,
name|pmap_kextract
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|mpentry
argument_list|)
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|ocm_handle
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|/* 	 * The SCU is enabled above but I think the second CPU doesn't 	 * turn on filtering until after the wake-up below. I think that's why 	 * things don't work if I don't put these cache ops here.  Also, the 	 * magic location, 0xfffffff0, isn't in the SCU's filtering range so it 	 * needs a write-back too. 	 */
name|dcache_wbinv_poc_all
argument_list|()
expr_stmt|;
comment|/* Wake up CPU1. */
name|dsb
argument_list|()
expr_stmt|;
name|sev
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

