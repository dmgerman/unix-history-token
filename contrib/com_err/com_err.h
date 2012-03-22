begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2001 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/* MIT compatible com_err library */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__COM_ERR_H__
end_ifndef

begin_define
define|#
directive|define
name|__COM_ERR_H__
end_define

begin_include
include|#
directive|include
file|<com_right.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__attribute__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|KRB5_CALLCONV
modifier|*
name|errf
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|KRB5_LIB_FUNCTION
specifier|const
name|char
modifier|*
name|KRB5_LIB_CALL
name|error_message
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
name|int
name|KRB5_LIB_CALL
name|init_error_table
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
name|void
name|KRB5_LIB_CALL
name|com_err_va
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|KRB5_LIB_FUNCTION
name|void
name|KRB5_LIB_CALL
name|com_err
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|KRB5_LIB_FUNCTION
name|errf
name|KRB5_LIB_CALL
name|set_com_err_hook
parameter_list|(
name|errf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
name|errf
name|KRB5_LIB_CALL
name|reset_com_err_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
specifier|const
name|char
modifier|*
name|KRB5_LIB_CALL
name|error_table_name
parameter_list|(
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KRB5_LIB_FUNCTION
name|void
name|KRB5_LIB_CALL
name|add_to_error_table
parameter_list|(
name|struct
name|et_list
modifier|*
name|new_table
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __COM_ERR_H__ */
end_comment

end_unit

