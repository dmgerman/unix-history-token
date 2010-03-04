begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: types.h,v 1.130.50.3.12.2 2009/12/31 20:29:21 each Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_TYPES_H
value|1
end_define

begin_comment
comment|/*! \file dns/types.h  * \brief  * Including this file gives you type declarations suitable for use in  * .h files, which lets us avoid circular type reference problems.  * \brief  * To actually use a type or get declarations of its methods, you must  * include the appropriate .h file too.  */
end_comment

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|dns_acache
name|dns_acache_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_acacheentry
name|dns_acacheentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_acachestats
name|dns_acachestats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_acl
name|dns_acl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_aclelement
name|dns_aclelement_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_aclenv
name|dns_aclenv_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_adb
name|dns_adb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_adbaddrinfo
name|dns_adbaddrinfo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dns_adbaddrinfo_t
argument_list|)
name|dns_adbaddrinfolist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_adbentry
name|dns_adbentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_adbfind
name|dns_adbfind_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dns_adbfind_t
argument_list|)
name|dns_adbfindlist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_byaddr
name|dns_byaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_cache
name|dns_cache_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|dns_cert_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_compress
name|dns_compress_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_db
name|dns_db_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dbimplementation
name|dns_dbimplementation_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dbiterator
name|dns_dbiterator_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|dns_dbload_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|dns_dbnode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dbtable
name|dns_dbtable_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|dns_dbversion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dlzimplementation
name|dns_dlzimplementation_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dlzdb
name|dns_dlzdb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_sdlzimplementation
name|dns_sdlzimplementation_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_decompress
name|dns_decompress_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dispatch
name|dns_dispatch_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dispatchevent
name|dns_dispatchevent_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dispatchlist
name|dns_dispatchlist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dispatchmgr
name|dns_dispatchmgr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dispentry
name|dns_dispentry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_dumpctx
name|dns_dumpctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_fetch
name|dns_fetch_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_fixedname
name|dns_fixedname_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_forwarders
name|dns_forwarders_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_fwdtable
name|dns_fwdtable_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_iptable
name|dns_iptable_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint32_t
name|dns_iterations_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|dns_keyflags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_keynode
name|dns_keynode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_keytable
name|dns_keytable_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|dns_keytag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_loadctx
name|dns_loadctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_loadmgr
name|dns_loadmgr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_message
name|dns_message_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|dns_messageid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_region_t
name|dns_label_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_lookup
name|dns_lookup_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_name
name|dns_name_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dns_name_t
argument_list|)
name|dns_namelist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|dns_opcode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|dns_offsets_t
index|[
literal|128
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_order
name|dns_order_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_peer
name|dns_peer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_peerlist
name|dns_peerlist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_portlist
name|dns_portlist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_rbt
name|dns_rbt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|dns_rcode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_rdata
name|dns_rdata_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_rdatacallbacks
name|dns_rdatacallbacks_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|dns_rdataclass_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_rdatalist
name|dns_rdatalist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_rdataset
name|dns_rdataset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dns_rdataset_t
argument_list|)
name|dns_rdatasetlist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_rdatasetiter
name|dns_rdatasetiter_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|dns_rdatatype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_request
name|dns_request_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_requestmgr
name|dns_requestmgr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_resolver
name|dns_resolver_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_sdbimplementation
name|dns_sdbimplementation_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint8_t
name|dns_secalg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint8_t
name|dns_secproto_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_signature
name|dns_signature_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_ssurule
name|dns_ssurule_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_ssutable
name|dns_ssutable_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_stats
name|dns_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint32_t
name|dns_rdatastatstype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_tkeyctx
name|dns_tkeyctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint16_t
name|dns_trust_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_tsig_keyring
name|dns_tsig_keyring_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_tsigkey
name|dns_tsigkey_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint32_t
name|dns_ttl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_validator
name|dns_validator_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_view
name|dns_view_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dns_view_t
argument_list|)
name|dns_viewlist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_zone
name|dns_zone_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dns_zone_t
argument_list|)
name|dns_zonelist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_zonemgr
name|dns_zonemgr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dns_zt
name|dns_zt_t
typedef|;
end_typedef

