begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Header file for eMMC support.    This header file contains some definitions defined in EMMC4.5/EMMC5.0 spec.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EMMC_H__
end_ifndef

begin_define
define|#
directive|define
name|__EMMC_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EMMC command index
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EMMC_GO_IDLE_STATE
value|0
end_define

begin_define
define|#
directive|define
name|EMMC_SEND_OP_COND
value|1
end_define

begin_define
define|#
directive|define
name|EMMC_ALL_SEND_CID
value|2
end_define

begin_define
define|#
directive|define
name|EMMC_SET_RELATIVE_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|EMMC_SET_DSR
value|4
end_define

begin_define
define|#
directive|define
name|EMMC_SLEEP_AWAKE
value|5
end_define

begin_define
define|#
directive|define
name|EMMC_SWITCH
value|6
end_define

begin_define
define|#
directive|define
name|EMMC_SELECT_DESELECT_CARD
value|7
end_define

begin_define
define|#
directive|define
name|EMMC_SEND_EXT_CSD
value|8
end_define

begin_define
define|#
directive|define
name|EMMC_SEND_CSD
value|9
end_define

begin_define
define|#
directive|define
name|EMMC_SEND_CID
value|10
end_define

begin_define
define|#
directive|define
name|EMMC_STOP_TRANSMISSION
value|12
end_define

begin_define
define|#
directive|define
name|EMMC_SEND_STATUS
value|13
end_define

begin_define
define|#
directive|define
name|EMMC_BUSTEST_R
value|14
end_define

begin_define
define|#
directive|define
name|EMMC_GO_INACTIVE_STATE
value|15
end_define

begin_define
define|#
directive|define
name|EMMC_SET_BLOCKLEN
value|16
end_define

begin_define
define|#
directive|define
name|EMMC_READ_SINGLE_BLOCK
value|17
end_define

begin_define
define|#
directive|define
name|EMMC_READ_MULTIPLE_BLOCK
value|18
end_define

begin_define
define|#
directive|define
name|EMMC_BUSTEST_W
value|19
end_define

begin_define
define|#
directive|define
name|EMMC_SEND_TUNING_BLOCK
value|21
end_define

begin_define
define|#
directive|define
name|EMMC_SET_BLOCK_COUNT
value|23
end_define

begin_define
define|#
directive|define
name|EMMC_WRITE_BLOCK
value|24
end_define

begin_define
define|#
directive|define
name|EMMC_WRITE_MULTIPLE_BLOCK
value|25
end_define

begin_define
define|#
directive|define
name|EMMC_PROGRAM_CID
value|26
end_define

begin_define
define|#
directive|define
name|EMMC_PROGRAM_CSD
value|27
end_define

begin_define
define|#
directive|define
name|EMMC_SET_WRITE_PROT
value|28
end_define

begin_define
define|#
directive|define
name|EMMC_CLR_WRITE_PROT
value|29
end_define

begin_define
define|#
directive|define
name|EMMC_SEND_WRITE_PROT
value|30
end_define

begin_define
define|#
directive|define
name|EMMC_SEND_WRITE_PROT_TYPE
value|31
end_define

begin_define
define|#
directive|define
name|EMMC_ERASE_GROUP_START
value|35
end_define

begin_define
define|#
directive|define
name|EMMC_ERASE_GROUP_END
value|36
end_define

begin_define
define|#
directive|define
name|EMMC_ERASE
value|38
end_define

begin_define
define|#
directive|define
name|EMMC_FAST_IO
value|39
end_define

begin_define
define|#
directive|define
name|EMMC_GO_IRQ_STATE
value|40
end_define

begin_define
define|#
directive|define
name|EMMC_LOCK_UNLOCK
value|42
end_define

begin_define
define|#
directive|define
name|EMMC_SET_TIME
value|49
end_define

begin_define
define|#
directive|define
name|EMMC_PROTOCOL_RD
value|53
end_define

begin_define
define|#
directive|define
name|EMMC_PROTOCOL_WR
value|54
end_define

begin_define
define|#
directive|define
name|EMMC_APP_CMD
value|55
end_define

