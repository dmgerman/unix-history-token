begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Null PE/Coff Extra Action library instances with empty functions.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/PeCoffExtraActionLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_comment
comment|/**   Performs additional actions after a PE/COFF image has been loaded and relocated.    If ImageContext is NULL, then ASSERT().    @param  ImageContext  The pointer to the image context structure that describes the                         PE/COFF image that has already been loaded and relocated.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|PeCoffLoaderRelocateImageExtraAction
parameter_list|(
name|IN
name|OUT
name|PE_COFF_LOADER_IMAGE_CONTEXT
modifier|*
name|ImageContext
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|ImageContext
operator|!=
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Performs additional actions just before a PE/COFF image is unloaded.  Any resources   that were allocated by PeCoffLoaderRelocateImageExtraAction() must be freed.      If ImageContext is NULL, then ASSERT().      @param  ImageContext  The pointer to the image context structure that describes the                         PE/COFF image that is being unloaded.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|PeCoffLoaderUnloadImageExtraAction
parameter_list|(
name|IN
name|OUT
name|PE_COFF_LOADER_IMAGE_CONTEXT
modifier|*
name|ImageContext
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|ImageContext
operator|!=
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

