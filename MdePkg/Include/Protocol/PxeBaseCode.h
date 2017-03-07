begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI PXE Base Code Protocol definitions, which is used to access PXE-compatible    devices for network access and network booting.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.     @par Revision Reference:             This Protocol is introduced in EFI Specification 1.10.             **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PXE_BASE_CODE_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__PXE_BASE_CODE_PROTOCOL_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PXE Base Code protocol.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_PROTOCOL_GUID
define|\
value|{ \     0x03c4e603, 0xac28, 0x11d3, {0x9a, 0x2d, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PXE_BASE_CODE_PROTOCOL
name|EFI_PXE_BASE_CODE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_PXE_BASE_CODE_PROTOCOL
name|EFI_PXE_BASE_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Default IP TTL and ToS.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TTL
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_ToS
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ICMP error format.
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
name|UINT8
name|Code
decl_stmt|;
name|UINT16
name|Checksum
decl_stmt|;
union|union
block|{
name|UINT32
name|reserved
decl_stmt|;
name|UINT32
name|Mtu
decl_stmt|;
name|UINT32
name|Pointer
decl_stmt|;
struct|struct
block|{
name|UINT16
name|Identifier
decl_stmt|;
name|UINT16
name|Sequence
decl_stmt|;
block|}
name|Echo
struct|;
block|}
name|u
union|;
name|UINT8
name|Data
index|[
literal|494
index|]
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_ICMP_ERROR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// TFTP error format.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ErrorCode
decl_stmt|;
name|CHAR8
name|ErrorString
index|[
literal|127
index|]
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_TFTP_ERROR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// IP Receive Filter definitions.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_MAX_IPCNT
value|8
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IP Receive Filter structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Filters
decl_stmt|;
name|UINT8
name|IpCnt
decl_stmt|;
name|UINT16
name|reserved
decl_stmt|;
name|EFI_IP_ADDRESS
name|IpList
index|[
name|EFI_PXE_BASE_CODE_MAX_IPCNT
index|]
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_IP_FILTER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_IP_FILTER_STATION_IP
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_IP_FILTER_BROADCAST
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_IP_FILTER_PROMISCUOUS
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_IP_FILTER_PROMISCUOUS_MULTICAST
value|0x0008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// ARP cache entries.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_IP_ADDRESS
name|IpAddr
decl_stmt|;
name|EFI_MAC_ADDRESS
name|MacAddr
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_ARP_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ARP route table entries.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_IP_ADDRESS
name|IpAddr
decl_stmt|;
name|EFI_IP_ADDRESS
name|SubnetMask
decl_stmt|;
name|EFI_IP_ADDRESS
name|GwAddr
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_ROUTE_ENTRY
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// UDP definitions
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|EFI_PXE_BASE_CODE_UDP_PORT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_UDP_OPFLAGS_ANY_SRC_IP
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_UDP_OPFLAGS_ANY_SRC_PORT
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_UDP_OPFLAGS_ANY_DEST_IP
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_UDP_OPFLAGS_ANY_DEST_PORT
value|0x0008
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_UDP_OPFLAGS_USE_FILTER
value|0x0010
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_UDP_OPFLAGS_MAY_FRAGMENT
value|0x0020
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Discover() definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_BOOTSTRAP
value|0
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_MS_WINNT_RIS
value|1
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_INTEL_LCM
value|2
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_DOSUNDI
value|3
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_NEC_ESMPRO
value|4
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_IBM_WSoD
value|5
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_IBM_LCCM
value|6
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_CA_UNICENTER_TNG
value|7
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_HP_OPENVIEW
value|8
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_ALTIRIS_9
value|9
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_ALTIRIS_10
value|10
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_ALTIRIS_11
value|11
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_NOT_USED_12
value|12
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_REDHAT_INSTALL
value|13
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_REDHAT_BOOT
value|14
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_REMBO
value|15
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_BEOBOOT
value|16
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// 17 through 32767 are reserved
end_comment

begin_comment
comment|// 32768 through 65279 are for vendor use
end_comment

begin_comment
comment|// 65280 through 65534 are reserved
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_TYPE_PXETEST
value|65535
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_LAYER_MASK
value|0x7FFF
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_BOOT_LAYER_INITIAL
value|0x0000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// PXE Tag definition that identifies the processor
end_comment

begin_comment
comment|// and programming environment of the client system.
end_comment

begin_comment
comment|// These identifiers are defined by IETF:
end_comment

begin_comment
comment|// http://www.ietf.org/assignments/dhcpv6-parameters/dhcpv6-parameters.xml
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IA32
argument_list|)
end_if

begin_define
define|#
directive|define
name|EFI_PXE_CLIENT_SYSTEM_ARCHITECTURE
value|0x0006
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_IPF
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_PXE_CLIENT_SYSTEM_ARCHITECTURE
value|0x0002
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_X64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_PXE_CLIENT_SYSTEM_ARCHITECTURE
value|0x0007
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_ARM
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_PXE_CLIENT_SYSTEM_ARCHITECTURE
value|0x000A
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_AARCH64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_PXE_CLIENT_SYSTEM_ARCHITECTURE
value|0x000B
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|///
end_comment

begin_comment
comment|/// Discover() server list structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|BOOLEAN
name|AcceptAnyResponse
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|EFI_IP_ADDRESS
name|IpAddr
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_SRVLIST
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Discover() information override structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|BOOLEAN
name|UseMCast
decl_stmt|;
name|BOOLEAN
name|UseBCast
decl_stmt|;
name|BOOLEAN
name|UseUCast
decl_stmt|;
name|BOOLEAN
name|MustUseList
decl_stmt|;
name|EFI_IP_ADDRESS
name|ServerMCastIp
decl_stmt|;
name|UINT16
name|IpCnt
decl_stmt|;
name|EFI_PXE_BASE_CODE_SRVLIST
name|SrvList
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_DISCOVER_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// TFTP opcode definitions.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EFI_PXE_BASE_CODE_TFTP_FIRST
block|,
name|EFI_PXE_BASE_CODE_TFTP_GET_FILE_SIZE
block|,
name|EFI_PXE_BASE_CODE_TFTP_READ_FILE
block|,
name|EFI_PXE_BASE_CODE_TFTP_WRITE_FILE
block|,
name|EFI_PXE_BASE_CODE_TFTP_READ_DIRECTORY
block|,
name|EFI_PXE_BASE_CODE_MTFTP_GET_FILE_SIZE
block|,
name|EFI_PXE_BASE_CODE_MTFTP_READ_FILE
block|,
name|EFI_PXE_BASE_CODE_MTFTP_READ_DIRECTORY
block|,
name|EFI_PXE_BASE_CODE_MTFTP_LAST
block|}
name|EFI_PXE_BASE_CODE_TFTP_OPCODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MTFTP information. This information is required
end_comment

