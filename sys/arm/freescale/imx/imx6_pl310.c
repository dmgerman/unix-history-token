begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Olivier Houchard.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_comment
comment|/*  * The machine-dependent part of the arm/pl310 driver for imx6 SoCs.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
file|<sys/rman.h>
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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/pl310.h>
end_include

begin_include
include|#
directive|include
file|<machine/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<arm/freescale/imx/imx6_machdep.h>
end_include

begin_include
include|#
directive|include
file|"platform_pl310_if.h"
end_include

begin_function
name|void
name|imx6_pl310_init
parameter_list|(
name|platform_t
name|plat
parameter_list|,
name|struct
name|pl310_softc
modifier|*
name|sc
parameter_list|)
block|{
name|uint32_t
name|reg
decl_stmt|;
comment|/* 	 * Enable power saving modes: 	 *  - Dynamic Gating stops the clock when the controller is idle. 	 *  - Standby stops the clock when the cores are in WFI mode. 	 */
name|reg
operator|=
name|pl310_read4
argument_list|(
name|sc
argument_list|,
name|PL310_POWER_CTRL
argument_list|)
expr_stmt|;
name|reg
operator||=
name|POWER_CTRL_ENABLE_GATING
operator||
name|POWER_CTRL_ENABLE_STANDBY
expr_stmt|;
name|pl310_write4
argument_list|(
name|sc
argument_list|,
name|PL310_POWER_CTRL
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|pl310_set_ram_latency
argument_list|(
name|sc
argument_list|,
name|PL310_TAG_RAM_CTRL
argument_list|,
literal|4
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|pl310_set_ram_latency
argument_list|(
name|sc
argument_list|,
name|PL310_DATA_RAM_CTRL
argument_list|,
literal|4
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

