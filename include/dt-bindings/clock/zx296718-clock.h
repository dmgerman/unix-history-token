begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2015 - 2016 ZTE Corporation.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_ZX296718_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_ZX296718_H
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|ZX296718_PLL_CPU
value|1
end_define

begin_define
define|#
directive|define
name|ZX296718_PLL_MAC
value|2
end_define

begin_define
define|#
directive|define
name|ZX296718_PLL_MM0
value|3
end_define

begin_define
define|#
directive|define
name|ZX296718_PLL_MM1
value|4
end_define

begin_define
define|#
directive|define
name|ZX296718_PLL_VGA
value|5
end_define

begin_define
define|#
directive|define
name|ZX296718_PLL_DDR
value|6
end_define

begin_define
define|#
directive|define
name|ZX296718_PLL_AUDIO
value|7
end_define

begin_define
define|#
directive|define
name|ZX296718_PLL_HSIC
value|8
end_define

begin_define
define|#
directive|define
name|CPU_DBG_GATE
value|9
end_define

begin_define
define|#
directive|define
name|A72_GATE
value|10
end_define

begin_define
define|#
directive|define
name|CPU_PERI_GATE
value|11
end_define

begin_define
define|#
directive|define
name|A53_GATE
value|12
end_define

begin_define
define|#
directive|define
name|DDR1_GATE
value|13
end_define

begin_define
define|#
directive|define
name|DDR0_GATE
value|14
end_define

begin_define
define|#
directive|define
name|SD1_WCLK
value|15
end_define

begin_define
define|#
directive|define
name|SD1_AHB
value|16
end_define

begin_define
define|#
directive|define
name|SD0_WCLK
value|17
end_define

begin_define
define|#
directive|define
name|SD0_AHB
value|18
end_define

begin_define
define|#
directive|define
name|EMMC_WCLK
value|19
end_define

begin_define
define|#
directive|define
name|EMMC_NAND_AXI
value|20
end_define

begin_define
define|#
directive|define
name|NAND_WCLK
value|21
end_define

begin_define
define|#
directive|define
name|EMMC_NAND_AHB
value|22
end_define

begin_define
define|#
directive|define
name|LSP1_148M5
value|23
end_define

begin_define
define|#
directive|define
name|LSP1_99M
value|24
end_define

begin_define
define|#
directive|define
name|LSP1_24M
value|25
end_define

begin_define
define|#
directive|define
name|LSP0_74M25
value|26
end_define

begin_define
define|#
directive|define
name|LSP0_32K
value|27
end_define

begin_define
define|#
directive|define
name|LSP0_148M5
value|28
end_define

begin_define
define|#
directive|define
name|LSP0_99M
value|29
end_define

begin_define
define|#
directive|define
name|LSP0_24M
value|30
end_define

begin_define
define|#
directive|define
name|DEMUX_AXI
value|31
end_define

begin_define
define|#
directive|define
name|DEMUX_APB
value|32
end_define

begin_define
define|#
directive|define
name|DEMUX_148M5
value|33
end_define

begin_define
define|#
directive|define
name|DEMUX_108M
value|34
end_define

begin_define
define|#
directive|define
name|AUDIO_APB
value|35
end_define

begin_define
define|#
directive|define
name|AUDIO_99M
value|36
end_define

begin_define
define|#
directive|define
name|AUDIO_24M
value|37
end_define

begin_define
define|#
directive|define
name|AUDIO_16M384
value|38
end_define

begin_define
define|#
directive|define
name|AUDIO_32K
value|39
end_define

begin_define
define|#
directive|define
name|WDT_WCLK
value|40
end_define

begin_define
define|#
directive|define
name|TIMER_WCLK
value|41
end_define

begin_define
define|#
directive|define
name|VDE_ACLK
value|42
end_define

begin_define
define|#
directive|define
name|VCE_ACLK
value|43
end_define

begin_define
define|#
directive|define
name|HDE_ACLK
value|44
end_define

begin_define
define|#
directive|define
name|GPU_ACLK
value|45
end_define

begin_define
define|#
directive|define
name|SAPPU_ACLK
value|46
end_define

begin_define
define|#
directive|define
name|SAPPU_WCLK
value|47
end_define

begin_define
define|#
directive|define
name|VOU_ACLK
value|48
end_define

begin_define
define|#
directive|define
name|VOU_MAIN_WCLK
value|49
end_define

begin_define
define|#
directive|define
name|VOU_AUX_WCLK
value|50
end_define

