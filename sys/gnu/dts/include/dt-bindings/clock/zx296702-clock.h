begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2014 Linaro Ltd.  * Copyright (C) 2014 ZTE Corporation.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_ZX296702_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_ZX296702_H
end_define

begin_define
define|#
directive|define
name|ZX296702_OSC
value|0
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_A9
value|1
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_A9_350M
value|2
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_MAC_1000M
value|3
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_MAC_333M
value|4
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_MM0_1188M
value|5
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_MM0_396M
value|6
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_MM0_198M
value|7
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_MM1_108M
value|8
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_MM1_72M
value|9
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_MM1_54M
value|10
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_LSP_104M
value|11
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_LSP_26M
value|12
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_AUDIO_294M912
value|13
end_define

begin_define
define|#
directive|define
name|ZX296702_PLL_DDR_266M
value|14
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_148M5
value|15
end_define

begin_define
define|#
directive|define
name|ZX296702_MATRIX_ACLK
value|16
end_define

begin_define
define|#
directive|define
name|ZX296702_MAIN_HCLK
value|17
end_define

begin_define
define|#
directive|define
name|ZX296702_MAIN_PCLK
value|18
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_500
value|19
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_250
value|20
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_125
value|21
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_74M25
value|22
end_define

begin_define
define|#
directive|define
name|ZX296702_A9_WCLK
value|23
end_define

begin_define
define|#
directive|define
name|ZX296702_A9_AS1_ACLK_MUX
value|24
end_define

begin_define
define|#
directive|define
name|ZX296702_A9_TRACE_CLKIN_MUX
value|25
end_define

begin_define
define|#
directive|define
name|ZX296702_A9_AS1_ACLK_DIV
value|26
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_2
value|27
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_27
value|28
end_define

begin_define
define|#
directive|define
name|ZX296702_DECPPU_ACLK_MUX
value|29
end_define

begin_define
define|#
directive|define
name|ZX296702_PPU_ACLK_MUX
value|30
end_define

begin_define
define|#
directive|define
name|ZX296702_MALI400_ACLK_MUX
value|31
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_ACLK_MUX
value|32
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_MAIN_WCLK_MUX
value|33
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_AUX_WCLK_MUX
value|34
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_SCALER_WCLK_MUX
value|35
end_define

begin_define
define|#
directive|define
name|ZX296702_R2D_ACLK_MUX
value|36
end_define

begin_define
define|#
directive|define
name|ZX296702_R2D_WCLK_MUX
value|37
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_50
value|38
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_25
value|39
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_12
value|40
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_16M384
value|41
end_define

begin_define
define|#
directive|define
name|ZX296702_CLK_32K768
value|42
end_define

begin_define
define|#
directive|define
name|ZX296702_SEC_WCLK_DIV
value|43
end_define

begin_define
define|#
directive|define
name|ZX296702_DDR_WCLK_MUX
value|44
end_define

begin_define
define|#
directive|define
name|ZX296702_NAND_WCLK_MUX
value|45
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP_26_WCLK_MUX
value|46
end_define

begin_define
define|#
directive|define
name|ZX296702_A9_AS0_ACLK
value|47
end_define

begin_define
define|#
directive|define
name|ZX296702_A9_AS1_ACLK
value|48
end_define

begin_define
define|#
directive|define
name|ZX296702_A9_TRACE_CLKIN
value|49
end_define

begin_define
define|#
directive|define
name|ZX296702_DECPPU_AXI_M_ACLK
value|50
end_define

begin_define
define|#
directive|define
name|ZX296702_DECPPU_AHB_S_HCLK
value|51
end_define

begin_define
define|#
directive|define
name|ZX296702_PPU_AXI_M_ACLK
value|52
end_define

begin_define
define|#
directive|define
name|ZX296702_PPU_AHB_S_HCLK
value|53
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_AXI_M_ACLK
value|54
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_APB_PCLK
value|55
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_MAIN_CHANNEL_WCLK
value|56
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_AUX_CHANNEL_WCLK
value|57
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_HDMI_OSCLK_CEC
value|58
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_SCALER_WCLK
value|59
end_define

begin_define
define|#
directive|define
name|ZX296702_MALI400_AXI_M_ACLK
value|60
end_define

begin_define
define|#
directive|define
name|ZX296702_MALI400_APB_PCLK
value|61
end_define

begin_define
define|#
directive|define
name|ZX296702_R2D_WCLK
value|62
end_define

begin_define
define|#
directive|define
name|ZX296702_R2D_AXI_M_ACLK
value|63
end_define

