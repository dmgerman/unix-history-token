begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2010 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SATA_H_
end_ifndef

begin_define
define|#
directive|define
name|_SATA_H_
end_define

begin_include
include|#
directive|include
file|<dev/isci/types.h>
end_include

begin_comment
comment|/**  * @file  *  * @brief This file defines all of the SATA releated constants, enumerations,  *        and types. Please note that this file does not necessarily contain  *        an exhaustive list of all contants and commands.  */
end_comment

begin_comment
comment|/**  * @name SATA FIS Types  *  * These constants depict the various SATA FIS types devined in the serial ATA  * specification.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SATA_FIS_TYPE_REGH2D
value|0x27
end_define

begin_define
define|#
directive|define
name|SATA_FIS_TYPE_REGD2H
value|0x34
end_define

begin_define
define|#
directive|define
name|SATA_FIS_TYPE_SETDEVBITS
value|0xA1
end_define

begin_define
define|#
directive|define
name|SATA_FIS_TYPE_DMA_ACTIVATE
value|0x39
end_define

begin_define
define|#
directive|define
name|SATA_FIS_TYPE_DMA_SETUP
value|0x41
end_define

begin_define
define|#
directive|define
name|SATA_FIS_TYPE_BIST_ACTIVATE
value|0x58
end_define

begin_define
define|#
directive|define
name|SATA_FIS_TYPE_PIO_SETUP
value|0x5F
end_define

begin_define
define|#
directive|define
name|SATA_FIS_TYPE_DATA
value|0x46
end_define

begin_comment
comment|/*@}*/
end_comment

begin_define
define|#
directive|define
name|SATA_REGISTER_FIS_SIZE
value|0x20
end_define

begin_comment
comment|/**  * @struct  SATA_FIS_HEADER  *  * @brief This is the common definition for a SATA FIS Header word.  A  *        different header word is defined for any FIS type that does not use  *        the standard header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATA_FIS_HEADER
block|{
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
comment|// word 0
name|U32
name|pm_port
range|:
literal|4
decl_stmt|;
name|U32
name|reserved
range|:
literal|1
decl_stmt|;
name|U32
name|direction_flag
range|:
literal|1
decl_stmt|;
comment|// direction
name|U32
name|interrupt_flag
range|:
literal|1
decl_stmt|;
name|U32
name|command_flag
range|:
literal|1
decl_stmt|;
comment|// command, auto_activate, or notification
name|U32
name|status
range|:
literal|8
decl_stmt|;
name|U32
name|error
range|:
literal|8
decl_stmt|;
block|}
name|SATA_FIS_HEADER_T
typedef|;
end_typedef

begin_comment
comment|/**  * @struct SATA_FIS_REG_H2D  *  * @brief This is the definition for a SATA Host to Device Register FIS.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATA_FIS_REG_H2D
block|{
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
comment|// word 0
name|U32
name|pm_port
range|:
literal|4
decl_stmt|;
name|U32
name|reserved0
range|:
literal|3
decl_stmt|;
name|U32
name|command_flag
range|:
literal|1
decl_stmt|;
name|U32
name|command
range|:
literal|8
decl_stmt|;
name|U32
name|features
range|:
literal|8
decl_stmt|;
name|U32
name|lba_low
range|:
literal|8
decl_stmt|;
comment|// word 1
name|U32
name|lba_mid
range|:
literal|8
decl_stmt|;
name|U32
name|lba_high
range|:
literal|8
decl_stmt|;
name|U32
name|device
range|:
literal|8
decl_stmt|;
name|U32
name|lba_low_exp
range|:
literal|8
decl_stmt|;
comment|// word 2
name|U32
name|lba_mid_exp
range|:
literal|8
decl_stmt|;
name|U32
name|lba_high_exp
range|:
literal|8
decl_stmt|;
name|U32
name|features_exp
range|:
literal|8
decl_stmt|;
name|U32
name|sector_count
range|:
literal|8
decl_stmt|;
comment|// word 3
name|U32
name|sector_count_exp
range|:
literal|8
decl_stmt|;
name|U32
name|reserved1
range|:
literal|8
decl_stmt|;
name|U32
name|control
range|:
literal|8
decl_stmt|;
name|U32
name|reserved2
decl_stmt|;
comment|// word 4
block|}
name|SATA_FIS_REG_H2D_T
typedef|;
end_typedef

begin_comment
comment|/**  * @struct SATA_FIS_REG_D2H  *  * @brief SATA Device To Host FIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATA_FIS_REG_D2H
block|{
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
comment|// word 0
name|U32
name|pm_port
range|:
literal|4
decl_stmt|;
name|U32
name|reserved0
range|:
literal|2
decl_stmt|;
name|U32
name|irq
range|:
literal|1
decl_stmt|;
name|U32
name|reserved1
range|:
literal|1
decl_stmt|;
name|U32
name|status
range|:
literal|8
decl_stmt|;
name|U32
name|error
range|:
literal|8
decl_stmt|;
name|U8
name|lba_low
decl_stmt|;
comment|// word 1
name|U8
name|lba_mid
decl_stmt|;
name|U8
name|lba_high
decl_stmt|;
name|U8
name|device
decl_stmt|;
name|U8
name|lba_low_exp
decl_stmt|;
comment|// word 2
name|U8
name|lba_mid_exp
decl_stmt|;
name|U8
name|lba_high_exp
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U8
name|sector_count
decl_stmt|;
comment|// word 3
name|U8
name|sector_count_exp
decl_stmt|;
name|U16
name|reserved2
decl_stmt|;
name|U32
name|reserved3
decl_stmt|;
block|}
name|SATA_FIS_REG_D2H_T
typedef|;
end_typedef

begin_comment
comment|/**  *  Status field bit definitions  */
end_comment

