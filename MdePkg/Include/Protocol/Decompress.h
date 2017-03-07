begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The Decompress Protocol Interface as defined in UEFI spec    Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DECOMPRESS_H__
end_ifndef

begin_define
define|#
directive|define
name|__DECOMPRESS_H__
end_define

begin_define
define|#
directive|define
name|EFI_DECOMPRESS_PROTOCOL_GUID
define|\
value|{ \     0xd8117cfe, 0x94a6, 0x11d4, {0x9a, 0x3a, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DECOMPRESS_PROTOCOL
name|EFI_DECOMPRESS_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The GetInfo() function retrieves the size of the uncompressed buffer    and the temporary scratch buffer required to decompress the buffer    specified by Source and SourceSize.  If the size of the uncompressed   buffer or the size of the scratch buffer cannot be determined from    the compressed data specified by Source and SourceData, then    EFI_INVALID_PARAMETER is returned.  Otherwise, the size of the uncompressed   buffer is returned in DestinationSize, the size of the scratch buffer is    returned in ScratchSize, and EFI_SUCCESS is returned.    The GetInfo() function does not have a scratch buffer available to perform    a thorough checking of the validity of the source data. It just retrieves   the 'Original Size' field from the beginning bytes of the source data and   output it as DestinationSize.  And ScratchSize is specific to the decompression   implementation.    @param  This            A pointer to the EFI_DECOMPRESS_PROTOCOL instance.   @param  Source          The source buffer containing the compressed data.   @param  SourceSize      The size, in bytes, of source buffer.   @param  DestinationSize A pointer to the size, in bytes, of the uncompressed buffer                           that will be generated when the compressed buffer specified                           by Source and SourceSize is decompressed.   @param  ScratchSize     A pointer to the size, in bytes, of the scratch buffer that                           is required to decompress the compressed buffer specified by                           Source and SourceSize.    @retval  EFI_SUCCESS           The size of the uncompressed data was returned in DestinationSize                                  and the size of the scratch buffer was returned in ScratchSize.   @retval  EFI_INVALID_PARAMETER The size of the uncompressed data or the size of the scratch                                  buffer cannot be determined from the compressed data specified by                                  Source and SourceData.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DECOMPRESS_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_DECOMPRESS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
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
end_typedef

begin_comment
comment|/**   The Decompress() function extracts decompressed data to its original form.    This protocol is designed so that the decompression algorithm can be    implemented without using any memory services.  As a result, the    Decompress() function is not allowed to call AllocatePool() or    AllocatePages() in its implementation.  It is the caller's responsibility    to allocate and free the Destination and Scratch buffers.    If the compressed source data specified by Source and SourceSize is    successfully decompressed into Destination, then EFI_SUCCESS is returned.     If the compressed source data specified by Source and SourceSize is not in    a valid compressed data format, then EFI_INVALID_PARAMETER is returned.    @param  This            A pointer to the EFI_DECOMPRESS_PROTOCOL instance.   @param  Source          The source buffer containing the compressed data.   @param  SourceSize      The size of source data.   @param  Destination     On output, the destination buffer that contains                           the uncompressed data.   @param  DestinationSize The size of destination buffer. The size of destination                           buffer needed is obtained from GetInfo().   @param  Scratch         A temporary scratch buffer that is used to perform the                           decompression.             @param  ScratchSize     The size of scratch buffer. The size of scratch buffer needed                           is obtained from GetInfo().    @retval  EFI_SUCCESS          Decompression completed successfully, and the uncompressed                                 buffer is returned in Destination.   @retval EFI_INVALID_PARAMETER The source buffer specified by Source and SourceSize is                                 corrupted (not in a valid compressed format).  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DECOMPRESS_DECOMPRESS
function_decl|)
parameter_list|(
name|IN
name|EFI_DECOMPRESS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Source
parameter_list|,
name|IN
name|UINT32
name|SourceSize
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Destination
parameter_list|,
name|IN
name|UINT32
name|DestinationSize
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Scratch
parameter_list|,
name|IN
name|UINT32
name|ScratchSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides a decompression service.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DECOMPRESS_PROTOCOL
block|{
name|EFI_DECOMPRESS_GET_INFO
name|GetInfo
decl_stmt|;
name|EFI_DECOMPRESS_DECOMPRESS
name|Decompress
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDecompressProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

