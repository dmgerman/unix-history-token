begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *      @(#)nameser.h	5.28 (Berkeley) %G%  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NAMESER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NAMESER_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
comment|/* non standard - supports ALLOW_UPDATES stuff from Mike Schwartz */
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
comment|/* delete all named resource record */
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

begin_define
define|#
directive|define
name|T_TXT
value|16
end_define

begin_comment
comment|/* text strings */
end_comment

begin_define
define|#
directive|define
name|T_RP
value|17
end_define

begin_comment
comment|/* responsible person */
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
comment|/* for chaos net (MIT) */
end_comment

begin_define
define|#
directive|define
name|C_HS
value|4
end_define

begin_comment
comment|/* for Hesiod name server (MIT) (XXX) */
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

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* least-significant byte first (vax, pc) */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* most-significant byte first (IBM, net) */
end_comment

begin_define
define|#
directive|define
name|PDP_ENDIAN
value|3412
end_define

begin_comment
comment|/* LSB first in word, MSW first in long (pdp)*/
end_comment

begin_if
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
name|sun386
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MIPSEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_MIPSEL
argument_list|)
operator|||
name|defined
argument_list|(
name|BIT_ZERO_ON_RIGHT
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha
argument_list|)
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
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
name|mc68000
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|is68k
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|ibm032
argument_list|)
operator|||
name|defined
argument_list|(
name|ibm370
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MIPSEB
argument_list|)
operator|||
name|defined
argument_list|(
name|_MIPSEB
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|apollo
argument_list|)
operator|||
name|defined
argument_list|(
name|hp9000
argument_list|)
operator|||
name|defined
argument_list|(
name|hp9000s300
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|BIT_ZERO_ON_LEFT
argument_list|)
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|||
expr|\
operator|(
name|BYTE_ORDER
operator|!=
name|BIG_ENDIAN
operator|&&
name|BYTE_ORDER
operator|!=
name|LITTLE_ENDIAN
operator|&&
expr|\
name|BYTE_ORDER
operator|!=
name|PDP_ENDIAN
operator|)
end_if

begin_comment
comment|/* you must determine what the correct bit order is for 	 * your compiler - the next line is an intentional error 	 * which will force your compiles to bomb until you fix 	 * the above macros. 	 */
end_comment

begin_error
error|#
directive|error
literal|"Undefined or invalid BYTE_ORDER"
error|;
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure for query header.  The order of the fields is machine- and  * compiler-dependent, depending on the byte/bit order and the layout  * of bit fields.  We use bit fields only in int variables, as this  * is all ANSI requires.  This requires a somewhat confusing rearrangement.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|id
decl_stmt|;
comment|/* query identification number */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
comment|/* fields in third byte */
name|u_int
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
name|u_int
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|u_int
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritive answer */
name|u_int
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|u_int
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
comment|/* fields in fourth byte */
name|u_int
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
name|u_int
name|pr
range|:
literal|1
decl_stmt|;
comment|/* primary server required (non standard) */
name|u_int
name|unused
range|:
literal|2
decl_stmt|;
comment|/* unused bits */
name|u_int
name|rcode
range|:
literal|4
decl_stmt|;
comment|/* response code */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|||
name|BYTE_ORDER
operator|==
name|PDP_ENDIAN
comment|/* fields in third byte */
name|u_int
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
name|u_int
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|u_int
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritive answer */
name|u_int
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|u_int
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
comment|/* fields in fourth byte */
name|u_int
name|rcode
range|:
literal|4
decl_stmt|;
comment|/* response code */
name|u_int
name|unused
range|:
literal|2
decl_stmt|;
comment|/* unused bits */
name|u_int
name|pr
range|:
literal|1
decl_stmt|;
comment|/* primary server required (non standard) */
name|u_int
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
endif|#
directive|endif
comment|/* remaining bytes */
name|u_int16_t
name|qdcount
decl_stmt|;
comment|/* number of question entries */
name|u_int16_t
name|ancount
decl_stmt|;
comment|/* number of answer entries */
name|u_int16_t
name|nscount
decl_stmt|;
comment|/* number of authority entries */
name|u_int16_t
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
name|int16_t
name|r_zone
decl_stmt|;
comment|/* zone number */
name|int16_t
name|r_class
decl_stmt|;
comment|/* class number */
name|int16_t
name|r_type
decl_stmt|;
comment|/* type number */
name|u_int32_t
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
name|u_int16_t
name|_getshort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|_getlong
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Inline versions of get/put short/long.  Pointer is advanced.  * We also assume that a "u_int16_t" holds 2 "chars"  * and that a "u_int32_t" holds 4 "chars".  *  * These macros demonstrate the property of C whereby it can be  * portable or it can be elegant but never both.  */
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
value|{ \ 	register u_char *t_cp = (u_char *)(cp); \ 	(s) = ((u_int16_t)t_cp[0]<< 8) | (u_int16_t)t_cp[1]; \ 	(cp) += 2; \ }
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
value|{ \ 	register u_char *t_cp = (u_char *)(cp); \ 	(l) = (((u_int32_t)t_cp[0])<< 24) \ 	    | (((u_int32_t)t_cp[1])<< 16) \ 	    | (((u_int32_t)t_cp[2])<< 8) \ 	    | (((u_int32_t)t_cp[3])); \ 	(cp) += 4; \ }
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
value|{ \ 	register u_int16_t t_s = (u_int16_t)(s); \ 	register u_char *t_cp = (u_char *)(cp); \ 	*t_cp++ = t_s>> 8; \ 	*t_cp   = t_s; \ 	(cp) += 2; \ }
end_define

begin_comment
comment|/*  * Warning: PUTLONG --no-longer-- destroys its first argument.  if you  * were depending on this "feature", you will lose.  */
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
value|{ \ 	register u_int32_t t_l = (u_int32_t)(l); \ 	register u_char *t_cp = (u_char *)(cp); \ 	*t_cp++ = t_l>> 24; \ 	*t_cp++ = t_l>> 16; \ 	*t_cp++ = t_l>> 8; \ 	*t_cp   = t_l; \ 	(cp) += 4; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NAMESER_H_ */
end_comment

end_unit

