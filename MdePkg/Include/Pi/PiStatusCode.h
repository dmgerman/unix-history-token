begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   StatusCode related definitions in PI.  Copyright (c) 2009 - 2013, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   These status codes are defined in UEFI Platform Initialization Specification 1.2,    Volume 3: Shared Architectural Elements.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_STATUS_CODE_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_STATUS_CODE_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Required for IA32, X64, IPF, ARM and EBC defines for CPU exception types
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|<Protocol/DebugSupport.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Status Code Type Definition.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_STATUS_CODE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A Status Code Type is made up of the code type and severity.
end_comment

begin_comment
comment|/// All values masked by EFI_STATUS_CODE_RESERVED_MASK are
end_comment

begin_comment
comment|/// reserved for use by this specification.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_STATUS_CODE_TYPE_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|EFI_STATUS_CODE_SEVERITY_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|EFI_STATUS_CODE_RESERVED_MASK
value|0x00FFFF00
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of code types. All other values masked by
end_comment

begin_comment
comment|/// EFI_STATUS_CODE_TYPE_MASK are reserved for use by
end_comment

begin_comment
comment|/// this specification.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PROGRESS_CODE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_CODE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_DEBUG_CODE
value|0x00000003
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definitions of severities, all other values masked by
end_comment

begin_comment
comment|/// EFI_STATUS_CODE_SEVERITY_MASK are reserved for use by
end_comment

begin_comment
comment|/// this specification.
end_comment

begin_comment
comment|/// Uncontained errors are major errors that could not contained
end_comment

begin_comment
comment|/// to the specific component that is reporting the error.
end_comment

begin_comment
comment|/// For example, if a memory error was not detected early enough,
end_comment

begin_comment
comment|/// the bad data could be consumed by other drivers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_ERROR_MINOR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_MAJOR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_UNRECOVERED
value|0x90000000
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_UNCONTAINED
value|0xa0000000
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Status Code Value Definition.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_STATUS_CODE_VALUE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A Status Code Value is made up of the class, subclass, and
end_comment

begin_comment
comment|/// an operation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_STATUS_CODE_CLASS_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|EFI_STATUS_CODE_SUBCLASS_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|EFI_STATUS_CODE_OPERATION_MASK
value|0x0000FFFF
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Status Code extended data header.
end_comment

begin_comment
comment|/// The data will follow HeaderSize bytes from the beginning of
end_comment

begin_comment
comment|/// the structure and is Size bytes long.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The size of the structure. This is specified to enable future expansion.
comment|///
name|UINT16
name|HeaderSize
decl_stmt|;
comment|///
comment|/// The size of the data in bytes. This does not include the size of the header structure.
comment|///
name|UINT16
name|Size
decl_stmt|;
comment|///
comment|/// The GUID defining the type of the data.
comment|///
name|EFI_GUID
name|Type
decl_stmt|;
block|}
name|EFI_STATUS_CODE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// General partitioning scheme for Progress and Error Codes are:
end_comment

begin_comment
comment|///   - 0x0000-0x0FFF    Shared by all sub-classes in a given class.
end_comment

begin_comment
comment|///   - 0x1000-0x7FFF    Subclass Specific.
end_comment

begin_comment
comment|///   - 0x8000-0xFFFF    OEM specific.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SUBCLASS_SPECIFIC
value|0x1000
end_define

begin_define
define|#
directive|define
name|EFI_OEM_SPECIFIC
value|0x8000
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Debug Code definitions for all classes and subclass.
end_comment

begin_comment
comment|/// Only one debug code is defined at this point and should
end_comment

begin_comment
comment|/// be used for anything that is sent to the debug stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_DC_UNSPECIFIED
value|0x0
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Class definitions.
end_comment

begin_comment
comment|/// Values of 4-127 are reserved for future use by this specification.
end_comment

begin_comment
comment|/// Values in the range 127-255 are reserved for OEM use.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS
value|0x02000000
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE
value|0x03000000
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Subclass definitions.
end_comment

begin_comment
comment|/// Values of 8-127 are reserved for future use by this specification.
end_comment

