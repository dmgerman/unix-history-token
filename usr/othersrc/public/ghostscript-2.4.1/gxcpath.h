begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxcpath.h */
end_comment

begin_comment
comment|/* Interface to clipping devices */
end_comment

begin_comment
comment|/* requires gzpath.h */
end_comment

begin_comment
comment|/* A cached cursor, relative to a known gx_clip_list. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rect_cursor_s
block|{
name|gx_clip_rect
modifier|*
name|rptr
decl_stmt|;
block|}
name|rect_cursor
typedef|;
end_typedef

begin_comment
comment|/* Device for accumulating a rectangle list. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gx_device_accum_s
block|{
name|gx_device_common
expr_stmt|;
name|gs_memory_procs
name|memory_procs
decl_stmt|;
comment|/* set by client */
name|gs_int_rect
name|bbox
decl_stmt|;
name|gx_clip_list
name|list
decl_stmt|;
name|gx_clip_rect
modifier|*
name|last
decl_stmt|;
block|}
name|gx_device_accum
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|gx_device_accum
name|gs_accum_device
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device for clipping with a rectangle list. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gx_clip_device_s
block|{
name|gx_device_common
expr_stmt|;
name|gx_device
modifier|*
name|target
decl_stmt|;
comment|/* set by client */
name|gx_clip_list
name|list
decl_stmt|;
comment|/* set by client */
name|rect_cursor
name|current
decl_stmt|;
block|}
name|gx_device_clip
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|gx_device_clip
name|gs_clip_device
decl_stmt|;
end_decl_stmt

end_unit

