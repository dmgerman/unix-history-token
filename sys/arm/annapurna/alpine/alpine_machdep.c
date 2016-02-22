begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ruslan Bukin<br@bsdpad.com>  * Copyright (c) 2015 Semihalf  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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

begin_define
define|#
directive|define
name|_ARM32_BUS_DMA_PRIVATE
end_define

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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_comment
comment|/* For trapframe_t, used in<machine/machdep.h> */
end_comment

begin_include
include|#
directive|include
file|<machine/machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/devmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/platform.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

begin_decl_stmt
name|struct
name|mtx
name|al_dbg_lock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEVMAP_MAX_VA_ADDRESS
value|0xF0000000
end_define

begin_decl_stmt
name|bus_addr_t
name|al_devmap_pa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bus_addr_t
name|al_devmap_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AL_NB_SERVICE_OFFSET
value|0x70000
end_define

begin_define
define|#
directive|define
name|AL_NB_CCU_OFFSET
value|0x90000
end_define

begin_define
define|#
directive|define
name|AL_CCU_SNOOP_CONTROL_IOFAB_0_OFFSET
value|0x4000
end_define

begin_define
define|#
directive|define
name|AL_CCU_SNOOP_CONTROL_IOFAB_1_OFFSET
value|0x5000
end_define

begin_define
define|#
directive|define
name|AL_CCU_SPECULATION_CONTROL_OFFSET
value|0x4
end_define

begin_define
define|#
directive|define
name|AL_NB_ACF_MISC_OFFSET
value|0xD0
end_define

begin_define
define|#
directive|define
name|AL_NB_ACF_MISC_READ_BYPASS
value|(1<< 30)
end_define

begin_function_decl
name|int
name|alpine_get_devmap_base
parameter_list|(
name|bus_addr_t
modifier|*
name|pa
parameter_list|,
name|bus_addr_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|vm_offset_t
name|platform_lastaddr
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|DEVMAP_MAX_VA_ADDRESS
operator|)
return|;
block|}
end_function

begin_function
name|void
name|platform_probe_and_attach
parameter_list|(
name|void
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|platform_gpio_init
parameter_list|(
name|void
parameter_list|)
block|{  }
end_function

begin_function
name|void
name|platform_late_init
parameter_list|(
name|void
parameter_list|)
block|{
name|bus_addr_t
name|reg_baddr
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
if|if
condition|(
operator|!
name|mtx_initialized
argument_list|(
operator|&
name|al_dbg_lock
argument_list|)
condition|)
name|mtx_init
argument_list|(
operator|&
name|al_dbg_lock
argument_list|,
literal|"ALDBG"
argument_list|,
literal|"ALDBG"
argument_list|,
name|MTX_SPIN
argument_list|)
expr_stmt|;
comment|/* configure system fabric */
if|if
condition|(
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|al_devmap_pa
argument_list|,
name|al_devmap_size
argument_list|,
literal|0
argument_list|,
operator|&
name|reg_baddr
argument_list|)
condition|)
name|panic
argument_list|(
literal|"Couldn't map Register Space area"
argument_list|)
expr_stmt|;
comment|/* do not allow reads to bypass writes to different addresses */
name|val
operator|=
name|bus_space_read_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|reg_baddr
argument_list|,
name|AL_NB_SERVICE_OFFSET
operator|+
name|AL_NB_ACF_MISC_OFFSET
argument_list|)
expr_stmt|;
name|val
operator|&=
operator|~
name|AL_NB_ACF_MISC_READ_BYPASS
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|reg_baddr
argument_list|,
name|AL_NB_SERVICE_OFFSET
operator|+
name|AL_NB_ACF_MISC_OFFSET
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|/* enable cache snoop */
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|reg_baddr
argument_list|,
name|AL_NB_CCU_OFFSET
operator|+
name|AL_CCU_SNOOP_CONTROL_IOFAB_0_OFFSET
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|reg_baddr
argument_list|,
name|AL_NB_CCU_OFFSET
operator|+
name|AL_CCU_SNOOP_CONTROL_IOFAB_1_OFFSET
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* disable speculative fetches from masters */
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|reg_baddr
argument_list|,
name|AL_NB_CCU_OFFSET
operator|+
name|AL_CCU_SPECULATION_CONTROL_OFFSET
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|reg_baddr
argument_list|,
name|al_devmap_size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Construct devmap table with DT-derived config data.  */
end_comment

begin_function
name|int
name|platform_devmap_init
parameter_list|(
name|void
parameter_list|)
block|{
name|alpine_get_devmap_base
argument_list|(
operator|&
name|al_devmap_pa
argument_list|,
operator|&
name|al_devmap_size
argument_list|)
expr_stmt|;
name|arm_devmap_add_entry
argument_list|(
name|al_devmap_pa
argument_list|,
name|al_devmap_size
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|arm32_dma_range
modifier|*
name|bus_dma_get_range
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
name|int
name|bus_dma_get_range_nb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

