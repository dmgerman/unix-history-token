begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014-2015 Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_IMX7D_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_IMX7D_H
end_define

begin_define
define|#
directive|define
name|IMX7D_OSC_24M_CLK
value|0
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ARM_MAIN
value|1
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ARM_MAIN_CLK
value|2
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ARM_MAIN_SRC
value|3
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ARM_MAIN_BYPASS
value|4
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN
value|5
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN_CLK
value|6
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN_SRC
value|7
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN_BYPASS
value|8
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN_480M
value|9
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN_240M
value|10
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN_120M
value|11
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN_480M_CLK
value|12
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN_240M_CLK
value|13
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_MAIN_120M_CLK
value|14
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD0_392M_CLK
value|15
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD0_196M
value|16
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD0_196M_CLK
value|17
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD1_332M_CLK
value|18
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD1_166M
value|19
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD1_166M_CLK
value|20
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD2_270M_CLK
value|21
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD2_135M
value|22
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD2_135M_CLK
value|23
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD3_CLK
value|24
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD4_CLK
value|25
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD5_CLK
value|26
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD6_CLK
value|27
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_SYS_PFD7_CLK
value|28
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN
value|29
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_CLK
value|30
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_SRC
value|31
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_BYPASS
value|32
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_500M
value|33
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_250M
value|34
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_125M
value|35
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_100M
value|36
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_50M
value|37
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_40M
value|38
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_25M
value|39
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_500M_CLK
value|40
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_250M_CLK
value|41
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_125M_CLK
value|42
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_100M_CLK
value|43
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_50M_CLK
value|44
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_40M_CLK
value|45
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_ENET_MAIN_25M_CLK
value|46
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_DRAM_MAIN
value|47
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_DRAM_MAIN_CLK
value|48
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_DRAM_MAIN_SRC
value|49
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_DRAM_MAIN_BYPASS
value|50
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_DRAM_MAIN_533M
value|51
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_DRAM_MAIN_533M_CLK
value|52
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_AUDIO_MAIN
value|53
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_AUDIO_MAIN_CLK
value|54
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_AUDIO_MAIN_SRC
value|55
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_AUDIO_MAIN_BYPASS
value|56
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_VIDEO_MAIN_CLK
value|57
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_VIDEO_MAIN
value|58
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_VIDEO_MAIN_SRC
value|59
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_VIDEO_MAIN_BYPASS
value|60
end_define

begin_define
define|#
directive|define
name|IMX7D_USB_MAIN_480M_CLK
value|61
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_A7_ROOT_CLK
value|62
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_A7_ROOT_SRC
value|63
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_A7_ROOT_CG
value|64
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_A7_ROOT_DIV
value|65
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_M4_ROOT_CLK
value|66
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_M4_ROOT_SRC
value|67
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_M4_ROOT_CG
value|68
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_M4_ROOT_DIV
value|69
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_M0_ROOT_CLK
value|70
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_M0_ROOT_SRC
value|71
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_M0_ROOT_CG
value|72
end_define

begin_define
define|#
directive|define
name|IMX7D_ARM_M0_ROOT_DIV
value|73
end_define

begin_define
define|#
directive|define
name|IMX7D_MAIN_AXI_ROOT_CLK
value|74
end_define

begin_define
define|#
directive|define
name|IMX7D_MAIN_AXI_ROOT_SRC
value|75
end_define

begin_define
define|#
directive|define
name|IMX7D_MAIN_AXI_ROOT_CG
value|76
end_define

begin_define
define|#
directive|define
name|IMX7D_MAIN_AXI_ROOT_DIV
value|77
end_define

begin_define
define|#
directive|define
name|IMX7D_DISP_AXI_ROOT_CLK
value|78
end_define

begin_define
define|#
directive|define
name|IMX7D_DISP_AXI_ROOT_SRC
value|79
end_define

begin_define
define|#
directive|define
name|IMX7D_DISP_AXI_ROOT_CG
value|80
end_define

begin_define
define|#
directive|define
name|IMX7D_DISP_AXI_ROOT_DIV
value|81
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_AXI_ROOT_CLK
value|82
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_AXI_ROOT_SRC
value|83
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_AXI_ROOT_CG
value|84
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_AXI_ROOT_DIV
value|85
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_USDHC_BUS_ROOT_CLK
value|86
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_USDHC_BUS_ROOT_SRC
value|87
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_USDHC_BUS_ROOT_CG
value|88
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_USDHC_BUS_ROOT_DIV
value|89
end_define

