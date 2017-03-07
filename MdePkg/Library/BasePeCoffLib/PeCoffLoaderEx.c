begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Specific relocation fixups for none Itanium architecture.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|"BasePeCoffLibInternals.h"
end_include

begin_comment
comment|/**   Performs an Itanium-based specific relocation fixup and is a no-op on other   instruction sets.    @param  Reloc       The pointer to the relocation record.   @param  Fixup       The pointer to the address to fix up.   @param  FixupData   The pointer to a buffer to log the fixups.   @param  Adjust      The offset to adjust the fixup.    @return Status code.  **/
end_comment

begin_function
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
block|{
return|return
name|RETURN_UNSUPPORTED
return|;
block|}
end_function

begin_comment
comment|/**   Returns TRUE if the machine type of PE/COFF image is supported. Supported   does not mean the image can be executed it means the PE/COFF loader supports   loading and relocating of the image type. It's up to the caller to support   the entry point.      The IA32/X64 version PE/COFF loader/relocater both support IA32, X64 and EBC images.    @param  Machine   The machine type from the PE Header.    @return TRUE if this PE/COFF loader can load the image  **/
end_comment

begin_function
name|BOOLEAN
name|PeCoffLoaderImageFormatSupported
parameter_list|(
name|IN
name|UINT16
name|Machine
parameter_list|)
block|{
if|if
condition|(
operator|(
name|Machine
operator|==
name|IMAGE_FILE_MACHINE_I386
operator|)
operator|||
operator|(
name|Machine
operator|==
name|IMAGE_FILE_MACHINE_X64
operator|)
operator|||
operator|(
name|Machine
operator|==
name|IMAGE_FILE_MACHINE_EBC
operator|)
operator|||
operator|(
name|Machine
operator|==
name|IMAGE_FILE_MACHINE_ARM64
operator|)
condition|)
block|{
return|return
name|TRUE
return|;
block|}
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**   Performs an Itanium-based specific re-relocation fixup and is a no-op on other   instruction sets. This is used to re-relocated the image into the EFI virtual   space for runtime calls.    @param  Reloc       The pointer to the relocation record.   @param  Fixup       The pointer to the address to fix up.   @param  FixupData   The pointer to a buffer to log the fixups.   @param  Adjust      The offset to adjust the fixup.    @return Status code.  **/
end_comment

begin_function
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
block|{
return|return
name|RETURN_UNSUPPORTED
return|;
block|}
end_function

end_unit

