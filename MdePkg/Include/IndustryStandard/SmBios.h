begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Industry Standard Definitions of SMBIOS Table Specification v3.1.0.  Copyright (c) 2006 - 2017, Intel Corporation. All rights reserved.<BR> (C) Copyright 2015-2017 Hewlett Packard Enterprise Development LP<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMBIOS_STANDARD_H__
end_ifndef

begin_define
define|#
directive|define
name|__SMBIOS_STANDARD_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Reference SMBIOS 2.6, chapter 3.1.2.
end_comment

begin_comment
comment|/// For v2.1 and later, handle values in the range 0FF00h to 0FFFFh are reserved for
end_comment

begin_comment
comment|/// use by this specification.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SMBIOS_HANDLE_RESERVED_BEGIN
value|0xFF00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Reference SMBIOS 2.7, chapter 6.1.2.
end_comment

begin_comment
comment|/// The UEFI Platform Initialization Specification reserves handle number FFFEh for its
end_comment

begin_comment
comment|/// EFI_SMBIOS_PROTOCOL.Add() function to mean "assign an unused handle number automatically."
end_comment

begin_comment
comment|/// This number is not used for any other purpose by the SMBIOS specification.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SMBIOS_HANDLE_PI_RESERVED
value|0xFFFE
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Reference SMBIOS 2.6, chapter 3.1.3.
end_comment

begin_comment
comment|/// Each text string is limited to 64 significant characters due to system MIF limitations.
end_comment

begin_comment
comment|/// Reference SMBIOS 2.7, chapter 6.1.3.
end_comment

begin_comment
comment|/// It will have no limit on the length of each individual text string.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SMBIOS_STRING_MAX_LENGTH
value|64
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// The length of the entire structure table (including all strings) must be reported
end_comment

begin_comment
comment|// in the Structure Table Length field of the SMBIOS Structure Table Entry Point,
end_comment

begin_comment
comment|// which is a WORD field limited to 65,535 bytes.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SMBIOS_TABLE_MAX_LENGTH
value|0xFFFF
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// For SMBIOS 3.0, Structure table maximum size in Entry Point structure is DWORD field limited to 0xFFFFFFFF bytes.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SMBIOS_3_0_TABLE_MAX_LENGTH
value|0xFFFFFFFF
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SMBIOS type macros which is according to SMBIOS 2.7 specification.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SMBIOS_TYPE_BIOS_INFORMATION
value|0
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM_INFORMATION
value|1
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_BASEBOARD_INFORMATION
value|2
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM_ENCLOSURE
value|3
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_PROCESSOR_INFORMATION
value|4
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MEMORY_CONTROLLER_INFORMATION
value|5
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MEMORY_MODULE_INFORMATON
value|6
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_CACHE_INFORMATION
value|7
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_PORT_CONNECTOR_INFORMATION
value|8
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM_SLOTS
value|9
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_ONBOARD_DEVICE_INFORMATION
value|10
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_OEM_STRINGS
value|11
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM_CONFIGURATION_OPTIONS
value|12
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_BIOS_LANGUAGE_INFORMATION
value|13
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_GROUP_ASSOCIATIONS
value|14
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM_EVENT_LOG
value|15
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_PHYSICAL_MEMORY_ARRAY
value|16
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MEMORY_DEVICE
value|17
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_32BIT_MEMORY_ERROR_INFORMATION
value|18
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MEMORY_ARRAY_MAPPED_ADDRESS
value|19
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MEMORY_DEVICE_MAPPED_ADDRESS
value|20
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_BUILT_IN_POINTING_DEVICE
value|21
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_PORTABLE_BATTERY
value|22
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM_RESET
value|23
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_HARDWARE_SECURITY
value|24
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM_POWER_CONTROLS
value|25
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_VOLTAGE_PROBE
value|26
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_COOLING_DEVICE
value|27
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_TEMPERATURE_PROBE
value|28
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_ELECTRICAL_CURRENT_PROBE
value|29
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_OUT_OF_BAND_REMOTE_ACCESS
value|30
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_BOOT_INTEGRITY_SERVICE
value|31
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM_BOOT_INFORMATION
value|32
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_64BIT_MEMORY_ERROR_INFORMATION
value|33
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MANAGEMENT_DEVICE
value|34
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MANAGEMENT_DEVICE_COMPONENT
value|35
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MANAGEMENT_DEVICE_THRESHOLD_DATA
value|36
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MEMORY_CHANNEL
value|37
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_IPMI_DEVICE_INFORMATION
value|38
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM_POWER_SUPPLY
value|39
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_ADDITIONAL_INFORMATION
value|40
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_ONBOARD_DEVICES_EXTENDED_INFORMATION
value|41
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MANAGEMENT_CONTROLLER_HOST_INTERFACE
value|42
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_TPM_DEVICE
value|43
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Inactive type is added from SMBIOS 2.2. Reference SMBIOS 2.6, chapter 3.3.43.
end_comment

begin_comment
comment|/// Upper-level software that interprets the SMBIOS structure-table should bypass an
end_comment

begin_comment
comment|/// Inactive structure just like a structure type that the software does not recognize.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SMBIOS_TYPE_INACTIVE
value|0x007E
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// End-of-table type is added from SMBIOS 2.2. Reference SMBIOS 2.6, chapter 3.3.44.
end_comment

begin_comment
comment|/// The end-of-table indicator is used in the last physical structure in a table
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SMBIOS_TYPE_END_OF_TABLE
value|0x007F
end_define

begin_define
define|#
directive|define
name|SMBIOS_OEM_BEGIN
value|128
end_define

begin_define
define|#
directive|define
name|SMBIOS_OEM_END
value|255
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Types 0 through 127 (7Fh) are reserved for and defined by this
end_comment

begin_comment
comment|/// specification. Types 128 through 256 (80h to FFh) are available for system- and OEM-specific information.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|SMBIOS_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specifies the structure's handle, a unique 16-bit number in the range 0 to 0FFFEh (for version
end_comment

begin_comment
comment|/// 2.0) or 0 to 0FEFFh (for version 2.1 and later). The handle can be used with the Get SMBIOS
end_comment

begin_comment
comment|/// Structure function to retrieve a specific structure; the handle numbers are not required to be
end_comment

begin_comment
comment|/// contiguous. For v2.1 and later, handle values in the range 0FF00h to 0FFFFh are reserved for
end_comment

begin_comment
comment|/// use by this specification.
end_comment

begin_comment
comment|/// If the system configuration changes, a previously assigned handle might no longer exist.
end_comment

begin_comment
comment|/// However once a handle has been assigned by the BIOS, the BIOS cannot re-assign that handle
end_comment

begin_comment
comment|/// number to another structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|SMBIOS_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Smbios Table Entry Point Structure.
end_comment

begin_comment
comment|///
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
name|AnchorString
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|EntryPointStructureChecksum
decl_stmt|;
name|UINT8
name|EntryPointLength
decl_stmt|;
name|UINT8
name|MajorVersion
decl_stmt|;
name|UINT8
name|MinorVersion
decl_stmt|;
name|UINT16
name|MaxStructureSize
decl_stmt|;
name|UINT8
name|EntryPointRevision
decl_stmt|;
name|UINT8
name|FormattedArea
index|[
literal|5
index|]
decl_stmt|;
name|UINT8
name|IntermediateAnchorString
index|[
literal|5
index|]
decl_stmt|;
name|UINT8
name|IntermediateChecksum
decl_stmt|;
name|UINT16
name|TableLength
decl_stmt|;
name|UINT32
name|TableAddress
decl_stmt|;
name|UINT16
name|NumberOfSmbiosStructures
decl_stmt|;
name|UINT8
name|SmbiosBcdRevision
decl_stmt|;
block|}
name|SMBIOS_TABLE_ENTRY_POINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|AnchorString
index|[
literal|5
index|]
decl_stmt|;
name|UINT8
name|EntryPointStructureChecksum
decl_stmt|;
name|UINT8
name|EntryPointLength
decl_stmt|;
name|UINT8
name|MajorVersion
decl_stmt|;
name|UINT8
name|MinorVersion
decl_stmt|;
name|UINT8
name|DocRev
decl_stmt|;
name|UINT8
name|EntryPointRevision
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT32
name|TableMaximumSize
decl_stmt|;
name|UINT64
name|TableAddress
decl_stmt|;
block|}
name|SMBIOS_TABLE_3_0_ENTRY_POINT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Smbios structure header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_TYPE
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|SMBIOS_HANDLE
name|Handle
decl_stmt|;
block|}
name|SMBIOS_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Text strings associated with a given SMBIOS structure are returned in the dmiStrucBuffer, appended directly after
end_comment

begin_comment
comment|/// the formatted portion of the structure. This method of returning string information eliminates the need for
end_comment

begin_comment
comment|/// application software to deal with pointers embedded in the SMBIOS structure. Each string is terminated with a null
end_comment

begin_comment
comment|/// (00h) BYTE and the set of strings is terminated with an additional null (00h) BYTE. When the formatted portion of
end_comment

begin_comment
comment|/// a SMBIOS structure references a string, it does so by specifying a non-zero string number within the structure's
end_comment

begin_comment
comment|/// string-set. For example, if a string field contains 02h, it references the second string following the formatted portion
end_comment

begin_comment
comment|/// of the SMBIOS structure. If a string field references no string, a null (0) is placed in that string field. If the
end_comment

begin_comment
comment|/// formatted portion of the structure contains string-reference fields and all the string fields are set to 0 (no string
end_comment

begin_comment
comment|/// references), the formatted section of the structure is followed by two null (00h) BYTES.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|SMBIOS_TABLE_STRING
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BIOS Characteristics
end_comment

begin_comment
comment|/// Defines which functions the BIOS supports. PCI, PCMCIA, Flash, etc.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Reserved
range|:
literal|2
decl_stmt|;
comment|///< Bits 0-1.
name|UINT32
name|Unknown
range|:
literal|1
decl_stmt|;
name|UINT32
name|BiosCharacteristicsNotSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|IsaIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|McaIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|EisaIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|PciIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|PcmciaIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|PlugAndPlayIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|ApmIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|BiosIsUpgradable
range|:
literal|1
decl_stmt|;
name|UINT32
name|BiosShadowingAllowed
range|:
literal|1
decl_stmt|;
name|UINT32
name|VlVesaIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|EscdSupportIsAvailable
range|:
literal|1
decl_stmt|;
name|UINT32
name|BootFromCdIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|SelectableBootIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|RomBiosIsSocketed
range|:
literal|1
decl_stmt|;
name|UINT32
name|BootFromPcmciaIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|EDDSpecificationIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|JapaneseNecFloppyIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|JapaneseToshibaFloppyIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|Floppy525_360IsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|Floppy525_12IsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|Floppy35_720IsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|Floppy35_288IsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|PrintScreenIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|Keyboard8042IsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|SerialIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|PrinterIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|CgaMonoIsSupported
range|:
literal|1
decl_stmt|;
name|UINT32
name|NecPc98
range|:
literal|1
decl_stmt|;
name|UINT32
name|ReservedForVendor
range|:
literal|32
decl_stmt|;
comment|///< Bits 32-63. Bits 32-47 reserved for BIOS vendor
comment|///< and bits 48-63 reserved for System Vendor.
block|}
name|MISC_BIOS_CHARACTERISTICS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BIOS Characteristics Extension Byte 1.
end_comment

begin_comment
comment|/// This information, available for SMBIOS version 2.1 and later, appears at offset 12h
end_comment

begin_comment
comment|/// within the BIOS Information structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|AcpiIsSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|UsbLegacyIsSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|AgpIsSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|I2OBootIsSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|Ls120BootIsSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|AtapiZipDriveBootIsSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|Boot1394IsSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|SmartBatteryIsSupported
range|:
literal|1
decl_stmt|;
block|}
name|MBCE_BIOS_RESERVED
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BIOS Characteristics Extension Byte 2.
end_comment

begin_comment
comment|/// This information, available for SMBIOS version 2.3 and later, appears at offset 13h
end_comment

begin_comment
comment|/// within the BIOS Information structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|BiosBootSpecIsSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|FunctionKeyNetworkBootIsSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|TargetContentDistributionEnabled
range|:
literal|1
decl_stmt|;
name|UINT8
name|UefiSpecificationSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|VirtualMachineSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|ExtensionByte2Reserved
range|:
literal|3
decl_stmt|;
block|}
name|MBCE_SYSTEM_RESERVED
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BIOS Characteristics Extension Bytes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|MBCE_BIOS_RESERVED
name|BiosReserved
decl_stmt|;
name|MBCE_SYSTEM_RESERVED
name|SystemReserved
decl_stmt|;
block|}
name|MISC_BIOS_CHARACTERISTICS_EXTENSION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended BIOS ROM size.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Size
range|:
literal|14
decl_stmt|;
name|UINT16
name|Unit
range|:
literal|2
decl_stmt|;
block|}
name|EXTENDED_BIOS_ROM_SIZE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BIOS Information (Type 0).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Vendor
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|BiosVersion
decl_stmt|;
name|UINT16
name|BiosSegment
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|BiosReleaseDate
decl_stmt|;
name|UINT8
name|BiosSize
decl_stmt|;
name|MISC_BIOS_CHARACTERISTICS
name|BiosCharacteristics
decl_stmt|;
name|UINT8
name|BIOSCharacteristicsExtensionBytes
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|SystemBiosMajorRelease
decl_stmt|;
name|UINT8
name|SystemBiosMinorRelease
decl_stmt|;
name|UINT8
name|EmbeddedControllerFirmwareMajorRelease
decl_stmt|;
name|UINT8
name|EmbeddedControllerFirmwareMinorRelease
decl_stmt|;
comment|//
comment|// Add for smbios 3.1.0
comment|//
name|EXTENDED_BIOS_ROM_SIZE
name|ExtendedBiosSize
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE0
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|///  System Wake-up Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SystemWakeupTypeReserved
init|=
literal|0x00
block|,
name|SystemWakeupTypeOther
init|=
literal|0x01
block|,
name|SystemWakeupTypeUnknown
init|=
literal|0x02
block|,
name|SystemWakeupTypeApmTimer
init|=
literal|0x03
block|,
name|SystemWakeupTypeModemRing
init|=
literal|0x04
block|,
name|SystemWakeupTypeLanRemote
init|=
literal|0x05
block|,
name|SystemWakeupTypePowerSwitch
init|=
literal|0x06
block|,
name|SystemWakeupTypePciPme
init|=
literal|0x07
block|,
name|SystemWakeupTypeAcPowerRestored
init|=
literal|0x08
block|}
name|MISC_SYSTEM_WAKEUP_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Information (Type 1).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines attributes of the overall system and is
end_comment

begin_comment
comment|/// intended to be associated with the Component ID group of the system's MIF.
end_comment

begin_comment
comment|/// An SMBIOS implementation is associated with a single system instance and contains
end_comment

begin_comment
comment|/// one and only one System Information (Type 1) structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Manufacturer
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|ProductName
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Version
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SerialNumber
decl_stmt|;
name|GUID
name|Uuid
decl_stmt|;
name|UINT8
name|WakeUpType
decl_stmt|;
comment|///< The enumeration value from MISC_SYSTEM_WAKEUP_TYPE.
name|SMBIOS_TABLE_STRING
name|SKUNumber
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Family
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE1
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|///  Base Board - Feature Flags.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Motherboard
range|:
literal|1
decl_stmt|;
name|UINT8
name|RequiresDaughterCard
range|:
literal|1
decl_stmt|;
name|UINT8
name|Removable
range|:
literal|1
decl_stmt|;
name|UINT8
name|Replaceable
range|:
literal|1
decl_stmt|;
name|UINT8
name|HotSwappable
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|3
decl_stmt|;
block|}
name|BASE_BOARD_FEATURE_FLAGS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|///  Base Board - Board Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BaseBoardTypeUnknown
init|=
literal|0x1
block|,
name|BaseBoardTypeOther
init|=
literal|0x2
block|,
name|BaseBoardTypeServerBlade
init|=
literal|0x3
block|,
name|BaseBoardTypeConnectivitySwitch
init|=
literal|0x4
block|,
name|BaseBoardTypeSystemManagementModule
init|=
literal|0x5
block|,
name|BaseBoardTypeProcessorModule
init|=
literal|0x6
block|,
name|BaseBoardTypeIOModule
init|=
literal|0x7
block|,
name|BaseBoardTypeMemoryModule
init|=
literal|0x8
block|,
name|BaseBoardTypeDaughterBoard
init|=
literal|0x9
block|,
name|BaseBoardTypeMotherBoard
init|=
literal|0xA
block|,
name|BaseBoardTypeProcessorMemoryModule
init|=
literal|0xB
block|,
name|BaseBoardTypeProcessorIOModule
init|=
literal|0xC
block|,
name|BaseBoardTypeInterconnectBoard
init|=
literal|0xD
block|}
name|BASE_BOARD_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Base Board (or Module) Information (Type 2).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines attributes of a system baseboard -
end_comment

