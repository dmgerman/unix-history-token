begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1989, 1993  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  *	$Id: nameser.h,v 8.41 2000/12/23 08:14:50 vixie Exp $  */
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
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
operator|)
operator|||
operator|(
name|BSD
operator|<
literal|199306
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/bitypes.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * Revision information.  This is the release date in YYYYMMDD format.  * It can change every day so the right thing to do with it is use it  * in preprocessor commands such as "#if (__NAMESER> 19931104)".  Do not  * compare for equality; rather, use it to determine whether your libbind.a  * contains a new enough lib/nameser/ to support the feature you need.  */
end_comment

begin_define
define|#
directive|define
name|__NAMESER
value|19991006
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
value|((ns_type)((rr).type + 0))
end_define

begin_define
define|#
directive|define
name|ns_rr_class
parameter_list|(
name|rr
parameter_list|)
value|((ns_class)((rr).rr_class + 0))
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
block|,
comment|/* The following are TSIG extended errors */
name|ns_r_badsig
init|=
literal|16
block|,
name|ns_r_badkey
init|=
literal|17
block|,
name|ns_r_badtime
init|=
literal|18
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
comment|/*  * This structure is used for TSIG authenticated messages  */
end_comment

begin_struct
struct|struct
name|ns_tsig_key
block|{
name|char
name|name
index|[
name|NS_MAXDNAME
index|]
decl_stmt|,
name|alg
index|[
name|NS_MAXDNAME
index|]
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ns_tsig_key
name|ns_tsig_key
typedef|;
end_typedef

begin_comment
comment|/*  * This structure is used for TSIG authenticated TCP messages  */
end_comment

begin_struct
struct|struct
name|ns_tcp_tsig_state
block|{
name|int
name|counter
decl_stmt|;
name|struct
name|dst_key
modifier|*
name|key
decl_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
name|unsigned
name|char
name|sig
index|[
name|NS_PACKETSZ
index|]
decl_stmt|;
name|int
name|siglen
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ns_tcp_tsig_state
name|ns_tcp_tsig_state
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NS_TSIG_FUDGE
value|300
end_define

begin_define
define|#
directive|define
name|NS_TSIG_TCP_COUNT
value|100
end_define

begin_define
define|#
directive|define
name|NS_TSIG_ALG_HMAC_MD5
value|"HMAC-MD5.SIG-ALG.REG.INT"
end_define

begin_define
define|#
directive|define
name|NS_TSIG_ERROR_NO_TSIG
value|-10
end_define

begin_define
define|#
directive|define
name|NS_TSIG_ERROR_NO_SPACE
value|-11
end_define

begin_define
define|#
directive|define
name|NS_TSIG_ERROR_FORMERR
value|-12
end_define

begin_comment
comment|/*  * Currently defined type values for resources and queries.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_type
block|{
name|ns_t_invalid
init|=
literal|0
block|,
comment|/* Cookie. */
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
name|ns_t_kx
init|=
literal|36
block|,
comment|/* Key Exchange */
name|ns_t_cert
init|=
literal|37
block|,
comment|/* Certification record */
name|ns_t_a6
init|=
literal|38
block|,
comment|/* IPv6 address (deprecates AAAA) */
name|ns_t_dname
init|=
literal|39
block|,
comment|/* Non-terminal DNAME (for IPv6) */
name|ns_t_sink
init|=
literal|40
block|,
comment|/* Kitchen sink (experimentatl) */
name|ns_t_opt
init|=
literal|41
block|,
comment|/* EDNS0 option (meta-RR) */
name|ns_t_tkey
init|=
literal|249
block|,
comment|/* Transaction key */
name|ns_t_tsig
init|=
literal|250
block|,
comment|/* Transaction signature. */
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
name|ns_t_zxfr
init|=
literal|256
block|,
comment|/* BIND-specific, nonstandard. */
name|ns_t_max
init|=
literal|65536
block|}
name|ns_type
typedef|;
end_typedef

begin_comment
comment|/* Exclusively a QTYPE? (not also an RTYPE) */
end_comment

begin_define
define|#
directive|define
name|ns_t_qt_p
parameter_list|(
name|t
parameter_list|)
value|(ns_t_xfr_p(t) || (t) == ns_t_any || \ 		      (t) == ns_t_mailb || (t) == ns_t_maila)
end_define

begin_comment
comment|/* Some kind of meta-RR? (not a QTYPE, but also not an RTYPE) */
end_comment

begin_define
define|#
directive|define
name|ns_t_mrr_p
parameter_list|(
name|t
parameter_list|)
value|((t) == ns_t_tsig || (t) == ns_t_opt)
end_define

begin_comment
comment|/* Exclusively an RTYPE? (not also a QTYPE or a meta-RR) */
end_comment

begin_define
define|#
directive|define
name|ns_t_rr_p
parameter_list|(
name|t
parameter_list|)
value|(!ns_t_qt_p(t)&& !ns_t_mrr_p(t))
end_define

begin_define
define|#
directive|define
name|ns_t_udp_p
parameter_list|(
name|t
parameter_list|)
value|((t) != ns_t_axfr&& (t) != ns_t_zxfr)
end_define

begin_define
define|#
directive|define
name|ns_t_xfr_p
parameter_list|(
name|t
parameter_list|)
value|((t) == ns_t_axfr || (t) == ns_t_ixfr || \ 		       (t) == ns_t_zxfr)
end_define

begin_comment
comment|/*  * Values for class field  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_class
block|{
name|ns_c_invalid
init|=
literal|0
block|,
comment|/* Cookie. */
name|ns_c_in
init|=
literal|1
block|,
comment|/* Internet. */
name|ns_c_2
init|=
literal|2
block|,
comment|/* unallocated/unsupported. */
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
comment|/* DNSSEC constants. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|__ns_key_types
block|{
name|ns_kt_rsa
init|=
literal|1
block|,
comment|/* key type RSA/MD5 */
name|ns_kt_dh
init|=
literal|2
block|,
comment|/* Diffie Hellman */
name|ns_kt_dsa
init|=
literal|3
block|,
comment|/* Digital Signature Standard (MANDATORY) */
name|ns_kt_private
init|=
literal|254
comment|/* Private key type starts with OID */
block|}
name|ns_key_types
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|__ns_cert_types
block|{
name|cert_t_pkix
init|=
literal|1
block|,
comment|/* PKIX (X.509v3) */
name|cert_t_spki
init|=
literal|2
block|,
comment|/* SPKI */
name|cert_t_pgp
init|=
literal|3
block|,
comment|/* PGP */
name|cert_t_url
init|=
literal|253
block|,
comment|/* URL private type */
name|cert_t_oid
init|=
literal|254
comment|/* OID private type */
block|}
name|ns_cert_types
typedef|;
end_typedef

begin_comment
comment|/* Flags field of the KEY RR rdata. */
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
name|NS_KEY_RESERVED2
value|0x2000
end_define

begin_comment
comment|/* Security is *mandatory* if bit=0 */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_EXTENDED_FLAGS
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
name|NS_KEY_RESERVED5
value|0x0400
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_NAME_TYPE
value|0x0300
end_define

begin_comment
comment|/* these bits determine the type */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_NAME_USER
value|0x0000
end_define

begin_comment
comment|/* key is assoc. with user */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_NAME_ENTITY
value|0x0200
end_define

begin_comment
comment|/* key is assoc. with entity eg host */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_NAME_ZONE
value|0x0100
end_define

begin_comment
comment|/* key is zone key */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_NAME_RESERVED
value|0x0300
end_define

begin_comment
comment|/* reserved meaning */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_RESERVED8
value|0x0080
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_RESERVED9
value|0x0040
end_define

begin_comment
comment|/* reserved - must be zero */
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
value|( NS_KEY_RESERVED2 | \ 				  NS_KEY_RESERVED4 | \ 				  NS_KEY_RESERVED5 | \ 				  NS_KEY_RESERVED8 | \ 				  NS_KEY_RESERVED9 | \ 				  NS_KEY_RESERVED10 | \ 				  NS_KEY_RESERVED11 )
end_define

begin_define
define|#
directive|define
name|NS_KEY_RESERVED_BITMASK2
value|0xFFFF
end_define

begin_comment
comment|/* no bits defined here */
end_comment

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
name|NS_ALG_DH
value|2
end_define

begin_comment
comment|/* Diffie Hellman KEY */
end_comment

begin_define
define|#
directive|define
name|NS_ALG_DSA
value|3
end_define

begin_comment
comment|/* DSA KEY */
end_comment

begin_define
define|#
directive|define
name|NS_ALG_DSS
value|NS_ALG_DSA
end_define

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
comment|/* Protocol values  */
end_comment

begin_comment
comment|/* value 0 is reserved */
end_comment

begin_define
define|#
directive|define
name|NS_KEY_PROT_TLS
value|1
end_define

begin_define
define|#
directive|define
name|NS_KEY_PROT_EMAIL
value|2
end_define

begin_define
define|#
directive|define
name|NS_KEY_PROT_DNSSEC
value|3
end_define

begin_define
define|#
directive|define
name|NS_KEY_PROT_IPSEC
value|4
end_define

begin_define
define|#
directive|define
name|NS_KEY_PROT_ANY
value|255
end_define

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

begin_define
define|#
directive|define
name|NS_MD5RSA_MIN_SIZE
value|((NS_MD5RSA_MIN_BITS+7)/8)
end_define

begin_define
define|#
directive|define
name|NS_MD5RSA_MAX_SIZE
value|((NS_MD5RSA_MAX_BITS+7)/8)
end_define

begin_define
define|#
directive|define
name|NS_DSA_SIG_SIZE
value|41
end_define

begin_define
define|#
directive|define
name|NS_DSA_MIN_SIZE
value|213
end_define

begin_define
define|#
directive|define
name|NS_DSA_MAX_BYTES
value|405
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

begin_define
define|#
directive|define
name|NS_NXT_MAX
value|127
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
value|do { \ 	register u_char *t_cp = (u_char *)(cp); \ 	(s) = ((u_int16_t)t_cp[0]<< 8) \ 	    | ((u_int16_t)t_cp[1]) \ 	    ; \ 	(cp) += NS_INT16SZ; \ } while (0)
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
value|do { \ 	register u_char *t_cp = (u_char *)(cp); \ 	(l) = ((u_int32_t)t_cp[0]<< 24) \ 	    | ((u_int32_t)t_cp[1]<< 16) \ 	    | ((u_int32_t)t_cp[2]<< 8) \ 	    | ((u_int32_t)t_cp[3]) \ 	    ; \ 	(cp) += NS_INT32SZ; \ } while (0)
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
value|do { \ 	register u_int16_t t_s = (u_int16_t)(s); \ 	register u_char *t_cp = (u_char *)(cp); \ 	*t_cp++ = t_s>> 8; \ 	*t_cp   = t_s; \ 	(cp) += NS_INT16SZ; \ } while (0)
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
value|do { \ 	register u_int32_t t_l = (u_int32_t)(l); \ 	register u_char *t_cp = (u_char *)(cp); \ 	*t_cp++ = t_l>> 24; \ 	*t_cp++ = t_l>> 16; \ 	*t_cp++ = t_l>> 8; \ 	*t_cp   = t_l; \ 	(cp) += NS_INT32SZ; \ } while (0)
end_define

begin_comment
comment|/*  * ANSI C identifier hiding for bind's lib/nameser.  */
end_comment

begin_define
define|#
directive|define
name|ns_msg_getflag
value|__ns_msg_getflag
end_define

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
name|ns_skiprr
value|__ns_skiprr
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
name|ns_datetosecs
value|__ns_datetosecs
end_define

begin_define
define|#
directive|define
name|ns_name_ntol
value|__ns_name_ntol
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

begin_define
define|#
directive|define
name|ns_name_skip
value|__ns_name_skip
end_define

begin_define
define|#
directive|define
name|ns_name_rollback
value|__ns_name_rollback
end_define

begin_define
define|#
directive|define
name|ns_sign
value|__ns_sign
end_define

begin_define
define|#
directive|define
name|ns_sign_tcp
value|__ns_sign_tcp
end_define

begin_define
define|#
directive|define
name|ns_sign_tcp_init
value|__ns_sign_tcp_init
end_define

begin_define
define|#
directive|define
name|ns_find_tsig
value|__ns_find_tsig
end_define

begin_define
define|#
directive|define
name|ns_verify
value|__ns_verify
end_define

begin_define
define|#
directive|define
name|ns_verify_tcp
value|__ns_verify_tcp
end_define

begin_define
define|#
directive|define
name|ns_verify_tcp_init
value|__ns_verify_tcp_init
end_define

begin_define
define|#
directive|define
name|ns_samedomain
value|__ns_samedomain
end_define

begin_define
define|#
directive|define
name|ns_subdomain
value|__ns_subdomain
end_define

begin_define
define|#
directive|define
name|ns_makecanon
value|__ns_makecanon
end_define

begin_define
define|#
directive|define
name|ns_samename
value|__ns_samename
end_define

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|ns_msg_getflag
name|__P
argument_list|(
operator|(
name|ns_msg
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|ns_get16
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
name|u_long
name|ns_get32
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
name|void
name|ns_put16
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ns_put32
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_initparse
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
name|int
operator|,
name|ns_msg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_skiprr
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|ns_sect
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_parserr
name|__P
argument_list|(
operator|(
name|ns_msg
operator|*
operator|,
name|ns_sect
operator|,
name|int
operator|,
name|ns_rr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_sprintrr
name|__P
argument_list|(
operator|(
specifier|const
name|ns_msg
operator|*
operator|,
specifier|const
name|ns_rr
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_sprintrrf
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|ns_class
operator|,
name|ns_type
operator|,
name|u_long
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_format_ttl
name|__P
argument_list|(
operator|(
name|u_long
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_parse_ttl
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int32_t
name|ns_datetosecs
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|cp
operator|,
name|int
operator|*
name|errp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_name_ntol
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_name_ntop
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_name_pton
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_name_unpack
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_name_pack
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|,
specifier|const
name|u_char
operator|*
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_name_uncompress
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_name_compress
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|u_char
operator|*
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_name_skip
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ns_name_rollback
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_sign
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|void
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|*
operator|,
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_sign_tcp
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|ns_tcp_tsig_state
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_sign_tcp_init
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|int
operator|,
name|ns_tcp_tsig_state
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
modifier|*
name|ns_find_tsig
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_verify
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int
operator|*
operator|,
name|void
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|*
operator|,
name|time_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_verify_tcp
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int
operator|*
operator|,
name|ns_tcp_tsig_state
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_verify_tcp_init
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|int
operator|,
name|ns_tcp_tsig_state
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_samedomain
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_subdomain
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_makecanon
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ns_samename
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

