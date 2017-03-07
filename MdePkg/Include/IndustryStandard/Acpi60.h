begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      ACPI 6.0 definitions from the ACPI Specification Revision 6.0 Errata A January, 2016.    Copyright (c) 2015 - 2017, Intel Corporation. All rights reserved.<BR>   (C) Copyright 2015-2016 Hewlett Packard Enterprise Development LP<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACPI_6_0_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACPI_6_0_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Acpi51.h>
end_include

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
comment|/// ACPI 6.0 Generic Address Space definition
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
name|AccessSize
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
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
name|EFI_ACPI_6_0_SYSTEM_MEMORY
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SYSTEM_IO
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PCI_CONFIGURATION_SPACE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EMBEDDED_CONTROLLER
value|3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SMBUS
value|4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PLATFORM_COMMUNICATION_CHANNEL
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FUNCTIONAL_FIXED_HARDWARE
value|0x7F
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Generic Address Space Access Sizes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_UNDEFINED
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_BYTE
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_WORD
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_DWORD
value|3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_QWORD
value|4
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ACPI 6.0 table structures
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
name|EFI_ACPI_6_0_ROOT_SYSTEM_DESCRIPTION_POINTER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// RSD_PTR Revision (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ROOT_SYSTEM_DESCRIPTION_POINTER_REVISION
value|0x02
end_define

begin_comment
comment|///< ACPISpec (Revision 6.0) says current value is 2
end_comment

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
name|EFI_ACPI_6_0_COMMON_HEADER
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
comment|/// RSDT Revision (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ROOT_SYSTEM_DESCRIPTION_TABLE_REVISION
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
comment|/// XSDT Revision (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EXTENDED_SYSTEM_DESCRIPTION_TABLE_REVISION
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
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|ResetReg
decl_stmt|;
name|UINT8
name|ResetValue
decl_stmt|;
name|UINT16
name|ArmBootArch
decl_stmt|;
name|UINT8
name|MinorVersion
decl_stmt|;
name|UINT64
name|XFirmwareCtrl
decl_stmt|;
name|UINT64
name|XDsdt
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|XPm1aEvtBlk
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|XPm1bEvtBlk
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|XPm1aCntBlk
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|XPm1bCntBlk
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|XPm2CntBlk
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|XPmTmrBlk
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|XGpe0Blk
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|XGpe1Blk
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|SleepControlReg
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|SleepStatusReg
decl_stmt|;
name|UINT64
name|HypervisorVendorIdentity
decl_stmt|;
block|}
name|EFI_ACPI_6_0_FIXED_ACPI_DESCRIPTION_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FADT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FIXED_ACPI_DESCRIPTION_TABLE_REVISION
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FIXED_ACPI_DESCRIPTION_TABLE_MINOR_REVISION
value|0x00
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
name|EFI_ACPI_6_0_PM_PROFILE_UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PM_PROFILE_DESKTOP
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PM_PROFILE_MOBILE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PM_PROFILE_WORKSTATION
value|3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PM_PROFILE_ENTERPRISE_SERVER
value|4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PM_PROFILE_SOHO_SERVER
value|5
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PM_PROFILE_APPLIANCE_PC
value|6
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PM_PROFILE_PERFORMANCE_SERVER
value|7
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PM_PROFILE_TABLET
value|8
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
name|EFI_ACPI_6_0_LEGACY_DEVICES
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_8042
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_VGA_NOT_PRESENT
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MSI_NOT_SUPPORTED
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PCIE_ASPM_CONTROLS
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_CMOS_RTC_NOT_PRESENT
value|BIT5
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Fixed ACPI Description Table Arm Boot Architecture Flags
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
name|EFI_ACPI_6_0_ARM_PSCI_COMPLIANT
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ARM_PSCI_USE_HVC
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
name|EFI_ACPI_6_0_WBINVD
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_WBINVD_FLUSH
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PROC_C1
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_P_LVL2_UP
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PWR_BUTTON
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SLP_BUTTON
value|BIT5
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FIX_RTC
value|BIT6
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_RTC_S4
value|BIT7
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_TMR_VAL_EXT
value|BIT8
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_DCK_CAP
value|BIT9
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_RESET_REG_SUP
value|BIT10
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SEALED_CASE
value|BIT11
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HEADLESS
value|BIT12
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_CPU_SW_SLP
value|BIT13
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PCI_EXP_WAK
value|BIT14
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_USE_PLATFORM_CLOCK
value|BIT15
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_S4_RTC_STS_VALID
value|BIT16
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_REMOTE_POWER_ON_CAPABLE
value|BIT17
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FORCE_APIC_CLUSTER_MODEL
value|BIT18
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FORCE_APIC_PHYSICAL_DESTINATION_MODE
value|BIT19
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HW_REDUCED_ACPI
value|BIT20
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_LOW_POWER_S0_IDLE_CAPABLE
value|BIT21
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
name|Reserved0
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|OspmFlags
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|24
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_FIRMWARE_ACPI_CONTROL_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FACS Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FIRMWARE_ACPI_CONTROL_STRUCTURE_VERSION
value|0x02
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
name|EFI_ACPI_6_0_S4BIOS_F
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_64BIT_WAKE_SUPPORTED_F
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// OSPM Enabled Firmware Control Structure Flags
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
name|EFI_ACPI_6_0_OSPM_64BIT_WAKE_F
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Differentiated System Description Table,
end_comment

begin_comment
comment|// Secondary System Description Table
end_comment

begin_comment
comment|// and Persistent System Description Table,
end_comment

begin_comment
comment|// no definition needed as they are common description table header, the same with
end_comment

begin_comment
comment|// EFI_ACPI_DESCRIPTION_HEADER, followed by a definition block.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_DIFFERENTIATED_SYSTEM_DESCRIPTION_TABLE_REVISION
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SECONDARY_SYSTEM_DESCRIPTION_TABLE_REVISION
value|0x02
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
name|EFI_ACPI_6_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MADT Revision (as defined in ACPI 6.0 Errata A spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MULTIPLE_APIC_DESCRIPTION_TABLE_REVISION
value|0x04
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
name|EFI_ACPI_6_0_PCAT_COMPAT
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Multiple APIC Description Table APIC structure types
end_comment

begin_comment
comment|// All other values between 0x0D and 0x7F are reserved and
end_comment

begin_comment
comment|// will be ignored by OSPM. 0x80 ~ 0xFF are reserved for OEM.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_APIC
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IO_APIC
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_INTERRUPT_SOURCE_OVERRIDE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NON_MASKABLE_INTERRUPT_SOURCE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_LOCAL_APIC_NMI
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_LOCAL_APIC_ADDRESS_OVERRIDE
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IO_SAPIC
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_LOCAL_SAPIC
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PLATFORM_INTERRUPT_SOURCES
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_X2APIC
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_LOCAL_X2APIC_NMI
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GIC
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GICD
value|0x0C
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GIC_MSI_FRAME
value|0x0D
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GICR
value|0x0E
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GIC_ITS
value|0x0F
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
name|AcpiProcessorUid
decl_stmt|;
name|UINT8
name|ApicId
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_APIC_STRUCTURE
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
name|EFI_ACPI_6_0_LOCAL_APIC_ENABLED
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
name|EFI_ACPI_6_0_IO_APIC_STRUCTURE
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
name|EFI_ACPI_6_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Platform Interrupt Sources Structure Definition
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
name|PlatformInterruptSourceFlags
decl_stmt|;
name|UINT8
name|CpeiProcessorOverride
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|31
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PLATFORM_INTERRUPT_APIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// MPS INTI flags.
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
name|EFI_ACPI_6_0_POLARITY
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_TRIGGER_MODE
value|(3<< 2)
end_define

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
name|EFI_ACPI_6_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE
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
name|AcpiProcessorUid
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT8
name|LocalApicLint
decl_stmt|;
block|}
name|EFI_ACPI_6_0_LOCAL_APIC_NMI_STRUCTURE
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
name|EFI_ACPI_6_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE
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
name|EFI_ACPI_6_0_IO_SAPIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Local SAPIC Structure
end_comment