begin_comment
comment|/// for example a motherboard, planar, or server blade or other standard system module.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Manufacturer
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|ProductName
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Version
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SerialNumber
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|AssetTag
decl_stmt|;
name|BASE_BOARD_FEATURE_FLAGS
name|FeatureFlag
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|LocationInChassis
decl_stmt|;
name|UINT16
name|ChassisHandle
decl_stmt|;
name|UINT8
name|BoardType
decl_stmt|;
comment|///< The enumeration value from BASE_BOARD_TYPE.
name|UINT8
name|NumberOfContainedObjectHandles
decl_stmt|;
name|UINT16
name|ContainedObjectHandles
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Enclosure or Chassis Types
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MiscChassisTypeOther
init|=
literal|0x01
block|,
name|MiscChassisTypeUnknown
init|=
literal|0x02
block|,
name|MiscChassisTypeDeskTop
init|=
literal|0x03
block|,
name|MiscChassisTypeLowProfileDesktop
init|=
literal|0x04
block|,
name|MiscChassisTypePizzaBox
init|=
literal|0x05
block|,
name|MiscChassisTypeMiniTower
init|=
literal|0x06
block|,
name|MiscChassisTypeTower
init|=
literal|0x07
block|,
name|MiscChassisTypePortable
init|=
literal|0x08
block|,
name|MiscChassisTypeLapTop
init|=
literal|0x09
block|,
name|MiscChassisTypeNotebook
init|=
literal|0x0A
block|,
name|MiscChassisTypeHandHeld
init|=
literal|0x0B
block|,
name|MiscChassisTypeDockingStation
init|=
literal|0x0C
block|,
name|MiscChassisTypeAllInOne
init|=
literal|0x0D
block|,
name|MiscChassisTypeSubNotebook
init|=
literal|0x0E
block|,
name|MiscChassisTypeSpaceSaving
init|=
literal|0x0F
block|,
name|MiscChassisTypeLunchBox
init|=
literal|0x10
block|,
name|MiscChassisTypeMainServerChassis
init|=
literal|0x11
block|,
name|MiscChassisTypeExpansionChassis
init|=
literal|0x12
block|,
name|MiscChassisTypeSubChassis
init|=
literal|0x13
block|,
name|MiscChassisTypeBusExpansionChassis
init|=
literal|0x14
block|,
name|MiscChassisTypePeripheralChassis
init|=
literal|0x15
block|,
name|MiscChassisTypeRaidChassis
init|=
literal|0x16
block|,
name|MiscChassisTypeRackMountChassis
init|=
literal|0x17
block|,
name|MiscChassisTypeSealedCasePc
init|=
literal|0x18
block|,
name|MiscChassisMultiSystemChassis
init|=
literal|0x19
block|,
name|MiscChassisCompactPCI
init|=
literal|0x1A
block|,
name|MiscChassisAdvancedTCA
init|=
literal|0x1B
block|,
name|MiscChassisBlade
init|=
literal|0x1C
block|,
name|MiscChassisBladeEnclosure
init|=
literal|0x1D
block|,
name|MiscChassisTablet
init|=
literal|0x1E
block|,
name|MiscChassisConvertible
init|=
literal|0x1F
block|,
name|MiscChassisDetachable
init|=
literal|0x20
block|,
name|MiscChassisIoTGateway
init|=
literal|0x21
block|,
name|MiscChassisEmbeddedPc
init|=
literal|0x22
block|,
name|MiscChassisMiniPc
init|=
literal|0x23
block|,
name|MiscChassisStickPc
init|=
literal|0x24
block|}
name|MISC_CHASSIS_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Enclosure or Chassis States .
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ChassisStateOther
init|=
literal|0x01
block|,
name|ChassisStateUnknown
init|=
literal|0x02
block|,
name|ChassisStateSafe
init|=
literal|0x03
block|,
name|ChassisStateWarning
init|=
literal|0x04
block|,
name|ChassisStateCritical
init|=
literal|0x05
block|,
name|ChassisStateNonRecoverable
init|=
literal|0x06
block|}
name|MISC_CHASSIS_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Enclosure or Chassis Security Status.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ChassisSecurityStatusOther
init|=
literal|0x01
block|,
name|ChassisSecurityStatusUnknown
init|=
literal|0x02
block|,
name|ChassisSecurityStatusNone
init|=
literal|0x03
block|,
name|ChassisSecurityStatusExternalInterfaceLockedOut
init|=
literal|0x04
block|,
name|ChassisSecurityStatusExternalInterfaceLockedEnabled
init|=
literal|0x05
block|}
name|MISC_CHASSIS_SECURITY_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Contained Element record
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ContainedElementType
decl_stmt|;
name|UINT8
name|ContainedElementMinimum
decl_stmt|;
name|UINT8
name|ContainedElementMaximum
decl_stmt|;
block|}
name|CONTAINED_ELEMENT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Enclosure or Chassis (Type 3).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines attributes of the system's mechanical enclosure(s).
end_comment

begin_comment
comment|/// For example, if a system included a separate enclosure for its peripheral devices,
end_comment

begin_comment
comment|/// two structures would be returned: one for the main, system enclosure and the second for
end_comment

begin_comment
comment|/// the peripheral device enclosure.  The additions to this structure in v2.1 of this specification
end_comment

