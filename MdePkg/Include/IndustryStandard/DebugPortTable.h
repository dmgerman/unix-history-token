begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      ACPI debug port table definition, defined at    Microsoft DebugPortSpecification.    Copyright (c) 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEBUG_PORT_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEBUG_PORT_TABLE_H_
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
comment|// Debug Port Table definition.
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
name|UINT8
name|InterfaceType
decl_stmt|;
name|UINT8
name|Reserved_37
index|[
literal|3
index|]
decl_stmt|;
name|EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE
name|BaseAddress
decl_stmt|;
block|}
name|EFI_ACPI_DEBUG_PORT_DESCRIPTION_TABLE
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
comment|// DBGP Revision (defined in spec)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_DEBUG_PORT_TABLE_REVISION
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Interface Type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_DBGP_INTERFACE_TYPE_FULL_16550
value|0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DBGP_INTERFACE_TYPE_16550_SUBSET_COMPATIBLE_WITH_MS_DBGP_SPEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

