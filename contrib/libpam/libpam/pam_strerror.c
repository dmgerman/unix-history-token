begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pam_strerror.c */
end_comment

begin_comment
comment|/* $Id: pam_strerror.c,v 1.6 1997/01/04 20:12:02 morgan Exp morgan $  * $FreeBSD$  *  * $Log: pam_strerror.c,v $  * Revision 1.6  1997/01/04 20:12:02  morgan  * replaced conditional FAIL_NOW with ABORT  *  * Revision 1.5  1996/07/07 23:58:56  morgan  * corrected "... " to "..."  *  * Revision 1.4  1996/06/02 08:03:29  morgan  * spelling correction  *  * Revision 1.3  1996/03/16 23:08:54  morgan  * PAM --> Linux-PAM ;)  *  */
end_comment

begin_include
include|#
directive|include
file|"pam_private.h"
end_include

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
name|errnum
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|UGLY_HACK_FOR_PRIOR_BEHAVIOR_SUPPORT
comment|/* will be removed from v 1.0 */
name|int
name|possible_error
decl_stmt|;
name|possible_error
operator|=
operator|(
name|int
operator|)
name|pamh
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|possible_error
operator|>=
literal|0
operator|&&
name|possible_error
operator|<=
name|PAM_BAD_ITEM
operator|)
condition|)
block|{
name|possible_error
operator|=
name|errnum
expr_stmt|;
block|}
comment|/* mask standard behavior to use possible_error variable. */
define|#
directive|define
name|errnum
value|possible_error
endif|#
directive|endif
comment|/* UGLY_HACK_FOR_PRIOR_BEHAVIOR_SUPPORT */
switch|switch
condition|(
name|errnum
condition|)
block|{
case|case
name|PAM_SUCCESS
case|:
return|return
literal|"Success"
return|;
case|case
name|PAM_ABORT
case|:
return|return
literal|"Critical error - immediate abort"
return|;
case|case
name|PAM_OPEN_ERR
case|:
return|return
literal|"dlopen() failure"
return|;
case|case
name|PAM_SYMBOL_ERR
case|:
return|return
literal|"Symbol not found"
return|;
case|case
name|PAM_SERVICE_ERR
case|:
return|return
literal|"Error in service module"
return|;
case|case
name|PAM_SYSTEM_ERR
case|:
return|return
literal|"System error"
return|;
case|case
name|PAM_BUF_ERR
case|:
return|return
literal|"Memory buffer error"
return|;
case|case
name|PAM_PERM_DENIED
case|:
return|return
literal|"Permission denied"
return|;
case|case
name|PAM_AUTH_ERR
case|:
return|return
literal|"Authentication failure"
return|;
case|case
name|PAM_CRED_INSUFFICIENT
case|:
return|return
literal|"Insufficient credentials to access authentication data"
return|;
case|case
name|PAM_AUTHINFO_UNAVAIL
case|:
return|return
literal|"Authentication service cannot retrieve authentication info."
return|;
case|case
name|PAM_USER_UNKNOWN
case|:
return|return
literal|"User not known to the underlying authentication module"
return|;
case|case
name|PAM_MAXTRIES
case|:
return|return
literal|"Have exhasted maximum number of retries for service."
return|;
case|case
name|PAM_NEW_AUTHTOK_REQD
case|:
return|return
literal|"Authentication token is no longer valid; new one required."
return|;
case|case
name|PAM_ACCT_EXPIRED
case|:
return|return
literal|"User account has expired"
return|;
case|case
name|PAM_SESSION_ERR
case|:
return|return
literal|"Cannot make/remove an entry for the specified session"
return|;
case|case
name|PAM_CRED_UNAVAIL
case|:
return|return
literal|"Authentication service cannot retrieve user credentials"
return|;
case|case
name|PAM_CRED_EXPIRED
case|:
return|return
literal|"User credentials expired"
return|;
case|case
name|PAM_CRED_ERR
case|:
return|return
literal|"Failure setting user credentials"
return|;
case|case
name|PAM_NO_MODULE_DATA
case|:
return|return
literal|"No module specific data is present"
return|;
case|case
name|PAM_BAD_ITEM
case|:
return|return
literal|"Bad item passed to pam_*_item()"
return|;
case|case
name|PAM_CONV_ERR
case|:
return|return
literal|"Conversation error"
return|;
case|case
name|PAM_AUTHTOK_ERR
case|:
return|return
literal|"Authentication token manipulation error"
return|;
case|case
name|PAM_AUTHTOK_RECOVER_ERR
case|:
return|return
literal|"Authentication information cannot be recovered"
return|;
case|case
name|PAM_AUTHTOK_LOCK_BUSY
case|:
return|return
literal|"Authentication token lock busy"
return|;
case|case
name|PAM_AUTHTOK_DISABLE_AGING
case|:
return|return
literal|"Authentication token aging disabled"
return|;
case|case
name|PAM_TRY_AGAIN
case|:
return|return
literal|"Failed preliminary check by password service"
return|;
case|case
name|PAM_IGNORE
case|:
return|return
literal|"Please ignore underlying account module"
return|;
case|case
name|PAM_MODULE_UNKNOWN
case|:
return|return
literal|"Module is unknown"
return|;
case|case
name|PAM_AUTHTOK_EXPIRED
case|:
return|return
literal|"Authentication token expired"
return|;
case|case
name|PAM_CONV_AGAIN
case|:
return|return
literal|"Conversation is waiting for event"
return|;
case|case
name|PAM_INCOMPLETE
case|:
return|return
literal|"Application needs to call libpam again"
return|;
block|}
return|return
literal|"Unknown Linux-PAM error (need to upgrde libpam?)"
return|;
block|}
end_function

end_unit

