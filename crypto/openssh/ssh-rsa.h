begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: ssh-rsa.h,v 1.3 2001/01/29 01:58:18 niklas Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_RSA_H
end_ifndef

begin_define
define|#
directive|define
name|SSH_RSA_H
end_define

begin_function_decl
name|int
name|ssh_rsa_sign
parameter_list|(
name|Key
modifier|*
name|key
parameter_list|,
name|u_char
modifier|*
modifier|*
name|sigp
parameter_list|,
name|int
modifier|*
name|lenp
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|,
name|int
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_rsa_verify
parameter_list|(
name|Key
modifier|*
name|key
parameter_list|,
name|u_char
modifier|*
name|signature
parameter_list|,
name|int
name|signaturelen
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|,
name|int
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