begin_comment
comment|/// support the population of the CIM_Chassis class.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Manufacturer
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Version
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SerialNumber
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|AssetTag
decl_stmt|;
name|UINT8
name|BootupState
decl_stmt|;
comment|///< The enumeration value from MISC_CHASSIS_STATE.
name|UINT8
name|PowerSupplyState
decl_stmt|;
comment|///< The enumeration value from MISC_CHASSIS_STATE.
name|UINT8
name|ThermalState
decl_stmt|;
comment|///< The enumeration value from MISC_CHASSIS_STATE.
name|UINT8
name|SecurityStatus
decl_stmt|;
comment|///< The enumeration value from MISC_CHASSIS_SECURITY_STATE.
name|UINT8
name|OemDefined
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|Height
decl_stmt|;
name|UINT8
name|NumberofPowerCords
decl_stmt|;
name|UINT8
name|ContainedElementCount
decl_stmt|;
name|UINT8
name|ContainedElementRecordLength
decl_stmt|;
comment|//
comment|// Can have 0 to (ContainedElementCount * ContainedElementRecordLength) contained elements
comment|//
name|CONTAINED_ELEMENT
name|ContainedElements
index|[
literal|1
index|]
decl_stmt|;
comment|//
comment|// Add for smbios 2.7
comment|//
comment|// Since ContainedElements has a variable number of entries, must not define SKUNumber in
comment|// the structure.  Need to reference it by starting at offset 0x15 and adding
comment|// (ContainedElementCount * ContainedElementRecordLength) bytes.
comment|//
comment|// SMBIOS_TABLE_STRING         SKUNumber;
block|}
name|SMBIOS_TABLE_TYPE3
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Information - Processor Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ProcessorOther
init|=
literal|0x01
block|,
name|ProcessorUnknown
init|=
literal|0x02
block|,
name|CentralProcessor
init|=
literal|0x03
block|,
name|MathProcessor
init|=
literal|0x04
block|,
name|DspProcessor
init|=
literal|0x05
block|,
name|VideoProcessor
init|=
literal|0x06
block|}
name|PROCESSOR_TYPE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Information - Processor Family.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ProcessorFamilyOther
init|=
literal|0x01
block|,
name|ProcessorFamilyUnknown
init|=
literal|0x02
block|,
name|ProcessorFamily8086
init|=
literal|0x03
block|,
name|ProcessorFamily80286
init|=
literal|0x04
block|,
name|ProcessorFamilyIntel386
init|=
literal|0x05
block|,
name|ProcessorFamilyIntel486
init|=
literal|0x06
block|,
name|ProcessorFamily8087
init|=
literal|0x07
block|,
name|ProcessorFamily80287
init|=
literal|0x08
block|,
name|ProcessorFamily80387
init|=
literal|0x09
block|,
name|ProcessorFamily80487
init|=
literal|0x0A
block|,
name|ProcessorFamilyPentium
init|=
literal|0x0B
block|,
name|ProcessorFamilyPentiumPro
init|=
literal|0x0C
block|,
name|ProcessorFamilyPentiumII
init|=
literal|0x0D
block|,
name|ProcessorFamilyPentiumMMX
init|=
literal|0x0E
block|,
name|ProcessorFamilyCeleron
init|=
literal|0x0F
block|,
name|ProcessorFamilyPentiumIIXeon
init|=
literal|0x10
block|,
name|ProcessorFamilyPentiumIII
init|=
literal|0x11
block|,
name|ProcessorFamilyM1
init|=
literal|0x12
block|,
name|ProcessorFamilyM2
init|=
literal|0x13
block|,
name|ProcessorFamilyIntelCeleronM
init|=
literal|0x14
block|,
name|ProcessorFamilyIntelPentium4Ht
init|=
literal|0x15
block|,
name|ProcessorFamilyAmdDuron
init|=
literal|0x18
block|,
name|ProcessorFamilyK5
init|=
literal|0x19
block|,
name|ProcessorFamilyK6
init|=
literal|0x1A
block|,
name|ProcessorFamilyK6_2
init|=
literal|0x1B
block|,
name|ProcessorFamilyK6_3
init|=
literal|0x1C
block|,
name|ProcessorFamilyAmdAthlon
init|=
literal|0x1D
block|,
name|ProcessorFamilyAmd29000
init|=
literal|0x1E
block|,
name|ProcessorFamilyK6_2Plus
init|=
literal|0x1F
block|,
name|ProcessorFamilyPowerPC
init|=
literal|0x20
block|,
name|ProcessorFamilyPowerPC601
init|=
literal|0x21
block|,
name|ProcessorFamilyPowerPC603
init|=
literal|0x22
block|,
name|ProcessorFamilyPowerPC603Plus
init|=
literal|0x23
block|,
name|ProcessorFamilyPowerPC604
init|=
literal|0x24
block|,
name|ProcessorFamilyPowerPC620
init|=
literal|0x25
block|,
name|ProcessorFamilyPowerPCx704
init|=
literal|0x26
block|,
name|ProcessorFamilyPowerPC750
init|=
literal|0x27
block|,
name|ProcessorFamilyIntelCoreDuo
init|=
literal|0x28
block|,
name|ProcessorFamilyIntelCoreDuoMobile
init|=
literal|0x29
block|,
name|ProcessorFamilyIntelCoreSoloMobile
init|=
literal|0x2A
block|,
name|ProcessorFamilyIntelAtom
init|=
literal|0x2B
block|,
name|ProcessorFamilyIntelCoreM
init|=
literal|0x2C
block|,
name|ProcessorFamilyIntelCorem3
init|=
literal|0x2D
block|,
name|ProcessorFamilyIntelCorem5
init|=
literal|0x2E
block|,
name|ProcessorFamilyIntelCorem7
init|=
literal|0x2F
block|,
name|ProcessorFamilyAlpha
init|=
literal|0x30
block|,
name|ProcessorFamilyAlpha21064
init|=
literal|0x31
block|,
name|ProcessorFamilyAlpha21066
init|=
literal|0x32
block|,
name|ProcessorFamilyAlpha21164
init|=
literal|0x33
block|,
name|ProcessorFamilyAlpha21164PC
init|=
literal|0x34
block|,
name|ProcessorFamilyAlpha21164a
init|=
literal|0x35
block|,
name|ProcessorFamilyAlpha21264
init|=
literal|0x36
block|,
name|ProcessorFamilyAlpha21364
init|=
literal|0x37
block|,
name|ProcessorFamilyAmdTurionIIUltraDualCoreMobileM
init|=
literal|0x38
block|,
name|ProcessorFamilyAmdTurionIIDualCoreMobileM
init|=
literal|0x39
block|,
name|ProcessorFamilyAmdAthlonIIDualCoreM
init|=
literal|0x3A
block|,
name|ProcessorFamilyAmdOpteron6100Series
init|=
literal|0x3B
block|,
name|ProcessorFamilyAmdOpteron4100Series
init|=
literal|0x3C
block|,
name|ProcessorFamilyAmdOpteron6200Series
init|=
literal|0x3D
block|,
name|ProcessorFamilyAmdOpteron4200Series
init|=
literal|0x3E
block|,
name|ProcessorFamilyAmdFxSeries
init|=
literal|0x3F
block|,
name|ProcessorFamilyMips
init|=
literal|0x40
block|,
name|ProcessorFamilyMIPSR4000
init|=
literal|0x41
block|,
name|ProcessorFamilyMIPSR4200
init|=
literal|0x42
block|,
name|ProcessorFamilyMIPSR4400
init|=
literal|0x43
block|,
name|ProcessorFamilyMIPSR4600
init|=
literal|0x44
block|,
name|ProcessorFamilyMIPSR10000
init|=
literal|0x45
block|,
name|ProcessorFamilyAmdCSeries
init|=
literal|0x46
block|,
name|ProcessorFamilyAmdESeries
init|=
literal|0x47
block|,
name|ProcessorFamilyAmdASeries
init|=
literal|0x48
block|,
comment|///< SMBIOS spec 2.8.0 updated the name
name|ProcessorFamilyAmdGSeries
init|=
literal|0x49
block|,
name|ProcessorFamilyAmdZSeries
init|=
literal|0x4A
block|,
name|ProcessorFamilyAmdRSeries
init|=
literal|0x4B
block|,
name|ProcessorFamilyAmdOpteron4300
init|=
literal|0x4C
block|,
name|ProcessorFamilyAmdOpteron6300
init|=
literal|0x4D
block|,
name|ProcessorFamilyAmdOpteron3300
init|=
literal|0x4E
block|,
name|ProcessorFamilyAmdFireProSeries
init|=
literal|0x4F
block|,
name|ProcessorFamilySparc
init|=
literal|0x50
block|,
name|ProcessorFamilySuperSparc
init|=
literal|0x51
block|,
name|ProcessorFamilymicroSparcII
init|=
literal|0x52
block|,
name|ProcessorFamilymicroSparcIIep
init|=
literal|0x53
block|,
name|ProcessorFamilyUltraSparc
init|=
literal|0x54
block|,
name|ProcessorFamilyUltraSparcII
init|=
literal|0x55
block|,
name|ProcessorFamilyUltraSparcIii
init|=
literal|0x56
block|,
name|ProcessorFamilyUltraSparcIII
init|=
literal|0x57
block|,
name|ProcessorFamilyUltraSparcIIIi
init|=
literal|0x58
block|,
name|ProcessorFamily68040
init|=
literal|0x60
block|,
name|ProcessorFamily68xxx
init|=
literal|0x61
block|,
name|ProcessorFamily68000
init|=
literal|0x62
block|,
name|ProcessorFamily68010
init|=
literal|0x63
block|,
name|ProcessorFamily68020
init|=
literal|0x64
block|,
name|ProcessorFamily68030
init|=
literal|0x65
block|,
name|ProcessorFamilyAmdAthlonX4QuadCore
init|=
literal|0x66
block|,
name|ProcessorFamilyAmdOpteronX1000Series
init|=
literal|0x67
block|,
name|ProcessorFamilyAmdOpteronX2000Series
init|=
literal|0x68
block|,
name|ProcessorFamilyAmdOpteronASeries
init|=
literal|0x69
block|,
name|ProcessorFamilyAmdOpteronX3000Series
init|=
literal|0x6A
block|,
name|ProcessorFamilyAmdZen
init|=
literal|0x6B
block|,
name|ProcessorFamilyHobbit
init|=
literal|0x70
block|,
name|ProcessorFamilyCrusoeTM5000
init|=
literal|0x78
block|,
name|ProcessorFamilyCrusoeTM3000
init|=
literal|0x79
block|,
name|ProcessorFamilyEfficeonTM8000
init|=
literal|0x7A
block|,
name|ProcessorFamilyWeitek
init|=
literal|0x80
block|,
name|ProcessorFamilyItanium
init|=
literal|0x82
block|,
name|ProcessorFamilyAmdAthlon64
init|=
literal|0x83
block|,
name|ProcessorFamilyAmdOpteron
init|=
literal|0x84
block|,
name|ProcessorFamilyAmdSempron
init|=
literal|0x85
block|,
name|ProcessorFamilyAmdTurion64Mobile
init|=
literal|0x86
block|,
name|ProcessorFamilyDualCoreAmdOpteron
init|=
literal|0x87
block|,
name|ProcessorFamilyAmdAthlon64X2DualCore
init|=
literal|0x88
block|,
name|ProcessorFamilyAmdTurion64X2Mobile
init|=
literal|0x89
block|,
name|ProcessorFamilyQuadCoreAmdOpteron
init|=
literal|0x8A
block|,
name|ProcessorFamilyThirdGenerationAmdOpteron
init|=
literal|0x8B
block|,
name|ProcessorFamilyAmdPhenomFxQuadCore
init|=
literal|0x8C
block|,
name|ProcessorFamilyAmdPhenomX4QuadCore
init|=
literal|0x8D
block|,
name|ProcessorFamilyAmdPhenomX2DualCore
init|=
literal|0x8E
block|,
name|ProcessorFamilyAmdAthlonX2DualCore
init|=
literal|0x8F
block|,
name|ProcessorFamilyPARISC
init|=
literal|0x90
block|,
name|ProcessorFamilyPaRisc8500
init|=
literal|0x91
block|,
name|ProcessorFamilyPaRisc8000
init|=
literal|0x92
block|,
name|ProcessorFamilyPaRisc7300LC
init|=
literal|0x93
block|,
name|ProcessorFamilyPaRisc7200
init|=
literal|0x94
block|,
name|ProcessorFamilyPaRisc7100LC
init|=
literal|0x95
block|,
name|ProcessorFamilyPaRisc7100
init|=
literal|0x96
block|,
name|ProcessorFamilyV30
init|=
literal|0xA0
block|,
name|ProcessorFamilyQuadCoreIntelXeon3200Series
init|=
literal|0xA1
block|,
name|ProcessorFamilyDualCoreIntelXeon3000Series
init|=
literal|0xA2
block|,
name|ProcessorFamilyQuadCoreIntelXeon5300Series
init|=
literal|0xA3
block|,
name|ProcessorFamilyDualCoreIntelXeon5100Series
init|=
literal|0xA4
block|,
name|ProcessorFamilyDualCoreIntelXeon5000Series
init|=
literal|0xA5
block|,
name|ProcessorFamilyDualCoreIntelXeonLV
init|=
literal|0xA6
block|,
name|ProcessorFamilyDualCoreIntelXeonULV
init|=
literal|0xA7
block|,
name|ProcessorFamilyDualCoreIntelXeon7100Series
init|=
literal|0xA8
block|,
name|ProcessorFamilyQuadCoreIntelXeon5400Series
init|=
literal|0xA9
block|,
name|ProcessorFamilyQuadCoreIntelXeon
init|=
literal|0xAA
block|,
name|ProcessorFamilyDualCoreIntelXeon5200Series
init|=
literal|0xAB
block|,
name|ProcessorFamilyDualCoreIntelXeon7200Series
init|=
literal|0xAC
block|,
name|ProcessorFamilyQuadCoreIntelXeon7300Series
init|=
literal|0xAD
block|,
name|ProcessorFamilyQuadCoreIntelXeon7400Series
init|=
literal|0xAE
block|,
name|ProcessorFamilyMultiCoreIntelXeon7400Series
init|=
literal|0xAF
block|,
name|ProcessorFamilyPentiumIIIXeon
init|=
literal|0xB0
block|,
name|ProcessorFamilyPentiumIIISpeedStep
init|=
literal|0xB1
block|,
name|ProcessorFamilyPentium4
init|=
literal|0xB2
block|,
name|ProcessorFamilyIntelXeon
init|=
literal|0xB3
block|,
name|ProcessorFamilyAS400
init|=
literal|0xB4
block|,
name|ProcessorFamilyIntelXeonMP
init|=
literal|0xB5
block|,
name|ProcessorFamilyAMDAthlonXP
init|=
literal|0xB6
block|,
name|ProcessorFamilyAMDAthlonMP
init|=
literal|0xB7
block|,
name|ProcessorFamilyIntelItanium2
init|=
literal|0xB8
block|,
name|ProcessorFamilyIntelPentiumM
init|=
literal|0xB9
block|,
name|ProcessorFamilyIntelCeleronD
init|=
literal|0xBA
block|,
name|ProcessorFamilyIntelPentiumD
init|=
literal|0xBB
block|,
name|ProcessorFamilyIntelPentiumEx
init|=
literal|0xBC
block|,
name|ProcessorFamilyIntelCoreSolo
init|=
literal|0xBD
block|,
comment|///< SMBIOS spec 2.6 updated this value
name|ProcessorFamilyReserved
init|=
literal|0xBE
block|,
name|ProcessorFamilyIntelCore2
init|=
literal|0xBF
block|,
name|ProcessorFamilyIntelCore2Solo
init|=
literal|0xC0
block|,
name|ProcessorFamilyIntelCore2Extreme
init|=
literal|0xC1
block|,
name|ProcessorFamilyIntelCore2Quad
init|=
literal|0xC2
block|,
name|ProcessorFamilyIntelCore2ExtremeMobile
init|=
literal|0xC3
block|,
name|ProcessorFamilyIntelCore2DuoMobile
init|=
literal|0xC4
block|,
name|ProcessorFamilyIntelCore2SoloMobile
init|=
literal|0xC5
block|,
name|ProcessorFamilyIntelCoreI7
init|=
literal|0xC6
block|,
name|ProcessorFamilyDualCoreIntelCeleron
init|=
literal|0xC7
block|,
name|ProcessorFamilyIBM390
init|=
literal|0xC8
block|,
name|ProcessorFamilyG4
init|=
literal|0xC9
block|,
name|ProcessorFamilyG5
init|=
literal|0xCA
block|,
name|ProcessorFamilyG6
init|=
literal|0xCB
block|,
name|ProcessorFamilyzArchitecture
init|=
literal|0xCC
block|,
name|ProcessorFamilyIntelCoreI5
init|=
literal|0xCD
block|,
name|ProcessorFamilyIntelCoreI3
init|=
literal|0xCE
block|,
name|ProcessorFamilyViaC7M
init|=
literal|0xD2
block|,
name|ProcessorFamilyViaC7D
init|=
literal|0xD3
block|,
name|ProcessorFamilyViaC7
init|=
literal|0xD4
block|,
name|ProcessorFamilyViaEden
init|=
literal|0xD5
block|,
name|ProcessorFamilyMultiCoreIntelXeon
init|=
literal|0xD6
block|,
name|ProcessorFamilyDualCoreIntelXeon3Series
init|=
literal|0xD7
block|,
name|ProcessorFamilyQuadCoreIntelXeon3Series
init|=
literal|0xD8
block|,
name|ProcessorFamilyViaNano
init|=
literal|0xD9
block|,
name|ProcessorFamilyDualCoreIntelXeon5Series
init|=
literal|0xDA
block|,
name|ProcessorFamilyQuadCoreIntelXeon5Series
init|=
literal|0xDB
block|,
name|ProcessorFamilyDualCoreIntelXeon7Series
init|=
literal|0xDD
block|,
name|ProcessorFamilyQuadCoreIntelXeon7Series
init|=
literal|0xDE
block|,
name|ProcessorFamilyMultiCoreIntelXeon7Series
init|=
literal|0xDF
block|,
name|ProcessorFamilyMultiCoreIntelXeon3400Series
init|=
literal|0xE0
block|,
name|ProcessorFamilyAmdOpteron3000Series
init|=
literal|0xE4
block|,
name|ProcessorFamilyAmdSempronII
init|=
literal|0xE5
block|,
name|ProcessorFamilyEmbeddedAmdOpteronQuadCore
init|=
literal|0xE6
block|,
name|ProcessorFamilyAmdPhenomTripleCore
init|=
literal|0xE7
block|,
name|ProcessorFamilyAmdTurionUltraDualCoreMobile
init|=
literal|0xE8
block|,
name|ProcessorFamilyAmdTurionDualCoreMobile
init|=
literal|0xE9
block|,
name|ProcessorFamilyAmdAthlonDualCore
init|=
literal|0xEA
block|,
name|ProcessorFamilyAmdSempronSI
init|=
literal|0xEB
block|,
name|ProcessorFamilyAmdPhenomII
init|=
literal|0xEC
block|,
name|ProcessorFamilyAmdAthlonII
init|=
literal|0xED
block|,
name|ProcessorFamilySixCoreAmdOpteron
init|=
literal|0xEE
block|,
name|ProcessorFamilyAmdSempronM
init|=
literal|0xEF
block|,
name|ProcessorFamilyi860
init|=
literal|0xFA
block|,
name|ProcessorFamilyi960
init|=
literal|0xFB
block|,
name|ProcessorFamilyIndicatorFamily2
init|=
literal|0xFE
block|,
name|ProcessorFamilyReserved1
init|=
literal|0xFF
block|}
name|PROCESSOR_FAMILY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Information2 - Processor Family2.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ProcessorFamilyARMv7
init|=
literal|0x0100
block|,
name|ProcessorFamilyARMv8
init|=
literal|0x0101
block|,
name|ProcessorFamilySH3
init|=
literal|0x0104
block|,
name|ProcessorFamilySH4
init|=
literal|0x0105
block|,
name|ProcessorFamilyARM
init|=
literal|0x0118
block|,
name|ProcessorFamilyStrongARM
init|=
literal|0x0119
block|,
name|ProcessorFamily6x86
init|=
literal|0x012C
block|,
name|ProcessorFamilyMediaGX
init|=
literal|0x012D
block|,
name|ProcessorFamilyMII
init|=
literal|0x012E
block|,
name|ProcessorFamilyWinChip
init|=
literal|0x0140
block|,
name|ProcessorFamilyDSP
init|=
literal|0x015E
block|,
name|ProcessorFamilyVideoProcessor
init|=
literal|0x01F4
block|}
name|PROCESSOR_FAMILY2_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Information - Voltage.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ProcessorVoltageCapability5V
range|:
literal|1
decl_stmt|;
name|UINT8
name|ProcessorVoltageCapability3_3V
range|:
literal|1
decl_stmt|;
name|UINT8
name|ProcessorVoltageCapability2_9V
range|:
literal|1
decl_stmt|;
name|UINT8
name|ProcessorVoltageCapabilityReserved
range|:
literal|1
decl_stmt|;
comment|///< Bit 3, must be zero.
name|UINT8
name|ProcessorVoltageReserved
range|:
literal|3
decl_stmt|;
comment|///< Bits 4-6, must be zero.
name|UINT8
name|ProcessorVoltageIndicateLegacy
range|:
literal|1
decl_stmt|;
block|}
name|PROCESSOR_VOLTAGE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Information - Processor Upgrade.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ProcessorUpgradeOther
init|=
literal|0x01
block|,
name|ProcessorUpgradeUnknown
init|=
literal|0x02
block|,
name|ProcessorUpgradeDaughterBoard
init|=
literal|0x03
block|,
name|ProcessorUpgradeZIFSocket
init|=
literal|0x04
block|,
name|ProcessorUpgradePiggyBack
init|=
literal|0x05
block|,
comment|///< Replaceable.
name|ProcessorUpgradeNone
init|=
literal|0x06
block|,
name|ProcessorUpgradeLIFSocket
init|=
literal|0x07
block|,
name|ProcessorUpgradeSlot1
init|=
literal|0x08
block|,
name|ProcessorUpgradeSlot2
init|=
literal|0x09
block|,
name|ProcessorUpgrade370PinSocket
init|=
literal|0x0A
block|,
name|ProcessorUpgradeSlotA
init|=
literal|0x0B
block|,
name|ProcessorUpgradeSlotM
init|=
literal|0x0C
block|,
name|ProcessorUpgradeSocket423
init|=
literal|0x0D
block|,
name|ProcessorUpgradeSocketA
init|=
literal|0x0E
block|,
comment|///< Socket 462.
name|ProcessorUpgradeSocket478
init|=
literal|0x0F
block|,
name|ProcessorUpgradeSocket754
init|=
literal|0x10
block|,
name|ProcessorUpgradeSocket940
init|=
literal|0x11
block|,
name|ProcessorUpgradeSocket939
init|=
literal|0x12
block|,
name|ProcessorUpgradeSocketmPGA604
init|=
literal|0x13
block|,
name|ProcessorUpgradeSocketLGA771
init|=
literal|0x14
block|,
name|ProcessorUpgradeSocketLGA775
init|=
literal|0x15
block|,
name|ProcessorUpgradeSocketS1
init|=
literal|0x16
block|,
name|ProcessorUpgradeAM2
init|=
literal|0x17
block|,
name|ProcessorUpgradeF1207
init|=
literal|0x18
block|,
name|ProcessorSocketLGA1366
init|=
literal|0x19
block|,
name|ProcessorUpgradeSocketG34
init|=
literal|0x1A
block|,
name|ProcessorUpgradeSocketAM3
init|=
literal|0x1B
block|,
name|ProcessorUpgradeSocketC32
init|=
literal|0x1C
block|,
name|ProcessorUpgradeSocketLGA1156
init|=
literal|0x1D
block|,
name|ProcessorUpgradeSocketLGA1567
init|=
literal|0x1E
block|,
name|ProcessorUpgradeSocketPGA988A
init|=
literal|0x1F
block|,
name|ProcessorUpgradeSocketBGA1288
init|=
literal|0x20
block|,
name|ProcessorUpgradeSocketrPGA988B
init|=
literal|0x21
block|,
name|ProcessorUpgradeSocketBGA1023
init|=
literal|0x22
block|,
name|ProcessorUpgradeSocketBGA1224
init|=
literal|0x23
block|,
name|ProcessorUpgradeSocketLGA1155
init|=
literal|0x24
block|,
comment|///< SMBIOS spec 2.8.0 updated the name
name|ProcessorUpgradeSocketLGA1356
init|=
literal|0x25
block|,
name|ProcessorUpgradeSocketLGA2011
init|=
literal|0x26
block|,
name|ProcessorUpgradeSocketFS1
init|=
literal|0x27
block|,
name|ProcessorUpgradeSocketFS2
init|=
literal|0x28
block|,
name|ProcessorUpgradeSocketFM1
init|=
literal|0x29
block|,
name|ProcessorUpgradeSocketFM2
init|=
literal|0x2A
block|,
name|ProcessorUpgradeSocketLGA2011_3
init|=
literal|0x2B
block|,
name|ProcessorUpgradeSocketLGA1356_3
init|=
literal|0x2C
block|,
name|ProcessorUpgradeSocketLGA1150
init|=
literal|0x2D
block|,
name|ProcessorUpgradeSocketBGA1168
init|=
literal|0x2E
block|,
name|ProcessorUpgradeSocketBGA1234
init|=
literal|0x2F
block|,
name|ProcessorUpgradeSocketBGA1364
init|=
literal|0x30
block|,
name|ProcessorUpgradeSocketAM4
init|=
literal|0x31
block|,
name|ProcessorUpgradeSocketLGA1151
init|=
literal|0x32
block|,
name|ProcessorUpgradeSocketBGA1356
init|=
literal|0x33
block|,
name|ProcessorUpgradeSocketBGA1440
init|=
literal|0x34
block|,
name|ProcessorUpgradeSocketBGA1515
init|=
literal|0x35
block|,
name|ProcessorUpgradeSocketLGA3647_1
init|=
literal|0x36
block|,
name|ProcessorUpgradeSocketSP3
init|=
literal|0x37
block|,
name|ProcessorUpgradeSocketSP3r2
init|=
literal|0x38
block|}
name|PROCESSOR_UPGRADE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor ID Field Description
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ProcessorSteppingId
range|:
literal|4
decl_stmt|;
name|UINT32
name|ProcessorModel
range|:
literal|4
decl_stmt|;
name|UINT32
name|ProcessorFamily
range|:
literal|4
decl_stmt|;
name|UINT32
name|ProcessorType
range|:
literal|2
decl_stmt|;
name|UINT32
name|ProcessorReserved1
range|:
literal|2
decl_stmt|;
name|UINT32
name|ProcessorXModel
range|:
literal|4
decl_stmt|;
name|UINT32
name|ProcessorXFamily
range|:
literal|8
decl_stmt|;
name|UINT32
name|ProcessorReserved2
range|:
literal|4
decl_stmt|;
block|}
name|PROCESSOR_SIGNATURE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ProcessorFpu
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorVme
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorDe
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorPse
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorTsc
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorMsr
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorPae
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorMce
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorCx8
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorApic
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorReserved1
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorSep
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorMtrr
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorPge
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorMca
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorCmov
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorPat
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorPse36
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorPsn
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorClfsh
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorReserved2
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorDs
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorAcpi
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorMmx
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorFxsr
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorSse
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorSse2
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorSs
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorReserved3
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorTm
range|:
literal|1
decl_stmt|;
name|UINT32
name|ProcessorReserved4
range|:
literal|2
decl_stmt|;
block|}
name|PROCESSOR_FEATURE_FLAGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PROCESSOR_SIGNATURE
name|Signature
decl_stmt|;
name|PROCESSOR_FEATURE_FLAGS
name|FeatureFlags
decl_stmt|;
block|}
name|PROCESSOR_ID_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Information (Type 4).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of a single processor;
end_comment

