begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iterator/iter_utils.h - iterative resolver module utility functions.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to assist the iterator module.  * Configuration options. Forward zones.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITERATOR_ITER_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|ITERATOR_ITER_UTILS_H
end_define

begin_include
include|#
directive|include
file|"iterator/iter_resptype.h"
end_include

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iter_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iter_hints
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iter_forwards
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|delegpt_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|delegpt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|msg_parse
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_randstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reply_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_qstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sock_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Process config options and set iterator module state.  * Sets default values if no config is found.  * @param iter_env: iterator module state.  * @param cfg: config options.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|iter_apply_cfg
parameter_list|(
name|struct
name|iter_env
modifier|*
name|iter_env
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Select a valid, nice target to send query to.  * Sorting and removing unsuitable targets is combined.  *  * @param iter_env: iterator module global state, with ip6 enabled and   *	do-not-query-addresses.  * @param env: environment with infra cache (lameness, rtt info).  * @param dp: delegation point with result list.  * @param name: zone name (for lameness check).  * @param namelen: length of name.  * @param qtype: query type that we want to send.  * @param dnssec_lame: set to 1, if a known dnssec-lame server is selected  *	these are not preferred, but are used as a last resort.  * @param chase_to_rd: set to 1 if a known recursion lame server is selected  * 	these are not preferred, but are used as a last resort.  * @param open_target: number of currently outstanding target queries.  * 	If we wait for these, perhaps more server addresses become available.  * @param blacklist: the IP blacklist to use.  * @return best target or NULL if no target.  *	if not null, that target is removed from the result list in the dp.  */
end_comment

begin_function_decl
name|struct
name|delegpt_addr
modifier|*
name|iter_server_selection
parameter_list|(
name|struct
name|iter_env
modifier|*
name|iter_env
parameter_list|,
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|qtype
parameter_list|,
name|int
modifier|*
name|dnssec_lame
parameter_list|,
name|int
modifier|*
name|chase_to_rd
parameter_list|,
name|int
name|open_target
parameter_list|,
name|struct
name|sock_list
modifier|*
name|blacklist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate dns_msg from parsed msg, in regional.  * @param pkt: packet.  * @param msg: parsed message (cleaned and ready for regional allocation).  * @param regional: regional to use for allocation.  * @return newly allocated dns_msg, or NULL on memory error.  */
end_comment

begin_function_decl
name|struct
name|dns_msg
modifier|*
name|dns_alloc_msg
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|struct
name|msg_parse
modifier|*
name|msg
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Copy a dns_msg to this regional.  * @param from: dns message, also in regional.  * @param regional: regional to use for allocation.  * @return newly allocated dns_msg, or NULL on memory error.  */
end_comment

begin_function_decl
name|struct
name|dns_msg
modifier|*
name|dns_copy_msg
parameter_list|(
name|struct
name|dns_msg
modifier|*
name|from
parameter_list|,
name|struct
name|regional
modifier|*
name|regional
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate a dns_msg with malloc/alloc structure and store in dns cache.  * @param env: environment, with alloc structure and dns cache.  * @param qinf: query info, the query for which answer is stored.  * @param rep: reply in dns_msg from dns_alloc_msg for example.  * @param is_referral: If true, then the given message to be stored is a  *	referral. The cache implementation may use this as a hint.  * @param leeway: prefetch TTL leeway to expire old rrsets quicker.  * @param pside: true if dp is parentside, thus message is 'fresh' and NS  * 	can be prefetch-updates.  * @param region: to copy modified (cache is better) rrs back to.  * @return void, because we are not interested in alloc errors,  * 	the iterator and validator can operate on the results in their  * 	scratch space (the qstate.region) and are not dependent on the cache.  * 	It is useful to log the alloc failure (for the server operator),  * 	but the query resolution can continue without cache storage.  */
end_comment

begin_function_decl
name|void
name|iter_dns_store
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinf
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|int
name|is_referral
parameter_list|,
name|time_t
name|leeway
parameter_list|,
name|int
name|pside
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Select randomly with n/m probability.  * For shuffle NS records for address fetching.  * @param rnd: random table  * @param n: probability.  * @param m: divisor for probability.  * @return true with n/m probability.  */
end_comment

begin_function_decl
name|int
name|iter_ns_probability
parameter_list|(
name|struct
name|ub_randstate
modifier|*
name|rnd
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Mark targets that result in a dependency cycle as done, so they  * will not get selected as targets.  * @param qstate: query state.  * @param dp: delegpt to mark ns in.  */
end_comment

begin_function_decl
name|void
name|iter_mark_cycle_targets
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Mark targets that result in a dependency cycle as done, so they  * will not get selected as targets.  For the parent-side lookups.  * @param qstate: query state.  * @param dp: delegpt to mark ns in.  */
end_comment

begin_function_decl
name|void
name|iter_mark_pside_cycle_targets
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if delegation is useful or offers immediately no targets for   * further recursion.  * @param qinfo: query name and type  * @param qflags: query flags with RD flag  * @param dp: delegpt to check.  * @return true if dp is useless.  */
end_comment

begin_function_decl
name|int
name|iter_dp_is_useless
parameter_list|(
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint16_t
name|qflags
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if delegation is expected to have DNSSEC information (RRSIGs) in   * its answers, or not. Inspects delegation point (name), trust anchors,  * and delegation message (DS RRset) to determine this.  * @param env: module env with trust anchors.  * @param dp: delegation point.  * @param msg: delegation message, with DS if a secure referral.  * @param dclass: class of query.  * @return 1 if dnssec is expected, 0 if not.  */
end_comment

begin_function_decl
name|int
name|iter_indicates_dnssec
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|dns_msg
modifier|*
name|msg
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if a message contains DNSSEC.  * This is examined by looking for RRSIGs. With DNSSEC a valid answer,   * nxdomain, nodata, referral or cname reply has RRSIGs in answer or auth   * sections, sigs on answer data, SOA, DS, or NSEC/NSEC3 records.  * @param msg: message to examine.  * @return true if DNSSEC information was found.  */
end_comment

begin_function_decl
name|int
name|iter_msg_has_dnssec
parameter_list|(
name|struct
name|dns_msg
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if a message is known to be from a certain zone.  * This looks for SOA or NS rrsets, for answers.  * For referrals, when one label is delegated, the zone is detected.  * Does not look at signatures.  * @param msg: the message to inspect.  * @param dp: delegation point with zone name to look for.  * @param type: type of message.  * @param dclass: class of query.  * @return true if message is certain to be from zone in dp->name.  *	false if not sure (empty msg), or not from the zone.  */
end_comment

begin_function_decl
name|int
name|iter_msg_from_zone
parameter_list|(
name|struct
name|dns_msg
modifier|*
name|msg
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|enum
name|response_type
name|type
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check if two replies are equal  * For fallback procedures  * @param p: reply one. The reply has rrset data pointers in region.  * 	Does not check rrset-IDs  * @param q: reply two  * @param region: scratch buffer.  * @return if one and two are equal.  */
end_comment

begin_function_decl
name|int
name|reply_equal
parameter_list|(
name|struct
name|reply_info
modifier|*
name|p
parameter_list|,
name|struct
name|reply_info
modifier|*
name|q
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Store parent-side rrset in seperate rrset cache entries for later   * last-resort * lookups in case the child-side versions of this information   * fails.  * @param env: environment with cache, time, ...  * @param rrset: the rrset to store (copied).  * Failure to store is logged, but otherwise ignored.  */
end_comment

begin_function_decl
name|void
name|iter_store_parentside_rrset
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Store parent-side NS records from a referral message  * @param env: environment with cache, time, ...  * @param rep: response with NS rrset.  * Failure to store is logged, but otherwise ignored.  */
end_comment

begin_function_decl
name|void
name|iter_store_parentside_NS
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Store parent-side negative element, the parentside rrset does not exist,  * creates an rrset with empty rdata in the rrset cache with PARENTSIDE flag.  * @param env: environment with cache, time, ...  * @param qinfo: the identity of the rrset that is missing.  * @param rep: delegation response or answer response, to glean TTL from.  * (malloc) failure is logged but otherwise ignored.  */
end_comment

begin_function_decl
name|void
name|iter_store_parentside_neg
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add parent NS record if that exists in the cache.  This is both new  * information and acts like a timeout throttle on retries.  * @param env: query env with rrset cache and time.  * @param dp: delegation point to store result in.  Also this dp is used to  *	see which NS name is needed.  * @param region: region to alloc result in.  * @param qinfo: pertinent information, the qclass.  * @return false on malloc failure.  *	if true, the routine worked and if such cached information   *	existed dp->has_parent_side_NS is set true.  */
end_comment

begin_function_decl
name|int
name|iter_lookup_parent_NS_from_cache
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add parent-side glue if that exists in the cache.  This is both new  * information and acts like a timeout throttle on retries to fetch them.  * @param env: query env with rrset cache and time.  * @param dp: delegation point to store result in.  Also this dp is used to  *	see which NS name is needed.  * @param region: region to alloc result in.  * @param qinfo: pertinent information, the qclass.  * @return: true, it worked, no malloc failures, and new addresses (lame)  *	have been added, giving extra options as query targets.  */
end_comment

begin_function_decl
name|int
name|iter_lookup_parent_glue_from_cache
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup next root-hint or root-forward entry.  * @param hints: the hints.  * @param fwd: the forwards.  * @param c: the class to start searching at. 0 means find first one.  * @return false if no classes found, true if found and returned in c.  */
end_comment

begin_function_decl
name|int
name|iter_get_next_root
parameter_list|(
name|struct
name|iter_hints
modifier|*
name|hints
parameter_list|,
name|struct
name|iter_forwards
modifier|*
name|fwd
parameter_list|,
name|uint16_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove DS records that are inappropriate before they are cached.  * @param msg: the response to scrub.  * @param ns: RRSET that is the NS record for the referral.  * 	if NULL, then all DS records are removed from the authority section.  * @param z: zone name that the response is from.  */
end_comment

begin_function_decl
name|void
name|iter_scrub_ds
parameter_list|(
name|struct
name|dns_msg
modifier|*
name|msg
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ns
parameter_list|,
name|uint8_t
modifier|*
name|z
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove query attempts from all available ips. For 0x20.  * @param dp: delegpt.  * @param d: decrease.  */
end_comment

begin_function_decl
name|void
name|iter_dec_attempts
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|int
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add retry counts from older delegpt to newer delegpt.  * Does not waste time on timeout'd (or other failing) addresses.  * @param dp: new delegationpoint.  * @param old: old delegationpoint.  */
end_comment

begin_function_decl
name|void
name|iter_merge_retry_counts
parameter_list|(
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|,
name|struct
name|delegpt
modifier|*
name|old
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if a DS response (type ANSWER) is too low: a nodata answer with   * a SOA record in the authority section at-or-below the qchase.qname.  * Also returns true if we are not sure (i.e. empty message, CNAME nosig).  * @param msg: the response.  * @param dp: the dp name is used to check if the RRSIG gives a clue that  * 	it was originated from the correct nameserver.  * @return true if too low.  */
end_comment

begin_function_decl
name|int
name|iter_ds_toolow
parameter_list|(
name|struct
name|dns_msg
modifier|*
name|msg
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if delegpt can go down a step to the qname or not  * @param qinfo: the query name looked up.  * @param dp: checked if the name can go lower to the qname  * @return true if can go down, false if that would not be possible.  * the current response seems to be the one and only, best possible, response.  */
end_comment

begin_function_decl
name|int
name|iter_dp_cangodown
parameter_list|(
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|delegpt
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITERATOR_ITER_UTILS_H */
end_comment

end_unit

