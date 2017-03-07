begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI IPv6 (Internet Protocol version 6)   Protocol interface. It is split into the following three main   sections:   - EFI IPv6 Service Binding Protocol   - EFI IPv6 Variable (deprecated in UEFI 2.4B)   - EFI IPv6 Protocol   The EFI IPv6 Protocol provides basic network IPv6 packet I/O services,   which includes support for Neighbor Discovery Protocol (ND), Multicast   Listener Discovery Protocol (MLD), and a subset of the Internet Control   Message Protocol (ICMPv6).    Copyright (c) 2008 - 2014, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_IP6_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_IP6_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/ManagedNetwork.h>
end_include

begin_define
define|#
directive|define
name|EFI_IP6_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xec835dd3, 0xfe0f, 0x617b, {0xa6, 0x21, 0xb3, 0x50, 0xc3, 0xe1, 0x33, 0x88 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_IP6_PROTOCOL_GUID
define|\
value|{ \     0x2c8759d5, 0x5c2d, 0x66ef, {0x92, 0x5f, 0xb6, 0x6c, 0x10, 0x19, 0x57, 0xe2 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_IP6_PROTOCOL
name|EFI_IP6_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_ADDRESS_PAIR is deprecated in the UEFI 2.4B and should not be used any more.
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
comment|/// The EFI IPv6 Protocol instance handle that is using this address/prefix pair.
comment|///
name|EFI_HANDLE
name|InstanceHandle
decl_stmt|;
comment|///
comment|/// IPv6 address in network byte order.
comment|///
name|EFI_IPv6_ADDRESS
name|Ip6Address
decl_stmt|;
comment|///
comment|/// The length of the prefix associated with the Ip6Address.
comment|///
name|UINT8
name|PrefixLength
decl_stmt|;
block|}
name|EFI_IP6_ADDRESS_PAIR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_VARIABLE_DATA is deprecated in the UEFI 2.4B and should not be used any more.
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
comment|/// The number of IPv6 address pairs that follow this data structure.
comment|///
name|UINT32
name|AddressCount
decl_stmt|;
comment|///
comment|/// List of IPv6 address pairs that are currently in use.
comment|///
name|EFI_IP6_ADDRESS_PAIR
name|AddressPairs
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IP6_VARIABLE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ICMPv6 type definitions for error messages
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|ICMP_V6_DEST_UNREACHABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|ICMP_V6_PACKET_TOO_BIG
value|0x2
end_define

begin_define
define|#
directive|define
name|ICMP_V6_TIME_EXCEEDED
value|0x3
end_define

begin_define
define|#
directive|define
name|ICMP_V6_PARAMETER_PROBLEM
value|0x4
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ICMPv6 type definition for informational messages
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|ICMP_V6_ECHO_REQUEST
value|0x80
end_define

begin_define
define|#
directive|define
name|ICMP_V6_ECHO_REPLY
value|0x81
end_define

begin_define
define|#
directive|define
name|ICMP_V6_LISTENER_QUERY
value|0x82
end_define

begin_define
define|#
directive|define
name|ICMP_V6_LISTENER_REPORT
value|0x83
end_define

begin_define
define|#
directive|define
name|ICMP_V6_LISTENER_DONE
value|0x84
end_define

begin_define
define|#
directive|define
name|ICMP_V6_ROUTER_SOLICIT
value|0x85
end_define

begin_define
define|#
directive|define
name|ICMP_V6_ROUTER_ADVERTISE
value|0x86
end_define

begin_define
define|#
directive|define
name|ICMP_V6_NEIGHBOR_SOLICIT
value|0x87
end_define

begin_define
define|#
directive|define
name|ICMP_V6_NEIGHBOR_ADVERTISE
value|0x88
end_define

begin_define
define|#
directive|define
name|ICMP_V6_REDIRECT
value|0x89
end_define

begin_define
define|#
directive|define
name|ICMP_V6_LISTENER_REPORT_2
value|0x8F
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ICMPv6 code definitions for ICMP_V6_DEST_UNREACHABLE
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|ICMP_V6_NO_ROUTE_TO_DEST
value|0x0
end_define

begin_define
define|#
directive|define
name|ICMP_V6_COMM_PROHIBITED
value|0x1
end_define

begin_define
define|#
directive|define
name|ICMP_V6_BEYOND_SCOPE
value|0x2
end_define

begin_define
define|#
directive|define
name|ICMP_V6_ADDR_UNREACHABLE
value|0x3
end_define

begin_define
define|#
directive|define
name|ICMP_V6_PORT_UNREACHABLE
value|0x4
end_define

begin_define
define|#
directive|define
name|ICMP_V6_SOURCE_ADDR_FAILED
value|0x5
end_define

begin_define
define|#
directive|define
name|ICMP_V6_ROUTE_REJECTED
value|0x6
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ICMPv6 code definitions for ICMP_V6_TIME_EXCEEDED
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|ICMP_V6_TIMEOUT_HOP_LIMIT
value|0x0
end_define

begin_define
define|#
directive|define
name|ICMP_V6_TIMEOUT_REASSEMBLE
value|0x1
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ICMPv6 code definitions for ICMP_V6_PARAMETER_PROBLEM
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|ICMP_V6_ERRONEOUS_HEADER
value|0x0
end_define

begin_define
define|#
directive|define
name|ICMP_V6_UNRECOGNIZE_NEXT_HDR
value|0x1
end_define

begin_define
define|#
directive|define
name|ICMP_V6_UNRECOGNIZE_OPTION
value|0x2
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_CONFIG_DATA
end_comment

begin_comment
comment|/// is used to report and change IPv6 session parameters.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// For the IPv6 packet to send and receive, this is the default value
comment|/// of the 'Next Header' field in the last IPv6 extension header or in
comment|/// the IPv6 header if there are no extension headers. Ignored when
comment|/// AcceptPromiscuous is TRUE.
comment|///
name|UINT8
name|DefaultProtocol
decl_stmt|;
comment|///
comment|/// Set to TRUE to receive all IPv6 packets that get through the
comment|/// receive filters.
comment|/// Set to FALSE to receive only the DefaultProtocol IPv6
comment|/// packets that get through the receive filters. Ignored when
comment|/// AcceptPromiscuous is TRUE.
comment|///
name|BOOLEAN
name|AcceptAnyProtocol
decl_stmt|;
comment|///
comment|/// Set to TRUE to receive ICMP error report packets. Ignored when
comment|/// AcceptPromiscuous or AcceptAnyProtocol is TRUE.
comment|///
name|BOOLEAN
name|AcceptIcmpErrors
decl_stmt|;
comment|///
comment|/// Set to TRUE to receive all IPv6 packets that are sent to any
comment|/// hardware address or any protocol address. Set to FALSE to stop
comment|/// receiving all promiscuous IPv6 packets.
comment|///
name|BOOLEAN
name|AcceptPromiscuous
decl_stmt|;
comment|///
comment|/// The destination address of the packets that will be transmitted.
comment|/// Ignored if it is unspecified.
comment|///
name|EFI_IPv6_ADDRESS
name|DestinationAddress
decl_stmt|;
comment|///
comment|/// The station IPv6 address that will be assigned to this EFI IPv6
comment|/// Protocol instance. This field can be set and changed only when
comment|/// the EFI IPv6 driver is transitioning from the stopped to the started
comment|/// states. If the StationAddress is specified, the EFI IPv6 Protocol
comment|/// driver will deliver only incoming IPv6 packets whose destination
comment|/// matches this IPv6 address exactly. The StationAddress is required
comment|/// to be one of currently configured IPv6 addresses. An address
comment|/// containing all zeroes is also accepted as a special case. Under this
comment|/// situation, the IPv6 driver is responsible for binding a source
comment|/// address to this EFI IPv6 protocol instance according to the source
comment|/// address selection algorithm. Only incoming packets destined to
comment|/// the selected address will be delivered to the user.  And the
comment|/// selected station address can be retrieved through later
comment|/// GetModeData() call. If no address is available for selecting,
comment|/// EFI_NO_MAPPING will be returned, and the station address will
comment|/// only be successfully bound to this EFI IPv6 protocol instance
comment|/// after IP6ModeData.IsConfigured changed to TRUE.
comment|///
name|EFI_IPv6_ADDRESS
name|StationAddress
decl_stmt|;
comment|///
comment|/// TrafficClass field in transmitted IPv6 packets. Default value
comment|/// is zero.
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
comment|/// FlowLabel field in transmitted IPv6 packets. Default value is
comment|/// zero.
comment|///
name|UINT32
name|FlowLabel
decl_stmt|;
comment|///
comment|/// The timer timeout value (number of microseconds) for the
comment|/// receive timeout event to be associated with each assembled
comment|/// packet. Zero means do not drop assembled packets.
comment|///
name|UINT32
name|ReceiveTimeout
decl_stmt|;
comment|///
comment|/// The timer timeout value (number of microseconds) for the
comment|/// transmit timeout event to be associated with each outgoing
comment|/// packet. Zero means do not drop outgoing packets.
comment|///
name|UINT32
name|TransmitTimeout
decl_stmt|;
block|}
name|EFI_IP6_CONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_ADDRESS_INFO
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_IPv6_ADDRESS
name|Address
decl_stmt|;
comment|///< The IPv6 address.
name|UINT8
name|PrefixLength
decl_stmt|;
comment|///< The length of the prefix associated with the Address.
block|}
name|EFI_IP6_ADDRESS_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_ROUTE_TABLE
end_comment

