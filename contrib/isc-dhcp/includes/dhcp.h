begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dhcp.h     Protocol structures... */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995-2001 The Internet Software Consortium.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This software has been written for the Internet Software Consortium  * by Ted Lemon in cooperation with Vixie Enterprises.  To learn more  * about the Internet Software Consortium, see ``http://www.isc.org''.  * To learn more about Vixie Enterprises, see ``http://www.vix.com''.  */
end_comment

begin_define
define|#
directive|define
name|DHCP_UDP_OVERHEAD
value|(14 +
comment|/* Ethernet header */
value|\ 				 20 +
comment|/* IP header */
value|\ 				 8)
end_define

begin_comment
comment|/* UDP header */
end_comment

begin_define
define|#
directive|define
name|DHCP_SNAME_LEN
value|64
end_define

begin_define
define|#
directive|define
name|DHCP_FILE_LEN
value|128
end_define

begin_define
define|#
directive|define
name|DHCP_FIXED_NON_UDP
value|236
end_define

begin_define
define|#
directive|define
name|DHCP_FIXED_LEN
value|(DHCP_FIXED_NON_UDP + DHCP_UDP_OVERHEAD)
end_define

begin_comment
comment|/* Everything but options. */
end_comment

begin_define
define|#
directive|define
name|DHCP_MTU_MAX
value|1500
end_define

begin_define
define|#
directive|define
name|DHCP_OPTION_LEN
value|(DHCP_MTU_MAX - DHCP_FIXED_LEN)
end_define

begin_define
define|#
directive|define
name|BOOTP_MIN_LEN
value|300
end_define

begin_define
define|#
directive|define
name|DHCP_MIN_LEN
value|548
end_define

begin_struct
struct|struct
name|dhcp_packet
block|{
name|u_int8_t
name|op
decl_stmt|;
comment|/* 0: Message opcode/type */
name|u_int8_t
name|htype
decl_stmt|;
comment|/* 1: Hardware addr type (net/if_types.h) */
name|u_int8_t
name|hlen
decl_stmt|;
comment|/* 2: Hardware addr length */
name|u_int8_t
name|hops
decl_stmt|;
comment|/* 3: Number of relay agent hops from client */
name|u_int32_t
name|xid
decl_stmt|;
comment|/* 4: Transaction ID */
name|u_int16_t
name|secs
decl_stmt|;
comment|/* 8: Seconds since client started looking */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* 10: Flag bits */
name|struct
name|in_addr
name|ciaddr
decl_stmt|;
comment|/* 12: Client IP address (if already in use) */
name|struct
name|in_addr
name|yiaddr
decl_stmt|;
comment|/* 16: Client IP address */
name|struct
name|in_addr
name|siaddr
decl_stmt|;
comment|/* 18: IP address of next server to talk to */
name|struct
name|in_addr
name|giaddr
decl_stmt|;
comment|/* 20: DHCP relay agent IP address */
name|unsigned
name|char
name|chaddr
index|[
literal|16
index|]
decl_stmt|;
comment|/* 24: Client hardware address */
name|char
name|sname
index|[
name|DHCP_SNAME_LEN
index|]
decl_stmt|;
comment|/* 40: Server name */
name|char
name|file
index|[
name|DHCP_FILE_LEN
index|]
decl_stmt|;
comment|/* 104: Boot filename */
name|unsigned
name|char
name|options
index|[
name|DHCP_OPTION_LEN
index|]
decl_stmt|;
comment|/* 212: Optional parameters 				   (actual length dependent on MTU). */
block|}
struct|;
end_struct

begin_comment
comment|/* BOOTP (rfc951) message types */
end_comment

begin_define
define|#
directive|define
name|BOOTREQUEST
value|1
end_define

begin_define
define|#
directive|define
name|BOOTREPLY
value|2
end_define

begin_comment
comment|/* Possible values for flags field... */
end_comment

begin_define
define|#
directive|define
name|BOOTP_BROADCAST
value|32768L
end_define

begin_comment
comment|/* Possible values for hardware type (htype) field... */
end_comment

begin_define
define|#
directive|define
name|HTYPE_ETHER
value|1
end_define

begin_comment
comment|/* Ethernet 10Mbps              */
end_comment

begin_define
define|#
directive|define
name|HTYPE_IEEE802
value|6
end_define

begin_comment
comment|/* IEEE 802.2 Token Ring...	*/
end_comment

begin_define
define|#
directive|define
name|HTYPE_FDDI
value|8
end_define

begin_comment
comment|/* FDDI...			*/
end_comment

begin_comment
comment|/* Magic cookie validating dhcp options field (and bootp vendor    extensions field). */
end_comment

