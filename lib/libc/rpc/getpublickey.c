begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 John D. Polstra  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  */
end_comment

begin_comment
comment|/*  * Stub version of getpublickey(), which is referenced in auth_des.c  * and svc_auth_des.c.  This stub always fails.  It is necessary to  * avoid any references to undefined symbols from libc.  */
end_comment

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_include
include|#
directive|include
file|<rpc/xdr.h>
end_include

begin_include
include|#
directive|include
file|<rpc/auth.h>
end_include

begin_function
name|int
name|getpublickey
parameter_list|(
name|servername
parameter_list|,
name|pkey_data
parameter_list|)
name|char
modifier|*
name|servername
decl_stmt|;
name|char
modifier|*
name|pkey_data
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

