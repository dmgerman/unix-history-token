begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UDP4 Service Binding Protocol as defined in UEFI specification.    The EFI UDPv4 Protocol provides simple packet-oriented services    to transmit and receive UDP packets.    Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.          @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.0.         **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_UDP4_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_UDP4_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Ip4.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|//GUID definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_UDP4_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x83f01464, 0x99bd, 0x45e5, {0xb3, 0x83, 0xaf, 0x63, 0x05, 0xd8, 0xe9, 0xe6 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_UDP4_PROTOCOL_GUID
define|\
value|{ \     0x3ad9df29, 0x4501, 0x478d, {0xb1, 0xf8, 0x7f, 0x7f, 0xe7, 0x0e, 0x50, 0xf3 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_UDP4_PROTOCOL
name|EFI_UDP4_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_UDP4_SERVICE_POINT is deprecated in the UEFI 2.4B and should not be used any more.
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
name|EFI_UDP4_SERVICE_POINT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_UDP4_VARIABLE_DATA is deprecated in the UEFI 2.4B and should not be used any more.
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
name|EFI_UDP4_SERVICE_POINT
name|Services
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_UDP4_VARIABLE_DATA
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
name|EFI_UDP4_FRAGMENT_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_IPv4_ADDRESS
name|SourceAddress
decl_stmt|;
name|UINT16
name|SourcePort
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|DestinationAddress
decl_stmt|;
name|UINT16
name|DestinationPort
decl_stmt|;
block|}
name|EFI_UDP4_SESSION_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Receiving Filters
comment|//
name|BOOLEAN
name|AcceptBroadcast
decl_stmt|;
name|BOOLEAN
name|AcceptPromiscuous
decl_stmt|;
name|BOOLEAN
name|AcceptAnyPort
decl_stmt|;
name|BOOLEAN
name|AllowDuplicatePort
decl_stmt|;
comment|//
comment|// I/O parameters
comment|//
name|UINT8
name|TypeOfService
decl_stmt|;
name|UINT8
name|TimeToLive
decl_stmt|;
name|BOOLEAN
name|DoNotFragment
decl_stmt|;
name|UINT32
name|ReceiveTimeout
decl_stmt|;
name|UINT32
name|TransmitTimeout
decl_stmt|;
comment|//
comment|// Access Point
comment|//
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
block|}
name|EFI_UDP4_CONFIG_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_UDP4_SESSION_DATA
modifier|*
name|UdpSessionData
decl_stmt|;
comment|//OPTIONAL
name|EFI_IPv4_ADDRESS
modifier|*
name|GatewayAddress
decl_stmt|;
comment|//OPTIONAL
name|UINT32
name|DataLength
decl_stmt|;
name|UINT32
name|FragmentCount
decl_stmt|;
name|EFI_UDP4_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_UDP4_TRANSMIT_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_TIME
name|TimeStamp
decl_stmt|;
name|EFI_EVENT
name|RecycleSignal
decl_stmt|;
name|EFI_UDP4_SESSION_DATA
name|UdpSession
decl_stmt|;
name|UINT32
name|DataLength
decl_stmt|;
name|UINT32
name|FragmentCount
decl_stmt|;
name|EFI_UDP4_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_UDP4_RECEIVE_DATA
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
union|union
block|{
name|EFI_UDP4_RECEIVE_DATA
modifier|*
name|RxData
decl_stmt|;
name|EFI_UDP4_TRANSMIT_DATA
modifier|*
name|TxData
decl_stmt|;
block|}
name|Packet
union|;
block|}
name|EFI_UDP4_COMPLETION_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Reads the current operational settings.    The GetModeData() function copies the current operational settings of this EFI   UDPv4 Protocol instance into user-supplied buffers. This function is used   optionally to retrieve the operational mode data of underlying networks or   drivers.    @param  This           The pointer to the EFI_UDP4_PROTOCOL instance.   @param  Udp4ConfigData The pointer to the buffer to receive the current configuration data.   @param  Ip4ModeData    The pointer to the EFI IPv4 Protocol mode data structure.   @param  MnpConfigData  The pointer to the managed network configuration data structure.   @param  SnpModeData    The pointer to the simple network mode data structure.    @retval EFI_SUCCESS           The mode data was read.   @retval EFI_NOT_STARTED       When Udp4ConfigData is queried, no configuration data is                                 available because this instance has not been started.   @retval EFI_INVALID_PARAMETER This is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP4_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_UDP4_CONFIG_DATA
modifier|*
name|Udp4ConfigData
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
comment|/**   Initializes, changes, or resets the operational parameters for this instance of the EFI UDPv4   Protocol.      The Configure() function is used to do the following:   * Initialize and start this instance of the EFI UDPv4 Protocol.   * Change the filtering rules and operational parameters.   * Reset this instance of the EFI UDPv4 Protocol.   Until these parameters are initialized, no network traffic can be sent or   received by this instance. This instance can be also reset by calling Configure()   with UdpConfigData set to NULL. Once reset, the receiving queue and transmitting   queue are flushed and no traffic is allowed through this instance.   With different parameters in UdpConfigData, Configure() can be used to bind   this instance to specified port.    @param  This           The pointer to the EFI_UDP4_PROTOCOL instance.   @param  Udp4ConfigData The pointer to the buffer to receive the current configuration data.    @retval EFI_SUCCESS           The configuration settings were set, changed, or reset successfully.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP,                                 RARP, etc.) is not finished yet.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_INVALID_PARAMETER UdpConfigData.StationAddress is not a valid unicast IPv4 address.   @retval EFI_INVALID_PARAMETER UdpConfigData.SubnetMask is not a valid IPv4 address mask. The subnet                                 mask must be contiguous.   @retval EFI_INVALID_PARAMETER UdpConfigData.RemoteAddress is not a valid unicast IPv4 address if it                                 is not zero.   @retval EFI_ALREADY_STARTED   The EFI UDPv4 Protocol instance is already started/configured                                 and must be stopped/reset before it can be reconfigured.   @retval EFI_ACCESS_DENIED     UdpConfigData. AllowDuplicatePort is FALSE                                 and UdpConfigData.StationPort is already used by                                 other instance.   @retval EFI_OUT_OF_RESOURCES  The EFI UDPv4 Protocol driver cannot allocate memory for this                                 EFI UDPv4 Protocol instance.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred and this instance                                  was not opened.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP4_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_UDP4_CONFIG_DATA
modifier|*
name|UdpConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Joins and leaves multicast groups.      The Groups() function is used to enable and disable the multicast group   filtering. If the JoinFlag is FALSE and the MulticastAddress is NULL, then all   currently joined groups are left.    @param  This             The pointer to the EFI_UDP4_PROTOCOL instance.   @param  JoinFlag         Set to TRUE to join a multicast group. Set to FALSE to leave one                            or all multicast groups.   @param  MulticastAddress The pointer to multicast group address to join or leave.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_NOT_STARTED       The EFI UDPv4 Protocol instance has not been started.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP,                                 RARP, etc.) is not finished yet.   @retval EFI_OUT_OF_RESOURCES  Could not allocate resources to join the group.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - This is NULL.                                 - JoinFlag is TRUE and MulticastAddress is NULL.                                 - JoinFlag is TRUE and *MulticastAddress is not                                   a valid multicast address.   @retval EFI_ALREADY_STARTED   The group address is already in the group table (when                                 JoinFlag is TRUE).   @retval EFI_NOT_FOUND         The group address is not in the group table (when JoinFlag is                                 FALSE).   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP4_GROUPS
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|JoinFlag
parameter_list|,
name|IN
name|EFI_IPv4_ADDRESS
modifier|*
name|MulticastAddress
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Adds and deletes routing table entries.      The Routes() function adds a route to or deletes a route from the routing table.   Routes are determined by comparing the SubnetAddress with the destination IP   address and arithmetically AND-ing it with the SubnetMask. The gateway address   must be on the same subnet as the configured station address.   The default route is added with SubnetAddress and SubnetMask both set to 0.0.0.0.   The default route matches all destination IP addresses that do not match any   other routes.   A zero GatewayAddress is a nonroute. Packets are sent to the destination IP   address if it can be found in the Address Resolution Protocol (ARP) cache or   on the local subnet. One automatic nonroute entry will be inserted into the   routing table for outgoing packets that are addressed to a local subnet   (gateway address of 0.0.0.0).   Each instance of the EFI UDPv4 Protocol has its own independent routing table.   Instances of the EFI UDPv4 Protocol that use the default IP address will also   have copies of the routing table provided by the EFI_IP4_CONFIG_PROTOCOL. These   copies will be updated automatically whenever the IP driver reconfigures its   instances; as a result, the previous modification to these copies will be lost.    @param  This           The pointer to the EFI_UDP4_PROTOCOL instance.   @param  DeleteRoute    Set to TRUE to delete this route from the routing table.                          Set to FALSE to add this route to the routing table.   @param  SubnetAddress  The destination network address that needs to be routed.   @param  SubnetMask     The subnet mask of SubnetAddress.   @param  GatewayAddress The gateway IP address for this route.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_NOT_STARTED       The EFI UDPv4 Protocol instance has not been started.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP,                                 - RARP, etc.) is not finished yet.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  Could not add the entry to the routing table.   @retval EFI_NOT_FOUND         This route is not in the routing table.   @retval EFI_ACCESS_DENIED     The route is already defined in the routing table.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP4_ROUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP4_PROTOCOL
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
comment|/**   Polls for incoming data packets and processes outgoing data packets.      The Poll() function can be used by network drivers and applications to increase   the rate that data packets are moved between the communications device and the   transmit and receive queues.   In some systems, the periodic timer event in the managed network driver may not   poll the underlying communications device fast enough to transmit and/or receive   all data packets without missing incoming packets or dropping outgoing packets.   Drivers and applications that are experiencing packet loss should try calling   the Poll() function more often.    @param  This The pointer to the EFI_UDP4_PROTOCOL instance.    @retval EFI_SUCCESS           Incoming or outgoing data was processed.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.   @retval EFI_TIMEOUT           Data was dropped out of the transmit and/or receive queue.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP4_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP4_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Places an asynchronous receive request into the receiving queue.      The Receive() function places a completion token into the receive packet queue.   This function is always asynchronous.   The caller must fill in the Token.Event field in the completion token, and this   field cannot be NULL. When the receive operation completes, the EFI UDPv4 Protocol   driver updates the Token.Status and Token.Packet.RxData fields and the Token.Event   is signaled. Providing a proper notification function and context for the event   will enable the user to receive the notification and receiving status. That   notification function is guaranteed to not be re-entered.    @param  This  The pointer to the EFI_UDP4_PROTOCOL instance.   @param  Token The pointer to a token that is associated with the receive data                 descriptor.    @retval EFI_SUCCESS           The receive completion token was cached.   @retval EFI_NOT_STARTED       This EFI UDPv4 Protocol instance has not been started.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP, RARP, etc.)                                 is not finished yet.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_INVALID_PARAMETER Token is NULL.   @retval EFI_INVALID_PARAMETER Token.Event is NULL.   @retval EFI_OUT_OF_RESOURCES  The receive completion token could not be queued due to a lack of system                                 resources (usually memory).   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.   @retval EFI_ACCESS_DENIED     A receive completion token with the same Token.Event was already in                                 the receive queue.   @retval EFI_NOT_READY         The receive request could not be queued because the receive queue is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP4_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_UDP4_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Queues outgoing data packets into the transmit queue.      The Transmit() function places a sending request to this instance of the EFI   UDPv4 Protocol, alongside the transmit data that was filled by the user. Whenever   the packet in the token is sent out or some errors occur, the Token.Event will   be signaled and Token.Status is updated. Providing a proper notification function   and context for the event will enable the user to receive the notification and   transmitting status.    @param  This  The pointer to the EFI_UDP4_PROTOCOL instance.   @param  Token The pointer to the completion token that will be placed into the                 transmit queue.    @retval EFI_SUCCESS           The data has been queued for transmission.   @retval EFI_NOT_STARTED       This EFI UDPv4 Protocol instance has not been started.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP,                                 RARP, etc.) is not finished yet.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_ACCESS_DENIED     The transmit completion token with the same                                 Token.Event was already in the transmit queue.   @retval EFI_NOT_READY         The completion token could not be queued because the                                 transmit queue is full.   @retval EFI_OUT_OF_RESOURCES  Could not queue the transmit data.   @retval EFI_NOT_FOUND         There is no route to the destination network or address.   @retval EFI_BAD_BUFFER_SIZE   The data length is greater than the maximum UDP packet                                 size. Or the length of the IP header + UDP header + data                                 length is greater than MTU if DoNotFragment is TRUE.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP4_TRANSMIT
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_UDP4_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Aborts an asynchronous transmit or receive request.      The Cancel() function is used to abort a pending transmit or receive request.   If the token is in the transmit or receive request queues, after calling this   function, Token.Status will be set to EFI_ABORTED and then Token.Event will be   signaled. If the token is not in one of the queues, which usually means that   the asynchronous operation has completed, this function will not signal the   token and EFI_NOT_FOUND is returned.    @param  This  The pointer to the EFI_UDP4_PROTOCOL instance.   @param  Token The pointer to a token that has been issued by                 EFI_UDP4_PROTOCOL.Transmit() or                 EFI_UDP4_PROTOCOL.Receive().If NULL, all pending                 tokens are aborted.    @retval  EFI_SUCCESS           The asynchronous I/O request was aborted and Token.Event                                  was signaled. When Token is NULL, all pending requests are                                  aborted and their events are signaled.   @retval  EFI_INVALID_PARAMETER This is NULL.   @retval  EFI_NOT_STARTED       This instance has not been started.   @retval  EFI_NO_MAPPING        When using the default address, configuration (DHCP, BOOTP,                                  RARP, etc.) is not finished yet.   @retval  EFI_NOT_FOUND         When Token is not NULL, the asynchronous I/O request was                                  not found in the transmit or receive queue. It has either completed                                  or was not issued by Transmit() and Receive().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP4_CANCEL
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_UDP4_COMPLETION_TOKEN
modifier|*
name|Token
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_UDP4_PROTOCOL defines an EFI UDPv4 Protocol session that can be used
end_comment

begin_comment
comment|/// by any network drivers, applications, or daemons to transmit or receive UDP packets.
end_comment

begin_comment
comment|/// This protocol instance can either be bound to a specified port as a service or
end_comment

begin_comment
comment|/// connected to some remote peer as an active client. Each instance has its own settings,
end_comment

begin_comment
comment|/// such as the routing table and group table, which are independent from each other.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_UDP4_PROTOCOL
block|{
name|EFI_UDP4_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_UDP4_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_UDP4_GROUPS
name|Groups
decl_stmt|;
name|EFI_UDP4_ROUTES
name|Routes
decl_stmt|;
name|EFI_UDP4_TRANSMIT
name|Transmit
decl_stmt|;
name|EFI_UDP4_RECEIVE
name|Receive
decl_stmt|;
name|EFI_UDP4_CANCEL
name|Cancel
decl_stmt|;
name|EFI_UDP4_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUdp4ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUdp4ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

