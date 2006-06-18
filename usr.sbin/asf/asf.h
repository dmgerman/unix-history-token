begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 The FreeBSD Project  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|KERNFILE
value|"kernel"
end_define

begin_define
define|#
directive|define
name|KLDSUFFIX
value|".ko"
end_define

begin_define
define|#
directive|define
name|MAXTOKEN
value|10
end_define

begin_function_decl
name|int
name|tokenize
parameter_list|(
name|char
modifier|*
name|cptr
parameter_list|,
name|char
modifier|*
name|token
index|[]
parameter_list|,
name|int
name|maxtoken
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kfile_add
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|caddr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|asf_kld
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|asf_kvm
parameter_list|(
specifier|const
name|char
modifier|*
name|kernfile
parameter_list|,
specifier|const
name|char
modifier|*
name|corefile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|asf_prog
parameter_list|(
name|int
name|run
parameter_list|)
function_decl|;
end_function_decl

end_unit

