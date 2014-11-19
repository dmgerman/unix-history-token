begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Arthur Mesh<arthurmesh@gmail.com>  * Copyright (c) 2013 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_RANDOM_LIVE_ENTROPY_SOURCES_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_RANDOM_LIVE_ENTROPY_SOURCES_H_INCLUDED
end_define

begin_typedef
typedef|typedef
name|u_int
name|random_live_read_func_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Live entropy source is a source of entropy that can provide  * specified or approximate amount of entropy immediately upon request or within  * an acceptable amount of time.  */
end_comment

begin_struct
struct|struct
name|live_entropy_source
block|{
specifier|const
name|char
modifier|*
name|les_ident
decl_stmt|;
name|enum
name|random_entropy_source
name|les_source
decl_stmt|;
name|random_live_read_func_t
modifier|*
name|les_read
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|live_entropy_sources
block|{
name|LIST_ENTRY
argument_list|(
argument|live_entropy_sources
argument_list|)
name|lles_entries
expr_stmt|;
comment|/* list of providers */
name|struct
name|live_entropy_source
modifier|*
name|lles_rsource
decl_stmt|;
comment|/* associated random adaptor */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|live_mtx
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|live_entropy_sources_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|live_entropy_sources_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|live_entropy_source_register
parameter_list|(
name|struct
name|live_entropy_source
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|live_entropy_source_deregister
parameter_list|(
name|struct
name|live_entropy_source
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|live_entropy_sources_feed
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
comment|/* SYS_DEV_RANDOM_LIVE_ENTROPY_SOURCES_H_INCLUDED */
end_comment

end_unit

