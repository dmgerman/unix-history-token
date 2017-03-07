begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   ACPI memory mapped configuration space access table definition, defined at    in the PCI Firmware Specification, version 3.0.   Specification is available at http://www.pcisig.com.        Copyright (c) 2007 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MEMORY_MAPPED_CONFIGURATION_SPACE_ACCESS_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MEMORY_MAPPED_CONFIGURATION_SPACE_ACCESS_TABLE_H_
end_define

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
comment|/// Memory Mapped Configuration Space Access Table (MCFG)
end_comment

begin_comment
comment|/// This table is a basic description table header followed by
end_comment

begin_comment
comment|/// a number of base address allocation structures.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT16
name|PciSegmentGroupNumber
decl_stmt|;
name|UINT8
name|StartBusNumber
decl_stmt|;
name|UINT8
name|EndBusNumber
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|EFI_ACPI_MEMORY_MAPPED_ENHANCED_CONFIGURATION_SPACE_BASE_ADDRESS_ALLOCATION_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MCFG Table header definition.  The rest of the table
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
name|UINT64
name|Reserved
decl_stmt|;
block|}
name|EFI_ACPI_MEMORY_MAPPED_CONFIGURATION_BASE_ADDRESS_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MCFG Revision (defined in spec)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_MAPPED_CONFIGURATION_SPACE_ACCESS_TABLE_REVISION
value|0x01
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

