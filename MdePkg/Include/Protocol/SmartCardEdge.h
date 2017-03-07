begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The Smart Card Edge Protocol provides an abstraction for device to provide Smart   Card support.    This protocol allows UEFI applications to interface with a Smart Card during   boot process for authentication or data signing/decryption, especially if the   application has to make use of PKI.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMART_CARD_EDGE_H__
end_ifndef

begin_define
define|#
directive|define
name|__SMART_CARD_EDGE_H__
end_define

begin_define
define|#
directive|define
name|EFI_SMART_CARD_EDGE_PROTOCOL_GUID
define|\
value|{ \       0xd317f29b, 0xa325, 0x4712, {0x9b, 0xf1, 0xc6, 0x19, 0x54, 0xdc, 0x19, 0x8c} \     }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMART_CARD_EDGE_PROTOCOL
name|EFI_SMART_CARD_EDGE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Maximum size for a Smart Card AID (Application IDentifier)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SCARD_AID_MAXSIZE
value|0x0010
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Size of CSN (Card Serial Number)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SCARD_CSN_SIZE
value|0x0010
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Current specification version 1.00
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SMART_CARD_EDGE_PROTOCOL_VERSION_1
value|0x00000100
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Parameters type definition
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|SMART_CARD_AID
index|[
name|SCARD_AID_MAXSIZE
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|SMART_CARD_CSN
index|[
name|SCARD_CSN_SIZE
index|]
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Type of data elements in credentials list
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// value of tag field for header, the number of containers
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_TAG_HEADER
value|0x0000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// value of tag field for certificate
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_TAG_CERT
value|0x0001
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// value of tag field for key index associated with certificate
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_TAG_KEY_ID
value|0x0002
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// value of tag field for key type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_TAG_KEY_TYPE
value|0x0003
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// value of tag field for key size
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_TAG_KEY_SIZE
value|0x0004
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Length of L fields of TLV items
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// size of L field for header
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_L_SIZE_HEADER
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// size of L field for certificate (big endian)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_L_SIZE_CERT
value|2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// size of L field for key index
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_L_SIZE_KEY_ID
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// size of L field for key type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_L_SIZE_KEY_TYPE
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// size of L field for key size (big endian)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_L_SIZE_KEY_SIZE
value|2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Some TLV items have a fixed value for L field
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// value of L field for header
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_L_VALUE_HEADER
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// value of L field for key index
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_L_VALUE_KEY_ID
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// value of L field for key type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_L_VALUE_KEY_TYPE
value|1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// value of L field for key size
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_L_VALUE_KEY_SIZE
value|2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Possible values for key type
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RSA decryption
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_RSA_EXCHANGE
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// RSA signature
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_RSA_SIGNATURE
value|0x02
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ECDSA signature
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_ECDSA_256
value|0x03
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ECDSA signature
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_ECDSA_384
value|0x04
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ECDSA signature
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_ECDSA_521
value|0x05
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ECDH agreement
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_ECDH_256
value|0x06
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ECDH agreement
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_ECDH_384
value|0x07
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ECDH agreement
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SC_EDGE_ECDH_521
value|0x08
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Padding methods GUIDs for signature
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RSASSA- PKCS#1-V1.5 padding method, for signature
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PADDING_RSASSA_PKCS1V1P5_GUID
define|\
value|{ \     0x9317ec24, 0x7cb0, 0x4d0e, {0x8b, 0x32, 0x2e, 0xd9, 0x20, 0x9c, 0xd8, 0xaf} \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPaddingRsassaPkcs1V1P5Guid
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// RSASSA-PSS padding method, for signature
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PADDING_RSASSA_PSS_GUID
define|\
value|{ \     0x7b2349e0, 0x522d, 0x4f8e, {0xb9, 0x27, 0x69, 0xd9, 0x7c, 0x9e, 0x79, 0x5f} \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPaddingRsassaPssGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// Padding methods GUIDs for decryption
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// No padding, for decryption
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PADDING_NONE_GUID
define|\
value|{ \     0x3629ddb1, 0x228c, 0x452e, {0xb6, 0x16, 0x09, 0xed, 0x31, 0x6a, 0x97, 0x00} \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPaddingNoneGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// RSAES-PKCS#1-V1.5 padding, for decryption
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PADDING_RSAES_PKCS1V1P5_GUID
define|\
value|{ \     0xe1c1d0a9, 0x40b1, 0x4632, {0xbd, 0xcc, 0xd9, 0xd6, 0xe5, 0x29, 0x56, 0x31} \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPaddingRsaesPkcs1V1P5Guid
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// RSAES-OAEP padding, for decryption
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PADDING_RSAES_OAEP_GUID
define|\
value|{ \     0xc1e63ac4, 0xd0cf, 0x4ce6, {0x83, 0x5b, 0xee, 0xd0, 0xe6, 0xa8, 0xa4, 0x5b} \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPaddingRsaesOaepGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   This function retrieves the context driver.    The GetContextfunction returns the context of the protocol, the application   identifiers supported by the protocol and the number and the CSN unique identifier   of Smart Cards that are present and supported by protocol.    If AidTableSize, AidTable, CsnTableSize, CsnTable or VersionProtocol is NULL,   the function does not fail but does not fill in such variables.    In case AidTableSize indicates a buffer too small to hold all the protocol AID table,   only the first AidTableSize items of the table are returned in AidTable.    In case CsnTableSize indicates a buffer too small to hold the entire table of   Smart Card CSN present, only the first CsnTableSize items of the table are returned   in CsnTable.    VersionScEdgeProtocol returns the version of the EFI_SMART_CARD_EDGE_PROTOCOL this   driver uses. For this protocol specification value is SMART_CARD_EDGE_PROTOCOL_VERSION_1.    In case of Smart Card removal the internal CSN list is immediately updated, even if   a connection is opened with that Smart Card.    @param[in]      This                  Indicates a pointer to the calling context.   @param[out]     NumberAidSupported    Number of AIDs this protocol supports.   @param[in, out] AidTableSize          On input, number of items allocated for the                                         AID table. On output, number of items returned                                         by protocol.   @param[out]     AidTable              Table of the AIDs supported by the protocol.   @param[out]     NumberSCPresent       Number of currently present Smart Cards that                                         are supported by protocol.   @param[in, out] CsnTableSize          On input, the number of items the buffer CSN                                         table can contain. On output, the number of                                         items returned by the protocol.   @param[out]     CsnTable              Table of the CSN of the Smart Card present and                                         supported by protocol.   @param[out]     VersionScEdgeProtocol EFI_SMART_CARD_EDGE_PROTOCOL version.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  NumberSCPresent is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_GET_CONTEXT
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|NumberAidSupported
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|AidTableSize
name|OPTIONAL
parameter_list|,
name|OUT
name|SMART_CARD_AID
modifier|*
name|AidTable
name|OPTIONAL
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|NumberSCPresent
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|CsnTableSize
name|OPTIONAL
parameter_list|,
name|OUT
name|SMART_CARD_CSN
modifier|*
name|CsnTable
name|OPTIONAL
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|VersionScEdgeProtocol
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function establish a connection with a Smart Card the protocol support.    In case of success the SCardHandle can be used.    If the ScardCsn is NULL the connection is established with the first Smart Card   the protocol finds in its table of Smart Card present and supported. Else it   establish context with the Smart Card whose CSN given by ScardCsn.    If ScardAid is not NULL the function returns the Smart Card AID the protocol supports.   After a successful connect the SCardHandle will remain existing even in case Smart Card   removed from Smart Card reader, but all function invoking this SCardHandle will fail.   SCardHandle is released only on Disconnect.    @param[in]  This               Indicates a pointer to the calling context.   @param[out] SCardHandle        Handle on Smart Card connection.   @param[in]  ScardCsn           CSN of the Smart Card the connection has to be                                  established.   @param[out] ScardAid           AID of the Smart Card the connection has been                                  established.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  SCardHandle is NULL.   @retval EFI_NO_MEDIA           No Smart Card supported by protocol is present,                                  Smart Card with CSN ScardCsn or Reader has been                                  removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_CONNECT
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|SCardHandle
parameter_list|,
name|IN
name|UINT8
modifier|*
name|ScardCsn
name|OPTIONAL
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|ScardAid
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function releases a connection previously established by Connect.    The Disconnect function releases the connection previously established by   a Connect. In case the Smart Card or the Smart Card reader has been removed   before this call, this function returns EFI_SUCCESS.    @param[in]  This               Indicates a pointer to the calling context.   @param[in]  SCardHandle        Handle on Smart Card connection to release.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_DISCONNECT
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function returns the Smart Card serial number.    @param[in]  This               Indicates a pointer to the calling context.   @param[in]  SCardHandle        Handle on Smart Card connection.   @param[out] Csn                The Card Serial number, 16 bytes array.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.   @retval EFI_NO_MEDIA           Smart Card or Reader of SCardHandle connection                                  has been removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_GET_CSN
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|,
name|OUT
name|UINT8
name|Csn
index|[
name|SCARD_CSN_SIZE
index|]
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function returns the name of the Smart Card reader used for this connection.    @param[in]      This              Indicates a pointer to the calling context.   @param[in]      SCardHandle       Handle on Smart Card connection.   @param[in, out] ReaderNameLength  On input, a pointer to the variable that holds                                     the maximal size, in bytes, of ReaderName.                                     On output, the required size, in bytes, for ReaderName.   @param[out]     ReaderName        A pointer to a NULL terminated string that will                                     contain the reader name.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.   @retval EFI_INVALID_PARAMETER  ReaderNameLength is NULL.   @retval EFI_NO_MEDIA           Smart Card or Reader of SCardHandle connection                                  has been removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_GET_READER_NAME
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|ReaderNameLength
parameter_list|,
name|OUT
name|CHAR16
modifier|*
name|ReaderName
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function authenticates a Smart Card user by presenting a PIN code.    The VerifyPinfunction presents a PIN code to the Smart Card.    If Smart Card found the PIN code correct the user is considered authenticated   to current application, and the function returns TRUE.    Negative or null PinSize value rejected if PinCodeis not NULL.    A NULL PinCodebuffer means the application didn't know the PIN, in that case:     - If PinSize value is negative the caller only wants to know if the current       chain of the elements Smart Card Edge protocol, Smart Card Reader protocol       and Smart Card Reader supports the Secure Pin Entry PCSC V2 functionality.     - If PinSize value is positive or null the caller ask to perform the verify       PIN using the Secure PIN Entry functionality.    In PinCode buffer, the PIN value is always given in plaintext, in case of secure   messaging the SMART_CARD_EDGE_PROTOCOL will be in charge of all intermediate   treatments to build the correct Smart Card APDU.    @param[in]  This               Indicates a pointer to the calling context.   @param[in]  SCardHandle        Handle on Smart Card connection.   @param[in]  PinSize            PIN code buffer size.   @param[in]  PinCode            PIN code to present to the Smart Card.   @param[out] PinResult          Result of PIN code presentation to the Smart Card.                                  TRUE when Smard Card founds the PIN code correct.   @param[out] RemainingAttempts  Number of attempts still possible.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_UNSUPPORTED        Pinsize< 0 and Secure PIN Entry functionality not                                  supported.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.   @retval EFI_INVALID_PARAMETER  Bad value for PinSize: value not supported by Smart                                  Card or, negative with PinCode not null.   @retval EFI_INVALID_PARAMETER  PinResult is NULL.   @retval EFI_NO_MEDIA           Smart Card or Reader of SCardHandle connection                                  has been removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_VERIFY_PIN
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|,
name|IN
name|INT32
name|PinSize
parameter_list|,
name|IN
name|UINT8
modifier|*
name|PinCode
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|PinResult
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|RemainingAttempts
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function gives the remaining number of attempts for PIN code presentation.    The number of attempts to present a correct PIN is limited and depends on Smart   Card and on PIN.    This function will retrieve the number of remaining possible attempts.    @param[in]  This               Indicates a pointer to the calling context.   @param[in]  SCardHandle        Handle on Smart Card connection.   @param[out] RemainingAttempts  Number of attempts still possible.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.   @retval EFI_INVALID_PARAMETER  RemainingAttempts is NULL.   @retval EFI_NO_MEDIA           Smart Card or Reader of SCardHandle connection                                  has been removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_GET_PIN_REMAINING
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|RemainingAttempts
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function returns a specific data from Smart Card.    The function is generic for any kind of data, but driver and application must   share an EFI_GUID that identify the data.    @param[in]      This           Indicates a pointer to the calling context.   @param[in]      SCardHandle    Handle on Smart Card connection.   @param[in]      DataId         The type identifier of the data to get.   @param[in, out] DataSize       On input, in bytes, the size of Data. On output,                                  in bytes, the size of buffer required to store                                  the specified data.   @param[out]     Data           The data buffer in which the data is returned.                                  The type of the data buffer is associated with                                  the DataId. Ignored if *DataSize is 0.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.   @retval EFI_INVALID_PARAMETER  DataId is NULL.   @retval EFI_INVALID_PARAMETER  DataSize is NULL.   @retval EFI_INVALID_PARAMETER  Data is NULL, and *DataSize is not zero.   @retval EFI_NOT_FOUND          DataId unknown for this driver.   @retval EFI_BUFFER_TOO_SMALL   The size of Data is too small for the specified                                  data and the required size is returned in DataSize.   @retval EFI_ACCESS_DENIED      Operation not performed, conditions not fulfilled.                                  PIN not verified.   @retval EFI_NO_MEDIA           Smart Card or Reader of SCardHandle connection                                  has been removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|DataId
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Data
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function retrieve credentials store into the Smart Card.    The function returns a series of items in TLV (Tag Length Value) format.    First TLV item is the header item that gives the number of following   containers (0x00, 0x01, Nb containers).    All these containers are a series of 4 TLV items:     - The certificate item (0x01, certificate size, certificate)     - The Key identifier item (0x02, 0x01, key index)     - The key type item (0x03, 0x01, key type)     - The key size item (0x04, 0x02, key size), key size in number of bits.   Numeric multi-bytes values are on big endian format, most significant byte first:     - The L field value for certificate (2 bytes)     - The L field value for key size (2 bytes)     - The value field for key size (2 bytes)    @param[in]      This           Indicates a pointer to the calling context.   @param[in]      SCardHandle    Handle on Smart Card connection.   @param[in, out] CredentialSize On input, in bytes, the size of buffer to store                                  the list of credential.                                  On output, in bytes, the size of buffer required                                  to store the entire list of credentials.    @param[out]     CredentialList List of credentials stored into the Smart Card.                                  A list of TLV (Tag Length Value) elements organized                                  in containers array.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.   @retval EFI_INVALID_PARAMETER  CredentialSize is NULL.   @retval EFI_INVALID_PARAMETER  CredentialList is NULL, if CredentialSize is not zero.   @retval EFI_BUFFER_TOO_SMALL   The size of CredentialList is too small for the                                  specified data and the required size is returned in                                  CredentialSize.   @retval EFI_NO_MEDIA           Smart Card or Reader of SCardHandle connection                                  has been removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_GET_CREDENTIAL
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|CredentialSize
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|CredentialList
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function signs an already hashed data with a Smart Card private key.    This function signs data, actually it is the hash of these data that is given   to the function.    SignatureData buffer shall be big enough for signature. Signature size is   function key size and key type.    @param[in]  This               Indicates a pointer to the calling context.   @param[in]  SCardHandle        Handle on Smart Card connection.   @param[in]  KeyId              Identifier of the key container, retrieved                                  in a key index item of credentials.   @param[in]  KeyType            The key type, retrieved in a key type item of                                  credentials.    @param[in]  HashAlgorithm      Hash algorithm used to hash the, one of:                                    - EFI_HASH_ALGORITHM_SHA1_GUID                                    - EFI_HASH_ALGORITHM_SHA256_GUID                                    - EFI_HASH_ALGORITHM_SHA384_GUID                                    - EFI_HASH_ALGORITHM_SHA512_GUID   @param[in]  PaddingMethod      Padding method used jointly with hash algorithm,                                  one of:                                    - EFI_PADDING_RSASSA_PKCS1V1P5_GUID                                    - EFI_PADDING_RSASSA_PSS_GUID   @param[in]  HashedData         Hash of the data to sign. Size is function of the                                  HashAlgorithm.    @param[out] SignatureData      Resulting signature with private key KeyId. Size                                  is function of the KeyType and key size retrieved                                  in the associated key size item of credentials.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.   @retval EFI_INVALID_PARAMETER  KeyId is not valid.   @retval EFI_INVALID_PARAMETER  KeyType is not valid or not corresponding to KeyId.   @retval EFI_INVALID_PARAMETER  HashAlgorithm is NULL.   @retval EFI_INVALID_PARAMETER  HashAlgorithm is not valid.   @retval EFI_INVALID_PARAMETER  PaddingMethod is NULL.   @retval EFI_INVALID_PARAMETER  PaddingMethod is not valid.   @retval EFI_INVALID_PARAMETER  HashedData is NULL.   @retval EFI_INVALID_PARAMETER  SignatureData is NULL.   @retval EFI_ACCESS_DENIED      Operation not performed, conditions not fulfilled.                                  PIN not verified.   @retval EFI_NO_MEDIA           Smart Card or Reader of SCardHandle connection                                  has been removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_SIGN_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|,
name|IN
name|UINTN
name|KeyId
parameter_list|,
name|IN
name|UINTN
name|KeyType
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|HashAlgorithm
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|PaddingMethod
parameter_list|,
name|IN
name|UINT8
modifier|*
name|HashedData
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|SignatureData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function decrypts data with a PKI/RSA Smart Card private key.    The function decrypts some PKI/RSA encrypted data with private key securely   stored into the Smart Card.    The KeyId must reference a key of type SC_EDGE_RSA_EXCHANGE.    @param[in]      This           Indicates a pointer to the calling context.   @param[in]      SCardHandle    Handle on Smart Card connection.   @param[in]      KeyId          Identifier of the key container, retrieved                                  in a key index item of credentials.   @param[in]      HashAlgorithm  Hash algorithm used to hash the, one of:                                    - EFI_HASH_ALGORITHM_SHA1_GUID                                    - EFI_HASH_ALGORITHM_SHA256_GUID                                    - EFI_HASH_ALGORITHM_SHA384_GUID                                    - EFI_HASH_ALGORITHM_SHA512_GUID   @param[in]      PaddingMethod  Padding method used jointly with hash algorithm,                                  one of:                                    - EFI_PADDING_NONE_GUID                                    - EFI_PADDING_RSAES_PKCS1V1P5_GUID                                    - EFI_PADDING_RSAES_OAEP_GUID   @param[in]      EncryptedSize  Size of data to decrypt.   @param[in]      EncryptedData  Data to decrypt   @param[in, out] PlaintextSize  On input, in bytes, the size of buffer to store                                  the decrypted data.                                  On output, in bytes, the size of buffer required                                  to store the decrypted data.   @param[out]     PlaintextData  Buffer for decrypted data, padding removed.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.   @retval EFI_INVALID_PARAMETER  KeyId is not valid or associated key not of type                                  SC_EDGE_RSA_EXCHANGE.   @retval EFI_INVALID_PARAMETER  HashAlgorithm is NULL.   @retval EFI_INVALID_PARAMETER  HashAlgorithm is not valid.   @retval EFI_INVALID_PARAMETER  PaddingMethod is NULL.   @retval EFI_INVALID_PARAMETER  PaddingMethod is not valid.   @retval EFI_INVALID_PARAMETER  EncryptedSize is 0.   @retval EFI_INVALID_PARAMETER  EncryptedData is NULL.   @retval EFI_INVALID_PARAMETER  PlaintextSize is NULL.   @retval EFI_INVALID_PARAMETER  PlaintextData is NULL.   @retval EFI_ACCESS_DENIED      Operation not performed, conditions not fulfilled.                                  PIN not verified.   @retval EFI_BUFFER_TOO_SMALL   PlaintextSize is too small for the plaintext data                                  and the required size is returned in PlaintextSize.   @retval EFI_NO_MEDIA           Smart Card or Reader of SCardHandle connection                                  has been removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_DECRYPT_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|,
name|IN
name|UINTN
name|KeyId
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|HashAlgorithm
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|PaddingMethod
parameter_list|,
name|IN
name|UINTN
name|EncryptedSize
parameter_list|,
name|IN
name|UINT8
modifier|*
name|EncryptedData
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|PlaintextSize
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|PlaintextData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function performs a secret Diffie Hellman agreement calculation that would   be used to derive a symmetric encryption / decryption key.    The function compute a DH agreement that should be diversified togenerate a symmetric   key to proceed encryption or decryption.    The application and the Smart Card shall agree on the diversification process.    The KeyId must reference a key of one of the types: SC_EDGE_ECDH_256, SC_EDGE_ECDH_384   or SC_EDGE_ECDH_521.    @param[in]  This               Indicates a pointer to the calling context.   @param[in]  SCardHandle        Handle on Smart Card connection.   @param[in]  KeyId              Identifier of the key container, retrieved                                  in a key index item of credentials.   @param[in]  dataQx             Public key x coordinate. Size is the same as                                  key size for KeyId. Stored in big endian format.   @param[in]  dataQy             Public key y coordinate. Size is the same as                                  key size for KeyId. Stored in big endian format.   @param[out] DHAgreement        Buffer for DH agreement computed. Size must be                                  bigger or equal to key size for KeyId.    @retval EFI_SUCCESS            The requested command completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_INVALID_PARAMETER  No connection for SCardHandle value.   @retval EFI_INVALID_PARAMETER  KeyId is not valid.   @retval EFI_INVALID_PARAMETER  dataQx is NULL.   @retval EFI_INVALID_PARAMETER  dataQy is NULL.   @retval EFI_INVALID_PARAMETER  DHAgreement is NULL.   @retval EFI_ACCESS_DENIED      Operation not performed, conditions not fulfilled.                                  PIN not verified.   @retval EFI_NO_MEDIA           Smart Card or Reader of SCardHandle connection                                  has been removed. A Disconnect should be performed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMART_CARD_EDGE_BUILD_DH_AGREEMENT
function_decl|)
parameter_list|(
name|IN
name|EFI_SMART_CARD_EDGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|SCardHandle
parameter_list|,
name|IN
name|UINTN
name|KeyId
parameter_list|,
name|IN
name|UINT8
modifier|*
name|dataQx
parameter_list|,
name|IN
name|UINT8
modifier|*
name|dataQy
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|DHAgreement
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Smart card aware application invokes this protocol to get access to an inserted
end_comment

begin_comment
comment|/// smart card in the reader or to the reader itself.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMART_CARD_EDGE_PROTOCOL
block|{
name|EFI_SMART_CARD_EDGE_GET_CONTEXT
name|GetContext
decl_stmt|;
name|EFI_SMART_CARD_EDGE_CONNECT
name|Connect
decl_stmt|;
name|EFI_SMART_CARD_EDGE_DISCONNECT
name|Disconnect
decl_stmt|;
name|EFI_SMART_CARD_EDGE_GET_CSN
name|GetCsn
decl_stmt|;
name|EFI_SMART_CARD_EDGE_GET_READER_NAME
name|GetReaderName
decl_stmt|;
name|EFI_SMART_CARD_EDGE_VERIFY_PIN
name|VerifyPin
decl_stmt|;
name|EFI_SMART_CARD_EDGE_GET_PIN_REMAINING
name|GetPinRemaining
decl_stmt|;
name|EFI_SMART_CARD_EDGE_GET_DATA
name|GetData
decl_stmt|;
name|EFI_SMART_CARD_EDGE_GET_CREDENTIAL
name|GetCredential
decl_stmt|;
name|EFI_SMART_CARD_EDGE_SIGN_DATA
name|SignData
decl_stmt|;
name|EFI_SMART_CARD_EDGE_DECRYPT_DATA
name|DecryptData
decl_stmt|;
name|EFI_SMART_CARD_EDGE_BUILD_DH_AGREEMENT
name|BuildDHAgreement
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmartCardEdgeProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

