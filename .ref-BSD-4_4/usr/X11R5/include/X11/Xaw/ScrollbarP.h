begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: ScrollbarP.h,v 1.2 90/04/11 17:33:53 jim Exp $  */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ScrollbarP_h
end_ifndef

begin_define
define|#
directive|define
name|_ScrollbarP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Scrollbar.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public */
name|Pixel
name|foreground
decl_stmt|;
comment|/* thumb foreground color */
name|XtOrientation
name|orientation
decl_stmt|;
comment|/* horizontal or vertical */
name|XtCallbackList
name|scrollProc
decl_stmt|;
comment|/* proportional scroll */
name|XtCallbackList
name|thumbProc
decl_stmt|;
comment|/* jump (to position) scroll */
name|XtCallbackList
name|jumpProc
decl_stmt|;
comment|/* same as thumbProc but pass data by ref */
name|Pixmap
name|thumb
decl_stmt|;
comment|/* thumb color */
name|Cursor
name|upCursor
decl_stmt|;
comment|/* scroll up cursor */
name|Cursor
name|downCursor
decl_stmt|;
comment|/* scroll down cursor */
name|Cursor
name|leftCursor
decl_stmt|;
comment|/* scroll left cursor */
name|Cursor
name|rightCursor
decl_stmt|;
comment|/* scroll right cursor */
name|Cursor
name|verCursor
decl_stmt|;
comment|/* scroll vertical cursor */
name|Cursor
name|horCursor
decl_stmt|;
comment|/* scroll horizontal cursor */
name|float
name|top
decl_stmt|;
comment|/* What percent is above the win's top */
name|float
name|shown
decl_stmt|;
comment|/* What percent is shown in the win */
name|Dimension
name|length
decl_stmt|;
comment|/* either height or width */
name|Dimension
name|thickness
decl_stmt|;
comment|/* either width or height */
name|Dimension
name|min_thumb
decl_stmt|;
comment|/* minium size for the thumb. */
comment|/* private */
name|Cursor
name|inactiveCursor
decl_stmt|;
comment|/* The normal cursor for scrollbar */
name|char
name|direction
decl_stmt|;
comment|/* a scroll has started; which direction */
name|GC
name|gc
decl_stmt|;
comment|/* a (shared) gc */
name|Position
name|topLoc
decl_stmt|;
comment|/* Pixel that corresponds to top */
name|Dimension
name|shownLength
decl_stmt|;
comment|/* Num pixels corresponding to shown */
block|}
name|ScrollbarPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ScrollbarRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|ScrollbarPart
name|scrollbar
decl_stmt|;
block|}
name|ScrollbarRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|ScrollbarClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ScrollbarClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|ScrollbarClassPart
name|scrollbar_class
decl_stmt|;
block|}
name|ScrollbarClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ScrollbarClassRec
name|scrollbarClassRec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ScrollbarP_h */
end_comment

end_unit

