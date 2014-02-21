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
name|KADM5_PWCHECK_H
end_ifndef

begin_define
define|#
directive|define
name|KADM5_PWCHECK_H
value|1
end_define

begin_define
define|#
directive|define
name|KADM5_PASSWD_VERSION_V0
value|0
end_define

begin_define
define|#
directive|define
name|KADM5_PASSWD_VERSION_V1
value|1
end_define

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|kadm5_passwd_quality_check_func_v0
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_principal
parameter_list|,
name|krb5_data
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The 4th argument, is a tuning parameter for the quality check  * function, the lib/caller will providing it for the password quality  * module.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|kadm5_passwd_quality_check_func
function_decl|)
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|krb5_principal
name|principal
parameter_list|,
name|krb5_data
modifier|*
name|password
parameter_list|,
specifier|const
name|char
modifier|*
name|tuning
parameter_list|,
name|char
modifier|*
name|message
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|kadm5_pw_policy_check_func
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|kadm5_passwd_quality_check_func
name|func
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kadm5_pw_policy_verifier
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|version
decl_stmt|;
specifier|const
name|char
modifier|*
name|vendor
decl_stmt|;
specifier|const
name|struct
name|kadm5_pw_policy_check_func
modifier|*
name|funcs
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KADM5_PWCHECK_H */
end_comment

end_unit

