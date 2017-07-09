begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Hisilicon Limited.  *  * Author: Bintian Wang<bintian.wang@huawei.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_HI6220_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_HI6220_H
end_define

begin_comment
comment|/* clk in Hi6220 AO (always on) controller */
end_comment

begin_define
define|#
directive|define
name|HI6220_NONE_CLOCK
value|0
end_define

begin_comment
comment|/* fixed rate clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_REF32K
value|1
end_define

begin_define
define|#
directive|define
name|HI6220_CLK_TCXO
value|2
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_PAD
value|3
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_PAD
value|4
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_PAD
value|5
end_define

begin_define
define|#
directive|define
name|HI6220_PLL_BBP
value|6
end_define

begin_define
define|#
directive|define
name|HI6220_PLL_GPU
value|7
end_define

begin_define
define|#
directive|define
name|HI6220_PLL1_DDR
value|8
end_define

begin_define
define|#
directive|define
name|HI6220_PLL_SYS
value|9
end_define

begin_define
define|#
directive|define
name|HI6220_PLL_SYS_MEDIA
value|10
end_define

begin_define
define|#
directive|define
name|HI6220_DDR_SRC
value|11
end_define

begin_define
define|#
directive|define
name|HI6220_PLL_MEDIA
value|12
end_define

begin_define
define|#
directive|define
name|HI6220_PLL_DDR
value|13
end_define

begin_comment
comment|/* fixed factor clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_300M
value|14
end_define

begin_define
define|#
directive|define
name|HI6220_150M
value|15
end_define

begin_define
define|#
directive|define
name|HI6220_PICOPHY_SRC
value|16
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_SRC_SEL
value|17
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_SRC_SEL
value|18
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_SRC_SEL
value|19
end_define

begin_define
define|#
directive|define
name|HI6220_VPU_CODEC
value|20
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_SMP
value|21
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_SMP
value|22
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_SMP
value|23
end_define

begin_comment
comment|/* gate clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_WDT0_PCLK
value|24
end_define

begin_define
define|#
directive|define
name|HI6220_WDT1_PCLK
value|25
end_define

begin_define
define|#
directive|define
name|HI6220_WDT2_PCLK
value|26
end_define

begin_define
define|#
directive|define
name|HI6220_TIMER0_PCLK
value|27
end_define

begin_define
define|#
directive|define
name|HI6220_TIMER1_PCLK
value|28
end_define

begin_define
define|#
directive|define
name|HI6220_TIMER2_PCLK
value|29
end_define

begin_define
define|#
directive|define
name|HI6220_TIMER3_PCLK
value|30
end_define

begin_define
define|#
directive|define
name|HI6220_TIMER4_PCLK
value|31
end_define

begin_define
define|#
directive|define
name|HI6220_TIMER5_PCLK
value|32
end_define

begin_define
define|#
directive|define
name|HI6220_TIMER6_PCLK
value|33
end_define

begin_define
define|#
directive|define
name|HI6220_TIMER7_PCLK
value|34
end_define

begin_define
define|#
directive|define
name|HI6220_TIMER8_PCLK
value|35
end_define

begin_define
define|#
directive|define
name|HI6220_UART0_PCLK
value|36
end_define

begin_define
define|#
directive|define
name|HI6220_RTC0_PCLK
value|37
end_define

begin_define
define|#
directive|define
name|HI6220_RTC1_PCLK
value|38
end_define

begin_define
define|#
directive|define
name|HI6220_AO_NR_CLKS
value|39
end_define

begin_comment
comment|/* clk in Hi6220 systrl */
end_comment

begin_comment
comment|/* gate clock */
end_comment

begin_define
define|#
directive|define
name|HI6220_MMC0_CLK
value|1
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_CIUCLK
value|2
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_CLK
value|3
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_CIUCLK
value|4
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_CLK
value|5
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_CIUCLK
value|6
end_define

begin_define
define|#
directive|define
name|HI6220_USBOTG_HCLK
value|7
end_define

begin_define
define|#
directive|define
name|HI6220_CLK_PICOPHY
value|8
end_define

begin_define
define|#
directive|define
name|HI6220_HIFI
value|9
end_define

begin_define
define|#
directive|define
name|HI6220_DACODEC_PCLK
value|10
end_define

begin_define
define|#
directive|define
name|HI6220_EDMAC_ACLK
value|11
end_define

begin_define
define|#
directive|define
name|HI6220_CS_ATB
value|12
end_define

begin_define
define|#
directive|define
name|HI6220_I2C0_CLK
value|13
end_define

begin_define
define|#
directive|define
name|HI6220_I2C1_CLK
value|14
end_define

begin_define
define|#
directive|define
name|HI6220_I2C2_CLK
value|15
end_define

begin_define
define|#
directive|define
name|HI6220_I2C3_CLK
value|16
end_define

begin_define
define|#
directive|define
name|HI6220_UART1_PCLK
value|17
end_define

begin_define
define|#
directive|define
name|HI6220_UART2_PCLK
value|18
end_define

begin_define
define|#
directive|define
name|HI6220_UART3_PCLK
value|19
end_define

begin_define
define|#
directive|define
name|HI6220_UART4_PCLK
value|20
end_define

begin_define
define|#
directive|define
name|HI6220_SPI_CLK
value|21
end_define

begin_define
define|#
directive|define
name|HI6220_TSENSOR_CLK
value|22
end_define

begin_define
define|#
directive|define
name|HI6220_MMU_CLK
value|23
end_define

begin_define
define|#
directive|define
name|HI6220_HIFI_SEL
value|24
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_SYSPLL
value|25
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_SYSPLL
value|26
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_SYSPLL
value|27
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_SEL
value|28
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_SEL
value|29
end_define

