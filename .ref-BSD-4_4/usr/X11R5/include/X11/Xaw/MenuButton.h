begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: MenuButton.h,v 1.7 89/12/11 14:57:44 kit Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/***********************************************************************  *  * MenuButton Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/*  * MenuButton.h - Public Header file for MenuButton widget.  *  * This is the public header file for the Athena MenuButton widget.  * It is intended to provide an easy method of activating pulldown menus.  *  * Date:    May 2, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawMenuButton_h
end_ifndef

begin_define
define|#
directive|define
name|_XawMenuButton_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Command.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		Pixel		XtDefaultBackground  bitmap		     Pixmap		Pixmap		None  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  callback	     Callback		Pointer		NULL  cursor		     Cursor		Cursor		None  destroyCallback     Callback		Pointer		NULL  font		     Font		XFontStruct*	XtDefaultFont  foreground	     Foreground		Pixel		XtDefaultForeground  height		     Height		Dimension	text height  highlightThickness  Thickness		Dimension	2  insensitiveBorder   Insensitive	Pixmap		Gray  internalHeight	     Height		Dimension	2  internalWidth	     Width		Dimension	4  justify	     Justify		XtJustify	XtJustifyCenter  label		     Label		String		NULL  mappedWhenManaged   MappedWhenManaged	Boolean		True  menuName            MenuName           String          "menu"  resize		     Resize		Boolean		True  sensitive	     Sensitive		Boolean		True  width		     Width		Dimension	text width  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_define
define|#
directive|define
name|XtNmenuName
value|"menuName"
end_define

begin_define
define|#
directive|define
name|XtCMenuName
value|"MenuName"
end_define

begin_decl_stmt
specifier|extern
name|WidgetClass
name|menuButtonWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_MenuButtonClassRec
modifier|*
name|MenuButtonWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_MenuButtonRec
modifier|*
name|MenuButtonWidget
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawMenuButton_h --  DON'T ADD STUFF AFTER THIS */
end_comment

end_unit