begin_define
define|#
directive|define
name|IMX7D_AHB_CHANNEL_ROOT_CLK
value|90
end_define

begin_define
define|#
directive|define
name|IMX7D_AHB_CHANNEL_ROOT_SRC
value|91
end_define

begin_define
define|#
directive|define
name|IMX7D_AHB_CHANNEL_ROOT_CG
value|92
end_define

begin_define
define|#
directive|define
name|IMX7D_AHB_CHANNEL_ROOT_DIV
value|93
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_PHYM_ROOT_CLK
value|94
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_PHYM_ROOT_SRC
value|95
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_PHYM_ROOT_CG
value|96
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_PHYM_ROOT_DIV
value|97
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_ROOT_CLK
value|98
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_ROOT_SRC
value|99
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_ROOT_CG
value|100
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_ROOT_DIV
value|101
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_PHYM_ALT_ROOT_CLK
value|102
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_PHYM_ALT_ROOT_SRC
value|103
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_PHYM_ALT_ROOT_CG
value|104
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_PHYM_ALT_ROOT_DIV
value|105
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_ALT_ROOT_CLK
value|106
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_ALT_ROOT_SRC
value|107
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_ALT_ROOT_CG
value|108
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_ALT_ROOT_DIV
value|109
end_define

begin_define
define|#
directive|define
name|IMX7D_USB_HSIC_ROOT_CLK
value|110
end_define

begin_define
define|#
directive|define
name|IMX7D_USB_HSIC_ROOT_SRC
value|111
end_define

begin_define
define|#
directive|define
name|IMX7D_USB_HSIC_ROOT_CG
value|112
end_define

begin_define
define|#
directive|define
name|IMX7D_USB_HSIC_ROOT_DIV
value|113
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_CTRL_ROOT_CLK
value|114
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_CTRL_ROOT_SRC
value|115
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_CTRL_ROOT_CG
value|116
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_CTRL_ROOT_DIV
value|117
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_PHY_ROOT_CLK
value|118
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_PHY_ROOT_SRC
value|119
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_PHY_ROOT_CG
value|120
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_PHY_ROOT_DIV
value|121
end_define

begin_define
define|#
directive|define
name|IMX7D_EPDC_PIXEL_ROOT_CLK
value|122
end_define

begin_define
define|#
directive|define
name|IMX7D_EPDC_PIXEL_ROOT_SRC
value|123
end_define

begin_define
define|#
directive|define
name|IMX7D_EPDC_PIXEL_ROOT_CG
value|124
end_define

begin_define
define|#
directive|define
name|IMX7D_EPDC_PIXEL_ROOT_DIV
value|125
end_define

begin_define
define|#
directive|define
name|IMX7D_LCDIF_PIXEL_ROOT_CLK
value|126
end_define

begin_define
define|#
directive|define
name|IMX7D_LCDIF_PIXEL_ROOT_SRC
value|127
end_define

begin_define
define|#
directive|define
name|IMX7D_LCDIF_PIXEL_ROOT_CG
value|128
end_define

begin_define
define|#
directive|define
name|IMX7D_LCDIF_PIXEL_ROOT_DIV
value|129
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DSI_ROOT_CLK
value|130
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DSI_ROOT_SRC
value|131
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DSI_ROOT_CG
value|132
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DSI_ROOT_DIV
value|133
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_CSI_ROOT_CLK
value|134
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_CSI_ROOT_SRC
value|135
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_CSI_ROOT_CG
value|136
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_CSI_ROOT_DIV
value|137
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DPHY_ROOT_CLK
value|138
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DPHY_ROOT_SRC
value|139
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DPHY_ROOT_CG
value|140
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DPHY_ROOT_DIV
value|141
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI1_ROOT_CLK
value|142
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI1_ROOT_SRC
value|143
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI1_ROOT_CG
value|144
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI1_ROOT_DIV
value|145
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI2_ROOT_CLK
value|146
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI2_ROOT_SRC
value|147
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI2_ROOT_CG
value|148
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI2_ROOT_DIV
value|149
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI3_ROOT_CLK
value|150
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI3_ROOT_SRC
value|151
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI3_ROOT_CG
value|152
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI3_ROOT_DIV
value|153
end_define

