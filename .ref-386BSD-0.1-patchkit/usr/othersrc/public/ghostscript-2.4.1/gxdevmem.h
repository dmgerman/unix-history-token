begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxdevmem.h */
end_comment

begin_comment
comment|/* "Memory" device structure for Ghostscript library */
end_comment

begin_comment
comment|/* Requires gxdevice.h */
end_comment

begin_comment
comment|/*  * A 'memory' device is essentially a stored bitmap.  * There are several different kinds: 1-bit black and white,  * 2-, 4-, and 8-bit mapped color, and 16-, 24-, and 32-bit true color.  * (16-bit uses 5/6/5 bits per color.  24- and 32-bit are equivalent:  * 24-bit takes less space, but is slower.)  All use the same structure,  * since it's so awkward to get the effect of subclasses in C.  *  * On little-endian machines, the bytes can be stored in either order.  * Little-endian order is the default, since this allows efficient  * updating; big-endian is required if the bits will be used as the  * source for a rendering operation (e.g., in the character cache).  * We provide an operation to normalize the byte order, and we trust the  * client not to do any rendering operations if the byte order is  * reversed.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_device_memory_s
name|gx_device_memory
typedef|;
end_typedef

begin_struct
struct|struct
name|gx_device_memory_s
block|{
name|gx_device_common
expr_stmt|;
comment|/* (see gxdevice.h) */
name|gs_matrix
name|initial_matrix
decl_stmt|;
comment|/* the initial transformation */
name|uint
name|raster
decl_stmt|;
comment|/* bytes per scan line, */
comment|/* filled in by '...bitmap_size' */
name|byte
modifier|*
name|base
decl_stmt|;
name|byte
modifier|*
modifier|*
name|line_ptrs
decl_stmt|;
comment|/* scan line pointers */
name|int
name|bytes_le
decl_stmt|;
comment|/* chunk size (2 bytes) if */
comment|/* bytes are stored in */
comment|/* little-endian order, else 0 */
comment|/* Following is only needed for monochrome */
name|int
name|invert
decl_stmt|;
comment|/* 0 if 1=white, -1 if 1=black */
comment|/* Following are only needed for mapped color */
name|int
name|palette_size
decl_stmt|;
comment|/* # of entries */
name|byte
modifier|*
name|palette
decl_stmt|;
comment|/* RGB triples */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|gx_device_memory
name|mem_mono_device
decl_stmt|,
name|mem_mapped2_color_device
decl_stmt|,
name|mem_mapped4_color_device
decl_stmt|,
name|mem_mapped8_color_device
decl_stmt|,
name|mem_true16_color_device
decl_stmt|,
name|mem_true24_color_device
decl_stmt|,
name|mem_true32_color_device
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Memory devices may have special setup requirements. */
end_comment

begin_comment
comment|/* In particular, it may not be obvious how much space to allocate */
end_comment

begin_comment
comment|/* for the bitmap.  Here is the routine that computes this */
end_comment

begin_comment
comment|/* from the width and height in the device structure. */
end_comment

begin_decl_stmt
specifier|extern
name|ulong
name|gdev_mem_bitmap_size
argument_list|(
name|P1
argument_list|(
name|gx_device_memory
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Determine the appropriate memory device for a given */
end_comment

begin_comment
comment|/* number of bits per pixel (0 if none suitable). */
end_comment

begin_decl_stmt
specifier|extern
name|gx_device_memory
modifier|*
name|gdev_mem_device_for_bits
argument_list|(
name|P1
argument_list|(
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Test whether a device is a memory device. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gs_device_is_memory
argument_list|(
name|P1
argument_list|(
specifier|const
name|gx_device
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ensure that the data bytes are in big-endian order. */
end_comment

begin_comment
comment|/* This is only needed when the bitmap will be used as the source */
end_comment

begin_comment
comment|/* for a copy_mono operation, and is only used for the character cache */
end_comment

begin_comment
comment|/* and similar RAM-resident devices. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gdev_mem_ensure_byte_order
argument_list|(
name|P1
argument_list|(
name|gx_device_memory
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * A memory device is guaranteed to allocate the bitmap consecutively,  * i.e., in the form that can serve as input to copy_mono or copy_color  * operations (provided that the bytes are in big-endian order, of course).  */
end_comment

end_unit

