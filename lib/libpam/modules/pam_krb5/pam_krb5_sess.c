begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pam_krb5_sess.c  *  * PAM session management functions for pam_krb5  * (null functions)  *  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: pam_krb5_sess.c,v 1.3 1999/01/19 20:49:44 fcusack Exp $"
decl_stmt|;
end_decl_stmt

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
comment|/* Initiate session management */
end_comment

begin_function
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

begin_comment
comment|/* Terminate session management */
end_comment

begin_function
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

end_unit

