begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI TCPv6(Transmission Control Protocol version 6) Protocol Definition   The EFI TCPv6 Service Binding Protocol is used to locate EFI TCPv6 Protocol drivers to create   and destroy child of the driver to communicate with other host using TCP protocol.   The EFI TCPv6 Protocol provides services to send and receive data stream.    Copyright (c) 2008 - 2014, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_TCP6_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_TCP6_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/ManagedNetwork.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/Ip6.h>
end_include

begin_define
define|#
directive|define
name|EFI_TCP6_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xec20eb79, 0x6c1a, 0x4664, {0x9a, 0x0d, 0xd2, 0xe4, 0xcc, 0x16, 0xd6, 0x64 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_TCP6_PROTOCOL_GUID
define|\
value|{ \     0x46e44855, 0xbd60, 0x4ab7, {0xab, 0x0d, 0xa6, 0x79, 0xb9, 0x44, 0x7d, 0x77 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_TCP6_PROTOCOL
name|EFI_TCP6_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_SERVICE_POINT is deprecated in the UEFI 2.4B and should not be used any more.
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
comment|/// The EFI TCPv6 Protocol instance handle that is using this
comment|/// address/port pair.
comment|///
name|EFI_HANDLE
name|InstanceHandle
decl_stmt|;
comment|///
comment|/// The local IPv6 address to which this TCP instance is bound. Set
comment|/// to 0::/128, if this TCP instance is configured to listen on all
comment|/// available source addresses.
comment|///
name|EFI_IPv6_ADDRESS
name|LocalAddress
decl_stmt|;
comment|///
comment|/// The local port number in host byte order.
comment|///
name|UINT16
name|LocalPort
decl_stmt|;
comment|///
comment|/// The remote IPv6 address. It may be 0::/128 if this TCP instance is
comment|/// not connected to any remote host.
comment|///
name|EFI_IPv6_ADDRESS
name|RemoteAddress
decl_stmt|;
comment|///
comment|/// The remote port number in host byte order. It may be zero if this
comment|/// TCP instance is not connected to any remote host.
comment|///
name|UINT16
name|RemotePort
decl_stmt|;
block|}
name|EFI_TCP6_SERVICE_POINT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_VARIABLE_DATA is deprecated in the UEFI 2.4B and should not be used any more.
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
comment|///< The handle of the driver that creates this entry.
name|UINT32
name|ServiceCount
decl_stmt|;
comment|///< The number of address/port pairs following this data structure.
name|EFI_TCP6_SERVICE_POINT
name|Services
index|[
literal|1
index|]
decl_stmt|;
comment|///< List of address/port pairs that are currently in use.
block|}
name|EFI_TCP6_VARIABLE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_ACCESS_POINT
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The local IP address assigned to this TCP instance. The EFI
comment|/// TCPv6 driver will only deliver incoming packets whose
comment|/// destination addresses exactly match the IP address. Set to zero to
comment|/// let the underlying IPv6 driver choose a source address. If not zero
comment|/// it must be one of the configured IP addresses in the underlying
comment|/// IPv6 driver.
comment|///
name|EFI_IPv6_ADDRESS
name|StationAddress
decl_stmt|;
comment|///
comment|/// The local port number to which this EFI TCPv6 Protocol instance
comment|/// is bound. If the instance doesn't care the local port number, set
comment|/// StationPort to zero to use an ephemeral port.
comment|///
name|UINT16
name|StationPort
decl_stmt|;
comment|///
comment|/// The remote IP address to which this EFI TCPv6 Protocol instance
comment|/// is connected. If ActiveFlag is FALSE (i.e. a passive TCPv6
comment|/// instance), the instance only accepts connections from the
comment|/// RemoteAddress. If ActiveFlag is TRUE the instance will
comment|/// connect to the RemoteAddress, i.e., outgoing segments will be
comment|/// sent to this address and only segments from this address will be
comment|/// delivered to the application. When ActiveFlag is FALSE, it
comment|/// can be set to zero and means that incoming connection requests
comment|/// from any address will be accepted.
comment|///
name|EFI_IPv6_ADDRESS
name|RemoteAddress
decl_stmt|;
comment|///
comment|/// The remote port to which this EFI TCPv6 Protocol instance
comment|/// connects or from which connection request will be accepted by
comment|/// this EFI TCPv6 Protocol instance. If ActiveFlag is FALSE it
comment|/// can be zero and means that incoming connection request from
comment|/// any port will be accepted. Its value can not be zero when
comment|/// ActiveFlag is TRUE.
comment|///
name|UINT16
name|RemotePort
decl_stmt|;
comment|///
comment|/// Set it to TRUE to initiate an active open. Set it to FALSE to
comment|/// initiate a passive open to act as a server.
comment|///
name|BOOLEAN
name|ActiveFlag
decl_stmt|;
block|}
name|EFI_TCP6_ACCESS_POINT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_OPTION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The size of the TCP receive buffer.
comment|///
name|UINT32
name|ReceiveBufferSize
decl_stmt|;
comment|///
comment|/// The size of the TCP send buffer.
comment|///
name|UINT32
name|SendBufferSize
decl_stmt|;
comment|///
comment|/// The length of incoming connect request queue for a passive
comment|/// instance. When set to zero, the value is implementation specific.
comment|///
name|UINT32
name|MaxSynBackLog
decl_stmt|;
comment|///
comment|/// The maximum seconds a TCP instance will wait for before a TCP
comment|/// connection established. When set to zero, the value is
comment|/// implementation specific.
comment|///
name|UINT32
name|ConnectionTimeout
decl_stmt|;
comment|///
comment|///The number of times TCP will attempt to retransmit a packet on
comment|///an established connection. When set to zero, the value is
comment|///implementation specific.
comment|///
name|UINT32
name|DataRetries
decl_stmt|;
comment|///
comment|/// How many seconds to wait in the FIN_WAIT_2 states for a final
comment|/// FIN flag before the TCP instance is closed. This timeout is in
comment|/// effective only if the application has called Close() to
comment|/// disconnect the connection completely. It is also called
comment|/// FIN_WAIT_2 timer in other implementations. When set to zero,
comment|/// it should be disabled because the FIN_WAIT_2 timer itself is
comment|/// against the standard. The default value is 60.
comment|///
name|UINT32
name|FinTimeout
decl_stmt|;
comment|///
comment|/// How many seconds to wait in TIME_WAIT state before the TCP
comment|/// instance is closed. The timer is disabled completely to provide a
comment|/// method to close the TCP connection quickly if it is set to zero. It
comment|/// is against the related RFC documents.
comment|///
name|UINT32
name|TimeWaitTimeout
decl_stmt|;
comment|///
comment|/// The maximum number of TCP keep-alive probes to send before
comment|/// giving up and resetting the connection if no response from the
comment|/// other end. Set to zero to disable keep-alive probe.
comment|///
name|UINT32
name|KeepAliveProbes
decl_stmt|;
comment|///
comment|/// The number of seconds a connection needs to be idle before TCP
comment|/// sends out periodical keep-alive probes. When set to zero, the
comment|/// value is implementation specific. It should be ignored if keep-
comment|/// alive probe is disabled.
comment|///
name|UINT32
name|KeepAliveTime
decl_stmt|;
comment|///
comment|/// The number of seconds between TCP keep-alive probes after the
comment|/// periodical keep-alive probe if no response. When set to zero, the
comment|/// value is implementation specific. It should be ignored if keep-
comment|/// alive probe is disabled.
comment|///
name|UINT32
name|KeepAliveInterval
decl_stmt|;
comment|///
comment|/// Set it to TRUE to enable the Nagle algorithm as defined in
comment|/// RFC896. Set it to FALSE to disable it.
comment|///
name|BOOLEAN
name|EnableNagle
decl_stmt|;
comment|///
comment|/// Set it to TRUE to enable TCP timestamps option as defined in
comment|/// RFC1323. Set to FALSE to disable it.
comment|///
name|BOOLEAN
name|EnableTimeStamp
decl_stmt|;
comment|///
comment|/// Set it to TRUE to enable TCP window scale option as defined in
comment|/// RFC1323. Set it to FALSE to disable it.
comment|///
name|BOOLEAN
name|EnableWindowScaling
decl_stmt|;
comment|///
comment|/// Set it to TRUE to enable selective acknowledge mechanism
comment|/// described in RFC 2018. Set it to FALSE to disable it.
comment|/// Implementation that supports SACK can optionally support
comment|/// DSAK as defined in RFC 2883.
comment|///
name|BOOLEAN
name|EnableSelectiveAck
decl_stmt|;
comment|///
comment|/// Set it to TRUE to enable path MTU discovery as defined in
comment|/// RFC 1191. Set to FALSE to disable it.
comment|///
name|BOOLEAN
name|EnablePathMtuDiscovery
decl_stmt|;
block|}
name|EFI_TCP6_OPTION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_CONFIG_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
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
comment|/// Used to specify TCP communication end settings for a TCP instance.
comment|///
name|EFI_TCP6_ACCESS_POINT
name|AccessPoint
decl_stmt|;
comment|///
comment|/// Used to configure the advance TCP option for a connection. If set
comment|/// to NULL, implementation specific options for TCP connection will be used.
comment|///
name|EFI_TCP6_OPTION
modifier|*
name|ControlOption
decl_stmt|;
block|}
name|EFI_TCP6_CONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_CONNECTION_STATE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Tcp6StateClosed
init|=
literal|0
block|,
name|Tcp6StateListen
init|=
literal|1
block|,
name|Tcp6StateSynSent
init|=
literal|2
block|,
name|Tcp6StateSynReceived
init|=
literal|3
block|,
name|Tcp6StateEstablished
init|=
literal|4
block|,
name|Tcp6StateFinWait1
init|=
literal|5
block|,
name|Tcp6StateFinWait2
init|=
literal|6
block|,
name|Tcp6StateClosing
init|=
literal|7
block|,
name|Tcp6StateTimeWait
init|=
literal|8
block|,
name|Tcp6StateCloseWait
init|=
literal|9
block|,
name|Tcp6StateLastAck
init|=
literal|10
block|}
name|EFI_TCP6_CONNECTION_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_COMPLETION_TOKEN
end_comment