begin_comment
comment|/*  * If we are not using GSSAPI, define the types we use as opaque types here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|not_defined_gss_cred_id
modifier|*
name|gss_cred_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|not_defined_gss_ctx
modifier|*
name|gss_ctx_id_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|dst_gssapi_signverifyctx
name|dst_gssapi_signverifyctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_hash_sha1
init|=
literal|1
block|}
name|dns_hash_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_fwdpolicy_none
init|=
literal|0
block|,
name|dns_fwdpolicy_first
init|=
literal|1
block|,
name|dns_fwdpolicy_only
init|=
literal|2
block|}
name|dns_fwdpolicy_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_namereln_none
init|=
literal|0
block|,
name|dns_namereln_contains
init|=
literal|1
block|,
name|dns_namereln_subdomain
init|=
literal|2
block|,
name|dns_namereln_equal
init|=
literal|3
block|,
name|dns_namereln_commonancestor
init|=
literal|4
block|}
name|dns_namereln_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_one_answer
block|,
name|dns_many_answers
block|}
name|dns_transfer_format_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_dbtype_zone
init|=
literal|0
block|,
name|dns_dbtype_cache
init|=
literal|1
block|,
name|dns_dbtype_stub
init|=
literal|3
block|}
name|dns_dbtype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_notifytype_no
init|=
literal|0
block|,
name|dns_notifytype_yes
init|=
literal|1
block|,
name|dns_notifytype_explicit
init|=
literal|2
block|,
name|dns_notifytype_masteronly
init|=
literal|3
block|}
name|dns_notifytype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_dialuptype_no
init|=
literal|0
block|,
name|dns_dialuptype_yes
init|=
literal|1
block|,
name|dns_dialuptype_notify
init|=
literal|2
block|,
name|dns_dialuptype_notifypassive
init|=
literal|3
block|,
name|dns_dialuptype_refresh
init|=
literal|4
block|,
name|dns_dialuptype_passive
init|=
literal|5
block|}
name|dns_dialuptype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_masterformat_none
init|=
literal|0
block|,
name|dns_masterformat_text
init|=
literal|1
block|,
name|dns_masterformat_raw
init|=
literal|2
block|}
name|dns_masterformat_t
typedef|;
end_typedef

begin_comment
comment|/*  * These are generated by gen.c.  */
end_comment

begin_include
include|#
directive|include
file|<dns/enumtype.h>
end_include

begin_comment
comment|/* Provides dns_rdatatype_t. */
end_comment

begin_include
include|#
directive|include
file|<dns/enumclass.h>
end_include

begin_comment
comment|/* Provides dns_rdataclass_t. */
end_comment

begin_comment
comment|/*%  * rcodes.  */
end_comment

begin_enum
enum|enum
block|{
comment|/* 	 * Standard rcodes. 	 */
name|dns_rcode_noerror
init|=
literal|0
block|,
define|#
directive|define
name|dns_rcode_noerror
value|((dns_rcode_t)dns_rcode_noerror)
name|dns_rcode_formerr
init|=
literal|1
block|,
define|#
directive|define
name|dns_rcode_formerr
value|((dns_rcode_t)dns_rcode_formerr)
name|dns_rcode_servfail
init|=
literal|2
block|,
define|#
directive|define
name|dns_rcode_servfail
value|((dns_rcode_t)dns_rcode_servfail)
name|dns_rcode_nxdomain
init|=
literal|3
block|,
define|#
directive|define
name|dns_rcode_nxdomain
value|((dns_rcode_t)dns_rcode_nxdomain)
name|dns_rcode_notimp
init|=
literal|4
block|,
define|#
directive|define
name|dns_rcode_notimp
value|((dns_rcode_t)dns_rcode_notimp)
name|dns_rcode_refused
init|=
literal|5
block|,
define|#
directive|define
name|dns_rcode_refused
value|((dns_rcode_t)dns_rcode_refused)
name|dns_rcode_yxdomain
init|=
literal|6
block|,
define|#
directive|define
name|dns_rcode_yxdomain
value|((dns_rcode_t)dns_rcode_yxdomain)
name|dns_rcode_yxrrset
init|=
literal|7
block|,
define|#
directive|define
name|dns_rcode_yxrrset
value|((dns_rcode_t)dns_rcode_yxrrset)
name|dns_rcode_nxrrset
init|=
literal|8
block|,
define|#
directive|define
name|dns_rcode_nxrrset
value|((dns_rcode_t)dns_rcode_nxrrset)
name|dns_rcode_notauth
init|=
literal|9
block|,
define|#
directive|define
name|dns_rcode_notauth
value|((dns_rcode_t)dns_rcode_notauth)
name|dns_rcode_notzone
init|=
literal|10
block|,
define|#
directive|define
name|dns_rcode_notzone
value|((dns_rcode_t)dns_rcode_notzone)
comment|/* 	 * Extended rcodes. 	 */
name|dns_rcode_badvers
init|=
literal|16
define|#
directive|define
name|dns_rcode_badvers
value|((dns_rcode_t)dns_rcode_badvers)
block|}
enum|;
end_enum