begin_define
define|#
directive|define
name|EMMC_GEN_CMD
value|56
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|EmmcPartitionUserData
init|=
literal|0
block|,
name|EmmcPartitionBoot1
init|=
literal|1
block|,
name|EmmcPartitionBoot2
init|=
literal|2
block|,
name|EmmcPartitionRPMB
init|=
literal|3
block|,
name|EmmcPartitionGP1
init|=
literal|4
block|,
name|EmmcPartitionGP2
init|=
literal|5
block|,
name|EmmcPartitionGP3
init|=
literal|6
block|,
name|EmmcPartitionGP4
init|=
literal|7
block|,
name|EmmcPartitionUnknown
block|}
name|EMMC_PARTITION_TYPE
typedef|;
end_typedef

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
name|UINT8
name|ManufacturingDate
decl_stmt|;
comment|// Manufacturing date [15:8]
name|UINT8
name|ProductSerialNumber
index|[
literal|4
index|]
decl_stmt|;
comment|// Product serial number [47:16]
name|UINT8
name|ProductRevision
decl_stmt|;
comment|// Product revision [55:48]
name|UINT8
name|ProductName
index|[
literal|6
index|]
decl_stmt|;
comment|// Product name [103:56]
name|UINT8
name|OemId
decl_stmt|;
comment|// OEM/Application ID [111:104]
name|UINT8
name|DeviceType
range|:
literal|2
decl_stmt|;
comment|// Device/BGA [113:112]
name|UINT8
name|Reserved
range|:
literal|6
decl_stmt|;
comment|// Reserved [119:114]
name|UINT8
name|ManufacturerId
decl_stmt|;
comment|// Manufacturer ID [127:120]
block|}
name|EMMC_CID
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
name|Ecc
range|:
literal|2
decl_stmt|;
comment|// ECC code [9:8]
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
name|ContentProtApp
range|:
literal|1
decl_stmt|;
comment|// Content protection application [16:16]
name|UINT32
name|Reserved
range|:
literal|4
decl_stmt|;
comment|// Reserved [20:17]
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
name|DefaultEcc
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
literal|5
decl_stmt|;
comment|// Write protect group size [36:32]
name|UINT32
name|EraseGrpMult
range|:
literal|5
decl_stmt|;
comment|// Erase group size multiplier [41:37]
name|UINT32
name|EraseGrpSize
range|:
literal|5
decl_stmt|;
comment|// Erase group size [46:42]
name|UINT32
name|CSizeMult
range|:
literal|3
decl_stmt|;
comment|// Device size multiplier [49:47]
name|UINT32
name|VddWCurrMax
range|:
literal|3
decl_stmt|;
comment|// Max. write current @ VDD max [52:50]
name|UINT32
name|VddWCurrMin
range|:
literal|3
decl_stmt|;
comment|// Max. write current @ VDD min [55:53]
name|UINT32
name|VddRCurrMax
range|:
literal|3
decl_stmt|;
comment|// Max. read current @ VDD max [58:56]
name|UINT32
name|VddRCurrMin
range|:
literal|3
decl_stmt|;
comment|// Max. read current @ VDD min [61:59]
name|UINT32
name|CSizeLow
range|:
literal|2
decl_stmt|;
comment|// Device size low two bits [63:62]
name|UINT32
name|CSizeHigh
range|:
literal|10
decl_stmt|;
comment|// Device size high eight bits [73:64]
name|UINT32
name|Reserved1
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
comment|// Device command classes [95:84]
name|UINT32
name|TranSpeed
range|:
literal|8
decl_stmt|;
comment|// Max. bus clock frequency [103:96]
name|UINT32
name|Nsac
range|:
literal|8
decl_stmt|;
comment|// Data read access-time 2 in CLK cycles (NSAC*100) [111:104]
name|UINT32
name|Taac
range|:
literal|8
decl_stmt|;
comment|// Data read access-time 1 [119:112]
name|UINT32
name|Reserved2
range|:
literal|2
decl_stmt|;
comment|// Reserved [121:120]
name|UINT32
name|SpecVers
range|:
literal|4
decl_stmt|;
comment|// System specification version [125:122]
name|UINT32
name|CsdStructure
range|:
literal|2
decl_stmt|;
comment|// CSD structure [127:126]
block|}
name|EMMC_CSD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Modes Segment
comment|//
name|UINT8
name|Reserved
index|[
literal|16
index|]
decl_stmt|;
comment|// Reserved [15:0]
name|UINT8
name|SecureRemovalType
decl_stmt|;
comment|// Secure Removal Type R/W& R [16]
name|UINT8
name|ProductStateAwarenessEnablement
decl_stmt|;
comment|// Product state awareness enablement R/W/E& R [17]
name|UINT8
name|MaxPreLoadingDataSize
index|[
literal|4
index|]
decl_stmt|;
comment|// Max pre loading data size R [21:18]
name|UINT8
name|PreLoadingDataSize
index|[
literal|4
index|]
decl_stmt|;
comment|// Pre loading data size R/W/EP [25:22]
name|UINT8
name|FfuStatus
decl_stmt|;
comment|// FFU status R [26]
name|UINT8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|// Reserved [28:27]
name|UINT8
name|ModeOperationCodes
decl_stmt|;
comment|// Mode operation codes W/EP [29]
name|UINT8
name|ModeConfig
decl_stmt|;
comment|// Mode config R/W/EP [30]
name|UINT8
name|Reserved2
decl_stmt|;
comment|// Reserved [31]
name|UINT8
name|FlushCache
decl_stmt|;
comment|// Flushing of the cache W/EP [32]
name|UINT8
name|CacheCtrl
decl_stmt|;
comment|// Control to turn the Cache ON/OFF R/W/EP [33]
name|UINT8
name|PowerOffNotification
decl_stmt|;
comment|// Power Off Notification R/W/EP [34]
name|UINT8
name|PackedFailureIndex
decl_stmt|;
comment|// Packed command failure index R [35]
name|UINT8
name|PackedCommandStatus
decl_stmt|;
comment|// Packed command status R [36]
name|UINT8
name|ContextConf
index|[
literal|15
index|]
decl_stmt|;
comment|// Context configuration R/W/EP [51:37]
name|UINT8
name|ExtPartitionsAttribute
index|[
literal|2
index|]
decl_stmt|;
comment|// Extended Partitions Attribute R/W [53:52]
name|UINT8
name|ExceptionEventsStatus
index|[
literal|2
index|]
decl_stmt|;
comment|// Exception events status R [55:54]
name|UINT8
name|ExceptionEventsCtrl
index|[
literal|2
index|]
decl_stmt|;
comment|// Exception events control R/W/EP [57:56]
name|UINT8
name|DyncapNeeded
decl_stmt|;
comment|// Number of addressed group to be Released R [58]
name|UINT8
name|Class6Ctrl
decl_stmt|;
comment|// Class 6 commands control R/W/EP [59]
name|UINT8
name|IniTimeoutEmu
decl_stmt|;
comment|// 1st initialization after disabling sector size emulation R [60]
name|UINT8
name|DataSectorSize
decl_stmt|;
comment|// Sector size R [61]
name|UINT8
name|UseNativeSector
decl_stmt|;
comment|// Sector size emulation R/W [62]
name|UINT8
name|NativeSectorSize
decl_stmt|;
comment|// Native sector size R [63]
name|UINT8
name|VendorSpecificField
index|[
literal|64
index|]
decl_stmt|;
comment|// Vendor Specific Fields<vendor specific> [127:64]
name|UINT8
name|Reserved3
index|[
literal|2
index|]
decl_stmt|;
comment|// Reserved [129:128]
name|UINT8
name|ProgramCidCsdDdrSupport
decl_stmt|;
comment|// Program CID/CSD in DDR mode support R [130]
name|UINT8
name|PeriodicWakeup
decl_stmt|;
comment|// Periodic Wake-up R/W/E [131]
name|UINT8
name|TcaseSupport
decl_stmt|;
comment|// Package Case Temperature is controlled W/EP [132]
name|UINT8
name|ProductionStateAwareness
decl_stmt|;
comment|// Production state awareness R/W/E [133]
name|UINT8
name|SecBadBlkMgmnt
decl_stmt|;
comment|// Bad Block Management mode R/W [134]
name|UINT8
name|Reserved4
decl_stmt|;
comment|// Reserved [135]
name|UINT8
name|EnhStartAddr
index|[
literal|4
index|]
decl_stmt|;
comment|// Enhanced User Data Start Address R/W [139:136]
name|UINT8
name|EnhSizeMult
index|[
literal|3
index|]
decl_stmt|;
comment|// Enhanced User Data Area Size R/W [142:140]
name|UINT8
name|GpSizeMult
index|[
literal|12
index|]
decl_stmt|;
comment|// General Purpose Partition Size R/W [154:143]
name|UINT8
name|PartitionSettingCompleted
decl_stmt|;
comment|// Partitioning Setting R/W [155]
name|UINT8
name|PartitionsAttribute
decl_stmt|;
comment|// Partitions attribute R/W [156]
name|UINT8
name|MaxEnhSizeMult
index|[
literal|3
index|]
decl_stmt|;
comment|// Max Enhanced Area Size R [159:157]
name|UINT8
name|PartitioningSupport
decl_stmt|;
comment|// Partitioning Support R [160]
name|UINT8
name|HpiMgmt
decl_stmt|;
comment|// HPI management R/W/EP [161]
name|UINT8
name|RstFunction
decl_stmt|;
comment|// H/W reset function R/W [162]
name|UINT8
name|BkopsEn
decl_stmt|;
comment|// Enable background operations handshake R/W [163]
name|UINT8
name|BkopsStart
decl_stmt|;
comment|// Manually start background operations W/EP [164]
name|UINT8
name|SanitizeStart
decl_stmt|;
comment|// Start Sanitize operation W/EP [165]
name|UINT8
name|WrRelParam
decl_stmt|;
comment|// Write reliability parameter register R [166]
name|UINT8
name|WrRelSet
decl_stmt|;
comment|// Write reliability setting register R/W [167]
name|UINT8
name|RpmbSizeMult
decl_stmt|;
comment|// RPMB Size R [168]
name|UINT8
name|FwConfig
decl_stmt|;
comment|// FW configuration R/W [169]
name|UINT8
name|Reserved5
decl_stmt|;
comment|// Reserved [170]
name|UINT8
name|UserWp
decl_stmt|;
comment|// User area write protection register R/W,R/W/CP&R/W/EP [171]
name|UINT8
name|Reserved6
decl_stmt|;
comment|// Reserved [172]
name|UINT8
name|BootWp
decl_stmt|;
comment|// Boot area write protection register R/W&R/W/CP[173]
name|UINT8
name|BootWpStatus
decl_stmt|;
comment|// Boot write protection status registers R [174]
name|UINT8
name|EraseGroupDef
decl_stmt|;
comment|// High-density erase group definition R/W/EP [175]
name|UINT8
name|Reserved7
decl_stmt|;
comment|// Reserved [176]
name|UINT8
name|BootBusConditions
decl_stmt|;
comment|// Boot bus Conditions R/W/E [177]
name|UINT8
name|BootConfigProt
decl_stmt|;
comment|// Boot config protection R/W&R/W/CP[178]
name|UINT8
name|PartitionConfig
decl_stmt|;
comment|// Partition configuration R/W/E&R/W/EP[179]
name|UINT8
name|Reserved8
decl_stmt|;
comment|// Reserved [180]
name|UINT8
name|ErasedMemCont
decl_stmt|;
comment|// Erased memory content R [181]
name|UINT8
name|Reserved9
decl_stmt|;
comment|// Reserved [182]
name|UINT8
name|BusWidth
decl_stmt|;
comment|// Bus width mode W/EP [183]
name|UINT8
name|Reserved10
decl_stmt|;
comment|// Reserved [184]
name|UINT8
name|HsTiming
decl_stmt|;
comment|// High-speed interface timing R/W/EP [185]
name|UINT8
name|Reserved11
decl_stmt|;
comment|// Reserved [186]
name|UINT8
name|PowerClass
decl_stmt|;
comment|// Power class R/W/EP [187]
name|UINT8
name|Reserved12
decl_stmt|;
comment|// Reserved [188]
name|UINT8
name|CmdSetRev
decl_stmt|;
comment|// Command set revision R [189]
name|UINT8
name|Reserved13
decl_stmt|;
comment|// Reserved [190]
name|UINT8
name|CmdSet
decl_stmt|;
comment|// Command set R/W/EP [191]
comment|//
comment|// Properties Segment
comment|//
name|UINT8
name|ExtCsdRev
decl_stmt|;
comment|// Extended CSD revision [192]
name|UINT8
name|Reserved14
decl_stmt|;
comment|// Reserved [193]
name|UINT8
name|CsdStructure
decl_stmt|;
comment|// CSD STRUCTURE [194]
name|UINT8
name|Reserved15
decl_stmt|;
comment|// Reserved [195]
name|UINT8
name|DeviceType
decl_stmt|;
comment|// Device type [196]
name|UINT8
name|DriverStrength
decl_stmt|;
comment|// I/O Driver Strength [197]
name|UINT8
name|OutOfInterruptTime
decl_stmt|;
comment|// Out-of-interrupt busy timing[198]
name|UINT8
name|PartitionSwitchTime
decl_stmt|;
comment|// Partition switching timing [199]
name|UINT8
name|PwrCl52M195V
decl_stmt|;
comment|// Power class for 52MHz at 1.95V [200]
name|UINT8
name|PwrCl26M195V
decl_stmt|;
comment|// Power class for 26MHz at 1.95V [201]
name|UINT8
name|PwrCl52M360V
decl_stmt|;
comment|// Power class for 52MHz at 3.6V [202]
name|UINT8
name|PwrCl26M360V
decl_stmt|;
comment|// Power class for 26MHz at 3.6V [203]
name|UINT8
name|Reserved16
decl_stmt|;
comment|// Reserved [204]
name|UINT8
name|MinPerfR4B26M
decl_stmt|;
comment|// Minimum Read Performance for 4bit at 26MHz [205]
name|UINT8
name|MinPerfW4B26M
decl_stmt|;
comment|// Minimum Write Performance for 4bit at 26MHz [206]
name|UINT8
name|MinPerfR8B26M4B52M
decl_stmt|;
comment|// Minimum Read Performance for 8bit at 26MHz, for 4bit at 52MHz [207]
name|UINT8
name|MinPerfW8B26M4B52M
decl_stmt|;
comment|// Minimum Write Performance for 8bit at 26MHz, for 4bit at 52MHz [208]
name|UINT8
name|MinPerfR8B52M
decl_stmt|;
comment|// Minimum Read Performance for 8bit at 52MHz [209]
name|UINT8
name|MinPerfW8B52M
decl_stmt|;
comment|// Minimum Write Performance for 8bit at 52MHz [210]
name|UINT8
name|Reserved17
decl_stmt|;
comment|// Reserved [211]
name|UINT8
name|SecCount
index|[
literal|4
index|]
decl_stmt|;
comment|// Sector Count [215:212]
name|UINT8
name|SleepNotificationTime
decl_stmt|;
comment|// Sleep Notification Timout [216]
name|UINT8
name|SATimeout
decl_stmt|;
comment|// Sleep/awake timeout [217]
name|UINT8
name|ProductionStateAwarenessTimeout
decl_stmt|;
comment|// Production state awareness timeout [218]
name|UINT8
name|SCVccq
decl_stmt|;
comment|// Sleep current (VCCQ) [219]
name|UINT8
name|SCVcc
decl_stmt|;
comment|// Sleep current (VCC) [220]
name|UINT8
name|HcWpGrpSize
decl_stmt|;
comment|// High-capacity write protect group size [221]
name|UINT8
name|RelWrSecC
decl_stmt|;
comment|// Reliable write sector count [222]
name|UINT8
name|EraseTimeoutMult
decl_stmt|;
comment|// High-capacity erase timeout [223]
name|UINT8
name|HcEraseGrpSize
decl_stmt|;
comment|// High-capacity erase unit size [224]
name|UINT8
name|AccSize
decl_stmt|;
comment|// Access size [225]
name|UINT8
name|BootSizeMult
decl_stmt|;
comment|// Boot partition size [226]
name|UINT8
name|Reserved18
decl_stmt|;
comment|// Reserved [227]
name|UINT8
name|BootInfo
decl_stmt|;
comment|// Boot information [228]
name|UINT8
name|SecTrimMult
decl_stmt|;
comment|// Secure TRIM Multiplier [229]
name|UINT8
name|SecEraseMult
decl_stmt|;
comment|// Secure Erase Multiplier [230]
name|UINT8
name|SecFeatureSupport
decl_stmt|;
comment|// Secure Feature support [231]
name|UINT8
name|TrimMult
decl_stmt|;
comment|// TRIM Multiplier [232]
name|UINT8
name|Reserved19
decl_stmt|;
comment|// Reserved [233]
name|UINT8
name|MinPerfDdrR8b52M
decl_stmt|;
comment|// Minimum Read Performance for 8bit at 52MHz in DDR mode [234]
name|UINT8
name|MinPerfDdrW8b52M
decl_stmt|;
comment|// Minimum Write Performance for 8bit at 52MHz in DDR mode [235]
name|UINT8
name|PwrCl200M130V
decl_stmt|;
comment|// Power class for 200MHz, at VCCQ=1.3V, VCC = 3.6V [236]
name|UINT8
name|PwrCl200M195V
decl_stmt|;
comment|// Power class for 200MHz at VCCQ=1.95V, VCC = 3.6V [237]
name|UINT8
name|PwrClDdr52M195V
decl_stmt|;
comment|// Power class for 52MHz, DDR at VCC= 1.95V [238]
name|UINT8
name|PwrClDdr52M360V
decl_stmt|;
comment|// Power class for 52MHz, DDR at VCC= 3.6V [239]
name|UINT8
name|Reserved20
decl_stmt|;
comment|// Reserved [240]
name|UINT8
name|IniTimeoutAp
decl_stmt|;
comment|// 1st initialization time after partitioning [241]
name|UINT8
name|CorrectlyPrgSectorsNum
index|[
literal|4
index|]
decl_stmt|;
comment|// Number of correctly programmed sectors [245:242]
name|UINT8
name|BkopsStatus
decl_stmt|;
comment|// Background operations status [246]
name|UINT8
name|PowerOffLongTime
decl_stmt|;
comment|// Power off notification(long) timeout [247]
name|UINT8
name|GenericCmd6Time
decl_stmt|;
comment|// Generic CMD6 timeout [248]
name|UINT8
name|CacheSize
index|[
literal|4
index|]
decl_stmt|;
comment|// Cache size [252:249]
name|UINT8
name|PwrClDdr200M360V
decl_stmt|;
comment|// Power class for 200MHz, DDR at VCC= 3.6V [253]
name|UINT8
name|FirmwareVersion
index|[
literal|8
index|]
decl_stmt|;
comment|// Firmware version [261:254]
name|UINT8
name|DeviceVersion
index|[
literal|2
index|]
decl_stmt|;
comment|// Device version [263:262]
name|UINT8
name|OptimalTrimUnitSize
decl_stmt|;
comment|// Optimal trim unit size[264]
name|UINT8
name|OptimalWriteSize
decl_stmt|;
comment|// Optimal write size [265]
name|UINT8
name|OptimalReadSize
decl_stmt|;
comment|// Optimal read size [266]
name|UINT8
name|PreEolInfo
decl_stmt|;
comment|// Pre EOL information [267]
name|UINT8
name|DeviceLifeTimeEstTypA
decl_stmt|;
comment|// Device life time estimation type A [268]
name|UINT8
name|DeviceLifeTimeEstTypB
decl_stmt|;
comment|// Device life time estimation type B [269]
name|UINT8
name|VendorProprietaryHealthReport
index|[
literal|32
index|]
decl_stmt|;
comment|// Vendor proprietary health report [301:270]
name|UINT8
name|NumOfFwSectorsProgrammed
index|[
literal|4
index|]
decl_stmt|;
comment|// Number of FW sectors correctly programmed [305:302]
name|UINT8
name|Reserved21
index|[
literal|181
index|]
decl_stmt|;
comment|// Reserved [486:306]
name|UINT8
name|FfuArg
index|[
literal|4
index|]
decl_stmt|;
comment|// FFU Argument [490:487]
name|UINT8
name|OperationCodeTimeout
decl_stmt|;
comment|// Operation codes timeout [491]
name|UINT8
name|FfuFeatures
decl_stmt|;
comment|// FFU features [492]
name|UINT8
name|SupportedModes
decl_stmt|;
comment|// Supported modes [493]
name|UINT8
name|ExtSupport
decl_stmt|;
comment|// Extended partitions attribute support [494]
name|UINT8
name|LargeUnitSizeM1
decl_stmt|;
comment|// Large Unit size [495]
name|UINT8
name|ContextCapabilities
decl_stmt|;
comment|// Context management capabilities [496]
name|UINT8
name|TagResSize
decl_stmt|;
comment|// Tag Resources Size [497]
name|UINT8
name|TagUnitSize
decl_stmt|;
comment|// Tag Unit Size [498]
name|UINT8
name|DataTagSupport
decl_stmt|;
comment|// Data Tag Support [499]
name|UINT8
name|MaxPackedWrites
decl_stmt|;
comment|// Max packed write commands [500]
name|UINT8
name|MaxPackedReads
decl_stmt|;
comment|// Max packed read commands[501]
name|UINT8
name|BkOpsSupport
decl_stmt|;
comment|// Background operations support [502]
name|UINT8
name|HpiFeatures
decl_stmt|;
comment|// HPI features [503]
name|UINT8
name|SupportedCmdSet
decl_stmt|;
comment|// Supported Command Sets [504]
name|UINT8
name|ExtSecurityErr
decl_stmt|;
comment|// Extended Security Commands Error [505]
name|UINT8
name|Reserved22
index|[
literal|6
index|]
decl_stmt|;
comment|// Reserved [511:506]
block|}
name|EMMC_EXT_CSD
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

