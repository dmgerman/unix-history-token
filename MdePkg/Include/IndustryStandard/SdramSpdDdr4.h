begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file contains definitions for SPD DDR4.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:     - Serial Presence Detect (SPD) for DDR4 SDRAM Modules Document Release 4       http://www.jedec.org/standards-documents/docs/spd412l-4 **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SDRAM_SPD_DDR4_H_
end_ifndef

begin_define
define|#
directive|define
name|_SDRAM_SPD_DDR4_H_
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
name|SPD4_DEVICE_DESCRIPTION_STRUCT
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
name|SPD4_REVISION_STRUCT
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
name|SPD4_DRAM_DEVICE_TYPE_STRUCT
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
name|SPD4_MODULE_TYPE_STRUCT
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
name|SPD4_SDRAM_DENSITY_BANKS_STRUCT
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
name|SPD4_SDRAM_ADDRESSING_STRUCT
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
name|Reserved
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
name|SPD4_PRIMARY_SDRAM_PACKAGE_TYPE_STRUCT
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
name|SPD4_SDRAM_OPTIONAL_FEATURES_STRUCT
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
name|SPD4_SDRAM_THERMAL_REFRESH_STRUCT
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
name|SPD4_OTHER_SDRAM_OPTIONAL_FEATURES_STRUCT
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
name|DRAMDensityRatio
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
name|SPD4_SECONDARY_SDRAM_PACKAGE_TYPE_STRUCT
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
name|Reserved
range|:
literal|6
decl_stmt|;
comment|///< Bits 7:2
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD4_MODULE_NOMINAL_VOLTAGE_STRUCT
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
name|RankMix
range|:
literal|1
decl_stmt|;
comment|///< Bits 6:6
name|UINT8
name|Reserved
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
name|SPD4_MODULE_ORGANIZATION_STRUCT
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
name|Reserved
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
name|SPD4_MODULE_MEMORY_BUS_WIDTH_STRUCT
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
name|SPD4_MODULE_THERMAL_SENSOR_STRUCT
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
name|SPD4_EXTENDED_MODULE_TYPE_STRUCT
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
name|SPD4_TIMEBASE_STRUCT
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
name|SPD4_TCK_MIN_MTB_STRUCT
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
name|SPD4_TCK_MAX_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|Cl7
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT32
name|Cl8
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT32
name|Cl9
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT32
name|Cl10
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT32
name|Cl11
range|:
literal|1
decl_stmt|;
comment|///< Bits 4:4
name|UINT32
name|Cl12
range|:
literal|1
decl_stmt|;
comment|///< Bits 5:5
name|UINT32
name|Cl13
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
name|Cl15
range|:
literal|1
decl_stmt|;
comment|///< Bits 8:8
name|UINT32
name|Cl16
range|:
literal|1
decl_stmt|;
comment|///< Bits 9:9
name|UINT32
name|Cl17
range|:
literal|1
decl_stmt|;
comment|///< Bits 10:10
name|UINT32
name|Cl18
range|:
literal|1
decl_stmt|;
comment|///< Bits 11:11
name|UINT32
name|Cl19
range|:
literal|1
decl_stmt|;
comment|///< Bits 12:12
name|UINT32
name|Cl20
range|:
literal|1
decl_stmt|;
comment|///< Bits 13:13
name|UINT32
name|Cl21
range|:
literal|1
decl_stmt|;
comment|///< Bits 14:14
name|UINT32
name|Cl22
range|:
literal|1
decl_stmt|;
comment|///< Bits 15:15
name|UINT32
name|Cl23
range|:
literal|1
decl_stmt|;
comment|///< Bits 16:16
name|UINT32
name|Cl24
range|:
literal|1
decl_stmt|;
comment|///< Bits 17:17
name|UINT32
name|Cl25
range|:
literal|1
decl_stmt|;
comment|///< Bits 18:18
name|UINT32
name|Cl26
range|:
literal|1
decl_stmt|;
comment|///< Bits 19:19
name|UINT32
name|Cl27
range|:
literal|1
decl_stmt|;
comment|///< Bits 20:20
name|UINT32
name|Cl28
range|:
literal|1
decl_stmt|;
comment|///< Bits 21:21
name|UINT32
name|Cl29
range|:
literal|1
decl_stmt|;
comment|///< Bits 22:22
name|UINT32
name|Cl30
range|:
literal|1
decl_stmt|;
comment|///< Bits 23:23
name|UINT32
name|Cl31
range|:
literal|1
decl_stmt|;
comment|///< Bits 24:24
name|UINT32
name|Cl32
range|:
literal|1
decl_stmt|;
comment|///< Bits 25:25
name|UINT32
name|Cl33
range|:
literal|1
decl_stmt|;
comment|///< Bits 26:26
name|UINT32
name|Cl34
range|:
literal|1
decl_stmt|;
comment|///< Bits 27:27
name|UINT32
name|Cl35
range|:
literal|1
decl_stmt|;
comment|///< Bits 28:28
name|UINT32
name|Cl36
range|:
literal|1
decl_stmt|;
comment|///< Bits 29:29
name|UINT32
name|Reserved
range|:
literal|1
decl_stmt|;
comment|///< Bits 30:30
name|UINT32
name|ClRange
range|:
literal|1
decl_stmt|;
comment|///< Bits 31:31
block|}
name|Bits
struct|;
struct|struct
block|{
name|UINT32
name|Cl23
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT32
name|Cl24
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT32
name|Cl25
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT32
name|Cl26
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT32
name|Cl27
range|:
literal|1
decl_stmt|;
comment|///< Bits 4:4
name|UINT32
name|Cl28
range|:
literal|1
decl_stmt|;
comment|///< Bits 5:5
name|UINT32
name|Cl29
range|:
literal|1
decl_stmt|;
comment|///< Bits 6:6
name|UINT32
name|Cl30
range|:
literal|1
decl_stmt|;
comment|///< Bits 7:7
name|UINT32
name|Cl31
range|:
literal|1
decl_stmt|;
comment|///< Bits 8:8
name|UINT32
name|Cl32
range|:
literal|1
decl_stmt|;
comment|///< Bits 9:9
name|UINT32
name|Cl33
range|:
literal|1
decl_stmt|;
comment|///< Bits 10:10
name|UINT32
name|Cl34
range|:
literal|1
decl_stmt|;
comment|///< Bits 11:11
name|UINT32
name|Cl35
range|:
literal|1
decl_stmt|;
comment|///< Bits 12:12
name|UINT32
name|Cl36
range|:
literal|1
decl_stmt|;
comment|///< Bits 13:13
name|UINT32
name|Cl37
range|:
literal|1
decl_stmt|;
comment|///< Bits 14:14
name|UINT32
name|Cl38
range|:
literal|1
decl_stmt|;
comment|///< Bits 15:15
name|UINT32
name|Cl39
range|:
literal|1
decl_stmt|;
comment|///< Bits 16:16
name|UINT32
name|Cl40
range|:
literal|1
decl_stmt|;
comment|///< Bits 17:17
name|UINT32
name|Cl41
range|:
literal|1
decl_stmt|;
comment|///< Bits 18:18
name|UINT32
name|Cl42
range|:
literal|1
decl_stmt|;
comment|///< Bits 19:19
name|UINT32
name|Cl43
range|:
literal|1
decl_stmt|;
comment|///< Bits 20:20
name|UINT32
name|Cl44
range|:
literal|1
decl_stmt|;
comment|///< Bits 21:21
name|UINT32
name|Cl45
range|:
literal|1
decl_stmt|;
comment|///< Bits 22:22
name|UINT32
name|Cl46
range|:
literal|1
decl_stmt|;
comment|///< Bits 23:23
name|UINT32
name|Cl47
range|:
literal|1
decl_stmt|;
comment|///< Bits 24:24
name|UINT32
name|Cl48
range|:
literal|1
decl_stmt|;
comment|///< Bits 25:25
name|UINT32
name|Cl49
range|:
literal|1
decl_stmt|;
comment|///< Bits 26:26
name|UINT32
name|Cl50
range|:
literal|1
decl_stmt|;
comment|///< Bits 27:27
name|UINT32
name|Cl51
range|:
literal|1
decl_stmt|;
comment|///< Bits 28:28
name|UINT32
name|Cl52
range|:
literal|1
decl_stmt|;
comment|///< Bits 29:29
name|UINT32
name|Reserved
range|:
literal|1
decl_stmt|;
comment|///< Bits 30:30
name|UINT32
name|ClRange
range|:
literal|1
decl_stmt|;
comment|///< Bits 31:31
block|}
name|HighRangeBits
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
name|SPD4_CAS_LATENCIES_SUPPORTED_STRUCT
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
name|SPD4_TAA_MIN_MTB_STRUCT
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
name|SPD4_TRCD_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tRPmin
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
name|SPD4_TRP_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tRASminUpper
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|tRCminUpper
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
name|SPD4_TRAS_TRC_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tRASmin
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
name|SPD4_TRAS_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tRCmin
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
name|SPD4_TRC_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT16
name|tRFCmin
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
name|SPD4_TRFC_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tFAWminUpper
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
name|SPD4_TFAW_MIN_MTB_UPPER_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tFAWmin
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
name|SPD4_TFAW_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tRRDmin
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
name|SPD4_TRRD_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tCCDmin
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
name|SPD4_TCCD_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tWRminMostSignificantNibble
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
name|SPD4_TWR_UPPER_NIBBLE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tWRmin
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
name|SPD4_TWR_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tWTR_SminMostSignificantNibble
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|tWTR_LminMostSignificantNibble
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
name|SPD4_TWTR_UPPER_NIBBLE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tWTRmin
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
name|SPD4_TWTR_MIN_MTB_STRUCT
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
name|SPD4_CONNECTOR_BIT_MAPPING_BYTE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tCCDminFine
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
name|SPD4_TCCD_MIN_FTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tRRDminFine
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
name|SPD4_TRRD_MIN_FTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tRCminFine
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
name|SPD4_TRC_MIN_FTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|INT8
name|tRPminFine
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
name|SPD4_TRP_MIN_FTB_STRUCT
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
name|SPD4_TRCD_MIN_FTB_STRUCT
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
name|SPD4_TAA_MIN_FTB_STRUCT
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
name|SPD4_TCK_MAX_FTB_STRUCT
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
name|SPD4_TCK_MIN_FTB_STRUCT
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
name|SPD4_UNBUF_MODULE_NOMINAL_HEIGHT
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
name|SPD4_UNBUF_MODULE_NOMINAL_THICKNESS
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
name|SPD4_UNBUF_REFERENCE_RAW_CARD
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|MappingRank1
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|Reserved
range|:
literal|7
decl_stmt|;
comment|///< Bits 7:1
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD4_UNBUF_ADDRESS_MAPPING
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
name|Reserved
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
name|SPD4_RDIMM_MODULE_NOMINAL_HEIGHT
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
name|SPD4_RDIMM_MODULE_NOMINAL_THICKNESS
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
name|SPD4_RDIMM_REFERENCE_RAW_CARD
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|RegisterCount
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|DramRowCount
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|RegisterType
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
name|SPD4_RDIMM_MODULE_ATTRIBUTES
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|HeatSpreaderThermalCharacteristics
range|:
literal|7
decl_stmt|;
comment|///< Bits 6:0
name|UINT8
name|HeatSpreaderSolution
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
name|SPD4_RDIMM_THERMAL_HEAT_SPREADER_SOLUTION
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
name|SPD4_MANUFACTURER_ID_CODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|RegisterRevisionNumber
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD4_RDIMM_REGISTER_REVISION_NUMBER
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Rank1Mapping
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|Reserved
range|:
literal|7
decl_stmt|;
comment|///< Bits 7:1
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD4_RDIMM_ADDRESS_MAPPING_FROM_REGISTER_TO_DRAM
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Cke
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|Odt
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|CommandAddress
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|ChipSelect
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
name|SPD4_RDIMM_REGISTER_OUTPUT_DRIVE_STRENGTH_FOR_CONTROL_COMMAND_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Y0Y2
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|Y1Y3
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|Reserved0
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|RcdOutputSlewRateControl
range|:
literal|1
decl_stmt|;
comment|///< Bits 6:6
name|UINT8
name|Reserved1
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
name|SPD4_RDIMM_REGISTER_OUTPUT_DRIVE_STRENGTH_FOR_CLOCK
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
name|Reserved
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
name|SPD4_LRDIMM_MODULE_NOMINAL_HEIGHT
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
name|SPD4_LRDIMM_MODULE_NOMINAL_THICKNESS
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
name|SPD4_LRDIMM_REFERENCE_RAW_CARD
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|RegisterCount
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|DramRowCount
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|RegisterType
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
name|SPD4_LRDIMM_MODULE_ATTRIBUTES
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|HeatSpreaderThermalCharacteristics
range|:
literal|7
decl_stmt|;
comment|///< Bits 6:0
name|UINT8
name|HeatSpreaderSolution
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
name|SPD4_LRDIMM_THERMAL_HEAT_SPREADER_SOLUTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|RegisterRevisionNumber
decl_stmt|;
comment|///< Bits 7:0
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD4_LRDIMM_REGISTER_REVISION_NUMBER
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Rank1Mapping
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|Reserved
range|:
literal|7
decl_stmt|;
comment|///< Bits 7:1
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD4_LRDIMM_ADDRESS_MAPPING_FROM_REGISTER_TO_DRAM
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Cke
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|Odt
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|CommandAddress
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|ChipSelect
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
name|SPD4_LRDIMM_REGISTER_OUTPUT_DRIVE_STRENGTH_FOR_CONTROL_COMMAND_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Y0Y2
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|Y1Y3
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|Reserved0
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|RcdOutputSlewRateControl
range|:
literal|1
decl_stmt|;
comment|///< Bits 6:6
name|UINT8
name|Reserved1
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
name|SPD4_LRDIMM_REGISTER_OUTPUT_DRIVE_STRENGTH_FOR_CLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DataBufferRevisionNumber
decl_stmt|;
block|}
name|SPD4_LRDIMM_DATA_BUFFER_REVISION_NUMBER
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|DramVrefDQForPackageRank0
range|:
literal|6
decl_stmt|;
comment|///< Bits 5:0
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
name|SPD4_LRDIMM_DRAM_VREFDQ_FOR_PACKAGE_RANK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DataBufferVrefDQforDramInterface
decl_stmt|;
block|}
name|SPD4_LRDIMM_DATA_BUFFER_VREFDQ_FOR_DRAM_INTERFACE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|DramInterfaceMdqDriveStrength
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|DramInterfaceMdqReadTerminationStrength
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
name|SPD4_LRDIMM_DATA_BUFFER_MDQ_DRIVE_STRENGTH_RTT_FOR_DATA_RATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|DataRateLe1866
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|DataRateLe2400
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|DataRateLe3200
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
name|SPD4_LRDIMM_DRAM_DRIVE_STRENGTH
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Rtt_Nom
range|:
literal|3
decl_stmt|;
comment|///< Bits 2:0
name|UINT8
name|Rtt_WR
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
name|SPD4_LRDIMM_DRAM_ODT_RTT_WR_RTT_NOM_FOR_DATA_RATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|PackageRanks0_1
range|:
literal|3
decl_stmt|;
comment|///< Bits 2:0
name|UINT8
name|PackageRanks2_3
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
name|SPD4_LRDIMM_DRAM_ODT_RTT_PARK_FOR_DATA_RATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Rank0
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|Rank1
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT8
name|Rank2
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT8
name|Rank3
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT8
name|DataBuffer
range|:
literal|1
decl_stmt|;
comment|///< Bits 4:4
name|UINT8
name|Reserved
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
name|SPD4_LRDIMM_DATA_BUFFER_VREFDQ_FOR_DRAM_INTERFACE_RANGE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|DataBufferGainAdjustment
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|DataBufferDfe
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT8
name|Reserved
range|:
literal|6
decl_stmt|;
comment|///< Bits 7:2
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD4_LRDIMM_DATA_BUFFER_DQ_DECISION_FEEDBACK_EQUALIZATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|SPD4_NVDIMM_MODULE_PRODUCT_IDENTIFIER
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
name|SPD4_NVDIMM_SUBSYSTEM_CONTROLLER_MANUFACTURER_ID_CODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|SPD4_NVDIMM_SUBSYSTEM_CONTROLLER_IDENTIFIER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|SPD4_NVDIMM_SUBSYSTEM_CONTROLLER_REVISION_CODE
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
name|SPD4_NVDIMM_REFERENCE_RAW_CARD
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
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|Extension
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
name|SPD4_NVDIMM_MODULE_CHARACTERISTICS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Reserved
decl_stmt|;
name|UINT8
name|MediaType
decl_stmt|;
block|}
name|SPD4_NVDIMM_HYBRID_MODULE_MEDIA_TYPES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|SPD4_NVDIMM_MAXIMUM_NONVOLATILE_MEMORY_INITIALIZATION_TIME
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT16
name|FunctionInterface
range|:
literal|5
decl_stmt|;
comment|///< Bits 4:0
name|UINT16
name|FunctionClass
range|:
literal|5
decl_stmt|;
comment|///< Bits 9:5
name|UINT16
name|BlockOffset
range|:
literal|4
decl_stmt|;
comment|///< Bits 13:10
name|UINT16
name|Reserved
range|:
literal|1
decl_stmt|;
comment|///< Bits 14:14
name|UINT16
name|Implemented
range|:
literal|1
decl_stmt|;
comment|///< Bits 15:15
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
name|SPD4_NVDIMM_FUNCTION_INTERFACE_DESCRIPTOR
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
name|SPD4_MANUFACTURING_DATE
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
name|SPD4_MANUFACTURER_SERIAL_NUMBER
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
name|SPD4_MANUFACTURING_LOCATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD4_MANUFACTURER_ID_CODE
name|IdCode
decl_stmt|;
comment|///< Module Manufacturer ID Code
name|SPD4_MANUFACTURING_LOCATION
name|Location
decl_stmt|;
comment|///< Module Manufacturing Location
name|SPD4_MANUFACTURING_DATE
name|Date
decl_stmt|;
comment|///< Module Manufacturing Year, in BCD (range: 2000-2255)
name|SPD4_MANUFACTURER_SERIAL_NUMBER
name|SerialNumber
decl_stmt|;
comment|///< Module Serial Number
block|}
name|SPD4_UNIQUE_MODULE_ID
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
name|SPD4_CYCLIC_REDUNDANCY_CODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD4_DEVICE_DESCRIPTION_STRUCT
name|Description
decl_stmt|;
comment|///< 0       Number of Serial PD Bytes Written / SPD Device Size / CRC Coverage 1, 2
name|SPD4_REVISION_STRUCT
name|Revision
decl_stmt|;
comment|///< 1       SPD Revision
name|SPD4_DRAM_DEVICE_TYPE_STRUCT
name|DramDeviceType
decl_stmt|;
comment|///< 2       DRAM Device Type
name|SPD4_MODULE_TYPE_STRUCT
name|ModuleType
decl_stmt|;
comment|///< 3       Module Type
name|SPD4_SDRAM_DENSITY_BANKS_STRUCT
name|SdramDensityAndBanks
decl_stmt|;
comment|///< 4       SDRAM Density and Banks
name|SPD4_SDRAM_ADDRESSING_STRUCT
name|SdramAddressing
decl_stmt|;
comment|///< 5       SDRAM Addressing
name|SPD4_PRIMARY_SDRAM_PACKAGE_TYPE_STRUCT
name|PrimarySdramPackageType
decl_stmt|;
comment|///< 6       Primary SDRAM Package Type
name|SPD4_SDRAM_OPTIONAL_FEATURES_STRUCT
name|SdramOptionalFeatures
decl_stmt|;
comment|///< 7       SDRAM Optional Features
name|SPD4_SDRAM_THERMAL_REFRESH_STRUCT
name|ThermalAndRefreshOptions
decl_stmt|;
comment|///< 8       SDRAM Thermal and Refresh Options
name|SPD4_OTHER_SDRAM_OPTIONAL_FEATURES_STRUCT
name|OtherOptionalFeatures
decl_stmt|;
comment|///< 9       Other SDRAM Optional Features
name|SPD4_SECONDARY_SDRAM_PACKAGE_TYPE_STRUCT
name|SecondarySdramPackageType
decl_stmt|;
comment|///< 10      Secondary SDRAM Package Type
name|SPD4_MODULE_NOMINAL_VOLTAGE_STRUCT
name|ModuleNominalVoltage
decl_stmt|;
comment|///< 11      Module Nominal Voltage, VDD
name|SPD4_MODULE_ORGANIZATION_STRUCT
name|ModuleOrganization
decl_stmt|;
comment|///< 12      Module Organization
name|SPD4_MODULE_MEMORY_BUS_WIDTH_STRUCT
name|ModuleMemoryBusWidth
decl_stmt|;
comment|///< 13      Module Memory Bus Width
name|SPD4_MODULE_THERMAL_SENSOR_STRUCT
name|ModuleThermalSensor
decl_stmt|;
comment|///< 14      Module Thermal Sensor
name|SPD4_EXTENDED_MODULE_TYPE_STRUCT
name|ExtendedModuleType
decl_stmt|;
comment|///< 15      Extended Module Type
name|UINT8
name|Reserved0
decl_stmt|;
comment|///< 16      Reserved
name|SPD4_TIMEBASE_STRUCT
name|Timebase
decl_stmt|;
comment|///< 17      Timebases
name|SPD4_TCK_MIN_MTB_STRUCT
name|tCKmin
decl_stmt|;
comment|///< 18      SDRAM Minimum Cycle Time (tCKmin)
name|SPD4_TCK_MAX_MTB_STRUCT
name|tCKmax
decl_stmt|;
comment|///< 19      SDRAM Maximum Cycle Time (tCKmax)
name|SPD4_CAS_LATENCIES_SUPPORTED_STRUCT
name|CasLatencies
decl_stmt|;
comment|///< 20-23   CAS Latencies Supported
name|SPD4_TAA_MIN_MTB_STRUCT
name|tAAmin
decl_stmt|;
comment|///< 24      Minimum CAS Latency Time (tAAmin)
name|SPD4_TRCD_MIN_MTB_STRUCT
name|tRCDmin
decl_stmt|;
comment|///< 25      Minimum RAS# to CAS# Delay Time (tRCDmin)
name|SPD4_TRP_MIN_MTB_STRUCT
name|tRPmin
decl_stmt|;
comment|///< 26      Minimum Row Precharge Delay Time (tRPmin)
name|SPD4_TRAS_TRC_MIN_MTB_STRUCT
name|tRASMintRCMinUpper
decl_stmt|;
comment|///< 27      Upper Nibbles for tRAS and tRC
name|SPD4_TRAS_MIN_MTB_STRUCT
name|tRASmin
decl_stmt|;
comment|///< 28      Minimum Active to Precharge Delay Time (tRASmin), Least Significant Byte
name|SPD4_TRC_MIN_MTB_STRUCT
name|tRCmin
decl_stmt|;
comment|///< 29      Minimum Active to Active/Refresh Delay Time (tRCmin), Least Significant Byte
name|SPD4_TRFC_MIN_MTB_STRUCT
name|tRFC1min
decl_stmt|;
comment|///< 30-31   Minimum Refresh Recovery Delay Time (tRFC1min)
name|SPD4_TRFC_MIN_MTB_STRUCT
name|tRFC2min
decl_stmt|;
comment|///< 32-33   Minimum Refresh Recovery Delay Time (tRFC2min)
name|SPD4_TRFC_MIN_MTB_STRUCT
name|tRFC4min
decl_stmt|;
comment|///< 34-35   Minimum Refresh Recovery Delay Time (tRFC4min)
name|SPD4_TFAW_MIN_MTB_UPPER_STRUCT
name|tFAWMinUpper
decl_stmt|;
comment|///< 36      Upper Nibble for tFAW
name|SPD4_TFAW_MIN_MTB_STRUCT
name|tFAWmin
decl_stmt|;
comment|///< 37      Minimum Four Activate Window Delay Time (tFAWmin)
name|SPD4_TRRD_MIN_MTB_STRUCT
name|tRRD_Smin
decl_stmt|;
comment|///< 38      Minimum Activate to Activate Delay Time (tRRD_Smin), different bank group
name|SPD4_TRRD_MIN_MTB_STRUCT
name|tRRD_Lmin
decl_stmt|;
comment|///< 39      Minimum Activate to Activate Delay Time (tRRD_Lmin), same bank group
name|SPD4_TCCD_MIN_MTB_STRUCT
name|tCCD_Lmin
decl_stmt|;
comment|///< 40      Minimum CAS to CAS Delay Time (tCCD_Lmin), Same Bank Group
name|SPD4_TWR_UPPER_NIBBLE_STRUCT
name|tWRUpperNibble
decl_stmt|;
comment|///< 41      Upper Nibble for tWRmin
name|SPD4_TWR_MIN_MTB_STRUCT
name|tWRmin
decl_stmt|;
comment|///< 42      Minimum Write Recovery Time (tWRmin)
name|SPD4_TWTR_UPPER_NIBBLE_STRUCT
name|tWTRUpperNibble
decl_stmt|;
comment|///< 43      Upper Nibbles for tWTRmin
name|SPD4_TWTR_MIN_MTB_STRUCT
name|tWTR_Smin
decl_stmt|;
comment|///< 44      Minimum Write to Read Time (tWTR_Smin), Different Bank Group
name|SPD4_TWTR_MIN_MTB_STRUCT
name|tWTR_Lmin
decl_stmt|;
comment|///< 45      Minimum Write to Read Time (tWTR_Lmin), Same Bank Group
name|UINT8
name|Reserved1
index|[
literal|59
operator|-
literal|46
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 46-59   Reserved
name|SPD4_CONNECTOR_BIT_MAPPING_BYTE_STRUCT
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
literal|116
operator|-
literal|78
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 78-116  Reserved
name|SPD4_TCCD_MIN_FTB_STRUCT
name|tCCD_LminFine
decl_stmt|;
comment|///< 117     Fine Offset for Minimum CAS to CAS Delay Time (tCCD_Lmin), same bank group
name|SPD4_TRRD_MIN_FTB_STRUCT
name|tRRD_LminFine
decl_stmt|;
comment|///< 118     Fine Offset for Minimum Activate to Activate Delay Time (tRRD_Lmin), different bank group
name|SPD4_TRRD_MIN_FTB_STRUCT
name|tRRD_SminFine
decl_stmt|;
comment|///< 119     Fine Offset for Minimum Activate to Activate Delay Time (tRRD_Smin), same bank group
name|SPD4_TRC_MIN_FTB_STRUCT
name|tRCminFine
decl_stmt|;
comment|///< 120     Fine Offset for Minimum Active to Active/Refresh Delay Time (tRCmin)
name|SPD4_TRP_MIN_FTB_STRUCT
name|tRPminFine
decl_stmt|;
comment|///< 121     Fine Offset for Minimum Row Precharge Delay Time (tRPabmin)
name|SPD4_TRCD_MIN_FTB_STRUCT
name|tRCDminFine
decl_stmt|;
comment|///< 122     Fine Offset for Minimum RAS# to CAS# Delay Time (tRCDmin)
name|SPD4_TAA_MIN_FTB_STRUCT
name|tAAminFine
decl_stmt|;
comment|///< 123     Fine Offset for Minimum CAS Latency Time (tAAmin)
name|SPD4_TCK_MAX_FTB_STRUCT
name|tCKmaxFine
decl_stmt|;
comment|///< 124     Fine Offset for SDRAM Minimum Cycle Time (tCKmax)
name|SPD4_TCK_MIN_FTB_STRUCT
name|tCKminFine
decl_stmt|;
comment|///< 125     Fine Offset for SDRAM Maximum Cycle Time (tCKmin)
name|SPD4_CYCLIC_REDUNDANCY_CODE
name|Crc
decl_stmt|;
comment|///< 126-127 Cyclical Redundancy Code (CRC)
block|}
name|SPD4_BASE_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD4_UNBUF_MODULE_NOMINAL_HEIGHT
name|ModuleNominalHeight
decl_stmt|;
comment|///< 128     Module Nominal Height
name|SPD4_UNBUF_MODULE_NOMINAL_THICKNESS
name|ModuleMaximumThickness
decl_stmt|;
comment|///< 129     Module Maximum Thickness
name|SPD4_UNBUF_REFERENCE_RAW_CARD
name|ReferenceRawCardUsed
decl_stmt|;
comment|///< 130     Reference Raw Card Used
name|SPD4_UNBUF_ADDRESS_MAPPING
name|AddressMappingEdgeConn
decl_stmt|;
comment|///< 131     Address Mapping from Edge Connector to DRAM
name|UINT8
name|Reserved
index|[
literal|253
operator|-
literal|132
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 132-253 Reserved
name|SPD4_CYCLIC_REDUNDANCY_CODE
name|Crc
decl_stmt|;
comment|///< 254-255 Cyclical Redundancy Code (CRC)
block|}
name|SPD4_MODULE_UNBUFFERED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD4_RDIMM_MODULE_NOMINAL_HEIGHT
name|ModuleNominalHeight
decl_stmt|;
comment|///< 128     Module Nominal Height
name|SPD4_RDIMM_MODULE_NOMINAL_THICKNESS
name|ModuleMaximumThickness
decl_stmt|;
comment|///< 129     Module Maximum Thickness
name|SPD4_RDIMM_REFERENCE_RAW_CARD
name|ReferenceRawCardUsed
decl_stmt|;
comment|///< 130     Reference Raw Card Used
name|SPD4_RDIMM_MODULE_ATTRIBUTES
name|DimmModuleAttributes
decl_stmt|;
comment|///< 131     DIMM Module Attributes
name|SPD4_RDIMM_THERMAL_HEAT_SPREADER_SOLUTION
name|DimmThermalHeatSpreaderSolution
decl_stmt|;
comment|///< 132     RDIMM Thermal Heat Spreader Solution
name|SPD4_MANUFACTURER_ID_CODE
name|RegisterManufacturerIdCode
decl_stmt|;
comment|///< 133-134 Register Manufacturer ID Code
name|SPD4_RDIMM_REGISTER_REVISION_NUMBER
name|RegisterRevisionNumber
decl_stmt|;
comment|///< 135     Register Revision Number
name|SPD4_RDIMM_ADDRESS_MAPPING_FROM_REGISTER_TO_DRAM
name|AddressMappingFromRegisterToDRAM
decl_stmt|;
comment|///< 136     Address Mapping from Register to DRAM
name|SPD4_RDIMM_REGISTER_OUTPUT_DRIVE_STRENGTH_FOR_CONTROL_COMMAND_ADDRESS
name|RegisterOutputDriveStrengthForControlCommandAddress
decl_stmt|;
comment|///< 137 Register Output Drive Strength for Control and Command Address
name|SPD4_RDIMM_REGISTER_OUTPUT_DRIVE_STRENGTH_FOR_CLOCK
name|RegisterOutputDriveStrengthForClock
decl_stmt|;
comment|///< 138     Register Output Drive Strength for Clock
name|UINT8
name|Reserved
index|[
literal|253
operator|-
literal|139
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 253-139 Reserved
name|SPD4_CYCLIC_REDUNDANCY_CODE
name|Crc
decl_stmt|;
comment|///< 254-255 Cyclical Redundancy Code (CRC)
block|}
name|SPD4_MODULE_REGISTERED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD4_LRDIMM_MODULE_NOMINAL_HEIGHT
name|ModuleNominalHeight
decl_stmt|;
comment|///< 128     Module Nominal Height
name|SPD4_LRDIMM_MODULE_NOMINAL_THICKNESS
name|ModuleMaximumThickness
decl_stmt|;
comment|///< 129     Module Maximum Thickness
name|SPD4_LRDIMM_REFERENCE_RAW_CARD
name|ReferenceRawCardUsed
decl_stmt|;
comment|///< 130     Reference Raw Card Used
name|SPD4_LRDIMM_MODULE_ATTRIBUTES
name|DimmModuleAttributes
decl_stmt|;
comment|///< 131     DIMM Module Attributes
name|SPD4_LRDIMM_THERMAL_HEAT_SPREADER_SOLUTION
name|ThermalHeatSpreaderSolution
decl_stmt|;
comment|///< 132     RDIMM Thermal Heat Spreader Solution
name|SPD4_MANUFACTURER_ID_CODE
name|RegisterManufacturerIdCode
decl_stmt|;
comment|///< 133-134 Register Manufacturer ID Code
name|SPD4_LRDIMM_REGISTER_REVISION_NUMBER
name|RegisterRevisionNumber
decl_stmt|;
comment|///< 135     Register Revision Number
name|SPD4_LRDIMM_ADDRESS_MAPPING_FROM_REGISTER_TO_DRAM
name|AddressMappingFromRegisterToDram
decl_stmt|;
comment|///< 136 Address Mapping from Register to DRAM
name|SPD4_LRDIMM_REGISTER_OUTPUT_DRIVE_STRENGTH_FOR_CONTROL_COMMAND_ADDRESS
name|RegisterOutputDriveStrengthForControlCommandAddress
decl_stmt|;
comment|///< 137 Register Output Drive Strength for Control and Command Address
name|SPD4_LRDIMM_REGISTER_OUTPUT_DRIVE_STRENGTH_FOR_CLOCK
name|RegisterOutputDriveStrengthForClock
decl_stmt|;
comment|///< 138 Register Output Drive Strength for Clock
name|SPD4_LRDIMM_DATA_BUFFER_REVISION_NUMBER
name|DataBufferRevisionNumber
decl_stmt|;
comment|///< 139     Data Buffer Revision Number
name|SPD4_LRDIMM_DRAM_VREFDQ_FOR_PACKAGE_RANK
name|DramVrefDQForPackageRank0
decl_stmt|;
comment|///< 140     DRAM VrefDQ for Package Rank 0
name|SPD4_LRDIMM_DRAM_VREFDQ_FOR_PACKAGE_RANK
name|DramVrefDQForPackageRank1
decl_stmt|;
comment|///< 141     DRAM VrefDQ for Package Rank 1
name|SPD4_LRDIMM_DRAM_VREFDQ_FOR_PACKAGE_RANK
name|DramVrefDQForPackageRank2
decl_stmt|;
comment|///< 142     DRAM VrefDQ for Package Rank 2
name|SPD4_LRDIMM_DRAM_VREFDQ_FOR_PACKAGE_RANK
name|DramVrefDQForPackageRank3
decl_stmt|;
comment|///< 143     DRAM VrefDQ for Package Rank 3
name|SPD4_LRDIMM_DATA_BUFFER_VREFDQ_FOR_DRAM_INTERFACE
name|DataBufferVrefDQForDramInterface
decl_stmt|;
comment|///< 144     Data Buffer VrefDQ for DRAM Interface
name|SPD4_LRDIMM_DATA_BUFFER_MDQ_DRIVE_STRENGTH_RTT_FOR_DATA_RATE
name|DataBufferMdqDriveStrengthRttForDataRateLe1866
decl_stmt|;
comment|///< 145     Data Buffer MDQ Drive Strength and RTT for data rate<= 1866
name|SPD4_LRDIMM_DATA_BUFFER_MDQ_DRIVE_STRENGTH_RTT_FOR_DATA_RATE
name|DataBufferMdqDriveStrengthRttForDataRateLe2400
decl_stmt|;
comment|///< 146     Data Buffer MDQ Drive Strength and RTT for data rate<=2400
name|SPD4_LRDIMM_DATA_BUFFER_MDQ_DRIVE_STRENGTH_RTT_FOR_DATA_RATE
name|DataBufferMdqDriveStrengthRttForDataRateLe3200
decl_stmt|;
comment|///< 147     Data Buffer MDQ Drive Strength and RTT for data rate<=3200
name|SPD4_LRDIMM_DRAM_DRIVE_STRENGTH
name|DramDriveStrength
decl_stmt|;
comment|///< 148     DRAM Drive Strength
name|SPD4_LRDIMM_DRAM_ODT_RTT_WR_RTT_NOM_FOR_DATA_RATE
name|DramOdtRttWrRttNomForDataRateLe1866
decl_stmt|;
comment|///< 149     DRAM ODT (RTT_WR and RTT_NOM) for data rate<= 1866
name|SPD4_LRDIMM_DRAM_ODT_RTT_WR_RTT_NOM_FOR_DATA_RATE
name|DramOdtRttWrRttNomForDataRateLe2400
decl_stmt|;
comment|///< 150     DRAM ODT (RTT_WR and RTT_NOM) for data rate<= 2400
name|SPD4_LRDIMM_DRAM_ODT_RTT_WR_RTT_NOM_FOR_DATA_RATE
name|DramOdtRttWrRttNomForDataRateLe3200
decl_stmt|;
comment|///< 151     DRAM ODT (RTT_WR and RTT_NOM) for data rate<= 3200
name|SPD4_LRDIMM_DRAM_ODT_RTT_PARK_FOR_DATA_RATE
name|DramOdtRttParkForDataRateLe1866
decl_stmt|;
comment|///< 152     DRAM ODT (RTT_PARK) for data rate<= 1866
name|SPD4_LRDIMM_DRAM_ODT_RTT_PARK_FOR_DATA_RATE
name|DramOdtRttParkForDataRateLe2400
decl_stmt|;
comment|///< 153     DRAM ODT (RTT_PARK) for data rate<= 2400
name|SPD4_LRDIMM_DRAM_ODT_RTT_PARK_FOR_DATA_RATE
name|DramOdtRttParkForDataRateLe3200
decl_stmt|;
comment|///< 154     DRAM ODT (RTT_PARK) for data rate<= 3200
name|SPD4_LRDIMM_DATA_BUFFER_VREFDQ_FOR_DRAM_INTERFACE_RANGE
name|DataBufferVrefDQForDramInterfaceRange
decl_stmt|;
comment|///< 155     Data Buffer VrefDQ for DRAM Interface Range
name|SPD4_LRDIMM_DATA_BUFFER_DQ_DECISION_FEEDBACK_EQUALIZATION
name|DataBufferDqDecisionFeedbackEqualization
decl_stmt|;
comment|///< 156     Data Buffer DQ Decision Feedback Equalization
name|UINT8
name|Reserved
index|[
literal|253
operator|-
literal|157
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 253-132 Reserved
name|SPD4_CYCLIC_REDUNDANCY_CODE
name|Crc
decl_stmt|;
comment|///< 254-255 Cyclical Redundancy Code (CRC)
block|}
name|SPD4_MODULE_LOADREDUCED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Reserved0
index|[
literal|191
operator|-
literal|128
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 128-191  Reserved
name|SPD4_NVDIMM_MODULE_PRODUCT_IDENTIFIER
name|ModuleProductIdentifier
decl_stmt|;
comment|///< 192-193  Module Product Identifier
name|SPD4_NVDIMM_SUBSYSTEM_CONTROLLER_MANUFACTURER_ID_CODE
name|SubsystemControllerManufacturerIdCode
decl_stmt|;
comment|///< 194-195  Subsystem Controller Manufacturer's ID Code
name|SPD4_NVDIMM_SUBSYSTEM_CONTROLLER_IDENTIFIER
name|SubsystemControllerIdentifier
decl_stmt|;
comment|///< 196-197  Subsystem Controller Identifier
name|SPD4_NVDIMM_SUBSYSTEM_CONTROLLER_REVISION_CODE
name|SubsystemControllerRevisionCode
decl_stmt|;
comment|///< 198      Subsystem Controller Revision Code
name|SPD4_NVDIMM_REFERENCE_RAW_CARD
name|ReferenceRawCardUsed
decl_stmt|;
comment|///< 199      Reference Raw Card Used
name|SPD4_NVDIMM_MODULE_CHARACTERISTICS
name|ModuleCharacteristics
decl_stmt|;
comment|///< 200      Module Characteristics
name|SPD4_NVDIMM_HYBRID_MODULE_MEDIA_TYPES
name|HybridModuleMediaTypes
decl_stmt|;
comment|///< 201-202  Hybrid Module Media Types
name|SPD4_NVDIMM_MAXIMUM_NONVOLATILE_MEMORY_INITIALIZATION_TIME
name|MaximumNonVolatileMemoryInitializationTime
decl_stmt|;
comment|///< 203 Maximum Non-Volatile Memory Initialization Time
name|SPD4_NVDIMM_FUNCTION_INTERFACE_DESCRIPTOR
name|FunctionInterfaceDescriptors
index|[
literal|8
index|]
decl_stmt|;
comment|///< 204-219  Function Interface Descriptors
name|UINT8
name|Reserved
index|[
literal|253
operator|-
literal|220
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 220-253  Reserved
name|SPD4_CYCLIC_REDUNDANCY_CODE
name|Crc
decl_stmt|;
comment|///< 254-255  Cyclical Redundancy Code (CRC)
block|}
name|SPD4_MODULE_NVDIMM
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|SPD4_MODULE_UNBUFFERED
name|Unbuffered
decl_stmt|;
comment|///< 128-255 Unbuffered Memory Module Types
name|SPD4_MODULE_REGISTERED
name|Registered
decl_stmt|;
comment|///< 128-255 Registered Memory Module Types
name|SPD4_MODULE_LOADREDUCED
name|LoadReduced
decl_stmt|;
comment|///< 128-255 Load Reduced Memory Module Types
name|SPD4_MODULE_NVDIMM
name|NonVolatile
decl_stmt|;
comment|///< 128-255 Non-Volatile (NVDIMM-N) Hybrid Memory Parameters
block|}
name|SPD4_MODULE_SPECIFIC
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
name|SPD4_MODULE_PART_NUMBER
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
name|SPD4_MANUFACTURER_SPECIFIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|SPD4_MODULE_REVISION_CODE
typedef|;
end_typedef

