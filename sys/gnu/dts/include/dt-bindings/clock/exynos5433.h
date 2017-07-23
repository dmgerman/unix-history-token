begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Samsung Electronics Co., Ltd.  * Author: Chanwoo Choi<cw00.choi@samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_EXYNOS5433_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_EXYNOS5433_H
end_define

begin_comment
comment|/* CMU_TOP */
end_comment

begin_define
define|#
directive|define
name|CLK_FOUT_ISP_PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_AUD_PLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_AUD_PLL
value|10
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ISP_PLL
value|11
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_AUD_PLL_USER_T
value|12
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MPHY_PLL_USER
value|13
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MFC_PLL_USER
value|14
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_BUS_PLL_USER
value|15
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_HEVC_400
value|16
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM1_333
value|17
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM1_552_B
value|18
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM1_552_A
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_ISP_DIS_400
value|20
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_ISP_400
value|21
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_BUS0_400
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_MSCL_400_B
value|23
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_MSCL_400_A
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_GSCL_333
value|25
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_G2D_400_B
value|26
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_G2D_400_A
value|27
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_JPEG_C
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_JPEG_B
value|29
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_JPEG_A
value|30
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC2_B
value|31
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC2_A
value|32
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC1_B
value|33
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC1_A
value|34
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC0_D
value|35
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC0_C
value|36
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC0_B
value|37
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC0_A
value|38
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_SPI4
value|39
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_SPI3
value|40
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_UART2
value|41
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_UART1
value|42
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_UART0
value|43
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_SPI2
value|44
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_SPI1
value|45
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_SPI0
value|46
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_MFC_400_C
value|47
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_MFC_400_B
value|48
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_MFC_400_A
value|49
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_ISP_SENSOR2
value|50
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_ISP_SENSOR1
value|51
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_ISP_SENSOR0
value|52
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_ISP_UART
value|53
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_ISP_SPI1
value|54
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_ISP_SPI0
value|55
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_PCIE_100
value|56
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_UFSUNIPRO
value|57
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_USBHOST30
value|58
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_USBDRD30
value|59
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_SLIMBUS
value|60
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_SPDIF
value|61
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_AUDIO1
value|62
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_AUDIO0
value|63
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_HDMI_SPDIF
value|64
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_FSYS_200
value|100
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_IMEM_SSSX_266
value|101
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_IMEM_200
value|102
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_IMEM_266
value|103
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_PERIC_66_B
value|104
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_PERIC_66_A
value|105
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_PERIS_66_B
value|106
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_PERIS_66_A
value|107
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_MMC1_B
value|108
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_MMC1_A
value|109
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_MMC0_B
value|110
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_MMC0_A
value|111
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_MMC2_B
value|112
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_MMC2_A
value|113
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI1_B
value|114
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI1_A
value|115
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI0_B
value|116
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI0_A
value|117
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI2_B
value|118
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI2_A
value|119
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_UART2
value|120
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_UART1
value|121
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_UART0
value|122
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI4_B
value|123
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI4_A
value|124
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI3_B
value|125
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SPI3_A
value|126
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_I2S1
value|127
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_PCM1
value|128
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_AUDIO1
value|129
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_AUDIO0
value|130
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_GSCL_111
value|131
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_GSCL_333
value|132
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_HEVC_400
value|133
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_MFC_400
value|134
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_G2D_266
value|135
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_G2D_400
value|136
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_G3D_400
value|137
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_BUS0_400
value|138
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_BUS1_400
value|139
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_PCIE_100
value|140
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_USBHOST30
value|141
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_UFSUNIPRO
value|142
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_USBDRD30
value|143
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_JPEG
value|144
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_MSCL_400
value|145
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_ISP_DIS_400
value|146
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_ISP_400
value|147
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CAM0_333
value|148
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CAM0_400
value|149
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CAM0_552
value|150
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CAM1_333
value|151
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CAM1_400
value|152
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CAM1_552
value|153
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_UART
value|154
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SPI1_B
value|155
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SPI1_A
value|156
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SPI0_B
value|157
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SPI0_A
value|158
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SENSOR2_B
value|159
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SENSOR2_A
value|160
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SENSOR1_B
value|161
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SENSOR1_A
value|162
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SENSOR0_B
value|163
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_SENSOR0_A
value|164
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PERIC_66
value|200
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PERIS_66
value|201
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_FSYS_200
value|202
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC2_FSYS
value|203
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC1_FSYS
value|204
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC0_FSYS
value|205
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI4_PERIC
value|206
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI3_PERIC
value|207
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART2_PERIC
value|208
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART1_PERIC
value|209
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART0_PERIC
value|210
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI2_PERIC
value|211
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1_PERIC
value|212
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0_PERIC
value|213
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPDIF_PERIC
value|214
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S1_PERIC
value|215
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM1_PERIC
value|216
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SLIMBUS
value|217
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO1
value|218
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO0
value|219
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G2D_266
value|220
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G2D_400
value|221
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G3D_400
value|222
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_IMEM_SSX_266
value|223
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BUS0_400
value|224
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BUS1_400
value|225
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_IMEM_200
value|226
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_IMEM_266
value|227
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCIE_100_FSYS
value|228
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UFSUNIPRO_FSYS
value|229
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_USBHOST30_FSYS
value|230
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_USBDRD30_FSYS
value|231
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_GSCL_111
value|232
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_GSCL_333
value|233
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_JPEG_MSCL
value|234
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MSCL_400
value|235
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MFC_400
value|236
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_HEVC_400
value|237
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ISP_DIS_400
value|238
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ISP_400
value|239
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM0_333
value|240
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM0_400
value|241
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM0_552
value|242
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM1_333
value|243
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM1_400
value|244
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM1_552
value|245
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SENSOR2
value|246
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SENSOR1
value|247
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SENSOR0
value|248
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_MCTADC_CAM1
value|249
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_UART_CAM1
value|250
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SPI1_CAM1
value|251
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SPI0_CAM1
value|252
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HDMI_SPDIF_DISP
value|253
end_define

begin_define
define|#
directive|define
name|TOP_NR_CLK
value|254
end_define

