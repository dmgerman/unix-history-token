begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/openpam/lib/pam_get_data.c#7 $  */
end_comment

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
comment|/*  * XSSO 4.2.1  * XSSO 6 page 43  *  * Get module information  */
end_comment

begin_function
name|int
name|pam_get_data
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|module_data_name
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
name|data
parameter_list|)
block|{
name|pam_data_t
modifier|*
name|dp
decl_stmt|;
if|if
condition|(
name|pamh
operator|==
name|NULL
condition|)
return|return
operator|(
name|PAM_SYSTEM_ERR
operator|)
return|;
for|for
control|(
name|dp
operator|=
name|pamh
operator|->
name|module_data
init|;
name|dp
operator|!=
name|NULL
condition|;
name|dp
operator|=
name|dp
operator|->
name|next
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|dp
operator|->
name|name
argument_list|,
name|module_data_name
argument_list|)
operator|==
literal|0
condition|)
block|{
operator|*
name|data
operator|=
name|dp
operator|->
name|data
expr_stmt|;
return|return
operator|(
name|PAM_SUCCESS
operator|)
return|;
block|}
return|return
operator|(
name|PAM_NO_MODULE_DATA
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Error codes:  *  *	PAM_SYSTEM_ERR  *	PAM_NO_MODULE_DATA  */
end_comment

begin_comment
comment|/**  * The =pam_get_data function looks up the opaque object associated with  * the string specified by the =module_data_name argument, in the PAM  * context specified by the =pamh argument.  * A pointer to the object is stored in the location pointed to by the  * =data argument.  *  * This function and its counterpart =pam_set_data are useful for managing  * data that are meaningful only to a particular service module.  */
end_comment

end_unit