begin_define
define|#
directive|define
name|VOU_PPU_WCLK
value|51
end_define

begin_define
define|#
directive|define
name|MIPI_CFG_CLK
value|52
end_define

begin_define
define|#
directive|define
name|VGA_I2C_WCLK
value|53
end_define

begin_define
define|#
directive|define
name|MIPI_REF_CLK
value|54
end_define

begin_define
define|#
directive|define
name|HDMI_OSC_CEC
value|55
end_define

begin_define
define|#
directive|define
name|HDMI_OSC_CLK
value|56
end_define

begin_define
define|#
directive|define
name|HDMI_XCLK
value|57
end_define

begin_define
define|#
directive|define
name|VIU_M0_ACLK
value|58
end_define

begin_define
define|#
directive|define
name|VIU_M1_ACLK
value|59
end_define

begin_define
define|#
directive|define
name|VIU_WCLK
value|60
end_define

begin_define
define|#
directive|define
name|VIU_JPEG_WCLK
value|61
end_define

begin_define
define|#
directive|define
name|VIU_CFG_CLK
value|62
end_define

begin_define
define|#
directive|define
name|TS_SYS_WCLK
value|63
end_define

begin_define
define|#
directive|define
name|TS_SYS_108M
value|64
end_define

begin_define
define|#
directive|define
name|USB20_HCLK
value|65
end_define

begin_define
define|#
directive|define
name|USB20_PHY_CLK
value|66
end_define

begin_define
define|#
directive|define
name|USB21_HCLK
value|67
end_define

begin_define
define|#
directive|define
name|USB21_PHY_CLK
value|68
end_define

begin_define
define|#
directive|define
name|GMAC_RMIICLK
value|69
end_define

begin_define
define|#
directive|define
name|GMAC_PCLK
value|70
end_define

begin_define
define|#
directive|define
name|GMAC_ACLK
value|71
end_define

begin_define
define|#
directive|define
name|GMAC_RFCLK
value|72
end_define

begin_define
define|#
directive|define
name|TEMPSENSOR_GATE
value|73
end_define

begin_define
define|#
directive|define
name|TOP_NR_CLKS
value|74
end_define

begin_define
define|#
directive|define
name|LSP0_TIMER3_PCLK
value|1
end_define

begin_define
define|#
directive|define
name|LSP0_TIMER3_WCLK
value|2
end_define

begin_define
define|#
directive|define
name|LSP0_TIMER4_PCLK
value|3
end_define

begin_define
define|#
directive|define
name|LSP0_TIMER4_WCLK
value|4
end_define

begin_define
define|#
directive|define
name|LSP0_TIMER5_PCLK
value|5
end_define

begin_define
define|#
directive|define
name|LSP0_TIMER5_WCLK
value|6
end_define

begin_define
define|#
directive|define
name|LSP0_UART3_PCLK
value|7
end_define

begin_define
define|#
directive|define
name|LSP0_UART3_WCLK
value|8
end_define

begin_define
define|#
directive|define
name|LSP0_UART1_PCLK
value|9
end_define

begin_define
define|#
directive|define
name|LSP0_UART1_WCLK
value|10
end_define

begin_define
define|#
directive|define
name|LSP0_UART2_PCLK
value|11
end_define

begin_define
define|#
directive|define
name|LSP0_UART2_WCLK
value|12
end_define

begin_define
define|#
directive|define
name|LSP0_SPIFC0_PCLK
value|13
end_define

begin_define
define|#
directive|define
name|LSP0_SPIFC0_WCLK
value|14
end_define

begin_define
define|#
directive|define
name|LSP0_I2C4_PCLK
value|15
end_define

begin_define
define|#
directive|define
name|LSP0_I2C4_WCLK
value|16
end_define

begin_define
define|#
directive|define
name|LSP0_I2C5_PCLK
value|17
end_define

begin_define
define|#
directive|define
name|LSP0_I2C5_WCLK
value|18
end_define

begin_define
define|#
directive|define
name|LSP0_SSP0_PCLK
value|19
end_define

begin_define
define|#
directive|define
name|LSP0_SSP0_WCLK
value|20
end_define

begin_define
define|#
directive|define
name|LSP0_SSP1_PCLK
value|21
end_define

begin_define
define|#
directive|define
name|LSP0_SSP1_WCLK
value|22
end_define

begin_define
define|#
directive|define
name|LSP0_USIM_PCLK
value|23
end_define

begin_define
define|#
directive|define
name|LSP0_USIM_WCLK
value|24
end_define

