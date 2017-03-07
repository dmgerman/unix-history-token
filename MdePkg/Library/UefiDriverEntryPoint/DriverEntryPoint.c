begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Entry point to a EFI/DXE driver.  Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Uefi.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/LoadedImage.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiDriverEntryPoint.h>
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
comment|/**   Unloads an image from memory.    This function is a callback that a driver registers to do cleanup    when the UnloadImage boot service function is called.    @param  ImageHandle The handle to the image to unload.    @return Status returned by all unload().  **/
end_comment

begin_function
name|EFI_STATUS
name|EFIAPI
name|_DriverUnloadHandler
parameter_list|(
name|EFI_HANDLE
name|ImageHandle
parameter_list|)
block|{
name|EFI_STATUS
name|Status
decl_stmt|;
comment|//
comment|// If an UnloadImage() handler is specified, then call it
comment|//
name|Status
operator|=
name|ProcessModuleUnloadList
argument_list|(
name|ImageHandle
argument_list|)
expr_stmt|;
comment|//
comment|// If the driver specific unload handler does not return an error, then call all of the
comment|// library destructors.  If the unload handler returned an error, then the driver can not be
comment|// unloaded, and the library destructors should not be called
comment|//
if|if
condition|(
operator|!
name|EFI_ERROR
argument_list|(
name|Status
argument_list|)
condition|)
block|{
name|ProcessLibraryDestructorList
argument_list|(
name|ImageHandle
argument_list|,
name|gST
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// Return the status from the driver specific unload handler
comment|//
return|return
name|Status
return|;
block|}
end_function

begin_comment
comment|/**   The entry point of PE/COFF Image for a DXE Driver, DXE Runtime Driver, DXE SMM    Driver, or UEFI Driver.     This function is the entry point for a DXE Driver, DXE Runtime Driver, DXE SMM Driver,   or UEFI Driver.  This function must call ProcessLibraryConstructorList() and   ProcessModuleEntryPointList(). If the return status from ProcessModuleEntryPointList()   is an error status, then ProcessLibraryDestructorList() must be called. The return    value from ProcessModuleEntryPointList() is returned. If _gDriverUnloadImageCount    is greater than zero, then an unload handler must be registered for this image    and the unload handler must invoke ProcessModuleUnloadList().   If _gUefiDriverRevision is not zero and SystemTable->Hdr.Revision is less than    _gUefiDriverRevison, then return EFI_INCOMPATIBLE_VERSION.     @param  ImageHandle  The image handle of the DXE Driver, DXE Runtime Driver,                         DXE SMM Driver, or UEFI Driver.   @param  SystemTable  A pointer to the EFI System Table.    @retval  EFI_SUCCESS               The DXE Driver, DXE Runtime Driver, DXE SMM                                       Driver, or UEFI Driver exited normally.   @retval  EFI_INCOMPATIBLE_VERSION  _gUefiDriverRevision is greater than                                      SystemTable->Hdr.Revision.   @retval  Other                     Return value from ProcessModuleEntryPointList().  **/
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
name|EFI_LOADED_IMAGE_PROTOCOL
modifier|*
name|LoadedImage
decl_stmt|;
if|if
condition|(
name|_gUefiDriverRevision
operator|!=
literal|0
condition|)
block|{
comment|//
comment|// Make sure that the EFI/UEFI spec revision of the platform is>= EFI/UEFI spec revision of the driver
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
comment|// Call constructor for all libraries
comment|//
name|ProcessLibraryConstructorList
argument_list|(
name|ImageHandle
argument_list|,
name|SystemTable
argument_list|)
expr_stmt|;
comment|//
comment|//  Install unload handler...
comment|//
if|if
condition|(
name|_gDriverUnloadImageCount
operator|!=
literal|0
condition|)
block|{
name|Status
operator|=
name|gBS
operator|->
name|HandleProtocol
argument_list|(
name|ImageHandle
argument_list|,
operator|&
name|gEfiLoadedImageProtocolGuid
argument_list|,
operator|(
name|VOID
operator|*
operator|*
operator|)
operator|&
name|LoadedImage
argument_list|)
expr_stmt|;
name|ASSERT_EFI_ERROR
argument_list|(
name|Status
argument_list|)
expr_stmt|;
name|LoadedImage
operator|->
name|Unload
operator|=
name|_DriverUnloadHandler
expr_stmt|;
block|}
comment|//
comment|// Call the driver entry point
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
comment|// If all of the drivers returned errors, then invoke all of the library destructors
comment|//
if|if
condition|(
name|EFI_ERROR
argument_list|(
name|Status
argument_list|)
condition|)
block|{
name|ProcessLibraryDestructorList
argument_list|(
name|ImageHandle
argument_list|,
name|SystemTable
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// Return the cummalative return status code from all of the driver entry points
comment|//
return|return
name|Status
return|;
block|}
end_function

begin_comment
comment|/**   Required by the EBC compiler and identical in functionality to _ModuleEntryPoint().     This function is required to call _ModuleEntryPoint() passing in ImageHandle,   and SystemTable.    @param  ImageHandle  The image handle of the DXE Driver, DXE Runtime Driver, DXE                         SMM Driver, or UEFI Driver.   @param  SystemTable  A pointer to the EFI System Table.    @retval  EFI_SUCCESS               The DXE Driver, DXE Runtime Driver, DXE SMM                                       Driver, or UEFI Driver exited normally.   @retval  EFI_INCOMPATIBLE_VERSION  _gUefiDriverRevision is greater than                                       SystemTable->Hdr.Revision.   @retval  Other                     Return value from ProcessModuleEntryPointList(). **/
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

