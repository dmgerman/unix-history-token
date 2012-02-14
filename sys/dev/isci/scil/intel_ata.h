begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2010 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * @file  * @brief This file defines all of the ATA related constants, enumerations,  *        and types.  Please note that this file does not necessarily contain  *        an exhaustive list of all constants, commands, sub-commands, etc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATA_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATA_H_
end_define

begin_include
include|#
directive|include
file|<dev/isci/types.h>
end_include

begin_comment
comment|/**  * @name ATA_COMMAND_CODES  *  * These constants depict the various ATA command codes defined  * in the ATA/ATAPI specification.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_IDENTIFY_DEVICE
value|0xEC
end_define

begin_define
define|#
directive|define
name|ATA_CHECK_POWER_MODE
value|0xE5
end_define

begin_define
define|#
directive|define
name|ATA_STANDBY
value|0xE2
end_define

begin_define
define|#
directive|define
name|ATA_STANDBY_IMMED
value|0xE0
end_define

begin_define
define|#
directive|define
name|ATA_IDLE_IMMED
value|0xE1
end_define

begin_define
define|#
directive|define
name|ATA_IDLE
value|0xE3
end_define

begin_define
define|#
directive|define
name|ATA_FLUSH_CACHE
value|0xE7
end_define

begin_define
define|#
directive|define
name|ATA_FLUSH_CACHE_EXT
value|0xEA
end_define

begin_define
define|#
directive|define
name|ATA_READ_DMA_EXT
value|0x25
end_define

begin_define
define|#
directive|define
name|ATA_READ_DMA
value|0xC8
end_define

begin_define
define|#
directive|define
name|ATA_READ_SECTORS_EXT
value|0x24
end_define

begin_define
define|#
directive|define
name|ATA_READ_SECTORS
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_DMA_EXT
value|0x35
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_DMA
value|0xCA
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_SECTORS_EXT
value|0x34
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_SECTORS
value|0x30
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_UNCORRECTABLE
value|0x45
end_define

begin_define
define|#
directive|define
name|ATA_READ_VERIFY_SECTORS
value|0x40
end_define

begin_define
define|#
directive|define
name|ATA_READ_VERIFY_SECTORS_EXT
value|0x42
end_define

begin_define
define|#
directive|define
name|ATA_READ_BUFFER
value|0xE4
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_BUFFER
value|0xE8
end_define

begin_define
define|#
directive|define
name|ATA_EXECUTE_DEVICE_DIAG
value|0x90
end_define

begin_define
define|#
directive|define
name|ATA_SET_FEATURES
value|0xEF
end_define

begin_define
define|#
directive|define
name|ATA_SMART
value|0xB0
end_define

begin_define
define|#
directive|define
name|ATA_PACKET_IDENTIFY
value|0xA1
end_define

begin_define
define|#
directive|define
name|ATA_PACKET
value|0xA0
end_define

begin_define
define|#
directive|define
name|ATA_READ_FPDMA
value|0x60
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_FPDMA
value|0x61
end_define

begin_define
define|#
directive|define
name|ATA_READ_LOG_EXT
value|0x2F
end_define

begin_define
define|#
directive|define
name|ATA_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_DEVICE_RESET
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_MEDIA_EJECT
value|0xED
end_define

begin_define
define|#
directive|define
name|ATA_SECURITY_UNLOCK
value|0xF2
end_define

begin_define
define|#
directive|define
name|ATA_SECURITY_FREEZE_LOCK
value|0xF5
end_define

begin_define
define|#
directive|define
name|ATA_DATA_SET_MANAGEMENT
value|0x06
end_define

begin_define
define|#
directive|define
name|ATA_DOWNLOAD_MICROCODE
value|0x92
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_STREAM_DMA_EXT
value|0x3A
end_define

begin_define
define|#
directive|define
name|ATA_READ_LOG_DMA_EXT
value|0x47
end_define

begin_define
define|#
directive|define
name|ATA_READ_STREAM_DMA_EXT
value|0x2A
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_DMA_FUA
value|0x3D
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_LOG_DMA_EXT
value|0x57
end_define

begin_define
define|#
directive|define
name|ATA_READ_DMA_QUEUED
value|0xC7
end_define

begin_define
define|#
directive|define
name|ATA_READ_DMA_QUEUED_EXT
value|0x26
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_DMA_QUEUED
value|0xCC
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_DMA_QUEUED_EXT
value|0x36
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_DMA_QUEUED_FUA_EXT
value|0x3E
end_define

begin_define
define|#
directive|define
name|ATA_READ_MULTIPLE
value|0xC4
end_define

begin_define
define|#
directive|define
name|ATA_READ_MULTIPLE_EXT
value|0x29
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_MULTIPLE
value|0xC5
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_MULTIPLE_EXT
value|0x39
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_MULTIPLE_FUA_EXT
value|0xCE
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_SMART_SUB_COMMAND_CODES  *  * These constants define the ATA SMART command sub-codes that can be  * executed.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_SUB_CMD_ENABLE
value|0xD8
end_define

begin_define
define|#
directive|define
name|ATA_SMART_SUB_CMD_DISABLE
value|0xD9
end_define

begin_define
define|#
directive|define
name|ATA_SMART_SUB_CMD_RETURN_STATUS
value|0xDA
end_define

begin_define
define|#
directive|define
name|ATA_SMART_SUB_CMD_READ_LOG
value|0xD5
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_SET_FEATURES_SUB_COMMAND_CODES  *  * These constants define the ATA SET FEATURES command sub-codes that can  * be executed.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_SET_FEATURES_SUB_CMD_ENABLE_CACHE
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_SET_FEATURES_SUB_CMD_DISABLE_CACHE
value|0x82
end_define

begin_define
define|#
directive|define
name|ATA_SET_FEATURES_SUB_CMD_DISABLE_READ_AHEAD
value|0x55
end_define

begin_define
define|#
directive|define
name|ATA_SET_FEATURES_SUB_CMD_ENABLE_READ_AHEAD
value|0xAA
end_define

begin_define
define|#
directive|define
name|ATA_SET_FEATURES_SUB_CMD_SET_TRANSFER_MODE
value|0x3
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_READ_LOG_EXT_PAGE_CODES  *  * This is a list of log page codes available for use.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_LOG_PAGE_NCQ_ERROR
value|0x10
end_define

begin_define
define|#
directive|define
name|ATA_LOG_PAGE_SMART_SELF_TEST
value|0x06
end_define

begin_define
define|#
directive|define
name|ATA_LOG_PAGE_EXTENDED_SMART_SELF_TEST
value|0x07
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_LOG_PAGE_NCQ_ERROR_CONSTANTS  *  * These constants define standard values for use when requesting the NCQ  * error log page.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_LOG_PAGE_NCQ_ERROR_SECTOR
value|0
end_define

begin_define
define|#
directive|define
name|ATA_LOG_PAGE_NCQ_ERROR_SECTOR_COUNT
value|1
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_STATUS_REGISTER_BITS  *  * The following are status register bit definitions per ATA/ATAPI-7.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_STATUS_REG_BSY_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|ATA_STATUS_REG_DEVICE_FAULT_BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_STATUS_REG_ERROR_BIT
value|0x01
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_ERROR_REGISTER_BITS  *  * The following are error register bit definitions per ATA/ATAPI-7.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_ERROR_REG_NO_MEDIA_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_ERROR_REG_ABORT_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|ATA_ERROR_REG_MEDIA_CHANGE_REQUEST_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|ATA_ERROR_REG_ID_NOT_FOUND_BIT
value|0x10
end_define

begin_define
define|#
directive|define
name|ATA_ERROR_REG_MEDIA_CHANGE_BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_ERROR_REG_UNCORRECTABLE_BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|ATA_ERROR_REG_WRITE_PROTECTED_BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|ATA_ERROR_REG_ICRC_BIT
value|0x80
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_CONTROL_REGISTER_BITS  *  * The following are control register bit definitions per ATA/ATAPI-7  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_CONTROL_REG_INTERRUPT_ENABLE_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_CONTROL_REG_SOFT_RESET_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|ATA_CONTROL_REG_HIGH_ORDER_BYTE_BIT
value|0x80
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_DEVICE_HEAD_REGISTER_BITS  *  * The following are device/head register bit definitions per ATA/ATAPI-7.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_DEV_HEAD_REG_LBA_MODE_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|ATA_DEV_HEAD_REG_FUA_ENABLE
value|0x80
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_IDENTIFY_DEVICE_FIELD_LENGTHS  *  * The following constants define the number of bytes contained in various  * fields found in the IDENTIFY DEVICE data structure.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_IDENTIFY_SERIAL_NUMBER_LEN
value|20
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_MODEL_NUMBER_LEN
value|40
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_FW_REVISION_LEN
value|8
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_48_LBA_LEN
value|8
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_MEDIA_SERIAL_NUMBER_LEN
value|30
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_WWN_LEN
value|8
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_IDENTIFY_DEVICE_FIELD_MASKS  *  * The following constants define bit masks utilized to determine if a  * feature is supported/enabled or if a bit is simply set inside of the  * IDENTIFY DEVICE data structre.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_IDENTIFY_REMOVABLE_MEDIA_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_CAPABILITIES1_NORMAL_DMA_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_CAPABILITIES1_STANDBY_ENABLE
value|0x2000
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_COMMAND_SET_SUPPORTED0_SMART_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_COMMAND_SET_SUPPORTED1_48BIT_ENABLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_COMMAND_SET_WWN_SUPPORT_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_COMMAND_SET_ENABLED0_SMART_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_SATA_CAPABILITIES_NCQ_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_NCQ_QUEUE_DEPTH_ENABLE
value|0x001F
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_SECTOR_LARGER_THEN_512_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_LOGICAL_SECTOR_PER_PHYSICAL_SECTOR_MASK
value|0x000F
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_LOGICAL_SECTOR_PER_PHYSICAL_SECTOR_ENABLE
value|0x2000
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_WRITE_UNCORRECTABLE_SUPPORT
value|0x0004
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_COMMAND_SET_SMART_SELF_TEST_SUPPORTED
value|0x0002
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_COMMAND_SET_DSM_TRIM_SUPPORTED
value|0x0001
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_COMMAND_ADDL_SUPPORTED_DETERMINISTIC_READ
value|0x4000
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_COMMAND_ADDL_SUPPORTED_READ_ZERO
value|0x0020
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATAPI_IDENTIFY_DEVICE_FIELD_MASKS  *  * These constants define the various bit definitions for the  * fields in the PACKET IDENTIFY DEVICE data structure.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATAPI_IDENTIFY_16BYTE_CMD_PCKT_ENABLE
value|0x01
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_PACKET_FEATURE_BITS  *  * These constants define the various bit definitions for the  * ATA PACKET feature register.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_PACKET_FEATURE_DMA
value|0x01
end_define

begin_define
define|#
directive|define
name|ATA_PACKET_FEATURE_OVL
value|0x02
end_define

begin_define
define|#
directive|define
name|ATA_PACKET_FEATURE_DMADIR
value|0x04
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_Device_Power_Mode_Values  *  * These constants define the power mode values returned by  * ATA_Check_Power_Mode  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_STANDBY_POWER_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_IDLE_POWER_MODE
value|0x80
end_define

begin_define
define|#
directive|define
name|ATA_ACTIVE_POWER_MODE
value|0xFF
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_WRITE_UNCORRECTIABLE feature field values  *  * These constants define the Write Uncorrectable feature values  * used with the SATI translation.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_WRITE_UNCORRECTABLE_PSUEDO
value|0x55
end_define

begin_define
define|#
directive|define
name|ATA_WRITE_UNCORRECTABLE_FLAGGED
value|0xAA
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name ATA_SECURITY_STATUS field values  *  * These constants define the mask of the securityStatus field and the various bits within it  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|ATA_SECURITY_STATUS_SUPPORTED
value|0x0001
end_define

begin_define
define|#
directive|define
name|ATA_SECURITY_STATUS_ENABLED
value|0x0002
end_define

begin_define
define|#
directive|define
name|ATA_SECURITY_STATUS_LOCKED
value|0x0004
end_define

begin_define
define|#
directive|define
name|ATA_SECURITY_STATUS_FROZEN
value|0x0008
end_define

begin_define
define|#
directive|define
name|ATA_SECURITY_STATUS_EXPIRED
value|0x0010
end_define

begin_define
define|#
directive|define
name|ATA_SECURITY_STATUS_ERASESUPPORTED
value|0x0020
end_define

begin_define
define|#
directive|define
name|ATA_SECURITY_STATUS_RESERVED
value|0xFEC0
end_define

begin_define
define|#
directive|define
name|ATA_SECURITY_STATUS_SECURITYLEVEL
value|0x0100
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @struct ATA_IDENTIFY_DEVICE  *  * @brief This structure depicts the ATA IDENTIFY DEVICE data format.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ATA_IDENTIFY_DEVICE_DATA
block|{
name|U16
name|general_config_bits
decl_stmt|;
comment|// word  00
name|U16
name|obsolete0
decl_stmt|;
comment|// word  01 (num cylinders)
name|U16
name|vendor_specific_config_bits
decl_stmt|;
comment|// word  02
name|U16
name|obsolete1
decl_stmt|;
comment|// word  03 (num heads)
name|U16
name|retired1
index|[
literal|2
index|]
decl_stmt|;
comment|// words 04-05
name|U16
name|obsolete2
decl_stmt|;
comment|// word  06 (sectors / track)
name|U16
name|reserved_for_compact_flash1
index|[
literal|2
index|]
decl_stmt|;
comment|// words 07-08
name|U16
name|retired0
decl_stmt|;
comment|// word  09
name|U8
name|serial_number
index|[
name|ATA_IDENTIFY_SERIAL_NUMBER_LEN
index|]
decl_stmt|;
comment|// word 10-19
name|U16
name|retired2
index|[
literal|2
index|]
decl_stmt|;
comment|// words 20-21
name|U16
name|obsolete4
decl_stmt|;
comment|// word  22
name|U8
name|firmware_revision
index|[
name|ATA_IDENTIFY_FW_REVISION_LEN
index|]
decl_stmt|;
comment|// words 23-26
name|U8
name|model_number
index|[
name|ATA_IDENTIFY_MODEL_NUMBER_LEN
index|]
decl_stmt|;
comment|// words 27-46
name|U16
name|max_sectors_per_multiple
decl_stmt|;
comment|// word  47
name|U16
name|reserved0
decl_stmt|;
comment|// word  48
name|U16
name|capabilities1
decl_stmt|;
comment|// word  49
name|U16
name|capabilities2
decl_stmt|;
comment|// word  50
name|U16
name|obsolete5
index|[
literal|2
index|]
decl_stmt|;
comment|// words 51-52
name|U16
name|validity_bits
decl_stmt|;
comment|// word  53
name|U16
name|obsolete6
index|[
literal|5
index|]
decl_stmt|;
comment|// words 54-58 Used to be:
comment|// current cylinders,
comment|// current heads,
comment|// current sectors/Track,
comment|// current capacity
name|U16
name|current_max_sectors_per_multiple
decl_stmt|;
comment|// word  59
name|U8
name|total_num_sectors
index|[
literal|4
index|]
decl_stmt|;
comment|// words 60-61
name|U16
name|obsolete7
decl_stmt|;
comment|// word  62
name|U16
name|multi_word_dma_mode
decl_stmt|;
comment|// word  63
name|U16
name|pio_modes_supported
decl_stmt|;
comment|// word  64
name|U16
name|min_multiword_dma_transfer_cycle
decl_stmt|;
comment|// word  65
name|U16
name|rec_min_multiword_dma_transfer_cycle
decl_stmt|;
comment|// word  66
name|U16
name|min_pio_transfer_no_flow_ctrl
decl_stmt|;
comment|// word  67
name|U16
name|min_pio_transfer_with_flow_ctrl
decl_stmt|;
comment|// word  68
name|U16
name|additional_supported
decl_stmt|;
comment|// word  69
name|U16
name|reserved1
decl_stmt|;
comment|// word  70
name|U16
name|reserved2
index|[
literal|4
index|]
decl_stmt|;
comment|// words 71-74
name|U16
name|queue_depth
decl_stmt|;
comment|// word  75
name|U16
name|serial_ata_capabilities
decl_stmt|;
comment|// word  76
name|U16
name|serial_ata_reserved
decl_stmt|;
comment|// word  77
name|U16
name|serial_ata_features_supported
decl_stmt|;
comment|// word  78
name|U16
name|serial_ata_features_enabled
decl_stmt|;
comment|// word  79
name|U16
name|major_version_number
decl_stmt|;
comment|// word  80
name|U16
name|minor_version_number
decl_stmt|;
comment|// word  81
name|U16
name|command_set_supported0
decl_stmt|;
comment|// word  82
name|U16
name|command_set_supported1
decl_stmt|;
comment|// word  83
name|U16
name|command_set_supported_extention
decl_stmt|;
comment|// word  84
name|U16
name|command_set_enabled0
decl_stmt|;
comment|// word  85
name|U16
name|command_set_enabled1
decl_stmt|;
comment|// word  86
name|U16
name|command_set_default
decl_stmt|;
comment|// word  87
name|U16
name|ultra_dma_mode
decl_stmt|;
comment|// word  88
name|U16
name|security_erase_completion_time
decl_stmt|;
comment|// word  89
name|U16
name|enhanced_security_erase_time
decl_stmt|;
comment|// word  90
name|U16
name|current_power_mgmt_value
decl_stmt|;
comment|// word  91
name|U16
name|master_password_revision
decl_stmt|;
comment|// word  92
name|U16
name|hardware_reset_result
decl_stmt|;
comment|// word  93
name|U16
name|current_acoustic_management_value
decl_stmt|;
comment|// word  94
name|U16
name|stream_min_request_size
decl_stmt|;
comment|// word  95
name|U16
name|stream_transfer_time
decl_stmt|;
comment|// word  96
name|U16
name|stream_access_latency
decl_stmt|;
comment|// word  97
name|U16
name|stream_performance_granularity
index|[
literal|2
index|]
decl_stmt|;
comment|// words 98-99
name|U8
name|max_48bit_lba
index|[
name|ATA_IDENTIFY_48_LBA_LEN
index|]
decl_stmt|;
comment|// words 100-103
name|U16
name|streaming_transfer_time
decl_stmt|;
comment|// word  104
name|U16
name|max_lba_range_entry_blocks
decl_stmt|;
comment|// word  105
name|U16
name|physical_logical_sector_info
decl_stmt|;
comment|// word  106
name|U16
name|acoustic_test_interseek_delay
decl_stmt|;
comment|// word  107
name|U8
name|world_wide_name
index|[
name|ATA_IDENTIFY_WWN_LEN
index|]
decl_stmt|;
comment|// words 108-111
name|U8
name|reserved_for_wwn_extention
index|[
name|ATA_IDENTIFY_WWN_LEN
index|]
decl_stmt|;
comment|// words 112-115
name|U16
name|reserved4
decl_stmt|;
comment|// word  116
name|U8
name|words_per_logical_sector
index|[
literal|4
index|]
decl_stmt|;
comment|// words 117-118
name|U16
name|command_set_supported2
decl_stmt|;
comment|// word  119
name|U16
name|reserved5
index|[
literal|7
index|]
decl_stmt|;
comment|// words 120-126
name|U16
name|removable_media_status
decl_stmt|;
comment|// word  127
name|U16
name|security_status
decl_stmt|;
comment|// word  128
name|U16
name|vendor_specific1
index|[
literal|31
index|]
decl_stmt|;
comment|// words 129-159
name|U16
name|cfa_power_mode1
decl_stmt|;
comment|// word  160
name|U16
name|reserved_for_compact_flash2
index|[
literal|7
index|]
decl_stmt|;
comment|// words 161-167
name|U16
name|device_nominal_form_factor
decl_stmt|;
comment|// word  168
name|U16
name|data_set_management
decl_stmt|;
comment|// word  169
name|U16
name|reserved_for_compact_flash3
index|[
literal|6
index|]
decl_stmt|;
comment|// words 170-175
name|U16
name|current_media_serial_number
index|[
name|ATA_IDENTIFY_MEDIA_SERIAL_NUMBER_LEN
index|]
decl_stmt|;
comment|//words 176-205
name|U16
name|reserved6
index|[
literal|3
index|]
decl_stmt|;
comment|// words 206-208
name|U16
name|logical_sector_alignment
decl_stmt|;
comment|// words 209
name|U16
name|reserved7
index|[
literal|7
index|]
decl_stmt|;
comment|// words 210-216
name|U16
name|nominal_media_rotation_rate
decl_stmt|;
comment|// word  217
name|U16
name|reserved8
index|[
literal|16
index|]
decl_stmt|;
comment|// words 218-233
name|U16
name|min_num_blocks_per_microcode
decl_stmt|;
comment|// word  234
name|U16
name|max_num_blocks_per_microcode
decl_stmt|;
comment|// word  235
name|U16
name|reserved9
index|[
literal|19
index|]
decl_stmt|;
comment|// words 236-254
name|U16
name|integrity_word
decl_stmt|;
comment|// word  255
block|}
name|ATA_IDENTIFY_DEVICE_DATA_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATA_IDENTIFY_DEVICE_GET_OFFSET
parameter_list|(
name|field_name
parameter_list|)
define|\
value|((POINTER_UINT)&(((ATA_IDENTIFY_DEVICE_DATA_T*)0)->field_name))
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_DEVICE_WCE_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|ATA_IDENTIFY_DEVICE_RA_ENABLE
value|0x40
end_define

begin_comment
comment|/**  * @struct ATAPI_IDENTIFY_PACKET_DATA  *  * @brief The following structure depicts the ATA-ATAPI 7 version of the  *        IDENTIFY PACKET DEVICE data structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ATAPI_IDENTIFY_PACKET_DEVICE
block|{
name|U16
name|generalConfigBits
decl_stmt|;
comment|// word  00
name|U16
name|reserved0
decl_stmt|;
comment|// word  01 (num cylinders)
name|U16
name|uniqueConfigBits
decl_stmt|;
comment|// word  02
name|U16
name|reserved1
index|[
literal|7
index|]
decl_stmt|;
comment|// words 03 - 09
name|U8
name|serialNumber
index|[
name|ATA_IDENTIFY_SERIAL_NUMBER_LEN
index|]
decl_stmt|;
comment|// word 10-19
name|U16
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
comment|// words 20-22
name|U8
name|firmwareRevision
index|[
name|ATA_IDENTIFY_FW_REVISION_LEN
index|]
decl_stmt|;
comment|// words 23-26
name|U8
name|modelNumber
index|[
name|ATA_IDENTIFY_MODEL_NUMBER_LEN
index|]
decl_stmt|;
comment|// words 27-46
name|U16
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
comment|// words 47-48
name|U16
name|capabilities1
decl_stmt|;
comment|// word  49
name|U16
name|capabilities2
decl_stmt|;
comment|// word  50
name|U16
name|obsolete0
index|[
literal|2
index|]
decl_stmt|;
comment|// words 51-52
name|U16
name|validityBits
decl_stmt|;
comment|// word  53
name|U16
name|reserved
index|[
literal|8
index|]
decl_stmt|;
comment|// words 54-61
name|U16
name|DMADIRBitRequired
decl_stmt|;
comment|// word  62, page2
name|U16
name|multiWordDmaMode
decl_stmt|;
comment|// word  63
name|U16
name|pioModesSupported
decl_stmt|;
comment|// word  64
name|U16
name|minMultiwordDmaTransferCycle
decl_stmt|;
comment|// word  65
name|U16
name|recMinMultiwordDmaTransferCycle
decl_stmt|;
comment|// word  66
name|U16
name|minPioTransferNoFlowCtrl
decl_stmt|;
comment|// word  67
name|U16
name|minPioTransferWithFlowCtrl
decl_stmt|;
comment|// word  68
name|U16
name|reserved6
index|[
literal|2
index|]
decl_stmt|;
comment|// words 69-70
name|U16
name|nsFromPACKETReceiptToBusRelease
decl_stmt|;
comment|// word  71
name|U16
name|nsFromSERVICEReceiptToBSYreset
decl_stmt|;
comment|// wore  72
name|U16
name|reserved7
index|[
literal|2
index|]
decl_stmt|;
comment|// words 73-74
name|U16
name|queueDepth
decl_stmt|;
comment|// word  75
name|U16
name|serialAtaCapabilities
decl_stmt|;
comment|// word  76
name|U16
name|serialAtaReserved
decl_stmt|;
comment|// word  77
name|U16
name|serialAtaFeaturesSupported
decl_stmt|;
comment|// word  78
name|U16
name|serialAtaFeaturesEnabled
decl_stmt|;
comment|// word  79
name|U16
name|majorVersionNumber
decl_stmt|;
comment|// word  80, page3
name|U16
name|minorVersionNumber
decl_stmt|;
comment|// word  81
name|U16
name|commandSetSupported0
decl_stmt|;
comment|// word  82
name|U16
name|commandSetSupported1
decl_stmt|;
comment|// word  83
name|U16
name|commandSetSupportedExtention
decl_stmt|;
comment|// word  84, page4
name|U16
name|commandSetEnabled0
decl_stmt|;
comment|// word  85
name|U16
name|commandSetEnabled1
decl_stmt|;
comment|// word  86
name|U16
name|commandSetDefault
decl_stmt|;
comment|// word  87
name|U16
name|ultraDmaMode
decl_stmt|;
comment|// word  88, page5
name|U16
name|reserved8
index|[
literal|4
index|]
decl_stmt|;
comment|// words 89 - 92
name|U16
name|hardwareResetResult
decl_stmt|;
comment|// word  93, page6
name|U16
name|currentAcousticManagementValue
decl_stmt|;
comment|// word  94
name|U16
name|reserved9
index|[
literal|30
index|]
decl_stmt|;
comment|// words 95-124
name|U16
name|ATAPIByteCount0Behavior
decl_stmt|;
comment|// word  125
name|U16
name|obsolete1
decl_stmt|;
comment|// word  126
name|U16
name|removableMediaStatus
decl_stmt|;
comment|// word  127,
name|U16
name|securityStatus
decl_stmt|;
comment|// word  128, page7
name|U16
name|vendorSpecific1
index|[
literal|31
index|]
decl_stmt|;
comment|// words 129-159
name|U16
name|reservedForCompactFlash
index|[
literal|16
index|]
decl_stmt|;
comment|// words 160-175
name|U16
name|reserved10
index|[
literal|79
index|]
decl_stmt|;
comment|// words 176-254
name|U16
name|integrityWord
decl_stmt|;
comment|// word  255
block|}
name|ATAPI_IDENTIFY_PACKET_DEVICE_T
typedef|;
end_typedef

begin_comment
comment|/** * @struct ATA_EXTENDED_SMART_SELF_TEST_LOG * * @brief The following structure depicts the ATA-8 version of the *        Extended SMART self test log page descriptor entry. */
end_comment

