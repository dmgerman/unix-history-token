begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/bootp.h,v 1.8 1999/10/17 23:35:46 mcr Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Bootstrap Protocol (BOOTP).  RFC951 and RFC1048.  *  * This file specifies the "implementation-independent" BOOTP protocol  * information which is common to both client and server.  *  * Copyright 1988 by Carnegie Mellon.  *  * Permission to use, copy, modify, and distribute this program for any  * purpose and without fee is hereby granted, provided that this copyright  * and permission notice appear on all copies and supporting documentation,  * the name of Carnegie Mellon not be used in advertising or publicity  * pertaining to distribution of the program without specific prior  * permission, and notice be given in supporting documentation that copying  * and distribution is by permission of Carnegie Mellon and Stanford  * University.  Carnegie Mellon makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  */
end_comment

begin_struct
struct|struct
name|bootp
block|{
name|unsigned
name|char
name|bp_op
decl_stmt|;
comment|/* packet opcode type */
name|unsigned
name|char
name|bp_htype
decl_stmt|;
comment|/* hardware addr type */
name|unsigned
name|char
name|bp_hlen
decl_stmt|;
comment|/* hardware addr length */
name|unsigned
name|char
name|bp_hops
decl_stmt|;
comment|/* gateway hops */
name|u_int32_t
name|bp_xid
decl_stmt|;
comment|/* transaction ID */
name|unsigned
name|short
name|bp_secs
decl_stmt|;
comment|/* seconds since boot began */
name|unsigned
name|short
name|bp_flags
decl_stmt|;
comment|/* flags: 0x8000 is broadcast */
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
name|unsigned
name|char
name|bp_chaddr
index|[
literal|16
index|]
decl_stmt|;
comment|/* client hardware address */
name|unsigned
name|char
name|bp_sname
index|[
literal|64
index|]
decl_stmt|;
comment|/* server host name */
name|unsigned
name|char
name|bp_file
index|[
literal|128
index|]
decl_stmt|;
comment|/* boot file name */
name|unsigned
name|char
name|bp_vend
index|[
literal|64
index|]
decl_stmt|;
comment|/* vendor-specific area */
block|}
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
name|BOOTREPLY
value|2
end_define

begin_define
define|#
directive|define
name|BOOTREQUEST
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
value|((unsigned char)   0)
end_define

begin_define
define|#
directive|define
name|TAG_SUBNET_MASK
value|((unsigned char)   1)
end_define

begin_define
define|#
directive|define
name|TAG_TIME_OFFSET
value|((unsigned char)   2)
end_define

begin_define
define|#
directive|define
name|TAG_GATEWAY
value|((unsigned char)   3)
end_define

begin_define
define|#
directive|define
name|TAG_TIME_SERVER
value|((unsigned char)   4)
end_define

begin_define
define|#
directive|define
name|TAG_NAME_SERVER
value|((unsigned char)   5)
end_define

begin_define
define|#
directive|define
name|TAG_DOMAIN_SERVER
value|((unsigned char)   6)
end_define

begin_define
define|#
directive|define
name|TAG_LOG_SERVER
value|((unsigned char)   7)
end_define

begin_define
define|#
directive|define
name|TAG_COOKIE_SERVER
value|((unsigned char)   8)
end_define

begin_define
define|#
directive|define
name|TAG_LPR_SERVER
value|((unsigned char)   9)
end_define

begin_define
define|#
directive|define
name|TAG_IMPRESS_SERVER
value|((unsigned char)  10)
end_define

begin_define
define|#
directive|define
name|TAG_RLP_SERVER
value|((unsigned char)  11)
end_define

begin_define
define|#
directive|define
name|TAG_HOSTNAME
value|((unsigned char)  12)
end_define

begin_define
define|#
directive|define
name|TAG_BOOTSIZE
value|((unsigned char)  13)
end_define

