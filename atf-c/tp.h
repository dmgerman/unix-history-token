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
name|ATF_C_TP_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATF_C_TP_H
end_define

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<atf-c/error_fwd.h>
end_include

begin_struct_decl
struct_decl|struct
name|atf_tc
struct_decl|;
end_struct_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * The "atf_tp" type.  * --------------------------------------------------------------------- */
end_comment

begin_struct_decl
struct_decl|struct
name|atf_tp_impl
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|atf_tp
block|{
name|struct
name|atf_tp_impl
modifier|*
name|pimpl
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atf_tp
name|atf_tp_t
typedef|;
end_typedef

begin_comment
comment|/* Constructors/destructors. */
end_comment

begin_function_decl
name|atf_error_t
name|atf_tp_init
parameter_list|(
name|atf_tp_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atf_tp_fini
parameter_list|(
name|atf_tp_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Getters. */
end_comment

begin_function_decl
name|char
modifier|*
modifier|*
name|atf_tp_get_config
parameter_list|(
specifier|const
name|atf_tp_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_tp_has_tc
parameter_list|(
specifier|const
name|atf_tp_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|atf_tc
modifier|*
name|atf_tp_get_tc
parameter_list|(
specifier|const
name|atf_tp_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|atf_tc
modifier|*
specifier|const
modifier|*
name|atf_tp_get_tcs
parameter_list|(
specifier|const
name|atf_tp_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Modifiers. */
end_comment

begin_function_decl
name|atf_error_t
name|atf_tp_add_tc
parameter_list|(
name|atf_tp_t
modifier|*
parameter_list|,
name|struct
name|atf_tc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ---------------------------------------------------------------------  * Free functions.  * --------------------------------------------------------------------- */
end_comment

begin_function_decl
name|atf_error_t
name|atf_tp_run
parameter_list|(
specifier|const
name|atf_tp_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|atf_error_t
name|atf_tp_cleanup
parameter_list|(
specifier|const
name|atf_tp_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(ATF_C_TP_H) */
end_comment

end_unit

