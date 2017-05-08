begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2011 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: openpam_nullconv.c 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_include
include|#
directive|include
file|"openpam_impl.h"
end_include

begin_comment
comment|/*  * OpenPAM extension  *  * Null conversation function  */
end_comment

begin_function
name|int
name|openpam_nullconv
parameter_list|(
name|int
name|n
parameter_list|,
specifier|const
name|struct
name|pam_message
modifier|*
modifier|*
name|msg
parameter_list|,
name|struct
name|pam_response
modifier|*
modifier|*
name|resp
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|ENTER
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|n
expr_stmt|;
operator|(
name|void
operator|)
name|msg
expr_stmt|;
operator|(
name|void
operator|)
name|resp
expr_stmt|;
operator|(
name|void
operator|)
name|data
expr_stmt|;
name|RETURNC
argument_list|(
name|PAM_CONV_ERR
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Error codes:  *  *	PAM_CONV_ERR  */
end_comment

begin_comment
comment|/**  * The =openpam_nullconv function is a null conversation function suitable  * for applications that want to use PAM but don't support interactive  * dialog with the user.  * Such applications should set =PAM_AUTHTOK to whatever authentication  * token they've obtained on their own before calling =pam_authenticate  * and / or =pam_chauthtok, and their PAM configuration should specify the  * ;use_first_pass option for all modules that require access to the  * authentication token, to make sure they use =PAM_AUTHTOK rather than  * try to query the user.  *  *>openpam_ttyconv  *>pam_prompt  *>pam_set_item  *>pam_vprompt  */
end_comment

end_unit

