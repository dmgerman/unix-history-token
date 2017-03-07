begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI TCPv4(Transmission Control Protocol version 4) Protocol Definition   The EFI TCPv4 Service Binding Protocol is used to locate EFI TCPv4 Protocol drivers to create   and destroy child of the driver to communicate with other host using TCP protocol.   The EFI TCPv4 Protocol provides services to send and receive data stream.  Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_TCP4_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_TCP4_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Ip4.h>
end_include

begin_define
define|#
directive|define
name|EFI_TCP4_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x00720665, 0x67EB, 0x4a99, {0xBA, 0xF7, 0xD3, 0xC3, 0x3A, 0x1C, 0x7C, 0xC9 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_TCP4_PROTOCOL_GUID
define|\
value|{ \     0x65530BC7, 0xA359, 0x410f, {0xB0, 0x10, 0x5A, 0xAD, 0xC7, 0xEC, 0x2B, 0x62 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_TCP4_PROTOCOL
name|EFI_TCP4_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP4_SERVICE_POINT is deprecated in the UEFI 2.4B and should not be used any more.
end_comment

begin_comment
comment|/// The definition in here is only present to provide backwards compatability.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_HANDLE
name|InstanceHandle
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|LocalAddress
decl_stmt|;
name|UINT16
name|LocalPort
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|RemoteAddress
decl_stmt|;
name|UINT16
name|RemotePort
decl_stmt|;
block|}
name|EFI_TCP4_SERVICE_POINT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP4_VARIABLE_DATA is deprecated in the UEFI 2.4B and should not be used any more.
end_comment

begin_comment
comment|/// The definition in here is only present to provide backwards compatability.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_HANDLE
name|DriverHandle
decl_stmt|;
name|UINT32
name|ServiceCount
decl_stmt|;
name|EFI_TCP4_SERVICE_POINT
name|Services
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_TCP4_VARIABLE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BOOLEAN
name|UseDefaultAddress
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|StationAddress
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
name|UINT16
name|StationPort
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|RemoteAddress
decl_stmt|;
name|UINT16
name|RemotePort
decl_stmt|;
name|BOOLEAN
name|ActiveFlag
decl_stmt|;
block|}
name|EFI_TCP4_ACCESS_POINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ReceiveBufferSize
decl_stmt|;
name|UINT32
name|SendBufferSize
decl_stmt|;
name|UINT32
name|MaxSynBackLog
decl_stmt|;
name|UINT32
name|ConnectionTimeout
decl_stmt|;
name|UINT32
name|DataRetries
decl_stmt|;
name|UINT32
name|FinTimeout
decl_stmt|;
name|UINT32
name|TimeWaitTimeout
decl_stmt|;
name|UINT32
name|KeepAliveProbes
decl_stmt|;
name|UINT32
name|KeepAliveTime
decl_stmt|;
name|UINT32
name|KeepAliveInterval
decl_stmt|;
name|BOOLEAN
name|EnableNagle
decl_stmt|;
name|BOOLEAN
name|EnableTimeStamp
decl_stmt|;
name|BOOLEAN
name|EnableWindowScaling
decl_stmt|;
name|BOOLEAN
name|EnableSelectiveAck
decl_stmt|;
name|BOOLEAN
name|EnablePathMtuDiscovery
decl_stmt|;
block|}
name|EFI_TCP4_OPTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// I/O parameters
comment|//
name|UINT8
name|TypeOfService
decl_stmt|;
name|UINT8
name|TimeToLive
decl_stmt|;
comment|//
comment|// Access Point
comment|//
name|EFI_TCP4_ACCESS_POINT
name|AccessPoint
decl_stmt|;
comment|//
comment|// TCP Control Options
comment|//
name|EFI_TCP4_OPTION
modifier|*
name|ControlOption
decl_stmt|;
block|}
name|EFI_TCP4_CONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// TCP4 connnection state
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Tcp4StateClosed
init|=
literal|0
block|,
name|Tcp4StateListen
init|=
literal|1
block|,
name|Tcp4StateSynSent
init|=
literal|2
block|,
name|Tcp4StateSynReceived
init|=
literal|3
block|,
name|Tcp4StateEstablished
init|=
literal|4
block|,
name|Tcp4StateFinWait1
init|=
literal|5
block|,
name|Tcp4StateFinWait2
init|=
literal|6
block|,
name|Tcp4StateClosing
init|=
literal|7
block|,
name|Tcp4StateTimeWait
init|=
literal|8
block|,
name|Tcp4StateCloseWait
init|=
literal|9
block|,
name|Tcp4StateLastAck
init|=
literal|10
block|}
name|EFI_TCP4_CONNECTION_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_EVENT
name|Event
decl_stmt|;
name|EFI_STATUS
name|Status
decl_stmt|;
block|}
name|EFI_TCP4_COMPLETION_TOKEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The Status in the CompletionToken will be set to one of
comment|/// the following values if the active open succeeds or an unexpected
comment|/// error happens:
comment|/// EFI_SUCCESS:              The active open succeeds and the instance's
comment|///                           state is Tcp4StateEstablished.
comment|/// EFI_CONNECTION_RESET:     The connect fails because the connection is reset
comment|///                           either by instance itself or the communication peer.
comment|/// EFI_CONNECTION_REFUSED:   The connect fails because this connection is initiated with
comment|///                           an active open and the connection is refused.
comment|/// EFI_ABORTED:              The active open is aborted.
comment|/// EFI_TIMEOUT:              The connection establishment timer expires and
comment|///                           no more specific information is available.
comment|/// EFI_NETWORK_UNREACHABLE:  The active open fails because
comment|///                           an ICMP network unreachable error is received.
comment|/// EFI_HOST_UNREACHABLE:     The active open fails because an
comment|///                           ICMP host unreachable error is received.
comment|/// EFI_PROTOCOL_UNREACHABLE: The active open fails
comment|///                           because an ICMP protocol unreachable error is received.
comment|/// EFI_PORT_UNREACHABLE:     The connection establishment
comment|///                           timer times out and an ICMP port unreachable error is received.
comment|/// EFI_ICMP_ERROR:           The connection establishment timer timeout and some other ICMP
comment|///                           error is received.
comment|/// EFI_DEVICE_ERROR:         An unexpected system or network error occurred.
comment|/// EFI_NO_MEDIA:             There was a media error.
comment|///
name|EFI_TCP4_COMPLETION_TOKEN
name|CompletionToken
decl_stmt|;
block|}
name|EFI_TCP4_CONNECTION_TOKEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_TCP4_COMPLETION_TOKEN
name|CompletionToken
decl_stmt|;
name|EFI_HANDLE
name|NewChildHandle
decl_stmt|;
block|}
name|EFI_TCP4_LISTEN_TOKEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|FragmentLength
decl_stmt|;
name|VOID
modifier|*
name|FragmentBuffer
decl_stmt|;
block|}
name|EFI_TCP4_FRAGMENT_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BOOLEAN
name|UrgentFlag
decl_stmt|;
name|UINT32
name|DataLength
decl_stmt|;
name|UINT32
name|FragmentCount
decl_stmt|;
name|EFI_TCP4_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_TCP4_RECEIVE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BOOLEAN
name|Push
decl_stmt|;
name|BOOLEAN
name|Urgent
decl_stmt|;
name|UINT32
name|DataLength
decl_stmt|;
name|UINT32
name|FragmentCount
decl_stmt|;
name|EFI_TCP4_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_TCP4_TRANSMIT_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// When transmission finishes or meets any unexpected error it will
comment|/// be set to one of the following values:
comment|/// EFI_SUCCESS:              The receiving or transmission operation
comment|///                           completes successfully.
comment|/// EFI_CONNECTION_FIN:       The receiving operation fails because the communication peer
comment|///                           has closed the connection and there is no more data in the
comment|///                           receive buffer of the instance.
comment|/// EFI_CONNECTION_RESET:     The receiving or transmission operation fails
comment|///                           because this connection is reset either by instance
comment|///                           itself or the communication peer.
comment|/// EFI_ABORTED:              The receiving or transmission is aborted.
comment|/// EFI_TIMEOUT:              The transmission timer expires and no more
comment|///                           specific information is available.
comment|/// EFI_NETWORK_UNREACHABLE:  The transmission fails
comment|///                           because an ICMP network unreachable error is received.
comment|/// EFI_HOST_UNREACHABLE:     The transmission fails because an
comment|///                           ICMP host unreachable error is received.
comment|/// EFI_PROTOCOL_UNREACHABLE: The transmission fails
comment|///                           because an ICMP protocol unreachable error is received.
comment|/// EFI_PORT_UNREACHABLE:     The transmission fails and an
comment|///                           ICMP port unreachable error is received.
comment|/// EFI_ICMP_ERROR:           The transmission fails and some other
comment|///                           ICMP error is received.
comment|/// EFI_DEVICE_ERROR:         An unexpected system or network error occurs.
comment|/// EFI_NO_MEDIA:             There was a media error.
comment|///
name|EFI_TCP4_COMPLETION_TOKEN
name|CompletionToken
decl_stmt|;
union|union
block|{
comment|///
comment|/// When this token is used for receiving, RxData is a pointer to EFI_TCP4_RECEIVE_DATA.
comment|///
name|EFI_TCP4_RECEIVE_DATA
modifier|*
name|RxData
decl_stmt|;
comment|///
comment|/// When this token is used for transmitting, TxData is a pointer to EFI_TCP4_TRANSMIT_DATA.
comment|///
name|EFI_TCP4_TRANSMIT_DATA
modifier|*
name|TxData
decl_stmt|;
block|}
name|Packet
union|;
block|}
name|EFI_TCP4_IO_TOKEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_TCP4_COMPLETION_TOKEN
name|CompletionToken
decl_stmt|;
name|BOOLEAN
name|AbortOnClose
decl_stmt|;
block|}
name|EFI_TCP4_CLOSE_TOKEN
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Interface definition for TCP4 protocol
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Get the current operational status.    @param  This           The pointer to the EFI_TCP4_PROTOCOL instance.   @param  Tcp4State      The pointer to the buffer to receive the current TCP state.   @param  Tcp4ConfigData The pointer to the buffer to receive the current TCP configuration.   @param  Ip4ModeData    The pointer to the buffer to receive the current IPv4 configuration                          data used by the TCPv4 instance.   @param  MnpConfigData  The pointer to the buffer to receive the current MNP configuration                          data used indirectly by the TCPv4 instance.   @param  SnpModeData    The pointer to the buffer to receive the current SNP configuration                          data used indirectly by the TCPv4 instance.    @retval EFI_SUCCESS           The mode data was read.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_NOT_STARTED       No configuration data is available because this instance hasn't                                  been started.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_TCP4_CONNECTION_STATE
modifier|*
name|Tcp4State
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_TCP4_CONFIG_DATA
modifier|*
name|Tcp4ConfigData
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_IP4_MODE_DATA
modifier|*
name|Ip4ModeData
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_MANAGED_NETWORK_CONFIG_DATA
modifier|*
name|MnpConfigData
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_SIMPLE_NETWORK_MODE
modifier|*
name|SnpModeData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Initialize or brutally reset the operational parameters for this EFI TCPv4 instance.    @param  This           The pointer to the EFI_TCP4_PROTOCOL instance.   @param  Tcp4ConfigData The pointer to the configure data to configure the instance.    @retval EFI_SUCCESS           The operational settings are set, changed, or reset                                 successfully.   @retval EFI_INVALID_PARAMETER Some parameter is invalid.   @retval EFI_NO_MAPPING        When using a default address, configuration (through                                 DHCP, BOOTP, RARP, etc.) is not finished yet.   @retval EFI_ACCESS_DENIED     Configuring TCP instance when it is configured without                                 calling Configure() with NULL to reset it.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred.   @retval EFI_UNSUPPORTED       One or more of the control options are not supported in                                 the implementation.   @retval EFI_OUT_OF_RESOURCES  Could not allocate enough system resources when                                 executing Configure().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP4_CONFIG_DATA
modifier|*
name|TcpConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Add or delete a route entry to the route table    @param  This           The pointer to the EFI_TCP4_PROTOCOL instance.   @param  DeleteRoute    Set it to TRUE to delete this route from the routing table. Set it to                          FALSE to add this route to the routing table.                          DestinationAddress and SubnetMask are used as the                          keywords to search route entry.   @param  SubnetAddress  The destination network.   @param  SubnetMask     The subnet mask of the destination network.   @param  GatewayAddress The gateway address for this route. It must be on the same                          subnet with the station address unless a direct route is specified.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_NOT_STARTED       The EFI TCPv4 Protocol instance has not been configured.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP,                                 RARP, etc.) is not finished yet.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - This is NULL.                                 - SubnetAddress is NULL.                                 - SubnetMask is NULL.                                 - GatewayAddress is NULL.                                 - *SubnetAddress is not NULL a valid subnet address.                                 - *SubnetMask is not a valid subnet mask.                                 - *GatewayAddress is not a valid unicast IP address or it                                 is not in the same subnet.   @retval EFI_OUT_OF_RESOURCES  Could not allocate enough resources to add the entry to the                                 routing table.   @retval EFI_NOT_FOUND         This route is not in the routing table.   @retval EFI_ACCESS_DENIED     The route is already defined in the routing table.   @retval EFI_UNSUPPORTED       The TCP driver does not support this operation.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_ROUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|DeleteRoute
parameter_list|,
name|IN
name|EFI_IPv4_ADDRESS
modifier|*
name|SubnetAddress
parameter_list|,
name|IN
name|EFI_IPv4_ADDRESS
modifier|*
name|SubnetMask
parameter_list|,
name|IN
name|EFI_IPv4_ADDRESS
modifier|*
name|GatewayAddress
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Initiate a nonblocking TCP connection request for an active TCP instance.    @param  This                  The pointer to the EFI_TCP4_PROTOCOL instance.   @param  ConnectionToken       The pointer to the connection token to return when the TCP three                                 way handshake finishes.    @retval EFI_SUCCESS           The connection request is successfully initiated and the state                                 of this TCPv4 instance has been changed to Tcp4StateSynSent.   @retval EFI_NOT_STARTED       This EFI TCPv4 Protocol instance has not been configured.   @retval EFI_ACCESS_DENIED     One or more of the following conditions are TRUE:                                 - This instance is not configured as an active one.                                 - This instance is not in Tcp4StateClosed state.   @retval EFI_INVALID_PARAMETER One or more of the following are TRUE:                                 - This is NULL.                                 - ConnectionToken is NULL.                                 - ConnectionToken->CompletionToken.Event is NULL.   @retval EFI_OUT_OF_RESOURCES  The driver can't allocate enough resource to initiate the activ eopen.   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_CONNECT
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP4_CONNECTION_TOKEN
modifier|*
name|ConnectionToken
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Listen on the passive instance to accept an incoming connection request. This is a nonblocking operation.    @param  This        The pointer to the EFI_TCP4_PROTOCOL instance.   @param  ListenToken The pointer to the listen token to return when operation finishes.    @retval EFI_SUCCESS           The listen token has been queued successfully.   @retval EFI_NOT_STARTED       This EFI TCPv4 Protocol instance has not been configured.   @retval EFI_ACCESS_DENIED     One or more of the following are TRUE:                                 - This instance is not a passive instance.                                 - This instance is not in Tcp4StateListen state.                                 - The same listen token has already existed in the listen                                 token queue of this TCP instance.   @retval EFI_INVALID_PARAMETER One or more of the following are TRUE:                                 - This is NULL.                                 - ListenToken is NULL.                                 - ListentToken->CompletionToken.Event is NULL.   @retval EFI_OUT_OF_RESOURCES  Could not allocate enough resource to finish the operation.   @retval EFI_DEVICE_ERROR      Any unexpected and not belonged to above category error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_ACCEPT
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP4_LISTEN_TOKEN
modifier|*
name|ListenToken
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Queues outgoing data into the transmit queue.    @param  This  The pointer to the EFI_TCP4_PROTOCOL instance.   @param  Token The pointer to the completion token to queue to the transmit queue.    @retval EFI_SUCCESS             The data has been queued for transmission.   @retval EFI_NOT_STARTED         This EFI TCPv4 Protocol instance has not been configured.   @retval EFI_NO_MAPPING          When using a default address, configuration (DHCP, BOOTP,                                   RARP, etc.) is not finished yet.   @retval EFI_INVALID_PARAMETER   One or more of the following are TRUE:                                   - This is NULL.                                   - Token is NULL.                                   - Token->CompletionToken.Event is NULL.                                   - Token->Packet.TxData is NULL L.                                   - Token->Packet.FragmentCount is zero.                                   - Token->Packet.DataLength is not equal to the sum of fragment lengths.   @retval EFI_ACCESS_DENIED       One or more of the following conditions is TRUE:                                   - A transmit completion token with the same Token->CompletionToken.Event                                   was already in the transmission queue.                                   - The current instance is in Tcp4StateClosed state.                                   - The current instance is a passive one and it is in                                   Tcp4StateListen state.                                   - User has called Close() to disconnect this connection.   @retval EFI_NOT_READY           The completion token could not be queued because the                                   transmit queue is full.   @retval EFI_OUT_OF_RESOURCES    Could not queue the transmit data because of resource                                   shortage.   @retval EFI_NETWORK_UNREACHABLE There is no route to the destination network or address.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_TRANSMIT
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP4_IO_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Places an asynchronous receive request into the receiving queue.    @param  This  The pointer to the EFI_TCP4_PROTOCOL instance.   @param  Token The pointer to a token that is associated with the receive data                 descriptor.    @retval EFI_SUCCESS           The receive completion token was cached.   @retval EFI_NOT_STARTED       This EFI TCPv4 Protocol instance has not been configured.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP, RARP,                                 etc.) is not finished yet.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - This is NULL.                                 - Token is NULL.                                 - Token->CompletionToken.Event is NULL.                                 - Token->Packet.RxData is NULL.                                 - Token->Packet.RxData->DataLength is 0.                                 - The Token->Packet.RxData->DataLength is not                                 the sum of all FragmentBuffer length in FragmentTable.   @retval EFI_OUT_OF_RESOURCES The receive completion token could not be queued due to a lack of                                system resources (usually memory).   @retval EFI_DEVICE_ERROR     An unexpected system or network error occurred.   @retval EFI_ACCESS_DENIED    One or more of the following conditions is TRUE:                                - A receive completion token with the same Token->CompletionToken.Event was already in the receive                                queue.                                - The current instance is in Tcp4StateClosed state.                                - The current instance is a passive one and it is in                                Tcp4StateListen state.                                - User has called Close() to disconnect this connection.   @retval EFI_CONNECTION_FIN   The communication peer has closed the connection and there is                                no any buffered data in the receive buffer of this instance.   @retval EFI_NOT_READY        The receive request could not be queued because the receive queue is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP4_IO_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Disconnecting a TCP connection gracefully or reset a TCP connection. This function is a   nonblocking operation.    @param  This       The pointer to the EFI_TCP4_PROTOCOL instance.   @param  CloseToken The pointer to the close token to return when operation finishes.    @retval EFI_SUCCESS           The Close() is called successfully.   @retval EFI_NOT_STARTED       This EFI TCPv4 Protocol instance has not been configured.   @retval EFI_ACCESS_DENIED     One or more of the following are TRUE:                                 - Configure() has been called with                                 TcpConfigData set to NULL and this function has                                 not returned.                                 - Previous Close() call on this instance has not                                 finished.   @retval EFI_INVALID_PARAMETER One or more of the following are TRUE:                                 - This is NULL.                                 - CloseToken is NULL.                                 - CloseToken->CompletionToken.Event is NULL.   @retval EFI_OUT_OF_RESOURCES  Could not allocate enough resource to finish the operation.   @retval EFI_DEVICE_ERROR      Any unexpected and not belonged to above category error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_CLOSE
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP4_CLOSE_TOKEN
modifier|*
name|CloseToken
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Abort an asynchronous connection, listen, transmission or receive request.    @param  This  The pointer to the EFI_TCP4_PROTOCOL instance.   @param  Token The pointer to a token that has been issued by                 EFI_TCP4_PROTOCOL.Connect(),                 EFI_TCP4_PROTOCOL.Accept(),                 EFI_TCP4_PROTOCOL.Transmit() or                 EFI_TCP4_PROTOCOL.Receive(). If NULL, all pending                 tokens issued by above four functions will be aborted. Type                 EFI_TCP4_COMPLETION_TOKEN is defined in                 EFI_TCP4_PROTOCOL.Connect().    @retval  EFI_SUCCESS             The asynchronous I/O request is aborted and Token->Event                                    is signaled.   @retval  EFI_INVALID_PARAMETER   This is NULL.   @retval  EFI_NOT_STARTED         This instance hasn't been configured.   @retval  EFI_NO_MAPPING          When using the default address, configuration                                    (DHCP, BOOTP,RARP, etc.) hasn't finished yet.   @retval  EFI_NOT_FOUND           The asynchronous I/O request isn't found in the                                    transmission or receive queue. It has either                                    completed or wasn't issued by Transmit() and Receive().   @retval  EFI_UNSUPPORTED         The implementation does not support this function.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_CANCEL
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP4_COMPLETION_TOKEN
modifier|*
name|Token
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Poll to receive incoming data and transmit outgoing segments.    @param  This The pointer to the EFI_TCP4_PROTOCOL instance.    @retval  EFI_SUCCESS           Incoming or outgoing data was processed.   @retval  EFI_INVALID_PARAMETER This is NULL.   @retval  EFI_DEVICE_ERROR      An unexpected system or network error occurred.   @retval  EFI_NOT_READY         No incoming or outgoing data is processed.   @retval  EFI_TIMEOUT           Data was dropped out of the transmission or receive queue.                                  Consider increasing the polling rate.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP4_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP4_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_TCP4_PROTOCOL defines the EFI TCPv4 Protocol child to be used by
end_comment

begin_comment
comment|/// any network drivers or applications to send or receive data stream.
end_comment

begin_comment
comment|/// It can either listen on a specified port as a service or actively connected
end_comment

begin_comment
comment|/// to remote peer as a client. Each instance has its own independent settings,
end_comment

begin_comment
comment|/// such as the routing table.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_TCP4_PROTOCOL
block|{
name|EFI_TCP4_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_TCP4_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_TCP4_ROUTES
name|Routes
decl_stmt|;
name|EFI_TCP4_CONNECT
name|Connect
decl_stmt|;
name|EFI_TCP4_ACCEPT
name|Accept
decl_stmt|;
name|EFI_TCP4_TRANSMIT
name|Transmit
decl_stmt|;
name|EFI_TCP4_RECEIVE
name|Receive
decl_stmt|;
name|EFI_TCP4_CLOSE
name|Close
decl_stmt|;
name|EFI_TCP4_CANCEL
name|Cancel
decl_stmt|;
name|EFI_TCP4_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTcp4ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTcp4ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

