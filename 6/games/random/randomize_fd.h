begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2003 Sean Chittenden<seanc@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RANDOMIZE_FD__
end_ifndef

begin_define
define|#
directive|define
name|__RANDOMIZE_FD__
end_define

begin_define
define|#
directive|define
name|RANDOM_TYPE_UNSET
value|0
end_define

begin_define
define|#
directive|define
name|RANDOM_TYPE_LINES
value|1
end_define

begin_define
define|#
directive|define
name|RANDOM_TYPE_WORDS
value|2
end_define

begin_comment
comment|/* The multiple instance single integer key */
end_comment

begin_struct
struct|struct
name|rand_node
block|{
name|u_char
modifier|*
name|cp
decl_stmt|;
name|u_int
name|len
decl_stmt|;
name|struct
name|rand_node
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|randomize_fd
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|unique
parameter_list|,
name|double
name|denom
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

