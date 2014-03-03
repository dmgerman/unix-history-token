begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2013  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RRL_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RRL_H
value|1
end_define

begin_comment
comment|/*  * Rate limit DNS responses.  */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<dns/fixedname.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdata.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*  * Memory allocation or other failures.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RRL_LOG_FAIL
value|ISC_LOG_WARNING
end_define

begin_comment
comment|/*  * dropped or slipped responses.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RRL_LOG_DROP
value|ISC_LOG_INFO
end_define

begin_comment
comment|/*  * Major events in dropping or slipping.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RRL_LOG_DEBUG1
value|ISC_LOG_DEBUG(3)
end_define

begin_comment
comment|/*  * Limit computations.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RRL_LOG_DEBUG2
value|ISC_LOG_DEBUG(4)
end_define

begin_comment
comment|/*  * Even less interesting.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RRL_LOG_DEBUG3
value|ISC_LOG_DEBUG(9)
end_define

begin_define
define|#
directive|define
name|DNS_RRL_LOG_ERR_LEN
value|64
end_define

begin_define
define|#
directive|define
name|DNS_RRL_LOG_BUF_LEN
value|(sizeof("would continue limiting") +	\ 				 DNS_RRL_LOG_ERR_LEN +			\ 				 sizeof(" responses to ") +		\ 				 ISC_NETADDR_FORMATSIZE +		\ 				 sizeof("/128 for IN ") +		\ 				 DNS_RDATATYPE_FORMATSIZE +		\ 				 DNS_NAME_FORMATSIZE)
end_define

begin_typedef
typedef|typedef
name|struct
name|dns_rrl_hash
name|dns_rrl_hash_t
typedef|;
end_typedef

begin_comment
comment|/*  * Response types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DNS_RRL_RTYPE_FREE
init|=
literal|0
block|,
name|DNS_RRL_RTYPE_QUERY
block|,
name|DNS_RRL_RTYPE_REFERRAL
block|,
name|DNS_RRL_RTYPE_NODATA
block|,
name|DNS_RRL_RTYPE_NXDOMAIN
block|,
name|DNS_RRL_RTYPE_ERROR
block|,
name|DNS_RRL_RTYPE_ALL
block|,
name|DNS_RRL_RTYPE_TCP
block|, }
name|dns_rrl_rtype_t
typedef|;
end_typedef

begin_comment
comment|/*  * A rate limit bucket key.  * This should be small to limit the total size of the database.  * The hash of the qname should be wide enough to make the probability  * of collisions among requests from a single IP address block less than 50%.  * We need a 32-bit hash value for 10000 qps (e.g. random qnames forged  * by attacker) to collide with legitimate qnames from the target with  * probability at most 1%.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RRL_MAX_PREFIX
value|64
end_define

begin_typedef
typedef|typedef
name|union
name|dns_rrl_key
name|dns_rrl_key_t
typedef|;
end_typedef

begin_union
union|union
name|dns_rrl_key
block|{
struct|struct
block|{
name|isc_uint32_t
name|ip
index|[
name|DNS_RRL_MAX_PREFIX
operator|/
literal|32
index|]
decl_stmt|;
name|isc_uint32_t
name|qname_hash
decl_stmt|;
name|dns_rdatatype_t
name|qtype
decl_stmt|;
name|isc_uint8_t
name|qclass
decl_stmt|;
name|dns_rrl_rtype_t
name|rtype
range|:
literal|4
decl_stmt|;
comment|/* 3 bits + sign bit */
name|isc_boolean_t
name|ipv6
range|:
literal|1
decl_stmt|;
block|}
name|s
struct|;
name|isc_uint16_t
name|w
index|[
literal|1
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * A rate-limit entry.  * This should be small to limit the total size of the table of entries.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_rrl_entry
name|dns_rrl_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dns_rrl_entry_t
argument_list|)
name|dns_rrl_bin_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|dns_rrl_entry
block|{
name|ISC_LINK
argument_list|(
argument|dns_rrl_entry_t
argument_list|)
name|lru
expr_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_rrl_entry_t
argument_list|)
name|hlink
expr_stmt|;
name|dns_rrl_key_t
name|key
decl_stmt|;
define|#
directive|define
name|DNS_RRL_RESPONSE_BITS
value|24
name|signed
name|int
name|responses
range|:
name|DNS_RRL_RESPONSE_BITS
decl_stmt|;
define|#
directive|define
name|DNS_RRL_QNAMES_BITS
value|8
name|unsigned
name|int
name|log_qname
range|:
name|DNS_RRL_QNAMES_BITS
decl_stmt|;
define|#
directive|define
name|DNS_RRL_TS_GEN_BITS
value|2
name|unsigned
name|int
name|ts_gen
range|:
name|DNS_RRL_TS_GEN_BITS
decl_stmt|;
name|isc_boolean_t
name|ts_valid
range|:
literal|1
decl_stmt|;
define|#
directive|define
name|DNS_RRL_HASH_GEN_BITS
value|1
name|unsigned
name|int
name|hash_gen
range|:
name|DNS_RRL_HASH_GEN_BITS
decl_stmt|;
name|isc_boolean_t
name|logged
range|:
literal|1
decl_stmt|;
define|#
directive|define
name|DNS_RRL_LOG_BITS
value|11
name|unsigned
name|int
name|log_secs
range|:
name|DNS_RRL_LOG_BITS
decl_stmt|;
define|#
directive|define
name|DNS_RRL_TS_BITS
value|12
name|unsigned
name|int
name|ts
range|:
name|DNS_RRL_TS_BITS
decl_stmt|;
define|#
directive|define
name|DNS_RRL_MAX_SLIP
value|10
name|unsigned
name|int
name|slip_cnt
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DNS_RRL_MAX_TIME_TRAVEL
value|5
end_define

