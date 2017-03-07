begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The EFI UDPv6 (User Datagram Protocol version 6) Protocol Definition, which is built upon   the EFI IPv6 Protocol and provides simple packet-oriented services to transmit and receive   UDP packets.    Copyright (c) 2008 - 2014, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                                                                                                            THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.     @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_UDP6_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_UDP6_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Ip6.h>
end_include

begin_define
define|#
directive|define
name|EFI_UDP6_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x66ed4721, 0x3c98, 0x4d3e, {0x81, 0xe3, 0xd0, 0x3d, 0xd3, 0x9a, 0x72, 0x54 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_UDP6_PROTOCOL_GUID
define|\
value|{ \     0x4f948815, 0xb4b9, 0x43cb, {0x8a, 0x33, 0x90, 0xe0, 0x60, 0xb3, 0x49, 0x55 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_UDP6_SERVICE_POINT is deprecated in the UEFI 2.4B and should not be used any more.
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
comment|///
comment|/// The EFI UDPv6 Protocol instance handle that is using this address/port pair.
comment|///
name|EFI_HANDLE
name|InstanceHandle
decl_stmt|;
comment|///
comment|/// The IPv6 address to which this instance of the EFI UDPv6 Protocol is bound.
comment|/// Set to 0::/128, if this instance is used to listen all packets from any
comment|/// source address.
comment|///
name|EFI_IPv6_ADDRESS
name|LocalAddress
decl_stmt|;
comment|///
comment|/// The port number in host byte order on which the service is listening.
comment|///
name|UINT16
name|LocalPort
decl_stmt|;
comment|///
comment|/// The IPv6 address of the remote host. May be 0::/128 if it is not connected
comment|/// to any remote host or connected with more than one remote host.
comment|///
name|EFI_IPv6_ADDRESS
name|RemoteAddress
decl_stmt|;
comment|///
comment|/// The port number in host byte order on which the remote host is
comment|/// listening. Maybe zero if it is not connected to any remote host.
comment|///
name|UINT16
name|RemotePort
decl_stmt|;
block|}
name|EFI_UDP6_SERVICE_POINT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_UDP6_VARIABLE_DATA is deprecated in the UEFI 2.4B and should not be used any more.
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
comment|///
comment|/// The handle of the driver that creates this entry.
comment|///
name|EFI_HANDLE
name|DriverHandle
decl_stmt|;
comment|///
comment|/// The number of address/port pairs that follow this data structure.
comment|///
name|UINT32
name|ServiceCount
decl_stmt|;
comment|///
comment|/// List of address/port pairs that are currently in use.
comment|///
name|EFI_UDP6_SERVICE_POINT
name|Services
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_UDP6_VARIABLE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_UDP6_PROTOCOL
name|EFI_UDP6_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_UDP6_FRAGMENT_DATA allows multiple receive or transmit buffers to be specified.
end_comment

begin_comment
comment|/// The purpose of this structure is to avoid copying the same packet multiple times.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|FragmentLength
decl_stmt|;
comment|///< Length of the fragment data buffer.
name|VOID
modifier|*
name|FragmentBuffer
decl_stmt|;
comment|///< Pointer to the fragment data buffer.
block|}
name|EFI_UDP6_FRAGMENT_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_UDP6_SESSION_DATA is used to retrieve the settings when receiving packets or
end_comment

begin_comment
comment|/// to override the existing settings (only DestinationAddress and DestinationPort can
end_comment

begin_comment
comment|/// be overridden) of this EFI UDPv6 Protocol instance when sending packets.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Address from which this packet is sent. This field should not be used when
comment|/// sending packets.
comment|///
name|EFI_IPv6_ADDRESS
name|SourceAddress
decl_stmt|;
comment|///
comment|/// Port from which this packet is sent. It is in host byte order. This field should
comment|/// not be used when sending packets.
comment|///
name|UINT16
name|SourcePort
decl_stmt|;
comment|///
comment|/// Address to which this packet is sent. When sending packet, it'll be ignored
comment|/// if it is zero.
comment|///
name|EFI_IPv6_ADDRESS
name|DestinationAddress
decl_stmt|;
comment|///
comment|/// Port to which this packet is sent. When sending packet, it'll be
comment|/// ignored if it is zero.
comment|///
name|UINT16
name|DestinationPort
decl_stmt|;
block|}
name|EFI_UDP6_SESSION_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Set to TRUE to accept UDP packets that are sent to any address.
comment|///
name|BOOLEAN
name|AcceptPromiscuous
decl_stmt|;
comment|///
comment|/// Set to TRUE to accept UDP packets that are sent to any port.
comment|///
name|BOOLEAN
name|AcceptAnyPort
decl_stmt|;
comment|///
comment|/// Set to TRUE to allow this EFI UDPv6 Protocol child instance to open a port number
comment|/// that is already being used by another EFI UDPv6 Protocol child instance.
comment|///
name|BOOLEAN
name|AllowDuplicatePort
decl_stmt|;
comment|///
comment|/// TrafficClass field in transmitted IPv6 packets.
comment|///
name|UINT8
name|TrafficClass
decl_stmt|;
comment|///
comment|/// HopLimit field in transmitted IPv6 packets.
comment|///
name|UINT8
name|HopLimit
decl_stmt|;
comment|///
comment|/// The receive timeout value (number of microseconds) to be associated with each
comment|/// incoming packet. Zero means do not drop incoming packets.
comment|///
name|UINT32
name|ReceiveTimeout
decl_stmt|;
comment|///
comment|/// The transmit timeout value (number of microseconds) to be associated with each
comment|/// outgoing packet. Zero means do not drop outgoing packets.
comment|///
name|UINT32
name|TransmitTimeout
decl_stmt|;
comment|///
comment|/// The station IP address that will be assigned to this EFI UDPv6 Protocol instance.
comment|/// The EFI UDPv6 and EFI IPv6 Protocol drivers will only deliver incoming packets
comment|/// whose destination matches this IP address exactly. Address 0::/128 is also accepted
comment|/// as a special case. Under this situation, underlying IPv6 driver is responsible for
comment|/// binding a source address to this EFI IPv6 protocol instance according to source
comment|/// address selection algorithm. Only incoming packet from the selected source address
comment|/// is delivered. This field can be set and changed only when the EFI IPv6 driver is
comment|/// transitioning from the stopped to the started states. If no address is available
comment|/// for selecting, the EFI IPv6 Protocol driver will use EFI_IP6_CONFIG_PROTOCOL to
comment|/// retrieve the IPv6 address.
name|EFI_IPv6_ADDRESS
name|StationAddress
decl_stmt|;
comment|///
comment|/// The port number to which this EFI UDPv6 Protocol instance is bound. If a client
comment|/// of the EFI UDPv6 Protocol does not care about the port number, set StationPort
comment|/// to zero. The EFI UDPv6 Protocol driver will assign a random port number to transmitted
comment|/// UDP packets. Ignored it if AcceptAnyPort is TRUE.
comment|///
name|UINT16
name|StationPort
decl_stmt|;
comment|///
comment|/// The IP address of remote host to which this EFI UDPv6 Protocol instance is connecting.
comment|/// If RemoteAddress is not 0::/128, this EFI UDPv6 Protocol instance will be connected to
comment|/// RemoteAddress; i.e., outgoing packets of this EFI UDPv6 Protocol instance will be sent
comment|/// to this address by default and only incoming packets from this address will be delivered
comment|/// to client. Ignored for incoming filtering if AcceptPromiscuous is TRUE.
name|EFI_IPv6_ADDRESS
name|RemoteAddress
decl_stmt|;
comment|///
comment|/// The port number of the remote host to which this EFI UDPv6 Protocol instance is connecting.
comment|/// If it is not zero, outgoing packets of this EFI UDPv6 Protocol instance will be sent to
comment|/// this port number by default and only incoming packets from this port will be delivered
comment|/// to client. Ignored if RemoteAddress is 0::/128 and ignored for incoming filtering if
comment|/// AcceptPromiscuous is TRUE.
name|UINT16
name|RemotePort
decl_stmt|;
block|}
name|EFI_UDP6_CONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI UDPv6 Protocol client must fill this data structure before sending a packet.
end_comment