begin_comment
comment|/// a separate structure instance is provided for each system processor socket/slot.
end_comment

begin_comment
comment|/// For example, a system with an IntelDX2 processor would have a single
end_comment

begin_comment
comment|/// structure instance, while a system with an IntelSX2 processor would have a structure
end_comment

begin_comment
comment|/// to describe the main CPU, and a second structure to describe the 80487 co-processor.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Socket
decl_stmt|;
name|UINT8
name|ProcessorType
decl_stmt|;
comment|///< The enumeration value from PROCESSOR_TYPE_DATA.
name|UINT8
name|ProcessorFamily
decl_stmt|;
comment|///< The enumeration value from PROCESSOR_FAMILY_DATA.
name|SMBIOS_TABLE_STRING
name|ProcessorManufacture
decl_stmt|;
name|PROCESSOR_ID_DATA
name|ProcessorId
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|ProcessorVersion
decl_stmt|;
name|PROCESSOR_VOLTAGE
name|Voltage
decl_stmt|;
name|UINT16
name|ExternalClock
decl_stmt|;
name|UINT16
name|MaxSpeed
decl_stmt|;
name|UINT16
name|CurrentSpeed
decl_stmt|;
name|UINT8
name|Status
decl_stmt|;
name|UINT8
name|ProcessorUpgrade
decl_stmt|;
comment|///< The enumeration value from PROCESSOR_UPGRADE.
name|UINT16
name|L1CacheHandle
decl_stmt|;
name|UINT16
name|L2CacheHandle
decl_stmt|;
name|UINT16
name|L3CacheHandle
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SerialNumber
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|AssetTag
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|PartNumber
decl_stmt|;
comment|//
comment|// Add for smbios 2.5
comment|//
name|UINT8
name|CoreCount
decl_stmt|;
name|UINT8
name|EnabledCoreCount
decl_stmt|;
name|UINT8
name|ThreadCount
decl_stmt|;
name|UINT16
name|ProcessorCharacteristics
decl_stmt|;
comment|//
comment|// Add for smbios 2.6
comment|//
name|UINT16
name|ProcessorFamily2
decl_stmt|;
comment|//
comment|// Add for smbios 3.0
comment|//
name|UINT16
name|CoreCount2
decl_stmt|;
name|UINT16
name|EnabledCoreCount2
decl_stmt|;
name|UINT16
name|ThreadCount2
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE4
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Controller Error Detecting Method.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ErrorDetectingMethodOther
init|=
literal|0x01
block|,
name|ErrorDetectingMethodUnknown
init|=
literal|0x02
block|,
name|ErrorDetectingMethodNone
init|=
literal|0x03
block|,
name|ErrorDetectingMethodParity
init|=
literal|0x04
block|,
name|ErrorDetectingMethod32Ecc
init|=
literal|0x05
block|,
name|ErrorDetectingMethod64Ecc
init|=
literal|0x06
block|,
name|ErrorDetectingMethod128Ecc
init|=
literal|0x07
block|,
name|ErrorDetectingMethodCrc
init|=
literal|0x08
block|}
name|MEMORY_ERROR_DETECT_METHOD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Controller Error Correcting Capability.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Other
range|:
literal|1
decl_stmt|;
name|UINT8
name|Unknown
range|:
literal|1
decl_stmt|;
name|UINT8
name|None
range|:
literal|1
decl_stmt|;
name|UINT8
name|SingleBitErrorCorrect
range|:
literal|1
decl_stmt|;
name|UINT8
name|DoubleBitErrorCorrect
range|:
literal|1
decl_stmt|;
name|UINT8
name|ErrorScrubbing
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|2
decl_stmt|;
block|}
name|MEMORY_ERROR_CORRECT_CAPABILITY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Controller Information - Interleave Support.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryInterleaveOther
init|=
literal|0x01
block|,
name|MemoryInterleaveUnknown
init|=
literal|0x02
block|,
name|MemoryInterleaveOneWay
init|=
literal|0x03
block|,
name|MemoryInterleaveTwoWay
init|=
literal|0x04
block|,
name|MemoryInterleaveFourWay
init|=
literal|0x05
block|,
name|MemoryInterleaveEightWay
init|=
literal|0x06
block|,
name|MemoryInterleaveSixteenWay
init|=
literal|0x07
block|}
name|MEMORY_SUPPORT_INTERLEAVE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Controller Information - Memory Speeds.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Other
range|:
literal|1
decl_stmt|;
name|UINT16
name|Unknown
range|:
literal|1
decl_stmt|;
name|UINT16
name|SeventyNs
range|:
literal|1
decl_stmt|;
name|UINT16
name|SixtyNs
range|:
literal|1
decl_stmt|;
name|UINT16
name|FiftyNs
range|:
literal|1
decl_stmt|;
name|UINT16
name|Reserved
range|:
literal|11
decl_stmt|;
block|}
name|MEMORY_SPEED_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Controller Information (Type 5, Obsolete).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of the system's memory controller(s)
end_comment

begin_comment
comment|/// and the supported attributes of any memory-modules present in the sockets controlled by
end_comment

begin_comment
comment|/// this controller.
end_comment

begin_comment
comment|/// Note: This structure, and its companion Memory Module Information (Type 6, Obsolete),
end_comment

begin_comment
comment|/// are obsolete starting with version 2.1 of this specification. The Physical Memory Array (Type 16)
end_comment

begin_comment
comment|/// and Memory Device (Type 17) structures should be used instead.  BIOS providers might
end_comment

begin_comment
comment|/// choose to implement both memory description types to allow existing DMI browsers
end_comment

begin_comment
comment|/// to properly display the system's memory attributes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|ErrDetectMethod
decl_stmt|;
comment|///< The enumeration value from MEMORY_ERROR_DETECT_METHOD.
name|MEMORY_ERROR_CORRECT_CAPABILITY
name|ErrCorrectCapability
decl_stmt|;
name|UINT8
name|SupportInterleave
decl_stmt|;
comment|///< The enumeration value from MEMORY_SUPPORT_INTERLEAVE_TYPE.
name|UINT8
name|CurrentInterleave
decl_stmt|;
comment|///< The enumeration value from MEMORY_SUPPORT_INTERLEAVE_TYPE .
name|UINT8
name|MaxMemoryModuleSize
decl_stmt|;
name|MEMORY_SPEED_TYPE
name|SupportSpeed
decl_stmt|;
name|UINT16
name|SupportMemoryType
decl_stmt|;
name|UINT8
name|MemoryModuleVoltage
decl_stmt|;
name|UINT8
name|AssociatedMemorySlotNum
decl_stmt|;
name|UINT16
name|MemoryModuleConfigHandles
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE5
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Module Information - Memory Types
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Other
range|:
literal|1
decl_stmt|;
name|UINT16
name|Unknown
range|:
literal|1
decl_stmt|;
name|UINT16
name|Standard
range|:
literal|1
decl_stmt|;
name|UINT16
name|FastPageMode
range|:
literal|1
decl_stmt|;
name|UINT16
name|Edo
range|:
literal|1
decl_stmt|;
name|UINT16
name|Parity
range|:
literal|1
decl_stmt|;
name|UINT16
name|Ecc
range|:
literal|1
decl_stmt|;
name|UINT16
name|Simm
range|:
literal|1
decl_stmt|;
name|UINT16
name|Dimm
range|:
literal|1
decl_stmt|;
name|UINT16
name|BurstEdo
range|:
literal|1
decl_stmt|;
name|UINT16
name|Sdram
range|:
literal|1
decl_stmt|;
name|UINT16
name|Reserved
range|:
literal|5
decl_stmt|;
block|}
name|MEMORY_CURRENT_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Module Information - Memory Size.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|InstalledOrEnabledSize
range|:
literal|7
decl_stmt|;
comment|///< Size (n), where 2**n is the size in MB.
name|UINT8
name|SingleOrDoubleBank
range|:
literal|1
decl_stmt|;
block|}
name|MEMORY_INSTALLED_ENABLED_SIZE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Module Information (Type 6, Obsolete)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// One Memory Module Information structure is included for each memory-module socket
end_comment

begin_comment
comment|/// in the system.  The structure describes the speed, type, size, and error status
end_comment

begin_comment
comment|/// of each system memory module.  The supported attributes of each module are described
end_comment

begin_comment
comment|/// by the "owning" Memory Controller Information structure.
end_comment

begin_comment
comment|/// Note:  This structure, and its companion Memory Controller Information (Type 5, Obsolete),
end_comment

begin_comment
comment|/// are obsolete starting with version 2.1 of this specification. The Physical Memory Array (Type 16)
end_comment

begin_comment
comment|/// and Memory Device (Type 17) structures should be used instead.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SocketDesignation
decl_stmt|;
name|UINT8
name|BankConnections
decl_stmt|;
name|UINT8
name|CurrentSpeed
decl_stmt|;
name|MEMORY_CURRENT_TYPE
name|CurrentMemoryType
decl_stmt|;
name|MEMORY_INSTALLED_ENABLED_SIZE
name|InstalledSize
decl_stmt|;
name|MEMORY_INSTALLED_ENABLED_SIZE
name|EnabledSize
decl_stmt|;
name|UINT8
name|ErrorStatus
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE6
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache Information - SRAM Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Other
range|:
literal|1
decl_stmt|;
name|UINT16
name|Unknown
range|:
literal|1
decl_stmt|;
name|UINT16
name|NonBurst
range|:
literal|1
decl_stmt|;
name|UINT16
name|Burst
range|:
literal|1
decl_stmt|;
name|UINT16
name|PipelineBurst
range|:
literal|1
decl_stmt|;
name|UINT16
name|Synchronous
range|:
literal|1
decl_stmt|;
name|UINT16
name|Asynchronous
range|:
literal|1
decl_stmt|;
name|UINT16
name|Reserved
range|:
literal|9
decl_stmt|;
block|}
name|CACHE_SRAM_TYPE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache Information - Error Correction Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CacheErrorOther
init|=
literal|0x01
block|,
name|CacheErrorUnknown
init|=
literal|0x02
block|,
name|CacheErrorNone
init|=
literal|0x03
block|,
name|CacheErrorParity
init|=
literal|0x04
block|,
name|CacheErrorSingleBit
init|=
literal|0x05
block|,
comment|///< ECC
name|CacheErrorMultiBit
init|=
literal|0x06
comment|///< ECC
block|}
name|CACHE_ERROR_TYPE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache Information - System Cache Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CacheTypeOther
init|=
literal|0x01
block|,
name|CacheTypeUnknown
init|=
literal|0x02
block|,
name|CacheTypeInstruction
init|=
literal|0x03
block|,
name|CacheTypeData
init|=
literal|0x04
block|,
name|CacheTypeUnified
init|=
literal|0x05
block|}
name|CACHE_TYPE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache Information - Associativity.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CacheAssociativityOther
init|=
literal|0x01
block|,
name|CacheAssociativityUnknown
init|=
literal|0x02
block|,
name|CacheAssociativityDirectMapped
init|=
literal|0x03
block|,
name|CacheAssociativity2Way
init|=
literal|0x04
block|,
name|CacheAssociativity4Way
init|=
literal|0x05
block|,
name|CacheAssociativityFully
init|=
literal|0x06
block|,
name|CacheAssociativity8Way
init|=
literal|0x07
block|,
name|CacheAssociativity16Way
init|=
literal|0x08
block|,
name|CacheAssociativity12Way
init|=
literal|0x09
block|,
name|CacheAssociativity24Way
init|=
literal|0x0A
block|,
name|CacheAssociativity32Way
init|=
literal|0x0B
block|,
name|CacheAssociativity48Way
init|=
literal|0x0C
block|,
name|CacheAssociativity64Way
init|=
literal|0x0D
block|,
name|CacheAssociativity20Way
init|=
literal|0x0E
block|}
name|CACHE_ASSOCIATIVITY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache Information (Type 7).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of CPU cache device in the system.
end_comment

begin_comment
comment|/// One structure is specified for each such device, whether the device is internal to
end_comment

begin_comment
comment|/// or external to the CPU module.  Cache modules can be associated with a processor structure
end_comment

begin_comment
comment|/// in one or two ways, depending on the SMBIOS version.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SocketDesignation
decl_stmt|;
name|UINT16
name|CacheConfiguration
decl_stmt|;
name|UINT16
name|MaximumCacheSize
decl_stmt|;
name|UINT16
name|InstalledSize
decl_stmt|;
name|CACHE_SRAM_TYPE_DATA
name|SupportedSRAMType
decl_stmt|;
name|CACHE_SRAM_TYPE_DATA
name|CurrentSRAMType
decl_stmt|;
name|UINT8
name|CacheSpeed
decl_stmt|;
name|UINT8
name|ErrorCorrectionType
decl_stmt|;
comment|///< The enumeration value from CACHE_ERROR_TYPE_DATA.
name|UINT8
name|SystemCacheType
decl_stmt|;
comment|///< The enumeration value from CACHE_TYPE_DATA.
name|UINT8
name|Associativity
decl_stmt|;
comment|///< The enumeration value from CACHE_ASSOCIATIVITY_DATA.
comment|//
comment|// Add for smbios 3.1.0
comment|//
name|UINT32
name|MaximumCacheSize2
decl_stmt|;
name|UINT32
name|InstalledSize2
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE7
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Port Connector Information - Connector Types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PortConnectorTypeNone
init|=
literal|0x00
block|,
name|PortConnectorTypeCentronics
init|=
literal|0x01
block|,
name|PortConnectorTypeMiniCentronics
init|=
literal|0x02
block|,
name|PortConnectorTypeProprietary
init|=
literal|0x03
block|,
name|PortConnectorTypeDB25Male
init|=
literal|0x04
block|,
name|PortConnectorTypeDB25Female
init|=
literal|0x05
block|,
name|PortConnectorTypeDB15Male
init|=
literal|0x06
block|,
name|PortConnectorTypeDB15Female
init|=
literal|0x07
block|,
name|PortConnectorTypeDB9Male
init|=
literal|0x08
block|,
name|PortConnectorTypeDB9Female
init|=
literal|0x09
block|,
name|PortConnectorTypeRJ11
init|=
literal|0x0A
block|,
name|PortConnectorTypeRJ45
init|=
literal|0x0B
block|,
name|PortConnectorType50PinMiniScsi
init|=
literal|0x0C
block|,
name|PortConnectorTypeMiniDin
init|=
literal|0x0D
block|,
name|PortConnectorTypeMicroDin
init|=
literal|0x0E
block|,
name|PortConnectorTypePS2
init|=
literal|0x0F
block|,
name|PortConnectorTypeInfrared
init|=
literal|0x10
block|,
name|PortConnectorTypeHpHil
init|=
literal|0x11
block|,
name|PortConnectorTypeUsb
init|=
literal|0x12
block|,
name|PortConnectorTypeSsaScsi
init|=
literal|0x13
block|,
name|PortConnectorTypeCircularDin8Male
init|=
literal|0x14
block|,
name|PortConnectorTypeCircularDin8Female
init|=
literal|0x15
block|,
name|PortConnectorTypeOnboardIde
init|=
literal|0x16
block|,
name|PortConnectorTypeOnboardFloppy
init|=
literal|0x17
block|,
name|PortConnectorType9PinDualInline
init|=
literal|0x18
block|,
name|PortConnectorType25PinDualInline
init|=
literal|0x19
block|,
name|PortConnectorType50PinDualInline
init|=
literal|0x1A
block|,
name|PortConnectorType68PinDualInline
init|=
literal|0x1B
block|,
name|PortConnectorTypeOnboardSoundInput
init|=
literal|0x1C
block|,
name|PortConnectorTypeMiniCentronicsType14
init|=
literal|0x1D
block|,
name|PortConnectorTypeMiniCentronicsType26
init|=
literal|0x1E
block|,
name|PortConnectorTypeHeadPhoneMiniJack
init|=
literal|0x1F
block|,
name|PortConnectorTypeBNC
init|=
literal|0x20
block|,
name|PortConnectorType1394
init|=
literal|0x21
block|,
name|PortConnectorTypeSasSata
init|=
literal|0x22
block|,
name|PortConnectorTypePC98
init|=
literal|0xA0
block|,
name|PortConnectorTypePC98Hireso
init|=
literal|0xA1
block|,
name|PortConnectorTypePCH98
init|=
literal|0xA2
block|,
name|PortConnectorTypePC98Note
init|=
literal|0xA3
block|,
name|PortConnectorTypePC98Full
init|=
literal|0xA4
block|,
name|PortConnectorTypeOther
init|=
literal|0xFF
block|}
name|MISC_PORT_CONNECTOR_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Port Connector Information - Port Types
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PortTypeNone
init|=
literal|0x00
block|,
name|PortTypeParallelXtAtCompatible
init|=
literal|0x01
block|,
name|PortTypeParallelPortPs2
init|=
literal|0x02
block|,
name|PortTypeParallelPortEcp
init|=
literal|0x03
block|,
name|PortTypeParallelPortEpp
init|=
literal|0x04
block|,
name|PortTypeParallelPortEcpEpp
init|=
literal|0x05
block|,
name|PortTypeSerialXtAtCompatible
init|=
literal|0x06
block|,
name|PortTypeSerial16450Compatible
init|=
literal|0x07
block|,
name|PortTypeSerial16550Compatible
init|=
literal|0x08
block|,
name|PortTypeSerial16550ACompatible
init|=
literal|0x09
block|,
name|PortTypeScsi
init|=
literal|0x0A
block|,
name|PortTypeMidi
init|=
literal|0x0B
block|,
name|PortTypeJoyStick
init|=
literal|0x0C
block|,
name|PortTypeKeyboard
init|=
literal|0x0D
block|,
name|PortTypeMouse
init|=
literal|0x0E
block|,
name|PortTypeSsaScsi
init|=
literal|0x0F
block|,
name|PortTypeUsb
init|=
literal|0x10
block|,
name|PortTypeFireWire
init|=
literal|0x11
block|,
name|PortTypePcmciaTypeI
init|=
literal|0x12
block|,
name|PortTypePcmciaTypeII
init|=
literal|0x13
block|,
name|PortTypePcmciaTypeIII
init|=
literal|0x14
block|,
name|PortTypeCardBus
init|=
literal|0x15
block|,
name|PortTypeAccessBusPort
init|=
literal|0x16
block|,
name|PortTypeScsiII
init|=
literal|0x17
block|,
name|PortTypeScsiWide
init|=
literal|0x18
block|,
name|PortTypePC98
init|=
literal|0x19
block|,
name|PortTypePC98Hireso
init|=
literal|0x1A
block|,
name|PortTypePCH98
init|=
literal|0x1B
block|,
name|PortTypeVideoPort
init|=
literal|0x1C
block|,
name|PortTypeAudioPort
init|=
literal|0x1D
block|,
name|PortTypeModemPort
init|=
literal|0x1E
block|,
name|PortTypeNetworkPort
init|=
literal|0x1F
block|,
name|PortTypeSata
init|=
literal|0x20
block|,
name|PortTypeSas
init|=
literal|0x21
block|,
name|PortType8251Compatible
init|=
literal|0xA0
block|,
name|PortType8251FifoCompatible
init|=
literal|0xA1
block|,
name|PortTypeOther
init|=
literal|0xFF
block|}
name|MISC_PORT_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Port Connector Information (Type 8).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of a system port connector,
end_comment

