begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * testcode/replay.h - store and use a replay of events for the DNS resolver.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  * Store and use a replay of events for the DNS resolver.  * Used to test known scenarios to get known outcomes.  *  *<pre>  * File format for replay files.  *  * ; unbound.conf options.  * ; ...  * ; additional commandline options to pass to unbound  * COMMANDLINE cmdline_option  * ; autotrust key file contents, also adds auto-trust-anchor-file: "x" to cfg  * AUTOTRUST_FILE id  * ; contents of that file  * AUTOTRUST_END  * CONFIG_END  * ; comment line.  * SCENARIO_BEGIN name_of_scenario  * RANGE_BEGIN start_time end_time  *    ; give ip of the virtual server, it matches any ip if not present.  *    ADDRESS ip_address   *    match_entries  * RANGE_END  * ; more RANGE items.  * ; go to the next moment  * STEP time_step event_type [ADDRESS ip_address]  * ; event_type can be:  *	o NOTHING - nothing  *	o QUERY - followed by entry  *	o CHECK_ANSWER - followed by entry  *	o CHECK_OUT_QUERY - followed by entry (if copy-id it is also reply).  *	o REPLY - followed by entry  *      o TIMEOUT  *      o TIME_PASSES ELAPSE [seconds] - increase 'now' time counter, can be   *      			a floating point number.  *        TIME_PASSES EVAL [macro] - expanded for seconds to move time.  *      o TRAFFIC - like CHECK_ANSWER, causes traffic to flow.  *		actually the traffic flows before this step is taken.  *		the step waits for traffic to stop.  *      o CHECK_AUTOTRUST [id] - followed by FILE_BEGIN [to match] FILE_END.  *      	The file contents is macro expanded before match.  *      o INFRA_RTT [ip] [dp] [rtt] - update infra cache entry with rtt.  *      o ERROR  * ; following entry starts on the next line, ENTRY_BEGIN.  * ; more STEP items  * SCENARIO_END  *  * Calculations, a macro-like system: ${$myvar + 3600}  * STEP 10 ASSIGN myvar = 3600  * 	; ASSIGN event. '=' is syntactic sugar here. 3600 is some expression.  * ${..} is macro expanded from its expression.  Text substitution.  * 	o $var replaced with its value.  var is identifier [azAZ09_]*  * 	o number is that number.  * 	o ${variables and arithmetic }  * 	o +, -, / and *.  Note, evaluated left-to-right. Use ${} for brackets.  * 	  So again, no precedence rules, so 2+3*4 == ${2+3}*4 = 20.  * 	  Do 2+${3*4} to get 24.  * 	o ${function params}  *		o ${time} is the current time for the simulated unbound.  *		o ${ctime value} is the text ctime(value), Fri 3 Aug 2009, ...  *		o ${timeout} is the time until next timeout in comm_timer list.  *		o ${range lower value upper} checks if lower<=value<=upper  *			returns value if check succeeds.  *  * ; Example file  * SCENARIO_BEGIN Example scenario  * RANGE_BEGIN 0 100  *   ENTRY_BEGIN  *   ; precoded answers to queries.  *   ENTRY_END  * END_RANGE  * STEP 0 QUERY  *   ENTRY_BEGIN  *   ; query  *   ENTRY_END  * ; a query is sent out to the network by resolver.  * ; precoded answer from range is returned.  * ; algorithm will do precoded answers from RANGE immediately, except if  * ; the next step specifically checks for that OUT_QUERY.  * ; or if none of the precoded answers match.  * STEP 1 CHECK_ANSWER  *   ENTRY_BEGIN  *   ; what the reply should look like  *   ENTRY_END  * ; successful termination. (if the answer was OK).  * ; also, all answers must have been checked with CHECK_ANSWER.  * ; and, no more pending out_queries (that have not been checked).  * SCENARIO_END  *   *</pre>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TESTCODE_REPLAY_H
end_ifndef

begin_define
define|#
directive|define
name|TESTCODE_REPLAY_H
end_define

