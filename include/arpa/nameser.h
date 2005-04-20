begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1989, 1993  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  *	From: Id: nameser.h,v 8.16 1998/02/06 00:35:58 halley Exp  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|BIND_4_COMPAT
end_define

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
comment|/*  * revision information.  this is the release date in YYYYMMDD format.  * it can change every day so the right thing to do with it is use it  * in preprocessor commands such as "#if (__NAMESER> 19931104)".  do not  * compare for equality; rather, use it to determine whether your libnameser.a  * is new enough to contain a certain feature.  */
end_comment

begin_comment
comment|/* XXXRTH I made this bigger than __BIND in 4.9.5 T6B */
end_comment

begin_define
define|#
directive|define
name|__NAMESER
value|19961001
end_define

begin_comment
comment|/* New interface version stamp. */
end_comment

begin_comment
comment|/*  * Define constants based on RFC 883, RFC 1034, RFC 1035  */
end_comment

begin_define
define|#
directive|define
name|NS_PACKETSZ
value|512
end_define

begin_comment
comment|/* maximum packet size */
end_comment

begin_define
define|#
directive|define
name|NS_MAXDNAME
value|1025
end_define

begin_comment
comment|/* maximum domain name */
end_comment

begin_define
define|#
directive|define
name|NS_MAXCDNAME
value|255
end_define

begin_comment
comment|/* maximum compressed domain name */
end_comment

begin_define
define|#
directive|define
name|NS_MAXLABEL
value|63
end_define

begin_comment
comment|/* maximum length of domain label */
end_comment

begin_define
define|#
directive|define
name|NS_HFIXEDSZ
value|12
end_define

begin_comment
comment|/* #/bytes of fixed data in header */
end_comment

begin_define
define|#
directive|define
name|NS_QFIXEDSZ
value|4
end_define

begin_comment
comment|/* #/bytes of fixed data in query */
end_comment

begin_define
define|#
directive|define
name|NS_RRFIXEDSZ
value|10
end_define

begin_comment
comment|/* #/bytes of fixed data in r record */
end_comment

begin_define
define|#
directive|define
name|NS_INT32SZ
value|4
end_define

begin_comment
comment|/* #/bytes of data in a u_int32_t */
end_comment

begin_define
define|#
directive|define
name|NS_INT16SZ
value|2
end_define

begin_comment
comment|/* #/bytes of data in a u_int16_t */
end_comment

begin_define
define|#
directive|define
name|NS_INT8SZ
value|1
end_define

begin_comment
comment|/* #/bytes of data in a u_int8_t */
end_comment

begin_define
define|#
directive|define
name|NS_INADDRSZ
value|4
end_define

begin_comment
comment|/* IPv4 T_A */
end_comment

begin_define
define|#
directive|define
name|NS_IN6ADDRSZ
value|16
end_define

begin_comment
comment|/* IPv6 T_AAAA */
end_comment

begin_define
define|#
directive|define
name|NS_CMPRSFLGS
value|0xc0
end_define

begin_comment
comment|/* Flag bits indicating name compression. */
end_comment

begin_define
define|#
directive|define
name|NS_DEFAULTPORT
value|53
end_define

begin_comment
comment|/* For both TCP and UDP. */
end_comment

begin_comment
comment|/*  * These can be expanded with synonyms, just keep ns_parse.c:ns_parserecord()  * in synch with it.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_sect
block|{
name|ns_s_qd
init|=
literal|0
block|,
comment|/* Query: Question. */
name|ns_s_zn
init|=
literal|0
block|,
comment|/* Update: Zone. */
name|ns_s_an
init|=
literal|1
block|,
comment|/* Query: Answer. */
name|ns_s_pr
init|=
literal|1
block|,
comment|/* Update: Prerequisites. */
name|ns_s_ns
init|=
literal|2
block|,
comment|/* Query: Name servers. */
name|ns_s_ud
init|=
literal|2
block|,
comment|/* Update: Update. */
name|ns_s_ar
init|=
literal|3
block|,
comment|/* Query|Update: Additional records. */
name|ns_s_max
init|=
literal|4
block|}
name|ns_sect
typedef|;
end_typedef