begin_comment
comment|/// is used as a common header for various asynchronous tokens.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The Event to signal after request is finished and Status field is
comment|/// updated by the EFI TCPv6 Protocol driver.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// The result of the completed operation.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
block|}
name|EFI_TCP6_COMPLETION_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_CONNECTION_TOKEN
end_comment

begin_comment
comment|/// will be set if the active open succeeds or an unexpected
end_comment

begin_comment
comment|/// error happens.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The Status in the CompletionToken will be set to one of
comment|/// the following values if the active open succeeds or an unexpected
comment|/// error happens:
comment|/// EFI_SUCCESS:              The active open succeeds and the instance's
comment|///                           state is Tcp6StateEstablished.
comment|/// EFI_CONNECTION_RESET:     The connect fails because the connection is reset
comment|///                           either by instance itself or the communication peer.
comment|/// EFI_CONNECTION_REFUSED:   The receiving or transmission operation fails because this
comment|///                           connection is refused.
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
comment|/// EFI_ICMP_ERROR:           The connection establishment timer times
comment|///                           out and some other ICMP error is received.
comment|/// EFI_DEVICE_ERROR:         An unexpected system or network error occurred.
comment|/// EFI_SECURITY_VIOLATION:   The active open was failed because of IPSec policy check.
comment|/// EFI_NO_MEDIA:             There was a media error.
comment|///
name|EFI_TCP6_COMPLETION_TOKEN
name|CompletionToken
decl_stmt|;
block|}
name|EFI_TCP6_CONNECTION_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_LISTEN_TOKEN
end_comment