begin_define
define|#
directive|define
name|SATA_FIS_STATUS_DEVBITS_MASK
value|(0x77)
end_define

begin_comment
comment|/**  * @struct SATA_FIS_SET_DEV_BITS  *  * @brief SATA Set Device Bits FIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATA_FIS_SET_DEV_BITS
block|{
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
comment|// word 0
name|U32
name|pm_port
range|:
literal|4
decl_stmt|;
name|U32
name|reserved0
range|:
literal|2
decl_stmt|;
name|U32
name|irq
range|:
literal|1
decl_stmt|;
name|U32
name|notification
range|:
literal|1
decl_stmt|;
name|U32
name|status_low
range|:
literal|4
decl_stmt|;
name|U32
name|status_high
range|:
literal|4
decl_stmt|;
name|U32
name|error
range|:
literal|8
decl_stmt|;
name|U32
name|s_active
decl_stmt|;
comment|// word 1
block|}
name|SATA_FIS_SET_DEV_BITS_T
typedef|;
end_typedef

begin_comment
comment|/**  * @struct SATA_FIS_DMA_ACTIVATE  *  * @brief SATA DMA Activate FIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATA_FIS_DMA_ACTIVATE
block|{
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
comment|// word 0
name|U32
name|pm_port
range|:
literal|4
decl_stmt|;
name|U32
name|reserved0
range|:
literal|24
decl_stmt|;
block|}
name|SATA_FIS_DMA_ACTIVATE_T
typedef|;
end_typedef

begin_comment
comment|/**  * The lower 5 bits in the DMA Buffer ID Low field of the DMA Setup  * are used to communicate the command tag.  */
end_comment

begin_define
define|#
directive|define
name|SATA_DMA_SETUP_TAG_ENABLE
value|0x1F
end_define

begin_define
define|#
directive|define
name|SATA_DMA_SETUP_AUTO_ACT_ENABLE
value|0x80
end_define

