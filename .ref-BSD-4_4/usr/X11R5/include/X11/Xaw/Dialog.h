begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Dialog.h,v 1.26 91/07/22 19:05:10 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawDialog_h
end_ifndef

begin_define
define|#
directive|define
name|_XawDialog_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Form.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/***********************************************************************  *  * Dialog Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/* Parameters:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		Pixel		XtDefaultBackground  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  destroyCallback     Callback		Pointer		NULL  height		     Height		Dimension	computed at create  icon		     Icon		Pixmap		0  label		     Label		String		NULL  mappedWhenManaged   MappedWhenManaged	Boolean		True  sensitive	     Sensitive		Boolean		True  value		     Value		String		NULL  width		     Width		Dimension	computed at create  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_define
define|#
directive|define
name|XtCIcon
value|"Icon"
end_define

begin_define
define|#
directive|define
name|XtNicon
value|"icon"
end_define

begin_typedef
typedef|typedef
name|struct
name|_DialogClassRec
modifier|*
name|DialogWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_DialogRec
modifier|*
name|DialogWidget
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|dialogWidgetClass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XawDialogAddButton
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* dialog */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
parameter_list|,
name|XtCallbackProc
comment|/* function */
parameter_list|,
name|XtPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XawDialogGetValueString
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
comment|/* _XawDialog_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

