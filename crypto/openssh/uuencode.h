begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: uuencode.h,v 1.5 2001/01/29 01:58:19 niklas Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1999 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UUENCODE_H
end_ifndef

begin_define
define|#
directive|define
name|UUENCODE_H
end_define

begin_function_decl
name|int
name|uuencode
parameter_list|(
name|u_char
modifier|*
name|src
parameter_list|,
name|u_int
name|srclength
parameter_list|,
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uudecode
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|u_char
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_base64
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