begin_comment
comment|/*  * This is a message handle.  It is caller allocated and has no dynamic data.  * This structure is intended to be opaque to all but ns_parse.c, thus the  * leading _'s on the member names.  Use the accessor functions, not the _'s.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__ns_msg
block|{
specifier|const
name|u_char
modifier|*
name|_msg
decl_stmt|,
modifier|*
name|_eom
decl_stmt|;
name|u_int16_t
name|_id
decl_stmt|,
name|_flags
decl_stmt|,
name|_counts
index|[
name|ns_s_max
index|]
decl_stmt|;
specifier|const
name|u_char
modifier|*
name|_sections
index|[
name|ns_s_max
index|]
decl_stmt|;
name|ns_sect
name|_sect
decl_stmt|;
name|int
name|_rrnum
decl_stmt|;
specifier|const
name|u_char
modifier|*
name|_ptr
decl_stmt|;
block|}
name|ns_msg
typedef|;
end_typedef

begin_comment
comment|/* Private data structure - do not use from outside library. */
end_comment

begin_struct
struct|struct
name|_ns_flagdata
block|{
name|int
name|mask
decl_stmt|,
name|shift
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|_ns_flagdata
name|_ns_flagdata
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Accessor macros - this is part of the public interface. */
end_comment

begin_define
define|#
directive|define
name|ns_msg_getflag
parameter_list|(
name|handle
parameter_list|,
name|flag
parameter_list|)
value|( \ 			((handle)._flags& _ns_flagdata[flag].mask) \>> _ns_flagdata[flag].shift \ 			)
end_define

begin_define
define|#
directive|define
name|ns_msg_id
parameter_list|(
name|handle
parameter_list|)
value|((handle)._id + 0)
end_define

begin_define
define|#
directive|define
name|ns_msg_base
parameter_list|(
name|handle
parameter_list|)
value|((handle)._msg + 0)
end_define

begin_define
define|#
directive|define
name|ns_msg_end
parameter_list|(
name|handle
parameter_list|)
value|((handle)._eom + 0)
end_define

begin_define
define|#
directive|define
name|ns_msg_size
parameter_list|(
name|handle
parameter_list|)
value|((handle)._eom - (handle)._msg)
end_define

begin_define
define|#
directive|define
name|ns_msg_count
parameter_list|(
name|handle
parameter_list|,
name|section
parameter_list|)
value|((handle)._counts[section] + 0)
end_define

begin_comment
comment|/*  * This is a parsed record.  It is caller allocated and has no dynamic data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__ns_rr
block|{
name|char
name|name
index|[
name|NS_MAXDNAME
index|]
decl_stmt|;
comment|/* XXX need to malloc */
name|u_int16_t
name|type
decl_stmt|;
name|u_int16_t
name|rr_class
decl_stmt|;
name|u_int32_t
name|ttl
decl_stmt|;
name|u_int16_t
name|rdlength
decl_stmt|;
specifier|const
name|u_char
modifier|*
name|rdata
decl_stmt|;
block|}
name|ns_rr
typedef|;
end_typedef

begin_comment
comment|/* Accessor macros - this is part of the public interface. */
end_comment

begin_define
define|#
directive|define
name|ns_rr_name
parameter_list|(
name|rr
parameter_list|)
value|(((rr).name[0] != '\0') ? (rr).name : ".")
end_define

begin_define
define|#
directive|define
name|ns_rr_type
parameter_list|(
name|rr
parameter_list|)
value|((rr).type + 0)
end_define

begin_define
define|#
directive|define
name|ns_rr_class
parameter_list|(
name|rr
parameter_list|)
value|((rr).rr_class + 0)
end_define

begin_define
define|#
directive|define
name|ns_rr_ttl
parameter_list|(
name|rr
parameter_list|)
value|((rr).ttl + 0)
end_define

begin_define
define|#
directive|define
name|ns_rr_rdlen
parameter_list|(
name|rr
parameter_list|)
value|((rr).rdlength + 0)
end_define

