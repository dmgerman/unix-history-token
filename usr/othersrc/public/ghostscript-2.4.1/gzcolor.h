begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gzcolor.h */
end_comment

begin_comment
comment|/* Private definition of color representation for Ghostscript */
end_comment

begin_include
include|#
directive|include
file|"gscolor.h"
end_include

begin_comment
comment|/* client interface */
end_comment

begin_include
include|#
directive|include
file|"gxlum.h"
end_include

begin_comment
comment|/* Colors as seen by clients. */
end_comment

begin_comment
comment|/* The color parameters are stored internally as color_params. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|color_param
typedef|;
end_typedef

begin_comment
comment|/*  * The following line should read:  *	#define max_color_param max_ushort  * but this seems to trigger brain-damage in a number of compilers.  * The problems all seem to come up when the compiler has to cast this value  * to some other type, so we define all the relevant casted values explicitly:  */
end_comment

begin_define
define|#
directive|define
name|max_color_param
value|((ushort)0xffff)
end_define

begin_define
define|#
directive|define
name|max_color_param_long
value|0xffffL
end_define

begin_define
define|#
directive|define
name|max_color_param_float
value|((float)0xffffL)
end_define

begin_comment
comment|/* Color_param_bits must be between 8 and 16. */
end_comment

begin_define
define|#
directive|define
name|color_param_bits
value|16
end_define

begin_comment
comment|/* Convert a byte to or from a color_param efficiently. */
end_comment

begin_define
define|#
directive|define
name|color_param_from_byte
parameter_list|(
name|b
parameter_list|)
define|\
value|(((ushort)(b)<< (color_param_bits - 8)) + ((b)>> (16 - color_param_bits)))
end_define

begin_define
define|#
directive|define
name|color_param_to_byte
parameter_list|(
name|p
parameter_list|)
define|\
value|((p)>> (color_param_bits - 8))
end_define

begin_comment
comment|/*  * The following members are used in the structure, depending on the space:  *	DeviceGray	red, green, blue (all equal)  *	DeviceRGB	red, green, blue  *	DeviceCMYK	red, green, blue, not_black  * luminance is also used for all of the above.  */
end_comment

begin_comment
comment|/*typedef struct gs_color_s gs_color;*/
end_comment

begin_comment
comment|/* in gscolor.h */
end_comment