begin_typedef
typedef|typedef
union|union
name|ATA_DESCRIPTOR_ENTRY
block|{
struct|struct
name|DESCRIPTOR_ENTRY
block|{
name|U8
name|lba_field
decl_stmt|;
name|U8
name|status_byte
decl_stmt|;
name|U8
name|time_stamp_low
decl_stmt|;
name|U8
name|time_stamp_high
decl_stmt|;
name|U8
name|checkpoint_byte
decl_stmt|;
name|U8
name|failing_lba_low
decl_stmt|;
name|U8
name|failing_lba_mid
decl_stmt|;
name|U8
name|failing_lba_high
decl_stmt|;
name|U8
name|failing_lba_low_ext
decl_stmt|;
name|U8
name|failing_lba_mid_ext
decl_stmt|;
name|U8
name|failing_lba_high_ext
decl_stmt|;
name|U8
name|vendor_specific1
decl_stmt|;
name|U8
name|vendor_specific2
decl_stmt|;
name|U8
name|vendor_specific3
decl_stmt|;
name|U8
name|vendor_specific4
decl_stmt|;
name|U8
name|vendor_specific5
decl_stmt|;
name|U8
name|vendor_specific6
decl_stmt|;
name|U8
name|vendor_specific7
decl_stmt|;
name|U8
name|vendor_specific8
decl_stmt|;
name|U8
name|vendor_specific9
decl_stmt|;
name|U8
name|vendor_specific10
decl_stmt|;
name|U8
name|vendor_specific11
decl_stmt|;
name|U8
name|vendor_specific12
decl_stmt|;
name|U8
name|vendor_specific13
decl_stmt|;
name|U8
name|vendor_specific14
decl_stmt|;
name|U8
name|vendor_specific15
decl_stmt|;
block|}
name|DESCRIPTOR_ENTRY
struct|;
name|U8
name|descriptor_entry
index|[
literal|26
index|]
decl_stmt|;
block|}
name|ATA_DESCRIPTOR_ENTRY_T
typedef|;
end_typedef

