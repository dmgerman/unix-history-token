begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD: src/lib/libgssapi/context.h,v 1.1 2005/12/29 14:40:20 dfr Exp $  *	$Id$  */
end_comment

begin_include
include|#
directive|include
file|<gssapi_mech.h>
end_include

begin_struct
struct|struct
name|_gss_context
block|{
name|gssapi_mech_interface
name|gc_mech
decl_stmt|;
name|gss_ctx_id_t
name|gc_ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|_gss_mg_error
parameter_list|(
name|gssapi_mech_interface
parameter_list|,
name|OM_uint32
parameter_list|,
name|OM_uint32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|_gss_mg_get_error
parameter_list|(
specifier|const
name|gss_OID
parameter_list|,
name|OM_uint32
parameter_list|,
name|OM_uint32
parameter_list|,
name|gss_buffer_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