begin_define
define|#
directive|define
name|DNS_RRL_FOREVER
value|(1<<DNS_RRL_TS_BITS)
end_define

begin_define
define|#
directive|define
name|DNS_RRL_MAX_TS
value|(DNS_RRL_FOREVER - 1)
end_define

begin_define
define|#
directive|define
name|DNS_RRL_MAX_RESPONSES
value|((1<<(DNS_RRL_RESPONSE_BITS-1))-1)
end_define

begin_define
define|#
directive|define
name|DNS_RRL_MAX_WINDOW
value|3600
end_define

begin_if
if|#
directive|if
name|DNS_RRL_MAX_WINDOW
operator|>=
name|DNS_RRL_MAX_TS
end_if

begin_error
error|#
directive|error
literal|"DNS_RRL_MAX_WINDOW is too large"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DNS_RRL_MAX_RATE
value|1000
end_define

begin_if
if|#
directive|if
name|DNS_RRL_MAX_RATE
operator|>=
operator|(
name|DNS_RRL_MAX_RESPONSES
operator|/
name|DNS_RRL_MAX_WINDOW
operator|)
end_if

begin_error
error|#
directive|error
literal|"DNS_RRL_MAX_rate is too large"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
literal|1
operator|<<
name|DNS_RRL_LOG_BITS
operator|)
operator|>=
name|DNS_RRL_FOREVER
end_if

begin_error
error|#
directive|error
error|DNS_RRL_LOG_BITS is too big
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DNS_RRL_MAX_LOG_SECS
value|1800
end_define

begin_if
if|#
directive|if
name|DNS_RRL_MAX_LOG_SECS
operator|>=
operator|(
literal|1
operator|<<
name|DNS_RRL_LOG_BITS
operator|)
end_if

begin_error
error|#
directive|error
literal|"DNS_RRL_MAX_LOG_SECS is too large"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DNS_RRL_STOP_LOG_SECS
value|60
end_define

begin_if
if|#
directive|if
name|DNS_RRL_STOP_LOG_SECS
operator|>=
operator|(
literal|1
operator|<<
name|DNS_RRL_LOG_BITS
operator|)
end_if

begin_error
error|#
directive|error
literal|"DNS_RRL_STOP_LOG_SECS is too large"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * A hash table of rate-limit entries.  */
end_comment

