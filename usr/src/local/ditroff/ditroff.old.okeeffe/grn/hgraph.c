begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	hgraph.c	1.1	(Berkeley) 83/07/21  *  *     This file contains the graphics routines for converting gremlin  * pictures to troff input.  */
end_comment

begin_include
include|#
directive|include
file|"gprint.h"
end_include

begin_define
define|#
directive|define
name|MAXVECT
value|50
end_define

begin_comment
comment|/* line and character styles */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|style
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|thick
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tfont
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tsize
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* variables used to print from font file */
end_comment

begin_extern
extern|extern cfont;
end_extern

begin_extern
extern|extern csize;
end_extern

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|devdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* imports from main.c */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|scale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|troffscale
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern point(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|int
name|linethickness
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linmod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lasty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastyline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ytop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ybottom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xleft
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xright
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	HGPrintElt (element_pointer)  |  | Results:	examines a picture element and calls the appropriate  |		routine(s) to print them according to their type.  |		After the picture is drawn, current position is (lastx, lasty).  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|HGPrintElt
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

begin_block
block|{
specifier|register
name|POINT
modifier|*
name|p1
decl_stmt|;
specifier|register
name|POINT
modifier|*
name|p2
decl_stmt|;
specifier|register
name|int
name|length
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
name|HGSetFont
argument_list|(
name|element
operator|->
name|brushf
argument_list|,
name|element
operator|->
name|size
argument_list|)
expr_stmt|;
name|HGPutText
argument_list|(
name|element
operator|->
name|type
argument_list|,
operator|*
operator|(
name|element
operator|->
name|ptlist
operator|)
argument_list|,
name|element
operator|->
name|textpt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|tmove
argument_list|(
name|p1
operator|=
name|element
operator|->
name|ptlist
argument_list|)
expr_stmt|;
comment|/* always move to start first */
name|HGSetBrush
argument_list|(
name|element
operator|->
name|brushf
argument_list|)
expr_stmt|;
comment|/* p1 always has first point */
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
name|p2
operator|=
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\\D'a"
argument_list|)
expr_stmt|;
comment|/* stuff... */
name|printf
argument_list|(
literal|" 0 0 0 0'"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CURVE
case|:
name|printf
argument_list|(
literal|"\\D'g"
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
operator|(
name|p1
operator|=
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
operator|)
argument_list|)
condition|)
block|{
name|dx
argument_list|(
operator|(
name|double
operator|)
name|p1
operator|->
name|x
argument_list|)
expr_stmt|;
name|dy
argument_list|(
operator|(
name|double
operator|)
name|p1
operator|->
name|y
argument_list|)
expr_stmt|;
block|}
comment|/* end while */
empty_stmt|;
name|putchar
argument_list|(
literal|'\''
argument_list|)
expr_stmt|;
break|break;
case|case
name|VECTOR
case|:
name|length
operator|=
literal|1
expr_stmt|;
comment|/* keep track of line length */
comment|/* so single lines don't get long */
while|while
condition|(
operator|!
name|Nullpoint
argument_list|(
operator|(
name|p1
operator|=
name|PTNextPoint
argument_list|(
name|p1
argument_list|)
operator|)
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"\\D'l"
argument_list|)
expr_stmt|;
name|dx
argument_list|(
operator|(
name|double
operator|)
name|p1
operator|->
name|x
argument_list|)
expr_stmt|;
name|dy
argument_list|(
operator|(
name|double
operator|)
name|p1
operator|->
name|y
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\''
argument_list|)
expr_stmt|;
if|if
condition|(
name|length
operator|++
operator|>
name|MAXVECT
condition|)
block|{
name|tmove
argument_list|(
name|p1
argument_list|)
expr_stmt|;
name|length
operator|=
literal|1
expr_stmt|;
block|}
block|}
comment|/* end while */
empty_stmt|;
break|break;
block|}
comment|/* end switch */
empty_stmt|;
block|}
comment|/* end else Text */
block|}
comment|/* end if */
block|}
end_block

begin_comment
comment|/* end PrintElt */
end_comment

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	HGPutText (justification, position_point, string)  |  | Results:	  |  | Side Efct:	  |  | Bugs:	  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|HGPutText
argument_list|(
argument|justify
argument_list|,
argument|pnt
argument_list|,
argument|string
argument_list|)
end_macro

begin_decl_stmt
name|int
name|justify
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|POINT
name|pnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|string
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This routine is used to calculate the proper starting position for a  * text string (based on justification, size and font), and prints it   * character by character.  */
end_comment