begin_comment
comment|/// e.g. parallel, serial, keyboard, or mouse ports.  The port's type and connector information
end_comment

begin_comment
comment|/// are provided. One structure is present for each port provided by the system.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|InternalReferenceDesignator
decl_stmt|;
name|UINT8
name|InternalConnectorType
decl_stmt|;
comment|///< The enumeration value from MISC_PORT_CONNECTOR_TYPE.
name|SMBIOS_TABLE_STRING
name|ExternalReferenceDesignator
decl_stmt|;
name|UINT8
name|ExternalConnectorType
decl_stmt|;
comment|///< The enumeration value from MISC_PORT_CONNECTOR_TYPE.
name|UINT8
name|PortType
decl_stmt|;
comment|///< The enumeration value from MISC_PORT_TYPE.
block|}
name|SMBIOS_TABLE_TYPE8
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Slots - Slot Type
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SlotTypeOther
init|=
literal|0x01
block|,
name|SlotTypeUnknown
init|=
literal|0x02
block|,
name|SlotTypeIsa
init|=
literal|0x03
block|,
name|SlotTypeMca
init|=
literal|0x04
block|,
name|SlotTypeEisa
init|=
literal|0x05
block|,
name|SlotTypePci
init|=
literal|0x06
block|,
name|SlotTypePcmcia
init|=
literal|0x07
block|,
name|SlotTypeVlVesa
init|=
literal|0x08
block|,
name|SlotTypeProprietary
init|=
literal|0x09
block|,
name|SlotTypeProcessorCardSlot
init|=
literal|0x0A
block|,
name|SlotTypeProprietaryMemoryCardSlot
init|=
literal|0x0B
block|,
name|SlotTypeIORiserCardSlot
init|=
literal|0x0C
block|,
name|SlotTypeNuBus
init|=
literal|0x0D
block|,
name|SlotTypePci66MhzCapable
init|=
literal|0x0E
block|,
name|SlotTypeAgp
init|=
literal|0x0F
block|,
name|SlotTypeApg2X
init|=
literal|0x10
block|,
name|SlotTypeAgp4X
init|=
literal|0x11
block|,
name|SlotTypePciX
init|=
literal|0x12
block|,
name|SlotTypeAgp8X
init|=
literal|0x13
block|,
name|SlotTypeM2Socket1_DP
init|=
literal|0x14
block|,
name|SlotTypeM2Socket1_SD
init|=
literal|0x15
block|,
name|SlotTypeM2Socket2
init|=
literal|0x16
block|,
name|SlotTypeM2Socket3
init|=
literal|0x17
block|,
name|SlotTypeMxmTypeI
init|=
literal|0x18
block|,
name|SlotTypeMxmTypeII
init|=
literal|0x19
block|,
name|SlotTypeMxmTypeIIIStandard
init|=
literal|0x1A
block|,
name|SlotTypeMxmTypeIIIHe
init|=
literal|0x1B
block|,
name|SlotTypeMxmTypeIV
init|=
literal|0x1C
block|,
name|SlotTypeMxm30TypeA
init|=
literal|0x1D
block|,
name|SlotTypeMxm30TypeB
init|=
literal|0x1E
block|,
name|SlotTypePciExpressGen2Sff_8639
init|=
literal|0x1F
block|,
name|SlotTypePciExpressGen3Sff_8639
init|=
literal|0x20
block|,
name|SlotTypePciExpressMini52pinWithBSKO
init|=
literal|0x21
block|,
comment|///< PCI Express Mini 52-pin (CEM spec. 2.0) with bottom-side keep-outs.
name|SlotTypePciExpressMini52pinWithoutBSKO
init|=
literal|0x22
block|,
comment|///< PCI Express Mini 52-pin (CEM spec. 2.0) without bottom-side keep-outs.
name|SlotTypePciExpressMini76pin
init|=
literal|0x23
block|,
comment|///< PCI Express Mini 76-pin (CEM spec. 2.0) Corresponds to Display-Mini card.
name|SlotTypePC98C20
init|=
literal|0xA0
block|,
name|SlotTypePC98C24
init|=
literal|0xA1
block|,
name|SlotTypePC98E
init|=
literal|0xA2
block|,
name|SlotTypePC98LocalBus
init|=
literal|0xA3
block|,
name|SlotTypePC98Card
init|=
literal|0xA4
block|,
name|SlotTypePciExpress
init|=
literal|0xA5
block|,
name|SlotTypePciExpressX1
init|=
literal|0xA6
block|,
name|SlotTypePciExpressX2
init|=
literal|0xA7
block|,
name|SlotTypePciExpressX4
init|=
literal|0xA8
block|,
name|SlotTypePciExpressX8
init|=
literal|0xA9
block|,
name|SlotTypePciExpressX16
init|=
literal|0xAA
block|,
name|SlotTypePciExpressGen2
init|=
literal|0xAB
block|,
name|SlotTypePciExpressGen2X1
init|=
literal|0xAC
block|,
name|SlotTypePciExpressGen2X2
init|=
literal|0xAD
block|,
name|SlotTypePciExpressGen2X4
init|=
literal|0xAE
block|,
name|SlotTypePciExpressGen2X8
init|=
literal|0xAF
block|,
name|SlotTypePciExpressGen2X16
init|=
literal|0xB0
block|,
name|SlotTypePciExpressGen3
init|=
literal|0xB1
block|,
name|SlotTypePciExpressGen3X1
init|=
literal|0xB2
block|,
name|SlotTypePciExpressGen3X2
init|=
literal|0xB3
block|,
name|SlotTypePciExpressGen3X4
init|=
literal|0xB4
block|,
name|SlotTypePciExpressGen3X8
init|=
literal|0xB5
block|,
name|SlotTypePciExpressGen3X16
init|=
literal|0xB6
block|}
name|MISC_SLOT_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Slots - Slot Data Bus Width.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SlotDataBusWidthOther
init|=
literal|0x01
block|,
name|SlotDataBusWidthUnknown
init|=
literal|0x02
block|,
name|SlotDataBusWidth8Bit
init|=
literal|0x03
block|,
name|SlotDataBusWidth16Bit
init|=
literal|0x04
block|,
name|SlotDataBusWidth32Bit
init|=
literal|0x05
block|,
name|SlotDataBusWidth64Bit
init|=
literal|0x06
block|,
name|SlotDataBusWidth128Bit
init|=
literal|0x07
block|,
name|SlotDataBusWidth1X
init|=
literal|0x08
block|,
comment|///< Or X1
name|SlotDataBusWidth2X
init|=
literal|0x09
block|,
comment|///< Or X2
name|SlotDataBusWidth4X
init|=
literal|0x0A
block|,
comment|///< Or X4
name|SlotDataBusWidth8X
init|=
literal|0x0B
block|,
comment|///< Or X8
name|SlotDataBusWidth12X
init|=
literal|0x0C
block|,
comment|///< Or X12
name|SlotDataBusWidth16X
init|=
literal|0x0D
block|,
comment|///< Or X16
name|SlotDataBusWidth32X
init|=
literal|0x0E
comment|///< Or X32
block|}
name|MISC_SLOT_DATA_BUS_WIDTH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Slots - Current Usage.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SlotUsageOther
init|=
literal|0x01
block|,
name|SlotUsageUnknown
init|=
literal|0x02
block|,
name|SlotUsageAvailable
init|=
literal|0x03
block|,
name|SlotUsageInUse
init|=
literal|0x04
block|}
name|MISC_SLOT_USAGE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Slots - Slot Length.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SlotLengthOther
init|=
literal|0x01
block|,
name|SlotLengthUnknown
init|=
literal|0x02
block|,
name|SlotLengthShort
init|=
literal|0x03
block|,
name|SlotLengthLong
init|=
literal|0x04
block|}
name|MISC_SLOT_LENGTH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Slots - Slot Characteristics 1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CharacteristicsUnknown
range|:
literal|1
decl_stmt|;
name|UINT8
name|Provides50Volts
range|:
literal|1
decl_stmt|;
name|UINT8
name|Provides33Volts
range|:
literal|1
decl_stmt|;
name|UINT8
name|SharedSlot
range|:
literal|1
decl_stmt|;
name|UINT8
name|PcCard16Supported
range|:
literal|1
decl_stmt|;
name|UINT8
name|CardBusSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|ZoomVideoSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|ModemRingResumeSupported
range|:
literal|1
decl_stmt|;
block|}
name|MISC_SLOT_CHARACTERISTICS1
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Slots - Slot Characteristics 2.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|PmeSignalSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|HotPlugDevicesSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|SmbusSignalSupported
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|5
decl_stmt|;
comment|///< Set to 0.
block|}
name|MISC_SLOT_CHARACTERISTICS2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Slots (Type 9)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of a system slot.
end_comment

begin_comment
comment|/// One structure is provided for each slot in the system.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SlotDesignation
decl_stmt|;
name|UINT8
name|SlotType
decl_stmt|;
comment|///< The enumeration value from MISC_SLOT_TYPE.
name|UINT8
name|SlotDataBusWidth
decl_stmt|;
comment|///< The enumeration value from MISC_SLOT_DATA_BUS_WIDTH.
name|UINT8
name|CurrentUsage
decl_stmt|;
comment|///< The enumeration value from MISC_SLOT_USAGE.
name|UINT8
name|SlotLength
decl_stmt|;
comment|///< The enumeration value from MISC_SLOT_LENGTH.
name|UINT16
name|SlotID
decl_stmt|;
name|MISC_SLOT_CHARACTERISTICS1
name|SlotCharacteristics1
decl_stmt|;
name|MISC_SLOT_CHARACTERISTICS2
name|SlotCharacteristics2
decl_stmt|;
comment|//
comment|// Add for smbios 2.6
comment|//
name|UINT16
name|SegmentGroupNum
decl_stmt|;
name|UINT8
name|BusNum
decl_stmt|;
name|UINT8
name|DevFuncNum
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE9
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// On Board Devices Information - Device Types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|OnBoardDeviceTypeOther
init|=
literal|0x01
block|,
name|OnBoardDeviceTypeUnknown
init|=
literal|0x02
block|,
name|OnBoardDeviceTypeVideo
init|=
literal|0x03
block|,
name|OnBoardDeviceTypeScsiController
init|=
literal|0x04
block|,
name|OnBoardDeviceTypeEthernet
init|=
literal|0x05
block|,
name|OnBoardDeviceTypeTokenRing
init|=
literal|0x06
block|,
name|OnBoardDeviceTypeSound
init|=
literal|0x07
block|,
name|OnBoardDeviceTypePATAController
init|=
literal|0x08
block|,
name|OnBoardDeviceTypeSATAController
init|=
literal|0x09
block|,
name|OnBoardDeviceTypeSASController
init|=
literal|0x0A
block|}
name|MISC_ONBOARD_DEVICE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device Item Entry
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DeviceType
decl_stmt|;
comment|///< Bit [6:0] - enumeration type of device from MISC_ONBOARD_DEVICE_TYPE.
comment|///< Bit 7     - 1 : device enabled, 0 : device disabled.
name|SMBIOS_TABLE_STRING
name|DescriptionString
decl_stmt|;
block|}
name|DEVICE_STRUCT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// On Board Devices Information (Type 10, obsolete).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note: This structure is obsolete starting with version 2.6 specification; the Onboard Devices Extended
end_comment

begin_comment
comment|/// Information (Type 41) structure should be used instead . BIOS providers can choose to implement both
end_comment

begin_comment
comment|/// types to allow existing SMBIOS browsers to properly display the system's onboard devices information.
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of devices that are onboard (soldered onto)
end_comment

begin_comment
comment|/// a system element, usually the baseboard.  In general, an entry in this table implies that the BIOS
end_comment

begin_comment
comment|/// has some level of control over the enabling of the associated device for use by the system.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|DEVICE_STRUCT
name|Device
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE10
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// OEM Strings (Type 11).
end_comment

begin_comment
comment|/// This structure contains free form strings defined by the OEM. Examples of this are:
end_comment

begin_comment
comment|/// Part Numbers for Reference Documents for the system, contact information for the manufacturer, etc.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|StringCount
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE11
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Configuration Options (Type 12).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure contains information required to configure the base board's Jumpers and Switches.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|StringCount
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE12
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BIOS Language Information (Type 13).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the installable language attributes of the BIOS.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|InstallableLanguages
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|15
index|]
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|CurrentLanguages
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE13
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Group Item Entry
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ItemType
decl_stmt|;
name|UINT16
name|ItemHandle
decl_stmt|;
block|}
name|GROUP_STRUCT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Group Associations (Type 14).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Group Associations structure is provided for OEMs who want to specify
end_comment

begin_comment
comment|/// the arrangement or hierarchy of certain components (including other Group Associations)
end_comment

