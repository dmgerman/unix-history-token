begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * getshell() returns the value the SHELL environment variable (usually  * the pathname of the user's command interpreter). If SHELL is undefined,  * getshell() returns SH (defined in header file bin.h).  */
end_comment

begin_include
include|#
directive|include
file|"bin.h"
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_function
name|char
modifier|*
name|getshell
parameter_list|()
block|{
name|char
modifier|*
name|shell
decl_stmt|;
comment|/* command shell pathname */
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
comment|/* get environment variable */
if|if
condition|(
operator|(
name|shell
operator|=
name|getenv
argument_list|(
literal|"SHELL"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|SH
operator|)
return|;
else|else
return|return
operator|(
name|shell
operator|)
return|;
block|}
end_function

end_unit

