begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: LabelP.h,v 1.27 91/06/22 19:34:58 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*   * LabelP.h - Private definitions for Label widget  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawLabelP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawLabelP_h
end_define

begin_comment
comment|/***********************************************************************  *  * Label Widget Private Data  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/Label.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_comment
comment|/* New fields for the Label widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|foo
decl_stmt|;
block|}
name|LabelClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_LabelClassRec
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
block|}
name|LabelClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|LabelClassRec
name|labelClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the Label widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|Pixel
name|foreground
decl_stmt|;
name|XFontStruct
modifier|*
name|font
decl_stmt|;
name|char
modifier|*
name|label
decl_stmt|;
name|XtJustify
name|justify
decl_stmt|;
name|Dimension
name|internal_width
decl_stmt|;
name|Dimension
name|internal_height
decl_stmt|;
name|Pixmap
name|pixmap
decl_stmt|;
name|Boolean
name|resize
decl_stmt|;
name|unsigned
name|char
name|encoding
decl_stmt|;
name|Pixmap
name|left_bitmap
decl_stmt|;
comment|/* private state */
name|GC
name|normal_GC
decl_stmt|;
name|GC
name|gray_GC
decl_stmt|;
name|Pixmap
name|stipple
decl_stmt|;
name|Position
name|label_x
decl_stmt|;
name|Position
name|label_y
decl_stmt|;
name|Dimension
name|label_width
decl_stmt|;
name|Dimension
name|label_height
decl_stmt|;
name|Dimension
name|label_len
decl_stmt|;
name|int
name|lbm_y
decl_stmt|;
comment|/* where in label */
name|unsigned
name|int
name|lbm_width
decl_stmt|,
name|lbm_height
decl_stmt|;
comment|/* size of pixmap */
block|}
name|LabelPart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_LabelRec
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
block|}
name|LabelRec
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LEFT_OFFSET
parameter_list|(
name|lw
parameter_list|)
value|((lw)->label.left_bitmap \ 			 ? (lw)->label.lbm_width + (lw)->label.internal_width \ 			 : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawLabelP_h */
end_comment

end_unit

