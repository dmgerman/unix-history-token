begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: conf.h,v 1.6 2015/01/27 19:40:36 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2015 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONF_H
end_ifndef

begin_define
define|#
directive|define
name|_CONF_H
end_define

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_struct
struct|struct
name|conf
block|{
name|struct
name|sockaddr_storage
name|c_ss
decl_stmt|;
name|int
name|c_lmask
decl_stmt|;
name|int
name|c_port
decl_stmt|;
name|int
name|c_proto
decl_stmt|;
name|int
name|c_family
decl_stmt|;
name|int
name|c_uid
decl_stmt|;
name|int
name|c_nfail
decl_stmt|;
name|char
name|c_name
index|[
literal|128
index|]
decl_stmt|;
name|int
name|c_rmask
decl_stmt|;
name|int
name|c_duration
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|confset
block|{
name|struct
name|conf
modifier|*
name|cs_c
decl_stmt|;
name|size_t
name|cs_n
decl_stmt|;
name|size_t
name|cs_m
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CONFNAMESZ
value|sizeof(((struct conf *)0)->c_name)
end_define

begin_function_decl
name|__BEGIN_DECLS
specifier|const
name|char
modifier|*
name|conf_print
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|conf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|conf_parse
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|conf
modifier|*
name|conf_find
parameter_list|(
name|int
parameter_list|,
name|uid_t
parameter_list|,
specifier|const
name|struct
name|sockaddr_storage
modifier|*
parameter_list|,
name|struct
name|conf
modifier|*
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
comment|/* _CONF_H */
end_comment

end_unit

