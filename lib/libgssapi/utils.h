begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2005 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|_gss_buffer_zero
parameter_list|(
name|buffer
parameter_list|)
define|\
value|do { (buffer)->value = NULL; (buffer)->length = 0; } while(0)
end_define

begin_function_decl
specifier|extern
name|int
name|_gss_oid_equal
parameter_list|(
specifier|const
name|gss_OID
parameter_list|,
specifier|const
name|gss_OID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|OM_uint32
name|_gss_copy_oid
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
specifier|const
name|gss_OID
parameter_list|,
name|gss_OID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|OM_uint32
name|_gss_free_oid
parameter_list|(
name|OM_uint32
modifier|*
parameter_list|,
name|gss_OID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|OM_uint32
name|_gss_copy_buffer
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_buffer_t
name|from_buf
parameter_list|,
name|gss_buffer_t
name|to_buf
parameter_list|)
function_decl|;
end_function_decl

end_unit

