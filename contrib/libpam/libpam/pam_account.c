begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pam_account.c - PAM Account Management */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"pam_private.h"
end_include

begin_function
name|int
name|pam_acct_mgmt
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|D
argument_list|(
operator|(
literal|"called"
operator|)
argument_list|)
expr_stmt|;
name|IF_NO_PAMH
argument_list|(
literal|"pam_acct_mgmt"
argument_list|,
name|pamh
argument_list|,
name|PAM_SYSTEM_ERR
argument_list|)
expr_stmt|;
return|return
name|_pam_dispatch
argument_list|(
name|pamh
argument_list|,
name|flags
argument_list|,
name|PAM_ACCOUNT
argument_list|)
return|;
block|}
end_function

end_unit