begin_comment
comment|/// is the entry structure that is used in routing tables
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The IPv6 address of the gateway to be used as the next hop for
comment|/// packets to this prefix. If the IPv6 address is all zeros, then the
comment|/// prefix is on-link.
comment|///
name|EFI_IPv6_ADDRESS
name|Gateway
decl_stmt|;
comment|///
comment|/// The destination prefix to be routed.
comment|///
name|EFI_IPv6_ADDRESS
name|Destination
decl_stmt|;
comment|///
comment|/// The length of the prefix associated with the Destination.
comment|///
name|UINT8
name|PrefixLength
decl_stmt|;
block|}
name|EFI_IP6_ROUTE_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_NEIGHBOR_STATE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Address resolution is being performed on this entry. Specially,
comment|/// Neighbor Solicitation has been sent to the solicited-node
comment|/// multicast address of the target, but corresponding Neighbor
comment|/// Advertisement has not been received.
comment|///
name|EfiNeighborInComplete
block|,
comment|///
comment|/// Positive confirmation was received that the forward path to the
comment|/// neighbor was functioning properly.
comment|///
name|EfiNeighborReachable
block|,
comment|///
comment|///Reachable Time has elapsed since the last positive confirmation
comment|///was received. In this state, the forward path to the neighbor was
comment|///functioning properly.
comment|///
name|EfiNeighborStale
block|,
comment|///
comment|/// This state is an optimization that gives upper-layer protocols
comment|/// additional time to provide reachability confirmation.
comment|///
name|EfiNeighborDelay
block|,
comment|///
comment|/// A reachability confirmation is actively sought by retransmitting
comment|/// Neighbor Solicitations every RetransTimer milliseconds until a
comment|/// reachability confirmation is received.
comment|///
name|EfiNeighborProbe
block|}
name|EFI_IP6_NEIGHBOR_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_NEIGHBOR_CACHE
end_comment

