begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file contains the DHCPv4 and DHCPv6 option definitions and other configuration.   They are used to carry additional information and parameters in DHCP messages.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DHCP_H_
end_ifndef

begin_define
define|#
directive|define
name|_DHCP_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Dynamic Host Configuration Protocol for IPv4 (DHCPv4)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Dhcpv4 Options, definitions from RFC 2132
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_PAD
value|0
end_define

begin_comment
comment|/// Pad Option
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_EOP
value|255
end_define

begin_comment
comment|/// End Option
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NETMASK
value|1
end_define

begin_comment
comment|/// Subnet Mask
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_TIME_OFFSET
value|2
end_define

begin_comment
comment|/// Time Offset from UTC
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_ROUTER
value|3
end_define

begin_comment
comment|/// Router option,
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_TIME_SERVER
value|4
end_define

begin_comment
comment|/// Time Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NAME_SERVER
value|5
end_define

begin_comment
comment|/// Name Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_DNS_SERVER
value|6
end_define

begin_comment
comment|/// Domain Name Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_LOG_SERVER
value|7
end_define

begin_comment
comment|/// Log Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_COOKIE_SERVER
value|8
end_define

begin_comment
comment|/// Cookie Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_LPR_SERVER
value|9
end_define

begin_comment
comment|/// LPR Print Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_IMPRESS_SERVER
value|10
end_define

begin_comment
comment|/// Impress Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_RL_SERVER
value|11
end_define

begin_comment
comment|/// Resource Location Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_HOSTNAME
value|12
end_define

begin_comment
comment|/// Host Name
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_BOOTFILE_LEN
value|13
end_define

begin_comment
comment|/// Boot File Size
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_DUMP
value|14
end_define

begin_comment
comment|/// Merit Dump File
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_DOMAINNAME
value|15
end_define

begin_comment
comment|/// Domain Name
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_SWAP_SERVER
value|16
end_define

begin_comment
comment|/// Swap Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_ROOTPATH
value|17
end_define

begin_comment
comment|/// Root path
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_EXTEND_PATH
value|18
end_define

begin_comment
comment|/// Extensions Path
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_IPFORWARD
value|19
end_define

begin_comment
comment|/// IP Forwarding Enable/Disable
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NONLOCAL_SRR
value|20
end_define

begin_comment
comment|/// on-Local Source Routing Enable/Disable
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_POLICY_SRR
value|21
end_define

begin_comment
comment|/// Policy Filter
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_EMTU
value|22
end_define

begin_comment
comment|/// Maximum Datagram Reassembly Size
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_TTL
value|23
end_define

begin_comment
comment|/// Default IP Time-to-live
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_PATHMTU_AGE
value|24
end_define

begin_comment
comment|/// Path MTU Aging Timeout
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_PATHMTU_PLATEAU
value|25
end_define

begin_comment
comment|/// Path MTU Plateau Table
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_IFMTU
value|26
end_define

begin_comment
comment|/// Interface MTU
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_SUBNET_LOCAL
value|27
end_define

begin_comment
comment|/// All Subnets are Local
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_BROADCAST
value|28
end_define

begin_comment
comment|/// Broadcast Address
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_DISCOVER_MASK
value|29
end_define

begin_comment
comment|/// Perform Mask Discovery
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_SUPPLY_MASK
value|30
end_define

begin_comment
comment|/// Mask Supplier
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_DISCOVER_ROUTE
value|31
end_define

begin_comment
comment|/// Perform Router Discovery
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_ROUTER_SOLICIT
value|32
end_define

begin_comment
comment|/// Router Solicitation Address
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_STATIC_ROUTE
value|33
end_define

begin_comment
comment|/// Static Route
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_TRAILER
value|34
end_define

begin_comment
comment|/// Trailer Encapsulation
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_ARPAGE
value|35
end_define

begin_comment
comment|/// ARP Cache Timeout
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_ETHER_ENCAP
value|36
end_define

begin_comment
comment|/// Ethernet Encapsulation
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_TCP_TTL
value|37
end_define

