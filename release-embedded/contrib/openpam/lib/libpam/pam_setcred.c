begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2011 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: pam_setcred.c 648 2013-03-05 17:54:27Z des $  */
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
file|<sys/param.h>
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
comment|/*  * XSSO 4.2.1  * XSSO 6 page 57  *  * Modify / delete user credentials for an authentication service  */
end_comment

begin_function
name|int
name|pam_setcred
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|int
name|r
decl_stmt|;
name|ENTER
argument_list|()
expr_stmt|;
if|if
condition|(
name|flags
operator|&
operator|~
operator|(
name|PAM_SILENT
operator||
name|PAM_ESTABLISH_CRED
operator||
name|PAM_DELETE_CRED
operator||
name|PAM_REINITIALIZE_CRED
operator||
name|PAM_REFRESH_CRED
operator|)
condition|)
name|RETURNC
argument_list|(
name|PAM_SYMBOL_ERR
argument_list|)
expr_stmt|;
comment|/* XXX enforce exclusivity */
name|r
operator|=
name|openpam_dispatch
argument_list|(
name|pamh
argument_list|,
name|PAM_SM_SETCRED
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|RETURNC
argument_list|(
name|r
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Error codes:  *  *	=openpam_dispatch  *	=pam_sm_setcred  *	!PAM_IGNORE  *	PAM_SYMBOL_ERR  */
end_comment

begin_comment
comment|/**  * The =pam_setcred function manages the application's credentials.  *  * The =flags argument is the binary or of zero or more of the following  * values:  *  *	=PAM_SILENT:  *		Do not emit any messages.  *	=PAM_ESTABLISH_CRED:  *		Establish the credentials of the target user.  *	=PAM_DELETE_CRED:  *		Revoke all established credentials.  *	=PAM_REINITIALIZE_CRED:  *		Fully reinitialise credentials.  *	=PAM_REFRESH_CRED:  *		Refresh credentials.  *  * The latter four are mutually exclusive.  *  * If any other bits are set, =pam_setcred will return =PAM_SYMBOL_ERR.  */
end_comment

end_unit

