begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|HDLCSIZE
value|(MAX_MRU*2+6)
end_define

begin_struct
struct|struct
name|async
block|{
name|int
name|mode
decl_stmt|;
name|int
name|length
decl_stmt|;
name|u_char
name|hbuff
index|[
name|HDLCSIZE
index|]
decl_stmt|;
comment|/* recv buffer */
name|u_char
name|xbuff
index|[
name|HDLCSIZE
index|]
decl_stmt|;
comment|/* xmit buffer */
name|u_int32_t
name|my_accmap
decl_stmt|;
name|u_int32_t
name|his_accmap
decl_stmt|;
struct|struct
block|{
name|u_char
name|EscMap
index|[
literal|33
index|]
decl_stmt|;
block|}
name|cfg
struct|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|lcp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|physical
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|async_Init
parameter_list|(
name|struct
name|async
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|async_SetLinkParams
parameter_list|(
name|struct
name|async
modifier|*
parameter_list|,
name|struct
name|lcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|layer
name|asynclayer
decl_stmt|;
end_decl_stmt

end_unit

