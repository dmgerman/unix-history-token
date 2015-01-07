begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Bootstrap Protocol (BOOTP).  RFC951 and RFC1048.  *  * This file specifies the "implementation-independent" BOOTP protocol  * information which is common to both client and server.  *  * Copyright 1988 by Carnegie Mellon.  *  * Permission to use, copy, modify, and distribute this program for any  * purpose and without fee is hereby granted, provided that this copyright  * and permission notice appear on all copies and supporting documentation,  * the name of Carnegie Mellon not be used in advertising or publicity  * pertaining to distribution of the program without specific prior  * permission, and notice be given in supporting documentation that copying  * and distribution is by permission of Carnegie Mellon and Stanford  * University.  Carnegie Mellon makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  */
end_comment

begin_struct
struct|struct
name|bootp
block|{
name|uint8_t
name|bp_op
decl_stmt|;
comment|/* packet opcode type */
name|uint8_t
name|bp_htype
decl_stmt|;
comment|/* hardware addr type */
name|uint8_t
name|bp_hlen
decl_stmt|;
comment|/* hardware addr length */
name|uint8_t
name|bp_hops
decl_stmt|;
comment|/* gateway hops */
name|uint32_t
name|bp_xid
decl_stmt|;
comment|/* transaction ID */
name|uint16_t
name|bp_secs
decl_stmt|;
comment|/* seconds since boot began */
name|uint16_t
name|bp_flags
decl_stmt|;
comment|/* flags - see bootp_flag_values[] 					   in print-bootp.c */
name|struct
name|in_addr
name|bp_ciaddr
decl_stmt|;
comment|/* client IP address */
name|struct
name|in_addr
name|bp_yiaddr
decl_stmt|;
comment|/* 'your' IP address */
name|struct
name|in_addr
name|bp_siaddr
decl_stmt|;
comment|/* server IP address */
name|struct
name|in_addr
name|bp_giaddr
decl_stmt|;
comment|/* gateway IP address */
name|uint8_t
name|bp_chaddr
index|[
literal|16
index|]
decl_stmt|;
comment|/* client hardware address */
name|uint8_t
name|bp_sname
index|[
literal|64
index|]
decl_stmt|;
comment|/* server host name */
name|uint8_t
name|bp_file
index|[
literal|128
index|]
decl_stmt|;
comment|/* boot file name */
name|uint8_t
name|bp_vend
index|[
literal|64
index|]
decl_stmt|;
comment|/* vendor-specific area */
block|}
name|UNALIGNED
struct|;
end_struct

begin_comment
comment|/*  * UDP port numbers, server and client.  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_BOOTPS
value|67
end_define

begin_define
define|#
directive|define
name|IPPORT_BOOTPC
value|68
end_define

begin_define
define|#
directive|define
name|BOOTPREPLY
value|2
end_define

begin_define
define|#
directive|define
name|BOOTPREQUEST
value|1
end_define

begin_comment
comment|/*  * Vendor magic cookie (v_magic) for CMU  */
end_comment

begin_define
define|#
directive|define
name|VM_CMU
value|"CMU"
end_define

begin_comment
comment|/*  * Vendor magic cookie (v_magic) for RFC1048  */
end_comment

begin_define
define|#
directive|define
name|VM_RFC1048
value|{ 99, 130, 83, 99 }
end_define

begin_escape
end_escape

begin_comment
comment|/*  * RFC1048 tag values used to specify what information is being supplied in  * the vendor field of the packet.  */
end_comment

begin_define
define|#
directive|define
name|TAG_PAD
value|((uint8_t)   0)
end_define

begin_define
define|#
directive|define
name|TAG_SUBNET_MASK
value|((uint8_t)   1)
end_define

begin_define
define|#
directive|define
name|TAG_TIME_OFFSET
value|((uint8_t)   2)
end_define

begin_define
define|#
directive|define
name|TAG_GATEWAY
value|((uint8_t)   3)
end_define

