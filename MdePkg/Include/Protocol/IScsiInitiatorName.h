begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_ISCSI_INITIATOR_NAME_PROTOCOL as defined in UEFI 2.0.   It provides the ability to get and set the iSCSI Initiator Name.                                                      Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ISCSI_INITIATOR_NAME_H__
end_ifndef

begin_define
define|#
directive|define
name|__ISCSI_INITIATOR_NAME_H__
end_define

begin_define
define|#
directive|define
name|EFI_ISCSI_INITIATOR_NAME_PROTOCOL_GUID
define|\
value|{ \   0x59324945, 0xec44, 0x4c0d, {0xb1, 0xcd, 0x9d, 0xb1, 0x39, 0xdf, 0x7, 0xc } \ }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_ISCSI_INITIATOR_NAME_PROTOCOL
name|EFI_ISCSI_INITIATOR_NAME_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Retrieves the current set value of iSCSI Initiator Name.    @param  This       Pointer to the EFI_ISCSI_INITIATOR_NAME_PROTOCOL instance.   @param  BufferSize Size of the buffer in bytes pointed to by Buffer / Actual size of the                      variable data buffer.   @param  Buffer     Pointer to the buffer for data to be read. The data is a null-terminated UTF-8 encoded string.                      The maximum length is 223 characters, including the null-terminator.    @retval EFI_SUCCESS           Data was successfully retrieved into the provided buffer and the                                 BufferSize was sufficient to handle the iSCSI initiator name   @retval EFI_BUFFER_TOO_SMALL  BufferSize is too small for the result.   @retval EFI_INVALID_PARAMETER BufferSize or Buffer is NULL.   @retval EFI_DEVICE_ERROR      The iSCSI initiator name could not be retrieved due to a hardware error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ISCSI_INITIATOR_NAME_GET
function_decl|)
parameter_list|(
name|IN
name|EFI_ISCSI_INITIATOR_NAME_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets the iSCSI Initiator Name.    @param  This       Pointer to the EFI_ISCSI_INITIATOR_NAME_PROTOCOL instance.   @param  BufferSize Size of the buffer in bytes pointed to by Buffer.   @param  Buffer     Pointer to the buffer for data to be written. The data is a null-terminated UTF-8 encoded string.                      The maximum length is 223 characters, including the null-terminator.    @retval EFI_SUCCESS           Data was successfully stored by the protocol.   @retval EFI_UNSUPPORTED       Platform policies do not allow for data to be written.   @retval EFI_INVALID_PARAMETER BufferSize or Buffer is NULL, or BufferSize exceeds the maximum allowed limit.   @retval EFI_DEVICE_ERROR      The data could not be stored due to a hardware error.   @retval EFI_OUT_OF_RESOURCES  Not enough storage is available to hold the data.   @retval EFI_PROTOCOL_ERROR    Input iSCSI initiator name does not adhere to RFC 3720                                 (and other related protocols)  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ISCSI_INITIATOR_NAME_SET
function_decl|)
parameter_list|(
name|IN
name|EFI_ISCSI_INITIATOR_NAME_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// iSCSI Initiator Name Protocol for setting and obtaining the iSCSI Initiator Name.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_ISCSI_INITIATOR_NAME_PROTOCOL
block|{
name|EFI_ISCSI_INITIATOR_NAME_GET
name|Get
decl_stmt|;
name|EFI_ISCSI_INITIATOR_NAME_SET
name|Set
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIScsiInitiatorNameProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