begin_define
define|#
directive|define
name|ns_rr_rdata
parameter_list|(
name|rr
parameter_list|)
value|((rr).rdata + 0)
end_define

begin_comment
comment|/*  * These don't have to be in the same order as in the packet flags word,  * and they can even overlap in some cases, but they will need to be kept  * in synch with ns_parse.c:ns_flagdata[].  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_flag
block|{
name|ns_f_qr
block|,
comment|/* Question/Response. */
name|ns_f_opcode
block|,
comment|/* Operation code. */
name|ns_f_aa
block|,
comment|/* Authoritative Answer. */
name|ns_f_tc
block|,
comment|/* Truncation occurred. */
name|ns_f_rd
block|,
comment|/* Recursion Desired. */
name|ns_f_ra
block|,
comment|/* Recursion Available. */
name|ns_f_z
block|,
comment|/* MBZ. */
name|ns_f_ad
block|,
comment|/* Authentic Data (DNSSEC). */
name|ns_f_cd
block|,
comment|/* Checking Disabled (DNSSEC). */
name|ns_f_rcode
block|,
comment|/* Response code. */
name|ns_f_max
block|}
name|ns_flag
typedef|;
end_typedef

begin_comment
comment|/*  * Currently defined opcodes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_opcode
block|{
name|ns_o_query
init|=
literal|0
block|,
comment|/* Standard query. */
name|ns_o_iquery
init|=
literal|1
block|,
comment|/* Inverse query (deprecated/unsupported). */
name|ns_o_status
init|=
literal|2
block|,
comment|/* Name server status query (unsupported). */
comment|/* Opcode 3 is undefined/reserved. */
name|ns_o_notify
init|=
literal|4
block|,
comment|/* Zone change notification. */
name|ns_o_update
init|=
literal|5
block|,
comment|/* Zone update message. */
name|ns_o_max
init|=
literal|6
block|}
name|ns_opcode
typedef|;
end_typedef

begin_comment
comment|/*  * Currently defined response codes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_rcode
block|{
name|ns_r_noerror
init|=
literal|0
block|,
comment|/* No error occurred. */
name|ns_r_formerr
init|=
literal|1
block|,
comment|/* Format error. */
name|ns_r_servfail
init|=
literal|2
block|,
comment|/* Server failure. */
name|ns_r_nxdomain
init|=
literal|3
block|,
comment|/* Name error. */
name|ns_r_notimpl
init|=
literal|4
block|,
comment|/* Unimplemented. */
name|ns_r_refused
init|=
literal|5
block|,
comment|/* Operation refused. */
comment|/* these are for BIND_UPDATE */
name|ns_r_yxdomain
init|=
literal|6
block|,
comment|/* Name exists */
name|ns_r_yxrrset
init|=
literal|7
block|,
comment|/* RRset exists */
name|ns_r_nxrrset
init|=
literal|8
block|,
comment|/* RRset does not exist */
name|ns_r_notauth
init|=
literal|9
block|,
comment|/* Not authoritative for zone */
name|ns_r_notzone
init|=
literal|10
block|,
comment|/* Zone of record different from zone section */
name|ns_r_max
init|=
literal|11
block|}
name|ns_rcode
typedef|;
end_typedef

begin_comment
comment|/* BIND_UPDATE */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_update_operation
block|{
name|ns_uop_delete
init|=
literal|0
block|,
name|ns_uop_add
init|=
literal|1
block|,
name|ns_uop_max
init|=
literal|2
block|}
name|ns_update_operation
typedef|;
end_typedef

begin_comment
comment|/*  * This RR-like structure is particular to UPDATE.  */
end_comment