begin_define
define|#
directive|define
name|LSP0_GPIO_PCLK
value|25
end_define

begin_define
define|#
directive|define
name|LSP0_GPIO_WCLK
value|26
end_define

begin_define
define|#
directive|define
name|LSP0_I2C3_PCLK
value|27
end_define

begin_define
define|#
directive|define
name|LSP0_I2C3_WCLK
value|28
end_define

begin_define
define|#
directive|define
name|LSP0_NR_CLKS
value|29
end_define

begin_define
define|#
directive|define
name|LSP1_UART4_PCLK
value|1
end_define

begin_define
define|#
directive|define
name|LSP1_UART4_WCLK
value|2
end_define

begin_define
define|#
directive|define
name|LSP1_UART5_PCLK
value|3
end_define

begin_define
define|#
directive|define
name|LSP1_UART5_WCLK
value|4
end_define

begin_define
define|#
directive|define
name|LSP1_PWM_PCLK
value|5
end_define

begin_define
define|#
directive|define
name|LSP1_PWM_WCLK
value|6
end_define

begin_define
define|#
directive|define
name|LSP1_I2C2_PCLK
value|7
end_define

begin_define
define|#
directive|define
name|LSP1_I2C2_WCLK
value|8
end_define

begin_define
define|#
directive|define
name|LSP1_SSP2_PCLK
value|9
end_define

begin_define
define|#
directive|define
name|LSP1_SSP2_WCLK
value|10
end_define

begin_define
define|#
directive|define
name|LSP1_SSP3_PCLK
value|11
end_define

begin_define
define|#
directive|define
name|LSP1_SSP3_WCLK
value|12
end_define

begin_define
define|#
directive|define
name|LSP1_SSP4_PCLK
value|13
end_define

begin_define
define|#
directive|define
name|LSP1_SSP4_WCLK
value|14
end_define

begin_define
define|#
directive|define
name|LSP1_USIM1_PCLK
value|15
end_define

begin_define
define|#
directive|define
name|LSP1_USIM1_WCLK
value|16
end_define

begin_define
define|#
directive|define
name|LSP1_NR_CLKS
value|17
end_define

begin_define
define|#
directive|define
name|AUDIO_I2S0_WCLK
value|1
end_define

begin_define
define|#
directive|define
name|AUDIO_I2S0_PCLK
value|2
end_define

begin_define
define|#
directive|define
name|AUDIO_I2S1_WCLK
value|3
end_define

begin_define
define|#
directive|define
name|AUDIO_I2S1_PCLK
value|4
end_define

begin_define
define|#
directive|define
name|AUDIO_I2S2_WCLK
value|5
end_define

begin_define
define|#
directive|define
name|AUDIO_I2S2_PCLK
value|6
end_define

begin_define
define|#
directive|define
name|AUDIO_I2S3_WCLK
value|7
end_define

begin_define
define|#
directive|define
name|AUDIO_I2S3_PCLK
value|8
end_define

begin_define
define|#
directive|define
name|AUDIO_I2C0_WCLK
value|9
end_define

begin_define
define|#
directive|define
name|AUDIO_I2C0_PCLK
value|10
end_define

begin_define
define|#
directive|define
name|AUDIO_SPDIF0_WCLK
value|11
end_define

begin_define
define|#
directive|define
name|AUDIO_SPDIF0_PCLK
value|12
end_define

begin_define
define|#
directive|define
name|AUDIO_SPDIF1_WCLK
value|13
end_define

begin_define
define|#
directive|define
name|AUDIO_SPDIF1_PCLK
value|14
end_define

begin_define
define|#
directive|define
name|AUDIO_TIMER_WCLK
value|15
end_define

begin_define
define|#
directive|define
name|AUDIO_TIMER_PCLK
value|16
end_define

begin_define
define|#
directive|define
name|AUDIO_TDM_WCLK
value|17
end_define

begin_define
define|#
directive|define
name|AUDIO_TDM_PCLK
value|18
end_define

begin_define
define|#
directive|define
name|AUDIO_TS_PCLK
value|19
end_define

begin_define
define|#
directive|define
name|I2S0_WCLK_MUX
value|20
end_define

begin_define
define|#
directive|define
name|I2S1_WCLK_MUX
value|21
end_define

begin_define
define|#
directive|define
name|I2S2_WCLK_MUX
value|22
end_define

begin_define
define|#
directive|define
name|I2S3_WCLK_MUX
value|23
end_define

begin_define
define|#
directive|define
name|AUDIO_NR_CLKS
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

