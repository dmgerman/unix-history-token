begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   ACPI Serial Port Console Redirection Table as defined by Microsoft in   http://www.microsoft.com/whdc/system/platform/server/spcr.mspx        Copyright (c) 2007 - 2015, Intel Corporation. All rights reserved.<BR>   (C) Copyright 2015 Hewlett Packard Enterprise Development LP<BR>   Copyright (c) 2014 - 2016, ARM Limited. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_H_
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
comment|///
end_comment

begin_comment
comment|/// SPCR Revision (defined in spec)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_REVISION
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Serial Port Console Redirection Table Format
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
name|InterfaceType
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
name|EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE
name|BaseAddress
decl_stmt|;
name|UINT8
name|InterruptType
decl_stmt|;
name|UINT8
name|Irq
decl_stmt|;
name|UINT32
name|GlobalSystemInterrupt
decl_stmt|;
name|UINT8
name|BaudRate
decl_stmt|;
name|UINT8
name|Parity
decl_stmt|;
name|UINT8
name|StopBits
decl_stmt|;
name|UINT8
name|FlowControl
decl_stmt|;
name|UINT8
name|TerminalType
decl_stmt|;
name|UINT8
name|Reserved2
decl_stmt|;
name|UINT16
name|PciDeviceId
decl_stmt|;
name|UINT16
name|PciVendorId
decl_stmt|;
name|UINT8
name|PciBusNumber
decl_stmt|;
name|UINT8
name|PciDeviceNumber
decl_stmt|;
name|UINT8
name|PciFunctionNumber
decl_stmt|;
name|UINT32
name|PciFlags
decl_stmt|;
name|UINT8
name|PciSegment
decl_stmt|;
name|UINT32
name|Reserved3
decl_stmt|;
block|}
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE
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
comment|// SPCR Definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Interface Type
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Full 16550 interface
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERFACE_TYPE_16550
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Full 16450 interface
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERFACE_TYPE_16450
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// The Serial Port Subtypes for ARM are documented in Table 3 of the DBG2 Specification
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ARM PL011 UART
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERFACE_TYPE_ARM_PL011_UART
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ARM SBSA Generic UART (2.x) supporting 32-bit only accesses [deprecated]
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERFACE_TYPE_ARM_SBSA_GENERIC_UART_2X
value|0x0d
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ARM SBSA Generic UART
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERFACE_TYPE_ARM_SBSA_GENERIC_UART
value|0x0e
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Interrupt Type
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PC-AT-compatible dual-8259 IRQ interrupt
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERRUPT_TYPE_8259
value|0x1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// I/O APIC interrupt (Global System Interrupt)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERRUPT_TYPE_APIC
value|0x2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// I/O SAPIC interrupt (Global System Interrupt)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERRUPT_TYPE_SAPIC
value|0x4
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ARMH GIC interrupt (Global System Interrupt)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERRUPT_TYPE_GIC
value|0x8
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Baud Rate
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_BAUD_RATE_9600
value|3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_BAUD_RATE_19200
value|4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_BAUD_RATE_57600
value|6
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_BAUD_RATE_115200
value|7
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Parity
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_PARITY_NO_PARITY
value|0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Stop Bits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_STOP_BITS_1
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Flow Control
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// DCD required for transmit
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_FLOW_CONTROL_DCD
value|0x1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// RTS/CTS hardware flow control
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_FLOW_CONTROL_RTS_CTS
value|0x2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|///  XON/XOFF software control
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_FLOW_CONTROL_XON_XOFF
value|0x4
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Terminal Type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_TERMINAL_TYPE_VT100
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_TERMINAL_TYPE_VT100_PLUS
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_TERMINAL_TYPE_VT_UTF8
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_TERMINAL_TYPE_ANSI
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

