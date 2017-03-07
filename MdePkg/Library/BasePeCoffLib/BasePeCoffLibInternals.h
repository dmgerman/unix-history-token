begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Declaration of internal functions in PE/COFF Lib.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BASE_PECOFF_LIB_INTERNALS__
end_ifndef

begin_define
define|#
directive|define
name|__BASE_PECOFF_LIB_INTERNALS__
end_define

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/PeCoffLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseMemoryLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PeCoffExtraActionLib.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/PeImage.h>
end_include

begin_comment
comment|/**   Performs an Itanium-based specific relocation fixup and is a no-op on other   instruction sets.    @param  Reloc       The pointer to the relocation record.   @param  Fixup       The pointer to the address to fix up.   @param  FixupData   The pointer to a buffer to log the fixups.   @param  Adjust      The offset to adjust the fixup.    @return Status code.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|PeCoffLoaderRelocateImageEx
parameter_list|(
name|IN
name|UINT16
modifier|*
name|Reloc
parameter_list|,
name|IN
name|OUT
name|CHAR8
modifier|*
name|Fixup
parameter_list|,
name|IN
name|OUT
name|CHAR8
modifier|*
modifier|*
name|FixupData
parameter_list|,
name|IN
name|UINT64
name|Adjust
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs an Itanium-based specific re-relocation fixup and is a no-op on other   instruction sets. This is used to re-relocated the image into the EFI virtual   space for runtime calls.    @param  Reloc       The pointer to the relocation record.   @param  Fixup       The pointer to the address to fix up.   @param  FixupData   The pointer to a buffer to log the fixups.   @param  Adjust      The offset to adjust the fixup.    @return Status code.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|PeHotRelocateImageEx
parameter_list|(
name|IN
name|UINT16
modifier|*
name|Reloc
parameter_list|,
name|IN
name|OUT
name|CHAR8
modifier|*
name|Fixup
parameter_list|,
name|IN
name|OUT
name|CHAR8
modifier|*
modifier|*
name|FixupData
parameter_list|,
name|IN
name|UINT64
name|Adjust
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns TRUE if the machine type of PE/COFF image is supported. Supported   does not mean the image can be executed it means the PE/COFF loader supports   loading and relocating of the image type. It's up to the caller to support   the entry point.    @param  Machine   Machine type from the PE Header.    @return TRUE if this PE/COFF loader can load the image  **/
end_comment

begin_function_decl
name|BOOLEAN
name|PeCoffLoaderImageFormatSupported
parameter_list|(
name|IN
name|UINT16
name|Machine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the magic value from the PE/COFF header.    @param  Hdr             The buffer in which to return the PE32, PE32+, or TE header.    @return EFI_IMAGE_NT_OPTIONAL_HDR32_MAGIC - Image is PE32   @return EFI_IMAGE_NT_OPTIONAL_HDR64_MAGIC - Image is PE32+  **/
end_comment

begin_function_decl
name|UINT16
name|PeCoffLoaderGetPeHeaderMagicValue
parameter_list|(
name|IN
name|EFI_IMAGE_OPTIONAL_HEADER_PTR_UNION
name|Hdr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the PE or TE Header from a PE/COFF or TE image.    @param  ImageContext    The context of the image being loaded.   @param  Hdr             The buffer in which to return the PE32, PE32+, or TE header.    @retval RETURN_SUCCESS  The PE or TE Header is read.   @retval Other           The error status from reading the PE/COFF or TE image using the ImageRead function.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|PeCoffLoaderGetPeHeader
parameter_list|(
name|IN
name|OUT
name|PE_COFF_LOADER_IMAGE_CONTEXT
modifier|*
name|ImageContext
parameter_list|,
name|OUT
name|EFI_IMAGE_OPTIONAL_HEADER_PTR_UNION
name|Hdr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Converts an image address to the loaded address.    @param  ImageContext      The context of the image being loaded.   @param  Address           The address to be converted to the loaded address.   @param  TeStrippedOffset  Stripped offset for TE image.    @return The converted address or NULL if the address can not be converted.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|PeCoffLoaderImageAddress
parameter_list|(
name|IN
name|OUT
name|PE_COFF_LOADER_IMAGE_CONTEXT
modifier|*
name|ImageContext
parameter_list|,
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINTN
name|TeStrippedOffset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

