begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: ViewportP.h,v 1.13 90/02/13 14:04:14 jim Exp $  * Private declarations for ViewportWidgetClass  */
end_comment

begin_comment
comment|/************************************************************ Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ********************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ViewportP_h
end_ifndef

begin_define
define|#
directive|define
name|_ViewportP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Viewport.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/FormP.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|ViewportClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ViewportClassRec
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
name|ViewportClassPart
name|viewport_class
decl_stmt|;
block|}
name|ViewportClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ViewportClassRec
name|viewportClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|_ViewportPart
block|{
comment|/* resources */
name|Boolean
name|forcebars
decl_stmt|;
comment|/* Whether we should always display */
comment|/* the selected scrollbars. */
name|Boolean
name|allowhoriz
decl_stmt|;
comment|/* Whether we allow horizontal scrollbars. */
name|Boolean
name|allowvert
decl_stmt|;
comment|/* Whether we allow vertical scrollbars. */
name|Boolean
name|usebottom
decl_stmt|;
comment|/* True iff horiz bars appear at bottom. */
name|Boolean
name|useright
decl_stmt|;
comment|/* True iff vert bars appear at right. */
name|XtCallbackList
name|report_callbacks
decl_stmt|;
comment|/* when size/position changes */
comment|/* private state */
name|Widget
name|clip
decl_stmt|,
name|child
decl_stmt|;
comment|/* The clipping and (scrolled) child widgets */
name|Widget
name|horiz_bar
decl_stmt|,
name|vert_bar
decl_stmt|;
comment|/* What scrollbars we currently have. */
block|}
name|ViewportPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ViewportRec
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
name|ViewportPart
name|viewport
decl_stmt|;
block|}
name|ViewportRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
comment|/* private state */
name|Boolean
name|reparented
decl_stmt|;
comment|/* True if child has been re-parented */
block|}
name|ViewportConstraintsPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ViewportConstraintsRec
block|{
name|FormConstraintsPart
name|form
decl_stmt|;
name|ViewportConstraintsPart
name|viewport
decl_stmt|;
block|}
name|ViewportConstraintsRec
operator|,
typedef|*
name|ViewportConstraints
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ViewportP_h */
end_comment

end_unit