begin_comment
comment|/// The packet may contain multiple buffers that may be not in a continuous memory location.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// If not NULL, the data that is used to override the transmitting settings.Only the two
comment|/// filed UdpSessionData.DestinationAddress and UdpSessionData.DestionPort can be used as
comment|/// the transmitting setting filed.
comment|///
name|EFI_UDP6_SESSION_DATA
modifier|*
name|UdpSessionData
decl_stmt|;
comment|///
comment|/// Sum of the fragment data length. Must not exceed the maximum UDP packet size.
comment|///
name|UINT32
name|DataLength
decl_stmt|;
comment|///
comment|/// Number of fragments.
comment|///
name|UINT32
name|FragmentCount
decl_stmt|;
comment|///
comment|/// Array of fragment descriptors.
comment|///
name|EFI_UDP6_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_UDP6_TRANSMIT_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_UDP6_RECEIVE_DATA is filled by the EFI UDPv6 Protocol driver when this EFI UDPv6
end_comment

begin_comment
comment|/// Protocol instance receives an incoming packet. If there is a waiting token for incoming
end_comment

begin_comment
comment|/// packets, the CompletionToken.Packet.RxData field is updated to this incoming packet and
end_comment

begin_comment
comment|/// the CompletionToken.Event is signaled. The EFI UDPv6 Protocol client must signal the
end_comment