begin_comment
comment|/* CMU_CPIF */
end_comment

begin_define
define|#
directive|define
name|CLK_FOUT_MPHY_PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MPHY_PLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_MPHY
value|10
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MPHY_PLL
value|11
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UFS_MPHY
value|11
end_define

begin_define
define|#
directive|define
name|CPIF_NR_CLK
value|12
end_define

begin_comment
comment|/* CMU_MIF */
end_comment

begin_define
define|#
directive|define
name|CLK_FOUT_MEM0_PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_MEM1_PLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_BUS_PLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_MFC_PLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_DOUT_MFC_PLL
value|5
end_define

begin_define
define|#
directive|define
name|CLK_DOUT_BUS_PLL
value|6
end_define

begin_define
define|#
directive|define
name|CLK_DOUT_MEM1_PLL
value|7
end_define

begin_define
define|#
directive|define
name|CLK_DOUT_MEM0_PLL
value|8
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MFC_PLL_DIV2
value|10
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_BUS_PLL_DIV2
value|11
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MEM1_PLL_DIV2
value|12
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MEM0_PLL_DIV2
value|13
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MFC_PLL
value|14
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_BUS_PLL
value|15
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MEM1_PLL
value|16
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MEM0_PLL
value|17
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CLK2X_PHY_C
value|18
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CLK2X_PHY_B
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CLK2X_PHY_A
value|20
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CLKM_PHY_C
value|21
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CLKM_PHY_B
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CLKM_PHY_A
value|23
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_MIFNM_200
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_MIFNM_400
value|25
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_DISP_333_B
value|26
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_DISP_333_A
value|27
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_VCLK_C
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_VCLK_B
value|29
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_VCLK_A
value|30
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_ECLK_C
value|31
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_ECLK_B
value|32
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_ECLK_A
value|33
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_ECLK_C
value|34
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_ECLK_B
value|35
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_ECLK_A
value|36
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSD_C
value|37
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSD_B
value|38
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSD_A
value|39
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM0_C
value|40
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM0_B
value|41
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM0_A
value|42
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_VCLK_C
value|46
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_VCLK_B
value|47
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_VCLK_A
value|48
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM1_C
value|49
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM1_B
value|50
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM1_A
value|51
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_HPM_MIF
value|55
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_DREX1
value|56
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_DREX0
value|57
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CLK2XPHY
value|58
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_MIF_266
value|59
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_MIFND_133
value|60
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_MIF_133
value|61
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_MIFNM_200
value|62
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_MIF_200
value|63
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_MIF_400
value|64
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_BUS2_400
value|65
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_DISP_333
value|66
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CPIF_200
value|67
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DSIM1
value|68
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DECON_TV_VCLK
value|69
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DSIM0
value|70
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DSD
value|71
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DECON_TV_ECLK
value|72
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DECON_VCLK
value|73
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DECON_ECLK
value|74
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MIF_PRE
value|75
end_define

begin_define
define|#
directive|define
name|CLK_CLK2X_PHY1
value|80
end_define

begin_define
define|#
directive|define
name|CLK_CLK2X_PHY0
value|81
end_define

begin_define
define|#
directive|define
name|CLK_CLKM_PHY1
value|82
end_define

begin_define
define|#
directive|define
name|CLK_CLKM_PHY0
value|83
end_define

begin_define
define|#
directive|define
name|CLK_RCLK_DREX1
value|84
end_define

begin_define
define|#
directive|define
name|CLK_RCLK_DREX0
value|85
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX1_TZ
value|86
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX0_TZ
value|87
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX1_PEREV
value|88
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX0_PEREV
value|89
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX1_MEMIF
value|90
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX0_MEMIF
value|91
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX1_SCH
value|92
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX0_SCH
value|93
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX1_BUSIF
value|94
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX0_BUSIF
value|95
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX1_BUSIF_RD
value|96
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX0_BUSIF_RD
value|97
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX1
value|98
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DREX0
value|99
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_ATLAS_CCIX
value|100
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_ATLAS_MIF
value|101
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_ATLAS_MIF
value|102
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_MIF_IMEM
value|103
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_NOC_P_CCI
value|104
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_NOC_P_CCI
value|105
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_CP1
value|106
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_CP1
value|107
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_CP0
value|108
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_CP0
value|109
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_DREX1_3
value|110
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_DREX1_3
value|111
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_DREX1_1
value|112
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_DREX1_1
value|113
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_DREX1_0
value|114
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_DREX1_0
value|115
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_DREX0_3
value|116
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_DREX0_3
value|117
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_DREX0_1
value|118
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_DREX0_1
value|119
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_DREX0_0
value|120
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_DREX0_0
value|121
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_MIF2P
value|122
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_MIF1P
value|123
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_MIF0P
value|124
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_IXIU_CCI
value|125
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_MIFSFRX
value|126
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MIFNP_133
value|127
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MIFNM_200
value|128
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MIFND_133
value|129
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MIFND_400
value|130
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CCI
value|131
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MIFND_266
value|132
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PPMU_DREX1S3
value|133
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PPMU_DREX1S1
value|134
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PPMU_DREX1S0
value|135
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PPMU_DREX0S3
value|136
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PPMU_DREX0S1
value|137
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PPMU_DREX0S0
value|138
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_APOLLO
value|139
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_ATLAS
value|140
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ACE_SEL_APOLL
value|141
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ACE_SEL_ATLAS
value|142
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIDS_CCI_MIFSFRX
value|143
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_ATLAS_CCI
value|144
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXISYNCDNS_CCI
value|145
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXISYNCDN_CCI
value|146
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXISYNCDN_NOC_D
value|147
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCACEM_APOLLO_CCI
value|148
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCACEM_ATLAS_CCI
value|149
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBS_MIF_CSSYS
value|150
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BUS2_400
value|151
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DISP_333
value|152
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CPIF_200
value|153
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PPMU_DREX1S3
value|154
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PPMU_DREX1S1
value|155
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PPMU_DREX1S0
value|156
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PPMU_DREX0S3
value|157
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PPMU_DREX0S1
value|158
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PPMU_DREX0S0
value|159
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_APOLLO
value|160
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_ATLAS
value|161
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_NOC_P_CCI
value|162
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_CP1
value|163
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_CP0
value|164
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_DREX1_3
value|165
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_DREX1_1
value|166
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_DREX1_0
value|167
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_DREX0_3
value|168
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_DREX0_1
value|169
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_DREX0_0
value|170
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_MIFSRVND_133
value|171
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_MIF
value|172
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_MIF
value|173
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GPIO_ALIVE
value|174
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ABB
value|175
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_APBIF
value|176
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DDR_PHY1
value|177
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DREX1
value|178
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DDR_PHY0
value|179
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DREX0
value|180
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DREX0_TZ
value|181
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DREX1_TZ
value|182
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_MONOTONIC_CNT
value|183
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_RTC
value|184
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DSIM1_DISP
value|185
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DECON_TV_VCLK_DISP
value|186
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FREQ_DET_BUS_PLL
value|187
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FREQ_DET_MFC_PLL
value|188
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FREQ_DET_MEM0_PLL
value|189
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FREQ_DET_MEM1_PLL
value|190
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DSIM0_DISP
value|191
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DSD_DISP
value|192
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DECON_TV_ECLK_DISP
value|193
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DECON_VCLK_DISP
value|194
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DECON_ECLK_DISP
value|195
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HPM_MIF
value|196
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MFC_PLL
value|197
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_BUS_PLL
value|198
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_BUS_PLL_APOLLO
value|199
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_BUS_PLL_ATLAS
value|200
end_define

