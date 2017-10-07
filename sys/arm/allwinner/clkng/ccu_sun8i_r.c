begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Emmanuel Vadot<manu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<dev/extres/clk/clk_div.h>
end_include

begin_include
include|#
directive|include
file|<dev/extres/clk/clk_fixed.h>
end_include

begin_include
include|#
directive|include
file|<dev/extres/clk/clk_mux.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_ccung.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_clk.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_clk_nm.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_clk_nkmp.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_clk_prediv_mux.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/ccu_sun8i_r.h>
end_include

begin_include
include|#
directive|include
file|<gnu/dts/include/dt-bindings/clock/sun8i-r-ccu.h>
end_include

begin_include
include|#
directive|include
file|<gnu/dts/include/dt-bindings/reset/sun8i-r-ccu.h>
end_include

begin_comment
comment|/* Non-exported clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_AHB0
value|1
end_define

begin_define
define|#
directive|define
name|CLK_APB0
value|2
end_define

begin_decl_stmt
specifier|static
name|struct
name|aw_ccung_reset
name|ccu_sun8i_r_resets
index|[]
init|=
block|{
name|CCU_RESET
argument_list|(
argument|RST_APB0_IR
argument_list|,
literal|0xb0
argument_list|,
literal|1
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB0_TIMER
argument_list|,
literal|0xb0
argument_list|,
literal|2
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB0_RSB
argument_list|,
literal|0xb0
argument_list|,
literal|4
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB0_UART
argument_list|,
literal|0xb0
argument_list|,
literal|6
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|aw_ccung_gate
name|ccu_sun8i_r_gates
index|[]
init|=
block|{
name|CCU_GATE
argument_list|(
argument|CLK_APB0_PIO
argument_list|,
literal|"apb0-pio"
argument_list|,
literal|"apb0"
argument_list|,
literal|0x28
argument_list|,
literal|0
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB0_IR
argument_list|,
literal|"apb0-ir"
argument_list|,
literal|"apb0"
argument_list|,
literal|0x28
argument_list|,
literal|1
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB0_TIMER
argument_list|,
literal|"apb0-timer"
argument_list|,
literal|"apb0"
argument_list|,
literal|0x28
argument_list|,
literal|2
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB0_RSB
argument_list|,
literal|"apb0-rsb"
argument_list|,
literal|"apb0"
argument_list|,
literal|0x28
argument_list|,
literal|3
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB0_UART
argument_list|,
literal|"apb0-uart"
argument_list|,
literal|"apb0"
argument_list|,
literal|0x28
argument_list|,
literal|4
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB0_I2C
argument_list|,
literal|"apb0-i2c"
argument_list|,
literal|"apb0"
argument_list|,
literal|0x28
argument_list|,
literal|6
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB0_TWD
argument_list|,
literal|"apb0-twd"
argument_list|,
literal|"apb0"
argument_list|,
literal|0x28
argument_list|,
literal|7
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|ar100_parents
index|[]
init|=
block|{
literal|"osc32k"
block|,
literal|"osc24M"
block|,
literal|"pll_periph0"
block|,
literal|"iosc"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PREDIV_CLK
argument_list|(
name|ar100_clk
argument_list|,
name|CLK_AR100
argument_list|,
comment|/* id */
literal|"ar100"
argument_list|,
name|ar100_parents
argument_list|,
comment|/* name, parents */
literal|0x00
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|4
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* div */
literal|8
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_HAS_COND
argument_list|,
comment|/* prediv */
literal|16
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* prediv condition */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|ahb0_parents
index|[]
init|=
block|{
literal|"ar100"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|ahb0_clk
argument_list|,
name|CLK_AHB0
argument_list|,
comment|/* id */
literal|"ahb0"
argument_list|,
comment|/* name */
name|ahb0_parents
argument_list|,
comment|/* parent */
literal|0
argument_list|,
comment|/* freq */
literal|1
argument_list|,
comment|/* mult */
literal|1
argument_list|,
comment|/* div */
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|apb0_parents
index|[]
init|=
block|{
literal|"ahb0"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DIV_CLK
argument_list|(
name|apb0_clk
argument_list|,
name|CLK_APB0
argument_list|,
comment|/* id */
literal|"apb0"
argument_list|,
name|apb0_parents
argument_list|,
comment|/* name, parents */
literal|0x0c
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|2
argument_list|,
comment|/* shift, width */
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags, div table */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|aw_clk_prediv_mux_def
modifier|*
name|prediv_mux_clks
index|[]
init|=
block|{
operator|&
name|ar100_clk
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk_div_def
modifier|*
name|div_clks
index|[]
init|=
block|{
operator|&
name|apb0_clk
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk_fixed_def
modifier|*
name|fixed_factor_clks
index|[]
init|=
block|{
operator|&
name|ahb0_clk
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|ccu_sun8i_r_register_clocks
parameter_list|(
name|struct
name|aw_ccung_softc
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|sc
operator|->
name|resets
operator|=
name|ccu_sun8i_r_resets
expr_stmt|;
name|sc
operator|->
name|nresets
operator|=
name|nitems
argument_list|(
name|ccu_sun8i_r_resets
argument_list|)
expr_stmt|;
name|sc
operator|->
name|gates
operator|=
name|ccu_sun8i_r_gates
expr_stmt|;
name|sc
operator|->
name|ngates
operator|=
name|nitems
argument_list|(
name|ccu_sun8i_r_gates
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
argument_list|(
name|prediv_mux_clks
argument_list|)
condition|;
name|i
operator|++
control|)
name|aw_clk_prediv_mux_register
argument_list|(
name|sc
operator|->
name|clkdom
argument_list|,
name|prediv_mux_clks
index|[
name|i
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
argument_list|(
name|div_clks
argument_list|)
condition|;
name|i
operator|++
control|)
name|clknode_div_register
argument_list|(
name|sc
operator|->
name|clkdom
argument_list|,
name|div_clks
index|[
name|i
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
argument_list|(
name|fixed_factor_clks
argument_list|)
condition|;
name|i
operator|++
control|)
name|clknode_fixed_register
argument_list|(
name|sc
operator|->
name|clkdom
argument_list|,
name|fixed_factor_clks
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

