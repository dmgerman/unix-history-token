begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      ACPI 2.0 definitions from the ACPI Specification, revision 2.0    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACPI_2_0_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACPI_2_0_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Acpi10.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Define for Desriptor
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ACPI_LARGE_GENERIC_REGISTER_DESCRIPTOR_NAME
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_GENERIC_REGISTER_DESCRIPTOR
value|0x82
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure proper structure formats
end_comment

begin_comment
comment|//
end_comment

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
comment|/// Generic Register Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PACKED
struct|struct
block|{
name|ACPI_LARGE_RESOURCE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|AddressSpaceId
decl_stmt|;
name|UINT8
name|RegisterBitWidth
decl_stmt|;
name|UINT8
name|RegisterBitOffset
decl_stmt|;
name|UINT8
name|AddressSize
decl_stmt|;
name|UINT64
name|RegisterAddress
decl_stmt|;
block|}
name|EFI_ACPI_GENERIC_REGISTER_DESCRIPTOR
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
comment|// Ensure proper structure formats
end_comment

begin_comment
comment|//
end_comment

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
comment|/// ACPI 2.0 Generic Address Space definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|AddressSpaceId
decl_stmt|;
name|UINT8
name|RegisterBitWidth
decl_stmt|;
name|UINT8
name|RegisterBitOffset
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
block|}
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Generic Address Space Address IDs
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SYSTEM_MEMORY
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SYSTEM_IO
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PCI_CONFIGURATION_SPACE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_EMBEDDED_CONTROLLER
value|3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SMBUS
value|4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_FUNCTIONAL_FIXED_HARDWARE
value|0x7F
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ACPI 2.0 table structures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Root System Description Pointer Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Signature
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|UINT8
name|OemId
index|[
literal|6
index|]
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
name|UINT32
name|RsdtAddress
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT64
name|XsdtAddress
decl_stmt|;
name|UINT8
name|ExtendedChecksum
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// RSD_PTR Revision (as defined in ACPI 2.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER_REVISION
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common table header, this prefaces all ACPI tables, including FACS, but
end_comment

begin_comment
comment|/// excluding the RSD PTR structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|EFI_ACPI_2_0_COMMON_HEADER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Root System Description Table
end_comment

begin_comment
comment|// No definition needed as it is a common description table header, the same with
end_comment

begin_comment
comment|// EFI_ACPI_DESCRIPTION_HEADER, followed by a variable number of UINT32 table pointers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// RSDT Revision (as defined in ACPI 2.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Extended System Description Table
end_comment

begin_comment
comment|// No definition needed as it is a common description table header, the same with
end_comment

