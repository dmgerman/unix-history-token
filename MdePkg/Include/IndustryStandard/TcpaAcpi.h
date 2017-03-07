begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   TCPA ACPI table definition.  Copyright (c) 2013, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCPA_ACPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_TCPA_ACPI_H_
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
name|_EFI_TCG_CLIENT_ACPI_TABLE
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT16
name|PlatformClass
decl_stmt|;
name|UINT32
name|Laml
decl_stmt|;
name|UINT64
name|Lasa
decl_stmt|;
block|}
name|EFI_TCG_CLIENT_ACPI_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_TCG_SERVER_ACPI_TABLE
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT16
name|PlatformClass
decl_stmt|;
name|UINT16
name|Reserved0
decl_stmt|;
name|UINT64
name|Laml
decl_stmt|;
name|UINT64
name|Lasa
decl_stmt|;
name|UINT16
name|SpecRev
decl_stmt|;
name|UINT8
name|DeviceFlags
decl_stmt|;
name|UINT8
name|InterruptFlags
decl_stmt|;
name|UINT8
name|Gpe
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|GlobalSysInt
decl_stmt|;
name|EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE
name|BaseAddress
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
name|EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE
name|ConfigAddress
decl_stmt|;
name|UINT8
name|PciSegNum
decl_stmt|;
name|UINT8
name|PciBusNum
decl_stmt|;
name|UINT8
name|PciDevNum
decl_stmt|;
name|UINT8
name|PciFuncNum
decl_stmt|;
block|}
name|EFI_TCG_SERVER_ACPI_TABLE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG Platform Type based on TCG ACPI Specification Version 1.00
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TCG_PLATFORM_TYPE_CLIENT
value|0
end_define

begin_define
define|#
directive|define
name|TCG_PLATFORM_TYPE_SERVER
value|1
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

