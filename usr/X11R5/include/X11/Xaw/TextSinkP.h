begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: TextSinkP.h,v 1.4 90/04/30 17:46:39 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*   * TextSinkP.h - Private definitions for TextSink object  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawTextSinkP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawTextSinkP_h
end_define

begin_comment
comment|/***********************************************************************  *  * TextSink Object Private Data  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/ObjectP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/TextP.h>
end_include

begin_comment
comment|/* This source works with the Text widget. */
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/TextSrcP.h>
end_include

begin_comment
comment|/* This source works with the Text Source. */
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/TextSink.h>
end_include

begin_comment
comment|/************************************************************  *  * New fields for the TextSink object class record.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TextSinkClassPart
block|{
name|void
function_decl|(
modifier|*
name|DisplayText
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|InsertCursor
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|ClearToBackground
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|FindPosition
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|FindDistance
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|Resolve
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|MaxLines
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|MaxHeight
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|SetTabs
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|GetCursorBounds
function_decl|)
parameter_list|()
function_decl|;
block|}
name|TextSinkClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TextSinkClassRec
block|{
name|ObjectClassPart
name|object_class
decl_stmt|;
name|TextSinkClassPart
name|text_sink_class
decl_stmt|;
block|}
name|TextSinkClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|TextSinkClassRec
name|textSinkClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the TextSink object record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|XFontStruct
modifier|*
name|font
decl_stmt|;
comment|/* Font to draw in. */
name|Pixel
name|foreground
decl_stmt|;
comment|/* Foreground color. */
name|Pixel
name|background
decl_stmt|;
comment|/* Background color. */
comment|/* private state. */
name|Position
modifier|*
name|tabs
decl_stmt|;
comment|/* The tab stops as pixel values. */
name|short
modifier|*
name|char_tabs
decl_stmt|;
comment|/* The tabs stops as character values. */
name|int
name|tab_count
decl_stmt|;
comment|/* number of items in tabs */
block|}
name|TextSinkPart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TextSinkRec
block|{
name|ObjectPart
name|object
decl_stmt|;
name|TextSinkPart
name|text_sink
decl_stmt|;
block|}
name|TextSinkRec
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  * Private declarations.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_XawSinkIntFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|_XawSinkVoidFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|XtInheritDisplayText
value|((_XawSinkVoidFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritInsertCursor
value|((_XawSinkVoidFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritClearToBackground
value|((_XawSinkVoidFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritFindPosition
value|((_XawSinkVoidFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritFindDistance
value|((_XawSinkVoidFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritResolve
value|((_XawSinkVoidFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritMaxLines
value|((_XawSinkIntFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritMaxHeight
value|((_XawSinkIntFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritSetTabs
value|((_XawSinkVoidFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritGetCursorBounds
value|((_XawSinkVoidFunc) _XtInherit)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawTextSinkP_h */
end_comment

end_unit

