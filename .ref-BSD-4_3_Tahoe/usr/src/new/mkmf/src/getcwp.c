begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: getcwp.c,v 1.1 85/03/14 16:58:54 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * getcwp() returns the pathname of the current working project. If the  * PROJECT environment variable is undefined or a null string, null is  * returned.  */
end_comment

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_function
name|char
modifier|*
name|getcwp
parameter_list|()
block|{
specifier|extern
name|char
modifier|*
name|_PROJECT
decl_stmt|;
comment|/* project root directory pathname */
name|void
name|getproject
parameter_list|()
function_decl|;
comment|/* get PROJECT environment variable */
if|if
condition|(
name|_PROJECT
operator|==
name|NULL
condition|)
name|getproject
argument_list|()
expr_stmt|;
return|return
operator|(
name|_PROJECT
operator|)
return|;
block|}
end_function

end_unit

