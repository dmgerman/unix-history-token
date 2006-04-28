begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Michael Bushkov<bushman@rsu.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CACHED_SINGLETONS_H__
end_ifndef

begin_define
define|#
directive|define
name|__CACHED_SINGLETONS_H__
end_define

begin_include
include|#
directive|include
file|"cachelib.h"
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"agent.h"
end_include

begin_struct
struct|struct
name|runtime_env
block|{
name|int
name|queue
decl_stmt|;
name|int
name|sockfd
decl_stmt|;
name|int
name|finished
decl_stmt|;
comment|/* for future use */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|configuration
modifier|*
name|s_configuration
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cache
name|s_cache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|runtime_env
modifier|*
name|s_runtime_env
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|agent_table
modifier|*
name|s_agent_table
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

