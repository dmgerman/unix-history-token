begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gdevmem.h */
end_comment

begin_comment
comment|/* Private definitions for memory devices. */
end_comment

begin_comment
comment|/*    The representation for a "memory" device is simply a    contiguous bitmap stored in something like the PostScript    representation, i.e., each scan line (in left-to-right order), padded    to a byte or word boundary, followed immediately by the next one.     The representation of strings in the Ghostscript interpreter limits    the size of a string to 64K-1 bytes, which means we can't simply use    a string for the contents of a memory device.    We get around this problem by making the client read out the    contents of a memory device bitmap in pieces.     On PCs with segmented architectures, there is no way to    obtain a contiguous block of storage larger than 64K bytes,    which isn't big enough for a full-screen bitmap, even in monochrome.    If this ever becomes a problem, we will use a banded representation.     Even though the scan lines are stored contiguously, we store a table    of their base addresses, because indexing into it is faster than    the multiplication that would otherwise be needed. */
end_comment

begin_comment
comment|/* ------ Generic macros ------ */
end_comment

begin_comment
comment|/* Macro for declaring the essential device procedures. */
end_comment

begin_define
define|#
directive|define
name|declare_mem_map_procs
parameter_list|(
name|map_rgb_color
parameter_list|,
name|map_color_rgb
parameter_list|)
define|\
value|private dev_proc_map_rgb_color(map_rgb_color);\   private dev_proc_map_color_rgb(map_color_rgb)
end_define

begin_define
define|#
directive|define
name|declare_mem_procs
parameter_list|(
name|copy_mono
parameter_list|,
name|copy_color
parameter_list|,
name|fill_rectangle
parameter_list|)
define|\
value|private dev_proc_copy_mono(copy_mono);\   private dev_proc_copy_color(copy_color);\   private dev_proc_fill_rectangle(fill_rectangle)
end_define

begin_comment
comment|/* Macro for generating the procedure record in the device descriptor */
end_comment

