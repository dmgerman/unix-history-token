begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Header file for SD memory card support.    This header file contains some definitions defined in SD Physical Layer Simplified   Specification Version 4.10 spec.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SD_H__
end_ifndef

begin_define
define|#
directive|define
name|__SD_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SD command index
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SD_GO_IDLE_STATE
value|0
end_define

begin_define
define|#
directive|define
name|SD_ALL_SEND_CID
value|2
end_define

begin_define
define|#
directive|define
name|SD_SET_RELATIVE_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|SD_SET_DSR
value|4
end_define

begin_define
define|#
directive|define
name|SDIO_SEND_OP_COND
value|5
end_define

begin_define
define|#
directive|define
name|SD_SWITCH_FUNC
value|6
end_define

begin_define
define|#
directive|define
name|SD_SELECT_DESELECT_CARD
value|7
end_define

begin_define
define|#
directive|define
name|SD_SEND_IF_COND
value|8
end_define

begin_define
define|#
directive|define
name|SD_SEND_CSD
value|9
end_define

begin_define
define|#
directive|define
name|SD_SEND_CID
value|10
end_define

begin_define
define|#
directive|define
name|SD_VOLTAGE_SWITCH
value|11
end_define

begin_define
define|#
directive|define
name|SD_STOP_TRANSMISSION
value|12
end_define

begin_define
define|#
directive|define
name|SD_SEND_STATUS
value|13
end_define

begin_define
define|#
directive|define
name|SD_GO_INACTIVE_STATE
value|15
end_define

begin_define
define|#
directive|define
name|SD_SET_BLOCKLEN
value|16
end_define

begin_define
define|#
directive|define
name|SD_READ_SINGLE_BLOCK
value|17
end_define

begin_define
define|#
directive|define
name|SD_READ_MULTIPLE_BLOCK
value|18
end_define

begin_define
define|#
directive|define
name|SD_SEND_TUNING_BLOCK
value|19
end_define

begin_define
define|#
directive|define
name|SD_SPEED_CLASS_CONTROL
value|20
end_define

begin_define
define|#
directive|define
name|SD_SET_BLOCK_COUNT
value|23
end_define

begin_define
define|#
directive|define
name|SD_WRITE_SINGLE_BLOCK
value|24
end_define

begin_define
define|#
directive|define
name|SD_WRITE_MULTIPLE_BLOCK
value|25
end_define

begin_define
define|#
directive|define
name|SD_PROGRAM_CSD
value|27
end_define

begin_define
define|#
directive|define
name|SD_SET_WRITE_PROT
value|28
end_define

begin_define
define|#
directive|define
name|SD_CLR_WRITE_PROT
value|29
end_define

begin_define
define|#
directive|define
name|SD_SEND_WRITE_PROT
value|30
end_define

begin_define
define|#
directive|define
name|SD_ERASE_WR_BLK_START
value|32
end_define

begin_define
define|#
directive|define
name|SD_ERASE_WR_BLK_END
value|33
end_define

begin_define
define|#
directive|define
name|SD_ERASE
value|38
end_define

begin_define
define|#
directive|define
name|SD_LOCK_UNLOCK
value|42
end_define

begin_define
define|#
directive|define
name|SD_READ_EXTR_SINGLE
value|48
end_define

begin_define
define|#
directive|define
name|SD_WRITE_EXTR_SINGLE
value|49
end_define

begin_define
define|#
directive|define
name|SDIO_RW_DIRECT
value|52
end_define

begin_define
define|#
directive|define
name|SDIO_RW_EXTENDED
value|53
end_define

begin_define
define|#
directive|define
name|SD_APP_CMD
value|55
end_define

begin_define
define|#
directive|define
name|SD_GEN_CMD
value|56
end_define

begin_define
define|#
directive|define
name|SD_READ_EXTR_MULTI
value|58
end_define

begin_define
define|#
directive|define
name|SD_WRITE_EXTR_MULTI
value|59
end_define

begin_define
define|#
directive|define
name|SD_SET_BUS_WIDTH
value|6
end_define

begin_comment
comment|// ACMD6
end_comment

