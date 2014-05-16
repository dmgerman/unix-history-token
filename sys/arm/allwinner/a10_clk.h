begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ganbold Tsagaankhuu<ganbold@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_A10_CLK_H_
end_ifndef

begin_define
define|#
directive|define
name|_A10_CLK_H_
end_define

begin_define
define|#
directive|define
name|CCMU_BASE
value|0xe1c20000
end_define

begin_define
define|#
directive|define
name|CCM_PLL1_CFG
value|0x0000
end_define

begin_define
define|#
directive|define
name|CCM_PLL1_TUN
value|0x0004
end_define

begin_define
define|#
directive|define
name|CCM_PLL2_CFG
value|0x0008
end_define

begin_define
define|#
directive|define
name|CCM_PLL2_TUN
value|0x000c
end_define

begin_define
define|#
directive|define
name|CCM_PLL3_CFG
value|0x0010
end_define

begin_define
define|#
directive|define
name|CCM_PLL3_TUN
value|0x0014
end_define

begin_define
define|#
directive|define
name|CCM_PLL4_CFG
value|0x0018
end_define

begin_define
define|#
directive|define
name|CCM_PLL4_TUN
value|0x001c
end_define

begin_define
define|#
directive|define
name|CCM_PLL5_CFG
value|0x0020
end_define

begin_define
define|#
directive|define
name|CCM_PLL5_TUN
value|0x0024
end_define

begin_define
define|#
directive|define
name|CCM_PLL6_CFG
value|0x0028
end_define

begin_define
define|#
directive|define
name|CCM_PLL6_TUN
value|0x002c
end_define

begin_define
define|#
directive|define
name|CCM_PLL7_CFG
value|0x0030
end_define

begin_define
define|#
directive|define
name|CCM_PLL7_TUN
value|0x0034
end_define

begin_define
define|#
directive|define
name|CCM_PLL1_TUN2
value|0x0038
end_define

begin_define
define|#
directive|define
name|CCM_PLL5_TUN2
value|0x003c
end_define

begin_define
define|#
directive|define
name|CCM_PLL_LOCK_DBG
value|0x004c
end_define

begin_define
define|#
directive|define
name|CCM_OSC24M_CFG
value|0x0050
end_define

begin_define
define|#
directive|define
name|CCM_CPU_AHB_APB0_CFG
value|0x0054
end_define

begin_define
define|#
directive|define
name|CCM_APB1_CLK_DIV
value|0x0058
end_define

begin_define
define|#
directive|define
name|CCM_AXI_GATING
value|0x005c
end_define

begin_define
define|#
directive|define
name|CCM_AHB_GATING0
value|0x0060
end_define

begin_define
define|#
directive|define
name|CCM_AHB_GATING1
value|0x0064
end_define

begin_define
define|#
directive|define
name|CCM_APB0_GATING
value|0x0068
end_define

begin_define
define|#
directive|define
name|CCM_APB1_GATING
value|0x006c
end_define

begin_define
define|#
directive|define
name|CCM_NAND_SCLK_CFG
value|0x0080
end_define

begin_define
define|#
directive|define
name|CCM_MS_SCLK_CFG
value|0x0084
end_define

begin_define
define|#
directive|define
name|CCM_MMC0_SCLK_CFG
value|0x0088
end_define

begin_define
define|#
directive|define
name|CCM_MMC1_SCLK_CFG
value|0x008c
end_define

begin_define
define|#
directive|define
name|CCM_MMC2_SCLK_CFG
value|0x0090
end_define

begin_define
define|#
directive|define
name|CCM_MMC3_SCLK_CFG
value|0x0094
end_define

begin_define
define|#
directive|define
name|CCM_TS_CLK
value|0x0098
end_define

begin_define
define|#
directive|define
name|CCM_SS_CLK
value|0x009c
end_define

begin_define
define|#
directive|define
name|CCM_SPI0_CLK
value|0x00a0
end_define

begin_define
define|#
directive|define
name|CCM_SPI1_CLK
value|0x00a4
end_define

