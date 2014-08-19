begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * services/mesh.h - deal with mesh of query states and handle events for that.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to assist in dealing with a mesh of  * query states. This mesh is supposed to be thread-specific.  * It consists of query states (per qname, qtype, qclass) and connections  * between query states and the super and subquery states, and replies to  * send back to clients.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVICES_MESH_H
end_ifndef

begin_define
define|#
directive|define
name|SERVICES_MESH_H
end_define

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_include
include|#
directive|include
file|"util/netevent.h"
end_include

begin_include
include|#
directive|include
file|"util/data/msgparse.h"
end_include

begin_include
include|#
directive|include
file|"util/module.h"
end_include

begin_include
include|#
directive|include
file|"services/modstack.h"
end_include

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mesh_state
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mesh_reply
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mesh_cb
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
name|outbound_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timehist
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Maximum number of mesh state activations. Any more is likely an  * infinite loop in the module. It is then terminated.  */
end_comment

begin_define
define|#
directive|define
name|MESH_MAX_ACTIVATION
value|3000
end_define

begin_comment
comment|/**  * Max number of references-to-references-to-references.. search size.  * Any more is treated like 'too large', and the creation of a new  * dependency is failed (so that no loops can be created).  */
end_comment

begin_define
define|#
directive|define
name|MESH_MAX_SUBSUB
value|1024
end_define

begin_comment
comment|/**   * Mesh of query states  */
end_comment

