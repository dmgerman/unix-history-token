begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Dima Dorfman.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEVFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEVFS_H__
end_define

begin_include
include|#
directive|include
file|<fs/devfs/devfs.h>
end_include

begin_struct
struct|struct
name|intstr
block|{
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
name|command_t
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|cmd
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|command_t
modifier|*
name|handler
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cmd
name|ctbl_t
index|[]
typedef|;
end_typedef

begin_decl_stmt
name|command_t
name|rule_main
decl_stmt|,
name|ruleset_main
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|atonum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eatoi
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|eatonum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|efgetln
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tokenize
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|usage
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mpfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mount-point file descriptor. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__DEVFS_H__ */
end_comment

end_unit