begin_comment
comment|/// returns when list operation finishes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The Status in CompletionToken will be set to the
comment|/// following value if accept finishes:
comment|/// EFI_SUCCESS:            A remote peer has successfully established a
comment|///                         connection to this instance. A new TCP instance has also been
comment|///                         created for the connection.
comment|/// EFI_CONNECTION_RESET:   The accept fails because the connection is reset either
comment|///                         by instance itself or communication peer.
comment|/// EFI_ABORTED:            The accept request has been aborted.
comment|/// EFI_SECURITY_VIOLATION: The accept operation was failed because of IPSec policy check.
comment|///
name|EFI_TCP6_COMPLETION_TOKEN
name|CompletionToken
decl_stmt|;
name|EFI_HANDLE
name|NewChildHandle
decl_stmt|;
block|}
name|EFI_TCP6_LISTEN_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_FRAGMENT_DATA
end_comment

begin_comment
comment|/// allows multiple receive or transmit buffers to be specified. The
end_comment

begin_comment
comment|/// purpose of this structure is to provide scattered read and write.
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
comment|///< Length of data buffer in the fragment.
name|VOID
modifier|*
name|FragmentBuffer
decl_stmt|;
comment|///< Pointer to the data buffer in the fragment.
block|}
name|EFI_TCP6_FRAGMENT_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_RECEIVE_DATA
end_comment

