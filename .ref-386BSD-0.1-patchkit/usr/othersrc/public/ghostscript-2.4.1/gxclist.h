begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxclist.h */
end_comment

begin_comment
comment|/* Command list definitions for Ghostscript. */
end_comment

begin_comment
comment|/* Requires gxdevice.h and gxdevmem.h */
end_comment

begin_comment
comment|/*  * A command list is essentially a compressed list of driver calls.  * Command lists are used to record an image that must be rendered in bands  * for a high-resolution printer.  In the future, they may be used  * for other purposes as well, such as providing a more compact representation  * of cached characters than a full bitmap (at high resolution), or  * representing fully rendered user paths (a Level 2 feature).  */
end_comment

begin_comment
comment|/* A command list device outputs commands to a stream, */
end_comment

begin_comment
comment|/* then reads them back to render in bands. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_device_clist_s
name|gx_device_clist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|gx_clist_state_s
name|gx_clist_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|slot_index
decl_stmt|;
block|}
name|tile_hash
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|gx_bitmap_id
name|id
decl_stmt|;
comment|/* byte band_mask[]; */
comment|/* byte bits[]; */
block|}
name|tile_slot
typedef|;
end_typedef

begin_struct
struct|struct
name|gx_device_clist_s
block|{
name|gx_device_common
expr_stmt|;
comment|/* (see gxdevice.h) */
comment|/* Following must be set before writing or reading. */
name|gx_device
modifier|*
name|target
decl_stmt|;
comment|/* device for which commands */
comment|/* are being buffered */
name|byte
modifier|*
name|data
decl_stmt|;
comment|/* buffer area */
name|uint
name|data_size
decl_stmt|;
comment|/* size of buffer */
name|FILE
modifier|*
name|cfile
decl_stmt|;
comment|/* command list file */
name|FILE
modifier|*
name|bfile
decl_stmt|;
comment|/* command list block file */
comment|/* Following are used only when writing. */
name|gx_clist_state
modifier|*
name|states
decl_stmt|;
comment|/* current state of each band */
name|byte
modifier|*
name|cbuf
decl_stmt|;
comment|/* start of command buffer */
name|byte
modifier|*
name|cnext
decl_stmt|;
comment|/* next slot in command buffer */
name|byte
modifier|*
name|cend
decl_stmt|;
comment|/* end of command buffer */
name|gx_clist_state
modifier|*
name|ccls
decl_stmt|;
comment|/* clist_state of last command */
comment|/* Following is the tile cache, used only when writing. */
name|gx_bitmap
name|tile
decl_stmt|;
comment|/* current tile cache parameters */
comment|/* (data pointer& id not used) */
name|tile_hash
modifier|*
name|tile_hash_table
decl_stmt|;
comment|/* hash table for tile cache: */
comment|/* -1 = unused,>= 0 = slot index */
name|uint
name|tile_max_size
decl_stmt|;
comment|/* max size of a single tile */
name|uint
name|tile_hash_mask
decl_stmt|;
comment|/* size of tile hash table -1 */
name|uint
name|tile_band_mask_size
decl_stmt|;
comment|/* size of band mask preceding */
comment|/* each tile in the cache */
name|uint
name|tile_count
decl_stmt|;
comment|/* # of occupied entries in cache */
name|uint
name|tile_max_count
decl_stmt|;
comment|/* capacity of the cache */
comment|/* Following are used for both writing and reading. */
name|byte
modifier|*
name|tile_data
decl_stmt|;
comment|/* data for cached tiles */
name|uint
name|tile_data_size
decl_stmt|;
comment|/* total size of tile cache data */
name|uint
name|tile_slot_size
decl_stmt|;
comment|/* size of each slot in tile cache */
define|#
directive|define
name|tile_slot_ptr
parameter_list|(
name|cldev
parameter_list|,
name|index
parameter_list|)
define|\
value|(tile_slot *)((cldev)->tile_data + (index) * (cldev)->tile_slot_size)
define|#
directive|define
name|ts_mask
parameter_list|(
name|pts
parameter_list|)
value|(byte *)((pts) + 1)
define|#
directive|define
name|ts_bits
parameter_list|(
name|cldev
parameter_list|,
name|pts
parameter_list|)
value|(ts_mask(pts) + (cldev)->tile_band_mask_size)
comment|/* Following are set when writing, read when reading. */
name|int
name|band_height
decl_stmt|;
comment|/* height of each band */
name|int
name|nbands
decl_stmt|;
comment|/* # of bands */
name|long
name|bfile_end_pos
decl_stmt|;
comment|/* ftell at end of bfile */
comment|/* Following are used only when reading. */
name|int
name|ymin
decl_stmt|,
name|ymax
decl_stmt|;
comment|/* current band */
name|gx_device_memory
name|mdev
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|gx_device_clist
name|gs_clist_device
decl_stmt|;
end_decl_stmt

end_unit

