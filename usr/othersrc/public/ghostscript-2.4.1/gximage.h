begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gximage.h */
end_comment

begin_comment
comment|/* Internal definitions for image rendering */
end_comment

begin_comment
comment|/* Requires gxcpath.h, gxdevmem.h, gzcolor.h, gzpath.h */
end_comment

begin_comment
comment|/* Imaging state structure */
end_comment

begin_comment
comment|/* The Unix C compiler can't handle typedefs for procedure */
end_comment

begin_comment
comment|/* (as opposed to pointer-to-procedure) types, */
end_comment

begin_comment
comment|/* so we have to do it with a macro instead: */
end_comment

begin_define
define|#
directive|define
name|iunpack_proc_args
define|\
value|P5(gs_image_enum *, byte *, byte *, uint, uint)
end_define

begin_define
define|#
directive|define
name|irender_proc_args
define|\
value|P4(gs_image_enum *, byte *, uint, int)
end_define

begin_comment
comment|/* Main state structure */
end_comment

begin_struct
struct|struct
name|gs_image_enum_s
block|{
comment|/* Following are set at structure initialization */
name|int
name|width
decl_stmt|;
name|int
name|height
decl_stmt|;
name|int
name|bps
decl_stmt|;
comment|/* bits per sample: 1, 2, 4, 8, 12 */
name|int
name|spp
decl_stmt|;
comment|/* samples per pixel: 1, 3, or 4 */
name|int
name|spread
decl_stmt|;
comment|/* spp if colors are separated, */
comment|/* 1 otherwise */
name|int
name|masked
decl_stmt|;
comment|/* 0 = [color]image, 1 = imagemask */
name|fixed
name|fxx
decl_stmt|,
name|fxy
decl_stmt|,
name|fyx
decl_stmt|,
name|fyy
decl_stmt|;
comment|/* fixed version of matrix */
name|void
function_decl|(
modifier|*
name|unpack
function_decl|)
parameter_list|(
name|iunpack_proc_args
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|render
function_decl|)
parameter_list|(
name|irender_proc_args
parameter_list|)
function_decl|;
name|gs_state
modifier|*
name|pgs
decl_stmt|;
name|gs_fixed_rect
name|clip_box
decl_stmt|;
comment|/* pgs->clip_path.path->bbox, */
comment|/* possibly translated */
name|gs_int_rect
name|ibox
decl_stmt|;
comment|/* integer version of clip_box, */
comment|/* only used for direct/buffered */
name|byte
modifier|*
name|buffer
decl_stmt|;
comment|/* for expanding to 8 bits/sample */
name|uint
name|buffer_size
decl_stmt|;
name|uint
name|bytes_per_row
decl_stmt|;
comment|/* # of input bytes per row */
comment|/* (per plane, if spp == 1 and */
comment|/* spread> 1) */
name|int
name|never_clip
decl_stmt|;
comment|/* true if entire image fits */
name|int
name|skewed
decl_stmt|;
comment|/* true if image is skewed */
comment|/* or rotated */
name|int
name|slow_loop
decl_stmt|;
comment|/* true if !(skewed | non-rect clip */
comment|/* | imagemask with a halftone) */
name|fixed
name|adjust
decl_stmt|;
comment|/* adjustment when rendering */
comment|/* characters */
name|ulong
name|_ds
modifier|*
name|map4to32
decl_stmt|;
comment|/* expansion map for monobit images */
name|gx_device_clip
name|clip_dev
decl_stmt|;
comment|/* clipping device (if needed) */
comment|/* Following are updated dynamically */
name|byte
modifier|*
name|planes
index|[
literal|4
index|]
decl_stmt|;
comment|/* separated color data */
name|int
name|plane_index
decl_stmt|;
comment|/* current plane index, [0..spp) */
name|uint
name|plane_size
decl_stmt|;
comment|/* size of data in each plane */
name|uint
name|byte_in_row
decl_stmt|;
comment|/* current input byte position in row */
name|fixed
name|xcur
decl_stmt|,
name|ycur
decl_stmt|;
comment|/* device x, y of current row */
name|int
name|yci
decl_stmt|,
name|hci
decl_stmt|;
comment|/* integer y& height of row */
comment|/* (if no skew) */
name|int
name|y
decl_stmt|;
comment|/* Entries 0 and 255 of the following are set at initialization */
comment|/* for monochrome images; other entries are updated dynamically. */
name|gx_device_color
name|dev_colors
index|[
literal|256
index|]
decl_stmt|;
define|#
directive|define
name|icolor0
value|dev_colors[0]
define|#
directive|define
name|icolor1
value|dev_colors[255]
block|}
struct|;
end_struct

end_unit