begin_comment
comment|/// RecycleSignal after processing the packet.
end_comment

begin_comment
comment|/// FragmentTable could contain multiple buffers that are not in the continuous memory locations.
end_comment

begin_comment
comment|/// The EFI UDPv6 Protocol client might need to combine two or more buffers in FragmentTable to
end_comment

begin_comment
comment|/// form their own protocol header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Time when the EFI UDPv6 Protocol accepted the packet.
comment|///
name|EFI_TIME
name|TimeStamp
decl_stmt|;
comment|///
comment|/// Indicates the event to signal when the received data has been processed.
comment|///
name|EFI_EVENT
name|RecycleSignal
decl_stmt|;
comment|///
comment|/// The UDP session data including SourceAddress, SourcePort, DestinationAddress,
comment|/// and DestinationPort.
comment|///
name|EFI_UDP6_SESSION_DATA
name|UdpSession
decl_stmt|;
comment|///
comment|/// The sum of the fragment data length.
comment|///
name|UINT32
name|DataLength
decl_stmt|;
comment|///
comment|/// Number of fragments. Maybe zero.
comment|///
name|UINT32
name|FragmentCount
decl_stmt|;
comment|///
comment|/// Array of fragment descriptors. Maybe zero.
comment|///
name|EFI_UDP6_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_UDP6_RECEIVE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_UDP6_COMPLETION_TOKEN structures are used for both transmit and receive operations.
end_comment

begin_comment
comment|/// When used for transmitting, the Event and TxData fields must be filled in by the EFI UDPv6
end_comment

begin_comment
comment|/// Protocol client. After the transmit operation completes, the Status field is updated by the
end_comment

begin_comment
comment|/// EFI UDPv6 Protocol and the Event is signaled.
end_comment

begin_comment
comment|/// When used for receiving, only the Event field must be filled in by the EFI UDPv6 Protocol
end_comment

begin_comment
comment|/// client. After a packet is received, RxData and Status are filled in by the EFI UDPv6 Protocol
end_comment

