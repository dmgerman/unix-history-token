begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 HiSilicon Technologies Co., Ltd.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program. If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_HISTB_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_HISTB_CLOCK_H
end_define

begin_comment
comment|/* clocks provided by core CRG */
end_comment

begin_define
define|#
directive|define
name|HISTB_OSC_CLK
value|0
end_define

begin_define
define|#
directive|define
name|HISTB_APB_CLK
value|1
end_define

begin_define
define|#
directive|define
name|HISTB_AHB_CLK
value|2
end_define

begin_define
define|#
directive|define
name|HISTB_UART1_CLK
value|3
end_define

begin_define
define|#
directive|define
name|HISTB_UART2_CLK
value|4
end_define

begin_define
define|#
directive|define
name|HISTB_UART3_CLK
value|5
end_define

begin_define
define|#
directive|define
name|HISTB_I2C0_CLK
value|6
end_define

begin_define
define|#
directive|define
name|HISTB_I2C1_CLK
value|7
end_define

begin_define
define|#
directive|define
name|HISTB_I2C2_CLK
value|8
end_define

begin_define
define|#
directive|define
name|HISTB_I2C3_CLK
value|9
end_define

begin_define
define|#
directive|define
name|HISTB_I2C4_CLK
value|10
end_define

begin_define
define|#
directive|define
name|HISTB_I2C5_CLK
value|11
end_define

begin_define
define|#
directive|define
name|HISTB_SPI0_CLK
value|12
end_define

begin_define
define|#
directive|define
name|HISTB_SPI1_CLK
value|13
end_define

begin_define
define|#
directive|define
name|HISTB_SPI2_CLK
value|14
end_define

begin_define
define|#
directive|define
name|HISTB_SCI_CLK
value|15
end_define

begin_define
define|#
directive|define
name|HISTB_FMC_CLK
value|16
end_define

begin_define
define|#
directive|define
name|HISTB_MMC_BIU_CLK
value|17
end_define

begin_define
define|#
directive|define
name|HISTB_MMC_CIU_CLK
value|18
end_define

begin_define
define|#
directive|define
name|HISTB_MMC_DRV_CLK
value|19
end_define

begin_define
define|#
directive|define
name|HISTB_MMC_SAMPLE_CLK
value|20
end_define

begin_define
define|#
directive|define
name|HISTB_SDIO0_BIU_CLK
value|21
end_define

begin_define
define|#
directive|define
name|HISTB_SDIO0_CIU_CLK
value|22
end_define

begin_define
define|#
directive|define
name|HISTB_SDIO0_DRV_CLK
value|23
end_define

begin_define
define|#
directive|define
name|HISTB_SDIO0_SAMPLE_CLK
value|24
end_define

begin_define
define|#
directive|define
name|HISTB_PCIE_AUX_CLK
value|25
end_define

begin_define
define|#
directive|define
name|HISTB_PCIE_PIPE_CLK
value|26
end_define

begin_define
define|#
directive|define
name|HISTB_PCIE_SYS_CLK
value|27
end_define

begin_define
define|#
directive|define
name|HISTB_PCIE_BUS_CLK
value|28
end_define

begin_define
define|#
directive|define
name|HISTB_ETH0_MAC_CLK
value|29
end_define

begin_define
define|#
directive|define
name|HISTB_ETH0_MACIF_CLK
value|30
end_define

begin_define
define|#
directive|define
name|HISTB_ETH1_MAC_CLK
value|31
end_define

begin_define
define|#
directive|define
name|HISTB_ETH1_MACIF_CLK
value|32
end_define

begin_define
define|#
directive|define
name|HISTB_COMBPHY1_CLK
value|33
end_define

begin_define
define|#
directive|define
name|HISTB_USB2_BUS_CLK
value|34
end_define

begin_define
define|#
directive|define
name|HISTB_USB2_PHY_CLK
value|35
end_define

begin_define
define|#
directive|define
name|HISTB_USB2_UTMI_CLK
value|36
end_define

begin_define
define|#
directive|define
name|HISTB_USB2_12M_CLK
value|37
end_define

begin_define
define|#
directive|define
name|HISTB_USB2_48M_CLK
value|38
end_define

begin_define
define|#
directive|define
name|HISTB_USB2_OTG_UTMI_CLK
value|39
end_define

begin_define
define|#
directive|define
name|HISTB_USB2_PHY1_REF_CLK
value|40
end_define

begin_define
define|#
directive|define
name|HISTB_USB2_PHY2_REF_CLK
value|41
end_define

begin_comment
comment|/* clocks provided by mcu CRG */
end_comment

begin_define
define|#
directive|define
name|HISTB_MCE_CLK
value|1
end_define

begin_define
define|#
directive|define
name|HISTB_IR_CLK
value|2
end_define

begin_define
define|#
directive|define
name|HISTB_TIMER01_CLK
value|3
end_define

begin_define
define|#
directive|define
name|HISTB_LEDC_CLK
value|4
end_define

begin_define
define|#
directive|define
name|HISTB_UART0_CLK
value|5
end_define

begin_define
define|#
directive|define
name|HISTB_LSADC_CLK
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_HISTB_CLOCK_H */
end_comment

end_unit

