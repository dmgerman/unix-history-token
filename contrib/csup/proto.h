begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2006, Maxime Henrion<mux@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROTO_H_
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"misc.h"
end_include

begin_define
define|#
directive|define
name|PROTO_MAJ
value|17
end_define

begin_define
define|#
directive|define
name|PROTO_MIN
value|0
end_define

begin_define
define|#
directive|define
name|PROTO_SWVER
value|"CSUP_1_0"
end_define

begin_struct_decl
struct_decl|struct
name|stream
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|proto_connect
parameter_list|(
name|struct
name|config
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_run
parameter_list|(
name|struct
name|config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_printf
parameter_list|(
name|struct
name|stream
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|proto_get_ascii
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|proto_get_rest
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_get_int
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_get_time
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PROTO_H_ */
end_comment

end_unit

