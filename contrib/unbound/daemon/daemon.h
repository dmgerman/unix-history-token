begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * daemon/daemon.h - collection of workers that handles requests.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * The daemon consists of global settings and a number of workers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DAEMON_H
end_ifndef

begin_define
define|#
directive|define
name|DAEMON_H
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
file|"services/modstack.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UB_ON_WINDOWS
end_ifdef

begin_include
include|#
directive|include
file|"util/winsock_event.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|worker
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|listen_port
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|slabhash
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rrset_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|acl_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|local_zones
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_randstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|daemon_remote
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Structure holding worker list.  * Holds globally visible information.  */
end_comment

begin_struct
struct|struct
name|daemon
block|{
comment|/** The config settings */
name|struct
name|config_file
modifier|*
name|cfg
decl_stmt|;
comment|/** the chroot dir in use, NULL if none */
name|char
modifier|*
name|chroot
decl_stmt|;
comment|/** pidfile that is used */
name|char
modifier|*
name|pidfile
decl_stmt|;
comment|/** port number that has ports opened. */
name|int
name|listening_port
decl_stmt|;
comment|/** array of listening ports, opened.  Listening ports per worker, 	 * or just one element[0] shared by the worker threads. */
name|struct
name|listen_port
modifier|*
modifier|*
name|ports
decl_stmt|;
comment|/** size of ports array */
name|size_t
name|num_ports
decl_stmt|;
comment|/** port number for remote that has ports opened. */
name|int
name|rc_port
decl_stmt|;
comment|/** listening ports for remote control */
name|struct
name|listen_port
modifier|*
name|rc_ports
decl_stmt|;
comment|/** remote control connections management (for first worker) */
name|struct
name|daemon_remote
modifier|*
name|rc
decl_stmt|;
comment|/** ssl context for listening to dnstcp over ssl, and connecting ssl */
name|void
modifier|*
name|listen_sslctx
decl_stmt|,
modifier|*
name|connect_sslctx
decl_stmt|;
comment|/** num threads allocated */
name|int
name|num
decl_stmt|;
comment|/** the worker entries */
name|struct
name|worker
modifier|*
modifier|*
name|workers
decl_stmt|;
comment|/** do we need to exit unbound (or is it only a reload?) */
name|int
name|need_to_exit
decl_stmt|;
comment|/** master random table ; used for port div between threads on reload*/
name|struct
name|ub_randstate
modifier|*
name|rand
decl_stmt|;
comment|/** master allocation cache */
name|struct
name|alloc_cache
name|superalloc
decl_stmt|;
comment|/** the module environment master value, copied and changed by threads*/
name|struct
name|module_env
modifier|*
name|env
decl_stmt|;
comment|/** stack of module callbacks */
name|struct
name|module_stack
name|mods
decl_stmt|;
comment|/** access control, which client IPs are allowed to connect */
name|struct
name|acl_list
modifier|*
name|acl
decl_stmt|;
comment|/** local authority zones */
name|struct
name|local_zones
modifier|*
name|local_zones
decl_stmt|;
comment|/** last time of statistics printout */
name|struct
name|timeval
name|time_last_stat
decl_stmt|;
comment|/** time when daemon started */
name|struct
name|timeval
name|time_boot
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Initialize daemon structure.  * @return: The daemon structure, or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|daemon
modifier|*
name|daemon_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Open shared listening ports (if needed).  * The cfg member pointer must have been set for the daemon.  * @param daemon: the daemon.  * @return: false on error.  */
end_comment

begin_function_decl
name|int
name|daemon_open_shared_ports
parameter_list|(
name|struct
name|daemon
modifier|*
name|daemon
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Fork workers and start service.  * When the routine exits, it is no longer forked.  * @param daemon: the daemon.  */
end_comment

begin_function_decl
name|void
name|daemon_fork
parameter_list|(
name|struct
name|daemon
modifier|*
name|daemon
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Close off the worker thread information.  * Bring the daemon back into state ready for daemon_fork again.  * @param daemon: the daemon.  */
end_comment

begin_function_decl
name|void
name|daemon_cleanup
parameter_list|(
name|struct
name|daemon
modifier|*
name|daemon
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete workers, close listening ports.  * @param daemon: the daemon.  */
end_comment

begin_function_decl
name|void
name|daemon_delete
parameter_list|(
name|struct
name|daemon
modifier|*
name|daemon
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Apply config settings.  * @param daemon: the daemon.  * @param cfg: new config settings.  */
end_comment

begin_function_decl
name|void
name|daemon_apply_cfg
parameter_list|(
name|struct
name|daemon
modifier|*
name|daemon
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DAEMON_H */
end_comment

end_unit