begin_comment
comment|/// to start or join a multicast TFTP session. It is also required to
end_comment

begin_comment
comment|/// perform the "get file size" and "read directory" operations of MTFTP.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_IP_ADDRESS
name|MCastIp
decl_stmt|;
name|EFI_PXE_BASE_CODE_UDP_PORT
name|CPort
decl_stmt|;
name|EFI_PXE_BASE_CODE_UDP_PORT
name|SPort
decl_stmt|;
name|UINT16
name|ListenTimeout
decl_stmt|;
name|UINT16
name|TransmitTimeout
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_MTFTP_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DHCPV4 Packet structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|BootpOpcode
decl_stmt|;
name|UINT8
name|BootpHwType
decl_stmt|;
name|UINT8
name|BootpHwAddrLen
decl_stmt|;
name|UINT8
name|BootpGateHops
decl_stmt|;
name|UINT32
name|BootpIdent
decl_stmt|;
name|UINT16
name|BootpSeconds
decl_stmt|;
name|UINT16
name|BootpFlags
decl_stmt|;
name|UINT8
name|BootpCiAddr
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|BootpYiAddr
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|BootpSiAddr
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|BootpGiAddr
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|BootpHwAddr
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|BootpSrvName
index|[
literal|64
index|]
decl_stmt|;
name|UINT8
name|BootpBootFile
index|[
literal|128
index|]
decl_stmt|;
name|UINT32
name|DhcpMagik
decl_stmt|;
name|UINT8
name|DhcpOptions
index|[
literal|56
index|]
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_DHCPV4_PACKET
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// DHCPV6 Packet structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|MessageType
range|:
literal|8
decl_stmt|;
name|UINT32
name|TransactionId
range|:
literal|24
decl_stmt|;
name|UINT8
name|DhcpOptions
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_DHCPV6_PACKET
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Packet structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|UINT8
name|Raw
index|[
literal|1472
index|]
decl_stmt|;
name|EFI_PXE_BASE_CODE_DHCPV4_PACKET
name|Dhcpv4
decl_stmt|;
name|EFI_PXE_BASE_CODE_DHCPV6_PACKET
name|Dhcpv6
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_PACKET
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// PXE Base Code Mode structure
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_MAX_ARP_ENTRIES
value|8
end_define

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_MAX_ROUTE_ENTRIES
value|8
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PXE_BASE_CODE_MODE.
end_comment

begin_comment
comment|/// The data values in this structure are read-only and
end_comment

begin_comment
comment|/// are updated by the code that produces the
end_comment

