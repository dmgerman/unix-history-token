begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)nameser.h	5.18 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Define constants based on rfc883  */
end_comment

begin_define
define|#
directive|define
name|PACKETSZ
value|512
end_define

begin_comment
comment|/* maximum packet size */
end_comment

begin_define
define|#
directive|define
name|MAXDNAME
value|256
end_define

begin_comment
comment|/* maximum domain name */
end_comment

begin_define
define|#
directive|define
name|MAXCDNAME
value|255
end_define

begin_comment
comment|/* maximum compressed domain name */
end_comment

begin_define
define|#
directive|define
name|MAXLABEL
value|63
end_define

begin_comment
comment|/* maximum length of domain label */
end_comment

begin_comment
comment|/* Number of bytes of fixed size data in query structure */
end_comment

begin_define
define|#
directive|define
name|QFIXEDSZ
value|4
end_define

begin_comment
comment|/* number of bytes of fixed size data in resource record */
end_comment

begin_define
define|#
directive|define
name|RRFIXEDSZ
value|10
end_define

begin_comment
comment|/*  * Internet nameserver port number  */
end_comment

begin_define
define|#
directive|define
name|NAMESERVER_PORT
value|53
end_define

begin_comment
comment|/*  * Currently defined opcodes  */
end_comment

begin_define
define|#
directive|define
name|QUERY
value|0x0
end_define

begin_comment
comment|/* standard query */
end_comment

begin_define
define|#
directive|define
name|IQUERY
value|0x1
end_define

begin_comment
comment|/* inverse query */
end_comment

begin_define
define|#
directive|define
name|STATUS
value|0x2
end_define

begin_comment
comment|/* nameserver status query */
end_comment

begin_comment
comment|/*#define xxx		0x3		/* 0x3 reserved */
end_comment

begin_comment
comment|/* non standard */
end_comment

begin_define
define|#
directive|define
name|UPDATEA
value|0x9
end_define

begin_comment
comment|/* add resource record */
end_comment

begin_define
define|#
directive|define
name|UPDATED
value|0xa
end_define

begin_comment
comment|/* delete a specific resource record */
end_comment

begin_define
define|#
directive|define
name|UPDATEDA
value|0xb
end_define

begin_comment
comment|/* delete all nemed resource record */
end_comment

begin_define
define|#
directive|define
name|UPDATEM
value|0xc
end_define

begin_comment
comment|/* modify a specific resource record */
end_comment

begin_define
define|#
directive|define
name|UPDATEMA
value|0xd
end_define

begin_comment
comment|/* modify all named resource record */
end_comment

begin_define
define|#
directive|define
name|ZONEINIT
value|0xe
end_define

begin_comment
comment|/* initial zone transfer */
end_comment

begin_define
define|#
directive|define
name|ZONEREF
value|0xf
end_define

begin_comment
comment|/* incremental zone referesh */
end_comment

begin_comment
comment|/*  * Currently defined response codes  */
end_comment

begin_define
define|#
directive|define
name|NOERROR
value|0
end_define

begin_comment
comment|/* no error */
end_comment

begin_define
define|#
directive|define
name|FORMERR
value|1
end_define

begin_comment
comment|/* format error */
end_comment

begin_define
define|#
directive|define
name|SERVFAIL
value|2
end_define

begin_comment
comment|/* server failure */
end_comment

begin_define
define|#
directive|define
name|NXDOMAIN
value|3
end_define

begin_comment
comment|/* non existent domain */
end_comment

begin_define
define|#
directive|define
name|NOTIMP
value|4
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|REFUSED
value|5
end_define

begin_comment
comment|/* query refused */
end_comment

begin_comment
comment|/* non standard */
end_comment

begin_define
define|#
directive|define
name|NOCHANGE
value|0xf
end_define

begin_comment
comment|/* update failed to change db */
end_comment

begin_comment
comment|/*  * Type values for resources and queries  */
end_comment

begin_define
define|#
directive|define
name|T_A
value|1
end_define

begin_comment
comment|/* host address */
end_comment

begin_define
define|#
directive|define
name|T_NS
value|2
end_define

