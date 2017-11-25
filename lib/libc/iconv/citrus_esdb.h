begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_esdb.h,v 1.1 2003/06/25 09:51:32 tshiozak Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_ESDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_ESDB_H_
end_define

begin_include
include|#
directive|include
file|"citrus_types.h"
end_include

begin_struct
struct|struct
name|_citrus_esdb_charset
block|{
name|_citrus_csid_t
name|ec_csid
decl_stmt|;
name|char
modifier|*
name|ec_csname
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_citrus_esdb
block|{
name|char
modifier|*
name|db_encname
decl_stmt|;
name|void
modifier|*
name|db_variable
decl_stmt|;
name|size_t
name|db_len_variable
decl_stmt|;
name|int
name|db_num_charsets
decl_stmt|;
name|struct
name|_citrus_esdb_charset
modifier|*
name|db_charsets
decl_stmt|;
name|int
name|db_use_invalid
decl_stmt|;
name|_citrus_wc_t
name|db_invalid
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
specifier|const
name|char
modifier|*
name|_citrus_esdb_alias
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_citrus_esdb_open
parameter_list|(
name|struct
name|_citrus_esdb
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_citrus_esdb_close
parameter_list|(
name|struct
name|_citrus_esdb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_citrus_esdb_free_list
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_citrus_esdb_get_list
parameter_list|(
name|char
modifier|*
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|bool
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

end_unit

