begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * winrc/win_svc.h - windows services API implementation for unbound  *  * Copyright (c) 2009, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to integrate with the windows services API.  * This means it handles the commandline switches to install and remove  * the service (via CreateService and DeleteService), it handles  * the ServiceMain() main service entry point when started as a service,  * and it handles the Handler[_ex]() to process requests to the service  * (such as start and stop and status).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINRC_WIN_SVC_H
end_ifndef

begin_define
define|#
directive|define
name|WINRC_WIN_SVC_H
end_define

begin_struct_decl
struct_decl|struct
name|worker
struct_decl|;
end_struct_decl

begin_comment
comment|/** service name for unbound (internal to ServiceManager) */
end_comment

begin_define
define|#
directive|define
name|SERVICE_NAME
value|"unbound"
end_define

begin_comment
comment|/** from gen_msg.h - success message record for windows message log */
end_comment

begin_define
define|#
directive|define
name|MSG_GENERIC_SUCCESS
value|((DWORD)0x20010001L)
end_define

begin_comment
comment|/** from gen_msg.h - informational message record for windows message log */
end_comment

begin_define
define|#
directive|define
name|MSG_GENERIC_INFO
value|((DWORD)0x60010002L)
end_define

begin_comment
comment|/** from gen_msg.h - warning message record for windows message log */
end_comment

begin_define
define|#
directive|define
name|MSG_GENERIC_WARN
value|((DWORD)0xA0010003L)
end_define

begin_comment
comment|/** from gen_msg.h - error message record for windows message log */
end_comment

begin_define
define|#
directive|define
name|MSG_GENERIC_ERR
value|((DWORD)0xE0010004L)
end_define

begin_comment
comment|/**  * Handle commandline service for windows.  * @param wopt: windows option string (install, remove, service).   * @param cfgfile: configfile to open (default or passed with -c).  * @param v: amount of commandline verbosity added with -v.  * @param c: true if cfgfile was set by commandline -c option.  */
end_comment

begin_function_decl
name|void
name|wsvc_command_option
parameter_list|(
specifier|const
name|char
modifier|*
name|wopt
parameter_list|,
specifier|const
name|char
modifier|*
name|cfgfile
parameter_list|,
name|int
name|v
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Setup lead worker events.  * @param worker: the worker  */
end_comment

begin_function_decl
name|void
name|wsvc_setup_worker
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Desetup lead worker events.  * @param worker: the worker  */
end_comment

begin_function_decl
name|void
name|wsvc_desetup_worker
parameter_list|(
name|struct
name|worker
modifier|*
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** windows worker stop event callback handler */
end_comment

begin_function_decl
name|void
name|worker_win_stop_cb
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|ev
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** windows cron timer callback handler */
end_comment

begin_function_decl
name|void
name|wsvc_cron_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINRC_WIN_SVC_H */
end_comment

end_unit

