begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	hpoint.c	1.1	84/10/08	*/
end_comment

begin_comment
comment|/*  * This file contains routines for manipulating the point data  * structures for the gremlin picture editor.  */
end_comment

begin_include
include|#
directive|include
file|"gprint.h"
end_include

begin_comment
comment|/* imports from C */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return pointer to empty point list.  */
end_comment

begin_function
name|POINT
modifier|*
name|PTInit
parameter_list|()
block|{
return|return
operator|(
operator|(
name|POINT
operator|*
operator|)
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This routine creates a new point with coordinates x and y and   * links it into the pointlist.  */
end_comment

begin_function
name|POINT
modifier|*
name|PTMakePoint
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|pplist
parameter_list|)
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
name|POINT
modifier|*
modifier|*
name|pplist
decl_stmt|;
block|{
specifier|register
name|POINT
modifier|*
name|point
decl_stmt|;
if|if
condition|(
name|Nullpoint
argument_list|(
name|point
operator|=
operator|*
name|pplist
argument_list|)
condition|)
block|{
comment|/* empty list */
operator|*
name|pplist
operator|=
operator|(
name|POINT
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|POINT
argument_list|)
argument_list|)
expr_stmt|;
name|point
operator|=
operator|*
name|pplist
expr_stmt|;
block|}
else|else
block|{
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|point
operator|->
name|nextpt
argument_list|)
condition|)
name|point
operator|=
name|point
operator|->
name|nextpt
expr_stmt|;
name|point
operator|->
name|nextpt
operator|=
operator|(
name|POINT
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|POINT
argument_list|)
argument_list|)
expr_stmt|;
name|point
operator|=
name|point
operator|->
name|nextpt
expr_stmt|;
block|}
name|point
operator|->
name|x
operator|=
name|x
expr_stmt|;
name|point
operator|->
name|y
operator|=
name|y
expr_stmt|;
name|point
operator|->
name|nextpt
operator|=
name|PTInit
argument_list|()
expr_stmt|;
return|return
operator|(
name|point
operator|)
return|;
block|}
end_function

begin_comment
comment|/* end PTMakePoint */
end_comment

end_unit