begin_define
define|#
directive|define
name|ZX296702_R2D_AHB_HCLK
value|64
end_define

begin_define
define|#
directive|define
name|ZX296702_DDR3_AXI_S0_ACLK
value|65
end_define

begin_define
define|#
directive|define
name|ZX296702_DDR3_APB_PCLK
value|66
end_define

begin_define
define|#
directive|define
name|ZX296702_DDR3_WCLK
value|67
end_define

begin_define
define|#
directive|define
name|ZX296702_USB20_0_AHB_HCLK
value|68
end_define

begin_define
define|#
directive|define
name|ZX296702_USB20_0_EXTREFCLK
value|69
end_define

begin_define
define|#
directive|define
name|ZX296702_USB20_1_AHB_HCLK
value|70
end_define

begin_define
define|#
directive|define
name|ZX296702_USB20_1_EXTREFCLK
value|71
end_define

begin_define
define|#
directive|define
name|ZX296702_USB20_2_AHB_HCLK
value|72
end_define

begin_define
define|#
directive|define
name|ZX296702_USB20_2_EXTREFCLK
value|73
end_define

begin_define
define|#
directive|define
name|ZX296702_GMAC_AXI_M_ACLK
value|74
end_define

begin_define
define|#
directive|define
name|ZX296702_GMAC_APB_PCLK
value|75
end_define

begin_define
define|#
directive|define
name|ZX296702_GMAC_125_CLKIN
value|76
end_define

begin_define
define|#
directive|define
name|ZX296702_GMAC_RMII_CLKIN
value|77
end_define

begin_define
define|#
directive|define
name|ZX296702_GMAC_25M_CLK
value|78
end_define

begin_define
define|#
directive|define
name|ZX296702_NANDFLASH_AHB_HCLK
value|79
end_define

begin_define
define|#
directive|define
name|ZX296702_NANDFLASH_WCLK
value|80
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP0_APB_PCLK
value|81
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP0_AHB_HCLK
value|82
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP0_26M_WCLK
value|83
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP0_104M_WCLK
value|84
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP0_16M384_WCLK
value|85
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP1_APB_PCLK
value|86
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP1_26M_WCLK
value|87
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP1_104M_WCLK
value|88
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP1_32K_CLK
value|89
end_define

begin_define
define|#
directive|define
name|ZX296702_AON_HCLK
value|90
end_define

begin_define
define|#
directive|define
name|ZX296702_SYS_CTRL_PCLK
value|91
end_define

begin_define
define|#
directive|define
name|ZX296702_DMA_PCLK
value|92
end_define

begin_define
define|#
directive|define
name|ZX296702_DMA_ACLK
value|93
end_define

begin_define
define|#
directive|define
name|ZX296702_SEC_HCLK
value|94
end_define

begin_define
define|#
directive|define
name|ZX296702_AES_WCLK
value|95
end_define

begin_define
define|#
directive|define
name|ZX296702_DES_WCLK
value|96
end_define

begin_define
define|#
directive|define
name|ZX296702_IRAM_ACLK
value|97
end_define

begin_define
define|#
directive|define
name|ZX296702_IROM_ACLK
value|98
end_define

begin_define
define|#
directive|define
name|ZX296702_BOOT_CTRL_HCLK
value|99
end_define

begin_define
define|#
directive|define
name|ZX296702_EFUSE_CLK_30
value|100
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_MAIN_CHANNEL_DIV
value|101
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_AUX_CHANNEL_DIV
value|102
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_TV_ENC_HD_DIV
value|103
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_TV_ENC_SD_DIV
value|104
end_define

begin_define
define|#
directive|define
name|ZX296702_VL0_MUX
value|105
end_define

begin_define
define|#
directive|define
name|ZX296702_VL1_MUX
value|106
end_define

begin_define
define|#
directive|define
name|ZX296702_VL2_MUX
value|107
end_define

begin_define
define|#
directive|define
name|ZX296702_GL0_MUX
value|108
end_define

begin_define
define|#
directive|define
name|ZX296702_GL1_MUX
value|109
end_define

begin_define
define|#
directive|define
name|ZX296702_GL2_MUX
value|110
end_define

begin_define
define|#
directive|define
name|ZX296702_WB_MUX
value|111
end_define

begin_define
define|#
directive|define
name|ZX296702_HDMI_MUX
value|112
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_TV_ENC_HD_MUX
value|113
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_TV_ENC_SD_MUX
value|114
end_define

begin_define
define|#
directive|define
name|ZX296702_VL0_CLK
value|115
end_define