begin_define
define|#
directive|define
name|IMX7D_SPDIF_ROOT_CLK
value|154
end_define

begin_define
define|#
directive|define
name|IMX7D_SPDIF_ROOT_SRC
value|155
end_define

begin_define
define|#
directive|define
name|IMX7D_SPDIF_ROOT_CG
value|156
end_define

begin_define
define|#
directive|define
name|IMX7D_SPDIF_ROOT_DIV
value|157
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_REF_ROOT_CLK
value|158
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_REF_ROOT_SRC
value|159
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_REF_ROOT_CG
value|160
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_REF_ROOT_DIV
value|161
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_TIME_ROOT_CLK
value|162
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_TIME_ROOT_SRC
value|163
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_TIME_ROOT_CG
value|164
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_TIME_ROOT_DIV
value|165
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_REF_ROOT_CLK
value|166
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_REF_ROOT_SRC
value|167
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_REF_ROOT_CG
value|168
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_REF_ROOT_DIV
value|169
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_TIME_ROOT_CLK
value|170
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_TIME_ROOT_SRC
value|171
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_TIME_ROOT_CG
value|172
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_TIME_ROOT_DIV
value|173
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_PHY_REF_ROOT_CLK
value|174
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_PHY_REF_ROOT_SRC
value|175
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_PHY_REF_ROOT_CG
value|176
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_PHY_REF_ROOT_DIV
value|177
end_define

begin_define
define|#
directive|define
name|IMX7D_EIM_ROOT_CLK
value|178
end_define

begin_define
define|#
directive|define
name|IMX7D_EIM_ROOT_SRC
value|179
end_define

begin_define
define|#
directive|define
name|IMX7D_EIM_ROOT_CG
value|180
end_define

begin_define
define|#
directive|define
name|IMX7D_EIM_ROOT_DIV
value|181
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_ROOT_CLK
value|182
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_ROOT_SRC
value|183
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_ROOT_CG
value|184
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_ROOT_DIV
value|185
end_define

begin_define
define|#
directive|define
name|IMX7D_QSPI_ROOT_CLK
value|186
end_define

begin_define
define|#
directive|define
name|IMX7D_QSPI_ROOT_SRC
value|187
end_define

begin_define
define|#
directive|define
name|IMX7D_QSPI_ROOT_CG
value|188
end_define

begin_define
define|#
directive|define
name|IMX7D_QSPI_ROOT_DIV
value|189
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC1_ROOT_CLK
value|190
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC1_ROOT_SRC
value|191
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC1_ROOT_CG
value|192
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC1_ROOT_DIV
value|193
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC2_ROOT_CLK
value|194
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC2_ROOT_SRC
value|195
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC2_ROOT_CG
value|196
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC2_ROOT_DIV
value|197
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC3_ROOT_CLK
value|198
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC3_ROOT_SRC
value|199
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC3_ROOT_CG
value|200
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC3_ROOT_DIV
value|201
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN1_ROOT_CLK
value|202
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN1_ROOT_SRC
value|203
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN1_ROOT_CG
value|204
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN1_ROOT_DIV
value|205
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN2_ROOT_CLK
value|206
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN2_ROOT_SRC
value|207
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN2_ROOT_CG
value|208
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN2_ROOT_DIV
value|209
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C1_ROOT_CLK
value|210
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C1_ROOT_SRC
value|211
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C1_ROOT_CG
value|212
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C1_ROOT_DIV
value|213
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C2_ROOT_CLK
value|214
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C2_ROOT_SRC
value|215
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C2_ROOT_CG
value|216
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C2_ROOT_DIV
value|217
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C3_ROOT_CLK
value|218
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C3_ROOT_SRC
value|219
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C3_ROOT_CG
value|220
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C3_ROOT_DIV
value|221
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C4_ROOT_CLK
value|222
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C4_ROOT_SRC
value|223
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C4_ROOT_CG
value|224
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C4_ROOT_DIV
value|225
end_define

begin_define
define|#
directive|define
name|IMX7D_UART1_ROOT_CLK
value|226
end_define

begin_define
define|#
directive|define
name|IMX7D_UART1_ROOT_SRC
value|227
end_define

begin_define
define|#
directive|define
name|IMX7D_UART1_ROOT_CG
value|228
end_define

begin_define
define|#
directive|define
name|IMX7D_UART1_ROOT_DIV
value|229
end_define

