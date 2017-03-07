begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This library implement library class DxeServiceTableLib.   It produce EFI_DXE_SERVICE pointer in global variable gDS in library's constructure.      A DXE driver can use gDS pointer to access services in EFI_DXE_SERVICE, if this   DXE driver declare that use DxeServicesTableLib library class and link to this    library instance.    Please attention this library instance can not be used util EFI_SYSTEM_TABLE was    initialized.      This library contains contruct function to retrieve EFI_DXE_SERIVCE, this construct   function will be invoked in DXE driver's autogen file.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<PiDxe.h>
end_include

begin_include
include|#
directive|include
file|<Guid/DxeServices.h>
end_include

begin_include
include|#
directive|include
file|<Library/DxeServicesTableLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiLib.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Cache copy of the DXE Services Table
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|EFI_DXE_SERVICES
modifier|*
name|gDS
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   The constructor function caches the pointer of DXE Services Table.    The constructor function caches the pointer of DXE Services Table.   It will ASSERT() if that operation fails.   It will ASSERT() if the pointer of DXE Services Table is NULL.   It will always return EFI_SUCCESS.    @param  ImageHandle   The firmware allocated handle for the EFI image.   @param  SystemTable   A pointer to the EFI System Table.    @retval EFI_SUCCESS   The constructor always returns EFI_SUCCESS.  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|DxeServicesTableLibConstructor
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
name|EFI_STATUS
name|Status
decl_stmt|;
comment|//
comment|// Cache copy of the DXE Services Table
comment|//
name|Status
operator|=
name|EfiGetSystemConfigurationTable
argument_list|(
operator|&
name|gEfiDxeServicesTableGuid
argument_list|,
operator|(
name|VOID
operator|*
operator|*
operator|)
operator|&
name|gDS
argument_list|)
expr_stmt|;
name|ASSERT_EFI_ERROR
argument_list|(
name|Status
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|gDS
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|Status
return|;
block|}
end_function

end_unit