begin_define
define|#
directive|define
name|MIF_NR_CLK
value|201
end_define

begin_comment
comment|/* CMU_PERIC */
end_comment

begin_define
define|#
directive|define
name|CLK_PCLK_SPI2
value|1
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SPI1
value|2
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SPI0
value|3
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_UART2
value|4
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_UART1
value|5
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_UART0
value|6
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C3
value|7
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C2
value|8
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C1
value|9
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C0
value|10
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_I2C7
value|11
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_I2C6
value|12
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_I2C5
value|13
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_I2C4
value|14
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_I2C3
value|15
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_I2C2
value|16
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_I2C1
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_I2C0
value|18
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SPI4
value|19
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SPI3
value|20
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C11
value|21
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C10
value|22
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C9
value|23
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C8
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C7
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C6
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C5
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HSI2C4
value|28
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI4
value|29
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI3
value|30
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI2
value|31
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1
value|32
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0
value|33
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART2
value|34
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART1
value|35
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART0
value|36
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_PERIC2P
value|37
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_PERIC1P
value|38
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_PERIC0P
value|39
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PERICNP_66
value|40
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SCI
value|41
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GPIO_FINGER
value|42
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GPIO_ESE
value|43
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PWM
value|44
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SPDIF
value|45
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PCM1
value|46
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_I2S1
value|47
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ADCIF
value|48
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GPIO_TOUCH
value|49
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GPIO_NFC
value|50
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GPIO_PERIC
value|51
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_PERIC
value|52
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_PERIC
value|53
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_IOCLK_SPI4
value|54
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_IOCLK_SPI3
value|55
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SCI
value|56
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SC_IN
value|57
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PWM
value|58
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_IOCLK_SPI2
value|59
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_IOCLK_SPI1
value|60
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_IOCLK_SPI0
value|61
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_IOCLK_I2S1_BCLK
value|62
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPDIF
value|63
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM1
value|64
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S1
value|65
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SCI
value|70
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_SC_IN
value|71
end_define

begin_define
define|#
directive|define
name|PERIC_NR_CLK
value|72
end_define

begin_comment
comment|/* CMU_PERIS */
end_comment

begin_define
define|#
directive|define
name|CLK_PCLK_HPM_APBIF
value|1
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TMU1_APBIF
value|2
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TMU0_APBIF
value|3
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_PERIS
value|4
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_PERIS
value|5
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_CMU_TOP_APBIF
value|6
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_WDT_APOLLO
value|7
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_WDT_ATLAS
value|8
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_MCT
value|9
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HDMI_CEC
value|10
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_PERIS1P
value|11
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_PERIS0P
value|12
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PERISNP_66
value|13
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC12
value|14
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC11
value|15
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC10
value|16
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC9
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC8
value|18
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC7
value|19
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC6
value|20
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC5
value|21
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC4
value|22
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC3
value|23
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC2
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC1
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TZPC0
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SECKEY_APBIF
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_CHIPID_APBIF
value|28
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TOPRTC
value|29
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_CUSTOM_EFUSE_APBIF
value|30
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ANTIRBK_CNT_APBIF
value|31
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_OTP_CON_APBIF
value|32
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ASV_TB
value|33
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_TMU1
value|34
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_TMU0
value|35
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SECKEY
value|36
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CHIPID
value|37
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_TOPRTC
value|38
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CUSTOM_EFUSE
value|39
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ANTIRBK_CNT
value|40
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_OTP_CON
value|41
end_define

begin_define
define|#
directive|define
name|PERIS_NR_CLK
value|42
end_define

