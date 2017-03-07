begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI TLS Protocols as defined in UEFI 2.5.    The EFI TLS Service Binding Protocol is used to locate EFI TLS Protocol drivers   to create and destroy child of the driver to communicate with other host using   TLS protocol.   The EFI TLS Protocol provides the ability to manage TLS session.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_TLS_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_TLS_PROTOCOL_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI TLS Service Binding Protocol is used to locate EFI TLS Protocol drivers to
end_comment

begin_comment
comment|/// create and destroy child of the driver to communicate with other host using TLS
end_comment

begin_comment
comment|/// protocol.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_TLS_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x952cb795, 0xff36, 0x48cf, {0xa2, 0x49, 0x4d, 0xf4, 0x86, 0xd6, 0xab, 0x8d } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI TLS protocol provides the ability to manage TLS session.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_TLS_PROTOCOL_GUID
define|\
value|{ \     0xca959f, 0x6cfa, 0x4db1, {0x95, 0xbc, 0xe4, 0x6c, 0x47, 0x51, 0x43, 0x90 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_TLS_PROTOCOL
name|EFI_TLS_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_SESSION_DATA_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Session Configuration
comment|///
comment|///
comment|/// TLS session Version. The corresponding Data is of type EFI_TLS_VERSION.
comment|///
name|EfiTlsVersion
block|,
comment|///
comment|/// TLS session as client or as server. The corresponding Data is of
comment|/// EFI_TLS_CONNECTION_END.
comment|///
name|EfiTlsConnectionEnd
block|,
comment|///
comment|/// A priority list of preferred algorithms for the TLS session.
comment|/// The corresponding Data is a list of EFI_TLS_CIPHER.
comment|///
name|EfiTlsCipherList
block|,
comment|///
comment|/// TLS session compression method.
comment|/// The corresponding Data is of type EFI_TLS_COMPRESSION.
comment|///
name|EfiTlsCompressionMethod
block|,
comment|///
comment|/// TLS session extension data.
comment|/// The corresponding Data is a list of type EFI_TLS_EXTENSION .
comment|///
name|EfiTlsExtensionData
block|,
comment|///
comment|/// TLS session verify method.
comment|/// The corresponding Data is of type EFI_TLS_VERIFY.
comment|///
name|EfiTlsVerifyMethod
block|,
comment|///
comment|/// TLS session data session ID.
comment|/// For SetSessionData(), it is TLS session ID used for session resumption.
comment|/// For GetSessionData(), it is the TLS session ID used for current session.
comment|/// The corresponding Data is of type EFI_TLS_SESSION_ID.
comment|///
name|EfiTlsSessionID
block|,
comment|///
comment|/// TLS session data session state.
comment|/// The corresponding Data is of type EFI_TLS_SESSION_STATE.
comment|///
name|EfiTlsSessionState
block|,
comment|///
comment|/// Session information
comment|///
comment|///
comment|/// TLS session data client random.
comment|/// The corresponding Data is of type EFI_TLS_RANDOM.
comment|///
name|EfiTlsClientRandom
block|,
comment|///
comment|/// TLS session data server random.
comment|/// The corresponding Data is of type EFI_TLS_RANDOM.
comment|///
name|EfiTlsServerRandom
block|,
comment|///
comment|/// TLS session data key material.
comment|/// The corresponding Data is of type EFI_TLS_MASTER_SECRET.
comment|///
name|EfiTlsKeyMaterial
block|,
name|EfiTlsSessionDataTypeMaximum
block|}
name|EFI_TLS_SESSION_DATA_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_VERSION
end_comment

begin_comment
comment|/// Note: The TLS version definition is from SSL3.0 to the latest TLS (e.g. 1.2).
end_comment

begin_comment
comment|///       SSL2.0 is obsolete and should not be used.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Major
decl_stmt|;
name|UINT8
name|Minor
decl_stmt|;
block|}
name|EFI_TLS_VERSION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_CONNECTION_END to define TLS session as client or server.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiTlsClient
block|,
name|EfiTlsServer
block|, }
name|EFI_TLS_CONNECTION_END
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_CIPHER
end_comment