begin_comment
comment|/// When TCPv6 driver wants to deliver received data to the application,
end_comment

begin_comment
comment|/// it will pick up the first queued receiving token, update its
end_comment

begin_comment
comment|/// Token->Packet.RxData then signal the Token->CompletionToken.Event.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Whether the data is urgent. When this flag is set, the instance is in
comment|/// urgent mode.
comment|///
name|BOOLEAN
name|UrgentFlag
decl_stmt|;
comment|///
comment|/// When calling Receive() function, it is the byte counts of all
comment|/// Fragmentbuffer in FragmentTable allocated by user.
comment|/// When the token is signaled by TCPv6 driver it is the length of
comment|/// received data in the fragments.
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
comment|/// An array of fragment descriptors.
comment|///
name|EFI_TCP6_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_TCP6_RECEIVE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_TRANSMIT_DATA
end_comment

begin_comment
comment|/// The EFI TCPv6 Protocol user must fill this data structure before sending a packet.
end_comment

begin_comment
comment|/// The packet may contain multiple buffers in non-continuous memory locations.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Push If TRUE, data must be transmitted promptly, and the PUSH bit in
comment|/// the last TCP segment created will be set. If FALSE, data
comment|/// transmission may be delayed to combine with data from
comment|/// subsequent Transmit()s for efficiency.
comment|///
name|BOOLEAN
name|Push
decl_stmt|;
comment|///
comment|/// The data in the fragment table are urgent and urgent point is in
comment|/// effect if TRUE. Otherwise those data are NOT considered urgent.
comment|///
name|BOOLEAN
name|Urgent
decl_stmt|;
comment|///
comment|/// Length of the data in the fragments.
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
comment|/// An array of fragment descriptors.
comment|///
name|EFI_TCP6_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_TCP6_TRANSMIT_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_IO_TOKEN
end_comment

begin_comment
comment|/// returns When transmission finishes or meets any unexpected error.
end_comment

begin_comment
comment|///
end_comment

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
comment|/// EFI_SECURITY_VIOLATION:   The receiving or transmission
comment|///                           operation was failed because of IPSec policy check
comment|/// EFI_NO_MEDIA:             There was a media error.
comment|///
name|EFI_TCP6_COMPLETION_TOKEN
name|CompletionToken
decl_stmt|;
union|union
block|{
comment|///
comment|/// When this token is used for receiving, RxData is a pointer to
comment|/// EFI_TCP6_RECEIVE_DATA.
comment|///
name|EFI_TCP6_RECEIVE_DATA
modifier|*
name|RxData
decl_stmt|;
comment|///
comment|/// When this token is used for transmitting, TxData is a pointer to
comment|/// EFI_TCP6_TRANSMIT_DATA.
comment|///
name|EFI_TCP6_TRANSMIT_DATA
modifier|*
name|TxData
decl_stmt|;
block|}
name|Packet
union|;
block|}
name|EFI_TCP6_IO_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_CLOSE_TOKEN
end_comment