begin_struct
struct|struct
name|ns_updrec
block|{
name|struct
name|ns_updrec
modifier|*
name|r_prev
decl_stmt|;
comment|/* prev record */
name|struct
name|ns_updrec
modifier|*
name|r_next
decl_stmt|;
comment|/* next record */
name|u_int8_t
name|r_section
decl_stmt|;
comment|/* ZONE/PREREQUISITE/UPDATE */
name|char
modifier|*
name|r_dname
decl_stmt|;
comment|/* owner of the RR */
name|u_int16_t
name|r_class
decl_stmt|;
comment|/* class number */
name|u_int16_t
name|r_type
decl_stmt|;
comment|/* type number */
name|u_int32_t
name|r_ttl
decl_stmt|;
comment|/* time to live */
name|u_char
modifier|*
name|r_data
decl_stmt|;
comment|/* rdata fields as text string */
name|u_int16_t
name|r_size
decl_stmt|;
comment|/* size of r_data field */
name|int
name|r_opcode
decl_stmt|;
comment|/* type of operation */
comment|/* following fields for private use by the resolver/server routines */
name|struct
name|ns_updrec
modifier|*
name|r_grpnext
decl_stmt|;
comment|/* next record when grouped */
name|struct
name|databuf
modifier|*
name|r_dp
decl_stmt|;
comment|/* databuf to process */
name|struct
name|databuf
modifier|*
name|r_deldp
decl_stmt|;
comment|/* databuf's deleted/overwritten */
name|u_int16_t
name|r_zone
decl_stmt|;
comment|/* zone number on server */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ns_updrec
name|ns_updrec
typedef|;
end_typedef

begin_comment
comment|/*  * Currently defined type values for resources and queries.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_type
block|{
name|ns_t_a
init|=
literal|1
block|,
comment|/* Host address. */
name|ns_t_ns
init|=
literal|2
block|,
comment|/* Authoritative server. */
name|ns_t_md
init|=
literal|3
block|,
comment|/* Mail destination. */
name|ns_t_mf
init|=
literal|4
block|,
comment|/* Mail forwarder. */
name|ns_t_cname
init|=
literal|5
block|,
comment|/* Canonical name. */
name|ns_t_soa
init|=
literal|6
block|,
comment|/* Start of authority zone. */
name|ns_t_mb
init|=
literal|7
block|,
comment|/* Mailbox domain name. */
name|ns_t_mg
init|=
literal|8
block|,
comment|/* Mail group member. */
name|ns_t_mr
init|=
literal|9
block|,
comment|/* Mail rename name. */
name|ns_t_null
init|=
literal|10
block|,
comment|/* Null resource record. */
name|ns_t_wks
init|=
literal|11
block|,
comment|/* Well known service. */
name|ns_t_ptr
init|=
literal|12
block|,
comment|/* Domain name pointer. */
name|ns_t_hinfo
init|=
literal|13
block|,
comment|/* Host information. */
name|ns_t_minfo
init|=
literal|14
block|,
comment|/* Mailbox information. */
name|ns_t_mx
init|=
literal|15
block|,
comment|/* Mail routing information. */
name|ns_t_txt
init|=
literal|16
block|,
comment|/* Text strings. */
name|ns_t_rp
init|=
literal|17
block|,
comment|/* Responsible person. */
name|ns_t_afsdb
init|=
literal|18
block|,
comment|/* AFS cell database. */
name|ns_t_x25
init|=
literal|19
block|,
comment|/* X_25 calling address. */
name|ns_t_isdn
init|=
literal|20
block|,
comment|/* ISDN calling address. */
name|ns_t_rt
init|=
literal|21
block|,
comment|/* Router. */
name|ns_t_nsap
init|=
literal|22
block|,
comment|/* NSAP address. */
name|ns_t_nsap_ptr
init|=
literal|23
block|,
comment|/* Reverse NSAP lookup (deprecated). */
name|ns_t_sig
init|=
literal|24
block|,
comment|/* Security signature. */
name|ns_t_key
init|=
literal|25
block|,
comment|/* Security key. */
name|ns_t_px
init|=
literal|26
block|,
comment|/* X.400 mail mapping. */
name|ns_t_gpos
init|=
literal|27
block|,
comment|/* Geographical position (withdrawn). */
name|ns_t_aaaa
init|=
literal|28
block|,
comment|/* Ip6 Address. */
name|ns_t_loc
init|=
literal|29
block|,
comment|/* Location Information. */
name|ns_t_nxt
init|=
literal|30
block|,
comment|/* Next domain (security). */
name|ns_t_eid
init|=
literal|31
block|,
comment|/* Endpoint identifier. */
name|ns_t_nimloc
init|=
literal|32
block|,
comment|/* Nimrod Locator. */
name|ns_t_srv
init|=
literal|33
block|,
comment|/* Server Selection. */
name|ns_t_atma
init|=
literal|34
block|,
comment|/* ATM Address */
name|ns_t_naptr
init|=
literal|35
block|,
comment|/* Naming Authority PoinTeR */
name|ns_t_opt
init|=
literal|41
block|,
comment|/* OPT pseudo-RR, RFC2761 */
comment|/* Query type values which do not appear in resource records. */
name|ns_t_ixfr
init|=
literal|251
block|,
comment|/* Incremental zone transfer. */
name|ns_t_axfr
init|=
literal|252
block|,
comment|/* Transfer zone of authority. */
name|ns_t_mailb
init|=
literal|253
block|,
comment|/* Transfer mailbox records. */
name|ns_t_maila
init|=
literal|254
block|,
comment|/* Transfer mail agent records. */
name|ns_t_any
init|=
literal|255
block|,
comment|/* Wildcard match. */
name|ns_t_max
init|=
literal|65536
block|}
name|ns_type
typedef|;
end_typedef