begin_struct
struct|struct
name|gs_color_s
block|{
name|color_param
name|red
decl_stmt|,
name|green
decl_stmt|,
name|blue
decl_stmt|;
comment|/* RGB/~CMY */
name|color_param
name|not_black
decl_stmt|;
comment|/* ~K */
name|color_param
name|luminance
decl_stmt|;
comment|/* computed luminance */
name|byte
comment|/*gs_color_space*/
name|space
decl_stmt|;
comment|/* see above */
name|unsigned
name|is_gray
range|:
literal|1
decl_stmt|;
comment|/* quick test for gray */
comment|/* (red==green==blue) */
name|unsigned
name|unused
range|:
literal|6
decl_stmt|;
name|unsigned
name|luminance_set
range|:
literal|1
decl_stmt|;
comment|/* true if luminance is set */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|color_param
name|gx_color_luminance
argument_list|(
name|P1
argument_list|(
expr|struct
name|gs_color_s
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|color_luminance
parameter_list|(
name|pcolor
parameter_list|)
define|\
value|((pcolor)->luminance_set ? (pcolor)->luminance :\ 	 gx_color_luminance(pcolor))
end_define

begin_comment
comment|/*  * The following parameters are computed from the above,  * and kept current through changes in transfer function or device.  * If the halftone is a colored tile, color1 == color2 == gx_no_color_index,  * and halftone_level == -1.  (Colored tiles are not currently used.)  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_device_color_s
name|gx_device_color
typedef|;
end_typedef

begin_struct
struct|struct
name|gx_device_color_s
block|{
name|gx_color_index
name|color1
decl_stmt|;
comment|/* device color, or */
comment|/* darker color for halftoning */
name|gx_color_index
name|color2
decl_stmt|;
comment|/* lighter color for halftoning */
name|int
name|halftone_level
decl_stmt|;
comment|/* number of spots to whiten */
comment|/* when halftoning, 0 if */
comment|/* halftoning not needed, */
comment|/*<0 if color halftone */
name|struct
name|gx_bitmap_s
modifier|*
name|tile
decl_stmt|;
comment|/* pointer to cached halftone */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|color_is_pure
parameter_list|(
name|pdevc
parameter_list|)
define|\
value|((pdevc)->halftone_level == 0)
end_define

begin_define
define|#
directive|define
name|color_is_color_halftone
parameter_list|(
name|pdevc
parameter_list|)
define|\
value|((pdevc)->halftone_level< 0)
end_define

begin_comment
comment|/* A fast version of gz_fill_rectangle. */
end_comment

begin_comment
comment|/* Note that it takes additional arguments. */
end_comment

begin_define
define|#
directive|define
name|gz_fill_rectangle_open
parameter_list|(
name|dev
parameter_list|,
name|xi
parameter_list|,
name|yi
parameter_list|,
name|w
parameter_list|,
name|h
parameter_list|,
name|fill_proc
parameter_list|,
name|tile_proc
parameter_list|,
name|pdevc
parameter_list|,
name|pgs
parameter_list|)
define|\
value|(color_is_pure(pdevc) ?\     (*fill_proc)(dev, xi, yi, w, h, pdevc->color1) :\     (*tile_proc)(dev, pdevc->tile, xi, yi, w, h,\ 	pdevc->color1, pdevc->color2,\ 	pgs->phase_mod.x, pgs->phase_mod.y) )
end_define

begin_comment
comment|/* Procedures in gxcolor.c used elsewhere. */
end_comment

begin_decl_stmt
name|void
name|gx_set_gray_only
argument_list|(
name|P2
argument_list|(
name|gs_color
operator|*
argument_list|,
name|color_param
argument_list|)
argument_list|)
decl_stmt|,
name|gx_set_rgb_only
argument_list|(
name|P4
argument_list|(
name|gs_color
operator|*
argument_list|,
name|color_param
argument_list|,
name|color_param
argument_list|,
name|color_param
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|color_param
name|gx_color_unit_param
argument_list|(
name|P1
argument_list|(
name|floatp
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A color transfer function and cache. */
end_comment

begin_comment
comment|/* log2... must not be greater than color_param_bits. */
end_comment

begin_define
define|#
directive|define
name|log2_transfer_map_size
value|8
end_define

begin_define
define|#
directive|define
name|transfer_map_size
value|(1<< log2_transfer_map_size)
end_define

begin_typedef
typedef|typedef
struct|struct
name|gx_transfer_map_s
block|{
name|gs_transfer_proc
name|proc
decl_stmt|;
name|color_param
name|values
index|[
name|transfer_map_size
index|]
decl_stmt|;
block|}
name|gx_transfer_map
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gx_transfer_s
block|{
name|int
name|ref_count
decl_stmt|;
comment|/* # of references from gstates */
name|gx_transfer_map
name|red
decl_stmt|,
name|green
decl_stmt|,
name|blue
decl_stmt|,
name|gray
decl_stmt|;
block|}
name|gx_transfer
typedef|;
end_typedef

begin_comment
comment|/* Map a color_param or byte through a transfer map. */
end_comment

begin_decl_stmt
specifier|extern
name|color_param
name|gx_color_param_map
argument_list|(
name|P2
argument_list|(
name|color_param
argument_list|,
name|color_param
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|gx_map_color_param
parameter_list|(
name|pgs
parameter_list|,
name|cp
parameter_list|,
name|m
parameter_list|)
define|\
value|gx_color_param_map(cp,&pgs->transfer->m.values[0])
end_define

begin_if
if|#
directive|if
name|log2_transfer_map_size
operator|<=
literal|8
end_if

begin_define
define|#
directive|define
name|byte_to_tmx
parameter_list|(
name|b
parameter_list|)
value|((b)>> (8 - log2_transfer_map_size))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|byte_to_tmx
parameter_list|(
name|b
parameter_list|)
define|\
value|(((b)<< (log2_transfer_map_size - 8)) +\ 	 ((b)>> (16 - log2_transfer_map_size)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gx_map_color_param_byte
parameter_list|(
name|pgs
parameter_list|,
name|b
parameter_list|,
name|m
parameter_list|)
define|\
value|(pgs->transfer->m.values[byte_to_tmx(b)])
end_define

end_unit

