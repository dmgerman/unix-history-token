begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: AsciiSinkP.h,v 1.2 89/10/04 13:56:34 kit Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*   * asciiSinkP.h - Private definitions for asciiSink object  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawAsciiSinkP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawAsciiSinkP_h
end_define

begin_comment
comment|/***********************************************************************  *  * AsciiSink Object Private Data  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/TextSinkP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/AsciiSink.h>
end_include

begin_comment
comment|/************************************************************  *  * New fields for the AsciiSink object class record.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AsciiSinkClassPart
block|{
name|int
name|foo
decl_stmt|;
block|}
name|AsciiSinkClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AsciiSinkClassRec
block|{
name|ObjectClassPart
name|object_class
decl_stmt|;
name|TextSinkClassPart
name|text_sink_class
decl_stmt|;
name|AsciiSinkClassPart
name|ascii_sink_class
decl_stmt|;
block|}
name|AsciiSinkClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|AsciiSinkClassRec
name|asciiSinkClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the AsciiSink object record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public resources */
name|Boolean
name|echo
decl_stmt|;
name|Boolean
name|display_nonprinting
decl_stmt|;
comment|/* private state */
name|GC
name|normgc
decl_stmt|,
name|invgc
decl_stmt|,
name|xorgc
decl_stmt|;
name|Pixmap
name|insertCursorOn
decl_stmt|;
name|XawTextInsertState
name|laststate
decl_stmt|;
name|short
name|cursor_x
decl_stmt|,
name|cursor_y
decl_stmt|;
comment|/* Cursor Location. */
block|}
name|AsciiSinkPart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AsciiSinkRec
block|{
name|ObjectPart
name|object
decl_stmt|;
name|TextSinkPart
name|text_sink
decl_stmt|;
name|AsciiSinkPart
name|ascii_sink
decl_stmt|;
block|}
name|AsciiSinkRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawAsciiSinkP_h */
end_comment

end_unit

