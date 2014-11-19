begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Samsung Electronics Co., Ltd.  * Author: Rahul Sharma<rahul.sharma@samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Provides Constants for Exynos5260 clocks. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_EXYNOS5260_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_EXYNOS5260_H
end_define

begin_comment
comment|/* Clock names:<cmu><type><IP> */
end_comment

begin_comment
comment|/* List Of Clocks For CMU_TOP */
end_comment

begin_define
define|#
directive|define
name|TOP_FOUT_DISP_PLL
value|1
end_define

begin_define
define|#
directive|define
name|TOP_FOUT_AUD_PLL
value|2
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_AUDTOP_PLL_USER
value|3
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_AUD_PLL
value|4
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_DISP_PLL
value|5
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_BUSTOP_PLL_USER
value|6
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_MEMTOP_PLL_USER
value|7
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_MEDIATOP_PLL_USER
value|8
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_DISP_DISP_333
value|9
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ACLK_DISP_333
value|10
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_DISP_DISP_222
value|11
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ACLK_DISP_222
value|12
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_DISP_MEDIA_PIXEL
value|13
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_FIMD1
value|14
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_PERI_SPI0_CLK
value|15
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_PERI_SPI1_CLK
value|16
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_PERI_SPI2_CLK
value|17
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_PERI_UART0_UCLK
value|18
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_PERI_UART2_UCLK
value|19
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_PERI_UART1_UCLK
value|20
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_BUS4_BUSTOP_100
value|21
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_BUS4_BUSTOP_400
value|22
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_BUS3_BUSTOP_100
value|23
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_BUS3_BUSTOP_400
value|24
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_BUS2_BUSTOP_400
value|25
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_BUS2_BUSTOP_100
value|26
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_BUS1_BUSTOP_100
value|27
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_BUS1_BUSTOP_400
value|28
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_FSYS_USB
value|29
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_FSYS_MMC0_SDCLKIN_A
value|30
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_FSYS_MMC1_SDCLKIN_A
value|31
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_FSYS_MMC2_SDCLKIN_A
value|32
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_FSYS_MMC0_SDCLKIN_B
value|33
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_FSYS_MMC1_SDCLKIN_B
value|34
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_FSYS_MMC2_SDCLKIN_B
value|35
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ACLK_ISP1_266
value|36
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ISP1_MEDIA_266
value|37
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ACLK_ISP1_400
value|38
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ISP1_MEDIA_400
value|39
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_ISP1_SPI0
value|40
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_ISP1_SPI1
value|41
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_ISP1_UART
value|42
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_ISP1_SENSOR2
value|43
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_ISP1_SENSOR1
value|44
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_SCLK_ISP1_SENSOR0
value|45
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ACLK_MFC_333
value|46
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_MFC_BUSTOP_333
value|47
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ACLK_G2D_333
value|48
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_G2D_BUSTOP_333
value|49
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ACLK_GSCL_FIMC
value|50
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_GSCL_BUSTOP_FIMC
value|51
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ACLK_GSCL_333
value|52
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_GSCL_BUSTOP_333
value|53
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_ACLK_GSCL_400
value|54
end_define

begin_define
define|#
directive|define
name|TOP_MOUT_M2M_MEDIATOP_400
value|55
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_MFC_333
value|56
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_G2D_333
value|57
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SENSOR2_A
value|58
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SENSOR1_A
value|59
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SENSOR0_A
value|60
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_GSCL_FIMC
value|61
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_GSCL_400
value|62
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_GSCL_333
value|63
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SPI0_B
value|64
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SPI0_A
value|65
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_ISP1_400
value|66
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_ISP1_266
value|67
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_UART
value|68
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SPI1_B
value|69
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SPI1_A
value|70
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SENSOR2_B
value|71
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SENSOR1_B
value|72
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_ISP1_SENSOR0_B
value|73
end_define

