begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999  *      Mark Murray.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY MARK MURRAY AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL MARK MURRAY OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/* magic sizes */
end_comment

begin_define
define|#
directive|define
name|MD5_SIZE
value|16
end_define

begin_function_decl
name|char
modifier|*
name|crypt_des
parameter_list|(
specifier|const
name|char
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|salt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|crypt_md5
parameter_list|(
specifier|const
name|char
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|salt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|crypt_blowfish
parameter_list|(
specifier|const
name|char
modifier|*
name|pw
parameter_list|,
specifier|const
name|char
modifier|*
name|salt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_crypt_to64
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|unsigned
name|long
name|v
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

end_unit

