begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Scrollbar.h,v 1.7 91/07/26 21:59:31 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Scrollbar_h
end_ifndef

begin_define
define|#
directive|define
name|_Scrollbar_h
end_define

begin_comment
comment|/****************************************************************  *  * Scrollbar Widget  *  ****************************************************************/
end_comment

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
comment|/* Scrollbar resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  accelerators	     Accelerators	AcceleratorTable NULL  ancestorSensitive   AncestorSensitive	Boolean		True  background	     Background		Pixel		XtDefaultBackground  backgroundPixmap    Pixmap		Pixmap		XtUnspecifiedPixmap  borderColor	     BorderColor	Pixel		XtDefaultForeground  borderPixmap	     Pixmap		Pixmap		XtUnspecifiedPixmap  borderWidth	     BorderWidth	Dimension	1  colormap	     Colormap		Colormap	parent's colormap  cursor		     Cursor		Cursor		None  cursorName	     Cursor		String		NULL  depth		     Depth		int		parent's depth  destroyCallback     Callback		XtCallbackList	NULL  foreground	     Foreground		Pixel		XtDefaultForeground  height		     Height		Dimension	length or thickness  insensitiveBorder   Insensitive	Pixmap		GreyPixmap  jumpProc	     Callback		XtCallbackList	NULL  length		     Length		Dimension	1  mappedWhenManaged   MappedWhenManaged	Boolean		True  minimumThumb	     MinimumThumb	Dimension	7  orientation	     Orientation	XtOrientation	XtorientVertical  pointerColor	     Foreground		Pixel		XtDefaultForeground  pointerColorBackground Background	Pixel		XtDefaultBackground  screen		     Screen		Screen		parent's screen  scrollDCursor	     Cursor		Cursor		XC_sb_down_arrow  scrollHCursor	     Cursor		Cursor		XC_sb_h_double_arrow  scrollLCursor	     Cursor		Cursor		XC_sb_left_arrow  scrollProc	     Callback		XtCallbackList	NULL  scrollRCursor	     Cursor		Cursor		XC_sb_right_arrow  scrollUCursor	     Cursor		Cursor		XC_sb_up_arrow  scrollVCursor	     Cursor		Cursor		XC_sb_v_double_arrow  sensitive	     Sensitive		Boolean		True  shown		     Shown		Float		0.0  thickness	     Thickness		Dimension	14  thumb		     Thumb		Bitmap		GreyPixmap  thumbProc	     Callback		XtCallbackList	NULL  topOfThumb	     TopOfThumb		Float		0.0  translations	     Translations	TranslationTable see source or doc  width		     Width		Dimension	thickness or length  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_comment
comment|/*   * Most things we need are in StringDefs.h   */
end_comment

begin_define
define|#
directive|define
name|XtCMinimumThumb
value|"MinimumThumb"
end_define

begin_define
define|#
directive|define
name|XtCShown
value|"Shown"
end_define

begin_define
define|#
directive|define
name|XtCTopOfThumb
value|"TopOfThumb"
end_define

begin_define
define|#
directive|define
name|XtNminimumThumb
value|"minimumThumb"
end_define

begin_define
define|#
directive|define
name|XtNtopOfThumb
value|"topOfThumb"
end_define

begin_typedef
typedef|typedef
name|struct
name|_ScrollbarRec
modifier|*
name|ScrollbarWidget
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ScrollbarClassRec
modifier|*
name|ScrollbarWidgetClass
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|scrollbarWidgetClass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|void
name|XawScrollbarSetThumb
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* scrollbar */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* float */
name|double
comment|/* top */
parameter_list|,
comment|/* float */
name|double
comment|/* shown */
else|#
directive|else
name|float
comment|/* top */
parameter_list|,
name|float
comment|/* shown */
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
comment|/* _Scrollbar_h */
end_comment

end_unit

