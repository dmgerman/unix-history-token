begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: Box.h,v 1.21 91/05/04 18:58:58 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawBox_h
end_ifndef

begin_define
define|#
directive|define
name|_XawBox_h
end_define

begin_include
include|#
directive|include
file|<X11/Xmu/Converters.h>
end_include

begin_comment
comment|/***********************************************************************  *  * Box Widget (subclass of CompositeClass)  *  ***********************************************************************/
end_comment

begin_comment
comment|/* Parameters:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		Pixel		XtDefaultBackground  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  destroyCallback     Callback		Pointer		NULL  hSpace 	     HSpace		Dimension	4  height		     Height		Dimension	0  mappedWhenManaged   MappedWhenManaged	Boolean		True  orientation	     Orientation	XtOrientation	vertical  vSpace 	     VSpace		Dimension	4  width		     Width		Dimension	0  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_comment
comment|/* New fields */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

begin_define
define|#
directive|define
name|XtNhSpace
value|"hSpace"
end_define

begin_define
define|#
directive|define
name|XtNvSpace
value|"vSpace"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Class record constants */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|boxWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_BoxClassRec
modifier|*
name|BoxWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_BoxRec
modifier|*
name|BoxWidget
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawBox_h */
end_comment

end_unit

