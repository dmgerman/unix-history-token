begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997, 1998 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: sl.h,v 1.7 1999/12/02 16:58:55 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SL_H
end_ifndef

begin_define
define|#
directive|define
name|_SL_H
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|cmd_func
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|sl_cmd
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|cmd_func
name|func
decl_stmt|;
name|char
modifier|*
name|usage
decl_stmt|;
name|char
modifier|*
name|help
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sl_cmd
name|SL_cmd
typedef|;
end_typedef

begin_function_decl
name|void
name|sl_help
parameter_list|(
name|SL_cmd
modifier|*
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sl_loop
parameter_list|(
name|SL_cmd
modifier|*
parameter_list|,
name|char
modifier|*
name|prompt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sl_command_loop
parameter_list|(
name|SL_cmd
modifier|*
name|cmds
parameter_list|,
name|char
modifier|*
name|prompt
parameter_list|,
name|void
modifier|*
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sl_command
parameter_list|(
name|SL_cmd
modifier|*
name|cmds
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sl_make_argv
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SL_H */
end_comment

end_unit

