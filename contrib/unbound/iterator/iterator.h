begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * iterator/iterator.h - iterative resolver DNS query response module  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains a module that performs recusive iterative DNS query  * processing.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITERATOR_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|ITERATOR_ITERATOR_H
end_define

begin_include
include|#
directive|include
file|"services/outbound_list.h"
end_include

begin_include
include|#
directive|include
file|"util/data/msgreply.h"
end_include

begin_include
include|#
directive|include
file|"util/module.h"
end_include

begin_struct_decl
struct_decl|struct
name|delegpt
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
name|iter_donotq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iter_prep_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iter_priv
struct_decl|;
end_struct_decl

begin_comment
comment|/** max number of query restarts. Determines max number of CNAME chain. */
end_comment

begin_define
define|#
directive|define
name|MAX_RESTART_COUNT
value|8
end_define

begin_comment
comment|/** max number of referrals. Makes sure resolver does not run away */
end_comment

begin_define
define|#
directive|define
name|MAX_REFERRAL_COUNT
value|130
end_define

begin_comment
comment|/** max number of queries-sent-out.  Make sure large NS set does not loop */
end_comment

begin_define
define|#
directive|define
name|MAX_SENT_COUNT
value|16
end_define

begin_comment
comment|/** at what query-sent-count to stop target fetch policy */
end_comment

begin_define
define|#
directive|define
name|TARGET_FETCH_STOP
value|3
end_define

begin_comment
comment|/** how nice is a server without further information, in msec   * Equals rtt initial timeout value.  */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_SERVER_NICENESS
value|376
end_define

begin_comment
comment|/** maximum timeout before a host is deemed unsuitable, in msec.   * After host_ttl this will be timed out and the host will be tried again.   * Equals RTT_MAX_TIMEOUT  */
end_comment

begin_define
define|#
directive|define
name|USEFUL_SERVER_TOP_TIMEOUT
value|120000
end_define

begin_comment
comment|/** Number of lost messages in a row that get a host blacklisted.  * With 16, a couple different queries have to time out and no working  * queries are happening */
end_comment

begin_define
define|#
directive|define
name|USEFUL_SERVER_MAX_LOST
value|16
end_define

begin_comment
comment|/** number of retries on outgoing queries */
end_comment

begin_define
define|#
directive|define
name|OUTBOUND_MSG_RETRY
value|5
end_define

begin_comment
comment|/** RTT band, within this amount from the best, servers are chosen randomly.  * Chosen so that the UNKNOWN_SERVER_NICENESS falls within the band of a   * fast server, this causes server exploration as a side benefit. msec. */
end_comment

begin_define
define|#
directive|define
name|RTT_BAND
value|400
end_define

begin_comment
comment|/** Start value for blacklisting a host, 2*USEFUL_SERVER_TOP_TIMEOUT in sec */
end_comment

begin_define
define|#
directive|define
name|INFRA_BACKOFF_INITIAL
value|240
end_define

begin_comment
comment|/**  * Global state for the iterator.   */
end_comment

