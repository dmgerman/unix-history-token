begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ip.h	7.7 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * Definitions for internet protocol version 4.  * Per RFC 791, September 1981.  */
end_comment

begin_define
define|#
directive|define
name|IPVERSION
value|4
end_define

begin_comment
comment|/*  * Structure of an internet header, naked of options.  *  * We declare ip_len and ip_off to be short, rather than u_short  * pragmatically since otherwise unsigned comparisons can result  * against negative integers quite easily, and fail in subtle ways.  */
end_comment

begin_struct
struct|struct
name|ip
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_char
name|ip_hl
range|:
literal|4
decl_stmt|,
comment|/* header length */
name|ip_v
range|:
literal|4
decl_stmt|;
comment|/* version */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|ip_v
range|:
literal|4
decl_stmt|,
comment|/* version */
name|ip_hl
range|:
literal|4
decl_stmt|;
comment|/* header length */
endif|#
directive|endif
name|u_char
name|ip_tos
decl_stmt|;
comment|/* type of service */
name|short
name|ip_len
decl_stmt|;
comment|/* total length */
name|u_short
name|ip_id
decl_stmt|;
comment|/* identification */
name|short
name|ip_off
decl_stmt|;
comment|/* fragment offset field */
define|#
directive|define
name|IP_DF
value|0x4000
comment|/* dont fragment flag */
define|#
directive|define
name|IP_MF
value|0x2000
comment|/* more fragments flag */
name|u_char
name|ip_ttl
decl_stmt|;
comment|/* time to live */
name|u_char
name|ip_p
decl_stmt|;
comment|/* protocol */
name|u_short
name|ip_sum
decl_stmt|;
comment|/* checksum */
name|struct
name|in_addr
name|ip_src
decl_stmt|,
name|ip_dst
decl_stmt|;
comment|/* source and dest address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IP_MAXPACKET
value|65535
end_define

begin_comment
comment|/* maximum packet size */
end_comment

begin_comment
comment|/*  * Definitions for options.  */
end_comment

begin_define
define|#
directive|define
name|IPOPT_COPIED
parameter_list|(
name|o
parameter_list|)
value|((o)&0x80)
end_define

begin_define
define|#
directive|define
name|IPOPT_CLASS
parameter_list|(
name|o
parameter_list|)
value|((o)&0x60)
end_define

begin_define
define|#
directive|define
name|IPOPT_NUMBER
parameter_list|(
name|o
parameter_list|)
value|((o)&0x1f)
end_define

begin_define
define|#
directive|define
name|IPOPT_CONTROL
value|0x00
end_define

begin_define
define|#
directive|define
name|IPOPT_RESERVED1
value|0x20
end_define

begin_define
define|#
directive|define
name|IPOPT_DEBMEAS
value|0x40
end_define

begin_define
define|#
directive|define
name|IPOPT_RESERVED2
value|0x60
end_define

begin_define
define|#
directive|define
name|IPOPT_EOL
value|0
end_define

begin_comment
comment|/* end of option list */
end_comment

begin_define
define|#
directive|define
name|IPOPT_NOP
value|1
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|IPOPT_RR
value|7
end_define

begin_comment
comment|/* record packet route */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS
value|68
end_define

begin_comment
comment|/* timestamp */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SECURITY
value|130
end_define

begin_comment
comment|/* provide s,c,h,tcc */
end_comment

begin_define
define|#
directive|define
name|IPOPT_LSRR
value|131
end_define

begin_comment
comment|/* loose source route */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SATID
value|136
end_define

begin_comment
comment|/* satnet id */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SSRR
value|137
end_define

begin_comment
comment|/* strict source route */
end_comment

begin_comment
comment|/*  * Offsets to fields in options other than EOL and NOP.  */
end_comment

begin_define
define|#
directive|define
name|IPOPT_OPTVAL
value|0
end_define

begin_comment
comment|/* option ID */
end_comment

begin_define
define|#
directive|define
name|IPOPT_OLEN
value|1
end_define

begin_comment
comment|/* option length */
end_comment

begin_define
define|#
directive|define
name|IPOPT_OFFSET
value|2
end_define

begin_comment
comment|/* offset within option */
end_comment

begin_define
define|#
directive|define
name|IPOPT_MINOFF
value|4
end_define

begin_comment
comment|/* min value of above */
end_comment

begin_comment
comment|/*  * Time stamp option structure.  */
end_comment

begin_struct
struct|struct
name|ip_timestamp
block|{
name|u_char
name|ipt_code
decl_stmt|;
comment|/* IPOPT_TS */
name|u_char
name|ipt_len
decl_stmt|;
comment|/* size of structure (variable) */
name|u_char
name|ipt_ptr
decl_stmt|;
comment|/* index of current entry */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_char
name|ipt_flg
range|:
literal|4
decl_stmt|,
comment|/* flags, see below */
name|ipt_oflw
range|:
literal|4
decl_stmt|;
comment|/* overflow counter */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|ipt_oflw
range|:
literal|4
decl_stmt|,
comment|/* overflow counter */
name|ipt_flg
range|:
literal|4
decl_stmt|;
comment|/* flags, see below */
endif|#
directive|endif
union|union
name|ipt_timestamp
block|{
name|n_long
name|ipt_time
index|[
literal|1
index|]
decl_stmt|;
struct|struct
name|ipt_ta
block|{
name|struct
name|in_addr
name|ipt_addr
decl_stmt|;
name|n_long
name|ipt_time
decl_stmt|;
block|}
name|ipt_ta
index|[
literal|1
index|]
struct|;
block|}
name|ipt_timestamp
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* flag bits for ipt_flg */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS_TSONLY
value|0
end_define

begin_comment
comment|/* timestamps only */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS_TSANDADDR
value|1
end_define

begin_comment
comment|/* timestamps and addresses */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS_PRESPEC
value|2
end_define

begin_comment
comment|/* specified modules only */
end_comment

begin_comment
comment|/* bits for security (not byte swapped) */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SECUR_UNCLASS
value|0x0000
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_CONFID
value|0xf135
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_EFTO
value|0x789a
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_MMMM
value|0xbc4d
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_RESTR
value|0xaf13
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_SECRET
value|0xd788
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_TOPSECRET
value|0x6bc5
end_define

begin_comment
comment|/*  * Internet implementation parameters.  */
end_comment

begin_define
define|#
directive|define
name|MAXTTL
value|255
end_define

begin_comment
comment|/* maximum time to live (seconds) */
end_comment

begin_define
define|#
directive|define
name|IPFRAGTTL
value|60
end_define

begin_comment
comment|/* time to live for frags, slowhz */
end_comment

begin_define
define|#
directive|define
name|IPTTLDEC
value|1
end_define

begin_comment
comment|/* subtracted when forwarding */
end_comment

begin_define
define|#
directive|define
name|IP_MSS
value|576
end_define

begin_comment
comment|/* default maximum segment size */
end_comment

end_unit