begin_comment
comment|/// TCP Default TTL
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_KEEP_INTERVAL
value|38
end_define

begin_comment
comment|/// TCP Keepalive Interval
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_KEEP_GARBAGE
value|39
end_define

begin_comment
comment|/// TCP Keepalive Garbage
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NIS_DOMAIN
value|40
end_define

begin_comment
comment|/// Network Information Service Domain
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NIS_SERVER
value|41
end_define

begin_comment
comment|/// Network Information Servers
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NTP_SERVER
value|42
end_define

begin_comment
comment|/// Network Time Protocol Servers
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_VENDOR
value|43
end_define

begin_comment
comment|/// Vendor Specific Information
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NBNS
value|44
end_define

begin_comment
comment|/// NetBIOS over TCP/IP Name Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NBDD
value|45
end_define

begin_comment
comment|/// NetBIOS Datagram Distribution Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NBTYPE
value|46
end_define

begin_comment
comment|/// NetBIOS over TCP/IP Node Type
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NBSCOPE
value|47
end_define

begin_comment
comment|/// NetBIOS over TCP/IP Scope
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_XFONT
value|48
end_define

begin_comment
comment|/// X Window System Font Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_XDM
value|49
end_define

begin_comment
comment|/// X Window System Display Manager
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_REQUEST_IP
value|50
end_define

begin_comment
comment|/// Requested IP Address
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_LEASE
value|51
end_define

begin_comment
comment|/// IP Address Lease Time
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_OVERLOAD
value|52
end_define

begin_comment
comment|/// Option Overload
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_MSG_TYPE
value|53
end_define

begin_comment
comment|/// DHCP Message Type
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_SERVER_ID
value|54
end_define

begin_comment
comment|/// Server Identifier
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_PARA_LIST
value|55
end_define

begin_comment
comment|/// Parameter Request List
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_MESSAGE
value|56
end_define

begin_comment
comment|/// Message
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_MAXMSG
value|57
end_define

begin_comment
comment|/// Maximum DHCP Message Size
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_T1
value|58
end_define

begin_comment
comment|/// Renewal (T1) Time Value
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_T2
value|59
end_define

begin_comment
comment|/// Rebinding (T2) Time Value
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_VENDOR_CLASS_ID
value|60
end_define

begin_comment
comment|/// Vendor class identifier
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_CLIENT_ID
value|61
end_define

begin_comment
comment|/// Client-identifier
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NISPLUS
value|64
end_define

begin_comment
comment|/// Network Information Service+ Domain
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NISPLUS_SERVER
value|65
end_define

begin_comment
comment|/// Network Information Service+ Servers
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_TFTP
value|66
end_define

begin_comment
comment|/// TFTP server name
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_BOOTFILE
value|67
end_define

begin_comment
comment|/// Bootfile name
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_MOBILEIP
value|68
end_define

begin_comment
comment|/// Mobile IP Home Agent
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_SMTP
value|69
end_define

begin_comment
comment|/// Simple Mail Transport Protocol Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_POP3
value|70
end_define

begin_comment
comment|/// Post Office Protocol (POP3) Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_NNTP
value|71
end_define

begin_comment
comment|/// Network News Transport Protocol Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_WWW
value|72
end_define

begin_comment
comment|/// Default World Wide Web (WWW) Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_FINGER
value|73
end_define

begin_comment
comment|/// Default Finger Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_IRC
value|74
end_define

begin_comment
comment|/// Default Internet Relay Chat (IRC) Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_STTALK
value|75
end_define

begin_comment
comment|/// StreetTalk Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_STDA
value|76
end_define

begin_comment
comment|/// StreetTalk Directory Assistance Server
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_USER_CLASS_ID
value|77
end_define

begin_comment
comment|/// User class identifier
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_ARCH
value|93
end_define

begin_comment
comment|/// Client System Architecture Type, RFC 4578
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_UNDI
value|94
end_define

begin_comment
comment|/// Client Network Interface Identifier, RFC 4578
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_UUID
value|97
end_define

begin_comment
comment|/// Client Machine Identifier, RFC 4578
end_comment

