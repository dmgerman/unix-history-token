begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pam_permit module */
end_comment

begin_comment
comment|/*  * $Id: pam_permit.c,v 1.5 1997/02/15 19:03:15 morgan Exp $  * $FreeBSD$  *  * Written by Andrew Morgan<morgan@parc.power.net> 1996/3/11  *  * $Log: pam_permit.c,v $  * Revision 1.5  1997/02/15 19:03:15  morgan  * fixed email address  *  * Revision 1.4  1997/02/15 16:03:10  morgan  * force a name for user  *  * Revision 1.3  1996/06/02 08:10:14  morgan  * updated for new static protocol  *  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_USER
value|"nobody"
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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

begin_include
include|#
directive|include
file|<security/_pam_macros.h>
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
name|int
name|retval
decl_stmt|;
specifier|const
name|char
modifier|*
name|user
init|=
name|NULL
decl_stmt|;
comment|/*      * authentication requires we know who the user wants to be      */
name|retval
operator|=
name|pam_get_user
argument_list|(
name|pamh
argument_list|,
operator|&
name|user
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|!=
name|PAM_SUCCESS
condition|)
block|{
name|D
argument_list|(
operator|(
literal|"get user returned error: %s"
operator|,
name|pam_strerror
argument_list|(
name|pamh
argument_list|,
name|retval
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
if|if
condition|(
name|user
operator|==
name|NULL
operator|||
operator|*
name|user
operator|==
literal|'\0'
condition|)
block|{
name|D
argument_list|(
operator|(
literal|"username not known"
operator|)
argument_list|)
expr_stmt|;
name|pam_set_item
argument_list|(
name|pamh
argument_list|,
name|PAM_USER
argument_list|,
operator|(
specifier|const
name|void
operator|*
operator|)
name|DEFAULT_USER
argument_list|)
expr_stmt|;
block|}
name|user
operator|=
name|NULL
expr_stmt|;
comment|/* clean up */
return|return
name|PAM_SUCCESS
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
name|PAM_SUCCESS
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
name|PAM_SUCCESS
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
name|PAM_SUCCESS
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
name|PAM_SUCCESS
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
name|PAM_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/* end of module definition */
end_comment

begin_expr_stmt
name|PAM_MODULE_ENTRY
argument_list|(
literal|"pam_permit"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

