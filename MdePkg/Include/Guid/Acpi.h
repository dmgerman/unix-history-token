begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUIDs used for ACPI entries in the EFI system table    These GUIDs point the ACPI tables as defined in the ACPI specifications.   ACPI 2.0 specification defines the ACPI 2.0 GUID. UEFI 2.0 defines the    ACPI 2.0 Table GUID and ACPI Table GUID.    Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUIDs defined in UEFI 2.0 spec.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPI_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACPI_GUID_H__
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_GUID
define|\
value|{ \     0xeb9d2d30, 0x2d88, 0x11d3, {0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_TABLE_GUID
define|\
value|{ \     0x8868e871, 0xe4f1, 0x11d3, {0xbc, 0x22, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } \   }
end_define

begin_define
define|#
directive|define
name|ACPI_10_TABLE_GUID
value|ACPI_TABLE_GUID
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ACPI 2.0 or newer tables should use EFI_ACPI_TABLE_GUID.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_20_TABLE_GUID
value|EFI_ACPI_TABLE_GUID
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAcpiTableGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAcpi10TableGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAcpi20TableGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

