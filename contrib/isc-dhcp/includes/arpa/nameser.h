begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ++Copyright++ 1983, 1989, 1993  * -  * Copyright (c) 1983, 1989, 1993  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/*  *      @(#)nameser.h	8.1 (Berkeley) 6/2/93  *	$Id: nameser.h,v 8.3 1995/08/21 01:27:12 vixie Exp   */
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
comment|/* for sizeof(struct inaddr) != 4 */
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
comment|/*#define xxx		0x3*/
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

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOW_UPDATES
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOW_UPDATES
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* authoritive answer */
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
name|pr
range|:
literal|1
decl_stmt|;
comment|/* primary server required (non standard) */
name|unsigned
name|unused
range|:
literal|2
decl_stmt|;
comment|/* unused bits (MBZ as of 4.9.3a3) */
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
comment|/* authoritive answer */
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
name|unused
range|:
literal|2
decl_stmt|;
comment|/* unused bits (MBZ as of 4.9.3a3) */
name|unsigned
name|pr
range|:
literal|1
decl_stmt|;
comment|/* primary server required (non standard) */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NAMESER_H_ */
end_comment

end_unit

