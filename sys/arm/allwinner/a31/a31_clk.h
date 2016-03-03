begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ganbold Tsagaankhuu<ganbold@freebsd.org>  * Copyright (c) 2016 Emmanuel Vadot<manu@bidouilliste.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_A31_CLK_H_
end_ifndef

begin_define
define|#
directive|define
name|_A31_CLK_H_
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL1_CFG
value|0x0000
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL2_CFG
value|0x0008
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL3_CFG
value|0x0010
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL4_CFG
value|0x0018
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL5_CFG
value|0x0020
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL6_CFG
value|0x0028
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL7_CFG
value|0x0030
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL8_CFG
value|0x0038
end_define

begin_define
define|#
directive|define
name|A31_CCM_MIPI_PLL_CFG
value|0x0040
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL9_CFG
value|0x0044
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL10_CFG
value|0x0048
end_define

begin_define
define|#
directive|define
name|A31_CCM_AXI_CFG_REG
value|0x0050
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_APB1_CFG
value|0x0054
end_define

begin_define
define|#
directive|define
name|A31_CCM_APB2_CLK_DIV
value|0x0058
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING0
value|0x0060
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING1
value|0x0064
end_define

begin_define
define|#
directive|define
name|A31_CCM_APB1_GATING
value|0x0068
end_define

begin_define
define|#
directive|define
name|A31_CCM_APB2_GATING
value|0x006c
end_define

begin_define
define|#
directive|define
name|A31_CCM_NAND0_SCLK_CFG
value|0x0080
end_define

begin_define
define|#
directive|define
name|A31_CCM_NAND1_SCLK_CFG
value|0x0084
end_define

begin_define
define|#
directive|define
name|A31_CCM_MMC0_SCLK_CFG
value|0x0088
end_define

begin_define
define|#
directive|define
name|A31_CCM_MMC1_SCLK_CFG
value|0x008c
end_define

begin_define
define|#
directive|define
name|A31_CCM_MMC2_SCLK_CFG
value|0x0090
end_define

begin_define
define|#
directive|define
name|A31_CCM_MMC3_SCLK_CFG
value|0x0094
end_define

begin_define
define|#
directive|define
name|A31_CCM_TS_CLK
value|0x0098
end_define

begin_define
define|#
directive|define
name|A31_CCM_SS_CLK
value|0x009c
end_define

begin_define
define|#
directive|define
name|A31_CCM_SPI0_CLK
value|0x00a0
end_define

begin_define
define|#
directive|define
name|A31_CCM_SPI1_CLK
value|0x00a4
end_define

begin_define
define|#
directive|define
name|A31_CCM_SPI2_CLK
value|0x00a8
end_define

begin_define
define|#
directive|define
name|A31_CCM_SPI3_CLK
value|0x00ac
end_define

begin_define
define|#
directive|define
name|A31_CCM_DAUDIO0_CLK
value|0x00b0
end_define

begin_define
define|#
directive|define
name|A31_CCM_DAUDIO1_CLK
value|0x00b4
end_define

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK
value|0x00cc
end_define

begin_define
define|#
directive|define
name|A31_CCM_GMAC_CLK
value|0x00d0
end_define

begin_define
define|#
directive|define
name|A31_CCM_MDFS_CLK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|A31_CCM_DRAM_CLK
value|0x00f4
end_define

begin_define
define|#
directive|define
name|A31_CCM_DRAM_GATING
value|0x0100
end_define

begin_define
define|#
directive|define
name|A31_CCM_BE0_SCLK
value|0x0104
end_define

begin_define
define|#
directive|define
name|A31_CCM_BE1_SCLK
value|0x0108
end_define

begin_define
define|#
directive|define
name|A31_CCM_FE0_CLK
value|0x010c
end_define

begin_define
define|#
directive|define
name|A31_CCM_FE1_CLK
value|0x0110
end_define

begin_define
define|#
directive|define
name|A31_CCM_MP_CLK
value|0x0114
end_define

begin_define
define|#
directive|define
name|A31_CCM_LCD0_CH0_CLK
value|0x0118
end_define

