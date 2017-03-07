begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Entry point to a PEIM.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<PiPei.h>
end_include

begin_include
include|#
directive|include
file|<Library/PeimEntryPoint.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_comment
comment|/**   The entry point of PE/COFF Image for a PEIM.    This function is the entry point for a PEIM.  This function must call ProcessLibraryConstructorList()    and ProcessModuleEntryPointList().  The return value from ProcessModuleEntryPointList() is returned.   If _gPeimRevision is not zero and PeiServices->Hdr.Revision is less than _gPeimRevison, then ASSERT().    @param  FileHandle  Handle of the file being invoked.    @param  PeiServices Describes the list of possible PEI Services.    @retval  EFI_SUCCESS   The PEIM executed normally.   @retval  !EFI_SUCCESS  The PEIM failed to execute normally. **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|_ModuleEntryPoint
parameter_list|(
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|)
block|{
if|if
condition|(
name|_gPeimRevision
operator|!=
literal|0
condition|)
block|{
comment|//
comment|// Make sure that the PEI spec revision of the platform is>= PEI spec revision of the driver
comment|//
name|ASSERT
argument_list|(
operator|(
operator|*
name|PeiServices
operator|)
operator|->
name|Hdr
operator|.
name|Revision
operator|>=
name|_gPeimRevision
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// Call constructor for all libraries
comment|//
name|ProcessLibraryConstructorList
argument_list|(
name|FileHandle
argument_list|,
name|PeiServices
argument_list|)
expr_stmt|;
comment|//
comment|// Call the driver entry point
comment|//
return|return
name|ProcessModuleEntryPointList
argument_list|(
name|FileHandle
argument_list|,
name|PeiServices
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**   Required by the EBC compiler and identical in functionality to _ModuleEntryPoint().      This function is required to call _ModuleEntryPoint() passing in FileHandle and PeiServices.    @param  FileHandle  Handle of the file being invoked.    @param  PeiServices Describes the list of possible PEI Services.    @retval EFI_SUCCESS  The PEIM executed normally.   @retval !EFI_SUCCESS The PEIM failed to execute normally.  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|EfiMain
parameter_list|(
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|)
block|{
return|return
name|_ModuleEntryPoint
argument_list|(
name|FileHandle
argument_list|,
name|PeiServices
argument_list|)
return|;
block|}
end_function

end_unit

