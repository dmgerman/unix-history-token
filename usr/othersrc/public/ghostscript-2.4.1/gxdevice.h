begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxdevice.h */
end_comment

begin_comment
comment|/* Device description structure for Ghostscript library */
end_comment

begin_include
include|#
directive|include
file|"gsmatrix.h"
end_include

begin_include
include|#
directive|include
file|"gxbitmap.h"
end_include

begin_comment
comment|/* See drivers.doc for documentation of the driver interface. */
end_comment

begin_comment
comment|/* Define the type for device color indices. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|gx_color_index
typedef|;
end_typedef

begin_comment
comment|/* Define the 'transparent' color index. */
end_comment

begin_define
define|#
directive|define
name|gx_no_color_value
value|(-1)
end_define

begin_comment
comment|/* no cast -> can be used in #if */
end_comment

begin_define
define|#
directive|define
name|gx_no_color_index
value|((gx_color_index)gx_no_color_value)
end_define

begin_comment
comment|/* Define the type for gray or RGB values at the driver interface. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|gx_color_value
typedef|;
end_typedef

begin_comment
comment|/* We might use less than the full range someday. */
end_comment

begin_comment
comment|/* ...bits must lie between 8 and 16. */
end_comment

begin_define
define|#
directive|define
name|gx_color_value_bits
value|(sizeof(gx_color_value) * 8)
end_define

begin_define
define|#
directive|define
name|gx_max_color_value
value|((gx_color_value)((1L<< gx_color_value_bits) - 1))
end_define

begin_define
define|#
directive|define
name|gx_color_value_to_byte
parameter_list|(
name|cv
parameter_list|)
define|\
value|((cv)>> (gx_color_value_bits - 8))
end_define

begin_define
define|#
directive|define
name|gx_color_value_from_byte
parameter_list|(
name|cb
parameter_list|)
define|\
value|(((cb)<< (gx_color_value_bits - 8)) + ((cb)>> (16 - gx_color_value_bits)))
end_define

begin_comment
comment|/* Define the structure for device color capabilities. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gx_device_color_info_s
block|{
name|int
name|num_components
decl_stmt|;
comment|/* 1 = gray only, 3 = RGB, */
comment|/* 4 = CMYK (not supported) */
name|int
name|depth
decl_stmt|;
comment|/* # of bits per pixel */
name|gx_color_value
name|max_gray
decl_stmt|;
comment|/* # of distinct gray levels -1 */
name|gx_color_value
name|max_rgb
decl_stmt|;
comment|/* # of distinct color levels -1 */
comment|/* (only relevant if num_comp.> 1) */
name|gx_color_value
name|dither_gray
decl_stmt|;
comment|/* size of gray ramp for dithering */
name|gx_color_value
name|dither_rgb
decl_stmt|;
comment|/* size of color cube ditto */
comment|/* (only relevant if num_comp.> 1) */
block|}
name|gx_device_color_info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dci_black_and_white
value|{ 1, 1, 1, 0, 2, 0 }
end_define

begin_define
define|#
directive|define
name|dci_color
parameter_list|(
name|depth
parameter_list|,
name|maxv
parameter_list|,
name|dither
parameter_list|)
value|{ 3, depth, maxv, maxv, dither, dither }
end_define

begin_define
define|#
directive|define
name|gx_device_has_color
parameter_list|(
name|dev
parameter_list|)
value|((dev)->color_info.num_components> 1)
end_define

begin_comment
comment|/* Structure for device procedures */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_device_procs_s
name|gx_device_procs
typedef|;
end_typedef

begin_comment
comment|/* Structure for generic device description */
end_comment

begin_define
define|#
directive|define
name|gx_device_common
define|\
value|int params_size;
comment|/* size of this structure */
value|\ 	gx_device_procs *procs;\ 	const char *dname;
comment|/* the device name */
value|\ 	int width;
comment|/* width in pixels */
value|\ 	int height;
comment|/* height in pixels */
value|\ 	float x_pixels_per_inch;
comment|/* x density */
value|\ 	float y_pixels_per_inch;
comment|/* y density */
value|\ 	float l_margin, b_margin, r_margin, t_margin;
comment|/* margins around */
value|\
comment|/* imageable area, in inches */
value|\ 	gx_device_color_info color_info;
comment|/* color information */
value|\ 	int is_open
end_define

begin_comment
comment|/* true if device has been opened */
end_comment

begin_define
define|#
directive|define
name|no_margins
value|0, 0, 0, 0
end_define

begin_comment
comment|/* A generic device */
end_comment