begin_struct
struct|struct
name|iter_env
block|{
comment|/** A flag to indicate whether or not we have an IPv6 route */
name|int
name|supports_ipv6
decl_stmt|;
comment|/** A flag to indicate whether or not we have an IPv4 route */
name|int
name|supports_ipv4
decl_stmt|;
comment|/** A set of inetaddrs that should never be queried. */
name|struct
name|iter_donotq
modifier|*
name|donotq
decl_stmt|;
comment|/** private address space and private domains */
name|struct
name|iter_priv
modifier|*
name|priv
decl_stmt|;
comment|/** The maximum dependency depth that this resolver will pursue. */
name|int
name|max_dependency_depth
decl_stmt|;
comment|/** 	 * The target fetch policy for each dependency level. This is  	 * described as a simple number (per dependency level):  	 *	negative numbers (usually just -1) mean fetch-all,  	 *	0 means only fetch on demand, and  	 *	positive numbers mean to fetch at most that many targets. 	 * array of max_dependency_depth+1 size. 	 */
name|int
modifier|*
name|target_fetch_policy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * State of the iterator for a query.  */
end_comment

begin_enum
enum|enum
name|iter_state
block|{
comment|/** 	 * Externally generated queries start at this state. Query restarts are 	 * reset to this state. 	 */
name|INIT_REQUEST_STATE
init|=
literal|0
block|,
comment|/** 	 * Root priming events reactivate here, most other events pass  	 * through this naturally as the 2nd part of the INIT_REQUEST_STATE. 	 */
name|INIT_REQUEST_2_STATE
block|,
comment|/** 	 * Stub priming events reactivate here, most other events pass  	 * through this naturally as the 3rd part of the INIT_REQUEST_STATE. 	 */
name|INIT_REQUEST_3_STATE
block|,
comment|/** 	 * Each time a delegation point changes for a given query or a  	 * query times out and/or wakes up, this state is (re)visited.  	 * This state is reponsible for iterating through a list of  	 * nameserver targets. 	 */
name|QUERYTARGETS_STATE
block|,
comment|/** 	 * Responses to queries start at this state. This state handles  	 * the decision tree associated with handling responses. 	 */
name|QUERY_RESP_STATE
block|,
comment|/** Responses to priming queries finish at this state. */
name|PRIME_RESP_STATE
block|,
comment|/** Collecting query class information, for qclass=ANY, when 	 * it spawns off queries for every class, it returns here. */
name|COLLECT_CLASS_STATE
block|,
comment|/** Find NS record to resolve DS record from, walking to the right 	 * NS spot until we find it */
name|DSNS_FIND_STATE
block|,
comment|/** Responses that are to be returned upstream end at this state.  	 * As well as responses to target queries. */
name|FINISHED_STATE
block|}
enum|;
end_enum

begin_comment
comment|/**  * Per query state for the iterator module.  */
end_comment

begin_struct
struct|struct
name|iter_qstate
block|{
comment|/**  	 * State of the iterator module. 	 * This is the state that event is in or should sent to -- all  	 * requests should start with the INIT_REQUEST_STATE. All  	 * responses should start with QUERY_RESP_STATE. Subsequent  	 * processing of the event will change this state. 	 */
name|enum
name|iter_state
name|state
decl_stmt|;
comment|/**  	 * Final state for the iterator module. 	 * This is the state that responses should be routed to once the  	 * response is final. For externally initiated queries, this  	 * will be FINISHED_STATE, locally initiated queries will have  	 * different final states. 	 */
name|enum
name|iter_state
name|final_state
decl_stmt|;
comment|/**  	 * The depth of this query, this means the depth of recursion. 	 * This address is needed for another query, which is an address 	 * needed for another query, etc. Original client query has depth 0. 	 */
name|int
name|depth
decl_stmt|;
comment|/** 	 * The response 	 */
name|struct
name|dns_msg
modifier|*
name|response
decl_stmt|;
comment|/**  	 * This is a list of RRsets that must be prepended to the  	 * ANSWER section of a response before being sent upstream. 	 */
name|struct
name|iter_prep_list
modifier|*
name|an_prepend_list
decl_stmt|;
comment|/** Last element of the prepend list */
name|struct
name|iter_prep_list
modifier|*
name|an_prepend_last
decl_stmt|;
comment|/** 	 * This is the list of RRsets that must be prepended to the 	 * AUTHORITY section of the response before being sent upstream. 	 */
name|struct
name|iter_prep_list
modifier|*
name|ns_prepend_list
decl_stmt|;
comment|/** Last element of the authority prepend list */
name|struct
name|iter_prep_list
modifier|*
name|ns_prepend_last
decl_stmt|;
comment|/** query name used for chasing the results. Initially the same as 	 * the state qinfo, but after CNAMEs this will be different.  	 * The query info used to elicit the results needed. */
name|struct
name|query_info
name|qchase
decl_stmt|;
comment|/** query flags to use when chasing the answer (i.e. RD flag) */
name|uint16_t
name|chase_flags
decl_stmt|;
comment|/** true if we set RD bit because of last resort recursion lame query*/
name|int
name|chase_to_rd
decl_stmt|;
comment|/**  	 * This is the current delegation point for an in-progress query. This 	 * object retains state as to which delegation targets need to be 	 * (sub)queried for vs which ones have already been visited. 	 */
name|struct
name|delegpt
modifier|*
name|dp
decl_stmt|;
comment|/** state for 0x20 fallback when capsfail happens, 0 not a fallback */
name|int
name|caps_fallback
decl_stmt|;
comment|/** state for capsfail: current server number to try */
name|size_t
name|caps_server
decl_stmt|;
comment|/** state for capsfail: stored query for comparisons */
name|struct
name|reply_info
modifier|*
name|caps_reply
decl_stmt|;
comment|/** Current delegation message - returned for non-RD queries */
name|struct
name|dns_msg
modifier|*
name|deleg_msg
decl_stmt|;
comment|/** number of outstanding target sub queries */
name|int
name|num_target_queries
decl_stmt|;
comment|/** outstanding direct queries */
name|int
name|num_current_queries
decl_stmt|;
comment|/** the number of times this query has been restarted. */
name|int
name|query_restart_count
decl_stmt|;
comment|/** the number of times this query as followed a referral. */
name|int
name|referral_count
decl_stmt|;
comment|/** number of queries fired off */
name|int
name|sent_count
decl_stmt|;
comment|/** 	 * The query must store NS records from referrals as parentside RRs 	 * Enabled once it hits resolution problems, to throttle retries. 	 * If enabled it is the pointer to the old delegation point with 	 * the old retry counts for bad-nameserver-addresses. 	 */
name|struct
name|delegpt
modifier|*
name|store_parent_NS
decl_stmt|;
comment|/** 	 * The query is for parent-side glue(A or AAAA) for a nameserver. 	 * If the item is seen as glue in a referral, and pside_glue is NULL, 	 * then it is stored in pside_glue for later. 	 * If it was never seen, at the end, then a negative caching element  	 * must be created.   	 * The (data or negative) RR cache element then throttles retries. 	 */
name|int
name|query_for_pside_glue
decl_stmt|;
comment|/** the parent-side-glue element (NULL if none, its first match) */
name|struct
name|ub_packed_rrset_key
modifier|*
name|pside_glue
decl_stmt|;
comment|/** If nonNULL we are walking upwards from DS query to find NS */
name|uint8_t
modifier|*
name|dsns_point
decl_stmt|;
comment|/** length of the dname in dsns_point */
name|size_t
name|dsns_point_len
decl_stmt|;
comment|/**  	 * expected dnssec information for this iteration step.  	 * If dnssec rrsigs are expected and not given, the server is marked 	 * lame (dnssec-lame). 	 */
name|int
name|dnssec_expected
decl_stmt|;
comment|/** 	 * We are expecting dnssec information, but we also know the server 	 * is DNSSEC lame.  The response need not be marked dnssec-lame again. 	 */
name|int
name|dnssec_lame_query
decl_stmt|;
comment|/** 	 * This is flag that, if true, means that this event is  	 * waiting for a stub priming query.  	 */
name|int
name|wait_priming_stub
decl_stmt|;
comment|/** 	 * This is a flag that, if true, means that this query is 	 * for (re)fetching glue from a zone. Since the address should 	 * have been glue, query again to the servers that should have 	 * been returning it as glue. 	 * The delegation point must be set to the one that should *not* 	 * be used when creating the state. A higher one will be attempted. 	 */
name|int
name|refetch_glue
decl_stmt|;
comment|/** list of pending queries to authoritative servers. */
name|struct
name|outbound_list
name|outlist
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * List of prepend items  */
end_comment

begin_struct
struct|struct
name|iter_prep_list
block|{
comment|/** next in list */
name|struct
name|iter_prep_list
modifier|*
name|next
decl_stmt|;
comment|/** rrset */
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Get the iterator function block.  * @return: function block with function pointers to iterator methods.  */
end_comment

begin_function_decl
name|struct
name|module_func_block
modifier|*
name|iter_get_funcblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get iterator state as a string  * @param state: to convert  * @return constant string that is printable.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|iter_state_to_string
parameter_list|(
name|enum
name|iter_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if iterator state is a response state  * @param s: to inspect  * @return true if response state.  */
end_comment

begin_function_decl
name|int
name|iter_state_is_responsestate
parameter_list|(
name|enum
name|iter_state
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** iterator init */
end_comment

begin_function_decl
name|int
name|iter_init
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** iterator deinit */
end_comment

begin_function_decl
name|void
name|iter_deinit
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** iterator operate on a query */
end_comment

begin_function_decl
name|void
name|iter_operate
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|enum
name|module_ev
name|event
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|outbound_entry
modifier|*
name|outbound
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return priming query results to interestes super querystates.  *   * Sets the delegation point and delegation message (not nonRD queries).  * This is a callback from walk_supers.  *  * @param qstate: query state that finished.  * @param id: module id.  * @param super: the qstate to inform.  */
end_comment

begin_function_decl
name|void
name|iter_inform_super
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|module_qstate
modifier|*
name|super
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** iterator cleanup query state */
end_comment

begin_function_decl
name|void
name|iter_clear
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** iterator alloc size routine */
end_comment

begin_function_decl
name|size_t
name|iter_get_mem
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITERATOR_ITERATOR_H */
end_comment

end_unit

