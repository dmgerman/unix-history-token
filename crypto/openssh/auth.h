begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $OpenBSD: auth.h,v 1.7 2000/10/16 09:38:44 djm Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|AUTH_H
end_define

begin_typedef
typedef|typedef
name|struct
name|Authctxt
name|Authctxt
typedef|;
end_typedef

begin_struct
struct|struct
name|Authctxt
block|{
name|int
name|success
decl_stmt|;
name|int
name|valid
decl_stmt|;
name|int
name|attempt
decl_stmt|;
name|char
modifier|*
name|user
decl_stmt|;
name|char
modifier|*
name|service
decl_stmt|;
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|do_authentication
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_authentication2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|userauth_log
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
name|int
name|authenticated
parameter_list|,
name|char
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|userauth_reply
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
name|int
name|authenticated
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth2_skey
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|allowed_user
parameter_list|(
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|auth_get_user
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AUTH_FAIL_MAX
value|6
end_define

begin_define
define|#
directive|define
name|AUTH_FAIL_LOG
value|(AUTH_FAIL_MAX/2)
end_define

begin_define
define|#
directive|define
name|AUTH_FAIL_MSG
value|"Too many authentication failures for %.100s"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

