begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011-2013  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RPZ_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RPZ_H
value|1
end_define

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

begin_define
define|#
directive|define
name|DNS_RPZ_PREFIX
value|"rpz-"
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_IP_ZONE
value|DNS_RPZ_PREFIX"ip"
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_NSIP_ZONE
value|DNS_RPZ_PREFIX"nsip"
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_NSDNAME_ZONE
value|DNS_RPZ_PREFIX"nsdname"
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_PASSTHRU_ZONE
value|DNS_RPZ_PREFIX"passthru"
end_define

begin_typedef
typedef|typedef
name|isc_uint8_t
name|dns_rpz_cidr_bits_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|DNS_RPZ_TYPE_BAD
block|,
name|DNS_RPZ_TYPE_QNAME
block|,
name|DNS_RPZ_TYPE_IP
block|,
name|DNS_RPZ_TYPE_NSDNAME
block|,
name|DNS_RPZ_TYPE_NSIP
block|}
name|dns_rpz_type_t
typedef|;
end_typedef

begin_comment
comment|/*  * Require DNS_RPZ_POLICY_PASSTHRU< DNS_RPZ_POLICY_NXDOMAIN<  * DNS_RPZ_POLICY_NODATA< DNS_RPZ_POLICY_CNAME to choose among competing  * policies.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DNS_RPZ_POLICY_GIVEN
init|=
literal|0
block|,
comment|/* 'given': what policy record says */
name|DNS_RPZ_POLICY_DISABLED
init|=
literal|1
block|,
comment|/* 'cname x': answer with x's rrsets */
name|DNS_RPZ_POLICY_PASSTHRU
init|=
literal|2
block|,
comment|/* 'passthru': do not rewrite */
name|DNS_RPZ_POLICY_NXDOMAIN
init|=
literal|3
block|,
comment|/* 'nxdomain': answer with NXDOMAIN */
name|DNS_RPZ_POLICY_NODATA
init|=
literal|4
block|,
comment|/* 'nodata': answer with ANCOUNT=0 */
name|DNS_RPZ_POLICY_CNAME
init|=
literal|5
block|,
comment|/* 'cname x': answer with x's rrsets */
name|DNS_RPZ_POLICY_RECORD
block|,
name|DNS_RPZ_POLICY_WILDCNAME
block|,
name|DNS_RPZ_POLICY_MISS
block|,
name|DNS_RPZ_POLICY_ERROR
block|}
name|dns_rpz_policy_t
typedef|;
end_typedef

begin_comment
comment|/*  * Specify a response policy zone.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_rpz_zone
name|dns_rpz_zone_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dns_rpz_zone
block|{
name|ISC_LINK
argument_list|(
argument|dns_rpz_zone_t
argument_list|)
name|link
expr_stmt|;
name|int
name|num
decl_stmt|;
comment|/* ordinal in list of policy zones */
name|dns_name_t
name|origin
decl_stmt|;
comment|/* Policy zone name */
name|dns_name_t
name|nsdname
decl_stmt|;
comment|/* DNS_RPZ_NSDNAME_ZONE.origin */
name|dns_name_t
name|passthru
decl_stmt|;
comment|/* DNS_RPZ_PASSTHRU_ZONE. */
name|dns_name_t
name|cname
decl_stmt|;
comment|/* override value for ..._CNAME */
name|dns_ttl_t
name|max_policy_ttl
decl_stmt|;
name|dns_rpz_policy_t
name|policy
decl_stmt|;
comment|/* DNS_RPZ_POLICY_GIVEN or override */
name|isc_boolean_t
name|recursive_only
decl_stmt|;
name|isc_boolean_t
name|defined
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Radix trees for response policy IP addresses.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_rpz_cidr
name|dns_rpz_cidr_t
typedef|;
end_typedef

