begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: SmeP.h,v 1.4 89/12/11 15:20:22 kit Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * SmeP.h - Private Header file for Sme object.  *  * This is the private header file for the Athena Sme object.  * This object is intended to be used with the simple menu widget.    *  * Date:    April 3, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawSmeP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawSmeP_h
end_define

begin_comment
comment|/***********************************************************************  *  * Sme Widget Private Data  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/RectObjP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Sme.h>
end_include

begin_comment
comment|/************************************************************  *  * New fields for the Sme widget class record.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SmeClassPart
block|{
name|void
function_decl|(
modifier|*
name|highlight
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|unhighlight
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|notify
function_decl|)
parameter_list|()
function_decl|;
name|XtPointer
name|extension
decl_stmt|;
block|}
name|SmeClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SmeClassRec
block|{
name|RectObjClassPart
name|rect_class
decl_stmt|;
name|SmeClassPart
name|sme_class
decl_stmt|;
block|}
name|SmeClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SmeClassRec
name|smeClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the Sme widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|XtCallbackList
name|callbacks
decl_stmt|;
comment|/* The callback list */
block|}
name|SmePart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SmeRec
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
block|}
name|SmeRec
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  * Private declarations.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|_XawEntryVoidFunc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|XtInheritHighlight
value|((_XawEntryVoidFunc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritUnhighlight
value|XtInheritHighlight
end_define

begin_define
define|#
directive|define
name|XtInheritNotify
value|XtInheritHighlight
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawSmeP_h */
end_comment

end_unit

