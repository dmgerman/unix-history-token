begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)display.c	1.3	%G%  *  * Copyright -C- 1982 Barry S. Roitblat  *  *      This file contains routines to implement the higher level display  * driver routines  */
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
comment|/* imports from graphics1.c */
end_comment

begin_extern
extern|extern GRsetwmask(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from graphics3.c */
end_comment

begin_extern
extern|extern GRVector(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|GRPutText
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|int
name|GRArc
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern GRClear(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_macro
name|DISScreenAdd
argument_list|(
argument|element
argument_list|,
argument|layer
argument_list|)
end_macro

begin_decl_stmt
name|ELT
modifier|*
name|element
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|layer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      This routine displays an arbitrary element type on the specified   * memory plane using the parameters stored with the element  */
end_comment

begin_block
block|{
name|POINT
modifier|*
name|p1
decl_stmt|,
modifier|*
name|p2
decl_stmt|,
name|pos
decl_stmt|;
if|if
condition|(
operator|!
name|DBNullelt
argument_list|(
name|element
argument_list|)
condition|)
block|{
name|GRsetwmask
argument_list|(
name|layer
argument_list|)
expr_stmt|;
if|if
condition|(
name|TEXT
argument_list|(
name|element
operator|->
name|type
argument_list|)
condition|)
block|{
name|p1
operator|=
name|element
operator|->
name|ptlist
expr_stmt|;
operator|(
name|void
operator|)
name|GRPutText
argument_list|(
name|element
operator|->
name|type
argument_list|,
name|p1
argument_list|,
name|element
operator|->
name|brushf
argument_list|,
name|element
operator|->
name|size
argument_list|,
name|element
operator|->
name|textpt
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
block|}
else|else
block|{
switch|switch
condition|(
name|element
operator|->
name|type
condition|)
block|{
case|case
name|ARC
case|:
name|p1
operator|=
name|element
operator|->
name|ptlist
expr_stmt|;
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
expr_stmt|;
comment|/* angle is stored in size */
operator|(
name|void
operator|)
name|GRArc
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|,
operator|(
name|float
operator|)
name|element
operator|->
name|size
argument_list|,
name|element
operator|->
name|brushf
argument_list|)
expr_stmt|;
break|break;
case|case
name|CURVE
case|:
operator|(
name|void
operator|)
name|GRCurve
argument_list|(
name|element
operator|->
name|ptlist
argument_list|,
name|element
operator|->
name|brushf
argument_list|)
expr_stmt|;
break|break;
case|case
name|POLYGON
case|:
case|case
name|VECTOR
case|:
name|p1
operator|=
name|element
operator|->
name|ptlist
expr_stmt|;
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|p2
argument_list|)
condition|)
block|{
name|GRVector
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|,
name|element
operator|->
name|brushf
argument_list|)
expr_stmt|;
name|p1
operator|=
name|p2
expr_stmt|;
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|p2
argument_list|)
expr_stmt|;
block|}
comment|/* end while */
empty_stmt|;
break|break;
block|}
comment|/* end switch */
empty_stmt|;
block|}
comment|/* end else TEXT */
block|}
comment|/* end if */
block|}
end_block

begin_comment
comment|/* end ScreenAdd */
end_comment

begin_macro
name|DISScreenErase
argument_list|(
argument|element
argument_list|,
argument|layer
argument_list|)
end_macro

begin_decl_stmt
name|ELT
modifier|*
name|element
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|layer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      This routine erases an arbitrary element type from the specified   * memory plane by redrawing the element in the background color.  It  * uses the parameters stored with the element.  */
end_comment

begin_block
block|{
name|POINT
modifier|*
name|p1
decl_stmt|,
modifier|*
name|p2
decl_stmt|,
name|pos
decl_stmt|;
if|if
condition|(
operator|!
name|DBNullelt
argument_list|(
name|element
argument_list|)
condition|)
block|{
name|GRsetwmask
argument_list|(
name|layer
argument_list|)
expr_stmt|;
if|if
condition|(
name|TEXT
argument_list|(
name|element
operator|->
name|type
argument_list|)
condition|)
block|{
name|p1
operator|=
name|element
operator|->
name|ptlist
expr_stmt|;
operator|(
name|void
operator|)
name|GRPutText
argument_list|(
name|element
operator|->
name|type
argument_list|,
name|p1
argument_list|,
name|eraseany
argument_list|,
name|element
operator|->
name|size
argument_list|,
name|element
operator|->
name|textpt
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
block|}
else|else
block|{
switch|switch
condition|(
name|element
operator|->
name|type
condition|)
block|{
case|case
name|ARC
case|:
name|p1
operator|=
name|element
operator|->
name|ptlist
expr_stmt|;
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
expr_stmt|;
comment|/* angle is stored in size */
operator|(
name|void
operator|)
name|GRArc
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|,
operator|(
name|float
operator|)
name|element
operator|->
name|size
argument_list|,
name|eraseany
argument_list|)
expr_stmt|;
break|break;
case|case
name|CURVE
case|:
operator|(
name|void
operator|)
name|GRCurve
argument_list|(
name|element
operator|->
name|ptlist
argument_list|,
name|eraseany
argument_list|)
expr_stmt|;
break|break;
case|case
name|POLYGON
case|:
case|case
name|VECTOR
case|:
name|p1
operator|=
name|element
operator|->
name|ptlist
expr_stmt|;
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|p2
argument_list|)
condition|)
block|{
name|GRVector
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|,
name|eraseany
argument_list|)
expr_stmt|;
name|p1
operator|=
name|p2
expr_stmt|;
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|p2
argument_list|)
expr_stmt|;
block|}
comment|/* end while */
empty_stmt|;
break|break;
block|}
comment|/* end switch */
empty_stmt|;
block|}
comment|/* end else TEXT */
block|}
comment|/* end if */
block|}
end_block

begin_comment
comment|/* end ScreenErase */
end_comment

begin_macro
name|DISDisplaySet
argument_list|(
argument|element
argument_list|)
end_macro

begin_decl_stmt
name|ELT
modifier|*
name|element
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      This routine displays the specified element as the part of  * the current set by calling screenadd with the current set layers  * specified  */
end_comment

begin_block
block|{
name|DISScreenAdd
argument_list|(
name|element
argument_list|,
name|setmask
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end DisplaySet */
end_comment

begin_macro
name|DISEraseSet
argument_list|(
argument|element
argument_list|)
end_macro

begin_decl_stmt
name|ELT
modifier|*
name|element
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *      This routine erases the set attribute of the specifed element by  * calling Screen Erase with the layer mask set for the current set layer(s)  */
end_comment

begin_block
block|{
name|DISScreenErase
argument_list|(
name|element
argument_list|,
name|setmask
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end EraseSet */
end_comment

begin_macro
name|DISClearSetDisplay
argument_list|()
end_macro

begin_comment
comment|/*  *      This routine clears the set attribute from all elements by erasing  * the  the entire set display layer.  */
end_comment

begin_block
block|{
name|GRClear
argument_list|(
name|setmask
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

