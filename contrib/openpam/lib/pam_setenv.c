begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2003 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/openpam/lib/pam_setenv.c#12 $  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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
comment|/*  * OpenPAM extension  *  * Set the value of an environment variable  * Mirrors setenv(3)  */
end_comment

begin_function
name|int
name|pam_setenv
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|int
name|overwrite
parameter_list|)
block|{
name|char
modifier|*
name|env
decl_stmt|;
name|int
name|r
decl_stmt|;
name|ENTER
argument_list|()
expr_stmt|;
if|if
condition|(
name|pamh
operator|==
name|NULL
condition|)
name|RETURNC
argument_list|(
name|PAM_SYSTEM_ERR
argument_list|)
expr_stmt|;
comment|/* sanity checks */
if|if
condition|(
name|name
operator|==
name|NULL
operator|||
name|value
operator|==
name|NULL
operator|||
name|strchr
argument_list|(
name|name
argument_list|,
literal|'='
argument_list|)
operator|!=
name|NULL
condition|)
name|RETURNC
argument_list|(
name|PAM_SYSTEM_ERR
argument_list|)
expr_stmt|;
comment|/* is it already there? */
if|if
condition|(
operator|!
name|overwrite
operator|&&
name|openpam_findenv
argument_list|(
name|pamh
argument_list|,
name|name
argument_list|,
name|strlen
argument_list|(
name|name
argument_list|)
argument_list|)
operator|>=
literal|0
condition|)
name|RETURNC
argument_list|(
name|PAM_SUCCESS
argument_list|)
expr_stmt|;
comment|/* set it... */
if|if
condition|(
name|asprintf
argument_list|(
operator|&
name|env
argument_list|,
literal|"%s=%s"
argument_list|,
name|name
argument_list|,
name|value
argument_list|)
operator|<
literal|0
condition|)
name|RETURNC
argument_list|(
name|PAM_BUF_ERR
argument_list|)
expr_stmt|;
name|r
operator|=
name|pam_putenv
argument_list|(
name|pamh
argument_list|,
name|env
argument_list|)
expr_stmt|;
name|FREE
argument_list|(
name|env
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
comment|/*  * Error codes:  *  *	=pam_putenv  *	PAM_SYSTEM_ERR  *	PAM_BUF_ERR  */
end_comment

begin_comment
comment|/**  * The =pam_setenv function sets a environment variable.  * Its semantics are similar to those of =setenv, but it modifies the PAM  * context's environment list instead of the application's.  *  *>pam_getenv  *>pam_getenvlist  *>pam_putenv  */
end_comment

end_unit