begin_comment
comment|/// Values of 128-255 are reserved for OEM use.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_UNSPECIFIED
value|(EFI_COMPUTING_UNIT | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_HOST_PROCESSOR
value|(EFI_COMPUTING_UNIT | 0x00010000)
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_FIRMWARE_PROCESSOR
value|(EFI_COMPUTING_UNIT | 0x00020000)
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_IO_PROCESSOR
value|(EFI_COMPUTING_UNIT | 0x00030000)
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_CACHE
value|(EFI_COMPUTING_UNIT | 0x00040000)
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MEMORY
value|(EFI_COMPUTING_UNIT | 0x00050000)
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_CHIPSET
value|(EFI_COMPUTING_UNIT | 0x00060000)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Class Progress Code definitions.
end_comment

begin_comment
comment|/// These are shared by all subclasses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CU_PC_INIT_BEGIN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_CU_PC_INIT_END
value|0x00000001
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Computing Unit Unspecified Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Host Processor Subclass Progress Code definitions.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CU_HP_PC_POWER_ON_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_PC_CACHE_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_PC_RAM_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_PC_MEMORY_CONTROLLER_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_PC_IO_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_PC_BSP_SELECT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_PC_BSP_RESELECT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_PC_AP_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000007)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_PC_SMM_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000008)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Computing Unit Firmware Processor Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Computing Unit IO Processor Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Cache Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CU_CACHE_PC_PRESENCE_DETECT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_CU_CACHE_PC_CONFIGURATION
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Memory Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_PC_SPD_READ
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_PC_PRESENCE_DETECT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_PC_TIMING
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_PC_CONFIGURING
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_PC_OPTIMIZING
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_PC_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_PC_TEST
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Computing Unit Chipset Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// South Bridge initialization prior to memory detection.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_PEI_CAR_SB_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000000)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// North Bridge initialization prior to memory detection.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_PEI_CAR_NB_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000001)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// South Bridge initialization after memory detection.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_PEI_MEM_SB_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000002)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// North Bridge initialization after memory detection.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_PEI_MEM_NB_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000003)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Host Bridge DXE initialization.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_DXE_HB_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000004)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// North Bridge DXE initialization.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_DXE_NB_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000005)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// North Bridge specific SMM initialization in DXE.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_DXE_NB_SMM_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000006)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Initialization of the South Bridge specific UEFI Runtime Services.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_DXE_SB_RT_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000007)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// South Bridge DXE initialization
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_DXE_SB_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000008)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// South Bridge specific SMM initialization in DXE.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_DXE_SB_SMM_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x00000009)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Initialization of the South Bridge devices.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_PC_DXE_SB_DEVICES_INIT
value|(EFI_SUBCLASS_SPECIFIC|0x0000000a)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Class Error Code definitions.
end_comment

begin_comment
comment|/// These are shared by all subclasses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CU_EC_NON_SPECIFIC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_CU_EC_DISABLED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_CU_EC_NOT_SUPPORTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_CU_EC_NOT_DETECTED
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EFI_CU_EC_NOT_CONFIGURED
value|0x00000004
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Computing Unit Unspecified Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Host Processor Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_INVALID_TYPE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_INVALID_SPEED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_MISMATCH
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_TIMER_EXPIRED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_SELF_TEST
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_INTERNAL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_THERMAL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_LOW_VOLTAGE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000007)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_HIGH_VOLTAGE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000008)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_CACHE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000009)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_MICROCODE_UPDATE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000A)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_CORRECTABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000B)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_UNCORRECTABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000C)
end_define

begin_define
define|#
directive|define
name|EFI_CU_HP_EC_NO_MICROCODE_UPDATE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000D)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Firmware Processor Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CU_FP_EC_HARD_FAIL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_CU_FP_EC_SOFT_FAIL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_CU_FP_EC_COMM_ERROR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Computing Unit IO Processor Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Cache Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CU_CACHE_EC_INVALID_TYPE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_CU_CACHE_EC_INVALID_SPEED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_CU_CACHE_EC_INVALID_SIZE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_CU_CACHE_EC_MISMATCH
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Memory Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_INVALID_TYPE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_INVALID_SPEED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_CORRECTABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_UNCORRECTABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_SPD_FAIL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_INVALID_SIZE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_MISMATCH
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_S3_RESUME_FAIL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000007)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_UPDATE_FAIL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000008)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_NONE_DETECTED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000009)
end_define

begin_define
define|#
directive|define
name|EFI_CU_MEMORY_EC_NONE_USEFUL
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000A)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Computing Unit Chipset Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CHIPSET_EC_BAD_BATTERY
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_CHIPSET_EC_DXE_NB_ERROR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_CHIPSET_EC_DXE_SB_ERROR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Peripheral Subclass definitions.
end_comment

begin_comment
comment|/// Values of 12-127 are reserved for future use by this specification.
end_comment