begin_define
define|#
directive|define
name|DHCP4_TAG_CLASSLESS_ROUTE
value|121
end_define

begin_comment
comment|/// Classless Route
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Dynamic Host Configuration Protocol for IPv6 (DHCPv6)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of Dhcp6 message type, refers to section-5.3 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Dhcp6MsgSolicit
init|=
literal|1
block|,
name|Dhcp6MsgAdvertise
init|=
literal|2
block|,
name|Dhcp6MsgRequest
init|=
literal|3
block|,
name|Dhcp6MsgConfirm
init|=
literal|4
block|,
name|Dhcp6MsgRenew
init|=
literal|5
block|,
name|Dhcp6MsgRebind
init|=
literal|6
block|,
name|Dhcp6MsgReply
init|=
literal|7
block|,
name|Dhcp6MsgRelease
init|=
literal|8
block|,
name|Dhcp6MsgDecline
init|=
literal|9
block|,
name|Dhcp6MsgReconfigure
init|=
literal|10
block|,
name|Dhcp6MsgInfoRequest
init|=
literal|11
block|}
name|DHCP6_MSG_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of option code in Dhcp6 packet, refers to section-24.3 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Dhcp6OptClientId
init|=
literal|1
block|,
name|Dhcp6OptServerId
init|=
literal|2
block|,
name|Dhcp6OptIana
init|=
literal|3
block|,
name|Dhcp6OptIata
init|=
literal|4
block|,
name|Dhcp6OptIaAddr
init|=
literal|5
block|,
name|Dhcp6OptRequestOption
init|=
literal|6
block|,
name|Dhcp6OptPreference
init|=
literal|7
block|,
name|Dhcp6OptElapsedTime
init|=
literal|8
block|,
name|Dhcp6OptReplayMessage
init|=
literal|9
block|,
name|Dhcp6OptAuthentication
init|=
literal|11
block|,
name|Dhcp6OptServerUnicast
init|=
literal|12
block|,
name|Dhcp6OptStatusCode
init|=
literal|13
block|,
name|Dhcp6OptRapidCommit
init|=
literal|14
block|,
name|Dhcp6OptUserClass
init|=
literal|15
block|,
name|Dhcp6OptVendorClass
init|=
literal|16
block|,
name|Dhcp6OptVendorInfo
init|=
literal|17
block|,
name|Dhcp6OptInterfaceId
init|=
literal|18
block|,
name|Dhcp6OptReconfigMessage
init|=
literal|19
block|,
name|Dhcp6OptReconfigureAccept
init|=
literal|20
block|}
name|DHCP6_OPT_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of status code recorded by IANA, refers to section-24.4 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Dhcp6StsSuccess
init|=
literal|0
block|,
name|Dhcp6StsUnspecFail
init|=
literal|1
block|,
name|Dhcp6StsNoAddrsAvail
init|=
literal|2
block|,
name|Dhcp6StsNoBinding
init|=
literal|3
block|,
name|Dhcp6StsNotOnLink
init|=
literal|4
block|,
name|Dhcp6StsUseMulticast
init|=
literal|5
block|}
name|DHCP6_STS_CODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of Duid type recorded by IANA, refers to section-24.5 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Dhcp6DuidTypeLlt
init|=
literal|1
block|,
name|Dhcp6DuidTypeEn
init|=
literal|2
block|,
name|Dhcp6DuidTypeLl
init|=
literal|3
block|,
name|Dhcp6DuidTypeUuid
init|=
literal|4
block|}
name|DHCP6_DUID_TYPE
typedef|;
end_typedef

begin_comment
comment|/// Transmission and Retransmission Parameters
end_comment

begin_comment
comment|/// This section presents a table of values used to describe the message
end_comment

begin_comment
comment|/// transmission behavior of clients and servers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit parameters of solicit message, refers to section-5.5 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DHCP6_SOL_MAX_DELAY
value|1
end_define

begin_define
define|#
directive|define
name|DHCP6_SOL_IRT
value|1
end_define

begin_define
define|#
directive|define
name|DHCP6_SOL_MRC
value|0
end_define