begin_comment
comment|/// Note: The definition of EFI_TLS_CIPHER definition is from "RFC 5246, A.4.1.
end_comment

begin_comment
comment|///       Hello Messages". The value of EFI_TLS_CIPHER is from TLS Cipher
end_comment

begin_comment
comment|///       Suite Registry of IANA.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Data1
decl_stmt|;
name|UINT8
name|Data2
decl_stmt|;
block|}
name|EFI_TLS_CIPHER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_COMPRESSION
end_comment

begin_comment
comment|/// Note: The value of EFI_TLS_COMPRESSION definition is from "RFC 3749".
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|EFI_TLS_COMPRESSION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_EXTENSION
end_comment

begin_comment
comment|/// Note: The definition of EFI_TLS_EXTENSION if from "RFC 5246 A.4.1.
end_comment

begin_comment
comment|///       Hello Messages".
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|ExtensionType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_TLS_EXTENSION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_VERIFY
end_comment

begin_comment
comment|/// Use either EFI_TLS_VERIFY_NONE or EFI_TLS_VERIFY_PEER, the last two options
end_comment

begin_comment
comment|/// are 'ORed' with EFI_TLS_VERIFY_PEER if they are desired.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_TLS_VERIFY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// No certificates will be sent or the TLS/SSL handshake will be continued regardless
end_comment

begin_comment
comment|/// of the certificate verification result.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_TLS_VERIFY_NONE
value|0x0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The TLS/SSL handshake is immediately terminated with an alert message containing
end_comment

begin_comment
comment|/// the reason for the certificate verification failure.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_TLS_VERIFY_PEER
value|0x1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TLS session will fail peer certificate is absent.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_TLS_VERIFY_FAIL_IF_NO_PEER_CERT
value|0x2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TLS session only verify client once, and doesn't request certificate during
end_comment

begin_comment
comment|/// re-negotiation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_TLS_VERIFY_CLIENT_ONCE
value|0x4
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_RANDOM
end_comment

begin_comment
comment|/// Note: The definition of EFI_TLS_RANDOM is from "RFC 5246 A.4.1.
end_comment

begin_comment
comment|///       Hello Messages".
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|GmtUnixTime
decl_stmt|;
name|UINT8
name|RandomBytes
index|[
literal|28
index|]
decl_stmt|;
block|}
name|EFI_TLS_RANDOM
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_MASTER_SECRET
end_comment

begin_comment
comment|/// Note: The definition of EFI_TLS_MASTER_SECRET is from "RFC 5246 8.1.
end_comment

begin_comment
comment|///       Computing the Master Secret".
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Data
index|[
literal|48
index|]
decl_stmt|;
block|}
name|EFI_TLS_MASTER_SECRET
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_SESSION_ID
end_comment

