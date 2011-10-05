begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__pop_auth_h__
end_ifndef

begin_define
define|#
directive|define
name|__pop_auth_h__
end_define

begin_struct
struct|struct
name|auth_mech
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|POP
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|loop
function_decl|)
parameter_list|(
name|POP
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|POP
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|POP_AUTH_CONTINUE
value|0
end_define

begin_define
define|#
directive|define
name|POP_AUTH_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|POP_AUTH_COMPLETE
value|2
end_define

begin_function_decl
name|void
name|pop_auth_set_error
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|auth_mech
name|gssapi_mech
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|auth_mech
name|krb4_mech
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __pop_auth_h__ */
end_comment

end_unit

