begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: List.h,v 1.20 91/07/26 20:07:51 converse Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  This is the List widget, it is useful to display a list, without the  *  overhead of having a widget for each item in the list.  It allows   *  the user to select an item in a list and notifies the application through  *  a callback function.  *  *	Created: 	8/13/88  *	By:		Chris D. Peterson  *                      MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawList_h
end_ifndef

begin_define
define|#
directive|define
name|_XawList_h
end_define

begin_comment
comment|/***********************************************************************  *  * List Widget  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/Simple.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		Pixel		XtDefaultBackground  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  callback            Callback           XtCallbackList  NULL       **6  columnSpacing       Spacing            Dimension       6  cursor		     Cursor		Cursor		left_ptr  cursorName	     Cursor		String		NULL  defaultColumns      Columns            int             2          **5  destroyCallback     Callback		Pointer		NULL   font		     Font		XFontStruct*	XtDefaultFont  forceColumns        Columns            Boolean         False      **5  foreground	     Foreground		Pixel		XtDefaultForeground  height		     Height		Dimension	0          **1  insensitiveBorder   Insensitive	Pixmap		Gray  internalHeight	     Height		Dimension	2  internalWidth	     Width		Dimension	4  list                List               String *        NULL       **2  longest             Longest            int             0          **3  **4  mappedWhenManaged   MappedWhenManaged	Boolean		True  numberStrings       NumberStrings      int             0          **4  pasteBuffer         Boolean            Boolean         False  pointerColor	     Foreground		Pixel		XtDefaultForeground  pointerColorBackground Background	Pixel		XtDefaultBackground  rowSpacing          Spacing            Dimension       4  sensitive	     Sensitive		Boolean		True  verticalList        Boolean            Boolean         False  width		     Width		Dimension	0          **1  x		     Position		Position	0  y		     Position		Position	0   **1 - If the Width or Height of the list widget is zero (0) then the value        is set to the minimum size necessay to fit the entire list.         If both Width and Height are zero then they are adjusted to fit the        entire list that is created width the number of default columns         specified in the defaultColumns resource.   **2 - This is an array of strings the specify elements of the list.        This resource must be specified.         (What good is a list widget without a list??  :-)   **3 - Longest is the length of the widest string in pixels.   **4 - If either of these values are zero (0) then the list widget calculates        the correct value.          (This allows you to make startup faster if you already have          this information calculated)         NOTE: If the numberStrings value is zero the list must               be NULL terminated.   **5 - By setting the List.Columns resource you can force the application to        have a given number of columns.	                **6 - This returns the name and index of the item selected in an         XawListReturnStruct that is pointed to by the client_data        in the CallbackProc.  */
end_comment

begin_comment
comment|/*  * Value returned when there are no highlighted objects.   */
end_comment

begin_define
define|#
directive|define
name|XAW_LIST_NONE
value|-1
end_define

begin_define
define|#
directive|define
name|XtCList
value|"List"
end_define

begin_define
define|#
directive|define
name|XtCSpacing
value|"Spacing"
end_define

begin_define
define|#
directive|define
name|XtCColumns
value|"Columns"
end_define

begin_define
define|#
directive|define
name|XtCLongest
value|"Longest"
end_define

begin_define
define|#
directive|define
name|XtCNumberStrings
value|"NumberStrings"
end_define

begin_define
define|#
directive|define
name|XtNcursor
value|"cursor"
end_define

begin_define
define|#
directive|define
name|XtNcolumnSpacing
value|"columnSpacing"
end_define

begin_define
define|#
directive|define
name|XtNdefaultColumns
value|"defaultColumns"
end_define

begin_define
define|#
directive|define
name|XtNforceColumns
value|"forceColumns"
end_define

begin_define
define|#
directive|define
name|XtNlist
value|"list"
end_define

begin_define
define|#
directive|define
name|XtNlongest
value|"longest"
end_define

begin_define
define|#
directive|define
name|XtNnumberStrings
value|"numberStrings"
end_define

begin_define
define|#
directive|define
name|XtNpasteBuffer
value|"pasteBuffer"
end_define

begin_define
define|#
directive|define
name|XtNrowSpacing
value|"rowSpacing"
end_define

begin_define
define|#
directive|define
name|XtNverticalList
value|"verticalList"
end_define

begin_comment
comment|/* Class record constants */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|listWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_ListClassRec
modifier|*
name|ListWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ListRec
modifier|*
name|ListWidget
typedef|;
end_typedef

begin_comment
comment|/* The list return structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XawListReturnStruct
block|{
name|String
name|string
decl_stmt|;
name|int
name|list_index
decl_stmt|;
block|}
name|XawListReturnStruct
typedef|;
end_typedef

begin_comment
comment|/******************************************************************  *  * Exported Functions  *  *****************************************************************/
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/*	Function Name: XawListChange.  *	Description: Changes the list being used and shown.  *	Arguments: w - the list widget.  *                 list - the new list.  *                 nitems - the number of items in the list.  *                 longest - the length (in Pixels) of the longest element  *                           in the list.  *                 resize - if TRUE the the list widget will  *                          try to resize itself.  *	Returns: none.  *      NOTE:      If nitems of longest are<= 0 then they will be caluculated.  *                 If nitems is<= 0 then the list needs to be NULL terminated.  */
specifier|extern
name|void
name|XawListChange
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|String
modifier|*
comment|/* list */
parameter_list|,
name|int
comment|/* nitems */
parameter_list|,
name|int
comment|/* longest */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* Boolean */
name|int
comment|/* resize */
else|#
directive|else
name|Boolean
comment|/* resize */
endif|#
directive|endif
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawListUnhighlight  *	Description: unlights the current highlighted element.  *	Arguments: w - the widget.  *	Returns: none.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawListUnhighlight
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
comment|/*	Function Name: XawListHighlight  *	Description: Highlights the given item.  *	Arguments: w - the list widget.  *                 item - the item to highlight.  *	Returns: none.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawListHighlight
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|int
comment|/* item */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawListShowCurrent  *	Description: returns the currently highlighted object.  *	Arguments: w - the list widget.  *	Returns: the info about the currently highlighted object.  */
end_comment

begin_function_decl
specifier|extern
name|XawListReturnStruct
modifier|*
name|XawListShowCurrent
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
comment|/* _XawList_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

