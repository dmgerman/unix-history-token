begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: SmeBSBP.h,v 1.6 89/12/11 15:20:15 kit Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Chris D. Peterson, MIT X Consortium  */
end_comment

begin_comment
comment|/*   * SmeP.h - Private definitions for Sme object  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawSmeBSBP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawSmeBSBP_h
end_define

begin_comment
comment|/***********************************************************************  *  * Sme Object Private Data  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/SmeP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SmeBSB.h>
end_include

begin_comment
comment|/************************************************************  *  * New fields for the Sme Object class record.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SmeBSBClassPart
block|{
name|XtPointer
name|extension
decl_stmt|;
block|}
name|SmeBSBClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SmeBSBClassRec
block|{
name|RectObjClassPart
name|rect_class
decl_stmt|;
name|SmeClassPart
name|sme_class
decl_stmt|;
name|SmeBSBClassPart
name|sme_bsb_class
decl_stmt|;
block|}
name|SmeBSBClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SmeBSBClassRec
name|smeBSBClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the Sme Object record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|String
name|label
decl_stmt|;
comment|/* The entry label. */
name|int
name|vert_space
decl_stmt|;
comment|/* extra vert space to leave, as a percentage 				   of the font height of the label. */
name|Pixmap
name|left_bitmap
decl_stmt|,
name|right_bitmap
decl_stmt|;
comment|/* bitmaps to show. */
name|Dimension
name|left_margin
decl_stmt|,
name|right_margin
decl_stmt|;
comment|/* left and right margins. */
name|Pixel
name|foreground
decl_stmt|;
comment|/* foreground color. */
name|XFontStruct
modifier|*
name|font
decl_stmt|;
comment|/* The font to show label in. */
name|XtJustify
name|justify
decl_stmt|;
comment|/* Justification for the label. */
comment|/* private resources. */
name|Boolean
name|set_values_area_cleared
decl_stmt|;
comment|/* Remember if we need to unhighlight. */
name|GC
name|norm_gc
decl_stmt|;
comment|/* noral color gc. */
name|GC
name|rev_gc
decl_stmt|;
comment|/* reverse color gc. */
name|GC
name|norm_gray_gc
decl_stmt|;
comment|/* Normal color (grayed out) gc. */
name|GC
name|invert_gc
decl_stmt|;
comment|/* gc for flipping colors. */
name|Dimension
name|left_bitmap_width
decl_stmt|;
comment|/* size of each bitmap. */
name|Dimension
name|left_bitmap_height
decl_stmt|;
name|Dimension
name|right_bitmap_width
decl_stmt|;
name|Dimension
name|right_bitmap_height
decl_stmt|;
block|}
name|SmeBSBPart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SmeBSBRec
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
name|SmeBSBPart
name|sme_bsb
decl_stmt|;
block|}
name|SmeBSBRec
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
comment|/* _XawSmeBSBP_h */
end_comment

end_unit

