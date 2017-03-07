begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUIDs used for UEFI Properties Table in the UEFI 2.5 specification.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_PROPERTIES_TABLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_PROPERTIES_TABLE_H__
end_define

begin_define
define|#
directive|define
name|EFI_PROPERTIES_TABLE_GUID
value|{\   0x880aaca3, 0x4adc, 0x4a04, {0x90, 0x79, 0xb7, 0x47, 0x34, 0x8, 0x25, 0xe5} \ }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Version
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT64
name|MemoryProtectionAttribute
decl_stmt|;
block|}
name|EFI_PROPERTIES_TABLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_PROPERTIES_TABLE_VERSION
value|0x00010000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Memory attribute (Not defined bit is reserved)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PROPERTIES_RUNTIME_MEMORY_PROTECTION_NON_EXECUTABLE_PE_DATA
value|0x1
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPropertiesTableGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