begin_define
define|#
directive|define
name|DHCP_OPTIONS_COOKIE
value|"\143\202\123\143"
end_define

begin_comment
comment|/* DHCP Option codes: */
end_comment

begin_define
define|#
directive|define
name|DHO_PAD
value|0
end_define

begin_define
define|#
directive|define
name|DHO_SUBNET_MASK
value|1
end_define

begin_define
define|#
directive|define
name|DHO_TIME_OFFSET
value|2
end_define

begin_define
define|#
directive|define
name|DHO_ROUTERS
value|3
end_define

begin_define
define|#
directive|define
name|DHO_TIME_SERVERS
value|4
end_define

begin_define
define|#
directive|define
name|DHO_NAME_SERVERS
value|5
end_define

begin_define
define|#
directive|define
name|DHO_DOMAIN_NAME_SERVERS
value|6
end_define

begin_define
define|#
directive|define
name|DHO_LOG_SERVERS
value|7
end_define

begin_define
define|#
directive|define
name|DHO_COOKIE_SERVERS
value|8
end_define

begin_define
define|#
directive|define
name|DHO_LPR_SERVERS
value|9
end_define

begin_define
define|#
directive|define
name|DHO_IMPRESS_SERVERS
value|10
end_define

begin_define
define|#
directive|define
name|DHO_RESOURCE_LOCATION_SERVERS
value|11
end_define

begin_define
define|#
directive|define
name|DHO_HOST_NAME
value|12
end_define

begin_define
define|#
directive|define
name|DHO_BOOT_SIZE
value|13
end_define

begin_define
define|#
directive|define
name|DHO_MERIT_DUMP
value|14
end_define

begin_define
define|#
directive|define
name|DHO_DOMAIN_NAME
value|15
end_define

begin_define
define|#
directive|define
name|DHO_SWAP_SERVER
value|16
end_define

begin_define
define|#
directive|define
name|DHO_ROOT_PATH
value|17
end_define

begin_define
define|#
directive|define
name|DHO_EXTENSIONS_PATH
value|18
end_define

begin_define
define|#
directive|define
name|DHO_IP_FORWARDING
value|19
end_define

begin_define
define|#
directive|define
name|DHO_NON_LOCAL_SOURCE_ROUTING
value|20
end_define

begin_define
define|#
directive|define
name|DHO_POLICY_FILTER
value|21
end_define

begin_define
define|#
directive|define
name|DHO_MAX_DGRAM_REASSEMBLY
value|22
end_define

begin_define
define|#
directive|define
name|DHO_DEFAULT_IP_TTL
value|23
end_define

begin_define
define|#
directive|define
name|DHO_PATH_MTU_AGING_TIMEOUT
value|24
end_define

begin_define
define|#
directive|define
name|DHO_PATH_MTU_PLATEAU_TABLE
value|25
end_define

begin_define
define|#
directive|define
name|DHO_INTERFACE_MTU
value|26
end_define

begin_define
define|#
directive|define
name|DHO_ALL_SUBNETS_LOCAL
value|27
end_define

begin_define
define|#
directive|define
name|DHO_BROADCAST_ADDRESS
value|28
end_define

begin_define
define|#
directive|define
name|DHO_PERFORM_MASK_DISCOVERY
value|29
end_define

begin_define
define|#
directive|define
name|DHO_MASK_SUPPLIER
value|30
end_define

begin_define
define|#
directive|define
name|DHO_ROUTER_DISCOVERY
value|31
end_define

begin_define
define|#
directive|define
name|DHO_ROUTER_SOLICITATION_ADDRESS
value|32
end_define

begin_define
define|#
directive|define
name|DHO_STATIC_ROUTES
value|33
end_define

begin_define
define|#
directive|define
name|DHO_TRAILER_ENCAPSULATION
value|34
end_define

begin_define
define|#
directive|define
name|DHO_ARP_CACHE_TIMEOUT
value|35
end_define

begin_define
define|#
directive|define
name|DHO_IEEE802_3_ENCAPSULATION
value|36
end_define

begin_define
define|#
directive|define
name|DHO_DEFAULT_TCP_TTL
value|37
end_define

begin_define
define|#
directive|define
name|DHO_TCP_KEEPALIVE_INTERVAL
value|38
end_define

begin_define
define|#
directive|define
name|DHO_TCP_KEEPALIVE_GARBAGE
value|39
end_define

begin_define
define|#
directive|define
name|DHO_NIS_DOMAIN
value|40
end_define

begin_define
define|#
directive|define
name|DHO_NIS_SERVERS
value|41
end_define

