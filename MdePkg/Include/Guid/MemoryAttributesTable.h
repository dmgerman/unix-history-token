begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUIDs used for UEFI Memory Attributes Table in the UEFI 2.6 specification.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_MEMORY_ATTRIBUTES_TABLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_MEMORY_ATTRIBUTES_TABLE_H__
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_ATTRIBUTES_TABLE_GUID
value|{\   0xdcfa911d, 0x26eb, 0x469f, {0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20} \ }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Version
decl_stmt|;
name|UINT32
name|NumberOfEntries
decl_stmt|;
name|UINT32
name|DescriptorSize
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
comment|//EFI_MEMORY_DESCRIPTOR Entry[1];
block|}
name|EFI_MEMORY_ATTRIBUTES_TABLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_MEMORY_ATTRIBUTES_TABLE_VERSION
value|0x00000001
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiMemoryAttributesTableGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

