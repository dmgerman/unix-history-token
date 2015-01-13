begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2007 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ATF_C_DETAIL_USER_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATF_C_DETAIL_USER_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_comment
comment|/* TODO: Would be nice to have an atf_user_t type and transform all of  * the functions below to methods. */
end_comment

begin_comment
comment|/* ---------------------------------------------------------------------  * Free functions.  * --------------------------------------------------------------------- */
end_comment

begin_function_decl
name|uid_t
name|atf_user_euid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_user_is_member_of_group
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_user_is_root
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atf_user_is_unprivileged
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
comment|/* !defined(ATF_C_DETAIL_USER_H) */
end_comment

end_unit

