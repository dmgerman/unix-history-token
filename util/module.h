begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/module.h - DNS handling module interface  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains the interface for DNS handling modules.  *  * The module interface uses the DNS modules as state machines.  The  * state machines are activated in sequence to operate on queries.  Once  * they are done, the reply is passed back.  In the usual setup the mesh  * is the caller of the state machines and once things are done sends replies  * and invokes result callbacks.  *  * The module provides a number of functions, listed in the module_func_block.  * The module is inited and destroyed and memory usage queries, for the  * module as a whole, for entire-module state (such as a cache).  And per-query  * functions are called, operate to move the state machine and cleanup of  * the per-query state.  *  * Most per-query state should simply be allocated in the query region.  * This is destroyed at the end of the query.  *  * The module environment contains services and information and caches  * shared by the modules and the rest of the system.  It also contains  * function pointers for module-specific tasks (like sending queries).  *  * *** Example module calls for a normal query  *  * In this example, the query does not need recursion, all the other data  * can be found in the cache.  This makes the example shorter.  *  * At the start of the program the iterator module is initialised.  * The iterator module sets up its global state, such as donotquery lists  * and private address trees.  *  * A query comes in, and a mesh entry is created for it.  The mesh  * starts the resolution process.  The validator module is the first  * in the list of modules, and it is started on this new query.  The  * operate() function is called.  The validator decides it needs not do  * anything yet until there is a result and returns wait_module, that  * causes the next module in the list to be started.  *  * The next module is the iterator.  It is started on the passed query and  * decides to perform a lookup.  For this simple example, the delegation  * point information is available, and all the iterator wants to do is  * send a UDP query.  The iterator uses env.send_query() to send the  * query.  Then the iterator suspends (returns from the operate call).  *  * When the UDP reply comes back (and on errors and timeouts), the  * operate function is called for the query, on the iterator module,  * with the event that there is a reply.  The iterator decides that this  * is enough, the work is done.  It returns the value finished from the  * operate call, which causes the previous module to be started.  *  * The previous module, the validator module, is started with the event  * that the iterator module is done.  The validator decides to validate  * the query.  Once it is done (which could take recursive lookups, but  * in this example no recursive lookups are needed), it returns from the  * operate function with finished.  *  * There is no previous module from the validator module, and the mesh  * takes this to mean that the query is finally done.  The mesh invokes  * callbacks and sends packets to queriers.  *  * If other modules had been waiting (recursively) on the answer to this  * query, then the mesh will tell them about it.  It calls the inform_super  * routine on all the waiting modules, and once that is done it calls all of  * them with the operate() call.  During inform_super the query that is done  * still exists and information can be copied from it (but the module should  * not really re-entry codepoints and services).  During the operate call  * the modules can use stored state to continue operation with the results.  * (network buffers are used to contain the answer packet during the  * inform_super phase, but after that the network buffers will be cleared  * of their contents so that other tasks can be performed).  *  * *** Example module calls for recursion  *  * A module is called in operate, and it decides that it wants to perform  * recursion.  That is, it wants the full state-machine-list to operate on  * a different query.  It calls env.attach_sub() to create a new query state.  * The routine returns the newly created state, and potentially the module  * can edit the module-states for the newly created query (i.e. pass along  * some information, like delegation points).  The module then suspends,  * returns from the operate routine.  *  * The mesh meanwhile will have the newly created query (or queries) on  * a waiting list, and will call operate() on this query (or queries).  * It starts again at the start of the module list for them.  The query  * (or queries) continue to operate their state machines, until they are  * done.  When they are done the mesh calls inform_super on the module that  * wanted the recursion.  After that the mesh calls operate() on the module  * that wanted to do the recursion, and during this phase the module could,  * for example, decide to create more recursions.  *  * If the module decides it no longer wants the recursive information  * it can call detach_subs.  Those queries will still run to completion,  * potentially filling the cache with information.  Inform_super is not  * called any more.  *  * The iterator module will fetch items from the cache, so a recursion  * attempt may complete very quickly if the item is in cache.  The calling  * module has to wait for completion or eventual timeout.  A recursive query  * that times out returns a servfail rcode (servfail is also returned for  * other errors during the lookup).  *  * Results are passed in the qstate, the rcode member is used to pass  * errors without requiring memory allocation, so that the code can continue  * in out-of-memory conditions.  If the rcode member is 0 (NOERROR) then  * the dns_msg entry contains a filled out message.  This message may  * also contain an rcode that is nonzero, but in this case additional  * information (query, additional) can be passed along.  *  * The rcode and dns_msg are used to pass the result from the the rightmost  * module towards the leftmost modules and then towards the user.  *  * If you want to avoid recursion-cycles where queries need other queries  * that need the first one, use detect_cycle() to see if that will happen.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_MODULE_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_MODULE_H
end_define

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_include
include|#
directive|include
file|"util/data/msgreply.h"
end_include

