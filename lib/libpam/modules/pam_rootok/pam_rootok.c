begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2001 Mark R V Murray  * All rights reserved.  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * Portions of this software were developed for the FreeBSD Project by  * ThinkSec AS and NAI Labs, the Security Research Division of Network  * Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|_BSD_SOURCE
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_define
define|#
directive|define
name|PAM_SM_AUTH
end_define

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_modules.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_mod_misc.h>
end_include

begin_function
name|PAM_EXTERN
name|int
name|pam_sm_authenticate
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
name|__unused
parameter_list|,
name|int
name|argc
name|__unused
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
name|__unused
parameter_list|)
block|{
if|if
condition|(
name|getuid
argument_list|()
operator|==
literal|0
condition|)
return|return
operator|(
name|PAM_SUCCESS
operator|)
return|;
name|PAM_VERBOSE_ERROR
argument_list|(
literal|"Refused; not superuser"
argument_list|)
expr_stmt|;
name|PAM_LOG
argument_list|(
literal|"User is not superuser"
argument_list|)
expr_stmt|;
return|return
operator|(
name|PAM_AUTH_ERR
operator|)
return|;
block|}
end_function

begin_function
name|PAM_EXTERN
name|int
name|pam_sm_setcred
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
name|__unused
parameter_list|,
name|int
name|flags
name|__unused
parameter_list|,
name|int
name|argc
name|__unused
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
name|__unused
parameter_list|)
block|{
return|return
operator|(
name|PAM_SUCCESS
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|PAM_MODULE_ENTRY
argument_list|(
literal|"pam_rootok"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

