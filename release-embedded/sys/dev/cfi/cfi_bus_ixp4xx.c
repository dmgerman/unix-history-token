begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Roelof Jonkman, Carlson Wireless Inc.  * Copyright (c) 2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/cfi/cfi_var.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425var.h>
end_include

begin_function
specifier|static
name|int
name|cfi_ixp4xx_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|cfi_softc
modifier|*
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
comment|/* 	 * NB: we assume the boot loader sets up EXP_TIMING_CS0_OFFSET 	 * according to the flash on the board.  If it does not then it 	 * can be done here. 	 */
if|if
condition|(
name|bootverbose
condition|)
block|{
name|struct
name|ixp425_softc
modifier|*
name|sa
init|=
name|device_get_softc
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|)
decl_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"EXP_TIMING_CS0_OFFSET 0x%x\n"
argument_list|,
name|EXP_BUS_READ_4
argument_list|(
name|sa
argument_list|,
name|EXP_TIMING_CS0_OFFSET
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|sc
operator|->
name|sc_width
operator|=
literal|2
expr_stmt|;
comment|/* NB: don't probe interface width */
return|return
name|cfi_probe
argument_list|(
name|dev
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|cfi_ixp4xx_methods
index|[]
init|=
block|{
comment|/* device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|cfi_ixp4xx_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|cfi_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|cfi_detach
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|cfi_ixp4xx_driver
init|=
block|{
name|cfi_driver_name
block|,
name|cfi_ixp4xx_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|cfi_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|cfi
argument_list|,
name|ixp
argument_list|,
name|cfi_ixp4xx_driver
argument_list|,
name|cfi_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