begin_define
define|#
directive|define
name|TOP_DOUTTOP__SCLK_HPM_TARGETCLK
value|74
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_DISP_PIXEL
value|75
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_DISP_222
value|76
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_DISP_333
value|77
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_BUS4_100
value|78
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_BUS4_400
value|79
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_BUS3_100
value|80
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_BUS3_400
value|81
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_BUS2_100
value|82
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_BUS2_400
value|83
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_BUS1_100
value|84
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_BUS1_400
value|85
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_PERI_SPI1_B
value|86
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_PERI_SPI1_A
value|87
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_PERI_SPI0_B
value|88
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_PERI_SPI0_A
value|89
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_PERI_UART0
value|90
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_PERI_UART2
value|91
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_PERI_UART1
value|92
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_PERI_SPI2_B
value|93
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_PERI_SPI2_A
value|94
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_PERI_AUD
value|95
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_PERI_66
value|96
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_FSYS_MMC0_SDCLKIN_B
value|97
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_FSYS_MMC0_SDCLKIN_A
value|98
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_FSYS_USBDRD30_SUSPEND_CLK
value|99
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_ACLK_FSYS_200
value|100
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_FSYS_MMC2_SDCLKIN_B
value|101
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_FSYS_MMC2_SDCLKIN_A
value|102
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_FSYS_MMC1_SDCLKIN_B
value|103
end_define

begin_define
define|#
directive|define
name|TOP_DOUT_SCLK_FSYS_MMC1_SDCLKIN_A
value|104
end_define

begin_define
define|#
directive|define
name|TOP_SCLK_FIMD1
value|105
end_define

begin_define
define|#
directive|define
name|TOP_SCLK_MMC2
value|106
end_define

begin_define
define|#
directive|define
name|TOP_SCLK_MMC1
value|107
end_define

begin_define
define|#
directive|define
name|TOP_SCLK_MMC0
value|108
end_define

begin_define
define|#
directive|define
name|PHYCLK_DPTX_PHY_CH3_TXD_CLK
value|109
end_define

begin_define
define|#
directive|define
name|PHYCLK_DPTX_PHY_CH2_TXD_CLK
value|110
end_define

begin_define
define|#
directive|define
name|PHYCLK_DPTX_PHY_CH1_TXD_CLK
value|111
end_define

begin_define
define|#
directive|define
name|PHYCLK_DPTX_PHY_CH0_TXD_CLK
value|112
end_define

begin_define
define|#
directive|define
name|phyclk_hdmi_phy_tmds_clko
value|113
end_define

begin_define
define|#
directive|define
name|PHYCLK_HDMI_PHY_PIXEL_CLKO
value|114
end_define

begin_define
define|#
directive|define
name|PHYCLK_HDMI_LINK_O_TMDS_CLKHI
value|115
end_define

begin_define
define|#
directive|define
name|PHYCLK_MIPI_DPHY_4L_M_TXBYTECLKHS
value|116
end_define

begin_define
define|#
directive|define
name|PHYCLK_DPTX_PHY_O_REF_CLK_24M
value|117
end_define

begin_define
define|#
directive|define
name|PHYCLK_DPTX_PHY_CLK_DIV2
value|118
end_define

begin_define
define|#
directive|define
name|PHYCLK_MIPI_DPHY_4L_M_RXCLKESC0
value|119
end_define

begin_define
define|#
directive|define
name|PHYCLK_USBHOST20_PHY_PHYCLOCK
value|120
end_define

begin_define
define|#
directive|define
name|PHYCLK_USBHOST20_PHY_FREECLK
value|121
end_define

begin_define
define|#
directive|define
name|PHYCLK_USBHOST20_PHY_CLK48MOHCI
value|122
end_define

begin_define
define|#
directive|define
name|PHYCLK_USBDRD30_UDRD30_PIPE_PCLK
value|123
end_define

begin_define
define|#
directive|define
name|PHYCLK_USBDRD30_UDRD30_PHYCLOCK
value|124
end_define

begin_define
define|#
directive|define
name|TOP_NR_CLK
value|125
end_define

begin_comment
comment|/* List Of Clocks For CMU_EGL */
end_comment

begin_define
define|#
directive|define
name|EGL_FOUT_EGL_PLL
value|1
end_define

begin_define
define|#
directive|define
name|EGL_FOUT_EGL_DPLL
value|2
end_define

begin_define
define|#
directive|define
name|EGL_MOUT_EGL_B
value|3
end_define

