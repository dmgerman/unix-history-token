begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: mac.h,v 1.10 2016/07/08 03:44:42 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSHMAC_H
end_ifndef

begin_define
define|#
directive|define
name|SSHMAC_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct
struct|struct
name|sshmac
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|enabled
decl_stmt|;
name|u_int
name|mac_len
decl_stmt|;
name|u_char
modifier|*
name|key
decl_stmt|;
name|u_int
name|key_len
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|etm
decl_stmt|;
comment|/* Encrypt-then-MAC */
name|struct
name|ssh_hmac_ctx
modifier|*
name|hmac_ctx
decl_stmt|;
name|struct
name|umac_ctx
modifier|*
name|umac_ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|mac_valid
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mac_alg_list
parameter_list|(
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_setup
parameter_list|(
name|struct
name|sshmac
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_init
parameter_list|(
name|struct
name|sshmac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_compute
parameter_list|(
name|struct
name|sshmac
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_check
parameter_list|(
name|struct
name|sshmac
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_clear
parameter_list|(
name|struct
name|sshmac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SSHMAC_H */
end_comment

end_unit

