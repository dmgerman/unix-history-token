begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2007 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: pam_prompt.c 408 2007-12-21 11:36:24Z des $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_include
include|#
directive|include
file|<security/openpam.h>
end_include

begin_comment
comment|/*  * OpenPAM extension  *  * Call the conversation function  */
end_comment

begin_function
name|int
name|pam_prompt
parameter_list|(
specifier|const
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|style
parameter_list|,
name|char
modifier|*
modifier|*
name|resp
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|int
name|r
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|r
operator|=
name|pam_vprompt
argument_list|(
name|pamh
argument_list|,
name|style
argument_list|,
name|resp
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Error codes:  *  *     !PAM_SYMBOL_ERR  *	PAM_SYSTEM_ERR  *	PAM_BUF_ERR  *	PAM_CONV_ERR  */
end_comment

begin_comment
comment|/**  * The =pam_prompt function constructs a message from the specified format  * string and arguments and passes it to the given PAM context's  * conversation function.  *  * A pointer to the response, or =NULL if the conversation function did  * not return one, is stored in the location pointed to by the =resp  * argument.  *  * See =pam_vprompt for further details.  *  *>pam_error  *>pam_info  *>pam_vprompt  */
end_comment

end_unit

