begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************************    $XConsortium: PanedP.h,v 1.5 91/05/09 20:58:23 gildea Exp $  Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * PanedP.h - Paned Composite Widget's private header file.  *  * Updated and significantly modified from the Athena VPaned Widget.  *  * Date:    March 1, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium  *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawPanedP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawPanedP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Paned.h>
end_include

begin_comment
comment|/*********************************************************************  *  * Paned Widget Private Data  *  *********************************************************************/
end_comment

begin_comment
comment|/* New fields for the Paned widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PanedClassPart
block|{
name|int
name|foo
decl_stmt|;
comment|/* keep compiler happy. */
block|}
name|PanedClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full Class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PanedClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ConstraintClassPart
name|constraint_class
decl_stmt|;
name|PanedClassPart
name|paned_class
decl_stmt|;
block|}
name|PanedClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|PanedClassRec
name|panedClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Paned constraint record */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PanedConstraintsPart
block|{
comment|/* Resources. */
name|Dimension
name|min
decl_stmt|;
comment|/* Minimum height */
name|Dimension
name|max
decl_stmt|;
comment|/* Maximum height */
name|Boolean
name|allow_resize
decl_stmt|;
comment|/* TRUE iff child resize requests are ok */
name|Boolean
name|show_grip
decl_stmt|;
comment|/* TRUE iff child will have grip below it, 				   when it is not the bottom pane. */
name|Boolean
name|skip_adjust
decl_stmt|;
comment|/* TRUE iff child's height should not be */
comment|/* changed without explicit user action. */
name|int
name|position
decl_stmt|;
comment|/* position location in Paned (relative to 				   other children) ** NIY ** */
name|Dimension
name|preferred_size
decl_stmt|;
comment|/* The Preferred size of the pane. 				   Iff this is zero then ask child for size.*/
name|Boolean
name|resize_to_pref
decl_stmt|;
comment|/* resize this pane to its preferred size 				   on a resize or change managed after  				   realize. */
comment|/* Private state. */
name|Position
name|delta
decl_stmt|;
comment|/* Desired Location */
name|Position
name|olddelta
decl_stmt|;
comment|/* The last value of dy. */
name|Boolean
name|paned_adjusted_me
decl_stmt|;
comment|/* Has the vpaned adjusted this widget w/o 				     user interaction to make things fit? */
name|Dimension
name|wp_size
decl_stmt|;
comment|/* widget's preferred size */
name|int
name|size
decl_stmt|;
comment|/* the size the widget will actually get. */
name|Widget
name|grip
decl_stmt|;
comment|/* The grip for this child */
block|}
name|PanedConstraintsPart
operator|,
typedef|*
name|Pane
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PanedConstraintsRec
block|{
name|PanedConstraintsPart
name|paned
decl_stmt|;
block|}
name|PanedConstraintsRec
operator|,
typedef|*
name|PanedConstraints
typedef|;
end_typedef

begin_comment
comment|/*  * The Pane Stack Structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PaneStack
block|{
name|struct
name|_PaneStack
modifier|*
name|next
decl_stmt|;
comment|/* The next element on the stack. */
name|Pane
name|pane
decl_stmt|;
comment|/* The pane in this element on the stack. */
name|int
name|start_size
decl_stmt|;
comment|/* The size of this element when it was pushed 				   onto the stack. */
block|}
name|PaneStack
typedef|;
end_typedef

begin_comment
comment|/* New Fields for the Paned widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|Position
name|grip_indent
decl_stmt|;
comment|/* Location of grips (offset	 					      from right margin) */
name|Boolean
name|refiguremode
decl_stmt|;
comment|/* Whether to refigure changes  					      right now */
name|XtTranslations
name|grip_translations
decl_stmt|;
comment|/* grip translation table */
name|Pixel
name|internal_bp
decl_stmt|;
comment|/* color of internal borders. */
name|Dimension
name|internal_bw
decl_stmt|;
comment|/* internal border width. */
name|XtOrientation
name|orientation
decl_stmt|;
comment|/* Orientation of paned widget. */
name|Cursor
name|cursor
decl_stmt|;
comment|/* Cursor for paned window */
name|Cursor
name|grip_cursor
decl_stmt|;
comment|/* inactive grip cursor */
name|Cursor
name|v_grip_cursor
decl_stmt|;
comment|/* inactive vert grip cursor */
name|Cursor
name|h_grip_cursor
decl_stmt|;
comment|/* inactive horiz grip cursor */
name|Cursor
name|adjust_this_cursor
decl_stmt|;
comment|/* active grip cursor: T */
name|Cursor
name|v_adjust_this_cursor
decl_stmt|;
comment|/* active vert grip cursor: T */
name|Cursor
name|h_adjust_this_cursor
decl_stmt|;
comment|/* active horiz grip cursor: T */
comment|/* vertical. */
name|Cursor
name|adjust_upper_cursor
decl_stmt|;
comment|/* active grip cursor: U */
name|Cursor
name|adjust_lower_cursor
decl_stmt|;
comment|/* active grip cursor: D */
comment|/* horizontal. */
name|Cursor
name|adjust_left_cursor
decl_stmt|;
comment|/* active grip cursor: U */
name|Cursor
name|adjust_right_cursor
decl_stmt|;
comment|/* active grip cursor: D */
comment|/* private */
name|Boolean
name|recursively_called
decl_stmt|;
comment|/* for ChangeManaged */
name|Boolean
name|resize_children_to_pref
decl_stmt|;
comment|/* override constrain resources 					      and resize all children to 					      preferred size. */
name|int
name|start_loc
decl_stmt|;
comment|/* mouse origin when adjusting */
name|Widget
name|whichadd
decl_stmt|;
comment|/* Which pane to add changes to */
name|Widget
name|whichsub
decl_stmt|;
comment|/* Which pane to sub changes from */
name|GC
name|normgc
decl_stmt|;
comment|/* GC to use when drawing borders */
name|GC
name|invgc
decl_stmt|;
comment|/* GC to use when erasing borders */
name|GC
name|flipgc
decl_stmt|;
comment|/* GC to use when animating 					      borders */
name|int
name|num_panes
decl_stmt|;
comment|/* count of managed panes */
name|PaneStack
modifier|*
name|stack
decl_stmt|;
comment|/* The pane stack for this widget.*/
block|}
name|PanedPart
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************  *  * Full instance record declaration  *  **************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PanedRec
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ConstraintPart
name|constraint
decl_stmt|;
name|PanedPart
name|paned
decl_stmt|;
block|}
name|PanedRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawPanedP_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

