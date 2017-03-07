begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   TPM2 ACPI table definition.  Copyright (c) 2013 - 2017, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TPM2_ACPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_TPM2_ACPI_H_
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

begin_define
define|#
directive|define
name|EFI_TPM2_ACPI_TABLE_REVISION_3
value|3
end_define

begin_define
define|#
directive|define
name|EFI_TPM2_ACPI_TABLE_REVISION_4
value|4
end_define

begin_define
define|#
directive|define
name|EFI_TPM2_ACPI_TABLE_REVISION
value|EFI_TPM2_ACPI_TABLE_REVISION_4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
comment|// Flags field is replaced in version 4 and above
comment|//    BIT0~15:  PlatformClass      This field is only valid for version 4 and above
comment|//    BIT16~31: Reserved
name|UINT32
name|Flags
decl_stmt|;
name|UINT64
name|AddressOfControlArea
decl_stmt|;
name|UINT32
name|StartMethod
decl_stmt|;
comment|//UINT8                       PlatformSpecificParameters[];
block|}
name|EFI_TPM2_ACPI_TABLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_TPM2_ACPI_TABLE_START_METHOD_ACPI
value|2
end_define

begin_define
define|#
directive|define
name|EFI_TPM2_ACPI_TABLE_START_METHOD_TIS
value|6
end_define

begin_define
define|#
directive|define
name|EFI_TPM2_ACPI_TABLE_START_METHOD_COMMAND_RESPONSE_BUFFER_INTERFACE
value|7
end_define

begin_define
define|#
directive|define
name|EFI_TPM2_ACPI_TABLE_START_METHOD_COMMAND_RESPONSE_BUFFER_INTERFACE_WITH_ACPI
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Reserved
decl_stmt|;
name|UINT32
name|Error
decl_stmt|;
name|UINT32
name|Cancel
decl_stmt|;
name|UINT32
name|Start
decl_stmt|;
name|UINT64
name|InterruptControl
decl_stmt|;
name|UINT32
name|CommandSize
decl_stmt|;
name|UINT64
name|Command
decl_stmt|;
name|UINT32
name|ResponseSize
decl_stmt|;
name|UINT64
name|Response
decl_stmt|;
block|}
name|EFI_TPM2_ACPI_CONTROL_AREA
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