begin_define
define|#
directive|define
name|EGL_MOUT_EGL_PLL
value|4
end_define

begin_define
define|#
directive|define
name|EGL_DOUT_EGL_PLL
value|5
end_define

begin_define
define|#
directive|define
name|EGL_DOUT_EGL_PCLK_DBG
value|6
end_define

begin_define
define|#
directive|define
name|EGL_DOUT_EGL_ATCLK
value|7
end_define

begin_define
define|#
directive|define
name|EGL_DOUT_PCLK_EGL
value|8
end_define

begin_define
define|#
directive|define
name|EGL_DOUT_ACLK_EGL
value|9
end_define

begin_define
define|#
directive|define
name|EGL_DOUT_EGL2
value|10
end_define

begin_define
define|#
directive|define
name|EGL_DOUT_EGL1
value|11
end_define

begin_define
define|#
directive|define
name|EGL_NR_CLK
value|12
end_define

begin_comment
comment|/* List Of Clocks For CMU_KFC */
end_comment

begin_define
define|#
directive|define
name|KFC_FOUT_KFC_PLL
value|1
end_define

begin_define
define|#
directive|define
name|KFC_MOUT_KFC_PLL
value|2
end_define

begin_define
define|#
directive|define
name|KFC_MOUT_KFC
value|3
end_define

begin_define
define|#
directive|define
name|KFC_DOUT_KFC_PLL
value|4
end_define

begin_define
define|#
directive|define
name|KFC_DOUT_PCLK_KFC
value|5
end_define

begin_define
define|#
directive|define
name|KFC_DOUT_ACLK_KFC
value|6
end_define

begin_define
define|#
directive|define
name|KFC_DOUT_KFC_PCLK_DBG
value|7
end_define

begin_define
define|#
directive|define
name|KFC_DOUT_KFC_ATCLK
value|8
end_define

begin_define
define|#
directive|define
name|KFC_DOUT_KFC2
value|9
end_define

begin_define
define|#
directive|define
name|KFC_DOUT_KFC1
value|10
end_define

begin_define
define|#
directive|define
name|KFC_NR_CLK
value|11
end_define

begin_comment
comment|/* List Of Clocks For CMU_MIF */
end_comment

begin_define
define|#
directive|define
name|MIF_FOUT_MEM_PLL
value|1
end_define

begin_define
define|#
directive|define
name|MIF_FOUT_MEDIA_PLL
value|2
end_define

begin_define
define|#
directive|define
name|MIF_FOUT_BUS_PLL
value|3
end_define

begin_define
define|#
directive|define
name|MIF_MOUT_CLK2X_PHY
value|4
end_define

begin_define
define|#
directive|define
name|MIF_MOUT_MIF_DREX2X
value|5
end_define

begin_define
define|#
directive|define
name|MIF_MOUT_CLKM_PHY
value|6
end_define

begin_define
define|#
directive|define
name|MIF_MOUT_MIF_DREX
value|7
end_define

begin_define
define|#
directive|define
name|MIF_MOUT_MEDIA_PLL
value|8
end_define

begin_define
define|#
directive|define
name|MIF_MOUT_BUS_PLL
value|9
end_define

begin_define
define|#
directive|define
name|MIF_MOUT_MEM_PLL
value|10
end_define

begin_define
define|#
directive|define
name|MIF_DOUT_ACLK_BUS_100
value|11
end_define

begin_define
define|#
directive|define
name|MIF_DOUT_ACLK_BUS_200
value|12
end_define

begin_define
define|#
directive|define
name|MIF_DOUT_ACLK_MIF_466
value|13
end_define

begin_define
define|#
directive|define
name|MIF_DOUT_CLK2X_PHY
value|14
end_define

begin_define
define|#
directive|define
name|MIF_DOUT_CLKM_PHY
value|15
end_define

begin_define
define|#
directive|define
name|MIF_DOUT_BUS_PLL
value|16
end_define

begin_define
define|#
directive|define
name|MIF_DOUT_MEM_PLL
value|17
end_define

begin_define
define|#
directive|define
name|MIF_DOUT_MEDIA_PLL
value|18
end_define

