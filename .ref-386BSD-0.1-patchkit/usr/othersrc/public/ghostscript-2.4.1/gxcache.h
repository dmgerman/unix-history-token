begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxcache.h */
end_comment

begin_comment
comment|/* Definitions for character cache */
end_comment

begin_comment
comment|/* Requires gxchar.h */
end_comment

begin_comment
comment|/* The character cache contains both used and free blocks. */
end_comment

begin_comment
comment|/* All blocks have a common header. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cached_char_head_s
block|{
name|uint
name|size
decl_stmt|;
comment|/* total block size in bytes */
name|cached_fm_pair
modifier|*
name|pair
decl_stmt|;
comment|/* font/matrix pair, 0 if free */
block|}
name|cached_char_head
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cc_head_is_free
parameter_list|(
name|cch
parameter_list|)
value|((cch)->pair == 0)
end_define

begin_define
define|#
directive|define
name|cc_head_set_free
parameter_list|(
name|cch
parameter_list|)
value|((cch)->pair = 0)
end_define

begin_comment
comment|/* A cached bitmap for an individual character. */
end_comment

begin_comment
comment|/* The bits immediately follow the structure. */
end_comment

begin_struct
struct|struct
name|cached_char_s
block|{
comment|/* The code and font/matrix pair are the 'key' in the cache. */
name|cached_char_head
name|head
decl_stmt|;
comment|/* (must be first) */
comment|/* references font/matrix pair */
name|char_code
name|code
decl_stmt|;
comment|/* character code */
name|cached_char
modifier|*
name|next
decl_stmt|;
comment|/* next in replacement ring */
comment|/* The rest of the structure is the 'value'. */
name|ushort
name|raster
decl_stmt|,
name|height
decl_stmt|;
comment|/* dimensions of bitmap */
name|ushort
name|width
decl_stmt|;
name|gx_bitmap_id
name|id
decl_stmt|;
name|gs_fixed_point
name|wxy
decl_stmt|;
comment|/* width in device coords */
name|gs_fixed_point
name|offset
decl_stmt|;
comment|/* (-llx, -lly) in device coords */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cc_is_free
parameter_list|(
name|cc
parameter_list|)
value|cc_head_is_free(&(cc)->head)
end_define

begin_define
define|#
directive|define
name|cc_set_free
parameter_list|(
name|cc
parameter_list|)
value|cc_head_set_free(&(cc)->head)
end_define

end_unit

