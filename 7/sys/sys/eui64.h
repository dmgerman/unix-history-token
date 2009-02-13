begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2004 The Aerospace Corporation.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions, and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions, and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  The name of The Aerospace Corporation may not be used to endorse or  *     promote products derived from this software.  *  * THIS SOFTWARE IS PROVIDED BY THE AEROSPACE CORPORATION "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AEROSPACE CORPORATION BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EUI64_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EUI64_H
end_define

begin_comment
comment|/*  * Size of the ASCII representation of an EUI-64.  */
end_comment

begin_define
define|#
directive|define
name|EUI64_SIZ
value|24
end_define

begin_comment
comment|/*  * The number of bytes in an EUI-64.  */
end_comment

begin_define
define|#
directive|define
name|EUI64_LEN
value|8
end_define

begin_comment
comment|/*  * Structure of an IEEE EUI-64.  */
end_comment

begin_struct
struct|struct
name|eui64
block|{
name|u_char
name|octet
index|[
name|EUI64_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|int
name|eui64_aton
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|eui64
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eui64_ntoa
parameter_list|(
specifier|const
name|struct
name|eui64
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
name|eui64_ntohost
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|struct
name|eui64
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eui64_hostton
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|eui64
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_EUI64_H */
end_comment

end_unit

