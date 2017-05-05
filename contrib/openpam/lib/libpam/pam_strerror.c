begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2017 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: pam_strerror.c 938 2017-04-30 21:34:42Z des $  */
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
specifier|const
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
operator|(
name|void
operator|)
name|pamh
expr_stmt|;
if|if
condition|(
name|error_number
operator|>=
literal|0
operator|&&
name|error_number
operator|<
name|PAM_NUM_ERRORS
condition|)
block|{
return|return
operator|(
name|pam_err_text
index|[
name|error_number
index|]
operator|)
return|;
block|}
else|else
block|{
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
comment|/**  * The =pam_strerror function returns a pointer to a string containing a  * textual description of the error indicated by the =error_number  * argument.  * The =pamh argument is ignored.  * For compatibility with other implementations, it should be either a  * valid PAM handle returned by a previous call to =pam_start, or =NULL.  */
end_comment

end_unit

