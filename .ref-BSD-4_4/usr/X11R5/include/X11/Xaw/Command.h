begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Command.h,v 1.27 91/07/28 18:51:35 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawCommand_h
end_ifndef

begin_define
define|#
directive|define
name|_XawCommand_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Label.h>
end_include

begin_comment
comment|/* Command widget resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  accelerators	     Accelerators	AcceleratorTable NULL  ancestorSensitive   AncestorSensitive	Boolean		True  background	     Background		Pixel		XtDefaultBackground  backgroundPixmap    Pixmap		Pixmap		XtUnspecifiedPixmap  bitmap		     Pixmap		Pixmap		None  borderColor	     BorderColor	Pixel		XtDefaultForeground  borderPixmap	     Pixmap		Pixmap		XtUnspecifiedPixmap  borderWidth	     BorderWidth	Dimension	1  callback	     Callback		XtCallbackList	NULL  colormap	     Colormap		Colormap	parent's colormap  cornerRoundPercent  CornerRoundPercent	Dimension	25  cursor		     Cursor		Cursor		None  cursorName	     Cursor		String		NULL  depth		     Depth		int		parent's depth  destroyCallback     Callback		XtCallbackList	NULL  encoding	     Encoding		UnsignedChar	XawTextEncoding8bit  font		     Font		XFontStruct*	XtDefaultFont  foreground	     Foreground		Pixel		XtDefaultForeground  height		     Height		Dimension	text height  highlightThickness  Thickness		Dimension	0 if shaped, else 2  insensitiveBorder   Insensitive	Pixmap		Gray  internalHeight	     Height		Dimension	2  internalWidth	     Width		Dimension	4  justify	     Justify		XtJustify	XtJustifyCenter  label		     Label		String		NULL  leftBitmap	     LeftBitmap		Pixmap		None  mappedWhenManaged   MappedWhenManaged	Boolean		True  pointerColor	     Foreground		Pixel		XtDefaultForeground  pointerColorBackground Background	Pixel		XtDefaultBackground  resize		     Resize		Boolean		True  screen		     Screen		Screen		parent's Screen  sensitive	     Sensitive		Boolean		True  shapeStyle	     ShapeStyle		ShapeStyle	Rectangle  translations	     Translations	TranslationTable see doc or source  width		     Width		Dimension	text width  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_define
define|#
directive|define
name|XtNhighlightThickness
value|"highlightThickness"
end_define

begin_define
define|#
directive|define
name|XtNshapeStyle
value|"shapeStyle"
end_define

begin_define
define|#
directive|define
name|XtCShapeStyle
value|"ShapeStyle"
end_define

begin_define
define|#
directive|define
name|XtRShapeStyle
value|"ShapeStyle"
end_define

begin_define
define|#
directive|define
name|XtNcornerRoundPercent
value|"cornerRoundPercent"
end_define

begin_define
define|#
directive|define
name|XtCCornerRoundPercent
value|"CornerRoundPercent"
end_define

begin_define
define|#
directive|define
name|XawShapeRectangle
value|XmuShapeRectangle
end_define

begin_define
define|#
directive|define
name|XawShapeOval
value|XmuShapeOval
end_define

begin_define
define|#
directive|define
name|XawShapeEllipse
value|XmuShapeEllipse
end_define

begin_define
define|#
directive|define
name|XawShapeRoundedRectangle
value|XmuShapeRoundedRectangle
end_define

begin_decl_stmt
specifier|extern
name|WidgetClass
name|commandWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_CommandClassRec
modifier|*
name|CommandWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_CommandRec
modifier|*
name|CommandWidget
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawCommand_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS */
end_comment

end_unit

