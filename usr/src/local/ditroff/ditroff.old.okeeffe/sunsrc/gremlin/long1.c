begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)long1.c	1.2	%G%  *  * Routines to implement "long" commands in the SUN Gremlin picture editor.  *  * Mark Opperman (opcode@monet.BERKELEY)  *  */
end_comment

begin_comment
comment|/*  * This file contains routines to implement the long text commands  * of the gremlin PICTURE editor.  */
end_comment

begin_include
include|#
directive|include
file|<sunwindow/rect.h>
end_include

begin_include
include|#
directive|include
file|"gremlin.h"
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* imports from graphics files */
end_comment

begin_extern
extern|extern GRBlankPoints(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRDisplayPoint(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRErasePoint(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRfontfound(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GROpenFont(
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
extern|extern curve_set;
end_extern

begin_comment
comment|/* TRUE if spline points pre-computed */
end_comment

begin_comment
comment|/* imports from point.c */
end_comment

begin_function_decl
specifier|extern
name|POINT
modifier|*
name|PTMakeTextPoints
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* imports from display.c */
end_comment

begin_extern
extern|extern DISClearSetDisplay(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DISScreenAdd(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DISScreenErase(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from database files */
end_comment

begin_function_decl
specifier|extern
name|ELT
modifier|*
name|DBCreateElt
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern DBGravitate(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DBChangeBrush(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DBChangeFont(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DBChangeSize(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DBChangeStipple(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DBChangeText(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DBChangeJustify(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DBAddSet(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern DBClearSet(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|POINT
modifier|*
name|PTMakePoint
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern PTDeletePoint(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from undodb.c */
end_comment

begin_extern
extern|extern UNRembMod(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from short.c */
end_comment

begin_extern
extern|extern SHUpdate(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from menu.c  */
end_comment

begin_extern
extern|extern HiArtMode;
end_extern

begin_extern
extern|extern HiLineStyle;
end_extern

begin_extern
extern|extern HiBrush[];
end_extern

begin_extern
extern|extern MNHighLt(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern MNUnHighLt(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern HiFont[];
end_extern

begin_extern
extern|extern HiSize[];
end_extern

begin_extern
extern|extern HiStipple[];
end_extern

begin_comment
comment|/* imports from text.c */
end_comment

begin_extern
extern|extern TxKillLine(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern TxMsgOK(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern text_getvalue(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* imports from main.c */
end_comment

begin_decl_stmt
specifier|extern
name|ELT
modifier|*
name|PICTURE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current PICTURE database      */
end_comment

begin_decl_stmt
specifier|extern
name|ELT
modifier|*
name|cset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current set database          */
end_comment

begin_extern
extern|extern Artmode;
end_extern

begin_comment
comment|/* indication of point display size */
end_comment

begin_extern
extern|extern CBRUSH
operator|,
extern|CSIZE
operator|,
extern|CFONT;
end_extern

begin_comment
comment|/* current brush, size, font     */
end_comment

begin_extern
extern|extern CJUST;
end_extern

begin_comment
comment|/* current text justification    */
end_comment

begin_extern
extern|extern CSTIPPLE;
end_extern

begin_comment
comment|/* current stipple pattern	     */
end_comment

begin_extern
extern|extern Alignment;
end_extern

begin_comment
comment|/* point alignment indicator     */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|PX
decl_stmt|,
name|PY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cursor coordinates            */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|Lastx
decl_stmt|,
name|Lasty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous cursor coordinates   */
end_comment

begin_extern
extern|extern SEQ;
end_extern

begin_comment
comment|/* point sequence number         */
end_comment

begin_decl_stmt
specifier|extern
name|POINT
modifier|*
name|POINTLIST
decl_stmt|,
modifier|*
name|BACKPOINT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accumulated point list        */
end_comment

begin_extern
extern|extern Adjustment;
end_extern

begin_comment
comment|/* point adjustment mode         */
end_comment

begin_extern
extern|extern GravityOn;
end_extern

begin_comment
comment|/* gravity mode flag             */
end_comment

begin_extern
extern|extern CHANGED;
end_extern

begin_comment
comment|/* PICTURE changed flag          */
end_comment

begin_extern
extern|extern SymbolicLines;
end_extern

begin_extern
extern|extern Gridsize;
end_extern

begin_extern
extern|extern SUN_XORIGIN;
end_extern

begin_extern
extern|extern SUN_YORIGIN;
end_extern

begin_decl_stmt
specifier|extern
name|struct
name|rect
name|pix_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* locals */
end_comment

begin_decl_stmt
name|int
name|SHOWPOINTS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if current set reference points on */
end_comment

begin_decl_stmt
specifier|static
name|char
name|badarg
index|[]
init|=
literal|"bad args"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|noset
index|[]
init|=
literal|"no current set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|delmsg
index|[]
init|=
literal|"can't delete any more points"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BADNUM
value|0x7fffffff
end_define

begin_comment
comment|/* largest positive 32-bit integer */
end_comment

begin_comment
comment|/*  * This routine trys to interpret the string starting at  * line+index as an integral numeric parameter.  The function  * returns the numeric equivalent or the largest possible  * integer if there is some error in interpreting the string.  */
end_comment

begin_expr_stmt
name|GetNumParm
argument_list|(
name|line
argument_list|,
name|index
argument_list|)
specifier|register
name|char
operator|*
name|line
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
modifier|*
name|index
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|num
index|[
literal|20
index|]
decl_stmt|;
specifier|register
name|sign
operator|=
literal|1
expr_stmt|;
specifier|register
name|i
expr_stmt|;
name|int
name|result
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|(
operator|*
operator|(
name|line
operator|+
operator|*
name|index
operator|)
operator|==
literal|' '
operator|)
condition|;
operator|++
name|i
control|)
comment|/* skip blanks */
operator|++
operator|(
operator|*
name|index
operator|)
expr_stmt|;
if|if
condition|(
operator|*
operator|(
name|line
operator|+
operator|*
name|index
operator|)
operator|==
literal|'-'
condition|)
block|{
comment|/* negative number */
name|sign
operator|=
operator|-
literal|1
expr_stmt|;
operator|++
operator|(
operator|*
name|index
operator|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|!
name|Delimiter
argument_list|(
operator|*
operator|(
name|line
operator|+
operator|*
name|index
operator|)
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|num
index|[
name|i
index|]
operator|=
operator|*
operator|(
name|line
operator|+
operator|*
name|index
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|isdigit
argument_list|(
name|num
index|[
name|i
index|]
argument_list|)
condition|)
return|return
operator|(
name|BADNUM
operator|)
return|;
operator|++
operator|(
operator|*
name|index
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
operator|(
name|BADNUM
operator|)
return|;
name|num
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
operator|(
name|void
operator|)
name|sscanf
argument_list|(
name|num
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|result
argument_list|)
expr_stmt|;
return|return
operator|(
name|result
operator|*
name|sign
operator|)
return|;
block|}
end_block

begin_comment
comment|/* end GetNumParm */
end_comment

begin_comment
comment|/*  * This routine accepts coordinates from the text terminal  * and creates and displays a point from them by passing them  * along to LGPoint.  */
end_comment

begin_macro
name|LGOPoint
argument_list|()
end_macro

begin_block
block|{
name|int
name|index
decl_stmt|,
name|xcoord
decl_stmt|,
name|ycoord
decl_stmt|;
name|char
name|buf
index|[
name|TEXT_BUFMAX
index|]
decl_stmt|;
name|text_getvalue
argument_list|(
operator|&
name|buf
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|TxKillLine
argument_list|()
expr_stmt|;
name|index
operator|=
literal|0
expr_stmt|;
name|xcoord
operator|=
name|GetNumParm
argument_list|(
name|buf
argument_list|,
operator|&
name|index
argument_list|)
expr_stmt|;
if|if
condition|(
name|xcoord
operator|==
name|BADNUM
condition|)
block|{
name|error
argument_list|(
name|badarg
argument_list|)
expr_stmt|;
return|return;
block|}
operator|++
name|index
expr_stmt|;
name|ycoord
operator|=
name|GetNumParm
argument_list|(
name|buf
argument_list|,
operator|&
name|index
argument_list|)
expr_stmt|;
if|if
condition|(
name|ycoord
operator|==
name|BADNUM
condition|)
block|{
name|error
argument_list|(
name|badarg
argument_list|)
expr_stmt|;
return|return;
block|}
name|PX
operator|=
name|xcoord
expr_stmt|;
name|PY
operator|=
name|ycoord
expr_stmt|;
name|LGPoint
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGOPoint */
end_comment

begin_comment
comment|/*  * This routine accepts cursor coordinates (global PX& PY) and then  * creates and displays points according to the current adjustment and   * alignment modes.  Note that alignment and gravity are mutually exclusive  * and adjustment takes precedence over either.  */
end_comment

begin_macro
name|LGPoint
argument_list|()
end_macro

begin_block
block|{
name|ELT
modifier|*
name|temp
decl_stmt|;
name|POINT
modifier|*
name|p1
decl_stmt|;
name|float
name|signx
init|=
literal|1.0
decl_stmt|;
name|float
name|signy
init|=
literal|1.0
decl_stmt|;
name|temp
operator|=
name|DBInit
argument_list|()
expr_stmt|;
if|if
condition|(
name|GravityOn
condition|)
name|DBGravitate
argument_list|(
name|PX
argument_list|,
name|PY
argument_list|,
operator|&
name|PX
argument_list|,
operator|&
name|PY
argument_list|,
operator|&
name|p1
argument_list|,
operator|&
name|temp
argument_list|,
name|PICTURE
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|temp
argument_list|)
condition|)
block|{
comment|/* no gravity in effect */
comment|/* Round to nearest alignment boundary */
if|if
condition|(
name|PX
operator|<
literal|0
condition|)
block|{
name|signx
operator|=
operator|-
literal|1.0
expr_stmt|;
name|PX
operator|=
operator|-
name|PX
expr_stmt|;
block|}
if|if
condition|(
name|PY
operator|<
literal|0
condition|)
block|{
name|signy
operator|=
operator|-
literal|1.0
expr_stmt|;
name|PY
operator|=
operator|-
name|PY
expr_stmt|;
block|}
name|PX
operator|=
call|(
name|float
call|)
argument_list|(
operator|(
call|(
name|int
call|)
argument_list|(
name|PX
operator|/
name|Alignment
operator|+
literal|0.5
argument_list|)
operator|)
operator|*
name|Alignment
argument_list|)
operator|*
name|signx
expr_stmt|;
name|PY
operator|=
call|(
name|float
call|)
argument_list|(
operator|(
call|(
name|int
call|)
argument_list|(
name|PY
operator|/
name|Alignment
operator|+
literal|0.5
argument_list|)
operator|)
operator|*
name|Alignment
argument_list|)
operator|*
name|signy
expr_stmt|;
block|}
if|if
condition|(
name|SEQ
operator|>
literal|0
condition|)
block|{
comment|/* this isn't the first point */
switch|switch
condition|(
name|Adjustment
condition|)
block|{
case|case
name|HORZ
case|:
name|PY
operator|=
name|Lasty
expr_stmt|;
break|break;
case|case
name|VERT
case|:
name|PX
operator|=
name|Lastx
expr_stmt|;
break|break;
case|case
name|MAN
case|:
if|if
condition|(
name|fabs
argument_list|(
name|PX
operator|-
name|Lastx
argument_list|)
operator|>
name|fabs
argument_list|(
name|PY
operator|-
name|Lasty
argument_list|)
condition|)
name|PY
operator|=
name|Lasty
expr_stmt|;
else|else
name|PX
operator|=
name|Lastx
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|SEQ
operator|>=
name|MAXPOINTS
condition|)
block|{
name|error
argument_list|(
literal|"too many points"
argument_list|)
expr_stmt|;
return|return;
block|}
name|GRDisplayPoint
argument_list|(
name|PX
argument_list|,
name|PY
argument_list|,
name|SEQ
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|PTMakePoint
argument_list|(
name|PX
argument_list|,
name|PY
argument_list|,
operator|&
name|POINTLIST
argument_list|)
expr_stmt|;
name|Lastx
operator|=
name|PX
expr_stmt|;
name|Lasty
operator|=
name|PY
expr_stmt|;
operator|++
name|SEQ
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGPoint */
end_comment

begin_comment
comment|/*  * Clear all points on from Showpoints command.  */
end_comment

begin_macro
name|CSP
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|SHOWPOINTS
condition|)
name|LGShowPoints
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This routine deletes all points from the POINTLIST and   * clears them from the display also.  */
end_comment

begin_macro
name|CP
argument_list|()
end_macro

begin_block
block|{
name|POINT
modifier|*
name|temp
decl_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|BACKPOINT
argument_list|)
condition|)
block|{
name|temp
operator|=
name|PTNextPoint
argument_list|(
name|BACKPOINT
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|BACKPOINT
argument_list|)
expr_stmt|;
name|BACKPOINT
operator|=
name|temp
expr_stmt|;
block|}
name|GRBlankPoints
argument_list|(
name|POINTLIST
argument_list|)
expr_stmt|;
name|BACKPOINT
operator|=
name|POINTLIST
expr_stmt|;
name|POINTLIST
operator|=
name|PTInit
argument_list|()
expr_stmt|;
name|SEQ
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end CP */
end_comment

begin_comment
comment|/*  * Clear all displayed points.  */
end_comment

begin_macro
name|LGClearPoints
argument_list|()
end_macro

begin_block
block|{
name|CP
argument_list|()
expr_stmt|;
name|CSP
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGClearPoints */
end_comment

begin_comment
comment|/*  * This routine removes the last point from the POINTLIST  * and erases it from the screen.  */
end_comment

begin_macro
name|LGDeletePoint
argument_list|()
end_macro

begin_block
block|{
name|POINT
modifier|*
name|pt1
decl_stmt|,
modifier|*
name|pt2
decl_stmt|,
modifier|*
name|pt3
decl_stmt|;
if|if
condition|(
name|SEQ
operator|==
literal|0
condition|)
block|{
name|error
argument_list|(
literal|"no point"
argument_list|)
expr_stmt|;
return|return;
block|}
name|pt2
operator|=
name|pt3
operator|=
name|POINTLIST
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|pt3
argument_list|)
condition|)
block|{
comment|/* find last point and pointer to it */
name|pt1
operator|=
name|pt2
expr_stmt|;
name|pt2
operator|=
name|pt3
expr_stmt|;
name|pt3
operator|=
name|PTNextPoint
argument_list|(
name|pt3
argument_list|)
expr_stmt|;
block|}
name|SEQ
operator|--
expr_stmt|;
name|GRErasePoint
argument_list|(
name|pt2
operator|->
name|x
argument_list|,
name|pt2
operator|->
name|y
argument_list|,
name|SEQ
argument_list|)
expr_stmt|;
name|PTDeletePoint
argument_list|(
name|pt2
argument_list|,
operator|&
name|POINTLIST
argument_list|)
expr_stmt|;
if|if
condition|(
name|SEQ
operator|>
literal|0
condition|)
block|{
comment|/* pt1 points to last one of them */
name|Lastx
operator|=
name|pt1
operator|->
name|x
expr_stmt|;
name|Lasty
operator|=
name|pt1
operator|->
name|y
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/* end LGDeletePoint */
end_comment

begin_comment
comment|/*  *  This routine causes the positioning points of the current set  *  to be displayed.  */
end_comment

begin_macro
name|LGShowPoints
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elt
decl_stmt|;
specifier|register
name|POINT
modifier|*
name|p1
decl_stmt|;
specifier|register
name|pno
expr_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|cset
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|noset
argument_list|)
expr_stmt|;
return|return;
block|}
name|elt
operator|=
name|cset
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elt
argument_list|)
condition|)
block|{
name|p1
operator|=
name|elt
operator|->
name|ptlist
expr_stmt|;
name|pno
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|p1
argument_list|)
condition|)
block|{
name|GRDisplayPoint
argument_list|(
name|p1
operator|->
name|x
argument_list|,
name|p1
operator|->
name|y
argument_list|,
name|pno
argument_list|)
expr_stmt|;
name|p1
operator|=
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
expr_stmt|;
name|pno
operator|++
expr_stmt|;
block|}
name|elt
operator|=
name|DBNextofSet
argument_list|(
name|elt
argument_list|)
expr_stmt|;
block|}
name|SHOWPOINTS
operator|=
operator|!
name|SHOWPOINTS
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGShowPoints */
end_comment

begin_comment
comment|/*  *  This routine handles the two forms of the TEXT command.  *  From the text subwindow, when a RETURN is pressed, the text  *  buffer is copied to the LAST point layed down, the text is  *  consumed, and that point is eaten.  This provides a convenient  *  method of entering several TEXT elements at many locations  *  in the picture.  *  From the menu subwindow, the traditional Gremlin TEXT command  *  is implemented.  One or two points may be specified, and all  *  points are consumed at the end of the command.  */
end_comment

begin_expr_stmt
specifier|static
name|LGTextDisplay
argument_list|(
argument|oldway
argument_list|)
name|int
name|oldway
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elt
decl_stmt|;
name|char
name|buf
index|[
name|TEXT_BUFMAX
index|]
decl_stmt|;
name|POINT
name|pos
decl_stmt|,
name|ppnt
decl_stmt|,
modifier|*
name|p1
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
if|if
condition|(
name|SEQ
operator|==
literal|0
condition|)
block|{
name|error
argument_list|(
literal|"not enough points"
argument_list|)
expr_stmt|;
return|return;
block|}
name|text_getvalue
argument_list|(
operator|&
name|buf
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|buf
operator|==
literal|'\0'
condition|)
block|{
comment|/* no text */
name|error
argument_list|(
literal|"empty string"
argument_list|)
expr_stmt|;
return|return;
block|}
name|GROpenFont
argument_list|(
name|CFONT
argument_list|,
name|CSIZE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|GRfontfound
argument_list|(
name|CFONT
argument_list|,
name|CSIZE
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"can't open font file"
argument_list|)
expr_stmt|;
return|return;
block|}
name|UNForget
argument_list|()
expr_stmt|;
name|text
operator|=
name|malloc
argument_list|(
operator|(
name|unsigned
operator|)
name|strlen
argument_list|(
name|buf
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|text
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|DISClearSetDisplay
argument_list|()
expr_stmt|;
name|DBClearSet
argument_list|()
expr_stmt|;
if|if
condition|(
name|oldway
operator|==
name|TRUE
condition|)
block|{
comment|/* one or two points OK */
name|ppnt
operator|.
name|x
operator|=
name|POINTLIST
operator|->
name|x
expr_stmt|;
name|ppnt
operator|.
name|y
operator|=
name|POINTLIST
operator|->
name|y
expr_stmt|;
if|if
condition|(
name|SEQ
operator|>
literal|1
condition|)
block|{
name|p1
operator|=
name|PTNextPoint
argument_list|(
name|POINTLIST
argument_list|)
expr_stmt|;
name|ppnt
operator|.
name|x
operator|=
operator|(
name|ppnt
operator|.
name|x
operator|+
name|p1
operator|->
name|x
operator|)
operator|/
literal|2
expr_stmt|;
name|ppnt
operator|.
name|y
operator|=
operator|(
name|ppnt
operator|.
name|y
operator|+
name|p1
operator|->
name|y
operator|)
operator|/
literal|2
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* find last point */
name|p1
operator|=
name|POINTLIST
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
argument_list|)
condition|)
name|p1
operator|=
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
expr_stmt|;
name|ppnt
operator|.
name|x
operator|=
name|p1
operator|->
name|x
expr_stmt|;
name|ppnt
operator|.
name|y
operator|=
name|p1
operator|->
name|y
expr_stmt|;
block|}
name|GRSetTextPos
argument_list|(
name|text
argument_list|,
name|CJUST
argument_list|,
name|CFONT
argument_list|,
name|CSIZE
argument_list|,
operator|&
name|ppnt
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
name|p1
operator|=
name|PTMakeTextPoints
argument_list|(
name|text
argument_list|,
name|CFONT
argument_list|,
name|CSIZE
argument_list|,
operator|&
name|ppnt
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
name|elt
operator|=
name|DBCreateElt
argument_list|(
name|CJUST
argument_list|,
name|p1
argument_list|,
name|CFONT
argument_list|,
name|CSIZE
argument_list|,
name|text
argument_list|,
operator|&
name|PICTURE
argument_list|)
expr_stmt|;
name|DISScreenAdd
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
name|DBAddSet
argument_list|(
name|elt
argument_list|)
expr_stmt|;
if|if
condition|(
name|oldway
operator|==
name|TRUE
condition|)
name|CP
argument_list|()
expr_stmt|;
else|else
name|LGDeletePoint
argument_list|()
expr_stmt|;
name|TxKillLine
argument_list|()
expr_stmt|;
name|CHANGED
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGTextDisplay */
end_comment

begin_comment
comment|/*   *  This routine implements the TEXT command from the menu subwindow.  */
end_comment

begin_macro
name|LGText
argument_list|()
end_macro

begin_block
block|{
name|LGTextDisplay
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
comment|/* the old way of doing text entry */
block|}
end_block

begin_comment
comment|/* end LGText */
end_comment

begin_macro
name|LGTextSW
argument_list|()
end_macro

begin_block
block|{
name|LGTextDisplay
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
comment|/* the new way of doing text entry */
block|}
end_block

begin_comment
comment|/* end LGTextSW */
end_comment

begin_comment
comment|/*  * This routine sets the current brush to that specified in the parameter.  */
end_comment

begin_macro
name|LGBrush
argument_list|(
argument|brush
argument_list|)
end_macro

begin_block
block|{
name|MNUnHighLt
argument_list|(
name|HiBrush
index|[
name|CBRUSH
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
name|CBRUSH
operator|=
name|brush
expr_stmt|;
name|MNHighLt
argument_list|(
name|HiBrush
index|[
name|CBRUSH
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGBrush */
end_comment

begin_macro
name|LGBrush1
argument_list|()
end_macro

begin_block
block|{
name|LGBrush
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGBrush2
argument_list|()
end_macro

begin_block
block|{
name|LGBrush
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGBrush3
argument_list|()
end_macro

begin_block
block|{
name|LGBrush
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGBrush4
argument_list|()
end_macro

begin_block
block|{
name|LGBrush
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGBrush5
argument_list|()
end_macro

begin_block
block|{
name|LGBrush
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGBrush6
argument_list|()
end_macro

begin_block
block|{
name|LGBrush
argument_list|(
literal|6
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This routine causes the elements in the current set  * to be redrawn using the new brush.  */
end_comment

begin_macro
name|LGMBrush
argument_list|(
argument|brush
argument_list|)
end_macro

begin_decl_stmt
name|int
name|brush
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elt
decl_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|cset
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|noset
argument_list|)
expr_stmt|;
return|return;
block|}
name|UNForget
argument_list|()
expr_stmt|;
name|CSP
argument_list|()
expr_stmt|;
name|elt
operator|=
name|cset
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elt
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|TEXT
argument_list|(
name|elt
operator|->
name|type
argument_list|)
condition|)
block|{
name|DISScreenErase
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
name|DBChangeBrush
argument_list|(
name|elt
argument_list|,
name|brush
argument_list|,
operator|&
name|PICTURE
argument_list|)
expr_stmt|;
name|curve_set
operator|=
name|TRUE
expr_stmt|;
comment|/* no need to re-compute spline points */
name|DISScreenAdd
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
block|}
name|elt
operator|=
name|DBNextofSet
argument_list|(
name|elt
argument_list|)
expr_stmt|;
block|}
name|CP
argument_list|()
expr_stmt|;
name|CHANGED
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGMBrush */
end_comment

begin_macro
name|LGMBrush1
argument_list|()
end_macro

begin_block
block|{
name|LGMBrush
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMBrush2
argument_list|()
end_macro

begin_block
block|{
name|LGMBrush
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMBrush3
argument_list|()
end_macro

begin_block
block|{
name|LGMBrush
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMBrush4
argument_list|()
end_macro

begin_block
block|{
name|LGMBrush
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMBrush5
argument_list|()
end_macro

begin_block
block|{
name|LGMBrush
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMBrush6
argument_list|()
end_macro

begin_block
block|{
name|LGMBrush
argument_list|(
literal|6
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This routine causes text elements in the current set  * to be redrawn using the new justification mode.  * mode is 1 - 9 for tl, tc, tr, cl, cc, cl, bl, bc, br  */
end_comment

begin_macro
name|LGMJustify
argument_list|(
argument|just
argument_list|)
end_macro

begin_decl_stmt
name|int
name|just
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elt
decl_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|cset
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|noset
argument_list|)
expr_stmt|;
return|return;
block|}
name|UNForget
argument_list|()
expr_stmt|;
name|CSP
argument_list|()
expr_stmt|;
name|elt
operator|=
name|cset
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elt
argument_list|)
condition|)
block|{
if|if
condition|(
name|TEXT
argument_list|(
name|elt
operator|->
name|type
argument_list|)
condition|)
block|{
name|DISScreenErase
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
name|DBChangeJustify
argument_list|(
name|elt
argument_list|,
name|just
argument_list|,
operator|&
name|PICTURE
argument_list|)
expr_stmt|;
name|DISScreenAdd
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
block|}
name|elt
operator|=
name|DBNextofSet
argument_list|(
name|elt
argument_list|)
expr_stmt|;
block|}
name|CP
argument_list|()
expr_stmt|;
name|CHANGED
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGMJustify */
end_comment

begin_comment
comment|/*  * This routine causes the text elements in the current set  * to be redrawn using the new font.  */
end_comment

begin_macro
name|LGMFont
argument_list|(
argument|font
argument_list|)
end_macro

begin_decl_stmt
name|int
name|font
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elt
decl_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|cset
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|noset
argument_list|)
expr_stmt|;
return|return;
block|}
name|UNForget
argument_list|()
expr_stmt|;
name|CSP
argument_list|()
expr_stmt|;
name|elt
operator|=
name|cset
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elt
argument_list|)
condition|)
block|{
if|if
condition|(
name|TEXT
argument_list|(
name|elt
operator|->
name|type
argument_list|)
condition|)
block|{
name|GROpenFont
argument_list|(
name|font
argument_list|,
name|elt
operator|->
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|GRfontfound
argument_list|(
name|font
argument_list|,
name|elt
operator|->
name|size
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"can't open font file"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|DISScreenErase
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
name|TxMsgOK
argument_list|()
expr_stmt|;
name|DBChangeFont
argument_list|(
name|elt
argument_list|,
name|font
argument_list|,
operator|&
name|PICTURE
argument_list|)
expr_stmt|;
name|DISScreenAdd
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
block|}
block|}
name|elt
operator|=
name|DBNextofSet
argument_list|(
name|elt
argument_list|)
expr_stmt|;
block|}
name|CP
argument_list|()
expr_stmt|;
name|CHANGED
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGMFont */
end_comment

begin_macro
name|LGMFont1
argument_list|()
end_macro

begin_block
block|{
name|LGMFont
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMFont2
argument_list|()
end_macro

begin_block
block|{
name|LGMFont
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMFont3
argument_list|()
end_macro

begin_block
block|{
name|LGMFont
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMFont4
argument_list|()
end_macro

begin_block
block|{
name|LGMFont
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This routine causes the text elements in the current set  * to be redrawn using the new size.  */
end_comment

begin_macro
name|LGMSize
argument_list|(
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elt
decl_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|cset
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|noset
argument_list|)
expr_stmt|;
return|return;
block|}
name|UNForget
argument_list|()
expr_stmt|;
name|CSP
argument_list|()
expr_stmt|;
name|elt
operator|=
name|cset
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elt
argument_list|)
condition|)
block|{
if|if
condition|(
name|TEXT
argument_list|(
name|elt
operator|->
name|type
argument_list|)
condition|)
block|{
name|GROpenFont
argument_list|(
name|elt
operator|->
name|brushf
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|GRfontfound
argument_list|(
name|elt
operator|->
name|brushf
argument_list|,
name|size
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"can't open font file"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|DISScreenErase
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
name|TxMsgOK
argument_list|()
expr_stmt|;
name|DBChangeSize
argument_list|(
name|elt
argument_list|,
name|size
argument_list|,
operator|&
name|PICTURE
argument_list|)
expr_stmt|;
name|DISScreenAdd
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
block|}
block|}
name|elt
operator|=
name|DBNextofSet
argument_list|(
name|elt
argument_list|)
expr_stmt|;
block|}
name|CP
argument_list|()
expr_stmt|;
name|CHANGED
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGMFize */
end_comment

begin_macro
name|LGMSize1
argument_list|()
end_macro

begin_block
block|{
name|LGMSize
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMSize2
argument_list|()
end_macro

begin_block
block|{
name|LGMSize
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMSize3
argument_list|()
end_macro

begin_block
block|{
name|LGMSize
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMSize4
argument_list|()
end_macro

begin_block
block|{
name|LGMSize
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This routine causes the polygon elements in the current set  * to be redrawn using the new stipple.  */
end_comment

begin_macro
name|LGMStipple
argument_list|(
argument|stipple
argument_list|)
end_macro

begin_decl_stmt
name|int
name|stipple
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elt
decl_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|cset
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|noset
argument_list|)
expr_stmt|;
return|return;
block|}
name|UNForget
argument_list|()
expr_stmt|;
name|CSP
argument_list|()
expr_stmt|;
name|elt
operator|=
name|cset
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elt
argument_list|)
condition|)
block|{
if|if
condition|(
name|elt
operator|->
name|type
operator|==
name|POLYGON
condition|)
block|{
name|DISScreenErase
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
name|TxMsgOK
argument_list|()
expr_stmt|;
name|DBChangeStipple
argument_list|(
name|elt
argument_list|,
name|stipple
argument_list|,
operator|&
name|PICTURE
argument_list|)
expr_stmt|;
name|DISScreenAdd
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
block|}
name|elt
operator|=
name|DBNextofSet
argument_list|(
name|elt
argument_list|)
expr_stmt|;
block|}
name|CP
argument_list|()
expr_stmt|;
name|CHANGED
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGMStipple */
end_comment

begin_macro
name|LGMStipple1
argument_list|()
end_macro

begin_block
block|{
name|LGMStipple
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMStipple2
argument_list|()
end_macro

begin_block
block|{
name|LGMStipple
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMStipple3
argument_list|()
end_macro

begin_block
block|{
name|LGMStipple
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMStipple4
argument_list|()
end_macro

begin_block
block|{
name|LGMStipple
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMStipple5
argument_list|()
end_macro

begin_block
block|{
name|LGMStipple
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMStipple6
argument_list|()
end_macro

begin_block
block|{
name|LGMStipple
argument_list|(
literal|6
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMStipple7
argument_list|()
end_macro

begin_block
block|{
name|LGMStipple
argument_list|(
literal|7
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGMStipple8
argument_list|()
end_macro

begin_block
block|{
name|LGMStipple
argument_list|(
literal|8
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*   * This routine allows modification of text by replacing   * an existing string with a new one, appropriately repositioned  */
end_comment

begin_macro
name|LGMText
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elt
decl_stmt|;
name|char
name|buf
index|[
name|TEXT_BUFMAX
index|]
decl_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|cset
argument_list|)
condition|)
block|{
name|error
argument_list|(
name|noset
argument_list|)
expr_stmt|;
return|return;
block|}
name|text_getvalue
argument_list|(
operator|&
name|buf
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|buf
operator|==
literal|'\0'
condition|)
block|{
comment|/* no text */
name|error
argument_list|(
literal|"empty string"
argument_list|)
expr_stmt|;
return|return;
block|}
name|UNForget
argument_list|()
expr_stmt|;
name|CSP
argument_list|()
expr_stmt|;
name|elt
operator|=
name|cset
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elt
argument_list|)
condition|)
block|{
if|if
condition|(
name|TEXT
argument_list|(
name|elt
operator|->
name|type
argument_list|)
condition|)
block|{
name|DISScreenErase
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
name|TxMsgOK
argument_list|()
expr_stmt|;
name|DBChangeText
argument_list|(
name|elt
argument_list|,
name|buf
argument_list|,
operator|&
name|PICTURE
argument_list|)
expr_stmt|;
name|DISScreenAdd
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
block|}
name|elt
operator|=
name|DBNextofSet
argument_list|(
name|elt
argument_list|)
expr_stmt|;
block|}
name|CP
argument_list|()
expr_stmt|;
name|TxKillLine
argument_list|()
expr_stmt|;
name|CHANGED
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGMText */
end_comment

begin_comment
comment|/*  * This routine modifies the element which contains the point  * closest to the first of two specified points so that that point  * coincides with the second of the points (if specified).  *  * Note: it implies knowledge of the database representation by modifying  *       the element directly.  */
end_comment

begin_macro
name|LGMPoint
argument_list|()
end_macro

begin_block
block|{
name|ELT
modifier|*
name|elt
decl_stmt|;
name|POINT
modifier|*
name|p1
decl_stmt|,
modifier|*
name|p2
decl_stmt|,
modifier|*
name|p3
decl_stmt|,
modifier|*
name|p4
decl_stmt|;
name|float
name|x1
decl_stmt|,
name|y1
decl_stmt|;
name|int
name|length
decl_stmt|;
if|if
condition|(
name|SEQ
operator|<
literal|1
condition|)
block|{
name|error
argument_list|(
literal|"no point specified"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* find point */
name|DBGravitate
argument_list|(
name|POINTLIST
operator|->
name|x
argument_list|,
name|POINTLIST
operator|->
name|y
argument_list|,
operator|&
name|x1
argument_list|,
operator|&
name|y1
argument_list|,
operator|&
name|p1
argument_list|,
operator|&
name|elt
argument_list|,
name|cset
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|elt
argument_list|)
operator|||
name|TEXT
argument_list|(
name|elt
operator|->
name|type
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"can't find a good element"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|SEQ
operator|==
literal|1
condition|)
block|{
comment|/* wants to delete a point */
name|length
operator|=
name|PTListLength
argument_list|(
name|elt
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|elt
operator|->
name|type
operator|==
name|POLYGON
operator|)
operator|&&
operator|(
name|length
operator|==
literal|3
operator|)
operator|)
operator|||
operator|(
name|length
operator|==
literal|2
operator|)
condition|)
block|{
name|error
argument_list|(
name|delmsg
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
comment|/* now OK to do whatever */
name|UNForget
argument_list|()
expr_stmt|;
name|CSP
argument_list|()
expr_stmt|;
name|DBClearSet
argument_list|()
expr_stmt|;
name|GRClear
argument_list|(
name|csetmask
argument_list|)
expr_stmt|;
name|DISScreenErase
argument_list|(
name|elt
argument_list|,
name|pixmask
argument_list|)
expr_stmt|;
name|UNRembMod
argument_list|(
name|elt
argument_list|,
operator|&
name|PICTURE
argument_list|)
expr_stmt|;
if|if
condition|(
name|SEQ
operator|>
literal|1
condition|)
block|{
comment|/* move a point, not delete */
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|POINTLIST
argument_list|)
expr_stmt|;
name|p1
operator|->
name|x
operator|=
name|p2
operator|->
name|x
expr_stmt|;
name|p1
operator|->
name|y
operator|=
name|p2
operator|->
name|y
expr_stmt|;
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|p2
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|Nullpoint
argument_list|(
name|p2
argument_list|)
condition|)
block|{
name|p3
operator|=
name|PTInit
argument_list|()
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
name|p4
operator|=
name|PTMakePoint
argument_list|(
name|p2
operator|->
name|x
argument_list|,
name|p2
operator|->
name|y
argument_list|,
operator|&
name|p3
argument_list|)
expr_stmt|;
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|p2
argument_list|)
expr_stmt|;
block|}
name|p4
operator|->
name|nextpt
operator|=
name|p1
operator|->
name|nextpt
expr_stmt|;
name|p1
operator|->
name|nextpt
operator|=
name|p3
expr_stmt|;
block|}
block|}
else|else
block|{
name|PTDeletePoint
argument_list|(
name|p1
argument_list|,
operator|&
operator|(
name|elt
operator|->
name|ptlist
operator|)
argument_list|)
expr_stmt|;
block|}
name|DISScreenAdd
argument_list|(
name|elt
argument_list|,
name|pixmask
operator||
name|csetmask
argument_list|)
expr_stmt|;
name|DBAddSet
argument_list|(
name|elt
argument_list|)
expr_stmt|;
name|CP
argument_list|()
expr_stmt|;
name|CHANGED
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGMPoint */
end_comment

begin_comment
comment|/*  * This routine allows users to leave gripe messages or report  * bugs to the maintainer.  Mail is invoked via the defined constant GRIPE.  */
end_comment

begin_macro
name|LGGripe
argument_list|()
end_macro

begin_block
block|{
name|TxPutMsg
argument_list|(
literal|"mail gripes to opcode@monet"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGGripe */
end_comment

begin_comment
comment|/*  * This routine controls the size of the point that is displayed.  * The sizes available are Artmode in which a small (3 x 3) point is displayed  * with no number and regular (non-Artmode).  */
end_comment

begin_macro
name|LGLittlePoint
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|POINT
modifier|*
name|plist
decl_stmt|;
specifier|register
name|sp
expr_stmt|;
specifier|register
name|i
operator|=
literal|0
expr_stmt|;
name|GRBlankPoints
argument_list|(
name|POINTLIST
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|sp
operator|=
name|SHOWPOINTS
operator|)
operator|!=
literal|0
condition|)
comment|/* turn off show points */
name|CSP
argument_list|()
expr_stmt|;
name|Artmode
operator|=
operator|!
name|Artmode
expr_stmt|;
name|plist
operator|=
name|POINTLIST
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|plist
argument_list|)
condition|)
block|{
name|GRDisplayPoint
argument_list|(
name|plist
operator|->
name|x
argument_list|,
name|plist
operator|->
name|y
argument_list|,
name|i
operator|++
argument_list|)
expr_stmt|;
name|plist
operator|=
name|PTNextPoint
argument_list|(
name|plist
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sp
operator|!=
literal|0
condition|)
comment|/* turn on show points */
name|LGShowPoints
argument_list|()
expr_stmt|;
if|if
condition|(
name|Artmode
condition|)
name|MNUnHighLt
argument_list|(
name|HiArtMode
argument_list|)
expr_stmt|;
else|else
name|MNHighLt
argument_list|(
name|HiArtMode
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGLittlePoint */
end_comment

begin_comment
comment|/*  * This routine looks at the command line for parameters to set  * the current Font.  */
end_comment

begin_macro
name|LGFont
argument_list|(
argument|font
argument_list|)
end_macro

begin_decl_stmt
name|int
name|font
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|MNUnHighLt
argument_list|(
name|HiFont
index|[
name|CFONT
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
name|CFONT
operator|=
name|font
expr_stmt|;
name|MNHighLt
argument_list|(
name|HiFont
index|[
name|CFONT
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGFont */
end_comment

begin_macro
name|LGFont1
argument_list|()
end_macro

begin_block
block|{
name|LGFont
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGFont2
argument_list|()
end_macro

begin_block
block|{
name|LGFont
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGFont3
argument_list|()
end_macro

begin_block
block|{
name|LGFont
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGFont4
argument_list|()
end_macro

begin_block
block|{
name|LGFont
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This routine changes the current character size.  */
end_comment

begin_macro
name|LGSize
argument_list|(
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|MNUnHighLt
argument_list|(
name|HiSize
index|[
name|CSIZE
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
name|CSIZE
operator|=
name|size
expr_stmt|;
name|MNHighLt
argument_list|(
name|HiSize
index|[
name|CSIZE
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGSize */
end_comment

begin_macro
name|LGSize1
argument_list|()
end_macro

begin_block
block|{
name|LGSize
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGSize2
argument_list|()
end_macro

begin_block
block|{
name|LGSize
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGSize3
argument_list|()
end_macro

begin_block
block|{
name|LGSize
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGSize4
argument_list|()
end_macro

begin_block
block|{
name|LGSize
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This routine changes the current stipple pattern.  */
end_comment

begin_macro
name|LGStipple
argument_list|(
argument|stipple
argument_list|)
end_macro

begin_decl_stmt
name|int
name|stipple
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|MNUnHighLt
argument_list|(
name|HiStipple
index|[
name|CSTIPPLE
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
name|CSTIPPLE
operator|=
name|stipple
expr_stmt|;
name|MNHighLt
argument_list|(
name|HiStipple
index|[
name|CSTIPPLE
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGStipple */
end_comment

begin_macro
name|LGStipple1
argument_list|()
end_macro

begin_block
block|{
name|LGStipple
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGStipple2
argument_list|()
end_macro

begin_block
block|{
name|LGStipple
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGStipple3
argument_list|()
end_macro

begin_block
block|{
name|LGStipple
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGStipple4
argument_list|()
end_macro

begin_block
block|{
name|LGStipple
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGStipple5
argument_list|()
end_macro

begin_block
block|{
name|LGStipple
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGStipple6
argument_list|()
end_macro

begin_block
block|{
name|LGStipple
argument_list|(
literal|6
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGStipple7
argument_list|()
end_macro

begin_block
block|{
name|LGStipple
argument_list|(
literal|7
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|LGStipple8
argument_list|()
end_macro

begin_block
block|{
name|LGStipple
argument_list|(
literal|8
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Toggle line style  */
end_comment

begin_macro
name|LGLineStyle
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|SymbolicLines
operator|=
operator|!
name|SymbolicLines
condition|)
name|MNUnHighLt
argument_list|(
name|HiLineStyle
argument_list|)
expr_stmt|;
else|else
name|MNHighLt
argument_list|(
name|HiLineStyle
argument_list|)
expr_stmt|;
name|SHUpdate
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGLineStyle */
end_comment

begin_macro
name|LGPan
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|SEQ
operator|<
literal|1
condition|)
block|{
name|error
argument_list|(
literal|"need one point"
argument_list|)
expr_stmt|;
return|return;
block|}
name|LGdopan
argument_list|(
name|POINTLIST
operator|->
name|x
argument_list|,
name|POINTLIST
operator|->
name|y
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Make (wx, wy) center of Gremlin window.  */
end_comment

begin_macro
name|LGdopan
argument_list|(
argument|wx
argument_list|,
argument|wy
argument_list|)
end_macro

begin_decl_stmt
name|float
name|wx
decl_stmt|,
name|wy
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|float
name|cx
decl_stmt|,
name|cy
decl_stmt|;
specifier|register
name|tx
operator|,
name|ty
expr_stmt|;
name|CP
argument_list|()
expr_stmt|;
comment|/* eat points first */
name|cx
operator|=
name|SUN_XORIGIN
operator|+
operator|(
name|pix_size
operator|.
name|r_width
operator|>>
literal|1
operator|)
expr_stmt|;
comment|/* window x center */
name|cy
operator|=
name|SUN_YORIGIN
operator|-
operator|(
name|pix_size
operator|.
name|r_height
operator|>>
literal|1
operator|)
expr_stmt|;
comment|/* window y center */
name|tx
operator|=
call|(
name|int
call|)
argument_list|(
name|wx
operator|-
name|cx
argument_list|)
expr_stmt|;
comment|/* x translation */
name|ty
operator|=
call|(
name|int
call|)
argument_list|(
name|wy
operator|-
name|cy
argument_list|)
expr_stmt|;
comment|/* y translation */
name|tx
operator|+=
operator|(
name|tx
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
literal|1
expr_stmt|;
comment|/* fudge factor */
name|ty
operator|+=
operator|(
name|ty
operator|<
literal|0
operator|)
condition|?
operator|-
literal|1
else|:
literal|1
expr_stmt|;
name|SUN_XORIGIN
operator|+=
operator|(
name|tx
operator|/
name|Gridsize
operator|)
operator|*
name|Gridsize
expr_stmt|;
name|SUN_YORIGIN
operator|+=
operator|(
name|ty
operator|/
name|Gridsize
operator|)
operator|*
name|Gridsize
expr_stmt|;
name|SHUpdate
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end LGPan */
end_comment

begin_comment
comment|/*  * Pan to absolute center of picture.  * Invoked by the middle button on the PAN icon.  */
end_comment

begin_macro
name|LGMPan
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|ELT
modifier|*
name|elt
decl_stmt|;
specifier|register
name|POINT
modifier|*
name|point
decl_stmt|;
name|float
name|minx
decl_stmt|,
name|miny
decl_stmt|,
name|maxx
decl_stmt|,
name|maxy
decl_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|PICTURE
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"empty picture"
argument_list|)
expr_stmt|;
return|return;
block|}
name|elt
operator|=
name|PICTURE
expr_stmt|;
name|minx
operator|=
name|maxx
operator|=
name|elt
operator|->
name|ptlist
operator|->
name|x
expr_stmt|;
name|miny
operator|=
name|maxy
operator|=
name|elt
operator|->
name|ptlist
operator|->
name|y
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|elt
argument_list|)
condition|)
block|{
name|point
operator|=
name|elt
operator|->
name|ptlist
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
name|point
argument_list|)
condition|)
block|{
name|MINMAX
argument_list|(
name|minx
argument_list|,
name|maxx
argument_list|,
name|point
operator|->
name|x
argument_list|)
expr_stmt|;
name|MINMAX
argument_list|(
name|miny
argument_list|,
name|maxy
argument_list|,
name|point
operator|->
name|y
argument_list|)
expr_stmt|;
name|point
operator|=
name|PTNextPoint
argument_list|(
name|point
argument_list|)
expr_stmt|;
block|}
name|elt
operator|=
name|DBNextElt
argument_list|(
name|elt
argument_list|)
expr_stmt|;
block|}
name|LGdopan
argument_list|(
name|maxx
operator|-
operator|(
operator|(
name|maxx
operator|-
name|minx
operator|)
operator|/
literal|2.0
operator|)
argument_list|,
name|maxy
operator|-
operator|(
operator|(
name|maxy
operator|-
name|miny
operator|)
operator|/
literal|2.0
operator|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

