begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* priv.c    See if a user is privileged.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_comment
comment|/* See whether the user is privileged (for example, only privileged    users are permitted to kill arbitrary jobs with uustat).  This is    true only for root and uucp.  We check for uucp by seeing if the    real user ID and the effective user ID are the same; this works    because we should be suid to uucp, so our effective user ID will    always be uucp while our real user ID will be whoever ran the    program.  */
end_comment

begin_function
name|boolean
name|fsysdep_privileged
parameter_list|()
block|{
name|uid_t
name|iuid
decl_stmt|;
name|iuid
operator|=
name|getuid
argument_list|()
expr_stmt|;
return|return
name|iuid
operator|==
literal|0
operator|||
name|iuid
operator|==
name|geteuid
argument_list|()
return|;
block|}
end_function

end_unit

