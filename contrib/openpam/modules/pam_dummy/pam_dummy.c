begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Networks Associates Technologies, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $P4: //depot/projects/openpam/modules/pam_dummy/pam_dummy.c#3 $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_modules.h>
end_include

begin_expr_stmt
name|PAM_SM_DUMMY
argument_list|(
name|authenticate
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PAM_SM_DUMMY
argument_list|(
name|setcred
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PAM_SM_DUMMY
argument_list|(
name|acct_mgmt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PAM_SM_DUMMY
argument_list|(
name|open_session
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PAM_SM_DUMMY
argument_list|(
name|close_session
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PAM_SM_DUMMY
argument_list|(
name|chauthtok
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PAM_MODULE_ENTRY
argument_list|(
literal|"pam_deny"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

