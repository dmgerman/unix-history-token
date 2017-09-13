begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Netflix, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * differnt routines to dump data.  */
end_comment

begin_function_decl
name|void
name|asciidump
parameter_list|(
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bindump
parameter_list|(
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|efi_print_load_option
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hexdump
parameter_list|(
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utf8dump
parameter_list|(
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|datalen
parameter_list|)
function_decl|;
end_function_decl

end_unit

