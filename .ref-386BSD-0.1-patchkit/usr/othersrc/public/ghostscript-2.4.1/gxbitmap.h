begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxbitmap.h */
end_comment

begin_comment
comment|/* Definitions for stored bitmaps for Ghostscript */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gxbitmap_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|gxbitmap_INCLUDED
end_define

begin_comment
comment|/*  * Drivers such as the X driver and the command list (band list) driver  * benefit greatly by being able to cache bitmaps (tiles and characters)  * and refer to them later.  To support this, we define a bitmap ID type  * which the kernel passes to the driver on each copy_ or tile_ operation.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|gx_bitmap_id
typedef|;
end_typedef

begin_define
define|#
directive|define
name|gx_no_bitmap_id
value|0L
end_define

begin_comment
comment|/*  * Structure for describing stored bitmaps.  * Bitmaps are stored bit-big-endian (i.e., the 2^7 bit of the first  * byte corresponds to x=0), as a sequence of bytes (i.e., you can't  * do word-oriented operations on them if you're on a little-endian  * platform like the Intel 80x86 or VAX).  Each scan line must start on  * a (32-bit) word boundary, and hence must be is padded to a word boundary,  * although this should rarely be of concern, since the raster and width  * are specified individually.  The first scan line corresponds to y=0  * in whatever coordinate system is relevant.  *  * For bitmaps used as halftone tiles, we may replicate the tile in  * X and/or Y, but it is still valuable to know the true tile dimensions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gx_bitmap_s
block|{
name|byte
modifier|*
name|data
decl_stmt|;
name|int
name|raster
decl_stmt|;
comment|/* bytes per scan line */
name|gs_int_point
name|size
decl_stmt|;
comment|/* width, height */
name|gx_bitmap_id
name|id
decl_stmt|;
name|ushort
name|rep_width
decl_stmt|,
name|rep_height
decl_stmt|;
comment|/* true size of tile */
block|}
name|gx_bitmap
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gxbitmap_INCLUDED */
end_comment

end_unit

