begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Label.h,v 1.31 91/07/26 19:51:37 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawLabel_h
end_ifndef

begin_define
define|#
directive|define
name|_XawLabel_h
end_define

begin_comment
comment|/***********************************************************************  *  * Label Widget  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/Simple.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		Pixel		XtDefaultBackground  bitmap		     Pixmap		Pixmap		None  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  cursor		     Cursor		Cursor		None  cursorName	     Cursor		String		NULL  destroyCallback     Callback		XtCallbackList	NULL  encoding	     Encoding		unsigned char	XawTextEncoding8bit  font		     Font		XFontStruct*	XtDefaultFont  foreground	     Foreground		Pixel		XtDefaultForeground  height		     Height		Dimension	text height  insensitiveBorder   Insensitive	Pixmap		Gray  internalHeight	     Height		Dimension	2  internalWidth	     Width		Dimension	4  justify	     Justify		XtJustify	XtJustifyCenter  label		     Label		String		NULL  leftBitmap	     LeftBitmap		Pixmap		None  mappedWhenManaged   MappedWhenManaged	Boolean		True  pointerColor	     Foreground		Pixel		XtDefaultForeground  pointerColorBackground Background	Pixel		XtDefaultBackground  resize		     Resize		Boolean		True  sensitive	     Sensitive		Boolean		True  width		     Width		Dimension	text width  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_define
define|#
directive|define
name|XawTextEncoding8bit
value|0
end_define

begin_define
define|#
directive|define
name|XawTextEncodingChar2b
value|1
end_define

begin_define
define|#
directive|define
name|XtNleftBitmap
value|"leftBitmap"
end_define

begin_define
define|#
directive|define
name|XtCLeftBitmap
value|"LeftBitmap"
end_define

begin_define
define|#
directive|define
name|XtNencoding
value|"encoding"
end_define

begin_define
define|#
directive|define
name|XtCEncoding
value|"Encoding"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

begin_define
define|#
directive|define
name|XtNbitmap
value|"bitmap"
end_define

begin_define
define|#
directive|define
name|XtNforeground
value|"foreground"
end_define

begin_define
define|#
directive|define
name|XtNlabel
value|"label"
end_define

begin_define
define|#
directive|define
name|XtNfont
value|"font"
end_define

begin_define
define|#
directive|define
name|XtNinternalWidth
value|"internalWidth"
end_define

begin_define
define|#
directive|define
name|XtNinternalHeight
value|"internalHeight"
end_define

begin_define
define|#
directive|define
name|XtNresize
value|"resize"
end_define

begin_define
define|#
directive|define
name|XtCResize
value|"Resize"
end_define

begin_define
define|#
directive|define
name|XtCBitmap
value|"Bitmap"
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
name|labelWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_LabelClassRec
modifier|*
name|LabelWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_LabelRec
modifier|*
name|LabelWidget
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawLabel_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

