begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Support for SCSI-2 standard    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SCSI_H__
end_ifndef

begin_define
define|#
directive|define
name|__SCSI_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SCSI command OP Code
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Commands for all device types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_CHANGE_DEFINITION
value|0x40
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_COMPARE
value|0x39
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_COPY
value|0x18
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_COPY_VERIFY
value|0x3a
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_INQUIRY
value|0x12
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_LOG_SELECT
value|0x4c
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_LOG_SENSE
value|0x4d
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_MODE_SEL6
value|0x15
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_MODE_SEL10
value|0x55
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_MODE_SEN6
value|0x1a
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_MODE_SEN10
value|0x5a
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_BUFFER
value|0x3c
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_RECEIVE_DIAG
value|0x1c
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_REQUEST_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEND_DIAG
value|0x1d
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_TEST_UNIT_READY
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE_BUFF
value|0x3b
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for Direct Access Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_FORMAT
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_LOCK_UN_CACHE
value|0x36
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_PREFETCH
value|0x34
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_MEDIA_REMOVAL
value|0x1e
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ6
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ10
value|0x28
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ16
value|0x88
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_CAPACITY
value|0x25
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_CAPACITY16
value|0x9e
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_DEFECT
value|0x37
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_LONG
value|0x3e
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_REASSIGN_BLK
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_RELEASE
value|0x17
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_REZERO
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEARCH_DATA_E
value|0x31
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEARCH_DATA_H
value|0x30
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEARCH_DATA_L
value|0x32
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEEK6
value|0x0b
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEEK10
value|0x2b
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEND_DIAG
value|0x1d
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SET_LIMIT
value|0x33
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_START_STOP_UNIT
value|0x1b
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SYNC_CACHE
value|0x35
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_VERIFY
value|0x2f
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE6
value|0x0a
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE10
value|0x2a
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE16
value|0x8a
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE_VERIFY
value|0x2e
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE_LONG
value|0x3f
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE_SAME
value|0x41
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_UNMAP
value|0x42
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for Sequential Access Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_ERASE
value|0x19
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_LOAD_UNLOAD
value|0x1b
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_LOCATE
value|0x2b
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_BLOCK_LIMIT
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_POS
value|0x34
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_REVERSE
value|0x0f
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_RECOVER_BUF_DATA
value|0x14
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_RESERVE_UNIT
value|0x16
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_REWIND
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SPACE
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_VERIFY_TAPE
value|0x13
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE_FILEMARK
value|0x10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for Printer Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_PRINT
value|0x0a
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SLEW_PRINT
value|0x0b
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_STOP_PRINT
value|0x1b
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SYNC_BUFF
value|0x10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for Processor Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_RECEIVE
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEND
value|0x0a
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for Write-Once Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_MEDIUM_SCAN
value|0x38
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEARCH_DAT_E10
value|0x31
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEARCH_DAT_E12
value|0xb1
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEARCH_DAT_H10
value|0x30
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEARCH_DAT_H12
value|0xb0
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEARCH_DAT_L10
value|0x32
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEARCH_DAT_L12
value|0xb2
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SET_LIMIT10
value|0x33
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SET_LIMIT12
value|0xb3
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_VERIFY10
value|0x2f
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_VERIFY12
value|0xaf
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE12
value|0xaa
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE_VERIFY10
value|0x2e
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_WRITE_VERIFY12
value|0xae
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for CD-ROM Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_PLAY_AUD_10
value|0x45
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_PLAY_AUD_12
value|0xa5
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_PLAY_AUD_MSF
value|0x47
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_PLAY_AUD_TKIN
value|0x48
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_PLAY_TK_REL10
value|0x49
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_PLAY_TK_REL12
value|0xa9
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_CD_CAPACITY
value|0x25
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_HEADER
value|0x44
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_SUB_CHANNEL
value|0x42
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_READ_TOC
value|0x43
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for Scanner Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_GET_DATABUFF_STAT
value|0x34
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_GET_WINDOW
value|0x25
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_OBJECT_POS
value|0x31
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SCAN
value|0x1b
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SET_WINDOW
value|0x24
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for Optical Memory Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_UPDATE_BLOCK
value|0x3d
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for Medium Changer Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_EXCHANGE_MEDIUM
value|0xa6
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_INIT_ELEMENT_STAT
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_POS_TO_ELEMENT
value|0x2b
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_REQUEST_VE_ADDR
value|0xb5
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEND_VOL_TAG
value|0xb6
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional commands for Communition Devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_OP_GET_MESSAGE6
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_GET_MESSAGE10
value|0x28
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_GET_MESSAGE12
value|0xa8
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEND_MESSAGE6
value|0x0a
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEND_MESSAGE10
value|0x2a
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_OP_SEND_MESSAGE12
value|0xaa
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SCSI Data Transfer Direction
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_DATA_IN
value|0
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_DATA_OUT
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Device Type Definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_DISK
value|0x00
end_define

