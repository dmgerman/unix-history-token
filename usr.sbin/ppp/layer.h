begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|LAYER_ASYNC
value|2
end_define

begin_define
define|#
directive|define
name|LAYER_SYNC
value|3
end_define

begin_define
define|#
directive|define
name|LAYER_HDLC
value|4
end_define

begin_define
define|#
directive|define
name|LAYER_ACF
value|5
end_define

begin_define
define|#
directive|define
name|LAYER_PROTO
value|6
end_define

begin_define
define|#
directive|define
name|LAYER_LQR
value|7
end_define

begin_define
define|#
directive|define
name|LAYER_CCP
value|8
end_define

begin_define
define|#
directive|define
name|LAYER_VJ
value|9
end_define

begin_define
define|#
directive|define
name|LAYER_NAT
value|10
end_define

begin_define
define|#
directive|define
name|LAYER_MAX
value|10
end_define

begin_comment
comment|/* How many layers we can handle on a link */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|link
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|layer
block|{
name|int
name|type
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|push
function_decl|)
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
name|pri
parameter_list|,
name|u_short
modifier|*
name|proto
parameter_list|)
function_decl|;
name|struct
name|mbuf
modifier|*
function_decl|(
modifier|*
name|pull
function_decl|)
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

end_unit