begin_define
define|#
directive|define
name|HI6220_BBPPLL_SEL
value|30
end_define

begin_define
define|#
directive|define
name|HI6220_MEDIA_PLL_SRC
value|31
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_SEL
value|32
end_define

begin_define
define|#
directive|define
name|HI6220_CS_ATB_SYSPLL
value|33
end_define

begin_comment
comment|/* mux clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_MMC0_SRC
value|34
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_SMP_IN
value|35
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_SRC
value|36
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_SMP_IN
value|37
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_SRC
value|38
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_SMP_IN
value|39
end_define

begin_define
define|#
directive|define
name|HI6220_HIFI_SRC
value|40
end_define

begin_define
define|#
directive|define
name|HI6220_UART1_SRC
value|41
end_define

begin_define
define|#
directive|define
name|HI6220_UART2_SRC
value|42
end_define

begin_define
define|#
directive|define
name|HI6220_UART3_SRC
value|43
end_define

begin_define
define|#
directive|define
name|HI6220_UART4_SRC
value|44
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_MUX0
value|45
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_MUX0
value|46
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_MUX0
value|47
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_MUX1
value|48
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_MUX1
value|49
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_MUX1
value|50
end_define

begin_comment
comment|/* divider clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_CLK_BUS
value|51
end_define

begin_define
define|#
directive|define
name|HI6220_MMC0_DIV
value|52
end_define

begin_define
define|#
directive|define
name|HI6220_MMC1_DIV
value|53
end_define

begin_define
define|#
directive|define
name|HI6220_MMC2_DIV
value|54
end_define

begin_define
define|#
directive|define
name|HI6220_HIFI_DIV
value|55
end_define

begin_define
define|#
directive|define
name|HI6220_BBPPLL0_DIV
value|56
end_define

begin_define
define|#
directive|define
name|HI6220_CS_DAPB
value|57
end_define

begin_define
define|#
directive|define
name|HI6220_CS_ATB_DIV
value|58
end_define

begin_comment
comment|/* gate clock */
end_comment

begin_define
define|#
directive|define
name|HI6220_DAPB_CLK
value|59
end_define

begin_define
define|#
directive|define
name|HI6220_SYS_NR_CLKS
value|60
end_define

begin_comment
comment|/* clk in Hi6220 media controller */
end_comment

begin_comment
comment|/* gate clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_DSI_PCLK
value|1
end_define

begin_define
define|#
directive|define
name|HI6220_G3D_PCLK
value|2
end_define

begin_define
define|#
directive|define
name|HI6220_ACLK_CODEC_VPU
value|3
end_define

begin_define
define|#
directive|define
name|HI6220_ISP_SCLK
value|4
end_define

begin_define
define|#
directive|define
name|HI6220_ADE_CORE
value|5
end_define

begin_define
define|#
directive|define
name|HI6220_MED_MMU
value|6
end_define

begin_define
define|#
directive|define
name|HI6220_CFG_CSI4PHY
value|7
end_define

begin_define
define|#
directive|define
name|HI6220_CFG_CSI2PHY
value|8
end_define

begin_define
define|#
directive|define
name|HI6220_ISP_SCLK_GATE
value|9
end_define

begin_define
define|#
directive|define
name|HI6220_ISP_SCLK_GATE1
value|10
end_define

begin_define
define|#
directive|define
name|HI6220_ADE_CORE_GATE
value|11
end_define

begin_define
define|#
directive|define
name|HI6220_CODEC_VPU_GATE
value|12
end_define

begin_define
define|#
directive|define
name|HI6220_MED_SYSPLL
value|13
end_define

begin_comment
comment|/* mux clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_1440_1200
value|14
end_define

begin_define
define|#
directive|define
name|HI6220_1000_1200
value|15
end_define

begin_define
define|#
directive|define
name|HI6220_1000_1440
value|16
end_define

begin_comment
comment|/* divider clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_CODEC_JPEG
value|17
end_define

begin_define
define|#
directive|define
name|HI6220_ISP_SCLK_SRC
value|18
end_define

begin_define
define|#
directive|define
name|HI6220_ISP_SCLK1
value|19
end_define

begin_define
define|#
directive|define
name|HI6220_ADE_CORE_SRC
value|20
end_define

begin_define
define|#
directive|define
name|HI6220_ADE_PIX_SRC
value|21
end_define

begin_define
define|#
directive|define
name|HI6220_G3D_CLK
value|22
end_define

begin_define
define|#
directive|define
name|HI6220_CODEC_VPU_SRC
value|23
end_define

begin_define
define|#
directive|define
name|HI6220_MEDIA_NR_CLKS
value|24
end_define

begin_comment
comment|/* clk in Hi6220 power controller */
end_comment

begin_comment
comment|/* gate clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_PLL_GPU_GATE
value|1
end_define

begin_define
define|#
directive|define
name|HI6220_PLL1_DDR_GATE
value|2
end_define

begin_define
define|#
directive|define
name|HI6220_PLL_DDR_GATE
value|3
end_define

begin_define
define|#
directive|define
name|HI6220_PLL_MEDIA_GATE
value|4
end_define

begin_define
define|#
directive|define
name|HI6220_PLL0_BBP_GATE
value|5
end_define

begin_comment
comment|/* divider clocks */
end_comment

begin_define
define|#
directive|define
name|HI6220_DDRC_SRC
value|6
end_define

begin_define
define|#
directive|define
name|HI6220_DDRC_AXI1
value|7
end_define

begin_define
define|#
directive|define
name|HI6220_POWER_NR_CLKS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

