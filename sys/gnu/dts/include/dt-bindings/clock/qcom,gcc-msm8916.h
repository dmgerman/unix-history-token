begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2015 Linaro Limited  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MSM_GCC_8916_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MSM_GCC_8916_H
end_define

begin_define
define|#
directive|define
name|GPLL0
value|0
end_define

begin_define
define|#
directive|define
name|GPLL0_VOTE
value|1
end_define

begin_define
define|#
directive|define
name|BIMC_PLL
value|2
end_define

begin_define
define|#
directive|define
name|BIMC_PLL_VOTE
value|3
end_define

begin_define
define|#
directive|define
name|GPLL1
value|4
end_define

begin_define
define|#
directive|define
name|GPLL1_VOTE
value|5
end_define

begin_define
define|#
directive|define
name|GPLL2
value|6
end_define

begin_define
define|#
directive|define
name|GPLL2_VOTE
value|7
end_define

begin_define
define|#
directive|define
name|PCNOC_BFDCD_CLK_SRC
value|8
end_define

begin_define
define|#
directive|define
name|SYSTEM_NOC_BFDCD_CLK_SRC
value|9
end_define

begin_define
define|#
directive|define
name|CAMSS_AHB_CLK_SRC
value|10
end_define

begin_define
define|#
directive|define
name|APSS_AHB_CLK_SRC
value|11
end_define

begin_define
define|#
directive|define
name|CSI0_CLK_SRC
value|12
end_define

begin_define
define|#
directive|define
name|CSI1_CLK_SRC
value|13
end_define

begin_define
define|#
directive|define
name|GFX3D_CLK_SRC
value|14
end_define

begin_define
define|#
directive|define
name|VFE0_CLK_SRC
value|15
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_I2C_APPS_CLK_SRC
value|16
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_SPI_APPS_CLK_SRC
value|17
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_I2C_APPS_CLK_SRC
value|18
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_SPI_APPS_CLK_SRC
value|19
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP3_I2C_APPS_CLK_SRC
value|20
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP3_SPI_APPS_CLK_SRC
value|21
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_I2C_APPS_CLK_SRC
value|22
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_SPI_APPS_CLK_SRC
value|23
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_I2C_APPS_CLK_SRC
value|24
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_SPI_APPS_CLK_SRC
value|25
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_I2C_APPS_CLK_SRC
value|26
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_SPI_APPS_CLK_SRC
value|27
end_define

begin_define
define|#
directive|define
name|BLSP1_UART1_APPS_CLK_SRC
value|28
end_define

begin_define
define|#
directive|define
name|BLSP1_UART2_APPS_CLK_SRC
value|29
end_define

begin_define
define|#
directive|define
name|CCI_CLK_SRC
value|30
end_define

begin_define
define|#
directive|define
name|CAMSS_GP0_CLK_SRC
value|31
end_define

begin_define
define|#
directive|define
name|CAMSS_GP1_CLK_SRC
value|32
end_define

begin_define
define|#
directive|define
name|JPEG0_CLK_SRC
value|33
end_define

begin_define
define|#
directive|define
name|MCLK0_CLK_SRC
value|34
end_define

begin_define
define|#
directive|define
name|MCLK1_CLK_SRC
value|35
end_define

begin_define
define|#
directive|define
name|CSI0PHYTIMER_CLK_SRC
value|36
end_define

begin_define
define|#
directive|define
name|CSI1PHYTIMER_CLK_SRC
value|37
end_define

begin_define
define|#
directive|define
name|CPP_CLK_SRC
value|38
end_define

begin_define
define|#
directive|define
name|CRYPTO_CLK_SRC
value|39
end_define

begin_define
define|#
directive|define
name|GP1_CLK_SRC
value|40
end_define

begin_define
define|#
directive|define
name|GP2_CLK_SRC
value|41
end_define

begin_define
define|#
directive|define
name|GP3_CLK_SRC
value|42
end_define

begin_define
define|#
directive|define
name|BYTE0_CLK_SRC
value|43
end_define

begin_define
define|#
directive|define
name|ESC0_CLK_SRC
value|44
end_define

begin_define
define|#
directive|define
name|MDP_CLK_SRC
value|45
end_define

begin_define
define|#
directive|define
name|PCLK0_CLK_SRC
value|46
end_define

begin_define
define|#
directive|define
name|VSYNC_CLK_SRC
value|47
end_define

begin_define
define|#
directive|define
name|PDM2_CLK_SRC
value|48
end_define

begin_define
define|#
directive|define
name|SDCC1_APPS_CLK_SRC
value|49
end_define

