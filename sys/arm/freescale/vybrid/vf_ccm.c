begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family Clock Controller Module (CCM)  * Chapter 10, Vybrid Reference Manual, Rev. 5, 07/2013  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/timeet.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<sys/watchdog.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<arm/freescale/vybrid/vf_common.h>
end_include

begin_define
define|#
directive|define
name|CCM_CCR
value|0x00
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CSR
value|0x04
end_define

begin_comment
comment|/* Status Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CCSR
value|0x08
end_define

begin_comment
comment|/* Clock Switcher Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CACRR
value|0x0C
end_define

begin_comment
comment|/* ARM Clock Root Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCMR1
value|0x10
end_define

begin_comment
comment|/* Serial Clock Multiplexer Register 1 */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCDR1
value|0x14
end_define

begin_comment
comment|/* Serial Clock Divider Register 1 */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCDR2
value|0x18
end_define

begin_comment
comment|/* Serial Clock Divider Register 2 */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCDR3
value|0x1C
end_define

begin_comment
comment|/* Serial Clock Divider Register 3 */
end_comment

begin_define
define|#
directive|define
name|CCM_CSCMR2
value|0x20
end_define

begin_comment
comment|/* Serial Clock Multiplexer Register 2 */
end_comment

begin_define
define|#
directive|define
name|CCM_CTOR
value|0x28
end_define

begin_comment
comment|/* Testing Observability Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CLPCR
value|0x2C
end_define

begin_comment
comment|/* Low Power Control Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CISR
value|0x30
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CIMR
value|0x34
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CCOSR
value|0x38
end_define

begin_comment
comment|/* Clock Output Source Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CGPR
value|0x3C
end_define

begin_comment
comment|/* General Purpose Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CCGRN
value|12
end_define

begin_define
define|#
directive|define
name|CCM_CCGR
parameter_list|(
name|n
parameter_list|)
value|(0x40 + (n * 0x04))
end_define

begin_comment
comment|/* Clock Gating Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CMEOR
parameter_list|(
name|n
parameter_list|)
value|(0x70 + (n * 0x70))
end_define

begin_comment
comment|/* Module Enable Override */
end_comment

begin_define
define|#
directive|define
name|CCM_CCPGR
parameter_list|(
name|n
parameter_list|)
value|(0x90 + (n * 0x04))
end_define

begin_comment
comment|/* Platform Clock Gating */
end_comment

begin_define
define|#
directive|define
name|CCM_CPPDSR
value|0x88
end_define

begin_comment
comment|/* PLL PFD Disable Status Register */
end_comment

begin_define
define|#
directive|define
name|CCM_CCOWR
value|0x8C
end_define

begin_comment
comment|/* CORE Wakeup Register */
end_comment

begin_define
define|#
directive|define
name|PLL3_PFD4_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|PLL3_PFD3_EN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PLL3_PFD2_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|PLL3_PFD1_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PLL2_PFD4_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|PLL2_PFD3_EN
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|PLL2_PFD2_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|PLL2_PFD1_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|PLL1_PFD4_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|PLL1_PFD3_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PLL1_PFD2_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PLL1_PFD1_EN
value|(1<< 8)
end_define

begin_comment
comment|/* CCM_CCR */
end_comment

begin_define
define|#
directive|define
name|FIRC_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|FXOSC_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|FXOSC_RDY
value|(1<< 5)
end_define

begin_comment
comment|/* CCM_CSCDR1 */
end_comment

begin_define
define|#
directive|define
name|ENET_TS_EN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RMII_CLK_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SAI3_EN
value|(1<< 19)
end_define

begin_comment
comment|/* CCM_CSCDR2 */
end_comment

begin_define
define|#
directive|define
name|ESAI_EN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|ESDHC1_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|ESDHC0_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|NFC_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|ESDHC1_DIV_S
value|20
end_define

begin_define
define|#
directive|define
name|ESDHC1_DIV_M
value|0xf
end_define

begin_define
define|#
directive|define
name|ESDHC0_DIV_S
value|16
end_define

begin_define
define|#
directive|define
name|ESDHC0_DIV_M
value|0xf
end_define

