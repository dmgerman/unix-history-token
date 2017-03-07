begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMM Services Table Library.    Copyright (c) 2009 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<PiSmm.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/SmmBase2.h>
end_include

begin_include
include|#
directive|include
file|<Library/SmmServicesTableLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_decl_stmt
name|EFI_SMM_SYSTEM_TABLE2
modifier|*
name|gSmst
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   The constructor function caches the pointer of SMM Services Table.    @param  ImageHandle   The firmware allocated handle for the EFI image.   @param  SystemTable   A pointer to the EFI System Table.    @retval EFI_SUCCESS   The constructor always returns EFI_SUCCESS.  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|SmmServicesTableLibConstructor
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
name|EFI_SMM_BASE2_PROTOCOL
modifier|*
name|InternalSmmBase2
decl_stmt|;
name|InternalSmmBase2
operator|=
name|NULL
expr_stmt|;
comment|//
comment|// Retrieve SMM Base2 Protocol,  Do not use gBS from UefiBootServicesTableLib on purpose
comment|// to prevent inclusion of gBS, gST, and gImageHandle from SMM Drivers unless the
comment|// SMM driver explicity declares that dependency.
comment|//
name|Status
operator|=
name|SystemTable
operator|->
name|BootServices
operator|->
name|LocateProtocol
argument_list|(
operator|&
name|gEfiSmmBase2ProtocolGuid
argument_list|,
name|NULL
argument_list|,
operator|(
name|VOID
operator|*
operator|*
operator|)
operator|&
name|InternalSmmBase2
argument_list|)
expr_stmt|;
name|ASSERT_EFI_ERROR
argument_list|(
name|Status
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|InternalSmmBase2
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//
comment|// We are in SMM, retrieve the pointer to SMM System Table
comment|//
name|InternalSmmBase2
operator|->
name|GetSmstLocation
argument_list|(
name|InternalSmmBase2
argument_list|,
operator|&
name|gSmst
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|gSmst
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|EFI_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/**   This function allows the caller to determine if the driver is executing in    System Management Mode(SMM).    This function returns TRUE if the driver is executing in SMM and FALSE if the    driver is not executing in SMM.    @retval  TRUE  The driver is executing in System Management Mode (SMM).   @retval  FALSE The driver is not executing in System Management Mode (SMM).   **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|InSmm
parameter_list|(
name|VOID
parameter_list|)
block|{
comment|//
comment|// We are already in SMM
comment|//
return|return
name|TRUE
return|;
block|}
end_function

end_unit