begin_comment
comment|/*  * Values for class field  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_class
block|{
name|ns_c_in
init|=
literal|1
block|,
comment|/* Internet. */
comment|/* Class 2 unallocated/unsupported. */
name|ns_c_chaos
init|=
literal|3
block|,
comment|/* MIT Chaos-net. */
name|ns_c_hs
init|=
literal|4
block|,
comment|/* MIT Hesiod. */
comment|/* Query class values which do not appear in resource records */
name|ns_c_none
init|=
literal|254
block|,
comment|/* for prereq. sections in update requests */
name|ns_c_any
init|=
literal|255
block|,
comment|/* Wildcard match. */
name|ns_c_max
init|=
literal|65536
block|}
name|ns_class
typedef|;
end_typedef

begin_comment
comment|/*  * Flags field of the KEY RR rdata  */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_TYPEMASK
value|0xC000
end_define

begin_comment
comment|/* Mask for "type" bits */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_TYPE_AUTH_CONF
value|0x0000
end_define

begin_comment
comment|/* Key usable for both */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_TYPE_CONF_ONLY
value|0x8000
end_define

begin_comment
comment|/* Key usable for confidentiality */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_TYPE_AUTH_ONLY
value|0x4000
end_define

begin_comment
comment|/* Key usable for authentication */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_TYPE_NO_KEY
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
name|NS_KEY_NO_AUTH
value|0x8000
end_define

begin_comment
comment|/* Key unusable for authentication */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_NO_CONF
value|0x4000
end_define

begin_comment
comment|/* Key unusable for confidentiality */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_EXPERIMENTAL
value|0x2000
end_define

begin_comment
comment|/* Security is *mandatory* if bit=0 */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_RESERVED3
value|0x1000
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_RESERVED4
value|0x0800
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_USERACCOUNT
value|0x0400
end_define

begin_comment
comment|/* key is assoc. with a user acct */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_ENTITY
value|0x0200
end_define

begin_comment
comment|/* key is assoc. with entity eg host */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_ZONEKEY
value|0x0100
end_define

begin_comment
comment|/* key is zone key */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_IPSEC
value|0x0080
end_define

begin_comment
comment|/* key is for IPSEC (host or user)*/
end_comment

begin_define
define|#
directive|define
name|NS_KEY_EMAIL
value|0x0040
end_define

begin_comment
comment|/* key is for email (MIME security) */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_RESERVED10
value|0x0020
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_RESERVED11
value|0x0010
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_SIGNATORYMASK
value|0x000F
end_define

begin_comment
comment|/* key can sign RR's of same name */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_RESERVED_BITMASK
value|( NS_KEY_RESERVED3 | \ 				  NS_KEY_RESERVED4 | \ 				  NS_KEY_RESERVED10 | \ 				  NS_KEY_RESERVED11 )
end_define