begin_comment
comment|///< 349     Module Revision Code
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|SPD4_DRAM_STEPPING
typedef|;
end_typedef

begin_comment
comment|///< 352     Dram Stepping
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD4_UNIQUE_MODULE_ID
name|ModuleId
decl_stmt|;
comment|///< 320-328 Unique Module ID
name|SPD4_MODULE_PART_NUMBER
name|ModulePartNumber
decl_stmt|;
comment|///< 329-348 Module Part Number
name|SPD4_MODULE_REVISION_CODE
name|ModuleRevisionCode
decl_stmt|;
comment|///< 349     Module Revision Code
name|SPD4_MANUFACTURER_ID_CODE
name|DramIdCode
decl_stmt|;
comment|///< 350-351 Dram Manufacturer ID Code
name|SPD4_DRAM_STEPPING
name|DramStepping
decl_stmt|;
comment|///< 352     Dram Stepping
name|SPD4_MANUFACTURER_SPECIFIC
name|ManufacturerSpecificData
decl_stmt|;
comment|///< 353-381 Manufacturer's Specific Data
name|UINT8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|///< 382-383 Reserved
block|}
name|SPD4_MANUFACTURING_DATA
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
comment|///< 384-511 Unbuffered Memory Module Types
block|}
name|SPD4_END_USER_SECTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DDR4 Serial Presence Detect structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD4_BASE_SECTION
name|Base
decl_stmt|;
comment|///< 0-127   Base Configuration and DRAM Parameters
name|SPD4_MODULE_SPECIFIC
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
comment|///< 256-319 Reserved
name|SPD4_MANUFACTURING_DATA
name|ManufactureInfo
decl_stmt|;
comment|///< 320-383 Manufacturing Information
name|SPD4_END_USER_SECTION
name|EndUser
decl_stmt|;
comment|///< 384-511 End User Programmable
block|}
name|SPD_DDR4
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

