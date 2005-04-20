begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: bootp.h,v 1.4 1997/09/06 13:55:57 drochner Exp $	*/
end_comment

begin_comment
comment|/*  * Bootstrap Protocol (BOOTP).  RFC951 and RFC1048.  *  * This file specifies the "implementation-independent" BOOTP protocol  * information which is common to both client and server.  *  * Copyright 1988 by Carnegie Mellon.  *  * Permission to use, copy, modify, and distribute this program for any  * purpose and without fee is hereby granted, provided that this copyright  * and permission notice appear on all copies and supporting documentation,  * the name of Carnegie Mellon not be used in advertising or publicity  * pertaining to distribution of the program without specific prior  * permission, and notice be given in supporting documentation that copying  * and distribution is by permission of Carnegie Mellon and Stanford  * University.  Carnegie Mellon makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * $FreeBSD$  */
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
name|unsigned
name|int
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
ifdef|#
directive|ifdef
name|SUPPORT_DHCP
define|#
directive|define
name|BOOTP_VENDSIZE
value|312
else|#
directive|else
define|#
directive|define
name|BOOTP_VENDSIZE
value|64
endif|#
directive|endif
name|unsigned
name|char
name|bp_vend
index|[
name|BOOTP_VENDSIZE
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
name|TAG_DUMPFILE
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
name|TAG_SWAPSERVER
value|((unsigned char)  16)
end_define

begin_define
define|#
directive|define
name|TAG_ROOTPATH
value|((unsigned char)  17)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_DHCP
end_ifdef

begin_define
define|#
directive|define
name|TAG_REQ_ADDR
value|((unsigned char)  50)
end_define

begin_define
define|#
directive|define
name|TAG_LEASETIME
value|((unsigned char)  51)
end_define

begin_define
define|#
directive|define
name|TAG_OVERLOAD
value|((unsigned char)  52)
end_define

begin_define
define|#
directive|define
name|TAG_DHCP_MSGTYPE
value|((unsigned char)  53)
end_define

begin_define
define|#
directive|define
name|TAG_SERVERID
value|((unsigned char)  54)
end_define

begin_define
define|#
directive|define
name|TAG_PARAM_REQ
value|((unsigned char)  55)
end_define

begin_define
define|#
directive|define
name|TAG_MSG
value|((unsigned char)  56)
end_define

begin_define
define|#
directive|define
name|TAG_MAXSIZE
value|((unsigned char)  57)
end_define

begin_define
define|#
directive|define
name|TAG_T1
value|((unsigned char)  58)
end_define

begin_define
define|#
directive|define
name|TAG_T2
value|((unsigned char)  59)
end_define

begin_define
define|#
directive|define
name|TAG_CLASSID
value|((unsigned char)  60)
end_define

begin_define
define|#
directive|define
name|TAG_CLIENTID
value|((unsigned char)  61)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TAG_END
value|((unsigned char) 255)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_DHCP
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * bootp flags  */
end_comment

begin_define
define|#
directive|define
name|BOOTP_NONE
value|0x0000
end_define

begin_comment
comment|/* No flags */
end_comment

begin_define
define|#
directive|define
name|BOOTP_PXE
value|0x0001
end_define

begin_comment
comment|/* Booting from PXE. */
end_comment

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
name|unsigned
name|int
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
literal|25
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

