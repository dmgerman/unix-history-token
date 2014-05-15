begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * daemon/worker.h - worker that handles a pending list of requests.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file describes the worker structure that holds a list of   * pending requests and handles them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DAEMON_WORKER_H
end_ifndef

begin_define
define|#
directive|define
name|DAEMON_WORKER_H
end_define

begin_include
include|#
directive|include
file|"libunbound/worker.h"
end_include

begin_include
include|#
directive|include
file|"util/netevent.h"
end_include

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
file|"util/data/msgreply.h"
end_include

begin_include
include|#
directive|include
file|"util/data/msgparse.h"
end_include

begin_include
include|#
directive|include
file|"daemon/stats.h"
end_include

begin_include
include|#
directive|include
file|"util/module.h"
end_include

begin_struct_decl
struct_decl|struct
name|listen_dnsport
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|outside_network
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|daemon
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|listen_port
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_randstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tube
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|daemon_remote
struct_decl|;
end_struct_decl

begin_comment
comment|/** worker commands */
end_comment

begin_enum
enum|enum
name|worker_commands
block|{
comment|/** make the worker quit */
name|worker_cmd_quit
block|,
comment|/** obtain statistics */
name|worker_cmd_stats
block|,
comment|/** obtain statistics without statsclear */
name|worker_cmd_stats_noreset
block|,
comment|/** execute remote control command */
name|worker_cmd_remote
block|}
enum|;
end_enum

begin_comment
comment|/**  * Structure holding working information for unbound.  * Holds globally visible information.  */
end_comment

begin_struct
struct|struct
name|worker
block|{
comment|/** the thread number (in daemon array). First in struct for debug. */
name|int
name|thread_num
decl_stmt|;
comment|/** global shared daemon structure */
name|struct
name|daemon
modifier|*
name|daemon
decl_stmt|;
comment|/** thread id */
name|ub_thread_t
name|thr_id
decl_stmt|;
comment|/** pipe, for commands for this worker */
name|struct
name|tube
modifier|*
name|cmd
decl_stmt|;
comment|/** the event base this worker works with */
name|struct
name|comm_base
modifier|*
name|base
decl_stmt|;
comment|/** the frontside listening interface where request events come in */
name|struct
name|listen_dnsport
modifier|*
name|front
decl_stmt|;
comment|/** the backside outside network interface to the auth servers */
name|struct
name|outside_network
modifier|*
name|back
decl_stmt|;
comment|/** ports to be used by this worker. */
name|int
modifier|*
name|ports
decl_stmt|;
comment|/** number of ports for this worker */
name|int
name|numports
decl_stmt|;
comment|/** the signal handler */
name|struct
name|comm_signal
modifier|*
name|comsig
decl_stmt|;
comment|/** commpoint to listen to commands. */
name|struct
name|comm_point
modifier|*
name|cmd_com
decl_stmt|;
comment|/** timer for statistics */
name|struct
name|comm_timer
modifier|*
name|stat_timer
decl_stmt|;
comment|/** random() table for this worker. */
name|struct
name|ub_randstate
modifier|*
name|rndstate
decl_stmt|;
comment|/** do we need to restart or quit (on signal) */
name|int
name|need_to_exit
decl_stmt|;
comment|/** allocation cache for this thread */
name|struct
name|alloc_cache
name|alloc
decl_stmt|;
comment|/** per thread statistics */
name|struct
name|server_stats
name|stats
decl_stmt|;
comment|/** thread scratch regional */
name|struct
name|regional
modifier|*
name|scratchpad
decl_stmt|;
comment|/** module environment passed to modules, changed for this thread */
name|struct
name|module_env
name|env
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create the worker structure. Bare bones version, zeroed struct,  * with backpointers only. Use worker_init on it later.  * @param daemon: the daemon that this worker thread is part of.  * @param id: the thread number from 0.. numthreads-1.  * @param ports: the ports it is allowed to use, array.  * @param n: the number of ports.  * @return: the new worker or NULL on alloc failure.  */
end_comment

begin_function_decl
name|struct
name|worker
modifier|*
name|worker_create
parameter_list|(
name|struct
name|daemon
modifier|*
name|daemon
parameter_list|,
name|int
name|id
parameter_list|,
name|int
modifier|*
name|ports
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize worker.  * Allocates event base, listens to ports  * @param worker: worker to initialize, created with worker_create.  * @param cfg: configuration settings.  * @param ports: list of shared query ports.  * @param do_sigs: if true, worker installs signal handlers.  * @return: false on error.  */
end_comment

begin_function_decl
name|int
name|worker_init
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
name|struct
name|listen_port
modifier|*
name|ports
parameter_list|,
name|int
name|do_sigs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Make worker work.  */
end_comment

begin_function_decl
name|void
name|worker_work
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete worker.  */
end_comment

begin_function_decl
name|void
name|worker_delete
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Send a command to a worker. Uses blocking writes.  * @param worker: worker to send command to.  * @param cmd: command to send.  */
end_comment

begin_function_decl
name|void
name|worker_send_cmd
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|,
name|enum
name|worker_commands
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Init worker stats - includes server_stats_init, outside network and mesh.  * @param worker: the worker to init  */
end_comment

begin_function_decl
name|void
name|worker_stats_clear
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DAEMON_WORKER_H */
end_comment

end_unit