begin_comment
comment|/// within the system.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|GroupName
decl_stmt|;
name|GROUP_STRUCT
name|Group
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE14
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Event Log - Event Log Types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EventLogTypeReserved
init|=
literal|0x00
block|,
name|EventLogTypeSingleBitECC
init|=
literal|0x01
block|,
name|EventLogTypeMultiBitECC
init|=
literal|0x02
block|,
name|EventLogTypeParityMemErr
init|=
literal|0x03
block|,
name|EventLogTypeBusTimeOut
init|=
literal|0x04
block|,
name|EventLogTypeIOChannelCheck
init|=
literal|0x05
block|,
name|EventLogTypeSoftwareNMI
init|=
literal|0x06
block|,
name|EventLogTypePOSTMemResize
init|=
literal|0x07
block|,
name|EventLogTypePOSTErr
init|=
literal|0x08
block|,
name|EventLogTypePCIParityErr
init|=
literal|0x09
block|,
name|EventLogTypePCISystemErr
init|=
literal|0x0A
block|,
name|EventLogTypeCPUFailure
init|=
literal|0x0B
block|,
name|EventLogTypeEISATimeOut
init|=
literal|0x0C
block|,
name|EventLogTypeMemLogDisabled
init|=
literal|0x0D
block|,
name|EventLogTypeLoggingDisabled
init|=
literal|0x0E
block|,
name|EventLogTypeSysLimitExce
init|=
literal|0x10
block|,
name|EventLogTypeAsyncHWTimer
init|=
literal|0x11
block|,
name|EventLogTypeSysConfigInfo
init|=
literal|0x12
block|,
name|EventLogTypeHDInfo
init|=
literal|0x13
block|,
name|EventLogTypeSysReconfig
init|=
literal|0x14
block|,
name|EventLogTypeUncorrectCPUErr
init|=
literal|0x15
block|,
name|EventLogTypeAreaResetAndClr
init|=
literal|0x16
block|,
name|EventLogTypeSystemBoot
init|=
literal|0x17
block|,
name|EventLogTypeUnused
init|=
literal|0x18
block|,
comment|///< 0x18 - 0x7F
name|EventLogTypeAvailForSys
init|=
literal|0x80
block|,
comment|///< 0x80 - 0xFE
name|EventLogTypeEndOfLog
init|=
literal|0xFF
block|}
name|EVENT_LOG_TYPE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Event Log - Variable Data Format Types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EventLogVariableNone
init|=
literal|0x00
block|,
name|EventLogVariableHandle
init|=
literal|0x01
block|,
name|EventLogVariableMutilEvent
init|=
literal|0x02
block|,
name|EventLogVariableMutilEventHandle
init|=
literal|0x03
block|,
name|EventLogVariablePOSTResultBitmap
init|=
literal|0x04
block|,
name|EventLogVariableSysManagementType
init|=
literal|0x05
block|,
name|EventLogVariableMutliEventSysManagmentType
init|=
literal|0x06
block|,
name|EventLogVariableUnused
init|=
literal|0x07
block|,
name|EventLogVariableOEMAssigned
init|=
literal|0x80
block|}
name|EVENT_LOG_VARIABLE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Event Log Type Descriptors
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|LogType
decl_stmt|;
comment|///< The enumeration value from EVENT_LOG_TYPE_DATA.
name|UINT8
name|DataFormatType
decl_stmt|;
block|}
name|EVENT_LOG_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Event Log (Type 15).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The presence of this structure within the SMBIOS data returned for a system indicates
end_comment

begin_comment
comment|/// that the system supports an event log.  An event log is a fixed-length area within a
end_comment

begin_comment
comment|/// non-volatile storage element, starting with a fixed-length (and vendor-specific) header
end_comment

begin_comment
comment|/// record, followed by one or more variable-length log records.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT16
name|LogAreaLength
decl_stmt|;
name|UINT16
name|LogHeaderStartOffset
decl_stmt|;
name|UINT16
name|LogDataStartOffset
decl_stmt|;
name|UINT8
name|AccessMethod
decl_stmt|;
name|UINT8
name|LogStatus
decl_stmt|;
name|UINT32
name|LogChangeToken
decl_stmt|;
name|UINT32
name|AccessMethodAddress
decl_stmt|;
name|UINT8
name|LogHeaderFormat
decl_stmt|;
name|UINT8
name|NumberOfSupportedLogTypeDescriptors
decl_stmt|;
name|UINT8
name|LengthOfLogTypeDescriptor
decl_stmt|;
name|EVENT_LOG_TYPE
name|EventLogTypeDescriptors
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE15
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Physical Memory Array - Location.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryArrayLocationOther
init|=
literal|0x01
block|,
name|MemoryArrayLocationUnknown
init|=
literal|0x02
block|,
name|MemoryArrayLocationSystemBoard
init|=
literal|0x03
block|,
name|MemoryArrayLocationIsaAddonCard
init|=
literal|0x04
block|,
name|MemoryArrayLocationEisaAddonCard
init|=
literal|0x05
block|,
name|MemoryArrayLocationPciAddonCard
init|=
literal|0x06
block|,
name|MemoryArrayLocationMcaAddonCard
init|=
literal|0x07
block|,
name|MemoryArrayLocationPcmciaAddonCard
init|=
literal|0x08
block|,
name|MemoryArrayLocationProprietaryAddonCard
init|=
literal|0x09
block|,
name|MemoryArrayLocationNuBus
init|=
literal|0x0A
block|,
name|MemoryArrayLocationPc98C20AddonCard
init|=
literal|0xA0
block|,
name|MemoryArrayLocationPc98C24AddonCard
init|=
literal|0xA1
block|,
name|MemoryArrayLocationPc98EAddonCard
init|=
literal|0xA2
block|,
name|MemoryArrayLocationPc98LocalBusAddonCard
init|=
literal|0xA3
block|}
name|MEMORY_ARRAY_LOCATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Physical Memory Array - Use.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryArrayUseOther
init|=
literal|0x01
block|,
name|MemoryArrayUseUnknown
init|=
literal|0x02
block|,
name|MemoryArrayUseSystemMemory
init|=
literal|0x03
block|,
name|MemoryArrayUseVideoMemory
init|=
literal|0x04
block|,
name|MemoryArrayUseFlashMemory
init|=
literal|0x05
block|,
name|MemoryArrayUseNonVolatileRam
init|=
literal|0x06
block|,
name|MemoryArrayUseCacheMemory
init|=
literal|0x07
block|}
name|MEMORY_ARRAY_USE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Physical Memory Array - Error Correction Types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryErrorCorrectionOther
init|=
literal|0x01
block|,
name|MemoryErrorCorrectionUnknown
init|=
literal|0x02
block|,
name|MemoryErrorCorrectionNone
init|=
literal|0x03
block|,
name|MemoryErrorCorrectionParity
init|=
literal|0x04
block|,
name|MemoryErrorCorrectionSingleBitEcc
init|=
literal|0x05
block|,
name|MemoryErrorCorrectionMultiBitEcc
init|=
literal|0x06
block|,
name|MemoryErrorCorrectionCrc
init|=
literal|0x07
block|}
name|MEMORY_ERROR_CORRECTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Physical Memory Array (Type 16).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes a collection of memory devices that operate
end_comment

begin_comment
comment|/// together to form a memory address space.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|Location
decl_stmt|;
comment|///< The enumeration value from MEMORY_ARRAY_LOCATION.
name|UINT8
name|Use
decl_stmt|;
comment|///< The enumeration value from MEMORY_ARRAY_USE.
name|UINT8
name|MemoryErrorCorrection
decl_stmt|;
comment|///< The enumeration value from MEMORY_ERROR_CORRECTION.
name|UINT32
name|MaximumCapacity
decl_stmt|;
name|UINT16
name|MemoryErrorInformationHandle
decl_stmt|;
name|UINT16
name|NumberOfMemoryDevices
decl_stmt|;
comment|//
comment|// Add for smbios 2.7
comment|//
name|UINT64
name|ExtendedMaximumCapacity
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE16
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Device - Form Factor.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryFormFactorOther
init|=
literal|0x01
block|,
name|MemoryFormFactorUnknown
init|=
literal|0x02
block|,
name|MemoryFormFactorSimm
init|=
literal|0x03
block|,
name|MemoryFormFactorSip
init|=
literal|0x04
block|,
name|MemoryFormFactorChip
init|=
literal|0x05
block|,
name|MemoryFormFactorDip
init|=
literal|0x06
block|,
name|MemoryFormFactorZip
init|=
literal|0x07
block|,
name|MemoryFormFactorProprietaryCard
init|=
literal|0x08
block|,
name|MemoryFormFactorDimm
init|=
literal|0x09
block|,
name|MemoryFormFactorTsop
init|=
literal|0x0A
block|,
name|MemoryFormFactorRowOfChips
init|=
literal|0x0B
block|,
name|MemoryFormFactorRimm
init|=
literal|0x0C
block|,
name|MemoryFormFactorSodimm
init|=
literal|0x0D
block|,
name|MemoryFormFactorSrimm
init|=
literal|0x0E
block|,
name|MemoryFormFactorFbDimm
init|=
literal|0x0F
block|}
name|MEMORY_FORM_FACTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Device - Type
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryTypeOther
init|=
literal|0x01
block|,
name|MemoryTypeUnknown
init|=
literal|0x02
block|,
name|MemoryTypeDram
init|=
literal|0x03
block|,
name|MemoryTypeEdram
init|=
literal|0x04
block|,
name|MemoryTypeVram
init|=
literal|0x05
block|,
name|MemoryTypeSram
init|=
literal|0x06
block|,
name|MemoryTypeRam
init|=
literal|0x07
block|,
name|MemoryTypeRom
init|=
literal|0x08
block|,
name|MemoryTypeFlash
init|=
literal|0x09
block|,
name|MemoryTypeEeprom
init|=
literal|0x0A
block|,
name|MemoryTypeFeprom
init|=
literal|0x0B
block|,
name|MemoryTypeEprom
init|=
literal|0x0C
block|,
name|MemoryTypeCdram
init|=
literal|0x0D
block|,
name|MemoryType3Dram
init|=
literal|0x0E
block|,
name|MemoryTypeSdram
init|=
literal|0x0F
block|,
name|MemoryTypeSgram
init|=
literal|0x10
block|,
name|MemoryTypeRdram
init|=
literal|0x11
block|,
name|MemoryTypeDdr
init|=
literal|0x12
block|,
name|MemoryTypeDdr2
init|=
literal|0x13
block|,
name|MemoryTypeDdr2FbDimm
init|=
literal|0x14
block|,
name|MemoryTypeDdr3
init|=
literal|0x18
block|,
name|MemoryTypeFbd2
init|=
literal|0x19
block|,
name|MemoryTypeDdr4
init|=
literal|0x1A
block|,
name|MemoryTypeLpddr
init|=
literal|0x1B
block|,
name|MemoryTypeLpddr2
init|=
literal|0x1C
block|,
name|MemoryTypeLpddr3
init|=
literal|0x1D
block|,
name|MemoryTypeLpddr4
init|=
literal|0x1E
block|}
name|MEMORY_DEVICE_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Reserved
range|:
literal|1
decl_stmt|;
name|UINT16
name|Other
range|:
literal|1
decl_stmt|;
name|UINT16
name|Unknown
range|:
literal|1
decl_stmt|;
name|UINT16
name|FastPaged
range|:
literal|1
decl_stmt|;
name|UINT16
name|StaticColumn
range|:
literal|1
decl_stmt|;
name|UINT16
name|PseudoStatic
range|:
literal|1
decl_stmt|;
name|UINT16
name|Rambus
range|:
literal|1
decl_stmt|;
name|UINT16
name|Synchronous
range|:
literal|1
decl_stmt|;
name|UINT16
name|Cmos
range|:
literal|1
decl_stmt|;
name|UINT16
name|Edo
range|:
literal|1
decl_stmt|;
name|UINT16
name|WindowDram
range|:
literal|1
decl_stmt|;
name|UINT16
name|CacheDram
range|:
literal|1
decl_stmt|;
name|UINT16
name|Nonvolatile
range|:
literal|1
decl_stmt|;
name|UINT16
name|Registered
range|:
literal|1
decl_stmt|;
name|UINT16
name|Unbuffered
range|:
literal|1
decl_stmt|;
name|UINT16
name|LrDimm
range|:
literal|1
decl_stmt|;
block|}
name|MEMORY_DEVICE_TYPE_DETAIL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Device (Type 17).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes a single memory device that is part of
end_comment

begin_comment
comment|/// a larger Physical Memory Array (Type 16).
end_comment

begin_comment
comment|/// Note:  If a system includes memory-device sockets, the SMBIOS implementation
end_comment

begin_comment
comment|/// includes a Memory Device structure instance for each slot, whether or not the
end_comment

begin_comment
comment|/// socket is currently populated.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT16
name|MemoryArrayHandle
decl_stmt|;
name|UINT16
name|MemoryErrorInformationHandle
decl_stmt|;
name|UINT16
name|TotalWidth
decl_stmt|;
name|UINT16
name|DataWidth
decl_stmt|;
name|UINT16
name|Size
decl_stmt|;
name|UINT8
name|FormFactor
decl_stmt|;
comment|///< The enumeration value from MEMORY_FORM_FACTOR.
name|UINT8
name|DeviceSet
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|DeviceLocator
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|BankLocator
decl_stmt|;
name|UINT8
name|MemoryType
decl_stmt|;
comment|///< The enumeration value from MEMORY_DEVICE_TYPE.
name|MEMORY_DEVICE_TYPE_DETAIL
name|TypeDetail
decl_stmt|;
name|UINT16
name|Speed
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Manufacturer
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SerialNumber
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|AssetTag
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|PartNumber
decl_stmt|;
comment|//
comment|// Add for smbios 2.6
comment|//
name|UINT8
name|Attributes
decl_stmt|;
comment|//
comment|// Add for smbios 2.7
comment|//
name|UINT32
name|ExtendedSize
decl_stmt|;
name|UINT16
name|ConfiguredMemoryClockSpeed
decl_stmt|;
comment|//
comment|// Add for smbios 2.8.0
comment|//
name|UINT16
name|MinimumVoltage
decl_stmt|;
name|UINT16
name|MaximumVoltage
decl_stmt|;
name|UINT16
name|ConfiguredVoltage
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE17
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 32-bit Memory Error Information - Error Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryErrorOther
init|=
literal|0x01
block|,
name|MemoryErrorUnknown
init|=
literal|0x02
block|,
name|MemoryErrorOk
init|=
literal|0x03
block|,
name|MemoryErrorBadRead
init|=
literal|0x04
block|,
name|MemoryErrorParity
init|=
literal|0x05
block|,
name|MemoryErrorSigleBit
init|=
literal|0x06
block|,
name|MemoryErrorDoubleBit
init|=
literal|0x07
block|,
name|MemoryErrorMultiBit
init|=
literal|0x08
block|,
name|MemoryErrorNibble
init|=
literal|0x09
block|,
name|MemoryErrorChecksum
init|=
literal|0x0A
block|,
name|MemoryErrorCrc
init|=
literal|0x0B
block|,
name|MemoryErrorCorrectSingleBit
init|=
literal|0x0C
block|,
name|MemoryErrorCorrected
init|=
literal|0x0D
block|,
name|MemoryErrorUnCorrectable
init|=
literal|0x0E
block|}
name|MEMORY_ERROR_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 32-bit Memory Error Information - Error Granularity.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryGranularityOther
init|=
literal|0x01
block|,
name|MemoryGranularityOtherUnknown
init|=
literal|0x02
block|,
name|MemoryGranularityDeviceLevel
init|=
literal|0x03
block|,
name|MemoryGranularityMemPartitionLevel
init|=
literal|0x04
block|}
name|MEMORY_ERROR_GRANULARITY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 32-bit Memory Error Information - Error Operation.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryErrorOperationOther
init|=
literal|0x01
block|,
name|MemoryErrorOperationUnknown
init|=
literal|0x02
block|,
name|MemoryErrorOperationRead
init|=
literal|0x03
block|,
name|MemoryErrorOperationWrite
init|=
literal|0x04
block|,
name|MemoryErrorOperationPartialWrite
init|=
literal|0x05
block|}
name|MEMORY_ERROR_OPERATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 32-bit Memory Error Information (Type 18).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure identifies the specifics of an error that might be detected
end_comment

