begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides a service to retrieve a pointer to the DXE Services Table.   Only available to DXE module types.      This library does not contain any functions or macros.  It simply exports a global    pointer to the DXE Services Table as defined in the Platform Initialization Driver    Execution Environment Core Interface Specification.  The library constructor must    initialize this global pointer to the DX Services Table, so it is available at the   module's entry point.  Since there is overhead in looking up the pointer to the DXE    Services Table, only those modules that actually require access to the DXE Services    Table should use this library.  This will typically be DXE Drivers that require GCD    or Dispatcher services.     Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DXE_SERVICES_TABLE_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__DXE_SERVICES_TABLE_LIB_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cache copy of the DXE Services Table
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_DXE_SERVICES
modifier|*
name|gDS
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