begin_define
define|#
directive|define
name|SDCC2_APPS_CLK_SRC
value|50
end_define

begin_define
define|#
directive|define
name|APSS_TCU_CLK_SRC
value|51
end_define

begin_define
define|#
directive|define
name|USB_HS_SYSTEM_CLK_SRC
value|52
end_define

begin_define
define|#
directive|define
name|VCODEC0_CLK_SRC
value|53
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_AHB_CLK
value|54
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_SLEEP_CLK
value|55
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_I2C_APPS_CLK
value|56
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_SPI_APPS_CLK
value|57
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_I2C_APPS_CLK
value|58
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_SPI_APPS_CLK
value|59
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_I2C_APPS_CLK
value|60
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_SPI_APPS_CLK
value|61
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_I2C_APPS_CLK
value|62
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_SPI_APPS_CLK
value|63
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_I2C_APPS_CLK
value|64
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_SPI_APPS_CLK
value|65
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_I2C_APPS_CLK
value|66
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_SPI_APPS_CLK
value|67
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART1_APPS_CLK
value|68
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_APPS_CLK
value|69
end_define

begin_define
define|#
directive|define
name|GCC_BOOT_ROM_AHB_CLK
value|70
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CCI_AHB_CLK
value|71
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CCI_CLK
value|72
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI0_AHB_CLK
value|73
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI0_CLK
value|74
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI0PHY_CLK
value|75
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI0PIX_CLK
value|76
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI0RDI_CLK
value|77
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI1_AHB_CLK
value|78
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI1_CLK
value|79
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI1PHY_CLK
value|80
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI1PIX_CLK
value|81
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI1RDI_CLK
value|82
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI_VFE0_CLK
value|83
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_GP0_CLK
value|84
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_GP1_CLK
value|85
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_ISPIF_AHB_CLK
value|86
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_JPEG0_CLK
value|87
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_JPEG_AHB_CLK
value|88
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_JPEG_AXI_CLK
value|89
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_MCLK0_CLK
value|90
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_MCLK1_CLK
value|91
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_MICRO_AHB_CLK
value|92
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI0PHYTIMER_CLK
value|93
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CSI1PHYTIMER_CLK
value|94
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_AHB_CLK
value|95
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_TOP_AHB_CLK
value|96
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CPP_AHB_CLK
value|97
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_CPP_CLK
value|98
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_VFE0_CLK
value|99
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_VFE_AHB_CLK
value|100
end_define

begin_define
define|#
directive|define
name|GCC_CAMSS_VFE_AXI_CLK
value|101
end_define

begin_define
define|#
directive|define
name|GCC_CRYPTO_AHB_CLK
value|102
end_define

begin_define
define|#
directive|define
name|GCC_CRYPTO_AXI_CLK
value|103
end_define

begin_define
define|#
directive|define
name|GCC_CRYPTO_CLK
value|104
end_define

begin_define
define|#
directive|define
name|GCC_OXILI_GMEM_CLK
value|105
end_define

begin_define
define|#
directive|define
name|GCC_GP1_CLK
value|106
end_define

begin_define
define|#
directive|define
name|GCC_GP2_CLK
value|107
end_define

begin_define
define|#
directive|define
name|GCC_GP3_CLK
value|108
end_define

begin_define
define|#
directive|define
name|GCC_MDSS_AHB_CLK
value|109
end_define

begin_define
define|#
directive|define
name|GCC_MDSS_AXI_CLK
value|110
end_define

begin_define
define|#
directive|define
name|GCC_MDSS_BYTE0_CLK
value|111
end_define

begin_define
define|#
directive|define
name|GCC_MDSS_ESC0_CLK
value|112
end_define

begin_define
define|#
directive|define
name|GCC_MDSS_MDP_CLK
value|113
end_define

begin_define
define|#
directive|define
name|GCC_MDSS_PCLK0_CLK
value|114
end_define

begin_define
define|#
directive|define
name|GCC_MDSS_VSYNC_CLK
value|115
end_define

begin_define
define|#
directive|define
name|GCC_MSS_CFG_AHB_CLK
value|116
end_define

begin_define
define|#
directive|define
name|GCC_OXILI_AHB_CLK
value|117
end_define

begin_define
define|#
directive|define
name|GCC_OXILI_GFX3D_CLK
value|118
end_define

begin_define
define|#
directive|define
name|GCC_PDM2_CLK
value|119
end_define

begin_define
define|#
directive|define
name|GCC_PDM_AHB_CLK
value|120
end_define

