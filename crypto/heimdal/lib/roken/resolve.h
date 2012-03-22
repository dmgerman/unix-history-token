begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2002 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RESOLVE_H__
end_ifndef

begin_define
define|#
directive|define
name|__RESOLVE_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ROKEN_LIB_FUNCTION
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|ROKEN_LIB_FUNCTION
end_define

begin_define
define|#
directive|define
name|ROKEN_LIB_CALL
value|__cdecl
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ROKEN_LIB_FUNCTION
end_define

begin_define
define|#
directive|define
name|ROKEN_LIB_CALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
block|{
name|rk_ns_c_in
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|rk_ns_t_invalid
init|=
literal|0
block|,
comment|/* Cookie. */
name|rk_ns_t_a
init|=
literal|1
block|,
comment|/* Host address. */
name|rk_ns_t_ns
init|=
literal|2
block|,
comment|/* Authoritative server. */
name|rk_ns_t_md
init|=
literal|3
block|,
comment|/* Mail destination. */
name|rk_ns_t_mf
init|=
literal|4
block|,
comment|/* Mail forwarder. */
name|rk_ns_t_cname
init|=
literal|5
block|,
comment|/* Canonical name. */
name|rk_ns_t_soa
init|=
literal|6
block|,
comment|/* Start of authority zone. */
name|rk_ns_t_mb
init|=
literal|7
block|,
comment|/* Mailbox domain name. */
name|rk_ns_t_mg
init|=
literal|8
block|,
comment|/* Mail group member. */
name|rk_ns_t_mr
init|=
literal|9
block|,
comment|/* Mail rename name. */
name|rk_ns_t_null
init|=
literal|10
block|,
comment|/* Null resource record. */
name|rk_ns_t_wks
init|=
literal|11
block|,
comment|/* Well known service. */
name|rk_ns_t_ptr
init|=
literal|12
block|,
comment|/* Domain name pointer. */
name|rk_ns_t_hinfo
init|=
literal|13
block|,
comment|/* Host information. */
name|rk_ns_t_minfo
init|=
literal|14
block|,
comment|/* Mailbox information. */
name|rk_ns_t_mx
init|=
literal|15
block|,
comment|/* Mail routing information. */
name|rk_ns_t_txt
init|=
literal|16
block|,
comment|/* Text strings. */
name|rk_ns_t_rp
init|=
literal|17
block|,
comment|/* Responsible person. */
name|rk_ns_t_afsdb
init|=
literal|18
block|,
comment|/* AFS cell database. */
name|rk_ns_t_x25
init|=
literal|19
block|,
comment|/* X_25 calling address. */
name|rk_ns_t_isdn
init|=
literal|20
block|,
comment|/* ISDN calling address. */
name|rk_ns_t_rt
init|=
literal|21
block|,
comment|/* Router. */
name|rk_ns_t_nsap
init|=
literal|22
block|,
comment|/* NSAP address. */
name|rk_ns_t_nsap_ptr
init|=
literal|23
block|,
comment|/* Reverse NSAP lookup (deprecated). */
name|rk_ns_t_sig
init|=
literal|24
block|,
comment|/* Security signature. */
name|rk_ns_t_key
init|=
literal|25
block|,
comment|/* Security key. */
name|rk_ns_t_px
init|=
literal|26
block|,
comment|/* X.400 mail mapping. */
name|rk_ns_t_gpos
init|=
literal|27
block|,
comment|/* Geographical position (withdrawn). */
name|rk_ns_t_aaaa
init|=
literal|28
block|,
comment|/* Ip6 Address. */
name|rk_ns_t_loc
init|=
literal|29
block|,
comment|/* Location Information. */
name|rk_ns_t_nxt
init|=
literal|30
block|,
comment|/* Next domain (security). */
name|rk_ns_t_eid
init|=
literal|31
block|,
comment|/* Endpoint identifier. */
name|rk_ns_t_nimloc
init|=
literal|32
block|,
comment|/* Nimrod Locator. */
name|rk_ns_t_srv
init|=
literal|33
block|,
comment|/* Server Selection. */
name|rk_ns_t_atma
init|=
literal|34
block|,
comment|/* ATM Address */
name|rk_ns_t_naptr
init|=
literal|35
block|,
comment|/* Naming Authority PoinTeR */
name|rk_ns_t_kx
init|=
literal|36
block|,
comment|/* Key Exchange */
name|rk_ns_t_cert
init|=
literal|37
block|,
comment|/* Certification record */
name|rk_ns_t_a6
init|=
literal|38
block|,
comment|/* IPv6 address (deprecates AAAA) */
name|rk_ns_t_dname
init|=
literal|39
block|,
comment|/* Non-terminal DNAME (for IPv6) */
name|rk_ns_t_sink
init|=
literal|40
block|,
comment|/* Kitchen sink (experimentatl) */
name|rk_ns_t_opt
init|=
literal|41
block|,
comment|/* EDNS0 option (meta-RR) */
name|rk_ns_t_apl
init|=
literal|42
block|,
comment|/* Address prefix list (RFC 3123) */
name|rk_ns_t_ds
init|=
literal|43
block|,
comment|/* Delegation Signer (RFC 3658) */
name|rk_ns_t_sshfp
init|=
literal|44
block|,
comment|/* SSH fingerprint */
name|rk_ns_t_tkey
init|=
literal|249
block|,
comment|/* Transaction key */
name|rk_ns_t_tsig
init|=
literal|250
block|,
comment|/* Transaction signature. */
name|rk_ns_t_ixfr
init|=
literal|251
block|,
comment|/* Incremental zone transfer. */
name|rk_ns_t_axfr
init|=
literal|252
block|,
comment|/* Transfer zone of authority. */
name|rk_ns_t_mailb
init|=
literal|253
block|,
comment|/* Transfer mailbox records. */
name|rk_ns_t_maila
init|=
literal|254
block|,
comment|/* Transfer mail agent records. */
name|rk_ns_t_any
init|=
literal|255
block|,
comment|/* Wildcard match. */
name|rk_ns_t_zxfr
init|=
literal|256
block|,
comment|/* BIND-specific, nonstandard. */
name|rk_ns_t_max
init|=
literal|65536
block|}
enum|;
end_enum

