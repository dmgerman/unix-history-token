begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * slinit() returns a pointer to the head block of a new list, or null  * pointer if out of memory.  */
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
name|SLIST
modifier|*
name|slinit
parameter_list|()
block|{
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|/* memory allocator */
name|SLIST
modifier|*
name|slist
decl_stmt|;
comment|/* pointer to list head block */
if|if
condition|(
operator|(
name|slist
operator|=
operator|(
name|SLIST
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|SLIST
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|warn
argument_list|(
literal|"out of memory"
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|slist
operator|->
name|nk
operator|=
literal|0
expr_stmt|;
name|slist
operator|->
name|maxkey
operator|=
literal|0
expr_stmt|;
name|slist
operator|->
name|head
operator|=
name|slist
operator|->
name|curblk
operator|=
name|slist
operator|->
name|tail
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|slist
operator|)
return|;
block|}
end_function

end_unit