begin_comment
comment|/// EFI_PXE_BASE_CODE_PROTOCOL functions.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|BOOLEAN
name|Started
decl_stmt|;
name|BOOLEAN
name|Ipv6Available
decl_stmt|;
name|BOOLEAN
name|Ipv6Supported
decl_stmt|;
name|BOOLEAN
name|UsingIpv6
decl_stmt|;
name|BOOLEAN
name|BisSupported
decl_stmt|;
name|BOOLEAN
name|BisDetected
decl_stmt|;
name|BOOLEAN
name|AutoArp
decl_stmt|;
name|BOOLEAN
name|SendGUID
decl_stmt|;
name|BOOLEAN
name|DhcpDiscoverValid
decl_stmt|;
name|BOOLEAN
name|DhcpAckReceived
decl_stmt|;
name|BOOLEAN
name|ProxyOfferReceived
decl_stmt|;
name|BOOLEAN
name|PxeDiscoverValid
decl_stmt|;
name|BOOLEAN
name|PxeReplyReceived
decl_stmt|;
name|BOOLEAN
name|PxeBisReplyReceived
decl_stmt|;
name|BOOLEAN
name|IcmpErrorReceived
decl_stmt|;
name|BOOLEAN
name|TftpErrorReceived
decl_stmt|;
name|BOOLEAN
name|MakeCallbacks
decl_stmt|;
name|UINT8
name|TTL
decl_stmt|;
name|UINT8
name|ToS
decl_stmt|;
name|EFI_IP_ADDRESS
name|StationIp
decl_stmt|;
name|EFI_IP_ADDRESS
name|SubnetMask
decl_stmt|;
name|EFI_PXE_BASE_CODE_PACKET
name|DhcpDiscover
decl_stmt|;
name|EFI_PXE_BASE_CODE_PACKET
name|DhcpAck
decl_stmt|;
name|EFI_PXE_BASE_CODE_PACKET
name|ProxyOffer
decl_stmt|;
name|EFI_PXE_BASE_CODE_PACKET
name|PxeDiscover
decl_stmt|;
name|EFI_PXE_BASE_CODE_PACKET
name|PxeReply
decl_stmt|;
name|EFI_PXE_BASE_CODE_PACKET
name|PxeBisReply
decl_stmt|;
name|EFI_PXE_BASE_CODE_IP_FILTER
name|IpFilter
decl_stmt|;
name|UINT32
name|ArpCacheEntries
decl_stmt|;
name|EFI_PXE_BASE_CODE_ARP_ENTRY
name|ArpCache
index|[
name|EFI_PXE_BASE_CODE_MAX_ARP_ENTRIES
index|]
decl_stmt|;
name|UINT32
name|RouteTableEntries
decl_stmt|;
name|EFI_PXE_BASE_CODE_ROUTE_ENTRY
name|RouteTable
index|[
name|EFI_PXE_BASE_CODE_MAX_ROUTE_ENTRIES
index|]
decl_stmt|;
name|EFI_PXE_BASE_CODE_ICMP_ERROR
name|IcmpError
decl_stmt|;
name|EFI_PXE_BASE_CODE_TFTP_ERROR
name|TftpError
decl_stmt|;
block|}
name|EFI_PXE_BASE_CODE_MODE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// PXE Base Code Interface Function definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**                                                                    Enables the use of the PXE Base Code Protocol functions.    This function enables the use of the PXE Base Code Protocol functions. If the   Started field of the EFI_PXE_BASE_CODE_MODE structure is already TRUE, then   EFI_ALREADY_STARTED will be returned. If UseIpv6 is TRUE, then IPv6 formatted   addresses will be used in this session. If UseIpv6 is FALSE, then IPv4 formatted   addresses will be used in this session. If UseIpv6 is TRUE, and the Ipv6Supported   field of the EFI_PXE_BASE_CODE_MODE structure is FALSE, then EFI_UNSUPPORTED will   be returned. If there is not enough memory or other resources to start the PXE   Base Code Protocol, then EFI_OUT_OF_RESOURCES will be returned. Otherwise, the   PXE Base Code Protocol will be started, and all of the fields of the EFI_PXE_BASE_CODE_MODE   structure will be initialized as follows:     StartedSet to TRUE.     Ipv6SupportedUnchanged.     Ipv6AvailableUnchanged.     UsingIpv6Set to UseIpv6.     BisSupportedUnchanged.     BisDetectedUnchanged.     AutoArpSet to TRUE.     SendGUIDSet to FALSE.     TTLSet to DEFAULT_TTL.     ToSSet to DEFAULT_ToS.     DhcpCompletedSet to FALSE.     ProxyOfferReceivedSet to FALSE.     StationIpSet to an address of all zeros.     SubnetMaskSet to a subnet mask of all zeros.     DhcpDiscoverZero-filled.     DhcpAckZero-filled.     ProxyOfferZero-filled.     PxeDiscoverValidSet to FALSE.     PxeDiscoverZero-filled.     PxeReplyValidSet to FALSE.     PxeReplyZero-filled.     PxeBisReplyValidSet to FALSE.     PxeBisReplyZero-filled.     IpFilterSet the Filters field to 0 and the IpCnt field to 0.     ArpCacheEntriesSet to 0.     ArpCacheZero-filled.     RouteTableEntriesSet to 0.     RouteTableZero-filled.     IcmpErrorReceivedSet to FALSE.     IcmpErrorZero-filled.     TftpErroReceivedSet to FALSE.     TftpErrorZero-filled.     MakeCallbacksSet to TRUE if the PXE Base Code Callback Protocol is available.     Set to FALSE if the PXE Base Code Callback Protocol is not available.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  UseIpv6               Specifies the type of IP addresses that are to be used during the session                                 that is being started. Set to TRUE for IPv6 addresses, and FALSE for                                      IPv4 addresses.                                                                                                                                       @retval EFI_SUCCESS           The PXE Base Code Protocol was started.   @retval EFI_DEVICE_ERROR      The network device encountered an error during this oper     @retval EFI_UNSUPPORTED       UseIpv6 is TRUE, but the Ipv6Supported field of the                                 EFI_PXE_BASE_CODE_MODE structure is FALSE.     @retval EFI_ALREADY_STARTED   The PXE Base Code Protocol is already in the started state.                                      @retval EFI_INVALID_PARAMETER The This parameter is NULL or does not point to a valid                                 EFI_PXE_BASE_CODE_PROTOCOL structure.         @retval EFI_OUT_OF_RESOURCES  Could not allocate enough memory or other resources to start the                                                                           PXE Base Code Protocol.                                                                                **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_START
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|UseIpv6
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Disables the use of the PXE Base Code Protocol functions.    This function stops all activity on the network device. All the resources allocated   in Start() are released, the Started field of the EFI_PXE_BASE_CODE_MODE structure is   set to FALSE and EFI_SUCCESS is returned. If the Started field of the EFI_PXE_BASE_CODE_MODE   structure is already FALSE, then EFI_NOT_STARTED will be returned.      @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.     @retval EFI_SUCCESS           The PXE Base Code Protocol was stopped.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is already in the stopped state.     @retval EFI_INVALID_PARAMETER The This parameter is NULL or does not point to a valid                                 EFI_PXE_BASE_CODE_PROTOCOL structure.                     @retval EFI_DEVICE_ERROR      The network device encountered an error during this operation.                                                                       **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_STOP
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Attempts to complete a DHCPv4 D.O.R.A. (discover / offer / request / acknowledge) or DHCPv6   S.A.R.R (solicit / advertise / request / reply) sequence.    This function attempts to complete the DHCP sequence. If this sequence is completed,   then EFI_SUCCESS is returned, and the DhcpCompleted, ProxyOfferReceived, StationIp,   SubnetMask, DhcpDiscover, DhcpAck, and ProxyOffer fields of the EFI_PXE_BASE_CODE_MODE   structure are filled in.   If SortOffers is TRUE, then the cached DHCP offer packets will be sorted before   they are tried. If SortOffers is FALSE, then the cached DHCP offer packets will   be tried in the order in which they are received. Please see the Preboot Execution   Environment (PXE) Specification for additional details on the implementation of DHCP.   This function can take at least 31 seconds to timeout and return control to the   caller. If the DHCP sequence does not complete, then EFI_TIMEOUT will be returned.   If the Callback Protocol does not return EFI_PXE_BASE_CODE_CALLBACK_STATUS_CONTINUE,   then the DHCP sequence will be stopped and EFI_ABORTED will be returned.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  SortOffers            TRUE if the offers received should be sorted. Set to FALSE to try the                                 offers in the order that they are received.                               @retval EFI_SUCCESS           Valid DHCP has completed.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER The This parameter is NULL or does not point to a valid                                 EFI_PXE_BASE_CODE_PROTOCOL structure.                     @retval EFI_DEVICE_ERROR      The network device encountered an error during this operation.                                   @retval EFI_OUT_OF_RESOURCES  Could not allocate enough memory to complete the DHCP Protocol.   @retval EFI_ABORTED           The callback function aborted the DHCP Protocol.   @retval EFI_TIMEOUT           The DHCP Protocol timed out.   @retval EFI_ICMP_ERROR        An ICMP error packet was received during the DHCP session.   @retval EFI_NO_RESPONSE       Valid PXE offer was not received.                                       **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_DHCP
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|SortOffers
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Attempts to complete the PXE Boot Server and/or boot image discovery sequence.    This function attempts to complete the PXE Boot Server and/or boot image discovery   sequence. If this sequence is completed, then EFI_SUCCESS is returned, and the   PxeDiscoverValid, PxeDiscover, PxeReplyReceived, and PxeReply fields of the   EFI_PXE_BASE_CODE_MODE structure are filled in. If UseBis is TRUE, then the   PxeBisReplyReceived and PxeBisReply fields of the EFI_PXE_BASE_CODE_MODE structure   will also be filled in. If UseBis is FALSE, then PxeBisReplyValid will be set to FALSE.   In the structure referenced by parameter Info, the PXE Boot Server list, SrvList[],   has two uses: It is the Boot Server IP address list used for unicast discovery   (if the UseUCast field is TRUE), and it is the list used for Boot Server verification   (if the MustUseList field is TRUE). Also, if the MustUseList field in that structure   is TRUE and the AcceptAnyResponse field in the SrvList[] array is TRUE, any Boot   Server reply of that type will be accepted. If the AcceptAnyResponse field is   FALSE, only responses from Boot Servers with matching IP addresses will be accepted.   This function can take at least 10 seconds to timeout and return control to the   caller. If the Discovery sequence does not complete, then EFI_TIMEOUT will be   returned. Please see the Preboot Execution Environment (PXE) Specification for   additional details on the implementation of the Discovery sequence.   If the Callback Protocol does not return EFI_PXE_BASE_CODE_CALLBACK_STATUS_CONTINUE,   then the Discovery sequence is stopped and EFI_ABORTED will be returned.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  Type                  The type of bootstrap to perform.   @param  Layer                 The pointer to the boot server layer number to discover, which must be                                 PXE_BOOT_LAYER_INITIAL when a new server type is being                                             discovered.                                                          @param  UseBis                TRUE if Boot Integrity Services are to be used. FALSE otherwise.                                   @param  Info                  The pointer to a data structure that contains additional information on the                                 type of discovery operation that is to be performed.                                                         @retval EFI_SUCCESS           The Discovery sequence has been completed.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                   @retval EFI_DEVICE_ERROR      The network device encountered an error during this operation.                                   @retval EFI_OUT_OF_RESOURCES  Could not allocate enough memory to complete Discovery.   @retval EFI_ABORTED           The callback function aborted the Discovery sequence.   @retval EFI_TIMEOUT           The Discovery sequence timed out.   @retval EFI_ICMP_ERROR        An ICMP error packet was received during the PXE discovery                                 session.                                                                                           **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_DISCOVER
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|Type
parameter_list|,
name|IN
name|UINT16
modifier|*
name|Layer
parameter_list|,
name|IN
name|BOOLEAN
name|UseBis
parameter_list|,
name|IN
name|EFI_PXE_BASE_CODE_DISCOVER_INFO
modifier|*
name|Info
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Used to perform TFTP and MTFTP services.    This function is used to perform TFTP and MTFTP services. This includes the   TFTP operations to get the size of a file, read a directory, read a file, and   write a file. It also includes the MTFTP operations to get the size of a file,   read a directory, and read a file. The type of operation is specified by Operation.   If the callback function that is invoked during the TFTP/MTFTP operation does   not return EFI_PXE_BASE_CODE_CALLBACK_STATUS_CONTINUE, then EFI_ABORTED will   be returned.   For read operations, the return data will be placed in the buffer specified by   BufferPtr. If BufferSize is too small to contain the entire downloaded file,   then EFI_BUFFER_TOO_SMALL will be returned and BufferSize will be set to zero   or the size of the requested file (the size of the requested file is only returned   if the TFTP server supports TFTP options). If BufferSize is large enough for the   read operation, then BufferSize will be set to the size of the downloaded file,   and EFI_SUCCESS will be returned. Applications using the PxeBc.Mtftp() services   should use the get-file-size operations to determine the size of the downloaded   file prior to using the read-file operations--especially when downloading large   (greater than 64 MB) files--instead of making two calls to the read-file operation.   Following this recommendation will save time if the file is larger than expected   and the TFTP server does not support TFTP option extensions. Without TFTP option   extension support, the client has to download the entire file, counting and discarding   the received packets, to determine the file size.   For write operations, the data to be sent is in the buffer specified by BufferPtr.   BufferSize specifies the number of bytes to send. If the write operation completes   successfully, then EFI_SUCCESS will be returned.   For TFTP "get file size" operations, the size of the requested file or directory   is returned in BufferSize, and EFI_SUCCESS will be returned. If the TFTP server   does not support options, the file will be downloaded into a bit bucket and the   length of the downloaded file will be returned. For MTFTP "get file size" operations,   if the MTFTP server does not support the "get file size" option, EFI_UNSUPPORTED   will be returned.   This function can take up to 10 seconds to timeout and return control to the caller.   If the TFTP sequence does not complete, EFI_TIMEOUT will be returned.   If the Callback Protocol does not return EFI_PXE_BASE_CODE_CALLBACK_STATUS_CONTINUE,   then the TFTP sequence is stopped and EFI_ABORTED will be returned.   The format of the data returned from a TFTP read directory operation is a null-terminated   filename followed by a null-terminated information string, of the form   "size year-month-day hour:minute:second" (i.e. %d %d-%d-%d %d:%d:%f - note that   the seconds field can be a decimal number), where the date and time are UTC. For   an MTFTP read directory command, there is additionally a null-terminated multicast   IP address preceding the filename of the form %d.%d.%d.%d for IP v4. The final   entry is itself null-terminated, so that the final information string is terminated   with two null octets.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  Operation             The type of operation to perform.   @param  BufferPtr             A pointer to the data buffer.                                                                        @param  Overwrite             Only used on write file operations. TRUE if a file on a remote server can                                 be overwritten.                                                             @param  BufferSize            For get-file-size operations, *BufferSize returns the size of the                                 requested file.                                                     @param  BlockSize             The requested block size to be used during a TFTP transfer.   @param  ServerIp              The TFTP / MTFTP server IP address.   @param  Filename              A Null-terminated ASCII string that specifies a directory name or a file                                 name.                                                                      @param  Info                  The pointer to the MTFTP information.   @param  DontUseBuffer         Set to FALSE for normal TFTP and MTFTP read file operation.                                                             @retval EFI_SUCCESS           The TFTP/MTFTP operation was completed.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                   @retval EFI_DEVICE_ERROR      The network device encountered an error during this operation.                                   @retval EFI_BUFFER_TOO_SMALL  The buffer is not large enough to complete the read operation.      @retval EFI_ABORTED           The callback function aborted the TFTP/MTFTP operation.   @retval EFI_TIMEOUT           The TFTP/MTFTP operation timed out.   @retval EFI_ICMP_ERROR        An ICMP error packet was received during the MTFTP session.   @retval EFI_TFTP_ERROR        A TFTP error packet was received during the MTFTP session.                                                                        **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_MTFTP
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PXE_BASE_CODE_TFTP_OPCODE
name|Operation
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|BufferPtr
name|OPTIONAL
parameter_list|,
name|IN
name|BOOLEAN
name|Overwrite
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|UINTN
modifier|*
name|BlockSize
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_IP_ADDRESS
modifier|*
name|ServerIp
parameter_list|,
name|IN
name|UINT8
modifier|*
name|Filename
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_PXE_BASE_CODE_MTFTP_INFO
modifier|*
name|Info
name|OPTIONAL
parameter_list|,
name|IN
name|BOOLEAN
name|DontUseBuffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Writes a UDP packet to the network interface.    This function writes a UDP packet specified by the (optional HeaderPtr and)   BufferPtr parameters to the network interface. The UDP header is automatically   built by this routine. It uses the parameters OpFlags, DestIp, DestPort, GatewayIp,   SrcIp, and SrcPort to build this header. If the packet is successfully built and   transmitted through the network interface, then EFI_SUCCESS will be returned.   If a timeout occurs during the transmission of the packet, then EFI_TIMEOUT will   be returned. If an ICMP error occurs during the transmission of the packet, then   the IcmpErrorReceived field is set to TRUE, the IcmpError field is filled in and   EFI_ICMP_ERROR will be returned. If the Callback Protocol does not return   EFI_PXE_BASE_CODE_CALLBACK_STATUS_CONTINUE, then EFI_ABORTED will be returned.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  OpFlags               The UDP operation flags.    @param  DestIp                The destination IP address.   @param  DestPort              The destination UDP port number.                                                                            @param  GatewayIp             The gateway IP address.                                                    @param  SrcIp                 The source IP address.   @param  SrcPort               The source UDP port number.   @param  HeaderSize            An optional field which may be set to the length of a header at                                 HeaderPtr to be prefixed to the data at BufferPtr.                @param  HeaderPtr             If HeaderSize is not NULL, a pointer to a header to be prefixed to the                                 data at BufferPtr.                                                       @param  BufferSize            A pointer to the size of the data at BufferPtr.   @param  BufferPtr             A pointer to the data to be written.                                      @retval EFI_SUCCESS           The UDP Write operation was completed.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                   @retval EFI_BAD_BUFFER_SIZE   The buffer is too long to be transmitted.     @retval EFI_ABORTED           The callback function aborted the UDP Write operation.   @retval EFI_TIMEOUT           The UDP Write operation timed out.   @retval EFI_ICMP_ERROR        An ICMP error packet was received during the UDP write session.                                                                          **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_UDP_WRITE
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|OpFlags
parameter_list|,
name|IN
name|EFI_IP_ADDRESS
modifier|*
name|DestIp
parameter_list|,
name|IN
name|EFI_PXE_BASE_CODE_UDP_PORT
modifier|*
name|DestPort
parameter_list|,
name|IN
name|EFI_IP_ADDRESS
modifier|*
name|GatewayIp
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_IP_ADDRESS
modifier|*
name|SrcIp
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|EFI_PXE_BASE_CODE_UDP_PORT
modifier|*
name|SrcPort
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
modifier|*
name|HeaderSize
parameter_list|,
name|OPTIONAL
name|IN
name|VOID
modifier|*
name|HeaderPtr
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|BufferPtr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Reads a UDP packet from the network interface.    This function reads a UDP packet from a network interface. The data contents   are returned in (the optional HeaderPtr and) BufferPtr, and the size of the   buffer received is returned in BufferSize. If the input BufferSize is smaller   than the UDP packet received (less optional HeaderSize), it will be set to the   required size, and EFI_BUFFER_TOO_SMALL will be returned. In this case, the   contents of BufferPtr are undefined, and the packet is lost. If a UDP packet is   successfully received, then EFI_SUCCESS will be returned, and the information   from the UDP header will be returned in DestIp, DestPort, SrcIp, and SrcPort if   they are not NULL.   Depending on the values of OpFlags and the DestIp, DestPort, SrcIp, and SrcPort   input values, different types of UDP packet receive filtering will be performed.   The following tables summarize these receive filter operations.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  OpFlags               The UDP operation flags.    @param  DestIp                The destination IP address.   @param  DestPort              The destination UDP port number.   @param  SrcIp                 The source IP address.   @param  SrcPort               The source UDP port number.   @param  HeaderSize            An optional field which may be set to the length of a header at                                 HeaderPtr to be prefixed to the data at BufferPtr.                @param  HeaderPtr             If HeaderSize is not NULL, a pointer to a header to be prefixed to the                                 data at BufferPtr.                                                       @param  BufferSize            A pointer to the size of the data at BufferPtr.   @param  BufferPtr             A pointer to the data to be read.                                      @retval EFI_SUCCESS           The UDP Read operation was completed.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                   @retval EFI_DEVICE_ERROR      The network device encountered an error during this operation.   @retval EFI_BUFFER_TOO_SMALL  The packet is larger than Buffer can hold.   @retval EFI_ABORTED           The callback function aborted the UDP Read operation.   @retval EFI_TIMEOUT           The UDP Read operation timed out.                                                                          **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_UDP_READ
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|OpFlags
parameter_list|,
name|IN
name|OUT
name|EFI_IP_ADDRESS
modifier|*
name|DestIp
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|EFI_PXE_BASE_CODE_UDP_PORT
modifier|*
name|DestPort
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|EFI_IP_ADDRESS
modifier|*
name|SrcIp
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|EFI_PXE_BASE_CODE_UDP_PORT
modifier|*
name|SrcPort
parameter_list|,
name|OPTIONAL
name|IN
name|UINTN
modifier|*
name|HeaderSize
parameter_list|,
name|OPTIONAL
name|IN
name|VOID
modifier|*
name|HeaderPtr
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|BufferPtr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Updates the IP receive filters of a network device and enables software filtering.      The NewFilter field is used to modify the network device's current IP receive   filter settings and to enable a software filter. This function updates the IpFilter   field of the EFI_PXE_BASE_CODE_MODE structure with the contents of NewIpFilter.   The software filter is used when the USE_FILTER in OpFlags is set to UdpRead().   The current hardware filter remains in effect no matter what the settings of OpFlags   are, so that the meaning of ANY_DEST_IP set in OpFlags to UdpRead() is from those   packets whose reception is enabled in hardware - physical NIC address (unicast),   broadcast address, logical address or addresses (multicast), or all (promiscuous).   UdpRead() does not modify the IP filter settings.   Dhcp(), Discover(), and Mtftp() set the IP filter, and return with the IP receive   filter list emptied and the filter set to EFI_PXE_BASE_CODE_IP_FILTER_STATION_IP.   If an application or driver wishes to preserve the IP receive filter settings,   it will have to preserve the IP receive filter settings before these calls, and   use SetIpFilter() to restore them after the calls. If incompatible filtering is   requested (for example, PROMISCUOUS with anything else), or if the device does not   support a requested filter setting and it cannot be accommodated in software   (for example, PROMISCUOUS not supported), EFI_INVALID_PARAMETER will be returned.   The IPlist field is used to enable IPs other than the StationIP. They may be   multicast or unicast. If IPcnt is set as well as EFI_PXE_BASE_CODE_IP_FILTER_STATION_IP,   then both the StationIP and the IPs from the IPlist will be used.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  NewFilter             The pointer to the new set of IP receive filters.      @retval EFI_SUCCESS           The IP receive filter settings were updated.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                                                                                          **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_SET_IP_FILTER
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PXE_BASE_CODE_IP_FILTER
modifier|*
name|NewFilter
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Uses the ARP protocol to resolve a MAC address.      This function uses the ARP protocol to resolve a MAC address. The UsingIpv6 field   of the EFI_PXE_BASE_CODE_MODE structure is used to determine if IPv4 or IPv6   addresses are being used. The IP address specified by IpAddr is used to resolve   a MAC address. If the ARP protocol succeeds in resolving the specified address,   then the ArpCacheEntries and ArpCache fields of the EFI_PXE_BASE_CODE_MODE structure   are updated, and EFI_SUCCESS is returned. If MacAddr is not NULL, the resolved   MAC address is placed there as well.   If the PXE Base Code protocol is in the stopped state, then EFI_NOT_STARTED is   returned. If the ARP protocol encounters a timeout condition while attempting   to resolve an address, then EFI_TIMEOUT is returned. If the Callback Protocol   does not return EFI_PXE_BASE_CODE_CALLBACK_STATUS_CONTINUE, then EFI_ABORTED is   returned.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  IpAddr                The pointer to the IP address that is used to resolve a MAC address.   @param  MacAddr               If not NULL, a pointer to the MAC address that was resolved with the                                 ARP protocol.                                                                                             @retval EFI_SUCCESS           The IP or MAC address was resolved.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                   @retval EFI_DEVICE_ERROR      The network device encountered an error during this operation.     @retval EFI_ABORTED           The callback function aborted the ARP Protocol.   @retval EFI_TIMEOUT           The ARP Protocol encountered a timeout condition.                                                                        **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_ARP
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP_ADDRESS
modifier|*
name|IpAddr
parameter_list|,
name|IN
name|EFI_MAC_ADDRESS
modifier|*
name|MacAddr
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Updates the parameters that affect the operation of the PXE Base Code Protocol.      This function sets parameters that affect the operation of the PXE Base Code Protocol.   The parameter specified by NewAutoArp is used to control the generation of ARP   protocol packets. If NewAutoArp is TRUE, then ARP Protocol packets will be generated   as required by the PXE Base Code Protocol. If NewAutoArp is FALSE, then no ARP   Protocol packets will be generated. In this case, the only mappings that are   available are those stored in the ArpCache of the EFI_PXE_BASE_CODE_MODE structure.   If there are not enough mappings in the ArpCache to perform a PXE Base Code Protocol   service, then the service will fail. This function updates the AutoArp field of   the EFI_PXE_BASE_CODE_MODE structure to NewAutoArp.   The SetParameters() call must be invoked after a Callback Protocol is installed   to enable the use of callbacks.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  NewAutoArp            If not NULL, a pointer to a value that specifies whether to replace the                                 current value of AutoARP.                                                 @param  NewSendGUID           If not NULL, a pointer to a value that specifies whether to replace the                                 current value of SendGUID.                                                @param  NewTTL                If not NULL, a pointer to be used in place of the current value of TTL,                                 the "time to live" field of the IP header.                              @param  NewToS                If not NULL, a pointer to be used in place of the current value of ToS,                                 the "type of service" field of the IP header.                           @param  NewMakeCallback       If not NULL, a pointer to a value that specifies whether to replace the                                 current value of the MakeCallback field of the Mode structure.                                                                                                      @retval EFI_SUCCESS           The new parameters values were updated.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                                                                                          **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_SET_PARAMETERS
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
modifier|*
name|NewAutoArp
parameter_list|,
name|OPTIONAL
name|IN
name|BOOLEAN
modifier|*
name|NewSendGUID
parameter_list|,
name|OPTIONAL
name|IN
name|UINT8
modifier|*
name|NewTTL
parameter_list|,
name|OPTIONAL
name|IN
name|UINT8
modifier|*
name|NewToS
parameter_list|,
name|OPTIONAL
name|IN
name|BOOLEAN
modifier|*
name|NewMakeCallback
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Updates the station IP address and/or subnet mask values of a network device.      This function updates the station IP address and/or subnet mask values of a network   device.   The NewStationIp field is used to modify the network device's current IP address.   If NewStationIP is NULL, then the current IP address will not be modified. Otherwise,   this function updates the StationIp field of the EFI_PXE_BASE_CODE_MODE structure   with NewStationIp.   The NewSubnetMask field is used to modify the network device's current subnet   mask. If NewSubnetMask is NULL, then the current subnet mask will not be modified.   Otherwise, this function updates the SubnetMask field of the EFI_PXE_BASE_CODE_MODE   structure with NewSubnetMask.        @param  This                  The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  NewStationIp          The pointer to the new IP address to be used by the network device.     @param  NewSubnetMask         The pointer to the new subnet mask to be used by the network device.                                                                       @retval EFI_SUCCESS           The new station IP address and/or subnet mask were updated.   @retval EFI_NOT_STARTED       The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                                                                                          **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_SET_STATION_IP
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IP_ADDRESS
modifier|*
name|NewStationIp
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_IP_ADDRESS
modifier|*
name|NewSubnetMask
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Updates the contents of the cached DHCP and Discover packets.      The pointers to the new packets are used to update the contents of the cached   packets in the EFI_PXE_BASE_CODE_MODE structure.        @param  This                   The pointer to the EFI_PXE_BASE_CODE_PROTOCOL instance.   @param  NewDhcpDiscoverValid   The pointer to a value that will replace the current                                  DhcpDiscoverValid field.                           @param  NewDhcpAckReceived     The pointer to a value that will replace the current                                  DhcpAckReceived field.                             @param  NewProxyOfferReceived  The pointer to a value that will replace the current                                  ProxyOfferReceived field.                          @param  NewPxeDiscoverValid    The pointer to a value that will replace the current                                       ProxyOfferReceived field.                          @param  NewPxeReplyReceived    The pointer to a value that will replace the current                                  PxeReplyReceived field.                            @param  NewPxeBisReplyReceived The pointer to a value that will replace the current                                  PxeBisReplyReceived field.                         @param  NewDhcpDiscover        The pointer to the new cached DHCP Discover packet contents.      @param  NewDhcpAck             The pointer to the new cached DHCP Ack packet contents.   @param  NewProxyOffer          The pointer to the new cached Proxy Offer packet contents.   @param  NewPxeDiscover         The pointer to the new cached PXE Discover packet contents.   @param  NewPxeReply            The pointer to the new cached PXE Reply packet contents.   @param  NewPxeBisReply         The pointer to the new cached PXE BIS Reply packet contents.                                       @retval EFI_SUCCESS            The cached packet contents were updated.   @retval EFI_NOT_STARTED        The PXE Base Code Protocol is in the stopped state.   @retval EFI_INVALID_PARAMETER  This is NULL or not point to a valid EFI_PXE_BASE_CODE_PROTOCOL structure.                                                                        **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PXE_BASE_CODE_SET_PACKETS
function_decl|)
parameter_list|(
name|IN
name|EFI_PXE_BASE_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|BOOLEAN
modifier|*
name|NewDhcpDiscoverValid
parameter_list|,
name|OPTIONAL
name|BOOLEAN
modifier|*
name|NewDhcpAckReceived
parameter_list|,
name|OPTIONAL
name|BOOLEAN
modifier|*
name|NewProxyOfferReceived
parameter_list|,
name|OPTIONAL
name|BOOLEAN
modifier|*
name|NewPxeDiscoverValid
parameter_list|,
name|OPTIONAL
name|BOOLEAN
modifier|*
name|NewPxeReplyReceived
parameter_list|,
name|OPTIONAL
name|BOOLEAN
modifier|*
name|NewPxeBisReplyReceived
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_PXE_BASE_CODE_PACKET
modifier|*
name|NewDhcpDiscover
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_PXE_BASE_CODE_PACKET
modifier|*
name|NewDhcpAck
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_PXE_BASE_CODE_PACKET
modifier|*
name|NewProxyOffer
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_PXE_BASE_CODE_PACKET
modifier|*
name|NewPxeDiscover
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_PXE_BASE_CODE_PACKET
modifier|*
name|NewPxeReply
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_PXE_BASE_CODE_PACKET
modifier|*
name|NewPxeBisReply
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// PXE Base Code Protocol structure
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_PROTOCOL_REVISION
value|0x00010000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Revision defined in EFI1.1
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PXE_BASE_CODE_INTERFACE_REVISION
value|EFI_PXE_BASE_CODE_PROTOCOL_REVISION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_PXE_BASE_CODE_PROTOCOL is used to control PXE-compatible devices.
end_comment

begin_comment
comment|/// An EFI_PXE_BASE_CODE_PROTOCOL will be layered on top of an
end_comment

begin_comment
comment|/// EFI_MANAGED_NETWORK_PROTOCOL protocol in order to perform packet level transactions.
end_comment

begin_comment
comment|/// The EFI_PXE_BASE_CODE_PROTOCOL handle also supports the
end_comment

begin_comment
comment|/// EFI_LOAD_FILE_PROTOCOL protocol. This provides a clean way to obtain control from the
end_comment

begin_comment
comment|/// boot manager if the boot path is from the remote device.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PXE_BASE_CODE_PROTOCOL
block|{
comment|///
comment|///  The revision of the EFI_PXE_BASE_CODE_PROTOCOL. All future revisions must
comment|///  be backwards compatible. If a future version is not backwards compatible
comment|///  it is not the same GUID.
comment|///
name|UINT64
name|Revision
decl_stmt|;
name|EFI_PXE_BASE_CODE_START
name|Start
decl_stmt|;
name|EFI_PXE_BASE_CODE_STOP
name|Stop
decl_stmt|;
name|EFI_PXE_BASE_CODE_DHCP
name|Dhcp
decl_stmt|;
name|EFI_PXE_BASE_CODE_DISCOVER
name|Discover
decl_stmt|;
name|EFI_PXE_BASE_CODE_MTFTP
name|Mtftp
decl_stmt|;
name|EFI_PXE_BASE_CODE_UDP_WRITE
name|UdpWrite
decl_stmt|;
name|EFI_PXE_BASE_CODE_UDP_READ
name|UdpRead
decl_stmt|;
name|EFI_PXE_BASE_CODE_SET_IP_FILTER
name|SetIpFilter
decl_stmt|;
name|EFI_PXE_BASE_CODE_ARP
name|Arp
decl_stmt|;
name|EFI_PXE_BASE_CODE_SET_PARAMETERS
name|SetParameters
decl_stmt|;
name|EFI_PXE_BASE_CODE_SET_STATION_IP
name|SetStationIp
decl_stmt|;
name|EFI_PXE_BASE_CODE_SET_PACKETS
name|SetPackets
decl_stmt|;
comment|///
comment|/// The pointer to the EFI_PXE_BASE_CODE_MODE data for this device.
comment|///
name|EFI_PXE_BASE_CODE_MODE
modifier|*
name|Mode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPxeBaseCodeProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

