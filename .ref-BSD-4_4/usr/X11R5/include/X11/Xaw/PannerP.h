begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: PannerP.h,v 1.18 90/04/11 17:05:11 jim Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * Author:  Jim Fulton, MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawPannerP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawPannerP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Panner.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_comment
comment|/* parent */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* new fields in widget class */
name|int
name|dummy
decl_stmt|;
block|}
name|PannerClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PannerClassRec
block|{
comment|/* Panner widget class */
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|PannerClassPart
name|panner_class
decl_stmt|;
block|}
name|PannerClassRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* new fields in widget */
comment|/* resources... */
name|XtCallbackList
name|report_callbacks
decl_stmt|;
comment|/* callback/Callback */
name|Boolean
name|allow_off
decl_stmt|;
comment|/* allowOff/AllowOff */
name|Boolean
name|resize_to_pref
decl_stmt|;
comment|/* resizeToPreferred/Boolean */
name|Pixel
name|foreground
decl_stmt|;
comment|/* foreground/Foreground */
name|Pixel
name|shadow_color
decl_stmt|;
comment|/* shadowColor/ShadowColor */
name|Dimension
name|shadow_thickness
decl_stmt|;
comment|/* shadowThickness/ShadowThickness */
name|Dimension
name|default_scale
decl_stmt|;
comment|/* defaultScale/DefaultScale */
name|Dimension
name|line_width
decl_stmt|;
comment|/* lineWidth/LineWidth */
name|Dimension
name|canvas_width
decl_stmt|;
comment|/* canvasWidth/CanvasWidth */
name|Dimension
name|canvas_height
decl_stmt|;
comment|/* canvasHeight/CanvasHeight */
name|Position
name|slider_x
decl_stmt|;
comment|/* sliderX/SliderX */
name|Position
name|slider_y
decl_stmt|;
comment|/* sliderY/SliderY */
name|Dimension
name|slider_width
decl_stmt|;
comment|/* sliderWidth/SliderWidth */
name|Dimension
name|slider_height
decl_stmt|;
comment|/* sliderHeight/SliderHeight */
name|Dimension
name|internal_border
decl_stmt|;
comment|/* internalBorderWidth/BorderWidth */
name|String
name|stipple_name
decl_stmt|;
comment|/* backgroundStipple/BackgroundStipple */
comment|/* private data... */
name|GC
name|slider_gc
decl_stmt|;
comment|/* background of slider */
name|GC
name|shadow_gc
decl_stmt|;
comment|/* edge of slider and shadow */
name|GC
name|xor_gc
decl_stmt|;
comment|/* for doing XOR tmp graphics */
name|double
name|haspect
decl_stmt|,
name|vaspect
decl_stmt|;
comment|/* aspect ratio of core to canvas */
name|Boolean
name|rubber_band
decl_stmt|;
comment|/* true = rubber band, false = move */
struct|struct
block|{
name|Boolean
name|doing
decl_stmt|;
comment|/* tmp graphics in progress */
name|Boolean
name|showing
decl_stmt|;
comment|/* true if tmp graphics displayed */
name|Position
name|startx
decl_stmt|,
name|starty
decl_stmt|;
comment|/* initial position of slider */
name|Position
name|dx
decl_stmt|,
name|dy
decl_stmt|;
comment|/* offset loc for tmp graphics */
name|Position
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* location for tmp graphics */
block|}
name|tmp
struct|;
name|Position
name|knob_x
decl_stmt|,
name|knob_y
decl_stmt|;
comment|/* real upper left of knob in canvas */
name|Dimension
name|knob_width
decl_stmt|,
name|knob_height
decl_stmt|;
comment|/* real size of knob in canvas */
name|Boolean
name|shadow_valid
decl_stmt|;
comment|/* true if rects are valid */
name|XRectangle
name|shadow_rects
index|[
literal|2
index|]
decl_stmt|;
comment|/* location of shadows */
name|Position
name|last_x
decl_stmt|,
name|last_y
decl_stmt|;
comment|/* previous location of knob */
block|}
name|PannerPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PannerRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|PannerPart
name|panner
decl_stmt|;
block|}
name|PannerRec
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PANNER_HSCALE
parameter_list|(
name|pw
parameter_list|,
name|val
parameter_list|)
value|((pw)->panner.haspect * ((double) (val)))
end_define

begin_define
define|#
directive|define
name|PANNER_VSCALE
parameter_list|(
name|pw
parameter_list|,
name|val
parameter_list|)
value|((pw)->panner.vaspect * ((double) (val)))
end_define

begin_define
define|#
directive|define
name|PANNER_DSCALE
parameter_list|(
name|pw
parameter_list|,
name|val
parameter_list|)
value|(Dimension)  \   ((((unsigned long) (val)) * (unsigned long) pw->panner.default_scale) / 100L)
end_define

begin_define
define|#
directive|define
name|PANNER_DEFAULT_SCALE
value|8
end_define

begin_comment
comment|/* percent */
end_comment

begin_define
define|#
directive|define
name|PANNER_OUTOFRANGE
value|-30000
end_define

begin_comment
comment|/*  * external declarations  */
end_comment

begin_decl_stmt
specifier|extern
name|PannerClassRec
name|pannerClassRec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawPannerP_h */
end_comment

end_unit