begin_struct
struct|struct
name|mesh_area
block|{
comment|/** active module stack */
name|struct
name|module_stack
name|mods
decl_stmt|;
comment|/** environment for new states */
name|struct
name|module_env
modifier|*
name|env
decl_stmt|;
comment|/** set of runnable queries (mesh_state.run_node) */
name|rbtree_t
name|run
decl_stmt|;
comment|/** rbtree of all current queries (mesh_state.node)*/
name|rbtree_t
name|all
decl_stmt|;
comment|/** count of the total number of mesh_reply entries */
name|size_t
name|num_reply_addrs
decl_stmt|;
comment|/** count of the number of mesh_states that have mesh_replies  	 * Because a state can send results to multiple reply addresses, 	 * this number must be equal or lower than num_reply_addrs. */
name|size_t
name|num_reply_states
decl_stmt|;
comment|/** number of mesh_states that have no mesh_replies, and also 	 * an empty set of super-states, thus are 'toplevel' or detached 	 * internal opportunistic queries */
name|size_t
name|num_detached_states
decl_stmt|;
comment|/** number of reply states in the forever list */
name|size_t
name|num_forever_states
decl_stmt|;
comment|/** max total number of reply states to have */
name|size_t
name|max_reply_states
decl_stmt|;
comment|/** max forever number of reply states to have */
name|size_t
name|max_forever_states
decl_stmt|;
comment|/** stats, cumulative number of reply states jostled out */
name|size_t
name|stats_jostled
decl_stmt|;
comment|/** stats, cumulative number of incoming client msgs dropped */
name|size_t
name|stats_dropped
decl_stmt|;
comment|/** number of replies sent */
name|size_t
name|replies_sent
decl_stmt|;
comment|/** sum of waiting times for the replies */
name|struct
name|timeval
name|replies_sum_wait
decl_stmt|;
comment|/** histogram of time values */
name|struct
name|timehist
modifier|*
name|histogram
decl_stmt|;
comment|/** (extended stats) secure replies */
name|size_t
name|ans_secure
decl_stmt|;
comment|/** (extended stats) bogus replies */
name|size_t
name|ans_bogus
decl_stmt|;
comment|/** (extended stats) rcodes in replies */
name|size_t
name|ans_rcode
index|[
literal|16
index|]
decl_stmt|;
comment|/** (extended stats) rcode nodata in replies */
name|size_t
name|ans_nodata
decl_stmt|;
comment|/** backup of query if other operations recurse and need the 	 * network buffers */
name|struct
name|sldns_buffer
modifier|*
name|qbuf_bak
decl_stmt|;
comment|/** double linked list of the run-to-completion query states. 	 * These are query states with a reply */
name|struct
name|mesh_state
modifier|*
name|forever_first
decl_stmt|;
comment|/** last entry in run forever list */
name|struct
name|mesh_state
modifier|*
name|forever_last
decl_stmt|;
comment|/** double linked list of the query states that can be jostled out 	 * by new queries if too old.  These are query states with a reply */
name|struct
name|mesh_state
modifier|*
name|jostle_first
decl_stmt|;
comment|/** last entry in jostle list - this is the entry that is newest */
name|struct
name|mesh_state
modifier|*
name|jostle_last
decl_stmt|;
comment|/** timeout for jostling. if age is lower, it does not get jostled. */
name|struct
name|timeval
name|jostle_max
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * A mesh query state  * Unique per qname, qtype, qclass (from the qstate).  * And RD / CD flag; in case a client turns it off.  * And priming queries are different from ordinary queries (because of hints).  *  * The entire structure is allocated in a region, this region is the qstate  * region. All parts (rbtree nodes etc) are also allocated in the region.  */
end_comment

begin_struct
struct|struct
name|mesh_state
block|{
comment|/** node in mesh_area all tree, key is this struct. Must be first. */
name|rbnode_t
name|node
decl_stmt|;
comment|/** node in mesh_area runnable tree, key is this struct */
name|rbnode_t
name|run_node
decl_stmt|;
comment|/** the query state. Note that the qinfo and query_flags  	 * may not change. */
name|struct
name|module_qstate
name|s
decl_stmt|;
comment|/** the list of replies to clients for the results */
name|struct
name|mesh_reply
modifier|*
name|reply_list
decl_stmt|;
comment|/** the list of callbacks for the results */
name|struct
name|mesh_cb
modifier|*
name|cb_list
decl_stmt|;
comment|/** set of superstates (that want this state's result)  	 * contains struct mesh_state_ref* */
name|rbtree_t
name|super_set
decl_stmt|;
comment|/** set of substates (that this state needs to continue) 	 * contains struct mesh_state_ref* */
name|rbtree_t
name|sub_set
decl_stmt|;
comment|/** number of activations for the mesh state */
name|size_t
name|num_activated
decl_stmt|;
comment|/** previous in linked list for reply states */
name|struct
name|mesh_state
modifier|*
name|prev
decl_stmt|;
comment|/** next in linked list for reply states */
name|struct
name|mesh_state
modifier|*
name|next
decl_stmt|;
comment|/** if this state is in the forever list, jostle list, or neither */
enum|enum
name|mesh_list_select
block|{
name|mesh_no_list
block|,
name|mesh_forever_list
block|,
name|mesh_jostle_list
block|}
name|list_select
enum|;
comment|/** true if replies have been sent out (at end for alignment) */
name|uint8_t
name|replies_sent
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Rbtree reference to a mesh_state.  * Used in super_set and sub_set.   */
end_comment

begin_struct
struct|struct
name|mesh_state_ref
block|{
comment|/** node in rbtree for set, key is this structure */
name|rbnode_t
name|node
decl_stmt|;
comment|/** the mesh state */
name|struct
name|mesh_state
modifier|*
name|s
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Reply to a client  */
end_comment

begin_struct
struct|struct
name|mesh_reply
block|{
comment|/** next in reply list */
name|struct
name|mesh_reply
modifier|*
name|next
decl_stmt|;
comment|/** the query reply destination, packet buffer and where to send. */
name|struct
name|comm_reply
name|query_reply
decl_stmt|;
comment|/** edns data from query */
name|struct
name|edns_data
name|edns
decl_stmt|;
comment|/** the time when request was entered */
name|struct
name|timeval
name|start_time
decl_stmt|;
comment|/** id of query, in network byteorder. */
name|uint16_t
name|qid
decl_stmt|;
comment|/** flags of query, for reply flags */
name|uint16_t
name|qflags
decl_stmt|;
comment|/** qname from this query. len same as mesh qinfo. */
name|uint8_t
modifier|*
name|qname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Mesh result callback func.  * called as func(cb_arg, rcode, buffer_with_reply, security, why_bogus);  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|mesh_cb_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
parameter_list|,
name|enum
name|sec_status
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * Callback to result routine  */
end_comment

begin_struct
struct|struct
name|mesh_cb
block|{
comment|/** next in list */
name|struct
name|mesh_cb
modifier|*
name|next
decl_stmt|;
comment|/** edns data from query */
name|struct
name|edns_data
name|edns
decl_stmt|;
comment|/** id of query, in network byteorder. */
name|uint16_t
name|qid
decl_stmt|;
comment|/** flags of query, for reply flags */
name|uint16_t
name|qflags
decl_stmt|;
comment|/** buffer for reply */
name|struct
name|sldns_buffer
modifier|*
name|buf
decl_stmt|;
comment|/** callback routine for results. if rcode != 0 buf has message. 	 * called as cb(cb_arg, rcode, buf, sec_state); 	 */
name|mesh_cb_func_t
name|cb
decl_stmt|;
comment|/** user arg for callback */
name|void
modifier|*
name|cb_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ------------------- Functions for worker -------------------- */
end_comment

begin_comment
comment|/**  * Allocate mesh, to empty.  * @param stack: module stack to activate, copied (as readonly reference).  * @param env: environment for new queries.  * @return mesh: the new mesh or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|mesh_area
modifier|*
name|mesh_create
parameter_list|(
name|struct
name|module_stack
modifier|*
name|stack
parameter_list|,
name|struct
name|module_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete mesh, and all query states and replies in it.  * @param mesh: the mesh to delete.  */
end_comment

begin_function_decl
name|void
name|mesh_delete
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * New query incoming from clients. Create new query state if needed, and  * add mesh_reply to it. Returns error to client on malloc failures.  * Will run the mesh area queries to process if a new query state is created.  *  * @param mesh: the mesh.  * @param qinfo: query from client.  * @param qflags: flags from client query.  * @param edns: edns data from client query.  * @param rep: where to reply to.  * @param qid: query id to reply with.  */
end_comment

begin_function_decl
name|void
name|mesh_new_client
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint16_t
name|qflags
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|rep
parameter_list|,
name|uint16_t
name|qid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * New query with callback. Create new query state if needed, and  * add mesh_cb to it.   * Will run the mesh area queries to process if a new query state is created.  *  * @param mesh: the mesh.  * @param qinfo: query from client.  * @param qflags: flags from client query.  * @param edns: edns data from client query.  * @param buf: buffer for reply contents.  * @param qid: query id to reply with.  * @param cb: callback function.  * @param cb_arg: callback user arg.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|mesh_new_callback
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint16_t
name|qflags
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|uint16_t
name|qid
parameter_list|,
name|mesh_cb_func_t
name|cb
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * New prefetch message. Create new query state if needed.  * Will run the mesh area queries to process if a new query state is created.  *  * @param mesh: the mesh.  * @param qinfo: query from client.  * @param qflags: flags from client query.  * @param leeway: TTL leeway what to expire earlier for this update.  */
end_comment

begin_function_decl
name|void
name|mesh_new_prefetch
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|uint16_t
name|qflags
parameter_list|,
name|time_t
name|leeway
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Handle new event from the wire. A serviced query has returned.  * The query state will be made runnable, and the mesh_area will process  * query states until processing is complete.  *  * @param mesh: the query mesh.  * @param e: outbound entry, with query state to run and reply pointer.  * @param reply: the comm point reply info.  * @param what: NETEVENT_* error code (if not 0, what is wrong, TIMEOUT).  */
end_comment

begin_function_decl
name|void
name|mesh_report_reply
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|,
name|struct
name|outbound_entry
modifier|*
name|e
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|reply
parameter_list|,
name|int
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------- Functions for module environment --------------- */
end_comment

begin_comment
comment|/**  * Detach-subqueries.  * Remove all sub-query references from this query state.  * Keeps super-references of those sub-queries correct.  * Updates stat items in mesh_area structure.  * @param qstate: used to find mesh state.  */
end_comment

begin_function_decl
name|void
name|mesh_detach_subs
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Attach subquery.  * Creates it if it does not exist already.  * Keeps sub and super references correct.  * Performs a cycle detection - for double check - and fails if there is one.  * Also fails if the sub-sub-references become too large.  * Updates stat items in mesh_area structure.  * Pass if it is priming query or not.  * return:  * 	o if error (malloc) happened.  * 	o need to initialise the new state (module init; it is a new state).  * 	  so that the next run of the query with this module is successful.  * 	o no init needed, attachment successful.  *  * @param qstate: the state to find mesh state, and that wants to receive  * 	the results from the new subquery.  * @param qinfo: what to query for (copied).  * @param qflags: what flags to use (RD / CD flag or not).  * @param prime: if it is a (stub) priming query.  * @param newq: If the new subquery needs initialisation, it is returned,  * 	otherwise NULL is returned.  * @return: false on error, true if success (and init may be needed).  */
end_comment

begin_function_decl
name|int
name|mesh_attach_sub
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
end_function_decl

begin_comment
comment|/**  * Query state is done, send messages to reply entries.  * Encode messages using reply entry values and the querystate (with original  * qinfo), using given reply_info.  * Pass errcode != 0 if an error reply is needed.  * If no reply entries, nothing is done.  * Must be called before a module can module_finished or return module_error.  * The module must handle the super query states itself as well.  *  * @param mstate: mesh state that is done. return_rcode and return_msg  * 	are used for replies.  * 	return_rcode: if not 0 (NOERROR) an error is sent back (and   * 		return_msg is ignored).  * 	return_msg: reply to encode and send back to clients.  */
end_comment

begin_function_decl
name|void
name|mesh_query_done
parameter_list|(
name|struct
name|mesh_state
modifier|*
name|mstate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Call inform_super for the super query states that are interested in the   * results from this query state. These can then be changed for error   * or results.  * Called when a module is module_finished or returns module_error.  * The super query states become runnable with event module_event_pass,  * it calls the current module for the super with the inform_super event.  *  * @param mesh: mesh area to add newly runnable modules to.  * @param mstate: the state that has results, used to find mesh state.  */
end_comment

begin_function_decl
name|void
name|mesh_walk_supers
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|,
name|struct
name|mesh_state
modifier|*
name|mstate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete mesh state, cleanup and also rbtrees and so on.  * Will detach from all super/subnodes.  * @param qstate: to remove.  */
end_comment

begin_function_decl
name|void
name|mesh_state_delete
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------- Functions for mesh -------------------- */
end_comment

begin_comment
comment|/**  * Create and initialize a new mesh state and its query state  * Does not put the mesh state into rbtrees and so on.  * @param env: module environment to set.  * @param qinfo: query info that the mesh is for.  * @param qflags: flags for query (RD / CD flag).  * @param prime: if true, it is a priming query, set is_priming on mesh state.  * @return: new mesh state or NULL on allocation error.  */
end_comment

begin_function_decl
name|struct
name|mesh_state
modifier|*
name|mesh_state_create
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
name|uint16_t
name|qflags
parameter_list|,
name|int
name|prime
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Cleanup a mesh state and its query state. Does not do rbtree or   * reference cleanup.  * @param mstate: mesh state to cleanup. Its pointer may no longer be used  * 	afterwards. Cleanup rbtrees before calling this function.  */
end_comment

begin_function_decl
name|void
name|mesh_state_cleanup
parameter_list|(
name|struct
name|mesh_state
modifier|*
name|mstate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete all mesh states from the mesh.  * @param mesh: the mesh area to clear  */
end_comment

begin_function_decl
name|void
name|mesh_delete_all
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find a mesh state in the mesh area. Pass relevant flags.  *  * @param mesh: the mesh area to look in.  * @param qinfo: what query  * @param qflags: if RD / CD bit is set or not.  * @param prime: if it is a priming query.  * @return: mesh state or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|mesh_state
modifier|*
name|mesh_area_find
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Setup attachment super/sub relation between super and sub mesh state.  * The relation must not be present when calling the function.  * Does not update stat items in mesh_area.  * @param super: super state.  * @param sub: sub state.  * @return: 0 on alloc error.  */
end_comment

begin_function_decl
name|int
name|mesh_state_attachment
parameter_list|(
name|struct
name|mesh_state
modifier|*
name|super
parameter_list|,
name|struct
name|mesh_state
modifier|*
name|sub
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create new reply structure and attach it to a mesh state.  * Does not update stat items in mesh area.  * @param s: the mesh state.  * @param edns: edns data for reply (bufsize).  * @param rep: comm point reply info.  * @param qid: ID of reply.  * @param qflags: original query flags.  * @param qname: original query name.  * @return: 0 on alloc error.  */
end_comment

begin_function_decl
name|int
name|mesh_state_add_reply
parameter_list|(
name|struct
name|mesh_state
modifier|*
name|s
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|rep
parameter_list|,
name|uint16_t
name|qid
parameter_list|,
name|uint16_t
name|qflags
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create new callback structure and attach it to a mesh state.  * Does not update stat items in mesh area.  * @param s: the mesh state.  * @param edns: edns data for reply (bufsize).  * @param buf: buffer for reply  * @param cb: callback to call with results.  * @param cb_arg: callback user arg.  * @param qid: ID of reply.  * @param qflags: original query flags.  * @return: 0 on alloc error.  */
end_comment

begin_function_decl
name|int
name|mesh_state_add_cb
parameter_list|(
name|struct
name|mesh_state
modifier|*
name|s
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|mesh_cb_func_t
name|cb
parameter_list|,
name|void
modifier|*
name|cb_arg
parameter_list|,
name|uint16_t
name|qid
parameter_list|,
name|uint16_t
name|qflags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Run the mesh. Run all runnable mesh states. Which can create new  * runnable mesh states. Until completion. Automatically called by  * mesh_report_reply and mesh_new_client as needed.  * @param mesh: mesh area.  * @param mstate: first mesh state to run.  * @param ev: event the mstate. Others get event_pass.  * @param e: if a reply, its outbound entry.  */
end_comment

begin_function_decl
name|void
name|mesh_run
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|,
name|struct
name|mesh_state
modifier|*
name|mstate
parameter_list|,
name|enum
name|module_ev
name|ev
parameter_list|,
name|struct
name|outbound_entry
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print some stats about the mesh to the log.  * @param mesh: the mesh to print it for.  * @param str: descriptive string to go with it.  */
end_comment

begin_function_decl
name|void
name|mesh_stats
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Clear the stats that the mesh keeps (number of queries serviced)  * @param mesh: the mesh  */
end_comment

begin_function_decl
name|void
name|mesh_stats_clear
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print all the states in the mesh to the log.  * @param mesh: the mesh to print all states of.  */
end_comment

begin_function_decl
name|void
name|mesh_log_list
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Calculate memory size in use by mesh and all queries inside it.  * @param mesh: the mesh to examine.  * @return size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|mesh_get_mem
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find cycle; see if the given mesh is in the targets sub, or sub-sub, ...  * trees.  * If the sub-sub structure is too large, it returns 'a cycle'=2.  * @param qstate: given mesh querystate.  * @param qinfo: query info for dependency.  * @param flags: query flags of dependency.  * @param prime: if dependency is a priming query or not.  * @return true if the name,type,class exists and the given qstate mesh exists  * 	as a dependency of that name. Thus if qstate becomes dependent on  * 	name,type,class then a cycle is created, this is return value 1.  * 	Too large to search is value 2 (also true).  */
end_comment

begin_function_decl
name|int
name|mesh_detect_cycle
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
end_function_decl

begin_comment
comment|/** compare two mesh_states */
end_comment

begin_function_decl
name|int
name|mesh_state_compare
parameter_list|(
specifier|const
name|void
modifier|*
name|ap
parameter_list|,
specifier|const
name|void
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare two mesh references */
end_comment

begin_function_decl
name|int
name|mesh_state_ref_compare
parameter_list|(
specifier|const
name|void
modifier|*
name|ap
parameter_list|,
specifier|const
name|void
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Make space for another recursion state for a reply in the mesh  * @param mesh: mesh area  * @param qbuf: query buffer to save if recursion is invoked to make space.  *    This buffer is necessary, because the following sequence in calls  *    can result in an overwrite of the incoming query:  *    delete_other_mesh_query - iter_clean - serviced_delete - waiting  *    udp query is sent - on error callback - callback sends SERVFAIL reply  *    over the same network channel, and shared UDP buffer is overwritten.  *    You can pass NULL if there is no buffer that must be backed up.  * @return false if no space is available.  */
end_comment

begin_function_decl
name|int
name|mesh_make_new_space
parameter_list|(
name|struct
name|mesh_area
modifier|*
name|mesh
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|qbuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert mesh state into a double linked list.  Inserted at end.  * @param m: mesh state.  * @param fp: pointer to the first-elem-pointer of the list.  * @param lp: pointer to the last-elem-pointer of the list.  */
end_comment

begin_function_decl
name|void
name|mesh_list_insert
parameter_list|(
name|struct
name|mesh_state
modifier|*
name|m
parameter_list|,
name|struct
name|mesh_state
modifier|*
modifier|*
name|fp
parameter_list|,
name|struct
name|mesh_state
modifier|*
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove mesh state from a double linked list.  Remove from any position.  * @param m: mesh state.  * @param fp: pointer to the first-elem-pointer of the list.  * @param lp: pointer to the last-elem-pointer of the list.  */
end_comment

begin_function_decl
name|void
name|mesh_list_remove
parameter_list|(
name|struct
name|mesh_state
modifier|*
name|m
parameter_list|,
name|struct
name|mesh_state
modifier|*
modifier|*
name|fp
parameter_list|,
name|struct
name|mesh_state
modifier|*
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVICES_MESH_H */
end_comment

end_unit