begin_include
include|#
directive|include
file|"util/netevent.h"
end_include

begin_include
include|#
directive|include
file|"testcode/testpkts.h"
end_include

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_struct_decl
struct_decl|struct
name|replay_answer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|replay_moment
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|replay_range
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fake_pending
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fake_timer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|replay_var
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|infra_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * A replay scenario.  */
end_comment

begin_struct
struct|struct
name|replay_scenario
block|{
comment|/** name of replay scenario. malloced string. */
name|char
modifier|*
name|title
decl_stmt|;
comment|/** The list of replay moments. Linked list. Time increases in list. */
name|struct
name|replay_moment
modifier|*
name|mom_first
decl_stmt|;
comment|/** The last element in list of replay moments. */
name|struct
name|replay_moment
modifier|*
name|mom_last
decl_stmt|;
comment|/**  	 * List of matching answers. This is to ease replay scenario 	 * creation. It lists queries (to the network) and what answer 	 * should be returned. The matching answers are valid for a range 	 * of time steps.  	 * So: timestep, parts of query, destination --> answer. 	 */
name|struct
name|replay_range
modifier|*
name|range_list
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * A replay moment.  * Basically, it consists of events to a fake select() call.  * This is a recording of an event that happens.  * And if output is presented, what is done with that.  */
end_comment

begin_struct
struct|struct
name|replay_moment
block|{
comment|/**  	 * The replay time step number. Starts at 0, time is incremented  	 * every time the fake select() is run.  	 */
name|int
name|time_step
decl_stmt|;
comment|/** Next replay moment in list of replay moments. */
name|struct
name|replay_moment
modifier|*
name|mom_next
decl_stmt|;
comment|/** what happens this moment? */
enum|enum
name|replay_event_type
block|{
comment|/** nothing happens, as if this event is not there. */
name|repevt_nothing
block|,
comment|/** incoming query */
name|repevt_front_query
block|,
comment|/** test fails if reply to query does not match */
name|repevt_front_reply
block|,
comment|/** timeout */
name|repevt_timeout
block|,
comment|/** time passes */
name|repevt_time_passes
block|,
comment|/** reply arrives from the network */
name|repevt_back_reply
block|,
comment|/** test fails if query to the network does not match */
name|repevt_back_query
block|,
comment|/** check autotrust key file */
name|repevt_autotrust_check
block|,
comment|/** an error happens to outbound query */
name|repevt_error
block|,
comment|/** assignment to a variable */
name|repevt_assign
block|,
comment|/** store infra rtt cache entry: addr and string (int) */
name|repevt_infra_rtt
block|,
comment|/** cause traffic to flow */
name|repevt_traffic
block|}
comment|/** variable with what is to happen this moment */
name|evt_type
enum|;
comment|/** The sent packet must match this. Incoming events, the data. */
name|struct
name|entry
modifier|*
name|match
decl_stmt|;
comment|/** the amount of time that passes */
name|struct
name|timeval
name|elapse
decl_stmt|;
comment|/** address that must be matched, or packet remote host address. */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of addr, if 0, then any address will do */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** macro name, for assign. */
name|char
modifier|*
name|variable
decl_stmt|;
comment|/** string argument, for assign. */
name|char
modifier|*
name|string
decl_stmt|;
comment|/** the autotrust file id to check */
name|char
modifier|*
name|autotrust_id
decl_stmt|;
comment|/** file contents to match, one string per line */
name|struct
name|config_strlist
modifier|*
name|file_content
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Range of timesteps, and canned replies to matching queries.  */
end_comment

begin_struct
struct|struct
name|replay_range
block|{
comment|/** time range when this is valid. Including start and end step. */
name|int
name|start_step
decl_stmt|;
comment|/** end step of time range. */
name|int
name|end_step
decl_stmt|;
comment|/** address of where this range is served. */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** length of addr, if 0, then any address will do */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** Matching list */
name|struct
name|entry
modifier|*
name|match
decl_stmt|;
comment|/** next in list of time ranges. */
name|struct
name|replay_range
modifier|*
name|next_range
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Replay storage of runtime information.  */
end_comment

begin_struct
struct|struct
name|replay_runtime
block|{
comment|/** 	 * The scenario 	 */
name|struct
name|replay_scenario
modifier|*
name|scenario
decl_stmt|;
comment|/** 	 * Current moment. 	 */
name|struct
name|replay_moment
modifier|*
name|now
decl_stmt|;
comment|/**  	 * List of pending queries in order they were sent out. First 	 * one has been sent out most recently. Last one in list is oldest.  	 */
name|struct
name|fake_pending
modifier|*
name|pending_list
decl_stmt|;
comment|/** 	 * List of answers to queries from clients. These need to be checked. 	 */
name|struct
name|replay_answer
modifier|*
name|answer_list
decl_stmt|;
comment|/** last element in answer list. */
name|struct
name|replay_answer
modifier|*
name|answer_last
decl_stmt|;
comment|/** list of fake timer callbacks that are pending */
name|struct
name|fake_timer
modifier|*
name|timer_list
decl_stmt|;
comment|/** callback to call for incoming queries */
name|comm_point_callback_t
modifier|*
name|callback_query
decl_stmt|;
comment|/** user argument for incoming query callback */
name|void
modifier|*
name|cb_arg
decl_stmt|;
comment|/** ref the infra cache (was passed to outside_network_create) */
name|struct
name|infra_cache
modifier|*
name|infra
decl_stmt|;
comment|/** the current time in seconds */
name|time_t
name|now_secs
decl_stmt|;
comment|/** the current time in microseconds */
name|struct
name|timeval
name|now_tv
decl_stmt|;
comment|/** signal handler callback */
name|void
function_decl|(
modifier|*
name|sig_cb
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** signal handler user arg */
name|void
modifier|*
name|sig_cb_arg
decl_stmt|;
comment|/** time to exit cleanly */
name|int
name|exit_cleanly
decl_stmt|;
comment|/** size of buffers */
name|size_t
name|bufsize
decl_stmt|;
comment|/** 	 * Tree of macro values. Of type replay_var 	 */
name|rbtree_t
modifier|*
name|vars
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Pending queries to network, fake replay version.  */
end_comment

begin_struct
struct|struct
name|fake_pending
block|{
comment|/** what is important only that we remember the query, copied here. */
name|struct
name|sldns_buffer
modifier|*
name|buffer
decl_stmt|;
comment|/** and to what address this is sent to. */
name|struct
name|sockaddr_storage
name|addr
decl_stmt|;
comment|/** len of addr */
name|socklen_t
name|addrlen
decl_stmt|;
comment|/** zone name, uncompressed wire format (as used when sent) */
name|uint8_t
modifier|*
name|zone
decl_stmt|;
comment|/** length of zone name */
name|size_t
name|zonelen
decl_stmt|;
comment|/** qtype */
name|int
name|qtype
decl_stmt|;
comment|/** The callback function to call when answer arrives (or timeout) */
name|comm_point_callback_t
modifier|*
name|callback
decl_stmt|;
comment|/** callback user argument */
name|void
modifier|*
name|cb_arg
decl_stmt|;
comment|/** original timeout in seconds from 'then' */
name|int
name|timeout
decl_stmt|;
comment|/** next in pending list */
name|struct
name|fake_pending
modifier|*
name|next
decl_stmt|;
comment|/** the buffer parsed into a sldns_pkt */
name|uint8_t
modifier|*
name|pkt
decl_stmt|;
name|size_t
name|pkt_len
decl_stmt|;
comment|/** by what transport was the query sent out */
name|enum
name|transport_type
name|transport
decl_stmt|;
comment|/** if this is a serviced query */
name|int
name|serviced
decl_stmt|;
comment|/** the runtime structure this is part of */
name|struct
name|replay_runtime
modifier|*
name|runtime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * An answer that is pending to happen.  */
end_comment

begin_struct
struct|struct
name|replay_answer
block|{
comment|/** Next in list */
name|struct
name|replay_answer
modifier|*
name|next
decl_stmt|;
comment|/** reply information */
name|struct
name|comm_reply
name|repinfo
decl_stmt|;
comment|/** the answer preparsed as ldns pkt */
name|uint8_t
modifier|*
name|pkt
decl_stmt|;
name|size_t
name|pkt_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Timers with callbacks, fake replay version.  */
end_comment

begin_struct
struct|struct
name|fake_timer
block|{
comment|/** next in list */
name|struct
name|fake_timer
modifier|*
name|next
decl_stmt|;
comment|/** the runtime structure this is part of */
name|struct
name|replay_runtime
modifier|*
name|runtime
decl_stmt|;
comment|/** the callback to call */
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** the callback user argument */
name|void
modifier|*
name|cb_arg
decl_stmt|;
comment|/** if timer is enabled */
name|int
name|enabled
decl_stmt|;
comment|/** when the timer expires */
name|struct
name|timeval
name|tv
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Replay macro variable.  And its value.  */
end_comment

begin_struct
struct|struct
name|replay_var
block|{
comment|/** rbtree node. Key is this structure. Sorted by name. */
name|rbnode_t
name|node
decl_stmt|;
comment|/** the variable name */
name|char
modifier|*
name|name
decl_stmt|;
comment|/** the variable value */
name|char
modifier|*
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Read a replay scenario from the file.  * @param in: file to read from.  * @param name: name to print in errors.  * @param lineno: incremented for every line read.  * @return: Scenario. NULL if no scenario read.  */
end_comment

begin_function_decl
name|struct
name|replay_scenario
modifier|*
name|replay_scenario_read
parameter_list|(
name|FILE
modifier|*
name|in
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|lineno
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete scenario.  * @param scen: to delete.  */
end_comment

begin_function_decl
name|void
name|replay_scenario_delete
parameter_list|(
name|struct
name|replay_scenario
modifier|*
name|scen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare two replay_vars */
end_comment

begin_function_decl
name|int
name|replay_var_compare
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
comment|/** get oldest enabled fake timer */
end_comment

begin_function_decl
name|struct
name|fake_timer
modifier|*
name|replay_get_oldest_timer
parameter_list|(
name|struct
name|replay_runtime
modifier|*
name|runtime
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create variable storage  * @return new or NULL on failure.  */
end_comment

begin_function_decl
name|rbtree_t
modifier|*
name|macro_store_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete variable storage  * @param store: the macro storage to free up.  */
end_comment

begin_function_decl
name|void
name|macro_store_delete
parameter_list|(
name|rbtree_t
modifier|*
name|store
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Apply macro substitution to string.  * @param store: variable store.  * @param runtime: the runtime to look up values as needed.  * @param text: string to work on.  * @return newly malloced string with result.  */
end_comment

begin_function_decl
name|char
modifier|*
name|macro_process
parameter_list|(
name|rbtree_t
modifier|*
name|store
parameter_list|,
name|struct
name|replay_runtime
modifier|*
name|runtime
parameter_list|,
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Look up a macro value. Like calling ${$name}.  * @param store: variable store  * @param name: macro name  * @return newly malloced string with result or strdup("") if not found.  * 	or NULL on malloc failure.  */
end_comment

begin_function_decl
name|char
modifier|*
name|macro_lookup
parameter_list|(
name|rbtree_t
modifier|*
name|store
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set macro value.  * @param store: variable store  * @param name: macro name  * @param value: text to set it to.  Not expanded.  * @return false on failure.  */
end_comment

begin_function_decl
name|int
name|macro_assign
parameter_list|(
name|rbtree_t
modifier|*
name|store
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Print macro variables stored as debug info */
end_comment

begin_function_decl
name|void
name|macro_print_debug
parameter_list|(
name|rbtree_t
modifier|*
name|store
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** testbounds self test */
end_comment

begin_function_decl
name|void
name|testbound_selftest
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TESTCODE_REPLAY_H */
end_comment

end_unit