begin_define
define|#
directive|define
name|MIF_CLK_LPDDR3PHY_WRAP1
value|19
end_define

begin_define
define|#
directive|define
name|MIF_CLK_LPDDR3PHY_WRAP0
value|20
end_define

begin_define
define|#
directive|define
name|MIF_CLK_MONOCNT
value|21
end_define

begin_define
define|#
directive|define
name|MIF_CLK_MIF_RTC
value|22
end_define

begin_define
define|#
directive|define
name|MIF_CLK_DREX1
value|23
end_define

begin_define
define|#
directive|define
name|MIF_CLK_DREX0
value|24
end_define

begin_define
define|#
directive|define
name|MIF_CLK_INTMEM
value|25
end_define

begin_define
define|#
directive|define
name|MIF_SCLK_LPDDR3PHY_WRAP_U1
value|26
end_define

begin_define
define|#
directive|define
name|MIF_SCLK_LPDDR3PHY_WRAP_U0
value|27
end_define

begin_define
define|#
directive|define
name|MIF_NR_CLK
value|28
end_define

begin_comment
comment|/* List Of Clocks For CMU_G3D */
end_comment

begin_define
define|#
directive|define
name|G3D_FOUT_G3D_PLL
value|1
end_define

begin_define
define|#
directive|define
name|G3D_MOUT_G3D_PLL
value|2
end_define

begin_define
define|#
directive|define
name|G3D_DOUT_PCLK_G3D
value|3
end_define

begin_define
define|#
directive|define
name|G3D_DOUT_ACLK_G3D
value|4
end_define

begin_define
define|#
directive|define
name|G3D_CLK_G3D_HPM
value|5
end_define

begin_define
define|#
directive|define
name|G3D_CLK_G3D
value|6
end_define

begin_define
define|#
directive|define
name|G3D_NR_CLK
value|7
end_define

begin_comment
comment|/* List Of Clocks For CMU_AUD */
end_comment

begin_define
define|#
directive|define
name|AUD_MOUT_SCLK_AUD_PCM
value|1
end_define

begin_define
define|#
directive|define
name|AUD_MOUT_SCLK_AUD_I2S
value|2
end_define

begin_define
define|#
directive|define
name|AUD_MOUT_AUD_PLL_USER
value|3
end_define

begin_define
define|#
directive|define
name|AUD_DOUT_ACLK_AUD_131
value|4
end_define

begin_define
define|#
directive|define
name|AUD_DOUT_SCLK_AUD_UART
value|5
end_define

begin_define
define|#
directive|define
name|AUD_DOUT_SCLK_AUD_PCM
value|6
end_define

begin_define
define|#
directive|define
name|AUD_DOUT_SCLK_AUD_I2S
value|7
end_define

begin_define
define|#
directive|define
name|AUD_CLK_AUD_UART
value|8
end_define

begin_define
define|#
directive|define
name|AUD_CLK_PCM
value|9
end_define

begin_define
define|#
directive|define
name|AUD_CLK_I2S
value|10
end_define

begin_define
define|#
directive|define
name|AUD_CLK_DMAC
value|11
end_define

begin_define
define|#
directive|define
name|AUD_CLK_SRAMC
value|12
end_define

begin_define
define|#
directive|define
name|AUD_SCLK_AUD_UART
value|13
end_define

begin_define
define|#
directive|define
name|AUD_SCLK_PCM
value|14
end_define

begin_define
define|#
directive|define
name|AUD_SCLK_I2S
value|15
end_define

begin_define
define|#
directive|define
name|AUD_NR_CLK
value|16
end_define

begin_comment
comment|/* List Of Clocks For CMU_MFC */
end_comment

begin_define
define|#
directive|define
name|MFC_MOUT_ACLK_MFC_333_USER
value|1
end_define

begin_define
define|#
directive|define
name|MFC_DOUT_PCLK_MFC_83
value|2
end_define

begin_define
define|#
directive|define
name|MFC_CLK_MFC
value|3
end_define

begin_define
define|#
directive|define
name|MFC_CLK_SMMU2_MFCM1
value|4
end_define

