begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: auth-pam.h,v 1.16 2002/07/23 00:44:07 stevesk Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Damien Miller.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PAM
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SSHD_PAM_SERVICE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SSHD_PAM_SERVICE
value|__progname
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|start_pam
parameter_list|(
specifier|const
name|char
modifier|*
name|user
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finish_pam
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_pam_password
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|,
specifier|const
name|char
modifier|*
name|password
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|fetch_pam_environment
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_pam_environment
parameter_list|(
name|char
modifier|*
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_pam_authenticate
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_pam_account
parameter_list|(
name|char
modifier|*
name|username
parameter_list|,
name|char
modifier|*
name|remote_user
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_pam_session
parameter_list|(
name|char
modifier|*
name|username
parameter_list|,
specifier|const
name|char
modifier|*
name|ttyname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_pam_setcred
parameter_list|(
name|int
name|init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_pam_messages
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_pam_password_change_required
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_pam_chauthtok
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_pam_set_conv
parameter_list|(
name|struct
name|pam_conv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|message_cat
parameter_list|(
name|char
modifier|*
modifier|*
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_PAM */
end_comment

end_unit