begin_define
define|#
directive|define
name|A31_CCM_LCD1_CH0_CLK
value|0x011c
end_define

begin_define
define|#
directive|define
name|A31_CCM_LCD0_CH1_CLK
value|0x012c
end_define

begin_define
define|#
directive|define
name|A31_CCM_LCD1_CH1_CLK
value|0x0130
end_define

begin_define
define|#
directive|define
name|A31_CCM_CSI0_CLK
value|0x0134
end_define

begin_define
define|#
directive|define
name|A31_CCM_CSI1_CLK
value|0x0138
end_define

begin_define
define|#
directive|define
name|A31_CCM_VE_CLK
value|0x013c
end_define

begin_define
define|#
directive|define
name|A31_CCM_AUDIO_CODEC_CLK
value|0x0140
end_define

begin_define
define|#
directive|define
name|A31_CCM_AVS_CLK
value|0x0144
end_define

begin_define
define|#
directive|define
name|A31_CCM_DIGITAL_MIC_CLK
value|0x0148
end_define

begin_define
define|#
directive|define
name|A31_CCM_HDMI_CLK
value|0x0150
end_define

begin_define
define|#
directive|define
name|A31_CCM_PS_CLK
value|0x0154
end_define

begin_define
define|#
directive|define
name|A31_CCM_MBUS_SCLK_CFG0
value|0x015c
end_define

begin_define
define|#
directive|define
name|A31_CCM_MBUS_SCLK_CFG1
value|0x0160
end_define

begin_define
define|#
directive|define
name|A31_CCM_MIPI_DSI_CLK
value|0x0168
end_define

begin_define
define|#
directive|define
name|A31_CCM_MIPI_CSI0_CLK
value|0x016c
end_define

begin_define
define|#
directive|define
name|A31_CCM_DRC0_SCLK_CFG
value|0x0180
end_define

begin_define
define|#
directive|define
name|A31_CCM_DRC1_SCLK_CFG
value|0x0184
end_define

begin_define
define|#
directive|define
name|A31_CCM_DEU0_SCLK_CFG
value|0x0188
end_define

begin_define
define|#
directive|define
name|A31_CCM_DEU1_SCLK_CFG
value|0x018c
end_define

begin_define
define|#
directive|define
name|A31_CCM_GPU_CORE_CLK
value|0x01a0
end_define

begin_define
define|#
directive|define
name|A31_CCM_GPU_MEM_CLK
value|0x01a4
end_define

begin_define
define|#
directive|define
name|A31_CCM_GPU_HYD_CLK
value|0x01a8
end_define

begin_define
define|#
directive|define
name|A31_CCM_ATS_CLK
value|0x01b0
end_define

begin_define
define|#
directive|define
name|A31_CCM_TRACE_CLK
value|0x01b4
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_LOCK_CFG
value|0x0200
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL1_LOCK_CFG
value|0x0204
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL1_BIAS
value|0x0220
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL2_BIAS
value|0x0224
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL3_BIAS
value|0x0228
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL4_BIAS
value|0x022c
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL5_BIAS
value|0x0230
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL6_BIAS
value|0x0234
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL7_BIAS
value|0x0238
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL8_BIAS
value|0x023c
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL9_BIAS
value|0x0240
end_define

begin_define
define|#
directive|define
name|A31_CCM_MIPI_PLL_BIAS
value|0x0244
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL10_BIAS
value|0x0248
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL1_PAT_CFG
value|0x0280
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL2_PAT_CFG
value|0x0284
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL3_PAT_CFG
value|0x0288
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL4_PAT_CFG
value|0x028c
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL5_PAT_CFG
value|0x0290
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL6_PAT_CFG
value|0x0294
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL7_PAT_CFG
value|0x0298
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL8_PAT_CFG
value|0x029c
end_define

begin_define
define|#
directive|define
name|A31_CCM_MIPI_PLL_PAT_CFG
value|0x02a0
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL9_PAT_CFG
value|0x02a4
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL10_PAT_CFG
value|0x02a8
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG0
value|0x02c0
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG1
value|0x02c4
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG2
value|0x02c8
end_define