begin_comment
comment|/** * @struct ATA_EXTENDED_SMART_SELF_TEST_LOG * * @brief The following structure depicts the ATA-8 version of the *        SMART self test log page descriptor entry. */
end_comment

begin_typedef
typedef|typedef
union|union
name|ATA_SMART_DESCRIPTOR_ENTRY
block|{
struct|struct
name|SMART_DESCRIPTOR_ENTRY
block|{
name|U8
name|lba_field
decl_stmt|;
name|U8
name|status_byte
decl_stmt|;
name|U8
name|time_stamp_low
decl_stmt|;
name|U8
name|time_stamp_high
decl_stmt|;
name|U8
name|checkpoint_byte
decl_stmt|;
name|U8
name|failing_lba_low
decl_stmt|;
name|U8
name|failing_lba_mid
decl_stmt|;
name|U8
name|failing_lba_high
decl_stmt|;
name|U8
name|failing_lba_low_ext
decl_stmt|;
name|U8
name|vendor_specific1
decl_stmt|;
name|U8
name|vendor_specific2
decl_stmt|;
name|U8
name|vendor_specific3
decl_stmt|;
name|U8
name|vendor_specific4
decl_stmt|;
name|U8
name|vendor_specific5
decl_stmt|;
name|U8
name|vendor_specific6
decl_stmt|;
name|U8
name|vendor_specific7
decl_stmt|;
name|U8
name|vendor_specific8
decl_stmt|;
name|U8
name|vendor_specific9
decl_stmt|;
name|U8
name|vendor_specific10
decl_stmt|;
name|U8
name|vendor_specific11
decl_stmt|;
name|U8
name|vendor_specific12
decl_stmt|;
name|U8
name|vendor_specific13
decl_stmt|;
name|U8
name|vendor_specific14
decl_stmt|;
name|U8
name|vendor_specific15
decl_stmt|;
block|}
name|SMART_DESCRIPTOR_ENTRY
struct|;
name|U8
name|smart_descriptor_entry
index|[
literal|24
index|]
decl_stmt|;
block|}
name|ATA_SMART_DESCRIPTOR_ENTRY_T
typedef|;
end_typedef

