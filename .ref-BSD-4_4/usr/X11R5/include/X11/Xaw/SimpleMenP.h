begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: SimpleMenP.h,v 1.12 89/12/11 15:01:39 kit Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * SimpleMenuP.h - Private Header file for SimpleMenu widget.  *  * Date:    April 3, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium  *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SimpleMenuP_h
end_ifndef

begin_define
define|#
directive|define
name|_SimpleMenuP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleMenu.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SmeP.h>
end_include

begin_include
include|#
directive|include
file|<X11/ShellP.h>
end_include

begin_define
define|#
directive|define
name|ForAllChildren
parameter_list|(
name|smw
parameter_list|,
name|childP
parameter_list|)
define|\
value|for ( (childP) = (SmeObject *) (smw)->composite.children ; \         (childP)< (SmeObject *) ( (smw)->composite.children + \ 				 (smw)->composite.num_children ) ; \         (childP)++ )
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtPointer
name|extension
decl_stmt|;
comment|/* For future needs. */
block|}
name|SimpleMenuClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SimpleMenuClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|ShellClassPart
name|shell_class
decl_stmt|;
name|OverrideShellClassPart
name|override_shell_class
decl_stmt|;
name|SimpleMenuClassPart
name|simpleMenu_class
decl_stmt|;
block|}
name|SimpleMenuClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SimpleMenuClassRec
name|simpleMenuClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|_SimpleMenuPart
block|{
comment|/* resources */
name|String
name|label_string
decl_stmt|;
comment|/* The string for the label or NULL. */
name|SmeObject
name|label
decl_stmt|;
comment|/* If label_string is non-NULL then this is 				   the label widget. */
name|WidgetClass
name|label_class
decl_stmt|;
comment|/* Widget Class of the menu label object. */
name|Dimension
name|top_margin
decl_stmt|;
comment|/* Top and bottom margins. */
name|Dimension
name|bottom_margin
decl_stmt|;
name|Dimension
name|row_height
decl_stmt|;
comment|/* height of each row (menu entry) */
name|Cursor
name|cursor
decl_stmt|;
comment|/* The menu's cursor. */
name|SmeObject
name|popup_entry
decl_stmt|;
comment|/* The entry to position the cursor on for 				   when using XawPositionSimpleMenu. */
name|Boolean
name|menu_on_screen
decl_stmt|;
comment|/* Force the menus to be fully on the screen.*/
name|int
name|backing_store
decl_stmt|;
comment|/* What type of backing store to use. */
comment|/* private state */
name|Boolean
name|recursive_set_values
decl_stmt|;
comment|/* contain a possible infinite loop. */
name|Boolean
name|menu_width
decl_stmt|;
comment|/* If true then force width to remain  				   core.width */
name|Boolean
name|menu_height
decl_stmt|;
comment|/* Just like menu_width, but for height. */
name|SmeObject
name|entry_set
decl_stmt|;
comment|/* The entry that is currently set or 				   highlighted. */
block|}
name|SimpleMenuPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SimpleMenuRec
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|ShellPart
name|shell
decl_stmt|;
name|OverrideShellPart
name|override
decl_stmt|;
name|SimpleMenuPart
name|simple_menu
decl_stmt|;
block|}
name|SimpleMenuRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SimpleMenuP_h */
end_comment

end_unit

