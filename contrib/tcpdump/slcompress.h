begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for tcp compression routines.  *  * @(#) $Header: /tcpdump/master/tcpdump/slcompress.h,v 1.2 2000/10/09 02:03:44 guy Exp $ (LBL)  *  * Copyright (c) 1989, 1990, 1992, 1993 Regents of the University of  * California. All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	Van Jacobson (van@ee.lbl.gov), Dec 31, 1989:  *	- Initial distribution.  */
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

end_unit