begin_comment
comment|/* The Algorithm field of the KEY and SIG RR's is an integer, {1..254} */
end_comment

begin_define
define|#
directive|define
name|NS_ALG_MD5RSA
value|1
end_define

begin_comment
comment|/* MD5 with RSA */
end_comment

begin_define
define|#
directive|define
name|NS_ALG_EXPIRE_ONLY
value|253
end_define

begin_comment
comment|/* No alg, no security */
end_comment

begin_define
define|#
directive|define
name|NS_ALG_PRIVATE_OID
value|254
end_define

begin_comment
comment|/* Key begins with OID giving alg */
end_comment

begin_comment
comment|/* Signatures */
end_comment

begin_define
define|#
directive|define
name|NS_MD5RSA_MIN_BITS
value|512
end_define

begin_comment
comment|/* Size of a mod or exp in bits */
end_comment

begin_define
define|#
directive|define
name|NS_MD5RSA_MAX_BITS
value|2552
end_define

begin_comment
comment|/* Total of binary mod and exp */
end_comment

begin_define
define|#
directive|define
name|NS_MD5RSA_MAX_BYTES
value|((NS_MD5RSA_MAX_BITS+7/8)*2+3)
end_define

begin_comment
comment|/* Max length of text sig block */
end_comment

begin_define
define|#
directive|define
name|NS_MD5RSA_MAX_BASE64
value|(((NS_MD5RSA_MAX_BYTES+2)/3)*4)
end_define

begin_comment
comment|/* Offsets into SIG record rdata to find various values */
end_comment

begin_define
define|#
directive|define
name|NS_SIG_TYPE
value|0
end_define

begin_comment
comment|/* Type flags */
end_comment

begin_define
define|#
directive|define
name|NS_SIG_ALG
value|2
end_define

begin_comment
comment|/* Algorithm */
end_comment

begin_define
define|#
directive|define
name|NS_SIG_LABELS
value|3
end_define

begin_comment
comment|/* How many labels in name */
end_comment

begin_define
define|#
directive|define
name|NS_SIG_OTTL
value|4
end_define

begin_comment
comment|/* Original TTL */
end_comment

begin_define
define|#
directive|define
name|NS_SIG_EXPIR
value|8
end_define

begin_comment
comment|/* Expiration time */
end_comment

begin_define
define|#
directive|define
name|NS_SIG_SIGNED
value|12
end_define

begin_comment
comment|/* Signature time */
end_comment

begin_define
define|#
directive|define
name|NS_SIG_FOOT
value|16
end_define

begin_comment
comment|/* Key footprint */
end_comment

begin_define
define|#
directive|define
name|NS_SIG_SIGNER
value|18
end_define

begin_comment
comment|/* Domain name of who signed it */
end_comment

begin_comment
comment|/* How RR types are represented as bit-flags in NXT records */
end_comment

begin_define
define|#
directive|define
name|NS_NXT_BITS
value|8
end_define

begin_define
define|#
directive|define
name|NS_NXT_BIT_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(p[(n)/NS_NXT_BITS] |=  (0x80>>((n)%NS_NXT_BITS)))
end_define

begin_define
define|#
directive|define
name|NS_NXT_BIT_CLEAR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(p[(n)/NS_NXT_BITS]&= ~(0x80>>((n)%NS_NXT_BITS)))
end_define

begin_define
define|#
directive|define
name|NS_NXT_BIT_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(p[(n)/NS_NXT_BITS]&   (0x80>>((n)%NS_NXT_BITS)))
end_define

begin_comment
comment|/*  * Inline versions of get/put short/long.  Pointer is advanced.  */
end_comment

begin_define
define|#
directive|define
name|NS_GET16
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register u_char *t_cp = (u_char *)(cp); \ 	(s) = ((u_int16_t)t_cp[0]<< 8) \ 	    | ((u_int16_t)t_cp[1]) \ 	    ; \ 	(cp) += NS_INT16SZ; \ }
end_define