begin_define
define|#
directive|define
name|IMX7D_UART2_ROOT_CLK
value|230
end_define

begin_define
define|#
directive|define
name|IMX7D_UART2_ROOT_SRC
value|231
end_define

begin_define
define|#
directive|define
name|IMX7D_UART2_ROOT_CG
value|232
end_define

begin_define
define|#
directive|define
name|IMX7D_UART2_ROOT_DIV
value|233
end_define

begin_define
define|#
directive|define
name|IMX7D_UART3_ROOT_CLK
value|234
end_define

begin_define
define|#
directive|define
name|IMX7D_UART3_ROOT_SRC
value|235
end_define

begin_define
define|#
directive|define
name|IMX7D_UART3_ROOT_CG
value|236
end_define

begin_define
define|#
directive|define
name|IMX7D_UART3_ROOT_DIV
value|237
end_define

begin_define
define|#
directive|define
name|IMX7D_UART4_ROOT_CLK
value|238
end_define

begin_define
define|#
directive|define
name|IMX7D_UART4_ROOT_SRC
value|239
end_define

begin_define
define|#
directive|define
name|IMX7D_UART4_ROOT_CG
value|240
end_define

begin_define
define|#
directive|define
name|IMX7D_UART4_ROOT_DIV
value|241
end_define

begin_define
define|#
directive|define
name|IMX7D_UART5_ROOT_CLK
value|242
end_define

begin_define
define|#
directive|define
name|IMX7D_UART5_ROOT_SRC
value|243
end_define

begin_define
define|#
directive|define
name|IMX7D_UART5_ROOT_CG
value|244
end_define

begin_define
define|#
directive|define
name|IMX7D_UART5_ROOT_DIV
value|245
end_define

begin_define
define|#
directive|define
name|IMX7D_UART6_ROOT_CLK
value|246
end_define

begin_define
define|#
directive|define
name|IMX7D_UART6_ROOT_SRC
value|247
end_define

begin_define
define|#
directive|define
name|IMX7D_UART6_ROOT_CG
value|248
end_define

begin_define
define|#
directive|define
name|IMX7D_UART6_ROOT_DIV
value|249
end_define

begin_define
define|#
directive|define
name|IMX7D_UART7_ROOT_CLK
value|250
end_define

begin_define
define|#
directive|define
name|IMX7D_UART7_ROOT_SRC
value|251
end_define

begin_define
define|#
directive|define
name|IMX7D_UART7_ROOT_CG
value|252
end_define

begin_define
define|#
directive|define
name|IMX7D_UART7_ROOT_DIV
value|253
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI1_ROOT_CLK
value|254
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI1_ROOT_SRC
value|255
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI1_ROOT_CG
value|256
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI1_ROOT_DIV
value|257
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI2_ROOT_CLK
value|258
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI2_ROOT_SRC
value|259
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI2_ROOT_CG
value|260
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI2_ROOT_DIV
value|261
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI3_ROOT_CLK
value|262
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI3_ROOT_SRC
value|263
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI3_ROOT_CG
value|264
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI3_ROOT_DIV
value|265
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI4_ROOT_CLK
value|266
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI4_ROOT_SRC
value|267
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI4_ROOT_CG
value|268
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI4_ROOT_DIV
value|269
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM1_ROOT_CLK
value|270
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM1_ROOT_SRC
value|271
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM1_ROOT_CG
value|272
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM1_ROOT_DIV
value|273
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM2_ROOT_CLK
value|274
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM2_ROOT_SRC
value|275
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM2_ROOT_CG
value|276
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM2_ROOT_DIV
value|277
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM3_ROOT_CLK
value|278
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM3_ROOT_SRC
value|279
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM3_ROOT_CG
value|280
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM3_ROOT_DIV
value|281
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM4_ROOT_CLK
value|282
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM4_ROOT_SRC
value|283
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM4_ROOT_CG
value|284
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM4_ROOT_DIV
value|285
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER1_ROOT_CLK
value|286
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER1_ROOT_SRC
value|287
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER1_ROOT_CG
value|288
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER1_ROOT_DIV
value|289
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER2_ROOT_CLK
value|290
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER2_ROOT_SRC
value|291
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER2_ROOT_CG
value|292
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER2_ROOT_DIV
value|293
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM1_ROOT_CLK
value|294
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM1_ROOT_SRC
value|295
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM1_ROOT_CG
value|296
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM1_ROOT_DIV
value|297
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM2_ROOT_CLK
value|298
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM2_ROOT_SRC
value|299
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM2_ROOT_CG
value|300
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM2_ROOT_DIV
value|301
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT1_ROOT_CLK
value|302
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT1_ROOT_SRC
value|303
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT1_ROOT_CG
value|304
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT1_ROOT_DIV
value|305
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT2_ROOT_CLK
value|306
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT2_ROOT_SRC
value|307
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT2_ROOT_CG
value|308
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT2_ROOT_DIV
value|309
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT3_ROOT_CLK
value|310
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT3_ROOT_SRC
value|311
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT3_ROOT_CG
value|312
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT3_ROOT_DIV
value|313
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT4_ROOT_CLK
value|314
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT4_ROOT_SRC
value|315
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT4_ROOT_CG
value|316
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT4_ROOT_DIV
value|317
end_define