begin_comment
comment|/// This struct followed by a null-terminated ASCII string - ACPI Processor UID String
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
name|UINT32
name|ACPIProcessorUIDValue
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_SAPIC_STRUCTURE
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
name|PlatformInterruptSourceFlags
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PLATFORM_INTERRUPT_SOURCES_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Platform Interrupt Source Flags.
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
name|EFI_ACPI_6_0_CPEI_PROCESSOR_OVERRIDE
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Local x2APIC Structure Definition
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
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
name|UINT32
name|X2ApicId
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|AcpiProcessorUid
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_X2APIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Local x2APIC NMI Structure
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
name|AcpiProcessorUid
decl_stmt|;
name|UINT8
name|LocalX2ApicLint
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_LOCAL_X2APIC_NMI_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GIC Structure
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
name|UINT32
name|CPUInterfaceNumber
decl_stmt|;
name|UINT32
name|AcpiProcessorUid
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|ParkingProtocolVersion
decl_stmt|;
name|UINT32
name|PerformanceInterruptGsiv
decl_stmt|;
name|UINT64
name|ParkedAddress
decl_stmt|;
name|UINT64
name|PhysicalBaseAddress
decl_stmt|;
name|UINT64
name|GICV
decl_stmt|;
name|UINT64
name|GICH
decl_stmt|;
name|UINT32
name|VGICMaintenanceInterrupt
decl_stmt|;
name|UINT64
name|GICRBaseAddress
decl_stmt|;
name|UINT64
name|MPIDR
decl_stmt|;
name|UINT8
name|ProcessorPowerEfficiencyClass
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GIC Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GIC_ENABLED
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PERFORMANCE_INTERRUPT_MODEL
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_VGIC_MAINTENANCE_INTERRUPT_MODE_FLAGS
value|BIT2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// GIC Distributor Structure
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
name|Reserved1
decl_stmt|;
name|UINT32
name|GicId
decl_stmt|;
name|UINT64
name|PhysicalBaseAddress
decl_stmt|;
name|UINT32
name|SystemVectorBase
decl_stmt|;
name|UINT8
name|GicVersion
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GIC_DISTRIBUTOR_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GIC Version
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GIC_V1
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GIC_V2
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GIC_V3
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GIC_V4
value|0x04
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// GIC MSI Frame Structure
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
name|Reserved1
decl_stmt|;
name|UINT32
name|GicMsiFrameId
decl_stmt|;
name|UINT64
name|PhysicalBaseAddress
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT16
name|SPICount
decl_stmt|;
name|UINT16
name|SPIBase
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GIC_MSI_FRAME_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GIC MSI Frame Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SPI_COUNT_BASE_SELECT
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// GICR Structure
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
name|DiscoveryRangeBaseAddress
decl_stmt|;
name|UINT32
name|DiscoveryRangeLength
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GICR_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GIC Interrupt Translation Service Structure
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
name|UINT32
name|GicItsId
decl_stmt|;
name|UINT64
name|PhysicalBaseAddress
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GIC_ITS_STRUCTURE
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
name|EFI_ACPI_6_0_SMART_BATTERY_DESCRIPTION_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SBST Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SMART_BATTERY_DESCRIPTION_TABLE_REVISION
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
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|EcControl
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|EcData
decl_stmt|;
name|UINT32
name|Uid
decl_stmt|;
name|UINT8
name|GpeBit
decl_stmt|;
block|}
name|EFI_ACPI_6_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ECDT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Resource Affinity Table (SRAT).  The rest of the table
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
name|Reserved1
decl_stmt|;
comment|///< Must be set to 1
name|UINT64
name|Reserved2
decl_stmt|;
block|}
name|EFI_ACPI_6_0_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SRAT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SYSTEM_RESOURCE_AFFINITY_TABLE_REVISION
value|0x03
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SRAT structure types.
end_comment

begin_comment
comment|// All other values between 0x04 an 0xFF are reserved and
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
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MEMORY_AFFINITY
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_X2APIC_AFFINITY
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GICC_AFFINITY
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Local APIC/SAPIC Affinity Structure Definition
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
name|ProximityDomain7To0
decl_stmt|;
name|UINT8
name|ApicId
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT8
name|LocalSapicEid
decl_stmt|;
name|UINT8
name|ProximityDomain31To8
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|ClockDomain
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Local APIC/SAPIC Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_APIC_SAPIC_ENABLED
value|(1<< 0)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Affinity Structure Definition
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
name|UINT32
name|ProximityDomain
decl_stmt|;
name|UINT16
name|Reserved1
decl_stmt|;
name|UINT32
name|AddressBaseLow
decl_stmt|;
name|UINT32
name|AddressBaseHigh
decl_stmt|;
name|UINT32
name|LengthLow
decl_stmt|;
name|UINT32
name|LengthHigh
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT64
name|Reserved3
decl_stmt|;
block|}
name|EFI_ACPI_6_0_MEMORY_AFFINITY_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Memory Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MEMORY_ENABLED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MEMORY_HOT_PLUGGABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MEMORY_NONVOLATILE
value|(1<< 2)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Local x2APIC Affinity Structure Definition
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
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
name|UINT32
name|ProximityDomain
decl_stmt|;
name|UINT32
name|X2ApicId
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|ClockDomain
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|4
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GICC Affinity Structure Definition
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
name|UINT32
name|ProximityDomain
decl_stmt|;
name|UINT32
name|AcpiProcessorUid
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|ClockDomain
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GICC_AFFINITY_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GICC Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GICC_ENABLED
value|(1<< 0)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Locality Distance Information Table (SLIT).
end_comment

