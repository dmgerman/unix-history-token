begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************ Copyright 1989 by The Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright no- tice appear in all copies and that both that copyright no- tice and this permission notice appear in supporting docu- mentation, and that the name of MIT not be used in advertising or publicity pertaining to distribution of the software without specific prior written permission. M.I.T. makes no representation about the suitability of this software for any purpose. It is provided "as is" without any express or implied warranty.  MIT DISCLAIMS ALL WARRANTIES WITH REGARD TO  THIS  SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FIT- NESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL SUN BE  LI- ABLE  FOR  ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  DATA  OR PROFITS,  WHETHER  IN  AN  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ********************************************************/
end_comment

begin_comment
comment|/* $XConsortium: shape.h,v 1.15 91/02/17 13:09:32 rws Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SHAPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SHAPE_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_define
define|#
directive|define
name|X_ShapeQueryVersion
value|0
end_define

begin_define
define|#
directive|define
name|X_ShapeRectangles
value|1
end_define

begin_define
define|#
directive|define
name|X_ShapeMask
value|2
end_define

begin_define
define|#
directive|define
name|X_ShapeCombine
value|3
end_define

begin_define
define|#
directive|define
name|X_ShapeOffset
value|4
end_define

begin_define
define|#
directive|define
name|X_ShapeQueryExtents
value|5
end_define

begin_define
define|#
directive|define
name|X_ShapeSelectInput
value|6
end_define

begin_define
define|#
directive|define
name|X_ShapeInputSelected
value|7
end_define

begin_define
define|#
directive|define
name|X_ShapeGetRectangles
value|8
end_define

begin_define
define|#
directive|define
name|ShapeSet
value|0
end_define

begin_define
define|#
directive|define
name|ShapeUnion
value|1
end_define

begin_define
define|#
directive|define
name|ShapeIntersect
value|2
end_define

begin_define
define|#
directive|define
name|ShapeSubtract
value|3
end_define

begin_define
define|#
directive|define
name|ShapeInvert
value|4
end_define

begin_define
define|#
directive|define
name|ShapeBounding
value|0
end_define

begin_define
define|#
directive|define
name|ShapeClip
value|1
end_define

begin_define
define|#
directive|define
name|ShapeNotifyMask
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|ShapeNotify
value|0
end_define

begin_define
define|#
directive|define
name|ShapeNumberEvents
value|(ShapeNotify + 1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SHAPE_SERVER_
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* of event */
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came frome a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
comment|/* window of event */
name|int
name|kind
decl_stmt|;
comment|/* ShapeBounding or ShapeClip */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* extents of new region */
name|unsigned
name|width
decl_stmt|,
name|height
decl_stmt|;
name|Time
name|time
decl_stmt|;
comment|/* server timestamp when region changed */
name|Bool
name|shaped
decl_stmt|;
comment|/* true if the region exists */
block|}
name|XShapeEvent
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|Bool
name|XShapeQueryExtension
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
modifier|*
comment|/* event_base */
parameter_list|,
name|int
modifier|*
comment|/* error_base */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XShapeQueryVersion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
modifier|*
comment|/* major_version */
parameter_list|,
name|int
modifier|*
comment|/* minor_version */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XShapeCombineRegion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* dest */
parameter_list|,
name|int
comment|/* dest_kind */
parameter_list|,
name|int
comment|/* x_off */
parameter_list|,
name|int
comment|/* y_off */
parameter_list|,
name|Region
comment|/* region */
parameter_list|,
name|int
comment|/* op */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XShapeCombineRectangles
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* dest */
parameter_list|,
name|int
comment|/* dest_kind */
parameter_list|,
name|int
comment|/* x_off */
parameter_list|,
name|int
comment|/* y_off */
parameter_list|,
name|XRectangle
modifier|*
comment|/* rectangles */
parameter_list|,
name|int
comment|/* n_rects */
parameter_list|,
name|int
comment|/* op */
parameter_list|,
name|int
comment|/* ordering */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XShapeCombineMask
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* dest */
parameter_list|,
name|int
comment|/* dest_kind */
parameter_list|,
name|int
comment|/* x_off */
parameter_list|,
name|int
comment|/* y_off */
parameter_list|,
name|Pixmap
comment|/* src */
parameter_list|,
name|int
comment|/* op */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XShapeCombineShape
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* dest */
parameter_list|,
name|int
comment|/* dest_kind */
parameter_list|,
name|int
comment|/* x_off */
parameter_list|,
name|int
comment|/* y_off */
parameter_list|,
name|Window
comment|/* src */
parameter_list|,
name|int
comment|/* src_kind */
parameter_list|,
name|int
comment|/* op */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XShapeOffsetShape
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* dest */
parameter_list|,
name|int
comment|/* dest_kind */
parameter_list|,
name|int
comment|/* x_off */
parameter_list|,
name|int
comment|/* y_off */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XShapeQueryExtents
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* window */
parameter_list|,
name|Bool
modifier|*
comment|/* bounding_shaped */
parameter_list|,
name|int
modifier|*
comment|/* x_bounding */
parameter_list|,
name|int
modifier|*
comment|/* y_bounding */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* w_bounding */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* h_bounding */
parameter_list|,
name|Bool
modifier|*
comment|/* clip_shaped */
parameter_list|,
name|int
modifier|*
comment|/* x_clip */
parameter_list|,
name|int
modifier|*
comment|/* y_clip */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* w_clip */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* h_clip */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XShapeSelectInput
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* window */
parameter_list|,
name|unsigned
name|long
comment|/* mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XShapeInputSelected
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* window */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XRectangle
modifier|*
name|XShapeGetRectangles
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* window */
parameter_list|,
name|int
comment|/* kind */
parameter_list|,
name|int
modifier|*
comment|/* count */
parameter_list|,
name|int
modifier|*
comment|/* ordering */
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
comment|/* _SHAPE_SERVER_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SHAPE_H_ */
end_comment

end_unit

