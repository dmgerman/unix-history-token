begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_AUTHENTICATION_INFO_PROTOCOL as defined in UEFI 2.0.   This protocol is used on any device handle to obtain authentication information    associated with the physical or logical device.  Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.   **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AUTHENTICATION_INFO_H__
end_ifndef

begin_define
define|#
directive|define
name|__AUTHENTICATION_INFO_H__
end_define

begin_define
define|#
directive|define
name|EFI_AUTHENTICATION_INFO_PROTOCOL_GUID
define|\
value|{ \     0x7671d9d0, 0x53db, 0x4173, {0xaa, 0x69, 0x23, 0x27, 0xf2, 0x1f, 0x0b, 0xc7 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_AUTHENTICATION_CHAP_RADIUS_GUID
define|\
value|{ \     0xd6062b50, 0x15ca, 0x11da, {0x92, 0x19, 0x00, 0x10, 0x83, 0xff, 0xca, 0x4d } \   }
end_define

begin_define
define|#
directive|define
name|EFI_AUTHENTICATION_CHAP_LOCAL_GUID
define|\
value|{ \     0xc280c73e, 0x15ca, 0x11da, {0xb0, 0xca, 0x00, 0x10, 0x83, 0xff, 0xca, 0x4d } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_AUTHENTICATION_INFO_PROTOCOL
name|EFI_AUTHENTICATION_INFO_PROTOCOL
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Authentication Type GUID.
comment|///
name|EFI_GUID
name|Guid
decl_stmt|;
comment|///
comment|/// Length of this structure in bytes.
comment|///
name|UINT16
name|Length
decl_stmt|;
block|}
name|AUTH_NODE_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|AUTH_NODE_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// RADIUS Server IPv4 or IPv6 Address.
comment|///
name|UINT8
name|RadiusIpAddr
index|[
literal|16
index|]
decl_stmt|;
comment|///< IPv4 or IPv6 address.
comment|///
comment|/// Reserved for future use.
comment|///
name|UINT16
name|Reserved
decl_stmt|;
comment|///
comment|/// Network Access Server IPv4 or IPv6 Address (OPTIONAL).
comment|///
name|UINT8
name|NasIpAddr
index|[
literal|16
index|]
decl_stmt|;
comment|///< IPv4 or IPv6 address.
comment|///
comment|/// Network Access Server Secret Length in bytes (OPTIONAL).
comment|///
name|UINT16
name|NasSecretLength
decl_stmt|;
comment|///
comment|/// Network Access Server Secret (OPTIONAL).
comment|///
name|UINT8
name|NasSecret
index|[
literal|1
index|]
decl_stmt|;
comment|///
comment|/// CHAP Initiator Secret Length in bytes on offset NasSecret + NasSecretLength.
comment|///
comment|/// UINT16           ChapSecretLength;
comment|///
comment|/// CHAP Initiator Secret.
comment|///
comment|/// UINT8            ChapSecret[];
comment|///
comment|/// CHAP Initiator Name Length in bytes on offset ChapSecret + ChapSecretLength.
comment|///
comment|/// UINT16           ChapNameLength;
comment|///
comment|/// CHAP Initiator Name.
comment|///
comment|/// UINT8            ChapName[];
comment|///
comment|/// Reverse CHAP Name Length in bytes on offset ChapName + ChapNameLength.
comment|///
comment|/// UINT16           ReverseChapNameLength;
comment|///
comment|/// Reverse CHAP Name.
comment|///
comment|/// UINT8            ReverseChapName[];
comment|///
comment|/// Reverse CHAP Secret Length in bytes on offseet ReverseChapName + ReverseChapNameLength.
comment|///
comment|/// UINT16           ReverseChapSecretLength;
comment|///
comment|/// Reverse CHAP Secret.
comment|///
comment|/// UINT8            ReverseChapSecret[];
comment|///
block|}
name|CHAP_RADIUS_AUTH_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|AUTH_NODE_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// Reserved for future use.
comment|///
name|UINT16
name|Reserved
decl_stmt|;
comment|///
comment|/// User Secret Length in bytes.
comment|///
name|UINT16
name|UserSecretLength
decl_stmt|;
comment|///
comment|/// User Secret.
comment|///
name|UINT8
name|UserSecret
index|[
literal|1
index|]
decl_stmt|;
comment|///
comment|/// User Name Length in bytes on offset UserSecret + UserSecretLength.
comment|///
comment|/// UINT16           UserNameLength;
comment|///
comment|/// User Name.
comment|///
comment|/// UINT8            UserName[];
comment|///
comment|/// CHAP Initiator Secret Length in bytes on offset UserName + UserNameLength.
comment|///
comment|/// UINT16           ChapSecretLength;
comment|///
comment|/// CHAP Initiator Secret.
comment|///
comment|/// UINT8            ChapSecret[];
comment|///
comment|/// CHAP Initiator Name Length in bytes on offset ChapSecret + ChapSecretLength.
comment|///
comment|/// UINT16           ChapNameLength;
comment|///
comment|/// CHAP Initiator Name.
comment|///
comment|/// UINT8            ChapName[];
comment|///
comment|/// Reverse CHAP Name Length in bytes on offset ChapName + ChapNameLength.
comment|///
comment|/// UINT16           ReverseChapNameLength;
comment|///
comment|/// Reverse CHAP Name.
comment|///
comment|/// UINT8            ReverseChapName[];
comment|///
comment|/// Reverse CHAP Secret Length in bytes on offset ReverseChapName + ReverseChapNameLength.
comment|///
comment|/// UINT16           ReverseChapSecretLength;
comment|///
comment|/// Reverse CHAP Secret.
comment|///
comment|/// UINT8            ReverseChapSecret[];
comment|///
block|}
name|CHAP_LOCAL_AUTH_NODE
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/**   Retrieves the authentication information associated with a particular controller handle.    @param[in]  This                  The pointer to the EFI_AUTHENTICATION_INFO_PROTOCOL.   @param[in]  ControllerHandle      The handle to the Controller.   @param[out] Buffer                The pointer to the authentication information. This function is                                     responsible for allocating the buffer and it is the caller's                                     responsibility to free buffer when the caller is finished with buffer.    @retval EFI_SUCCESS           Successfully retrieved authentication information                                  for the given ControllerHandle.   @retval EFI_INVALID_PARAMETER No matching authentication information found for                                  the given ControllerHandle.   @retval EFI_DEVICE_ERROR      The authentication information could not be retrieved                                  due to a hardware error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_AUTHENTICATION_INFO_PROTOCOL_GET
function_decl|)
parameter_list|(
name|IN
name|EFI_AUTHENTICATION_INFO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Set the authentication information for a given controller handle.    @param[in]  This                 The pointer to the EFI_AUTHENTICATION_INFO_PROTOCOL.   @param[in]  ControllerHandle     The handle to the Controller.   @param[in]  Buffer               The pointer to the authentication information.                                    @retval EFI_SUCCESS          Successfully set authentication information for the                                 given ControllerHandle.   @retval EFI_UNSUPPORTED      If the platform policies do not allow setting of                                 the authentication information.   @retval EFI_DEVICE_ERROR     The authentication information could not be configured                                 due to a hardware error.   @retval EFI_OUT_OF_RESOURCES Not enough storage is available to hold the data.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_AUTHENTICATION_INFO_PROTOCOL_SET
function_decl|)
parameter_list|(
name|IN
name|EFI_AUTHENTICATION_INFO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
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
comment|/// This protocol is used on any device handle to obtain authentication
end_comment

begin_comment
comment|/// information associated with the physical or logical device.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_AUTHENTICATION_INFO_PROTOCOL
block|{
name|EFI_AUTHENTICATION_INFO_PROTOCOL_GET
name|Get
decl_stmt|;
name|EFI_AUTHENTICATION_INFO_PROTOCOL_SET
name|Set
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAuthenticationInfoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAuthenticationChapRadiusGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAuthenticationChapLocalGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

