begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * Portions Copyright (c) 1995 by International Business Machines, Inc.  *  * International Business Machines, Inc. (hereinafter called IBM) grants  * permission under its copyrights to use, copy, modify, and distribute this  * Software with or without fee, provided that the above copyright notice and  * all paragraphs of this notice appear in all copies, and that the name of IBM  * not be used in connection with the marketing of any product incorporating  * the Software or modifications thereof, without specific, written prior  * permission.  *  * To the extent it has a right to do so, IBM grants an immunity from suit  * under its patents, if any, for the use, sale or manufacture of products to  * the extent that such products are used for performing Domain Name System  * dynamic updates in TCP/IP networks by means of the Software.  No immunity is  * granted for any product per se or for any other function of any product.  * THE SOFTWARE IS PROVIDED "AS IS", AND IBM DISCLAIMS ALL WARRANTIES,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL,  * DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER ARISING  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE, EVEN  * IF IBM IS APPRISED OF THE POSSIBILITY OF SUCH DAMAGES.  *  *      @(#)nameser.h	8.2 (Berkeley) 2/16/94  *	From Id: nameser.h,v 8.11 1996/10/08 04:51:02 vixie Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARPA_NAMESER_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARPA_NAMESER_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * revision information.  this is the release date in YYYYMMDD format.  * it can change every day so the right thing to do with it is use it  * in preprocessor commands such as "#if (__BIND> 19931104)".  do not  * compare for equality; rather, use it to determine whether your resolver  * is new enough to contain a certain feature.  */
end_comment

begin_define
define|#
directive|define
name|__BIND
value|19960801
end_define

begin_comment
comment|/* interface version stamp */
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
value|1025
end_define

begin_comment
comment|/* maximum presentation domain name */
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

begin_define
define|#
directive|define
name|HFIXEDSZ
value|12
end_define

begin_comment
comment|/* #/bytes of fixed data in header */
end_comment

begin_define
define|#
directive|define
name|QFIXEDSZ
value|4
end_define

begin_comment
comment|/* #/bytes of fixed data in query */
end_comment

begin_define
define|#
directive|define
name|RRFIXEDSZ
value|10
end_define

begin_comment
comment|/* #/bytes of fixed data in r record */
end_comment

begin_define
define|#
directive|define
name|INT32SZ
value|4
end_define

begin_comment
comment|/* for systems without 32-bit ints */
end_comment

begin_define
define|#
directive|define
name|INT16SZ
value|2
end_define

begin_comment
comment|/* for systems without 16-bit ints */
end_comment

begin_define
define|#
directive|define
name|INADDRSZ
value|4
end_define

begin_comment
comment|/* IPv4 T_A */
end_comment

begin_define
define|#
directive|define
name|IN6ADDRSZ
value|16
end_define

begin_comment
comment|/* IPv6 T_AAAA */
end_comment

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
comment|/*#define xxx		0x3 */
end_comment

begin_comment
comment|/* 0x3 reserved */
end_comment

begin_define
define|#
directive|define
name|NS_NOTIFY_OP
value|0x4
end_define

begin_comment
comment|/* notify secondary of SOA change */
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
comment|/* canonical name */
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

begin_define
define|#
directive|define
name|T_AFSDB
value|18
end_define

begin_comment
comment|/* AFS cell database */
end_comment

begin_define
define|#
directive|define
name|T_X25
value|19
end_define

begin_comment
comment|/* X_25 calling address */
end_comment

begin_define
define|#
directive|define
name|T_ISDN
value|20
end_define

begin_comment
comment|/* ISDN calling address */
end_comment

begin_define
define|#
directive|define
name|T_RT
value|21
end_define

begin_comment
comment|/* router */
end_comment

begin_define
define|#
directive|define
name|T_NSAP
value|22
end_define

begin_comment
comment|/* NSAP address */
end_comment

begin_define
define|#
directive|define
name|T_NSAP_PTR
value|23
end_define

begin_comment
comment|/* reverse NSAP lookup (deprecated) */
end_comment

begin_define
define|#
directive|define
name|T_SIG
value|24
end_define

begin_comment
comment|/* security signature */
end_comment

begin_define
define|#
directive|define
name|T_KEY
value|25
end_define

begin_comment
comment|/* security key */
end_comment

begin_define
define|#
directive|define
name|T_PX
value|26
end_define

begin_comment
comment|/* X.400 mail mapping */
end_comment

begin_define
define|#
directive|define
name|T_GPOS
value|27
end_define

begin_comment
comment|/* geographical position (withdrawn) */
end_comment

begin_define
define|#
directive|define
name|T_AAAA
value|28
end_define

begin_comment
comment|/* IP6 Address */
end_comment

begin_define
define|#
directive|define
name|T_LOC
value|29
end_define

begin_comment
comment|/* Location Information */
end_comment

begin_define
define|#
directive|define
name|T_NXT
value|30
end_define

begin_comment
comment|/* Next Valid Name in Zone */
end_comment

begin_define
define|#
directive|define
name|T_EID
value|31
end_define

begin_comment
comment|/* Endpoint identifier */
end_comment

begin_define
define|#
directive|define
name|T_NIMLOC
value|32
end_define

begin_comment
comment|/* Nimrod locator */
end_comment

begin_define
define|#
directive|define
name|T_SRV
value|33
end_define

begin_comment
comment|/* Server selection */
end_comment

begin_define
define|#
directive|define
name|T_ATMA
value|34
end_define

begin_comment
comment|/* ATM Address */
end_comment

begin_define
define|#
directive|define
name|T_NAPTR
value|35
end_define

begin_comment
comment|/* Naming Authority PoinTeR */
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
name|T_IXFR
value|251
end_define

begin_comment
comment|/* incremental zone transfer */
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
comment|/*  * Flags field of the KEY RR rdata  */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_TYPEMASK
value|0xC000
end_define

begin_comment
comment|/* Mask for "type" bits */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_TYPE_AUTH_CONF
value|0x0000
end_define

begin_comment
comment|/* Key usable for both */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_TYPE_CONF_ONLY
value|0x8000
end_define

begin_comment
comment|/* Key usable for confidentiality */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_TYPE_AUTH_ONLY
value|0x4000
end_define

begin_comment
comment|/* Key usable for authentication */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_TYPE_NO_KEY
value|0xC000
end_define

begin_comment
comment|/* No key usable for either; no key */
end_comment

begin_comment
comment|/* The type bits can also be interpreted independently, as single bits: */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_NO_AUTH
value|0x8000
end_define

begin_comment
comment|/* Key not usable for authentication */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_NO_CONF
value|0x4000
end_define

begin_comment
comment|/* Key not usable for confidentiality */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_EXPERIMENTAL
value|0x2000
end_define

begin_comment
comment|/* Security is *mandatory* if bit=0 */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_RESERVED3
value|0x1000
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_RESERVED4
value|0x0800
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_USERACCOUNT
value|0x0400
end_define

begin_comment
comment|/* key is assoc. with a user acct */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_ENTITY
value|0x0200
end_define

begin_comment
comment|/* key is assoc. with entity eg host */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_ZONEKEY
value|0x0100
end_define

begin_comment
comment|/* key is zone key for the zone named */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_IPSEC
value|0x0080
end_define

begin_comment
comment|/* key is for IPSEC use (host or user)*/
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_EMAIL
value|0x0040
end_define

begin_comment
comment|/* key is for email (MIME security) */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_RESERVED10
value|0x0020
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_RESERVED11
value|0x0010
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_SIGNATORYMASK
value|0x000F
end_define

begin_comment
comment|/* key can sign DNS RR's of same name */
end_comment

begin_define
define|#
directive|define
name|KEYFLAG_RESERVED_BITMASK
value|( KEYFLAG_RESERVED3 | \ 				    KEYFLAG_RESERVED4 | \ 				    KEYFLAG_RESERVED10| KEYFLAG_RESERVED11)
end_define

begin_comment
comment|/* The Algorithm field of the KEY and SIG RR's is an integer, {1..254} */
end_comment

begin_define
define|#
directive|define
name|ALGORITHM_MD5RSA
value|1
end_define

begin_comment
comment|/* MD5 with RSA */
end_comment

begin_define
define|#
directive|define
name|ALGORITHM_EXPIRE_ONLY
value|253
end_define

begin_comment
comment|/* No alg, no security */
end_comment

begin_define
define|#
directive|define
name|ALGORITHM_PRIVATE_OID
value|254
end_define

begin_comment
comment|/* Key begins with OID indicating alg */
end_comment

begin_comment
comment|/* Signatures */
end_comment

begin_comment
comment|/* Size of a mod or exp in bits */
end_comment

begin_define
define|#
directive|define
name|MIN_MD5RSA_KEY_PART_BITS
value|512
end_define

begin_define
define|#
directive|define
name|MAX_MD5RSA_KEY_PART_BITS
value|2552
end_define

begin_comment
comment|/* Total of binary mod and exp, bytes */
end_comment

begin_define
define|#
directive|define
name|MAX_MD5RSA_KEY_BYTES
value|((MAX_MD5RSA_KEY_PART_BITS+7/8)*2+3)
end_define

begin_comment
comment|/* Max length of text sig block */
end_comment

begin_define
define|#
directive|define
name|MAX_KEY_BASE64
value|(((MAX_MD5RSA_KEY_BYTES+2)/3)*4)
end_define

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
value|(-1)
end_define

begin_define
define|#
directive|define
name|CONV_BADFMT
value|(-2)
end_define

begin_define
define|#
directive|define
name|CONV_BADCKSUM
value|(-3)
end_define

begin_define
define|#
directive|define
name|CONV_BADBUFLEN
value|(-4)
end_define

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/*  * Structure for query header.  The order of the fields is machine- and  * compiler-dependent, depending on the byte/bit order and the layout  * of bit fields.  We use bit fields only in int variables, as this  * is all ANSI requires.  This requires a somewhat confusing rearrangement.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|id
range|:
literal|16
decl_stmt|;
comment|/* query identification number */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
comment|/* fields in third byte */
name|unsigned
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
name|unsigned
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|unsigned
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritative answer */
name|unsigned
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|unsigned
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
comment|/* fields in fourth byte */
name|unsigned
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
name|unsigned
name|unused
range|:
literal|1
decl_stmt|;
comment|/* unused bits (MBZ as of 4.9.3a3) */
name|unsigned
name|ad
range|:
literal|1
decl_stmt|;
comment|/* authentic data from named */
name|unsigned
name|cd
range|:
literal|1
decl_stmt|;
comment|/* checking disabled by resolver */
name|unsigned
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
name|unsigned
name|rd
range|:
literal|1
decl_stmt|;
comment|/* recursion desired */
name|unsigned
name|tc
range|:
literal|1
decl_stmt|;
comment|/* truncated message */
name|unsigned
name|aa
range|:
literal|1
decl_stmt|;
comment|/* authoritative answer */
name|unsigned
name|opcode
range|:
literal|4
decl_stmt|;
comment|/* purpose of message */
name|unsigned
name|qr
range|:
literal|1
decl_stmt|;
comment|/* response flag */
comment|/* fields in fourth byte */
name|unsigned
name|rcode
range|:
literal|4
decl_stmt|;
comment|/* response code */
name|unsigned
name|cd
range|:
literal|1
decl_stmt|;
comment|/* checking disabled by resolver */
name|unsigned
name|ad
range|:
literal|1
decl_stmt|;
comment|/* authentic data from named */
name|unsigned
name|unused
range|:
literal|1
decl_stmt|;
comment|/* unused bits (MBZ as of 4.9.3a3) */
name|unsigned
name|ra
range|:
literal|1
decl_stmt|;
comment|/* recursion available */
endif|#
directive|endif
comment|/* remaining bytes */
name|unsigned
name|qdcount
range|:
literal|16
decl_stmt|;
comment|/* number of question entries */
name|unsigned
name|ancount
range|:
literal|16
decl_stmt|;
comment|/* number of answer entries */
name|unsigned
name|nscount
range|:
literal|16
decl_stmt|;
comment|/* number of authority entries */
name|unsigned
name|arcount
range|:
literal|16
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

begin_decl_stmt
specifier|extern
name|u_int16_t
name|_getshort
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|_getlong
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Inline versions of get/put short/long.  Pointer is advanced.  *  * These macros demonstrate the property of C whereby it can be  * portable or it can be elegant but rarely both.  */
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
value|{ \ 	register u_char *t_cp = (u_char *)(cp); \ 	(s) = ((u_int16_t)t_cp[0]<< 8) \ 	    | ((u_int16_t)t_cp[1]) \ 	    ; \ 	(cp) += INT16SZ; \ }
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
value|{ \ 	register u_char *t_cp = (u_char *)(cp); \ 	(l) = ((u_int32_t)t_cp[0]<< 24) \ 	    | ((u_int32_t)t_cp[1]<< 16) \ 	    | ((u_int32_t)t_cp[2]<< 8) \ 	    | ((u_int32_t)t_cp[3]) \ 	    ; \ 	(cp) += INT32SZ; \ }
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
value|{ \ 	register u_int16_t t_s = (u_int16_t)(s); \ 	register u_char *t_cp = (u_char *)(cp); \ 	*t_cp++ = t_s>> 8; \ 	*t_cp   = t_s; \ 	(cp) += INT16SZ; \ }
end_define

begin_define
define|#
directive|define
name|PUTLONG
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register u_int32_t t_l = (u_int32_t)(l); \ 	register u_char *t_cp = (u_char *)(cp); \ 	*t_cp++ = t_l>> 24; \ 	*t_cp++ = t_l>> 16; \ 	*t_cp++ = t_l>> 8; \ 	*t_cp   = t_l; \ 	(cp) += INT32SZ; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ARPA_NAMESER_H_ */
end_comment

end_unit

