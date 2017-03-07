begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Neil Armstrong<narmstrong@baylibre.com>  *  * This program is free software; you can redistribute it and/or modify it  * under the terms and conditions of the GNU General Public License,  * version 2, as published by the Free Software Foundation.  *  * This program is distributed in the hope it will be useful, but WITHOUT  * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for  * more details.  *  * You should have received a copy of the GNU General Public License  * along with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DT_CLOCK_OXSEMI_OX820_H
end_ifndef

begin_define
define|#
directive|define
name|DT_CLOCK_OXSEMI_OX820_H
end_define

begin_comment
comment|/* PLLs */
end_comment

begin_define
define|#
directive|define
name|CLK_820_PLLA
value|0
end_define

begin_define
define|#
directive|define
name|CLK_820_PLLB
value|1
end_define

begin_comment
comment|/* Gate Clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_820_LEON
value|2
end_define

begin_define
define|#
directive|define
name|CLK_820_DMA_SGDMA
value|3
end_define

begin_define
define|#
directive|define
name|CLK_820_CIPHER
value|4
end_define

begin_define
define|#
directive|define
name|CLK_820_SD
value|5
end_define

begin_define
define|#
directive|define
name|CLK_820_SATA
value|6
end_define

begin_define
define|#
directive|define
name|CLK_820_AUDIO
value|7
end_define

begin_define
define|#
directive|define
name|CLK_820_USBMPH
value|8
end_define

begin_define
define|#
directive|define
name|CLK_820_ETHA
value|9
end_define

begin_define
define|#
directive|define
name|CLK_820_PCIEA
value|10
end_define

begin_define
define|#
directive|define
name|CLK_820_NAND
value|11
end_define

begin_define
define|#
directive|define
name|CLK_820_PCIEB
value|12
end_define

begin_define
define|#
directive|define
name|CLK_820_ETHB
value|13
end_define

begin_define
define|#
directive|define
name|CLK_820_REF600
value|14
end_define

begin_define
define|#
directive|define
name|CLK_820_USBDEV
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DT_CLOCK_OXSEMI_OX820_H */
end_comment

end_unit

