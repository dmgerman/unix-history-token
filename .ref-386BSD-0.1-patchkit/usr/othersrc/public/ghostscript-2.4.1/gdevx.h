begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gdevx.h */
end_comment

begin_comment
comment|/* Header file with X device structure */
end_comment

begin_comment
comment|/* Requires gxdevice.h and x_.h */
end_comment

begin_comment
comment|/* Define the type of an X pixel. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|x_pixel
typedef|;
end_typedef

begin_comment
comment|/*  * We have two alternatives in mapping between X pixel values and  * Ghostscript gx_color_index values.  If we make them the same,  * Ghostscript will get confused if there is an X pixel value  * corresponding to gx_no_color_index.  If we make them different,  * we have to keep some kind of map, with all the associated bookkeeping.  *  * We opt for the first solution.  When we open the device,  * we check whether black or white maps to gx_no_color_index.  * (Since gx_no_color_index is all 1's, we assume no other color  * could have this pixel value.)  If this is the case, we xor all  * pixel values with a value chosen so that no pixel value will map  * to gx_no_color_index.  */
end_comment

begin_define
define|#
directive|define
name|pixel_to_color_index
parameter_list|(
name|px
parameter_list|)
value|((px) ^ xdev->pixel_fix)
end_define

begin_define
define|#
directive|define
name|color_index_to_pixel
parameter_list|(
name|ci
parameter_list|)
value|((ci) ^ xdev->pixel_fix)
end_define

begin_comment
comment|/* Define a rectangle structure for update bookkeeping */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rect_s
block|{
name|int
name|xo
decl_stmt|,
name|yo
decl_stmt|,
name|xe
decl_stmt|,
name|ye
decl_stmt|;
block|}
name|rect
typedef|;
end_typedef

begin_comment
comment|/* Define the X Windows device */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gx_device_X_s
block|{
name|gx_device_common
expr_stmt|;
comment|/* An XImage object for writing bitmap images to the screen */
name|XImage
name|image
decl_stmt|;
comment|/* Global X state */
name|Display
modifier|*
name|dpy
decl_stmt|;
name|Screen
modifier|*
name|scr
decl_stmt|;
name|XVisualInfo
modifier|*
name|vinfo
decl_stmt|;
name|Colormap
name|cmap
decl_stmt|;
name|Window
name|win
decl_stmt|;
name|GC
name|gc
decl_stmt|;
comment|/* A backing pixmap so X will handle exposure automatically */
name|Pixmap
name|bpixmap
decl_stmt|;
comment|/* 0 if use_backing is false, */
comment|/* or if it can't be allocated */
name|int
name|ghostview
decl_stmt|;
comment|/* flag to tell if ghostview is in control */
name|Window
name|mwin
decl_stmt|;
comment|/* window to receive ghostview messages */
comment|/* Don't include standard colormap stuff for X11R3 and earlier */
if|#
directive|if
name|HaveStdCMap
name|XStandardColormap
modifier|*
name|std_cmap
decl_stmt|;
comment|/* standard color map if available */
endif|#
directive|endif
name|gs_matrix
name|initial_matrix
decl_stmt|;
comment|/* the initial transformation */
name|Atom
name|next
decl_stmt|,
name|page
decl_stmt|,
name|done
decl_stmt|;
comment|/* Atoms used to talk to ghostview */
name|rect
name|update
decl_stmt|;
comment|/* region needing updating */
name|long
name|up_area
decl_stmt|;
comment|/* total area of update */
comment|/* (always 0 if no backing pixmap) */
name|int
name|up_count
decl_stmt|;
comment|/* # of updates since flush */
name|Pixmap
name|dest
decl_stmt|;
comment|/* bpixmap if non-0, else win */
name|x_pixel
name|colors_or
decl_stmt|;
comment|/* 'or' of all device colors used so far */
name|x_pixel
name|colors_and
decl_stmt|;
comment|/* 'and' ditto */
comment|/* An intermediate pixmap for the stencil case of copy_mono */
struct|struct
block|{
name|Pixmap
name|pixmap
decl_stmt|;
name|GC
name|gc
decl_stmt|;
name|int
name|raster
decl_stmt|,
name|height
decl_stmt|;
block|}
name|cp
struct|;
comment|/* Structure for dealing with the halftone tile. */
comment|/* Later this might become a multi-element cache. */
struct|struct
block|{
name|Pixmap
name|pixmap
decl_stmt|;
name|Pixmap
name|no_pixmap
decl_stmt|;
comment|/* kludge to get around X bug */
name|gx_bitmap_id
name|id
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|,
name|raster
decl_stmt|;
name|x_pixel
name|fore_c
decl_stmt|,
name|back_c
decl_stmt|;
block|}
name|ht
struct|;
comment|/* Cache the function and fill style from the GC */
name|int
name|function
decl_stmt|;
name|int
name|fill_style
decl_stmt|;
define|#
directive|define
name|set_fill_style
parameter_list|(
name|style
parameter_list|)
define|\
value|if ( xdev->fill_style != style )\     XSetFillStyle(xdev->dpy, xdev->gc, (xdev->fill_style = style))
define|#
directive|define
name|set_function
parameter_list|(
name|func
parameter_list|)
define|\
value|if ( xdev->function != func )\     XSetFunction(xdev->dpy, xdev->gc, (xdev->function = func))
comment|/* Map color indices to X pixel values */
name|unsigned
name|long
name|pixel_fix
decl_stmt|;
name|x_pixel
name|colors
index|[
literal|8
index|]
decl_stmt|;
comment|/* primary colors */
define|#
directive|define
name|pixel_black
value|xdev->colors[0]
define|#
directive|define
name|pixel_white
value|xdev->colors[7]
name|x_pixel
name|back_color
decl_stmt|,
name|fore_color
decl_stmt|;
define|#
directive|define
name|note_color
parameter_list|(
name|pixel
parameter_list|)
define|\
value|xdev->colors_or |= pixel,\   xdev->colors_and&= pixel
define|#
directive|define
name|set_back_color
parameter_list|(
name|pixel
parameter_list|)
define|\
value|if ( xdev->back_color != pixel )\    { xdev->back_color = pixel;\      note_color(pixel);\      XSetBackground(xdev->dpy, xdev->gc, pixel);\    }
define|#
directive|define
name|set_fore_color
parameter_list|(
name|pixel
parameter_list|)
define|\
value|if ( xdev->fore_color != pixel )\    { xdev->fore_color = pixel;\      note_color(pixel);\      XSetForeground(xdev->dpy, xdev->gc, pixel);\    }
block|}
name|gx_device_X
typedef|;
end_typedef

begin_comment
comment|/* Default window size */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_WIDTH_INCHES
value|8.5
end_define

begin_define
define|#
directive|define
name|DEFAULT_HEIGHT_INCHES
value|11
end_define

begin_comment
comment|/* Define a fake value for X and Y resolution, */
end_comment

begin_comment
comment|/* so an uninitialized value can be detected easily. */
end_comment

begin_define
define|#
directive|define
name|FAKE_RES
value|2
end_define

begin_comment
comment|/* easily detected fake value */
end_comment

end_unit