begin_comment
comment|/* CMU_FSYS */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_FSYS_200_USER
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC2_USER
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC1_USER
value|3
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MMC0_USER
value|4
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_UFS_MPHY_USER
value|5
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_PCIE_100_USER
value|6
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_UFSUNIPRO_USER
value|7
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_USBHOST30_USER
value|8
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_USBDRD30_USER
value|9
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_USBHOST30_UHOST30_PIPE_PCLK_USER
value|10
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_USBHOST30_UHOST30_PHYCLOCK_USER
value|11
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_USBHOST20_PHY_HSIC1_USER
value|12
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_USBHOST20_PHY_CLK48MOHCI_USER
value|13
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_USBHOST20_PHY_PHYCLOCK_USER
value|14
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_USBHOST20_PHY_PHY_FREECLK_USER
value|15
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_USBDRD30_UDRD30_PIPE_PCLK_USER
value|16
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_USBDRD30_UDRD30_PHYCLOCK_USER
value|17
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_UFS_RX1_SYMBOL_USER
value|18
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_UFS_RX0_SYMBOL_USER
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_UFS_TX1_SYMBOL_USER
value|20
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_UFS_TX0_SYMBOL_USER
value|21
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_LLI_MPHY_TO_UFS_USER
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_MPHY
value|23
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBDRD30_UDRD30_PHYCLOCK_PHY
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBDRD30_UDRD30_PIPE_PCLK_PHY
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST30_UHOST30_PHYCLOCK_PHY
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST30_UHOST30_PIPE_PCLK_PHY
value|28
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST20_PHY_FREECLK_PHY
value|29
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST20_PHY_PHYCLOCK_PHY
value|30
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST20_PHY_CLK48MOHCI_PHY
value|31
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST20_PHY_HSIC1_PHY
value|32
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_UFS_TX0_SYMBOL_PHY
value|33
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_UFS_RX0_SYMBOL_PHY
value|34
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_UFS_TX1_SYMBOL_PHY
value|35
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_UFS_RX1_SYMBOL_PHY
value|36
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_LLI_MPHY_TO_UFS_PHY
value|37
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PCIE
value|50
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PDMA1
value|51
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_TSI
value|52
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MMC2
value|53
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MMC1
value|54
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MMC0
value|55
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_UFS
value|56
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_USBHOST20
value|57
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_USBHOST30
value|58
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_USBDRD30
value|59
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_PDMA0
value|60
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC2
value|61
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC1
value|62
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC0
value|63
end_define

begin_define
define|#
directive|define
name|CLK_PDMA1
value|64
end_define

begin_define
define|#
directive|define
name|CLK_PDMA0
value|65
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_FSYSPX
value|66
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB_USBLINKH1
value|67
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_PDMA1
value|68
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_PCIE
value|69
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_PDMA1
value|70
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_PDMA0
value|71
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_UFS
value|72
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_USBHOST30
value|73
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_USBDRD30
value|74
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_PDMA0
value|75
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_USBHS
value|76
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_FSYSSX
value|77
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_FSYSP
value|78
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2AXI_USBHS
value|79
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB_USBLINKH0
value|80
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB_USBHS
value|81
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB_FSYSH
value|82
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_FSYSX
value|83
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_FSYSSX
value|84
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_FSYSNP_200
value|85
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_FSYSND_200
value|86
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PCIE_CTRL
value|87
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_PDMA1
value|88
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PCIE_PHY
value|89
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_PCIE
value|90
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_PDMA0
value|91
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_UFS
value|92
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_USBHOST30
value|93
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_USBDRD30
value|94
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GPIO_FSYS
value|95
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_FSYS
value|96
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_FSYS
value|97
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCIE_100
value|98
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST30_UHOST30_PIPE_PCLK
value|99
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST30_UHOST30_PHYCLOCK
value|100
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_UFS_RX1_SYMBOL
value|101
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_UFS_RX0_SYMBOL
value|102
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_UFS_TX1_SYMBOL
value|103
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_UFS_TX0_SYMBOL
value|104
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST20_PHY_HSIC1
value|105
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST20_PHY_CLK48MOHCI
value|106
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST20_PHY_PHYCLOCK
value|107
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBHOST20_PHY_FREECLK
value|108
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBDRD30_UDRD30_PIPE_PCLK
value|109
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_USBDRD30_UDRD30_PHYCLOCK
value|110
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MPHY
value|111
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UFSUNIPRO
value|112
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_USBHOST30
value|113
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_USBDRD30
value|114
end_define

begin_define
define|#
directive|define
name|CLK_PCIE
value|115
end_define

begin_define
define|#
directive|define
name|FSYS_NR_CLK
value|116
end_define

begin_comment
comment|/* CMU_G2D */
end_comment

begin_define
define|#
directive|define
name|CLK_MUX_ACLK_G2D_266_USER
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MUX_ACLK_G2D_400_USER
value|2
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_G2D
value|3
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_MDMA1
value|4
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_MDMA1
value|5
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_G2D
value|6
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ALB_G2D
value|7
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_G2DX
value|8
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXI_SYSX
value|9
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_G2D1P
value|10
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_G2D0P
value|11
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_G2DX
value|12
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G2DNP_133
value|13
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G2DND_400
value|14
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MDMA1
value|15
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G2D
value|16
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_G2D
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_MDMA1
value|18
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_MDMA1
value|19
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_G2D
value|20
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ALB_G2D
value|21
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_SYSX
value|22
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_G2D
value|23
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_G2D
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_G2D
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_G2D
value|26
end_define

begin_define
define|#
directive|define
name|G2D_NR_CLK
value|27
end_define

begin_comment
comment|/* CMU_DISP */
end_comment

