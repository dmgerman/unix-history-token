begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services to decompress a buffer using the UEFI Decompress algorithm.    The UEFI Decompress Library enables the decompression of objects that    were compressed using the UEFI compression scheme. The UEFI Decompress    Library is independent of environment and requires the caller to allocate    all required memory buffers.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_DECPOMPRESS_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_DECPOMPRESS_LIB_H__
end_define

begin_comment
comment|/**   Given a compressed source buffer, this function retrieves the size of    the uncompressed buffer and the size of the scratch buffer required    to decompress the compressed source buffer.    Retrieves the size of the uncompressed buffer and the temporary scratch buffer    required to decompress the buffer specified by Source and SourceSize.   If the size of the uncompressed buffer or the size of the scratch buffer cannot   be determined from the compressed data specified by Source and SourceData,    then RETURN_INVALID_PARAMETER is returned.  Otherwise, the size of the uncompressed   buffer is returned in DestinationSize, the size of the scratch buffer is returned   in ScratchSize, and RETURN_SUCCESS is returned.   This function does not have scratch buffer available to perform a thorough    checking of the validity of the source data.  It just retrieves the "Original Size"   field from the beginning bytes of the source data and output it as DestinationSize.   And ScratchSize is specific to the decompression implementation.    If Source is NULL, then ASSERT().   If DestinationSize is NULL, then ASSERT().   If ScratchSize is NULL, then ASSERT().    @param  Source          The source buffer containing the compressed data.   @param  SourceSize      The size, in bytes, of the source buffer.   @param  DestinationSize A pointer to the size, in bytes, of the uncompressed buffer                           that will be generated when the compressed buffer specified                           by Source and SourceSize is decompressed.   @param  ScratchSize     A pointer to the size, in bytes, of the scratch buffer that                           is required to decompress the compressed buffer specified                            by Source and SourceSize.    @retval  RETURN_SUCCESS The size of the uncompressed data was returned                            in DestinationSize and the size of the scratch                            buffer was returned in ScratchSize.   @retval  RETURN_INVALID_PARAMETER                            The size of the uncompressed data or the size of                            the scratch buffer cannot be determined from                            the compressed data specified by Source                            and SourceSize. **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|UefiDecompressGetInfo
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Source
parameter_list|,
name|IN
name|UINT32
name|SourceSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|DestinationSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|ScratchSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Decompresses a compressed source buffer.    Extracts decompressed data to its original form.   This function is designed so that the decompression algorithm can be implemented   without using any memory services.  As a result, this function is not allowed to   call any memory allocation services in its implementation.  It is the caller's    responsibility to allocate and free the Destination and Scratch buffers.   If the compressed source data specified by Source is successfully decompressed    into Destination, then RETURN_SUCCESS is returned.  If the compressed source data    specified by Source is not in a valid compressed data format,   then RETURN_INVALID_PARAMETER is returned.    If Source is NULL, then ASSERT().   If Destination is NULL, then ASSERT().   If the required scratch buffer size> 0 and Scratch is NULL, then ASSERT().    @param  Source      The source buffer containing the compressed data.   @param  Destination The destination buffer to store the decompressed data   @param  Scratch     A temporary scratch buffer that is used to perform the decompression.                       This is an optional parameter that may be NULL if the                        required scratch buffer size is 0.                         @retval  RETURN_SUCCESS Decompression completed successfully, and                            the uncompressed buffer is returned in Destination.   @retval  RETURN_INVALID_PARAMETER                            The source buffer specified by Source is corrupted                            (not in a valid compressed format). **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|UefiDecompress
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Source
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Destination
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Scratch
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

