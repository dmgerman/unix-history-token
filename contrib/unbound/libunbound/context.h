begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * libunbound/context.h - validating context for unbound internal use  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains the validator context structure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBUNBOUND_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LIBUNBOUND_CONTEXT_H
end_define

begin_include
include|#
directive|include
file|"util/locks.h"
end_include

begin_include
include|#
directive|include
file|"util/alloc.h"
end_include

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_include
include|#
directive|include
file|"services/modstack.h"
end_include

begin_include
include|#
directive|include
file|"libunbound/unbound.h"
end_include

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

begin_struct_decl
struct_decl|struct
name|libworker
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tube
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|event_base
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * The context structure  *  * Contains two pipes for async service  *	qq : write queries to the async service pid/tid.  *	rr : read results from the async service pid/tid.  */
end_comment

begin_struct
struct|struct
name|ub_ctx
block|{
comment|/* --- pipes --- */
comment|/** mutex on query write pipe */
name|lock_basic_t
name|qqpipe_lock
decl_stmt|;
comment|/** the query write pipe */
name|struct
name|tube
modifier|*
name|qq_pipe
decl_stmt|;
comment|/** mutex on result read pipe */
name|lock_basic_t
name|rrpipe_lock
decl_stmt|;
comment|/** the result read pipe */
name|struct
name|tube
modifier|*
name|rr_pipe
decl_stmt|;
comment|/* --- shared data --- */
comment|/** mutex for access to env.cfg, finalized and dothread */
name|lock_basic_t
name|cfglock
decl_stmt|;
comment|/**  	 * The context has been finalized  	 * This is after config when the first resolve is done. 	 * The modules are inited (module-init()) and shared caches created. 	 */
name|int
name|finalized
decl_stmt|;
comment|/** is bg worker created yet ? */
name|int
name|created_bg
decl_stmt|;
comment|/** pid of bg worker process */
name|pid_t
name|bg_pid
decl_stmt|;
comment|/** tid of bg worker thread */
name|ub_thread_t
name|bg_tid
decl_stmt|;
comment|/** do threading (instead of forking) for async resolution */
name|int
name|dothread
decl_stmt|;
comment|/** next thread number for new threads */
name|int
name|thr_next_num
decl_stmt|;
comment|/** if logfile is overriden */
name|int
name|logfile_override
decl_stmt|;
comment|/** what logfile to use instead */
name|FILE
modifier|*
name|log_out
decl_stmt|;
comment|/**  	 * List of alloc-cache-id points per threadnum for notinuse threads. 	 * Simply the entire struct alloc_cache with the 'super' member used 	 * to link a simply linked list. Reset super member to the superalloc 	 * before use. 	 */
name|struct
name|alloc_cache
modifier|*
name|alloc_list
decl_stmt|;
comment|/** shared caches, and so on */
name|struct
name|alloc_cache
name|superalloc
decl_stmt|;
comment|/** module env master value */
name|struct
name|module_env
modifier|*
name|env
decl_stmt|;
comment|/** module stack */
name|struct
name|module_stack
name|mods
decl_stmt|;
comment|/** local authority zones */
name|struct
name|local_zones
modifier|*
name|local_zones
decl_stmt|;
comment|/** random state used to seed new random state structures */
name|struct
name|ub_randstate
modifier|*
name|seed_rnd
decl_stmt|;
comment|/** event base for event oriented interface */
name|struct
name|event_base
modifier|*
name|event_base
decl_stmt|;
comment|/** libworker for event based interface */
name|struct
name|libworker
modifier|*
name|event_worker
decl_stmt|;
comment|/** next query number (to try) to use */
name|int
name|next_querynum
decl_stmt|;
comment|/** number of async queries outstanding */
name|size_t
name|num_async
decl_stmt|;
comment|/**  	 * Tree of outstanding queries. Indexed by querynum  	 * Used when results come in for async to lookup. 	 * Used when cancel is done for lookup (and delete). 	 * Used to see if querynum is free for use. 	 * Content of type ctx_query. 	 */
name|rbtree_t
name|queries
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * The queries outstanding for the libunbound resolver.  * These are outstanding for async resolution.  * But also, outstanding for sync resolution by one of the threads that  * has joined the threadpool.  */
end_comment

begin_struct
struct|struct
name|ctx_query
block|{
comment|/** node in rbtree, must be first entry, key is ptr to the querynum */
name|struct
name|rbnode_t
name|node
decl_stmt|;
comment|/** query id number, key for node */
name|int
name|querynum
decl_stmt|;
comment|/** was this an async query? */
name|int
name|async
decl_stmt|;
comment|/** was this query cancelled (for bg worker) */
name|int
name|cancelled
decl_stmt|;
comment|/** for async query, the callback function */
name|ub_callback_t
name|cb
decl_stmt|;
comment|/** for async query, the callback user arg */
name|void
modifier|*
name|cb_arg
decl_stmt|;
comment|/** answer message, result from resolver lookup. */
name|uint8_t
modifier|*
name|msg
decl_stmt|;
comment|/** resulting message length. */
name|size_t
name|msg_len
decl_stmt|;
comment|/** validation status on security */
name|enum
name|sec_status
name|msg_security
decl_stmt|;
comment|/** store libworker that is handling this query */
name|struct
name|libworker
modifier|*
name|w
decl_stmt|;
comment|/** result structure, also contains original query, type, class. 	 * malloced ptr ready to hand to the client. */
name|struct
name|ub_result
modifier|*
name|res
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * The error constants  */
end_comment

begin_enum
enum|enum
name|ub_ctx_err
block|{
comment|/** no error */
name|UB_NOERROR
init|=
literal|0
block|,
comment|/** socket operation. Set to -1, so that if an error from _fd() is 	 * passed (-1) it gives a socket error. */
name|UB_SOCKET
init|=
operator|-
literal|1
block|,
comment|/** alloc failure */
name|UB_NOMEM
init|=
operator|-
literal|2
block|,
comment|/** syntax error */
name|UB_SYNTAX
init|=
operator|-
literal|3
block|,
comment|/** DNS service failed */
name|UB_SERVFAIL
init|=
operator|-
literal|4
block|,
comment|/** fork() failed */
name|UB_FORKFAIL
init|=
operator|-
literal|5
block|,
comment|/** cfg change after finalize() */
name|UB_AFTERFINAL
init|=
operator|-
literal|6
block|,
comment|/** initialization failed (bad settings) */
name|UB_INITFAIL
init|=
operator|-
literal|7
block|,
comment|/** error in pipe communication with async bg worker */
name|UB_PIPE
init|=
operator|-
literal|8
block|,
comment|/** error reading from file (resolv.conf) */
name|UB_READFILE
init|=
operator|-
literal|9
block|,
comment|/** error async_id does not exist or result already been delivered */
name|UB_NOID
init|=
operator|-
literal|10
block|}
enum|;
end_enum

begin_comment
comment|/**  * Command codes for libunbound pipe.  *  * Serialization looks like this:  * 	o length (of remainder) uint32.  * 	o uint32 command code.  * 	o per command format.  */
end_comment

begin_enum
enum|enum
name|ub_ctx_cmd
block|{
comment|/** QUIT */
name|UB_LIBCMD_QUIT
init|=
literal|0
block|,
comment|/** New query, sent to bg worker */
name|UB_LIBCMD_NEWQUERY
block|,
comment|/** Cancel query, sent to bg worker */
name|UB_LIBCMD_CANCEL
block|,
comment|/** Query result, originates from bg worker */
name|UB_LIBCMD_ANSWER
block|}
enum|;
end_enum

begin_comment
comment|/**   * finalize a context.  * @param ctx: context to finalize. creates shared data.  * @return 0 if OK, or errcode.  */
end_comment

begin_function_decl
name|int
name|context_finalize
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare two ctx_query elements */
end_comment

begin_function_decl
name|int
name|context_query_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * delete context query  * @param q: query to delete, including message packet and prealloc result  */
end_comment

begin_function_decl
name|void
name|context_query_delete
parameter_list|(
name|struct
name|ctx_query
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create new query in context, add to querynum list.  * @param ctx: context  * @param name: query name  * @param rrtype: type  * @param rrclass: class  * @param cb: callback for async, or NULL for sync.  * @param cbarg: user arg for async queries.  * @return new ctx_query or NULL for malloc failure.  */
end_comment

begin_function_decl
name|struct
name|ctx_query
modifier|*
name|context_new
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|rrtype
parameter_list|,
name|int
name|rrclass
parameter_list|,
name|ub_callback_t
name|cb
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get a new alloc. Creates a new one or uses a cached one.  * @param ctx: context  * @param locking: if true, cfglock is locked while getting alloc.  * @return an alloc, or NULL on mem error.  */
end_comment

begin_function_decl
name|struct
name|alloc_cache
modifier|*
name|context_obtain_alloc
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|int
name|locking
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Release an alloc. Puts it into the cache.  * @param ctx: context  * @param locking: if true, cfglock is locked while releasing alloc.  * @param alloc: alloc to relinquish.  */
end_comment

begin_function_decl
name|void
name|context_release_alloc
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|int
name|locking
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Serialize a context query that questions data.  * This serializes the query name, type, ...  * As well as command code 'new_query'.  * @param q: context query  * @param len: the length of the allocation is returned.  * @return: an alloc, or NULL on mem error.  */
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|context_serialize_new_query
parameter_list|(
name|struct
name|ctx_query
modifier|*
name|q
parameter_list|,
name|uint32_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Serialize a context_query result to hand back to user.  * This serializes the query name, type, ..., and result.  * As well as command code 'answer'.  * @param q: context query  * @param err: error code to pass to client.  * @param pkt: the packet to add, can be NULL.  * @param len: the length of the allocation is returned.  * @return: an alloc, or NULL on mem error.  */
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|context_serialize_answer
parameter_list|(
name|struct
name|ctx_query
modifier|*
name|q
parameter_list|,
name|int
name|err
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|pkt
parameter_list|,
name|uint32_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Serialize a query cancellation. Serializes query async id  * as well as command code 'cancel'  * @param q: context query  * @param len: the length of the allocation is returned.  * @return: an alloc, or NULL on mem error.  */
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|context_serialize_cancel
parameter_list|(
name|struct
name|ctx_query
modifier|*
name|q
parameter_list|,
name|uint32_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Serialize a 'quit' command.  * @param len: the length of the allocation is returned.  * @return: an alloc, or NULL on mem error.  */
end_comment

begin_function_decl
name|uint8_t
modifier|*
name|context_serialize_quit
parameter_list|(
name|uint32_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Obtain command code from serialized buffer  * @param p: buffer serialized.  * @param len: length of buffer.  * @return command code or QUIT on error.  */
end_comment

begin_function_decl
name|enum
name|ub_ctx_cmd
name|context_serial_getcmd
parameter_list|(
name|uint8_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup query from new_query buffer.  * @param ctx: context  * @param p: buffer serialized.  * @param len: length of buffer.  * @return looked up ctx_query or NULL for malloc failure.  */
end_comment

begin_function_decl
name|struct
name|ctx_query
modifier|*
name|context_lookup_new_query
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|uint8_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Deserialize a new_query buffer.  * @param ctx: context  * @param p: buffer serialized.  * @param len: length of buffer.  * @return new ctx_query or NULL for malloc failure.  */
end_comment

begin_function_decl
name|struct
name|ctx_query
modifier|*
name|context_deserialize_new_query
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|uint8_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Deserialize an answer buffer.  * @param ctx: context  * @param p: buffer serialized.  * @param len: length of buffer.  * @param err: error code to be returned to client is passed.  * @return ctx_query with answer added or NULL for malloc failure.  */
end_comment

begin_function_decl
name|struct
name|ctx_query
modifier|*
name|context_deserialize_answer
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|uint8_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|len
parameter_list|,
name|int
modifier|*
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Deserialize a cancel buffer.  * @param ctx: context  * @param p: buffer serialized.  * @param len: length of buffer.  * @return ctx_query to cancel or NULL for failure.  */
end_comment

begin_function_decl
name|struct
name|ctx_query
modifier|*
name|context_deserialize_cancel
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|uint8_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBUNBOUND_CONTEXT_H */
end_comment

end_unit