begin_comment
comment|/// within a Physical Memory Array.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|ErrorType
decl_stmt|;
comment|///< The enumeration value from MEMORY_ERROR_TYPE.
name|UINT8
name|ErrorGranularity
decl_stmt|;
comment|///< The enumeration value from MEMORY_ERROR_GRANULARITY.
name|UINT8
name|ErrorOperation
decl_stmt|;
comment|///< The enumeration value from MEMORY_ERROR_OPERATION.
name|UINT32
name|VendorSyndrome
decl_stmt|;
name|UINT32
name|MemoryArrayErrorAddress
decl_stmt|;
name|UINT32
name|DeviceErrorAddress
decl_stmt|;
name|UINT32
name|ErrorResolution
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE18
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Array Mapped Address (Type 19).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides the address mapping for a Physical Memory Array.
end_comment

begin_comment
comment|/// One structure is present for each contiguous address range described.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT32
name|StartingAddress
decl_stmt|;
name|UINT32
name|EndingAddress
decl_stmt|;
name|UINT16
name|MemoryArrayHandle
decl_stmt|;
name|UINT8
name|PartitionWidth
decl_stmt|;
comment|//
comment|// Add for smbios 2.7
comment|//
name|UINT64
name|ExtendedStartingAddress
decl_stmt|;
name|UINT64
name|ExtendedEndingAddress
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE19
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Device Mapped Address (Type 20).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure maps memory address space usually to a device-level granularity.
end_comment

begin_comment
comment|/// One structure is present for each contiguous address range described.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT32
name|StartingAddress
decl_stmt|;
name|UINT32
name|EndingAddress
decl_stmt|;
name|UINT16
name|MemoryDeviceHandle
decl_stmt|;
name|UINT16
name|MemoryArrayMappedAddressHandle
decl_stmt|;
name|UINT8
name|PartitionRowPosition
decl_stmt|;
name|UINT8
name|InterleavePosition
decl_stmt|;
name|UINT8
name|InterleavedDataDepth
decl_stmt|;
comment|//
comment|// Add for smbios 2.7
comment|//
name|UINT64
name|ExtendedStartingAddress
decl_stmt|;
name|UINT64
name|ExtendedEndingAddress
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE20
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Built-in Pointing Device - Type
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PointingDeviceTypeOther
init|=
literal|0x01
block|,
name|PointingDeviceTypeUnknown
init|=
literal|0x02
block|,
name|PointingDeviceTypeMouse
init|=
literal|0x03
block|,
name|PointingDeviceTypeTrackBall
init|=
literal|0x04
block|,
name|PointingDeviceTypeTrackPoint
init|=
literal|0x05
block|,
name|PointingDeviceTypeGlidePoint
init|=
literal|0x06
block|,
name|PointingDeviceTouchPad
init|=
literal|0x07
block|,
name|PointingDeviceTouchScreen
init|=
literal|0x08
block|,
name|PointingDeviceOpticalSensor
init|=
literal|0x09
block|}
name|BUILTIN_POINTING_DEVICE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Built-in Pointing Device - Interface.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PointingDeviceInterfaceOther
init|=
literal|0x01
block|,
name|PointingDeviceInterfaceUnknown
init|=
literal|0x02
block|,
name|PointingDeviceInterfaceSerial
init|=
literal|0x03
block|,
name|PointingDeviceInterfacePs2
init|=
literal|0x04
block|,
name|PointingDeviceInterfaceInfrared
init|=
literal|0x05
block|,
name|PointingDeviceInterfaceHpHil
init|=
literal|0x06
block|,
name|PointingDeviceInterfaceBusMouse
init|=
literal|0x07
block|,
name|PointingDeviceInterfaceADB
init|=
literal|0x08
block|,
name|PointingDeviceInterfaceBusMouseDB9
init|=
literal|0xA0
block|,
name|PointingDeviceInterfaceBusMouseMicroDin
init|=
literal|0xA1
block|,
name|PointingDeviceInterfaceUsb
init|=
literal|0xA2
block|}
name|BUILTIN_POINTING_DEVICE_INTERFACE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Built-in Pointing Device (Type 21).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes the attributes of the built-in pointing device for the
end_comment

begin_comment
comment|/// system. The presence of this structure does not imply that the built-in
end_comment

begin_comment
comment|/// pointing device is active for the system's use!
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
comment|///< The enumeration value from BUILTIN_POINTING_DEVICE_TYPE.
name|UINT8
name|Interface
decl_stmt|;
comment|///< The enumeration value from BUILTIN_POINTING_DEVICE_INTERFACE.
name|UINT8
name|NumberOfButtons
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE21
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Portable Battery - Device Chemistry
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PortableBatteryDeviceChemistryOther
init|=
literal|0x01
block|,
name|PortableBatteryDeviceChemistryUnknown
init|=
literal|0x02
block|,
name|PortableBatteryDeviceChemistryLeadAcid
init|=
literal|0x03
block|,
name|PortableBatteryDeviceChemistryNickelCadmium
init|=
literal|0x04
block|,
name|PortableBatteryDeviceChemistryNickelMetalHydride
init|=
literal|0x05
block|,
name|PortableBatteryDeviceChemistryLithiumIon
init|=
literal|0x06
block|,
name|PortableBatteryDeviceChemistryZincAir
init|=
literal|0x07
block|,
name|PortableBatteryDeviceChemistryLithiumPolymer
init|=
literal|0x08
block|}
name|PORTABLE_BATTERY_DEVICE_CHEMISTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Portable Battery (Type 22).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes the attributes of the portable battery(s) for the system.
end_comment

begin_comment
comment|/// The structure contains the static attributes for the group.  Each structure describes
end_comment

begin_comment
comment|/// a single battery pack's attributes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Location
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Manufacturer
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|ManufactureDate
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SerialNumber
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|DeviceName
decl_stmt|;
name|UINT8
name|DeviceChemistry
decl_stmt|;
comment|///< The enumeration value from PORTABLE_BATTERY_DEVICE_CHEMISTRY.
name|UINT16
name|DeviceCapacity
decl_stmt|;
name|UINT16
name|DesignVoltage
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SBDSVersionNumber
decl_stmt|;
name|UINT8
name|MaximumErrorInBatteryData
decl_stmt|;
name|UINT16
name|SBDSSerialNumber
decl_stmt|;
name|UINT16
name|SBDSManufactureDate
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SBDSDeviceChemistry
decl_stmt|;
name|UINT8
name|DesignCapacityMultiplier
decl_stmt|;
name|UINT32
name|OEMSpecific
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE22
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Reset (Type 23)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes whether Automatic System Reset functions enabled (Status).
end_comment

begin_comment
comment|/// If the system has a watchdog Timer and the timer is not reset (Timer Reset)
end_comment

begin_comment
comment|/// before the Interval elapses, an automatic system reset will occur. The system will re-boot
end_comment

begin_comment
comment|/// according to the Boot Option. This function may repeat until the Limit is reached, at which time
end_comment

begin_comment
comment|/// the system will re-boot according to the Boot Option at Limit.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|Capabilities
decl_stmt|;
name|UINT16
name|ResetCount
decl_stmt|;
name|UINT16
name|ResetLimit
decl_stmt|;
name|UINT16
name|TimerInterval
decl_stmt|;
name|UINT16
name|Timeout
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE23
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Hardware Security (Type 24).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes the system-wide hardware security settings.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|HardwareSecuritySettings
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE24
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Power Controls (Type 25).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes the attributes for controlling the main power supply to the system.
end_comment

begin_comment
comment|/// Software that interprets this structure uses the month, day, hour, minute, and second values
end_comment

begin_comment
comment|/// to determine the number of seconds until the next power-on of the system.  The presence of
end_comment

begin_comment
comment|/// this structure implies that a timed power-on facility is available for the system.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|NextScheduledPowerOnMonth
decl_stmt|;
name|UINT8
name|NextScheduledPowerOnDayOfMonth
decl_stmt|;
name|UINT8
name|NextScheduledPowerOnHour
decl_stmt|;
name|UINT8
name|NextScheduledPowerOnMinute
decl_stmt|;
name|UINT8
name|NextScheduledPowerOnSecond
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE25
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Voltage Probe - Location and Status.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|VoltageProbeSite
range|:
literal|5
decl_stmt|;
name|UINT8
name|VoltageProbeStatus
range|:
literal|3
decl_stmt|;
block|}
name|MISC_VOLTAGE_PROBE_LOCATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Voltage Probe (Type 26)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This describes the attributes for a voltage probe in the system.
end_comment

begin_comment
comment|/// Each structure describes a single voltage probe.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Description
decl_stmt|;
name|MISC_VOLTAGE_PROBE_LOCATION
name|LocationAndStatus
decl_stmt|;
name|UINT16
name|MaximumValue
decl_stmt|;
name|UINT16
name|MinimumValue
decl_stmt|;
name|UINT16
name|Resolution
decl_stmt|;
name|UINT16
name|Tolerance
decl_stmt|;
name|UINT16
name|Accuracy
decl_stmt|;
name|UINT32
name|OEMDefined
decl_stmt|;
name|UINT16
name|NominalValue
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE26
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cooling Device - Device Type and Status.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CoolingDevice
range|:
literal|5
decl_stmt|;
name|UINT8
name|CoolingDeviceStatus
range|:
literal|3
decl_stmt|;
block|}
name|MISC_COOLING_DEVICE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cooling Device (Type 27)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes the attributes for a cooling device in the system.
end_comment

begin_comment
comment|/// Each structure describes a single cooling device.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT16
name|TemperatureProbeHandle
decl_stmt|;
name|MISC_COOLING_DEVICE_TYPE
name|DeviceTypeAndStatus
decl_stmt|;
name|UINT8
name|CoolingUnitGroup
decl_stmt|;
name|UINT32
name|OEMDefined
decl_stmt|;
name|UINT16
name|NominalSpeed
decl_stmt|;
comment|//
comment|// Add for smbios 2.7
comment|//
name|SMBIOS_TABLE_STRING
name|Description
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE27
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Temperature Probe - Location and Status.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|TemperatureProbeSite
range|:
literal|5
decl_stmt|;
name|UINT8
name|TemperatureProbeStatus
range|:
literal|3
decl_stmt|;
block|}
name|MISC_TEMPERATURE_PROBE_LOCATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Temperature Probe (Type 28).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes the attributes for a temperature probe in the system.
end_comment

begin_comment
comment|/// Each structure describes a single temperature probe.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Description
decl_stmt|;
name|MISC_TEMPERATURE_PROBE_LOCATION
name|LocationAndStatus
decl_stmt|;
name|UINT16
name|MaximumValue
decl_stmt|;
name|UINT16
name|MinimumValue
decl_stmt|;
name|UINT16
name|Resolution
decl_stmt|;
name|UINT16
name|Tolerance
decl_stmt|;
name|UINT16
name|Accuracy
decl_stmt|;
name|UINT32
name|OEMDefined
decl_stmt|;
name|UINT16
name|NominalValue
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE28
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Electrical Current Probe - Location and Status.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ElectricalCurrentProbeSite
range|:
literal|5
decl_stmt|;
name|UINT8
name|ElectricalCurrentProbeStatus
range|:
literal|3
decl_stmt|;
block|}
name|MISC_ELECTRICAL_CURRENT_PROBE_LOCATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Electrical Current Probe (Type 29).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes the attributes for an electrical current probe in the system.
end_comment

begin_comment
comment|/// Each structure describes a single electrical current probe.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Description
decl_stmt|;
name|MISC_ELECTRICAL_CURRENT_PROBE_LOCATION
name|LocationAndStatus
decl_stmt|;
name|UINT16
name|MaximumValue
decl_stmt|;
name|UINT16
name|MinimumValue
decl_stmt|;
name|UINT16
name|Resolution
decl_stmt|;
name|UINT16
name|Tolerance
decl_stmt|;
name|UINT16
name|Accuracy
decl_stmt|;
name|UINT32
name|OEMDefined
decl_stmt|;
name|UINT16
name|NominalValue
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE29
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Out-of-Band Remote Access (Type 30).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes the attributes and policy settings of a hardware facility
end_comment

begin_comment
comment|/// that may be used to gain remote access to a hardware system when the operating system
end_comment

begin_comment
comment|/// is not available due to power-down status, hardware failures, or boot failures.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|ManufacturerName
decl_stmt|;
name|UINT8
name|Connections
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE30
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Boot Integrity Services (BIS) Entry Point (Type 31).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Structure type 31 (decimal) is reserved for use by the Boot Integrity Services (BIS).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT16
name|Reserved2
decl_stmt|;
name|UINT32
name|BisEntry16
decl_stmt|;
name|UINT32
name|BisEntry32
decl_stmt|;
name|UINT64
name|Reserved3
decl_stmt|;
name|UINT32
name|Reserved4
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE31
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Boot Information - System Boot Status.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BootInformationStatusNoError
init|=
literal|0x00
block|,
name|BootInformationStatusNoBootableMedia
init|=
literal|0x01
block|,
name|BootInformationStatusNormalOSFailedLoading
init|=
literal|0x02
block|,
name|BootInformationStatusFirmwareDetectedFailure
init|=
literal|0x03
block|,
name|BootInformationStatusOSDetectedFailure
init|=
literal|0x04
block|,
name|BootInformationStatusUserRequestedBoot
init|=
literal|0x05
block|,
name|BootInformationStatusSystemSecurityViolation
init|=
literal|0x06
block|,
name|BootInformationStatusPreviousRequestedImage
init|=
literal|0x07
block|,
name|BootInformationStatusWatchdogTimerExpired
init|=
literal|0x08
block|,
name|BootInformationStatusStartReserved
init|=
literal|0x09
block|,
name|BootInformationStatusStartOemSpecific
init|=
literal|0x80
block|,
name|BootInformationStatusStartProductSpecific
init|=
literal|0xC0
block|}
name|MISC_BOOT_INFORMATION_STATUS_DATA_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Boot Information (Type 32).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The client system firmware, e.g. BIOS, communicates the System Boot Status to the
end_comment

begin_comment
comment|/// client's Pre-boot Execution Environment (PXE) boot image or OS-present management
end_comment

begin_comment
comment|/// application via this structure. When used in the PXE environment, for example,
end_comment

begin_comment
comment|/// this code identifies the reason the PXE was initiated and can be used by boot-image
end_comment

begin_comment
comment|/// software to further automate an enterprise's PXE sessions.  For example, an enterprise
end_comment

begin_comment
comment|/// could choose to automatically download a hardware-diagnostic image to a client whose
end_comment

begin_comment
comment|/// reason code indicated either a firmware- or operating system-detected hardware failure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|6
index|]
decl_stmt|;
name|UINT8
name|BootStatus
decl_stmt|;
comment|///< The enumeration value from MISC_BOOT_INFORMATION_STATUS_DATA_TYPE.
block|}
name|SMBIOS_TABLE_TYPE32
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 64-bit Memory Error Information (Type 33).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure describes an error within a Physical Memory Array,
end_comment

begin_comment
comment|/// when the error address is above 4G (0xFFFFFFFF).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|ErrorType
decl_stmt|;
comment|///< The enumeration value from MEMORY_ERROR_TYPE.
name|UINT8
name|ErrorGranularity
decl_stmt|;
comment|///< The enumeration value from MEMORY_ERROR_GRANULARITY.
name|UINT8
name|ErrorOperation
decl_stmt|;
comment|///< The enumeration value from MEMORY_ERROR_OPERATION.
name|UINT32
name|VendorSyndrome
decl_stmt|;
name|UINT64
name|MemoryArrayErrorAddress
decl_stmt|;
name|UINT64
name|DeviceErrorAddress
decl_stmt|;
name|UINT32
name|ErrorResolution
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE33
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Management Device -  Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ManagementDeviceTypeOther
init|=
literal|0x01
block|,
name|ManagementDeviceTypeUnknown
init|=
literal|0x02
block|,
name|ManagementDeviceTypeLm75
init|=
literal|0x03
block|,
name|ManagementDeviceTypeLm78
init|=
literal|0x04
block|,
name|ManagementDeviceTypeLm79
init|=
literal|0x05
block|,
name|ManagementDeviceTypeLm80
init|=
literal|0x06
block|,
name|ManagementDeviceTypeLm81
init|=
literal|0x07
block|,
name|ManagementDeviceTypeAdm9240
init|=
literal|0x08
block|,
name|ManagementDeviceTypeDs1780
init|=
literal|0x09
block|,
name|ManagementDeviceTypeMaxim1617
init|=
literal|0x0A
block|,
name|ManagementDeviceTypeGl518Sm
init|=
literal|0x0B
block|,
name|ManagementDeviceTypeW83781D
init|=
literal|0x0C
block|,
name|ManagementDeviceTypeHt82H791
init|=
literal|0x0D
block|}
name|MISC_MANAGEMENT_DEVICE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Management Device -  Address Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ManagementDeviceAddressTypeOther
init|=
literal|0x01
block|,
name|ManagementDeviceAddressTypeUnknown
init|=
literal|0x02
block|,
name|ManagementDeviceAddressTypeIOPort
init|=
literal|0x03
block|,
name|ManagementDeviceAddressTypeMemory
init|=
literal|0x04
block|,
name|ManagementDeviceAddressTypeSmbus
init|=
literal|0x05
block|}
name|MISC_MANAGEMENT_DEVICE_ADDRESS_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Management Device (Type 34).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of a Management Device.
end_comment

