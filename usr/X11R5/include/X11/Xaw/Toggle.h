begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Toggle.h,v 1.13 91/05/04 18:59:01 rws Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * ToggleP.h - Private definitions for Toggle widget  *  * Author: Chris D. Peterson  *         MIT X Consortium  *         kit@expo.lcs.mit.edu  *    * Date:   January 12, 1989  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawToggle_h
end_ifndef

begin_define
define|#
directive|define
name|_XawToggle_h
end_define

begin_comment
comment|/***********************************************************************  *  * Toggle Widget  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/Command.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  radioGroup          RadioGroup         Widget          NULL              +  radioData           RadioData          Pointer         (caddr_t) Widget  ++  state               State              Boolean         Off   background	     Background		Pixel		XtDefaultBackground  bitmap		     Pixmap		Pixmap		None  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  callback	     Callback		Pointer		NULL  cursor		     Cursor		Cursor		None  destroyCallback     Callback		Pointer		NULL  font		     Font		XFontStructx*	XtDefaultFont  foreground	     Foreground		Pixel		XtDefaultForeground  height		     Height		Dimension	text height  highlightThickness  Thickness		Dimension	2  insensitiveBorder   Insensitive	Pixmap		Gray  internalHeight	     Height		Dimension	2  internalWidth	     Width		Dimension	4  justify	     Justify		XtJustify	XtJustifyCenter  label		     Label		String		NULL  mappedWhenManaged   MappedWhenManaged	Boolean		True  resize		     Resize		Boolean		True  sensitive	     Sensitive		Boolean		True  width		     Width		Dimension	text width  x		     Position		Position	0  y		     Position		Position	0  + To use the toggle as a radio toggle button, set this resource to point to   any other widget in the radio group.  ++ This is the data returned from a call to XtToggleGetCurrent, by default    this is set to the name of toggle widget.  */
end_comment

begin_comment
comment|/*  * These should be in StringDefs.h but aren't so we will define  * them here if they are needed.  */
end_comment

begin_define
define|#
directive|define
name|XtCWidget
value|"Widget"
end_define

begin_define
define|#
directive|define
name|XtCState
value|"State"
end_define

begin_define
define|#
directive|define
name|XtCRadioGroup
value|"RadioGroup"
end_define

begin_define
define|#
directive|define
name|XtCRadioData
value|"RadioData"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

begin_define
define|#
directive|define
name|XtRWidget
value|"Widget"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XtNstate
value|"state"
end_define

begin_define
define|#
directive|define
name|XtNradioGroup
value|"radioGroup"
end_define

begin_define
define|#
directive|define
name|XtNradioData
value|"radioData"
end_define

begin_decl_stmt
specifier|extern
name|WidgetClass
name|toggleWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_ToggleClassRec
modifier|*
name|ToggleWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ToggleRec
modifier|*
name|ToggleWidget
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *   * Public Functions  *  ************************************************************/
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/*	Function Name: XawToggleChangeRadioGroup  *	Description: Allows a toggle widget to change radio lists.  *	Arguments: w - The toggle widget to change lists.  *                 radio_group - any widget in the new list.  *	Returns: none.  */
specifier|extern
name|void
name|XawToggleChangeRadioGroup
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|Widget
comment|/* radio_group */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawToggleGetCurrent  *	Description: Returns the RadioData associated with the toggle  *                   widget that is currently active in a toggle list.  *	Arguments: radio_group - any toggle widget in the toggle list.  *	Returns: The XtNradioData associated with the toggle widget.  */
end_comment

begin_function_decl
specifier|extern
name|XtPointer
name|XawToggleGetCurrent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* radio_group */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawToggleSetCurrent  *	Description: Sets the Toggle widget associated with the  *                   radio_data specified.  *	Arguments: radio_group - any toggle widget in the toggle list.  *                 radio_data - radio data of the toggle widget to set.  *	Returns: none.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawToggleSetCurrent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* radio_group */
parameter_list|,
name|XtPointer
comment|/* radio_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawToggleUnsetCurrent  *	Description: Unsets all Toggles in the radio_group specified.  *	Arguments: radio_group - any toggle widget in the toggle list.  *	Returns: none.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawToggleUnsetCurrent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* radio_group */
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
comment|/* _XawToggle_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS */
end_comment

end_unit

