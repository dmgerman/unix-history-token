begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gdevprn.h */
end_comment

begin_comment
comment|/* Common header file for memory-buffered printers */
end_comment

begin_include
include|#
directive|include
file|"memory_.h"
end_include

begin_include
include|#
directive|include
file|"string_.h"
end_include

begin_include
include|#
directive|include
file|"gs.h"
end_include

begin_include
include|#
directive|include
file|"gsmatrix.h"
end_include

begin_comment
comment|/* for gxdevice.h */
end_comment

begin_include
include|#
directive|include
file|"gxdevice.h"
end_include

begin_include
include|#
directive|include
file|"gxdevmem.h"
end_include

begin_include
include|#
directive|include
file|"gxclist.h"
end_include

begin_comment
comment|/* Define the parameters for the printer rendering method. */
end_comment

begin_comment
comment|/* If the entire bitmap fits in PRN_MAX_BITMAP, render in RAM, */
end_comment

begin_comment
comment|/* otherwise use a command list with a size of PRN_BUFFER_SPACE. */
end_comment

begin_comment
comment|/* (These are "properties" that can be changed by a Ghostscript program.) */
end_comment

begin_if
if|#
directive|if
name|arch_ints_are_short
end_if

begin_comment
comment|/* 16-bit machines have little dinky RAMs.... */
end_comment

begin_define
define|#
directive|define
name|PRN_MAX_BITMAP
value|32000
end_define

begin_define
define|#
directive|define
name|PRN_BUFFER_SPACE
value|25000
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 32-bit machines have great big hulking RAMs.... */
end_comment

begin_define
define|#
directive|define
name|PRN_MAX_BITMAP
value|10000000L
end_define

begin_define
define|#
directive|define
name|PRN_BUFFER_SPACE
value|1000000L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the declaration macro for print_page procedures. */
end_comment

begin_define
define|#
directive|define
name|dev_proc_print_page
parameter_list|(
name|proc
parameter_list|)
define|\
value|int proc(P2(gx_device_printer *, FILE *))
end_define

begin_comment
comment|/* Structure for generic printer devices. */
end_comment

begin_comment
comment|/* This must be preceded by gx_device_common. */
end_comment

begin_comment
comment|/* Printer devices are actually a union of a memory device */
end_comment

begin_comment
comment|/* and a clist device, plus some additional state. */
end_comment

begin_define
define|#
directive|define
name|gx_prn_device_common
define|\
value|byte skip[max(sizeof(gx_device_memory), sizeof(gx_device_clist)) -\ 		  sizeof(gx_device) + sizeof(double)
comment|/* padding */
value|];\
comment|/* The following is required only for devices where */
value|\
comment|/* output_page is gdev_prn_output_page; */
value|\
comment|/* it is ignored for other devices. */
value|\ 	dev_proc_print_page((*print_page));\
comment|/* ------ The following items must be set before ------ */
value|\
comment|/* ------ calling the device open routine. ------ */
value|\ 	long max_bitmap;
comment|/* max size of non-buffered bitmap */
value|\ 	long use_buffer_space;
comment|/* space to use for buffer */
value|\ 	char fname[80];
comment|/* output file name */
value|\
comment|/* ------ End of preset items ------ */
value|\ 	FILE *file;
comment|/* output file */
value|\ 	char ccfname[30];
comment|/* clist file name */
value|\ 	FILE *ccfile;
comment|/* command list scratch file */
value|\ 	char cbfname[30];
comment|/* clist block file name */
value|\ 	FILE *cbfile;
comment|/* command list block scratch file */
value|\ 	long buffer_space;
comment|/* amount of space for clist buffer, */
value|\
comment|/* 0 means not using clist */
value|\ 	byte *buf;
comment|/* buffer for rendering */
value|\ 	int page_count;
comment|/* # of pages printed so far */
value|\ 	gx_device_procs *orig_procs;
comment|/* original procs */
value|\ 	gx_device_procs mod_procs
end_define

begin_comment
comment|/* modified procs */
end_comment

begin_comment
comment|/* The device descriptor */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gx_device_printer_s
name|gx_device_printer
typedef|;
end_typedef

