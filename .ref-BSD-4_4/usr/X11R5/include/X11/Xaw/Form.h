begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Form.h,v 1.28 91/05/04 18:59:10 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawForm_h
end_ifndef

begin_define
define|#
directive|define
name|_XawForm_h
end_define

begin_include
include|#
directive|include
file|<X11/Constraint.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/***********************************************************************  *  * Form Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/* Parameters:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		Pixel		XtDefaultBackground  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  defaultDistance     Thickness		int		4  destroyCallback     Callback		Pointer		NULL  height		     Height		Dimension	computed at realize  mappedWhenManaged   MappedWhenManaged	Boolean		True  sensitive	     Sensitive		Boolean		True  width		     Width		Dimension	computed at realize  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_comment
comment|/* Constraint parameters:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  bottom		     Edge		XtEdgeType	XtRubber  fromHoriz	     Widget		Widget		(left edge of form)  fromVert	     Widget		Widget		(top of form)  horizDistance	     Thickness		int		defaultDistance  left		     Edge		XtEdgeType	XtRubber  resizable	     Boolean		Boolean		False  right		     Edge		XtEdgeType	XtRubber  top		     Edge		XtEdgeType	XtRubber  vertDistance	     Thickness		int		defaultDistance  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

begin_define
define|#
directive|define
name|XtNtop
value|"top"
end_define

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
name|XtNdefaultDistance
value|"defaultDistance"
end_define

begin_define
define|#
directive|define
name|XtNbottom
value|"bottom"
end_define

begin_define
define|#
directive|define
name|XtNleft
value|"left"
end_define

begin_define
define|#
directive|define
name|XtNright
value|"right"
end_define

begin_define
define|#
directive|define
name|XtNfromHoriz
value|"fromHoriz"
end_define

begin_define
define|#
directive|define
name|XtNfromVert
value|"fromVert"
end_define

begin_define
define|#
directive|define
name|XtNhorizDistance
value|"horizDistance"
end_define

begin_define
define|#
directive|define
name|XtNvertDistance
value|"vertDistance"
end_define

begin_define
define|#
directive|define
name|XtNresizable
value|"resizable"
end_define

begin_define
define|#
directive|define
name|XtCEdge
value|"Edge"
end_define

begin_define
define|#
directive|define
name|XtCWidget
value|"Widget"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_XawEdgeType_e
end_ifndef

begin_define
define|#
directive|define
name|_XawEdgeType_e
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawChainTop
block|,
comment|/* Keep this edge a constant distance from 				   the top of the form */
name|XawChainBottom
block|,
comment|/* Keep this edge a constant distance from 				   the bottom of the form */
name|XawChainLeft
block|,
comment|/* Keep this edge a constant distance from 				   the left of the form */
name|XawChainRight
block|,
comment|/* Keep this edge a constant distance from 				   the right of the form */
name|XawRubber
comment|/* Keep this edge a proportional distance 				   from the edges of the form*/
block|}
name|XawEdgeType
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawEdgeType_e */
end_comment

begin_comment
comment|/*  * Unfortunatly I missed this definition for R4, so I cannot  * protect it with XAW_BC, it looks like this particular problem is  * one that we will have to live with for a while.  *  * Chris D. Peterson - 3/23/90.  */
end_comment

begin_define
define|#
directive|define
name|XtEdgeType
value|XawEdgeType
end_define

begin_define
define|#
directive|define
name|XtChainTop
value|XawChainTop
end_define

begin_define
define|#
directive|define
name|XtChainBottom
value|XawChainBottom
end_define

begin_define
define|#
directive|define
name|XtChainLeft
value|XawChainLeft
end_define

begin_define
define|#
directive|define
name|XtChainRight
value|XawChainRight
end_define

begin_define
define|#
directive|define
name|XtRubber
value|XawRubber
end_define

begin_typedef
typedef|typedef
name|struct
name|_FormClassRec
modifier|*
name|FormWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_FormRec
modifier|*
name|FormWidget
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|formWidgetClass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XawFormDoLayout
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* Boolean */
name|int
comment|/* do_layout */
else|#
directive|else
name|Boolean
comment|/* do_layout */
endif|#
directive|endif
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
comment|/* _XawForm_h */
end_comment

end_unit

