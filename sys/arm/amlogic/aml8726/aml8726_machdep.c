begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2013-2015 John Wehle<john@feith.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/devmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
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
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<arm/amlogic/aml8726/aml8726_soc.h>
end_include

begin_include
include|#
directive|include
file|<arm/amlogic/aml8726/aml8726_clkmsr.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOCDEV_PA
argument_list|)
operator|&&
name|defined
argument_list|(
name|SOCDEV_VA
argument_list|)
end_if

begin_decl_stmt
name|vm_offset_t
name|aml8726_aobus_kva_base
init|=
name|SOCDEV_VA
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|vm_offset_t
name|aml8726_aobus_kva_base
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|void
name|aml8726_fixup_busfreq
parameter_list|()
block|{
name|phandle_t
name|node
decl_stmt|;
name|pcell_t
name|freq
decl_stmt|,
name|prop
decl_stmt|;
name|ssize_t
name|len
decl_stmt|;
comment|/* 	 * Set the bus-frequency for the SoC simple-bus if it 	 * needs updating (meaning the current frequency is zero). 	 */
if|if
condition|(
operator|(
name|freq
operator|=
name|aml8726_clkmsr_bus_frequency
argument_list|()
operator|)
operator|==
literal|0
operator|||
operator|(
name|node
operator|=
name|OF_finddevice
argument_list|(
literal|"/soc"
argument_list|)
operator|)
operator|==
literal|0
operator|||
name|fdt_is_compatible_strict
argument_list|(
name|node
argument_list|,
literal|"simple-bus"
argument_list|)
operator|==
literal|0
condition|)
while|while
condition|(
literal|1
condition|)
empty_stmt|;
name|freq
operator|=
name|cpu_to_fdt32
argument_list|(
name|freq
argument_list|)
expr_stmt|;
name|len
operator|=
name|OF_getencprop
argument_list|(
name|node
argument_list|,
literal|"bus-frequency"
argument_list|,
operator|&
name|prop
argument_list|,
sizeof|sizeof
argument_list|(
name|prop
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|len
operator|/
sizeof|sizeof
argument_list|(
name|prop
argument_list|)
operator|)
operator|==
literal|1
operator|&&
name|prop
operator|==
literal|0
condition|)
name|OF_setprop
argument_list|(
name|node
argument_list|,
literal|"bus-frequency"
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|&
name|freq
argument_list|,
sizeof|sizeof
argument_list|(
name|freq
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

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
block|{ }
end_function

begin_function
name|void
name|platform_gpio_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * The UART console driver used for debugging early boot code 	 * needs to know the virtual base address of the aobus.  It's 	 * expected to equal SOCDEV_VA prior to initarm calling setttb 	 * ... afterwards it needs to be updated due to the new page 	 * tables. 	 * 	 * This means there's a deadzone in initarm between setttb 	 * and platform_gpio_init during which printf can't be used. 	 */
name|aml8726_aobus_kva_base
operator|=
operator|(
name|vm_offset_t
operator|)
name|arm_devmap_ptov
argument_list|(
literal|0xc8100000
argument_list|,
literal|0x100000
argument_list|)
expr_stmt|;
comment|/* 	 * The hardware mux used by clkmsr is unique to the SoC (though 	 * currently clk81 is at a fixed location, however that might 	 * change in the future). 	 */
name|aml8726_identify_soc
argument_list|()
expr_stmt|;
comment|/* 	 * My aml8726-m3 development box which identifies the CPU as 	 * a Cortex A9-r2 rev 4 randomly locks up during boot when WFI 	 * is used. 	 */
switch|switch
condition|(
name|aml8726_soc_hw_rev
condition|)
block|{
case|case
name|AML_SOC_HW_REV_M3
case|:
name|cpufuncs
operator|.
name|cf_sleep
operator|=
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
expr_stmt|;
break|break;
default|default:
break|break;
block|}
comment|/* 	 * This FDT fixup should arguably be called through fdt_fixup_table, 	 * however currently there's no mechanism to specify a fixup which 	 * should always be invoked. 	 * 	 * It needs to be called prior to the console being initialized which 	 * is why it's called here, rather than from platform_late_init. 	 */
name|aml8726_fixup_busfreq
argument_list|()
expr_stmt|;
block|}
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
comment|/*  * Construct static devmap entries to map out the core  * peripherals using 1mb section mappings.  */
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
literal|0xc1100000
argument_list|,
literal|0x200000
argument_list|)
expr_stmt|;
comment|/* cbus */
name|arm_devmap_add_entry
argument_list|(
literal|0xc4200000
argument_list|,
literal|0x100000
argument_list|)
expr_stmt|;
comment|/* pl310 */
name|arm_devmap_add_entry
argument_list|(
literal|0xc4300000
argument_list|,
literal|0x100000
argument_list|)
expr_stmt|;
comment|/* periph */
name|arm_devmap_add_entry
argument_list|(
literal|0xc8000000
argument_list|,
literal|0x100000
argument_list|)
expr_stmt|;
comment|/* apbbus */
name|arm_devmap_add_entry
argument_list|(
literal|0xc8100000
argument_list|,
literal|0x100000
argument_list|)
expr_stmt|;
comment|/* aobus */
name|arm_devmap_add_entry
argument_list|(
literal|0xc9000000
argument_list|,
literal|0x800000
argument_list|)
expr_stmt|;
comment|/* ahbbus */
name|arm_devmap_add_entry
argument_list|(
literal|0xd9000000
argument_list|,
literal|0x100000
argument_list|)
expr_stmt|;
comment|/* ahb */
name|arm_devmap_add_entry
argument_list|(
literal|0xda000000
argument_list|,
literal|0x100000
argument_list|)
expr_stmt|;
comment|/* secbus */
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

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_INTRNG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_GIC
end_ifndef

begin_function
specifier|static
name|int
name|fdt_pic_decode_ic
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
comment|/* 	 * The single core chips have just an Amlogic PIC. 	 */
if|if
condition|(
operator|!
name|fdt_is_compatible_strict
argument_list|(
name|node
argument_list|,
literal|"amlogic,aml8726-pic"
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
literal|1
index|]
argument_list|)
expr_stmt|;
operator|*
name|trig
operator|=
name|INTR_TRIGGER_EDGE
expr_stmt|;
operator|*
name|pol
operator|=
name|INTR_POLARITY_HIGH
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|fdt_pic_decode_t
name|fdt_pic_table
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|DEV_GIC
operator|&
name|gic_decode_fdt
block|,
else|#
directive|else
operator|&
name|fdt_pic_decode_ic
block|,
endif|#
directive|endif
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_INTRNG */
end_comment

end_unit