begin_comment
comment|/// is the entry structure that is used in neighbor cache. It records a set
end_comment

begin_comment
comment|/// of entries about individual neighbors to which traffic has been sent recently.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_IPv6_ADDRESS
name|Neighbor
decl_stmt|;
comment|///< The on-link unicast/anycast IP address of the neighbor.
name|EFI_MAC_ADDRESS
name|LinkAddress
decl_stmt|;
comment|///< Link-layer address of the neighbor.
name|EFI_IP6_NEIGHBOR_STATE
name|State
decl_stmt|;
comment|///< State of this neighbor cache entry.
block|}
name|EFI_IP6_NEIGHBOR_CACHE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_ICMP_TYPE
end_comment

begin_comment
comment|/// is used to describe those ICMP messages that are supported by this EFI
end_comment

begin_comment
comment|/// IPv6 Protocol driver.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
comment|///< The type of ICMP message.
name|UINT8
name|Code
decl_stmt|;
comment|///< The code of the ICMP message.
block|}
name|EFI_IP6_ICMP_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_MODE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Set to TRUE after this EFI IPv6 Protocol instance is started.
comment|/// All other fields in this structure are undefined until this field is TRUE.
comment|/// Set to FALSE when the EFI IPv6 Protocol instance is stopped.
comment|///
name|BOOLEAN
name|IsStarted
decl_stmt|;
comment|///
comment|/// The maximum packet size, in bytes, of the packet which the upper layer driver could feed.
comment|///
name|UINT32
name|MaxPacketSize
decl_stmt|;
comment|///
comment|/// Current configuration settings. Undefined until IsStarted is TRUE.
comment|///
name|EFI_IP6_CONFIG_DATA
name|ConfigData
decl_stmt|;
comment|///
comment|/// Set to TRUE when the EFI IPv6 Protocol instance is configured.
comment|/// The instance is configured when it has a station address and
comment|/// corresponding prefix length.
comment|/// Set to FALSE when the EFI IPv6 Protocol instance is not configured.
comment|///
name|BOOLEAN
name|IsConfigured
decl_stmt|;
comment|///
comment|/// Number of configured IPv6 addresses on this interface.
comment|///
name|UINT32
name|AddressCount
decl_stmt|;
comment|///
comment|/// List of currently configured IPv6 addresses and corresponding
comment|/// prefix lengths assigned to this interface. It is caller's
comment|/// responsibility to free this buffer.
comment|///
name|EFI_IP6_ADDRESS_INFO
modifier|*
name|AddressList
decl_stmt|;
comment|///
comment|/// Number of joined multicast groups. Undefined until
comment|/// IsConfigured is TRUE.
comment|///
name|UINT32
name|GroupCount
decl_stmt|;
comment|///
comment|/// List of joined multicast group addresses. It is caller's
comment|/// responsibility to free this buffer. Undefined until
comment|/// IsConfigured is TRUE.
comment|///
name|EFI_IPv6_ADDRESS
modifier|*
name|GroupTable
decl_stmt|;
comment|///
comment|/// Number of entries in the routing table. Undefined until
comment|/// IsConfigured is TRUE.
comment|///
name|UINT32
name|RouteCount
decl_stmt|;
comment|///
comment|/// Routing table entries. It is caller's responsibility to free this buffer.
comment|///
name|EFI_IP6_ROUTE_TABLE
modifier|*
name|RouteTable
decl_stmt|;
comment|///
comment|/// Number of entries in the neighbor cache. Undefined until
comment|/// IsConfigured is TRUE.
comment|///
name|UINT32
name|NeighborCount
decl_stmt|;
comment|///
comment|/// Neighbor cache entries. It is caller's responsibility to free this
comment|/// buffer. Undefined until IsConfigured is TRUE.
comment|///
name|EFI_IP6_NEIGHBOR_CACHE
modifier|*
name|NeighborCache
decl_stmt|;
comment|///
comment|/// Number of entries in the prefix table. Undefined until
comment|/// IsConfigured is TRUE.
comment|///
name|UINT32
name|PrefixCount
decl_stmt|;
comment|///
comment|/// On-link Prefix table entries. It is caller's responsibility to free this
comment|/// buffer. Undefined until IsConfigured is TRUE.
comment|///
name|EFI_IP6_ADDRESS_INFO
modifier|*
name|PrefixTable
decl_stmt|;
comment|///
comment|/// Number of entries in the supported ICMP types list.
comment|///
name|UINT32
name|IcmpTypeCount
decl_stmt|;
comment|///
comment|/// Array of ICMP types and codes that are supported by this EFI
comment|/// IPv6 Protocol driver. It is caller's responsibility to free this
comment|/// buffer.
comment|///
name|EFI_IP6_ICMP_TYPE
modifier|*
name|IcmpTypeList
decl_stmt|;
block|}
name|EFI_IP6_MODE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_HEADER
end_comment