begin_define
define|#
directive|define
name|TAG_TIME_SERVER
value|((uint8_t)   4)
end_define

begin_define
define|#
directive|define
name|TAG_NAME_SERVER
value|((uint8_t)   5)
end_define

begin_define
define|#
directive|define
name|TAG_DOMAIN_SERVER
value|((uint8_t)   6)
end_define

begin_define
define|#
directive|define
name|TAG_LOG_SERVER
value|((uint8_t)   7)
end_define

begin_define
define|#
directive|define
name|TAG_COOKIE_SERVER
value|((uint8_t)   8)
end_define

begin_define
define|#
directive|define
name|TAG_LPR_SERVER
value|((uint8_t)   9)
end_define

begin_define
define|#
directive|define
name|TAG_IMPRESS_SERVER
value|((uint8_t)  10)
end_define

begin_define
define|#
directive|define
name|TAG_RLP_SERVER
value|((uint8_t)  11)
end_define

begin_define
define|#
directive|define
name|TAG_HOSTNAME
value|((uint8_t)  12)
end_define

begin_define
define|#
directive|define
name|TAG_BOOTSIZE
value|((uint8_t)  13)
end_define

begin_define
define|#
directive|define
name|TAG_END
value|((uint8_t) 255)
end_define

begin_comment
comment|/* RFC1497 tags */
end_comment

begin_define
define|#
directive|define
name|TAG_DUMPPATH
value|((uint8_t)  14)
end_define

begin_define
define|#
directive|define
name|TAG_DOMAINNAME
value|((uint8_t)  15)
end_define

begin_define
define|#
directive|define
name|TAG_SWAP_SERVER
value|((uint8_t)  16)
end_define

begin_define
define|#
directive|define
name|TAG_ROOTPATH
value|((uint8_t)  17)
end_define

begin_define
define|#
directive|define
name|TAG_EXTPATH
value|((uint8_t)  18)
end_define

begin_comment
comment|/* RFC2132 */
end_comment

begin_define
define|#
directive|define
name|TAG_IP_FORWARD
value|((uint8_t)  19)
end_define

begin_define
define|#
directive|define
name|TAG_NL_SRCRT
value|((uint8_t)  20)
end_define

begin_define
define|#
directive|define
name|TAG_PFILTERS
value|((uint8_t)  21)
end_define

begin_define
define|#
directive|define
name|TAG_REASS_SIZE
value|((uint8_t)  22)
end_define

begin_define
define|#
directive|define
name|TAG_DEF_TTL
value|((uint8_t)  23)
end_define

begin_define
define|#
directive|define
name|TAG_MTU_TIMEOUT
value|((uint8_t)  24)
end_define

begin_define
define|#
directive|define
name|TAG_MTU_TABLE
value|((uint8_t)  25)
end_define

begin_define
define|#
directive|define
name|TAG_INT_MTU
value|((uint8_t)  26)
end_define

begin_define
define|#
directive|define
name|TAG_LOCAL_SUBNETS
value|((uint8_t)  27)
end_define

begin_define
define|#
directive|define
name|TAG_BROAD_ADDR
value|((uint8_t)  28)
end_define

begin_define
define|#
directive|define
name|TAG_DO_MASK_DISC
value|((uint8_t)  29)
end_define

begin_define
define|#
directive|define
name|TAG_SUPPLY_MASK
value|((uint8_t)  30)
end_define

begin_define
define|#
directive|define
name|TAG_DO_RDISC
value|((uint8_t)  31)
end_define

begin_define
define|#
directive|define
name|TAG_RTR_SOL_ADDR
value|((uint8_t)  32)
end_define

begin_define
define|#
directive|define
name|TAG_STATIC_ROUTE
value|((uint8_t)  33)
end_define

begin_define
define|#
directive|define
name|TAG_USE_TRAILERS
value|((uint8_t)  34)
end_define

begin_define
define|#
directive|define
name|TAG_ARP_TIMEOUT
value|((uint8_t)  35)
end_define