begin_define
define|#
directive|define
name|IMX7D_TRACE_ROOT_CLK
value|318
end_define

begin_define
define|#
directive|define
name|IMX7D_TRACE_ROOT_SRC
value|319
end_define

begin_define
define|#
directive|define
name|IMX7D_TRACE_ROOT_CG
value|320
end_define

begin_define
define|#
directive|define
name|IMX7D_TRACE_ROOT_DIV
value|321
end_define

begin_define
define|#
directive|define
name|IMX7D_WDOG1_ROOT_CLK
value|322
end_define

begin_define
define|#
directive|define
name|IMX7D_WDOG_ROOT_SRC
value|323
end_define

begin_define
define|#
directive|define
name|IMX7D_WDOG_ROOT_CG
value|324
end_define

begin_define
define|#
directive|define
name|IMX7D_WDOG_ROOT_DIV
value|325
end_define

begin_define
define|#
directive|define
name|IMX7D_CSI_MCLK_ROOT_CLK
value|326
end_define

begin_define
define|#
directive|define
name|IMX7D_CSI_MCLK_ROOT_SRC
value|327
end_define

begin_define
define|#
directive|define
name|IMX7D_CSI_MCLK_ROOT_CG
value|328
end_define

begin_define
define|#
directive|define
name|IMX7D_CSI_MCLK_ROOT_DIV
value|329
end_define

begin_define
define|#
directive|define
name|IMX7D_AUDIO_MCLK_ROOT_CLK
value|330
end_define

begin_define
define|#
directive|define
name|IMX7D_AUDIO_MCLK_ROOT_SRC
value|331
end_define

begin_define
define|#
directive|define
name|IMX7D_AUDIO_MCLK_ROOT_CG
value|332
end_define

begin_define
define|#
directive|define
name|IMX7D_AUDIO_MCLK_ROOT_DIV
value|333
end_define

begin_define
define|#
directive|define
name|IMX7D_WRCLK_ROOT_CLK
value|334
end_define

begin_define
define|#
directive|define
name|IMX7D_WRCLK_ROOT_SRC
value|335
end_define

begin_define
define|#
directive|define
name|IMX7D_WRCLK_ROOT_CG
value|336
end_define

begin_define
define|#
directive|define
name|IMX7D_WRCLK_ROOT_DIV
value|337
end_define

begin_define
define|#
directive|define
name|IMX7D_CLKO1_ROOT_SRC
value|338
end_define

begin_define
define|#
directive|define
name|IMX7D_CLKO1_ROOT_CG
value|339
end_define

begin_define
define|#
directive|define
name|IMX7D_CLKO1_ROOT_DIV
value|340
end_define

begin_define
define|#
directive|define
name|IMX7D_CLKO2_ROOT_SRC
value|341
end_define

begin_define
define|#
directive|define
name|IMX7D_CLKO2_ROOT_CG
value|342
end_define

begin_define
define|#
directive|define
name|IMX7D_CLKO2_ROOT_DIV
value|343
end_define

begin_define
define|#
directive|define
name|IMX7D_MAIN_AXI_ROOT_PRE_DIV
value|344
end_define

begin_define
define|#
directive|define
name|IMX7D_DISP_AXI_ROOT_PRE_DIV
value|345
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_AXI_ROOT_PRE_DIV
value|346
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_USDHC_BUS_ROOT_PRE_DIV
value|347
end_define

