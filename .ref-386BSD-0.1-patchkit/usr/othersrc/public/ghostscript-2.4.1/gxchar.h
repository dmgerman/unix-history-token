begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxchar.h */
end_comment

begin_comment
comment|/* Internal character definition for Ghostscript library */
end_comment

begin_comment
comment|/* Requires gsmatrix.h, gxfixed.h, gzdevice.h */
end_comment

begin_include
include|#
directive|include
file|"gschar.h"
end_include

begin_comment
comment|/* An entry for a (font,matrix) pair in the character cache. */
end_comment

begin_comment
comment|/* Either font == 0 and UniqueID != -1, or font != 0 and UniqueID == -1. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cached_fm_pair_s
name|cached_fm_pair
typedef|;
end_typedef

begin_struct
struct|struct
name|cached_fm_pair_s
block|{
name|struct
name|gs_font_s
modifier|*
name|font
decl_stmt|;
comment|/* base font */
name|long
name|UniqueID
decl_stmt|;
comment|/* font UniqueID */
name|char
modifier|*
comment|/* void * */
name|encoding
decl_stmt|;
comment|/* encoding vector (opaque) */
name|float
name|mxx
decl_stmt|,
name|mxy
decl_stmt|,
name|myx
decl_stmt|,
name|myy
decl_stmt|;
comment|/* transformation */
name|int
name|num_chars
decl_stmt|;
comment|/* # of cached chars with this */
comment|/* f/m pair */
block|}
struct|;
end_struct

begin_comment
comment|/* If font == 0 and UniqueID == -1, this is a free entry. */
end_comment

begin_define
define|#
directive|define
name|fm_pair_is_free
parameter_list|(
name|pair
parameter_list|)
value|((pair)->font == 0&& (pair)->UniqueID == -1)
end_define

begin_define
define|#
directive|define
name|fm_pair_set_free
parameter_list|(
name|pair
parameter_list|)
value|((pair)->font = 0, (pair)->UniqueID = -1)
end_define

begin_comment
comment|/* The type of cached characters is opaque. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cached_char_s
name|cached_char
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|uint
name|cached_char_sizeof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An enumeration object for string display. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|sws_none
block|,
name|sws_cache
block|,
comment|/* setcachedevice */
name|sws_no_cache
comment|/* setcharwidth */
block|}
name|show_width_status
typedef|;
end_typedef

begin_struct
struct|struct
name|gs_show_enum_s
block|{
comment|/* Following are set at creation time */
name|gs_state
modifier|*
name|pgs
decl_stmt|;
name|int
name|level
decl_stmt|;
comment|/* save the level of pgs */
name|byte
modifier|*
name|str
decl_stmt|;
comment|/* char may be signed! */
name|uint
name|size
decl_stmt|;
name|float
name|wcx
decl_stmt|,
name|wcy
decl_stmt|;
comment|/* for widthshow */
name|char_code
name|wchr
decl_stmt|;
comment|/* ditto */
name|float
name|ax
decl_stmt|,
name|ay
decl_stmt|;
comment|/* for ashow */
name|int
name|add
decl_stmt|;
comment|/* true if a[width]show */
name|int
name|do_kern
decl_stmt|;
comment|/* true if kshow */
name|int
name|slow_show
decl_stmt|;
comment|/* [a][width]show or kshow */
name|int
name|charpath_flag
decl_stmt|;
comment|/* 0 for show, 1 for false */
comment|/* charpath, 2 for true charpath */
name|int
name|stringwidth_flag
decl_stmt|;
comment|/* 0 for show/charpath, */
comment|/* 1 for stringwidth */
name|int
name|can_cache
decl_stmt|;
comment|/* true if can cache chars */
name|int
name|cxmin
decl_stmt|,
name|cymin
decl_stmt|,
name|cxmax
decl_stmt|,
name|cymax
decl_stmt|;
comment|/* int version of quick-check */
comment|/* clipping box */
name|int
name|is_composite
decl_stmt|;
comment|/* true if composite font */
name|int
name|ftx
decl_stmt|,
name|fty
decl_stmt|;
comment|/* transformed font translation */
comment|/* Following are set at most once */
name|gx_device_memory
name|dev_cache_info
decl_stmt|;
name|device
name|dev_cache_dev
decl_stmt|;
name|int
name|dev_cache_set
decl_stmt|;
comment|/* Following are updated dynamically */
name|uint
name|index
decl_stmt|;
comment|/* index within string */
name|gs_fixed_point
name|wxy
decl_stmt|;
comment|/* for current char in device coords */
name|cached_char
modifier|*
name|cc
decl_stmt|;
comment|/* being accumulated */
name|gs_point
name|width
decl_stmt|;
comment|/* total width of string, set at end */
name|show_width_status
name|width_status
decl_stmt|;
name|gs_fixed_point
name|metrics_sb
decl_stmt|,
name|metrics_width
decl_stmt|;
comment|/* width and side */
comment|/* bearing from metrics, in */
comment|/* *character* coordinates */
comment|/* (only used for Type 1 fonts) */
name|byte
name|sb_set
decl_stmt|,
name|width_set
decl_stmt|;
comment|/* true if metrics set */
comment|/* (only used for Type 1 fonts) */
name|int
name|color_loaded
decl_stmt|;
comment|/* true if have done gx_color_render */
name|int
argument_list|(
operator|*
name|continue_proc
argument_list|)
argument_list|(
name|P1
argument_list|(
expr|struct
name|gs_show_enum_s
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|/* continuation procedure */
comment|/* Following are dynamic, for composite fonts only */
define|#
directive|define
name|max_font_depth
value|5
name|struct
name|gs_font_s
modifier|*
name|fstack
index|[
name|max_font_depth
index|]
decl_stmt|;
name|int
name|fdepth
decl_stmt|;
name|struct
name|gs_font_s
modifier|*
name|pfont
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|gs_show_enum_s_DEFINED
end_define

begin_comment
comment|/* Cached character procedures (in gxfont.c) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gs_font_dir_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|gs_font_dir_DEFINED
end_define

begin_typedef
typedef|typedef
name|struct
name|gs_font_dir_s
name|gs_font_dir
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|gx_char_cache_init
argument_list|(
name|P1
argument_list|(
name|gs_font_dir
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cached_char
modifier|*
name|gx_alloc_char_bits
argument_list|(
name|P4
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|gx_device_memory
operator|*
argument_list|,
name|ushort
argument_list|,
name|ushort
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gx_free_cached_char
argument_list|(
name|P2
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|cached_char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cached_fm_pair
modifier|*
name|gx_lookup_fm_pair
argument_list|(
name|P1
argument_list|(
name|gs_state
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gx_add_cached_char
argument_list|(
name|P4
argument_list|(
name|gs_font_dir
operator|*
argument_list|,
name|gx_device_memory
operator|*
argument_list|,
name|cached_char
operator|*
argument_list|,
name|cached_fm_pair
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cached_char
modifier|*
name|gx_lookup_cached_char
argument_list|(
name|P3
argument_list|(
name|gs_state
operator|*
argument_list|,
name|cached_fm_pair
operator|*
argument_list|,
name|char_code
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gx_image_cached_char
argument_list|(
name|P2
argument_list|(
name|gs_show_enum
operator|*
argument_list|,
name|cached_char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

