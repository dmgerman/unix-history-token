begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************           Copyright 1988, 1991 by Carnegie Mellon University                            All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of Carnegie Mellon University not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  CARNEGIE MELLON UNIVERSITY DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL CMU BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ************************************************************************/
end_comment

begin_comment
comment|/*  * Bootstrap Protocol (BOOTP).  RFC951 and RFC1395.  *  * $FreeBSD$  *  *  * This file specifies the "implementation-independent" BOOTP protocol  * information which is common to both client and server.  *  */
end_comment

begin_include
include|#
directive|include
file|"bptypes.h"
end_include

begin_comment
comment|/* for int32, u_int32 */
end_comment

begin_define
define|#
directive|define
name|BP_CHADDR_LEN
value|16
end_define

begin_define
define|#
directive|define
name|BP_SNAME_LEN
value|64
end_define

begin_define
define|#
directive|define
name|BP_FILE_LEN
value|128
end_define

begin_define
define|#
directive|define
name|BP_VEND_LEN
value|64
end_define

begin_define
define|#
directive|define
name|BP_MINPKTSZ
value|300
end_define

begin_comment
comment|/* to check sizeof(struct bootp) */
end_comment

begin_comment
comment|/* Overhead to fit a bootp message into an Ethernet packet. */
end_comment

begin_define
define|#
directive|define
name|BP_MSG_OVERHEAD
value|(14 + 20 + 8)
end_define

begin_comment
comment|/* Ethernet + IP + UDP headers */
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
name|u_int32
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
comment|/* RFC1532 broadcast, etc. */
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
name|BP_CHADDR_LEN
index|]
decl_stmt|;
comment|/* client hardware address */
name|char
name|bp_sname
index|[
name|BP_SNAME_LEN
index|]
decl_stmt|;
comment|/* server host name */
name|char
name|bp_file
index|[
name|BP_FILE_LEN
index|]
decl_stmt|;
comment|/* boot file name */
name|unsigned
name|char
name|bp_vend
index|[
name|BP_VEND_LEN
index|]
decl_stmt|;
comment|/* vendor-specific area */
comment|/* note that bp_vend can be longer, extending to end of packet. */
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
comment|/*  * Hardware types from Assigned Numbers RFC.  */
end_comment

begin_define
define|#
directive|define
name|HTYPE_ETHERNET
value|1
end_define

begin_define
define|#
directive|define
name|HTYPE_EXP_ETHERNET
value|2
end_define

begin_define
define|#
directive|define
name|HTYPE_AX25
value|3
end_define

begin_define
define|#
directive|define
name|HTYPE_PRONET
value|4
end_define

begin_define
define|#
directive|define
name|HTYPE_CHAOS
value|5
end_define

begin_define
define|#
directive|define
name|HTYPE_IEEE802
value|6
end_define

begin_define
define|#
directive|define
name|HTYPE_ARCNET
value|7
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
comment|/*  * Tag values used to specify what information is being supplied in  * the vendor (options) data area of the packet.  */
end_comment

begin_comment
comment|/* RFC 1048 */
end_comment

begin_define
define|#
directive|define
name|TAG_END
value|((unsigned char) 255)
end_define

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
name|TAG_HOST_NAME
value|((unsigned char)  12)
end_define

begin_define
define|#
directive|define
name|TAG_BOOT_SIZE
value|((unsigned char)  13)
end_define

begin_comment
comment|/* RFC 1395 */
end_comment

begin_define
define|#
directive|define
name|TAG_DUMP_FILE
value|((unsigned char)  14)
end_define

begin_define
define|#
directive|define
name|TAG_DOMAIN_NAME
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
name|TAG_ROOT_PATH
value|((unsigned char)  17)
end_define

begin_comment
comment|/* RFC 1497 */
end_comment

begin_define
define|#
directive|define
name|TAG_EXTEN_FILE
value|((unsigned char)  18)
end_define

begin_comment
comment|/* RFC 1533 */
end_comment

begin_define
define|#
directive|define
name|TAG_NIS_DOMAIN
value|((unsigned char)  40)
end_define

begin_define
define|#
directive|define
name|TAG_NIS_SERVER
value|((unsigned char)  41)
end_define

begin_define
define|#
directive|define
name|TAG_NTP_SERVER
value|((unsigned char)  42)
end_define

begin_comment
comment|/* DHCP maximum message size. */
end_comment

begin_define
define|#
directive|define
name|TAG_MAX_MSGSZ
value|((unsigned char)  57)
end_define

begin_comment
comment|/* XXX - Add new tags here */
end_comment

begin_comment
comment|/*  * "vendor" data permitted for CMU bootp clients.  */
end_comment

begin_struct
struct|struct
name|cmu_vend
block|{
name|char
name|v_magic
index|[
literal|4
index|]
decl_stmt|;
comment|/* magic number */
name|u_int32
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
name|int32
name|v_unused
index|[
literal|6
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