begin_define
define|#
directive|define
name|CLK_FOUT_DISP_PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_DISP_PLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM1_USER
value|3
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM0_USER
value|4
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSD_USER
value|5
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_ECLK_USER
value|6
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_VCLK_USER
value|7
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_ECLK_USER
value|8
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_VCLK_USER
value|9
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_DISP_333_USER
value|10
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_MIPIDPHY1_BITCLKDIV8_USER
value|11
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_MIPIDPHY1_RXCLKESC0_USER
value|12
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_MIPIDPHY0_BITCLKDIV8_USER
value|13
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_MIPIDPHY0_RXCLKESC0_USER
value|14
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_HDMIPHY_TMDS_CLKO_USER
value|15
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_HDMIPHY_PIXEL_CLKO_USER
value|16
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM0
value|17
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_ECLK
value|18
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_VCLK
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_ECLK
value|20
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM1_B_DISP
value|21
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DSIM1_A_DISP
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_VCLK_C_DISP
value|23
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_VCLK_B_DISP
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_DECON_TV_VCLK_A_DISP
value|25
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DSIM1_DISP
value|30
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DECON_TV_VCLK_DISP
value|31
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DSIM0_DISP
value|32
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DECON_TV_ECLK_DISP
value|33
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DECON_VCLK_DISP
value|34
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_DECON_ECLK_DISP
value|35
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_DISP
value|36
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DECON_TV
value|40
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DECON
value|41
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_TV1X
value|42
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_TV0X
value|43
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_DECON1X
value|44
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_DECON0X
value|45
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DECON_TV_M3
value|46
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DECON_TV_M2
value|47
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DECON_TV_M1
value|48
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DECON_TV_M0
value|49
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DECON_NM4
value|50
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DECON_NM3
value|51
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DECON_NM2
value|52
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DECON_NM1
value|53
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DECON_NM0
value|54
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_DISPSFR2P
value|55
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_DISPSFR1P
value|56
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_DISPSFR0P
value|57
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB_DISPH
value|58
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_TV1X
value|59
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_TV0X
value|60
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_DECON1X
value|61
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_DECON0X
value|62
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_DISP1X
value|63
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_DISPNP_100
value|64
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DISP1ND_333
value|65
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DISP0ND_333
value|66
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_TV1X
value|67
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_TV0X
value|68
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_DECON1X
value|69
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_DECON0X
value|70
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DECON_TV_M3
value|71
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DECON_TV_M2
value|72
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DECON_TV_M1
value|73
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DECON_TV_M0
value|74
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DECONM4
value|75
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DECONM3
value|76
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DECONM2
value|77
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DECONM1
value|78
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DECONM0
value|79
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_MIC1
value|80
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_DISP
value|81
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_DISP
value|82
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HDMIPHY
value|83
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HDMI
value|84
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_MIC0
value|85
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DSIM1
value|86
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DSIM0
value|87
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DECON_TV
value|88
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_MIPIDPHY1_BITCLKDIV8
value|89
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_MIPIDPHY1_RXCLKESC0
value|90
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_RGB_TV_VCLK_TO_DSIM1
value|91
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_RGB_TV_VCLK_TO_MIC1
value|92
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DSIM1
value|93
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DECON_TV_VCLK
value|94
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_MIPIDPHY0_BITCLKDIV8
value|95
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_MIPIDPHY0_RXCLKESC0
value|96
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_HDMIPHY_TMDS_CLKO
value|97
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_HDMI_PIXEL
value|98
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_RGB_VCLK_TO_SMIES
value|99
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FREQ_DET_DISP_PLL
value|100
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_RGB_VCLK_TO_DSIM0
value|101
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_RGB_VCLK_TO_MIC0
value|102
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DSD
value|103
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HDMI_SPDIF
value|104
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DSIM0
value|105
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DECON_TV_ECLK
value|106
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DECON_VCLK
value|107
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DECON_ECLK
value|108
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_RGB_VCLK
value|109
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_RGB_TV_VCLK
value|110
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_HDMIPHY_PIXEL_CLKO_PHY
value|111
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_HDMIPHY_TMDS_CLKO_PHY
value|112
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DECON
value|113
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_MIPIDPHY0_BITCLKDIV8_PHY
value|114
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_MIPIDPHY0_RXCLKESC0_PHY
value|115
end_define

begin_define
define|#
directive|define
name|DISP_NR_CLK
value|116
end_define

begin_comment
comment|/* CMU_AUD */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_AUD_PLL_USER
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_AUD_PCM
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_AUD_I2S
value|3
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ATCLK_AUD
value|4
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_DBG_AUD
value|5
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_AUD
value|6
end_define

begin_define
define|#
directive|define
name|CLK_DIV_AUD_CA5
value|7
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_AUD_SLIMBUS
value|8
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_AUD_UART
value|9
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_AUD_PCM
value|10
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_AUD_I2S
value|11
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_INTR_CTRL
value|12
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIDS2_LPASSP
value|13
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIDS1_LPASSP
value|14
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI2APB1_LPASSP
value|15
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI2APH_LPASSP
value|16
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_LPASSX
value|17
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIDS0_LPASSP
value|18
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI2APB0_LPASSP
value|19
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_LPASSX
value|20
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AUDNP_133
value|21
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AUDND_133
value|22
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SRAMC
value|23
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DMAC
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_WDT1
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_WDT0
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SFR1
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_LPASSX
value|28
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GPIO_AUD
value|29
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_AUD
value|30
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_AUD
value|31
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_AUD_SLIMBUS
value|32
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_AUD_UART
value|33
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_AUD_PCM
value|34
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_AUD_I2S
value|35
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_TIMER
value|36
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SFR0_CTRL
value|37
end_define

begin_define
define|#
directive|define
name|CLK_ATCLK_AUD
value|38
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DBG_AUD
value|39
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUD_CA5
value|40
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_JTAG_TCK
value|41
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SLIMBUS_CLKIN
value|42
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUD_SLIMBUS
value|43
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUD_UART
value|44
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUD_PCM
value|45
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S_BCLK
value|46
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUD_I2S
value|47
end_define

begin_define
define|#
directive|define
name|AUD_NR_CLK
value|48
end_define

begin_comment
comment|/* CMU_BUS{0|1|2} */
end_comment

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_BUS_133
value|1
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_BUSP
value|2
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BUSNP_133
value|3
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BUSND_400
value|4
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BUSSRVND_133
value|5
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_BUS
value|6
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_BUS
value|7
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_BUS2_400_USER
value|8
end_define

begin_comment
comment|/* Only CMU_BUS2 */
end_comment

begin_define
define|#
directive|define
name|CLK_ACLK_BUS2BEND_400
value|9
end_define

begin_comment
comment|/* Only CMU_BUS2 */
end_comment

begin_define
define|#
directive|define
name|CLK_ACLK_BUS2RTND_400
value|10
end_define

begin_comment
comment|/* Only CMU_BUS2 */
end_comment

begin_define
define|#
directive|define
name|BUSx_NR_CLK
value|11
end_define

begin_comment
comment|/* CMU_G3D */
end_comment

begin_define
define|#
directive|define
name|CLK_FOUT_G3D_PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_G3D_400
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D_PLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_HPM_G3D
value|4
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_G3D
value|5
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_G3D
value|6
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_G3D1
value|7
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_G3D0
value|8
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBS_G3D
value|9
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBM_G3D
value|10
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_G3DP
value|11
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G3DNP_150
value|12
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G3DND_600
value|13
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G3D
value|14
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_G3D1
value|15
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_G3D0
value|16
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_G3D
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_G3D
value|18
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HPM_G3D
value|19
end_define

begin_define
define|#
directive|define
name|G3D_NR_CLK
value|20
end_define