begin_extern
extern|extern dev_proc_open_device(mem_open
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern dev_proc_get_initial_matrix(mem_get_initial_matrix
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern dev_proc_get_bits(mem_get_bits
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|mem_procs
parameter_list|(
name|map_rgb_color
parameter_list|,
name|map_color_rgb
parameter_list|,
name|copy_mono
parameter_list|,
name|copy_color
parameter_list|,
name|fill_rectangle
parameter_list|)
define|\
value|{	mem_open,\ 	mem_get_initial_matrix,\ 	gx_default_sync_output,\ 	gx_default_output_page,\ 	gx_default_close_device,\ 	map_rgb_color,
comment|/* differs */
value|\ 	map_color_rgb,
comment|/* differs */
value|\ 	fill_rectangle,
comment|/* differs */
value|\ 	gx_default_tile_rectangle,\ 	copy_mono,
comment|/* differs */
value|\ 	copy_color,
comment|/* differs */
value|\ 	gx_default_draw_line,\ 	mem_get_bits,\ 	gx_default_get_props,\ 	gx_default_put_props\ }
end_define

begin_comment
comment|/*  * Macro for generating the device descriptor.  * Various compilers have problems with the obvious definition  * for max_value, namely:  *	(depth>= 8 ? 255 : (1<< depth) - 1)  * I tried changing (1<< depth) to (1<< (depth& 15)) to forestall bogus  * error messages about invalid shift counts, but the H-P compiler chokes  * on this.  Since the only values of depth we ever plan to support are  * powers of 2 (and 24), we just go ahead and enumerate them.  */
end_comment

begin_define
define|#
directive|define
name|max_value
parameter_list|(
name|depth
parameter_list|)
define|\
value|(depth>= 8 ? 255 : depth == 4 ? 15 : depth == 2 ? 3 : 1)
end_define

begin_define
define|#
directive|define
name|mem_device
parameter_list|(
name|name
parameter_list|,
name|depth
parameter_list|,
name|procs
parameter_list|)
define|\
value|{	sizeof(gx_device_memory),\&procs,
comment|/* differs */
value|\ 	name,
comment|/* differs */
value|\ 	0, 0,
comment|/* x and y extent (filled in) */
value|\ 	72, 72,
comment|/* density (makes initclip come out right) */
value|\ 	no_margins,
comment|/* margins */
value|\ 	   {	(depth>= 4 ? 3 : 1),
comment|/* num_components */
value|\ 		depth,\ 		max_value(depth),
comment|/* max_gray */
value|\ 		max_value(depth),
comment|/* max_rgb */
value|\ 		max_value(depth) + 1,
comment|/* dither_gray */
value|\ 		max_value(depth) + 1,
comment|/* dither_color */
value|\ 	   },\ 	0,
comment|/* not open yet */
value|\ 	identity_matrix_body,
comment|/* initial matrix (filled in) */
value|\ 	0,
comment|/* raster (filled in) */
value|\ 	(byte *)0,
comment|/* base (filled in) */
value|\ 	(byte **)0,
comment|/* line_ptrs (filled in by mem_open) */
value|\ 	0,
comment|/* initial bytes_le (filled in by mem_open) */
value|\ 	0,
comment|/* invert (filled in for mono) */
value|\ 	0, (byte *)0
comment|/* palette (filled in for color) */
value|\ }
end_define

begin_comment
comment|/* Macro for casting gx_device argument */
end_comment

begin_define
define|#
directive|define
name|mdev
value|((gx_device_memory *)dev)
end_define

begin_comment
comment|/* Macro for rectangle arguments (x,y,w,h) */
end_comment

begin_define
define|#
directive|define
name|check_rect
parameter_list|()
define|\
value|if ( w<= 0 || h<= 0 ) return 0;\ 	if ( (x | y)< 0 || x> mdev->width - w || y> mdev->height - h )\ 		return -1
end_define

begin_comment
comment|/*  * Macros for processing bitmaps in the largest possible chunks.  * Bits within a byte are always stored big-endian;  * bytes are normally stored in the natural order for the platform,  * but the client can force them into big-endian order (which is required  * for the source of copy_mono) by calling gdev_mem_ensure_byte_order.  * (mem_get_bits swaps bytes if necessary.)  * Note that we use type uint for register variables holding a chunk:  * for this reason, the chunk size cannot be larger than uint.  */
end_comment

begin_comment
comment|/******  ****** Note: we assume that ints are 2 or 4 bytes in size!  ****** (This is required by the clog2_bytes macro.)  ******/
end_comment

begin_comment
comment|/* Generic macros for chunk accessing. */
end_comment

begin_define
define|#
directive|define
name|cbytes
parameter_list|(
name|ct
parameter_list|)
value|((int)sizeof(ct))
end_define

begin_comment
comment|/* sizeof may be unsigned */
end_comment

begin_define
define|#
directive|define
name|chunk_bytes
value|cbytes(chunk)
end_define

begin_define
define|#
directive|define
name|clog2_bytes
parameter_list|(
name|ct
parameter_list|)
value|((int)sizeof(ct)>>1)
end_define

begin_comment
comment|/* works for 1,2,4! */
end_comment

begin_define
define|#
directive|define
name|chunk_log2_bytes
value|clog2_bytes(chunk)
end_define

begin_define
define|#
directive|define
name|cbits
parameter_list|(
name|ct
parameter_list|)
value|((int)sizeof(ct)*8)
end_define

begin_comment
comment|/* sizeof may be unsigned */
end_comment

begin_define
define|#
directive|define
name|chunk_bits
value|cbits(chunk)
end_define

begin_define
define|#
directive|define
name|clog2_bits
parameter_list|(
name|ct
parameter_list|)
value|(clog2_bytes(ct)+3)
end_define

begin_define
define|#
directive|define
name|chunk_log2_bits
value|clog2_bits(chunk)
end_define

begin_define
define|#
directive|define
name|cbit_mask
parameter_list|(
name|ct
parameter_list|)
value|(cbits(ct)-1)
end_define

begin_define
define|#
directive|define
name|chunk_bit_mask
value|cbit_mask(chunk)
end_define

begin_comment
comment|/*  * The obvious definition for cmask is:  *	#define cmask(ct) ((ct)~(ct)0)  * but this doesn't work on the VAX/VMS compiler, which fails to truncate  * the value to 16 bits when ct is ushort.  * Instead, we have to generate the mask with no extra 1-bits.  * We can't do this in the obvious way:  *	#define cmask(ct) ((1<< (sizeof(ct) * 8)) - 1)  * because some compilers won't allow a shift of 32 bits.  Instead,  * we have to do something really awkward:  */
end_comment

begin_define
define|#
directive|define
name|cmask
parameter_list|(
name|ct
parameter_list|)
value|((ct) (((((ct)1<< (sizeof(ct)*8-2)) - 1)<< 2) + 3))
end_define

begin_define
define|#
directive|define
name|chunk_all_bits
value|cmask(chunk)
end_define

begin_comment
comment|/*  * The obvious definition for chi_bits is:  *	#define chi_bits(ct,n) (cmask(ct)-(cmask(ct)>>(n)))  * but this doesn't work on the DEC/MIPS compilers.  * Instead, we have to restrict chi_bits to only working for values of n  * between 0 and cbits(ct)-1, and use  */
end_comment

begin_define
define|#
directive|define
name|chi_bits
parameter_list|(
name|ct
parameter_list|,
name|n
parameter_list|)
value|(ct)(~(ct)1<< (cbits(ct)-1 - (n)))
end_define

begin_define
define|#
directive|define
name|chunk_hi_bits
parameter_list|(
name|n
parameter_list|)
value|chi_bits(chunk,n)
end_define

begin_comment
comment|/* Define whether this is a machine where chunks are long, */
end_comment

begin_comment
comment|/* but the machine can't shift a long by its full width. */
end_comment

begin_define
define|#
directive|define
name|arch_cant_shift_full_chunk
define|\
value|(arch_is_big_endian&& !arch_ints_are_short&& !arch_can_shift_full_long)
end_define

begin_comment
comment|/* Macros for scan line access. */
end_comment

begin_comment
comment|/* x_to_byte is different for each number of bits per pixel. */
end_comment

begin_comment
comment|/* Note that these macros depend on the definition of chunk: */
end_comment

begin_comment
comment|/* each procedure that uses the scanning macros should #define */
end_comment

begin_comment
comment|/* (not typedef) chunk as either uint or byte. */
end_comment

begin_define
define|#
directive|define
name|scan_line_base
parameter_list|(
name|dev
parameter_list|,
name|y
parameter_list|)
value|(dev->line_ptrs[y])
end_define

begin_define
define|#
directive|define
name|declare_scan_ptr
parameter_list|(
name|ptr
parameter_list|)
value|declare_scan_ptr_as(ptr, chunk *)
end_define

begin_define
define|#
directive|define
name|declare_scan_ptr_as
parameter_list|(
name|ptr
parameter_list|,
name|ptype
parameter_list|)
define|\
value|register ptype ptr; uint draster
end_define

begin_define
define|#
directive|define
name|inc_chunk_ptr
parameter_list|(
name|ptr
parameter_list|,
name|delta
parameter_list|)
define|\
value|ptr = (chunk *)((byte *)ptr + (delta))
end_define

begin_define
define|#
directive|define
name|setup_rect
parameter_list|(
name|ptr
parameter_list|)
value|setup_rect_as(ptr, chunk *)
end_define

begin_define
define|#
directive|define
name|setup_rect_as
parameter_list|(
name|ptr
parameter_list|,
name|ptype
parameter_list|)
define|\
value|draster = mdev->raster;\ 	ptr = (ptype)(scan_line_base(mdev, y) +\ 		(x_to_byte(x)& -chunk_bytes))
end_define

end_unit