begin_define
define|#
directive|define
name|DHO_NTP_SERVERS
value|42
end_define

begin_define
define|#
directive|define
name|DHO_VENDOR_ENCAPSULATED_OPTIONS
value|43
end_define

begin_define
define|#
directive|define
name|DHO_NETBIOS_NAME_SERVERS
value|44
end_define

begin_define
define|#
directive|define
name|DHO_NETBIOS_DD_SERVER
value|45
end_define

begin_define
define|#
directive|define
name|DHO_NETBIOS_NODE_TYPE
value|46
end_define

begin_define
define|#
directive|define
name|DHO_NETBIOS_SCOPE
value|47
end_define

begin_define
define|#
directive|define
name|DHO_FONT_SERVERS
value|48
end_define

begin_define
define|#
directive|define
name|DHO_X_DISPLAY_MANAGER
value|49
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_REQUESTED_ADDRESS
value|50
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_LEASE_TIME
value|51
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_OPTION_OVERLOAD
value|52
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_MESSAGE_TYPE
value|53
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_SERVER_IDENTIFIER
value|54
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_PARAMETER_REQUEST_LIST
value|55
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_MESSAGE
value|56
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_MAX_MESSAGE_SIZE
value|57
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_RENEWAL_TIME
value|58
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_REBINDING_TIME
value|59
end_define

begin_define
define|#
directive|define
name|DHO_VENDOR_CLASS_IDENTIFIER
value|60
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_CLIENT_IDENTIFIER
value|61
end_define

begin_define
define|#
directive|define
name|DHO_NWIP_DOMAIN_NAME
value|62
end_define

begin_define
define|#
directive|define
name|DHO_NWIP_SUBOPTIONS
value|63
end_define

begin_define
define|#
directive|define
name|DHO_USER_CLASS
value|77
end_define

begin_define
define|#
directive|define
name|DHO_FQDN
value|81
end_define

begin_define
define|#
directive|define
name|DHO_DHCP_AGENT_OPTIONS
value|82
end_define

begin_define
define|#
directive|define
name|DHO_SUBNET_SELECTION
value|118
end_define

begin_comment
comment|/* RFC3011! */
end_comment

begin_comment
comment|/* The DHO_AUTHENTICATE option is not a standard yet, so I've    allocated an option out of the "local" option space for it on a    temporary basis.  Once an option code number is assigned, I will    immediately and shamelessly break this, so don't count on it    continuing to work. */
end_comment

begin_define
define|#
directive|define
name|DHO_AUTHENTICATE
value|210
end_define

begin_define
define|#
directive|define
name|DHO_END
value|255
end_define

begin_comment
comment|/* DHCP message types. */
end_comment

begin_define
define|#
directive|define
name|DHCPDISCOVER
value|1
end_define

begin_define
define|#
directive|define
name|DHCPOFFER
value|2
end_define

begin_define
define|#
directive|define
name|DHCPREQUEST
value|3
end_define

begin_define
define|#
directive|define
name|DHCPDECLINE
value|4
end_define

begin_define
define|#
directive|define
name|DHCPACK
value|5
end_define

begin_define
define|#
directive|define
name|DHCPNAK
value|6
end_define

begin_define
define|#
directive|define
name|DHCPRELEASE
value|7
end_define

begin_define
define|#
directive|define
name|DHCPINFORM
value|8
end_define

begin_comment
comment|/* Relay Agent Information option subtypes: */
end_comment

begin_define
define|#
directive|define
name|RAI_CIRCUIT_ID
value|1
end_define

begin_define
define|#
directive|define
name|RAI_REMOTE_ID
value|2
end_define

begin_define
define|#
directive|define
name|RAI_AGENT_ID
value|3
end_define

begin_comment
comment|/* FQDN suboptions: */
end_comment

begin_define
define|#
directive|define
name|FQDN_NO_CLIENT_UPDATE
value|1
end_define

begin_define
define|#
directive|define
name|FQDN_SERVER_UPDATE
value|2
end_define

begin_define
define|#
directive|define
name|FQDN_ENCODED
value|3
end_define

begin_define
define|#
directive|define
name|FQDN_RCODE1
value|4
end_define

begin_define
define|#
directive|define
name|FQDN_RCODE2
value|5
end_define

begin_define
define|#
directive|define
name|FQDN_HOSTNAME
value|6
end_define

begin_define
define|#
directive|define
name|FQDN_DOMAINNAME
value|7
end_define

begin_define
define|#
directive|define
name|FQDN_FQDN
value|8
end_define

begin_define
define|#
directive|define
name|FQDN_SUBOPTION_COUNT
value|8
end_define

end_unit