begin_define
define|#
directive|define
name|GCC_PRNG_AHB_CLK
value|121
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_AHB_CLK
value|122
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_APPS_CLK
value|123
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_AHB_CLK
value|124
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_APPS_CLK
value|125
end_define

begin_define
define|#
directive|define
name|GCC_GTCU_AHB_CLK
value|126
end_define

begin_define
define|#
directive|define
name|GCC_JPEG_TBU_CLK
value|127
end_define

begin_define
define|#
directive|define
name|GCC_MDP_TBU_CLK
value|128
end_define

begin_define
define|#
directive|define
name|GCC_SMMU_CFG_CLK
value|129
end_define

begin_define
define|#
directive|define
name|GCC_VENUS_TBU_CLK
value|130
end_define

begin_define
define|#
directive|define
name|GCC_VFE_TBU_CLK
value|131
end_define

begin_define
define|#
directive|define
name|GCC_USB2A_PHY_SLEEP_CLK
value|132
end_define

begin_define
define|#
directive|define
name|GCC_USB_HS_AHB_CLK
value|133
end_define

begin_define
define|#
directive|define
name|GCC_USB_HS_SYSTEM_CLK
value|134
end_define

begin_define
define|#
directive|define
name|GCC_VENUS0_AHB_CLK
value|135
end_define

begin_define
define|#
directive|define
name|GCC_VENUS0_AXI_CLK
value|136
end_define

begin_define
define|#
directive|define
name|GCC_VENUS0_VCODEC0_CLK
value|137
end_define

begin_define
define|#
directive|define
name|BIMC_DDR_CLK_SRC
value|138
end_define

begin_define
define|#
directive|define
name|GCC_APSS_TCU_CLK
value|139
end_define

begin_define
define|#
directive|define
name|GCC_GFX_TCU_CLK
value|140
end_define

begin_define
define|#
directive|define
name|BIMC_GPU_CLK_SRC
value|141
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_GFX_CLK
value|142
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_GPU_CLK
value|143
end_define

begin_define
define|#
directive|define
name|ULTAUDIO_LPAIF_PRI_I2S_CLK_SRC
value|144
end_define

begin_define
define|#
directive|define
name|ULTAUDIO_LPAIF_SEC_I2S_CLK_SRC
value|145
end_define

begin_define
define|#
directive|define
name|ULTAUDIO_LPAIF_AUX_I2S_CLK_SRC
value|146
end_define

begin_define
define|#
directive|define
name|ULTAUDIO_XO_CLK_SRC
value|147
end_define

begin_define
define|#
directive|define
name|ULTAUDIO_AHBFABRIC_CLK_SRC
value|148
end_define

begin_define
define|#
directive|define
name|CODEC_DIGCODEC_CLK_SRC
value|149
end_define

begin_define
define|#
directive|define
name|GCC_ULTAUDIO_PCNOC_MPORT_CLK
value|150
end_define

begin_define
define|#
directive|define
name|GCC_ULTAUDIO_PCNOC_SWAY_CLK
value|151
end_define

begin_define
define|#
directive|define
name|GCC_ULTAUDIO_AVSYNC_XO_CLK
value|152
end_define

begin_define
define|#
directive|define
name|GCC_ULTAUDIO_STC_XO_CLK
value|153
end_define

begin_define
define|#
directive|define
name|GCC_ULTAUDIO_AHBFABRIC_IXFABRIC_CLK
value|154
end_define

begin_define
define|#
directive|define
name|GCC_ULTAUDIO_AHBFABRIC_IXFABRIC_LPM_CLK
value|155
end_define

begin_define
define|#
directive|define
name|GCC_ULTAUDIO_LPAIF_PRI_I2S_CLK
value|156
end_define

begin_define
define|#
directive|define
name|GCC_ULTAUDIO_LPAIF_SEC_I2S_CLK
value|157
end_define

begin_define
define|#
directive|define
name|GCC_ULTAUDIO_LPAIF_AUX_I2S_CLK
value|158
end_define

begin_define
define|#
directive|define
name|GCC_CODEC_DIGCODEC_CLK
value|159
end_define

begin_comment
comment|/* Indexes for GDSCs */
end_comment

begin_define
define|#
directive|define
name|BIMC_GDSC
value|0
end_define

begin_define
define|#
directive|define
name|VENUS_GDSC
value|1
end_define

begin_define
define|#
directive|define
name|MDSS_GDSC
value|2
end_define

begin_define
define|#
directive|define
name|JPEG_GDSC
value|3
end_define

begin_define
define|#
directive|define
name|VFE_GDSC
value|4
end_define

begin_define
define|#
directive|define
name|OXILI_GDSC
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