begin_comment
comment|/// Note: The definition of EFI_TLS_SESSION_ID is from "RFC 5246 A.4.1. Hello Messages".
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_TLS_SESSION_ID_LENGTH
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Data
index|[
name|MAX_TLS_SESSION_ID_LENGTH
index|]
decl_stmt|;
block|}
name|EFI_TLS_SESSION_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_SESSION_STATE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// When a new child of TLS protocol is created, the initial state of TLS session
comment|/// is EfiTlsSessionNotStarted.
comment|///
name|EfiTlsSessionNotStarted
block|,
comment|///
comment|/// The consumer can call BuildResponsePacket() with NULL to get ClientHello to
comment|/// start the TLS session. Then the status is EfiTlsSessionHandShaking.
comment|///
name|EfiTlsSessionHandShaking
block|,
comment|///
comment|/// During handshake, the consumer need call BuildResponsePacket() with input
comment|/// data from peer, then get response packet and send to peer. After handshake
comment|/// finish, the TLS session status becomes EfiTlsSessionDataTransferring, and
comment|/// consumer can use ProcessPacket() for data transferring.
comment|///
name|EfiTlsSessionDataTransferring
block|,
comment|///
comment|/// Finally, if consumer wants to active close TLS session, consumer need
comment|/// call SetSessionData to set TLS session state to EfiTlsSessionClosing, and
comment|/// call BuildResponsePacket() with NULL to get CloseNotify alert message,
comment|/// and sent it out.
comment|///
name|EfiTlsSessionClosing
block|,
comment|///
comment|/// If any error happen during parsing ApplicationData content type, EFI_ABORT
comment|/// will be returned by ProcessPacket(), and TLS session state will become
comment|/// EfiTlsSessionError. Then consumer need call BuildResponsePacket() with
comment|/// NULL to get alert message and sent it out.
comment|///
name|EfiTlsSessionError
block|,
name|EfiTlsSessionStateMaximum
block|}
name|EFI_TLS_SESSION_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_FRAGMENT_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Length of data buffer in the fragment.
comment|///
name|UINT32
name|FragmentLength
decl_stmt|;
comment|///
comment|/// Pointer to the data buffer in the fragment.
comment|///
name|VOID
modifier|*
name|FragmentBuffer
decl_stmt|;
block|}
name|EFI_TLS_FRAGMENT_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_CRYPT_MODE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Encrypt data provided in the fragment buffers.
comment|///
name|EfiTlsEncrypt
block|,
comment|///
comment|/// Decrypt data provided in the fragment buffers.
comment|///
name|EfiTlsDecrypt
block|, }
name|EFI_TLS_CRYPT_MODE
typedef|;
end_typedef

