begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Panner.h,v 1.21 91/05/04 18:59:17 rws Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Jim Fulton, MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawPanner_h
end_ifndef

begin_define
define|#
directive|define
name|_XawPanner_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Reports.h>
end_include

begin_comment
comment|/*****************************************************************************  *   * Panner Widget (subclass of Simple)  *   * This widget is used to represent navigation in a 2d coordinate system.  *   * Parameters:  *   *  Name		Class		Type		Default  *  ----		-----		----		-------  *   *  allowOff		AllowOff	Boolean		FALSE  *  background		Background	Pixel		XtDefaultBackground  *  backgroundStipple	BackgroundStipple	String	NULL  *  canvasWidth		CanvasWidth	Dimension	0  *  canvasHeight	CanvasHeight	Dimension	0  *  defaultScale	DefaultScale	Dimension	8 percent  *  foreground		Foreground	Pixel		XtDefaultBackground  *  internalSpace	InternalSpace	Dimension	4  *  lineWidth		LineWidth	Dimension	0  *  reportCallback	ReportCallback	XtCallbackList	NULL  *  resize		Resize		Boolean		TRUE  *  rubberBand		RubberBand	Boolean		FALSE  *  shadowColor		ShadowColor	Pixel		XtDefaultForeground  *  shadowThickness	ShadowThickness	Dimension	2  *  sliderX		SliderX		Position	0  *  sliderY		SliderY		Position	0  *  sliderWidth		SliderWidth	Dimension	0  *  sliderHeight	SliderHeight	Dimension	0  *   *****************************************************************************/
end_comment

begin_comment
comment|/* new instance and class names */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XtNallowOff
value|"allowOff"
end_define

begin_define
define|#
directive|define
name|XtCAllowOff
value|"AllowOff"
end_define

begin_define
define|#
directive|define
name|XtNbackgroundStipple
value|"backgroundStipple"
end_define

begin_define
define|#
directive|define
name|XtCBackgroundStipple
value|"BackgroundStipple"
end_define

begin_define
define|#
directive|define
name|XtNdefaultScale
value|"defaultScale"
end_define

begin_define
define|#
directive|define
name|XtCDefaultScale
value|"DefaultScale"
end_define

begin_define
define|#
directive|define
name|XtNcanvasWidth
value|"canvasWidth"
end_define

begin_define
define|#
directive|define
name|XtCCanvasWidth
value|"CanvasWidth"
end_define

begin_define
define|#
directive|define
name|XtNcanvasHeight
value|"canvasHeight"
end_define

begin_define
define|#
directive|define
name|XtCCanvasHeight
value|"CanvasHeight"
end_define

begin_define
define|#
directive|define
name|XtNinternalSpace
value|"internalSpace"
end_define

begin_define
define|#
directive|define
name|XtCInternalSpace
value|"InternalSpace"
end_define

begin_define
define|#
directive|define
name|XtNlineWidth
value|"lineWidth"
end_define

begin_define
define|#
directive|define
name|XtCLineWidth
value|"LineWidth"
end_define

begin_define
define|#
directive|define
name|XtNrubberBand
value|"rubberBand"
end_define

begin_define
define|#
directive|define
name|XtCRubberBand
value|"RubberBand"
end_define

begin_define
define|#
directive|define
name|XtNshadowThickness
value|"shadowThickness"
end_define

begin_define
define|#
directive|define
name|XtCShadowThickness
value|"ShadowThickness"
end_define

begin_define
define|#
directive|define
name|XtNshadowColor
value|"shadowColor"
end_define

begin_define
define|#
directive|define
name|XtCShadowColor
value|"ShadowColor"
end_define

begin_define
define|#
directive|define
name|XtNsliderX
value|"sliderX"
end_define

begin_define
define|#
directive|define
name|XtCSliderX
value|"SliderX"
end_define

begin_define
define|#
directive|define
name|XtNsliderY
value|"sliderY"
end_define

begin_define
define|#
directive|define
name|XtCSliderY
value|"SliderY"
end_define

begin_define
define|#
directive|define
name|XtNsliderWidth
value|"sliderWidth"
end_define

begin_define
define|#
directive|define
name|XtCSliderWidth
value|"SliderWidth"
end_define

begin_define
define|#
directive|define
name|XtNsliderHeight
value|"sliderHeight"
end_define

begin_define
define|#
directive|define
name|XtCSliderHeight
value|"SliderHeight"
end_define

begin_comment
comment|/* external declarations */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|pannerWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_PannerClassRec
modifier|*
name|PannerWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_PannerRec
modifier|*
name|PannerWidget
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawPanner_h */
end_comment

end_unit