begin_comment
comment|///< Direct-access device (e.g. magnetic disk)
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_TAPE
value|0x01
end_define

begin_comment
comment|///< Sequential-access device (e.g. magnetic tape)
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_PRINTER
value|0x02
end_define

begin_comment
comment|///< Printer device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_PROCESSOR
value|0x03
end_define

begin_comment
comment|///< Processor device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_WORM
value|0x04
end_define

begin_comment
comment|///< Write-once device (e.g. some optical disks)
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_CDROM
value|0x05
end_define

begin_comment
comment|///< CD-ROM device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_SCANNER
value|0x06
end_define

begin_comment
comment|///< Scanner device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_OPTICAL
value|0x07
end_define

begin_comment
comment|///< Optical memory device (e.g. some optical disks)
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_MEDIUMCHANGER
value|0x08
end_define

begin_comment
comment|///< Medium changer device (e.g. jukeboxes)
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_COMMUNICATION
value|0x09
end_define

begin_comment
comment|///< Communications device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_ASCIT8_1
value|0x0A
end_define

begin_comment
comment|///< Defined by ASC IT8 (Graphic arts pre-press devices)
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_ASCIT8_2
value|0x0B
end_define

begin_comment
comment|///< Defined by ASC IT8 (Graphic arts pre-press devices)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 0Ch - 1Eh are reserved
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_TYPE_UNKNOWN
value|0x1F
end_define

