begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 HiSilicon Technologies Co., Ltd.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program. If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_HI3516CV300_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_HI3516CV300_CLOCK_H
end_define

begin_comment
comment|/* hi3516CV300 core CRG */
end_comment

begin_define
define|#
directive|define
name|HI3516CV300_APB_CLK
value|0
end_define

begin_define
define|#
directive|define
name|HI3516CV300_UART0_CLK
value|1
end_define

begin_define
define|#
directive|define
name|HI3516CV300_UART1_CLK
value|2
end_define

begin_define
define|#
directive|define
name|HI3516CV300_UART2_CLK
value|3
end_define

begin_define
define|#
directive|define
name|HI3516CV300_SPI0_CLK
value|4
end_define

begin_define
define|#
directive|define
name|HI3516CV300_SPI1_CLK
value|5
end_define

begin_define
define|#
directive|define
name|HI3516CV300_FMC_CLK
value|6
end_define

begin_define
define|#
directive|define
name|HI3516CV300_MMC0_CLK
value|7
end_define

begin_define
define|#
directive|define
name|HI3516CV300_MMC1_CLK
value|8
end_define

begin_define
define|#
directive|define
name|HI3516CV300_MMC2_CLK
value|9
end_define

begin_define
define|#
directive|define
name|HI3516CV300_MMC3_CLK
value|10
end_define

begin_define
define|#
directive|define
name|HI3516CV300_ETH_CLK
value|11
end_define

begin_define
define|#
directive|define
name|HI3516CV300_ETH_MACIF_CLK
value|12
end_define

begin_define
define|#
directive|define
name|HI3516CV300_DMAC_CLK
value|13
end_define

begin_define
define|#
directive|define
name|HI3516CV300_PWM_CLK
value|14
end_define

begin_define
define|#
directive|define
name|HI3516CV300_USB2_BUS_CLK
value|15
end_define

begin_define
define|#
directive|define
name|HI3516CV300_USB2_OHCI48M_CLK
value|16
end_define

begin_define
define|#
directive|define
name|HI3516CV300_USB2_OHCI12M_CLK
value|17
end_define

begin_define
define|#
directive|define
name|HI3516CV300_USB2_OTG_UTMI_CLK
value|18
end_define

begin_define
define|#
directive|define
name|HI3516CV300_USB2_HST_PHY_CLK
value|19
end_define

begin_define
define|#
directive|define
name|HI3516CV300_USB2_UTMI0_CLK
value|20
end_define

begin_define
define|#
directive|define
name|HI3516CV300_USB2_PHY_CLK
value|21
end_define

begin_comment
comment|/* hi3516CV300 sysctrl CRG */
end_comment

begin_define
define|#
directive|define
name|HI3516CV300_WDT_CLK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_HI3516CV300_CLOCK_H */
end_comment

end_unit