begin_comment
comment|/// The rest of the table is a matrix.
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
name|UINT64
name|NumberOfSystemLocalities
decl_stmt|;
block|}
name|EFI_ACPI_6_0_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SLIT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Corrected Platform Error Polling Table (CPEP)
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
name|UINT8
name|Reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// CPEP Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// CPEP processor structure types.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_CPEP_PROCESSOR_APIC_SAPIC
value|0x00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Corrected Platform Error Polling Processor Structure Definition
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
name|ProcessorId
decl_stmt|;
name|UINT8
name|ProcessorEid
decl_stmt|;
name|UINT32
name|PollingInterval
decl_stmt|;
block|}
name|EFI_ACPI_6_0_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Maximum System Characteristics Table (MSCT)
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
name|OffsetProxDomInfo
decl_stmt|;
name|UINT32
name|MaximumNumberOfProximityDomains
decl_stmt|;
name|UINT32
name|MaximumNumberOfClockDomains
decl_stmt|;
name|UINT64
name|MaximumPhysicalAddress
decl_stmt|;
block|}
name|EFI_ACPI_6_0_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MSCT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Maximum Proximity Domain Information Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT32
name|ProximityDomainRangeLow
decl_stmt|;
name|UINT32
name|ProximityDomainRangeHigh
decl_stmt|;
name|UINT32
name|MaximumProcessorCapacity
decl_stmt|;
name|UINT64
name|MaximumMemoryCapacity
decl_stmt|;
block|}
name|EFI_ACPI_6_0_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI RAS Feature Table definition.
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
name|UINT8
name|PlatformCommunicationChannelIdentifier
index|[
literal|12
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_RAS_FEATURE_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// RASF Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_RAS_FEATURE_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI RASF Platform Communication Channel Shared Memory Region definition.
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
name|UINT16
name|Command
decl_stmt|;
name|UINT16
name|Status
decl_stmt|;
name|UINT16
name|Version
decl_stmt|;
name|UINT8
name|RASCapabilities
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|SetRASCapabilities
index|[
literal|16
index|]
decl_stmt|;
name|UINT16
name|NumberOfRASFParameterBlocks
decl_stmt|;
name|UINT32
name|SetRASCapabilitiesStatus
decl_stmt|;
block|}
name|EFI_ACPI_6_0_RASF_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI RASF PCC command code
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_RASF_PCC_COMMAND_CODE_EXECUTE_RASF_COMMAND
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI RASF Platform RAS Capabilities
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_RASF_PLATFORM_RAS_CAPABILITY_HARDWARE_BASED_PATROL_SCRUB_SUPPOTED
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_RASF_PLATFORM_RAS_CAPABILITY_HARDWARE_BASED_PATROL_SCRUB_SUPPOTED_AND_EXPOSED_TO_SOFTWARE
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI RASF Parameter Block structure for PATROL_SCRUB
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Version
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT16
name|PatrolScrubCommand
decl_stmt|;
name|UINT64
name|RequestedAddressRange
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|ActualAddressRange
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT8
name|RequestedSpeed
decl_stmt|;
block|}
name|EFI_ACPI_6_0_RASF_PATROL_SCRUB_PLATFORM_BLOCK_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI RASF Patrol Scrub command
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_RASF_PATROL_SCRUB_COMMAND_GET_PATROL_PARAMETERS
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_RASF_PATROL_SCRUB_COMMAND_START_PATROL_SCRUBBER
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_RASF_PATROL_SCRUB_COMMAND_STOP_PATROL_SCRUBBER
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Power State Table definition.
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
name|UINT8
name|PlatformCommunicationChannelIdentifier
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
comment|// Memory Power Node Structure
comment|// Memory Power State Characteristics
block|}
name|EFI_ACPI_6_0_MEMORY_POWER_STATUS_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MPST Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MEMORY_POWER_STATE_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// MPST Platform Communication Channel Shared Memory Region definition.
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
name|UINT16
name|Command
decl_stmt|;
name|UINT16
name|Status
decl_stmt|;
name|UINT32
name|MemoryPowerCommandRegister
decl_stmt|;
name|UINT32
name|MemoryPowerStatusRegister
decl_stmt|;
name|UINT32
name|PowerStateId
decl_stmt|;
name|UINT32
name|MemoryPowerNodeId
decl_stmt|;
name|UINT64
name|MemoryEnergyConsumed
decl_stmt|;
name|UINT64
name|ExpectedAveragePowerComsuned
decl_stmt|;
block|}
name|EFI_ACPI_6_0_MPST_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI MPST PCC command code
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_PCC_COMMAND_CODE_EXECUTE_MPST_COMMAND
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI MPST Memory Power command
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_COMMAND_GET_MEMORY_POWER_STATE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_COMMAND_SET_MEMORY_POWER_STATE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_COMMAND_GET_AVERAGE_POWER_CONSUMED
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_COMMAND_GET_MEMORY_ENERGY_CONSUMED
value|0x04
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// MPST Memory Power Node Table
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|PowerStateValue
decl_stmt|;
name|UINT8
name|PowerStateInformationIndex
decl_stmt|;
block|}
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Flag
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT16
name|MemoryPowerNodeId
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT64
name|AddressBase
decl_stmt|;
name|UINT64
name|AddressLength
decl_stmt|;
name|UINT32
name|NumberOfPowerStates
decl_stmt|;
name|UINT32
name|NumberOfPhysicalComponents
decl_stmt|;
comment|//EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE              MemoryPowerState[NumberOfPowerStates];
comment|//UINT16                                            PhysicalComponentIdentifier[NumberOfPhysicalComponents];
block|}
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STRUCTURE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STRUCTURE_FLAG_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STRUCTURE_FLAG_POWER_MANAGED
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STRUCTURE_FLAG_HOT_PLUGGABLE
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|MemoryPowerNodeCount
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_NODE_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MPST Memory Power State Characteristics Table
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|PowerStateStructureID
decl_stmt|;
name|UINT8
name|Flag
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|AveragePowerConsumedInMPS0
decl_stmt|;
name|UINT32
name|RelativePowerSavingToMPS0
decl_stmt|;
name|UINT64
name|ExitLatencyToMPS0
decl_stmt|;
block|}
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE_FLAG_MEMORY_CONTENT_PRESERVED
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE_FLAG_AUTONOMOUS_MEMORY_POWER_STATE_ENTRY
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE_FLAG_AUTONOMOUS_MEMORY_POWER_STATE_EXIT
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|MemoryPowerStateCharacteristicsCount
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Topology Table definition.
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
name|Reserved
decl_stmt|;
block|}
name|EFI_ACPI_6_0_MEMORY_TOPOLOGY_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PMTT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MEMORY_TOPOLOGY_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common Memory Aggregator Device Structure.
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
name|Reserved
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT16
name|Reserved1
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Aggregator Device Type
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PMMT_MEMORY_AGGREGATOR_DEVICE_TYPE_SOCKET
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PMMT_MEMORY_AGGREGATOR_DEVICE_TYPE_MEMORY_CONTROLLER
value|0x2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PMMT_MEMORY_AGGREGATOR_DEVICE_TYPE_DIMM
value|0x3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Socket Memory Aggregator Device Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE
name|Header
decl_stmt|;
name|UINT16
name|SocketIdentifier
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|//EFI_ACPI_6_0_PMMT_MEMORY_CONTROLLER_MEMORY_AGGREGATOR_DEVICE_STRUCTURE  MemoryController[];
block|}
name|EFI_ACPI_6_0_PMMT_SOCKET_MEMORY_AGGREGATOR_DEVICE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MemoryController Memory Aggregator Device Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE
name|Header
decl_stmt|;
name|UINT32
name|ReadLatency
decl_stmt|;
name|UINT32
name|WriteLatency
decl_stmt|;
name|UINT32
name|ReadBandwidth
decl_stmt|;
name|UINT32
name|WriteBandwidth
decl_stmt|;
name|UINT16
name|OptimalAccessUnit
decl_stmt|;
name|UINT16
name|OptimalAccessAlignment
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT16
name|NumberOfProximityDomains
decl_stmt|;
comment|//UINT32                                                       ProximityDomain[NumberOfProximityDomains];
comment|//EFI_ACPI_6_0_PMMT_DIMM_MEMORY_AGGREGATOR_DEVICE_STRUCTURE    PhysicalComponent[];
block|}
name|EFI_ACPI_6_0_PMMT_MEMORY_CONTROLLER_MEMORY_AGGREGATOR_DEVICE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DIMM Memory Aggregator Device Structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE
name|Header
decl_stmt|;
name|UINT16
name|PhysicalComponentIdentifier
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|SizeOfDimm
decl_stmt|;
name|UINT32
name|SmbiosHandle
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PMMT_DIMM_MEMORY_AGGREGATOR_DEVICE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Boot Graphics Resource Table definition.
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
comment|///
comment|/// 2-bytes (16 bit) version ID. This value must be 1.
comment|///
name|UINT16
name|Version
decl_stmt|;
comment|///
comment|/// 1-byte status field indicating current status about the table.
comment|///     Bits[7:1] = Reserved (must be zero)
comment|///     Bit [0] = Valid. A one indicates the boot image graphic is valid.
comment|///
name|UINT8
name|Status
decl_stmt|;
comment|///
comment|/// 1-byte enumerated type field indicating format of the image.
comment|///     0 = Bitmap
comment|///     1 - 255  Reserved (for future use)
comment|///
name|UINT8
name|ImageType
decl_stmt|;
comment|///
comment|/// 8-byte (64 bit) physical address pointing to the firmware's in-memory copy
comment|/// of the image bitmap.
comment|///
name|UINT64
name|ImageAddress
decl_stmt|;
comment|///
comment|/// A 4-byte (32-bit) unsigned long describing the display X-offset of the boot image.
comment|/// (X, Y) display offset of the top left corner of the boot image.
comment|/// The top left corner of the display is at offset (0, 0).
comment|///
name|UINT32
name|ImageOffsetX
decl_stmt|;
comment|///
comment|/// A 4-byte (32-bit) unsigned long describing the display Y-offset of the boot image.
comment|/// (X, Y) display offset of the top left corner of the boot image.
comment|/// The top left corner of the display is at offset (0, 0).
comment|///
name|UINT32
name|ImageOffsetY
decl_stmt|;
block|}
name|EFI_ACPI_6_0_BOOT_GRAPHICS_RESOURCE_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BGRT Revision
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_BOOT_GRAPHICS_RESOURCE_TABLE_REVISION
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// BGRT Version
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_BGRT_VERSION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// BGRT Status
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_BGRT_STATUS_NOT_DISPLAYED
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_BGRT_STATUS_DISPLAYED
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// BGRT Image Type
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_BGRT_IMAGE_TYPE_BMP
value|0x00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FIRMWARE_PERFORMANCE_DATA_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Performance Record Types
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RECORD_TYPE_FIRMWARE_BASIC_BOOT_POINTER
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RECORD_TYPE_S3_PERFORMANCE_TABLE_POINTER
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Performance Record Revision
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RECORD_REVISION_FIRMWARE_BASIC_BOOT_POINTER
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RECORD_REVISION_S3_PERFORMANCE_TABLE_POINTER
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Runtime Performance Record Types
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RUNTIME_RECORD_TYPE_S3_RESUME
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RUNTIME_RECORD_TYPE_S3_SUSPEND
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RUNTIME_RECORD_TYPE_FIRMWARE_BASIC_BOOT
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Runtime Performance Record Revision
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RUNTIME_RECORD_REVISION_S3_RESUME
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RUNTIME_RECORD_REVISION_S3_SUSPEND
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_RUNTIME_RECORD_REVISION_FIRMWARE_BASIC_BOOT
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Performance Record header
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
block|}
name|EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Performance Table header
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
name|EFI_ACPI_6_0_FPDT_PERFORMANCE_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Firmware Basic Boot Performance Pointer Record Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
comment|///
comment|/// 64-bit processor-relative physical address of the Basic Boot Performance Table.
comment|///
name|UINT64
name|BootPerformanceTablePointer
decl_stmt|;
block|}
name|EFI_ACPI_6_0_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT S3 Performance Table Pointer Record Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
comment|///
comment|/// 64-bit processor-relative physical address of the S3 Performance Table.
comment|///
name|UINT64
name|S3PerformanceTablePointer
decl_stmt|;
block|}
name|EFI_ACPI_6_0_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Firmware Basic Boot Performance Record Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
comment|///
comment|/// Timer value logged at the beginning of firmware image execution.
comment|/// This may not always be zero or near zero.
comment|///
name|UINT64
name|ResetEnd
decl_stmt|;
comment|///
comment|/// Timer value logged just prior to loading the OS boot loader into memory.
comment|/// For non-UEFI compatible boots, this field must be zero.
comment|///
name|UINT64
name|OsLoaderLoadImageStart
decl_stmt|;
comment|///
comment|/// Timer value logged just prior to launching the previously loaded OS boot loader image.
comment|/// For non-UEFI compatible boots, the timer value logged will be just prior
comment|/// to the INT 19h handler invocation.
comment|///
name|UINT64
name|OsLoaderStartImageStart
decl_stmt|;
comment|///
comment|/// Timer value logged at the point when the OS loader calls the
comment|/// ExitBootServices function for UEFI compatible firmware.
comment|/// For non-UEFI compatible boots, this field must be zero.
comment|///
name|UINT64
name|ExitBootServicesEntry
decl_stmt|;
comment|///
comment|/// Timer value logged at the point just prior towhen the OS loader gaining
comment|/// control back from calls the ExitBootServices function for UEFI compatible firmware.
comment|/// For non-UEFI compatible boots, this field must be zero.
comment|///
name|UINT64
name|ExitBootServicesExit
decl_stmt|;
block|}
name|EFI_ACPI_6_0_FPDT_FIRMWARE_BASIC_BOOT_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Firmware Basic Boot Performance Table signature
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_BOOT_PERFORMANCE_TABLE_SIGNATURE
value|SIGNATURE_32('F', 'B', 'P', 'T')
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// FPDT Firmware Basic Boot Performance Table
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_FPDT_PERFORMANCE_TABLE_HEADER
name|Header
decl_stmt|;
comment|//
comment|// one or more Performance Records.
comment|//
block|}
name|EFI_ACPI_6_0_FPDT_FIRMWARE_BASIC_BOOT_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT "S3PT" S3 Performance Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FPDT_S3_PERFORMANCE_TABLE_SIGNATURE
value|SIGNATURE_32('S', '3', 'P', 'T')
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// FPDT Firmware S3 Boot Performance Table
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_FPDT_PERFORMANCE_TABLE_HEADER
name|Header
decl_stmt|;
comment|//
comment|// one or more Performance Records.
comment|//
block|}
name|EFI_ACPI_6_0_FPDT_FIRMWARE_S3_BOOT_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Basic S3 Resume Performance Record
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// A count of the number of S3 resume cycles since the last full boot sequence.
comment|///
name|UINT32
name|ResumeCount
decl_stmt|;
comment|///
comment|/// Timer recorded at the end of BIOS S3 resume, just prior to handoff to the
comment|/// OS waking vector. Only the most recent resume cycle's time is retained.
comment|///
name|UINT64
name|FullResume
decl_stmt|;
comment|///
comment|/// Average timer value of all resume cycles logged since the last full boot
comment|/// sequence, including the most recent resume.  Note that the entire log of
comment|/// timer values does not need to be retained in order to calculate this average.
comment|///
name|UINT64
name|AverageResume
decl_stmt|;
block|}
name|EFI_ACPI_6_0_FPDT_S3_RESUME_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// FPDT Basic S3 Suspend Performance Record
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// Timer value recorded at the OS write to SLP_TYP upon entry to S3.
comment|/// Only the most recent suspend cycle's timer value is retained.
comment|///
name|UINT64
name|SuspendStart
decl_stmt|;
comment|///
comment|/// Timer value recorded at the final firmware write to SLP_TYP (or other
comment|/// mechanism) used to trigger hardware entry to S3.
comment|/// Only the most recent suspend cycle's timer value is retained.
comment|///
name|UINT64
name|SuspendEnd
decl_stmt|;
block|}
name|EFI_ACPI_6_0_FPDT_S3_SUSPEND_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Firmware Performance Record Table definition.
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
block|}
name|EFI_ACPI_6_0_FIRMWARE_PERFORMANCE_RECORD_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Generic Timer Description Table definition.
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
name|UINT64
name|CntControlBasePhysicalAddress
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT32
name|SecurePL1TimerGSIV
decl_stmt|;
name|UINT32
name|SecurePL1TimerFlags
decl_stmt|;
name|UINT32
name|NonSecurePL1TimerGSIV
decl_stmt|;
name|UINT32
name|NonSecurePL1TimerFlags
decl_stmt|;
name|UINT32
name|VirtualTimerGSIV
decl_stmt|;
name|UINT32
name|VirtualTimerFlags
decl_stmt|;
name|UINT32
name|NonSecurePL2TimerGSIV
decl_stmt|;
name|UINT32
name|NonSecurePL2TimerFlags
decl_stmt|;
name|UINT64
name|CntReadBasePhysicalAddress
decl_stmt|;
name|UINT32
name|PlatformTimerCount
decl_stmt|;
name|UINT32
name|PlatformTimerOffset
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GENERIC_TIMER_DESCRIPTION_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GTDT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GENERIC_TIMER_DESCRIPTION_TABLE_REVISION
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Timer Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_TIMER_FLAG_TIMER_INTERRUPT_MODE
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_TIMER_FLAG_TIMER_INTERRUPT_POLARITY
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_TIMER_FLAG_ALWAYS_ON_CAPABILITY
value|BIT2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Platform Timer Type
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_GT_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_SBSA_GENERIC_WATCHDOG
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// GT Block Structure
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
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT64
name|CntCtlBase
decl_stmt|;
name|UINT32
name|GTBlockTimerCount
decl_stmt|;
name|UINT32
name|GTBlockTimerOffset
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GTDT_GT_BLOCK_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GT Block Timer Structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|GTFrameNumber
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT64
name|CntBaseX
decl_stmt|;
name|UINT64
name|CntEL0BaseX
decl_stmt|;
name|UINT32
name|GTxPhysicalTimerGSIV
decl_stmt|;
name|UINT32
name|GTxPhysicalTimerFlags
decl_stmt|;
name|UINT32
name|GTxVirtualTimerGSIV
decl_stmt|;
name|UINT32
name|GTxVirtualTimerFlags
decl_stmt|;
name|UINT32
name|GTxCommonFlags
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GTDT_GT_BLOCK_TIMER_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GT Block Physical Timers and Virtual Timers Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_GT_BLOCK_TIMER_FLAG_TIMER_INTERRUPT_MODE
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_GT_BLOCK_TIMER_FLAG_TIMER_INTERRUPT_POLARITY
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common Flags Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_GT_BLOCK_COMMON_FLAG_SECURE_TIMER
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_GT_BLOCK_COMMON_FLAG_ALWAYS_ON_CAPABILITY
value|BIT1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// SBSA Generic Watchdog Structure
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
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT64
name|RefreshFramePhysicalAddress
decl_stmt|;
name|UINT64
name|WatchdogControlFramePhysicalAddress
decl_stmt|;
name|UINT32
name|WatchdogTimerGSIV
decl_stmt|;
name|UINT32
name|WatchdogTimerFlags
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GTDT_SBSA_GENERIC_WATCHDOG_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SBSA Generic Watchdog Timer Flags.  All other bits are reserved and must be 0.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_SBSA_GENERIC_WATCHDOG_FLAG_TIMER_INTERRUPT_MODE
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_SBSA_GENERIC_WATCHDOG_FLAG_TIMER_INTERRUPT_POLARITY
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GTDT_SBSA_GENERIC_WATCHDOG_FLAG_SECURE_TIMER
value|BIT2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// NVDIMM Firmware Interface Table definition.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|EFI_ACPI_6_0_NVDIMM_FIRMWARE_INTERFACE_TABLE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// NFIT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NVDIMM_FIRMWARE_INTERFACE_TABLE_REVISION
value|0x1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for NFIT Table Structure Types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_STRUCTURE_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_MEMORY_DEVICE_TO_SYSTEM_ADDRESS_RANGE_MAP_STRUCTURE_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_INTERLEAVE_STRUCTURE_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_SMBIOS_MANAGEMENT_INFORMATION_STRUCTURE_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_NVDIMM_CONTROL_REGION_STRUCTURE_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_NVDIMM_BLOCK_DATA_WINDOW_REGION_STRUCTURE_TYPE
value|5
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_FLUSH_HINT_ADDRESS_STRUCTURE_TYPE
value|6
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for NFIT Structure Header
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|EFI_ACPI_6_0_NFIT_STRUCTURE_HEADER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for System Physical Address Range Structure
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_FLAGS_CONTROL_REGION_FOR_MANAGEMENT
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_FLAGS_PROXIMITY_DOMAIN_VALID
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_GUID_VOLATILE_MEMORY_REGION
value|{ 0x7305944F, 0xFDDA, 0x44E3, { 0xB1, 0x6C, 0x3F, 0x22, 0xD2, 0x52, 0xE5, 0xD0 }}
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_GUID_BYTE_ADDRESSABLE_PERSISTENT_MEMORY_REGION
value|{ 0x66F0D379, 0xB4F3, 0x4074, { 0xAC, 0x43, 0x0D, 0x33, 0x18, 0xB7, 0x8C, 0xDB }}
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_GUID_NVDIMM_CONTROL_REGION
value|{ 0x92F701F6, 0x13B4, 0x405D, { 0x91, 0x0B, 0x29, 0x93, 0x67, 0xE8, 0x23, 0x4C }}
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_GUID_NVDIMM_BLOCK_DATA_WINDOW_REGION
value|{ 0x91AF0530, 0x5D86, 0x470E, { 0xA6, 0xB0, 0x0A, 0x2D, 0xB9, 0x40, 0x82, 0x49 }}
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_DISK_REGION_VOLATILE
value|{ 0x77AB535A, 0x45FC, 0x624B, { 0x55, 0x60, 0xF7, 0xB2, 0x81, 0xD1, 0xF9, 0x6E }}
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_CD_REGION_VOLATILE
value|{ 0x3D5ABD30, 0x4175, 0x87CE, { 0x6D, 0x64, 0xD2, 0xAD, 0xE5, 0x23, 0xC4, 0xBB }}
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_DISK_REGION_PERSISTENT
value|{ 0x5CEA02C9, 0x4D07, 0x69D3, { 0x26, 0x9F ,0x44, 0x96, 0xFB, 0xE0, 0x96, 0xF9 }}
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_CD_REGION_PERSISTENT
value|{ 0x08018188, 0x42CD, 0xBB48, { 0x10, 0x0F, 0x53, 0x87, 0xD5, 0x3D, 0xED, 0x3D }}
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT16
name|SPARangeStructureIndex
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT32
name|Reserved_8
decl_stmt|;
name|UINT32
name|ProximityDomain
decl_stmt|;
name|GUID
name|AddressRangeTypeGUID
decl_stmt|;
name|UINT64
name|SystemPhysicalAddressRangeBase
decl_stmt|;
name|UINT64
name|SystemPhysicalAddressRangeLength
decl_stmt|;
name|UINT64
name|AddressRangeMemoryMappingAttribute
decl_stmt|;
block|}
name|EFI_ACPI_6_0_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for Memory Device to System Physical Address Range Mapping Structure
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|DIMMNumber
range|:
literal|4
decl_stmt|;
name|UINT32
name|MemoryChannelNumber
range|:
literal|4
decl_stmt|;
name|UINT32
name|MemoryControllerID
range|:
literal|4
decl_stmt|;
name|UINT32
name|SocketID
range|:
literal|4
decl_stmt|;
name|UINT32
name|NodeControllerID
range|:
literal|12
decl_stmt|;
name|UINT32
name|Reserved_28
range|:
literal|4
decl_stmt|;
block|}
name|EFI_ACPI_6_0_NFIT_DEVICE_HANDLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_MEMORY_DEVICE_STATE_FLAGS_PREVIOUS_SAVE_FAIL
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_MEMORY_DEVICE_STATE_FLAGS_LAST_RESTORE_FAIL
value|BIT1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_MEMORY_DEVICE_STATE_FLAGS_PLATFORM_FLUSH_FAIL
value|BIT2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_MEMORY_DEVICE_STATE_FLAGS_NOT_ARMED_PRIOR_TO_OSPM_HAND_OFF
value|BIT3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_MEMORY_DEVICE_STATE_FLAGS_SMART_HEALTH_EVENTS_PRIOR_OSPM_HAND_OFF
value|BIT4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_MEMORY_DEVICE_STATE_FLAGS_FIRMWARE_ENABLED_TO_NOTIFY_OSPM_ON_SMART_HEALTH_EVENTS
value|BIT5
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|EFI_ACPI_6_0_NFIT_DEVICE_HANDLE
name|NFITDeviceHandle
decl_stmt|;
name|UINT16
name|MemoryDevicePhysicalID
decl_stmt|;
name|UINT16
name|MemoryDeviceRegionID
decl_stmt|;
name|UINT16
name|SPARangeStructureIndex
decl_stmt|;
name|UINT16
name|NVDIMMControlRegionStructureIndex
decl_stmt|;
name|UINT64
name|MemoryDeviceRegionSize
decl_stmt|;
name|UINT64
name|RegionOffset
decl_stmt|;
name|UINT64
name|MemoryDevicePhysicalAddressRegionBase
decl_stmt|;
name|UINT16
name|InterleaveStructureIndex
decl_stmt|;
name|UINT16
name|InterleaveWays
decl_stmt|;
name|UINT16
name|MemoryDeviceStateFlags
decl_stmt|;
name|UINT16
name|Reserved_46
decl_stmt|;
block|}
name|EFI_ACPI_6_0_NFIT_MEMORY_DEVICE_TO_SYSTEM_ADDRESS_RANGE_MAP_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for Interleave Structure
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT16
name|InterleaveStructureIndex
decl_stmt|;
name|UINT16
name|Reserved_6
decl_stmt|;
name|UINT32
name|NumberOfLines
decl_stmt|;
name|UINT32
name|LineSize
decl_stmt|;
comment|//UINT32                                      LineOffset[NumberOfLines];
block|}
name|EFI_ACPI_6_0_NFIT_INTERLEAVE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for SMBIOS Management Information Structure
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT32
name|Reserved_4
decl_stmt|;
comment|//UINT8                                       Data[];
block|}
name|EFI_ACPI_6_0_NFIT_SMBIOS_MANAGEMENT_INFORMATION_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for NVDIMM Control Region Structure
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NFIT_NVDIMM_CONTROL_REGION_FLAGS_BLOCK_DATA_WINDOWS_BUFFERED
value|BIT0
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT16
name|NVDIMMControlRegionStructureIndex
decl_stmt|;
name|UINT16
name|VendorID
decl_stmt|;
name|UINT16
name|DeviceID
decl_stmt|;
name|UINT16
name|RevisionID
decl_stmt|;
name|UINT16
name|SubsystemVendorID
decl_stmt|;
name|UINT16
name|SubsystemDeviceID
decl_stmt|;
name|UINT16
name|SubsystemRevisionID
decl_stmt|;
name|UINT8
name|Reserved_18
index|[
literal|6
index|]
decl_stmt|;
name|UINT32
name|SerialNumber
decl_stmt|;
name|UINT16
name|RegionFormatInterfaceCode
decl_stmt|;
name|UINT16
name|NumberOfBlockControlWindows
decl_stmt|;
name|UINT64
name|SizeOfBlockControlWindow
decl_stmt|;
name|UINT64
name|CommandRegisterOffsetInBlockControlWindow
decl_stmt|;
name|UINT64
name|SizeOfCommandRegisterInBlockControlWindows
decl_stmt|;
name|UINT64
name|StatusRegisterOffsetInBlockControlWindow
decl_stmt|;
name|UINT64
name|SizeOfStatusRegisterInBlockControlWindows
decl_stmt|;
name|UINT16
name|NVDIMMControlRegionFlag
decl_stmt|;
name|UINT8
name|Reserved_74
index|[
literal|6
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_NFIT_NVDIMM_CONTROL_REGION_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for NVDIMM Block Data Window Region Structure
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT16
name|NVDIMMControlRegionStructureIndex
decl_stmt|;
name|UINT16
name|NumberOfBlockDataWindows
decl_stmt|;
name|UINT64
name|BlockDataWindowStartOffset
decl_stmt|;
name|UINT64
name|SizeOfBlockDataWindow
decl_stmt|;
name|UINT64
name|BlockAccessibleMemoryCapacity
decl_stmt|;
name|UINT64
name|BeginningAddressOfFirstBlockInBlockAccessibleMemory
decl_stmt|;
block|}
name|EFI_ACPI_6_0_NFIT_NVDIMM_BLOCK_DATA_WINDOW_REGION_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for Flush Hint Address Structure
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|EFI_ACPI_6_0_NFIT_DEVICE_HANDLE
name|NFITDeviceHandle
decl_stmt|;
name|UINT16
name|NumberOfFlushHintAddresses
decl_stmt|;
name|UINT8
name|Reserved_10
index|[
literal|6
index|]
decl_stmt|;
comment|//UINT64                                      FlushHintAddress[NumberOfFlushHintAddresses];
block|}
name|EFI_ACPI_6_0_NFIT_FLUSH_HINT_ADDRESS_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Boot Error Record Table (BERT)
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
name|BootErrorRegionLength
decl_stmt|;
name|UINT64
name|BootErrorRegion
decl_stmt|;
block|}
name|EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BERT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Boot Error Region Block Status Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|UncorrectableErrorValid
range|:
literal|1
decl_stmt|;
name|UINT32
name|CorrectableErrorValid
range|:
literal|1
decl_stmt|;
name|UINT32
name|MultipleUncorrectableErrors
range|:
literal|1
decl_stmt|;
name|UINT32
name|MultipleCorrectableErrors
range|:
literal|1
decl_stmt|;
name|UINT32
name|ErrorDataEntryCount
range|:
literal|10
decl_stmt|;
name|UINT32
name|Reserved
range|:
literal|18
decl_stmt|;
block|}
name|EFI_ACPI_6_0_ERROR_BLOCK_STATUS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Boot Error Region Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_ERROR_BLOCK_STATUS
name|BlockStatus
decl_stmt|;
name|UINT32
name|RawDataOffset
decl_stmt|;
name|UINT32
name|RawDataLength
decl_stmt|;
name|UINT32
name|DataLength
decl_stmt|;
name|UINT32
name|ErrorSeverity
decl_stmt|;
block|}
name|EFI_ACPI_6_0_BOOT_ERROR_REGION_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Boot Error Severity types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_SEVERITY_CORRECTABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_SEVERITY_FATAL
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_SEVERITY_CORRECTED
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_SEVERITY_NONE
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Generic Error Data Entry Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|SectionType
index|[
literal|16
index|]
decl_stmt|;
name|UINT32
name|ErrorSeverity
decl_stmt|;
name|UINT16
name|Revision
decl_stmt|;
name|UINT8
name|ValidationBits
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT32
name|ErrorDataLength
decl_stmt|;
name|UINT8
name|FruId
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|FruText
index|[
literal|20
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GENERIC_ERROR_DATA_ENTRY_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Generic Error Data Entry Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GENERIC_ERROR_DATA_ENTRY_REVISION
value|0x0201
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// HEST - Hardware Error Source Table
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
name|ErrorSourceCount
decl_stmt|;
block|}
name|EFI_ACPI_6_0_HARDWARE_ERROR_SOURCE_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// HEST Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_SOURCE_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Error Source structure types.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_NMI_ERROR
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PCI_EXPRESS_ROOT_PORT_AER
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PCI_EXPRESS_DEVICE_AER
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PCI_EXPRESS_BRIDGE_AER
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GENERIC_HARDWARE_ERROR
value|0x09
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Error Source structure flags.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_SOURCE_FLAG_FIRMWARE_FIRST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_SOURCE_FLAG_GLOBAL
value|(1<< 1)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA-32 Architecture Machine Check Exception Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT8
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|NumberOfRecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT64
name|GlobalCapabilityInitData
decl_stmt|;
name|UINT64
name|GlobalControlInitData
decl_stmt|;
name|UINT8
name|NumberOfHardwareBanks
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|7
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA-32 Architecture Machine Check Bank Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|BankNumber
decl_stmt|;
name|UINT8
name|ClearStatusOnInitialization
decl_stmt|;
name|UINT8
name|StatusDataFormat
decl_stmt|;
name|UINT8
name|Reserved0
decl_stmt|;
name|UINT32
name|ControlRegisterMsrAddress
decl_stmt|;
name|UINT64
name|ControlInitData
decl_stmt|;
name|UINT32
name|StatusRegisterMsrAddress
decl_stmt|;
name|UINT32
name|AddressRegisterMsrAddress
decl_stmt|;
name|UINT32
name|MiscRegisterMsrAddress
decl_stmt|;
block|}
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA-32 Architecture Machine Check Bank Structure MCA data format
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_DATA_FORMAT_IA32
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_DATA_FORMAT_INTEL64
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_DATA_FORMAT_AMD64
value|0x02
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Hardware Error Notification types. All other values are reserved
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_POLLED
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_EXTERNAL_INTERRUPT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_LOCAL_INTERRUPT
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_SCI
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_NMI
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_CMCI
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_MCE
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_GPIO_SIGNAL
value|0x07
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Hardware Error Notification Configuration Write Enable Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
range|:
literal|1
decl_stmt|;
name|UINT16
name|PollInterval
range|:
literal|1
decl_stmt|;
name|UINT16
name|SwitchToPollingThresholdValue
range|:
literal|1
decl_stmt|;
name|UINT16
name|SwitchToPollingThresholdWindow
range|:
literal|1
decl_stmt|;
name|UINT16
name|ErrorThresholdValue
range|:
literal|1
decl_stmt|;
name|UINT16
name|ErrorThresholdWindow
range|:
literal|1
decl_stmt|;
name|UINT16
name|Reserved
range|:
literal|10
decl_stmt|;
block|}
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Hardware Error Notification Structure Definition
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
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE
name|ConfigurationWriteEnable
decl_stmt|;
name|UINT32
name|PollInterval
decl_stmt|;
name|UINT32
name|Vector
decl_stmt|;
name|UINT32
name|SwitchToPollingThresholdValue
decl_stmt|;
name|UINT32
name|SwitchToPollingThresholdWindow
decl_stmt|;
name|UINT32
name|ErrorThresholdValue
decl_stmt|;
name|UINT32
name|ErrorThresholdWindow
decl_stmt|;
block|}
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA-32 Architecture Corrected Machine Check Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT8
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|NumberOfRecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE
name|NotificationStructure
decl_stmt|;
name|UINT8
name|NumberOfHardwareBanks
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
block|}
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IA-32 Architecture NMI Error Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT8
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
name|UINT32
name|NumberOfRecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|MaxRawDataLength
decl_stmt|;
block|}
name|EFI_ACPI_6_0_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Express Root Port AER Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT8
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|NumberOfRecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|Bus
decl_stmt|;
name|UINT16
name|Device
decl_stmt|;
name|UINT16
name|Function
decl_stmt|;
name|UINT16
name|DeviceControl
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
name|UINT32
name|UncorrectableErrorMask
decl_stmt|;
name|UINT32
name|UncorrectableErrorSeverity
decl_stmt|;
name|UINT32
name|CorrectableErrorMask
decl_stmt|;
name|UINT32
name|AdvancedErrorCapabilitiesAndControl
decl_stmt|;
name|UINT32
name|RootErrorCommand
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Express Device AER Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT8
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|NumberOfRecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|Bus
decl_stmt|;
name|UINT16
name|Device
decl_stmt|;
name|UINT16
name|Function
decl_stmt|;
name|UINT16
name|DeviceControl
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
name|UINT32
name|UncorrectableErrorMask
decl_stmt|;
name|UINT32
name|UncorrectableErrorSeverity
decl_stmt|;
name|UINT32
name|CorrectableErrorMask
decl_stmt|;
name|UINT32
name|AdvancedErrorCapabilitiesAndControl
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PCI_EXPRESS_DEVICE_AER_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Express Bridge AER Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT8
name|Reserved0
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|NumberOfRecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|Bus
decl_stmt|;
name|UINT16
name|Device
decl_stmt|;
name|UINT16
name|Function
decl_stmt|;
name|UINT16
name|DeviceControl
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
name|UINT32
name|UncorrectableErrorMask
decl_stmt|;
name|UINT32
name|UncorrectableErrorSeverity
decl_stmt|;
name|UINT32
name|CorrectableErrorMask
decl_stmt|;
name|UINT32
name|AdvancedErrorCapabilitiesAndControl
decl_stmt|;
name|UINT32
name|SecondaryUncorrectableErrorMask
decl_stmt|;
name|UINT32
name|SecondaryUncorrectableErrorSeverity
decl_stmt|;
name|UINT32
name|SecondaryAdvancedErrorCapabilitiesAndControl
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PCI_EXPRESS_BRIDGE_AER_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Generic Hardware Error Source Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT16
name|RelatedSourceId
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|NumberOfRecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|MaxRawDataLength
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|ErrorStatusAddress
decl_stmt|;
name|EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE
name|NotificationStructure
decl_stmt|;
name|UINT32
name|ErrorStatusBlockLength
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Generic Error Status Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_6_0_ERROR_BLOCK_STATUS
name|BlockStatus
decl_stmt|;
name|UINT32
name|RawDataOffset
decl_stmt|;
name|UINT32
name|RawDataLength
decl_stmt|;
name|UINT32
name|DataLength
decl_stmt|;
name|UINT32
name|ErrorSeverity
decl_stmt|;
block|}
name|EFI_ACPI_6_0_GENERIC_ERROR_STATUS_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ERST - Error Record Serialization Table
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
name|SerializationHeaderSize
decl_stmt|;
name|UINT8
name|Reserved0
index|[
literal|4
index|]
decl_stmt|;
name|UINT32
name|InstructionEntryCount
decl_stmt|;
block|}
name|EFI_ACPI_6_0_ERROR_RECORD_SERIALIZATION_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ERST Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_RECORD_SERIALIZATION_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ERST Serialization Actions
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_BEGIN_WRITE_OPERATION
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_BEGIN_READ_OPERATION
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_BEGIN_CLEAR_OPERATION
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_END_OPERATION
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_SET_RECORD_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_EXECUTE_OPERATION
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_CHECK_BUSY_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_GET_COMMAND_STATUS
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_GET_RECORD_IDENTIFIER
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_SET_RECORD_IDENTIFIER
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_GET_RECORD_COUNT
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_BEGIN_DUMMY_WRITE_OPERATION
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_GET_ERROR_LOG_ADDRESS_RANGE
value|0x0D
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_GET_ERROR_LOG_ADDRESS_RANGE_LENGTH
value|0x0E
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_GET_ERROR_LOG_ADDRESS_RANGE_ATTRIBUTES
value|0x0F
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ERST Action Command Status
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_STATUS_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_STATUS_NOT_ENOUGH_SPACE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_STATUS_HARDWARE_NOT_AVAILABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_STATUS_FAILED
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_STATUS_RECORD_STORE_EMPTY
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_STATUS_RECORD_NOT_FOUND
value|0x05
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ERST Serialization Instructions
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_READ_REGISTER
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_READ_REGISTER_VALUE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_WRITE_REGISTER
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_WRITE_REGISTER_VALUE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_NOOP
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_LOAD_VAR1
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_LOAD_VAR2
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_STORE_VAR1
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_ADD
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_SUBTRACT
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_ADD_VALUE
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_SUBTRACT_VALUE
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_STALL
value|0x0C
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_STALL_WHILE_TRUE
value|0x0D
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_SKIP_NEXT_INSTRUCTION_IF_TRUE
value|0x0E
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_GOTO
value|0x0F
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_SET_SRC_ADDRESS_BASE
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_SET_DST_ADDRESS_BASE
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_MOVE_DATA
value|0x12
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ERST Instruction Flags
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERST_PRESERVE_REGISTER
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ERST Serialization Instruction Entry
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|SerializationAction
decl_stmt|;
name|UINT8
name|Instruction
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved0
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|RegisterRegion
decl_stmt|;
name|UINT64
name|Value
decl_stmt|;
name|UINT64
name|Mask
decl_stmt|;
block|}
name|EFI_ACPI_6_0_ERST_SERIALIZATION_INSTRUCTION_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EINJ - Error Injection Table
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
name|InjectionHeaderSize
decl_stmt|;
name|UINT8
name|InjectionFlags
decl_stmt|;
name|UINT8
name|Reserved0
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|InjectionEntryCount
decl_stmt|;
block|}
name|EFI_ACPI_6_0_ERROR_INJECTION_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EINJ Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_INJECTION_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EINJ Error Injection Actions
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_BEGIN_INJECTION_OPERATION
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_GET_TRIGGER_ERROR_ACTION_TABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_SET_ERROR_TYPE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_GET_ERROR_TYPE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_END_OPERATION
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_EXECUTE_OPERATION
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_CHECK_BUSY_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_GET_COMMAND_STATUS
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_TRIGGER_ERROR
value|0xFF
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EINJ Action Command Status
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_STATUS_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_STATUS_UNKNOWN_FAILURE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_STATUS_INVALID_ACCESS
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EINJ Error Type Definition
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_PROCESSOR_CORRECTABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_PROCESSOR_UNCORRECTABLE_NONFATAL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_PROCESSOR_UNCORRECTABLE_FATAL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_MEMORY_CORRECTABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_MEMORY_UNCORRECTABLE_NONFATAL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_MEMORY_UNCORRECTABLE_FATAL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_PCI_EXPRESS_CORRECTABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_PCI_EXPRESS_UNCORRECTABLE_NONFATAL
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_PCI_EXPRESS_UNCORRECTABLE_FATAL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_PLATFORM_CORRECTABLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_PLATFORM_UNCORRECTABLE_NONFATAL
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_ERROR_PLATFORM_UNCORRECTABLE_FATAL
value|(1<< 11)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EINJ Injection Instructions
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_READ_REGISTER
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_READ_REGISTER_VALUE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_WRITE_REGISTER
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_WRITE_REGISTER_VALUE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_NOOP
value|0x04
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EINJ Instruction Flags
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_EINJ_PRESERVE_REGISTER
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EINJ Injection Instruction Entry
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|InjectionAction
decl_stmt|;
name|UINT8
name|Instruction
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved0
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|RegisterRegion
decl_stmt|;
name|UINT64
name|Value
decl_stmt|;
name|UINT64
name|Mask
decl_stmt|;
block|}
name|EFI_ACPI_6_0_EINJ_INJECTION_INSTRUCTION_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EINJ Trigger Action Table
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|HeaderSize
decl_stmt|;
name|UINT32
name|Revision
decl_stmt|;
name|UINT32
name|TableSize
decl_stmt|;
name|UINT32
name|EntryCount
decl_stmt|;
block|}
name|EFI_ACPI_6_0_EINJ_TRIGGER_ACTION_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Platform Communications Channel Table (PCCT)
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
name|Flags
decl_stmt|;
name|UINT64
name|Reserved
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PLATFORM_COMMUNICATION_CHANNEL_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCCT Version (as defined in ACPI 6.0 spec.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PLATFORM_COMMUNICATION_CHANNEL_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCCT Global Flags
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PCCT_FLAGS_SCI_DOORBELL
value|BIT0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// PCCT Subspace type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PCCT_SUBSPACE_TYPE_GENERIC
value|0x00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCC Subspace Structure Header
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
block|}
name|EFI_ACPI_6_0_PCCT_SUBSPACE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Generic Communications Subspace Structure
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
name|Reserved
index|[
literal|6
index|]
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT64
name|AddressLength
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|DoorbellRegister
decl_stmt|;
name|UINT64
name|DoorbellPreserve
decl_stmt|;
name|UINT64
name|DoorbellWrite
decl_stmt|;
name|UINT32
name|NominalLatency
decl_stmt|;
name|UINT32
name|MaximumPeriodicAccessRate
decl_stmt|;
name|UINT16
name|MinimumRequestTurnaroundTime
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PCCT_SUBSPACE_GENERIC
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Generic Communications Channel Shared Memory Region
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Command
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|7
decl_stmt|;
name|UINT8
name|GenerateSci
range|:
literal|1
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CommandComplete
range|:
literal|1
decl_stmt|;
name|UINT8
name|SciDoorbell
range|:
literal|1
decl_stmt|;
name|UINT8
name|Error
range|:
literal|1
decl_stmt|;
name|UINT8
name|PlatformNotification
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND
name|Command
decl_stmt|;
name|EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS
name|Status
decl_stmt|;
block|}
name|EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER
typedef|;
end_typedef

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
name|EFI_ACPI_6_0_ROOT_SYSTEM_DESCRIPTION_POINTER_SIGNATURE
value|SIGNATURE_64('R', 'S', 'D', ' ', 'P', 'T', 'R', ' ')
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
name|EFI_ACPI_6_0_MULTIPLE_APIC_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('A', 'P', 'I', 'C')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "BERT" Boot Error Record Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_SIGNATURE
value|SIGNATURE_32('B', 'E', 'R', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "BGRT" Boot Graphics Resource Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_BOOT_GRAPHICS_RESOURCE_TABLE_SIGNATURE
value|SIGNATURE_32('B', 'G', 'R', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "CPEP" Corrected Platform Error Polling Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_SIGNATURE
value|SIGNATURE_32('C', 'P', 'E', 'P')
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
name|EFI_ACPI_6_0_DIFFERENTIATED_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
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
name|EFI_ACPI_6_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE_SIGNATURE
value|SIGNATURE_32('E', 'C', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "EINJ" Error Injection Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_INJECTION_TABLE_SIGNATURE
value|SIGNATURE_32('E', 'I', 'N', 'J')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "ERST" Error Record Serialization Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ERROR_RECORD_SERIALIZATION_TABLE_SIGNATURE
value|SIGNATURE_32('E', 'R', 'S', 'T')
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
name|EFI_ACPI_6_0_FIXED_ACPI_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('F', 'A', 'C', 'P')
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
name|EFI_ACPI_6_0_FIRMWARE_ACPI_CONTROL_STRUCTURE_SIGNATURE
value|SIGNATURE_32('F', 'A', 'C', 'S')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "FPDT" Firmware Performance Data Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_FIRMWARE_PERFORMANCE_DATA_TABLE_SIGNATURE
value|SIGNATURE_32('F', 'P', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "GTDT" Generic Timer Description Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_GENERIC_TIMER_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('G', 'T', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "HEST" Hardware Error Source Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HARDWARE_ERROR_SOURCE_TABLE_SIGNATURE
value|SIGNATURE_32('H', 'E', 'S', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "MPST" Memory Power State Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MEMORY_POWER_STATE_TABLE_SIGNATURE
value|SIGNATURE_32('M', 'P', 'S', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "MSCT" Maximum System Characteristics Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_SIGNATURE
value|SIGNATURE_32('M', 'S', 'C', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "NFIT" NVDIMM Firmware Interface Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_NVDIMM_FIRMWARE_INTERFACE_TABLE_STRUCTURE_SIGNATURE
value|SIGNATURE_32('N', 'F', 'I', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "PMTT" Platform Memory Topology Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PLATFORM_MEMORY_TOPOLOGY_TABLE_SIGNATURE
value|SIGNATURE_32('P', 'M', 'T', 'T')
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
name|EFI_ACPI_6_0_PERSISTENT_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('P', 'S', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "RASF" ACPI RAS Feature Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ACPI_RAS_FEATURE_TABLE_SIGNATURE
value|SIGNATURE_32('R', 'A', 'S', 'F')
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
name|EFI_ACPI_6_0_ROOT_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
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
name|EFI_ACPI_6_0_SMART_BATTERY_SPECIFICATION_TABLE_SIGNATURE
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
name|EFI_ACPI_6_0_SYSTEM_LOCALITY_INFORMATION_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'L', 'I', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SRAT" System Resource Affinity Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SYSTEM_RESOURCE_AFFINITY_TABLE_SIGNATURE
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
name|EFI_ACPI_6_0_SECONDARY_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'S', 'D', 'T')
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
name|EFI_ACPI_6_0_EXTENDED_SYSTEM_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('X', 'S', 'D', 'T')
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
name|EFI_ACPI_6_0_SIMPLE_BOOT_FLAG_TABLE_SIGNATURE
value|SIGNATURE_32('B', 'O', 'O', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "CSRT" MS Core System Resource Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_CORE_SYSTEM_RESOURCE_TABLE_SIGNATURE
value|SIGNATURE_32('C', 'S', 'R', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "DBG2" MS Debug Port 2 Spec
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_DEBUG_PORT_2_TABLE_SIGNATURE
value|SIGNATURE_32('D', 'B', 'G', '2')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "DBGP" MS Debug Port Spec
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_DEBUG_PORT_TABLE_SIGNATURE
value|SIGNATURE_32('D', 'B', 'G', 'P')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "DMAR" DMA Remapping Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_DMA_REMAPPING_TABLE_SIGNATURE
value|SIGNATURE_32('D', 'M', 'A', 'R')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "DRTM" Dynamic Root of Trust for Measurement Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_DYNAMIC_ROOT_OF_TRUST_FOR_MEASUREMENT_TABLE_SIGNATURE
value|SIGNATURE_32('D', 'R', 'T', 'M')
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
name|EFI_ACPI_6_0_EVENT_TIMER_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('E', 'T', 'D', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "HPET" IA-PC High Precision Event Timer Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_HIGH_PRECISION_EVENT_TIMER_TABLE_SIGNATURE
value|SIGNATURE_32('H', 'P', 'E', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "iBFT" iSCSI Boot Firmware Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_ISCSI_BOOT_FIRMWARE_TABLE_SIGNATURE
value|SIGNATURE_32('i', 'B', 'F', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "IORT" I/O Remapping Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IO_REMAPPING_TABLE_SIGNATURE
value|SIGNATURE_32('I', 'O', 'R', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "IVRS" I/O Virtualization Reporting Structure
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_IO_VIRTUALIZATION_REPORTING_STRUCTURE_SIGNATURE
value|SIGNATURE_32('I', 'V', 'R', 'S')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "LPIT" Low Power Idle Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_LOW_POWER_IDLE_TABLE_STRUCTURE_SIGNATURE
value|SIGNATURE_32('L', 'P', 'I', 'T')
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
name|EFI_ACPI_6_0_PCI_EXPRESS_MEMORY_MAPPED_CONFIGURATION_SPACE_BASE_ADDRESS_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32('M', 'C', 'F', 'G')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "MCHI" Management Controller Host Interface Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_MANAGEMENT_CONTROLLER_HOST_INTERFACE_TABLE_SIGNATURE
value|SIGNATURE_32('M', 'C', 'H', 'I')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "MSDM" MS Data Management Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_DATA_MANAGEMENT_TABLE_SIGNATURE
value|SIGNATURE_32('M', 'S', 'D', 'M')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "SLIC" MS Software Licensing Table Specification
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_SOFTWARE_LICENSING_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'L', 'I', 'C')
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
name|EFI_ACPI_6_0_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'P', 'C', 'R')
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
name|EFI_ACPI_6_0_SERVER_PLATFORM_MANAGEMENT_INTERFACE_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'P', 'M', 'I')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "STAO" _STA Override Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_STA_OVERRIDE_TABLE_SIGNATURE
value|SIGNATURE_32('S', 'T', 'A', 'O')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "TCPA" Trusted Computing Platform Alliance Capabilities Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_TRUSTED_COMPUTING_PLATFORM_ALLIANCE_CAPABILITIES_TABLE_SIGNATURE
value|SIGNATURE_32('T', 'C', 'P', 'A')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "TPM2" Trusted Computing Platform 1 Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_TRUSTED_COMPUTING_PLATFORM_2_TABLE_SIGNATURE
value|SIGNATURE_32('T', 'P', 'M', '2')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "UEFI" UEFI ACPI Data Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_UEFI_ACPI_DATA_TABLE_SIGNATURE
value|SIGNATURE_32('U', 'E', 'F', 'I')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "WAET" Windows ACPI Emulated Devices Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_WINDOWS_ACPI_EMULATED_DEVICES_TABLE_SIGNATURE
value|SIGNATURE_32('W', 'A', 'E', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "WDAT" Watchdog Action Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_WATCHDOG_ACTION_TABLE_SIGNATURE
value|SIGNATURE_32('W', 'D', 'A', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "WDRT" Watchdog Resource Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_WATCHDOG_RESOURCE_TABLE_SIGNATURE
value|SIGNATURE_32('W', 'D', 'R', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "WPBT" MS Platform Binary Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_PLATFORM_BINARY_TABLE_SIGNATURE
value|SIGNATURE_32('W', 'P', 'B', 'T')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "XENV" Xen Project Table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_6_0_XEN_PROJECT_TABLE_SIGNATURE
value|SIGNATURE_32('X', 'E', 'N', 'V')
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

