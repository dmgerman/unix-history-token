begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/openpam/lib/pam_strerror.c#9 $  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
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
comment|/*  * XSSO 4.2.1  * XSSO 6 page 92  *  * Get PAM standard error message string  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|pam_strerror
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|error_number
parameter_list|)
block|{
specifier|static
name|char
name|unknown
index|[
literal|16
index|]
decl_stmt|;
name|pamh
operator|=
name|pamh
expr_stmt|;
switch|switch
condition|(
name|error_number
condition|)
block|{
case|case
name|PAM_SUCCESS
case|:
return|return
operator|(
literal|"success"
operator|)
return|;
case|case
name|PAM_OPEN_ERR
case|:
return|return
operator|(
literal|"failed to load module"
operator|)
return|;
case|case
name|PAM_SYMBOL_ERR
case|:
return|return
operator|(
literal|"invalid symbol"
operator|)
return|;
case|case
name|PAM_SERVICE_ERR
case|:
return|return
operator|(
literal|"error in service module"
operator|)
return|;
case|case
name|PAM_SYSTEM_ERR
case|:
return|return
operator|(
literal|"system error"
operator|)
return|;
case|case
name|PAM_BUF_ERR
case|:
return|return
operator|(
literal|"memory buffer error"
operator|)
return|;
case|case
name|PAM_CONV_ERR
case|:
return|return
operator|(
literal|"conversation failure"
operator|)
return|;
case|case
name|PAM_PERM_DENIED
case|:
return|return
operator|(
literal|"permission denied"
operator|)
return|;
case|case
name|PAM_MAXTRIES
case|:
return|return
operator|(
literal|"maximum number of tries exceeded"
operator|)
return|;
case|case
name|PAM_AUTH_ERR
case|:
return|return
operator|(
literal|"authentication error"
operator|)
return|;
case|case
name|PAM_NEW_AUTHTOK_REQD
case|:
return|return
operator|(
literal|"new authentication token required"
operator|)
return|;
case|case
name|PAM_CRED_INSUFFICIENT
case|:
return|return
operator|(
literal|"insufficient credentials"
operator|)
return|;
case|case
name|PAM_AUTHINFO_UNAVAIL
case|:
return|return
operator|(
literal|"authentication information is unavailable"
operator|)
return|;
case|case
name|PAM_USER_UNKNOWN
case|:
return|return
operator|(
literal|"unknown user"
operator|)
return|;
case|case
name|PAM_CRED_UNAVAIL
case|:
return|return
operator|(
literal|"failed to retrieve user credentials"
operator|)
return|;
case|case
name|PAM_CRED_EXPIRED
case|:
return|return
operator|(
literal|"user credentials have expired"
operator|)
return|;
case|case
name|PAM_CRED_ERR
case|:
return|return
operator|(
literal|"failed to set user credentials"
operator|)
return|;
case|case
name|PAM_ACCT_EXPIRED
case|:
return|return
operator|(
literal|"user accound has expired"
operator|)
return|;
case|case
name|PAM_AUTHTOK_EXPIRED
case|:
return|return
operator|(
literal|"password has expired"
operator|)
return|;
case|case
name|PAM_SESSION_ERR
case|:
return|return
operator|(
literal|"session failure"
operator|)
return|;
case|case
name|PAM_AUTHTOK_ERR
case|:
return|return
operator|(
literal|"authentication token failure"
operator|)
return|;
case|case
name|PAM_AUTHTOK_RECOVERY_ERR
case|:
return|return
operator|(
literal|"failed to recover old authentication token"
operator|)
return|;
case|case
name|PAM_AUTHTOK_LOCK_BUSY
case|:
return|return
operator|(
literal|"authentication token lock busy"
operator|)
return|;
case|case
name|PAM_AUTHTOK_DISABLE_AGING
case|:
return|return
operator|(
literal|"authentication token aging disabled"
operator|)
return|;
case|case
name|PAM_NO_MODULE_DATA
case|:
return|return
operator|(
literal|"module data not found"
operator|)
return|;
case|case
name|PAM_IGNORE
case|:
return|return
operator|(
literal|"ignore this module"
operator|)
return|;
case|case
name|PAM_ABORT
case|:
return|return
operator|(
literal|"general failure"
operator|)
return|;
case|case
name|PAM_TRY_AGAIN
case|:
return|return
operator|(
literal|"try again"
operator|)
return|;
case|case
name|PAM_MODULE_UNKNOWN
case|:
return|return
operator|(
literal|"unknown module type"
operator|)
return|;
case|case
name|PAM_DOMAIN_UNKNOWN
case|:
return|return
operator|(
literal|"unknown authentication domain"
operator|)
return|;
default|default:
name|snprintf
argument_list|(
name|unknown
argument_list|,
sizeof|sizeof
name|unknown
argument_list|,
literal|"#%d"
argument_list|,
name|error_number
argument_list|)
expr_stmt|;
return|return
operator|(
name|unknown
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/**  * The =pam_strerror function returns a pointer to a string containing a  * textual description of the error indicated by the =error_number  * argument, in the context of the PAM transaction described by the =pamh  * argument.  */
end_comment

end_unit