begin_comment
comment|/// and the Event is signaled.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated by the EFI UDPv6 Protocol
comment|/// driver. The type of Event must be EVT_NOTIFY_SIGNAL.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Will be set to one of the following values:
comment|///   - EFI_SUCCESS: The receive or transmit operation completed successfully.
comment|///   - EFI_ABORTED: The receive or transmit was aborted.
comment|///   - EFI_TIMEOUT: The transmit timeout expired.
comment|///   - EFI_NETWORK_UNREACHABLE: The destination network is unreachable. RxData is set to
comment|///     NULL in this situation.
comment|///   - EFI_HOST_UNREACHABLE: The destination host is unreachable. RxData is set to NULL in
comment|///     this situation.
comment|///   - EFI_PROTOCOL_UNREACHABLE: The UDP protocol is unsupported in the remote system.
comment|///     RxData is set to NULL in this situation.
comment|///   - EFI_PORT_UNREACHABLE: No service is listening on the remote port. RxData is set to
comment|///     NULL in this situation.
comment|///   - EFI_ICMP_ERROR: Some other Internet Control Message Protocol (ICMP) error report was
comment|///     received. For example, packets are being sent too fast for the destination to receive them
comment|///     and the destination sent an ICMP source quench report. RxData is set to NULL in this situation.
comment|///   - EFI_DEVICE_ERROR: An unexpected system or network error occurred.
comment|///   - EFI_SECURITY_VIOLATION: The transmit or receive was failed because of IPsec policy check.
comment|///   - EFI_NO_MEDIA: There was a media error.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
union|union
block|{
comment|///
comment|/// When this token is used for receiving, RxData is a pointer to EFI_UDP6_RECEIVE_DATA.
comment|///
name|EFI_UDP6_RECEIVE_DATA
modifier|*
name|RxData
decl_stmt|;
comment|///
comment|/// When this token is used for transmitting, TxData is a pointer to EFI_UDP6_TRANSMIT_DATA.
comment|///
name|EFI_UDP6_TRANSMIT_DATA
modifier|*
name|TxData
decl_stmt|;
block|}
name|Packet
union|;
block|}
name|EFI_UDP6_COMPLETION_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Read the current operational settings.    The GetModeData() function copies the current operational settings of this EFI UDPv6 Protocol   instance into user-supplied buffers. This function is used optionally to retrieve the operational   mode data of underlying networks or drivers.     @param[in]   This             Pointer to the EFI_UDP6_PROTOCOL instance.   @param[out]  Udp6ConfigData   The buffer in which the current UDP configuration data is returned.   @param[out]  Ip6ModeData      The buffer in which the current EFI IPv6 Protocol mode data is returned.   @param[out]  MnpConfigData    The buffer in which the current managed network configuration data is                                 returned.   @param[out]  SnpModeData      The buffer in which the simple network mode data is returned.    @retval EFI_SUCCESS           The mode data was read.   @retval EFI_NOT_STARTED       When Udp6ConfigData is queried, no configuration data is available                                 because this instance has not been started.   @retval EFI_INVALID_PARAMETER This is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP6_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_UDP6_CONFIG_DATA
modifier|*
name|Udp6ConfigData
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_IP6_MODE_DATA
modifier|*
name|Ip6ModeData
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
comment|/**   Initializes, changes, or resets the operational parameters for this instance of the EFI UDPv6    Protocol.    The Configure() function is used to do the following:   - Initialize and start this instance of the EFI UDPv6 Protocol.   - Change the filtering rules and operational parameters.   - Reset this instance of the EFI UDPv6 Protocol.     Until these parameters are initialized, no network traffic can be sent or received by this instance.   This instance can be also reset by calling Configure() with UdpConfigData set to NULL.   Once reset, the receiving queue and transmitting queue are flushed and no traffic is allowed through   this instance.    With different parameters in UdpConfigData, Configure() can be used to bind this instance to specified   port.    @param[in]   This             Pointer to the EFI_UDP6_PROTOCOL instance.   @param[in]   UdpConfigData    Pointer to the buffer contained the configuration data.    @retval EFI_SUCCESS           The configuration settings were set, changed, or reset successfully.   @retval EFI_NO_MAPPING        The underlying IPv6 driver was responsible for choosing a source                                  address for this instance, but no source address was available for use.   @retval EFI_INVALID_PARAMETER One or more following conditions are TRUE:                                 - This is NULL.                                 - UdpConfigData.StationAddress neither zero nor one of the configured IP                                   addresses in the underlying IPv6 driver.                                 - UdpConfigData.RemoteAddress is not a valid unicast IPv6 address if it                                   is not zero.   @retval EFI_ALREADY_STARTED   The EFI UDPv6 Protocol instance is already started/configured and must be                                 stopped/reset before it can be reconfigured. Only TrafficClass, HopLimit,                                 ReceiveTimeout, and TransmitTimeout can be reconfigured without stopping                                 the current instance of the EFI UDPv6 Protocol.   @retval EFI_ACCESS_DENIED     UdpConfigData.AllowDuplicatePort is FALSE and UdpConfigData.StationPort                                 is already used by other instance.    @retval EFI_OUT_OF_RESOURCES  The EFI UDPv6 Protocol driver cannot allocate memory for this EFI UDPv6                                 Protocol instance.   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred and this instance was not                                 opened.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP6_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_UDP6_CONFIG_DATA
modifier|*
name|UdpConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Joins and leaves multicast groups.    The Groups() function is used to join or leave one or more multicast group.   If the JoinFlag is FALSE and the MulticastAddress is NULL, then all currently joined groups are left.    @param[in]   This             Pointer to the EFI_UDP6_PROTOCOL instance.   @param[in]   JoinFlag         Set to TRUE to join a multicast group. Set to FALSE to leave one                                 or all multicast groups.   @param[in]   MulticastAddress Pointer to multicast group address to join or leave.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_NOT_STARTED       The EFI UDPv6 Protocol instance has not been started.   @retval EFI_OUT_OF_RESOURCES  Could not allocate resources to join the group.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - This is NULL.                                 - JoinFlag is TRUE and MulticastAddress is NULL.                                 - JoinFlag is TRUE and *MulticastAddress is not a valid multicast address.   @retval EFI_ALREADY_STARTED   The group address is already in the group table (when JoinFlag is TRUE).   @retval EFI_NOT_FOUND         The group address is not in the group table (when JoinFlag is FALSE).   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP6_GROUPS
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|JoinFlag
parameter_list|,
name|IN
name|EFI_IPv6_ADDRESS
modifier|*
name|MulticastAddress
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Queues outgoing data packets into the transmit queue.    The Transmit() function places a sending request to this instance of the EFI UDPv6 Protocol,   alongside the transmit data that was filled by the user. Whenever the packet in the token is   sent out or some errors occur, the Token.Event will be signaled and Token.Status is updated.   Providing a proper notification function and context for the event will enable the user to   receive the notification and transmitting status.    @param[in]   This             Pointer to the EFI_UDP6_PROTOCOL instance.   @param[in]   Token            Pointer to the completion token that will be placed into the                                  transmit queue.    @retval EFI_SUCCESS           The data has been queued for transmission.   @retval EFI_NOT_STARTED       This EFI UDPv6 Protocol instance has not been started.   @retval EFI_NO_MAPPING        The underlying IPv6 driver was responsible for choosing a source                                 address for this instance, but no source address was available                                 for use.   @retval EFI_INVALID_PARAMETER One or more of the following are TRUE:                                 - This is NULL.                                 - Token is NULL.                                 - Token.Event is NULL.                                 - Token.Packet.TxData is NULL.                                 - Token.Packet.TxData.FragmentCount is zero.                                 - Token.Packet.TxData.DataLength is not equal to the sum of fragment                                   lengths.                                 - One or more of the Token.Packet.TxData.FragmentTable[].FragmentLength                                   fields is zero.                                 - One or more of the Token.Packet.TxData.FragmentTable[].FragmentBuffer                                   fields is NULL.                                 - Token.Packet.TxData.UdpSessionData.DestinationAddress is not zero                                   and is not valid unicast Ipv6 address if UdpSessionData is not NULL.                                 - Token.Packet.TxData.UdpSessionData is NULL and this instance's                                    UdpConfigData.RemoteAddress is unspecified.                                 - Token.Packet.TxData.UdpSessionData.DestinationAddress is non-zero                                   when DestinationAddress is configured as non-zero when doing Configure()                                   for this EFI Udp6 protocol instance.                                 - Token.Packet.TxData.UdpSesionData.DestinationAddress is zero when                                    DestinationAddress is unspecified when doing Configure() for this                                   EFI Udp6 protocol instance.   @retval EFI_ACCESS_DENIED     The transmit completion token with the same Token.Event was already                                 in the transmit queue.   @retval EFI_NOT_READY         The completion token could not be queued because the transmit queue                                 is full.   @retval EFI_OUT_OF_RESOURCES  Could not queue the transmit data.   @retval EFI_NOT_FOUND         There is no route to the destination network or address.   @retval EFI_BAD_BUFFER_SIZE   The data length is greater than the maximum UDP packet size.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP6_TRANSMIT
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_UDP6_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Places an asynchronous receive request into the receiving queue.    The Receive() function places a completion token into the receive packet queue. This function is   always asynchronous.   The caller must fill in the Token.Event field in the completion token, and this field cannot be    NULL. When the receive operation completes, the EFI UDPv6 Protocol driver updates the Token.Status   and Token.Packet.RxData fields and the Token.Event is signaled.   Providing a proper notification function and context for the event will enable the user to receive   the notification and receiving status. That notification function is guaranteed to not be re-entered.    @param[in]   This             Pointer to the EFI_UDP6_PROTOCOL instance.   @param[in]   Token            Pointer to a token that is associated with the receive data descriptor.    @retval EFI_SUCCESS           The receive completion token was cached.   @retval EFI_NOT_STARTED       This EFI UDPv6 Protocol instance has not been started.   @retval EFI_NO_MAPPING        The underlying IPv6 driver was responsible for choosing a source                                 address for this instance, but no source address was available                                 for use.   @retval EFI_INVALID_PARAMETER One or more of the following is TRUE:                                 - This is NULL.                                 - Token is NULL.                                 - Token.Event is NULL.   @retval EFI_OUT_OF_RESOURCES  The receive completion token could not be queued due to a lack of system                                  resources (usually memory).   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred. The EFI UDPv6 Protocol                                 instance has been reset to startup defaults.   @retval EFI_ACCESS_DENIED     A receive completion token with the same Token.Event was already in                                  the receive queue.   @retval EFI_NOT_READY         The receive request could not be queued because the receive queue is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP6_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_UDP6_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Aborts an asynchronous transmit or receive request.    The Cancel() function is used to abort a pending transmit or receive request. If the token is in the   transmit or receive request queues, after calling this function, Token.Status will be set to   EFI_ABORTED and then Token.Event will be signaled. If the token is not in one of the queues,   which usually means that the asynchronous operation has completed, this function will not signal the   token and EFI_NOT_FOUND is returned.    @param[in]   This             Pointer to the EFI_UDP6_PROTOCOL instance.   @param[in]   Token            Pointer to a token that has been issued by EFI_UDP6_PROTOCOL.Transmit()                                 or EFI_UDP6_PROTOCOL.Receive().If NULL, all pending tokens are aborted.    @retval EFI_SUCCESS           The asynchronous I/O request was aborted and Token.Event was signaled.                                 When Token is NULL, all pending requests are aborted and their events                                 are signaled.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_NOT_STARTED       This instance has not been started.   @retval EFI_NOT_FOUND         When Token is not NULL, the asynchronous I/O request was not found in                                 the transmit or receive queue. It has either completed or was not issued                                 by Transmit() and Receive().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP6_CANCEL
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_UDP6_COMPLETION_TOKEN
modifier|*
name|Token
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Polls for incoming data packets and processes outgoing data packets.    The Poll() function can be used by network drivers and applications to increase the rate that data   packets are moved between the communications device and the transmit and receive queues.   In some systems, the periodic timer event in the managed network driver may not poll the underlying   communications device fast enough to transmit and/or receive all data packets without missing incoming   packets or dropping outgoing packets. Drivers and applications that are experiencing packet loss should   try calling the Poll() function more often.    @param[in]   This             Pointer to the EFI_UDP6_PROTOCOL instance.    @retval EFI_SUCCESS           Incoming or outgoing data was processed.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred.    @retval EFI_TIMEOUT           Data was dropped out of the transmit and/or receive queue.                                 Consider increasing the polling rate.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UDP6_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_UDP6_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_UDP6_PROTOCOL defines an EFI UDPv6 Protocol session that can be used by any network drivers,
end_comment

begin_comment
comment|/// applications, or daemons to transmit or receive UDP packets. This protocol instance can either be
end_comment

begin_comment
comment|/// bound to a specified port as a service or connected to some remote peer as an active client.
end_comment

begin_comment
comment|/// Each instance has its own settings, such as group table, that are independent from each other.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_UDP6_PROTOCOL
block|{
name|EFI_UDP6_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_UDP6_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_UDP6_GROUPS
name|Groups
decl_stmt|;
name|EFI_UDP6_TRANSMIT
name|Transmit
decl_stmt|;
name|EFI_UDP6_RECEIVE
name|Receive
decl_stmt|;
name|EFI_UDP6_CANCEL
name|Cancel
decl_stmt|;
name|EFI_UDP6_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUdp6ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUdp6ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

