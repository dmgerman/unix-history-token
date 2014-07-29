begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * daemon/remote.h - remote control for the unbound daemon.  *  * Copyright (c) 2008, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains the remote control functionality for the daemon.  * The remote control can be performed using either the commandline  * unbound-control tool, or a SSLv3/TLS capable web browser.   * The channel is secured using SSLv3 or TLSv1, and certificates.  * Both the server and the client(control tool) have their own keys.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DAEMON_REMOTE_H
end_ifndef

begin_define
define|#
directive|define
name|DAEMON_REMOTE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OPENSSL_SSL_H
end_ifdef

begin_include
include|#
directive|include
file|"openssl/ssl.h"
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
name|listen_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|listen_port
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|worker
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_reply
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|comm_point
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|daemon_remote
struct_decl|;
end_struct_decl

begin_comment
comment|/** number of seconds timeout on incoming remote control handshake */
end_comment

begin_define
define|#
directive|define
name|REMOTE_CONTROL_TCP_TIMEOUT
value|120
end_define

begin_comment
comment|/**  * a busy control command connection, SSL state  */
end_comment

begin_struct
struct|struct
name|rc_state
block|{
comment|/** the next item in list */
name|struct
name|rc_state
modifier|*
name|next
decl_stmt|;
comment|/** the commpoint */
name|struct
name|comm_point
modifier|*
name|c
decl_stmt|;
comment|/** in the handshake part */
enum|enum
block|{
name|rc_none
block|,
name|rc_hs_read
block|,
name|rc_hs_write
block|}
name|shake_state
enum|;
ifdef|#
directive|ifdef
name|HAVE_SSL
comment|/** the ssl state */
name|SSL
modifier|*
name|ssl
decl_stmt|;
endif|#
directive|endif
comment|/** the rc this is part of */
name|struct
name|daemon_remote
modifier|*
name|rc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * The remote control tool state.  * The state is only created for the first thread, other threads  * are called from this thread.  Only the first threads listens to  * the control port.  The other threads do not, but are called on the  * command channel(pipe) from the first thread.  */
end_comment

begin_struct
struct|struct
name|daemon_remote
block|{
comment|/** the worker for this remote control */
name|struct
name|worker
modifier|*
name|worker
decl_stmt|;
comment|/** commpoints for accepting remote control connections */
name|struct
name|listen_list
modifier|*
name|accept_list
decl_stmt|;
comment|/** number of active commpoints that are handling remote control */
name|int
name|active
decl_stmt|;
comment|/** max active commpoints */
name|int
name|max_active
decl_stmt|;
comment|/** current commpoints busy; should be a short list, malloced */
name|struct
name|rc_state
modifier|*
name|busy_list
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_SSL
comment|/** the SSL context for creating new SSL streams */
name|SSL_CTX
modifier|*
name|ctx
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create new remote control state for the daemon.  * @param cfg: config file with key file settings.  * @return new state, or NULL on failure.  */
end_comment

begin_function_decl
name|struct
name|daemon_remote
modifier|*
name|daemon_remote_create
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * remote control state to delete.  * @param rc: state to delete.  */
end_comment

begin_function_decl
name|void
name|daemon_remote_delete
parameter_list|(
name|struct
name|daemon_remote
modifier|*
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * remote control state to clear up. Busy and accept points are closed.  * Does not delete the rc itself, or the ssl context (with its keys).  * @param rc: state to clear.  */
end_comment

begin_function_decl
name|void
name|daemon_remote_clear
parameter_list|(
name|struct
name|daemon_remote
modifier|*
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Open and create listening ports for remote control.  * @param cfg: config options.  * @return list of ports or NULL on failure.  *	can be freed with listening_ports_free().  */
end_comment

begin_function_decl
name|struct
name|listen_port
modifier|*
name|daemon_remote_open_ports
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Setup comm points for accepting remote control connections.  * @param rc: state  * @param ports: already opened ports.  * @param worker: worker with communication base. and links to command channels.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|daemon_remote_open_accept
parameter_list|(
name|struct
name|daemon_remote
modifier|*
name|rc
parameter_list|,
name|struct
name|listen_port
modifier|*
name|ports
parameter_list|,
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Stop accept handlers for TCP (until enabled again)  * @param rc: state  */
end_comment

begin_function_decl
name|void
name|daemon_remote_stop_accept
parameter_list|(
name|struct
name|daemon_remote
modifier|*
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Stop accept handlers for TCP (until enabled again)  * @param rc: state  */
end_comment

begin_function_decl
name|void
name|daemon_remote_start_accept
parameter_list|(
name|struct
name|daemon_remote
modifier|*
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Handle nonthreaded remote cmd execution.  * @param worker: this worker (the remote worker).  */
end_comment

begin_function_decl
name|void
name|daemon_remote_exec
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SSL
end_ifdef

begin_comment
comment|/**   * Print fixed line of text over ssl connection in blocking mode  * @param ssl: print to  * @param text: the text.  * @return false on connection failure.  */
end_comment

begin_function_decl
name|int
name|ssl_print_text
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * printf style printing to the ssl connection  * @param ssl: the SSL connection to print to. Blocking.  * @param format: printf style format string.  * @return success or false on a network failure.  */
end_comment

begin_function_decl
name|int
name|ssl_printf
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Read until \n is encountered  * If SSL signals EOF, the string up to then is returned (without \n).  * @param ssl: the SSL connection to read from. blocking.  * @param buf: buffer to read to.  * @param max: size of buffer.  * @return false on connection failure.  */
end_comment

begin_function_decl
name|int
name|ssl_read_line
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SSL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DAEMON_REMOTE_H */
end_comment

end_unit

