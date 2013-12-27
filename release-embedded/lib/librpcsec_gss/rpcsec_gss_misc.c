begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpcsec_gss.h>
end_include

begin_include
include|#
directive|include
file|"rpcsec_gss_int.h"
end_include

begin_decl_stmt
specifier|static
name|rpc_gss_error_t
name|_rpc_gss_error
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_rpc_gss_set_error
parameter_list|(
name|int
name|rpc_gss_error
parameter_list|,
name|int
name|system_error
parameter_list|)
block|{
name|_rpc_gss_error
operator|.
name|rpc_gss_error
operator|=
name|rpc_gss_error
expr_stmt|;
name|_rpc_gss_error
operator|.
name|system_error
operator|=
name|system_error
expr_stmt|;
block|}
end_function

begin_function
name|void
name|rpc_gss_get_error
parameter_list|(
name|rpc_gss_error_t
modifier|*
name|error
parameter_list|)
block|{
operator|*
name|error
operator|=
name|_rpc_gss_error
expr_stmt|;
block|}
end_function

end_unit

