begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)point.c	1.2	%G%  *  * Copyright -C- 1982 Barry S. Roitblat  *  *  *      This file contains routines for manipulating the point data  * structures for the gremlin picture editor.  */
end_comment

begin_include
include|#
directive|include
file|"gremlin.h"
end_include

begin_include
include|#
directive|include
file|"grem2.h"
end_include

begin_comment
comment|/* imports from c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|POINT
modifier|*
name|PTInit
parameter_list|()
comment|/*  *      This routine creates a null point and returns  a pointer  * to it.  */
block|{
name|POINT
modifier|*
name|pt
decl_stmt|;
name|pt
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
name|pt
operator|->
name|x
operator|=
name|nullpt
expr_stmt|;
name|pt
operator|->
name|y
operator|=
name|nullpt
expr_stmt|;
return|return
operator|(
name|pt
operator|)
return|;
block|}
end_function

begin_comment
comment|/* end PTInit */
end_comment

begin_decl_stmt
name|POINT
modifier|*
name|PTMakePoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pointlist
argument_list|)
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|POINT
argument_list|*
operator|(
operator|*
name|pointlist
operator|)
argument_list|;
comment|/*  *      This routine creates a new point with coordinates x and y and   * links it into the pointlist.  */
block|{
name|POINT
modifier|*
name|pt1
decl_stmt|;
name|pt1
operator|=
operator|*
name|pointlist
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|pt1
argument_list|)
condition|)
block|{
name|pt1
operator|=
name|pt1
operator|->
name|nextpt
expr_stmt|;
block|}
comment|/* end while */
empty_stmt|;
name|pt1
operator|->
name|x
operator|=
name|x
expr_stmt|;
name|pt1
operator|->
name|y
operator|=
name|y
expr_stmt|;
name|pt1
operator|->
name|nextpt
operator|=
name|PTInit
argument_list|()
expr_stmt|;
return|return
operator|(
name|pt1
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/* end MakePoint */
end_comment

begin_macro
name|PTDeletePoint
argument_list|(
argument|pt
argument_list|)
end_macro

begin_decl_stmt
name|POINT
modifier|*
name|pt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      This routine removes the specified point from the pointlist and  * returns it to free storage.  Deletion is done in place by copying the  * next point over the one to be deleted and then removing the (previously)  * next point.  */
end_comment

begin_block
block|{
name|POINT
modifier|*
name|tempt
decl_stmt|;
name|tempt
operator|=
name|PTNextPoint
argument_list|(
name|pt
argument_list|)
expr_stmt|;
name|pt
operator|->
name|x
operator|=
name|tempt
operator|->
name|x
expr_stmt|;
name|pt
operator|->
name|y
operator|=
name|tempt
operator|->
name|y
expr_stmt|;
name|pt
operator|->
name|nextpt
operator|=
name|tempt
operator|->
name|nextpt
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|tempt
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end DeletePoint */
end_comment

end_unit