begin_comment
comment|/* authoritative server */
end_comment

begin_define
define|#
directive|define
name|T_MD
value|3
end_define

begin_comment
comment|/* mail destination */
end_comment

begin_define
define|#
directive|define
name|T_MF
value|4
end_define

begin_comment
comment|/* mail forwarder */
end_comment

begin_define
define|#
directive|define
name|T_CNAME
value|5
end_define

begin_comment
comment|/* connonical name */
end_comment

begin_define
define|#
directive|define
name|T_SOA
value|6
end_define

begin_comment
comment|/* start of authority zone */
end_comment

begin_define
define|#
directive|define
name|T_MB
value|7
end_define

begin_comment
comment|/* mailbox domain name */
end_comment

begin_define
define|#
directive|define
name|T_MG
value|8
end_define

begin_comment
comment|/* mail group member */
end_comment

begin_define
define|#
directive|define
name|T_MR
value|9
end_define

begin_comment
comment|/* mail rename name */
end_comment

begin_define
define|#
directive|define
name|T_NULL
value|10
end_define

begin_comment
comment|/* null resource record */
end_comment

begin_define
define|#
directive|define
name|T_WKS
value|11
end_define

begin_comment
comment|/* well known service */
end_comment

begin_define
define|#
directive|define
name|T_PTR
value|12
end_define

begin_comment
comment|/* domain name pointer */
end_comment

begin_define
define|#
directive|define
name|T_HINFO
value|13
end_define

begin_comment
comment|/* host information */
end_comment

begin_define
define|#
directive|define
name|T_MINFO
value|14
end_define

begin_comment
comment|/* mailbox information */
end_comment

begin_define
define|#
directive|define
name|T_MX
value|15
end_define

begin_comment
comment|/* mail routing information */
end_comment

begin_comment
comment|/* non standard */
end_comment

begin_define
define|#
directive|define
name|T_UINFO
value|100
end_define

begin_comment
comment|/* user (finger) information */
end_comment

begin_define
define|#
directive|define
name|T_UID
value|101
end_define

begin_comment
comment|/* user ID */
end_comment

begin_define
define|#
directive|define
name|T_GID
value|102
end_define

begin_comment
comment|/* group ID */
end_comment

begin_define
define|#
directive|define
name|T_UNSPEC
value|103
end_define

begin_comment
comment|/* Unspecified format (binary data) */
end_comment

begin_comment
comment|/* Query type values which do not appear in resource records */
end_comment

begin_define
define|#
directive|define
name|T_AXFR
value|252
end_define

begin_comment
comment|/* transfer zone of authority */
end_comment

begin_define
define|#
directive|define
name|T_MAILB
value|253
end_define

begin_comment
comment|/* transfer mailbox records */
end_comment

begin_define
define|#
directive|define
name|T_MAILA
value|254
end_define

begin_comment
comment|/* transfer mail agent records */
end_comment

begin_define
define|#
directive|define
name|T_ANY
value|255
end_define

begin_comment
comment|/* wildcard match */
end_comment

begin_comment
comment|/*  * Values for class field  */
end_comment

begin_define
define|#
directive|define
name|C_IN
value|1
end_define

begin_comment
comment|/* the arpa internet */
end_comment

begin_define
define|#
directive|define
name|C_CHAOS
value|3
end_define

begin_comment
comment|/* for chaos net at MIT */
end_comment

begin_comment
comment|/* Query class values which do not appear in resource records */
end_comment

begin_define
define|#
directive|define
name|C_ANY
value|255
end_define

begin_comment
comment|/* wildcard match */
end_comment

begin_comment
comment|/*  * Status return codes for T_UNSPEC conversion routines  */
end_comment

begin_define
define|#
directive|define
name|CONV_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|CONV_OVERFLOW
value|-1
end_define

begin_define
define|#
directive|define
name|CONV_BADFMT
value|-2
end_define

begin_define
define|#
directive|define
name|CONV_BADCKSUM
value|-3
end_define

begin_define
define|#
directive|define
name|CONV_BADBUFLEN
value|-4
end_define

