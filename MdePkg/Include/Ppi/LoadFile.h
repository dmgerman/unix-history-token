begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Load image file from fv to memory.     Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LOAD_FILE_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__LOAD_FILE_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_LOAD_FILE_PPI_GUID
define|\
value|{ 0xb9e0abfe, 0x5979, 0x4914, { 0x97, 0x7f, 0x6d, 0xee, 0x78, 0xc2, 0x78, 0xa6 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_LOAD_FILE_PPI
name|EFI_PEI_LOAD_FILE_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Loads a PEIM into memory for subsequent execution.    This service is the single member function of EFI_LOAD_FILE_PPI.   This service separates image loading and relocating from the PEI Foundation.      @param This                   Interface pointer that implements                                 the Load File PPI instance.   @param FileHandle             File handle of the file to load.   @param ImageAddress           Pointer to the address of the loaded image.   @param ImageSize              Pointer to the size of the loaded image.   @param EntryPoint             Pointer to the entry point of the image.   @param AuthenticationState    On exit, points to the attestation                                 authentication state of the image                                 or 0 if no attestation was performed.    @retval EFI_SUCCESS           The image was loaded successfully.   @retval EFI_OUT_OF_RESOURCES  There was not enough memory.   @retval EFI_LOAD_ERROR        There was no supported image in the file.   @retval EFI_INVALID_PARAMETER FileHandle was not a valid firmware file handle.   @retval EFI_INVALID_PARAMETER EntryPoint was NULL.   @retval EFI_UNSUPPORTED       An image requires relocations or is not                                 memory mapped.   @retval EFI_WARN_BUFFER_TOO_SMALL                                  There is not enough heap to allocate the requested size.                                 This will not prevent the XIP image from being invoked.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_LOAD_FILE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_LOAD_FILE_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PEI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|ImageAddress
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|ImageSize
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|EntryPoint
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|AuthenticationState
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI is a pointer to the Load File service.
end_comment

begin_comment
comment|/// This service will be published by a PEIM. The PEI Foundation
end_comment

begin_comment
comment|/// will use this service to launch the known PEI module images.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_LOAD_FILE_PPI
block|{
name|EFI_PEI_LOAD_FILE
name|LoadFile
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiLoadFilePpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

