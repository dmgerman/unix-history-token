begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright Alexander O. Yuriev, 1996.  All rights reserved.  * NIS+ support by Thorsten Kukuk<kukuk@weber.uni-paderborn.de>  * Copyright Jan Rêkorajski, 1999.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, and the entire permission notice in its entirety,  *    including the disclaimer of warranties.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *   * ALTERNATIVELY, this product may be distributed under the terms of  * the GNU Public License, in which case the provisions of the GPL are  * required INSTEAD OF the above restrictions.  (This clause is  * necessary due to a potential bad interaction between the GPL and  * the restrictions contained in a BSD-style copyright.)  *   * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* #define DEBUG */
end_comment

begin_include
include|#
directive|include
file|<security/_pam_aconf.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* indicate the following groups are defined */
end_comment

begin_define
define|#
directive|define
name|PAM_SM_AUTH
end_define

begin_define
define|#
directive|define
name|_PAM_EXTERN_FUNCTIONS
end_define

begin_include
include|#
directive|include
file|<security/_pam_macros.h>
end_include

begin_include
include|#
directive|include
file|<security/pam_modules.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_PAM
end_ifndef

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINUX_PAM */
end_comment

begin_include
include|#
directive|include
file|"support.h"
end_include

begin_comment
comment|/*  * PAM framework looks for these entry-points to pass control to the  * authentication module.  */
end_comment

begin_comment
comment|/* Fun starts here :)   * pam_sm_authenticate() performs UNIX/shadow authentication  *  *      First, if shadow support is available, attempt to perform  *      authentication using shadow passwords. If shadow is not  *      available, or user does not have a shadow password, fallback  *      onto a normal UNIX authentication  */
end_comment

begin_define
define|#
directive|define
name|_UNIX_AUTHTOK
value|"-UN*X-PASS"
end_define

