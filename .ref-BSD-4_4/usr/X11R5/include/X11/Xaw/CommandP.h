begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: CommandP.h,v 1.30 90/12/01 13:00:10 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*   * CommandP.h - Private definitions for Command widget  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawCommandP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawCommandP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Command.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/LabelP.h>
end_include

begin_comment
comment|/***********************************************************************  *  * Command Widget Private Data  *  ***********************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HighlightNone
block|,
comment|/* Do not highlight. */
name|HighlightWhenUnset
block|,
comment|/* Highlight only when unset, this is 				   to preserve current command widget  				   functionality. */
name|HighlightAlways
comment|/* Always highlight, lets the toggle widget 				   and other subclasses do the right thing. */
block|}
name|XtCommandHighlight
typedef|;
end_typedef

begin_comment
comment|/************************************  *  *  Class structure  *  ***********************************/
end_comment

begin_comment
comment|/* New fields for the Command widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CommandClass
block|{
name|int
name|makes_compiler_happy
decl_stmt|;
comment|/* not used */
block|}
name|CommandClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CommandClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|LabelClassPart
name|label_class
decl_stmt|;
name|CommandClassPart
name|command_class
decl_stmt|;
block|}
name|CommandClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|CommandClassRec
name|commandClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************************  *  *  Instance (widget) structure   *  **************************************/
end_comment

begin_comment
comment|/* New fields for the Command widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|Dimension
name|highlight_thickness
decl_stmt|;
name|XtCallbackList
name|callbacks
decl_stmt|;
comment|/* private state */
name|Pixmap
name|gray_pixmap
decl_stmt|;
name|GC
name|normal_GC
decl_stmt|;
name|GC
name|inverse_GC
decl_stmt|;
name|Boolean
name|set
decl_stmt|;
name|XtCommandHighlight
name|highlighted
decl_stmt|;
comment|/* more resources */
name|int
name|shape_style
decl_stmt|;
name|Dimension
name|corner_round
decl_stmt|;
block|}
name|CommandPart
typedef|;
end_typedef

begin_comment
comment|/*    XtEventsPtr eventTable;*/
end_comment

begin_comment
comment|/* Full widget declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CommandRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|LabelPart
name|label
decl_stmt|;
name|CommandPart
name|command
decl_stmt|;
block|}
name|CommandRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawCommandP_h */
end_comment

end_unit