begin_struct
struct|struct
name|dns_rrl_hash
block|{
name|isc_stdtime_t
name|check_time
decl_stmt|;
name|unsigned
name|int
name|gen
range|:
name|DNS_RRL_HASH_GEN_BITS
decl_stmt|;
name|int
name|length
decl_stmt|;
name|dns_rrl_bin_t
name|bins
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A block of rate-limit entries.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_rrl_block
name|dns_rrl_block_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dns_rrl_block
block|{
name|ISC_LINK
argument_list|(
argument|dns_rrl_block_t
argument_list|)
name|link
expr_stmt|;
name|int
name|size
decl_stmt|;
name|dns_rrl_entry_t
name|entries
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A rate limited qname buffer.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_rrl_qname_buf
name|dns_rrl_qname_buf_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dns_rrl_qname_buf
block|{
name|ISC_LINK
argument_list|(
argument|dns_rrl_qname_buf_t
argument_list|)
name|link
expr_stmt|;
specifier|const
name|dns_rrl_entry_t
modifier|*
name|e
decl_stmt|;
name|unsigned
name|int
name|index
decl_stmt|;
name|dns_fixedname_t
name|qname
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dns_rrl_rate
name|dns_rrl_rate_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dns_rrl_rate
block|{
name|int
name|r
decl_stmt|;
name|int
name|scaled
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-view query rate limit parameters and a pointer to database.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_rrl
name|dns_rrl_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dns_rrl
block|{
name|isc_mutex_t
name|lock
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_boolean_t
name|log_only
decl_stmt|;
name|dns_rrl_rate_t
name|responses_per_second
decl_stmt|;
name|dns_rrl_rate_t
name|referrals_per_second
decl_stmt|;
name|dns_rrl_rate_t
name|nodata_per_second
decl_stmt|;
name|dns_rrl_rate_t
name|nxdomains_per_second
decl_stmt|;
name|dns_rrl_rate_t
name|errors_per_second
decl_stmt|;
name|dns_rrl_rate_t
name|all_per_second
decl_stmt|;
name|dns_rrl_rate_t
name|slip
decl_stmt|;
name|int
name|window
decl_stmt|;
name|double
name|qps_scale
decl_stmt|;
name|int
name|max_entries
decl_stmt|;
name|dns_acl_t
modifier|*
name|exempt
decl_stmt|;
name|int
name|num_entries
decl_stmt|;
name|int
name|qps_responses
decl_stmt|;
name|isc_stdtime_t
name|qps_time
decl_stmt|;
name|double
name|qps
decl_stmt|;
name|unsigned
name|int
name|probes
decl_stmt|;
name|unsigned
name|int
name|searches
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_rrl_block_t
argument_list|)
name|blocks
expr_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_rrl_entry_t
argument_list|)
name|lru
expr_stmt|;
name|dns_rrl_hash_t
modifier|*
name|hash
decl_stmt|;
name|dns_rrl_hash_t
modifier|*
name|old_hash
decl_stmt|;
name|unsigned
name|int
name|hash_gen
decl_stmt|;
name|unsigned
name|int
name|ts_gen
decl_stmt|;
define|#
directive|define
name|DNS_RRL_TS_BASES
value|(1<<DNS_RRL_TS_GEN_BITS)
name|isc_stdtime_t
name|ts_bases
index|[
name|DNS_RRL_TS_BASES
index|]
decl_stmt|;
name|int
name|ipv4_prefixlen
decl_stmt|;
name|isc_uint32_t
name|ipv4_mask
decl_stmt|;
name|int
name|ipv6_prefixlen
decl_stmt|;
name|isc_uint32_t
name|ipv6_mask
index|[
literal|4
index|]
decl_stmt|;
name|isc_stdtime_t
name|log_stops_time
decl_stmt|;
name|dns_rrl_entry_t
modifier|*
name|last_logged
decl_stmt|;
name|int
name|num_logged
decl_stmt|;
name|int
name|num_qnames
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_rrl_qname_buf_t
argument_list|)
name|qname_free
expr_stmt|;
define|#
directive|define
name|DNS_RRL_QNAMES
value|(1<<DNS_RRL_QNAMES_BITS)
name|dns_rrl_qname_buf_t
modifier|*
name|qnames
index|[
name|DNS_RRL_QNAMES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|DNS_RRL_RESULT_OK
block|,
name|DNS_RRL_RESULT_DROP
block|,
name|DNS_RRL_RESULT_SLIP
block|, }
name|dns_rrl_result_t
typedef|;
end_typedef

begin_function_decl
name|dns_rrl_result_t
name|dns_rrl
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|client_addr
parameter_list|,
name|isc_boolean_t
name|is_tcp
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|qtype
parameter_list|,
name|dns_name_t
modifier|*
name|qname
parameter_list|,
name|isc_result_t
name|resp_result
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|isc_boolean_t
name|wouldlog
parameter_list|,
name|char
modifier|*
name|log_buf
parameter_list|,
name|unsigned
name|int
name|log_buf_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_rrl_view_destroy
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_rrl_init
parameter_list|(
name|dns_rrl_t
modifier|*
modifier|*
name|rrlp
parameter_list|,
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|int
name|min_entries
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RRL_H */
end_comment

end_unit