begin_comment
comment|/*  * context for finding the best policy  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|state
decl_stmt|;
define|#
directive|define
name|DNS_RPZ_REWRITTEN
value|0x0001
define|#
directive|define
name|DNS_RPZ_DONE_QNAME
value|0x0002
comment|/* qname checked */
define|#
directive|define
name|DNS_RPZ_DONE_QNAME_IP
value|0x0004
comment|/* IP addresses of qname checked */
define|#
directive|define
name|DNS_RPZ_DONE_NSDNAME
value|0x0008
comment|/* NS name missed; checking addresses */
define|#
directive|define
name|DNS_RPZ_DONE_IPv4
value|0x0010
define|#
directive|define
name|DNS_RPZ_RECURSING
value|0x0020
define|#
directive|define
name|DNS_RPZ_HAVE_IP
value|0x0040
comment|/* a policy zone has IP addresses */
define|#
directive|define
name|DNS_RPZ_HAVE_NSIPv4
value|0x0080
comment|/*		  IPv4 NISP addresses */
define|#
directive|define
name|DNS_RPZ_HAVE_NSIPv6
value|0x0100
comment|/*		  IPv6 NISP addresses */
define|#
directive|define
name|DNS_RPZ_HAVE_NSDNAME
value|0x0200
comment|/*		  NS names */
comment|/* 	 * Best match so far. 	 */
struct|struct
block|{
name|dns_rpz_type_t
name|type
decl_stmt|;
name|dns_rpz_zone_t
modifier|*
name|rpz
decl_stmt|;
name|dns_rpz_cidr_bits_t
name|prefix
decl_stmt|;
name|dns_rpz_policy_t
name|policy
decl_stmt|;
name|dns_ttl_t
name|ttl
decl_stmt|;
name|isc_result_t
name|result
decl_stmt|;
name|dns_zone_t
modifier|*
name|zone
decl_stmt|;
name|dns_db_t
modifier|*
name|db
decl_stmt|;
name|dns_dbversion_t
modifier|*
name|version
decl_stmt|;
name|dns_dbnode_t
modifier|*
name|node
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|rdataset
decl_stmt|;
block|}
name|m
struct|;
comment|/* 	 * State for chasing IP addresses and NS names including recursion. 	 */
struct|struct
block|{
name|unsigned
name|int
name|label
decl_stmt|;
name|dns_db_t
modifier|*
name|db
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|ns_rdataset
decl_stmt|;
name|dns_rdatatype_t
name|r_type
decl_stmt|;
name|isc_result_t
name|r_result
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|r_rdataset
decl_stmt|;
block|}
name|r
struct|;
comment|/* 	 * State of real query while recursing for NSIP or NSDNAME. 	 */
struct|struct
block|{
name|isc_result_t
name|result
decl_stmt|;
name|isc_boolean_t
name|is_zone
decl_stmt|;
name|isc_boolean_t
name|authoritative
decl_stmt|;
name|dns_zone_t
modifier|*
name|zone
decl_stmt|;
name|dns_db_t
modifier|*
name|db
decl_stmt|;
name|dns_dbnode_t
modifier|*
name|node
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|rdataset
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|sigrdataset
decl_stmt|;
name|dns_rdatatype_t
name|qtype
decl_stmt|;
block|}
name|q
struct|;
name|dns_name_t
modifier|*
name|qname
decl_stmt|;
name|dns_name_t
modifier|*
name|r_name
decl_stmt|;
name|dns_name_t
modifier|*
name|fname
decl_stmt|;
name|dns_fixedname_t
name|_qnamef
decl_stmt|;
name|dns_fixedname_t
name|_r_namef
decl_stmt|;
name|dns_fixedname_t
name|_fnamef
decl_stmt|;
block|}
name|dns_rpz_st_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_RPZ_TTL_DEFAULT
value|5
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_MAX_TTL_DEFAULT
value|DNS_RPZ_TTL_DEFAULT
end_define

begin_comment
comment|/*  * So various response policy zone messages can be turned up or down.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RPZ_ERROR_LEVEL
value|ISC_LOG_WARNING
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_INFO_LEVEL
value|ISC_LOG_INFO
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_DEBUG_LEVEL1
value|ISC_LOG_DEBUG(1)
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_DEBUG_LEVEL2
value|ISC_LOG_DEBUG(2)
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_DEBUG_LEVEL3
value|ISC_LOG_DEBUG(3)
end_define

begin_define
define|#
directive|define
name|DNS_RPZ_DEBUG_QUIET
value|(DNS_RPZ_DEBUG_LEVEL3+1)
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|dns_rpz_type2str
parameter_list|(
name|dns_rpz_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_rpz_policy_t
name|dns_rpz_str2policy
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|dns_rpz_policy2str
parameter_list|(
name|dns_rpz_policy_t
name|policy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_rpz_cidr_free
parameter_list|(
name|dns_rpz_cidr_t
modifier|*
modifier|*
name|cidr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_rpz_view_destroy
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_rpz_new_cidr
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_rpz_cidr_t
modifier|*
modifier|*
name|rbtdb_cidr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_rpz_enabled_get
parameter_list|(
name|dns_rpz_cidr_t
modifier|*
name|cidr
parameter_list|,
name|dns_rpz_st_t
modifier|*
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_rpz_cidr_deleteip
parameter_list|(
name|dns_rpz_cidr_t
modifier|*
name|cidr
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_rpz_cidr_addip
parameter_list|(
name|dns_rpz_cidr_t
modifier|*
name|cidr
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_rpz_cidr_find
parameter_list|(
name|dns_rpz_cidr_t
modifier|*
name|cidr
parameter_list|,
specifier|const
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|,
name|dns_rpz_type_t
name|type
parameter_list|,
name|dns_name_t
modifier|*
name|canon_name
parameter_list|,
name|dns_name_t
modifier|*
name|search_name
parameter_list|,
name|dns_rpz_cidr_bits_t
modifier|*
name|prefix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_rpz_policy_t
name|dns_rpz_decode_cname
parameter_list|(
name|dns_rpz_zone_t
modifier|*
name|rpz
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_name_t
modifier|*
name|selfname
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
comment|/* DNS_RPZ_H */
end_comment

end_unit

