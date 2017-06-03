begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/devmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
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
file|<machine/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<arm/freescale/imx/imx_machdep.h>
end_include

begin_include
include|#
directive|include
file|"platform_if.h"
end_include

begin_decl_stmt
specifier|static
name|platform_attach_t
name|imx51_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_devmap_init_t
name|imx51_devmap_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_cpu_reset_t
name|imx51_cpu_reset
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|imx51_attach
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
comment|/* XXX - Get rid of this stuff soon. */
name|boothowto
operator||=
name|RB_VERBOSE
operator||
name|RB_MULTIPLE
expr_stmt|;
name|bootverbose
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Set up static device mappings.  This is hand-optimized platform-specific  * config data which covers most of the common on-chip devices with a few 1MB  * section mappings.  *  * Notably missing are entries for GPU, IPU, in general anything video related.  */
end_comment

begin_function
specifier|static
name|int
name|imx51_devmap_init
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|devmap_add_entry
argument_list|(
literal|0x70000000
argument_list|,
literal|0x00100000
argument_list|)
expr_stmt|;
name|devmap_add_entry
argument_list|(
literal|0x73f00000
argument_list|,
literal|0x00100000
argument_list|)
expr_stmt|;
name|devmap_add_entry
argument_list|(
literal|0x83f00000
argument_list|,
literal|0x00100000
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
specifier|static
name|void
name|imx51_cpu_reset
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|imx_wdog_cpu_reset
argument_list|(
literal|0x73F98000
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|u_int
name|imx_soc_type
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|IMXSOC_51
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|platform_method_t
name|imx51_methods
index|[]
init|=
block|{
name|PLATFORMMETHOD
argument_list|(
name|platform_attach
argument_list|,
name|imx51_attach
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_devmap_init
argument_list|,
name|imx51_devmap_init
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_cpu_reset
argument_list|,
name|imx51_cpu_reset
argument_list|)
block|,
name|PLATFORMMETHOD_END
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FDT_PLATFORM_DEF
argument_list|(
name|imx51
argument_list|,
literal|"i.MX51"
argument_list|,
literal|0
argument_list|,
literal|"fsl,imx51"
argument_list|,
literal|100
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