begin_define
define|#
directive|define
name|CCM_SPI2_CLK
value|0x00a8
end_define

begin_define
define|#
directive|define
name|CCM_PATA_CLK
value|0x00ac
end_define

begin_define
define|#
directive|define
name|CCM_IR0_CLK
value|0x00b0
end_define

begin_define
define|#
directive|define
name|CCM_IR1_CLK
value|0x00b4
end_define

begin_define
define|#
directive|define
name|CCM_IIS_CLK
value|0x00b8
end_define

begin_define
define|#
directive|define
name|CCM_AC97_CLK
value|0x00bc
end_define

begin_define
define|#
directive|define
name|CCM_SPDIF_CLK
value|0x00c0
end_define

begin_define
define|#
directive|define
name|CCM_KEYPAD_CLK
value|0x00c4
end_define

begin_define
define|#
directive|define
name|CCM_SATA_CLK
value|0x00c8
end_define

begin_define
define|#
directive|define
name|CCM_USB_CLK
value|0x00cc
end_define

begin_define
define|#
directive|define
name|CCM_GPS_CLK
value|0x00d0
end_define

begin_define
define|#
directive|define
name|CCM_SPI3_CLK
value|0x00d4
end_define

begin_define
define|#
directive|define
name|CCM_DRAM_CLK
value|0x0100
end_define

begin_define
define|#
directive|define
name|CCM_BE0_SCLK
value|0x0104
end_define

begin_define
define|#
directive|define
name|CCM_BE1_SCLK
value|0x0108
end_define

begin_define
define|#
directive|define
name|CCM_FE0_CLK
value|0x010c
end_define

begin_define
define|#
directive|define
name|CCM_FE1_CLK
value|0x0110
end_define

begin_define
define|#
directive|define
name|CCM_MP_CLK
value|0x0114
end_define

begin_define
define|#
directive|define
name|CCM_LCD0_CH0_CLK
value|0x0118
end_define

begin_define
define|#
directive|define
name|CCM_LCD1_CH0_CLK
value|0x011c
end_define

begin_define
define|#
directive|define
name|CCM_CSI_ISP_CLK
value|0x0120
end_define

begin_define
define|#
directive|define
name|CCM_TVD_CLK
value|0x0128
end_define

begin_define
define|#
directive|define
name|CCM_LCD0_CH1_CLK
value|0x012c
end_define

begin_define
define|#
directive|define
name|CCM_LCD1_CH1_CLK
value|0x0130
end_define

begin_define
define|#
directive|define
name|CCM_CS0_CLK
value|0x0134
end_define

begin_define
define|#
directive|define
name|CCM_CS1_CLK
value|0x0138
end_define

begin_define
define|#
directive|define
name|CCM_VE_CLK
value|0x013c
end_define

begin_define
define|#
directive|define
name|CCM_AUDIO_CODEC_CLK
value|0x0140
end_define

begin_define
define|#
directive|define
name|CCM_AVS_CLK
value|0x0144
end_define

begin_define
define|#
directive|define
name|CCM_ACE_CLK
value|0x0148
end_define

begin_define
define|#
directive|define
name|CCM_LVDS_CLK
value|0x014c
end_define

begin_define
define|#
directive|define
name|CCM_HDMI_CLK
value|0x0150
end_define

begin_define
define|#
directive|define
name|CCM_MALI400_CLK
value|0x0154
end_define

begin_define
define|#
directive|define
name|CCM_AHB_GATING_USB0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CCM_AHB_GATING_EHCI0
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CCM_AHB_GATING_EHCI1
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CCM_AHB_GATING_EMAC
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|CCM_USB_PHY
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|CCM_USB0_RESET
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CCM_USB1_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CCM_USB2_RESET
value|(1<< 2)
end_define

begin_function_decl
name|int
name|a10_clk_usb_activate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a10_clk_usb_deactivate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a10_clk_emac_activate
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
comment|/* _A10_CLK_H_ */
end_comment

end_unit

