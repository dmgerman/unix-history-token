begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2010 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_BUILD
end_ifndef

begin_error
error|#
directive|error
error|This header is only to be used internally to libarchive.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_ACL_PRIVATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_ACL_PRIVATE_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|"archive_string.h"
end_include

begin_struct
struct|struct
name|archive_acl_entry
block|{
name|struct
name|archive_acl_entry
modifier|*
name|next
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* E.g., access or default */
name|int
name|tag
decl_stmt|;
comment|/* E.g., user/group/other/mask */
name|int
name|permset
decl_stmt|;
comment|/* r/w/x bits */
name|int
name|id
decl_stmt|;
comment|/* uid/gid for user/group */
name|struct
name|archive_mstring
name|name
decl_stmt|;
comment|/* uname/gname */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|archive_acl
block|{
name|mode_t
name|mode
decl_stmt|;
name|struct
name|archive_acl_entry
modifier|*
name|acl_head
decl_stmt|;
name|struct
name|archive_acl_entry
modifier|*
name|acl_p
decl_stmt|;
name|int
name|acl_state
decl_stmt|;
comment|/* See acl_next for details. */
name|wchar_t
modifier|*
name|acl_text_w
decl_stmt|;
name|char
modifier|*
name|acl_text
decl_stmt|;
name|int
name|acl_types
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|archive_acl_clear
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive_acl_copy
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|,
name|struct
name|archive_acl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_acl_count
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_acl_reset
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_acl_next
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_acl
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_acl_add_entry
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_acl_add_entry_w_len
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_acl_add_entry_len
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|wchar_t
modifier|*
name|archive_acl_text_w
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|struct
name|archive_acl
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_acl_text_l
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|struct
name|archive_string_conv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Private ACL parser.  This is private because it handles some  * very weird formats that clients should not be messing with.  * Clients should only deal with their platform-native formats.  * Because of the need to support many formats cleanly, new arguments  * are likely to get added on a regular basis.  Clients who try to use  * this interface are likely to be surprised when it changes.  */
end_comment

begin_function_decl
name|int
name|archive_acl_parse_w
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|int
comment|/* type */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|archive_acl_parse_l
parameter_list|(
name|struct
name|archive_acl
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
comment|/* type */
parameter_list|,
name|struct
name|archive_string_conv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARCHIVE_ENTRY_PRIVATE_H_INCLUDED */
end_comment

end_unit

