begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI Erase Block Protocol.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.6  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_ERASE_BLOCK_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_ERASE_BLOCK_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_ERASE_BLOCK_PROTOCOL_GUID
define|\
value|{ \     0x95a9a93e, 0xa86e, 0x4926, { 0xaa, 0xef, 0x99, 0x18, 0xe7, 0x72, 0xd9, 0x87 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_ERASE_BLOCK_PROTOCOL
name|EFI_ERASE_BLOCK_PROTOCOL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ERASE_BLOCK_PROTOCOL_REVISION
value|((2<<16) | (60))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ERASE_BLOCK_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// If Event is NULL, then blocking I/O is performed. If Event is not NULL and
comment|// non-blocking I/O is supported, then non-blocking I/O is performed, and
comment|// Event will be signaled when the erase request is completed.
comment|//
name|EFI_EVENT
name|Event
decl_stmt|;
comment|//
comment|// Defines whether the signaled event encountered an error.
comment|//
name|EFI_STATUS
name|TransactionStatus
decl_stmt|;
block|}
name|EFI_ERASE_BLOCK_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Erase a specified number of device blocks.    @param[in]       This           Indicates a pointer to the calling context.   @param[in]       MediaId        The media ID that the erase request is for.   @param[in]       LBA            The starting logical block address to be                                   erased. The caller is responsible for erasing                                   only legitimate locations.   @param[in, out]  Token          A pointer to the token associated with the                                   transaction.   @param[in]       Size           The size in bytes to be erased. This must be                                   a multiple of the physical block size of the                                   device.    @retval EFI_SUCCESS             The erase request was queued if Event is not                                   NULL. The data was erased correctly to the                                   device if the Event is NULL.to the device.   @retval EFI_WRITE_PROTECTED     The device cannot be erased due to write                                   protection.   @retval EFI_DEVICE_ERROR        The device reported an error while attempting                                   to perform the erase operation.   @retval EFI_INVALID_PARAMETER   The erase request contains LBAs that are not                                   valid.   @retval EFI_NO_MEDIA            There is no media in the device.   @retval EFI_MEDIA_CHANGED       The MediaId is not for the current media.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_ERASE
function_decl|)
parameter_list|(
name|IN
name|EFI_ERASE_BLOCK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|EFI_LBA
name|LBA
parameter_list|,
name|IN
name|OUT
name|EFI_ERASE_BLOCK_TOKEN
modifier|*
name|Token
parameter_list|,
name|IN
name|UINTN
name|Size
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI Erase Block Protocol provides the ability for a device to expose
end_comment

begin_comment
comment|/// erase functionality. This optional protocol is installed on the same handle
end_comment

begin_comment
comment|/// as the EFI_BLOCK_IO_PROTOCOL or EFI_BLOCK_IO2_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_ERASE_BLOCK_PROTOCOL
block|{
comment|//
comment|// The revision to which the EFI_ERASE_BLOCK_PROTOCOL adheres. All future
comment|// revisions must be backwards compatible. If a future version is not
comment|// backwards compatible, it is not the same GUID.
comment|//
name|UINT64
name|Revision
decl_stmt|;
comment|//
comment|// Returns the erase length granularity as a number of logical blocks. A
comment|// value of 1 means the erase granularity is one logical block.
comment|//
name|UINT32
name|EraseLengthGranularity
decl_stmt|;
name|EFI_BLOCK_ERASE
name|EraseBlocks
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEraseBlockProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