begin_comment
comment|/// returns when close operation finishes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// When close finishes or meets any unexpected error it will be set
comment|/// to one of the following values:
comment|/// EFI_SUCCESS:            The close operation completes successfully.
comment|/// EFI_ABORTED:            User called configure with NULL without close stopping.
comment|/// EFI_SECURITY_VIOLATION: The close operation was failed because of IPSec policy check.
comment|///
name|EFI_TCP6_COMPLETION_TOKEN
name|CompletionToken
decl_stmt|;
comment|///
comment|/// Abort the TCP connection on close instead of the standard TCP
comment|/// close process when it is set to TRUE. This option can be used to
comment|/// satisfy a fast disconnect.
comment|///
name|BOOLEAN
name|AbortOnClose
decl_stmt|;
block|}
name|EFI_TCP6_CLOSE_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Get the current operational status.    The GetModeData() function copies the current operational settings of this EFI TCPv6   Protocol instance into user-supplied buffers. This function can also be used to retrieve   the operational setting of underlying drivers such as IPv6, MNP, or SNP.    @param[in]  This              Pointer to the EFI_TCP6_PROTOCOL instance.   @param[out] Tcp6State         The buffer in which the current TCP state is returned.   @param[out] Tcp6ConfigData    The buffer in which the current TCP configuration is returned.   @param[out] Ip6ModeData       The buffer in which the current IPv6 configuration data used by                                 the TCP instance is returned.   @param[out] MnpConfigData     The buffer in which the current MNP configuration data used                                 indirectly by the TCP instance is returned.   @param[out] SnpModeData       The buffer in which the current SNP mode data used indirectly by                                 the TCP instance is returned.    @retval EFI_SUCCESS           The mode data was read.   @retval EFI_NOT_STARTED       No configuration data is available because this instance hasn't                                 been started.   @retval EFI_INVALID_PARAMETER This is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP6_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_TCP6_CONNECTION_STATE
modifier|*
name|Tcp6State
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_TCP6_CONFIG_DATA
modifier|*
name|Tcp6ConfigData
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
comment|/**   Initialize or brutally reset the operational parameters for this EFI TCPv6 instance.    The Configure() function does the following:   - Initialize this TCP instance, i.e., initialize the communication end settings and     specify active open or passive open for an instance.   - Reset this TCP instance brutally, i.e., cancel all pending asynchronous tokens, flush     transmission and receiving buffer directly without informing the communication peer.    No other TCPv6 Protocol operation except Poll() can be executed by this instance until   it is configured properly. For an active TCP instance, after a proper configuration it   may call Connect() to initiates the three-way handshake. For a passive TCP instance,   its state will transit to Tcp6StateListen after configuration, and Accept() may be   called to listen the incoming TCP connection requests. If Tcp6ConfigData is set to NULL,   the instance is reset. Resetting process will be done brutally, the state machine will   be set to Tcp6StateClosed directly, the receive queue and transmit queue will be flushed,   and no traffic is allowed through this instance.    @param[in] This               Pointer to the EFI_TCP6_PROTOCOL instance.   @param[in] Tcp6ConfigData     Pointer to the configure data to configure the instance.                                 If Tcp6ConfigData is set to NULL, the instance is reset.    @retval EFI_SUCCESS           The operational settings are set, changed, or reset                                 successfully.   @retval EFI_NO_MAPPING        The underlying IPv6 driver was responsible for choosing a source                                 address for this instance, but no source address was available for                                 use.   @retval EFI_INVALID_PARAMETER One or more of the following conditions are TRUE:                                 - This is NULL.                                 - Tcp6ConfigData->AccessPoint.StationAddress is neither zero nor                                   one of the configured IP addresses in the underlying IPv6 driver.                                 - Tcp6ConfigData->AccessPoint.RemoteAddress isn't a valid unicast                                   IPv6 address.                                 - Tcp6ConfigData->AccessPoint.RemoteAddress is zero or                                   Tcp6ConfigData->AccessPoint.RemotePort is zero when                                   Tcp6ConfigData->AccessPoint.ActiveFlag is TRUE.                                 - A same access point has been configured in other TCP                                   instance properly.   @retval EFI_ACCESS_DENIED     Configuring TCP instance when it is configured without                                 calling Configure() with NULL to reset it.   @retval EFI_UNSUPPORTED       One or more of the control options are not supported in                                 the implementation.   @retval EFI_OUT_OF_RESOURCES  Could not allocate enough system resources when                                 executing Configure().   @retval EFI_DEVICE_ERROR      An unexpected network or system error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP6_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP6_CONFIG_DATA
modifier|*
name|Tcp6ConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Initiate a nonblocking TCP connection request for an active TCP instance.    The Connect() function will initiate an active open to the remote peer configured   in current TCP instance if it is configured active. If the connection succeeds or   fails due to any error, the ConnectionToken->CompletionToken.Event will be signaled   and ConnectionToken->CompletionToken.Status will be updated accordingly. This   function can only be called for the TCP instance in Tcp6StateClosed state. The   instance will transfer into Tcp6StateSynSent if the function returns EFI_SUCCESS.   If TCP three-way handshake succeeds, its state will become Tcp6StateEstablished,   otherwise, the state will return to Tcp6StateClosed.    @param[in] This                Pointer to the EFI_TCP6_PROTOCOL instance.   @param[in] ConnectionToken     Pointer to the connection token to return when the TCP three                                  way handshake finishes.    @retval EFI_SUCCESS            The connection request is successfully initiated and the state of                                  this TCP instance has been changed to Tcp6StateSynSent.   @retval EFI_NOT_STARTED        This EFI TCPv6 Protocol instance has not been configured.   @retval EFI_ACCESS_DENIED      One or more of the following conditions are TRUE:                                  - This instance is not configured as an active one.                                  - This instance is not in Tcp6StateClosed state.   @retval EFI_INVALID_PARAMETER  One or more of the following are TRUE:                                  - This is NULL.                                  - ConnectionToken is NULL.                                  - ConnectionToken->CompletionToken.Event is NULL.   @retval EFI_OUT_OF_RESOURCES   The driver can't allocate enough resource to initiate the active open.   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP6_CONNECT
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP6_CONNECTION_TOKEN
modifier|*
name|ConnectionToken
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Listen on the passive instance to accept an incoming connection request. This is a   nonblocking operation.    The Accept() function initiates an asynchronous accept request to wait for an incoming   connection on the passive TCP instance. If a remote peer successfully establishes a   connection with this instance, a new TCP instance will be created and its handle will   be returned in ListenToken->NewChildHandle. The newly created instance is configured   by inheriting the passive instance's configuration and is ready for use upon return.   The new instance is in the Tcp6StateEstablished state.    The ListenToken->CompletionToken.Event will be signaled when a new connection is   accepted, user aborts the listen or connection is reset.    This function only can be called when current TCP instance is in Tcp6StateListen state.    @param[in] This                Pointer to the EFI_TCP6_PROTOCOL instance.   @param[in] ListenToken         Pointer to the listen token to return when operation finishes.     @retval EFI_SUCCESS            The listen token has been queued successfully.   @retval EFI_NOT_STARTED        This EFI TCPv6 Protocol instance has not been configured.   @retval EFI_ACCESS_DENIED      One or more of the following are TRUE:                                  - This instance is not a passive instance.                                  - This instance is not in Tcp6StateListen state.                                  - The same listen token has already existed in the listen                                    token queue of this TCP instance.   @retval EFI_INVALID_PARAMETER  One or more of the following are TRUE:                                  - This is NULL.                                  - ListenToken is NULL.                                  - ListentToken->CompletionToken.Event is NULL.   @retval EFI_OUT_OF_RESOURCES   Could not allocate enough resource to finish the operation.   @retval EFI_DEVICE_ERROR       Any unexpected and not belonged to above category error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP6_ACCEPT
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP6_LISTEN_TOKEN
modifier|*
name|ListenToken
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Queues outgoing data into the transmit queue.    The Transmit() function queues a sending request to this TCP instance along with the   user data. The status of the token is updated and the event in the token will be   signaled once the data is sent out or some error occurs.    @param[in] This                 Pointer to the EFI_TCP6_PROTOCOL instance.   @param[in] Token                Pointer to the completion token to queue to the transmit queue.    @retval EFI_SUCCESS             The data has been queued for transmission.   @retval EFI_NOT_STARTED         This EFI TCPv6 Protocol instance has not been configured.   @retval EFI_NO_MAPPING          The underlying IPv6 driver was responsible for choosing a                                   source address for this instance, but no source address was                                   available for use.   @retval EFI_INVALID_PARAMETER   One or more of the following are TRUE:                                   - This is NULL.                                   - Token is NULL.                                   - Token->CompletionToken.Event is NULL.                                   - Token->Packet.TxData is NULL.                                   - Token->Packet.FragmentCount is zero.                                   - Token->Packet.DataLength is not equal to the sum of fragment lengths.   @retval EFI_ACCESS_DENIED       One or more of the following conditions are TRUE:                                   - A transmit completion token with the same Token->                                     CompletionToken.Event was already in the                                     transmission queue.                                   - The current instance is in Tcp6StateClosed state.                                   - The current instance is a passive one and it is in                                     Tcp6StateListen state.                                   - User has called Close() to disconnect this connection.   @retval EFI_NOT_READY           The completion token could not be queued because the                                   transmit queue is full.   @retval EFI_OUT_OF_RESOURCES    Could not queue the transmit data because of resource                                   shortage.   @retval EFI_NETWORK_UNREACHABLE There is no route to the destination network or address.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP6_TRANSMIT
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP6_IO_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Places an asynchronous receive request into the receiving queue.    The Receive() function places a completion token into the receive packet queue. This   function is always asynchronous. The caller must allocate the Token->CompletionToken.Event   and the FragmentBuffer used to receive data. The caller also must fill the DataLength which   represents the whole length of all FragmentBuffer. When the receive operation completes, the   EFI TCPv6 Protocol driver updates the Token->CompletionToken.Status and Token->Packet.RxData   fields and the Token->CompletionToken.Event is signaled. If got data the data and its length   will be copied into the FragmentTable, at the same time the full length of received data will   be recorded in the DataLength fields. Providing a proper notification function and context   for the event will enable the user to receive the notification and receiving status. That   notification function is guaranteed to not be re-entered.    @param[in] This               Pointer to the EFI_TCP6_PROTOCOL instance.   @param[in] Token              Pointer to a token that is associated with the receive data                                 descriptor.    @retval EFI_SUCCESS            The receive completion token was cached.   @retval EFI_NOT_STARTED        This EFI TCPv6 Protocol instance has not been configured.   @retval EFI_NO_MAPPING         The underlying IPv6 driver was responsible for choosing a source                                  address for this instance, but no source address was available for use.   @retval EFI_INVALID_PARAMETER  One or more of the following conditions is TRUE:                                  - This is NULL.                                  - Token is NULL.                                  - Token->CompletionToken.Event is NULL.                                  - Token->Packet.RxData is NULL.                                  - Token->Packet.RxData->DataLength is 0.                                  - The Token->Packet.RxData->DataLength is not the                                    sum of all FragmentBuffer length in FragmentTable.   @retval EFI_OUT_OF_RESOURCES   The receive completion token could not be queued due to a lack of                                  system resources (usually memory).   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.                                  The EFI TCPv6 Protocol instance has been reset to startup defaults.   @retval EFI_ACCESS_DENIED      One or more of the following conditions is TRUE:                                  - A receive completion token with the same Token->CompletionToken.Event                                    was already in the receive queue.                                  - The current instance is in Tcp6StateClosed state.                                  - The current instance is a passive one and it is in                                    Tcp6StateListen state.                                  - User has called Close() to disconnect this connection.   @retval EFI_CONNECTION_FIN     The communication peer has closed the connection and there is no                                  any buffered data in the receive buffer of this instance   @retval EFI_NOT_READY          The receive request could not be queued because the receive queue is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP6_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP6_IO_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Disconnecting a TCP connection gracefully or reset a TCP connection. This function is a   nonblocking operation.    Initiate an asynchronous close token to TCP driver. After Close() is called, any buffered   transmission data will be sent by TCP driver and the current instance will have a graceful close   working flow described as RFC 793 if AbortOnClose is set to FALSE, otherwise, a rest packet   will be sent by TCP driver to fast disconnect this connection. When the close operation completes   successfully the TCP instance is in Tcp6StateClosed state, all pending asynchronous   operations are signaled and any buffers used for TCP network traffic are flushed.    @param[in] This                Pointer to the EFI_TCP6_PROTOCOL instance.   @param[in] CloseToken          Pointer to the close token to return when operation finishes.    @retval EFI_SUCCESS            The Close() is called successfully.   @retval EFI_NOT_STARTED        This EFI TCPv6 Protocol instance has not been configured.   @retval EFI_ACCESS_DENIED      One or more of the following are TRUE:                                  - CloseToken or CloseToken->CompletionToken.Event is already in use.                                  - Previous Close() call on this instance has not finished.   @retval EFI_INVALID_PARAMETER  One or more of the following are TRUE:                                  - This is NULL.                                  - CloseToken is NULL.                                  - CloseToken->CompletionToken.Event is NULL.   @retval EFI_OUT_OF_RESOURCES   Could not allocate enough resource to finish the operation.   @retval EFI_DEVICE_ERROR       Any unexpected and not belonged to above category error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP6_CLOSE
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP6_CLOSE_TOKEN
modifier|*
name|CloseToken
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Abort an asynchronous connection, listen, transmission or receive request.    The Cancel() function aborts a pending connection, listen, transmit or   receive request.    If Token is not NULL and the token is in the connection, listen, transmission   or receive queue when it is being cancelled, its Token->Status will be set   to EFI_ABORTED and then Token->Event will be signaled.    If the token is not in one of the queues, which usually means that the   asynchronous operation has completed, EFI_NOT_FOUND is returned.    If Token is NULL all asynchronous token issued by Connect(), Accept(),   Transmit() and Receive() will be aborted.    @param[in] This                Pointer to the EFI_TCP6_PROTOCOL instance.   @param[in] Token               Pointer to a token that has been issued by                                  EFI_TCP6_PROTOCOL.Connect(),                                  EFI_TCP6_PROTOCOL.Accept(),                                  EFI_TCP6_PROTOCOL.Transmit() or                                  EFI_TCP6_PROTOCOL.Receive(). If NULL, all pending                                  tokens issued by above four functions will be aborted. Type                                  EFI_TCP6_COMPLETION_TOKEN is defined in                                  EFI_TCP_PROTOCOL.Connect().    @retval EFI_SUCCESS            The asynchronous I/O request is aborted and Token->Event                                  is signaled.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_NOT_STARTED        This instance hasn't been configured.   @retval EFI_NOT_FOUND          The asynchronous I/O request isn't found in the transmission or                                  receive queue. It has either completed or wasn't issued by                                  Transmit() and Receive().   @retval EFI_UNSUPPORTED        The implementation does not support this function.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP6_CANCEL
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TCP6_COMPLETION_TOKEN
modifier|*
name|Token
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Poll to receive incoming data and transmit outgoing segments.    The Poll() function increases the rate that data is moved between the network   and application and can be called when the TCP instance is created successfully.   Its use is optional.    @param[in] This                Pointer to the EFI_TCP6_PROTOCOL instance.    @retval EFI_SUCCESS            Incoming or outgoing data was processed.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.   @retval EFI_NOT_READY          No incoming or outgoing data is processed.   @retval EFI_TIMEOUT            Data was dropped out of the transmission or receive queue.                                  Consider increasing the polling rate.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCP6_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_TCP6_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TCP6_PROTOCOL
end_comment

begin_comment
comment|/// defines the EFI TCPv6 Protocol child to be used by any network drivers or
end_comment

begin_comment
comment|/// applications to send or receive data stream. It can either listen on a
end_comment

begin_comment
comment|/// specified port as a service or actively connect to remote peer as a client.
end_comment

begin_comment
comment|/// Each instance has its own independent settings.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_TCP6_PROTOCOL
block|{
name|EFI_TCP6_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_TCP6_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_TCP6_CONNECT
name|Connect
decl_stmt|;
name|EFI_TCP6_ACCEPT
name|Accept
decl_stmt|;
name|EFI_TCP6_TRANSMIT
name|Transmit
decl_stmt|;
name|EFI_TCP6_RECEIVE
name|Receive
decl_stmt|;
name|EFI_TCP6_CLOSE
name|Close
decl_stmt|;
name|EFI_TCP6_CANCEL
name|Cancel
decl_stmt|;
name|EFI_TCP6_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTcp6ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTcp6ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