begin_block
block|{
switch|switch
condition|(
name|justify
condition|)
block|{
case|case
name|BOTLEFT
case|:
break|break;
case|case
name|BOTCENT
case|:
break|break;
case|case
name|BOTRIGHT
case|:
break|break;
case|case
name|CENTLEFT
case|:
break|break;
case|case
name|CENTCENT
case|:
break|break;
case|case
name|CENTRIGHT
case|:
break|break;
case|case
name|TOPLEFT
case|:
break|break;
case|case
name|TOPCENT
case|:
break|break;
case|case
name|TOPRIGHT
case|:
break|break;
block|}
name|HGplotch
argument_list|(
name|string
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* end HGPutText */
end_comment

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|HGSetFont
argument_list|(
argument|font
argument_list|,
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|int
name|font
decl_stmt|,
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
name|char
name|c
decl_stmt|,
name|string
index|[
literal|100
index|]
decl_stmt|;
if|if
condition|(
name|font
operator|!=
name|cfont
condition|)
name|cfont
operator|=
name|font
expr_stmt|;
if|if
condition|(
name|size
operator|!=
name|csize
condition|)
name|csize
operator|=
name|size
expr_stmt|;
comment|/* and whatever... */
block|}
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	HGSetBrush (line_mode)  |  | Results:	generates the troff commands to set up the line width and  |		style of subsequent lines.  Does nothing if no change is needed.  |  | Side Efct:	sets "linmode" and "linethicknes"  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|HGSetBrush
argument_list|(
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|linmod
operator|!=
name|style
index|[
operator|--
name|mode
index|]
condition|)
block|{
name|printf
argument_list|(
literal|"\\D's %du'"
argument_list|,
name|linmod
operator|=
name|style
index|[
name|mode
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|linethickness
operator|!=
name|thick
index|[
name|mode
index|]
condition|)
block|{
name|printf
argument_list|(
literal|"\\D't %du'"
argument_list|,
name|linethickness
operator|=
name|thick
index|[
name|mode
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|HGplotch
argument_list|(
argument|string
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	dx (x_destination)  |  | Results:	scales and outputs a number for delta x (with a leading space)  |		given "lastx" and x_destination.  |  | Side Efct:	resets "lastx" to x_destination.  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|dx
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|double
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|ix
init|=
call|(
name|int
call|)
argument_list|(
name|x
operator|*
name|troffscale
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|" %du"
argument_list|,
name|ix
operator|-
name|lastx
argument_list|)
expr_stmt|;
name|lastx
operator|=
name|ix
expr_stmt|;
block|}
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	dy (y_destination)  |  | Results:	scales and outputs a number for delta y (with a leading space)  |		given "lastyline" and y_destination.  |  | Side Efct:	resets "lastyline" to y_destination.  Since "line" vertical  |		motions don't affect "page" ones, "lasty" isn't updated.  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|dy
argument_list|(
argument|y
argument_list|)
end_macro

begin_decl_stmt
name|double
name|y
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|iy
init|=
call|(
name|int
call|)
argument_list|(
name|y
operator|*
name|troffscale
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|" %du"
argument_list|,
name|iy
operator|-
name|lastyline
argument_list|)
expr_stmt|;
name|lastyline
operator|=
name|iy
expr_stmt|;
block|}
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	tmove (point_pointer)  |  | Results:	produces horizontal and vertical moves for troff given  |		the point pointer.  |  | Bugs:	Notice that this is identical to "dx" and "dy" in value  |		output.  This is because troff does NOT understand spaces  |		in \h or \v commands (!)  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|tmove
argument_list|(
argument|ptr
argument_list|)
end_macro

begin_decl_stmt
name|POINT
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|ix
init|=
call|(
name|int
call|)
argument_list|(
name|ptr
operator|->
name|x
operator|*
name|troffscale
argument_list|)
decl_stmt|;
specifier|register
name|int
name|iy
init|=
call|(
name|int
call|)
argument_list|(
name|ptr
operator|->
name|y
operator|*
name|troffscale
argument_list|)
decl_stmt|;
name|cr
argument_list|()
expr_stmt|;
if|if
condition|(
name|iy
operator|-
name|lasty
condition|)
block|{
name|printf
argument_list|(
literal|".sp %du\n"
argument_list|,
name|iy
operator|-
name|lasty
argument_list|)
expr_stmt|;
block|}
name|lastyline
operator|=
name|lasty
operator|=
name|iy
expr_stmt|;
if|if
condition|(
name|ix
operator|-
name|lastx
condition|)
block|{
name|printf
argument_list|(
literal|"\\h'%du'"
argument_list|,
name|ix
operator|-
name|lastx
argument_list|)
expr_stmt|;
name|lastx
operator|=
name|ix
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	cr  |  | Results:	breaks the output line up to not overrun troff with lines that  |		are too long.  Outputs a ".sp -1" also to keep the vertical  |		spacing correct.  |  | Side Efct:	sets "lastx" to "leftpoint" for troff's return to left margin  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|cr
argument_list|()
end_macro

begin_block
block|{
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|lastx
operator|=
name|xleft
expr_stmt|;
block|}
end_block

end_unit

