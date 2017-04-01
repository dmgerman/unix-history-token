begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Eric McCorkle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INTAKE_H_
end_ifndef

begin_define
define|#
directive|define
name|_INTAKE_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  * This file provides an interface for providing keys to the kernel  * during boot time.  */
end_comment

begin_define
define|#
directive|define
name|MAX_KEY_BITS
value|4096
end_define

begin_define
define|#
directive|define
name|MAX_KEY_BYTES
value|(MAX_KEY_BITS / NBBY)
end_define

begin_define
define|#
directive|define
name|KEYBUF_SENTINEL
value|0xcee54b5d
end_define

begin_comment
comment|/* KEYS4BSD */
end_comment

begin_enum
enum|enum
block|{
name|KEYBUF_TYPE_NONE
block|,
name|KEYBUF_TYPE_GELI
block|}
enum|;
end_enum

begin_struct
struct|struct
name|keybuf_ent
block|{
name|unsigned
name|int
name|ke_type
decl_stmt|;
name|char
name|ke_data
index|[
name|MAX_KEY_BYTES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|keybuf
block|{
name|unsigned
name|int
name|kb_nents
decl_stmt|;
name|struct
name|keybuf_ent
name|kb_ents
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Get the key intake buffer */
end_comment

begin_function_decl
specifier|extern
name|struct
name|keybuf
modifier|*
name|get_keybuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

