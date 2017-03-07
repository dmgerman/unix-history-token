begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI EAP(Extended Authenticaton Protocol) Protocol Definition   The EFI EAP Protocol is used to abstract the ability to configure and extend the   EAP framework.    The definitions in this file are defined in UEFI Specification 2.3.1B, which have   not been verified by one implementation yet.    Copyright (c) 2009 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_EAP_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_EAP_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_EAP_PROTOCOL_GUID
define|\
value|{ \     0x5d9f96db, 0xe731, 0x4caa, {0xa0, 0xd, 0x72, 0xe1, 0x87, 0xcd, 0x77, 0x62 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_EAP_PROTOCOL
name|EFI_EAP_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Type for the identification number assigned to the Port by the
end_comment

begin_comment
comment|/// System in which the Port resides.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_PORT_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EAP Authentication Method Type (RFC 3748)
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_TLS
value|13
end_define

begin_comment
comment|///< REQUIRED - RFC 5216
end_comment

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// EAP_TYPE MD5, OTP and TOEKN_CARD has been removed from UEFI2.3.1B.
end_comment

begin_comment
comment|// Definitions are kept for backward compatibility.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_MD5
value|4
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_OTP
value|5
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_TOKEN_CARD
value|6
end_define

begin_comment
comment|/**   One user provided EAP authentication method.    Build EAP response packet in response to the EAP request packet specified by   (RequestBuffer, RequestSize).    @param[in]      PortNumber     Specified the Port where the EAP request packet comes.   @param[in]      RequestBuffer  Pointer to the most recently received EAP- Request packet.   @param[in]      RequestSize    Packet size in bytes for the most recently received                                  EAP-Request packet.   @param[in]      Buffer         Pointer to the buffer to hold the built packet.   @param[in, out] BufferSize     Pointer to the buffer size in bytes.                                   On input, it is the buffer size provided by the caller.                                  On output, it is the buffer size in fact needed to contain                                  the packet.    @retval EFI_SUCCESS            The required EAP response packet is built successfully.   @retval others                 Failures are encountered during the packet building process.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_BUILD_RESPONSE_PACKET
function_decl|)
parameter_list|(
name|IN
name|EFI_PORT_HANDLE
name|PortNumber
parameter_list|,
name|IN
name|UINT8
modifier|*
name|RequestBuffer
parameter_list|,
name|IN
name|UINTN
name|RequestSize
parameter_list|,
name|IN
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Set the desired EAP authentication method for the Port.    The SetDesiredAuthMethod() function sets the desired EAP authentication method indicated    by EapAuthType for the Port.      If EapAuthType is an invalid EAP authentication type, then EFI_INVALID_PARAMETER is    returned.   If the EAP authentication method of EapAuthType is unsupported by the Ports, then it will   return EFI_UNSUPPORTED.   The cryptographic strength of EFI_EAP_TYPE_TLS shall be at least of hash strength    SHA-256 and RSA key length of at least 2048 bits.      @param[in] This                A pointer to the EFI_EAP_PROTOCOL instance that indicates                                   the calling context.   @param[in] EapAuthType         The type of the EAP authentication method to register. It should                                   be the type value defined by RFC. See RFC 2284 for details.   @param[in] Handler             The handler of the EAP authentication method to register.    @retval EFI_SUCCESS            The EAP authentication method of EapAuthType is                                   registered successfully.   @retval EFI_INVALID_PARAMETER  EapAuthType is an invalid EAP authentication type.   @retval EFI_UNSUPPORTED        The EAP authentication method of EapAuthType is                                  unsupported by the Port.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_SET_DESIRED_AUTHENTICATION_METHOD
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|EapAuthType
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register an EAP authentication method.     The RegisterAuthMethod() function registers the user provided EAP authentication method,    the type of which is EapAuthType and the handler of which is Handler.       If EapAuthType is an invalid EAP authentication type, then EFI_INVALID_PARAMETER is    returned.   If there is not enough system memory to perform the registration, then    EFI_OUT_OF_RESOURCES is returned.    @param[in] This                A pointer to the EFI_EAP_PROTOCOL instance that indicates                                   the calling context.   @param[in] EapAuthType         The type of the EAP authentication method to register. It should                                   be the type value defined by RFC. See RFC 2284 for details.   @param[in] Handler             The handler of the EAP authentication method to register.    @retval EFI_SUCCESS            The EAP authentication method of EapAuthType is                                   registered successfully.   @retval EFI_INVALID_PARAMETER  EapAuthType is an invalid EAP authentication type.   @retval EFI_OUT_OF_RESOURCES   There is not enough system memory to perform the registration.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_REGISTER_AUTHENTICATION_METHOD
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|EapAuthType
parameter_list|,
name|IN
name|EFI_EAP_BUILD_RESPONSE_PACKET
name|Handler
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_EAP_PROTOCOL
end_comment

begin_comment
comment|/// is used to configure the desired EAP authentication method for the EAP
end_comment

begin_comment
comment|/// framework and extend the EAP framework by registering new EAP authentication
end_comment

begin_comment
comment|/// method on a Port. The EAP framework is built on a per-Port basis. Herein, a
end_comment

begin_comment
comment|/// Port means a NIC. For the details of EAP protocol, please refer to RFC 2284.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_EAP_PROTOCOL
block|{
name|EFI_EAP_SET_DESIRED_AUTHENTICATION_METHOD
name|SetDesiredAuthMethod
decl_stmt|;
name|EFI_EAP_REGISTER_AUTHENTICATION_METHOD
name|RegisterAuthMethod
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEapProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