begin_define
define|#
directive|define
name|TAG_ETH_ENCAP
value|((uint8_t)  36)
end_define

begin_define
define|#
directive|define
name|TAG_TCP_TTL
value|((uint8_t)  37)
end_define

begin_define
define|#
directive|define
name|TAG_TCP_KEEPALIVE
value|((uint8_t)  38)
end_define

begin_define
define|#
directive|define
name|TAG_KEEPALIVE_GO
value|((uint8_t)  39)
end_define

begin_define
define|#
directive|define
name|TAG_NIS_DOMAIN
value|((uint8_t)  40)
end_define

begin_define
define|#
directive|define
name|TAG_NIS_SERVERS
value|((uint8_t)  41)
end_define

begin_define
define|#
directive|define
name|TAG_NTP_SERVERS
value|((uint8_t)  42)
end_define

begin_define
define|#
directive|define
name|TAG_VENDOR_OPTS
value|((uint8_t)  43)
end_define

begin_define
define|#
directive|define
name|TAG_NETBIOS_NS
value|((uint8_t)  44)
end_define

begin_define
define|#
directive|define
name|TAG_NETBIOS_DDS
value|((uint8_t)  45)
end_define

begin_define
define|#
directive|define
name|TAG_NETBIOS_NODE
value|((uint8_t)  46)
end_define

begin_define
define|#
directive|define
name|TAG_NETBIOS_SCOPE
value|((uint8_t)  47)
end_define

begin_define
define|#
directive|define
name|TAG_XWIN_FS
value|((uint8_t)  48)
end_define

begin_define
define|#
directive|define
name|TAG_XWIN_DM
value|((uint8_t)  49)
end_define

begin_define
define|#
directive|define
name|TAG_NIS_P_DOMAIN
value|((uint8_t)  64)
end_define

begin_define
define|#
directive|define
name|TAG_NIS_P_SERVERS
value|((uint8_t)  65)
end_define

begin_define
define|#
directive|define
name|TAG_MOBILE_HOME
value|((uint8_t)  68)
end_define

begin_define
define|#
directive|define
name|TAG_SMPT_SERVER
value|((uint8_t)  69)
end_define

begin_define
define|#
directive|define
name|TAG_POP3_SERVER
value|((uint8_t)  70)
end_define

begin_define
define|#
directive|define
name|TAG_NNTP_SERVER
value|((uint8_t)  71)
end_define

begin_define
define|#
directive|define
name|TAG_WWW_SERVER
value|((uint8_t)  72)
end_define

begin_define
define|#
directive|define
name|TAG_FINGER_SERVER
value|((uint8_t)  73)
end_define

begin_define
define|#
directive|define
name|TAG_IRC_SERVER
value|((uint8_t)  74)
end_define

begin_define
define|#
directive|define
name|TAG_STREETTALK_SRVR
value|((uint8_t)  75)
end_define

begin_define
define|#
directive|define
name|TAG_STREETTALK_STDA
value|((uint8_t)  76)
end_define

begin_comment
comment|/* DHCP options */
end_comment

begin_define
define|#
directive|define
name|TAG_REQUESTED_IP
value|((uint8_t)  50)
end_define

begin_define
define|#
directive|define
name|TAG_IP_LEASE
value|((uint8_t)  51)
end_define

begin_define
define|#
directive|define
name|TAG_OPT_OVERLOAD
value|((uint8_t)  52)
end_define

begin_define
define|#
directive|define
name|TAG_TFTP_SERVER
value|((uint8_t)  66)
end_define

begin_define
define|#
directive|define
name|TAG_BOOTFILENAME
value|((uint8_t)  67)
end_define

begin_define
define|#
directive|define
name|TAG_DHCP_MESSAGE
value|((uint8_t)  53)
end_define

begin_define
define|#
directive|define
name|TAG_SERVER_ID
value|((uint8_t)  54)
end_define

begin_define
define|#
directive|define
name|TAG_PARM_REQUEST
value|((uint8_t)  55)
end_define

