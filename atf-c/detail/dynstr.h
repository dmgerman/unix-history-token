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
name|ATF_C_DETAIL_DYNSTR_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATF_C_DETAIL_DYNSTR_H
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
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

begin_include
include|#
directive|include
file|<atf-c/error_fwd.h>
end_include

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_dynstr" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|atf_dynstr
block|{
name|char
modifier|*
name|m_data
decl_stmt|;
name|size_t
name|m_datasize
decl_stmt|;
name|size_t
name|m_length
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_dynstr
name|atf_dynstr_t
typedef|;
end_typedef

begin_comment
comment|/* Constants */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|atf_dynstr_npos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Constructors and destructors */
end_comment

begin_function_decl
name|atf_error_t
name|atf_dynstr_init
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_dynstr_init_ap
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_dynstr_init_fmt
parameter_list|(
name|atf_dynstr_t
modifier|*
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
name|atf_error_t
name|atf_dynstr_init_raw
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_dynstr_init_rep
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_dynstr_init_substr
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|,
specifier|const
name|atf_dynstr_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_dynstr_copy
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|,
specifier|const
name|atf_dynstr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atf_dynstr_fini
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|atf_dynstr_fini_disown
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Getters */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|atf_dynstr_cstring
parameter_list|(
specifier|const
name|atf_dynstr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|atf_dynstr_length
parameter_list|(
specifier|const
name|atf_dynstr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|atf_dynstr_rfind_ch
parameter_list|(
specifier|const
name|atf_dynstr_t
modifier|*
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Modifiers */
end_comment

begin_function_decl
name|atf_error_t
name|atf_dynstr_append_ap
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_dynstr_append_fmt
parameter_list|(
name|atf_dynstr_t
modifier|*
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
name|void
name|atf_dynstr_clear
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_dynstr_prepend_ap
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_dynstr_prepend_fmt
parameter_list|(
name|atf_dynstr_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Operators */
end_comment

begin_function_decl
name|bool
name|atf_equal_dynstr_cstring
parameter_list|(
specifier|const
name|atf_dynstr_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_equal_dynstr_dynstr
parameter_list|(
specifier|const
name|atf_dynstr_t
modifier|*
parameter_list|,
specifier|const
name|atf_dynstr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(ATF_C_DETAIL_DYNSTR_H) */
end_comment

end_unit

