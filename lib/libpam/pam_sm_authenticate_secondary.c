begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2011 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: pam_sm_authenticate_secondary.c 437 2011-09-13 12:00:13Z des $  */
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
file|<security/pam_modules.h>
end_include

begin_comment
comment|/*  * XSSO 4.2.2  * XSSO 6 page 70  *  * Service module implementation for pam_authenticate_secondary  */
end_comment

begin_function
name|int
name|pam_sm_authenticate_secondary
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|char
modifier|*
name|target_username
parameter_list|,
name|char
modifier|*
name|target_module_type
parameter_list|,
name|char
modifier|*
name|target_authn_domain
parameter_list|,
name|char
modifier|*
name|target_supp_data
parameter_list|,
name|unsigned
name|char
modifier|*
name|target_module_authtok
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|ENTER
argument_list|()
expr_stmt|;
name|RETURNC
argument_list|(
name|PAM_SYSTEM_ERR
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * NODOC  */
end_comment

end_unit

