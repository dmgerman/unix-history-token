begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pam_second.c -- PAM secondary authentication  * (based on XSSO draft spec of March 1997)  *  * $Id: pam_second.c,v 1.2 2000/12/04 19:02:34 baggins Exp $  * $FreeBSD$  *  */
end_comment

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
file|"pam_private.h"
end_include

begin_comment
comment|/* p 42 */
end_comment

begin_function
name|int
name|pam_authenticate_secondary
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|char
modifier|*
name|target_username
name|__unused
parameter_list|,
name|char
modifier|*
name|target_module_type
name|__unused
parameter_list|,
name|char
modifier|*
name|target_authn_domain
name|__unused
parameter_list|,
name|char
modifier|*
name|target_supp_data
name|__unused
parameter_list|,
name|unsigned
name|char
modifier|*
name|target_module_authtok
name|__unused
parameter_list|,
name|int
name|flags
name|__unused
parameter_list|)
block|{
name|int
name|retval
init|=
name|PAM_SYSTEM_ERR
decl_stmt|;
name|D
argument_list|(
operator|(
literal|"called"
operator|)
argument_list|)
expr_stmt|;
name|_pam_start_timer
argument_list|(
name|pamh
argument_list|)
expr_stmt|;
comment|/* we try to make the time for a failure 				  independent of the time it takes to 				  fail */
name|IF_NO_PAMH
argument_list|(
literal|"pam_authenticate_secondary"
argument_list|,
name|pamh
argument_list|,
name|PAM_SYSTEM_ERR
argument_list|)
expr_stmt|;
name|_pam_await_timer
argument_list|(
name|pamh
argument_list|,
name|retval
argument_list|)
expr_stmt|;
comment|/* if unsuccessful then wait now */
name|D
argument_list|(
operator|(
literal|"pam_authenticate_secondary exit"
operator|)
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

end_unit

