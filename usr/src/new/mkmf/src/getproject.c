begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: getproject.c,v 1.1 85/03/14 16:59:01 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * getproject() saves the contents of the PROJECT environment variable.  * If the PROJECT variable is undefined or a null string, null is returned.  */
end_comment

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|_PROJECT
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* project root directory pathname */
end_comment

begin_function
name|void
name|getproject
parameter_list|()
block|{
specifier|register
name|char
modifier|*
name|pv
decl_stmt|;
comment|/* ptr to start of PROJECT variable */
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
comment|/* get environment variable */
name|char
modifier|*
name|strsav
parameter_list|()
function_decl|;
comment|/* save a string somewhere */
if|if
condition|(
operator|(
name|pv
operator|=
name|getenv
argument_list|(
literal|"PROJECT"
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
operator|*
name|pv
operator|!=
literal|'\0'
condition|)
name|_PROJECT
operator|=
name|strsav
argument_list|(
name|pv
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