begin_comment
comment|/* CMU_GSCL */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_GSCL_111_USER
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_GSCL_333_USER
value|2
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_GSCL2
value|3
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_GSCL1
value|4
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_GSCL0
value|5
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_GSCLP
value|6
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_GSCLX
value|7
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_GSCLNP_111
value|8
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_GSCLRTND_333
value|9
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_GSCLBEND_333
value|10
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_GSD
value|11
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_GSCL2
value|12
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_GSCL1
value|13
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_GSCL0
value|14
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_GSCL0
value|15
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_GSCL1
value|16
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_GSCL2
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_GSCL2
value|18
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_GSCL1
value|19
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_GSCL0
value|20
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_GSCL
value|21
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_GSCL
value|22
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GSCL2
value|23
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GSCL1
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_GSCL0
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_GSCL0
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_GSCL1
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_GSCL2
value|28
end_define

begin_define
define|#
directive|define
name|GSCL_NR_CLK
value|29
end_define

begin_comment
comment|/* CMU_APOLLO */
end_comment

begin_define
define|#
directive|define
name|CLK_FOUT_APOLLO_PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_APOLLO_PLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_BUS_PLL_APOLLO_USER
value|3
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_APOLLO
value|4
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CNTCLK_APOLLO
value|5
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_DBG_APOLLO
value|6
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ATCLK_APOLLO
value|7
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_APOLLO
value|8
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_APOLLO
value|9
end_define

begin_define
define|#
directive|define
name|CLK_DIV_APOLLO2
value|10
end_define

begin_define
define|#
directive|define
name|CLK_DIV_APOLLO1
value|11
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_HPM_APOLLO
value|12
end_define

begin_define
define|#
directive|define
name|CLK_DIV_APOLLO_PLL
value|13
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATBDS_APOLLO_3
value|14
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATBDS_APOLLO_2
value|15
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATBDS_APOLLO_1
value|16
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATBDS_APOLLO_0
value|17
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASATBSLV_APOLLO_3_CSSYS
value|18
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASATBSLV_APOLLO_2_CSSYS
value|19
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASATBSLV_APOLLO_1_CSSYS
value|20
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASATBSLV_APOLLO_0_CSSYS
value|21
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCACES_APOLLO_CCI
value|22
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_APOLLOP
value|23
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_APOLLONP_200
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASAPBMST_CSSYS_APOLLO
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_APOLLO
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_APOLLO
value|27
end_define

begin_define
define|#
directive|define
name|CLK_CNTCLK_APOLLO
value|28
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HPM_APOLLO
value|29
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_APOLLO
value|30
end_define

begin_define
define|#
directive|define
name|APOLLO_NR_CLK
value|31
end_define

begin_comment
comment|/* CMU_ATLAS */
end_comment

begin_define
define|#
directive|define
name|CLK_FOUT_ATLAS_PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ATLAS_PLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_BUS_PLL_ATLAS_USER
value|3
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ATLAS
value|4
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CNTCLK_ATLAS
value|5
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_DBG_ATLAS
value|6
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ATCLK_ATLASO
value|7
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_ATLAS
value|8
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_ATLAS
value|9
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ATLAS2
value|10
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ATLAS1
value|11
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_HPM_ATLAS
value|12
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ATLAS_PLL
value|13
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATB_AUD_CSSYS
value|14
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATB_APOLLO3_CSSYS
value|15
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATB_APOLLO2_CSSYS
value|16
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATB_APOLLO1_CSSYS
value|17
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATB_APOLLO0_CSSYS
value|18
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAHBS_CSSYS_SSS
value|19
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_CSSYS_CCIX
value|20
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCACES_ATLAS_CCI
value|21
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_ATLASP
value|22
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ATLASNP_200
value|23
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAPB_AUD_CSSYS
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAPB_ISP_CSSYS
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAPB_APOLLO_CSSYS
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_ATLAS
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_ATLAS
value|28
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SECJTAG
value|29
end_define

begin_define
define|#
directive|define
name|CLK_CNTCLK_ATLAS
value|30
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FREQ_DET_ATLAS_PLL
value|31
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HPM_ATLAS
value|32
end_define

begin_define
define|#
directive|define
name|CLK_TRACECLK
value|33
end_define

begin_define
define|#
directive|define
name|CLK_CTMCLK
value|34
end_define

begin_define
define|#
directive|define
name|CLK_HCLK_CSSYS
value|35
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DBG_CSSYS
value|36
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DBG
value|37
end_define

begin_define
define|#
directive|define
name|CLK_ATCLK
value|38
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ATLAS
value|39
end_define

begin_define
define|#
directive|define
name|ATLAS_NR_CLK
value|40
end_define

begin_comment
comment|/* CMU_MSCL */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_JPEG_USER
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_MSCL_400_USER
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_JPEG
value|3
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_MSCL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_JPEG
value|5
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_M2MSCALER1
value|6
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_M2MSCALER0
value|7
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_MSCL0P
value|8
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_MSCLX
value|9
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MSCLNP_100
value|10
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MSCLND_400
value|11
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_JPEG
value|12
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_M2MSCALER1
value|13
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_M2MSCALER0
value|14
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_M2MSCALER0
value|15
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_M2MSCALER1
value|16
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_JPEG
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_JPEG
value|18
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_M2MSCALER1
value|19
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_M2MSCALER0
value|20
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_MSCL
value|21
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_MSCL
value|22
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_JPEG
value|23
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_M2MSCALER1
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_M2MSCALER0
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_M2MSCALER0
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_M2MSCALER1
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_JPEG
value|28
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_JPEG
value|29
end_define

begin_define
define|#
directive|define
name|MSCL_NR_CLK
value|30
end_define

begin_comment
comment|/* CMU_MFC */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_MFC_400_USER
value|1
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_MFC
value|2
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_MFC_1
value|3
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_MFC_0
value|4
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_MFCP
value|5
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_MFCX
value|6
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MFCNP_100
value|7
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MFCND_400
value|8
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_MFC
value|9
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_MFC_1
value|10
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_MFC_0
value|11
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_MFC_1
value|12
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_MFC_0
value|13
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_MFC
value|14
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_MFC
value|15
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_MFC
value|16
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_MFC_1
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_MFC_0
value|18
end_define