begin_define
define|#
directive|define
name|DHCP6_SOL_MRT
value|120
end_define

begin_define
define|#
directive|define
name|DHCP6_SOL_MRD
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit parameters of request message, refers to section-5.5 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DHCP6_REQ_IRT
value|1
end_define

begin_define
define|#
directive|define
name|DHCP6_REQ_MRC
value|10
end_define

begin_define
define|#
directive|define
name|DHCP6_REQ_MRT
value|30
end_define

begin_define
define|#
directive|define
name|DHCP6_REQ_MRD
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit parameters of confirm message, refers to section-5.5 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DHCP6_CNF_MAX_DELAY
value|1
end_define

begin_define
define|#
directive|define
name|DHCP6_CNF_IRT
value|1
end_define

begin_define
define|#
directive|define
name|DHCP6_CNF_MRC
value|0
end_define

begin_define
define|#
directive|define
name|DHCP6_CNF_MRT
value|4
end_define

begin_define
define|#
directive|define
name|DHCP6_CNF_MRD
value|10
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit parameters of renew message, refers to section-5.5 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DHCP6_REN_IRT
value|10
end_define

begin_define
define|#
directive|define
name|DHCP6_REN_MRC
value|0
end_define

begin_define
define|#
directive|define
name|DHCP6_REN_MRT
value|600
end_define

begin_define
define|#
directive|define
name|DHCP6_REN_MRD
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit parameters of rebind message, refers to section-5.5 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DHCP6_REB_IRT
value|10
end_define

begin_define
define|#
directive|define
name|DHCP6_REB_MRC
value|0
end_define

begin_define
define|#
directive|define
name|DHCP6_REB_MRT
value|600
end_define

begin_define
define|#
directive|define
name|DHCP6_REB_MRD
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit parameters of information request message, refers to section-5.5 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DHCP6_INF_MAX_DELAY
value|1
end_define

begin_define
define|#
directive|define
name|DHCP6_INF_IRT
value|1
end_define

begin_define
define|#
directive|define
name|DHCP6_INF_MRC
value|0
end_define

begin_define
define|#
directive|define
name|DHCP6_INF_MRT
value|120
end_define

begin_define
define|#
directive|define
name|DHCP6_INF_MRD
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit parameters of release message, refers to section-5.5 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DHCP6_REL_IRT
value|1
end_define

begin_define
define|#
directive|define
name|DHCP6_REL_MRC
value|5
end_define

begin_define
define|#
directive|define
name|DHCP6_REL_MRT
value|0
end_define

begin_define
define|#
directive|define
name|DHCP6_REL_MRD
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit parameters of decline message, refers to section-5.5 of rfc-3315.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DHCP6_DEC_IRT
value|1
end_define

begin_define
define|#
directive|define
name|DHCP6_DEC_MRC
value|5
end_define

begin_define
define|#
directive|define
name|DHCP6_DEC_MRT
value|0
end_define

begin_define
define|#
directive|define
name|DHCP6_DEC_MRD
value|0
end_define

begin_comment
comment|////
end_comment

begin_comment
comment|//// DHCPv6 Options, definitions from RFC 3315,RFC 5970 and RFC 3646.
end_comment

begin_comment
comment|////
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_CLIENT_ID
value|1
end_define

begin_comment
comment|/// Client Identifier Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_SERVER_ID
value|2
end_define

begin_comment
comment|/// Server Identifier Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_IA_NA
value|3
end_define

begin_comment
comment|/// The Identity Association for Non-temporary Addresses option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_IA_TA
value|4
end_define

begin_comment
comment|/// The Identity Association for the Temporary Addresses
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_IAADDR
value|5
end_define

begin_comment
comment|/// IA Address option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_ORO
value|6
end_define

begin_comment
comment|/// Request option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_PREFERENCE
value|7
end_define

begin_comment
comment|/// Preference option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_ELAPSED_TIME
value|8
end_define

begin_comment
comment|/// Elapsed Time Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_REPLAY_MSG
value|9
end_define

