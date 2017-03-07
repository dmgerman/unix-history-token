begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI Runtime Services Table Library.    This library instance retrieve EFI_RUNTIME_SERVICES pointer from EFI system table   in library's constructor.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Uefi.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_decl_stmt
name|EFI_RUNTIME_SERVICES
modifier|*
name|gRT
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   The constructor function caches the pointer of Runtime Services Table.    The constructor function caches the pointer of Runtime Services Table.   It will ASSERT() if the pointer of Runtime Services Table is NULL.   It will always return EFI_SUCCESS.    @param  ImageHandle   The firmware allocated handle for the EFI image.   @param  SystemTable   A pointer to the EFI System Table.    @retval EFI_SUCCESS   The constructor always returns EFI_SUCCESS.  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|UefiRuntimeServicesTableLibConstructor
parameter_list|(
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|)
block|{
comment|//
comment|// Cache pointer to the EFI Runtime Services Table
comment|//
name|gRT
operator|=
name|SystemTable
operator|->
name|RuntimeServices
expr_stmt|;
name|ASSERT
argument_list|(
name|gRT
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|EFI_SUCCESS
return|;
block|}
end_function

end_unit