begin_comment
comment|/**  * @struct SATA_FIS_DMA_SETUP  *  * @brief SATA DMA Setup FIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATA_FIS_DMA_SETUP
block|{
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
comment|// word 0
name|U32
name|pm_port
range|:
literal|4
decl_stmt|;
name|U32
name|reserved_00
range|:
literal|1
decl_stmt|;
name|U32
name|direction
range|:
literal|1
decl_stmt|;
name|U32
name|irq
range|:
literal|1
decl_stmt|;
name|U32
name|auto_activate
range|:
literal|1
decl_stmt|;
name|U32
name|reserved_01
range|:
literal|16
decl_stmt|;
name|U32
name|dma_buffer_id_low
decl_stmt|;
comment|// word 1
name|U32
name|dma_buffer_id_high
decl_stmt|;
comment|// word 2
name|U32
name|reserved0
decl_stmt|;
comment|// word 3
name|U32
name|dma_buffer_offset
decl_stmt|;
comment|// word 4
name|U32
name|dma_transfer_count
decl_stmt|;
comment|// word 5
name|U32
name|reserved1
decl_stmt|;
comment|// word 6
block|}
name|SATA_FIS_DMA_SETUP_T
typedef|;
end_typedef

begin_comment
comment|/**  *  @struct SATA_FIS_BIST_ACTIVATE  *  *  @brief SATA BIST Activate FIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATA_FIS_BIST_ACTIVATE
block|{
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
comment|// word 0
name|U32
name|reserved0
range|:
literal|8
decl_stmt|;
name|U32
name|pattern_definition
range|:
literal|8
decl_stmt|;
name|U32
name|reserved1
range|:
literal|8
decl_stmt|;
name|U32
name|data1
decl_stmt|;
comment|// word 1
name|U32
name|data2
decl_stmt|;
comment|// word 1
block|}
name|SATA_FIS_BIST_ACTIVATE_T
typedef|;
end_typedef

begin_comment
comment|/*  *  SATA PIO Setup FIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATA_FIS_PIO_SETUP
block|{
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
comment|// word 0
name|U32
name|pm_port
range|:
literal|4
decl_stmt|;
name|U32
name|reserved_00
range|:
literal|1
decl_stmt|;
name|U32
name|direction
range|:
literal|1
decl_stmt|;
name|U32
name|irq
range|:
literal|1
decl_stmt|;
name|U32
name|reserved_01
range|:
literal|1
decl_stmt|;
name|U32
name|status
range|:
literal|8
decl_stmt|;
name|U32
name|error
range|:
literal|8
decl_stmt|;
name|U32
name|lba_low
range|:
literal|8
decl_stmt|;
comment|// word 1
name|U32
name|lba_mid
range|:
literal|8
decl_stmt|;
name|U32
name|lba_high
range|:
literal|8
decl_stmt|;
name|U32
name|device
range|:
literal|8
decl_stmt|;
name|U32
name|lba_low_exp
range|:
literal|8
decl_stmt|;
comment|// word 2
name|U32
name|lba_mid_exp
range|:
literal|8
decl_stmt|;
name|U32
name|lba_high_exp
range|:
literal|8
decl_stmt|;
name|U32
name|reserved
range|:
literal|8
decl_stmt|;
name|U32
name|sector_count
range|:
literal|8
decl_stmt|;
comment|// word 3
name|U32
name|sector_count_exp
range|:
literal|8
decl_stmt|;
name|U32
name|reserved1
range|:
literal|8
decl_stmt|;
name|U32
name|ending_status
range|:
literal|8
decl_stmt|;
name|U32
name|transfter_count
range|:
literal|16
decl_stmt|;
comment|// word 4
name|U32
name|reserved3
range|:
literal|16
decl_stmt|;
block|}
name|SATA_FIS_PIO_SETUP_T
typedef|;
end_typedef

begin_comment
comment|/**  * @struct SATA_FIS_DATA  *  * @brief SATA Data FIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATA_FIS_DATA
block|{
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
comment|// word 0
name|U32
name|pm_port
range|:
literal|4
decl_stmt|;
name|U32
name|reserved0
range|:
literal|24
decl_stmt|;
name|U8
name|data
index|[
literal|4
index|]
decl_stmt|;
comment|// word 1
block|}
name|SATA_FIS_DATA_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SATA_H_
end_comment

end_unit