begin_comment
comment|/// Relay Message option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_AUTH
value|11
end_define

begin_comment
comment|/// Authentication option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_UNICAST
value|12
end_define

begin_comment
comment|/// Server Unicast Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_STATUS_CODE
value|13
end_define

begin_comment
comment|/// Status Code Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_RAPID_COMMIT
value|14
end_define

begin_comment
comment|/// Rapid Commit option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_USER_CLASS
value|15
end_define

begin_comment
comment|/// User Class option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_VENDOR_CLASS
value|16
end_define

begin_comment
comment|/// Vendor Class Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_VENDOR_OPTS
value|17
end_define

begin_comment
comment|/// Vendor-specific Information Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_INTERFACE_ID
value|18
end_define

begin_comment
comment|/// Interface-Id Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_RECONFIG_MSG
value|19
end_define

begin_comment
comment|/// Reconfigure Message Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_RECONFIG_ACCEPT
value|20
end_define

begin_comment
comment|/// Reconfigure Accept Option
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_DNS_SERVERS
value|23
end_define

begin_comment
comment|/// DNS Configuration options, RFC 3646
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_BOOT_FILE_URL
value|59
end_define

begin_comment
comment|/// Assigned by IANA, RFC 5970
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_BOOT_FILE_PARAM
value|60
end_define

begin_comment
comment|/// Assigned by IANA, RFC 5970
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_ARCH
value|61
end_define

begin_comment
comment|/// Assigned by IANA, RFC 5970
end_comment

begin_define
define|#
directive|define
name|DHCP6_OPT_UNDI
value|62
end_define

begin_comment
comment|/// Assigned by IANA, RFC 5970
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Processor Architecture Types
end_comment

begin_comment
comment|/// These identifiers are defined by IETF:
end_comment

begin_comment
comment|/// http://www.ietf.org/assignments/dhcpv6-parameters/dhcpv6-parameters.xml
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_CLIENT_ARCH_X86_BIOS
value|0x0000
end_define

begin_comment
comment|/// x86 BIOS for PXE
end_comment

begin_define
define|#
directive|define
name|PXE_CLIENT_ARCH_IPF
value|0x0002
end_define

begin_comment
comment|/// Itanium for PXE
end_comment

begin_define
define|#
directive|define
name|PXE_CLIENT_ARCH_IA32
value|0x0006
end_define

begin_comment
comment|/// x86 uefi for PXE
end_comment

begin_define
define|#
directive|define
name|PXE_CLIENT_ARCH_X64
value|0x0007
end_define

begin_comment
comment|/// x64 uefi for PXE
end_comment

begin_define
define|#
directive|define
name|PXE_CLIENT_ARCH_EBC
value|0x0009
end_define

begin_comment
comment|/// EBC for PXE
end_comment

begin_define
define|#
directive|define
name|PXE_CLIENT_ARCH_ARM
value|0x000A
end_define

begin_comment
comment|/// Arm uefi 32 for PXE
end_comment

begin_define
define|#
directive|define
name|PXE_CLIENT_ARCH_AARCH64
value|0x000B
end_define

begin_comment
comment|/// Arm uefi 64 for PXE
end_comment

begin_define
define|#
directive|define
name|HTTP_CLIENT_ARCH_IA32
value|0x000F
end_define

begin_comment
comment|/// x86 uefi boot from http
end_comment

begin_define
define|#
directive|define
name|HTTP_CLIENT_ARCH_X64
value|0x0010
end_define

begin_comment
comment|/// x64 uefi boot from http
end_comment

begin_define
define|#
directive|define
name|HTTP_CLIENT_ARCH_EBC
value|0x0011
end_define

begin_comment
comment|/// EBC boot from http
end_comment

begin_define
define|#
directive|define
name|HTTP_CLIENT_ARCH_ARM
value|0x0012
end_define

begin_comment
comment|/// Arm uefi 32 boot from http
end_comment

begin_define
define|#
directive|define
name|HTTP_CLIENT_ARCH_AARCH64
value|0x0013
end_define

begin_comment
comment|/// Arm uefi 64 boot from http
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

