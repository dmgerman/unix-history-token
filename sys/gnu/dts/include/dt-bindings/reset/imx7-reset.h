begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2017 Impinj, Inc.  *  * Author: Andrey Smirnov<andrew.smirnov@gmail.com>  *  * This program is free software; you can redistribute it and/or modify it  * under the terms and conditions of the GNU General Public License,  * version 2, as published by the Free Software Foundation.  *  * This program is distributed in the hope it will be useful, but WITHOUT  * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for  * more details.  *  * You should have received a copy of the GNU General Public License  * along with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DT_BINDING_RESET_IMX7_H
end_ifndef

begin_define
define|#
directive|define
name|DT_BINDING_RESET_IMX7_H
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_CORE_POR_RESET0
value|0
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_CORE_POR_RESET1
value|1
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_CORE_RESET0
value|2
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_CORE_RESET1
value|3
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_DBG_RESET0
value|4
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_DBG_RESET1
value|5
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_ETM_RESET0
value|6
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_ETM_RESET1
value|7
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_SOC_DBG_RESET
value|8
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_A7_L2RESET
value|9
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_SW_M4C_RST
value|10
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_SW_M4P_RST
value|11
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_EIM_RST
value|12
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_HSICPHY_PORT_RST
value|13
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_USBPHY1_POR
value|14
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_USBPHY1_PORT_RST
value|15
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_USBPHY2_POR
value|16
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_USBPHY2_PORT_RST
value|17
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_MIPI_PHY_MRST
value|18
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_MIPI_PHY_SRST
value|19
end_define

begin_comment
comment|/*  * IMX7_RESET_PCIEPHY is a logical reset line combining PCIEPHY_BTN  * and PCIEPHY_G_RST  */
end_comment

begin_define
define|#
directive|define
name|IMX7_RESET_PCIEPHY
value|20
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_PCIEPHY_PERST
value|21
end_define

begin_comment
comment|/*  * IMX7_RESET_PCIE_CTRL_APPS_EN is not strictly a reset line, but it  * can be used to inhibit PCIe LTTSM, so, in a way, it can be thoguht  * of as one  */
end_comment

begin_define
define|#
directive|define
name|IMX7_RESET_PCIE_CTRL_APPS_EN
value|22
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_DDRC_PRST
value|23
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_DDRC_CORE_RST
value|24
end_define

begin_define
define|#
directive|define
name|IMX7_RESET_NUM
value|25
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

