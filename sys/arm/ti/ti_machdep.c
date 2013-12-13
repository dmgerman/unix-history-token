begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1998 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: FreeBSD: //depot/projects/arm/src/sys/arm/at91/kb920x_machdep.c, rev 45  */
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
file|<machine/machdep.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/omap4/omap4_reg.h>
end_include

begin_comment
comment|/* Start of address space used for bootstrap map */
end_comment

begin_define
define|#
directive|define
name|DEVMAP_BOOTSTRAP_MAP_START
value|0xF0000000
end_define

begin_function_decl
name|void
function_decl|(
modifier|*
name|ti_cpu_reset
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|vm_offset_t
name|initarm_lastaddr
parameter_list|(
name|void
parameter_list|)
block|{
name|ti_cpu_reset
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|DEVMAP_BOOTSTRAP_MAP_START
operator|-
name|ARM_NOCACHE_KVA_SIZE
operator|)
return|;
block|}
end_function

begin_function
name|void
name|initarm_gpio_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|initarm_late_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_define
define|#
directive|define
name|FDT_DEVMAP_MAX
value|(2)
end_define

begin_comment
comment|// FIXME
end_comment

begin_decl_stmt
specifier|static
name|struct
name|pmap_devmap
name|fdt_devmap
index|[
name|FDT_DEVMAP_MAX
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Construct pmap_devmap[] with DT-derived config data.  */
end_comment

begin_function
name|int
name|platform_devmap_init
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SOC_OMAP4
argument_list|)
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_va
operator|=
literal|0xF8000000
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_pa
operator|=
literal|0x48000000
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_size
operator|=
literal|0x1000000
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_prot
operator|=
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_cache
operator|=
name|PTE_DEVICE
expr_stmt|;
name|i
operator|++
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_TI_AM335X
argument_list|)
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_va
operator|=
literal|0xF4C00000
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_pa
operator|=
literal|0x44C00000
expr_stmt|;
comment|/* L4_WKUP */
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_size
operator|=
literal|0x400000
expr_stmt|;
comment|/* 4 MB */
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_prot
operator|=
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
expr_stmt|;
name|fdt_devmap
index|[
name|i
index|]
operator|.
name|pd_cache
operator|=
name|PTE_DEVICE
expr_stmt|;
name|i
operator|++
expr_stmt|;
else|#
directive|else
error|#
directive|error
literal|"Unknown SoC"
endif|#
directive|endif
name|pmap_devmap_bootstrap_table
operator|=
operator|&
name|fdt_devmap
index|[
literal|0
index|]
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

begin_function
name|void
name|cpu_reset
parameter_list|()
block|{
if|if
condition|(
name|ti_cpu_reset
condition|)
call|(
modifier|*
name|ti_cpu_reset
call|)
argument_list|()
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"no cpu_reset implementation\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Reset failed!\n"
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

end_unit