begin_comment
comment|/**   Set TLS session data.    The SetSessionData() function set data for a new TLS session. All session data should   be set before BuildResponsePacket() invoked.    @param[in]  This                Pointer to the EFI_TLS_PROTOCOL instance.   @param[in]  DataType            TLS session data type.   @param[in]  Data                Pointer to session data.   @param[in]  DataSize            Total size of session data.    @retval EFI_SUCCESS             The TLS session data is set successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Data is NULL.                                   DataSize is 0.   @retval EFI_UNSUPPORTED         The DataType is unsupported.   @retval EFI_ACCESS_DENIED       If the DataType is one of below:                                   EfiTlsClientRandom                                   EfiTlsServerRandom                                   EfiTlsKeyMaterial   @retval EFI_NOT_READY           Current TLS session state is NOT                                   EfiTlsSessionStateNotStarted.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TLS_SET_SESSION_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_TLS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TLS_SESSION_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get TLS session data.    The GetSessionData() function return the TLS session information.    @param[in]       This           Pointer to the EFI_TLS_PROTOCOL instance.   @param[in]       DataType       TLS session data type.   @param[in, out]  Data           Pointer to session data.   @param[in, out]  DataSize       Total size of session data. On input, it means                                   the size of Data buffer. On output, it means the size                                   of copied Data buffer if EFI_SUCCESS, and means the                                   size of desired Data buffer if EFI_BUFFER_TOO_SMALL.    @retval EFI_SUCCESS             The TLS session data is got successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   DataSize is NULL.                                   Data is NULL if *DataSize is not zero.   @retval EFI_UNSUPPORTED         The DataType is unsupported.   @retval EFI_NOT_FOUND           The TLS session data is not found.   @retval EFI_NOT_READY           The DataType is not ready in current session state.   @retval EFI_BUFFER_TOO_SMALL    The buffer is too small to hold the data. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TLS_GET_SESSION_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_TLS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TLS_SESSION_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Build response packet according to TLS state machine. This function is only valid for   alert, handshake and change_cipher_spec content type.    The BuildResponsePacket() function builds TLS response packet in response to the TLS   request packet specified by RequestBuffer and RequestSize. If RequestBuffer is NULL and   RequestSize is 0, and TLS session status is EfiTlsSessionNotStarted, the TLS session   will be initiated and the response packet needs to be ClientHello. If RequestBuffer is   NULL and RequestSize is 0, and TLS session status is EfiTlsSessionClosing, the TLS   session will be closed and response packet needs to be CloseNotify. If RequestBuffer is   NULL and RequestSize is 0, and TLS session status is EfiTlsSessionError, the TLS   session has errors and the response packet needs to be Alert message based on error   type.    @param[in]       This           Pointer to the EFI_TLS_PROTOCOL instance.   @param[in]       RequestBuffer  Pointer to the most recently received TLS packet. NULL                                   means TLS need initiate the TLS session and response                                   packet need to be ClientHello.   @param[in]       RequestSize    Packet size in bytes for the most recently received TLS                                   packet. 0 is only valid when RequestBuffer is NULL.   @param[out]      Buffer         Pointer to the buffer to hold the built packet.   @param[in, out]  BufferSize     Pointer to the buffer size in bytes. On input, it is                                   the buffer size provided by the caller. On output, it                                   is the buffer size in fact needed to contain the                                   packet.    @retval EFI_SUCCESS             The required TLS packet is built successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   RequestBuffer is NULL but RequestSize is NOT 0.                                   RequestSize is 0 but RequestBuffer is NOT NULL.                                   BufferSize is NULL.                                   Buffer is NULL if *BufferSize is not zero.   @retval EFI_BUFFER_TOO_SMALL    BufferSize is too small to hold the response packet.   @retval EFI_NOT_READY           Current TLS session state is NOT ready to build                                   ResponsePacket.   @retval EFI_ABORTED             Something wrong build response packet. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TLS_BUILD_RESPONSE_PACKET
function_decl|)
parameter_list|(
name|IN
name|EFI_TLS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
modifier|*
name|RequestBuffer
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
name|RequestSize
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Decrypt or encrypt TLS packet during session. This function is only valid after   session connected and for application_data content type.    The ProcessPacket () function process each inbound or outbound TLS APP packet.    @param[in]       This           Pointer to the EFI_TLS_PROTOCOL instance.   @param[in, out]  FragmentTable  Pointer to a list of fragment. The caller will take                                   responsible to handle the original FragmentTable while                                   it may be reallocated in TLS driver. If CryptMode is                                   EfiTlsEncrypt, on input these fragments contain the TLS                                   header and plain text TLS APP payload; on output these                                   fragments contain the TLS header and cipher text TLS                                   APP payload. If CryptMode is EfiTlsDecrypt, on input                                   these fragments contain the TLS header and cipher text                                   TLS APP payload; on output these fragments contain the                                   TLS header and plain text TLS APP payload.   @param[in]       FragmentCount  Number of fragment.   @param[in]       CryptMode      Crypt mode.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   FragmentTable is NULL.                                   FragmentCount is NULL.                                   CryptoMode is invalid.   @retval EFI_NOT_READY           Current TLS session state is NOT                                   EfiTlsSessionDataTransferring.   @retval EFI_ABORTED             Something wrong decryption the message. TLS session                                   status will become EfiTlsSessionError. The caller need                                   call BuildResponsePacket() to generate Error Alert                                   message and send it out.   @retval EFI_OUT_OF_RESOURCES    No enough resource to finish the operation. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TLS_PROCESS_PACKET
function_decl|)
parameter_list|(
name|IN
name|EFI_TLS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_TLS_FRAGMENT_DATA
modifier|*
modifier|*
name|FragmentTable
parameter_list|,
name|IN
name|UINT32
modifier|*
name|FragmentCount
parameter_list|,
name|IN
name|EFI_TLS_CRYPT_MODE
name|CryptMode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_TLS_PROTOCOL is used to create, destroy and manage TLS session.
end_comment

begin_comment
comment|/// For detail of TLS, please refer to TLS related RFC.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_TLS_PROTOCOL
block|{
name|EFI_TLS_SET_SESSION_DATA
name|SetSessionData
decl_stmt|;
name|EFI_TLS_GET_SESSION_DATA
name|GetSessionData
decl_stmt|;
name|EFI_TLS_BUILD_RESPONSE_PACKET
name|BuildResponsePacket
decl_stmt|;
name|EFI_TLS_PROCESS_PACKET
name|ProcessPacket
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTlsServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTlsProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __EFI_TLS_PROTOCOL_H__
end_comment

end_unit

