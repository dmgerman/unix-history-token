begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * slget() returns a pointer to the next key in list slist, or null upon  * reaching end of list.  */
end_comment

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"slist.h"
end_include

begin_function
name|char
modifier|*
name|slget
parameter_list|(
name|slist
parameter_list|)
name|SLIST
modifier|*
name|slist
decl_stmt|;
comment|/* pointer to list head block */
block|{
name|char
modifier|*
name|key
decl_stmt|;
comment|/* key pointer */
if|if
condition|(
name|slist
operator|->
name|curblk
operator|!=
name|NULL
condition|)
block|{
name|key
operator|=
name|slist
operator|->
name|curblk
operator|->
name|key
expr_stmt|;
name|slist
operator|->
name|curblk
operator|=
name|slist
operator|->
name|curblk
operator|->
name|next
expr_stmt|;
return|return
operator|(
name|key
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

