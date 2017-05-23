begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: bl.h,v 1.13 2016/03/11 17:16:40 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2014 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BL_H
end_ifndef

begin_define
define|#
directive|define
name|_BL_H
end_define

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|"blacklist.h"
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|BL_INVALID
block|,
name|BL_ADD
block|,
name|BL_DELETE
block|,
name|BL_ABUSE
block|,
name|BL_BADUSER
block|}
name|bl_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bl_type_t
name|bi_type
decl_stmt|;
name|int
name|bi_fd
decl_stmt|;
name|uid_t
name|bi_uid
decl_stmt|;
name|gid_t
name|bi_gid
decl_stmt|;
name|socklen_t
name|bi_slen
decl_stmt|;
name|struct
name|sockaddr_storage
name|bi_ss
decl_stmt|;
name|char
name|bi_msg
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|bl_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|bi_cred
value|bi_u._bi_cred
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BLSOCK
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BLSOCK
value|"/var/run/blacklistd.sock"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
name|struct
name|blacklist
modifier|*
name|bl_t
typedef|;
end_typedef

begin_function_decl
name|bl_t
name|bl_create
parameter_list|(
name|bool
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bl_destroy
parameter_list|(
name|bl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bl_send
parameter_list|(
name|bl_t
parameter_list|,
name|bl_type_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|socklen_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bl_getfd
parameter_list|(
name|bl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bl_info_t
modifier|*
name|bl_recv
parameter_list|(
name|bl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bl_isconnected
parameter_list|(
name|bl_t
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BL_H */
end_comment

end_unit

