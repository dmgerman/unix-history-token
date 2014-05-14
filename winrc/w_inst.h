begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * winrc/w_inst.h - install and remove functions  *  * Copyright (c) 2009, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * Contains install and remove functions that manipulate the  * windows services API and windows registry.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINRC_W_INST_H
end_ifndef

begin_define
define|#
directive|define
name|WINRC_W_INST_H
end_define

begin_comment
comment|/**   * Install service in servicecontrolmanager, setup registry   * @param out: debug output printed here (errors). or NULL.  * @param rename: if nonNULL this executable is not unbound.exe but this name.  */
end_comment

begin_function_decl
name|void
name|wsvc_install
parameter_list|(
name|FILE
modifier|*
name|out
parameter_list|,
specifier|const
name|char
modifier|*
name|rename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Remove installed service from servicecontrolmanager, registry entries   * @param out: debug output printed here (errors). or NULL.  */
end_comment

begin_function_decl
name|void
name|wsvc_remove
parameter_list|(
name|FILE
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Start the service from servicecontrolmanager, tells OS to start daemon.  * @param out: debug output printed here (errors). or NULL.  */
end_comment

begin_function_decl
name|void
name|wsvc_rc_start
parameter_list|(
name|FILE
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Stop the service from servicecontrolmanager, tells OS to stop daemon.  * @param out: debug output printed here (errors). or NULL.  */
end_comment

begin_function_decl
name|void
name|wsvc_rc_stop
parameter_list|(
name|FILE
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Convert windows GetLastError() value to a neat string.  * @param str: destination buffer  * @param len: length of dest buffer  * @param fixed: fixed text to prepend to string.  * @param err: the GetLastError() value.  */
end_comment

begin_function_decl
name|void
name|wsvc_err2str
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|fixed
parameter_list|,
name|DWORD
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINRC_W_INST_H */
end_comment

end_unit

