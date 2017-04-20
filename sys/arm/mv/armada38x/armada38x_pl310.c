begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Stormshield.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
comment|/*  * The machine-dependent part of the arm/pl310 driver for Armada 38x SoCs.  */
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

begin_function
name|void
name|platform_pl310_init
parameter_list|(
name|struct
name|pl310_softc
modifier|*
name|sc
parameter_list|)
block|{
name|uint32_t
name|reg
decl_stmt|;
comment|/* 	 * Enable power saving modes: 	 *  - Dynamic Gating stops the clock when the controller is idle. 	 */
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
name|pl310_write4
argument_list|(
name|sc
argument_list|,
name|PL310_PREFETCH_CTRL
argument_list|,
name|PREFETCH_CTRL_DL
operator||
name|PREFETCH_CTRL_DATA_PREFETCH
operator||
name|PREFETCH_CTRL_INCR_DL
operator||
name|PREFETCH_CTRL_DL_ON_WRAP
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|platform_pl310_write_ctrl
parameter_list|(
name|struct
name|pl310_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|pl310_write4
argument_list|(
name|sc
argument_list|,
name|PL310_CTRL
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|platform_pl310_write_debug
parameter_list|(
name|struct
name|pl310_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|pl310_write4
argument_list|(
name|sc
argument_list|,
name|PL310_DEBUG_CTRL
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

