begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_arp.h	7.3 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Address Resolution Protocol.  *  * See RFC 826 for protocol description.  ARP packets are variable  * in size; the arphdr structure defines the fixed-length portion.  * Protocol type values are the same as those for 10 Mb/s Ethernet.  * It is followed by the variable-sized fields ar_sha, arp_spa,  * arp_tha and arp_tpa in that order, according to the lengths  * specified.  Field names used correspond to RFC 826.  */
end_comment

begin_struct
struct|struct
name|arphdr
block|{
name|u_short
name|ar_hrd
decl_stmt|;
comment|/* format of hardware address */
define|#
directive|define
name|ARPHRD_ETHER
value|1
comment|/* ethernet hardware address */
name|u_short
name|ar_pro
decl_stmt|;
comment|/* format of protocol address */
name|u_char
name|ar_hln
decl_stmt|;
comment|/* length of hardware address */
name|u_char
name|ar_pln
decl_stmt|;
comment|/* length of protocol address */
name|u_short
name|ar_op
decl_stmt|;
comment|/* one of: */
define|#
directive|define
name|ARPOP_REQUEST
value|1
comment|/* request to resolve address */
define|#
directive|define
name|ARPOP_REPLY
value|2
comment|/* response to previous request */
comment|/*  * The remaining fields are variable in size,  * according to the sizes above.  */
comment|/*	u_char	ar_sha[];	/* sender hardware address */
comment|/*	u_char	ar_spa[];	/* sender protocol address */
comment|/*	u_char	ar_tha[];	/* target hardware address */
comment|/*	u_char	ar_tpa[];	/* target protocol address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ARP ioctl request  */
end_comment

begin_struct
struct|struct
name|arpreq
block|{
name|struct
name|sockaddr
name|arp_pa
decl_stmt|;
comment|/* protocol address */
name|struct
name|sockaddr
name|arp_ha
decl_stmt|;
comment|/* hardware address */
name|int
name|arp_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  arp_flags and at_flags field values */
end_comment

begin_define
define|#
directive|define
name|ATF_INUSE
value|0x01
end_define

begin_comment
comment|/* entry in use */
end_comment

begin_define
define|#
directive|define
name|ATF_COM
value|0x02
end_define

begin_comment
comment|/* completed entry (enaddr valid) */
end_comment

begin_define
define|#
directive|define
name|ATF_PERM
value|0x04
end_define

begin_comment
comment|/* permanent entry */
end_comment

begin_define
define|#
directive|define
name|ATF_PUBL
value|0x08
end_define

begin_comment
comment|/* publish entry (respond for other host) */
end_comment

begin_define
define|#
directive|define
name|ATF_USETRAILERS
value|0x10
end_define

begin_comment
comment|/* has requested trailers */
end_comment

end_unit