begin_define
define|#
directive|define
name|MFC_NR_CLK
value|19
end_define

begin_comment
comment|/* CMU_HEVC */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_HEVC_400_USER
value|1
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_HEVC
value|2
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_HEVC_1
value|3
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_HEVC_0
value|4
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_HEVCP
value|5
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_HEVCX
value|6
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_HEVCNP_100
value|7
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_HEVCND_400
value|8
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_HEVC
value|9
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_HEVC_1
value|10
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_HEVC_0
value|11
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_HEVC_1
value|12
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_HEVC_0
value|13
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_HEVC
value|14
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_HEVC
value|15
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_HEVC
value|16
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_HEVC_1
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_HEVC_0
value|18
end_define

begin_define
define|#
directive|define
name|HEVC_NR_CLK
value|19
end_define

begin_comment
comment|/* CMU_ISP */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_ISP_DIS_400_USER
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_ISP_400_USER
value|2
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_ISP_DIS
value|3
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_ISP
value|4
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_ISP_D_200
value|5
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_ISP_C_200
value|6
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ISP_D_GLUE
value|7
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SCALERP
value|8
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_3DNR
value|9
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DIS
value|10
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SCALERC
value|11
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_DRC
value|12
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ISP
value|13
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_SCALERP
value|14
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_SCALERC
value|15
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_DRC
value|16
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAHBM_ISP2P
value|17
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAHBM_ISP1P
value|18
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_DIS1
value|19
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_DIS0
value|20
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_DIS1
value|21
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_DIS0
value|22
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_ISP2P
value|23
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_ISP1P
value|24
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_ISP2P
value|25
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_ISP1P
value|26
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI2APB_ISP2P
value|27
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI2APB_ISP1P
value|28
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_ISPEX1
value|29
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_ISPEX0
value|30
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ISPND_400
value|31
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_SCALERP
value|32
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_3DNR
value|33
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_DIS1
value|34
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_DIS0
value|35
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_SCALERC
value|36
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_DRC
value|37
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_ISP
value|38
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_SCALERP
value|39
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_3DR
value|40
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DIS1
value|41
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DIS0
value|42
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_SCALERC
value|43
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_DRC
value|44
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_ISP
value|45
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_SCALERP
value|46
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_3DNR
value|47
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_DIS1
value|48
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_DIS0
value|49
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_SCALERC
value|50
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_DRC
value|51
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_ISP
value|52
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_SCALERP
value|53
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_3DNR
value|54
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DIS1
value|55
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DIS0
value|56
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_SCALERC
value|57
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_DRC
value|58
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_ISP
value|59
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_DIS1
value|60
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_DIS0
value|61
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_ISP
value|62
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_ISP
value|63
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_CMU_ISP_LOCAL
value|64
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SCALERP
value|65
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_3DNR
value|66
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DIS_CORE
value|67
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DIS
value|68
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SCALERC
value|69
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DRC
value|70
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP
value|71
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCS_DIS
value|72
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCM_DIS
value|73
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCS_SCALERP
value|74
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCM_ISPD
value|75
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCS_ISPC
value|76
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCM_ISPC
value|77
end_define

begin_define
define|#
directive|define
name|ISP_NR_CLK
value|78
end_define

begin_comment
comment|/* CMU_CAM0 */
end_comment

begin_define
define|#
directive|define
name|CLK_PHYCLK_RXBYTEECLKHS0_S4_PHY
value|1
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_RXBYTEECLKHS0_S2A_PHY
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM0_333_USER
value|3
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM0_400_USER
value|4
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM0_552_USER
value|5
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_RXBYTECLKHS0_S4_USER
value|6
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_RXBYTECLKHS0_S2A_USER
value|7
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_LITE_D_B
value|8
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_LITE_D_A
value|9
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_LITE_B_B
value|10
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_LITE_B_A
value|11
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_LITE_A_B
value|12
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_LITE_A_A
value|13
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM0_400
value|14
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CSIS1_B
value|15
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CSIS1_A
value|16
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CSIS0_B
value|17
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CSIS0_A
value|18
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_3AA1_B
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_3AA1_A
value|20
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_3AA0_B
value|21
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_3AA0_A
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_LITE_FREECNT_C
value|23
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_LITE_FREECNT_B
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_LITE_FREECNT_A
value|25
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_PIXELASYNC_LITE_C_B
value|26
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_PIXELASYNC_LITE_C_A
value|27
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_PIXELASYNC_LITE_C_INIT_B
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_PIXELASYNC_LITE_C_INIT_A
value|29
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_CAM0_50
value|30
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CAM0_200
value|31
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CAM0_BUS_400
value|32
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_LITE_D
value|33
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_LITE_D
value|34
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_LITE_B
value|35
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_LITE_B
value|36
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_LITE_A
value|37
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_LITE_A
value|38
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CSIS1
value|39
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CSIS0
value|40
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_3AA1
value|41
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_3AA1
value|42
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_3AA0
value|43
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_3AA0
value|44
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_PIXELASYNC_LITE_C
value|45
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_PIXELASYNC_LITE_C
value|46
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_PIXELASYNC_LITE_C_INIT
value|47
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CSIS1
value|50
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CSIS0
value|51
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_3AA1
value|52
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_3AA0
value|53
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_LITE_D
value|54
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_LITE_B
value|55
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_LITE_A
value|56
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHBSYNCDN
value|57
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_LITE_D
value|58
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_LITE_B
value|59
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_LITE_A
value|60
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBM_3AA1
value|61
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBS_3AA1
value|62
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBM_3AA0
value|63
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBS_3AA0
value|64
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBM_LITE_D
value|65
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBS_LITE_D
value|66
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBM_LITE_B
value|67
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBS_LITE_B
value|68
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBM_LITE_A
value|69
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBS_LITE_A
value|70
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_ISP0P
value|71
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_3AA1
value|72
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_3AA1
value|73
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_3AA0
value|74
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_3AA0
value|75
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_LITE_D
value|76
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_LITE_D
value|77
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_LITE_B
value|78
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_LITE_B
value|79
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_LITE_A
value|80
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_LITE_A
value|81
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_ISPSFRP
value|82
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI2APB_ISP0P
value|83
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI2AHB_ISP0P
value|84
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_IS0X
value|85
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_ISP0EX
value|86
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM0NP_276
value|87
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM0ND_400
value|88
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_3AA1
value|89
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_3AA0
value|90
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_LITE_D
value|91
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_LITE_B
value|92
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_LITE_A
value|93
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_3AA1
value|94
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_3AA0
value|95
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_LITE_D
value|96
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_LITE_B
value|97
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_LITE_A
value|98
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_3AA1
value|99
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_3AA0
value|100
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_LITE_D
value|101
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_LITE_B
value|102
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_LITE_A
value|103
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_3AA1
value|104
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_3AA0
value|105
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_LITE_D
value|106
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_LITE_B
value|107
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_LITE_A
value|108
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_CAM1
value|109
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_3AA1
value|110
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_3AA0
value|111
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_LITE_D
value|112
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_LITE_B
value|113
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXI_LITE_A
value|114
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_CAM0
value|115
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_CAM0
value|116
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_CMU_CAM0_LOCAL
value|117
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_CSIS1
value|118
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_CSIS0
value|119
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_3AA1
value|120
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_3AA0
value|121
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_LITE_D
value|122
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_LITE_B
value|123
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_LITE_A
value|124
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_RXBYTECLKHS0_S4
value|125
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_RXBYTECLKHS0_S2A
value|126
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_LITE_FREECNT
value|127
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCM_3AA1
value|128
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCM_3AA0
value|129
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCS_3AA0
value|130
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCM_LITE_C
value|131
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCM_LITE_C_INIT
value|132
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCS_LITE_C_INIT
value|133
end_define