begin_struct
struct|struct
name|gx_device_printer_s
block|{
name|gx_device_common
expr_stmt|;
name|gx_prn_device_common
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Macro for casting gx_device argument */
end_comment

begin_define
define|#
directive|define
name|prn_dev
value|((gx_device_printer *)dev)
end_define

begin_comment
comment|/* Standard device procedures for printers */
end_comment

begin_expr_stmt
name|dev_proc_open_device
argument_list|(
name|gdev_prn_open
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_output_page
argument_list|(
name|gdev_prn_output_page
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_close_device
argument_list|(
name|gdev_prn_close
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_map_rgb_color
argument_list|(
name|gdev_prn_map_rgb_color
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_map_color_rgb
argument_list|(
name|gdev_prn_map_color_rgb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_get_props
argument_list|(
name|gdev_prn_get_props
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dev_proc_put_props
argument_list|(
name|gdev_prn_put_props
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Macro for generating procedure table */
end_comment

begin_define
define|#
directive|define
name|prn_procs
parameter_list|(
name|proc_open
parameter_list|,
name|proc_output_page
parameter_list|,
name|proc_close
parameter_list|)
define|\
value|prn_color_procs(proc_open, proc_output_page, proc_close,\ 		  gdev_prn_map_rgb_color, gdev_prn_map_color_rgb)
end_define

begin_comment
comment|/* See gdev_prn_open for explanation of the NULLs below. */
end_comment

begin_define
define|#
directive|define
name|prn_color_procs
parameter_list|(
name|proc_open
parameter_list|,
name|proc_output_page
parameter_list|,
name|proc_close
parameter_list|,
name|proc_map_rgb_color
parameter_list|,
name|proc_map_color_rgb
parameter_list|)
value|{\ 	proc_open,\ 	gx_default_get_initial_matrix,\ 	gx_default_sync_output,\ 	proc_output_page,\ 	proc_close,\ 	proc_map_rgb_color,\ 	proc_map_color_rgb,\ 	NULL,
comment|/* fill_rectangle */
value|\ 	NULL,
comment|/* tile_rectangle */
value|\ 	NULL,
comment|/* copy_mono */
value|\ 	NULL,
comment|/* copy_color */
value|\ 	NULL,
comment|/* draw_line */
value|\ 	gx_default_get_bits,\ 	gdev_prn_get_props,\ 	gdev_prn_put_props\ }
end_define

begin_comment
comment|/* The standard printer device procedures */
end_comment

begin_comment
comment|/* (using gdev_prn_open/output_page/close). */
end_comment

begin_decl_stmt
specifier|extern
name|gx_device_procs
name|prn_std_procs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro for generating the device descriptor. */
end_comment

begin_comment
comment|/*  * The computations of page width and height in pixels should really be  *	((int)(page_width_inches*x_dpi))  * but some compilers (the Ultrix 3.X pcc compiler and the HPUX compiler)  * can't cast a computed float to an int.  That's why we specify  * the page width and height in inches/10 instead of inches.  *  * Note that the macro is broken up so as to be usable for devices that  * add further initialized state to the printer device.  */
end_comment

begin_define
define|#
directive|define
name|prn_device_body
parameter_list|(
name|devtype
parameter_list|,
name|procs
parameter_list|,
name|dev_name
parameter_list|,
name|width_10ths
parameter_list|,
name|height_10ths
parameter_list|,
name|x_dpi
parameter_list|,
name|y_dpi
parameter_list|,
name|l_margin
parameter_list|,
name|b_margin
parameter_list|,
name|r_margin
parameter_list|,
name|t_margin
parameter_list|,
name|num_comp
parameter_list|,
name|depth
parameter_list|,
name|max_gray
parameter_list|,
name|max_rgb
parameter_list|,
name|dither_gray
parameter_list|,
name|dither_rgb
parameter_list|,
name|print_page
parameter_list|)
define|\
value|sizeof(devtype),\&procs,\ 	dev_name,\ 	(int)((long)width_10ths * x_dpi / 10),
comment|/* width */
value|\ 	(int)((long)height_10ths * y_dpi / 10),
comment|/* height */
value|\ 	x_dpi,\ 	y_dpi,\ 	l_margin, b_margin, r_margin, t_margin,\ 	 { num_comp, depth, max_gray, max_rgb, dither_gray, dither_rgb },\ 	0,
comment|/* not initialized yet */
value|\ 	  { 0 },
comment|/* skip */
value|\ 	print_page,\ 	PRN_MAX_BITMAP,\ 	PRN_BUFFER_SPACE,\ 	  { 0 },
comment|/* fname */
value|\ 	0, { 0 }, 0, { 0 }, 0, 0, 0, 0, 0, { 0 }
end_define

begin_comment
comment|/* ... mod_procs */
end_comment

begin_define
define|#
directive|define
name|prn_device
parameter_list|(
name|procs
parameter_list|,
name|dev_name
parameter_list|,
name|width_10ths
parameter_list|,
name|height_10ths
parameter_list|,
name|x_dpi
parameter_list|,
name|y_dpi
parameter_list|,
name|l_margin
parameter_list|,
name|b_margin
parameter_list|,
name|r_margin
parameter_list|,
name|t_margin
parameter_list|,
name|color_bits
parameter_list|,
name|print_page
parameter_list|)
define|\
value|{ prn_device_body(gx_device_printer, procs, dev_name,\     width_10ths, height_10ths, x_dpi, y_dpi,\     l_margin, b_margin, r_margin, t_margin,\     (color_bits> 1 ? 3 : 1),\     ((color_bits> 1)& (color_bits< 8) ? 8 : color_bits),\     (color_bits>= 8 ? 255 : 1),\     (color_bits>= 8 ? 255 : color_bits> 1 ? 1 : 0),\     (color_bits>= 8 ? 5 : 2),\     (color_bits>= 8 ? 5 : color_bits> 1 ? 2 : 0),\     print_page)\ }
end_define

begin_comment
comment|/* Common procedures defined in gdevprn.c */
end_comment

begin_decl_stmt
name|int
name|gdev_prn_open_printer
argument_list|(
name|P1
argument_list|(
name|gx_device
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint
name|gdev_prn_bytes_per_scan_line
argument_list|(
name|P1
argument_list|(
name|gx_device_printer
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gdev_prn_copy_scan_lines
argument_list|(
name|P4
argument_list|(
name|gx_device_printer
operator|*
argument_list|,
name|int
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gdev_prn_get_bits
argument_list|(
name|P5
argument_list|(
name|gx_device_printer
operator|*
argument_list|,
name|int
argument_list|,
name|byte
operator|*
argument_list|,
name|uint
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gdev_prn_close_printer
argument_list|(
name|P1
argument_list|(
name|gx_device
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BACKWARD COMPATIBILITY */
end_comment

begin_define
define|#
directive|define
name|gdev_mem_bytes_per_scan_line
parameter_list|(
name|dev
parameter_list|)
define|\
value|gdev_prn_bytes_per_scan_line((gx_device_printer *)(dev))
end_define

begin_define
define|#
directive|define
name|gdev_prn_transpose_8x8
parameter_list|(
name|inp
parameter_list|,
name|ils
parameter_list|,
name|outp
parameter_list|,
name|ols
parameter_list|)
define|\
value|memflip8x8(inp,ils,outp,ols)
end_define

end_unit