begin_comment
comment|/** * @struct ATA_EXTENDED_SMART_SELF_TEST_LOG * * @brief The following structure depicts the ATA-8 version of the *        Extended SMART self test log page. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ATA_EXTENDED_SMART_SELF_TEST_LOG
block|{
name|U8
name|self_test_log_data_structure_revision_number
decl_stmt|;
comment|//byte 0
name|U8
name|reserved0
decl_stmt|;
comment|//byte 1
name|U8
name|self_test_descriptor_index
index|[
literal|2
index|]
decl_stmt|;
comment|//byte 2-3
name|ATA_DESCRIPTOR_ENTRY_T
name|descriptor_entrys
index|[
literal|19
index|]
decl_stmt|;
comment|//bytes 4-497
name|U8
name|vendor_specific
index|[
literal|2
index|]
decl_stmt|;
comment|//byte 498-499
name|U8
name|reserved1
index|[
literal|11
index|]
decl_stmt|;
comment|//byte 500-510
name|U8
name|data_structure_checksum
decl_stmt|;
comment|//byte 511
block|}
name|ATA_EXTENDED_SMART_SELF_TEST_LOG_T
typedef|;
end_typedef

begin_comment
comment|/** * @struct ATA_EXTENDED_SMART_SELF_TEST_LOG * * @brief The following structure depicts the ATA-8 version of the *        SMART self test log page. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ATA_SMART_SELF_TEST_LOG
block|{
name|U8
name|self_test_log_data_structure_revision_number
index|[
literal|2
index|]
decl_stmt|;
comment|//bytes 0-1
name|ATA_SMART_DESCRIPTOR_ENTRY_T
name|descriptor_entrys
index|[
literal|21
index|]
decl_stmt|;
comment|//bytes 2-505
name|U8
name|vendor_specific
index|[
literal|2
index|]
decl_stmt|;
comment|//byte 506-507
name|U8
name|self_test_index
decl_stmt|;
comment|//byte 508
name|U8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|//byte 509-510
name|U8
name|data_structure_checksum
decl_stmt|;
comment|//byte 511
block|}
name|ATA_SMART_SELF_TEST_LOG_T
typedef|;
end_typedef

begin_comment
comment|/** * @struct ATA_NCQ_COMMAND_ERROR_LOG * * @brief The following structure depicts the ATA-8 version of the *        NCQ command error log page. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ATA_NCQ_COMMAND_ERROR_LOG
block|{
name|U8
name|ncq_tag
range|:
literal|5
decl_stmt|;
name|U8
name|reserved1
range|:
literal|2
decl_stmt|;
name|U8
name|nq
range|:
literal|1
decl_stmt|;
name|U8
name|reserved2
decl_stmt|;
name|U8
name|status
decl_stmt|;
name|U8
name|error
decl_stmt|;
name|U8
name|lba_7_0
decl_stmt|;
name|U8
name|lba_15_8
decl_stmt|;
name|U8
name|lba_23_16
decl_stmt|;
name|U8
name|device
decl_stmt|;
name|U8
name|lba_31_24
decl_stmt|;
name|U8
name|lba_39_32
decl_stmt|;
name|U8
name|lba_47_40
decl_stmt|;
name|U8
name|reserved3
decl_stmt|;
name|U8
name|count_7_0
decl_stmt|;
name|U8
name|count_15_8
decl_stmt|;
name|U8
name|reserved4
index|[
literal|242
index|]
decl_stmt|;
name|U8
name|vendor_specific
index|[
literal|255
index|]
decl_stmt|;
name|U8
name|checksum
decl_stmt|;
block|}
name|ATA_NCQ_COMMAND_ERROR_LOG_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _ATA_H_
end_comment

end_unit