begin_comment
comment|// EFI_ACPI_DESCRIPTION_HEADER, followed by a variable number of UINT64 table pointers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// XSDT Revision (as defined in ACPI 2.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_EXTENDED_SYSTEM_DESCRIPTION_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Fixed ACPI Description Table Structure (FADT)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT32
name|FirmwareCtrl
decl_stmt|;
name|UINT32
name|Dsdt
decl_stmt|;
name|UINT8
name|Reserved0
decl_stmt|;
name|UINT8
name|PreferredPmProfile
decl_stmt|;
name|UINT16
name|SciInt
decl_stmt|;
name|UINT32
name|SmiCmd
decl_stmt|;
name|UINT8
name|AcpiEnable
decl_stmt|;
name|UINT8
name|AcpiDisable
decl_stmt|;
name|UINT8
name|S4BiosReq
decl_stmt|;
name|UINT8
name|PstateCnt
decl_stmt|;
name|UINT32
name|Pm1aEvtBlk
decl_stmt|;
name|UINT32
name|Pm1bEvtBlk
decl_stmt|;
name|UINT32
name|Pm1aCntBlk
decl_stmt|;
name|UINT32
name|Pm1bCntBlk
decl_stmt|;
name|UINT32
name|Pm2CntBlk
decl_stmt|;
name|UINT32
name|PmTmrBlk
decl_stmt|;
name|UINT32
name|Gpe0Blk
decl_stmt|;
name|UINT32
name|Gpe1Blk
decl_stmt|;
name|UINT8
name|Pm1EvtLen
decl_stmt|;
name|UINT8
name|Pm1CntLen
decl_stmt|;
name|UINT8
name|Pm2CntLen
decl_stmt|;
name|UINT8
name|PmTmrLen
decl_stmt|;
name|UINT8
name|Gpe0BlkLen
decl_stmt|;
name|UINT8
name|Gpe1BlkLen
decl_stmt|;
name|UINT8
name|Gpe1Base
decl_stmt|;
name|UINT8
name|CstCnt
decl_stmt|;
name|UINT16
name|PLvl2Lat
decl_stmt|;
name|UINT16
name|PLvl3Lat
decl_stmt|;
name|UINT16
name|FlushSize
decl_stmt|;
name|UINT16
name|FlushStride
decl_stmt|;
name|UINT8
name|DutyOffset
decl_stmt|;
name|UINT8
name|DutyWidth
decl_stmt|;
name|UINT8
name|DayAlrm
decl_stmt|;
name|UINT8
name|MonAlrm
decl_stmt|;
name|UINT8
name|Century
decl_stmt|;
name|UINT16
name|IaPcBootArch
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|ResetReg
decl_stmt|;
name|UINT8
name|ResetValue
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
name|UINT64
name|XFirmwareCtrl
decl_stmt|;
name|UINT64
name|XDsdt
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|XPm1aEvtBlk
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|XPm1bEvtBlk
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|XPm1aCntBlk
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|XPm1bCntBlk
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|XPm2CntBlk
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|XPmTmrBlk
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|XGpe0Blk
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|XGpe1Blk
decl_stmt|;
block|}
name|EFI_ACPI_2_0_FIXED_ACPI_DESCRIPTION_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FADT Version (as defined in ACPI 2.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_FIXED_ACPI_DESCRIPTION_TABLE_REVISION
value|0x03
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Fixed ACPI Description Table Preferred Power Management Profile
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PM_PROFILE_UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PM_PROFILE_DESKTOP
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PM_PROFILE_MOBILE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PM_PROFILE_WORKSTATION
value|3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PM_PROFILE_ENTERPRISE_SERVER
value|4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PM_PROFILE_SOHO_SERVER
value|5
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PM_PROFILE_APPLIANCE_PC
value|6
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Fixed ACPI Description Table Boot Architecture Flags
end_comment

begin_comment
comment|// All other bits are reserved and must be set to 0.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_LEGACY_DEVICES
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_8042
value|BIT1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Fixed ACPI Description Table Fixed Feature Flags
end_comment

begin_comment
comment|// All other bits are reserved and must be set to 0.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_WBINVD
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_WBINVD_FLUSH
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PROC_C1
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_P_LVL2_UP
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PWR_BUTTON
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SLP_BUTTON
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_FIX_RTC
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_RTC_S4
value|BIT7
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_TMR_VAL_EXT
value|BIT8
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_DCK_CAP
value|BIT9
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_RESET_REG_SUP
value|BIT10
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SEALED_CASE
value|BIT11
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_HEADLESS
value|BIT12
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_CPU_SW_SLP
value|BIT13
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Firmware ACPI Control Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|HardwareSignature
decl_stmt|;
name|UINT32
name|FirmwareWakingVector
decl_stmt|;
name|UINT32
name|GlobalLock
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT64
name|XFirmwareWakingVector
decl_stmt|;
name|UINT8
name|Version
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|31
index|]
decl_stmt|;
block|}
name|EFI_ACPI_2_0_FIRMWARE_ACPI_CONTROL_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FACS Version (as defined in ACPI 2.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_FIRMWARE_ACPI_CONTROL_STRUCTURE_VERSION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Firmware Control Structure Feature Flags
end_comment

begin_comment
comment|/// All other bits are reserved and must be set to 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_S4BIOS_F
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Multiple APIC Description Table header definition.  The rest of the table
end_comment

begin_comment
comment|/// must be defined in a platform specific manner.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT32
name|LocalApicAddress
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_2_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MADT Revision (as defined in ACPI 2.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_MULTIPLE_APIC_DESCRIPTION_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Multiple APIC Flags
end_comment

begin_comment
comment|/// All other bits are reserved and must be set to 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PCAT_COMPAT
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Multiple APIC Description Table APIC structure types
end_comment

begin_comment
comment|// All other values between 0x09 an 0xFF are reserved and
end_comment

begin_comment
comment|// will be ignored by OSPM.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_IO_APIC
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_NON_MASKABLE_INTERRUPT_SOURCE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_LOCAL_APIC_NMI
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_LOCAL_APIC_ADDRESS_OVERRIDE
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_IO_SAPIC
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PROCESSOR_LOCAL_SAPIC
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PLATFORM_INTERRUPT_SOURCES
value|0x08
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// APIC Structure Definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Local APIC Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|AcpiProcessorId
decl_stmt|;
name|UINT8
name|ApicId
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Local APIC Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_LOCAL_APIC_ENABLED
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO APIC Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|IoApicId
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT32
name|IoApicAddress
decl_stmt|;
name|UINT32
name|GlobalSystemInterruptBase
decl_stmt|;
block|}
name|EFI_ACPI_2_0_IO_APIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Interrupt Source Override Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|Bus
decl_stmt|;
name|UINT8
name|Source
decl_stmt|;
name|UINT32
name|GlobalSystemInterrupt
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Non-Maskable Interrupt Source Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT32
name|GlobalSystemInterrupt
decl_stmt|;
block|}
name|EFI_ACPI_2_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Local APIC NMI Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|AcpiProcessorId
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT8
name|LocalApicLint
decl_stmt|;
block|}
name|EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Local APIC Address Override Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT64
name|LocalApicAddress
decl_stmt|;
block|}
name|EFI_ACPI_2_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IO SAPIC Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|IoApicId
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT32
name|GlobalSystemInterruptBase
decl_stmt|;
name|UINT64
name|IoSapicAddress
decl_stmt|;
block|}
name|EFI_ACPI_2_0_IO_SAPIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Local SAPIC Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|AcpiProcessorId
decl_stmt|;
name|UINT8
name|LocalSapicId
decl_stmt|;
name|UINT8
name|LocalSapicEid
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_2_0_PROCESSOR_LOCAL_SAPIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Platform Interrupt Sources Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT8
name|InterruptType
decl_stmt|;
name|UINT8
name|ProcessorId
decl_stmt|;
name|UINT8
name|ProcessorEid
decl_stmt|;
name|UINT8
name|IoSapicVector
decl_stmt|;
name|UINT32
name|GlobalSystemInterrupt
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|EFI_ACPI_2_0_PLATFORM_INTERRUPT_SOURCES_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Smart Battery Description Table (SBST)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT32
name|WarningEnergyLevel
decl_stmt|;
name|UINT32
name|LowEnergyLevel
decl_stmt|;
name|UINT32
name|CriticalEnergyLevel
decl_stmt|;
block|}
name|EFI_ACPI_2_0_SMART_BATTERY_DESCRIPTION_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SBST Version (as defined in ACPI 2.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SMART_BATTERY_DESCRIPTION_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Embedded Controller Boot Resources Table (ECDT)
end_comment

begin_comment
comment|/// The table is followed by a null terminated ASCII string that contains
end_comment

begin_comment
comment|/// a fully qualified reference to the name space object.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|EcControl
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|EcData
decl_stmt|;
name|UINT32
name|Uid
decl_stmt|;
name|UINT8
name|GpeBit
decl_stmt|;
block|}
name|EFI_ACPI_2_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ECDT Version (as defined in ACPI 2.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Known table signatures
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// "RSD PTR " Root System Description Pointer
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER_SIGNATURE
value|SIGNATURE_64('R', 'S', 'D', ' ', 'P', 'T', 'R', ' ')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SPIC" Multiple SAPIC Description Table
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// BUGBUG: Don't know where this came from except SR870BN4 uses it.
end_comment

begin_comment
comment|/// #define EFI_ACPI_2_0_MULTIPLE_SAPIC_DESCRIPTION_TABLE_SIGNATURE 0x43495053
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_MULTIPLE_SAPIC_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('A', 'P', 'I', 'C')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "BOOT" MS Simple Boot Spec
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SIMPLE_BOOT_FLAG_TABLE_SIGNATURE
value|SIGNATURE_32('B', 'O', 'O', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "DBGP" MS Bebug Port Spec
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_DEBUG_PORT_TABLE_SIGNATURE
value|SIGNATURE_32('D', 'B', 'G', 'P')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "DSDT" Differentiated System Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_DIFFERENTIATED_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('D', 'S', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "ECDT" Embedded Controller Boot Resources Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE_SIGNATURE
value|SIGNATURE_32('E', 'C', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "ETDT" Event Timer Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_EVENT_TIMER_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('E', 'T', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "FACS" Firmware ACPI Control Structure
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_FIRMWARE_ACPI_CONTROL_STRUCTURE_SIGNATURE
value|SIGNATURE_32('F', 'A', 'C', 'S')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "FACP" Fixed ACPI Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_FIXED_ACPI_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('F', 'A', 'C', 'P')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "APIC" Multiple APIC Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_MULTIPLE_APIC_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('A', 'P', 'I', 'C')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "PSDT" Persistent System Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_PERSISTENT_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('P', 'S', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "RSDT" Root System Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('R', 'S', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SBST" Smart Battery Specification Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SMART_BATTERY_SPECIFICATION_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'B', 'S', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SLIT" System Locality Information Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SYSTEM_LOCALITY_INFORMATION_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'L', 'I', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SPCR" Serial Port Concole Redirection Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'P', 'C', 'R')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SRAT" Static Resource Affinity Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_STATIC_RESOURCE_AFFINITY_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'R', 'A', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SSDT" Secondary System Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SECONDARY_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'S', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SPMI" Server Platform Management Interface Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_SERVER_PLATFORM_MANAGEMENT_INTERFACE_SIGNATURE
value|SIGNATURE_32('S', 'P', 'M', 'I')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "XSDT" Extended System Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_EXTENDED_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('X', 'S', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "MCFG" PCI Express Memory Mapped Configuration Space Base Address Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_MEMORY_MAPPED_CONFIGURATION_BASE_ADDRESS_TABLE_SIGNATURE
value|SIGNATURE_32('M', 'C', 'F', 'G')
end_define

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