begin_comment
comment|/// The fields in the IPv6 header structure are defined in the Internet
end_comment

begin_comment
comment|/// Protocol version6 specification.
end_comment

begin_comment
comment|///
end_comment

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
name|_EFI_IP6_HEADER
block|{
name|UINT8
name|TrafficClassH
range|:
literal|4
decl_stmt|;
name|UINT8
name|Version
range|:
literal|4
decl_stmt|;
name|UINT8
name|FlowLabelH
range|:
literal|4
decl_stmt|;
name|UINT8
name|TrafficClassL
range|:
literal|4
decl_stmt|;
name|UINT16
name|FlowLabelL
decl_stmt|;
name|UINT16
name|PayloadLength
decl_stmt|;
name|UINT8
name|NextHeader
decl_stmt|;
name|UINT8
name|HopLimit
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|SourceAddress
decl_stmt|;
name|EFI_IPv6_ADDRESS
name|DestinationAddress
decl_stmt|;
block|}
name|EFI_IP6_HEADER
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
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_FRAGMENT_DATA
end_comment

begin_comment
comment|/// describes the location and length of the IPv6 packet
end_comment

begin_comment
comment|/// fragment to transmit or that has been received.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IP6_FRAGMENT_DATA
block|{
name|UINT32
name|FragmentLength
decl_stmt|;
comment|///< Length of fragment data. This field may not be set to zero.
name|VOID
modifier|*
name|FragmentBuffer
decl_stmt|;
comment|///< Pointer to fragment data. This field may not be set to NULL.
block|}
name|EFI_IP6_FRAGMENT_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_RECEIVE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IP6_RECEIVE_DATA
block|{
comment|///
comment|/// Time when the EFI IPv6 Protocol driver accepted the packet.
comment|/// Ignored if it is zero.
comment|///
name|EFI_TIME
name|TimeStamp
decl_stmt|;
comment|///
comment|/// After this event is signaled, the receive data structure is released
comment|/// and must not be referenced.
comment|///
name|EFI_EVENT
name|RecycleSignal
decl_stmt|;
comment|///
comment|///Length of the IPv6 packet headers, including both the IPv6
comment|///header and any extension headers.
comment|///
name|UINT32
name|HeaderLength
decl_stmt|;
comment|///
comment|/// Pointer to the IPv6 packet header. If the IPv6 packet was
comment|/// fragmented, this argument is a pointer to the header in the first
comment|/// fragment.
comment|///
name|EFI_IP6_HEADER
modifier|*
name|Header
decl_stmt|;
comment|///
comment|/// Sum of the lengths of IPv6 packet buffers in FragmentTable. May
comment|/// be zero.
comment|///
name|UINT32
name|DataLength
decl_stmt|;
comment|///
comment|/// Number of IPv6 payload fragments. May be zero.
comment|///
name|UINT32
name|FragmentCount
decl_stmt|;
comment|///
comment|/// Array of payload fragment lengths and buffer pointers.
comment|///
name|EFI_IP6_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IP6_RECEIVE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_OVERRIDE_DATA
end_comment

begin_comment
comment|/// The information and flags in the override data structure will override
end_comment

begin_comment
comment|/// default parameters or settings for one Transmit() function call.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IP6_OVERRIDE_DATA
block|{
name|UINT8
name|Protocol
decl_stmt|;
comment|///< Protocol type override.
name|UINT8
name|HopLimit
decl_stmt|;
comment|///< Hop-Limit override.
name|UINT32
name|FlowLabel
decl_stmt|;
comment|///< Flow-Label override.
block|}
name|EFI_IP6_OVERRIDE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_TRANSMIT_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IP6_TRANSMIT_DATA
block|{
comment|///
comment|/// The destination IPv6 address.  If it is unspecified,
comment|/// ConfigData.DestinationAddress will be used instead.
comment|///
name|EFI_IPv6_ADDRESS
name|DestinationAddress
decl_stmt|;
comment|///
comment|/// If not NULL, the IPv6 transmission control override data.
comment|///
name|EFI_IP6_OVERRIDE_DATA
modifier|*
name|OverrideData
decl_stmt|;
comment|///
comment|/// Total length in byte of the IPv6 extension headers specified in
comment|/// ExtHdrs.
comment|///
name|UINT32
name|ExtHdrsLength
decl_stmt|;
comment|///
comment|/// Pointer to the IPv6 extension headers. The IP layer will append
comment|/// the required extension headers if they are not specified by
comment|/// ExtHdrs. Ignored if ExtHdrsLength is zero.
comment|///
name|VOID
modifier|*
name|ExtHdrs
decl_stmt|;
comment|///
comment|/// The protocol of first extension header in ExtHdrs. Ignored if
comment|/// ExtHdrsLength is zero.
comment|///
name|UINT8
name|NextHeader
decl_stmt|;
comment|///
comment|/// Total length in bytes of the FragmentTable data to transmit.
comment|///
name|UINT32
name|DataLength
decl_stmt|;
comment|///
comment|/// Number of entries in the fragment data table.
comment|///
name|UINT32
name|FragmentCount
decl_stmt|;
comment|///
comment|/// Start of the fragment data table.
comment|///
name|EFI_IP6_FRAGMENT_DATA
name|FragmentTable
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IP6_TRANSMIT_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IP6_COMPLETION_TOKEN
end_comment

begin_comment
comment|/// structures are used for both transmit and receive operations.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This Event will be signaled after the Status field is updated by
comment|/// the EFI IPv6 Protocol driver. The type of Event must be EFI_NOTIFY_SIGNAL.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Will be set to one of the following values:
comment|/// - EFI_SUCCESS:  The receive or transmit completed
comment|///   successfully.
comment|/// - EFI_ABORTED:  The receive or transmit was aborted
comment|/// - EFI_TIMEOUT:  The transmit timeout expired.
comment|/// - EFI_ICMP_ERROR:  An ICMP error packet was received.
comment|/// - EFI_DEVICE_ERROR:  An unexpected system or network
comment|///   error occurred.
comment|/// - EFI_SECURITY_VIOLATION: The transmit or receive was
comment|///   failed because of an IPsec policy check.
comment|/// - EFI_NO_MEDIA: There was a media error.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
union|union
block|{
comment|///
comment|/// When the Token is used for receiving, RxData is a pointer to the EFI_IP6_RECEIVE_DATA.
comment|///
name|EFI_IP6_RECEIVE_DATA
modifier|*
name|RxData
decl_stmt|;
comment|///
comment|/// When the Token is used for transmitting, TxData is a pointer to the EFI_IP6_TRANSMIT_DATA.
comment|///
name|EFI_IP6_TRANSMIT_DATA
modifier|*
name|TxData
decl_stmt|;
block|}
name|Packet
union|;
block|}
name|EFI_IP6_COMPLETION_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Gets the current operational settings for this instance of the EFI IPv6 Protocol driver.    The GetModeData() function returns the current operational mode data for this driver instance.   The data fields in EFI_IP6_MODE_DATA are read only. This function is used optionally to   retrieve the operational mode data of underlying networks or drivers..    @param[in]  This               Pointer to the EFI_IP6_PROTOCOL instance.   @param[out] Ip6ModeData        Pointer to the EFI IPv6 Protocol mode data structure.   @param[out] MnpConfigData      Pointer to the managed network configuration data structure.   @param[out] SnpModeData        Pointer to the simple network mode data structure.    @retval EFI_SUCCESS            The operation completed successfully.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_OUT_OF_RESOURCES   The required mode data could not be allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_PROTOCOL
modifier|*
name|This
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
comment|/**   Assigns an IPv6 address and subnet mask to this EFI IPv6 Protocol driver instance.    The Configure() function is used to set, change, or reset the operational parameters and filter   settings for this EFI IPv6 Protocol instance. Until these parameters have been set, no network traffic   can be sent or received by this instance. Once the parameters have been reset (by calling this   function with Ip6ConfigData set to NULL), no more traffic can be sent or received until these   parameters have been set again. Each EFI IPv6 Protocol instance can be started and stopped   independently of each other by enabling or disabling their receive filter settings with the   Configure() function.    If Ip6ConfigData.StationAddress is a valid non-zero IPv6 unicast address, it is required   to be one of the currently configured IPv6 addresses list in the EFI IPv6 drivers, or else   EFI_INVALID_PARAMETER will be returned. If Ip6ConfigData.StationAddress is   unspecified, the IPv6 driver will bind a source address according to the source address selection   algorithm. Clients could frequently call GetModeData() to check get currently configured IPv6   address list in the EFI IPv6 driver. If both Ip6ConfigData.StationAddress and   Ip6ConfigData.Destination are unspecified, when transmitting the packet afterwards, the   source address filled in each outgoing IPv6 packet is decided based on the destination of this packet. .    If operational parameters are reset or changed, any pending transmit and receive requests will be   cancelled. Their completion token status will be set to EFI_ABORTED and their events will be   signaled.    @param[in]  This               Pointer to the EFI_IP6_PROTOCOL instance.   @param[in]  Ip6ConfigData      Pointer to the EFI IPv6 Protocol configuration data structure.    @retval EFI_SUCCESS            The driver instance was successfully opened.   @retval EFI_INVALID_PARAMETER  One or more of the following conditions is TRUE:                                  - This is NULL.                                  - Ip6ConfigData.StationAddress is neither zero nor                                    a unicast IPv6 address.                                  - Ip6ConfigData.StationAddress is neither zero nor                                    one of the configured IP addresses in the EFI IPv6 driver.                                  - Ip6ConfigData.DefaultProtocol is illegal.   @retval EFI_OUT_OF_RESOURCES   The EFI IPv6 Protocol driver instance data could not be allocated.   @retval EFI_NO_MAPPING         The IPv6 driver was responsible for choosing a source address for                                  this instance, but no source address was available for use.   @retval EFI_ALREADY_STARTED    The interface is already open and must be stopped before the IPv6                                  address or prefix length can be changed.   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred. The EFI IPv6                                  Protocol driver instance is not opened.   @retval EFI_UNSUPPORTED        Default protocol specified through                                  Ip6ConfigData.DefaulProtocol isn't supported.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP6_CONFIG_DATA
modifier|*
name|Ip6ConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Joins and leaves multicast groups.    The Groups() function is used to join and leave multicast group sessions. Joining a group will   enable reception of matching multicast packets. Leaving a group will disable reception of matching   multicast packets. Source-Specific Multicast isn't required to be supported.    If JoinFlag is FALSE and GroupAddress is NULL, all joined groups will be left.    @param[in]  This               Pointer to the EFI_IP6_PROTOCOL instance.   @param[in]  JoinFlag           Set to TRUE to join the multicast group session and FALSE to leave.   @param[in]  GroupAddress       Pointer to the IPv6 multicast address.    @retval EFI_SUCCESS            The operation completed successfully.   @retval EFI_INVALID_PARAMETER  One or more of the following is TRUE:                                  - This is NULL.                                  - JoinFlag is TRUE and GroupAddress is NULL.                                  - GroupAddress is not NULL and *GroupAddress is                                    not a multicast IPv6 address.                                  - GroupAddress is not NULL and *GroupAddress is in the                                    range of SSM destination address.   @retval EFI_NOT_STARTED        This instance has not been started.   @retval EFI_OUT_OF_RESOURCES   System resources could not be allocated.   @retval EFI_UNSUPPORTED        This EFI IPv6 Protocol implementation does not support multicast groups.   @retval EFI_ALREADY_STARTED    The group address is already in the group table (when                                  JoinFlag is TRUE).   @retval EFI_NOT_FOUND          The group address is not in the group table (when JoinFlag is FALSE).   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_GROUPS
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_PROTOCOL
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
name|GroupAddress
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Adds and deletes routing table entries.    The Routes() function adds a route to or deletes a route from the routing table.    Routes are determined by comparing the leftmost PrefixLength bits of Destination with   the destination IPv6 address arithmetically. The gateway address must be on the same subnet as the   configured station address.    The default route is added with Destination and PrefixLegth both set to all zeros. The   default route matches all destination IPv6 addresses that do not match any other routes.    All EFI IPv6 Protocol instances share a routing table.    @param[in]  This               Pointer to the EFI_IP6_PROTOCOL instance.   @param[in]  DeleteRoute        Set to TRUE to delete this route from the routing table. Set to                                  FALSE to add this route to the routing table. Destination,                                  PrefixLength and Gateway are used as the key to each                                  route entry.   @param[in]  Destination        The address prefix of the subnet that needs to be routed.   @param[in]  PrefixLength       The prefix length of Destination. Ignored if Destination                                  is NULL.   @param[in]  GatewayAddress     The unicast gateway IPv6 address for this route.    @retval EFI_SUCCESS            The operation completed successfully.   @retval EFI_NOT_STARTED        The driver instance has not been started.   @retval EFI_INVALID_PARAMETER  One or more of the following conditions is TRUE:                                  - This is NULL.                                  - When DeleteRoute is TRUE, both Destination and                                    GatewayAddress are NULL.                                  - When DeleteRoute is FALSE, either Destination or                                    GatewayAddress is NULL.                                  - *GatewayAddress is not a valid unicast IPv6 address.                                  - *GatewayAddress is one of the local configured IPv6                                    addresses.   @retval EFI_OUT_OF_RESOURCES   Could not add the entry to the routing table.   @retval EFI_NOT_FOUND          This route is not in the routing table (when DeleteRoute is TRUE).   @retval EFI_ACCESS_DENIED      The route is already defined in the routing table (when                                  DeleteRoute is FALSE).  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_ROUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|DeleteRoute
parameter_list|,
name|IN
name|EFI_IPv6_ADDRESS
modifier|*
name|Destination
name|OPTIONAL
parameter_list|,
name|IN
name|UINT8
name|PrefixLength
parameter_list|,
name|IN
name|EFI_IPv6_ADDRESS
modifier|*
name|GatewayAddress
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Add or delete Neighbor cache entries.    The Neighbors() function is used to add, update, or delete an entry from neighbor cache.   IPv6 neighbor cache entries are typically inserted and updated by the network protocol driver as   network traffic is processed. Most neighbor cache entries will time out and be deleted if the network   traffic stops. Neighbor cache entries that were inserted by Neighbors() may be static (will not   timeout) or dynamic (will time out).    The implementation should follow the neighbor cache timeout mechanism which is defined in   RFC4861. The default neighbor cache timeout value should be tuned for the expected network   environment    @param[in]  This               Pointer to the EFI_IP6_PROTOCOL instance.   @param[in]  DeleteFlag         Set to TRUE to delete the specified cache entry, set to FALSE to                                  add (or update, if it already exists and Override is TRUE) the                                  specified cache entry. TargetIp6Address is used as the key                                  to find the requested cache entry.   @param[in]  TargetIp6Address   Pointer to Target IPv6 address.   @param[in]  TargetLinkAddress  Pointer to link-layer address of the target. Ignored if NULL.   @param[in]  Timeout            Time in 100-ns units that this entry will remain in the neighbor                                  cache, it will be deleted after Timeout. A value of zero means that                                  the entry is permanent. A non-zero value means that the entry is                                  dynamic.   @param[in]  Override           If TRUE, the cached link-layer address of the matching entry will                                  be overridden and updated; if FALSE, EFI_ACCESS_DENIED                                  will be returned if a corresponding cache entry already existed.    @retval  EFI_SUCCESS           The data has been queued for transmission.   @retval  EFI_NOT_STARTED       This instance has not been started.   @retval  EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                  - This is NULL.                                  - TargetIpAddress is NULL.                                  - *TargetLinkAddress is invalid when not NULL.                                  - *TargetIpAddress is not a valid unicast IPv6 address.                                  - *TargetIpAddress is one of the local configured IPv6                                    addresses.   @retval  EFI_OUT_OF_RESOURCES  Could not add the entry to the neighbor cache.   @retval  EFI_NOT_FOUND         This entry is not in the neighbor cache (when DeleteFlag  is                                  TRUE or when DeleteFlag  is FALSE while                                  TargetLinkAddress is NULL.).   @retval  EFI_ACCESS_DENIED     The to-be-added entry is already defined in the neighbor cache,                                  and that entry is tagged as un-overridden (when DeleteFlag                                  is FALSE).  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_NEIGHBORS
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|DeleteFlag
parameter_list|,
name|IN
name|EFI_IPv6_ADDRESS
modifier|*
name|TargetIp6Address
parameter_list|,
name|IN
name|EFI_MAC_ADDRESS
modifier|*
name|TargetLinkAddress
parameter_list|,
name|IN
name|UINT32
name|Timeout
parameter_list|,
name|IN
name|BOOLEAN
name|Override
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Places outgoing data packets into the transmit queue.    The Transmit() function places a sending request in the transmit queue of this   EFI IPv6 Protocol instance. Whenever the packet in the token is sent out or some   errors occur, the event in the token will be signaled and the status is updated.    @param[in]  This               Pointer to the EFI_IP6_PROTOCOL instance.   @param[in]  Token              Pointer to the transmit token.    @retval  EFI_SUCCESS           The data has been queued for transmission.   @retval  EFI_NOT_STARTED       This instance has not been started.   @retval  EFI_NO_MAPPING        The IPv6 driver was responsible for choosing a source address for                                  this transmission, but no source address was available for use.   @retval  EFI_INVALID_PARAMETER One or more of the following is TRUE:                                  - This is NULL.                                  - Token is NULL.                                  - Token.Event is NULL.                                  - Token.Packet.TxData is NULL.                                  - Token.Packet.ExtHdrsLength is not zero and Token.Packet.ExtHdrs is NULL.                                  - Token.Packet.FragmentCount is zero.                                  - One or more of the Token.Packet.TxData.FragmentTable[].FragmentLength fields is zero.                                  - One or more of the Token.Packet.TxData.FragmentTable[].FragmentBuffer fields is NULL.                                  - Token.Packet.TxData.DataLength is zero or not equal to the sum of fragment lengths.                                  - Token.Packet.TxData.DestinationAddress is non-zero when DestinationAddress is configured as                                    non-zero when doing Configure() for this EFI IPv6 protocol instance.                                  - Token.Packet.TxData.DestinationAddress is unspecified when DestinationAddress is unspecified                                    when doing Configure() for this EFI IPv6 protocol instance.   @retval  EFI_ACCESS_DENIED     The transmit completion token with the same Token.Event                                  was already in the transmit queue.   @retval  EFI_NOT_READY         The completion token could not be queued because the transmit                                  queue is full.   @retval  EFI_NOT_FOUND         Not route is found to destination address.   @retval  EFI_OUT_OF_RESOURCES  Could not queue the transmit data.   @retval  EFI_BUFFER_TOO_SMALL  Token.Packet.TxData.TotalDataLength is too                                  short to transmit.   @retval  EFI_BAD_BUFFER_SIZE   If Token.Packet.TxData.DataLength is beyond the                                  maximum that which can be described through the Fragment Offset                                  field in Fragment header when performing fragmentation.   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_TRANSMIT
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP6_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Places a receiving request into the receiving queue.    The Receive() function places a completion token into the receive packet queue.   This function is always asynchronous.    The Token.Event field in the completion token must be filled in by the caller   and cannot be NULL. When the receive operation completes, the EFI IPv6 Protocol   driver updates the Token.Status and Token.Packet.RxData fields and the Token.Event   is signaled.    @param[in]  This               Pointer to the EFI_IP6_PROTOCOL instance.   @param[in]  Token              Pointer to a token that is associated with the receive data descriptor.    @retval EFI_SUCCESS            The receive completion token was cached.   @retval EFI_NOT_STARTED        This EFI IPv6 Protocol instance has not been started.   @retval EFI_NO_MAPPING         When IP6 driver responsible for binding source address to this instance,                                  while no source address is available for use.   @retval EFI_INVALID_PARAMETER  One or more of the following conditions is TRUE:                                  - This is NULL.                                  - Token is NULL.                                  - Token.Event is NULL.   @retval EFI_OUT_OF_RESOURCES   The receive completion token could not be queued due to a lack of system                                  resources (usually memory).   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.                                  The EFI IPv6 Protocol instance has been reset to startup defaults.   @retval EFI_ACCESS_DENIED      The receive completion token with the same Token.Event was already                                  in the receive queue.   @retval EFI_NOT_READY          The receive request could not be queued because the receive queue is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP6_COMPLETION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Abort an asynchronous transmit or receive request.    The Cancel() function is used to abort a pending transmit or receive request.   If the token is in the transmit or receive request queues, after calling this   function, Token->Status will be set to EFI_ABORTED and then Token->Event will   be signaled. If the token is not in one of the queues, which usually means the   asynchronous operation has completed, this function will not signal the token   and EFI_NOT_FOUND is returned.    @param[in]  This               Pointer to the EFI_IP6_PROTOCOL instance.   @param[in]  Token              Pointer to a token that has been issued by                                  EFI_IP6_PROTOCOL.Transmit() or                                  EFI_IP6_PROTOCOL.Receive(). If NULL, all pending                                  tokens are aborted. Type EFI_IP6_COMPLETION_TOKEN is                                  defined in EFI_IP6_PROTOCOL.Transmit().    @retval EFI_SUCCESS            The asynchronous I/O request was aborted and                                  Token->Event was signaled. When Token is NULL, all                                  pending requests were aborted and their events were signaled.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_NOT_STARTED        This instance has not been started.   @retval EFI_NOT_FOUND          When Token is not NULL, the asynchronous I/O request was                                  not found in the transmit or receive queue. It has either completed                                  or was not issued by Transmit() and Receive().   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_CANCEL
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP6_COMPLETION_TOKEN
modifier|*
name|Token
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Polls for incoming data packets and processes outgoing data packets.    The Poll() function polls for incoming data packets and processes outgoing data   packets. Network drivers and applications can call the EFI_IP6_PROTOCOL.Poll()   function to increase the rate that data packets are moved between the communications   device and the transmit and receive queues.    In some systems the periodic timer event may not poll the underlying communications   device fast enough to transmit and/or receive all data packets without missing   incoming packets or dropping outgoing packets. Drivers and applications that are   experiencing packet loss should try calling the EFI_IP6_PROTOCOL.Poll() function   more often.    @param[in]  This               Pointer to the EFI_IP6_PROTOCOL instance.    @retval  EFI_SUCCESS           Incoming or outgoing data was processed.   @retval  EFI_NOT_STARTED       This EFI IPv6 Protocol instance has not been started.   @retval  EFI_INVALID_PARAMETER This is NULL.   @retval  EFI_DEVICE_ERROR      An unexpected system or network error occurred.   @retval  EFI_NOT_READY         No incoming or outgoing data is processed.   @retval  EFI_TIMEOUT           Data was dropped out of the transmit and/or receive queue.                                  Consider increasing the polling rate.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IP6_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_IP6_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI IPv6 Protocol implements a simple packet-oriented interface that can be
end_comment

begin_comment
comment|/// used by drivers, daemons, and applications to transmit and receive network packets.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_IP6_PROTOCOL
block|{
name|EFI_IP6_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_IP6_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_IP6_GROUPS
name|Groups
decl_stmt|;
name|EFI_IP6_ROUTES
name|Routes
decl_stmt|;
name|EFI_IP6_NEIGHBORS
name|Neighbors
decl_stmt|;
name|EFI_IP6_TRANSMIT
name|Transmit
decl_stmt|;
name|EFI_IP6_RECEIVE
name|Receive
decl_stmt|;
name|EFI_IP6_CANCEL
name|Cancel
decl_stmt|;
name|EFI_IP6_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIp6ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIp6ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