begin_comment
comment|/* CCM_CSCDR3 */
end_comment

begin_define
define|#
directive|define
name|DCU0_EN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|QSPI1_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|QSPI1_DIV
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|QSPI1_X2_DIV
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|QSPI1_X4_DIV_M
value|0x3
end_define

begin_define
define|#
directive|define
name|QSPI1_X4_DIV_S
value|8
end_define

begin_define
define|#
directive|define
name|QSPI0_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|QSPI0_DIV
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|QSPI0_X2_DIV
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|QSPI0_X4_DIV_M
value|0x3
end_define

begin_define
define|#
directive|define
name|QSPI0_X4_DIV_S
value|0
end_define

begin_define
define|#
directive|define
name|SAI3_DIV_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SAI3_DIV_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|ESAI_DIV_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|ESAI_DIV_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|PLL4_CLK_DIV_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|PLL4_CLK_DIV_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|IPG_CLK_DIV_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|IPG_CLK_DIV_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|ESAI_CLK_SEL_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ESAI_CLK_SEL_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|SAI3_CLK_SEL_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|SAI3_CLK_SEL_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|CKO1_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|CKO1_DIV_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|CKO1_DIV_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CKO1_SEL_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|CKO1_SEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CKO1_PLL4_MAIN
value|0x6
end_define

begin_define
define|#
directive|define
name|CKO1_PLL4_DIVD
value|0x7
end_define