begin_comment
comment|/*%  * TSIG errors.  */
end_comment

begin_enum
enum|enum
block|{
name|dns_tsigerror_badsig
init|=
literal|16
block|,
name|dns_tsigerror_badkey
init|=
literal|17
block|,
name|dns_tsigerror_badtime
init|=
literal|18
block|,
name|dns_tsigerror_badmode
init|=
literal|19
block|,
name|dns_tsigerror_badname
init|=
literal|20
block|,
name|dns_tsigerror_badalg
init|=
literal|21
block|,
name|dns_tsigerror_badtrunc
init|=
literal|22
block|}
enum|;
end_enum

begin_comment
comment|/*%  * Opcodes.  */
end_comment

begin_enum
enum|enum
block|{
name|dns_opcode_query
init|=
literal|0
block|,
define|#
directive|define
name|dns_opcode_query
value|((dns_opcode_t)dns_opcode_query)
name|dns_opcode_iquery
init|=
literal|1
block|,
define|#
directive|define
name|dns_opcode_iquery
value|((dns_opcode_t)dns_opcode_iquery)
name|dns_opcode_status
init|=
literal|2
block|,
define|#
directive|define
name|dns_opcode_status
value|((dns_opcode_t)dns_opcode_status)
name|dns_opcode_notify
init|=
literal|4
block|,
define|#
directive|define
name|dns_opcode_notify
value|((dns_opcode_t)dns_opcode_notify)
name|dns_opcode_update
init|=
literal|5
comment|/* dynamic update */
define|#
directive|define
name|dns_opcode_update
value|((dns_opcode_t)dns_opcode_update)
block|}
enum|;
end_enum

begin_comment
comment|/*%  * Trust levels.  Must be kept in sync with trustnames[] in masterdump.c.  */
end_comment

