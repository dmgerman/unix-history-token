begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      ACPI Watchdog Action Table (WADT) as defined at   Microsoft Hardware Watchdog Timers Design Specification.    Copyright (c) 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WATCHDOG_ACTION_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_WATCHDOG_ACTION_TABLE_H_
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
comment|/// Watchdog Action Table definition.
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
name|WatchdogHeaderLength
decl_stmt|;
name|UINT16
name|PCISegment
decl_stmt|;
name|UINT8
name|PCIBusNumber
decl_stmt|;
name|UINT8
name|PCIDeviceNumber
decl_stmt|;
name|UINT8
name|PCIFunctionNumber
decl_stmt|;
name|UINT8
name|Reserved_45
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|TimerPeriod
decl_stmt|;
name|UINT32
name|MaxCount
decl_stmt|;
name|UINT32
name|MinCount
decl_stmt|;
name|UINT8
name|WatchdogFlags
decl_stmt|;
name|UINT8
name|Reserved_61
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|NumberWatchdogInstructionEntries
decl_stmt|;
block|}
name|EFI_ACPI_WATCHDOG_ACTION_1_0_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Watchdog Instruction Entries
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|WatchdogAction
decl_stmt|;
name|UINT8
name|InstructionFlags
decl_stmt|;
name|UINT8
name|Reserved_2
index|[
literal|2
index|]
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|RegisterRegion
decl_stmt|;
name|UINT32
name|Value
decl_stmt|;
name|UINT32
name|Mask
decl_stmt|;
block|}
name|EFI_ACPI_WATCHDOG_ACTION_1_0_WATCHDOG_ACTION_INSTRUCTION_ENTRY
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
comment|///
end_comment

begin_comment
comment|/// WDAT Revision (defined in spec)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_WATCHDOG_ACTION_1_0_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// WDAT 1.0 Flags
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ENABLED
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_STOPPED_IN_SLEEP_STATE
value|0x80
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// WDAT 1.0 Watchdog Actions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_RESET
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_QUERY_CURRENT_COUNTDOWN_PERIOD
value|0x4
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_QUERY_COUNTDOWN_PERIOD
value|0x5
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_SET_COUNTDOWN_PERIOD
value|0x6
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_QUERY_RUNNING_STATE
value|0x8
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_SET_RUNNING_STATE
value|0x9
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_QUERY_STOPPED_STATE
value|0xA
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_SET_STOPPED_STATE
value|0xB
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_QUERY_REBOOT
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_SET_REBOOT
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_QUERY_SHUTDOWN
value|0x12
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_SET_SHUTDOWN
value|0x13
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_QUERY_WATCHDOG_STATUS
value|0x20
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_ACTION_SET_WATCHDOG_STATUS
value|0x21
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// WDAT 1.0 Watchdog Action Entry Instruction Flags
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_INSTRUCTION_READ_VALUE
value|0x0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_INSTRUCTION_READ_COUNTDOWN
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_INSTRUCTION_WRITE_VALUE
value|0x2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_INSTRUCTION_WRITE_COUNTDOWN
value|0x3
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDAT_1_0_WATCHDOG_INSTRUCTION_PRESERVE_REGISTER
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

