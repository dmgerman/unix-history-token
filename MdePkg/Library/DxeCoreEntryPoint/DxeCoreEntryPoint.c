begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Entry point to the DXE Core.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<PiDxe.h>
end_include

begin_include
include|#
directive|include
file|<Library/DxeCoreEntryPoint.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Cache copy of HobList pointer.
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|VOID
modifier|*
name|gHobList
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   The entry point of PE/COFF Image for the DXE Core.     This function is the entry point for the DXE Core. This function is required to call   ProcessModuleEntryPointList() and ProcessModuleEntryPointList() is never expected to return.   The DXE Core is responsible for calling ProcessLibraryConstructorList() as soon as the EFI   System Table and the image handle for the DXE Core itself have been established.   If ProcessModuleEntryPointList() returns, then ASSERT() and halt the system.    @param  HobStart  The pointer to the beginning of the HOB List passed in from the PEI Phase.   **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|_ModuleEntryPoint
parameter_list|(
name|IN
name|VOID
modifier|*
name|HobStart
parameter_list|)
block|{
comment|//
comment|// Cache a pointer to the HobList
comment|//
name|gHobList
operator|=
name|HobStart
expr_stmt|;
comment|//
comment|// Call the DXE Core entry point
comment|//
name|ProcessModuleEntryPointList
argument_list|(
name|HobStart
argument_list|)
expr_stmt|;
comment|//
comment|// Should never return
comment|//
name|ASSERT
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
name|CpuDeadLoop
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Required by the EBC compiler and identical in functionality to _ModuleEntryPoint().    This function is required to call _ModuleEntryPoint() passing in HobStart.    @param  HobStart  The pointer to the beginning of the HOB List passed in from the PEI Phase.   **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|EfiMain
parameter_list|(
name|IN
name|VOID
modifier|*
name|HobStart
parameter_list|)
block|{
name|_ModuleEntryPoint
argument_list|(
name|HobStart
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

