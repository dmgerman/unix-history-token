begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: MenuButtoP.h,v 1.6 89/12/11 14:57:23 kit Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/***********************************************************************  *  * MenuButton Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/*  * MenuButtonP.h - Private Header file for MenuButton widget.  *  * This is the private header file for the Athena MenuButton widget.  * It is intended to provide an easy method of activating pulldown menus.  *  * Date:    May 2, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawMenuButtonP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawtMenuButtonP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/MenuButton.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/CommandP.h>
end_include

begin_comment
comment|/************************************  *  *  Class structure  *  ***********************************/
end_comment

begin_comment
comment|/* New fields for the MenuButton widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MenuButtonClass
block|{
name|int
name|makes_compiler_happy
decl_stmt|;
comment|/* not used */
block|}
name|MenuButtonClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MenuButtonClassRec
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
name|MenuButtonClassPart
name|menuButton_class
decl_stmt|;
block|}
name|MenuButtonClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|MenuButtonClassRec
name|menuButtonClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************************  *  *  Instance (widget) structure   *  **************************************/
end_comment

begin_comment
comment|/* New fields for the MenuButton widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|String
name|menu_name
decl_stmt|;
block|}
name|MenuButtonPart
typedef|;
end_typedef

begin_comment
comment|/* Full widget declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MenuButtonRec
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
name|MenuButtonPart
name|menu_button
decl_stmt|;
block|}
name|MenuButtonRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawMenuButtonP_h */
end_comment

end_unit