begin_define
define|#
directive|define
name|MFC_CLK_SMMU2_MFCM0
value|5
end_define

begin_define
define|#
directive|define
name|MFC_NR_CLK
value|6
end_define

begin_comment
comment|/* List Of Clocks For CMU_GSCL */
end_comment

begin_define
define|#
directive|define
name|GSCL_MOUT_ACLK_CSIS
value|1
end_define

begin_define
define|#
directive|define
name|GSCL_MOUT_ACLK_GSCL_FIMC_USER
value|2
end_define

begin_define
define|#
directive|define
name|GSCL_MOUT_ACLK_M2M_400_USER
value|3
end_define

begin_define
define|#
directive|define
name|GSCL_MOUT_ACLK_GSCL_333_USER
value|4
end_define

begin_define
define|#
directive|define
name|GSCL_DOUT_ACLK_CSIS_200
value|5
end_define

begin_define
define|#
directive|define
name|GSCL_DOUT_PCLK_M2M_100
value|6
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_PIXEL_GSCL1
value|7
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_PIXEL_GSCL0
value|8
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_MSCL1
value|9
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_MSCL0
value|10
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_GSCL1
value|11
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_GSCL0
value|12
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_FIMC_LITE_D
value|13
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_FIMC_LITE_B
value|14
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_FIMC_LITE_A
value|15
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_CSIS1
value|16
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_CSIS0
value|17
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_SMMU3_LITE_D
value|18
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_SMMU3_LITE_B
value|19
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_SMMU3_LITE_A
value|20
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_SMMU3_GSCL0
value|21
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_SMMU3_GSCL1
value|22
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_SMMU3_MSCL0
value|23
end_define

begin_define
define|#
directive|define
name|GSCL_CLK_SMMU3_MSCL1
value|24
end_define

begin_define
define|#
directive|define
name|GSCL_SCLK_CSIS1_WRAP
value|25
end_define

begin_define
define|#
directive|define
name|GSCL_SCLK_CSIS0_WRAP
value|26
end_define

begin_define
define|#
directive|define
name|GSCL_NR_CLK
value|27
end_define

begin_comment
comment|/* List Of Clocks For CMU_FSYS */
end_comment

begin_define
define|#
directive|define
name|FSYS_MOUT_PHYCLK_USBHOST20_PHYCLK_USER
value|1
end_define

begin_define
define|#
directive|define
name|FSYS_MOUT_PHYCLK_USBHOST20_FREECLK_USER
value|2
end_define

begin_define
define|#
directive|define
name|FSYS_MOUT_PHYCLK_USBHOST20_CLK48MOHCI_USER
value|3
end_define

begin_define
define|#
directive|define
name|FSYS_MOUT_PHYCLK_USBDRD30_PIPE_PCLK_USER
value|4
end_define

begin_define
define|#
directive|define
name|FSYS_MOUT_PHYCLK_USBDRD30_PHYCLOCK_USER
value|5
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_TSI
value|6
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_USBLINK
value|7
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_USBHOST20
value|8
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_USBDRD30
value|9
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_SROMC
value|10
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_PDMA
value|11
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_MMC2
value|12
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_MMC1
value|13
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_MMC0
value|14
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_RTIC
value|15
end_define

begin_define
define|#
directive|define
name|FSYS_CLK_SMMU_RTIC
value|16
end_define

begin_define
define|#
directive|define
name|FSYS_PHYCLK_USBDRD30
value|17
end_define

begin_define
define|#
directive|define
name|FSYS_PHYCLK_USBHOST20
value|18
end_define

begin_define
define|#
directive|define
name|FSYS_NR_CLK
value|19
end_define

begin_comment
comment|/* List Of Clocks For CMU_PERI */
end_comment

begin_define
define|#
directive|define
name|PERI_MOUT_SCLK_SPDIF
value|1
end_define

begin_define
define|#
directive|define
name|PERI_MOUT_SCLK_I2SCOD
value|2
end_define

begin_define
define|#
directive|define
name|PERI_MOUT_SCLK_PCM
value|3
end_define

begin_define
define|#
directive|define
name|PERI_DOUT_I2S
value|4
end_define

