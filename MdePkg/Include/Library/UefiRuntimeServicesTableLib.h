begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides a service to retrieve a pointer to the EFI Runtime Services Table.    This library does not contain any functions or macros.  It simply exports the   global variable gRT that is a pointer to the EFI Runtime Services Table as defined   in the UEFI Specification.  The global variable gRT must be preinitialized to NULL.   The library constructor must set gRT to point at the EFI Runtime Services Table so   it is available at the module's entry point. Since there is overhead in initializing   this global variable, only those modules that actually require access to the EFI   Runtime Services Table should use this library.   Only available to DXE and UEFI module types.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_RUNTIME_SERVICES_TABLE_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_RUNTIME_SERVICES_TABLE_LIB_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cached copy of the EFI Runtime Services Table
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_RUNTIME_SERVICES
modifier|*
name|gRT
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