begin_enum
enum|enum
block|{
comment|/* Sentinel value; no data should have this trust level. */
name|dns_trust_none
init|=
literal|0
block|,
define|#
directive|define
name|dns_trust_none
value|((dns_trust_t)dns_trust_none)
comment|/*% 	 * Subject to DNSSEC validation but has not yet been validated 	 * dns_trust_pending_additional (from the additional section). 	 */
name|dns_trust_pending_additional
init|=
literal|1
block|,
define|#
directive|define
name|dns_trust_pending_additional
define|\
value|((dns_trust_t)dns_trust_pending_additional)
name|dns_trust_pending_answer
init|=
literal|2
block|,
define|#
directive|define
name|dns_trust_pending_answer
value|((dns_trust_t)dns_trust_pending_answer)
comment|/*% Received in the additional section of a response. */
name|dns_trust_additional
init|=
literal|3
block|,
define|#
directive|define
name|dns_trust_additional
value|((dns_trust_t)dns_trust_additional)
comment|/* Received in a referral response. */
name|dns_trust_glue
init|=
literal|4
block|,
define|#
directive|define
name|dns_trust_glue
value|((dns_trust_t)dns_trust_glue)
comment|/* Answer from a non-authoritative server */
name|dns_trust_answer
init|=
literal|5
block|,
define|#
directive|define
name|dns_trust_answer
value|((dns_trust_t)dns_trust_answer)
comment|/*  Received in the authority section as part of an 	    authoritative response */
name|dns_trust_authauthority
init|=
literal|6
block|,
define|#
directive|define
name|dns_trust_authauthority
value|((dns_trust_t)dns_trust_authauthority)
comment|/* Answer from an authoritative server */
name|dns_trust_authanswer
init|=
literal|7
block|,
define|#
directive|define
name|dns_trust_authanswer
value|((dns_trust_t)dns_trust_authanswer)
comment|/* Successfully DNSSEC validated */
name|dns_trust_secure
init|=
literal|8
block|,
define|#
directive|define
name|dns_trust_secure
value|((dns_trust_t)dns_trust_secure)
comment|/* This server is authoritative */
name|dns_trust_ultimate
init|=
literal|9
define|#
directive|define
name|dns_trust_ultimate
value|((dns_trust_t)dns_trust_ultimate)
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DNS_TRUST_PENDING
parameter_list|(
name|x
parameter_list|)
value|((x) == dns_trust_pending_answer || \ 					 (x) == dns_trust_pending_additional)
end_define

begin_define
define|#
directive|define
name|DNS_TRUST_ADDITIONAL
parameter_list|(
name|x
parameter_list|)
value|((x) == dns_trust_additional || \ 					 (x) == dns_trust_pending_additional)
end_define

begin_define
define|#
directive|define
name|DNS_TRUST_GLUE
parameter_list|(
name|x
parameter_list|)
value|((x) == dns_trust_glue)
end_define

begin_comment
comment|/*%  * Name checking severities.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_severity_ignore
block|,
name|dns_severity_warn
block|,
name|dns_severity_fail
block|}
name|dns_severity_t
typedef|;
end_typedef

begin_comment
comment|/*  * Functions.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_dumpdonefunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|isc_result_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_loaddonefunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|isc_result_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_addrdatasetfunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|dns_name_t
modifier|*
parameter_list|,
name|dns_rdataset_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_additionaldatafunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|dns_name_t
modifier|*
parameter_list|,
name|dns_rdatatype_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_digestfunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|isc_region_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_xfrindone_t
function_decl|)
parameter_list|(
name|dns_zone_t
modifier|*
parameter_list|,
name|isc_result_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_updatecallback_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|isc_result_t
parameter_list|,
name|dns_message_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|dns_rdatasetorderfunc_t
function_decl|)
parameter_list|(
specifier|const
name|dns_rdata_t
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_boolean_t
function_decl|(
modifier|*
name|dns_checkmxfunc_t
function_decl|)
parameter_list|(
name|dns_zone_t
modifier|*
parameter_list|,
name|dns_name_t
modifier|*
parameter_list|,
name|dns_name_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_boolean_t
function_decl|(
modifier|*
name|dns_checksrvfunc_t
function_decl|)
parameter_list|(
name|dns_zone_t
modifier|*
parameter_list|,
name|dns_name_t
modifier|*
parameter_list|,
name|dns_name_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_boolean_t
function_decl|(
modifier|*
name|dns_checknsfunc_t
function_decl|)
parameter_list|(
name|dns_zone_t
modifier|*
parameter_list|,
name|dns_name_t
modifier|*
parameter_list|,
name|dns_name_t
modifier|*
parameter_list|,
name|dns_rdataset_t
modifier|*
parameter_list|,
name|dns_rdataset_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_boolean_t
function_decl|(
modifier|*
name|dns_isselffunc_t
function_decl|)
parameter_list|(
name|dns_view_t
modifier|*
parameter_list|,
name|dns_tsigkey_t
modifier|*
parameter_list|,
name|isc_sockaddr_t
modifier|*
parameter_list|,
name|isc_sockaddr_t
modifier|*
parameter_list|,
name|dns_rdataclass_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_TYPES_H */
end_comment

end_unit

