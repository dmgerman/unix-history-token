begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * slsget() returns a pointer to the next block in list slslist, or null  * upon reaching end of list.  */
end_comment

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"slslist.h"
end_include

begin_function
name|SLSBLK
modifier|*
name|slsget
parameter_list|(
name|slslist
parameter_list|)
name|SLSLIST
modifier|*
name|slslist
decl_stmt|;
comment|/* pointer to list head block */
block|{
name|SLSBLK
modifier|*
name|slsbptr
decl_stmt|;
comment|/* block pointer */
if|if
condition|(
name|slslist
operator|->
name|curblk
operator|!=
name|NULL
condition|)
block|{
name|slsbptr
operator|=
name|slslist
operator|->
name|curblk
expr_stmt|;
name|slslist
operator|->
name|curblk
operator|=
name|slslist
operator|->
name|curblk
operator|->
name|next
expr_stmt|;
return|return
operator|(
name|slsbptr
operator|)
return|;
block|}
else|else
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