begin_comment
comment|///< Unknown or no device type
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Page Codes for INQUIRY command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_PAGE_CODE_SUPPORTED_VPD
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_PAGE_CODE_BLOCK_LIMITS_VPD
value|0xB0
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// Standard INQUIRY data format
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Peripheral_Type
range|:
literal|5
decl_stmt|;
name|UINT8
name|Peripheral_Qualifier
range|:
literal|3
decl_stmt|;
name|UINT8
name|DeviceType_Modifier
range|:
literal|7
decl_stmt|;
name|UINT8
name|Rmb
range|:
literal|1
decl_stmt|;
name|UINT8
name|Version
decl_stmt|;
name|UINT8
name|Response_Data_Format
decl_stmt|;
name|UINT8
name|Addnl_Length
decl_stmt|;
name|UINT8
name|Reserved_5_95
index|[
literal|95
operator|-
literal|5
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|EFI_SCSI_INQUIRY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Supported VPD Pages VPD page
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Peripheral_Type
range|:
literal|5
decl_stmt|;
name|UINT8
name|Peripheral_Qualifier
range|:
literal|3
decl_stmt|;
name|UINT8
name|PageCode
decl_stmt|;
name|UINT8
name|PageLength2
decl_stmt|;
name|UINT8
name|PageLength1
decl_stmt|;
name|UINT8
name|SupportedVpdPageList
index|[
literal|0x100
index|]
decl_stmt|;
block|}
name|EFI_SCSI_SUPPORTED_VPD_PAGES_VPD_PAGE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Block Limits VPD page
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Peripheral_Type
range|:
literal|5
decl_stmt|;
name|UINT8
name|Peripheral_Qualifier
range|:
literal|3
decl_stmt|;
name|UINT8
name|PageCode
decl_stmt|;
name|UINT8
name|PageLength2
decl_stmt|;
name|UINT8
name|PageLength1
decl_stmt|;
name|UINT8
name|WriteSameNonZero
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved_4
range|:
literal|7
decl_stmt|;
name|UINT8
name|MaximumCompareAndWriteLength
decl_stmt|;
name|UINT8
name|OptimalTransferLengthGranularity2
decl_stmt|;
name|UINT8
name|OptimalTransferLengthGranularity1
decl_stmt|;
name|UINT8
name|MaximumTransferLength4
decl_stmt|;
name|UINT8
name|MaximumTransferLength3
decl_stmt|;
name|UINT8
name|MaximumTransferLength2
decl_stmt|;
name|UINT8
name|MaximumTransferLength1
decl_stmt|;
name|UINT8
name|OptimalTransferLength4
decl_stmt|;
name|UINT8
name|OptimalTransferLength3
decl_stmt|;
name|UINT8
name|OptimalTransferLength2
decl_stmt|;
name|UINT8
name|OptimalTransferLength1
decl_stmt|;
name|UINT8
name|MaximumPrefetchXdreadXdwriteTransferLength4
decl_stmt|;
name|UINT8
name|MaximumPrefetchXdreadXdwriteTransferLength3
decl_stmt|;
name|UINT8
name|MaximumPrefetchXdreadXdwriteTransferLength2
decl_stmt|;
name|UINT8
name|MaximumPrefetchXdreadXdwriteTransferLength1
decl_stmt|;
name|UINT8
name|MaximumUnmapLbaCount4
decl_stmt|;
name|UINT8
name|MaximumUnmapLbaCount3
decl_stmt|;
name|UINT8
name|MaximumUnmapLbaCount2
decl_stmt|;
name|UINT8
name|MaximumUnmapLbaCount1
decl_stmt|;
name|UINT8
name|MaximumUnmapBlockDescriptorCount4
decl_stmt|;
name|UINT8
name|MaximumUnmapBlockDescriptorCount3
decl_stmt|;
name|UINT8
name|MaximumUnmapBlockDescriptorCount2
decl_stmt|;
name|UINT8
name|MaximumUnmapBlockDescriptorCount1
decl_stmt|;
name|UINT8
name|OptimalUnmapGranularity4
decl_stmt|;
name|UINT8
name|OptimalUnmapGranularity3
decl_stmt|;
name|UINT8
name|OptimalUnmapGranularity2
decl_stmt|;
name|UINT8
name|OptimalUnmapGranularity1
decl_stmt|;
name|UINT8
name|UnmapGranularityAlignment4
range|:
literal|7
decl_stmt|;
name|UINT8
name|UnmapGranularityAlignmentValid
range|:
literal|1
decl_stmt|;
name|UINT8
name|UnmapGranularityAlignment3
decl_stmt|;
name|UINT8
name|UnmapGranularityAlignment2
decl_stmt|;
name|UINT8
name|UnmapGranularityAlignment1
decl_stmt|;
name|UINT8
name|MaximumWriteSameLength4
decl_stmt|;
name|UINT8
name|MaximumWriteSameLength3
decl_stmt|;
name|UINT8
name|MaximumWriteSameLength2
decl_stmt|;
name|UINT8
name|MaximumWriteSameLength1
decl_stmt|;
name|UINT8
name|MaximumAtomicTransferLength4
decl_stmt|;
name|UINT8
name|MaximumAtomicTransferLength3
decl_stmt|;
name|UINT8
name|MaximumAtomicTransferLength2
decl_stmt|;
name|UINT8
name|MaximumAtomicTransferLength1
decl_stmt|;
name|UINT8
name|AtomicAlignment4
decl_stmt|;
name|UINT8
name|AtomicAlignment3
decl_stmt|;
name|UINT8
name|AtomicAlignment2
decl_stmt|;
name|UINT8
name|AtomicAlignment1
decl_stmt|;
name|UINT8
name|AtomicTransferLengthGranularity4
decl_stmt|;
name|UINT8
name|AtomicTransferLengthGranularity3
decl_stmt|;
name|UINT8
name|AtomicTransferLengthGranularity2
decl_stmt|;
name|UINT8
name|AtomicTransferLengthGranularity1
decl_stmt|;
name|UINT8
name|MaximumAtomicTransferLengthWithAtomicBoundary4
decl_stmt|;
name|UINT8
name|MaximumAtomicTransferLengthWithAtomicBoundary3
decl_stmt|;
name|UINT8
name|MaximumAtomicTransferLengthWithAtomicBoundary2
decl_stmt|;
name|UINT8
name|MaximumAtomicTransferLengthWithAtomicBoundary1
decl_stmt|;
name|UINT8
name|MaximumAtomicBoundarySize4
decl_stmt|;
name|UINT8
name|MaximumAtomicBoundarySize3
decl_stmt|;
name|UINT8
name|MaximumAtomicBoundarySize2
decl_stmt|;
name|UINT8
name|MaximumAtomicBoundarySize1
decl_stmt|;
block|}
name|EFI_SCSI_BLOCK_LIMITS_VPD_PAGE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Error codes 70h and 71h sense data format
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Error_Code
range|:
literal|7
decl_stmt|;
name|UINT8
name|Valid
range|:
literal|1
decl_stmt|;
name|UINT8
name|Segment_Number
decl_stmt|;
name|UINT8
name|Sense_Key
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved_21
range|:
literal|1
decl_stmt|;
name|UINT8
name|Ili
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved_22
range|:
literal|2
decl_stmt|;
name|UINT8
name|Information_3_6
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|Addnl_Sense_Length
decl_stmt|;
comment|///< Additional sense length (n-7)
name|UINT8
name|Vendor_Specific_8_11
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|Addnl_Sense_Code
decl_stmt|;
comment|///< Additional sense code
name|UINT8
name|Addnl_Sense_Code_Qualifier
decl_stmt|;
comment|///< Additional sense code qualifier
name|UINT8
name|Field_Replaceable_Unit_Code
decl_stmt|;
comment|///< Field replaceable unit code
name|UINT8
name|Reserved_15_17
index|[
literal|3
index|]
decl_stmt|;
block|}
name|EFI_SCSI_SENSE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SCSI Disk READ CAPACITY Data
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|LastLba3
decl_stmt|;
name|UINT8
name|LastLba2
decl_stmt|;
name|UINT8
name|LastLba1
decl_stmt|;
name|UINT8
name|LastLba0
decl_stmt|;
name|UINT8
name|BlockSize3
decl_stmt|;
name|UINT8
name|BlockSize2
decl_stmt|;
name|UINT8
name|BlockSize1
decl_stmt|;
name|UINT8
name|BlockSize0
decl_stmt|;
block|}
name|EFI_SCSI_DISK_CAPACITY_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|LastLba7
decl_stmt|;
name|UINT8
name|LastLba6
decl_stmt|;
name|UINT8
name|LastLba5
decl_stmt|;
name|UINT8
name|LastLba4
decl_stmt|;
name|UINT8
name|LastLba3
decl_stmt|;
name|UINT8
name|LastLba2
decl_stmt|;
name|UINT8
name|LastLba1
decl_stmt|;
name|UINT8
name|LastLba0
decl_stmt|;
name|UINT8
name|BlockSize3
decl_stmt|;
name|UINT8
name|BlockSize2
decl_stmt|;
name|UINT8
name|BlockSize1
decl_stmt|;
name|UINT8
name|BlockSize0
decl_stmt|;
name|UINT8
name|Protection
decl_stmt|;
name|UINT8
name|LogicPerPhysical
decl_stmt|;
name|UINT8
name|LowestAlignLogic2
decl_stmt|;
name|UINT8
name|LowestAlignLogic1
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|16
index|]
decl_stmt|;
block|}
name|EFI_SCSI_DISK_CAPACITY_DATA16
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|DataLen
decl_stmt|;
name|UINT16
name|BlkDespDataLen
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|EFI_SCSI_DISK_UNMAP_PARAM_LIST_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Lba
decl_stmt|;
name|UINT32
name|BlockNum
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
name|EFI_SCSI_DISK_UNMAP_BLOCK_DESP
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Sense Key
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_SK_NO_SENSE
value|(0x0)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_RECOVERY_ERROR
value|(0x1)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_NOT_READY
value|(0x2)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_MEDIUM_ERROR
value|(0x3)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_HARDWARE_ERROR
value|(0x4)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_ILLEGAL_REQUEST
value|(0x5)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_UNIT_ATTENTION
value|(0x6)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_DATA_PROTECT
value|(0x7)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_BLANK_CHECK
value|(0x8)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_VENDOR_SPECIFIC
value|(0x9)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_RESERVED_A
value|(0xA)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_ABORT
value|(0xB)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_RESERVED_C
value|(0xC)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_OVERFLOW
value|(0xD)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_MISCOMPARE
value|(0xE)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_SK_RESERVED_F
value|(0xF)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional Sense Codes and Sense Code Qualifiers.
end_comment

begin_comment
comment|// Only some frequently used additional sense codes and qualifiers are
end_comment

begin_comment
comment|// defined here. Please refer to SCSI standard for full value definition.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_NOT_READY
value|(0x04)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASCQ_IN_PROGRESS
value|(0x01)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_MEDIA_ERR1
value|(0x10)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_MEDIA_ERR2
value|(0x11)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_MEDIA_ERR3
value|(0x14)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_MEDIA_ERR4
value|(0x30)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_MEDIA_UPSIDE_DOWN
value|(0x06)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_INVALID_CMD
value|(0x20)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_LBA_OUT_OF_RANGE
value|(0x21)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_INVALID_FIELD
value|(0x24)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_WRITE_PROTECTED
value|(0x27)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_MEDIA_CHANGE
value|(0x28)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_RESET
value|(0x29)
end_define

begin_comment
comment|///< Power On Reset or Bus Reset occurred
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_ILLEGAL_FIELD
value|(0x26)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_NO_MEDIA
value|(0x3A)
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_ASC_ILLEGAL_MODE_FOR_THIS_TRACK
value|(0x64)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

