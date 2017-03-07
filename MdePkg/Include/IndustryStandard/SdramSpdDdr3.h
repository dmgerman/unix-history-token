begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file contains definitions for SPD DDR3.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:     - Serial Presence Detect (SPD) for DDR3 SDRAM Modules Document Release 6       http://www.jedec.org/sites/default/files/docs/4_01_02_11R21A.pdf **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SDRAM_SPD_DDR3_H_
end_ifndef

begin_define
define|#
directive|define
name|_SDRAM_SPD_DDR3_H_
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
name|SPD3_DEVICE_DESCRIPTION_STRUCT
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
name|SPD3_REVISION_STRUCT
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
name|SPD3_DRAM_DEVICE_TYPE_STRUCT
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
name|SPD3_MODULE_TYPE_STRUCT
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
literal|3
decl_stmt|;
comment|///< Bits 6:4
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
name|SPD3_SDRAM_DENSITY_BANKS_STRUCT
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
name|SPD3_SDRAM_ADDRESSING_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|OperationAt1_50
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|OperationAt1_35
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT8
name|OperationAt1_25
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT8
name|Reserved
range|:
literal|5
decl_stmt|;
comment|///< Bits 7:3
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD3_MODULE_NOMINAL_VOLTAGE_STRUCT
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
name|SPD3_MODULE_ORGANIZATION_STRUCT
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
name|SPD3_MODULE_MEMORY_BUS_WIDTH_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Divisor
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|Dividend
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
name|SPD3_FINE_TIMEBASE_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Dividend
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
name|SPD3_MEDIUM_TIMEBASE_DIVIDEND_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Divisor
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
name|SPD3_MEDIUM_TIMEBASE_DIVISOR_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD3_MEDIUM_TIMEBASE_DIVIDEND_STRUCT
name|Dividend
decl_stmt|;
comment|///< Medium Timebase (MTB) Dividend
name|SPD3_MEDIUM_TIMEBASE_DIVISOR_STRUCT
name|Divisor
decl_stmt|;
comment|///< Medium Timebase (MTB) Divisor
block|}
name|SPD3_MEDIUM_TIMEBASE
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
name|SPD3_TCK_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT16
name|Cl4
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT16
name|Cl5
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT16
name|Cl6
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT16
name|Cl7
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT16
name|Cl8
range|:
literal|1
decl_stmt|;
comment|///< Bits 4:4
name|UINT16
name|Cl9
range|:
literal|1
decl_stmt|;
comment|///< Bits 5:5
name|UINT16
name|Cl10
range|:
literal|1
decl_stmt|;
comment|///< Bits 6:6
name|UINT16
name|Cl11
range|:
literal|1
decl_stmt|;
comment|///< Bits 7:7
name|UINT16
name|Cl12
range|:
literal|1
decl_stmt|;
comment|///< Bits 8:8
name|UINT16
name|Cl13
range|:
literal|1
decl_stmt|;
comment|///< Bits 9:9
name|UINT16
name|Cl14
range|:
literal|1
decl_stmt|;
comment|///< Bits 10:10
name|UINT16
name|Cl15
range|:
literal|1
decl_stmt|;
comment|///< Bits 11:11
name|UINT16
name|Cl16
range|:
literal|1
decl_stmt|;
comment|///< Bits 12:12
name|UINT16
name|Cl17
range|:
literal|1
decl_stmt|;
comment|///< Bits 13:13
name|UINT16
name|Cl18
range|:
literal|1
decl_stmt|;
comment|///< Bits 14:14
name|UINT16
name|Reserved
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
name|SPD3_CAS_LATENCIES_SUPPORTED_STRUCT
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
name|SPD3_TAA_MIN_MTB_STRUCT
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
name|SPD3_TWR_MIN_MTB_STRUCT
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
name|SPD3_TRCD_MIN_MTB_STRUCT
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
name|SPD3_TRRD_MIN_MTB_STRUCT
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
name|SPD3_TRP_MIN_MTB_STRUCT
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
name|SPD3_TRAS_TRC_MIN_MTB_STRUCT
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
name|SPD3_TRAS_MIN_MTB_STRUCT
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
name|SPD3_TRC_MIN_MTB_STRUCT
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
name|SPD3_TRFC_MIN_MTB_STRUCT
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
name|SPD3_TWTR_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|tRTPmin
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
name|SPD3_TRTP_MIN_MTB_STRUCT
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
name|SPD3_TFAW_MIN_MTB_UPPER_STRUCT
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
name|SPD3_TFAW_MIN_MTB_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Rzq6
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|Rzq7
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT8
name|Reserved
range|:
literal|5
decl_stmt|;
comment|///< Bits 6:2
name|UINT8
name|DllOff
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
name|SPD3_SDRAM_OPTIONAL_FEATURES_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|ExtendedTemperatureRange
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|ExtendedTemperatureRefreshRate
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT8
name|AutoSelfRefresh
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT8
name|OnDieThermalSensor
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT8
name|Reserved
range|:
literal|3
decl_stmt|;
comment|///< Bits 6:4
name|UINT8
name|PartialArraySelfRefresh
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
name|SPD3_SDRAM_THERMAL_REFRESH_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|ThermalSensorAccuracy
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
name|SPD3_MODULE_THERMAL_SENSOR_STRUCT
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
name|SdramDeviceType
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
name|SPD3_SDRAM_DEVICE_TYPE_STRUCT
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
name|SPD3_TCK_MIN_FTB_STRUCT
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
name|SPD3_TAA_MIN_FTB_STRUCT
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
name|SPD3_TRCD_MIN_FTB_STRUCT
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
name|SPD3_TRP_MIN_FTB_STRUCT
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
name|SPD3_TRC_MIN_FTB_STRUCT
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
name|VendorSpecific
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
name|SPD3_MAXIMUM_ACTIVE_COUNT_STRUCT
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
name|SPD3_UNBUF_MODULE_NOMINAL_HEIGHT
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
name|SPD3_UNBUF_MODULE_NOMINAL_THICKNESS
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
name|SPD3_UNBUF_REFERENCE_RAW_CARD
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
name|SPD3_UNBUF_ADDRESS_MAPPING
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
name|SPD3_RDIMM_MODULE_NOMINAL_HEIGHT
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
name|SPD3_RDIMM_MODULE_NOMINAL_THICKNESS
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
name|SPD3_RDIMM_REFERENCE_RAW_CARD
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
name|SPD3_RDIMM_MODULE_ATTRIBUTES
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
name|SPD3_RDIMM_THERMAL_HEAT_SPREADER_SOLUTION
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
name|SPD3_MANUFACTURER_ID_CODE
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
name|SPD3_RDIMM_REGISTER_REVISION_NUMBER
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Bit0
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|Bit1
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT8
name|Bit2
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT8
name|Reserved
range|:
literal|5
decl_stmt|;
comment|///< Bits 7:3
block|}
name|Bits
struct|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|SPD3_RDIMM_REGISTER_TYPE
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
comment|///< Bits 0:3
name|UINT8
name|CommandAddressAOutputs
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|CommandAddressBOutputs
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
name|SPD3_RDIMM_REGISTER_CONTROL_COMMAND_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|ControlSignalsAOutputs
range|:
literal|2
decl_stmt|;
comment|///< Bits 0:1
name|UINT8
name|ControlSignalsBOutputs
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|Y1Y3ClockOutputs
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|Y0Y2ClockOutputs
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
name|SPD3_RDIMM_REGISTER_CONTROL_CONTROL_CLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Reserved0
range|:
literal|4
decl_stmt|;
comment|///< Bits 0:3
name|UINT8
name|Reserved1
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
name|SPD3_RDIMM_REGISTER_CONTROL_RESERVED
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
name|SPD3_LRDIMM_MODULE_NOMINAL_HEIGHT
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
name|SPD3_LRDIMM_MODULE_NOMINAL_THICKNESS
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
name|SPD3_LRDIMM_REFERENCE_RAW_CARD
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
name|SPD3_LRDIMM_MODULE_ATTRIBUTES
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|AddressCommandPrelaunch
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|Rank1Rank5Swap
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT8
name|Reserved0
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT8
name|Reserved1
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT8
name|AddressCommandOutputs
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|QxCS_nOutputs
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
name|SPD3_LRDIMM_TIMING_CONTROL_DRIVE_STRENGTH
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|QxOdtOutputs
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|QxCkeOutputs
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|Y1Y3ClockOutputs
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|Y0Y2ClockOutputs
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
name|SPD3_LRDIMM_TIMING_DRIVE_STRENGTH
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|YExtendedDelay
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|QxCS_n
range|:
literal|2
decl_stmt|;
comment|///< Bits 3:2
name|UINT8
name|QxOdt
range|:
literal|2
decl_stmt|;
comment|///< Bits 5:4
name|UINT8
name|QxCke
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
name|SPD3_LRDIMM_EXTENDED_DELAY
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|DelayY
range|:
literal|3
decl_stmt|;
comment|///< Bits 2:0
name|UINT8
name|Reserved
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT8
name|QxCS_n
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
name|SPD3_LRDIMM_ADDITIVE_DELAY_FOR_QXCS_N_QXCA
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|QxCS_n
range|:
literal|4
decl_stmt|;
comment|///< Bits 3:0
name|UINT8
name|QxOdt
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
name|SPD3_LRDIMM_ADDITIVE_DELAY_FOR_QXODT_QXCKE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|RC8MdqOdtStrength
range|:
literal|3
decl_stmt|;
comment|///< Bits 2:0
name|UINT8
name|RC8Reserved
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT8
name|RC9MdqOdtStrength
range|:
literal|3
decl_stmt|;
comment|///< Bits 6:4
name|UINT8
name|RC9Reserved
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
name|SPD3_LRDIMM_MDQ_TERMINATION_DRIVE_STRENGTH
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|RC10DA3ValueR0
range|:
literal|1
decl_stmt|;
comment|///< Bits 0:0
name|UINT8
name|RC10DA4ValueR0
range|:
literal|1
decl_stmt|;
comment|///< Bits 1:1
name|UINT8
name|RC10DA3ValueR1
range|:
literal|1
decl_stmt|;
comment|///< Bits 2:2
name|UINT8
name|RC10DA4ValueR1
range|:
literal|1
decl_stmt|;
comment|///< Bits 3:3
name|UINT8
name|RC11DA3ValueR0
range|:
literal|1
decl_stmt|;
comment|///< Bits 4:4
name|UINT8
name|RC11DA4ValueR0
range|:
literal|1
decl_stmt|;
comment|///< Bits 5:5
name|UINT8
name|RC11DA3ValueR1
range|:
literal|1
decl_stmt|;
comment|///< Bits 6:6
name|UINT8
name|RC11DA4ValueR1
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
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Driver_Impedance
range|:
literal|2
decl_stmt|;
comment|///< Bits 1:0
name|UINT8
name|Rtt_Nom
range|:
literal|3
decl_stmt|;
comment|///< Bits 4:2
name|UINT8
name|Reserved
range|:
literal|1
decl_stmt|;
comment|///< Bits 5:5
name|UINT8
name|Rtt_WR
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
name|SPD3_LRDIMM_MR_1_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|MinimumDelayTime
range|:
literal|7
decl_stmt|;
comment|///< Bits 0:6
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
name|SPD3_LRDIMM_MODULE_DELAY_TIME
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
name|SPD3_MANUFACTURING_DATE
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
name|SPD3_MANUFACTURER_SERIAL_NUMBER
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
name|SPD3_MANUFACTURING_LOCATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD3_MANUFACTURER_ID_CODE
name|IdCode
decl_stmt|;
comment|///< Module Manufacturer ID Code
name|SPD3_MANUFACTURING_LOCATION
name|Location
decl_stmt|;
comment|///< Module Manufacturing Location
name|SPD3_MANUFACTURING_DATE
name|Date
decl_stmt|;
comment|///< Module Manufacturing Year, in BCD (range: 2000-2255)
name|SPD3_MANUFACTURER_SERIAL_NUMBER
name|SerialNumber
decl_stmt|;
comment|///< Module Serial Number
block|}
name|SPD3_UNIQUE_MODULE_ID
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
name|SPD3_CYCLIC_REDUNDANCY_CODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD3_DEVICE_DESCRIPTION_STRUCT
name|Description
decl_stmt|;
comment|///< 0   Number of Serial PD Bytes Written / SPD Device Size / CRC Coverage 1, 2
name|SPD3_REVISION_STRUCT
name|Revision
decl_stmt|;
comment|///< 1   SPD Revision
name|SPD3_DRAM_DEVICE_TYPE_STRUCT
name|DramDeviceType
decl_stmt|;
comment|///< 2   DRAM Device Type
name|SPD3_MODULE_TYPE_STRUCT
name|ModuleType
decl_stmt|;
comment|///< 3   Module Type
name|SPD3_SDRAM_DENSITY_BANKS_STRUCT
name|SdramDensityAndBanks
decl_stmt|;
comment|///< 4   SDRAM Density and Banks
name|SPD3_SDRAM_ADDRESSING_STRUCT
name|SdramAddressing
decl_stmt|;
comment|///< 5   SDRAM Addressing
name|SPD3_MODULE_NOMINAL_VOLTAGE_STRUCT
name|ModuleNominalVoltage
decl_stmt|;
comment|///< 6   Module Nominal Voltage, VDD
name|SPD3_MODULE_ORGANIZATION_STRUCT
name|ModuleOrganization
decl_stmt|;
comment|///< 7   Module Organization
name|SPD3_MODULE_MEMORY_BUS_WIDTH_STRUCT
name|ModuleMemoryBusWidth
decl_stmt|;
comment|///< 8   Module Memory Bus Width
name|SPD3_FINE_TIMEBASE_STRUCT
name|FineTimebase
decl_stmt|;
comment|///< 9   Fine Timebase (FTB) Dividend / Divisor
name|SPD3_MEDIUM_TIMEBASE
name|MediumTimebase
decl_stmt|;
comment|///< 10-11 Medium Timebase (MTB) Dividend
name|SPD3_TCK_MIN_MTB_STRUCT
name|tCKmin
decl_stmt|;
comment|///< 12  SDRAM Minimum Cycle Time (tCKmin)
name|UINT8
name|Reserved0
decl_stmt|;
comment|///< 13  Reserved
name|SPD3_CAS_LATENCIES_SUPPORTED_STRUCT
name|CasLatencies
decl_stmt|;
comment|///< 14-15 CAS Latencies Supported
name|SPD3_TAA_MIN_MTB_STRUCT
name|tAAmin
decl_stmt|;
comment|///< 16  Minimum CAS Latency Time (tAAmin)
name|SPD3_TWR_MIN_MTB_STRUCT
name|tWRmin
decl_stmt|;
comment|///< 17  Minimum Write Recovery Time (tWRmin)
name|SPD3_TRCD_MIN_MTB_STRUCT
name|tRCDmin
decl_stmt|;
comment|///< 18  Minimum RAS# to CAS# Delay Time (tRCDmin)
name|SPD3_TRRD_MIN_MTB_STRUCT
name|tRRDmin
decl_stmt|;
comment|///< 19  Minimum Row Active to Row Active Delay Time (tRRDmin)
name|SPD3_TRP_MIN_MTB_STRUCT
name|tRPmin
decl_stmt|;
comment|///< 20  Minimum Row Precharge Delay Time (tRPmin)
name|SPD3_TRAS_TRC_MIN_MTB_STRUCT
name|tRASMintRCMinUpper
decl_stmt|;
comment|///< 21  Upper Nibbles for tRAS and tRC
name|SPD3_TRAS_MIN_MTB_STRUCT
name|tRASmin
decl_stmt|;
comment|///< 22  Minimum Active to Precharge Delay Time (tRASmin), Least Significant Byte
name|SPD3_TRC_MIN_MTB_STRUCT
name|tRCmin
decl_stmt|;
comment|///< 23  Minimum Active to Active/Refresh Delay Time (tRCmin), Least Significant Byte
name|SPD3_TRFC_MIN_MTB_STRUCT
name|tRFCmin
decl_stmt|;
comment|///< 24-25  Minimum Refresh Recovery Delay Time (tRFCmin)
name|SPD3_TWTR_MIN_MTB_STRUCT
name|tWTRmin
decl_stmt|;
comment|///< 26  Minimum Internal Write to Read Command Delay Time (tWTRmin)
name|SPD3_TRTP_MIN_MTB_STRUCT
name|tRTPmin
decl_stmt|;
comment|///< 27  Minimum Internal Read to Precharge Command Delay Time (tRTPmin)
name|SPD3_TFAW_MIN_MTB_UPPER_STRUCT
name|tFAWMinUpper
decl_stmt|;
comment|///< 28  Upper Nibble for tFAW
name|SPD3_TFAW_MIN_MTB_STRUCT
name|tFAWmin
decl_stmt|;
comment|///< 29  Minimum Four Activate Window Delay Time (tFAWmin)
name|SPD3_SDRAM_OPTIONAL_FEATURES_STRUCT
name|SdramOptionalFeatures
decl_stmt|;
comment|///< 30  SDRAM Optional Features
name|SPD3_SDRAM_THERMAL_REFRESH_STRUCT
name|ThermalAndRefreshOptions
decl_stmt|;
comment|///< 31  SDRAM Thermal And Refresh Options
name|SPD3_MODULE_THERMAL_SENSOR_STRUCT
name|ModuleThermalSensor
decl_stmt|;
comment|///< 32  Module Thermal Sensor
name|SPD3_SDRAM_DEVICE_TYPE_STRUCT
name|SdramDeviceType
decl_stmt|;
comment|///< 33  SDRAM Device Type
name|SPD3_TCK_MIN_FTB_STRUCT
name|tCKminFine
decl_stmt|;
comment|///< 34  Fine Offset for SDRAM Minimum Cycle Time (tCKmin)
name|SPD3_TAA_MIN_FTB_STRUCT
name|tAAminFine
decl_stmt|;
comment|///< 35  Fine Offset for Minimum CAS Latency Time (tAAmin)
name|SPD3_TRCD_MIN_FTB_STRUCT
name|tRCDminFine
decl_stmt|;
comment|///< 36  Fine Offset for Minimum RAS# to CAS# Delay Time (tRCDmin)
name|SPD3_TRP_MIN_FTB_STRUCT
name|tRPminFine
decl_stmt|;
comment|///< 37  Minimum Row Precharge Delay Time (tRPmin)
name|SPD3_TRC_MIN_FTB_STRUCT
name|tRCminFine
decl_stmt|;
comment|///< 38  Fine Offset for Minimum Active to Active/Refresh Delay Time (tRCmin)
name|UINT8
name|Reserved1
index|[
literal|40
operator|-
literal|39
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 39 - 40 Reserved
name|SPD3_MAXIMUM_ACTIVE_COUNT_STRUCT
name|MacValue
decl_stmt|;
comment|///< 41  SDRAM Maximum Active Count (MAC) Value
name|UINT8
name|Reserved2
index|[
literal|59
operator|-
literal|42
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 42 - 59 Reserved
block|}
name|SPD3_BASE_SECTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD3_UNBUF_MODULE_NOMINAL_HEIGHT
name|ModuleNominalHeight
decl_stmt|;
comment|///< 60  Module Nominal Height
name|SPD3_UNBUF_MODULE_NOMINAL_THICKNESS
name|ModuleMaximumThickness
decl_stmt|;
comment|///< 61  Module Maximum Thickness
name|SPD3_UNBUF_REFERENCE_RAW_CARD
name|ReferenceRawCardUsed
decl_stmt|;
comment|///< 62  Reference Raw Card Used
name|SPD3_UNBUF_ADDRESS_MAPPING
name|AddressMappingEdgeConn
decl_stmt|;
comment|///< 63  Address Mapping from Edge Connector to DRAM
name|UINT8
name|Reserved
index|[
literal|116
operator|-
literal|64
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 64-116 Reserved
block|}
name|SPD3_MODULE_UNBUFFERED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD3_RDIMM_MODULE_NOMINAL_HEIGHT
name|ModuleNominalHeight
decl_stmt|;
comment|///< 60  Module Nominal Height
name|SPD3_RDIMM_MODULE_NOMINAL_THICKNESS
name|ModuleMaximumThickness
decl_stmt|;
comment|///< 61  Module Maximum Thickness
name|SPD3_RDIMM_REFERENCE_RAW_CARD
name|ReferenceRawCardUsed
decl_stmt|;
comment|///< 62  Reference Raw Card Used
name|SPD3_RDIMM_MODULE_ATTRIBUTES
name|DimmModuleAttributes
decl_stmt|;
comment|///< 63  DIMM Module Attributes
name|SPD3_RDIMM_THERMAL_HEAT_SPREADER_SOLUTION
name|ThermalHeatSpreaderSolution
decl_stmt|;
comment|///< 64     RDIMM Thermal Heat Spreader Solution
name|SPD3_MANUFACTURER_ID_CODE
name|RegisterManufacturerIdCode
decl_stmt|;
comment|///< 65-66  Register Manufacturer ID Code
name|SPD3_RDIMM_REGISTER_REVISION_NUMBER
name|RegisterRevisionNumber
decl_stmt|;
comment|///< 67     Register Revision Number
name|SPD3_RDIMM_REGISTER_TYPE
name|RegisterType
decl_stmt|;
comment|///< 68  Register Type
name|SPD3_RDIMM_REGISTER_CONTROL_RESERVED
name|Rc1Rc0
decl_stmt|;
comment|///< 69  RC1 (MS Nibble) / RC0 (LS Nibble) - Reserved
name|SPD3_RDIMM_REGISTER_CONTROL_COMMAND_ADDRESS
name|Rc3Rc2
decl_stmt|;
comment|///< 70  RC3 (MS Nibble) / RC2 (LS Nibble) - Drive Strength, Command/Address
name|SPD3_RDIMM_REGISTER_CONTROL_CONTROL_CLOCK
name|Rc5Rc4
decl_stmt|;
comment|///< 71  RC5 (MS Nibble) / RC4 (LS Nibble) - Drive Strength, Control and Clock
name|SPD3_RDIMM_REGISTER_CONTROL_RESERVED
name|Rc7Rc6
decl_stmt|;
comment|///< 72  RC7 (MS Nibble) / RC6 (LS Nibble) - Reserved for Register Vendor
name|SPD3_RDIMM_REGISTER_CONTROL_RESERVED
name|Rc9Rc8
decl_stmt|;
comment|///< 73  RC9 (MS Nibble) / RC8 (LS Nibble) - Reserved
name|SPD3_RDIMM_REGISTER_CONTROL_RESERVED
name|Rc11Rc10
decl_stmt|;
comment|///< 74  RC11 (MS Nibble) / RC10 (LS Nibble) - Reserved
name|SPD3_RDIMM_REGISTER_CONTROL_RESERVED
name|Rc13Rc12
decl_stmt|;
comment|///< 75  RC12 (MS Nibble) / RC12 (LS Nibble) - Reserved
name|SPD3_RDIMM_REGISTER_CONTROL_RESERVED
name|Rc15Rc14
decl_stmt|;
comment|///< 76  RC15 (MS Nibble) / RC14 (LS Nibble) - Reserved
name|UINT8
name|Reserved
index|[
literal|116
operator|-
literal|77
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 77-116 Reserved
block|}
name|SPD3_MODULE_REGISTERED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD3_UNBUF_MODULE_NOMINAL_HEIGHT
name|ModuleNominalHeight
decl_stmt|;
comment|///< 60  Module Nominal Height
name|SPD3_UNBUF_MODULE_NOMINAL_THICKNESS
name|ModuleMaximumThickness
decl_stmt|;
comment|///< 61  Module Maximum Thickness
name|SPD3_UNBUF_REFERENCE_RAW_CARD
name|ReferenceRawCardUsed
decl_stmt|;
comment|///< 62  Reference Raw Card Used
name|UINT8
name|Reserved
index|[
literal|116
operator|-
literal|63
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 63-116 Reserved
block|}
name|SPD3_MODULE_CLOCKED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD3_LRDIMM_MODULE_NOMINAL_HEIGHT
name|ModuleNominalHeight
decl_stmt|;
comment|///< 60  Module Nominal Height
name|SPD3_LRDIMM_MODULE_NOMINAL_THICKNESS
name|ModuleMaximumThickness
decl_stmt|;
comment|///< 61  Module Maximum Thickness
name|SPD3_LRDIMM_REFERENCE_RAW_CARD
name|ReferenceRawCardUsed
decl_stmt|;
comment|///< 62  Reference Raw Card Used
name|SPD3_LRDIMM_MODULE_ATTRIBUTES
name|DimmModuleAttributes
decl_stmt|;
comment|///< 63  Module Attributes
name|UINT8
name|MemoryBufferRevisionNumber
decl_stmt|;
comment|///< 64    Memory Buffer Revision Number
name|SPD3_MANUFACTURER_ID_CODE
name|ManufacturerIdCode
decl_stmt|;
comment|///< 65-66 Memory Buffer Manufacturer ID Code
name|SPD3_LRDIMM_TIMING_CONTROL_DRIVE_STRENGTH
name|TimingControlDriveStrengthCaCs
decl_stmt|;
comment|///< 67    F0RC3 / F0RC2 - Timing Control& Drive Strength, CA& CS
name|SPD3_LRDIMM_TIMING_DRIVE_STRENGTH
name|DriveStrength
decl_stmt|;
comment|///< 68    F0RC5 / F0RC4 - Drive Strength, ODT& CKE and Y
name|SPD3_LRDIMM_EXTENDED_DELAY
name|ExtendedDelay
decl_stmt|;
comment|///< 69    F1RC11 / F1RC8 - Extended Delay for Y, CS and ODT& CKE
name|SPD3_LRDIMM_ADDITIVE_DELAY_FOR_QXCS_N_QXCA
name|AdditiveDelayForCsCa
decl_stmt|;
comment|///< 70    F1RC13 / F1RC12 - Additive Delay for CS and CA
name|SPD3_LRDIMM_ADDITIVE_DELAY_FOR_QXODT_QXCKE
name|AdditiveDelayForOdtCke
decl_stmt|;
comment|///< 71    F1RC15 / F1RC14 - Additive Delay for ODT& CKE
name|SPD3_LRDIMM_MDQ_TERMINATION_DRIVE_STRENGTH
name|MdqTerminationDriveStrengthFor800_1066
decl_stmt|;
comment|///< 72    F1RC15 / F1RC14 - Additive Delay for ODT& CKE
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_0_1QxOdtControlFor800_1066
decl_stmt|;
comment|///< 73    F[3,4]RC11 / F[3,4]RC10 - Rank 0& 1 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_2_3QxOdtControlFor800_1066
decl_stmt|;
comment|///< 74    F[5,6]RC11 / F[5,6]RC10 - Rank 2& 3 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_4_5QxOdtControlFor800_1066
decl_stmt|;
comment|///< 75    F[7,8]RC11 / F[7,8]RC10 - Rank 4& 5 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_6_7QxOdtControlFor800_1066
decl_stmt|;
comment|///< 76    F[9,10]RC11 / F[9,10]RC10 - Rank 6& 7 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_MR_1_2
name|MR_1_2RegistersFor800_1066
decl_stmt|;
comment|///< 77    MR1,2 Registers for 800& 1066
name|SPD3_LRDIMM_MDQ_TERMINATION_DRIVE_STRENGTH
name|MdqTerminationDriveStrengthFor1333_1600
decl_stmt|;
comment|///< 78    F1RC15 / F1RC14 - Additive Delay for ODT& CKE
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_0_1QxOdtControlFor1333_1600
decl_stmt|;
comment|///< 79    F[3,4]RC11 / F[3,4]RC10 - Rank 0& 1 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_2_3QxOdtControlFor1333_1600
decl_stmt|;
comment|///< 80    F[5,6]RC11 / F[5,6]RC10 - Rank 2& 3 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_4_5QxOdtControlFor1333_1600
decl_stmt|;
comment|///< 81    F[7,8]RC11 / F[7,8]RC10 - Rank 4& 5 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_6_7QxOdtControlFor1333_1600
decl_stmt|;
comment|///< 82    F[9,10]RC11 / F[9,10]RC10 - Rank 6& 7 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_MR_1_2
name|MR_1_2RegistersFor1333_1600
decl_stmt|;
comment|///< 83    MR1,2 Registers for 800& 1066
name|SPD3_LRDIMM_MDQ_TERMINATION_DRIVE_STRENGTH
name|MdqTerminationDriveStrengthFor1866_2133
decl_stmt|;
comment|///< 84    F1RC15 / F1RC14 - Additive Delay for ODT& CKE
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_0_1QxOdtControlFor1866_2133
decl_stmt|;
comment|///< 85    F[3,4]RC11 / F[3,4]RC10 - Rank 0& 1 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_2_3QxOdtControlFor1866_2133
decl_stmt|;
comment|///< 86    F[5,6]RC11 / F[5,6]RC10 - Rank 2& 3 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_4_5QxOdtControlFor1866_2133
decl_stmt|;
comment|///< 87    F[7,8]RC11 / F[7,8]RC10 - Rank 4& 5 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_RANK_READ_WRITE_QXODT_CONTROL
name|Rank_6_7QxOdtControlFor1866_2133
decl_stmt|;
comment|///< 88    F[9,10]RC11 / F[9,10]RC10 - Rank 6& 7 RD& WR QxODT Control for 800& 1066
name|SPD3_LRDIMM_MR_1_2
name|MR_1_2RegistersFor1866_2133
decl_stmt|;
comment|///< 89    MR1,2 Registers for 800& 1066
name|SPD3_LRDIMM_MODULE_DELAY_TIME
name|MinimumModuleDelayTimeFor1_5V
decl_stmt|;
comment|///< 90    Minimum Module Delay Time for 1.5 V
name|SPD3_LRDIMM_MODULE_DELAY_TIME
name|MaximumModuleDelayTimeFor1_5V
decl_stmt|;
comment|///< 91    Maximum Module Delay Time for 1.5 V
name|SPD3_LRDIMM_MODULE_DELAY_TIME
name|MinimumModuleDelayTimeFor1_35V
decl_stmt|;
comment|///< 92    Minimum Module Delay Time for 1.35 V
name|SPD3_LRDIMM_MODULE_DELAY_TIME
name|MaximumModuleDelayTimeFor1_35V
decl_stmt|;
comment|///< 93    Maximum Module Delay Time for 1.35 V
name|SPD3_LRDIMM_MODULE_DELAY_TIME
name|MinimumModuleDelayTimeFor1_25V
decl_stmt|;
comment|///< 94    Minimum Module Delay Time for 1.25 V
name|SPD3_LRDIMM_MODULE_DELAY_TIME
name|MaximumModuleDelayTimeFor1_25V
decl_stmt|;
comment|///< 95    Maximum Module Delay Time for 1.25 V
name|UINT8
name|Reserved
index|[
literal|101
operator|-
literal|96
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 96-101  Reserved
name|UINT8
name|PersonalityByte
index|[
literal|116
operator|-
literal|102
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 102-116 Memory Buffer Personality Bytes
block|}
name|SPD3_MODULE_LOADREDUCED
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|SPD3_MODULE_UNBUFFERED
name|Unbuffered
decl_stmt|;
comment|///< 128-255 Unbuffered Memory Module Types
name|SPD3_MODULE_REGISTERED
name|Registered
decl_stmt|;
comment|///< 128-255 Registered Memory Module Types
name|SPD3_MODULE_CLOCKED
name|Clocked
decl_stmt|;
comment|///< 128-255 Registered Memory Module Types
name|SPD3_MODULE_LOADREDUCED
name|LoadReduced
decl_stmt|;
comment|///< 128-255 Load Reduced Memory Module Types
block|}
name|SPD3_MODULE_SPECIFIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ModulePartNumber
index|[
literal|145
operator|-
literal|128
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 128-145 Module Part Number
block|}
name|SPD3_MODULE_PART_NUMBER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ModuleRevisionCode
index|[
literal|147
operator|-
literal|146
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 146-147 Module Revision Code
block|}
name|SPD3_MODULE_REVISION_CODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ManufacturerSpecificData
index|[
literal|175
operator|-
literal|150
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 150-175 Manufacturer's Specific Data
block|}
name|SPD3_MANUFACTURER_SPECIFIC
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DDR3 Serial Presence Detect structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPD3_BASE_SECTION
name|General
decl_stmt|;
comment|///< 0-59    General Section
name|SPD3_MODULE_SPECIFIC
name|Module
decl_stmt|;
comment|///< 60-116  Module-Specific Section
name|SPD3_UNIQUE_MODULE_ID
name|ModuleId
decl_stmt|;
comment|///< 117-125 Unique Module ID
name|SPD3_CYCLIC_REDUNDANCY_CODE
name|Crc
decl_stmt|;
comment|///< 126-127 Cyclical Redundancy Code (CRC)
name|SPD3_MODULE_PART_NUMBER
name|ModulePartNumber
decl_stmt|;
comment|///< 128-145 Module Part Number
name|SPD3_MODULE_REVISION_CODE
name|ModuleRevisionCode
decl_stmt|;
comment|///< 146-147 Module Revision Code
name|SPD3_MANUFACTURER_ID_CODE
name|DramIdCode
decl_stmt|;
comment|///< 148-149 Dram Manufacturer ID Code
name|SPD3_MANUFACTURER_SPECIFIC
name|ManufacturerSpecificData
decl_stmt|;
comment|///< 150-175 Manufacturer's Specific Data
name|UINT8
name|Reserved
index|[
literal|255
operator|-
literal|176
operator|+
literal|1
index|]
decl_stmt|;
comment|///< 176-255 Open for Customer Use
block|}
name|SPD_DDR3
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

