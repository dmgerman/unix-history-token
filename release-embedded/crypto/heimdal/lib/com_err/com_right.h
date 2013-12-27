begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2000 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__COM_RIGHT_H__
end_ifndef

begin_define
define|#
directive|define
name|__COM_RIGHT_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KRB5_LIB
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|KRB5_LIB_FUNCTION
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|KRB5_LIB_FUNCTION
value|__declspec(dllimport)
end_define

begin_define
define|#
directive|define
name|KRB5_LIB_CALL
value|__stdcall
end_define

begin_define
define|#
directive|define
name|KRB5_LIB_VARIABLE
value|__declspec(dllimport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRB5_LIB_FUNCTION
end_define

begin_define
define|#
directive|define
name|KRB5_LIB_CALL
end_define

begin_define
define|#
directive|define
name|KRB5_LIB_VARIABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|KRB5_CALLCONV
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KRB5_CALLCONV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|error_table
block|{
name|char
specifier|const
modifier|*
specifier|const
modifier|*
name|msgs
decl_stmt|;
name|long
name|base
decl_stmt|;
name|int
name|n_msgs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_list
block|{
name|struct
name|et_list
modifier|*
name|next
decl_stmt|;
name|struct
name|error_table
modifier|*
name|table
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|et_list
modifier|*
name|_et_list
decl_stmt|;
end_decl_stmt

begin_function_decl
name|KRB5_LIB_FUNCTION
specifier|const
name|char
modifier|*
name|KRB5_LIB_CALL
name|com_right
parameter_list|(
name|struct
name|et_list
modifier|*
name|list
parameter_list|,
name|long
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
specifier|const
name|char
modifier|*
name|KRB5_LIB_CALL
name|com_right_r
parameter_list|(
name|struct
name|et_list
modifier|*
name|list
parameter_list|,
name|long
name|code
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
name|void
name|KRB5_LIB_CALL
name|initialize_error_table_r
parameter_list|(
name|struct
name|et_list
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
name|void
name|KRB5_LIB_CALL
name|free_error_table
parameter_list|(
name|struct
name|et_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __COM_RIGHT_H__ */
end_comment

end_unit