begin_define
define|#
directive|define
name|NS_GET32
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register u_char *t_cp = (u_char *)(cp); \ 	(l) = ((u_int32_t)t_cp[0]<< 24) \ 	    | ((u_int32_t)t_cp[1]<< 16) \ 	    | ((u_int32_t)t_cp[2]<< 8) \ 	    | ((u_int32_t)t_cp[3]) \ 	    ; \ 	(cp) += NS_INT32SZ; \ }
end_define

begin_define
define|#
directive|define
name|NS_PUT16
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register u_int16_t t_s = (u_int16_t)(s); \ 	register u_char *t_cp = (u_char *)(cp); \ 	*t_cp++ = t_s>> 8; \ 	*t_cp   = t_s; \ 	(cp) += NS_INT16SZ; \ }
end_define

begin_define
define|#
directive|define
name|NS_PUT32
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register u_int32_t t_l = (u_int32_t)(l); \ 	register u_char *t_cp = (u_char *)(cp); \ 	*t_cp++ = t_l>> 24; \ 	*t_cp++ = t_l>> 16; \ 	*t_cp++ = t_l>> 8; \ 	*t_cp   = t_l; \ 	(cp) += NS_INT32SZ; \ }
end_define

begin_comment
comment|/*  * ANSI C identifier hiding.  */
end_comment

begin_define
define|#
directive|define
name|ns_get16
value|__ns_get16
end_define

begin_define
define|#
directive|define
name|ns_get32
value|__ns_get32
end_define

begin_define
define|#
directive|define
name|ns_put16
value|__ns_put16
end_define

begin_define
define|#
directive|define
name|ns_put32
value|__ns_put32
end_define

begin_define
define|#
directive|define
name|ns_initparse
value|__ns_initparse
end_define

begin_define
define|#
directive|define
name|ns_parserr
value|__ns_parserr
end_define

begin_define
define|#
directive|define
name|ns_sprintrr
value|__ns_sprintrr
end_define

begin_define
define|#
directive|define
name|ns_sprintrrf
value|__ns_sprintrrf
end_define

begin_define
define|#
directive|define
name|ns_format_ttl
value|__ns_format_ttl
end_define

begin_define
define|#
directive|define
name|ns_parse_ttl
value|__ns_parse_ttl
end_define

begin_define
define|#
directive|define
name|ns_name_ntop
value|__ns_name_ntop
end_define

begin_define
define|#
directive|define
name|ns_name_pton
value|__ns_name_pton
end_define

begin_define
define|#
directive|define
name|ns_name_unpack
value|__ns_name_unpack
end_define

begin_define
define|#
directive|define
name|ns_name_pack
value|__ns_name_pack
end_define

begin_define
define|#
directive|define
name|ns_name_compress
value|__ns_name_compress
end_define

begin_define
define|#
directive|define
name|ns_name_uncompress
value|__ns_name_uncompress
end_define

begin_function_decl
name|__BEGIN_DECLS
name|u_int
name|ns_get16
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|ns_get32
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_put16
parameter_list|(
name|u_int
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_put32
parameter_list|(
name|u_long
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_initparse
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|ns_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_parserr
parameter_list|(
name|ns_msg
modifier|*
parameter_list|,
name|ns_sect
parameter_list|,
name|int
parameter_list|,
name|ns_rr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_sprintrr
parameter_list|(
specifier|const
name|ns_msg
modifier|*
parameter_list|,
specifier|const
name|ns_rr
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_sprintrrf
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|ns_class
parameter_list|,
name|ns_type
parameter_list|,
name|u_long
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_format_ttl
parameter_list|(
name|u_long
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_parse_ttl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_name_ntop
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_name_pton
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_name_unpack
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_name_pack
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_name_uncompress
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_name_compress
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|u_char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ns_name_skip
parameter_list|(
specifier|const
name|u_char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_4_COMPAT
end_ifdef

begin_include
include|#
directive|include
file|<arpa/nameser_compat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ARPA_NAMESER_H_ */
end_comment

end_unit