begin_define
define|#
directive|define
name|CAM0_NR_CLK
value|134
end_define

begin_comment
comment|/* CMU_CAM1 */
end_comment

begin_define
define|#
directive|define
name|CLK_PHYCLK_RXBYTEECLKHS0_S2B
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_ISP_UART_USER
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_ISP_SPI1_USER
value|3
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SCLK_ISP_SPI0_USER
value|4
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM1_333_USER
value|5
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM1_400_USER
value|6
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CAM1_552_USER
value|7
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PHYCLK_RXBYTECLKHS0_S2B_USER
value|8
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CSIS2_B
value|9
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_CSIS2_A
value|10
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_FD_B
value|11
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_FD_A
value|12
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_LITE_C_B
value|13
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_LITE_C_A
value|14
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SCLK_ISP_MPWM
value|15
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_CAM1_83
value|16
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_CAM1_166
value|17
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_DBG_CAM1
value|18
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ATCLK_CAM1
value|19
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_CSIS2
value|20
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_FD
value|21
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_FD
value|22
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_LITE_C
value|23
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_LITE_C
value|24
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ISP_GIC
value|25
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_FD
value|26
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_LITE_C
value|27
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CSIS2
value|28
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBM_FD
value|29
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBS_FD
value|30
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBM_LITE_C
value|31
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAPBS_LITE_C
value|32
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAHBS_SFRISP2H2
value|33
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAHBS_SFRISP2H1
value|34
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_CA5
value|35
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_CA5
value|36
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_ISPX2
value|37
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_ISPX1
value|38
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_ISPX0
value|39
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_ISPEX
value|40
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_ISP3P
value|41
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_ISP3P
value|42
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_FD
value|43
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_FD
value|44
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIM_LITE_C
value|45
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_ASYNCAXIS_LITE_C
value|46
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_ISP5P
value|47
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB2APB_ISP3P
value|48
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI2APB_ISP3P
value|49
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHB_SFRISP2H
value|50
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI_ISP_HX_R
value|51
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI_ISP_CX_R
value|52
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI_ISP_HX
value|53
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXI_ISP_CX
value|54
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_ISPX
value|55
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_XIU_ISPEX
value|56
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM1NP_333
value|57
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_CAM1ND_400
value|58
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_ISPCPU
value|59
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_FD
value|60
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_SMMU_LITE_C
value|61
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_ISP3P
value|62
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_FD
value|63
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_BTS_LITE_C
value|64
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHBDN_SFRISP2H
value|65
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AHBDN_ISP5P
value|66
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_ISP3P
value|67
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_FD
value|68
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_AXIUS_LITE_C
value|69
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_ISPCPU
value|70
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_FD
value|71
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SMMU_LITE_C
value|72
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_ISP3P
value|73
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_FD
value|74
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_BTS_LITE_C
value|75
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXIM_CA5
value|76
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXIM_ISPEX
value|77
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXIM_ISP3P
value|78
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXIM_FD
value|79
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ASYNCAXIM_LITE_C
value|80
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_PMU_CAM1
value|81
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_SYSREG_CAM1
value|82
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_CMU_CAM1_LOCAL
value|83
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_MCTADC
value|84
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_WDT
value|85
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_PWM
value|86
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_UART
value|87
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_MCUCTL
value|88
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_SPI1
value|89
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_SPI0
value|90
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_I2C2
value|91
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_I2C1
value|92
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_I2C0
value|93
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_ISP_MPWM
value|94
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_FD
value|95
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_LITE_C
value|96
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_CSIS2
value|97
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_I2C2
value|98
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_I2C1
value|99
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_I2C0
value|100
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_PWM
value|101
end_define

begin_define
define|#
directive|define
name|CLK_PHYCLK_RXBYTECLKHS0_S2B
value|102
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_LITE_C_FREECNT
value|103
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXELASYNCM_FD
value|104
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_MCTADC
value|105
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_UART
value|106
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SPI1
value|107
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SPI0
value|108
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_MPWM
value|109
end_define

begin_define
define|#
directive|define
name|CLK_PCLK_DBG_ISP
value|110
end_define

begin_define
define|#
directive|define
name|CLK_ATCLK_ISP
value|111
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_CA5
value|112
end_define

begin_define
define|#
directive|define
name|CAM1_NR_CLK
value|113
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_EXYNOS5433_H */
end_comment

end_unit

