begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: ToggleP.h,v 1.8 91/06/20 16:15:51 converse Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*   * ToggleP.h - Private definitions for Toggle widget  *   * Author: Chris D. Peterson  *         MIT X Consortium  *         kit@expo.lcs.mit.edu  *    * Date:   January 12, 1989  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawToggleP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawToggleP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Toggle.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/CommandP.h>
end_include

begin_comment
comment|/***********************************************************************  *  * Toggle Widget Private Data  *  ***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|streq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|( strcmp((a), (b)) == 0 )
end_define

begin_typedef
typedef|typedef
struct|struct
name|_RadioGroup
block|{
name|struct
name|_RadioGroup
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
comment|/* Pointers to other elements in group. */
name|Widget
name|widget
decl_stmt|;
comment|/* Widget corrosponding to this element. */
block|}
name|RadioGroup
typedef|;
end_typedef

begin_comment
comment|/************************************  *  *  Class structure  *  ***********************************/
end_comment

begin_comment
comment|/* New fields for the Toggle widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ToggleClass
block|{
name|XtActionProc
name|Set
decl_stmt|;
name|XtActionProc
name|Unset
decl_stmt|;
name|XtPointer
name|extension
decl_stmt|;
block|}
name|ToggleClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ToggleClassRec
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
name|ToggleClassPart
name|toggle_class
decl_stmt|;
block|}
name|ToggleClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ToggleClassRec
name|toggleClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************************  *  *  Instance (widget) structure   *  **************************************/
end_comment

begin_comment
comment|/* New fields for the Toggle widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|Widget
name|widget
decl_stmt|;
name|XtPointer
name|radio_data
decl_stmt|;
comment|/* private data */
name|RadioGroup
modifier|*
name|radio_group
decl_stmt|;
block|}
name|TogglePart
typedef|;
end_typedef

begin_comment
comment|/* Full widget declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ToggleRec
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
name|TogglePart
name|toggle
decl_stmt|;
block|}
name|ToggleRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawToggleP_h */
end_comment

end_unit