begin_define
define|#
directive|define
name|A31_CCM_APB1_RST
value|0x02d0
end_define

begin_define
define|#
directive|define
name|A31_CCM_APB2_RST
value|0x02d8
end_define

begin_define
define|#
directive|define
name|A31_CCM_CLK_OUTA
value|0x0300
end_define

begin_define
define|#
directive|define
name|A31_CCM_CLK_OUTB
value|0x0304
end_define

begin_define
define|#
directive|define
name|A31_CCM_CLK_OUTC
value|0x0308
end_define

begin_comment
comment|/* PLL6_CFG_REG */
end_comment

begin_define
define|#
directive|define
name|A31_CCM_PLL6_CFG_REG_LOCK
value|(1<< 28)
end_define

begin_comment
comment|/* AHB_GATING_REG0 */
end_comment

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING_OHCI2
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING_OHCI1
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING_OHCI0
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING_EHCI1
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING_EHCI0
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING_USBDRD
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING_GMAC
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB_GATING_SDMMC0
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_CFG_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_CFG_BYPASS
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_CFG_PLL5
value|(1U<< 25)
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_CFG_PLL6
value|(1U<< 24)
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_CFG_FACTOR_N
value|0x1f00
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_CFG_FACTOR_N_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_CFG_FACTOR_K
value|0x30
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_CFG_FACTOR_K_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|A31_CCM_PLL_CFG_FACTOR_M
value|0x3
end_define

begin_comment
comment|/* APB2_GATING */
end_comment

begin_define
define|#
directive|define
name|A31_CCM_APB2_GATING_TWI
value|(1<< 0)
end_define

begin_comment
comment|/* AHB1_RST_REG0 */
end_comment

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG0_OHCI2
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG0_OHCI1
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG0_OHCI0
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG0_EHCI1
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG0_EHCI0
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG0_GMAC
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|A31_CCM_AHB1_RST_REG0_SDMMC
value|(1<< 8)
end_define

begin_comment
comment|/* APB2_RST_REG */
end_comment

begin_define
define|#
directive|define
name|A31_CCM_APB2_RST_TWI
value|(1<< 0)
end_define

begin_comment
comment|/* GMAC */
end_comment

begin_define
define|#
directive|define
name|A31_CCM_GMAC_CLK_DELAY_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|A31_CCM_GMAC_CLK_MODE_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|A31_CCM_GMAC_MODE_RGMII
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|A31_CCM_GMAC_CLK_MII
value|0x0
end_define

begin_define
define|#
directive|define
name|A31_CCM_GMAC_CLK_EXT_RGMII
value|0x1
end_define

begin_define
define|#
directive|define
name|A31_CCM_GMAC_CLK_RGMII
value|0x2
end_define

begin_comment
comment|/* SD/MMC */
end_comment

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_SRC_SEL
value|0x3000000
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_SRC_SEL_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_SRC_SEL_OSC24M
value|0
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_SRC_SEL_PLL6
value|1
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_PHASE_CTR
value|0x700000
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_PHASE_CTR_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_DIV_RATIO_N
value|0x30000
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_DIV_RATIO_N_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_OPHASE_CTR
value|0x700
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_OPHASE_CTR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|A31_CCM_SD_CLK_DIV_RATIO_M
value|0xf
end_define

begin_comment
comment|/* USB */
end_comment

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK_GATING_OHCI2
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK_GATING_OHCI1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK_GATING_OHCI0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK_GATING_USBPHY2
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK_GATING_USBPHY1
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK_GATING_USBPHY0
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK_USBPHY2_RST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK_USBPHY1_RST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|A31_CCM_USBPHY_CLK_USBPHY0_RST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|A31_CCM_CLK_REF_FREQ
value|24000000U
end_define

begin_function_decl
name|int
name|a31_clk_gmac_activate
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a31_clk_mmc_activate
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a31_clk_mmc_cfg
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a31_clk_i2c_activate
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a31_clk_ehci_activate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a31_clk_ehci_deactivate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _A31_CLK_H_ */
end_comment

end_unit