begin_define
define|#
directive|define
name|PERI_DOUT_PCM
value|5
end_define

begin_define
define|#
directive|define
name|PERI_CLK_WDT_KFC
value|6
end_define

begin_define
define|#
directive|define
name|PERI_CLK_WDT_EGL
value|7
end_define

begin_define
define|#
directive|define
name|PERI_CLK_HSIC3
value|8
end_define

begin_define
define|#
directive|define
name|PERI_CLK_HSIC2
value|9
end_define

begin_define
define|#
directive|define
name|PERI_CLK_HSIC1
value|10
end_define

begin_define
define|#
directive|define
name|PERI_CLK_HSIC0
value|11
end_define

begin_define
define|#
directive|define
name|PERI_CLK_PCM
value|12
end_define

begin_define
define|#
directive|define
name|PERI_CLK_MCT
value|13
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2S
value|14
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2CHDMI
value|15
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2C7
value|16
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2C6
value|17
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2C5
value|18
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2C4
value|19
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2C9
value|20
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2C8
value|21
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2C11
value|22
end_define

begin_define
define|#
directive|define
name|PERI_CLK_I2C10
value|23
end_define

begin_define
define|#
directive|define
name|PERI_CLK_HDMICEC
value|24
end_define

begin_define
define|#
directive|define
name|PERI_CLK_EFUSE_WRITER
value|25
end_define

begin_define
define|#
directive|define
name|PERI_CLK_ABB
value|26
end_define

begin_define
define|#
directive|define
name|PERI_CLK_UART2
value|27
end_define

begin_define
define|#
directive|define
name|PERI_CLK_UART1
value|28
end_define

begin_define
define|#
directive|define
name|PERI_CLK_UART0
value|29
end_define

begin_define
define|#
directive|define
name|PERI_CLK_ADC
value|30
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TMU4
value|31
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TMU3
value|32
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TMU2
value|33
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TMU1
value|34
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TMU0
value|35
end_define

begin_define
define|#
directive|define
name|PERI_CLK_SPI2
value|36
end_define

begin_define
define|#
directive|define
name|PERI_CLK_SPI1
value|37
end_define

begin_define
define|#
directive|define
name|PERI_CLK_SPI0
value|38
end_define

begin_define
define|#
directive|define
name|PERI_CLK_SPDIF
value|39
end_define

begin_define
define|#
directive|define
name|PERI_CLK_PWM
value|40
end_define

begin_define
define|#
directive|define
name|PERI_CLK_UART4
value|41
end_define

begin_define
define|#
directive|define
name|PERI_CLK_CHIPID
value|42
end_define

begin_define
define|#
directive|define
name|PERI_CLK_PROVKEY0
value|43
end_define

begin_define
define|#
directive|define
name|PERI_CLK_PROVKEY1
value|44
end_define

begin_define
define|#
directive|define
name|PERI_CLK_SECKEY
value|45
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TOP_RTC
value|46
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC10
value|47
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC9
value|48
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC8
value|49
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC7
value|50
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC6
value|51
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC5
value|52
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC4
value|53
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC3
value|54
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC2
value|55
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC1
value|56
end_define

begin_define
define|#
directive|define
name|PERI_CLK_TZPC0
value|57
end_define

begin_define
define|#
directive|define
name|PERI_SCLK_UART2
value|58
end_define

begin_define
define|#
directive|define
name|PERI_SCLK_UART1
value|59
end_define

begin_define
define|#
directive|define
name|PERI_SCLK_UART0
value|60
end_define

begin_define
define|#
directive|define
name|PERI_SCLK_SPI2
value|61
end_define

begin_define
define|#
directive|define
name|PERI_SCLK_SPI1
value|62
end_define

begin_define
define|#
directive|define
name|PERI_SCLK_SPI0
value|63
end_define

begin_define
define|#
directive|define
name|PERI_SCLK_SPDIF
value|64
end_define

begin_define
define|#
directive|define
name|PERI_SCLK_I2S
value|65
end_define

begin_define
define|#
directive|define
name|PERI_SCLK_PCM1
value|66
end_define

begin_define
define|#
directive|define
name|PERI_NR_CLK
value|67
end_define

