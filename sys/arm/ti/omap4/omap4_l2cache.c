begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Olivier Houchard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<arm/ti/ti_smc.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/omap4/omap4_machdep.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/omap4/omap4_smc.h>
end_include

begin_include
include|#
directive|include
file|"platform_pl310_if.h"
end_include

begin_function
name|void
name|omap4_pl310_init
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
name|aux
decl_stmt|,
name|prefetch
decl_stmt|;
name|aux
operator|=
name|pl310_read4
argument_list|(
name|sc
argument_list|,
name|PL310_AUX_CTRL
argument_list|)
expr_stmt|;
name|prefetch
operator|=
name|pl310_read4
argument_list|(
name|sc
argument_list|,
name|PL310_PREFETCH_CTRL
argument_list|)
expr_stmt|;
comment|/* 	 * Disable instruction prefetch 	 */
name|prefetch
operator|&=
operator|~
name|PREFETCH_CTRL_INSTR_PREFETCH
expr_stmt|;
name|aux
operator|&=
operator|~
name|AUX_CTRL_INSTR_PREFETCH
expr_stmt|;
comment|// prefetch&= ~PREFETCH_CTRL_DATA_PREFETCH;
comment|// aux&= ~AUX_CTRL_DATA_PREFETCH;
comment|/* 	 * Make sure data prefetch is on 	 */
name|prefetch
operator||=
name|PREFETCH_CTRL_DATA_PREFETCH
expr_stmt|;
name|aux
operator||=
name|AUX_CTRL_DATA_PREFETCH
expr_stmt|;
comment|/* 	 * TODO: add tunable for prefetch offset 	 * and experiment with performance 	 */
name|ti_smc0
argument_list|(
name|aux
argument_list|,
literal|0
argument_list|,
name|WRITE_AUXCTRL_REG
argument_list|)
expr_stmt|;
name|ti_smc0
argument_list|(
name|prefetch
argument_list|,
literal|0
argument_list|,
name|WRITE_PREFETCH_CTRL_REG
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|omap4_pl310_write_ctrl
parameter_list|(
name|platform_t
name|plat
parameter_list|,
name|struct
name|pl310_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|ti_smc0
argument_list|(
name|val
argument_list|,
literal|0
argument_list|,
name|L2CACHE_WRITE_CTRL_REG
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|omap4_pl310_write_debug
parameter_list|(
name|platform_t
name|plat
parameter_list|,
name|struct
name|pl310_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|ti_smc0
argument_list|(
name|val
argument_list|,
literal|0
argument_list|,
name|L2CACHE_WRITE_DEBUG_REG
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

