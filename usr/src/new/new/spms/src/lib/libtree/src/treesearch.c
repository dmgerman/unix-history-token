begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * treesearch() returns the number of occurrences of a key in a binary tree.  */
end_comment

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_macro
name|treesearch
argument_list|(
argument|p
argument_list|,
argument|key
argument_list|)
end_macro

begin_decl_stmt
name|TREE
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current node pointer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to key */
end_comment

begin_block
block|{
name|int
name|comp
decl_stmt|;
comment|/* compare key values */
name|int
name|strcmp
parameter_list|()
function_decl|;
comment|/* string comparison */
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|(
name|comp
operator|=
name|strcmp
argument_list|(
name|key
argument_list|,
name|p
operator|->
name|key
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|treesearch
argument_list|(
name|p
operator|->
name|left
argument_list|,
name|key
argument_list|)
operator|)
return|;
elseif|else
if|if
condition|(
name|comp
operator|>
literal|0
condition|)
return|return
operator|(
name|treesearch
argument_list|(
name|p
operator|->
name|right
argument_list|,
name|key
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|p
operator|->
name|count
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

