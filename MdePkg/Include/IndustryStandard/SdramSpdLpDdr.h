begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file contains definitions for SPD LPDDR.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:     - Serial Presence Detect (SPD) for LPDDR3 and LPDDR4 SDRAM Modules Document Release 2       http://www.jedec.org/standards-documents/docs/spd412m-2 **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SDRAM_SPD_LPDDR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SDRAM_SPD_LPDDR_H_
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|BytesUsed
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|BytesTotal
range|:
literal|3
decl_stmt|;
comment|///< Bits 6:4
name|UINT8
name|CrcCoverage
range|:
literal|1
decl_stmt|;
comment|///< Bits 7:7
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_DEVICE_DESCRIPTION_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Minor
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|Major
range|:
literal|4
decl_stmt|;
comment|///< Bits 7:4
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_REVISION_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Type
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_DRAM_DEVICE_TYPE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|ModuleType
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|HybridMedia
range|:
literal|3
decl_stmt|;
comment|///< Bits 6:4
name|UINT8
name|Hybrid
range|:
literal|1
decl_stmt|;
comment|///< Bits 7:7
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_MODULE_TYPE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Density
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|BankAddress
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|BankGroup
range|:
literal|2
decl_stmt|;
comment|///< Bits 7:6
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_SDRAM_DENSITY_BANKS_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|ColumnAddress
range|:
literal|3
decl_stmt|;
comment|///< Bits 2:0
name|UINT8
name|RowAddress
range|:
literal|3
decl_stmt|;
comment|///< Bits 5:3
name|UINT8
name|Reserved
range|:
literal|2
decl_stmt|;
comment|///< Bits 7:6
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_SDRAM_ADDRESSING_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|SignalLoading
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|ChannelsPerDie
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|DieCount
range|:
literal|3
decl_stmt|;
comment|///< Bits 6:4
name|UINT8
name|SdramPackageType
range|:
literal|1
decl_stmt|;
comment|///< Bits 7:7
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_SDRAM_PACKAGE_TYPE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|MaximumActivateCount
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|MaximumActivateWindow
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|Reserved
range|:
literal|2
decl_stmt|;
comment|///< Bits 7:6
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_SDRAM_OPTIONAL_FEATURES_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Reserved
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_SDRAM_THERMAL_REFRESH_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Reserved
range|:
literal|5
decl_stmt|;
comment|///< Bits 4:0
name|UINT8
name|SoftPPR
range|:
literal|1
decl_stmt|;
comment|///< Bits 5:5
name|UINT8
name|PostPackageRepair
range|:
literal|2
decl_stmt|;
comment|///< Bits 7:6
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_OTHER_SDRAM_OPTIONAL_FEATURES_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|OperationAt1_20
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|EndurantAt1_20
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT8
name|OperationAt1_10
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT8
name|EndurantAt1_10
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT8
name|OperationAtTBD2V
range|:
literal|1
decl_stmt|;
comment|///< Bits 4:4
name|UINT8
name|EndurantAtTBD2V
range|:
literal|1
decl_stmt|;
comment|///< Bits 5:5
name|UINT8
name|Reserved
range|:
literal|2
decl_stmt|;
comment|///< Bits 7:6
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_MODULE_NOMINAL_VOLTAGE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|SdramDeviceWidth
range|:
literal|3
decl_stmt|;
comment|///< Bits 2:0
name|UINT8
name|RankCount
range|:
literal|3
decl_stmt|;
comment|///< Bits 5:3
name|UINT8
name|Reserved
range|:
literal|2
decl_stmt|;
comment|///< Bits 7:6
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_MODULE_ORGANIZATION_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|PrimaryBusWidth
range|:
literal|3
decl_stmt|;
comment|///< Bits 2:0
name|UINT8
name|BusWidthExtension
range|:
literal|2
decl_stmt|;
comment|///< Bits 4:3
name|UINT8
name|NumberofChannels
range|:
literal|3
decl_stmt|;
comment|///< Bits 7:5
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_MODULE_MEMORY_BUS_WIDTH_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Reserved
range|:
literal|7
decl_stmt|;
comment|///< Bits 6:0
name|UINT8
name|ThermalSensorPresence
range|:
literal|1
decl_stmt|;
comment|///< Bits 7:7
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_MODULE_THERMAL_SENSOR_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|ExtendedBaseModuleType
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
comment|///< Bits 7:4
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_EXTENDED_MODULE_TYPE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|ChipSelectLoading
range|:
literal|3
decl_stmt|;
comment|///< Bits 2:0
name|UINT8
name|CommandAddressControlClockLoading
range|:
literal|3
decl_stmt|;
comment|///< Bits 5:3
name|UINT8
name|DataStrobeMaskLoading
range|:
literal|2
decl_stmt|;
comment|///< Bits 7:6
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_SIGNAL_LOADING_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Fine
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|Medium
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
comment|///< Bits 7:4
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TIMEBASE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tCKmin
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TCK_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tCKmax
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TCK_MAX_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|Cl3
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT32
name|Cl6
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT32
name|Cl8
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT32
name|Cl9
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT32
name|Cl10
range|:
literal|1
decl_stmt|;
comment|///< Bits 4:4
name|UINT32
name|Cl11
range|:
literal|1
decl_stmt|;
comment|///< Bits 5:5
name|UINT32
name|Cl12
range|:
literal|1
decl_stmt|;
comment|///< Bits 6:6
name|UINT32
name|Cl14
range|:
literal|1
decl_stmt|;
comment|///< Bits 7:7
name|UINT32
name|Cl16
range|:
literal|1
decl_stmt|;
comment|///< Bits 8:8
name|UINT32
name|Reserved0
range|:
literal|1
decl_stmt|;
comment|///< Bits 9:9
name|UINT32
name|Cl20
range|:
literal|1
decl_stmt|;
comment|///< Bits 10:10
name|UINT32
name|Cl22
range|:
literal|1
decl_stmt|;
comment|///< Bits 11:11
name|UINT32
name|Cl24
range|:
literal|1
decl_stmt|;
comment|///< Bits 12:12
name|UINT32
name|Reserved1
range|:
literal|1
decl_stmt|;
comment|///< Bits 13:13
name|UINT32
name|Cl28
range|:
literal|1
decl_stmt|;
comment|///< Bits 14:14
name|UINT32
name|Reserved2
range|:
literal|1
decl_stmt|;
comment|///< Bits 15:15
name|UINT32
name|Cl32
range|:
literal|1
decl_stmt|;
comment|///< Bits 16:16
name|UINT32
name|Reserved3
range|:
literal|1
decl_stmt|;
comment|///< Bits 17:17
name|UINT32
name|Cl36
range|:
literal|1
decl_stmt|;
comment|///< Bits 18:18
name|UINT32
name|Reserved4
range|:
literal|1
decl_stmt|;
comment|///< Bits 19:19
name|UINT32
name|Cl40
range|:
literal|1
decl_stmt|;
comment|///< Bits 20:20
name|UINT32
name|Reserved5
range|:
literal|11
decl_stmt|;
comment|///< Bits 31:21
block|}
name|Bits
struct|;
name|UINT32
name|Data
decl_stmt|;
name|UINT16
name|Data16
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|Data8
index|[
literal|4
index|]
decl_stmt|;
block|}
name|SPD_LPDDR_CAS_LATENCIES_SUPPORTED_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tAAmin
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TAA_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|ReadLatencyMode
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|WriteLatencySet
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
comment|///< Bits 7:4
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_RW_LATENCY_OPTION_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tRCDmin
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TRCD_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tRPab
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TRP_AB_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tRPpb
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TRP_PB_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT16
name|tRFCab
range|:
literal|16
decl_stmt|;
comment|///< Bits 15:0
block|}
name|Bits
struct|;
name|UINT16
name|Data
decl_stmt|;
name|UINT8
name|Data8
index|[
literal|2
index|]
decl_stmt|;
block|}
name|SPD_LPDDR_TRFC_AB_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT16
name|tRFCpb
range|:
literal|16
decl_stmt|;
comment|///< Bits 15:0
block|}
name|Bits
struct|;
name|UINT16
name|Data
decl_stmt|;
name|UINT8
name|Data8
index|[
literal|2
index|]
decl_stmt|;
block|}
name|SPD_LPDDR_TRFC_PB_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|BitOrderatSDRAM
range|:
literal|5
decl_stmt|;
comment|///< Bits 4:0
name|UINT8
name|WiredtoUpperLowerNibble
range|:
literal|1
decl_stmt|;
comment|///< Bits 5:5
name|UINT8
name|PackageRankMap
range|:
literal|2
decl_stmt|;
comment|///< Bits 7:6
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_CONNECTOR_BIT_MAPPING_BYTE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tRPpbFine
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|INT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TRP_PB_FTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tRPabFine
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|INT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TRP_AB_FTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tRCDminFine
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|INT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TRCD_MIN_FTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tAAminFine
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|INT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TAA_MIN_FTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tCKmaxFine
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|INT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TCK_MAX_FTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tCKminFine
range|:
literal|8
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|INT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_TCK_MIN_FTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT16
name|ContinuationCount
range|:
literal|7
decl_stmt|;
comment|///< Bits 6:0
name|UINT16
name|ContinuationParity
range|:
literal|1
decl_stmt|;
comment|///< Bits 7:7
name|UINT16
name|LastNonZeroByte
range|:
literal|8
decl_stmt|;
comment|///< Bits 15:8
block|}
name|Bits
struct|;
name|UINT16
name|Data
decl_stmt|;
name|UINT8
name|Data8
index|[
literal|2
index|]
decl_stmt|;
block|}
name|SPD_LPDDR_MANUFACTURER_ID_CODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Location
decl_stmt|;
comment|///< Module Manufacturing Location
block|}
name|SPD_LPDDR_MANUFACTURING_LOCATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Year
decl_stmt|;
comment|///< Year represented in BCD (00h = 2000)
name|UINT8
name|Week
decl_stmt|;
comment|///< Year represented in BCD (47h = week 47)
block|}
name|SPD_LPDDR_MANUFACTURING_DATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT32
name|Data
decl_stmt|;
name|UINT16
name|SerialNumber16
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|SerialNumber8
index|[
literal|4
index|]
decl_stmt|;
block|}
name|SPD_LPDDR_MANUFACTURER_SERIAL_NUMBER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD_LPDDR_MANUFACTURER_ID_CODE
name|IdCode
decl_stmt|;
comment|///< Module Manufacturer ID Code
name|SPD_LPDDR_MANUFACTURING_LOCATION
name|Location
decl_stmt|;
comment|///< Module Manufacturing Location
name|SPD_LPDDR_MANUFACTURING_DATE
name|Date
decl_stmt|;
comment|///< Module Manufacturing Year, in BCD (range: 2000-2255)
name|SPD_LPDDR_MANUFACTURER_SERIAL_NUMBER
name|SerialNumber
decl_stmt|;
comment|///< Module Serial Number
block|}
name|SPD_LPDDR_UNIQUE_MODULE_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|FrontThickness
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|BackThickness
range|:
literal|4
decl_stmt|;
comment|///< Bits 7:4
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_MODULE_MAXIMUM_THICKNESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Height
range|:
literal|5
decl_stmt|;
comment|///< Bits 4:0
name|UINT8
name|RawCardExtension
range|:
literal|3
decl_stmt|;
comment|///< Bits 7:5
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_MODULE_NOMINAL_HEIGHT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Card
range|:
literal|5
decl_stmt|;
comment|///< Bits 4:0
name|UINT8
name|Revision
range|:
literal|2
decl_stmt|;
comment|///< Bits 6:5
name|UINT8
name|Extension
range|:
literal|1
decl_stmt|;
comment|///< Bits 7:7
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD_LPDDR_REFERENCE_RAW_CARD
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT16
name|Crc
index|[
literal|1
index|]
decl_stmt|;
name|UINT8
name|Data8
index|[
literal|2
index|]
decl_stmt|;
block|}
name|SPD_LPDDR_CYCLIC_REDUNDANCY_CODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD_LPDDR_DEVICE_DESCRIPTION_STRUCT
name|Description
decl_stmt|;
comment|///< 0       Number of Serial PD Bytes Written / SPD Device Size / CRC Coverage 1, 2
name|SPD_LPDDR_REVISION_STRUCT
name|Revision
decl_stmt|;
comment|///< 1       SPD Revision
name|SPD_LPDDR_DRAM_DEVICE_TYPE_STRUCT
name|DramDeviceType
decl_stmt|;
comment|///< 2       DRAM Device Type
name|SPD_LPDDR_MODULE_TYPE_STRUCT
name|ModuleType
decl_stmt|;
comment|///< 3       Module Type
name|SPD_LPDDR_SDRAM_DENSITY_BANKS_STRUCT
name|SdramDensityAndBanks
decl_stmt|;
comment|///< 4       SDRAM Density and Banks
name|SPD_LPDDR_SDRAM_ADDRESSING_STRUCT
name|SdramAddressing
decl_stmt|;
comment|///< 5       SDRAM Addressing
name|SPD_LPDDR_SDRAM_PACKAGE_TYPE_STRUCT
name|SdramPackageType
decl_stmt|;
comment|///< 6       SDRAM Package Type
name|SPD_LPDDR_SDRAM_OPTIONAL_FEATURES_STRUCT
name|SdramOptionalFeatures
decl_stmt|;
comment|///< 7       SDRAM Optional Features
name|SPD_LPDDR_SDRAM_THERMAL_REFRESH_STRUCT
name|ThermalAndRefreshOptions
decl_stmt|;
comment|///< 8       SDRAM Thermal and Refresh Options
name|SPD_LPDDR_OTHER_SDRAM_OPTIONAL_FEATURES_STRUCT
name|OtherOptionalFeatures
decl_stmt|;
comment|///< 9      Other SDRAM Optional Features
name|UINT8
name|Reserved0
decl_stmt|;
comment|///< 10      Reserved
name|SPD_LPDDR_MODULE_NOMINAL_VOLTAGE_STRUCT
name|ModuleNominalVoltage
decl_stmt|;
comment|///< 11      Module Nominal Voltage, VDD
name|SPD_LPDDR_MODULE_ORGANIZATION_STRUCT
name|ModuleOrganization
decl_stmt|;
comment|///< 12      Module Organization
name|SPD_LPDDR_MODULE_MEMORY_BUS_WIDTH_STRUCT
name|ModuleMemoryBusWidth
decl_stmt|;
comment|///< 13      Module Memory Bus Width
name|SPD_LPDDR_MODULE_THERMAL_SENSOR_STRUCT
name|ModuleThermalSensor
decl_stmt|;
comment|///< 14      Module Thermal Sensor
name|SPD_LPDDR_EXTENDED_MODULE_TYPE_STRUCT
name|ExtendedModuleType
decl_stmt|;
comment|///< 15      Extended Module Type
name|SPD_LPDDR_SIGNAL_LOADING_STRUCT
name|SignalLoading
decl_stmt|;
comment|///< 16      Signal Loading
name|SPD_LPDDR_TIMEBASE_STRUCT
name|Timebase
decl_stmt|;
comment|///< 17      Timebases
name|SPD_LPDDR_TCK_MIN_MTB_STRUCT
name|tCKmin
decl_stmt|;
comment|///< 18      SDRAM Minimum Cycle Time (tCKmin)
name|SPD_LPDDR_TCK_MAX_MTB_STRUCT
name|tCKmax
decl_stmt|;
comment|///< 19      SDRAM Maximum Cycle Time (tCKmax)
name|SPD_LPDDR_CAS_LATENCIES_SUPPORTED_STRUCT
name|CasLatencies
decl_stmt|;
comment|///< 20-23   CAS Latencies Supported
name|SPD_LPDDR_TAA_MIN_MTB_STRUCT
name|tAAmin
decl_stmt|;
comment|///< 24      Minimum CAS Latency Time (tAAmin)
name|SPD_LPDDR_RW_LATENCY_OPTION_STRUCT
name|LatencySetOptions
decl_stmt|;
comment|///< 25      Read and Write Latency Set Options
name|SPD_LPDDR_TRCD_MIN_MTB_STRUCT
name|tRCDmin
decl_stmt|;
comment|///< 26      Minimum RAS# to CAS# Delay Time (tRCDmin)
name|SPD_LPDDR_TRP_AB_MTB_STRUCT
name|tRPab
decl_stmt|;
comment|///< 27      Minimum Row Precharge Delay Time (tRPab), all banks
name|SPD_LPDDR_TRP_PB_MTB_STRUCT
name|tRPpb
decl_stmt|;
comment|///< 28      Minimum Row Precharge Delay Time (tRPpb), per bank
name|SPD_LPDDR_TRFC_AB_MTB_STRUCT
name|tRFCab
decl_stmt|;
comment|///< 29-30   Minimum Refresh Recovery Delay Time (tRFCab), all banks
name|SPD_LPDDR_TRFC_PB_MTB_STRUCT
name|tRFCpb
decl_stmt|;
comment|///< 31-32   Minimum Refresh Recovery Delay Time (tRFCpb), per bank
name|UINT8
name|Reserved1
index|[
literal|59
operator|-
literal|33
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 33-59   Reserved
name|SPD_LPDDR_CONNECTOR_BIT_MAPPING_BYTE_STRUCT
name|BitMapping
index|[
literal|77
operator|-
literal|60
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 60-77   Connector to SDRAM Bit Mapping
name|UINT8
name|Reserved2
index|[
literal|119
operator|-
literal|78
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 78-119  Reserved
name|SPD_LPDDR_TRP_PB_FTB_STRUCT
name|tRPpbFine
decl_stmt|;
comment|///< 120     Fine Offset for Minimum Row Precharge Delay Time (tRPpbFine), per bank
name|SPD_LPDDR_TRP_AB_FTB_STRUCT
name|tRPabFine
decl_stmt|;
comment|///< 121     Fine Offset for Minimum Row Precharge Delay Time (tRPabFine), all ranks
name|SPD_LPDDR_TRCD_MIN_FTB_STRUCT
name|tRCDminFine
decl_stmt|;
comment|///< 122     Fine Offset for Minimum RAS# to CAS# Delay Time (tRCDmin)
name|SPD_LPDDR_TAA_MIN_FTB_STRUCT
name|tAAminFine
decl_stmt|;
comment|///< 123     Fine Offset for Minimum CAS Latency Time (tAAmin)
name|SPD_LPDDR_TCK_MAX_FTB_STRUCT
name|tCKmaxFine
decl_stmt|;
comment|///< 124     Fine Offset for SDRAM Maximum Cycle Time (tCKmax)
name|SPD_LPDDR_TCK_MIN_FTB_STRUCT
name|tCKminFine
decl_stmt|;
comment|///< 125     Fine Offset for SDRAM Minimum Cycle Time (tCKmin)
name|SPD_LPDDR_CYCLIC_REDUNDANCY_CODE
name|Crc
decl_stmt|;
comment|///< 126-127 Cyclical Redundancy Code (CRC)
block|}
name|SPD_LPDDR_BASE_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD_LPDDR_MODULE_NOMINAL_HEIGHT
name|ModuleNominalHeight
decl_stmt|;
comment|///< 128     Module Nominal Height
name|SPD_LPDDR_MODULE_MAXIMUM_THICKNESS
name|ModuleMaximumThickness
decl_stmt|;
comment|///< 129     Module Maximum Thickness
name|SPD_LPDDR_REFERENCE_RAW_CARD
name|ReferenceRawCardUsed
decl_stmt|;
comment|///< 130     Reference Raw Card Used
name|UINT8
name|Reserved
index|[
literal|253
operator|-
literal|131
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 131-253 Reserved
name|SPD_LPDDR_CYCLIC_REDUNDANCY_CODE
name|Crc
decl_stmt|;
comment|///< 254-255 Cyclical Redundancy Code (CRC)
block|}
name|SPD_LPDDR_MODULE_LPDIMM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD_LPDDR_MODULE_LPDIMM
name|LpDimm
decl_stmt|;
comment|///< 128-255 Unbuffered Memory Module Types
block|}
name|SPD_LPDDR_MODULE_SPECIFIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ModulePartNumber
index|[
literal|348
operator|-
literal|329
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 329-348 Module Part Number
block|}
name|SPD_LPDDR_MODULE_PART_NUMBER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ManufacturerSpecificData
index|[
literal|381
operator|-
literal|353
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 353-381 Manufacturer's Specific Data
block|}
name|SPD_LPDDR_MANUFACTURER_SPECIFIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|SPD_LPDDR_MODULE_REVISION_CODE
typedef|;
end_typedef

begin_comment
comment|///< 349     Module Revision Code
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|SPD_LPDDR_DRAM_STEPPING
typedef|;
end_typedef

begin_comment
comment|///< 352     Dram Stepping
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD_LPDDR_UNIQUE_MODULE_ID
name|ModuleId
decl_stmt|;
comment|///< 320-328 Unique Module ID
name|SPD_LPDDR_MODULE_PART_NUMBER
name|ModulePartNumber
decl_stmt|;
comment|///< 329-348 Module Part Number
name|SPD_LPDDR_MODULE_REVISION_CODE
name|ModuleRevisionCode
decl_stmt|;
comment|///< 349     Module Revision Code
name|SPD_LPDDR_MANUFACTURER_ID_CODE
name|DramIdCode
decl_stmt|;
comment|///< 350-351 Dram Manufacturer ID Code
name|SPD_LPDDR_DRAM_STEPPING
name|DramStepping
decl_stmt|;
comment|///< 352     Dram Stepping
name|SPD_LPDDR_MANUFACTURER_SPECIFIC
name|ManufacturerSpecificData
decl_stmt|;
comment|///< 353-381 Manufacturer's Specific Data
name|UINT8
name|Reserved
index|[
literal|383
operator|-
literal|382
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 382-383 Reserved
block|}
name|SPD_LPDDR_MANUFACTURING_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Reserved
index|[
literal|511
operator|-
literal|384
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 384-511 End User Programmable
block|}
name|SPD_LPDDR_END_USER_SECTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// LPDDR Serial Presence Detect structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD_LPDDR_BASE_SECTION
name|Base
decl_stmt|;
comment|///< 0-127   Base Configuration and DRAM Parameters
name|SPD_LPDDR_MODULE_SPECIFIC
name|Module
decl_stmt|;
comment|///< 128-255 Module-Specific Section
name|UINT8
name|Reserved
index|[
literal|319
operator|-
literal|256
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 256-319 Hybrid Memory Parameters
name|SPD_LPDDR_MANUFACTURING_DATA
name|ManufactureInfo
decl_stmt|;
comment|///< 320-383 Manufacturing Information
name|SPD_LPDDR_END_USER_SECTION
name|EndUser
decl_stmt|;
comment|///< 384-511 End User Programmable
block|}
name|SPD_LPDDR
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

