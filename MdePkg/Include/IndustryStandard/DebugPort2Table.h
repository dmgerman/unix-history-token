begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      ACPI debug port 2 table definition, defined at    Microsoft DebugPort2Specification.    Copyright (c) 2012, Intel Corporation. All rights reserved.<BR>   Copyright (c) 2012 - 2016, ARM Limited. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEBUG_PORT_2_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEBUG_PORT_2_TABLE_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Acpi.h>
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
comment|//
end_comment

begin_comment
comment|// Debug Device Information structure.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Revision
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|NumberofGenericAddressRegisters
decl_stmt|;
name|UINT16
name|NameSpaceStringLength
decl_stmt|;
name|UINT16
name|NameSpaceStringOffset
decl_stmt|;
name|UINT16
name|OemDataLength
decl_stmt|;
name|UINT16
name|OemDataOffset
decl_stmt|;
name|UINT16
name|PortType
decl_stmt|;
name|UINT16
name|PortSubtype
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|BaseAddressRegisterOffset
decl_stmt|;
name|UINT16
name|AddressSizeOffset
decl_stmt|;
block|}
name|EFI_ACPI_DBG2_DEBUG_DEVICE_INFORMATION_STRUCT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_DEBUG_DEVICE_INFORMATION_STRUCT_REVISION
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_TYPE_SERIAL
value|0x8000
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_SERIAL_FULL_16550
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_SERIAL_16550_SUBSET_COMPATIBLE_WITH_MS_DBGP_SPEC
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_SERIAL_ARM_PL011_UART
value|0x0003
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_SERIAL_ARM_SBSA_GENERIC_UART_2X
value|0x000d
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_SERIAL_ARM_SBSA_GENERIC_UART
value|0x000e
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_SERIAL_DCC
value|0x000f
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_SERIAL_BCM2835_UART
value|0x0010
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_TYPE_1394
value|0x8001
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_1394_STANDARD
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_TYPE_USB
value|0x8002
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_USB_XHCI
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_SUBTYPE_USB_EHCI
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBG2_PORT_TYPE_NET
value|0x8003
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Debug Port 2 Table definition.
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
name|OffsetDbgDeviceInfo
decl_stmt|;
name|UINT32
name|NumberDbgDeviceInfo
decl_stmt|;
block|}
name|EFI_ACPI_DEBUG_PORT_2_DESCRIPTION_TABLE
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
comment|// DBG2 Revision (defined in spec)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_DEBUG_PORT_2_TABLE_REVISION
value|0x00
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

