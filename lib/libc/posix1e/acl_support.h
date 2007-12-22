begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000, 2001 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Support functionality for the POSIX.1e ACL interface  * These calls are intended only to be called within the library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACL_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|_ACL_SUPPORT_H
end_define

begin_define
define|#
directive|define
name|_POSIX1E_ACL_STRING_PERM_MAXSIZE
value|3
end_define

begin_comment
comment|/* read, write, exec */
end_comment

begin_function_decl
name|int
name|_posix1e_acl_check
parameter_list|(
name|acl_t
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_posix1e_acl_sort
parameter_list|(
name|acl_t
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_posix1e_acl
parameter_list|(
name|acl_t
name|acl
parameter_list|,
name|acl_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_posix1e_acl_id_to_name
parameter_list|(
name|acl_tag_t
name|tag
parameter_list|,
name|uid_t
name|id
parameter_list|,
name|ssize_t
name|buf_len
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_posix1e_acl_perm_to_string
parameter_list|(
name|acl_perm_t
name|perm
parameter_list|,
name|ssize_t
name|buf_len
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_posix1e_acl_string_to_perm
parameter_list|(
name|char
modifier|*
name|string
parameter_list|,
name|acl_perm_t
modifier|*
name|perm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_posix1e_acl_add_entry
parameter_list|(
name|acl_t
name|acl
parameter_list|,
name|acl_tag_t
name|tag
parameter_list|,
name|uid_t
name|id
parameter_list|,
name|acl_perm_t
name|perm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

