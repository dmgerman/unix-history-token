begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: SimpleMenu.h,v 1.20 91/02/17 13:18:55 rws Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Chris D. Peterson, MIT X Consortium  */
end_comment

begin_comment
comment|/*  * SimpleMenu.h - Public Header file for SimpleMenu widget.  *  * This is the public header file for the Athena SimpleMenu widget.  * It is intended to provide one pane pulldown and popup menus within  * the framework of the X Toolkit.  As the name implies it is a first and  * by no means complete implementation of menu code. It does not attempt to  * fill the needs of all applications, but does allow a resource oriented  * interface to menus.  *  * Date:    April 3, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SimpleMenu_h
end_ifndef

begin_define
define|#
directive|define
name|_SimpleMenu_h
end_define

begin_include
include|#
directive|include
file|<X11/Shell.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xmu/Converters.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/****************************************************************  *  * SimpleMenu widget  *  ****************************************************************/
end_comment

begin_comment
comment|/* SimpleMenu Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		Pixel		XtDefaultBackground  backgroundPixmap    BackgroundPixmap	Pixmap          None  borderColor	     BorderColor	Pixel		XtDefaultForeground  borderPixmap	     BorderPixmap	Pixmap		None  borderWidth	     BorderWidth	Dimension	1  bottomMargin        VerticalMargins    Dimension       VerticalSpace  columnWidth         ColumnWidth        Dimension       Width of widest text  cursor              Cursor             Cursor          None  destroyCallback     Callback		Pointer		NULL  height		     Height		Dimension	0  label               Label              String          NULL (No label)  labelClass          LabelClass         Pointer         smeBSBObjectClass  mappedWhenManaged   MappedWhenManaged	Boolean		True  rowHeight           RowHeight          Dimension       Height of Font  sensitive	     Sensitive		Boolean		True  topMargin           VerticalMargins    Dimension       VerticalSpace  width		     Width		Dimension	0  x		     Position		Position	0n  y		     Position		Position	0  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_SimpleMenuClassRec
modifier|*
name|SimpleMenuWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_SimpleMenuRec
modifier|*
name|SimpleMenuWidget
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|simpleMenuWidgetClass
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XtNcursor
value|"cursor"
end_define

begin_define
define|#
directive|define
name|XtNbottomMargin
value|"bottomMargin"
end_define

begin_define
define|#
directive|define
name|XtNcolumnWidth
value|"columnWidth"
end_define

begin_define
define|#
directive|define
name|XtNlabelClass
value|"labelClass"
end_define

begin_define
define|#
directive|define
name|XtNmenuOnScreen
value|"menuOnScreen"
end_define

begin_define
define|#
directive|define
name|XtNpopupOnEntry
value|"popupOnEntry"
end_define

begin_define
define|#
directive|define
name|XtNrowHeight
value|"rowHeight"
end_define

begin_define
define|#
directive|define
name|XtNtopMargin
value|"topMargin"
end_define

begin_define
define|#
directive|define
name|XtCColumnWidth
value|"ColumnWidth"
end_define

begin_define
define|#
directive|define
name|XtCLabelClass
value|"LabelClass"
end_define

begin_define
define|#
directive|define
name|XtCMenuOnScreen
value|"MenuOnScreen"
end_define

begin_define
define|#
directive|define
name|XtCPopupOnEntry
value|"PopupOnEntry"
end_define

begin_define
define|#
directive|define
name|XtCRowHeight
value|"RowHeight"
end_define

begin_define
define|#
directive|define
name|XtCVerticalMargins
value|"VerticalMargins"
end_define

begin_comment
comment|/************************************************************  *  * Public Functions.  *  ************************************************************/
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/*	Function Name: XawSimpleMenuAddGlobalActions  *	Description: adds the global actions to the simple menu widget.  *	Arguments: app_con - the appcontext.  *	Returns: none.  */
specifier|extern
name|void
name|XawSimpleMenuAddGlobalActions
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_con */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawSimpleMenuGetActiveEntry  *	Description: Gets the currently active (set) entry.  *	Arguments: w - the smw widget.  *	Returns: the currently set entry or NULL if none is set.  */
end_comment

begin_function_decl
specifier|extern
name|Widget
name|XawSimpleMenuGetActiveEntry
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawSimpleMenuClearActiveEntry  *	Description: Unsets the currently active (set) entry.  *	Arguments: w - the smw widget.  *	Returns: none.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawSimpleMenuClearActiveEntry
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SimpleMenu_h */
end_comment

end_unit

