begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: dispatch.h,v 1.9 2002/01/11 13:39:36 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_enum
enum|enum
block|{
name|DISPATCH_BLOCK
block|,
name|DISPATCH_NONBLOCK
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|void
name|dispatch_fn
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|dispatch_init
parameter_list|(
name|dispatch_fn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dispatch_set
parameter_list|(
name|int
parameter_list|,
name|dispatch_fn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dispatch_range
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|dispatch_fn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dispatch_run
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dispatch_protocol_error
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dispatch_protocol_ignore
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

