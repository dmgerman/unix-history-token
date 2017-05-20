begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The device path protocol as defined in UEFI 2.0.    The device path represents a programmatic path to a device,   from a software point of view. The path must persist from boot to boot, so    it can not contain things like PCI bus numbers that change from boot to boot.  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_DEVICE_PATH_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_DEVICE_PATH_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Guid/PcAnsi.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/Bluetooth.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/Acpi60.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device Path protocol.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEVICE_PATH_PROTOCOL_GUID
define|\
value|{ \     0x9576e91, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device Path guid definition for backward-compatible with EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DEVICE_PATH_PROTOCOL
value|EFI_DEVICE_PATH_PROTOCOL_GUID
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
comment|/**   This protocol can be used on any device handle to obtain generic path/location    information concerning the physical device or logical device. If the handle does    not logically map to a physical device, the handle may not necessarily support    the device path protocol. The device path describes the location of the device    the handle is for. The size of the Device Path can be determined from the structures    that make up the Device Path. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
comment|///< 0x01 Hardware Device Path.
comment|///< 0x02 ACPI Device Path.
comment|///< 0x03 Messaging Device Path.
comment|///< 0x04 Media Device Path.
comment|///< 0x05 BIOS Boot Specification Device Path.
comment|///< 0x7F End of Hardware Device Path.
name|UINT8
name|SubType
decl_stmt|;
comment|///< Varies by Type
comment|///< 0xFF End Entire Device Path, or
comment|///< 0x01 End This Instance of a Device Path and start a new
comment|///< Device Path.
name|UINT8
name|Length
index|[
literal|2
index|]
decl_stmt|;
comment|///< Specific Device Path data. Type and Sub-Type define
comment|///< type of data. Size of data is included in Length.
block|}
name|EFI_DEVICE_PATH_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device Path protocol definition for backward-compatible with EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
name|EFI_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Hardware Device Paths.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HARDWARE_DEVICE_PATH
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HW_PCI_DP
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Device Path.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// PCI Function Number.
comment|///
name|UINT8
name|Function
decl_stmt|;
comment|///
comment|/// PCI Device Number.
comment|///
name|UINT8
name|Device
decl_stmt|;
block|}
name|PCI_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCCARD Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HW_PCCARD_DP
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCCARD Device Path.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Function Number (0 = First Function).
comment|///
name|UINT8
name|FunctionNumber
decl_stmt|;
block|}
name|PCCARD_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Mapped Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HW_MEMMAP_DP
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Mapped Device Path.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// EFI_MEMORY_TYPE
comment|///
name|UINT32
name|MemoryType
decl_stmt|;
comment|///
comment|/// Starting Memory Address.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|StartingAddress
decl_stmt|;
comment|///
comment|/// Ending Memory Address.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|EndingAddress
decl_stmt|;
block|}
name|MEMMAP_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Hardware Vendor Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HW_VENDOR_DP
value|0x04
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Vendor Device Path allows the creation of vendor-defined Device Paths. A vendor must
end_comment

begin_comment
comment|/// allocate a Vendor GUID for a Device Path. The Vendor GUID can then be used to define the
end_comment

begin_comment
comment|/// contents on the n bytes that follow in the Vendor Device Path node.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Vendor-assigned GUID that defines the data that follows.
comment|///
name|EFI_GUID
name|Guid
decl_stmt|;
comment|///
comment|/// Vendor-defined variable size data.
comment|///
block|}
name|VENDOR_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Controller Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HW_CONTROLLER_DP
value|0x05
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Controller Device Path.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Controller number.
comment|///
name|UINT32
name|ControllerNumber
decl_stmt|;
block|}
name|CONTROLLER_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BMC Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|HW_BMC_DP
value|0x06
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// BMC Device Path.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Interface Type.
comment|///
name|UINT8
name|InterfaceType
decl_stmt|;
comment|///
comment|/// Base Address.
comment|///
name|UINT8
name|BaseAddress
index|[
literal|8
index|]
decl_stmt|;
block|}
name|BMC_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI Device Paths.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ACPI_DEVICE_PATH
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ACPI_DP
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Device's PnP hardware ID stored in a numeric 32-bit
comment|/// compressed EISA-type ID. This value must match the
comment|/// corresponding _HID in the ACPI name space.
comment|///
name|UINT32
name|HID
decl_stmt|;
comment|///
comment|/// Unique ID that is required by ACPI if two devices have the
comment|/// same _HID. This value must also match the corresponding
comment|/// _UID/_HID pair in the ACPI name space. Only the 32-bit
comment|/// numeric value type of _UID is supported. Thus, strings must
comment|/// not be used for the _UID in the ACPI name space.
comment|///
name|UINT32
name|UID
decl_stmt|;
block|}
name|ACPI_HID_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Expanded ACPI Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ACPI_EXTENDED_DP
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Device's PnP hardware ID stored in a numeric 32-bit
comment|/// compressed EISA-type ID. This value must match the
comment|/// corresponding _HID in the ACPI name space.
comment|///
name|UINT32
name|HID
decl_stmt|;
comment|///
comment|/// Unique ID that is required by ACPI if two devices have the
comment|/// same _HID. This value must also match the corresponding
comment|/// _UID/_HID pair in the ACPI name space.
comment|///
name|UINT32
name|UID
decl_stmt|;
comment|///
comment|/// Device's compatible PnP hardware ID stored in a numeric
comment|/// 32-bit compressed EISA-type ID. This value must match at
comment|/// least one of the compatible device IDs returned by the
comment|/// corresponding _CID in the ACPI name space.
comment|///
name|UINT32
name|CID
decl_stmt|;
comment|///
comment|/// Optional variable length _HIDSTR.
comment|/// Optional variable length _UIDSTR.
comment|/// Optional variable length _CIDSTR.
comment|///
block|}
name|ACPI_EXTENDED_HID_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  EISA ID Macro
end_comment

begin_comment
comment|//  EISA ID Definition 32-bits
end_comment

begin_comment
comment|//   bits[15:0] - three character compressed ASCII EISA ID.
end_comment

begin_comment
comment|//   bits[31:16] - binary number
end_comment

begin_comment
comment|//    Compressed ASCII is 5 bits per character 0b00001 = 'A' 0b11010 = 'Z'
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PNP_EISA_ID_CONST
value|0x41d0
end_define

begin_define
define|#
directive|define
name|EISA_ID
parameter_list|(
name|_Name
parameter_list|,
name|_Num
parameter_list|)
value|((UINT32)((_Name) | (_Num)<< 16))
end_define

begin_define
define|#
directive|define
name|EISA_PNP_ID
parameter_list|(
name|_PNPId
parameter_list|)
value|(EISA_ID(PNP_EISA_ID_CONST, (_PNPId)))
end_define

begin_define
define|#
directive|define
name|EFI_PNP_ID
parameter_list|(
name|_PNPId
parameter_list|)
value|(EISA_ID(PNP_EISA_ID_CONST, (_PNPId)))
end_define

begin_define
define|#
directive|define
name|PNP_EISA_ID_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|EISA_ID_TO_NUM
parameter_list|(
name|_Id
parameter_list|)
value|((_Id)>> 16)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ACPI _ADR Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ACPI_ADR_DP
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The _ADR device path is used to contain video output device attributes to support the Graphics
end_comment

begin_comment
comment|/// Output Protocol. The device path can contain multiple _ADR entries if multiple video output
end_comment

begin_comment
comment|/// devices are displaying the same output.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// _ADR value. For video output devices the value of this
comment|/// field comes from Table B-2 of the ACPI 3.0 specification. At
comment|/// least one _ADR value is required.
comment|///
name|UINT32
name|ADR
decl_stmt|;
comment|//
comment|// This device path may optionally contain more than one _ADR entry.
comment|//
block|}
name|ACPI_ADR_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_ADR_DISPLAY_TYPE_OTHER
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_DISPLAY_TYPE_VGA
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_DISPLAY_TYPE_TV
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_DISPLAY_TYPE_EXTERNAL_DIGITAL
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_DISPLAY_TYPE_INTERNAL_DIGITAL
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_DISPLAY_ADR
parameter_list|(
name|_DeviceIdScheme
parameter_list|,
name|_HeadId
parameter_list|,
name|_NonVgaOutput
parameter_list|,
name|_BiosCanDetect
parameter_list|,
name|_VendorInfo
parameter_list|,
name|_Type
parameter_list|,
name|_Port
parameter_list|,
name|_Index
parameter_list|)
define|\
value|((UINT32)(  ((UINT32)((_DeviceIdScheme)& 0x1)<< 31) |  \                       (((_HeadId)& 0x7)<< 18) |  \                       (((_NonVgaOutput)& 0x1)<< 17) |  \                       (((_BiosCanDetect)& 0x1)<< 16) |  \                       (((_VendorInfo)& 0xf)<< 12) |  \                       (((_Type)& 0xf)<< 8)  |  \                       (((_Port)& 0xf)<< 4)  |  \                        ((_Index)& 0xf) ))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Messaging Device Paths.
end_comment

begin_comment
comment|/// This Device Path is used to describe the connection of devices outside the resource domain of the
end_comment

begin_comment
comment|/// system. This Device Path can describe physical messaging information like SCSI ID, or abstract
end_comment

begin_comment
comment|/// information like networking protocol IP addresses.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MESSAGING_DEVICE_PATH
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ATAPI Device Path SubType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_ATAPI_DP
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Set to zero for primary, or one for secondary.
comment|///
name|UINT8
name|PrimarySecondary
decl_stmt|;
comment|///
comment|/// Set to zero for master, or one for slave mode.
comment|///
name|UINT8
name|SlaveMaster
decl_stmt|;
comment|///
comment|/// Logical Unit Number.
comment|///
name|UINT16
name|Lun
decl_stmt|;
block|}
name|ATAPI_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SCSI Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_SCSI_DP
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Target ID on the SCSI bus (PUN).
comment|///
name|UINT16
name|Pun
decl_stmt|;
comment|///
comment|/// Logical Unit Number (LUN).
comment|///
name|UINT16
name|Lun
decl_stmt|;
block|}
name|SCSI_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Fibre Channel SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_FIBRECHANNEL_DP
value|0x03
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Reserved for the future.
comment|///
name|UINT32
name|Reserved
decl_stmt|;
comment|///
comment|/// Fibre Channel World Wide Number.
comment|///
name|UINT64
name|WWN
decl_stmt|;
comment|///
comment|/// Fibre Channel Logical Unit Number.
comment|///
name|UINT64
name|Lun
decl_stmt|;
block|}
name|FIBRECHANNEL_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Fibre Channel Ex SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_FIBRECHANNELEX_DP
value|0x15
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Reserved for the future.
comment|///
name|UINT32
name|Reserved
decl_stmt|;
comment|///
comment|/// 8 byte array containing Fibre Channel End Device Port Name.
comment|///
name|UINT8
name|WWN
index|[
literal|8
index|]
decl_stmt|;
comment|///
comment|/// 8 byte array containing Fibre Channel Logical Unit Number.
comment|///
name|UINT8
name|Lun
index|[
literal|8
index|]
decl_stmt|;
block|}
name|FIBRECHANNELEX_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1394 Device Path SubType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_1394_DP
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Reserved for the future.
comment|///
name|UINT32
name|Reserved
decl_stmt|;
comment|///
comment|/// 1394 Global Unique ID (GUID).
comment|///
name|UINT64
name|Guid
decl_stmt|;
block|}
name|F1394_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// USB Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_USB_DP
value|0x05
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// USB Parent Port Number.
comment|///
name|UINT8
name|ParentPortNumber
decl_stmt|;
comment|///
comment|/// USB Interface Number.
comment|///
name|UINT8
name|InterfaceNumber
decl_stmt|;
block|}
name|USB_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// USB Class Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_USB_CLASS_DP
value|0x0f
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Vendor ID assigned by USB-IF. A value of 0xFFFF will
comment|/// match any Vendor ID.
comment|///
name|UINT16
name|VendorId
decl_stmt|;
comment|///
comment|/// Product ID assigned by USB-IF. A value of 0xFFFF will
comment|/// match any Product ID.
comment|///
name|UINT16
name|ProductId
decl_stmt|;
comment|///
comment|/// The class code assigned by the USB-IF. A value of 0xFF
comment|/// will match any class code.
comment|///
name|UINT8
name|DeviceClass
decl_stmt|;
comment|///
comment|/// The subclass code assigned by the USB-IF. A value of
comment|/// 0xFF will match any subclass code.
comment|///
name|UINT8
name|DeviceSubClass
decl_stmt|;
comment|///
comment|/// The protocol code assigned by the USB-IF. A value of
comment|/// 0xFF will match any protocol code.
comment|///
name|UINT8
name|DeviceProtocol
decl_stmt|;
block|}
name|USB_CLASS_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// USB WWID Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_USB_WWID_DP
value|0x10
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This device path describes a USB device using its serial number.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// USB interface number.
comment|///
name|UINT16
name|InterfaceNumber
decl_stmt|;
comment|///
comment|/// USB vendor id of the device.
comment|///
name|UINT16
name|VendorId
decl_stmt|;
comment|///
comment|/// USB product id of the device.
comment|///
name|UINT16
name|ProductId
decl_stmt|;
comment|///
comment|/// Last 64-or-fewer UTF-16 characters of the USB
comment|/// serial number. The length of the string is
comment|/// determined by the Length field less the offset of the
comment|/// Serial Number field (10)
comment|///
comment|/// CHAR16                     SerialNumber[...];
block|}
name|USB_WWID_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device Logical Unit SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_DEVICE_LOGICAL_UNIT_DP
value|0x11
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Logical Unit Number for the interface.
comment|///
name|UINT8
name|Lun
decl_stmt|;
block|}
name|DEVICE_LOGICAL_UNIT_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SATA Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_SATA_DP
value|0x12
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// The HBA port number that facilitates the connection to the
comment|/// device or a port multiplier. The value 0xFFFF is reserved.
comment|///
name|UINT16
name|HBAPortNumber
decl_stmt|;
comment|///
comment|/// The Port multiplier port number that facilitates the connection
comment|/// to the device. Must be set to 0xFFFF if the device is directly
comment|/// connected to the HBA.
comment|///
name|UINT16
name|PortMultiplierPortNumber
decl_stmt|;
comment|///
comment|/// Logical Unit Number.
comment|///
name|UINT16
name|Lun
decl_stmt|;
block|}
name|SATA_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Flag for if the device is directly connected to the HBA.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SATA_HBA_DIRECT_CONNECT_FLAG
value|0x8000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// I2O Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_I2O_DP
value|0x06
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Target ID (TID) for a device.
comment|///
name|UINT32
name|Tid
decl_stmt|;
block|}
name|I2O_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MAC Address Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_MAC_ADDR_DP
value|0x0b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// The MAC address for a network interface padded with 0s.
comment|///
name|EFI_MAC_ADDRESS
name|MacAddress
decl_stmt|;
comment|///
comment|/// Network interface type(i.e. 802.3, FDDI).
comment|///
name|UINT8
name|IfType
decl_stmt|;
block|}
name|MAC_ADDR_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IPv4 Device Path SubType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_IPv4_DP
value|0x0c
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// The local IPv4 address.
comment|///
name|EFI_IPv4_ADDRESS
name|LocalIpAddress
decl_stmt|;
comment|///
comment|/// The remote IPv4 address.
comment|///
name|EFI_IPv4_ADDRESS
name|RemoteIpAddress
decl_stmt|;
comment|///
comment|/// The local port number.
comment|///
name|UINT16
name|LocalPort
decl_stmt|;
comment|///
comment|/// The remote port number.
comment|///
name|UINT16
name|RemotePort
decl_stmt|;
comment|///
comment|/// The network protocol(i.e. UDP, TCP).
comment|///
name|UINT16
name|Protocol
decl_stmt|;
comment|///
comment|/// 0x00 - The Source IP Address was assigned though DHCP.
comment|/// 0x01 - The Source IP Address is statically bound.
comment|///
name|BOOLEAN
name|StaticIpAddress
decl_stmt|;
comment|///
comment|/// The gateway IP address
comment|///
name|EFI_IPv4_ADDRESS
name|GatewayIpAddress
decl_stmt|;
comment|///
comment|/// The subnet mask
comment|///
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
block|}
name|IPv4_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IPv6 Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_IPv6_DP
value|0x0d
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// The local IPv6 address.
comment|///
name|EFI_IPv6_ADDRESS
name|LocalIpAddress
decl_stmt|;
comment|///
comment|/// The remote IPv6 address.
comment|///
name|EFI_IPv6_ADDRESS
name|RemoteIpAddress
decl_stmt|;
comment|///
comment|/// The local port number.
comment|///
name|UINT16
name|LocalPort
decl_stmt|;
comment|///
comment|/// The remote port number.
comment|///
name|UINT16
name|RemotePort
decl_stmt|;
comment|///
comment|/// The network protocol(i.e. UDP, TCP).
comment|///
name|UINT16
name|Protocol
decl_stmt|;
comment|///
comment|/// 0x00 - The Local IP Address was manually configured.
comment|/// 0x01 - The Local IP Address is assigned through IPv6
comment|/// stateless auto-configuration.
comment|/// 0x02 - The Local IP Address is assigned through IPv6
comment|/// stateful configuration.
comment|///
name|UINT8
name|IpAddressOrigin
decl_stmt|;
comment|///
comment|/// The prefix length
comment|///
name|UINT8
name|PrefixLength
decl_stmt|;
comment|///
comment|/// The gateway IP address
comment|///
name|EFI_IPv6_ADDRESS
name|GatewayIpAddress
decl_stmt|;
block|}
name|IPv6_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// InfiniBand Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_INFINIBAND_DP
value|0x09
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Flags to help identify/manage InfiniBand device path elements:
comment|/// Bit 0 - IOC/Service (0b = IOC, 1b = Service).
comment|/// Bit 1 - Extend Boot Environment.
comment|/// Bit 2 - Console Protocol.
comment|/// Bit 3 - Storage Protocol.
comment|/// Bit 4 - Network Protocol.
comment|/// All other bits are reserved.
comment|///
name|UINT32
name|ResourceFlags
decl_stmt|;
comment|///
comment|/// 128-bit Global Identifier for remote fabric port.
comment|///
name|UINT8
name|PortGid
index|[
literal|16
index|]
decl_stmt|;
comment|///
comment|/// 64-bit unique identifier to remote IOC or server process.
comment|/// Interpretation of field specified by Resource Flags (bit 0).
comment|///
name|UINT64
name|ServiceId
decl_stmt|;
comment|///
comment|/// 64-bit persistent ID of remote IOC port.
comment|///
name|UINT64
name|TargetPortId
decl_stmt|;
comment|///
comment|/// 64-bit persistent ID of remote device.
comment|///
name|UINT64
name|DeviceId
decl_stmt|;
block|}
name|INFINIBAND_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INFINIBAND_RESOURCE_FLAG_IOC_SERVICE
value|0x01
end_define

begin_define
define|#
directive|define
name|INFINIBAND_RESOURCE_FLAG_EXTENDED_BOOT_ENVIRONMENT
value|0x02
end_define

begin_define
define|#
directive|define
name|INFINIBAND_RESOURCE_FLAG_CONSOLE_PROTOCOL
value|0x04
end_define

begin_define
define|#
directive|define
name|INFINIBAND_RESOURCE_FLAG_STORAGE_PROTOCOL
value|0x08
end_define

begin_define
define|#
directive|define
name|INFINIBAND_RESOURCE_FLAG_NETWORK_PROTOCOL
value|0x10
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UART Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_UART_DP
value|0x0e
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Reserved.
comment|///
name|UINT32
name|Reserved
decl_stmt|;
comment|///
comment|/// The baud rate setting for the UART style device. A value of 0
comment|/// means that the device's default baud rate will be used.
comment|///
name|UINT64
name|BaudRate
decl_stmt|;
comment|///
comment|/// The number of data bits for the UART style device. A value
comment|/// of 0 means that the device's default number of data bits will be used.
comment|///
name|UINT8
name|DataBits
decl_stmt|;
comment|///
comment|/// The parity setting for the UART style device.
comment|/// Parity 0x00 - Default Parity.
comment|/// Parity 0x01 - No Parity.
comment|/// Parity 0x02 - Even Parity.
comment|/// Parity 0x03 - Odd Parity.
comment|/// Parity 0x04 - Mark Parity.
comment|/// Parity 0x05 - Space Parity.
comment|///
name|UINT8
name|Parity
decl_stmt|;
comment|///
comment|/// The number of stop bits for the UART style device.
comment|/// Stop Bits 0x00 - Default Stop Bits.
comment|/// Stop Bits 0x01 - 1 Stop Bit.
comment|/// Stop Bits 0x02 - 1.5 Stop Bits.
comment|/// Stop Bits 0x03 - 2 Stop Bits.
comment|///
name|UINT8
name|StopBits
decl_stmt|;
block|}
name|UART_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Use VENDOR_DEVICE_PATH struct
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MSG_VENDOR_DP
value|0x0a
end_define

begin_typedef
typedef|typedef
name|VENDOR_DEVICE_PATH
name|VENDOR_DEFINED_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEVICE_PATH_MESSAGING_PC_ANSI
value|EFI_PC_ANSI_GUID
end_define

begin_define
define|#
directive|define
name|DEVICE_PATH_MESSAGING_VT_100
value|EFI_VT_100_GUID
end_define

begin_define
define|#
directive|define
name|DEVICE_PATH_MESSAGING_VT_100_PLUS
value|EFI_VT_100_PLUS_GUID
end_define

begin_define
define|#
directive|define
name|DEVICE_PATH_MESSAGING_VT_UTF8
value|EFI_VT_UTF8_GUID
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A new device path node is defined to declare flow control characteristics.
end_comment

begin_comment
comment|/// UART Flow Control Messaging Device Path
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// DEVICE_PATH_MESSAGING_UART_FLOW_CONTROL GUID.
comment|///
name|EFI_GUID
name|Guid
decl_stmt|;
comment|///
comment|/// Bitmap of supported flow control types.
comment|/// Bit 0 set indicates hardware flow control.
comment|/// Bit 1 set indicates Xon/Xoff flow control.
comment|/// All other bits are reserved and are clear.
comment|///
name|UINT32
name|FlowControlMap
decl_stmt|;
block|}
name|UART_FLOW_CONTROL_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UART_FLOW_CONTROL_HARDWARE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|UART_FLOW_CONTROL_XON_XOFF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DEVICE_PATH_MESSAGING_SAS
value|EFI_SAS_DEVICE_PATH_GUID
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Serial Attached SCSI (SAS) Device Path.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// DEVICE_PATH_MESSAGING_SAS GUID.
comment|///
name|EFI_GUID
name|Guid
decl_stmt|;
comment|///
comment|/// Reserved for future use.
comment|///
name|UINT32
name|Reserved
decl_stmt|;
comment|///
comment|/// SAS Address for Serial Attached SCSI Target.
comment|///
name|UINT64
name|SasAddress
decl_stmt|;
comment|///
comment|/// SAS Logical Unit Number.
comment|///
name|UINT64
name|Lun
decl_stmt|;
comment|///
comment|/// More Information about the device and its interconnect.
comment|///
name|UINT16
name|DeviceTopology
decl_stmt|;
comment|///
comment|/// Relative Target Port (RTP).
comment|///
name|UINT16
name|RelativeTargetPort
decl_stmt|;
block|}
name|SAS_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Serial Attached SCSI (SAS) Ex Device Path SubType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_SASEX_DP
value|0x16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// 8-byte array of the SAS Address for Serial Attached SCSI Target Port.
comment|///
name|UINT8
name|SasAddress
index|[
literal|8
index|]
decl_stmt|;
comment|///
comment|/// 8-byte array of the SAS Logical Unit Number.
comment|///
name|UINT8
name|Lun
index|[
literal|8
index|]
decl_stmt|;
comment|///
comment|/// More Information about the device and its interconnect.
comment|///
name|UINT16
name|DeviceTopology
decl_stmt|;
comment|///
comment|/// Relative Target Port (RTP).
comment|///
name|UINT16
name|RelativeTargetPort
decl_stmt|;
block|}
name|SASEX_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// NvmExpress Namespace Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_NVME_NAMESPACE_DP
value|0x17
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|UINT32
name|NamespaceId
decl_stmt|;
name|UINT64
name|NamespaceUuid
decl_stmt|;
block|}
name|NVME_NAMESPACE_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Uniform Resource Identifiers (URI) Device Path SubType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_URI_DP
value|0x18
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Instance of the URI pursuant to RFC 3986.
comment|///
name|CHAR8
name|Uri
index|[]
decl_stmt|;
block|}
name|URI_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Universal Flash Storage (UFS) Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_UFS_DP
value|0x19
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Target ID on the UFS bus (PUN).
comment|///
name|UINT8
name|Pun
decl_stmt|;
comment|///
comment|/// Logical Unit Number (LUN).
comment|///
name|UINT8
name|Lun
decl_stmt|;
block|}
name|UFS_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SD (Secure Digital) Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_SD_DP
value|0x1A
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|UINT8
name|SlotNumber
decl_stmt|;
block|}
name|SD_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EMMC (Embedded MMC) Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_EMMC_DP
value|0x1D
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|UINT8
name|SlotNumber
decl_stmt|;
block|}
name|EMMC_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// iSCSI Device Path SubType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_ISCSI_DP
value|0x13
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Network Protocol (0 = TCP, 1+ = reserved).
comment|///
name|UINT16
name|NetworkProtocol
decl_stmt|;
comment|///
comment|/// iSCSI Login Options.
comment|///
name|UINT16
name|LoginOption
decl_stmt|;
comment|///
comment|/// iSCSI Logical Unit Number.
comment|///
name|UINT64
name|Lun
decl_stmt|;
comment|///
comment|/// iSCSI Target Portal group tag the initiator intends
comment|/// to establish a session with.
comment|///
name|UINT16
name|TargetPortalGroupTag
decl_stmt|;
comment|///
comment|/// iSCSI NodeTarget Name. The length of the name
comment|/// is determined by subtracting the offset of this field from Length.
comment|///
comment|/// CHAR8                        iSCSI Target Name.
block|}
name|ISCSI_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISCSI_LOGIN_OPTION_NO_HEADER_DIGEST
value|0x0000
end_define

begin_define
define|#
directive|define
name|ISCSI_LOGIN_OPTION_HEADER_DIGEST_USING_CRC32C
value|0x0002
end_define

begin_define
define|#
directive|define
name|ISCSI_LOGIN_OPTION_NO_DATA_DIGEST
value|0x0000
end_define

begin_define
define|#
directive|define
name|ISCSI_LOGIN_OPTION_DATA_DIGEST_USING_CRC32C
value|0x0008
end_define

begin_define
define|#
directive|define
name|ISCSI_LOGIN_OPTION_AUTHMETHOD_CHAP
value|0x0000
end_define

begin_define
define|#
directive|define
name|ISCSI_LOGIN_OPTION_AUTHMETHOD_NON
value|0x1000
end_define

begin_define
define|#
directive|define
name|ISCSI_LOGIN_OPTION_CHAP_BI
value|0x0000
end_define

begin_define
define|#
directive|define
name|ISCSI_LOGIN_OPTION_CHAP_UNI
value|0x2000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// VLAN Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_VLAN_DP
value|0x14
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// VLAN identifier (0-4094).
comment|///
name|UINT16
name|VlanId
decl_stmt|;
block|}
name|VLAN_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Bluetooth Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_BLUETOOTH_DP
value|0x1b
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// 48bit Bluetooth device address.
comment|///
name|BLUETOOTH_ADDRESS
name|BD_ADDR
decl_stmt|;
block|}
name|BLUETOOTH_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Wi-Fi Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MSG_WIFI_DP
value|0x1C
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Service set identifier. A 32-byte octets string.
comment|///
name|UINT8
name|SSId
index|[
literal|32
index|]
decl_stmt|;
block|}
name|WIFI_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Media Device Path
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MEDIA_DEVICE_PATH
value|0x04
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Hard Drive Media Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MEDIA_HARDDRIVE_DP
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Hard Drive Media Device Path is used to represent a partition on a hard drive.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Describes the entry in a partition table, starting with entry 1.
comment|/// Partition number zero represents the entire device. Valid
comment|/// partition numbers for a MBR partition are [1, 4]. Valid
comment|/// partition numbers for a GPT partition are [1, NumberOfPartitionEntries].
comment|///
name|UINT32
name|PartitionNumber
decl_stmt|;
comment|///
comment|/// Starting LBA of the partition on the hard drive.
comment|///
name|UINT64
name|PartitionStart
decl_stmt|;
comment|///
comment|/// Size of the partition in units of Logical Blocks.
comment|///
name|UINT64
name|PartitionSize
decl_stmt|;
comment|///
comment|/// Signature unique to this partition:
comment|/// If SignatureType is 0, this field has to be initialized with 16 zeros.
comment|/// If SignatureType is 1, the MBR signature is stored in the first 4 bytes of this field.
comment|/// The other 12 bytes are initialized with zeros.
comment|/// If SignatureType is 2, this field contains a 16 byte signature.
comment|///
name|UINT8
name|Signature
index|[
literal|16
index|]
decl_stmt|;
comment|///
comment|/// Partition Format: (Unused values reserved).
comment|/// 0x01 - PC-AT compatible legacy MBR.
comment|/// 0x02 - GUID Partition Table.
comment|///
name|UINT8
name|MBRType
decl_stmt|;
comment|///
comment|/// Type of Disk Signature: (Unused values reserved).
comment|/// 0x00 - No Disk Signature.
comment|/// 0x01 - 32-bit signature from address 0x1b8 of the type 0x01 MBR.
comment|/// 0x02 - GUID signature.
comment|///
name|UINT8
name|SignatureType
decl_stmt|;
block|}
name|HARDDRIVE_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MBR_TYPE_PCAT
value|0x01
end_define

begin_define
define|#
directive|define
name|MBR_TYPE_EFI_PARTITION_TABLE_HEADER
value|0x02
end_define

begin_define
define|#
directive|define
name|NO_DISK_SIGNATURE
value|0x00
end_define

begin_define
define|#
directive|define
name|SIGNATURE_TYPE_MBR
value|0x01
end_define

begin_define
define|#
directive|define
name|SIGNATURE_TYPE_GUID
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// CD-ROM Media Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MEDIA_CDROM_DP
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The CD-ROM Media Device Path is used to define a system partition that exists on a CD-ROM.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Boot Entry number from the Boot Catalog. The Initial/Default entry is defined as zero.
comment|///
name|UINT32
name|BootEntry
decl_stmt|;
comment|///
comment|/// Starting RBA of the partition on the medium. CD-ROMs use Relative logical Block Addressing.
comment|///
name|UINT64
name|PartitionStart
decl_stmt|;
comment|///
comment|/// Size of the partition in units of Blocks, also called Sectors.
comment|///
name|UINT64
name|PartitionSize
decl_stmt|;
block|}
name|CDROM_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Use VENDOR_DEVICE_PATH struct
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MEDIA_VENDOR_DP
value|0x03
end_define

begin_comment
comment|///< Media vendor device path subtype.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// File Path Media Device Path SubType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MEDIA_FILEPATH_DP
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// A NULL-terminated Path string including directory and file names.
comment|///
name|CHAR16
name|PathName
index|[
literal|1
index|]
decl_stmt|;
block|}
name|FILEPATH_DEVICE_PATH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SIZE_OF_FILEPATH_DEVICE_PATH
value|OFFSET_OF(FILEPATH_DEVICE_PATH,PathName)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Media Protocol Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MEDIA_PROTOCOL_DP
value|0x05
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Media Protocol Device Path is used to denote the protocol that is being
end_comment

begin_comment
comment|/// used in a device path at the location of the path specified.
end_comment

begin_comment
comment|/// Many protocols are inherent to the style of device path.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// The ID of the protocol.
comment|///
name|EFI_GUID
name|Protocol
decl_stmt|;
block|}
name|MEDIA_PROTOCOL_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PIWG Firmware File SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MEDIA_PIWG_FW_FILE_DP
value|0x06
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This device path is used by systems implementing the UEFI PI Specification 1.0 to describe a firmware file.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Firmware file name
comment|///
name|EFI_GUID
name|FvFileName
decl_stmt|;
block|}
name|MEDIA_FW_VOL_FILEPATH_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PIWG Firmware Volume Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MEDIA_PIWG_FW_VOL_DP
value|0x07
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This device path is used by systems implementing the UEFI PI Specification 1.0 to describe a firmware volume.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Firmware volume name.
comment|///
name|EFI_GUID
name|FvName
decl_stmt|;
block|}
name|MEDIA_FW_VOL_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Media relative offset range device path.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MEDIA_RELATIVE_OFFSET_RANGE_DP
value|0x08
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used to describe the offset range of media relative.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT64
name|StartingOffset
decl_stmt|;
name|UINT64
name|EndingOffset
decl_stmt|;
block|}
name|MEDIA_RELATIVE_OFFSET_RANGE_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This GUID defines a RAM Disk supporting a raw disk format in volatile memory.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_VIRTUAL_DISK_GUID
value|EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_DISK_REGION_VOLATILE
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiVirtualDiskGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// This GUID defines a RAM Disk supporting an ISO image in volatile memory.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_VIRTUAL_CD_GUID
value|EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_CD_REGION_VOLATILE
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiVirtualCdGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// This GUID defines a RAM Disk supporting a raw disk format in persistent memory.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PERSISTENT_VIRTUAL_DISK_GUID
value|EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_DISK_REGION_PERSISTENT
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPersistentVirtualDiskGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// This GUID defines a RAM Disk supporting an ISO image in persistent memory.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PERSISTENT_VIRTUAL_CD_GUID
value|EFI_ACPI_6_0_NFIT_GUID_RAM_DISK_SUPPORTING_VIRTUAL_CD_REGION_PERSISTENT
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPersistentVirtualCdGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// Media ram disk device path.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MEDIA_RAM_DISK_DP
value|0x09
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used to describe the ram disk device path.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Starting Memory Address.
comment|///
name|UINT32
name|StartingAddr
index|[
literal|2
index|]
decl_stmt|;
comment|///
comment|/// Ending Memory Address.
comment|///
name|UINT32
name|EndingAddr
index|[
literal|2
index|]
decl_stmt|;
comment|///
comment|/// GUID that defines the type of the RAM Disk.
comment|///
name|EFI_GUID
name|TypeGuid
decl_stmt|;
comment|///
comment|/// RAM Diskinstance number, if supported. The default value is zero.
comment|///
name|UINT16
name|Instance
decl_stmt|;
block|}
name|MEDIA_RAM_DISK_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// BIOS Boot Specification Device Path.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|BBS_DEVICE_PATH
value|0x05
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// BIOS Boot Specification Device Path SubType.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|BBS_BBS_DP
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This Device Path is used to describe the booting of non-EFI-aware operating systems.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
comment|///
comment|/// Device Type as defined by the BIOS Boot Specification.
comment|///
name|UINT16
name|DeviceType
decl_stmt|;
comment|///
comment|/// Status Flags as defined by the BIOS Boot Specification.
comment|///
name|UINT16
name|StatusFlag
decl_stmt|;
comment|///
comment|/// Null-terminated ASCII string that describes the boot device to a user.
comment|///
name|CHAR8
name|String
index|[
literal|1
index|]
decl_stmt|;
block|}
name|BBS_BBS_DEVICE_PATH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// DeviceType definitions - from BBS specification
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|BBS_TYPE_FLOPPY
value|0x01
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_HARDDRIVE
value|0x02
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_CDROM
value|0x03
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_PCMCIA
value|0x04
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_USB
value|0x05
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_EMBEDDED_NETWORK
value|0x06
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_BEV
value|0x80
end_define

begin_define
define|#
directive|define
name|BBS_TYPE_UNKNOWN
value|0xFF
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Union of all possible Device Paths and pointers to Device Paths.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|DevPath
decl_stmt|;
name|PCI_DEVICE_PATH
name|Pci
decl_stmt|;
name|PCCARD_DEVICE_PATH
name|PcCard
decl_stmt|;
name|MEMMAP_DEVICE_PATH
name|MemMap
decl_stmt|;
name|VENDOR_DEVICE_PATH
name|Vendor
decl_stmt|;
name|CONTROLLER_DEVICE_PATH
name|Controller
decl_stmt|;
name|BMC_DEVICE_PATH
name|Bmc
decl_stmt|;
name|ACPI_HID_DEVICE_PATH
name|Acpi
decl_stmt|;
name|ACPI_EXTENDED_HID_DEVICE_PATH
name|ExtendedAcpi
decl_stmt|;
name|ACPI_ADR_DEVICE_PATH
name|AcpiAdr
decl_stmt|;
name|ATAPI_DEVICE_PATH
name|Atapi
decl_stmt|;
name|SCSI_DEVICE_PATH
name|Scsi
decl_stmt|;
name|ISCSI_DEVICE_PATH
name|Iscsi
decl_stmt|;
name|FIBRECHANNEL_DEVICE_PATH
name|FibreChannel
decl_stmt|;
name|FIBRECHANNELEX_DEVICE_PATH
name|FibreChannelEx
decl_stmt|;
name|F1394_DEVICE_PATH
name|F1394
decl_stmt|;
name|USB_DEVICE_PATH
name|Usb
decl_stmt|;
name|SATA_DEVICE_PATH
name|Sata
decl_stmt|;
name|USB_CLASS_DEVICE_PATH
name|UsbClass
decl_stmt|;
name|USB_WWID_DEVICE_PATH
name|UsbWwid
decl_stmt|;
name|DEVICE_LOGICAL_UNIT_DEVICE_PATH
name|LogicUnit
decl_stmt|;
name|I2O_DEVICE_PATH
name|I2O
decl_stmt|;
name|MAC_ADDR_DEVICE_PATH
name|MacAddr
decl_stmt|;
name|IPv4_DEVICE_PATH
name|Ipv4
decl_stmt|;
name|IPv6_DEVICE_PATH
name|Ipv6
decl_stmt|;
name|VLAN_DEVICE_PATH
name|Vlan
decl_stmt|;
name|INFINIBAND_DEVICE_PATH
name|InfiniBand
decl_stmt|;
name|UART_DEVICE_PATH
name|Uart
decl_stmt|;
name|UART_FLOW_CONTROL_DEVICE_PATH
name|UartFlowControl
decl_stmt|;
name|SAS_DEVICE_PATH
name|Sas
decl_stmt|;
name|SASEX_DEVICE_PATH
name|SasEx
decl_stmt|;
name|NVME_NAMESPACE_DEVICE_PATH
name|NvmeNamespace
decl_stmt|;
name|URI_DEVICE_PATH
name|Uri
decl_stmt|;
name|BLUETOOTH_DEVICE_PATH
name|Bluetooth
decl_stmt|;
name|WIFI_DEVICE_PATH
name|WiFi
decl_stmt|;
name|UFS_DEVICE_PATH
name|Ufs
decl_stmt|;
name|SD_DEVICE_PATH
name|Sd
decl_stmt|;
name|EMMC_DEVICE_PATH
name|Emmc
decl_stmt|;
name|HARDDRIVE_DEVICE_PATH
name|HardDrive
decl_stmt|;
name|CDROM_DEVICE_PATH
name|CD
decl_stmt|;
name|FILEPATH_DEVICE_PATH
name|FilePath
decl_stmt|;
name|MEDIA_PROTOCOL_DEVICE_PATH
name|MediaProtocol
decl_stmt|;
name|MEDIA_FW_VOL_DEVICE_PATH
name|FirmwareVolume
decl_stmt|;
name|MEDIA_FW_VOL_FILEPATH_DEVICE_PATH
name|FirmwareFile
decl_stmt|;
name|MEDIA_RELATIVE_OFFSET_RANGE_DEVICE_PATH
name|Offset
decl_stmt|;
name|MEDIA_RAM_DISK_DEVICE_PATH
name|RamDisk
decl_stmt|;
name|BBS_BBS_DEVICE_PATH
name|Bbs
decl_stmt|;
block|}
name|EFI_DEV_PATH
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevPath
decl_stmt|;
name|PCI_DEVICE_PATH
modifier|*
name|Pci
decl_stmt|;
name|PCCARD_DEVICE_PATH
modifier|*
name|PcCard
decl_stmt|;
name|MEMMAP_DEVICE_PATH
modifier|*
name|MemMap
decl_stmt|;
name|VENDOR_DEVICE_PATH
modifier|*
name|Vendor
decl_stmt|;
name|CONTROLLER_DEVICE_PATH
modifier|*
name|Controller
decl_stmt|;
name|BMC_DEVICE_PATH
modifier|*
name|Bmc
decl_stmt|;
name|ACPI_HID_DEVICE_PATH
modifier|*
name|Acpi
decl_stmt|;
name|ACPI_EXTENDED_HID_DEVICE_PATH
modifier|*
name|ExtendedAcpi
decl_stmt|;
name|ACPI_ADR_DEVICE_PATH
modifier|*
name|AcpiAdr
decl_stmt|;
name|ATAPI_DEVICE_PATH
modifier|*
name|Atapi
decl_stmt|;
name|SCSI_DEVICE_PATH
modifier|*
name|Scsi
decl_stmt|;
name|ISCSI_DEVICE_PATH
modifier|*
name|Iscsi
decl_stmt|;
name|FIBRECHANNEL_DEVICE_PATH
modifier|*
name|FibreChannel
decl_stmt|;
name|FIBRECHANNELEX_DEVICE_PATH
modifier|*
name|FibreChannelEx
decl_stmt|;
name|F1394_DEVICE_PATH
modifier|*
name|F1394
decl_stmt|;
name|USB_DEVICE_PATH
modifier|*
name|Usb
decl_stmt|;
name|SATA_DEVICE_PATH
modifier|*
name|Sata
decl_stmt|;
name|USB_CLASS_DEVICE_PATH
modifier|*
name|UsbClass
decl_stmt|;
name|USB_WWID_DEVICE_PATH
modifier|*
name|UsbWwid
decl_stmt|;
name|DEVICE_LOGICAL_UNIT_DEVICE_PATH
modifier|*
name|LogicUnit
decl_stmt|;
name|I2O_DEVICE_PATH
modifier|*
name|I2O
decl_stmt|;
name|MAC_ADDR_DEVICE_PATH
modifier|*
name|MacAddr
decl_stmt|;
name|IPv4_DEVICE_PATH
modifier|*
name|Ipv4
decl_stmt|;
name|IPv6_DEVICE_PATH
modifier|*
name|Ipv6
decl_stmt|;
name|VLAN_DEVICE_PATH
modifier|*
name|Vlan
decl_stmt|;
name|INFINIBAND_DEVICE_PATH
modifier|*
name|InfiniBand
decl_stmt|;
name|UART_DEVICE_PATH
modifier|*
name|Uart
decl_stmt|;
name|UART_FLOW_CONTROL_DEVICE_PATH
modifier|*
name|UartFlowControl
decl_stmt|;
name|SAS_DEVICE_PATH
modifier|*
name|Sas
decl_stmt|;
name|SASEX_DEVICE_PATH
modifier|*
name|SasEx
decl_stmt|;
name|NVME_NAMESPACE_DEVICE_PATH
modifier|*
name|NvmeNamespace
decl_stmt|;
name|URI_DEVICE_PATH
modifier|*
name|Uri
decl_stmt|;
name|BLUETOOTH_DEVICE_PATH
modifier|*
name|Bluetooth
decl_stmt|;
name|WIFI_DEVICE_PATH
modifier|*
name|WiFi
decl_stmt|;
name|UFS_DEVICE_PATH
modifier|*
name|Ufs
decl_stmt|;
name|SD_DEVICE_PATH
modifier|*
name|Sd
decl_stmt|;
name|EMMC_DEVICE_PATH
modifier|*
name|Emmc
decl_stmt|;
name|HARDDRIVE_DEVICE_PATH
modifier|*
name|HardDrive
decl_stmt|;
name|CDROM_DEVICE_PATH
modifier|*
name|CD
decl_stmt|;
name|FILEPATH_DEVICE_PATH
modifier|*
name|FilePath
decl_stmt|;
name|MEDIA_PROTOCOL_DEVICE_PATH
modifier|*
name|MediaProtocol
decl_stmt|;
name|MEDIA_FW_VOL_DEVICE_PATH
modifier|*
name|FirmwareVolume
decl_stmt|;
name|MEDIA_FW_VOL_FILEPATH_DEVICE_PATH
modifier|*
name|FirmwareFile
decl_stmt|;
name|MEDIA_RELATIVE_OFFSET_RANGE_DEVICE_PATH
modifier|*
name|Offset
decl_stmt|;
name|MEDIA_RAM_DISK_DEVICE_PATH
modifier|*
name|RamDisk
decl_stmt|;
name|BBS_BBS_DEVICE_PATH
modifier|*
name|Bbs
decl_stmt|;
name|UINT8
modifier|*
name|Raw
decl_stmt|;
block|}
name|EFI_DEV_PATH_PTR
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|END_DEVICE_PATH_TYPE
value|0x7f
end_define

begin_define
define|#
directive|define
name|END_ENTIRE_DEVICE_PATH_SUBTYPE
value|0xFF
end_define

begin_define
define|#
directive|define
name|END_INSTANCE_DEVICE_PATH_SUBTYPE
value|0x01
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDevicePathProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

