begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ATF_C_ERROR_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATF_C_ERROR_H
end_define

begin_include
include|#
directive|include
file|<atf-c/error_fwd.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_error" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atf_error
block|{
name|bool
name|m_free
decl_stmt|;
specifier|const
name|char
modifier|*
name|m_type
decl_stmt|;
name|void
modifier|*
name|m_data
decl_stmt|;
name|void
function_decl|(
modifier|*
name|m_format
function_decl|)
parameter_list|(
name|struct
name|atf_error
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|atf_error_t
name|atf_error_new
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|atf_error_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atf_error_free
parameter_list|(
name|atf_error_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_no_error
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_is_error
parameter_list|(
specifier|const
name|atf_error_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_error_is
parameter_list|(
specifier|const
name|atf_error_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|atf_error_data
parameter_list|(
specifier|const
name|atf_error_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atf_error_format
parameter_list|(
specifier|const
name|atf_error_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * Common error types.  * --------------------------------------------------------------------- */
end_comment

begin_function_decl
name|atf_error_t
name|atf_libc_error
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atf_libc_error_code
parameter_list|(
specifier|const
name|atf_error_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|atf_libc_error_msg
parameter_list|(
specifier|const
name|atf_error_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_no_memory_error
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
comment|/* !defined(ATF_C_ERROR_H) */
end_comment

end_unit