begin_define
define|#
directive|define
name|ZX296702_VL1_CLK
value|116
end_define

begin_define
define|#
directive|define
name|ZX296702_VL2_CLK
value|117
end_define

begin_define
define|#
directive|define
name|ZX296702_GL0_CLK
value|118
end_define

begin_define
define|#
directive|define
name|ZX296702_GL1_CLK
value|119
end_define

begin_define
define|#
directive|define
name|ZX296702_GL2_CLK
value|120
end_define

begin_define
define|#
directive|define
name|ZX296702_WB_CLK
value|121
end_define

begin_define
define|#
directive|define
name|ZX296702_CL_CLK
value|122
end_define

begin_define
define|#
directive|define
name|ZX296702_MAIN_MIX_CLK
value|123
end_define

begin_define
define|#
directive|define
name|ZX296702_AUX_MIX_CLK
value|124
end_define

begin_define
define|#
directive|define
name|ZX296702_HDMI_CLK
value|125
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_TV_ENC_HD_DAC_CLK
value|126
end_define

begin_define
define|#
directive|define
name|ZX296702_VOU_TV_ENC_SD_DAC_CLK
value|127
end_define

begin_define
define|#
directive|define
name|ZX296702_A9_PERIPHCLK
value|128
end_define

begin_define
define|#
directive|define
name|ZX296702_TOPCLK_END
value|129
end_define

begin_define
define|#
directive|define
name|ZX296702_SDMMC1_WCLK_MUX
value|0
end_define

begin_define
define|#
directive|define
name|ZX296702_SDMMC1_WCLK_DIV
value|1
end_define

begin_define
define|#
directive|define
name|ZX296702_SDMMC1_WCLK
value|2
end_define

begin_define
define|#
directive|define
name|ZX296702_SDMMC1_PCLK
value|3
end_define

begin_define
define|#
directive|define
name|ZX296702_SPDIF0_WCLK_MUX
value|4
end_define

begin_define
define|#
directive|define
name|ZX296702_SPDIF0_WCLK
value|5
end_define

begin_define
define|#
directive|define
name|ZX296702_SPDIF0_PCLK
value|6
end_define

begin_define
define|#
directive|define
name|ZX296702_SPDIF0_DIV
value|7
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S0_WCLK_MUX
value|8
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S0_WCLK
value|9
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S0_PCLK
value|10
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S0_DIV
value|11
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S1_WCLK_MUX
value|12
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S1_WCLK
value|13
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S1_PCLK
value|14
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S1_DIV
value|15
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S2_WCLK_MUX
value|16
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S2_WCLK
value|17
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S2_PCLK
value|18
end_define

begin_define
define|#
directive|define
name|ZX296702_I2S2_DIV
value|19
end_define

begin_define
define|#
directive|define
name|ZX296702_GPIO_CLK
value|20
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP0CLK_END
value|21
end_define

begin_define
define|#
directive|define
name|ZX296702_UART0_WCLK_MUX
value|0
end_define

begin_define
define|#
directive|define
name|ZX296702_UART0_WCLK
value|1
end_define

begin_define
define|#
directive|define
name|ZX296702_UART0_PCLK
value|2
end_define

begin_define
define|#
directive|define
name|ZX296702_UART1_WCLK_MUX
value|3
end_define

begin_define
define|#
directive|define
name|ZX296702_UART1_WCLK
value|4
end_define

begin_define
define|#
directive|define
name|ZX296702_UART1_PCLK
value|5
end_define

begin_define
define|#
directive|define
name|ZX296702_SDMMC0_WCLK_MUX
value|6
end_define

begin_define
define|#
directive|define
name|ZX296702_SDMMC0_WCLK_DIV
value|7
end_define

begin_define
define|#
directive|define
name|ZX296702_SDMMC0_WCLK
value|8
end_define

begin_define
define|#
directive|define
name|ZX296702_SDMMC0_PCLK
value|9
end_define

begin_define
define|#
directive|define
name|ZX296702_SPDIF1_WCLK_MUX
value|10
end_define

begin_define
define|#
directive|define
name|ZX296702_SPDIF1_WCLK
value|11
end_define

begin_define
define|#
directive|define
name|ZX296702_SPDIF1_PCLK
value|12
end_define

begin_define
define|#
directive|define
name|ZX296702_SPDIF1_DIV
value|13
end_define

begin_define
define|#
directive|define
name|ZX296702_LSP1CLK_END
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_ZX296702_H */
end_comment

end_unit

