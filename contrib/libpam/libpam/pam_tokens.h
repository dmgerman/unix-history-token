begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pam_tokens.h  *  * $Id$  * $FreeBSD$  *  * This is a Linux-PAM Library Private Header file. It contains tokens  * that are used when we parse the configuration file(s).  *  * Please see end of file for copyright.  *  * Creator: Andrew Morgan.  *   * $Log$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PAM_TOKENS_H
end_ifndef

begin_define
define|#
directive|define
name|_PAM_TOKENS_H
end_define

begin_comment
comment|/* an array of actions */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|_pam_token_actions
index|[
operator|-
name|_PAM_ACTION_UNDEF
index|]
init|=
block|{
literal|"ignore"
block|,
comment|/*  0 */
literal|"ok"
block|,
comment|/* -1 */
literal|"done"
block|,
comment|/* -2 */
literal|"bad"
block|,
comment|/* -3 */
literal|"die"
block|,
comment|/* -4 */
literal|"reset"
block|,
comment|/* -5 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* an array of possible return values */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|_pam_token_returns
index|[
name|_PAM_RETURN_VALUES
operator|+
literal|1
index|]
init|=
block|{
literal|"success"
block|,
comment|/* 0 */
literal|"open_err"
block|,
comment|/* 1 */
literal|"symbol_err"
block|,
comment|/* 2 */
literal|"service_err"
block|,
comment|/* 3 */
literal|"system_err"
block|,
comment|/* 4 */
literal|"buf_err"
block|,
comment|/* 5 */
literal|"perm_denied"
block|,
comment|/* 6 */
literal|"auth_err"
block|,
comment|/* 7 */
literal|"cred_insufficient"
block|,
comment|/* 8 */
literal|"authinfo_unavail"
block|,
comment|/* 9 */
literal|"user_unknown"
block|,
comment|/* 10 */
literal|"maxtries"
block|,
comment|/* 11 */
literal|"new_authtok_reqd"
block|,
comment|/* 12 */
literal|"acct_expired"
block|,
comment|/* 13 */
literal|"session_err"
block|,
comment|/* 14 */
literal|"cred_unavail"
block|,
comment|/* 15 */
literal|"cred_expired"
block|,
comment|/* 16 */
literal|"cred_err"
block|,
comment|/* 17 */
literal|"no_module_data"
block|,
comment|/* 18 */
literal|"conv_err"
block|,
comment|/* 19 */
literal|"authtok_err"
block|,
comment|/* 20 */
literal|"authtok_recover_err"
block|,
comment|/* 21 */
literal|"authtok_lock_busy"
block|,
comment|/* 22 */
literal|"authtok_disable_aging"
block|,
comment|/* 23 */
literal|"try_again"
block|,
comment|/* 24 */
literal|"ignore"
block|,
comment|/* 25 */
literal|"abort"
block|,
comment|/* 26 */
literal|"authtok_expired"
block|,
comment|/* 27 */
literal|"module_unknown"
block|,
comment|/* 28 */
literal|"bad_item"
block|,
comment|/* 29 */
comment|/* add new return codes here */
literal|"default"
comment|/* this is _PAM_RETURN_VALUES and indicates 			    the default return action */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Copyright (C) 1998, Andrew G. Morgan<morgan@linux.kernel.org>  *  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, and the entire permission notice in its entirety,  *    including the disclaimer of warranties.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *   * ALTERNATIVELY, this product may be distributed under the terms of  * the GNU Public License, in which case the provisions of the GPL are  * required INSTEAD OF the above restrictions.  (This clause is  * necessary due to a potential bad interaction between the GPL and  * the restrictions contained in a BSD-style copyright.)  *   * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAM_PRIVATE_H_ */
end_comment

end_unit