begin_comment
comment|/* List Of Clocks For CMU_DISP */
end_comment

begin_define
define|#
directive|define
name|DISP_MOUT_SCLK_HDMI_SPDIF
value|1
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_SCLK_HDMI_PIXEL
value|2
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_MIPI_DPHY_4LMRXCLK_ESC0_USER
value|3
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_HDMI_PHY_TMDS_CLKO_USER
value|4
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_HDMI_PHY_REF_CLKO_USER
value|5
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_HDMI_PHY_PIXEL
value|6
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_HDMI_LINK_O_TMDS_CLKHI_USER
value|7
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_MIPI_DPHY_4L_M_TXBYTE_CLKHS
value|8
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_DPTX_PHY_O_REF_CLK_24M_USER
value|9
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_DPTX_PHY_CLK_DIV2_USER
value|10
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_DPTX_PHY_CH3_TXD_CLK_USER
value|11
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_DPTX_PHY_CH2_TXD_CLK_USER
value|12
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_DPTX_PHY_CH1_TXD_CLK_USER
value|13
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_PHYCLK_DPTX_PHY_CH0_TXD_CLK_USER
value|14
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_ACLK_DISP_222_USER
value|15
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_SCLK_DISP_PIXEL_USER
value|16
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_ACLK_DISP_333_USER
value|17
end_define

begin_define
define|#
directive|define
name|DISP_DOUT_SCLK_HDMI_PHY_PIXEL_CLKI
value|18
end_define

begin_define
define|#
directive|define
name|DISP_DOUT_SCLK_FIMD1_EXTCLKPLL
value|19
end_define

begin_define
define|#
directive|define
name|DISP_DOUT_PCLK_DISP_111
value|20
end_define

begin_define
define|#
directive|define
name|DISP_CLK_SMMU_TV
value|21
end_define

begin_define
define|#
directive|define
name|DISP_CLK_SMMU_FIMD1M1
value|22
end_define

begin_define
define|#
directive|define
name|DISP_CLK_SMMU_FIMD1M0
value|23
end_define

begin_define
define|#
directive|define
name|DISP_CLK_PIXEL_MIXER
value|24
end_define

begin_define
define|#
directive|define
name|DISP_CLK_PIXEL_DISP
value|25
end_define

begin_define
define|#
directive|define
name|DISP_CLK_MIXER
value|26
end_define

begin_define
define|#
directive|define
name|DISP_CLK_MIPIPHY
value|27
end_define

begin_define
define|#
directive|define
name|DISP_CLK_HDMIPHY
value|28
end_define

begin_define
define|#
directive|define
name|DISP_CLK_HDMI
value|29
end_define

begin_define
define|#
directive|define
name|DISP_CLK_FIMD1
value|30
end_define

begin_define
define|#
directive|define
name|DISP_CLK_DSIM1
value|31
end_define

begin_define
define|#
directive|define
name|DISP_CLK_DPPHY
value|32
end_define

begin_define
define|#
directive|define
name|DISP_CLK_DP
value|33
end_define

begin_define
define|#
directive|define
name|DISP_SCLK_PIXEL
value|34
end_define

begin_define
define|#
directive|define
name|DISP_MOUT_HDMI_PHY_PIXEL_USER
value|35
end_define

begin_define
define|#
directive|define
name|DISP_NR_CLK
value|36
end_define

begin_comment
comment|/* List Of Clocks For CMU_G2D */
end_comment

begin_define
define|#
directive|define
name|G2D_MOUT_ACLK_G2D_333_USER
value|1
end_define

begin_define
define|#
directive|define
name|G2D_DOUT_PCLK_G2D_83
value|2
end_define

begin_define
define|#
directive|define
name|G2D_CLK_SMMU3_JPEG
value|3
end_define

begin_define
define|#
directive|define
name|G2D_CLK_MDMA
value|4
end_define

begin_define
define|#
directive|define
name|G2D_CLK_JPEG
value|5
end_define

begin_define
define|#
directive|define
name|G2D_CLK_G2D
value|6
end_define

begin_define
define|#
directive|define
name|G2D_CLK_SSS
value|7
end_define