begin_define
define|#
directive|define
name|SD_STATUS
value|13
end_define

begin_comment
comment|// ACMD13
end_comment

begin_define
define|#
directive|define
name|SD_SEND_NUM_WR_BLOCKS
value|22
end_define

begin_comment
comment|// ACMD22
end_comment

begin_define
define|#
directive|define
name|SD_SET_WR_BLK_ERASE_COUNT
value|23
end_define

begin_comment
comment|// ACMD23
end_comment

begin_define
define|#
directive|define
name|SD_SEND_OP_COND
value|41
end_define

begin_comment
comment|// ACMD41
end_comment

begin_define
define|#
directive|define
name|SD_SET_CLR_CARD_DETECT
value|42
end_define

begin_comment
comment|// ACMD42
end_comment

begin_define
define|#
directive|define
name|SD_SEND_SCR
value|51
end_define

begin_comment
comment|// ACMD51
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|NotUsed
range|:
literal|1
decl_stmt|;
comment|// Not used [0:0]
name|UINT8
name|Crc
range|:
literal|7
decl_stmt|;
comment|// CRC [7:1]
name|UINT16
name|ManufacturingDate
range|:
literal|12
decl_stmt|;
comment|// Manufacturing date [19:8]
name|UINT16
name|Reserved
range|:
literal|4
decl_stmt|;
comment|// Reserved [23:20]
name|UINT8
name|ProductSerialNumber
index|[
literal|4
index|]
decl_stmt|;
comment|// Product serial number [55:24]
name|UINT8
name|ProductRevision
decl_stmt|;
comment|// Product revision [63:56]
name|UINT8
name|ProductName
index|[
literal|5
index|]
decl_stmt|;
comment|// Product name [103:64]
name|UINT8
name|OemId
index|[
literal|2
index|]
decl_stmt|;
comment|// OEM/Application ID [119:104]
name|UINT8
name|ManufacturerId
decl_stmt|;
comment|// Manufacturer ID [127:120]
block|}
name|SD_CID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|NotUsed
range|:
literal|1
decl_stmt|;
comment|// Not used [0:0]
name|UINT32
name|Crc
range|:
literal|7
decl_stmt|;
comment|// CRC [7:1]
name|UINT32
name|Reserved
range|:
literal|2
decl_stmt|;
comment|// Reserved [9:8]
name|UINT32
name|FileFormat
range|:
literal|2
decl_stmt|;
comment|// File format [11:10]
name|UINT32
name|TmpWriteProtect
range|:
literal|1
decl_stmt|;
comment|// Temporary write protection [12:12]
name|UINT32
name|PermWriteProtect
range|:
literal|1
decl_stmt|;
comment|// Permanent write protection [13:13]
name|UINT32
name|Copy
range|:
literal|1
decl_stmt|;
comment|// Copy flag (OTP) [14:14]
name|UINT32
name|FileFormatGrp
range|:
literal|1
decl_stmt|;
comment|// File format group [15:15]
name|UINT32
name|Reserved1
range|:
literal|5
decl_stmt|;
comment|// Reserved [20:16]
name|UINT32
name|WriteBlPartial
range|:
literal|1
decl_stmt|;
comment|// Partial blocks for write allowed [21:21]
name|UINT32
name|WriteBlLen
range|:
literal|4
decl_stmt|;
comment|// Max. write data block length [25:22]
name|UINT32
name|R2WFactor
range|:
literal|3
decl_stmt|;
comment|// Write speed factor [28:26]
name|UINT32
name|Reserved2
range|:
literal|2
decl_stmt|;
comment|// Manufacturer default ECC [30:29]
name|UINT32
name|WpGrpEnable
range|:
literal|1
decl_stmt|;
comment|// Write protect group enable [31:31]
name|UINT32
name|WpGrpSize
range|:
literal|7
decl_stmt|;
comment|// Write protect group size [38:32]
name|UINT32
name|SectorSize
range|:
literal|7
decl_stmt|;
comment|// Erase sector size [45:39]
name|UINT32
name|EraseBlkEn
range|:
literal|1
decl_stmt|;
comment|// Erase single block enable [46:46]
name|UINT32
name|CSizeMul
range|:
literal|3
decl_stmt|;
comment|// device size multiplier [49:47]
name|UINT32
name|VddWCurrMax
range|:
literal|3
decl_stmt|;
comment|// max. write current @VDD max [52:50]
name|UINT32
name|VddWCurrMin
range|:
literal|3
decl_stmt|;
comment|// max. write current @VDD min [55:53]
name|UINT32
name|VddRCurrMax
range|:
literal|3
decl_stmt|;
comment|// max. read current @VDD max [58:56]
name|UINT32
name|VddRCurrMin
range|:
literal|3
decl_stmt|;
comment|// max. read current @VDD min [61:59]
name|UINT32
name|CSizeLow
range|:
literal|2
decl_stmt|;
comment|// Device size low 2 bits [63:62]
name|UINT32
name|CSizeHigh
range|:
literal|10
decl_stmt|;
comment|// Device size high 10 bits [73:64]
name|UINT32
name|Reserved4
range|:
literal|2
decl_stmt|;
comment|// Reserved [75:74]
name|UINT32
name|DsrImp
range|:
literal|1
decl_stmt|;
comment|// DSR implemented [76:76]
name|UINT32
name|ReadBlkMisalign
range|:
literal|1
decl_stmt|;
comment|// Read block misalignment [77:77]
name|UINT32
name|WriteBlkMisalign
range|:
literal|1
decl_stmt|;
comment|// Write block misalignment [78:78]
name|UINT32
name|ReadBlPartial
range|:
literal|1
decl_stmt|;
comment|// Partial blocks for read allowed [79:79]
name|UINT32
name|ReadBlLen
range|:
literal|4
decl_stmt|;
comment|// Max. read data block length [83:80]
name|UINT32
name|Ccc
range|:
literal|12
decl_stmt|;
comment|// Card command classes [95:84]
name|UINT32
name|TranSpeed
range|:
literal|8
decl_stmt|;
comment|// Max. data transfer rate [103:96]
name|UINT32
name|Nsac
range|:
literal|8
decl_stmt|;
comment|// Data read access-time in CLK cycles (NSAC*100) [111:104]
name|UINT32
name|Taac
range|:
literal|8
decl_stmt|;
comment|// Data read access-time [119:112]
name|UINT32
name|Reserved5
range|:
literal|6
decl_stmt|;
comment|// Reserved [125:120]
name|UINT32
name|CsdStructure
range|:
literal|2
decl_stmt|;
comment|// CSD structure [127:126]
block|}
name|SD_CSD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|NotUsed
range|:
literal|1
decl_stmt|;
comment|// Not used [0:0]
name|UINT32
name|Crc
range|:
literal|7
decl_stmt|;
comment|// CRC [7:1]
name|UINT32
name|Reserved
range|:
literal|2
decl_stmt|;
comment|// Reserved [9:8]
name|UINT32
name|FileFormat
range|:
literal|2
decl_stmt|;
comment|// File format [11:10]
name|UINT32
name|TmpWriteProtect
range|:
literal|1
decl_stmt|;
comment|// Temporary write protection [12:12]
name|UINT32
name|PermWriteProtect
range|:
literal|1
decl_stmt|;
comment|// Permanent write protection [13:13]
name|UINT32
name|Copy
range|:
literal|1
decl_stmt|;
comment|// Copy flag (OTP) [14:14]
name|UINT32
name|FileFormatGrp
range|:
literal|1
decl_stmt|;
comment|// File format group [15:15]
name|UINT32
name|Reserved1
range|:
literal|5
decl_stmt|;
comment|// Reserved [20:16]
name|UINT32
name|WriteBlPartial
range|:
literal|1
decl_stmt|;
comment|// Partial blocks for write allowed [21:21]
name|UINT32
name|WriteBlLen
range|:
literal|4
decl_stmt|;
comment|// Max. write data block length [25:22]
name|UINT32
name|R2WFactor
range|:
literal|3
decl_stmt|;
comment|// Write speed factor [28:26]
name|UINT32
name|Reserved2
range|:
literal|2
decl_stmt|;
comment|// Manufacturer default ECC [30:29]
name|UINT32
name|WpGrpEnable
range|:
literal|1
decl_stmt|;
comment|// Write protect group enable [31:31]
name|UINT32
name|WpGrpSize
range|:
literal|7
decl_stmt|;
comment|// Write protect group size [38:32]
name|UINT32
name|SectorSize
range|:
literal|7
decl_stmt|;
comment|// Erase sector size [45:39]
name|UINT32
name|EraseBlkEn
range|:
literal|1
decl_stmt|;
comment|// Erase single block enable [46:46]
name|UINT32
name|Reserved3
range|:
literal|1
decl_stmt|;
comment|// Reserved [47:47]
name|UINT32
name|CSizeLow
range|:
literal|16
decl_stmt|;
comment|// Device size low 16 bits [63:48]
name|UINT32
name|CSizeHigh
range|:
literal|6
decl_stmt|;
comment|// Device size high 6 bits [69:64]
name|UINT32
name|Reserved4
range|:
literal|6
decl_stmt|;
comment|// Reserved [75:70]
name|UINT32
name|DsrImp
range|:
literal|1
decl_stmt|;
comment|// DSR implemented [76:76]
name|UINT32
name|ReadBlkMisalign
range|:
literal|1
decl_stmt|;
comment|// Read block misalignment [77:77]
name|UINT32
name|WriteBlkMisalign
range|:
literal|1
decl_stmt|;
comment|// Write block misalignment [78:78]
name|UINT32
name|ReadBlPartial
range|:
literal|1
decl_stmt|;
comment|// Partial blocks for read allowed [79:79]
name|UINT32
name|ReadBlLen
range|:
literal|4
decl_stmt|;
comment|// Max. read data block length [83:80]
name|UINT32
name|Ccc
range|:
literal|12
decl_stmt|;
comment|// Card command classes [95:84]
name|UINT32
name|TranSpeed
range|:
literal|8
decl_stmt|;
comment|// Max. data transfer rate [103:96]
name|UINT32
name|Nsac
range|:
literal|8
decl_stmt|;
comment|// Data read access-time in CLK cycles (NSAC*100) [111:104]
name|UINT32
name|Taac
range|:
literal|8
decl_stmt|;
comment|// Data read access-time [119:112]
name|UINT32
name|Reserved5
range|:
literal|6
decl_stmt|;
comment|// Reserved [125:120]
name|UINT32
name|CsdStructure
range|:
literal|2
decl_stmt|;
comment|// CSD structure [127:126]
block|}
name|SD_CSD2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Reserved
decl_stmt|;
comment|// Reserved [31:0]
name|UINT32
name|CmdSupport
range|:
literal|4
decl_stmt|;
comment|// Command Support bits [35:32]
name|UINT32
name|Reserved1
range|:
literal|6
decl_stmt|;
comment|// Reserved [41:36]
name|UINT32
name|SdSpec4
range|:
literal|1
decl_stmt|;
comment|// Spec. Version 4.00 or higher [42:42]
name|UINT32
name|ExSecurity
range|:
literal|4
decl_stmt|;
comment|// Extended Security Support [46:43]
name|UINT32
name|SdSpec3
range|:
literal|1
decl_stmt|;
comment|// Spec. Version 3.00 or higher [47:47]
name|UINT32
name|SdBusWidths
range|:
literal|4
decl_stmt|;
comment|// DAT Bus widths supported [51:48]
name|UINT32
name|SdSecurity
range|:
literal|3
decl_stmt|;
comment|// CPRM security support [54:52]
name|UINT32
name|DataStatAfterErase
range|:
literal|1
decl_stmt|;
comment|// Data status after erases [55]
name|UINT32
name|SdSpec
range|:
literal|4
decl_stmt|;
comment|// SD Memory Card Spec. Version [59:56]
name|UINT32
name|ScrStructure
range|:
literal|4
decl_stmt|;
comment|// SCR Structure [63:60]
block|}
name|SD_SCR
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

