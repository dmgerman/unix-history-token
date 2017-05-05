begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2011 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: openpam_restore_cred.c 938 2017-04-30 21:34:42Z des $  */
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
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
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

begin_include
include|#
directive|include
file|"openpam_cred.h"
end_include

begin_comment
comment|/*  * OpenPAM extension  *  * Restore credentials  */
end_comment

begin_function
name|int
name|openpam_restore_cred
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|)
block|{
specifier|const
name|struct
name|pam_saved_cred
modifier|*
name|scred
decl_stmt|;
specifier|const
name|void
modifier|*
name|scredp
decl_stmt|;
name|int
name|r
decl_stmt|;
name|ENTER
argument_list|()
expr_stmt|;
name|r
operator|=
name|pam_get_data
argument_list|(
name|pamh
argument_list|,
name|PAM_SAVED_CRED
argument_list|,
operator|&
name|scredp
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|!=
name|PAM_SUCCESS
condition|)
name|RETURNC
argument_list|(
name|r
argument_list|)
expr_stmt|;
if|if
condition|(
name|scredp
operator|==
name|NULL
condition|)
name|RETURNC
argument_list|(
name|PAM_SYSTEM_ERR
argument_list|)
expr_stmt|;
name|scred
operator|=
name|scredp
expr_stmt|;
if|if
condition|(
name|scred
operator|->
name|euid
operator|!=
name|geteuid
argument_list|()
condition|)
block|{
if|if
condition|(
name|seteuid
argument_list|(
name|scred
operator|->
name|euid
argument_list|)
operator|<
literal|0
operator|||
name|setgroups
argument_list|(
name|scred
operator|->
name|ngroups
argument_list|,
name|scred
operator|->
name|groups
argument_list|)
operator|<
literal|0
operator|||
name|setegid
argument_list|(
name|scred
operator|->
name|egid
argument_list|)
operator|<
literal|0
condition|)
name|RETURNC
argument_list|(
name|PAM_SYSTEM_ERR
argument_list|)
expr_stmt|;
block|}
name|pam_set_data
argument_list|(
name|pamh
argument_list|,
name|PAM_SAVED_CRED
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|RETURNC
argument_list|(
name|PAM_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Error codes:  *  *	=pam_get_data  *	PAM_SYSTEM_ERR  */
end_comment

begin_comment
comment|/**  * The =openpam_restore_cred function restores the credentials saved by  * =openpam_borrow_cred.  *  *>setegid 2  *>seteuid 2  *>setgroups 2  */
end_comment

end_unit

