begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Entry point library instance to a UEFI application.  Copyright (c) 2007 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Uefi.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiApplicationEntryPoint.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiBootServicesTableLib.h>
end_include

begin_comment
comment|/**   Entry point to UEFI Application.    This function is the entry point for a UEFI Application. This function must call   ProcessLibraryConstructorList(), ProcessModuleEntryPointList(), and ProcessLibraryDestructorList().   The return value from ProcessModuleEntryPointList() is returned.   If _gUefiDriverRevision is not zero and SystemTable->Hdr.Revision is less than _gUefiDriverRevison,   then return EFI_INCOMPATIBLE_VERSION.    @param  ImageHandle                The image handle of the UEFI Application.   @param  SystemTable                A pointer to the EFI System Table.    @retval  EFI_SUCCESS               The UEFI Application exited normally.   @retval  EFI_INCOMPATIBLE_VERSION  _gUefiDriverRevision is greater than SystemTable->Hdr.Revision.   @retval  Other                     Return value from ProcessModuleEntryPointList().  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|_ModuleEntryPoint
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
if|if
condition|(
name|_gUefiDriverRevision
operator|!=
literal|0
condition|)
block|{
comment|//
comment|// Make sure that the EFI/UEFI spec revision of the platform is>= EFI/UEFI spec revision of the application.
comment|//
if|if
condition|(
name|SystemTable
operator|->
name|Hdr
operator|.
name|Revision
operator|<
name|_gUefiDriverRevision
condition|)
block|{
return|return
name|EFI_INCOMPATIBLE_VERSION
return|;
block|}
block|}
comment|//
comment|// Call constructor for all libraries.
comment|//
name|ProcessLibraryConstructorList
argument_list|(
name|ImageHandle
argument_list|,
name|SystemTable
argument_list|)
expr_stmt|;
comment|//
comment|// Call the module's entry point
comment|//
name|Status
operator|=
name|ProcessModuleEntryPointList
argument_list|(
name|ImageHandle
argument_list|,
name|SystemTable
argument_list|)
expr_stmt|;
comment|//
comment|// Process destructor for all libraries.
comment|//
name|ProcessLibraryDestructorList
argument_list|(
name|ImageHandle
argument_list|,
name|SystemTable
argument_list|)
expr_stmt|;
comment|//
comment|// Return the return status code from the driver entry point
comment|//
return|return
name|Status
return|;
block|}
end_function

begin_comment
comment|/**   Invokes the library destructors for all dependent libraries and terminates   the UEFI Application.     This function calls ProcessLibraryDestructorList() and the EFI Boot Service Exit()   with a status specified by Status.    @param  Status  Status returned by the application that is exiting.    **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|Exit
parameter_list|(
name|IN
name|EFI_STATUS
name|Status
parameter_list|)
block|{
name|ProcessLibraryDestructorList
argument_list|(
name|gImageHandle
argument_list|,
name|gST
argument_list|)
expr_stmt|;
name|gBS
operator|->
name|Exit
argument_list|(
name|gImageHandle
argument_list|,
name|Status
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Required by the EBC compiler and identical in functionality to _ModuleEntryPoint().     @param  ImageHandle  The image handle of the UEFI Application.   @param  SystemTable  A pointer to the EFI System Table.    @retval  EFI_SUCCESS               The UEFI Application exited normally.   @retval  EFI_INCOMPATIBLE_VERSION  _gUefiDriverRevision is greater than SystemTable->Hdr.Revision.   @retval  Other                     Return value from ProcessModuleEntryPointList().  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|EfiMain
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
return|return
name|_ModuleEntryPoint
argument_list|(
name|ImageHandle
argument_list|,
name|SystemTable
argument_list|)
return|;
block|}
end_function

end_unit

