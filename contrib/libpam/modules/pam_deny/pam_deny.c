begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pam_permit module */
end_comment

begin_comment
comment|/*  * $Id: pam_deny.c,v 1.2 2000/12/04 19:02:34 baggins Exp $  *  * Written by Andrew Morgan<morgan@parc.power.net> 1996/3/11  *  */
end_comment

begin_comment
comment|/*  * here, we make definitions for the externally accessible functions  * in this file (these definitions are required for static modules  * but strongly encouraged generally) they are used to instruct the  * modules include file to define their prototypes.  */
end_comment

begin_define
define|#
directive|define
name|PAM_SM_AUTH
end_define

begin_define
define|#
directive|define
name|PAM_SM_ACCOUNT
end_define

begin_define
define|#
directive|define
name|PAM_SM_SESSION
end_define

begin_define
define|#
directive|define
name|PAM_SM_PASSWORD
end_define

begin_include
include|#
directive|include
file|<security/pam_modules.h>
end_include

begin_comment
comment|/* --- authentication management functions --- */
end_comment

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
return|return
name|PAM_AUTH_ERR
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
return|return
name|PAM_CRED_UNAVAIL
return|;
block|}
end_function

begin_comment
comment|/* --- account management functions --- */
end_comment

begin_function
name|PAM_EXTERN
name|int
name|pam_sm_acct_mgmt
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
return|return
name|PAM_ACCT_EXPIRED
return|;
block|}
end_function

begin_comment
comment|/* --- password management --- */
end_comment

begin_function
name|PAM_EXTERN
name|int
name|pam_sm_chauthtok
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
return|return
name|PAM_AUTHTOK_ERR
return|;
block|}
end_function

begin_comment
comment|/* --- session management --- */
end_comment

begin_function
name|PAM_EXTERN
name|int
name|pam_sm_open_session
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
return|return
name|PAM_SYSTEM_ERR
return|;
block|}
end_function

begin_function
name|PAM_EXTERN
name|int
name|pam_sm_close_session
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
return|return
name|PAM_SYSTEM_ERR
return|;
block|}
end_function

begin_comment
comment|/* end of module definition */
end_comment

begin_comment
comment|/* static module data */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PAM_STATIC
end_ifdef

begin_decl_stmt
name|struct
name|pam_module
name|_pam_deny_modstruct
init|=
block|{
literal|"pam_deny"
block|,
name|pam_sm_authenticate
block|,
name|pam_sm_setcred
block|,
name|pam_sm_acct_mgmt
block|,
name|pam_sm_open_session
block|,
name|pam_sm_close_session
block|,
name|pam_sm_chauthtok
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

