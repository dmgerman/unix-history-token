begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   ACPI high precision event timer table definition, at www.intel.com   Specification name is IA-PC HPET (High Precision Event Timers) Specification.        Copyright (c) 2007 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HIGH_PRECISION_EVENT_TIMER_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_HIGH_PRECISION_EVENT_TIMER_TABLE_H_
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
comment|/// High Precision Event Timer Table header definition.
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
name|EventTimerBlockId
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|BaseAddressLower32Bit
decl_stmt|;
name|UINT8
name|HpetNumber
decl_stmt|;
name|UINT16
name|MainCounterMinimumClockTickInPeriodicMode
decl_stmt|;
name|UINT8
name|PageProtectionAndOemAttribute
decl_stmt|;
block|}
name|EFI_ACPI_HIGH_PRECISION_EVENT_TIMER_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// HPET Revision (defined in spec)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_HIGH_PRECISION_EVENT_TIMER_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Page protection setting
end_comment

begin_comment
comment|// Values 3 through 15 are reserved for use by the specification
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_NO_PAGE_PROTECTION
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_4KB_PAGE_PROTECTION
value|1
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_64KB_PAGE_PROTECTION
value|2
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

