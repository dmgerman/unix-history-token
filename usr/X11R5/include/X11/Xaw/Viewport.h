begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Viewport.h,v 1.21 91/07/22 19:05:23 converse Exp $ */
end_comment

begin_comment
comment|/************************************************************ Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ********************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawViewport_h
end_ifndef

begin_define
define|#
directive|define
name|_XawViewport_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Form.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Reports.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  allowHoriz	     Boolean		Boolean		False  allowVert	     Boolean		Boolean		False  background	     Background		Pixel		XtDefaultBackground  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  destroyCallback     Callback		Pointer		NULL  foreceBars	     Boolean		Boolean		False  height		     Height		Dimension	0  mappedWhenManaged   MappedWhenManaged	Boolean		True  reportCallback	     ReportCallback	Pointer		NULL  sensitive	     Sensitive		Boolean		True  useBottom	     Boolean		Boolean		False  useRight	     Boolean		Boolean		False  width		     Width		Dimension	0  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_comment
comment|/* fields added to Form */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

begin_define
define|#
directive|define
name|XtNforceBars
value|"forceBars"
end_define

begin_define
define|#
directive|define
name|XtNallowHoriz
value|"allowHoriz"
end_define

begin_define
define|#
directive|define
name|XtNallowVert
value|"allowVert"
end_define

begin_define
define|#
directive|define
name|XtNuseBottom
value|"useBottom"
end_define

begin_define
define|#
directive|define
name|XtNuseRight
value|"useRight"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|WidgetClass
name|viewportWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_ViewportClassRec
modifier|*
name|ViewportWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ViewportRec
modifier|*
name|ViewportWidget
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XawViewportSetLocation
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* gw */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* float */
name|double
comment|/* xoff */
parameter_list|,
comment|/* float */
name|double
comment|/* yoff */
else|#
directive|else
name|float
comment|/* xoff */
parameter_list|,
name|float
comment|/* yoff */
endif|#
directive|endif
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XawViewportSetCoordinates
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* gw */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* Position */
name|int
comment|/* x */
parameter_list|,
comment|/* Position */
name|int
comment|/* y */
else|#
directive|else
name|Position
comment|/* x */
parameter_list|,
name|Position
comment|/* y */
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
comment|/* _XawViewport_h */
end_comment

end_unit