begin_comment
comment|/// A Management Device might control one or more fans or voltage, current, or temperature
end_comment

begin_comment
comment|/// probes as defined by one or more Management Device Component structures.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Description
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
comment|///< The enumeration value from MISC_MANAGEMENT_DEVICE_TYPE.
name|UINT32
name|Address
decl_stmt|;
name|UINT8
name|AddressType
decl_stmt|;
comment|///< The enumeration value from MISC_MANAGEMENT_DEVICE_ADDRESS_TYPE.
block|}
name|SMBIOS_TABLE_TYPE34
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Management Device Component (Type 35)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure associates a cooling device or environmental probe with structures
end_comment

begin_comment
comment|/// that define the controlling hardware device and (optionally) the component's thresholds.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Description
decl_stmt|;
name|UINT16
name|ManagementDeviceHandle
decl_stmt|;
name|UINT16
name|ComponentHandle
decl_stmt|;
name|UINT16
name|ThresholdHandle
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE35
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Management Device Threshold Data (Type 36).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines threshold information for
end_comment

begin_comment
comment|/// a component (probe or cooling-unit) contained within a Management Device.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT16
name|LowerThresholdNonCritical
decl_stmt|;
name|UINT16
name|UpperThresholdNonCritical
decl_stmt|;
name|UINT16
name|LowerThresholdCritical
decl_stmt|;
name|UINT16
name|UpperThresholdCritical
decl_stmt|;
name|UINT16
name|LowerThresholdNonRecoverable
decl_stmt|;
name|UINT16
name|UpperThresholdNonRecoverable
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE36
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Channel Entry.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DeviceLoad
decl_stmt|;
name|UINT16
name|DeviceHandle
decl_stmt|;
block|}
name|MEMORY_DEVICE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Channel - Channel Type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MemoryChannelTypeOther
init|=
literal|0x01
block|,
name|MemoryChannelTypeUnknown
init|=
literal|0x02
block|,
name|MemoryChannelTypeRambus
init|=
literal|0x03
block|,
name|MemoryChannelTypeSyncLink
init|=
literal|0x04
block|}
name|MEMORY_CHANNEL_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Channel (Type 37)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure provides the correlation between a Memory Channel
end_comment

begin_comment
comment|/// and its associated Memory Devices.  Each device presents one or more loads to the channel.
end_comment

begin_comment
comment|/// The sum of all device loads cannot exceed the channel's defined maximum.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|ChannelType
decl_stmt|;
name|UINT8
name|MaximumChannelLoad
decl_stmt|;
name|UINT8
name|MemoryDeviceCount
decl_stmt|;
name|MEMORY_DEVICE
name|MemoryDevice
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE37
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IPMI Device Information - BMC Interface Type
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IPMIDeviceInfoInterfaceTypeUnknown
init|=
literal|0x00
block|,
name|IPMIDeviceInfoInterfaceTypeKCS
init|=
literal|0x01
block|,
comment|///< The Keyboard Controller Style.
name|IPMIDeviceInfoInterfaceTypeSMIC
init|=
literal|0x02
block|,
comment|///< The Server Management Interface Chip.
name|IPMIDeviceInfoInterfaceTypeBT
init|=
literal|0x03
block|,
comment|///< The Block Transfer
name|IPMIDeviceInfoInterfaceTypeReserved
init|=
literal|0x04
block|}
name|BMC_INTERFACE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IPMI Device Information (Type 38).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of an
end_comment

begin_comment
comment|/// Intelligent Platform Management Interface (IPMI) Baseboard Management Controller (BMC).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Type 42 structure can also be used to describe a physical management controller
end_comment

begin_comment
comment|/// host interface and one or more protocols that share that interface. If IPMI is not
end_comment

begin_comment
comment|/// shared with other protocols, either the Type 38 or Type 42 structures can be used.
end_comment

begin_comment
comment|/// Providing Type 38 is recommended for backward compatibility.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|InterfaceType
decl_stmt|;
comment|///< The enumeration value from BMC_INTERFACE_TYPE.
name|UINT8
name|IPMISpecificationRevision
decl_stmt|;
name|UINT8
name|I2CSlaveAddress
decl_stmt|;
name|UINT8
name|NVStorageDeviceAddress
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT8
name|BaseAddressModifier_InterruptInfo
decl_stmt|;
name|UINT8
name|InterruptNumber
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE38
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Power Supply - Power Supply Characteristics.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|PowerSupplyHotReplaceable
range|:
literal|1
decl_stmt|;
name|UINT16
name|PowerSupplyPresent
range|:
literal|1
decl_stmt|;
name|UINT16
name|PowerSupplyUnplugged
range|:
literal|1
decl_stmt|;
name|UINT16
name|InputVoltageRangeSwitch
range|:
literal|4
decl_stmt|;
name|UINT16
name|PowerSupplyStatus
range|:
literal|3
decl_stmt|;
name|UINT16
name|PowerSupplyType
range|:
literal|4
decl_stmt|;
name|UINT16
name|Reserved
range|:
literal|2
decl_stmt|;
block|}
name|SYS_POWER_SUPPLY_CHARACTERISTICS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Power Supply (Type 39).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure identifies attributes of a system power supply. One instance
end_comment

begin_comment
comment|/// of this record is present for each possible power supply in a system.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|PowerUnitGroup
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Location
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|DeviceName
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Manufacturer
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|SerialNumber
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|AssetTagNumber
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|ModelPartNumber
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|RevisionLevel
decl_stmt|;
name|UINT16
name|MaxPowerCapacity
decl_stmt|;
name|SYS_POWER_SUPPLY_CHARACTERISTICS
name|PowerSupplyCharacteristics
decl_stmt|;
name|UINT16
name|InputVoltageProbeHandle
decl_stmt|;
name|UINT16
name|CoolingDeviceHandle
decl_stmt|;
name|UINT16
name|InputCurrentProbeHandle
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE39
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Additional Information Entry Format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|EntryLength
decl_stmt|;
name|UINT16
name|ReferencedHandle
decl_stmt|;
name|UINT8
name|ReferencedOffset
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|EntryString
decl_stmt|;
name|UINT8
name|Value
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ADDITIONAL_INFORMATION_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Additional Information (Type 40).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure is intended to provide additional information for handling unspecified
end_comment

begin_comment
comment|/// enumerated values and interim field updates in another structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|NumberOfAdditionalInformationEntries
decl_stmt|;
name|ADDITIONAL_INFORMATION_ENTRY
name|AdditionalInfoEntries
index|[
literal|1
index|]
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE40
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Onboard Devices Extended Information - Onboard Device Types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|OnBoardDeviceExtendedTypeOther
init|=
literal|0x01
block|,
name|OnBoardDeviceExtendedTypeUnknown
init|=
literal|0x02
block|,
name|OnBoardDeviceExtendedTypeVideo
init|=
literal|0x03
block|,
name|OnBoardDeviceExtendedTypeScsiController
init|=
literal|0x04
block|,
name|OnBoardDeviceExtendedTypeEthernet
init|=
literal|0x05
block|,
name|OnBoardDeviceExtendedTypeTokenRing
init|=
literal|0x06
block|,
name|OnBoardDeviceExtendedTypeSound
init|=
literal|0x07
block|,
name|OnBoardDeviceExtendedTypePATAController
init|=
literal|0x08
block|,
name|OnBoardDeviceExtendedTypeSATAController
init|=
literal|0x09
block|,
name|OnBoardDeviceExtendedTypeSASController
init|=
literal|0x0A
block|}
name|ONBOARD_DEVICE_EXTENDED_INFO_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Onboard Devices Extended Information (Type 41).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of devices that
end_comment

begin_comment
comment|/// are onboard (soldered onto) a system element, usually the baseboard.
end_comment

begin_comment
comment|/// In general, an entry in this table implies that the BIOS has some level of
end_comment

begin_comment
comment|/// control over the enabling of the associated device for use by the system.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|ReferenceDesignation
decl_stmt|;
name|UINT8
name|DeviceType
decl_stmt|;
comment|///< The enumeration value from ONBOARD_DEVICE_EXTENDED_INFO_TYPE
name|UINT8
name|DeviceTypeInstance
decl_stmt|;
name|UINT16
name|SegmentGroupNum
decl_stmt|;
name|UINT8
name|BusNum
decl_stmt|;
name|UINT8
name|DevFuncNum
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE41
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Management Controller Host Interface - Interface Types.
end_comment

begin_comment
comment|/// 00h - 3Fh: MCTP Host Interfaces
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MCHostInterfaceTypeNetworkHostInterface
init|=
literal|0x40
block|,
name|MCHostInterfaceTypeOemDefined
init|=
literal|0xF0
block|}
name|MC_HOST_INTERFACE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Management Controller Host Interface - Protocol Types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MCHostInterfaceProtocolTypeIPMI
init|=
literal|0x02
block|,
name|MCHostInterfaceProtocolTypeMCTP
init|=
literal|0x03
block|,
name|MCHostInterfaceProtocolTypeRedfishOverIP
init|=
literal|0x04
block|,
name|MCHostInterfaceProtocolTypeOemDefined
init|=
literal|0xF0
block|}
name|MC_HOST_INTERFACE_PROTOCOL_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Management Controller Host Interface (Type 42).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The information in this structure defines the attributes of a Management
end_comment

begin_comment
comment|/// Controller Host Interface that is not discoverable by "Plug and Play" mechanisms.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type 42 should be used for management controller host interfaces that use protocols
end_comment

begin_comment
comment|/// other than IPMI or that use multiple protocols on a single host interface type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure should also be provided if IPMI is shared with other protocols
end_comment

begin_comment
comment|/// over the same interface hardware. If IPMI is not shared with other protocols,
end_comment

begin_comment
comment|/// either the Type 38 or Type 42 structures can be used. Providing Type 38 is
end_comment

begin_comment
comment|/// recommended for backward compatibility. The structures are not required to
end_comment

begin_comment
comment|/// be mutually exclusive. Type 38 and Type 42 structures may be implemented
end_comment

begin_comment
comment|/// simultaneously to provide backward compatibility with IPMI applications or drivers
end_comment

begin_comment
comment|/// that do not yet recognize the Type 42 structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|InterfaceType
decl_stmt|;
comment|///< The enumeration value from MC_HOST_INTERFACE_TYPE
name|UINT8
name|MCHostInterfaceData
index|[
literal|1
index|]
decl_stmt|;
comment|///< This field has a minimum of four bytes
block|}
name|SMBIOS_TABLE_TYPE42
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// TPM Device (Type 43).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
name|UINT8
name|VendorID
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|MajorSpecVersion
decl_stmt|;
name|UINT8
name|MinorSpecVersion
decl_stmt|;
name|UINT32
name|FirmwareVersion1
decl_stmt|;
name|UINT32
name|FirmwareVersion2
decl_stmt|;
name|SMBIOS_TABLE_STRING
name|Description
decl_stmt|;
name|UINT64
name|Characteristics
decl_stmt|;
name|UINT32
name|OemDefined
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE43
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Inactive (Type 126)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE126
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// End-of-Table (Type 127)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SMBIOS_STRUCTURE
name|Hdr
decl_stmt|;
block|}
name|SMBIOS_TABLE_TYPE127
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Union of all the possible SMBIOS record types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|SMBIOS_STRUCTURE
modifier|*
name|Hdr
decl_stmt|;
name|SMBIOS_TABLE_TYPE0
modifier|*
name|Type0
decl_stmt|;
name|SMBIOS_TABLE_TYPE1
modifier|*
name|Type1
decl_stmt|;
name|SMBIOS_TABLE_TYPE2
modifier|*
name|Type2
decl_stmt|;
name|SMBIOS_TABLE_TYPE3
modifier|*
name|Type3
decl_stmt|;
name|SMBIOS_TABLE_TYPE4
modifier|*
name|Type4
decl_stmt|;
name|SMBIOS_TABLE_TYPE5
modifier|*
name|Type5
decl_stmt|;
name|SMBIOS_TABLE_TYPE6
modifier|*
name|Type6
decl_stmt|;
name|SMBIOS_TABLE_TYPE7
modifier|*
name|Type7
decl_stmt|;
name|SMBIOS_TABLE_TYPE8
modifier|*
name|Type8
decl_stmt|;
name|SMBIOS_TABLE_TYPE9
modifier|*
name|Type9
decl_stmt|;
name|SMBIOS_TABLE_TYPE10
modifier|*
name|Type10
decl_stmt|;
name|SMBIOS_TABLE_TYPE11
modifier|*
name|Type11
decl_stmt|;
name|SMBIOS_TABLE_TYPE12
modifier|*
name|Type12
decl_stmt|;
name|SMBIOS_TABLE_TYPE13
modifier|*
name|Type13
decl_stmt|;
name|SMBIOS_TABLE_TYPE14
modifier|*
name|Type14
decl_stmt|;
name|SMBIOS_TABLE_TYPE15
modifier|*
name|Type15
decl_stmt|;
name|SMBIOS_TABLE_TYPE16
modifier|*
name|Type16
decl_stmt|;
name|SMBIOS_TABLE_TYPE17
modifier|*
name|Type17
decl_stmt|;
name|SMBIOS_TABLE_TYPE18
modifier|*
name|Type18
decl_stmt|;
name|SMBIOS_TABLE_TYPE19
modifier|*
name|Type19
decl_stmt|;
name|SMBIOS_TABLE_TYPE20
modifier|*
name|Type20
decl_stmt|;
name|SMBIOS_TABLE_TYPE21
modifier|*
name|Type21
decl_stmt|;
name|SMBIOS_TABLE_TYPE22
modifier|*
name|Type22
decl_stmt|;
name|SMBIOS_TABLE_TYPE23
modifier|*
name|Type23
decl_stmt|;
name|SMBIOS_TABLE_TYPE24
modifier|*
name|Type24
decl_stmt|;
name|SMBIOS_TABLE_TYPE25
modifier|*
name|Type25
decl_stmt|;
name|SMBIOS_TABLE_TYPE26
modifier|*
name|Type26
decl_stmt|;
name|SMBIOS_TABLE_TYPE27
modifier|*
name|Type27
decl_stmt|;
name|SMBIOS_TABLE_TYPE28
modifier|*
name|Type28
decl_stmt|;
name|SMBIOS_TABLE_TYPE29
modifier|*
name|Type29
decl_stmt|;
name|SMBIOS_TABLE_TYPE30
modifier|*
name|Type30
decl_stmt|;
name|SMBIOS_TABLE_TYPE31
modifier|*
name|Type31
decl_stmt|;
name|SMBIOS_TABLE_TYPE32
modifier|*
name|Type32
decl_stmt|;
name|SMBIOS_TABLE_TYPE33
modifier|*
name|Type33
decl_stmt|;
name|SMBIOS_TABLE_TYPE34
modifier|*
name|Type34
decl_stmt|;
name|SMBIOS_TABLE_TYPE35
modifier|*
name|Type35
decl_stmt|;
name|SMBIOS_TABLE_TYPE36
modifier|*
name|Type36
decl_stmt|;
name|SMBIOS_TABLE_TYPE37
modifier|*
name|Type37
decl_stmt|;
name|SMBIOS_TABLE_TYPE38
modifier|*
name|Type38
decl_stmt|;
name|SMBIOS_TABLE_TYPE39
modifier|*
name|Type39
decl_stmt|;
name|SMBIOS_TABLE_TYPE40
modifier|*
name|Type40
decl_stmt|;
name|SMBIOS_TABLE_TYPE41
modifier|*
name|Type41
decl_stmt|;
name|SMBIOS_TABLE_TYPE42
modifier|*
name|Type42
decl_stmt|;
name|SMBIOS_TABLE_TYPE43
modifier|*
name|Type43
decl_stmt|;
name|SMBIOS_TABLE_TYPE126
modifier|*
name|Type126
decl_stmt|;
name|SMBIOS_TABLE_TYPE127
modifier|*
name|Type127
decl_stmt|;
name|UINT8
modifier|*
name|Raw
decl_stmt|;
block|}
name|SMBIOS_STRUCTURE_POINTER
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

