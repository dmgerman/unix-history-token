begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	hgraph.c	1.5	(Berkeley) 83/09/19  *  *     This file contains the graphics routines for converting gremlin  * pictures to troff input.  */
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

begin_define
define|#
directive|define
name|pi
value|3.14159265358979324
end_define

begin_define
define|#
directive|define
name|twopi
value|(2.0 * pi)
end_define

begin_define
define|#
directive|define
name|len
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|sqrt((b.x-a.x) * (b.x-a.x) + (b.y-a.y) * (b.y-a.y))
end_define

begin_decl_stmt
specifier|extern
name|int
name|style
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line and character styles */
end_comment

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

begin_decl_stmt
specifier|extern
name|double
name|scale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* imports from main.c */
end_comment

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
name|p1
operator|=
name|element
operator|->
name|ptlist
expr_stmt|;
comment|/* p1 always has first point */
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
name|p1
argument_list|,
name|element
operator|->
name|textpt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|HGSetBrush
argument_list|(
name|element
operator|->
name|brushf
argument_list|)
expr_stmt|;
comment|/* graphics need brush set */
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
name|doarc
argument_list|(
operator|*
name|p1
argument_list|,
operator|*
name|p2
argument_list|,
name|element
operator|->
name|size
argument_list|)
expr_stmt|;
break|break;
case|case
name|CURVE
case|:
name|tmove
argument_list|(
name|p1
argument_list|)
expr_stmt|;
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
name|tmove
argument_list|(
name|p1
argument_list|)
expr_stmt|;
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
break|break;
block|}
comment|/* end switch */
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
comment|/*----------------------------------------------------------------------------*  | Routine:	HGPutText (justification, position_point, string)  |  | Results:	given the justification, a point to position with, and a  |		string to put, HGPutText first sends the string into a  |		diversion, moves to the positioning point, then outputs local  |		vertical and horizontal motions as needed to justify the text.  |		After all motions are done, the diversion is printed out.  *----------------------------------------------------------------------------*/
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

begin_block
block|{
name|int
name|savelasty
init|=
name|lasty
decl_stmt|;
comment|/* vertical motion for text is to be */
comment|/*   ignored.  save current y here */
name|printf
argument_list|(
literal|".nr g8 \\n(.d\n"
argument_list|,
name|string
argument_list|)
expr_stmt|;
comment|/* save current vertical position. */
name|printf
argument_list|(
literal|".ds g9 \"%s"
argument_list|,
name|string
argument_list|)
expr_stmt|;
comment|/* define string containing the text. */
name|tmove
argument_list|(
operator|&
name|pnt
argument_list|)
expr_stmt|;
comment|/* move to positioning point */
switch|switch
condition|(
name|justify
condition|)
block|{
comment|/* local vertical motions */
comment|/* (the numbers here are used to be */
comment|/* somewhat compatible with gprint) */
case|case
name|CENTLEFT
case|:
case|case
name|CENTCENT
case|:
case|case
name|CENTRIGHT
case|:
name|printf
argument_list|(
literal|"\\v'0.85n'"
argument_list|)
expr_stmt|;
comment|/* down half */
break|break;
case|case
name|TOPLEFT
case|:
case|case
name|TOPCENT
case|:
case|case
name|TOPRIGHT
case|:
name|printf
argument_list|(
literal|"\\v'1.7n'"
argument_list|)
expr_stmt|;
comment|/* down whole */
block|}
switch|switch
condition|(
name|justify
condition|)
block|{
comment|/* local horizontal motions */
case|case
name|BOTCENT
case|:
case|case
name|CENTCENT
case|:
case|case
name|TOPCENT
case|:
name|printf
argument_list|(
literal|"\\h'-\\w'\\*(g9'u/2u'"
argument_list|)
expr_stmt|;
comment|/* back half */
break|break;
case|case
name|BOTRIGHT
case|:
case|case
name|CENTRIGHT
case|:
case|case
name|TOPRIGHT
case|:
name|printf
argument_list|(
literal|"\\h'-\\w'\\*(g9'u'"
argument_list|)
expr_stmt|;
comment|/* back whole */
block|}
name|printf
argument_list|(
literal|"\\*(g9\n"
argument_list|)
expr_stmt|;
comment|/* now print the text. */
name|printf
argument_list|(
literal|".sp |\\n(g8u"
argument_list|)
expr_stmt|;
comment|/* restore vertical position */
name|lasty
operator|=
name|savelasty
expr_stmt|;
comment|/* vertical position is restored to */
comment|/*   what it was before text was printed */
block|}
end_block

begin_comment
comment|/* end HGPutText */
end_comment

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	doarc (center_point, start_point, angle)  |  | Results:	produces either drawarc command or a drawcircle command  |		depending on the angle needed to draw through.  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|doarc
argument_list|(
argument|cp
argument_list|,
argument|sp
argument_list|,
argument|angle
argument_list|)
end_macro

