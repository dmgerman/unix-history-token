begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: FormP.h,v 1.20 91/05/02 16:20:29 swick Exp $ */
end_comment

begin_comment
comment|/* Copyright	Massachusetts Institute of Technology	1987 */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/* Form widget private definitions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawFormP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawFormP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Form.h>
end_include

begin_include
include|#
directive|include
file|<X11/ConstrainP.h>
end_include

begin_define
define|#
directive|define
name|XtREdgeType
value|"EdgeType"
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|LayoutPending
block|,
name|LayoutInProgress
block|,
name|LayoutDone
block|}
name|LayoutState
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XtInheritLayout
value|((Boolean (*)())_XtInherit)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Boolean
function_decl|(
modifier|*
name|layout
function_decl|)
parameter_list|(
comment|/* FormWidget, Dimension, Dimension */
parameter_list|)
function_decl|;
block|}
name|FormClassPart
typedef|;
end_typedef

begin_comment
comment|/*  * Layout(  *	FormWidget w	- the widget whose children are to be configured  *	Dimension w, h	- bounding box of layout to be calculated  *  *  Stores preferred geometry in w->form.preferred_{width,height}.  *  If w->form.resize_in_layout is True, then a geometry request  *  may be made for the preferred bounding box if necessary.  *  *  Returns True if a geometry request was granted, False otherwise.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_FormClassRec
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
name|FormClassPart
name|form_class
decl_stmt|;
block|}
name|FormClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FormClassRec
name|formClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|_FormPart
block|{
comment|/* resources */
name|int
name|default_spacing
decl_stmt|;
comment|/* default distance between children */
comment|/* private state */
name|Dimension
name|old_width
decl_stmt|,
name|old_height
decl_stmt|;
comment|/* last known dimensions		 */
name|int
name|no_refigure
decl_stmt|;
comment|/* no re-layout while> 0		 */
name|Boolean
name|needs_relayout
decl_stmt|;
comment|/* next time no_refigure == 0	 */
name|Boolean
name|resize_in_layout
decl_stmt|;
comment|/* should layout() do geom request?  */
name|Dimension
name|preferred_width
decl_stmt|,
name|preferred_height
decl_stmt|;
comment|/* cached from layout */
name|Boolean
name|resize_is_no_op
decl_stmt|;
comment|/* Causes resize to take not action. */
block|}
name|FormPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_FormRec
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
name|FormPart
name|form
decl_stmt|;
block|}
name|FormRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_FormConstraintsPart
block|{
comment|/*  * Constraint Resources.  */
name|XtEdgeType
name|top
decl_stmt|,
name|bottom
decl_stmt|,
comment|/* where to drag edge on resize		*/
name|left
decl_stmt|,
name|right
decl_stmt|;
name|int
name|dx
decl_stmt|;
comment|/* desired horiz offset			*/
name|int
name|dy
decl_stmt|;
comment|/* desired vertical offset		*/
name|Widget
name|horiz_base
decl_stmt|;
comment|/* measure dx from here if non-null	*/
name|Widget
name|vert_base
decl_stmt|;
comment|/* measure dy from here if non-null	*/
name|Boolean
name|allow_resize
decl_stmt|;
comment|/* TRUE if child may request resize	*/
comment|/*  * Private contstraint resources.  */
comment|/*  * What the size of this child would be if we did not impose the   * constraint the width and height must be greater than zero (0).  */
name|short
name|virtual_width
decl_stmt|,
name|virtual_height
decl_stmt|;
comment|/*  * Temporary Storage for children's new possible possition.  */
name|Position
name|new_x
decl_stmt|,
name|new_y
decl_stmt|;
name|LayoutState
name|layout_state
decl_stmt|;
comment|/* temporary layout state		*/
name|Boolean
name|deferred_resize
decl_stmt|;
comment|/* was resized while no_refigure is set */
block|}
name|FormConstraintsPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_FormConstraintsRec
block|{
name|FormConstraintsPart
name|form
decl_stmt|;
block|}
name|FormConstraintsRec
operator|,
typedef|*
name|FormConstraints
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawFormP_h */
end_comment

end_unit

