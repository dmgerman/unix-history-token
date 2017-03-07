begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Neil Armstrong<narmstrong@baylibre.com>  *  * This program is free software; you can redistribute it and/or modify it  * under the terms and conditions of the GNU General Public License,  * version 2, as published by the Free Software Foundation.  *  * This program is distributed in the hope it will be useful, but WITHOUT  * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for  * more details.  *  * You should have received a copy of the GNU General Public License  * along with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DT_RESET_OXSEMI_OX810SE_H
end_ifndef

begin_define
define|#
directive|define
name|DT_RESET_OXSEMI_OX810SE_H
end_define

begin_define
define|#
directive|define
name|RESET_ARM
value|0
end_define

begin_define
define|#
directive|define
name|RESET_COPRO
value|1
end_define

begin_comment
comment|/* Reserved		2 */
end_comment

begin_comment
comment|/* Reserved		3 */
end_comment

begin_define
define|#
directive|define
name|RESET_USBHS
value|4
end_define

begin_define
define|#
directive|define
name|RESET_USBHSPHY
value|5
end_define

begin_define
define|#
directive|define
name|RESET_MAC
value|6
end_define

begin_define
define|#
directive|define
name|RESET_PCI
value|7
end_define

begin_define
define|#
directive|define
name|RESET_DMA
value|8
end_define

begin_define
define|#
directive|define
name|RESET_DPE
value|9
end_define

begin_define
define|#
directive|define
name|RESET_DDR
value|10
end_define

begin_define
define|#
directive|define
name|RESET_SATA
value|11
end_define

begin_define
define|#
directive|define
name|RESET_SATA_LINK
value|12
end_define

begin_define
define|#
directive|define
name|RESET_SATA_PHY
value|13
end_define

begin_comment
comment|/* Reserved		14 */
end_comment

begin_define
define|#
directive|define
name|RESET_NAND
value|15
end_define

begin_define
define|#
directive|define
name|RESET_GPIO
value|16
end_define

begin_define
define|#
directive|define
name|RESET_UART1
value|17
end_define

begin_define
define|#
directive|define
name|RESET_UART2
value|18
end_define

begin_define
define|#
directive|define
name|RESET_MISC
value|19
end_define

begin_define
define|#
directive|define
name|RESET_I2S
value|20
end_define

begin_define
define|#
directive|define
name|RESET_AHB_MON
value|21
end_define

begin_define
define|#
directive|define
name|RESET_UART3
value|22
end_define

begin_define
define|#
directive|define
name|RESET_UART4
value|23
end_define

begin_define
define|#
directive|define
name|RESET_SGDMA
value|24
end_define

begin_comment
comment|/* Reserved		25 */
end_comment

begin_comment
comment|/* Reserved		26 */
end_comment

begin_comment
comment|/* Reserved		27 */
end_comment

begin_comment
comment|/* Reserved		28 */
end_comment

begin_comment
comment|/* Reserved		29 */
end_comment

begin_comment
comment|/* Reserved		30 */
end_comment

begin_define
define|#
directive|define
name|RESET_BUS
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DT_RESET_OXSEMI_OX810SE_H */
end_comment

end_unit

