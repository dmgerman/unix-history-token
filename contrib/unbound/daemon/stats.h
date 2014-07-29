begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * daemon/stats.h - collect runtime performance indicators.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file describes the data structure used to collect runtime performance  * numbers. These 'statistics' may be of interest to the operator.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DAEMON_STATS_H
end_ifndef

begin_define
define|#
directive|define
name|DAEMON_STATS_H
end_define

begin_include
include|#
directive|include
file|"util/timehist.h"
end_include

begin_struct_decl
struct_decl|struct
name|worker
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_point
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_reply
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|edns_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/** number of qtype that is stored for in array */
end_comment

begin_define
define|#
directive|define
name|STATS_QTYPE_NUM
value|256
end_define

begin_comment
comment|/** number of qclass that is stored for in array */
end_comment

begin_define
define|#
directive|define
name|STATS_QCLASS_NUM
value|256
end_define

begin_comment
comment|/** number of rcodes in stats */
end_comment

begin_define
define|#
directive|define
name|STATS_RCODE_NUM
value|16
end_define

begin_comment
comment|/** number of opcodes in stats */
end_comment

begin_define
define|#
directive|define
name|STATS_OPCODE_NUM
value|16
end_define

begin_comment
comment|/** per worker statistics */
end_comment

begin_struct
struct|struct
name|server_stats
block|{
comment|/** number of queries from clients received. */
name|size_t
name|num_queries
decl_stmt|;
comment|/** number of queries that had a cache-miss. */
name|size_t
name|num_queries_missed_cache
decl_stmt|;
comment|/** number of prefetch queries - cachehits with prefetch */
name|size_t
name|num_queries_prefetch
decl_stmt|;
comment|/** 	 * Sum of the querylistsize of the worker for  	 * every query that missed cache. To calculate average. 	 */
name|size_t
name|sum_query_list_size
decl_stmt|;
comment|/** max value of query list size reached. */
name|size_t
name|max_query_list_size
decl_stmt|;
comment|/** Extended stats below (bool) */
name|int
name|extended
decl_stmt|;
comment|/** qtype stats */
name|size_t
name|qtype
index|[
name|STATS_QTYPE_NUM
index|]
decl_stmt|;
comment|/** bigger qtype values not in array */
name|size_t
name|qtype_big
decl_stmt|;
comment|/** qclass stats */
name|size_t
name|qclass
index|[
name|STATS_QCLASS_NUM
index|]
decl_stmt|;
comment|/** bigger qclass values not in array */
name|size_t
name|qclass_big
decl_stmt|;
comment|/** query opcodes */
name|size_t
name|qopcode
index|[
name|STATS_OPCODE_NUM
index|]
decl_stmt|;
comment|/** number of queries over TCP */
name|size_t
name|qtcp
decl_stmt|;
comment|/** number of queries over IPv6 */
name|size_t
name|qipv6
decl_stmt|;
comment|/** number of queries with QR bit */
name|size_t
name|qbit_QR
decl_stmt|;
comment|/** number of queries with AA bit */
name|size_t
name|qbit_AA
decl_stmt|;
comment|/** number of queries with TC bit */
name|size_t
name|qbit_TC
decl_stmt|;
comment|/** number of queries with RD bit */
name|size_t
name|qbit_RD
decl_stmt|;
comment|/** number of queries with RA bit */
name|size_t
name|qbit_RA
decl_stmt|;
comment|/** number of queries with Z bit */
name|size_t
name|qbit_Z
decl_stmt|;
comment|/** number of queries with AD bit */
name|size_t
name|qbit_AD
decl_stmt|;
comment|/** number of queries with CD bit */
name|size_t
name|qbit_CD
decl_stmt|;
comment|/** number of queries with EDNS OPT record */
name|size_t
name|qEDNS
decl_stmt|;
comment|/** number of queries with EDNS with DO flag */
name|size_t
name|qEDNS_DO
decl_stmt|;
comment|/** answer rcodes */
name|size_t
name|ans_rcode
index|[
name|STATS_RCODE_NUM
index|]
decl_stmt|;
comment|/** answers with pseudo rcode 'nodata' */
name|size_t
name|ans_rcode_nodata
decl_stmt|;
comment|/** answers that were secure (AD) */
name|size_t
name|ans_secure
decl_stmt|;
comment|/** answers that were bogus (withheld as SERVFAIL) */
name|size_t
name|ans_bogus
decl_stmt|;
comment|/** rrsets marked bogus by validator */
name|size_t
name|rrset_bogus
decl_stmt|;
comment|/** unwanted traffic received on server-facing ports */
name|size_t
name|unwanted_replies
decl_stmt|;
comment|/** unwanted traffic received on client-facing ports */
name|size_t
name|unwanted_queries
decl_stmt|;
comment|/** histogram data exported to array  	 * if the array is the same size, no data is lost, and 	 * if all histograms are same size (is so by default) then 	 * adding up works well. */
name|size_t
name|hist
index|[
name|NUM_BUCKETS_HIST
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Statistics to send over the control pipe when asked  * This struct is made to be memcpied, sent in binary.  */
end_comment

begin_struct
struct|struct
name|stats_info
block|{
comment|/** the thread stats */
name|struct
name|server_stats
name|svr
decl_stmt|;
comment|/** mesh stats: current number of states */
name|size_t
name|mesh_num_states
decl_stmt|;
comment|/** mesh stats: current number of reply (user) states */
name|size_t
name|mesh_num_reply_states
decl_stmt|;
comment|/** mesh stats: number of reply states overwritten with a new one */
name|size_t
name|mesh_jostled
decl_stmt|;
comment|/** mesh stats: number of incoming queries dropped */
name|size_t
name|mesh_dropped
decl_stmt|;
comment|/** mesh stats: replies sent */
name|size_t
name|mesh_replies_sent
decl_stmt|;
comment|/** mesh stats: sum of waiting times for the replies */
name|struct
name|timeval
name|mesh_replies_sum_wait
decl_stmt|;
comment|/** mesh stats: median of waiting times for replies (in sec) */
name|double
name|mesh_time_median
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Initialize server stats to 0.  * @param stats: what to init (this is alloced by the caller).  * @param cfg: with extended statistics option.  */
end_comment

begin_function_decl
name|void
name|server_stats_init
parameter_list|(
name|struct
name|server_stats
modifier|*
name|stats
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** add query if it missed the cache */
end_comment

begin_function_decl
name|void
name|server_stats_querymiss
parameter_list|(
name|struct
name|server_stats
modifier|*
name|stats
parameter_list|,
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** add query if was cached and also resulted in a prefetch */
end_comment

begin_function_decl
name|void
name|server_stats_prefetch
parameter_list|(
name|struct
name|server_stats
modifier|*
name|stats
parameter_list|,
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** display the stats to the log */
end_comment

begin_function_decl
name|void
name|server_stats_log
parameter_list|(
name|struct
name|server_stats
modifier|*
name|stats
parameter_list|,
name|struct
name|worker
modifier|*
name|worker
parameter_list|,
name|int
name|threadnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Obtain the stats info for a given thread. Uses pipe to communicate.  * @param worker: the worker that is executing (the first worker).  * @param who: on who to get the statistics info.  * @param s: the stats block to fill in.  * @param reset: if stats can be reset.  */
end_comment

begin_function_decl
name|void
name|server_stats_obtain
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|,
name|struct
name|worker
modifier|*
name|who
parameter_list|,
name|struct
name|stats_info
modifier|*
name|s
parameter_list|,
name|int
name|reset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compile stats into structure for this thread worker.  * Also clears the statistics counters (if that is set by config file).  * @param worker: the worker to compile stats for, also the executing worker.  * @param s: stats block.  * @param reset: if true, depending on config stats are reset.  * 	if false, statistics are not reset.  */
end_comment

begin_function_decl
name|void
name|server_stats_compile
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|,
name|struct
name|stats_info
modifier|*
name|s
parameter_list|,
name|int
name|reset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Send stats over comm tube in reply to query cmd  * @param worker: this worker.  * @param reset: if true, depending on config stats are reset.  * 	if false, statistics are not reset.  */
end_comment

begin_function_decl
name|void
name|server_stats_reply
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|,
name|int
name|reset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Addup stat blocks.  * @param total: sum of the two entries.  * @param a: to add to it.  */
end_comment

begin_function_decl
name|void
name|server_stats_add
parameter_list|(
name|struct
name|stats_info
modifier|*
name|total
parameter_list|,
name|struct
name|stats_info
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add stats for this query  * @param stats: the stats  * @param c: commpoint with type and buffer.  * @param qtype: query type  * @param qclass: query class  * @param edns: edns record  * @param repinfo: reply info with remote address  */
end_comment

begin_function_decl
name|void
name|server_stats_insquery
parameter_list|(
name|struct
name|server_stats
modifier|*
name|stats
parameter_list|,
name|struct
name|comm_point
modifier|*
name|c
parameter_list|,
name|uint16_t
name|qtype
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|,
name|struct
name|comm_reply
modifier|*
name|repinfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add rcode for this query.  * @param stats: the stats  * @param buf: buffer with rcode. If buffer is length0: not counted.  */
end_comment

begin_function_decl
name|void
name|server_stats_insrcode
parameter_list|(
name|struct
name|server_stats
modifier|*
name|stats
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DAEMON_STATS_H */
end_comment

end_unit