begin_define
define|#
directive|define
name|TAG_END
value|((unsigned char) 255)
end_define

begin_comment
comment|/* RFC1497 tags */
end_comment

begin_define
define|#
directive|define
name|TAG_DUMPPATH
value|((unsigned char)  14)
end_define

begin_define
define|#
directive|define
name|TAG_DOMAINNAME
value|((unsigned char)  15)
end_define

begin_define
define|#
directive|define
name|TAG_SWAP_SERVER
value|((unsigned char)  16)
end_define

begin_define
define|#
directive|define
name|TAG_ROOTPATH
value|((unsigned char)  17)
end_define

begin_define
define|#
directive|define
name|TAG_EXTPATH
value|((unsigned char)  18)
end_define

begin_comment
comment|/* RFC2132 */
end_comment

begin_define
define|#
directive|define
name|TAG_IP_FORWARD
value|((unsigned char)  19)
end_define

begin_define
define|#
directive|define
name|TAG_NL_SRCRT
value|((unsigned char)  20)
end_define

begin_define
define|#
directive|define
name|TAG_PFILTERS
value|((unsigned char)  21)
end_define

begin_define
define|#
directive|define
name|TAG_REASS_SIZE
value|((unsigned char)  22)
end_define

begin_define
define|#
directive|define
name|TAG_DEF_TTL
value|((unsigned char)  23)
end_define

begin_define
define|#
directive|define
name|TAG_MTU_TIMEOUT
value|((unsigned char)  24)
end_define

begin_define
define|#
directive|define
name|TAG_MTU_TABLE
value|((unsigned char)  25)
end_define

begin_define
define|#
directive|define
name|TAG_INT_MTU
value|((unsigned char)  26)
end_define

begin_define
define|#
directive|define
name|TAG_LOCAL_SUBNETS
value|((unsigned char)  27)
end_define

begin_define
define|#
directive|define
name|TAG_BROAD_ADDR
value|((unsigned char)  28)
end_define

begin_define
define|#
directive|define
name|TAG_DO_MASK_DISC
value|((unsigned char)  29)
end_define

begin_define
define|#
directive|define
name|TAG_SUPPLY_MASK
value|((unsigned char)  30)
end_define

begin_define
define|#
directive|define
name|TAG_DO_RDISC
value|((unsigned char)  31)
end_define

begin_define
define|#
directive|define
name|TAG_RTR_SOL_ADDR
value|((unsigned char)  32)
end_define

begin_define
define|#
directive|define
name|TAG_STATIC_ROUTE
value|((unsigned char)  33)
end_define

begin_define
define|#
directive|define
name|TAG_USE_TRAILERS
value|((unsigned char)  34)
end_define

begin_define
define|#
directive|define
name|TAG_ARP_TIMEOUT
value|((unsigned char)  35)
end_define

begin_define
define|#
directive|define
name|TAG_ETH_ENCAP
value|((unsigned char)  36)
end_define

begin_define
define|#
directive|define
name|TAG_TCP_TTL
value|((unsigned char)  37)
end_define

begin_define
define|#
directive|define
name|TAG_TCP_KEEPALIVE
value|((unsigned char)  38)
end_define

begin_define
define|#
directive|define
name|TAG_KEEPALIVE_GO
value|((unsigned char)  39)
end_define

begin_define
define|#
directive|define
name|TAG_NIS_DOMAIN
value|((unsigned char)  40)
end_define

begin_define
define|#
directive|define
name|TAG_NIS_SERVERS
value|((unsigned char)  41)
end_define

begin_define
define|#
directive|define
name|TAG_NTP_SERVERS
value|((unsigned char)  42)
end_define

begin_define
define|#
directive|define
name|TAG_VENDOR_OPTS
value|((unsigned char)  43)
end_define

begin_define
define|#
directive|define
name|TAG_NETBIOS_NS
value|((unsigned char)  44)
end_define

