begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   ACPI Low Power Idle Table (LPIT) definitions    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:     - ACPI Low Power Idle Table (LPIT) Revision 001, dated July 2014       http://www.uefi.org/sites/default/files/resources/ACPI_Low_Power_Idle_Table.pdf    @par Glossary:     - GAS - Generic Address Structure     - LPI - Low Power Idle **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOW_POWER_IDLE_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOW_POWER_IDLE_TABLE_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Acpi.h>
end_include

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
comment|/// LPI Structure Types
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ACPI_LPI_STRUCTURE_TYPE_NATIVE_CSTATE
value|0x00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Low Power Idle (LPI) State Flags
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|Disabled
range|:
literal|1
decl_stmt|;
comment|///< If set, LPI state is not used
comment|/**       If set, Residency counter is not available for this LPI state and       Residency Counter Frequency is invalid     **/
name|UINT32
name|CounterUnavailable
range|:
literal|1
decl_stmt|;
name|UINT32
name|Reserved
range|:
literal|30
decl_stmt|;
comment|///< Reserved for future use. Must be zero
block|}
name|Bits
struct|;
name|UINT32
name|Data32
decl_stmt|;
block|}
name|ACPI_LPI_STATE_FLAGS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Low Power Idle (LPI) structure with Native C-state instruction entry trigger descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Type
decl_stmt|;
comment|///< LPI State descriptor Type 0
name|UINT32
name|Length
decl_stmt|;
comment|///< Length of LPI state Descriptor Structure
comment|///
comment|/// Unique LPI state identifier: zero based, monotonically increasing identifier
comment|///
name|UINT16
name|UniqueId
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|///< Must be Zero
name|ACPI_LPI_STATE_FLAGS
name|Flags
decl_stmt|;
comment|///< LPI state flags
comment|/**     The LPI entry trigger, matching an existing _CST.Register object, represented as a     Generic Address Structure. All processors must request this state or deeper to trigger.   **/
name|EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE
name|EntryTrigger
decl_stmt|;
name|UINT32
name|Residency
decl_stmt|;
comment|///< Minimum residency or break-even in uSec
name|UINT32
name|Latency
decl_stmt|;
comment|///< Worst case exit latency in uSec
comment|/**     [optional] Residency counter, represented as a Generic Address Structure.     If not present, Flags[1] bit should be set.   **/
name|EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE
name|ResidencyCounter
decl_stmt|;
comment|/**     [optional] Residency counter frequency in cycles per second. Value 0 indicates that     counter runs at TSC frequency. Valid only if Residency Counter is present.   **/
name|UINT64
name|ResidencyCounterFrequency
decl_stmt|;
block|}
name|ACPI_LPI_NATIVE_CSTATE_DESCRIPTOR
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

