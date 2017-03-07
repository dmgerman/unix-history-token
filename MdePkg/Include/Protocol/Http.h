begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI HTTP Protocol interface. It is split into   the following two main sections:   HTTP Service Binding Protocol (HTTPSB)   HTTP Protocol (HTTP)    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   (C) Copyright 2015 Hewlett Packard Enterprise Development LP<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_HTTP_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_HTTP_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_HTTP_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xbdc8e6af, 0xd9bc, 0x4379, {0xa7, 0x2a, 0xe0, 0xc4, 0xe7, 0x5d, 0xae, 0x1c } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HTTP_PROTOCOL_GUID
define|\
value|{ \     0x7a59b29b, 0x910b, 0x4171, {0x82, 0x42, 0xa8, 0x5a, 0x0d, 0xf2, 0x5b, 0x5b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_HTTP_PROTOCOL
name|EFI_HTTP_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_VERSION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HttpVersion10
block|,
name|HttpVersion11
block|,
name|HttpVersionUnsupported
block|}
name|EFI_HTTP_VERSION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_METHOD
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HttpMethodGet
block|,
name|HttpMethodPost
block|,
name|HttpMethodPatch
block|,
name|HttpMethodOptions
block|,
name|HttpMethodConnect
block|,
name|HttpMethodHead
block|,
name|HttpMethodPut
block|,
name|HttpMethodDelete
block|,
name|HttpMethodTrace
block|,
name|HttpMethodMax
block|}
name|EFI_HTTP_METHOD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_STATUS_CODE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HTTP_STATUS_UNSUPPORTED_STATUS
init|=
literal|0
block|,
name|HTTP_STATUS_100_CONTINUE
block|,
name|HTTP_STATUS_101_SWITCHING_PROTOCOLS
block|,
name|HTTP_STATUS_200_OK
block|,
name|HTTP_STATUS_201_CREATED
block|,
name|HTTP_STATUS_202_ACCEPTED
block|,
name|HTTP_STATUS_203_NON_AUTHORITATIVE_INFORMATION
block|,
name|HTTP_STATUS_204_NO_CONTENT
block|,
name|HTTP_STATUS_205_RESET_CONTENT
block|,
name|HTTP_STATUS_206_PARTIAL_CONTENT
block|,
name|HTTP_STATUS_300_MULTIPLE_CHIOCES
block|,
name|HTTP_STATUS_301_MOVED_PERMANENTLY
block|,
name|HTTP_STATUS_302_FOUND
block|,
name|HTTP_STATUS_303_SEE_OTHER
block|,
name|HTTP_STATUS_304_NOT_MODIFIED
block|,
name|HTTP_STATUS_305_USE_PROXY
block|,
name|HTTP_STATUS_307_TEMPORARY_REDIRECT
block|,
name|HTTP_STATUS_400_BAD_REQUEST
block|,
name|HTTP_STATUS_401_UNAUTHORIZED
block|,
name|HTTP_STATUS_402_PAYMENT_REQUIRED
block|,
name|HTTP_STATUS_403_FORBIDDEN
block|,
name|HTTP_STATUS_404_NOT_FOUND
block|,
name|HTTP_STATUS_405_METHOD_NOT_ALLOWED
block|,
name|HTTP_STATUS_406_NOT_ACCEPTABLE
block|,
name|HTTP_STATUS_407_PROXY_AUTHENTICATION_REQUIRED
block|,
name|HTTP_STATUS_408_REQUEST_TIME_OUT
block|,
name|HTTP_STATUS_409_CONFLICT
block|,
name|HTTP_STATUS_410_GONE
block|,
name|HTTP_STATUS_411_LENGTH_REQUIRED
block|,
name|HTTP_STATUS_412_PRECONDITION_FAILED
block|,
name|HTTP_STATUS_413_REQUEST_ENTITY_TOO_LARGE
block|,
name|HTTP_STATUS_414_REQUEST_URI_TOO_LARGE
block|,
name|HTTP_STATUS_415_UNSUPPORTED_MEDIA_TYPE
block|,
name|HTTP_STATUS_416_REQUESTED_RANGE_NOT_SATISFIED
block|,
name|HTTP_STATUS_417_EXPECTATION_FAILED
block|,
name|HTTP_STATUS_500_INTERNAL_SERVER_ERROR
block|,
name|HTTP_STATUS_501_NOT_IMPLEMENTED
block|,
name|HTTP_STATUS_502_BAD_GATEWAY
block|,
name|HTTP_STATUS_503_SERVICE_UNAVAILABLE
block|,
name|HTTP_STATUS_504_GATEWAY_TIME_OUT
block|,
name|HTTP_STATUS_505_HTTP_VERSION_NOT_SUPPORTED
block|}
name|EFI_HTTP_STATUS_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTPv4_ACCESS_POINT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Set to TRUE to instruct the EFI HTTP instance to use the default address
comment|/// information in every TCP connection made by this instance. In addition, when set
comment|/// to TRUE, LocalAddress and LocalSubnet are ignored.
comment|///
name|BOOLEAN
name|UseDefaultAddress
decl_stmt|;
comment|///
comment|/// If UseDefaultAddress is set to FALSE, this defines the local IP address to be
comment|/// used in every TCP connection opened by this instance.
comment|///
name|EFI_IPv4_ADDRESS
name|LocalAddress
decl_stmt|;
comment|///
comment|/// If UseDefaultAddress is set to FALSE, this defines the local subnet to be used
comment|/// in every TCP connection opened by this instance.
comment|///
name|EFI_IPv4_ADDRESS
name|LocalSubnet
decl_stmt|;
comment|///
comment|/// This defines the local port to be used in
comment|/// every TCP connection opened by this instance.
comment|///
name|UINT16
name|LocalPort
decl_stmt|;
block|}
name|EFI_HTTPv4_ACCESS_POINT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTPv6_ACCESS_POINT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Local IP address to be used in every TCP connection opened by this instance.
comment|///
name|EFI_IPv6_ADDRESS
name|LocalAddress
decl_stmt|;
comment|///
comment|/// Local port to be used in every TCP connection opened by this instance.
comment|///
name|UINT16
name|LocalPort
decl_stmt|;
block|}
name|EFI_HTTPv6_ACCESS_POINT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_CONFIG_DATA_ACCESS_POINT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// HTTP version that this instance will support.
comment|///
name|EFI_HTTP_VERSION
name|HttpVersion
decl_stmt|;
comment|///
comment|/// Time out (in milliseconds) when blocking for requests.
comment|///
name|UINT32
name|TimeOutMillisec
decl_stmt|;
comment|///
comment|/// Defines behavior of EFI DNS and TCP protocols consumed by this instance. If
comment|/// FALSE, this instance will use EFI_DNS4_PROTOCOL and EFI_TCP4_PROTOCOL. If TRUE,
comment|/// this instance will use EFI_DNS6_PROTOCOL and EFI_TCP6_PROTOCOL.
comment|///
name|BOOLEAN
name|LocalAddressIsIPv6
decl_stmt|;
union|union
block|{
comment|///
comment|/// When LocalAddressIsIPv6 is FALSE, this points to the local address, subnet, and
comment|/// port used by the underlying TCP protocol.
comment|///
name|EFI_HTTPv4_ACCESS_POINT
modifier|*
name|IPv4Node
decl_stmt|;
comment|///
comment|/// When LocalAddressIsIPv6 is TRUE, this points to the local IPv6 address and port
comment|/// used by the underlying TCP protocol.
comment|///
name|EFI_HTTPv6_ACCESS_POINT
modifier|*
name|IPv6Node
decl_stmt|;
block|}
name|AccessPoint
union|;
block|}
name|EFI_HTTP_CONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_REQUEST_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HTTP method (e.g. GET, POST) for this HTTP Request.
comment|///
name|EFI_HTTP_METHOD
name|Method
decl_stmt|;
comment|///
comment|/// The URI of a remote host. From the information in this field, the HTTP instance
comment|/// will be able to determine whether to use HTTP or HTTPS and will also be able to
comment|/// determine the port number to use. If no port number is specified, port 80 (HTTP)
comment|/// is assumed. See RFC 3986 for more details on URI syntax.
comment|///
name|CHAR16
modifier|*
name|Url
decl_stmt|;
block|}
name|EFI_HTTP_REQUEST_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_RESPONSE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Response status code returned by the remote host.
comment|///
name|EFI_HTTP_STATUS_CODE
name|StatusCode
decl_stmt|;
block|}
name|EFI_HTTP_RESPONSE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Null terminated string which describes a field name. See RFC 2616 Section 14 for
comment|/// detailed information about field names.
comment|///
name|CHAR8
modifier|*
name|FieldName
decl_stmt|;
comment|///
comment|/// Null terminated string which describes the corresponding field value. See RFC 2616
comment|/// Section 14 for detailed information about field values.
comment|///
name|CHAR8
modifier|*
name|FieldValue
decl_stmt|;
block|}
name|EFI_HTTP_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_MESSAGE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// HTTP message data.
comment|///
union|union
block|{
comment|///
comment|/// When the token is used to send a HTTP request, Request is a pointer to storage that
comment|/// contains such data as URL and HTTP method.
comment|///
name|EFI_HTTP_REQUEST_DATA
modifier|*
name|Request
decl_stmt|;
comment|///
comment|/// When used to await a response, Response points to storage containing HTTP response
comment|/// status code.
comment|///
name|EFI_HTTP_RESPONSE_DATA
modifier|*
name|Response
decl_stmt|;
block|}
name|Data
union|;
comment|///
comment|/// Number of HTTP header structures in Headers list. On request, this count is
comment|/// provided by the caller. On response, this count is provided by the HTTP driver.
comment|///
name|UINTN
name|HeaderCount
decl_stmt|;
comment|///
comment|/// Array containing list of HTTP headers. On request, this array is populated by the
comment|/// caller. On response, this array is allocated and populated by the HTTP driver. It
comment|/// is the responsibility of the caller to free this memory on both request and
comment|/// response.
comment|///
name|EFI_HTTP_HEADER
modifier|*
name|Headers
decl_stmt|;
comment|///
comment|/// Length in bytes of the HTTP body. This can be zero depending on the HttpMethod type.
comment|///
name|UINTN
name|BodyLength
decl_stmt|;
comment|///
comment|/// Body associated with the HTTP request or response. This can be NULL depending on
comment|/// the HttpMethod type.
comment|///
name|VOID
modifier|*
name|Body
decl_stmt|;
block|}
name|EFI_HTTP_MESSAGE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HTTP_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated by the EFI HTTP
comment|/// Protocol driver. The type of Event must be EFI_NOTIFY_SIGNAL. The Task Priority
comment|/// Level (TPL) of Event must be lower than or equal to TPL_CALLBACK.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Status will be set to one of the following value if the HTTP request is
comment|/// successfully sent or if an unexpected error occurs:
comment|///   EFI_SUCCESS:      The HTTP request was successfully sent to the remote host.
comment|///   EFI_HTTP_ERROR:   The response message was successfully received but contains a
comment|///                     HTTP error. The response status code is returned in token.
comment|///   EFI_ABORTED:      The HTTP request was cancelled by the caller and removed from
comment|///                     the transmit queue.
comment|///   EFI_TIMEOUT:      The HTTP request timed out before reaching the remote host.
comment|///   EFI_DEVICE_ERROR: An unexpected system or network error occurred.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// Pointer to storage containing HTTP message data.
comment|///
name|EFI_HTTP_MESSAGE
modifier|*
name|Message
decl_stmt|;
block|}
name|EFI_HTTP_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Returns the operational parameters for the current HTTP child instance.    The GetModeData() function is used to read the current mode data (operational   parameters) for this HTTP protocol instance.    @param[in]  This                Pointer to EFI_HTTP_PROTOCOL instance.   @param[out] HttpConfigData      Point to buffer for operational parameters of this                                   HTTP instance.    @retval EFI_SUCCESS             Operation succeeded.   @retval EFI_INVALID_PARAMETER   This is NULL.                                   HttpConfigData is NULL.                                   HttpInstance->LocalAddressIsIPv6 is FALSE and                                   HttpConfigData->IPv4Node is NULL.                                   HttpInstance->LocalAddressIsIPv6 is TRUE and                                   HttpConfigData->IPv6Node is NULL.   @retval EFI_NOT_STARTED         This EFI HTTP Protocol instance has not been started. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HTTP_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_HTTP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_HTTP_CONFIG_DATA
modifier|*
name|HttpConfigData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Initialize or brutally reset the operational parameters for this EFI HTTP instance.    The Configure() function does the following:   When HttpConfigData is not NULL Initialize this EFI HTTP instance by configuring   timeout, local address, port, etc.   When HttpConfigData is NULL, reset this EFI HTTP instance by closing all active   connections with remote hosts, canceling all asynchronous tokens, and flush request   and response buffers without informing the appropriate hosts.    No other EFI HTTP function can be executed by this instance until the Configure()   function is executed and returns successfully.    @param[in]  This                Pointer to EFI_HTTP_PROTOCOL instance.   @param[in]  HttpConfigData      Pointer to the configure data to configure the instance.    @retval EFI_SUCCESS             Operation succeeded.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   HttpConfigData->LocalAddressIsIPv6 is FALSE and                                   HttpConfigData->IPv4Node is NULL.                                   HttpConfigData->LocalAddressIsIPv6 is TRUE and                                   HttpConfigData->IPv6Node is NULL.   @retval EFI_ALREADY_STARTED     Reinitialize this HTTP instance without calling                                   Configure() with NULL to reset it.   @retval EFI_DEVICE_ERROR        An unexpected system or network error occurred.   @retval EFI_OUT_OF_RESOURCES    Could not allocate enough system resources when                                   executing Configure().   @retval EFI_UNSUPPORTED         One or more options in ConfigData are not supported                                   in the implementation. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HTTP_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_HTTP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HTTP_CONFIG_DATA
modifier|*
name|HttpConfigData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The Request() function queues an HTTP request to this HTTP instance,    similar to Transmit() function in the EFI TCP driver. When the HTTP request is sent   successfully, or if there is an error, Status in token will be updated and Event will   be signaled.    @param[in]  This                Pointer to EFI_HTTP_PROTOCOL instance.   @param[in]  Token               Pointer to storage containing HTTP request token.    @retval EFI_SUCCESS             Outgoing data was processed.   @retval EFI_NOT_STARTED         This EFI HTTP Protocol instance has not been started.   @retval EFI_DEVICE_ERROR        An unexpected system or network error occurred.   @retval EFI_TIMEOUT             Data was dropped out of the transmit or receive queue.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Token is NULL.                                   Token->Message is NULL.                                   Token->Message->Body is not NULL,                                   Token->Message->BodyLength is non-zero, and                                   Token->Message->Data is NULL, but a previous call to                                   Request()has not been completed successfully.   @retval EFI_OUT_OF_RESOURCES    Could not allocate enough system resources.   @retval EFI_UNSUPPORTED         The HTTP method is not supported in current implementation. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HTTP_REQUEST
function_decl|)
parameter_list|(
name|IN
name|EFI_HTTP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HTTP_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Abort an asynchronous HTTP request or response token.    The Cancel() function aborts a pending HTTP request or response transaction. If   Token is not NULL and the token is in transmit or receive queues when it is being   cancelled, its Token->Status will be set to EFI_ABORTED and then Token->Event will   be signaled. If the token is not in one of the queues, which usually means that the   asynchronous operation has completed, EFI_NOT_FOUND is returned. If Token is NULL,   all asynchronous tokens issued by Request() or Response() will be aborted.    @param[in]  This                Pointer to EFI_HTTP_PROTOCOL instance.   @param[in]  Token               Point to storage containing HTTP request or response                                   token.    @retval EFI_SUCCESS             Request and Response queues are successfully flushed.   @retval EFI_INVALID_PARAMETER   This is NULL.   @retval EFI_NOT_STARTED         This instance hasn't been configured.   @retval EFI_NOT_FOUND           The asynchronous request or response token is not                                   found.   @retval EFI_UNSUPPORTED         The implementation does not support this function. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HTTP_CANCEL
function_decl|)
parameter_list|(
name|IN
name|EFI_HTTP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HTTP_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The Response() function queues an HTTP response to this HTTP instance, similar to   Receive() function in the EFI TCP driver. When the HTTP Response is received successfully,   or if there is an error, Status in token will be updated and Event will be signaled.    The HTTP driver will queue a receive token to the underlying TCP instance. When data   is received in the underlying TCP instance, the data will be parsed and Token will   be populated with the response data. If the data received from the remote host   contains an incomplete or invalid HTTP header, the HTTP driver will continue waiting   (asynchronously) for more data to be sent from the remote host before signaling   Event in Token.    It is the responsibility of the caller to allocate a buffer for Body and specify the   size in BodyLength. If the remote host provides a response that contains a content   body, up to BodyLength bytes will be copied from the receive buffer into Body and   BodyLength will be updated with the amount of bytes received and copied to Body. This   allows the client to download a large file in chunks instead of into one contiguous   block of memory. Similar to HTTP request, if Body is not NULL and BodyLength is   non-zero and all other fields are NULL or 0, the HTTP driver will queue a receive   token to underlying TCP instance. If data arrives in the receive buffer, up to   BodyLength bytes of data will be copied to Body. The HTTP driver will then update   BodyLength with the amount of bytes received and copied to Body.    If the HTTP driver does not have an open underlying TCP connection with the host   specified in the response URL, Request() will return EFI_ACCESS_DENIED. This is   consistent with RFC 2616 recommendation that HTTP clients should attempt to maintain   an open TCP connection between client and host.    @param[in]  This                Pointer to EFI_HTTP_PROTOCOL instance.   @param[in]  Token               Pointer to storage containing HTTP response token.    @retval EFI_SUCCESS             Allocation succeeded.   @retval EFI_NOT_STARTED         This EFI HTTP Protocol instance has not been                                   initialized.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Token is NULL.                                   Token->Message->Headers is NULL.                                   Token->Message is NULL.                                   Token->Message->Body is not NULL,                                   Token->Message->BodyLength is non-zero, and                                   Token->Message->Data is NULL, but a previous call to                                   Response() has not been completed successfully.   @retval EFI_OUT_OF_RESOURCES    Could not allocate enough system resources.   @retval EFI_ACCESS_DENIED       An open TCP connection is not present with the host                                   specified by response URL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HTTP_RESPONSE
function_decl|)
parameter_list|(
name|IN
name|EFI_HTTP_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HTTP_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The Poll() function can be used by network drivers and applications to increase the   rate that data packets are moved between the communication devices and the transmit   and receive queues.    In some systems, the periodic timer event in the managed network driver may not poll   the underlying communications device fast enough to transmit and/or receive all data   packets without missing incoming packets or dropping outgoing packets. Drivers and   applications that are experiencing packet loss should try calling the Poll() function   more often.    @param[in]  This                Pointer to EFI_HTTP_PROTOCOL instance.    @retval EFI_SUCCESS             Incoming or outgoing data was processed..   @retval EFI_DEVICE_ERROR        An unexpected system or network error occurred   @retval EFI_INVALID_PARAMETER   This is NULL.   @retval EFI_NOT_READY           No incoming or outgoing data is processed.   @retval EFI_NOT_STARTED         This EFI HTTP Protocol instance has not been started. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HTTP_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_HTTP_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI HTTP protocol is designed to be used by EFI drivers and applications to
end_comment

begin_comment
comment|/// create and transmit HTTP Requests, as well as handle HTTP responses that are
end_comment

begin_comment
comment|/// returned by a remote host. This EFI protocol uses and relies on an underlying EFI
end_comment

begin_comment
comment|/// TCP protocol.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_HTTP_PROTOCOL
block|{
name|EFI_HTTP_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_HTTP_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_HTTP_REQUEST
name|Request
decl_stmt|;
name|EFI_HTTP_CANCEL
name|Cancel
decl_stmt|;
name|EFI_HTTP_RESPONSE
name|Response
decl_stmt|;
name|EFI_HTTP_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHttpServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHttpProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

