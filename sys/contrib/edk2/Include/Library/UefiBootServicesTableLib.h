begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides a service to retrieve a pointer to the EFI Boot Services Table.   Only available to DXE and UEFI module types.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_BOOT_SERVICES_TABLE_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_BOOT_SERVICES_TABLE_LIB_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache the Image Handle
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_HANDLE
name|gImageHandle
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache pointer to the EFI System Table
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_SYSTEM_TABLE
modifier|*
name|gST
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache pointer to the EFI Boot Services Table
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_BOOT_SERVICES
modifier|*
name|gBS
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

