begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * tree() searchs for a key in a binary tree. If the search is  * unsuccessful a new node is added to the tree.  */
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

begin_function
name|TREE
modifier|*
name|tree
parameter_list|(
name|p
parameter_list|,
name|key
parameter_list|)
name|TREE
modifier|*
name|p
decl_stmt|;
comment|/* current node pointer */
name|char
modifier|*
name|key
decl_stmt|;
comment|/* pointer to key */
block|{
name|TREE
modifier|*
name|talloc
parameter_list|()
function_decl|;
comment|/* allocate a binary tree node */
name|char
modifier|*
name|strsav
parameter_list|()
function_decl|;
comment|/* save a string */
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
operator|==
name|NULL
condition|)
block|{
comment|/* a new key has arrived */
if|if
condition|(
operator|(
name|p
operator|=
name|talloc
argument_list|()
operator|)
operator|==
name|NULL
operator|||
operator|(
name|p
operator|->
name|key
operator|=
name|strsav
argument_list|(
name|key
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"out of memory"
argument_list|)
expr_stmt|;
name|p
operator|->
name|count
operator|=
literal|1
expr_stmt|;
name|p
operator|->
name|left
operator|=
name|p
operator|->
name|right
operator|=
name|NULL
expr_stmt|;
block|}
elseif|else
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
name|p
operator|->
name|left
operator|=
name|tree
argument_list|(
name|p
operator|->
name|left
argument_list|,
name|key
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|comp
operator|>
literal|0
condition|)
name|p
operator|->
name|right
operator|=
name|tree
argument_list|(
name|p
operator|->
name|right
argument_list|,
name|key
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|comp
operator|==
literal|0
condition|)
name|p
operator|->
name|count
operator|++
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * talloc() allocates memory for a binary tree node.  */
end_comment

begin_function
specifier|static
name|TREE
modifier|*
name|talloc
parameter_list|()
block|{
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|/* memory allocator */
return|return
operator|(
operator|(
name|TREE
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|TREE
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