begin_ifndef
ifndef|#
directive|ifndef
name|MAXDNAME
end_ifndef

begin_define
define|#
directive|define
name|MAXDNAME
value|1025
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mx_record
value|rk_mx_record
end_define

begin_define
define|#
directive|define
name|srv_record
value|rk_srv_record
end_define

begin_define
define|#
directive|define
name|key_record
value|rk_key_record
end_define

begin_define
define|#
directive|define
name|sig_record
value|rk_sig_record
end_define

begin_define
define|#
directive|define
name|cert_record
value|rk_cert_record
end_define

begin_define
define|#
directive|define
name|sshfp_record
value|rk_sshfp_record
end_define

begin_struct
struct|struct
name|rk_dns_query
block|{
name|char
modifier|*
name|domain
decl_stmt|;
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|class
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rk_mx_record
block|{
name|unsigned
name|preference
decl_stmt|;
name|char
name|domain
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rk_srv_record
block|{
name|unsigned
name|priority
decl_stmt|;
name|unsigned
name|weight
decl_stmt|;
name|unsigned
name|port
decl_stmt|;
name|char
name|target
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rk_key_record
block|{
name|unsigned
name|flags
decl_stmt|;
name|unsigned
name|protocol
decl_stmt|;
name|unsigned
name|algorithm
decl_stmt|;
name|size_t
name|key_len
decl_stmt|;
name|u_char
name|key_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rk_sig_record
block|{
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|algorithm
decl_stmt|;
name|unsigned
name|labels
decl_stmt|;
name|unsigned
name|orig_ttl
decl_stmt|;
name|unsigned
name|sig_expiration
decl_stmt|;
name|unsigned
name|sig_inception
decl_stmt|;
name|unsigned
name|key_tag
decl_stmt|;
name|char
modifier|*
name|signer
decl_stmt|;
name|size_t
name|sig_len
decl_stmt|;
name|char
name|sig_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* also includes signer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rk_cert_record
block|{
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|tag
decl_stmt|;
name|unsigned
name|algorithm
decl_stmt|;
name|size_t
name|cert_len
decl_stmt|;
name|u_char
name|cert_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rk_sshfp_record
block|{
name|unsigned
name|algorithm
decl_stmt|;
name|unsigned
name|type
decl_stmt|;
name|size_t
name|sshfp_len
decl_stmt|;
name|u_char
name|sshfp_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rk_ds_record
block|{
name|unsigned
name|key_tag
decl_stmt|;
name|unsigned
name|algorithm
decl_stmt|;
name|unsigned
name|digest_type
decl_stmt|;
name|size_t
name|digest_len
decl_stmt|;
name|u_char
name|digest_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rk_resource_record
block|{
name|char
modifier|*
name|domain
decl_stmt|;
name|unsigned
name|type
decl_stmt|;
name|unsigned
name|class
decl_stmt|;
name|unsigned
name|ttl
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|struct
name|rk_mx_record
modifier|*
name|mx
decl_stmt|;
name|struct
name|rk_mx_record
modifier|*
name|afsdb
decl_stmt|;
comment|/* mx and afsdb are identical */
name|struct
name|rk_srv_record
modifier|*
name|srv
decl_stmt|;
name|struct
name|in_addr
modifier|*
name|a
decl_stmt|;
name|char
modifier|*
name|txt
decl_stmt|;
name|struct
name|rk_key_record
modifier|*
name|key
decl_stmt|;
name|struct
name|rk_cert_record
modifier|*
name|cert
decl_stmt|;
name|struct
name|rk_sig_record
modifier|*
name|sig
decl_stmt|;
name|struct
name|rk_sshfp_record
modifier|*
name|sshfp
decl_stmt|;
name|struct
name|rk_ds_record
modifier|*
name|ds
decl_stmt|;
block|}
name|u
union|;
name|struct
name|rk_resource_record
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rk_DNS_MAX_PACKET_SIZE
value|0xffff
end_define

begin_struct
struct|struct
name|rk_dns_header
block|{
name|unsigned
name|id
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
define|#
directive|define
name|rk_DNS_HEADER_RESPONSE_FLAG
value|1
define|#
directive|define
name|rk_DNS_HEADER_AUTHORITIVE_ANSWER
value|2
define|#
directive|define
name|rk_DNS_HEADER_TRUNCATED_MESSAGE
value|4
define|#
directive|define
name|rk_DNS_HEADER_RECURSION_DESIRED
value|8
define|#
directive|define
name|rk_DNS_HEADER_RECURSION_AVAILABLE
value|16
define|#
directive|define
name|rk_DNS_HEADER_AUTHENTIC_DATA
value|32
define|#
directive|define
name|rk_DNS_HEADER_CHECKING_DISABLED
value|64
name|unsigned
name|opcode
decl_stmt|;
name|unsigned
name|response_code
decl_stmt|;
name|unsigned
name|qdcount
decl_stmt|;
name|unsigned
name|ancount
decl_stmt|;
name|unsigned
name|nscount
decl_stmt|;
name|unsigned
name|arcount
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rk_dns_reply
block|{
name|struct
name|rk_dns_header
name|h
decl_stmt|;
name|struct
name|rk_dns_query
name|q
decl_stmt|;
name|struct
name|rk_resource_record
modifier|*
name|head
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|ROKEN_LIB_FUNCTION
name|struct
name|rk_dns_reply
modifier|*
name|ROKEN_LIB_CALL
name|rk_dns_lookup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|ROKEN_LIB_FUNCTION
name|void
name|ROKEN_LIB_CALL
name|rk_dns_free_data
parameter_list|(
name|struct
name|rk_dns_reply
modifier|*
parameter_list|)
function_decl|;
name|ROKEN_LIB_FUNCTION
name|int
name|ROKEN_LIB_CALL
name|rk_dns_string_to_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|ROKEN_LIB_FUNCTION
specifier|const
name|char
modifier|*
name|ROKEN_LIB_CALL
name|rk_dns_type_to_string
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
name|ROKEN_LIB_FUNCTION
name|void
name|ROKEN_LIB_CALL
name|rk_dns_srv_order
parameter_list|(
name|struct
name|rk_dns_reply
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RESOLVE_H__ */
end_comment

end_unit

