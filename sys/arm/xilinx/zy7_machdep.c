begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Thomas Skibo  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine dependent code for Xilinx Zynq-7000 Soc.  *  * Reference: Zynq-7000 All Programmable SoC Technical Reference Manual.  * (v1.4) November 16, 2012.  Xilinx doc UG585.  */
end_comment

begin_include
include|#
directive|include
file|"opt_global.h"
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
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/devmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/platform.h>
end_include

begin_include
include|#
directive|include
file|<arm/xilinx/zy7_reg.h>
end_include

begin_function_decl
name|void
function_decl|(
modifier|*
name|zynq7_cpu_reset
function_decl|)
parameter_list|(
name|void
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
name|arm_devmap_lastaddr
argument_list|()
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
block|{ }
end_function

begin_function
name|void
name|platform_late_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  * Set up static device mappings.  Not strictly necessary -- simplebus will  * dynamically establish mappings as needed -- but doing it this way gets us  * nice efficient 1MB section mappings.  */
end_comment

begin_function
name|int
name|platform_devmap_init
parameter_list|(
name|void
parameter_list|)
block|{
name|arm_devmap_add_entry
argument_list|(
name|ZYNQ7_PSIO_HWBASE
argument_list|,
name|ZYNQ7_PSIO_SIZE
argument_list|)
expr_stmt|;
name|arm_devmap_add_entry
argument_list|(
name|ZYNQ7_PSCTL_HWBASE
argument_list|,
name|ZYNQ7_PSCTL_SIZE
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|fdt_fixup_entry
name|fdt_fixup_table
index|[]
init|=
block|{
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|fdt_gic_decode_ic
parameter_list|(
name|phandle_t
name|node
parameter_list|,
name|pcell_t
modifier|*
name|intr
parameter_list|,
name|int
modifier|*
name|interrupt
parameter_list|,
name|int
modifier|*
name|trig
parameter_list|,
name|int
modifier|*
name|pol
parameter_list|)
block|{
if|if
condition|(
operator|!
name|fdt_is_compatible
argument_list|(
name|node
argument_list|,
literal|"arm,gic"
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
operator|*
name|interrupt
operator|=
name|fdt32_to_cpu
argument_list|(
name|intr
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
operator|*
name|trig
operator|=
name|INTR_TRIGGER_CONFORM
expr_stmt|;
operator|*
name|pol
operator|=
name|INTR_POLARITY_CONFORM
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|fdt_pic_decode_t
name|fdt_pic_table
index|[]
init|=
block|{
operator|&
name|fdt_gic_decode_ic
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

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

begin_function
name|void
name|cpu_reset
parameter_list|()
block|{
if|if
condition|(
name|zynq7_cpu_reset
operator|!=
name|NULL
condition|)
call|(
modifier|*
name|zynq7_cpu_reset
call|)
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"cpu_reset: no platform cpu_reset.  hanging.\n"
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
empty_stmt|;
block|}
end_function

end_unit