begin_include
include|#
directive|include
file|"util/data/msgparse.h"
end_include

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|alloc_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rrset_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|key_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|slabhash
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|edns_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|worker
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_qstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_randstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mesh_area
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mesh_state
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|val_anchors
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|val_neg_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iter_forwards
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iter_hints
struct_decl|;
end_struct_decl

begin_comment
comment|/** Maximum number of modules in operation */
end_comment

begin_define
define|#
directive|define
name|MAX_MODULE
value|5
end_define

begin_comment
comment|/**  * Module environment.  * Services and data provided to the module.  */
end_comment

begin_struct
struct|struct
name|module_env
block|{
comment|/* --- data --- */
comment|/** config file with config options */
name|struct
name|config_file
modifier|*
name|cfg
decl_stmt|;
comment|/** shared message cache */
name|struct
name|slabhash
modifier|*
name|msg_cache
decl_stmt|;
comment|/** shared rrset cache */
name|struct
name|rrset_cache
modifier|*
name|rrset_cache
decl_stmt|;
comment|/** shared infrastructure cache (edns, lameness) */
name|struct
name|infra_cache
modifier|*
name|infra_cache
decl_stmt|;
comment|/** shared key cache */
name|struct
name|key_cache
modifier|*
name|key_cache
decl_stmt|;
comment|/* --- services --- */
comment|/**  	 * Send serviced DNS query to server. UDP/TCP and EDNS is handled. 	 * operate() should return with wait_reply. Later on a callback  	 * will cause operate() to be called with event timeout or reply. 	 * The time until a timeout is calculated from roundtrip timing, 	 * several UDP retries are attempted. 	 * @param qname: query name. (host order) 	 * @param qnamelen: length in bytes of qname, including trailing 0. 	 * @param qtype: query type. (host order) 	 * @param qclass: query class. (host order) 	 * @param flags: host order flags word, with opcode and CD bit. 	 * @param dnssec: if set, EDNS record will have bits set. 	 *	If EDNS_DO bit is set, DO bit is set in EDNS records. 	 *	If BIT_CD is set, CD bit is set in queries with EDNS records. 	 * @param want_dnssec: if set, the validator wants DNSSEC.  Without 	 * 	EDNS, the answer is likely to be useless for this domain. 	 * @param addr: where to. 	 * @param addrlen: length of addr. 	 * @param zone: delegation point name. 	 * @param zonelen: length of zone name. 	 * @param q: wich query state to reactivate upon return. 	 * @return: false on failure (memory or socket related). no query was 	 *	sent. Or returns an outbound entry with qsent and qstate set. 	 *	This outbound_entry will be used on later module invocations 	 *	that involve this query (timeout, error or reply). 	 */
name|struct
name|outbound_entry
modifier|*
function_decl|(
modifier|*
name|send_query
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|size_t
name|qnamelen
parameter_list|,
name|uint16_t
name|qtype
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|uint16_t
name|flags
parameter_list|,
name|int
name|dnssec
parameter_list|,
name|int
name|want_dnssec
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|uint8_t
modifier|*
name|zone
parameter_list|,
name|size_t
name|zonelen
parameter_list|,
name|struct
name|module_qstate
modifier|*
name|q
parameter_list|)
function_decl|;
comment|/** 	 * Detach-subqueries. 	 * Remove all sub-query references from this query state. 	 * Keeps super-references of those sub-queries correct. 	 * Updates stat items in mesh_area structure. 	 * @param qstate: used to find mesh state. 	 */
name|void
function_decl|(
modifier|*
name|detach_subs
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|)
function_decl|;
comment|/** 	 * Attach subquery. 	 * Creates it if it does not exist already. 	 * Keeps sub and super references correct. 	 * Updates stat items in mesh_area structure. 	 * Pass if it is priming query or not. 	 * return: 	 * o if error (malloc) happened. 	 * o need to initialise the new state (module init; it is a new state). 	 *   so that the next run of the query with this module is successful. 	 * o no init needed, attachment successful. 	 *  	 * @param qstate: the state to find mesh state, and that wants to  	 * 	receive the results from the new subquery. 	 * @param qinfo: what to query for (copied). 	 * @param qflags: what flags to use (RD, CD flag or not). 	 * @param prime: if it is a (stub) priming query. 	 * @param newq: If the new subquery needs initialisation, it is  	 * 	returned, otherwise NULL is returned. 	 * @return: false on error, true if success (and init may be needed). 	 */
name|int
function_decl|(
modifier|*
name|attach_sub
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint16_t
name|qflags
parameter_list|,
name|int
name|prime
parameter_list|,
name|struct
name|module_qstate
modifier|*
modifier|*
name|newq
parameter_list|)
function_decl|;
comment|/** 	 * Kill newly attached sub. If attach_sub returns newq for  	 * initialisation, but that fails, then this routine will cleanup and 	 * delete the fresly created sub. 	 * @param newq: the new subquery that is no longer needed. 	 * 	It is removed. 	 */
name|void
function_decl|(
modifier|*
name|kill_sub
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|newq
parameter_list|)
function_decl|;
comment|/** 	 * Detect if adding a dependency for qstate on name,type,class will 	 * create a dependency cycle. 	 * @param qstate: given mesh querystate. 	 * @param qinfo: query info for dependency.  	 * @param flags: query flags of dependency, RD/CD flags. 	 * @param prime: if dependency is a priming query or not. 	 * @return true if the name,type,class exists and the given  	 * 	qstate mesh exists as a dependency of that name. Thus  	 * 	if qstate becomes dependent on name,type,class then a  	 * 	cycle is created. 	 */
name|int
function_decl|(
modifier|*
name|detect_cycle
function_decl|)
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint16_t
name|flags
parameter_list|,
name|int
name|prime
parameter_list|)
function_decl|;
comment|/** region for temporary usage. May be cleared after operate() call. */
name|struct
name|regional
modifier|*
name|scratch
decl_stmt|;
comment|/** buffer for temporary usage. May be cleared after operate() call. */
name|struct
name|sldns_buffer
modifier|*
name|scratch_buffer
decl_stmt|;
comment|/** internal data for daemon - worker thread. */
name|struct
name|worker
modifier|*
name|worker
decl_stmt|;
comment|/** mesh area with query state dependencies */
name|struct
name|mesh_area
modifier|*
name|mesh
decl_stmt|;
comment|/** allocation service */
name|struct
name|alloc_cache
modifier|*
name|alloc
decl_stmt|;
comment|/** random table to generate random numbers */
name|struct
name|ub_randstate
modifier|*
name|rnd
decl_stmt|;
comment|/** time in seconds, converted to integer */
name|time_t
modifier|*
name|now
decl_stmt|;
comment|/** time in microseconds. Relatively recent. */
name|struct
name|timeval
modifier|*
name|now_tv
decl_stmt|;
comment|/** is validation required for messages, controls client-facing 	 * validation status (AD bits) and servfails */
name|int
name|need_to_validate
decl_stmt|;
comment|/** trusted key storage; these are the configured keys, if not NULL, 	 * otherwise configured by validator. These are the trust anchors, 	 * and are not primed and ready for validation, but on the bright 	 * side, they are read only memory, thus no locks and fast. */
name|struct
name|val_anchors
modifier|*
name|anchors
decl_stmt|;
comment|/** negative cache, configured by the validator. if not NULL, 	 * contains NSEC record lookup trees. */
name|struct
name|val_neg_cache
modifier|*
name|neg_cache
decl_stmt|;
comment|/** the 5011-probe timer (if any) */
name|struct
name|comm_timer
modifier|*
name|probe_timer
decl_stmt|;
comment|/** Mapping of forwarding zones to targets. 	 * iterator forwarder information. per-thread, created by worker */
name|struct
name|iter_forwards
modifier|*
name|fwds
decl_stmt|;
comment|/**  	 * iterator forwarder information. per-thread, created by worker. 	 * The hints -- these aren't stored in the cache because they don't  	 * expire. The hints are always used to "prime" the cache. Note  	 * that both root hints and stub zone "hints" are stored in this  	 * data structure.  	 */
name|struct
name|iter_hints
modifier|*
name|hints
decl_stmt|;
comment|/** module specific data. indexed by module id. */
name|void
modifier|*
name|modinfo
index|[
name|MAX_MODULE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * External visible states of the module state machine   * Modules may also have an internal state.  * Modules are supposed to run to completion or until blocked.  */
end_comment

begin_enum
enum|enum
name|module_ext_state
block|{
comment|/** initial state - new query */
name|module_state_initial
init|=
literal|0
block|,
comment|/** waiting for reply to outgoing network query */
name|module_wait_reply
block|,
comment|/** module is waiting for another module */
name|module_wait_module
block|,
comment|/** module is waiting for another module; that other is restarted */
name|module_restart_next
block|,
comment|/** module is waiting for sub-query */
name|module_wait_subquery
block|,
comment|/** module could not finish the query */
name|module_error
block|,
comment|/** module is finished with query */
name|module_finished
block|}
enum|;
end_enum

begin_comment
comment|/**  * Events that happen to modules, that start or wakeup modules.  */
end_comment

begin_enum
enum|enum
name|module_ev
block|{
comment|/** new query */
name|module_event_new
init|=
literal|0
block|,
comment|/** query passed by other module */
name|module_event_pass
block|,
comment|/** reply inbound from server */
name|module_event_reply
block|,
comment|/** no reply, timeout or other error */
name|module_event_noreply
block|,
comment|/** reply is there, but capitalisation check failed */
name|module_event_capsfail
block|,
comment|/** next module is done, and its reply is awaiting you */
name|module_event_moddone
block|,
comment|/** error */
name|module_event_error
block|}
enum|;
end_enum

begin_comment
comment|/**   * Linked list of sockaddrs   * May be allocated such that only 'len' bytes of addr exist for the structure.  */
end_comment

begin_struct
struct|struct
name|sock_list
block|{
comment|/** next in list */
name|struct
name|sock_list
modifier|*
name|next
decl_stmt|;
comment|/** length of addr */
name|socklen_t
name|len
decl_stmt|;
comment|/** sockaddr */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Module state, per query.  */
end_comment

begin_struct
struct|struct
name|module_qstate
block|{
comment|/** which query is being answered: name, type, class */
name|struct
name|query_info
name|qinfo
decl_stmt|;
comment|/** flags uint16 from query */
name|uint16_t
name|query_flags
decl_stmt|;
comment|/** if this is a (stub or root) priming query (with hints) */
name|int
name|is_priming
decl_stmt|;
comment|/** comm_reply contains server replies */
name|struct
name|comm_reply
modifier|*
name|reply
decl_stmt|;
comment|/** the reply message, with message for client and calling module */
name|struct
name|dns_msg
modifier|*
name|return_msg
decl_stmt|;
comment|/** the rcode, in case of error, instead of a reply message */
name|int
name|return_rcode
decl_stmt|;
comment|/** origin of the reply (can be NULL from cache, list for cnames) */
name|struct
name|sock_list
modifier|*
name|reply_origin
decl_stmt|;
comment|/** IP blacklist for queries */
name|struct
name|sock_list
modifier|*
name|blacklist
decl_stmt|;
comment|/** region for this query. Cleared when query process finishes. */
name|struct
name|regional
modifier|*
name|region
decl_stmt|;
comment|/** failure reason information if val-log-level is high */
name|struct
name|config_strlist
modifier|*
name|errinf
decl_stmt|;
comment|/** which module is executing */
name|int
name|curmod
decl_stmt|;
comment|/** module states */
name|enum
name|module_ext_state
name|ext_state
index|[
name|MAX_MODULE
index|]
decl_stmt|;
comment|/** module specific data for query. indexed by module id. */
name|void
modifier|*
name|minfo
index|[
name|MAX_MODULE
index|]
decl_stmt|;
comment|/** environment for this query */
name|struct
name|module_env
modifier|*
name|env
decl_stmt|;
comment|/** mesh related information for this query */
name|struct
name|mesh_state
modifier|*
name|mesh_info
decl_stmt|;
comment|/** how many seconds before expiry is this prefetched (0 if not) */
name|time_t
name|prefetch_leeway
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Module functionality block  */
end_comment

begin_struct
struct|struct
name|module_func_block
block|{
comment|/** text string name of module */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**  	 * init the module. Called once for the global state. 	 * This is the place to apply settings from the config file. 	 * @param env: module environment. 	 * @param id: module id number. 	 * return: 0 on error 	 */
name|int
function_decl|(
modifier|*
name|init
function_decl|)
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
comment|/** 	 * de-init, delete, the module. Called once for the global state. 	 * @param env: module environment. 	 * @param id: module id number. 	 */
name|void
function_decl|(
modifier|*
name|deinit
function_decl|)
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
comment|/** 	 * accept a new query, or work further on existing query. 	 * Changes the qstate->ext_state to be correct on exit. 	 * @param ev: event that causes the module state machine to  	 *	(re-)activate. 	 * @param qstate: the query state.  	 *	Note that this method is not allowed to change the 	 *	query state 'identity', that is query info, qflags, 	 *	and priming status. 	 *	Attach a subquery to get results to a different query. 	 * @param id: module id number that operate() is called on.  	 * @param outbound: if not NULL this event is due to the reply/timeout 	 *	or error on this outbound query. 	 * @return: if at exit the ext_state is: 	 *	o wait_module: next module is started. (with pass event). 	 *	o error or finished: previous module is resumed. 	 *	o otherwise it waits until that event happens (assumes 	 *	  the service routine to make subrequest or send message 	 *	  have been called. 	 */
name|void
function_decl|(
modifier|*
name|operate
function_decl|)
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
comment|/** 	 * inform super querystate about the results from this subquerystate. 	 * Is called when the querystate is finished.  The method invoked is 	 * the one from the current module active in the super querystate. 	 * @param qstate: the query state that is finished. 	 *	Examine return_rcode and return_reply in the qstate. 	 * @param id: module id for this module. 	 *	This coincides with the current module for the super qstate. 	 * @param super: the super querystate that needs to be informed. 	 */
name|void
function_decl|(
modifier|*
name|inform_super
function_decl|)
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
comment|/** 	 * clear module specific data 	 */
name|void
function_decl|(
modifier|*
name|clear
function_decl|)
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
comment|/** 	 * How much memory is the module specific data using.  	 * @param env: module environment. 	 * @param id: the module id. 	 * @return the number of bytes that are alloced. 	 */
name|size_t
function_decl|(
modifier|*
name|get_mem
function_decl|)
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
block|}
struct|;
end_struct

begin_comment
comment|/**   * Debug utility: module external qstate to string   * @param s: the state value.  * @return descriptive string.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|strextstate
parameter_list|(
name|enum
name|module_ext_state
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Debug utility: module event to string   * @param e: the module event value.  * @return descriptive string.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|strmodulevent
parameter_list|(
name|enum
name|module_ev
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_MODULE_H */
end_comment

end_unit