begin_struct
struct|struct
name|gx_device_s
block|{
name|gx_device_common
expr_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|gx_device_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|gx_device_DEFINED
end_define

begin_typedef
typedef|typedef
name|struct
name|gx_device_s
name|gx_device
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define an opaque type for property lists. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gs_prop_item_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|gs_prop_item_DEFINED
end_define

begin_typedef
typedef|typedef
name|struct
name|gs_prop_item_s
name|gs_prop_item
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Definition of device procedures */
end_comment

begin_struct
struct|struct
name|gx_device_procs_s
block|{
define|#
directive|define
name|dev_proc_open_device
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P1(gx_device *dev))
name|dev_proc_open_device
argument_list|(
operator|(
operator|*
name|open_device
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_get_initial_matrix
parameter_list|(
name|proc
parameter_list|)
define|\
value|void proc(P2(gx_device *dev, gs_matrix *pmat))
name|dev_proc_get_initial_matrix
argument_list|(
operator|(
operator|*
name|get_initial_matrix
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_sync_output
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P1(gx_device *dev))
name|dev_proc_sync_output
argument_list|(
operator|(
operator|*
name|sync_output
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_output_page
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P3(gx_device *dev, int num_copies, int flush))
name|dev_proc_output_page
argument_list|(
operator|(
operator|*
name|output_page
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_close_device
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P1(gx_device *dev))
name|dev_proc_close_device
argument_list|(
operator|(
operator|*
name|close_device
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_map_rgb_color
parameter_list|(
name|proc
parameter_list|)
define|\
value|gx_color_index proc(P4(gx_device *dev,\     gx_color_value red, gx_color_value green, gx_color_value blue))
name|dev_proc_map_rgb_color
argument_list|(
operator|(
operator|*
name|map_rgb_color
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_map_color_rgb
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P3(gx_device *dev,\     gx_color_index color, gx_color_value rgb[3]))
name|dev_proc_map_color_rgb
argument_list|(
operator|(
operator|*
name|map_color_rgb
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_fill_rectangle
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P6(gx_device *dev,\     int x, int y, int width, int height, gx_color_index color))
name|dev_proc_fill_rectangle
argument_list|(
operator|(
operator|*
name|fill_rectangle
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_tile_rectangle
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P10(gx_device *dev,\     gx_bitmap *tile, int x, int y, int width, int height,\     gx_color_index color0, gx_color_index color1,\     int phase_x, int phase_y))
name|dev_proc_tile_rectangle
argument_list|(
operator|(
operator|*
name|tile_rectangle
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_copy_mono
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P11(gx_device *dev,\     unsigned char *data, int data_x, int raster, gx_bitmap_id id,\     int x, int y, int width, int height,\     gx_color_index color0, gx_color_index color1))
name|dev_proc_copy_mono
argument_list|(
operator|(
operator|*
name|copy_mono
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_copy_color
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P9(gx_device *dev,\     unsigned char *data, int data_x, int raster, gx_bitmap_id id,\     int x, int y, int width, int height))
name|dev_proc_copy_color
argument_list|(
operator|(
operator|*
name|copy_color
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_draw_line
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P6(gx_device *dev,\     int x0, int y0, int x1, int y1, gx_color_index color))
name|dev_proc_draw_line
argument_list|(
operator|(
operator|*
name|draw_line
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_get_bits
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P5(gx_device *dev,\     int y, unsigned char *data, unsigned int size, int pad_to_word))
name|dev_proc_get_bits
argument_list|(
operator|(
operator|*
name|get_bits
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_get_props
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P2(gx_device *dev, gs_prop_item *plist))
name|dev_proc_get_props
argument_list|(
operator|(
operator|*
name|get_props
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|dev_proc_put_props
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P3(gx_device *dev, gs_prop_item *plist, int count))
name|dev_proc_put_props
argument_list|(
operator|(
operator|*
name|put_props
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Calculate the number of bytes in a scan line, */
end_comment

begin_comment
comment|/* with byte or word padding. */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|gx_device_bytes_per_scan_line
argument_list|(
name|P2
argument_list|(
argument|gx_device *dev
argument_list|,
argument|int pad_to_word
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default implementations of optional procedures */
end_comment

begin_expr_stmt
name|dev_proc_open_device
argument_list|(
name|gx_default_open_device
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_get_initial_matrix
argument_list|(
name|gx_default_get_initial_matrix
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_sync_output
argument_list|(
name|gx_default_sync_output
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_output_page
argument_list|(
name|gx_default_output_page
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_close_device
argument_list|(
name|gx_default_close_device
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_map_rgb_color
argument_list|(
name|gx_default_map_rgb_color
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_map_color_rgb
argument_list|(
name|gx_default_map_color_rgb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_tile_rectangle
argument_list|(
name|gx_default_tile_rectangle
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_copy_color
argument_list|(
name|gx_default_copy_color
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_draw_line
argument_list|(
name|gx_default_draw_line
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_get_bits
argument_list|(
name|gx_default_get_bits
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_get_props
argument_list|(
name|gx_default_get_props
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_put_props
argument_list|(
name|gx_default_put_props
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

