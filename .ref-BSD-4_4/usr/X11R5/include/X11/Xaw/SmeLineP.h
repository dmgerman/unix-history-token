begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: SmeLineP.h,v 1.3 89/12/11 15:20:20 kit Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Chris D. Peterson, MIT X Consortium  */
end_comment

begin_comment
comment|/*   * SmeLineP.h - Private definitions for SmeLine widget  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawSmeLineP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawSmeLineP_h
end_define

begin_comment
comment|/***********************************************************************  *  * SmeLine Widget Private Data  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/SmeP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SmeLine.h>
end_include

begin_comment
comment|/************************************************************  *  * New fields for the SmeLine widget class record.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SmeLineClassPart
block|{
name|XtPointer
name|extension
decl_stmt|;
block|}
name|SmeLineClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SmeLineClassRec
block|{
name|RectObjClassPart
name|rect_class
decl_stmt|;
name|SmeClassPart
name|sme_class
decl_stmt|;
name|SmeLineClassPart
name|sme_line_class
decl_stmt|;
block|}
name|SmeLineClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SmeLineClassRec
name|smeLineClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the SmeLine widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|Pixel
name|foreground
decl_stmt|;
comment|/* Foreground color. */
name|Pixmap
name|stipple
decl_stmt|;
comment|/* Line Stipple. */
name|Dimension
name|line_width
decl_stmt|;
comment|/* Width of the line. */
comment|/* private data.  */
name|GC
name|gc
decl_stmt|;
comment|/* Graphics context for drawing line. */
block|}
name|SmeLinePart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SmeLineRec
block|{
name|ObjectPart
name|object
decl_stmt|;
name|RectObjPart
name|rectangle
decl_stmt|;
name|SmePart
name|sme
decl_stmt|;
name|SmeLinePart
name|sme_line
decl_stmt|;
block|}
name|SmeLineRec
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  * Private declarations.  *  ************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawSmeLineP_h */
end_comment

end_unit