begin_comment
comment|/// Values of 128-255 are reserved for OEM use.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_UNSPECIFIED
value|(EFI_PERIPHERAL | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_KEYBOARD
value|(EFI_PERIPHERAL | 0x00010000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_MOUSE
value|(EFI_PERIPHERAL | 0x00020000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_LOCAL_CONSOLE
value|(EFI_PERIPHERAL | 0x00030000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_REMOTE_CONSOLE
value|(EFI_PERIPHERAL | 0x00040000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_SERIAL_PORT
value|(EFI_PERIPHERAL | 0x00050000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_PARALLEL_PORT
value|(EFI_PERIPHERAL | 0x00060000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_FIXED_MEDIA
value|(EFI_PERIPHERAL | 0x00070000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_REMOVABLE_MEDIA
value|(EFI_PERIPHERAL | 0x00080000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_AUDIO_INPUT
value|(EFI_PERIPHERAL | 0x00090000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_AUDIO_OUTPUT
value|(EFI_PERIPHERAL | 0x000A0000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_LCD_DEVICE
value|(EFI_PERIPHERAL | 0x000B0000)
end_define

begin_define
define|#
directive|define
name|EFI_PERIPHERAL_NETWORK
value|(EFI_PERIPHERAL | 0x000C0000)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Peripheral Class Progress Code definitions.
end_comment

begin_comment
comment|/// These are shared by all subclasses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_P_PC_INIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_P_PC_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_P_PC_DISABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_P_PC_PRESENCE_DETECT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EFI_P_PC_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_P_PC_RECONFIG
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EFI_P_PC_DETECTED
value|0x00000006
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Unspecified Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Peripheral Class Keyboard Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_P_KEYBOARD_PC_CLEAR_BUFFER
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_P_KEYBOARD_PC_SELF_TEST
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Peripheral Class Mouse Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_P_MOUSE_PC_SELF_TEST
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Local Console Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Remote Console Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Peripheral Class Serial Port Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_P_SERIAL_PORT_PC_CLEAR_BUFFER
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Parallel Port Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Fixed Media Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Removable Media Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Audio Input Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Audio Output Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class LCD Device Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Network Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Peripheral Class Error Code definitions.
end_comment

begin_comment
comment|/// These are shared by all subclasses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_P_EC_NON_SPECIFIC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_P_EC_DISABLED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_P_EC_NOT_SUPPORTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_P_EC_NOT_DETECTED
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EFI_P_EC_NOT_CONFIGURED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_P_EC_INTERFACE_ERROR
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EFI_P_EC_CONTROLLER_ERROR
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EFI_P_EC_INPUT_ERROR
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EFI_P_EC_OUTPUT_ERROR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_P_EC_RESOURCE_CONFLICT
value|0x00000009
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Unspecified Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Peripheral Class Keyboard Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_P_KEYBOARD_EC_LOCKED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_P_KEYBOARD_EC_STUCK_KEY
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Peripheral Class Mouse Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_P_MOUSE_EC_LOCKED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Local Console Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Remote Console Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Serial Port Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Parallel Port Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Fixed Media Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Removable Media Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Audio Input Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Audio Output Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class LCD Device Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Peripheral Class Network Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO Bus Subclass definitions.
end_comment

begin_comment
comment|/// Values of 14-127 are reserved for future use by this specification.
end_comment

begin_comment
comment|/// Values of 128-255 are reserved for OEM use.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IO_BUS_UNSPECIFIED
value|(EFI_IO_BUS | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_PCI
value|(EFI_IO_BUS | 0x00010000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_USB
value|(EFI_IO_BUS | 0x00020000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_IBA
value|(EFI_IO_BUS | 0x00030000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_AGP
value|(EFI_IO_BUS | 0x00040000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_PC_CARD
value|(EFI_IO_BUS | 0x00050000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_LPC
value|(EFI_IO_BUS | 0x00060000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_SCSI
value|(EFI_IO_BUS | 0x00070000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_ATA_ATAPI
value|(EFI_IO_BUS | 0x00080000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_FC
value|(EFI_IO_BUS | 0x00090000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_IP_NETWORK
value|(EFI_IO_BUS | 0x000A0000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_SMBUS
value|(EFI_IO_BUS | 0x000B0000)
end_define

begin_define
define|#
directive|define
name|EFI_IO_BUS_I2C
value|(EFI_IO_BUS | 0x000C0000)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO Bus Class Progress Code definitions.
end_comment

begin_comment
comment|/// These are shared by all subclasses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IOB_PC_INIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_IOB_PC_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_IOB_PC_DISABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_IOB_PC_DETECT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EFI_IOB_PC_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_IOB_PC_RECONFIG
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EFI_IOB_PC_HOTPLUG
value|0x00000006
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class Unspecified Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO Bus Class PCI Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IOB_PCI_BUS_ENUM
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_IOB_PCI_RES_ALLOC
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_IOB_PCI_HPC_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class USB Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class IBA Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class AGP Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class PC Card Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class LPC Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class SCSI Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class ATA/ATAPI Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IOB_ATA_BUS_SMART_ENABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_IOB_ATA_BUS_SMART_DISABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_IOB_ATA_BUS_SMART_OVERTHRESHOLD
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_IOB_ATA_BUS_SMART_UNDERTHRESHOLD
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class FC Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class IP Network Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class SMBUS Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class I2C Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO Bus Class Error Code definitions.
end_comment

begin_comment
comment|/// These are shared by all subclasses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IOB_EC_NON_SPECIFIC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_IOB_EC_DISABLED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_IOB_EC_NOT_SUPPORTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_IOB_EC_NOT_DETECTED
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EFI_IOB_EC_NOT_CONFIGURED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_IOB_EC_INTERFACE_ERROR
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EFI_IOB_EC_CONTROLLER_ERROR
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EFI_IOB_EC_READ_ERROR
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EFI_IOB_EC_WRITE_ERROR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_IOB_EC_RESOURCE_CONFLICT
value|0x00000009
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class Unspecified Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO Bus Class PCI Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IOB_PCI_EC_PERR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_IOB_PCI_EC_SERR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class USB Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class IBA Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class AGP Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class PC Card Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class LPC Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class SCSI Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class ATA/ATAPI Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IOB_ATA_BUS_SMART_NOTSUPPORTED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_IOB_ATA_BUS_SMART_DISABLED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class FC Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class IP Network Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class SMBUS Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IO Bus Class I2C Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Subclass definitions.
end_comment

begin_comment
comment|/// Values of 14-127 are reserved for future use by this specification.
end_comment

begin_comment
comment|/// Values of 128-255 are reserved for OEM use.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SOFTWARE_UNSPECIFIED
value|(EFI_SOFTWARE | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_SEC
value|(EFI_SOFTWARE | 0x00010000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_PEI_CORE
value|(EFI_SOFTWARE | 0x00020000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_PEI_MODULE
value|(EFI_SOFTWARE | 0x00030000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_DXE_CORE
value|(EFI_SOFTWARE | 0x00040000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_DXE_BS_DRIVER
value|(EFI_SOFTWARE | 0x00050000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_DXE_RT_DRIVER
value|(EFI_SOFTWARE | 0x00060000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_SMM_DRIVER
value|(EFI_SOFTWARE | 0x00070000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_EFI_APPLICATION
value|(EFI_SOFTWARE | 0x00080000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_EFI_OS_LOADER
value|(EFI_SOFTWARE | 0x00090000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_RT
value|(EFI_SOFTWARE | 0x000A0000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_AL
value|(EFI_SOFTWARE | 0x000B0000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_EBC_EXCEPTION
value|(EFI_SOFTWARE | 0x000C0000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_IA32_EXCEPTION
value|(EFI_SOFTWARE | 0x000D0000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_IPF_EXCEPTION
value|(EFI_SOFTWARE | 0x000E0000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_PEI_SERVICE
value|(EFI_SOFTWARE | 0x000F0000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_EFI_BOOT_SERVICE
value|(EFI_SOFTWARE | 0x00100000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_EFI_RUNTIME_SERVICE
value|(EFI_SOFTWARE | 0x00110000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_EFI_DXE_SERVICE
value|(EFI_SOFTWARE | 0x00120000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_X64_EXCEPTION
value|(EFI_SOFTWARE | 0x00130000)
end_define

begin_define
define|#
directive|define
name|EFI_SOFTWARE_ARM_EXCEPTION
value|(EFI_SOFTWARE | 0x00140000)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class Progress Code definitions.
end_comment

begin_comment
comment|/// These are shared by all subclasses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_PC_INIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_SW_PC_LOAD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_SW_PC_INIT_BEGIN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_SW_PC_INIT_END
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EFI_SW_PC_AUTHENTICATE_BEGIN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_SW_PC_AUTHENTICATE_END
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EFI_SW_PC_INPUT_WAIT
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EFI_SW_PC_USER_SETUP
value|0x00000007
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class Unspecified Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class SEC Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_SEC_PC_ENTRY_POINT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_SEC_PC_HANDOFF_TO_NEXT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class PEI Core Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_PEI_CORE_PC_ENTRY_POINT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_CORE_PC_HANDOFF_TO_NEXT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_CORE_PC_RETURN_TO_LAST
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class PEI Module Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_PEI_PC_RECOVERY_BEGIN
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_PC_CAPSULE_LOAD
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_PC_CAPSULE_START
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_PC_RECOVERY_USER
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_PC_RECOVERY_AUTO
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_PC_S3_BOOT_SCRIPT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_PC_OS_WAKE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class DXE Core Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_DXE_CORE_PC_ENTRY_POINT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_CORE_PC_HANDOFF_TO_NEXT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_CORE_PC_RETURN_TO_LAST
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_CORE_PC_START_DRIVER
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_CORE_PC_ARCH_READY
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class DXE BS Driver Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_PC_LEGACY_OPROM_INIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_PC_READY_TO_BOOT_EVENT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_PC_LEGACY_BOOT_EVENT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_PC_EXIT_BOOT_SERVICES_EVENT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_PC_VIRTUAL_ADDRESS_CHANGE_EVENT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class SMM Driver Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class EFI Application Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class EFI OS Loader Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class EFI RT Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_RT_PC_ENTRY_POINT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RT_PC_HANDOFF_TO_NEXT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RT_PC_RETURN_TO_LAST
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class X64 Exception Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class ARM Exception Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class EBC Exception Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class IA32 Exception Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class X64 Exception Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class IPF Exception Subclass Progress Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class PEI Services Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_INSTALL_PPI
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_REINSTALL_PPI
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_LOCATE_PPI
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_NOTIFY_PPI
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_GET_BOOT_MODE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_SET_BOOT_MODE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_GET_HOB_LIST
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_CREATE_HOB
value|(EFI_SUBCLASS_SPECIFIC | 0x00000007)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_FFS_FIND_NEXT_VOLUME
value|(EFI_SUBCLASS_SPECIFIC | 0x00000008)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_FFS_FIND_NEXT_FILE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000009)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_FFS_FIND_SECTION_DATA
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000A)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_INSTALL_PEI_MEMORY
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000B)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_ALLOCATE_PAGES
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000C)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_ALLOCATE_POOL
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000D)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_COPY_MEM
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000E)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_SET_MEM
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000F)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_RESET_SYSTEM
value|(EFI_SUBCLASS_SPECIFIC | 0x00000010)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_FFS_FIND_FILE_BY_NAME
value|(EFI_SUBCLASS_SPECIFIC | 0x00000013)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_FFS_GET_FILE_INFO
value|(EFI_SUBCLASS_SPECIFIC | 0x00000014)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_FFS_GET_VOLUME_INFO
value|(EFI_SUBCLASS_SPECIFIC | 0x00000015)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_PC_FFS_REGISTER_FOR_SHADOW
value|(EFI_SUBCLASS_SPECIFIC | 0x00000016)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class EFI Boot Services Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_RAISE_TPL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_RESTORE_TPL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_ALLOCATE_PAGES
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_FREE_PAGES
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_GET_MEMORY_MAP
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_ALLOCATE_POOL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_FREE_POOL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_CREATE_EVENT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000007)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_SET_TIMER
value|(EFI_SUBCLASS_SPECIFIC | 0x00000008)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_WAIT_FOR_EVENT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000009)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_SIGNAL_EVENT
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000A)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_CLOSE_EVENT
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000B)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_CHECK_EVENT
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000C)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_INSTALL_PROTOCOL_INTERFACE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000D)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_REINSTALL_PROTOCOL_INTERFACE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000E)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_UNINSTALL_PROTOCOL_INTERFACE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000F)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_HANDLE_PROTOCOL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000010)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_PC_HANDLE_PROTOCOL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000011)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_REGISTER_PROTOCOL_NOTIFY
value|(EFI_SUBCLASS_SPECIFIC | 0x00000012)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_LOCATE_HANDLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000013)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_INSTALL_CONFIGURATION_TABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000014)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_LOAD_IMAGE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000015)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_START_IMAGE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000016)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_EXIT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000017)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_UNLOAD_IMAGE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000018)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_EXIT_BOOT_SERVICES
value|(EFI_SUBCLASS_SPECIFIC | 0x00000019)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_GET_NEXT_MONOTONIC_COUNT
value|(EFI_SUBCLASS_SPECIFIC | 0x0000001A)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_STALL
value|(EFI_SUBCLASS_SPECIFIC | 0x0000001B)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_SET_WATCHDOG_TIMER
value|(EFI_SUBCLASS_SPECIFIC | 0x0000001C)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_CONNECT_CONTROLLER
value|(EFI_SUBCLASS_SPECIFIC | 0x0000001D)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_DISCONNECT_CONTROLLER
value|(EFI_SUBCLASS_SPECIFIC | 0x0000001E)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_OPEN_PROTOCOL
value|(EFI_SUBCLASS_SPECIFIC | 0x0000001F)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_CLOSE_PROTOCOL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000020)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_OPEN_PROTOCOL_INFORMATION
value|(EFI_SUBCLASS_SPECIFIC | 0x00000021)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_PROTOCOLS_PER_HANDLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000022)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_LOCATE_HANDLE_BUFFER
value|(EFI_SUBCLASS_SPECIFIC | 0x00000023)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_LOCATE_PROTOCOL
value|(EFI_SUBCLASS_SPECIFIC | 0x00000024)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_INSTALL_MULTIPLE_INTERFACES
value|(EFI_SUBCLASS_SPECIFIC | 0x00000025)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_UNINSTALL_MULTIPLE_INTERFACES
value|(EFI_SUBCLASS_SPECIFIC | 0x00000026)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_CALCULATE_CRC_32
value|(EFI_SUBCLASS_SPECIFIC | 0x00000027)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_COPY_MEM
value|(EFI_SUBCLASS_SPECIFIC | 0x00000028)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_SET_MEM
value|(EFI_SUBCLASS_SPECIFIC | 0x00000029)
end_define

begin_define
define|#
directive|define
name|EFI_SW_BS_PC_CREATE_EVENT_EX
value|(EFI_SUBCLASS_SPECIFIC | 0x0000002A)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class EFI Runtime Services Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_GET_TIME
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_SET_TIME
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_GET_WAKEUP_TIME
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_SET_WAKEUP_TIME
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_SET_VIRTUAL_ADDRESS_MAP
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_CONVERT_POINTER
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_GET_VARIABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_GET_NEXT_VARIABLE_NAME
value|(EFI_SUBCLASS_SPECIFIC | 0x00000007)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_SET_VARIABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000008)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_GET_NEXT_HIGH_MONOTONIC_COUNT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000009)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_RESET_SYSTEM
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000A)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_UPDATE_CAPSULE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000B)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_QUERY_CAPSULE_CAPABILITIES
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000C)
end_define

begin_define
define|#
directive|define
name|EFI_SW_RS_PC_QUERY_VARIABLE_INFO
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000D)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class EFI DXE Services Subclass Progress Code definitions
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_ADD_MEMORY_SPACE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_ALLOCATE_MEMORY_SPACE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_FREE_MEMORY_SPACE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_REMOVE_MEMORY_SPACE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_GET_MEMORY_SPACE_DESCRIPTOR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_SET_MEMORY_SPACE_ATTRIBUTES
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_GET_MEMORY_SPACE_MAP
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_ADD_IO_SPACE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000007)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_ALLOCATE_IO_SPACE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000008)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_FREE_IO_SPACE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000009)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_REMOVE_IO_SPACE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000A)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_GET_IO_SPACE_DESCRIPTOR
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000B)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_GET_IO_SPACE_MAP
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000C)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_DISPATCH
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000D)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_SCHEDULE
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000E)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_TRUST
value|(EFI_SUBCLASS_SPECIFIC | 0x0000000F)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DS_PC_PROCESS_FIRMWARE_VOLUME
value|(EFI_SUBCLASS_SPECIFIC | 0x00000010)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class Error Code definitions.
end_comment

begin_comment
comment|/// These are shared by all subclasses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_EC_NON_SPECIFIC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_LOAD_ERROR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_INVALID_PARAMETER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_UNSUPPORTED
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_INVALID_BUFFER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_OUT_OF_RESOURCES
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ABORTED
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ILLEGAL_SOFTWARE_STATE
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ILLEGAL_HARDWARE_STATE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_START_ERROR
value|0x00000009
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_BAD_DATE_TIME
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_CFG_INVALID
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_CFG_CLR_REQUEST
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_CFG_DEFAULT
value|0x0000000D
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_PWD_INVALID
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_PWD_CLR_REQUEST
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_PWD_CLEARED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EVENT_LOG_FULL
value|0x00000011
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class Unspecified Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class SEC Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class PEI Core Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_PEI_CORE_EC_DXE_CORRUPT
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_CORE_EC_DXEIPL_NOT_FOUND
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_CORE_EC_MEMORY_NOT_INSTALLED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class PEI Module Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_PEI_EC_NO_RECOVERY_CAPSULE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_EC_INVALID_CAPSULE_DESCRIPTOR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_EC_S3_RESUME_PPI_NOT_FOUND
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_EC_S3_BOOT_SCRIPT_ERROR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_EC_S3_OS_WAKE_ERROR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_EC_S3_RESUME_FAILED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_EC_RECOVERY_PPI_NOT_FOUND
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PEI_EC_RECOVERY_FAILED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000007)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class DXE Foundation Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_DXE_CORE_EC_NO_ARCH
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class DXE Boot Service Driver Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_EC_LEGACY_OPROM_NO_SPACE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_EC_INVALID_PASSWORD
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_EC_BOOT_OPTION_LOAD_ERROR
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_EC_BOOT_OPTION_FAILED
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_EC_INVALID_IDE_PASSWORD
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class DXE Runtime Service Driver Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class SMM Driver Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class EFI Application Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class EFI OS Loader Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class EFI RT Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class EFI AL Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class EBC Exception Subclass Error Code definitions.
end_comment

begin_comment
comment|/// These exceptions are derived from the debug protocol definitions in the EFI
end_comment

begin_comment
comment|/// specification.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_UNDEFINED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_DIVIDE_ERROR
value|EXCEPT_EBC_DIVIDE_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_DEBUG
value|EXCEPT_EBC_DEBUG
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_BREAKPOINT
value|EXCEPT_EBC_BREAKPOINT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_OVERFLOW
value|EXCEPT_EBC_OVERFLOW
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_INVALID_OPCODE
value|EXCEPT_EBC_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_STACK_FAULT
value|EXCEPT_EBC_STACK_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_ALIGNMENT_CHECK
value|EXCEPT_EBC_ALIGNMENT_CHECK
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_INSTRUCTION_ENCODING
value|EXCEPT_EBC_INSTRUCTION_ENCODING
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_BAD_BREAK
value|EXCEPT_EBC_BAD_BREAK
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_EBC_STEP
value|EXCEPT_EBC_STEP
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class IA32 Exception Subclass Error Code definitions.
end_comment

begin_comment
comment|/// These exceptions are derived from the debug protocol definitions in the EFI
end_comment

begin_comment
comment|/// specification.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_DIVIDE_ERROR
value|EXCEPT_IA32_DIVIDE_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_DEBUG
value|EXCEPT_IA32_DEBUG
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_NMI
value|EXCEPT_IA32_NMI
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_BREAKPOINT
value|EXCEPT_IA32_BREAKPOINT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_OVERFLOW
value|EXCEPT_IA32_OVERFLOW
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_BOUND
value|EXCEPT_IA32_BOUND
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_INVALID_OPCODE
value|EXCEPT_IA32_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_DOUBLE_FAULT
value|EXCEPT_IA32_DOUBLE_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_INVALID_TSS
value|EXCEPT_IA32_INVALID_TSS
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_SEG_NOT_PRESENT
value|EXCEPT_IA32_SEG_NOT_PRESENT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_STACK_FAULT
value|EXCEPT_IA32_STACK_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_GP_FAULT
value|EXCEPT_IA32_GP_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_PAGE_FAULT
value|EXCEPT_IA32_PAGE_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_FP_ERROR
value|EXCEPT_IA32_FP_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_ALIGNMENT_CHECK
value|EXCEPT_IA32_ALIGNMENT_CHECK
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_MACHINE_CHECK
value|EXCEPT_IA32_MACHINE_CHECK
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IA32_SIMD
value|EXCEPT_IA32_SIMD
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class IPF Exception Subclass Error Code definitions.
end_comment

begin_comment
comment|/// These exceptions are derived from the debug protocol definitions in the EFI
end_comment

begin_comment
comment|/// specification.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_ALT_DTLB
value|EXCEPT_IPF_ALT_DTLB
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_DNESTED_TLB
value|EXCEPT_IPF_DNESTED_TLB
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_BREAKPOINT
value|EXCEPT_IPF_BREAKPOINT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_EXTERNAL_INTERRUPT
value|EXCEPT_IPF_EXTERNAL_INTERRUPT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_GEN_EXCEPT
value|EXCEPT_IPF_GEN_EXCEPT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_NAT_CONSUMPTION
value|EXCEPT_IPF_NAT_CONSUMPTION
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_DEBUG_EXCEPT
value|EXCEPT_IPF_DEBUG_EXCEPT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_UNALIGNED_ACCESS
value|EXCEPT_IPF_UNALIGNED_ACCESS
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_FP_FAULT
value|EXCEPT_IPF_FP_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_FP_TRAP
value|EXCEPT_IPF_FP_TRAP
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_TAKEN_BRANCH
value|EXCEPT_IPF_TAKEN_BRANCH
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_IPF_SINGLE_STEP
value|EXCEPT_IPF_SINGLE_STEP
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class PEI Service Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_PS_EC_RESET_NOT_AVAILABLE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_PS_EC_MEMORY_INSTALLED_TWICE
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class EFI Boot Service Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Software Class EFI Runtime Service Subclass Error Code definitions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class EFI DXE Service Subclass Error Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_PC_BEGIN_CONNECTING_DRIVERS
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_BS_PC_VERIFYING_PASSWORD
value|(EFI_SUBCLASS_SPECIFIC | 0x00000006)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class DXE RT Driver Subclass Progress Code definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_DXE_RT_PC_S0
value|(EFI_SUBCLASS_SPECIFIC | 0x00000000)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_RT_PC_S1
value|(EFI_SUBCLASS_SPECIFIC | 0x00000001)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_RT_PC_S2
value|(EFI_SUBCLASS_SPECIFIC | 0x00000002)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_RT_PC_S3
value|(EFI_SUBCLASS_SPECIFIC | 0x00000003)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_RT_PC_S4
value|(EFI_SUBCLASS_SPECIFIC | 0x00000004)
end_define

begin_define
define|#
directive|define
name|EFI_SW_DXE_RT_PC_S5
value|(EFI_SUBCLASS_SPECIFIC | 0x00000005)
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class X64 Exception Subclass Error Code definitions.
end_comment

begin_comment
comment|/// These exceptions are derived from the debug protocol
end_comment

begin_comment
comment|/// definitions in the EFI specification.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_DIVIDE_ERROR
value|EXCEPT_X64_DIVIDE_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_DEBUG
value|EXCEPT_X64_DEBUG
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_NMI
value|EXCEPT_X64_NMI
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_BREAKPOINT
value|EXCEPT_X64_BREAKPOINT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_OVERFLOW
value|EXCEPT_X64_OVERFLOW
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_BOUND
value|EXCEPT_X64_BOUND
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_INVALID_OPCODE
value|EXCEPT_X64_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_DOUBLE_FAULT
value|EXCEPT_X64_DOUBLE_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_INVALID_TSS
value|EXCEPT_X64_INVALID_TSS
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_SEG_NOT_PRESENT
value|EXCEPT_X64_SEG_NOT_PRESENT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_STACK_FAULT
value|EXCEPT_X64_STACK_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_GP_FAULT
value|EXCEPT_X64_GP_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_PAGE_FAULT
value|EXCEPT_X64_PAGE_FAULT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_FP_ERROR
value|EXCEPT_X64_FP_ERROR
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_ALIGNMENT_CHECK
value|EXCEPT_X64_ALIGNMENT_CHECK
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_MACHINE_CHECK
value|EXCEPT_X64_MACHINE_CHECK
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_X64_SIMD
value|EXCEPT_X64_SIMD
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Software Class ARM Exception Subclass Error Code definitions.
end_comment

begin_comment
comment|/// These exceptions are derived from the debug protocol
end_comment

begin_comment
comment|/// definitions in the EFI specification.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_SW_EC_ARM_RESET
value|EXCEPT_ARM_RESET
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ARM_UNDEFINED_INSTRUCTION
value|EXCEPT_ARM_UNDEFINED_INSTRUCTION
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ARM_SOFTWARE_INTERRUPT
value|EXCEPT_ARM_SOFTWARE_INTERRUPT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ARM_PREFETCH_ABORT
value|EXCEPT_ARM_PREFETCH_ABORT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ARM_DATA_ABORT
value|EXCEPT_ARM_DATA_ABORT
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ARM_RESERVED
value|EXCEPT_ARM_RESERVED
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ARM_IRQ
value|EXCEPT_ARM_IRQ
end_define

begin_define
define|#
directive|define
name|EFI_SW_EC_ARM_FIQ
value|EXCEPT_ARM_FIQ
end_define

begin_comment
comment|///@}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

