begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI ACPI Data Table Definition.  Copyright (c) 2011 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_ACPI_DATA_TABLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_ACPI_DATA_TABLE_H__
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|GUID
name|Identifier
decl_stmt|;
name|UINT16
name|DataOffset
decl_stmt|;
block|}
name|EFI_ACPI_DATA_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DATA_TABLE
name|UefiAcpiDataTable
decl_stmt|;
name|UINT32
name|SwSmiNumber
decl_stmt|;
name|UINT64
name|BufferPtrAddress
decl_stmt|;
block|}
name|EFI_SMM_COMMUNICATION_ACPI_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_SMM_COMMUNICATION_ACPI_TABLE
name|UefiSmmCommunicationAcpiTable
decl_stmt|;
name|EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE
name|InvocationRegister
decl_stmt|;
block|}
name|EFI_SMM_COMMUNICATION_ACPI_TABLE_2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// To avoid confusion in interpreting frames, the communication buffer should always
end_comment

begin_comment
comment|/// begin with EFI_SMM_COMMUNICATE_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Allows for disambiguation of the message format.
comment|///
name|EFI_GUID
name|HeaderGuid
decl_stmt|;
comment|///
comment|/// Describes the size of Data (in bytes) and does not include the size of the header.
comment|///
name|UINTN
name|MessageLength
decl_stmt|;
comment|///
comment|/// Designates an array of bytes that is MessageLength in size.
comment|///
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_SMM_COMMUNICATE_HEADER
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

