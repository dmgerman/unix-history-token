begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)display.c	1.2	%G%  *  * This file contains routines to implement the higher level display  * driver routines for the SUN Gremlin picture editor.  *  * Mark Opperman (opcode@monet.BERKELEY)  *  */
end_comment

begin_include
include|#
directive|include
file|<suntool/tool_hs.h>
end_include

begin_include
include|#
directive|include
file|"gremlin.h"
end_include

begin_comment
comment|/* imports from graphics.c */
end_comment

begin_extern
extern|extern GRArc(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRClear(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRCurve(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRCurrentSetOn(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* force display of current set */
end_comment

begin_extern
extern|extern GRDisplayJustify(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRNewElement(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRPutText(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRSetCurve(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRSetLineStyle(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRSetStippleStyle(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRSetTextPos(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRStippleFill(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRVector(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern curve_set;
end_extern

begin_comment
comment|/* true if spline pre-computed */
end_comment

begin_comment
comment|/* imports from main.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pixwin
modifier|*
name|pix_pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rect
name|pix_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
modifier|*
name|cset_pr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
modifier|*
name|scratch_pr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ELT
modifier|*
name|cset
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern SHOWPOINTS;
end_extern

begin_extern
extern|extern SUN_XORIGIN;
end_extern

begin_extern
extern|extern SUN_YORIGIN;
end_extern

begin_comment
comment|/* imports from long*.c */
end_comment

begin_extern
extern|extern LGShowPoints(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* locals */
end_comment

begin_decl_stmt
name|int
name|minsunx
decl_stmt|,
name|maxsunx
decl_stmt|,
name|minsuny
decl_stmt|,
name|maxsuny
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This routine displays an arbitrary element type   * using the parameters stored with the element.    * Elements are drawn by Exclusive Oring the screen.  */
end_comment

begin_expr_stmt
name|DISScreenAdd
argument_list|(
name|element
argument_list|,
name|mask
argument_list|)
specifier|register
name|ELT
operator|*
name|element
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|mask
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|POINT
modifier|*
name|p0
decl_stmt|,
modifier|*
name|p1
decl_stmt|,
modifier|*
name|p2
decl_stmt|;
name|POINT
name|point
decl_stmt|;
specifier|register
name|x
operator|,
name|y
operator|,
name|width
operator|,
name|height
expr_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|element
argument_list|)
condition|)
return|return;
comment|/* clear scratch_pr */
name|pr_rop
argument_list|(
name|scratch_pr
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|pix_size
operator|.
name|r_width
argument_list|,
name|pix_size
operator|.
name|r_height
argument_list|,
name|PIX_SRC
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* determine bounds for this element */
name|minsunx
operator|=
name|maxsunx
operator|=
name|dbx_to_win
argument_list|(
name|element
operator|->
name|ptlist
operator|->
name|x
argument_list|)
expr_stmt|;
name|minsuny
operator|=
name|maxsuny
operator|=
name|dby_to_win
argument_list|(
name|element
operator|->
name|ptlist
operator|->
name|y
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
name|GRSetTextPos
argument_list|(
name|element
operator|->
name|textpt
argument_list|,
name|element
operator|->
name|type
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
name|ptlist
argument_list|,
operator|&
name|point
argument_list|)
expr_stmt|;
name|GRPutText
argument_list|(
name|element
operator|->
name|textpt
argument_list|,
name|element
operator|->
name|brushf
argument_list|,
name|element
operator|->
name|size
argument_list|,
operator|&
name|point
argument_list|)
expr_stmt|;
if|if
condition|(
name|mask
operator|&
name|csetmask
condition|)
comment|/* display justification marker */
name|GRDisplayJustify
argument_list|(
name|element
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
if|if
condition|(
operator|!
name|curve_set
condition|)
name|GRSetCurve
argument_list|(
name|element
operator|->
name|ptlist
argument_list|)
expr_stmt|;
name|GRCurve
argument_list|(
name|element
operator|->
name|brushf
argument_list|)
expr_stmt|;
name|curve_set
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|POLYGON
case|:
if|if
condition|(
name|element
operator|->
name|brushf
operator|!=
literal|0
condition|)
block|{
comment|/* bordered polygon */
name|p0
operator|=
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
name|GRSetLineStyle
argument_list|(
name|element
operator|->
name|brushf
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
operator|->
name|x
argument_list|,
name|p1
operator|->
name|y
argument_list|,
name|p2
operator|->
name|x
argument_list|,
name|p2
operator|->
name|y
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
comment|/* if last point not specified, join end points */
if|if
condition|(
operator|(
name|p0
operator|->
name|x
operator|!=
name|p1
operator|->
name|x
operator|)
operator|||
operator|(
name|p0
operator|->
name|y
operator|!=
name|p1
operator|->
name|y
operator|)
condition|)
name|GRVector
argument_list|(
name|p1
operator|->
name|x
argument_list|,
name|p1
operator|->
name|y
argument_list|,
name|p0
operator|->
name|x
argument_list|,
name|p0
operator|->
name|y
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* unbordered: find min/max */
name|p0
operator|=
name|element
operator|->
name|ptlist
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|p0
argument_list|)
condition|)
block|{
name|MINMAX
argument_list|(
name|minsunx
argument_list|,
name|maxsunx
argument_list|,
name|dbx_to_win
argument_list|(
name|p0
operator|->
name|x
argument_list|)
argument_list|)
expr_stmt|;
name|MINMAX
argument_list|(
name|minsuny
argument_list|,
name|maxsuny
argument_list|,
name|dby_to_win
argument_list|(
name|p0
operator|->
name|y
argument_list|)
argument_list|)
expr_stmt|;
name|p0
operator|=
name|PTNextPoint
argument_list|(
name|p0
argument_list|)
expr_stmt|;
block|}
block|}
name|GRSetStippleStyle
argument_list|(
name|element
operator|->
name|size
argument_list|)
expr_stmt|;
name|GRStippleFill
argument_list|(
name|element
operator|->
name|ptlist
argument_list|)
expr_stmt|;
break|break;
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
name|GRSetLineStyle
argument_list|(
name|element
operator|->
name|brushf
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
operator|->
name|x
argument_list|,
name|p1
operator|->
name|y
argument_list|,
name|p2
operator|->
name|x
argument_list|,
name|p2
operator|->
name|y
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
break|break;
block|}
block|}
name|x
operator|=
name|minsunx
operator|-
literal|8
expr_stmt|;
name|y
operator|=
name|minsuny
operator|-
literal|8
expr_stmt|;
name|width
operator|=
name|maxsunx
operator|+
literal|8
operator|-
name|x
expr_stmt|;
name|height
operator|=
name|maxsuny
operator|+
literal|8
operator|-
name|y
expr_stmt|;
if|if
condition|(
name|mask
operator|&
name|pixmask
condition|)
name|pw_write
argument_list|(
name|pix_pw
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|PIX_SRC
operator|^
name|PIX_DST
argument_list|,
name|scratch_pr
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|mask
operator|&
name|csetmask
condition|)
name|pr_rop
argument_list|(
name|cset_pr
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|PIX_SRC
operator|^
name|PIX_DST
argument_list|,
name|scratch_pr
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end DISScreenAdd */
end_comment

begin_comment
comment|/*  * This routine erases an arbitrary element type by redrawing the   * element with XOR.  This is the same as drawing the element.  */
end_comment

begin_expr_stmt
name|DISScreenErase
argument_list|(
name|element
argument_list|,
name|mask
argument_list|)
specifier|register
name|ELT
operator|*
name|element
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|register
name|mask
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|DISScreenAdd
argument_list|(
name|element
argument_list|,
name|mask
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end ScreenErase */
end_comment

begin_comment
comment|/*  * This routine clears the current set pixrect.  */
end_comment

begin_macro
name|DISClearSetDisplay
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elist
decl_stmt|;
name|GRCurrentSetOn
argument_list|()
expr_stmt|;
if|if
condition|(
name|SHOWPOINTS
condition|)
name|LGShowPoints
argument_list|()
expr_stmt|;
name|elist
operator|=
name|cset
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elist
argument_list|)
condition|)
block|{
if|if
condition|(
name|TEXT
argument_list|(
name|elist
operator|->
name|type
argument_list|)
condition|)
comment|/* turn off text handle */
name|GRDisplayJustify
argument_list|(
name|elist
argument_list|)
expr_stmt|;
name|elist
operator|=
name|DBNextofSet
argument_list|(
name|elist
argument_list|)
expr_stmt|;
block|}
name|GRClear
argument_list|(
name|csetmask
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end DISClearSetDisplay */
end_comment

end_unit