begin_define
define|#
directive|define
name|AUTH_RETURN
define|\
value|{								\ 	if (on(UNIX_LIKE_AUTH, ctrl)&& ret_data) {		\ 		D(("recording return code for next time [%d]",	\ 					retval));		\ 		pam_set_data(pamh, "unix_setcred_return",	\ 				(void *) retval, NULL);	        \ 	}							\ 	D(("done. [%s]", pam_strerror(pamh, retval)));		\ 	return retval;						\ }
end_define

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
name|unsigned
name|int
name|ctrl
decl_stmt|;
name|int
name|retval
decl_stmt|,
modifier|*
name|ret_data
init|=
name|NULL
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|p
decl_stmt|;
name|D
argument_list|(
operator|(
literal|"called."
operator|)
argument_list|)
expr_stmt|;
name|ctrl
operator|=
name|_set_ctrl
argument_list|(
name|pamh
argument_list|,
name|flags
argument_list|,
name|NULL
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* Get a few bytes so we can pass our return value to 	   pam_sm_setcred(). */
name|ret_data
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
comment|/* get the user'name' */
name|retval
operator|=
name|pam_get_user
argument_list|(
name|pamh
argument_list|,
operator|&
name|name
argument_list|,
literal|"login: "
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|==
name|PAM_SUCCESS
condition|)
block|{
comment|/* 		 * Various libraries at various times have had bugs related to 		 * '+' or '-' as the first character of a user name. Don't take 		 * any chances here. Require that the username starts with an 		 * alphanumeric character. 		 */
if|if
condition|(
name|name
operator|==
name|NULL
operator|||
operator|!
name|isalnum
argument_list|(
operator|*
name|name
argument_list|)
condition|)
block|{
name|_log_err
argument_list|(
name|LOG_ERR
argument_list|,
name|pamh
argument_list|,
literal|"bad username [%s]"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|retval
operator|=
name|PAM_USER_UNKNOWN
expr_stmt|;
name|AUTH_RETURN
block|}
if|if
condition|(
name|retval
operator|==
name|PAM_SUCCESS
operator|&&
name|on
argument_list|(
name|UNIX_DEBUG
argument_list|,
name|ctrl
argument_list|)
condition|)
name|D
argument_list|(
operator|(
literal|"username [%s] obtained"
operator|,
name|name
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|D
argument_list|(
operator|(
literal|"trouble reading username"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|==
name|PAM_CONV_AGAIN
condition|)
block|{
name|D
argument_list|(
operator|(
literal|"pam_get_user/conv() function is not ready yet"
operator|)
argument_list|)
expr_stmt|;
comment|/* it is safe to resume this function so we translate this 			 * retval to the value that indicates we're happy to resume. 			 */
name|retval
operator|=
name|PAM_INCOMPLETE
expr_stmt|;
block|}
name|AUTH_RETURN
block|}
comment|/* if this user does not have a password... */
if|if
condition|(
name|_unix_blankpasswd
argument_list|(
name|ctrl
argument_list|,
name|name
argument_list|)
condition|)
block|{
name|D
argument_list|(
operator|(
literal|"user '%s' has blank passwd"
operator|,
name|name
operator|)
argument_list|)
expr_stmt|;
name|name
operator|=
name|NULL
expr_stmt|;
name|retval
operator|=
name|PAM_SUCCESS
expr_stmt|;
name|AUTH_RETURN
block|}
comment|/* get this user's authentication token */
name|retval
operator|=
name|_unix_read_password
argument_list|(
name|pamh
argument_list|,
name|ctrl
argument_list|,
name|NULL
argument_list|,
literal|"Password: "
argument_list|,
name|NULL
argument_list|,
name|_UNIX_AUTHTOK
argument_list|,
operator|&
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|!=
name|PAM_SUCCESS
condition|)
block|{
if|if
condition|(
name|retval
operator|!=
name|PAM_CONV_AGAIN
condition|)
block|{
name|_log_err
argument_list|(
name|LOG_CRIT
argument_list|,
name|pamh
argument_list|,
literal|"auth could not identify password for [%s]"
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|D
argument_list|(
operator|(
literal|"conversation function is not ready yet"
operator|)
argument_list|)
expr_stmt|;
comment|/* 			 * it is safe to resume this function so we translate this 			 * retval to the value that indicates we're happy to resume. 			 */
name|retval
operator|=
name|PAM_INCOMPLETE
expr_stmt|;
block|}
name|name
operator|=
name|NULL
expr_stmt|;
name|AUTH_RETURN
block|}
name|D
argument_list|(
operator|(
literal|"user=%s, password=[%s]"
operator|,
name|name
operator|,
name|p
operator|)
argument_list|)
expr_stmt|;
comment|/* verify the password of this user */
name|retval
operator|=
name|_unix_verify_password
argument_list|(
name|pamh
argument_list|,
name|name
argument_list|,
name|p
argument_list|,
name|ctrl
argument_list|)
expr_stmt|;
name|name
operator|=
name|p
operator|=
name|NULL
expr_stmt|;
name|AUTH_RETURN
block|}
end_function

begin_comment
comment|/*   * The only thing _pam_set_credentials_unix() does is initialization of  * UNIX group IDs.  *  * Well, everybody but me on linux-pam is convinced that it should not  * initialize group IDs, so I am not doing it but don't say that I haven't  * warned you. -- AOY  */
end_comment

begin_function
name|PAM_EXTERN
name|int
name|pam_sm_setcred
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
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
name|unsigned
name|int
name|ctrl
decl_stmt|;
name|int
name|retval
decl_stmt|;
name|D
argument_list|(
operator|(
literal|"called."
operator|)
argument_list|)
expr_stmt|;
comment|/* FIXME: it shouldn't be necessary to parse the arguments again. The 	   only argument we need is UNIX_LIKE_AUTH: if it was set, 	   pam_get_data will succeed. If it wasn't, it will fail, and we 	   return PAM_SUCCESS.  -SRL */
name|ctrl
operator|=
name|_set_ctrl
argument_list|(
name|pamh
argument_list|,
name|flags
argument_list|,
name|NULL
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|retval
operator|=
name|PAM_SUCCESS
expr_stmt|;
if|if
condition|(
name|on
argument_list|(
name|UNIX_LIKE_AUTH
argument_list|,
name|ctrl
argument_list|)
condition|)
block|{
name|int
modifier|*
name|pretval
init|=
name|NULL
decl_stmt|;
name|D
argument_list|(
operator|(
literal|"recovering return code from auth call"
operator|)
argument_list|)
expr_stmt|;
name|pam_get_data
argument_list|(
name|pamh
argument_list|,
literal|"unix_setcred_return"
argument_list|,
operator|(
specifier|const
name|void
operator|*
operator|*
operator|)
name|pretval
argument_list|)
expr_stmt|;
if|if
condition|(
name|pretval
condition|)
block|{
name|retval
operator|=
operator|*
name|pretval
expr_stmt|;
name|free
argument_list|(
name|pretval
argument_list|)
expr_stmt|;
name|D
argument_list|(
operator|(
literal|"recovered data indicates that old retval was %d"
operator|,
name|retval
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|retval
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_STATIC
end_ifdef

begin_decl_stmt
name|struct
name|pam_module
name|_pam_unix_auth_modstruct
init|=
block|{
literal|"pam_unix_auth"
block|,
name|pam_sm_authenticate
block|,
name|pam_sm_setcred
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