begin_struct
struct|struct
name|clk
block|{
name|uint32_t
name|reg
decl_stmt|;
name|uint32_t
name|enable_reg
decl_stmt|;
name|uint32_t
name|div_mask
decl_stmt|;
name|uint32_t
name|div_shift
decl_stmt|;
name|uint32_t
name|div_val
decl_stmt|;
name|uint32_t
name|sel_reg
decl_stmt|;
name|uint32_t
name|sel_mask
decl_stmt|;
name|uint32_t
name|sel_shift
decl_stmt|;
name|uint32_t
name|sel_val
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*   PLL4 clock divider (before switching the clocks should be gated)   000 Divide by 1 (only if PLL frequency less than or equal to 650 MHz)   001 Divide by 4   010 Divide by 6   011 Divide by 8   100 Divide by 10   101 Divide by 12   110 Divide by 14   111 Divide by 16 */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|clk
name|pll4_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CACRR
block|,
operator|.
name|enable_reg
operator|=
literal|0
block|,
operator|.
name|div_mask
operator|=
name|PLL4_CLK_DIV_MASK
block|,
operator|.
name|div_shift
operator|=
name|PLL4_CLK_DIV_SHIFT
block|,
operator|.
name|div_val
operator|=
literal|5
block|,
comment|/* Divide by 12 */
operator|.
name|sel_reg
operator|=
literal|0
block|,
operator|.
name|sel_mask
operator|=
literal|0
block|,
operator|.
name|sel_shift
operator|=
literal|0
block|,
operator|.
name|sel_val
operator|=
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk
name|sai3_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CSCDR1
block|,
operator|.
name|enable_reg
operator|=
name|SAI3_EN
block|,
operator|.
name|div_mask
operator|=
name|SAI3_DIV_MASK
block|,
operator|.
name|div_shift
operator|=
name|SAI3_DIV_SHIFT
block|,
operator|.
name|div_val
operator|=
literal|1
block|,
operator|.
name|sel_reg
operator|=
name|CCM_CSCMR1
block|,
operator|.
name|sel_mask
operator|=
name|SAI3_CLK_SEL_MASK
block|,
operator|.
name|sel_shift
operator|=
name|SAI3_CLK_SEL_SHIFT
block|,
operator|.
name|sel_val
operator|=
literal|0x3
block|,
comment|/* Divided PLL4 main clock */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk
name|cko1_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CCOSR
block|,
operator|.
name|enable_reg
operator|=
name|CKO1_EN
block|,
operator|.
name|div_mask
operator|=
name|CKO1_DIV_MASK
block|,
operator|.
name|div_shift
operator|=
name|CKO1_DIV_SHIFT
block|,
operator|.
name|div_val
operator|=
literal|1
block|,
operator|.
name|sel_reg
operator|=
name|CCM_CCOSR
block|,
operator|.
name|sel_mask
operator|=
name|CKO1_SEL_MASK
block|,
operator|.
name|sel_shift
operator|=
name|CKO1_SEL_SHIFT
block|,
operator|.
name|sel_val
operator|=
name|CKO1_PLL4_DIVD
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk
name|esdhc0_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CSCDR2
block|,
operator|.
name|enable_reg
operator|=
name|ESDHC0_EN
block|,
operator|.
name|div_mask
operator|=
name|ESDHC0_DIV_M
block|,
operator|.
name|div_shift
operator|=
name|ESDHC0_DIV_S
block|,
operator|.
name|div_val
operator|=
literal|0x9
block|,
operator|.
name|sel_reg
operator|=
literal|0
block|,
operator|.
name|sel_mask
operator|=
literal|0
block|,
operator|.
name|sel_shift
operator|=
literal|0
block|,
operator|.
name|sel_val
operator|=
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk
name|esdhc1_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CSCDR2
block|,
operator|.
name|enable_reg
operator|=
name|ESDHC1_EN
block|,
operator|.
name|div_mask
operator|=
name|ESDHC1_DIV_M
block|,
operator|.
name|div_shift
operator|=
name|ESDHC1_DIV_S
block|,
operator|.
name|div_val
operator|=
literal|0x9
block|,
operator|.
name|sel_reg
operator|=
literal|0
block|,
operator|.
name|sel_mask
operator|=
literal|0
block|,
operator|.
name|sel_shift
operator|=
literal|0
block|,
operator|.
name|sel_val
operator|=
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk
name|qspi0_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CSCDR3
block|,
operator|.
name|enable_reg
operator|=
name|QSPI0_EN
block|,
operator|.
name|div_mask
operator|=
literal|0
block|,
operator|.
name|div_shift
operator|=
literal|0
block|,
operator|.
name|div_val
operator|=
literal|0
block|,
operator|.
name|sel_reg
operator|=
literal|0
block|,
operator|.
name|sel_mask
operator|=
literal|0
block|,
operator|.
name|sel_shift
operator|=
literal|0
block|,
operator|.
name|sel_val
operator|=
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk
name|dcu0_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CSCDR3
block|,
operator|.
name|enable_reg
operator|=
name|DCU0_EN
block|,
operator|.
name|div_mask
operator|=
literal|0x7
block|,
operator|.
name|div_shift
operator|=
literal|16
block|,
comment|/* DCU0_DIV */
operator|.
name|div_val
operator|=
literal|0
block|,
comment|/* divide by 1 */
operator|.
name|sel_reg
operator|=
literal|0
block|,
operator|.
name|sel_mask
operator|=
literal|0
block|,
operator|.
name|sel_shift
operator|=
literal|0
block|,
operator|.
name|sel_val
operator|=
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk
name|enet_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CSCDR1
block|,
operator|.
name|enable_reg
operator|=
operator|(
name|ENET_TS_EN
operator||
name|RMII_CLK_EN
operator|)
block|,
operator|.
name|div_mask
operator|=
literal|0
block|,
operator|.
name|div_shift
operator|=
literal|0
block|,
operator|.
name|div_val
operator|=
literal|0
block|,
operator|.
name|sel_reg
operator|=
literal|0
block|,
operator|.
name|sel_mask
operator|=
literal|0
block|,
operator|.
name|sel_shift
operator|=
literal|0
block|,
operator|.
name|sel_val
operator|=
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk
name|nand_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CSCDR2
block|,
operator|.
name|enable_reg
operator|=
name|NFC_EN
block|,
operator|.
name|div_mask
operator|=
literal|0
block|,
operator|.
name|div_shift
operator|=
literal|0
block|,
operator|.
name|div_val
operator|=
literal|0
block|,
operator|.
name|sel_reg
operator|=
literal|0
block|,
operator|.
name|sel_mask
operator|=
literal|0
block|,
operator|.
name|sel_shift
operator|=
literal|0
block|,
operator|.
name|sel_val
operator|=
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   Divider to generate ESAI clock   0000    Divide by 1   0001    Divide by 2   ...     ...   1111    Divide by 16 */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|clk
name|esai_clk
init|=
block|{
operator|.
name|reg
operator|=
name|CCM_CSCDR2
block|,
operator|.
name|enable_reg
operator|=
name|ESAI_EN
block|,
operator|.
name|div_mask
operator|=
name|ESAI_DIV_MASK
block|,
operator|.
name|div_shift
operator|=
name|ESAI_DIV_SHIFT
block|,
operator|.
name|div_val
operator|=
literal|3
block|,
comment|/* Divide by 4 */
operator|.
name|sel_reg
operator|=
name|CCM_CSCMR1
block|,
operator|.
name|sel_mask
operator|=
name|ESAI_CLK_SEL_MASK
block|,
operator|.
name|sel_shift
operator|=
name|ESAI_CLK_SEL_SHIFT
block|,
operator|.
name|sel_val
operator|=
literal|0x3
block|,
comment|/* Divided PLL4 main clock */
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|clock_entry
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|clk
modifier|*
name|clk
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|clock_entry
name|clock_map
index|[]
init|=
block|{
block|{
literal|"pll4"
block|,
operator|&
name|pll4_clk
block|}
block|,
block|{
literal|"sai3"
block|,
operator|&
name|sai3_clk
block|}
block|,
block|{
literal|"cko1"
block|,
operator|&
name|cko1_clk
block|}
block|,
block|{
literal|"esdhc0"
block|,
operator|&
name|esdhc0_clk
block|}
block|,
block|{
literal|"esdhc1"
block|,
operator|&
name|esdhc1_clk
block|}
block|,
block|{
literal|"qspi0"
block|,
operator|&
name|qspi0_clk
block|}
block|,
block|{
literal|"dcu0"
block|,
operator|&
name|dcu0_clk
block|}
block|,
block|{
literal|"enet"
block|,
operator|&
name|enet_clk
block|}
block|,
block|{
literal|"nand"
block|,
operator|&
name|nand_clk
block|}
block|,
block|{
literal|"esai"
block|,
operator|&
name|esai_clk
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ccm_softc
block|{
name|struct
name|resource
modifier|*
name|res
index|[
literal|1
index|]
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|ccm_spec
index|[]
init|=
block|{
block|{
name|SYS_RES_MEMORY
block|,
literal|0
block|,
name|RF_ACTIVE
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|ccm_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_status_okay
argument_list|(
name|dev
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"fsl,mvf600-ccm"
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Vybrid Family CCM Unit"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|set_clock
parameter_list|(
name|struct
name|ccm_softc
modifier|*
name|sc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
block|{
name|struct
name|clk
modifier|*
name|clk
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|clock_map
index|[
name|i
index|]
operator|.
name|name
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|clock_map
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|name
argument_list|)
operator|==
literal|0
condition|)
block|{
if|#
directive|if
literal|0
block|device_printf(sc->dev, "Configuring %s clk\n", name);
endif|#
directive|endif
name|clk
operator|=
name|clock_map
index|[
name|i
index|]
operator|.
name|clk
expr_stmt|;
if|if
condition|(
name|clk
operator|->
name|sel_reg
operator|!=
literal|0
condition|)
block|{
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|clk
operator|->
name|sel_reg
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|clk
operator|->
name|sel_mask
operator|<<
name|clk
operator|->
name|sel_shift
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|clk
operator|->
name|sel_val
operator|<<
name|clk
operator|->
name|sel_shift
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|clk
operator|->
name|sel_reg
argument_list|,
name|reg
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|clk
operator|->
name|reg
argument_list|)
expr_stmt|;
name|reg
operator||=
name|clk
operator|->
name|enable_reg
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|clk
operator|->
name|div_mask
operator|<<
name|clk
operator|->
name|div_shift
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|clk
operator|->
name|div_val
operator|<<
name|clk
operator|->
name|div_shift
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|clk
operator|->
name|reg
argument_list|,
name|reg
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
empty_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ccm_fdt_set
parameter_list|(
name|struct
name|ccm_softc
modifier|*
name|sc
parameter_list|)
block|{
name|phandle_t
name|child
decl_stmt|,
name|parent
decl_stmt|,
name|root
decl_stmt|;
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|fdt_config
decl_stmt|,
modifier|*
name|name
decl_stmt|;
name|root
operator|=
name|OF_finddevice
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
name|len
operator|=
literal|0
expr_stmt|;
name|parent
operator|=
name|root
expr_stmt|;
comment|/* Find 'clock_names' prop in the tree */
for|for
control|(
name|child
operator|=
name|OF_child
argument_list|(
name|parent
argument_list|)
init|;
name|child
operator|!=
literal|0
condition|;
name|child
operator|=
name|OF_peer
argument_list|(
name|child
argument_list|)
control|)
block|{
comment|/* Find a 'leaf'. Start the search from this node. */
while|while
condition|(
name|OF_child
argument_list|(
name|child
argument_list|)
condition|)
block|{
name|parent
operator|=
name|child
expr_stmt|;
name|child
operator|=
name|OF_child
argument_list|(
name|child
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|fdt_is_enabled
argument_list|(
name|child
argument_list|)
condition|)
continue|continue;
if|if
condition|(
operator|(
name|len
operator|=
name|OF_getproplen
argument_list|(
name|child
argument_list|,
literal|"clock_names"
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
name|len
operator|=
name|OF_getproplen
argument_list|(
name|child
argument_list|,
literal|"clock_names"
argument_list|)
expr_stmt|;
name|OF_getprop_alloc
argument_list|(
name|child
argument_list|,
literal|"clock_names"
argument_list|,
literal|1
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|fdt_config
argument_list|)
expr_stmt|;
while|while
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|name
operator|=
name|fdt_config
expr_stmt|;
name|fdt_config
operator|+=
name|strlen
argument_list|(
name|name
argument_list|)
operator|+
literal|1
expr_stmt|;
name|len
operator|-=
name|strlen
argument_list|(
name|name
argument_list|)
operator|+
literal|1
expr_stmt|;
name|set_clock
argument_list|(
name|sc
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
empty_stmt|;
if|if
condition|(
name|OF_peer
argument_list|(
name|child
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* No more siblings. */
name|child
operator|=
name|parent
expr_stmt|;
name|parent
operator|=
name|OF_parent
argument_list|(
name|child
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ccm_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|ccm_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|int
name|i
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|dev
operator|=
name|dev
expr_stmt|;
if|if
condition|(
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|ccm_spec
argument_list|,
name|sc
operator|->
name|res
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"could not allocate resources\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Memory interface */
name|sc
operator|->
name|bst
operator|=
name|rman_get_bustag
argument_list|(
name|sc
operator|->
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|sc
operator|->
name|bsh
operator|=
name|rman_get_bushandle
argument_list|(
name|sc
operator|->
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* Enable oscillator */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|CCM_CCR
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|FIRC_EN
operator||
name|FXOSC_EN
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CCM_CCR
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Wait 10 times */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|READ4
argument_list|(
name|sc
argument_list|,
name|CCM_CSR
argument_list|)
operator|&
name|FXOSC_RDY
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
literal|"On board oscillator is ready.\n"
argument_list|)
expr_stmt|;
break|break;
block|}
name|cpufunc_nullop
argument_list|()
expr_stmt|;
block|}
comment|/* Clock is on during all modes, except stop mode. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|CCM_CCGRN
condition|;
name|i
operator|++
control|)
block|{
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|CCM_CCGR
argument_list|(
name|i
argument_list|)
argument_list|,
literal|0xffffffff
argument_list|)
expr_stmt|;
block|}
comment|/* Take and apply FDT clocks */
name|ccm_fdt_set
argument_list|(
name|sc
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
specifier|static
name|device_method_t
name|ccm_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ccm_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|ccm_attach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|ccm_driver
init|=
block|{
literal|"ccm"
block|,
name|ccm_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|ccm_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|ccm_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|ccm
argument_list|,
name|simplebus
argument_list|,
name|ccm_driver
argument_list|,
name|ccm_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

