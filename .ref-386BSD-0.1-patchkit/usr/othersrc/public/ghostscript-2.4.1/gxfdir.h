begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxfdir.h */
end_comment

begin_comment
comment|/* Font directory (font/character cache manager) definitions */
end_comment

begin_comment
comment|/* Requires gsfont.h. */
end_comment

begin_comment
comment|/* A font directory (font/character cache manager). */
end_comment

begin_struct
struct|struct
name|gs_font_dir_s
block|{
name|proc_alloc_t
name|alloc
decl_stmt|;
name|proc_free_t
name|free
decl_stmt|;
comment|/* Font directory */
name|long
name|next_id
decl_stmt|;
comment|/* next unique ID */
comment|/* Scaled font cache */
name|gs_font
modifier|*
name|scaled_fonts
decl_stmt|;
comment|/* list of recently scaled fonts */
name|uint
name|ssize
decl_stmt|,
name|smax
decl_stmt|;
comment|/* Character cache parameters and statistics */
name|uint
name|bsize
decl_stmt|,
name|bmax
decl_stmt|;
comment|/* # of bytes for cached chars */
name|uint
name|msize
decl_stmt|,
name|mmax
decl_stmt|;
comment|/* # of cached font/matrix pairs */
name|uint
name|csize
decl_stmt|,
name|cmax
decl_stmt|;
comment|/* # of cached chars */
name|uint
name|lower
decl_stmt|;
comment|/* min size at which cached chars */
comment|/* should be stored compressed */
name|uint
name|upper
decl_stmt|;
comment|/* max size of a single cached char */
comment|/* Character cache */
name|struct
name|cached_char_s
modifier|*
modifier|*
name|chars
decl_stmt|;
comment|/* chain heads */
name|uint
name|chars_mask
decl_stmt|;
comment|/* (a power of 2 -1) */
name|struct
name|cached_fm_pair_s
modifier|*
name|mdata
decl_stmt|;
name|uint
name|mnext
decl_stmt|;
comment|/* rover for allocating font/matrix pairs */
name|byte
modifier|*
name|cdata
decl_stmt|;
comment|/* struct cached_char_head_s * */
name|uint
name|cdata_size
decl_stmt|;
name|uint
name|cnext
decl_stmt|;
comment|/* rover for allocating cached characters */
block|}
struct|;
end_struct

end_unit