begin_define
define|#
directive|define
name|G2D_CLK_SLIM_SSS
value|8
end_define

begin_define
define|#
directive|define
name|G2D_CLK_SMMU_SLIM_SSS
value|9
end_define

begin_define
define|#
directive|define
name|G2D_CLK_SMMU_SSS
value|10
end_define

begin_define
define|#
directive|define
name|G2D_CLK_SMMU_MDMA
value|11
end_define

begin_define
define|#
directive|define
name|G2D_CLK_SMMU3_G2D
value|12
end_define

begin_define
define|#
directive|define
name|G2D_NR_CLK
value|13
end_define

begin_comment
comment|/* List Of Clocks For CMU_ISP */
end_comment

begin_define
define|#
directive|define
name|ISP_MOUT_ISP_400_USER
value|1
end_define

begin_define
define|#
directive|define
name|ISP_MOUT_ISP_266_USER
value|2
end_define

begin_define
define|#
directive|define
name|ISP_DOUT_SCLK_MPWM
value|3
end_define

begin_define
define|#
directive|define
name|ISP_DOUT_CA5_PCLKDBG
value|4
end_define

begin_define
define|#
directive|define
name|ISP_DOUT_CA5_ATCLKIN
value|5
end_define

begin_define
define|#
directive|define
name|ISP_DOUT_PCLK_ISP_133
value|6
end_define

begin_define
define|#
directive|define
name|ISP_DOUT_PCLK_ISP_66
value|7
end_define

begin_define
define|#
directive|define
name|ISP_CLK_GIC
value|8
end_define

begin_define
define|#
directive|define
name|ISP_CLK_WDT
value|9
end_define

begin_define
define|#
directive|define
name|ISP_CLK_UART
value|10
end_define

begin_define
define|#
directive|define
name|ISP_CLK_SPI1
value|11
end_define

begin_define
define|#
directive|define
name|ISP_CLK_SPI0
value|12
end_define

begin_define
define|#
directive|define
name|ISP_CLK_SMMU_SCALERP
value|13
end_define

begin_define
define|#
directive|define
name|ISP_CLK_SMMU_SCALERC
value|14
end_define

begin_define
define|#
directive|define
name|ISP_CLK_SMMU_ISPCX
value|15
end_define

begin_define
define|#
directive|define
name|ISP_CLK_SMMU_ISP
value|16
end_define

begin_define
define|#
directive|define
name|ISP_CLK_SMMU_FD
value|17
end_define

begin_define
define|#
directive|define
name|ISP_CLK_SMMU_DRC
value|18
end_define

begin_define
define|#
directive|define
name|ISP_CLK_PWM
value|19
end_define

begin_define
define|#
directive|define
name|ISP_CLK_MTCADC
value|20
end_define

begin_define
define|#
directive|define
name|ISP_CLK_MPWM
value|21
end_define

begin_define
define|#
directive|define
name|ISP_CLK_MCUCTL
value|22
end_define

begin_define
define|#
directive|define
name|ISP_CLK_I2C1
value|23
end_define

begin_define
define|#
directive|define
name|ISP_CLK_I2C0
value|24
end_define

begin_define
define|#
directive|define
name|ISP_CLK_FIMC_SCALERP
value|25
end_define

begin_define
define|#
directive|define
name|ISP_CLK_FIMC_SCALERC
value|26
end_define

begin_define
define|#
directive|define
name|ISP_CLK_FIMC
value|27
end_define

begin_define
define|#
directive|define
name|ISP_CLK_FIMC_FD
value|28
end_define

begin_define
define|#
directive|define
name|ISP_CLK_FIMC_DRC
value|29
end_define

begin_define
define|#
directive|define
name|ISP_CLK_CA5
value|30
end_define

begin_define
define|#
directive|define
name|ISP_SCLK_SPI0_EXT
value|31
end_define

begin_define
define|#
directive|define
name|ISP_SCLK_SPI1_EXT
value|32
end_define

begin_define
define|#
directive|define
name|ISP_SCLK_UART_EXT
value|33
end_define

begin_define
define|#
directive|define
name|ISP_NR_CLK
value|34
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

