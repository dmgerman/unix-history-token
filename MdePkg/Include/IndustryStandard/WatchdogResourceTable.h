begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      ACPI Watchdog Resource Table (WDRT) as defined at   Microsoft Windows Hardware Developer Central.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WATCHDOG_RESOURCE_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_WATCHDOG_RESOURCE_TABLE_H_
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
comment|/// Watchdog Resource Table definition.
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
name|ControlRegisterAddress
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|CountRegisterAddress
decl_stmt|;
name|UINT16
name|PCIDeviceID
decl_stmt|;
name|UINT16
name|PCIVendorID
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
name|PCISegment
decl_stmt|;
name|UINT16
name|MaxCount
decl_stmt|;
name|UINT8
name|Units
decl_stmt|;
block|}
name|EFI_ACPI_WATCHDOG_RESOURCE_1_0_TABLE
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
comment|// WDRT Revision (defined in spec)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_WATCHDOG_RESOURCE_1_0_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// WDRT 1.0 Count Unit
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_WDRT_1_0_COUNT_UNIT_1_SEC_PER_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDRT_1_0_COUNT_UNIT_100_MILLISEC_PER_COUNT
value|2
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_WDRT_1_0_COUNT_UNIT_10_MILLISEC_PER_COUNT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

