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
file|<arm/ti/omap4/omap4_reg.h>
end_include

begin_function_decl
name|void
function_decl|(
modifier|*
name|ti_cpu_reset
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

begin_function
name|vm_offset_t
name|initarm_lastaddr
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
name|initarm_early_init
parameter_list|(
name|void
parameter_list|)
block|{ }
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

begin_comment
comment|/*  * Construct static devmap entries to map out the most frequently used  * peripherals using 1mb section mappings.  */
end_comment

begin_function
name|int
name|initarm_devmap_init
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|SOC_OMAP4
argument_list|)
name|arm_devmap_add_entry
argument_list|(
literal|0x48000000
argument_list|,
literal|0x01000000
argument_list|)
expr_stmt|;
comment|/*16mb L4_PER devices */
name|arm_devmap_add_entry
argument_list|(
literal|0x4A000000
argument_list|,
literal|0x01000000
argument_list|)
expr_stmt|;
comment|/*16mb L4_CFG devices */
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_TI_AM335X
argument_list|)
name|arm_devmap_add_entry
argument_list|(
literal|0x44C00000
argument_list|,
literal|0x00400000
argument_list|)
expr_stmt|;
comment|/* 4mb L4_WKUP devices*/
name|arm_devmap_add_entry
argument_list|(
literal|0x47400000
argument_list|,
literal|0x00100000
argument_list|)
expr_stmt|;
comment|/* 1mb USB            */
name|arm_devmap_add_entry
argument_list|(
literal|0x47800000
argument_list|,
literal|0x00100000
argument_list|)
expr_stmt|;
comment|/* 1mb mmchs2         */
name|arm_devmap_add_entry
argument_list|(
literal|0x48000000
argument_list|,
literal|0x01000000
argument_list|)
expr_stmt|;
comment|/*16mb L4_PER devices */
name|arm_devmap_add_entry
argument_list|(
literal|0x49000000
argument_list|,
literal|0x00100000
argument_list|)
expr_stmt|;
comment|/* 1mb edma3          */
name|arm_devmap_add_entry
argument_list|(
literal|0x49800000
argument_list|,
literal|0x00300000
argument_list|)
expr_stmt|;
comment|/* 3mb edma3          */
name|arm_devmap_add_entry
argument_list|(
literal|0x4A000000
argument_list|,
literal|0x01000000
argument_list|)
expr_stmt|;
comment|/*16mb L4_FAST devices*/
else|#
directive|else
error|#
directive|error
literal|"Unknown SoC"
endif|#
directive|endif
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