begin_define
define|#
directive|define
name|TAG_MESSAGE
value|((uint8_t)  56)
end_define

begin_define
define|#
directive|define
name|TAG_MAX_MSG_SIZE
value|((uint8_t)  57)
end_define

begin_define
define|#
directive|define
name|TAG_RENEWAL_TIME
value|((uint8_t)  58)
end_define

begin_define
define|#
directive|define
name|TAG_REBIND_TIME
value|((uint8_t)  59)
end_define

begin_define
define|#
directive|define
name|TAG_VENDOR_CLASS
value|((uint8_t)  60)
end_define

begin_define
define|#
directive|define
name|TAG_CLIENT_ID
value|((uint8_t)  61)
end_define

begin_comment
comment|/* RFC 2241 */
end_comment

begin_define
define|#
directive|define
name|TAG_NDS_SERVERS
value|((uint8_t)  85)
end_define

begin_define
define|#
directive|define
name|TAG_NDS_TREE_NAME
value|((uint8_t)  86)
end_define

begin_define
define|#
directive|define
name|TAG_NDS_CONTEXT
value|((uint8_t)  87)
end_define

begin_comment
comment|/* RFC 2242 */
end_comment

begin_define
define|#
directive|define
name|TAG_NDS_IPDOMAIN
value|((uint8_t)  62)
end_define

begin_define
define|#
directive|define
name|TAG_NDS_IPINFO
value|((uint8_t)  63)
end_define

begin_comment
comment|/* RFC 2485 */
end_comment

begin_define
define|#
directive|define
name|TAG_OPEN_GROUP_UAP
value|((uint8_t)  98)
end_define

begin_comment
comment|/* RFC 2563 */
end_comment

begin_define
define|#
directive|define
name|TAG_DISABLE_AUTOCONF
value|((uint8_t) 116)
end_define

begin_comment
comment|/* RFC 2610 */
end_comment

begin_define
define|#
directive|define
name|TAG_SLP_DA
value|((uint8_t)  78)
end_define

begin_define
define|#
directive|define
name|TAG_SLP_SCOPE
value|((uint8_t)  79)
end_define

begin_comment
comment|/* RFC 2937 */
end_comment

begin_define
define|#
directive|define
name|TAG_NS_SEARCH
value|((uint8_t) 117)
end_define

begin_comment
comment|/* RFC 3011 */
end_comment

begin_define
define|#
directive|define
name|TAG_IP4_SUBNET_SELECT
value|((uint8_t) 118)
end_define

begin_comment
comment|/* RFC 3442 */
end_comment

begin_define
define|#
directive|define
name|TAG_CLASSLESS_STATIC_RT
value|((uint8_t) 121)
end_define

begin_define
define|#
directive|define
name|TAG_CLASSLESS_STA_RT_MS
value|((uint8_t) 249)
end_define

begin_comment
comment|/* ftp://ftp.isi.edu/.../assignments/bootp-dhcp-extensions */
end_comment

begin_define
define|#
directive|define
name|TAG_USER_CLASS
value|((uint8_t)  77)
end_define

begin_define
define|#
directive|define
name|TAG_SLP_NAMING_AUTH
value|((uint8_t)  80)
end_define

begin_define
define|#
directive|define
name|TAG_CLIENT_FQDN
value|((uint8_t)  81)
end_define

begin_define
define|#
directive|define
name|TAG_AGENT_CIRCUIT
value|((uint8_t)  82)
end_define

begin_define
define|#
directive|define
name|TAG_AGENT_REMOTE
value|((uint8_t)  83)
end_define

begin_define
define|#
directive|define
name|TAG_AGENT_MASK
value|((uint8_t)  84)
end_define

begin_define
define|#
directive|define
name|TAG_TZ_STRING
value|((uint8_t)  88)
end_define

begin_define
define|#
directive|define
name|TAG_FQDN_OPTION
value|((uint8_t)  89)
end_define

begin_define
define|#
directive|define
name|TAG_AUTH
value|((uint8_t)  90)
end_define

