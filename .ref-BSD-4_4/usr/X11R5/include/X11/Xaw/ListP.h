begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: ListP.h,v 1.12 89/12/11 15:09:04 kit Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Chris D. Peterson, MIT X Consortium  */
end_comment

begin_comment
comment|/*   * ListP.h - Private definitions for List widget  *   * This is the List widget, it is useful to display a list, without the  * overhead of having a widget for each item in the list.  It allows   * the user to select an item in a list and notifies the application through  * a callback function.  *  *	Created: 	8/13/88  *	By:		Chris D. Peterson  *                      MIT - Project Athena  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawListP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawListP_h
end_define

begin_comment
comment|/***********************************************************************  *  * List Widget Private Data  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/List.h>
end_include

begin_define
define|#
directive|define
name|NO_HIGHLIGHT
value|XAW_LIST_NONE
end_define

begin_define
define|#
directive|define
name|OUT_OF_RANGE
value|-1
end_define

begin_define
define|#
directive|define
name|OKAY
value|0
end_define

begin_comment
comment|/* New fields for the List widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|foo
decl_stmt|;
block|}
name|ListClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ListClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|ListClassPart
name|list_class
decl_stmt|;
block|}
name|ListClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ListClassRec
name|listClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the List widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|Pixel
name|foreground
decl_stmt|;
name|Dimension
name|internal_width
decl_stmt|,
name|internal_height
decl_stmt|,
name|column_space
decl_stmt|,
name|row_space
decl_stmt|;
name|int
name|default_cols
decl_stmt|;
name|Boolean
name|force_cols
decl_stmt|,
name|paste
decl_stmt|,
name|vertical_cols
decl_stmt|;
name|int
name|longest
decl_stmt|;
name|int
name|nitems
decl_stmt|;
comment|/* number of items in the list. */
name|XFontStruct
modifier|*
name|font
decl_stmt|;
name|String
modifier|*
name|list
decl_stmt|;
name|XtCallbackList
name|callback
decl_stmt|;
comment|/* private state */
name|int
name|is_highlighted
decl_stmt|,
comment|/* set to the item currently highlighted. */
name|highlight
decl_stmt|,
comment|/*set to the item that should be highlighted.*/
name|col_width
decl_stmt|,
comment|/* width of each column. */
name|row_height
decl_stmt|,
comment|/* height of each row. */
name|nrows
decl_stmt|,
comment|/* number of rows in the list. */
name|ncols
decl_stmt|;
comment|/* number of columns in the list. */
name|GC
name|normgc
decl_stmt|,
comment|/* a couple o' GC's. */
name|revgc
decl_stmt|,
name|graygc
decl_stmt|;
comment|/* used when inactive. */
block|}
name|ListPart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ListRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|ListPart
name|list
decl_stmt|;
block|}
name|ListRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawListP_h */
end_comment

end_unit

