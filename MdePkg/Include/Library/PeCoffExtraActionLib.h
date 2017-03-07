begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services to perform additional actions when a PE/COFF image is loaded   or unloaded.  This is useful for environment where symbols need to be loaded    and unloaded to support source level debugging.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PE_COFF_EXTRA_ACTION_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__PE_COFF_EXTRA_ACTION_LIB_H__
end_define

begin_include
include|#
directive|include
file|<Library/PeCoffLib.h>
end_include

begin_comment
comment|/**   Performs additional actions after a PE/COFF image has been loaded and relocated.    If ImageContext is NULL, then ASSERT().    @param  ImageContext  Pointer to the image context structure that describes the                         PE/COFF image that has already been loaded and relocated.  **/
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs additional actions just before a PE/COFF image is unloaded.  Any resources   that were allocated by PeCoffLoaderRelocateImageExtraAction() must be freed.      If ImageContext is NULL, then ASSERT().      @param  ImageContext  Pointer to the image context structure that describes the                         PE/COFF image that is being unloaded.  **/
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