begin_define
define|#
directive|define
name|TAG_VINES_SERVERS
value|((uint8_t)  91)
end_define

begin_define
define|#
directive|define
name|TAG_SERVER_RANK
value|((uint8_t)  92)
end_define

begin_define
define|#
directive|define
name|TAG_CLIENT_ARCH
value|((uint8_t)  93)
end_define

begin_define
define|#
directive|define
name|TAG_CLIENT_NDI
value|((uint8_t)  94)
end_define

begin_define
define|#
directive|define
name|TAG_CLIENT_GUID
value|((uint8_t)  97)
end_define

begin_define
define|#
directive|define
name|TAG_LDAP_URL
value|((uint8_t)  95)
end_define

begin_define
define|#
directive|define
name|TAG_6OVER4
value|((uint8_t)  96)
end_define

begin_define
define|#
directive|define
name|TAG_PRINTER_NAME
value|((uint8_t) 100)
end_define

begin_define
define|#
directive|define
name|TAG_MDHCP_SERVER
value|((uint8_t) 101)
end_define

begin_define
define|#
directive|define
name|TAG_IPX_COMPAT
value|((uint8_t) 110)
end_define

begin_define
define|#
directive|define
name|TAG_NETINFO_PARENT
value|((uint8_t) 112)
end_define

begin_define
define|#
directive|define
name|TAG_NETINFO_PARENT_TAG
value|((uint8_t) 113)
end_define

begin_define
define|#
directive|define
name|TAG_URL
value|((uint8_t) 114)
end_define

begin_define
define|#
directive|define
name|TAG_FAILOVER
value|((uint8_t) 115)
end_define

begin_define
define|#
directive|define
name|TAG_EXTENDED_REQUEST
value|((uint8_t) 126)
end_define

begin_define
define|#
directive|define
name|TAG_EXTENDED_OPTION
value|((uint8_t) 127)
end_define

begin_comment
comment|/* DHCP Message types (values for TAG_DHCP_MESSAGE option) */
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
comment|/*  * "vendor" data permitted for CMU bootp clients.  */
end_comment

begin_struct
struct|struct
name|cmu_vend
block|{
name|uint8_t
name|v_magic
index|[
literal|4
index|]
decl_stmt|;
comment|/* magic number */
name|uint32_t
name|v_flags
decl_stmt|;
comment|/* flags/opcodes, etc. */
name|struct
name|in_addr
name|v_smask
decl_stmt|;
comment|/* Subnet mask */
name|struct
name|in_addr
name|v_dgate
decl_stmt|;
comment|/* Default gateway */
name|struct
name|in_addr
name|v_dns1
decl_stmt|,
name|v_dns2
decl_stmt|;
comment|/* Domain name servers */
name|struct
name|in_addr
name|v_ins1
decl_stmt|,
name|v_ins2
decl_stmt|;
comment|/* IEN-116 name servers */
name|struct
name|in_addr
name|v_ts1
decl_stmt|,
name|v_ts2
decl_stmt|;
comment|/* Time servers */
name|uint8_t
name|v_unused
index|[
literal|24
index|]
decl_stmt|;
comment|/* currently unused */
block|}
name|UNALIGNED
struct|;
end_struct

begin_comment
comment|/* v_flags values */
end_comment

begin_define
define|#
directive|define
name|VF_SMASK
value|1
end_define

begin_comment
comment|/* Subnet mask field contains valid data */
end_comment

begin_comment
comment|/* RFC 4702 DHCP Client FQDN Option */
end_comment

begin_define
define|#
directive|define
name|CLIENT_FQDN_FLAGS_S
value|0x01
end_define

begin_define
define|#
directive|define
name|CLIENT_FQDN_FLAGS_O
value|0x02
end_define

begin_define
define|#
directive|define
name|CLIENT_FQDN_FLAGS_E
value|0x04
end_define

begin_define
define|#
directive|define
name|CLIENT_FQDN_FLAGS_N
value|0x08
end_define

end_unit