begin_define
define|#
directive|define
name|TAG_NETBIOS_DDS
value|((unsigned char)  45)
end_define

begin_define
define|#
directive|define
name|TAG_NETBIOS_NODE
value|((unsigned char)  46)
end_define

begin_define
define|#
directive|define
name|TAG_NETBIOS_SCOPE
value|((unsigned char)  47)
end_define

begin_define
define|#
directive|define
name|TAG_XWIN_FS
value|((unsigned char)  48)
end_define

begin_define
define|#
directive|define
name|TAG_XWIN_DM
value|((unsigned char)  49)
end_define

begin_define
define|#
directive|define
name|TAG_NIS_P_DOMAIN
value|((unsigned char)  64)
end_define

begin_define
define|#
directive|define
name|TAG_NIS_P_SERVERS
value|((unsigned char)  65)
end_define

begin_define
define|#
directive|define
name|TAG_MOBILE_HOME
value|((unsigned char)  68)
end_define

begin_define
define|#
directive|define
name|TAG_SMPT_SERVER
value|((unsigned char)  69)
end_define

begin_define
define|#
directive|define
name|TAG_POP3_SERVER
value|((unsigned char)  70)
end_define

begin_define
define|#
directive|define
name|TAG_NNTP_SERVER
value|((unsigned char)  71)
end_define

begin_define
define|#
directive|define
name|TAG_WWW_SERVER
value|((unsigned char)  72)
end_define

begin_define
define|#
directive|define
name|TAG_FINGER_SERVER
value|((unsigned char)  73)
end_define

begin_define
define|#
directive|define
name|TAG_IRC_SERVER
value|((unsigned char)  74)
end_define

begin_define
define|#
directive|define
name|TAG_STREETTALK_SRVR
value|((unsigned char)  75)
end_define

begin_define
define|#
directive|define
name|TAG_STREETTALK_STDA
value|((unsigned char)  76)
end_define

begin_comment
comment|/* DHCP options */
end_comment

begin_define
define|#
directive|define
name|TAG_REQUESTED_IP
value|((unsigned char)  50)
end_define

begin_define
define|#
directive|define
name|TAG_IP_LEASE
value|((unsigned char)  51)
end_define

begin_define
define|#
directive|define
name|TAG_OPT_OVERLOAD
value|((unsigned char)  52)
end_define

begin_define
define|#
directive|define
name|TAG_TFTP_SERVER
value|((unsigned char)  66)
end_define

begin_define
define|#
directive|define
name|TAG_BOOTFILENAME
value|((unsigned char)  67)
end_define

begin_define
define|#
directive|define
name|TAG_DHCP_MESSAGE
value|((unsigned char)  53)
end_define

begin_define
define|#
directive|define
name|TAG_SERVER_ID
value|((unsigned char)  54)
end_define

begin_define
define|#
directive|define
name|TAG_PARM_REQUEST
value|((unsigned char)  55)
end_define

begin_define
define|#
directive|define
name|TAG_MESSAGE
value|((unsigned char)  56)
end_define

begin_define
define|#
directive|define
name|TAG_MAX_MSG_SIZE
value|((unsigned char)  57)
end_define

begin_define
define|#
directive|define
name|TAG_RENEWAL_TIME
value|((unsigned char)  58)
end_define

begin_define
define|#
directive|define
name|TAG_REBIND_TIME
value|((unsigned char)  59)
end_define

begin_define
define|#
directive|define
name|TAG_VENDOR_CLASS
value|((unsigned char)  60)
end_define

begin_define
define|#
directive|define
name|TAG_CLIENT_ID
value|((unsigned char)  61)
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
name|unsigned
name|char
name|v_magic
index|[
literal|4
index|]
decl_stmt|;
comment|/* magic number */
name|u_int32_t
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
name|unsigned
name|char
name|v_unused
index|[
literal|24
index|]
decl_stmt|;
comment|/* currently unused */
block|}
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

end_unit

