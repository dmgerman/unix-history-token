begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for tcp compression routines.  *  * $Header: /home/ncvs/src/usr.sbin/ppp/slcompress.h,v 1.8 1997/10/07 00:56:58 brian Exp $  *  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: slcompress.h,v 1.8 1997/10/07 00:56:58 brian Exp $  *  *	Van Jacobson (van@helios.ee.lbl.gov), Dec 31, 1989:  *	- Initial distribution.  */
end_comment

begin_define
define|#
directive|define
name|MAX_STATES
value|16
end_define

begin_comment
comment|/* must be> 2 and< 256 */
end_comment

begin_define
define|#
directive|define
name|MAX_HDR
value|128
end_define

begin_comment
comment|/* XXX 4bsd-ism: should really be 128 */
end_comment

begin_comment
comment|/*  * Compressed packet format:  *  * The first octet contains the packet type (top 3 bits), TCP  * 'push' bit, and flags that indicate which of the 4 TCP sequence  * numbers have changed (bottom 5 bits).  The next octet is a  * conversation number that associates a saved IP/TCP header with  * the compressed packet.  The next two octets are the TCP checksum  * from the original datagram.  The next 0 to 15 octets are  * sequence number changes, one change per bit set in the header  * (there may be no changes and there are two special cases where  * the receiver implicitly knows what changed -- see below).  *  * There are 5 numbers which can change (they are always inserted  * in the following order): TCP urgent pointer, window,  * acknowlegement, sequence number and IP ID.  (The urgent pointer  * is different from the others in that its value is sent, not the  * change in value.)  Since typical use of SLIP links is biased  * toward small packets (see comments on MTU/MSS below), changes  * use a variable length coding with one octet for numbers in the  * range 1 - 255 and 3 octets (0, MSB, LSB) for numbers in the  * range 256 - 65535 or 0.  (If the change in sequence number or  * ack is more than 65535, an uncompressed packet is sent.)  */
end_comment

begin_comment
comment|/*  * Packet types (must not conflict with IP protocol version)  *  * The top nibble of the first octet is the packet type.  There are  * three possible types: IP (not proto TCP or tcp with one of the  * control flags set); uncompressed TCP (a normal IP/TCP packet but  * with the 8-bit protocol field replaced by an 8-bit connection id --  * this type of packet syncs the sender& receiver); and compressed  * TCP (described above).  *  * LSB of 4-bit field is TCP "PUSH" bit (a worthless anachronism) and  * is logically part of the 4-bit "changes" field that follows.  Top  * three bits are actual packet type.  For backward compatibility  * and in the interest of conserving bits, numbers are chosen so the  * IP protocol version number (4) which normally appears in this nibble  * means "IP packet".  */
end_comment

begin_comment
comment|/* packet types */
end_comment

begin_define
define|#
directive|define
name|TYPE_IP
value|0x40
end_define

begin_define
define|#
directive|define
name|TYPE_UNCOMPRESSED_TCP
value|0x70
end_define

begin_define
define|#
directive|define
name|TYPE_COMPRESSED_TCP
value|0x80
end_define

begin_define
define|#
directive|define
name|TYPE_ERROR
value|0x00
end_define

begin_comment
comment|/* Bits in first octet of compressed packet */
end_comment

begin_define
define|#
directive|define
name|NEW_C
value|0x40
end_define

begin_comment
comment|/* flag bits for what changed in a packet */
end_comment

begin_define
define|#
directive|define
name|NEW_I
value|0x20
end_define

begin_define
define|#
directive|define
name|NEW_S
value|0x08
end_define

begin_define
define|#
directive|define
name|NEW_A
value|0x04
end_define

begin_define
define|#
directive|define
name|NEW_W
value|0x02
end_define

begin_define
define|#
directive|define
name|NEW_U
value|0x01
end_define

begin_comment
comment|/* reserved, special-case values of above */
end_comment

begin_define
define|#
directive|define
name|SPECIAL_I
value|(NEW_S|NEW_W|NEW_U)
end_define

begin_comment
comment|/* echoed interactive traffic */
end_comment

begin_define
define|#
directive|define
name|SPECIAL_D
value|(NEW_S|NEW_A|NEW_W|NEW_U)
end_define

begin_comment
comment|/* unidirectional data */
end_comment

begin_define
define|#
directive|define
name|SPECIALS_MASK
value|(NEW_S|NEW_A|NEW_W|NEW_U)
end_define

begin_define
define|#
directive|define
name|TCP_PUSH_BIT
value|0x10
end_define

begin_comment
comment|/*  * "state" data for each active tcp conversation on the wire.  This is  * basically a copy of the entire IP/TCP header from the last packet  * we saw from the conversation together with a small identifier  * the transmit& receive ends of the line use to locate saved header.  */
end_comment

begin_struct
struct|struct
name|cstate
block|{
name|struct
name|cstate
modifier|*
name|cs_next
decl_stmt|;
comment|/* next most recently used cstate (xmit only) */
name|u_short
name|cs_hlen
decl_stmt|;
comment|/* size of hdr (receive only) */
name|u_char
name|cs_id
decl_stmt|;
comment|/* connection # associated with this state */
name|u_char
name|cs_filler
decl_stmt|;
union|union
block|{
name|char
name|csu_hdr
index|[
name|MAX_HDR
index|]
decl_stmt|;
name|struct
name|ip
name|csu_ip
decl_stmt|;
comment|/* ip/tcp hdr from most recent packet */
block|}
name|slcs_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cs_ip
value|slcs_u.csu_ip
end_define

begin_define
define|#
directive|define
name|cs_hdr
value|slcs_u.csu_hdr
end_define

begin_comment
comment|/*  * all the state data for one serial line (we need one of these  * per line).  */
end_comment

begin_struct
struct|struct
name|slcompress
block|{
name|struct
name|cstate
modifier|*
name|last_cs
decl_stmt|;
comment|/* most recently used tstate */
name|u_char
name|last_recv
decl_stmt|;
comment|/* last rcvd conn. id */
name|u_char
name|last_xmit
decl_stmt|;
comment|/* last sent conn. id */
name|u_short
name|flags
decl_stmt|;
name|struct
name|cstate
name|tstate
index|[
name|MAX_STATES
index|]
decl_stmt|;
comment|/* xmit connection states */
name|struct
name|cstate
name|rstate
index|[
name|MAX_STATES
index|]
decl_stmt|;
comment|/* receive connection states */
block|}
struct|;
end_struct

begin_comment
comment|/* flag values */
end_comment

begin_define
define|#
directive|define
name|SLF_TOSS
value|1
end_define

begin_comment
comment|/* tossing rcvd frames because of input err */
end_comment

begin_function_decl
specifier|extern
name|void
name|sl_compress_init
parameter_list|(
name|struct
name|slcompress
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_char
name|sl_compress_tcp
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|slcompress
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sl_uncompress_tcp
parameter_list|(
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|slcompress
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ReportCompress
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