begin_decl_stmt
name|POINT
name|cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|POINT
name|sp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|angle
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|double
name|radius
init|=
name|len
argument_list|(
name|cp
argument_list|,
name|sp
argument_list|)
decl_stmt|;
name|double
name|radians
decl_stmt|;
if|if
condition|(
name|angle
condition|)
block|{
comment|/* arc with angle */
name|tmove
argument_list|(
operator|&
name|sp
argument_list|)
expr_stmt|;
comment|/* starting point first */
name|printf
argument_list|(
literal|"\\D'a"
argument_list|)
expr_stmt|;
name|dx
argument_list|(
operator|(
name|double
operator|)
name|cp
operator|.
name|x
argument_list|)
expr_stmt|;
comment|/* move to center */
name|dy
argument_list|(
operator|(
name|double
operator|)
name|cp
operator|.
name|y
argument_list|)
expr_stmt|;
name|radians
operator|=
name|acos
argument_list|(
operator|(
name|sp
operator|.
name|x
operator|-
name|cp
operator|.
name|x
operator|)
operator|/
name|radius
argument_list|)
expr_stmt|;
comment|/* angle of ending */
if|if
condition|(
name|cp
operator|.
name|y
operator|-
name|sp
operator|.
name|y
operator|<
literal|0.0
condition|)
comment|/* point calculated */
name|radians
operator|=
name|twopi
operator|-
name|radians
expr_stmt|;
comment|/* from start point */
name|radians
operator|+=
operator|(
operator|(
name|double
operator|)
name|angle
operator|)
operator|*
operator|(
name|pi
operator|/
literal|180.0
operator|)
expr_stmt|;
comment|/* and arc's angle */
if|if
condition|(
name|radians
operator|>
name|twopi
condition|)
name|radians
operator|-=
name|twopi
expr_stmt|;
name|dx
argument_list|(
name|cp
operator|.
name|x
operator|+
name|cos
argument_list|(
name|radians
argument_list|)
operator|*
name|radius
argument_list|)
expr_stmt|;
comment|/* move to ending point */
name|dy
argument_list|(
name|cp
operator|.
name|y
operator|-
name|sin
argument_list|(
name|radians
argument_list|)
operator|*
name|radius
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* a full circle (angle == 0) */
name|cp
operator|.
name|x
operator|-=
name|radius
expr_stmt|;
name|tmove
argument_list|(
operator|&
name|cp
argument_list|)
expr_stmt|;
comment|/* move to the left point first */
comment|/* draw circle with given diameter */
name|printf
argument_list|(
literal|"\\D'c %du"
argument_list|,
call|(
name|int
call|)
argument_list|(
operator|(
name|radius
operator|+
name|radius
operator|)
operator|*
name|troffscale
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|putchar
argument_list|(
literal|'\''
argument_list|)
expr_stmt|;
comment|/* finish the command */
block|}
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	HGSetFont (font_number, Point_size)  |  | Results:	ALWAYS outputs a .ft and .ps directive to troff.  This is  |		done because someone may change stuff inside a text string.  *----------------------------------------------------------------------------*/
end_comment

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
name|cr
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|".ft %s\n.ps %s\n"
argument_list|,
name|tfont
index|[
name|font
operator|-
literal|1
index|]
argument_list|,
name|tsize
index|[
name|size
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
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
name|cr
argument_list|()
expr_stmt|;
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
name|cr
argument_list|()
expr_stmt|;
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
comment|/*----------------------------------------------------------------------------*  | Routine:	tmove (point_pointer)  |  | Results:	produces horizontal and vertical moves for troff given the  |		pointer of a point to move to.  *----------------------------------------------------------------------------*/
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
specifier|register
name|int
name|dx
decl_stmt|;
specifier|register
name|int
name|dy
decl_stmt|;
name|cr
argument_list|()
expr_stmt|;
if|if
condition|(
name|dy
operator|=
name|iy
operator|-
name|lasty
condition|)
block|{
name|printf
argument_list|(
literal|".sp %du\n"
argument_list|,
name|dy
argument_list|)
expr_stmt|;
block|}
name|lastyline
operator|=
name|lasty
operator|=
name|iy
expr_stmt|;
comment|/* lasty is always set to current */
if|if
condition|(
name|dx
operator|=
name|ix
operator|-
name|lastx
condition|)
block|{
name|printf
argument_list|(
literal|"\\h'%du'"
argument_list|,
name|dx
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
comment|/*----------------------------------------------------------------------------*  | Routine:	cr ( )  |  | Results:	breaks the output line up to not overrun troff with lines that  |		are too long.  |  | Side Efct:	sets "lastx" to "xleft" for troff's return to left margin  *----------------------------------------------------------------------------*/
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