begin_define
define|#
directive|define
name|IMX7D_AHB_CHANNEL_ROOT_PRE_DIV
value|348
end_define

begin_define
define|#
directive|define
name|IMX7D_USB_HSIC_ROOT_PRE_DIV
value|349
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_CTRL_ROOT_PRE_DIV
value|350
end_define

begin_define
define|#
directive|define
name|IMX7D_PCIE_PHY_ROOT_PRE_DIV
value|351
end_define

begin_define
define|#
directive|define
name|IMX7D_EPDC_PIXEL_ROOT_PRE_DIV
value|352
end_define

begin_define
define|#
directive|define
name|IMX7D_LCDIF_PIXEL_ROOT_PRE_DIV
value|353
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DSI_ROOT_PRE_DIV
value|354
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_CSI_ROOT_PRE_DIV
value|355
end_define

begin_define
define|#
directive|define
name|IMX7D_MIPI_DPHY_ROOT_PRE_DIV
value|356
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI1_ROOT_PRE_DIV
value|357
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI2_ROOT_PRE_DIV
value|358
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI3_ROOT_PRE_DIV
value|359
end_define

begin_define
define|#
directive|define
name|IMX7D_SPDIF_ROOT_PRE_DIV
value|360
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_REF_ROOT_PRE_DIV
value|361
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET1_TIME_ROOT_PRE_DIV
value|362
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_REF_ROOT_PRE_DIV
value|363
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET2_TIME_ROOT_PRE_DIV
value|364
end_define

begin_define
define|#
directive|define
name|IMX7D_ENET_PHY_REF_ROOT_PRE_DIV
value|365
end_define

begin_define
define|#
directive|define
name|IMX7D_EIM_ROOT_PRE_DIV
value|366
end_define

begin_define
define|#
directive|define
name|IMX7D_NAND_ROOT_PRE_DIV
value|367
end_define

begin_define
define|#
directive|define
name|IMX7D_QSPI_ROOT_PRE_DIV
value|368
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC1_ROOT_PRE_DIV
value|369
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC2_ROOT_PRE_DIV
value|370
end_define

begin_define
define|#
directive|define
name|IMX7D_USDHC3_ROOT_PRE_DIV
value|371
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN1_ROOT_PRE_DIV
value|372
end_define

begin_define
define|#
directive|define
name|IMX7D_CAN2_ROOT_PRE_DIV
value|373
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C1_ROOT_PRE_DIV
value|374
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C2_ROOT_PRE_DIV
value|375
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C3_ROOT_PRE_DIV
value|376
end_define

begin_define
define|#
directive|define
name|IMX7D_I2C4_ROOT_PRE_DIV
value|377
end_define

begin_define
define|#
directive|define
name|IMX7D_UART1_ROOT_PRE_DIV
value|378
end_define

begin_define
define|#
directive|define
name|IMX7D_UART2_ROOT_PRE_DIV
value|379
end_define

begin_define
define|#
directive|define
name|IMX7D_UART3_ROOT_PRE_DIV
value|380
end_define

begin_define
define|#
directive|define
name|IMX7D_UART4_ROOT_PRE_DIV
value|381
end_define

begin_define
define|#
directive|define
name|IMX7D_UART5_ROOT_PRE_DIV
value|382
end_define

begin_define
define|#
directive|define
name|IMX7D_UART6_ROOT_PRE_DIV
value|383
end_define

begin_define
define|#
directive|define
name|IMX7D_UART7_ROOT_PRE_DIV
value|384
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI1_ROOT_PRE_DIV
value|385
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI2_ROOT_PRE_DIV
value|386
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI3_ROOT_PRE_DIV
value|387
end_define

begin_define
define|#
directive|define
name|IMX7D_ECSPI4_ROOT_PRE_DIV
value|388
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM1_ROOT_PRE_DIV
value|389
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM2_ROOT_PRE_DIV
value|390
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM3_ROOT_PRE_DIV
value|391
end_define

begin_define
define|#
directive|define
name|IMX7D_PWM4_ROOT_PRE_DIV
value|392
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER1_ROOT_PRE_DIV
value|393
end_define

begin_define
define|#
directive|define
name|IMX7D_FLEXTIMER2_ROOT_PRE_DIV
value|394
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM1_ROOT_PRE_DIV
value|395
end_define

