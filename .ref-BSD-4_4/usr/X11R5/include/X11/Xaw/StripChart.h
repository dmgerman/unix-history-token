begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: StripChart.h,v 1.5 91/07/26 22:50:35 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawStripChart_h
end_ifndef

begin_define
define|#
directive|define
name|_XawStripChart_h
end_define

begin_comment
comment|/***********************************************************************  *  * StripChart Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/* StripChart resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  accelerators	     Accelerators	AcceleratorTable NULL  ancestorSensitive   AncestorSensitive	Boolean		True   background	     Background		Pixel		XtDefaultBackground  backgroundPixmap    Pixmap		Pixmap		XtUnspecifiedPixmap  borderColor	     BorderColor	Pixel		XtDefaultForeground  borderPixmap	     Pixmap		Pixmap		XtUnspecifiedPixmap  borderWidth	     BorderWidth	Dimension	1  colormap	     Colormap		Colormap	parent's colormap  cursor		     Cursor		Cursor		None  cursorName	     Cursor		String		NULL  depth		     Depth		int		parent's depth  destroyCallback     Callback		XtCallbackList	NULL  foreground	     Foreground		Pixel		XtDefaultForeground  getValue	     Callback		XtCallbackList	NULL  height		     Height		Dimension	120  highlight	     Foreground		Pixel		XtDefaultForeground  insensitiveBorder   Insensitive	Pixmap		GreyPixmap  jumpScroll	     JumpScroll		int		1/2 width  mappedWhenManaged   MappedWhenManaged	Boolean		True  minScale	     Scale		int		1  pointerColor	     Foreground		Pixel		XtDefaultForeground  pointerColorBackground Background	Pixel		XtDefaultBackground  screen		     Screen		Screen		parent's screen  sensitive	     Sensitive		Boolean		True  translations	     Translations	TranslationTable NULL  update		     Interval		int		10 (seconds)  width		     Width		Dimension	120  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_JUMP
value|-1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

begin_define
define|#
directive|define
name|XtNhighlight
value|"highlight"
end_define

begin_define
define|#
directive|define
name|XtNupdate
value|"update"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XtCJumpScroll
value|"JumpScroll"
end_define

begin_define
define|#
directive|define
name|XtCScale
value|"Scale"
end_define

begin_define
define|#
directive|define
name|XtNgetValue
value|"getValue"
end_define

begin_define
define|#
directive|define
name|XtNjumpScroll
value|"jumpScroll"
end_define

begin_define
define|#
directive|define
name|XtNminScale
value|"minScale"
end_define

begin_define
define|#
directive|define
name|XtNscale
value|"scale"
end_define

begin_define
define|#
directive|define
name|XtNvmunix
value|"vmunix"
end_define

begin_typedef
typedef|typedef
name|struct
name|_StripChartRec
modifier|*
name|StripChartWidget
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_StripChartClassRec
modifier|*
name|StripChartWidgetClass
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|stripChartWidgetClass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawStripChart_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

