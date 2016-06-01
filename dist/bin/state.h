begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: state.h,v 1.5 2015/01/27 19:40:37 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2015 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STATE_H
end_ifndef

begin_define
define|#
directive|define
name|_STATE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DB_185_H
end_ifdef

begin_include
include|#
directive|include
file|<db_185.h>
end_include

begin_elif
elif|#
directive|elif
name|HAVE_DB_H
end_elif

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"no db.h"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_struct
struct|struct
name|dbinfo
block|{
name|int
name|count
decl_stmt|;
name|time_t
name|last
decl_stmt|;
name|char
name|id
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|sockaddr_storage
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|conf
struct_decl|;
end_struct_decl

begin_function_decl
name|DB
modifier|*
name|state_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|state_close
parameter_list|(
name|DB
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|state_get
parameter_list|(
name|DB
modifier|*
parameter_list|,
specifier|const
name|struct
name|conf
modifier|*
parameter_list|,
name|struct
name|dbinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|state_put
parameter_list|(
name|DB
modifier|*
parameter_list|,
specifier|const
name|struct
name|conf
modifier|*
parameter_list|,
specifier|const
name|struct
name|dbinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|state_del
parameter_list|(
name|DB
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
name|int
name|state_iterate
parameter_list|(
name|DB
modifier|*
parameter_list|,
name|struct
name|conf
modifier|*
parameter_list|,
name|struct
name|dbinfo
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|state_sync
parameter_list|(
name|DB
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
comment|/* _STATE_H */
end_comment

end_unit