begin_define
define|#
directive|define
name|IMX7D_SIM2_ROOT_PRE_DIV
value|396
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT1_ROOT_PRE_DIV
value|397
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT2_ROOT_PRE_DIV
value|398
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT3_ROOT_PRE_DIV
value|399
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT4_ROOT_PRE_DIV
value|400
end_define

begin_define
define|#
directive|define
name|IMX7D_TRACE_ROOT_PRE_DIV
value|401
end_define

begin_define
define|#
directive|define
name|IMX7D_WDOG_ROOT_PRE_DIV
value|402
end_define

begin_define
define|#
directive|define
name|IMX7D_CSI_MCLK_ROOT_PRE_DIV
value|403
end_define

begin_define
define|#
directive|define
name|IMX7D_AUDIO_MCLK_ROOT_PRE_DIV
value|404
end_define

begin_define
define|#
directive|define
name|IMX7D_WRCLK_ROOT_PRE_DIV
value|405
end_define

begin_define
define|#
directive|define
name|IMX7D_CLKO1_ROOT_PRE_DIV
value|406
end_define

begin_define
define|#
directive|define
name|IMX7D_CLKO2_ROOT_PRE_DIV
value|407
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_PHYM_ALT_ROOT_PRE_DIV
value|408
end_define

begin_define
define|#
directive|define
name|IMX7D_DRAM_ALT_ROOT_PRE_DIV
value|409
end_define

begin_define
define|#
directive|define
name|IMX7D_LVDS1_IN_CLK
value|410
end_define

begin_define
define|#
directive|define
name|IMX7D_LVDS1_OUT_SEL
value|411
end_define

begin_define
define|#
directive|define
name|IMX7D_LVDS1_OUT_CLK
value|412
end_define

begin_define
define|#
directive|define
name|IMX7D_CLK_DUMMY
value|413
end_define

begin_define
define|#
directive|define
name|IMX7D_GPT_3M_CLK
value|414
end_define

begin_define
define|#
directive|define
name|IMX7D_OCRAM_CLK
value|415
end_define

begin_define
define|#
directive|define
name|IMX7D_OCRAM_S_CLK
value|416
end_define

begin_define
define|#
directive|define
name|IMX7D_WDOG2_ROOT_CLK
value|417
end_define

begin_define
define|#
directive|define
name|IMX7D_WDOG3_ROOT_CLK
value|418
end_define

begin_define
define|#
directive|define
name|IMX7D_WDOG4_ROOT_CLK
value|419
end_define

begin_define
define|#
directive|define
name|IMX7D_SDMA_CORE_CLK
value|420
end_define

begin_define
define|#
directive|define
name|IMX7D_USB1_MAIN_480M_CLK
value|421
end_define

begin_define
define|#
directive|define
name|IMX7D_USB_CTRL_CLK
value|422
end_define

begin_define
define|#
directive|define
name|IMX7D_USB_PHY1_CLK
value|423
end_define

begin_define
define|#
directive|define
name|IMX7D_USB_PHY2_CLK
value|424
end_define

begin_define
define|#
directive|define
name|IMX7D_IPG_ROOT_CLK
value|425
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI1_IPG_CLK
value|426
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI2_IPG_CLK
value|427
end_define

begin_define
define|#
directive|define
name|IMX7D_SAI3_IPG_CLK
value|428
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_AUDIO_TEST_DIV
value|429
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_AUDIO_POST_DIV
value|430
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_VIDEO_TEST_DIV
value|431
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_VIDEO_POST_DIV
value|432
end_define

begin_define
define|#
directive|define
name|IMX7D_MU_ROOT_CLK
value|433
end_define

begin_define
define|#
directive|define
name|IMX7D_SEMA4_HS_ROOT_CLK
value|434
end_define

begin_define
define|#
directive|define
name|IMX7D_PLL_DRAM_TEST_DIV
value|435
end_define

begin_define
define|#
directive|define
name|IMX7D_ADC_ROOT_CLK
value|436
end_define

begin_define
define|#
directive|define
name|IMX7D_CLK_ARM
value|437
end_define

begin_define
define|#
directive|define
name|IMX7D_CKIL
value|438
end_define

begin_define
define|#
directive|define
name|IMX7D_OCOTP_CLK
value|439
end_define

begin_define
define|#
directive|define
name|IMX7D_CLK_END
value|440
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_IMX7D_H */
end_comment

end_unit

