begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * slsinit() returns a pointer to the head block of a new list, or null  * pointer if out of memory.  */
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
name|SLSLIST
modifier|*
name|slsinit
parameter_list|()
block|{
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|/* memory allocator */
name|SLSLIST
modifier|*
name|slslist
decl_stmt|;
comment|/* pointer to list head block */
if|if
condition|(
operator|(
name|slslist
operator|=
operator|(
name|SLSLIST
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|SLSLIST
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
name|slslist
operator|->
name|nk
operator|=
literal|0
expr_stmt|;
name|slslist
operator|->
name|maxkey
operator|=
name|slslist
operator|->
name|maxstr
operator|=
literal|0
expr_stmt|;
name|slslist
operator|->
name|head
operator|=
name|slslist
operator|->
name|curblk
operator|=
name|slslist
operator|->
name|tail
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|slslist
operator|)
return|;
block|}
end_function

end_unit