begin_comment
comment|/*  * Structure for query header, the order of the fields is machine and  * compiler dependent, in our case, the bits within a byte are assignd   * least significant first, while the order of transmition is most   * significant first.  This requires a somewhat confusing rearrangement.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|id
decl_stmt|;
comment|/* query identification number */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|sel
argument_list|)
operator|||
name|defined
argument_list|(
name|pyr
argument_list|)
operator|||
name|defined
argument_list|(
name|is68k
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|BIT_ZERO_ON_LEFT
argument_list|)
comment|/* Bit zero on left:  Gould and similar architectures */
comment|/* fields in third byte */
name|u_char
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
name|u_char
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|u_char
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritive answer */
name|u_char
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|u_char
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
comment|/* fields in fourth byte */
name|u_char
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
name|u_char
name|pr
range|:
literal|1
decl_stmt|;
comment|/* primary server required (non standard) */
name|u_char
name|unused
range|:
literal|2
decl_stmt|;
comment|/* unused bits */
name|u_char
name|rcode
range|:
literal|4
decl_stmt|;
comment|/* response code */
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|ns32000
argument_list|)
operator|||
name|defined
argument_list|(
name|BIT_ZERO_ON_RIGHT
argument_list|)
comment|/* Bit zero on right:  VAX */
comment|/* fields in third byte */
name|u_char
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
name|u_char
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|u_char
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritive answer */
name|u_char
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|u_char
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
comment|/* fields in fourth byte */
name|u_char
name|rcode
range|:
literal|4
decl_stmt|;
comment|/* response code */
name|u_char
name|unused
range|:
literal|2
decl_stmt|;
comment|/* unused bits */
name|u_char
name|pr
range|:
literal|1
decl_stmt|;
comment|/* primary server required (non standard) */
name|u_char
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
else|#
directive|else
comment|/* you must determine what the correct bit order is for your compiler */
name|UNDEFINED_BIT_ORDER
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* remaining bytes */
name|u_short
name|qdcount
decl_stmt|;
comment|/* number of question entries */
name|u_short
name|ancount
decl_stmt|;
comment|/* number of answer entries */
name|u_short
name|nscount
decl_stmt|;
comment|/* number of authority entries */
name|u_short
name|arcount
decl_stmt|;
comment|/* number of resource entries */
block|}
name|HEADER
typedef|;
end_typedef

begin_comment
comment|/*  * Defines for handling compressed domain names  */
end_comment

begin_define
define|#
directive|define
name|INDIR_MASK
value|0xc0
end_define

begin_comment
comment|/*  * Structure for passing resource records around.  */
end_comment

begin_struct
struct|struct
name|rrec
block|{
name|short
name|r_zone
decl_stmt|;
comment|/* zone number */
name|short
name|r_class
decl_stmt|;
comment|/* class number */
name|short
name|r_type
decl_stmt|;
comment|/* type number */
name|u_long
name|r_ttl
decl_stmt|;
comment|/* time to live */
name|int
name|r_size
decl_stmt|;
comment|/* size of data area */
name|char
modifier|*
name|r_data
decl_stmt|;
comment|/* pointer to data */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|u_short
name|_getshort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|_getlong
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Inline versions of get/put short/long.  * Pointer is advanced; we assume that both arguments  * are lvalues and will already be in registers.  * cp MUST be u_char *.  */
end_comment

begin_define
define|#
directive|define
name|GETSHORT
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(s) = *(cp)++<< 8; \ 	(s) |= *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|GETLONG
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(l) = *(cp)++<< 8; \ 	(l) |= *(cp)++; (l)<<= 8; \ 	(l) |= *(cp)++; (l)<<= 8; \ 	(l) |= *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTSHORT
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (s)>> 8; \ 	*(cp)++ = (s); \ }
end_define

begin_comment
comment|/*  * Warning: PUTLONG destroys its first argument.  */
end_comment

begin_define
define|#
directive|define
name|PUTLONG
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(cp)[3] = l; \ 	(cp)[2] = (l>>= 8); \ 	(cp)[1] = (l>>= 8); \ 	(cp)[0] = l>> 8; \ 	(cp) += sizeof(u_long); \ }
end_define

end_unit

