begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gdevdjet.c */
end_comment

begin_comment
comment|/* HP LaserJet/DeskJet driver for Ghostscript */
end_comment

begin_include
include|#
directive|include
file|"gdevprn.h"
end_include

begin_include
include|#
directive|include
file|"gdevpcl.h"
end_include

begin_comment
comment|/* Thanks to Jim Mayer, Xerox Webster Research Center, */
end_comment

begin_comment
comment|/* and to Jan-Mark Wams (jms@cs.vu.nl) for improvements. */
end_comment

begin_comment
comment|/*  * You may select a resolution of 75, 100, 150, or 300 DPI.  * Normally you would do this in the makefile or on the gs command line,  * not here.  */
end_comment

begin_comment
comment|/*#define X_DPI 300*/
end_comment

begin_comment
comment|/*#define Y_DPI 300*/
end_comment

begin_comment
comment|/*  * Standard U.S. page width and height.  A4 paper is 8.4" x 11.7".  */
end_comment

begin_define
define|#
directive|define
name|WIDTH_10THS
value|85
end_define

begin_define
define|#
directive|define
name|HEIGHT_10THS
value|110
end_define

begin_define
define|#
directive|define
name|X_DPI_MAX
value|300
end_define

begin_define
define|#
directive|define
name|Y_DPI_MAX
value|300
end_define

begin_comment
comment|/* We round up the LINE_SIZE to a multiple of a ulong for faster scanning. */
end_comment

begin_define
define|#
directive|define
name|W
value|sizeof(word)
end_define

begin_define
define|#
directive|define
name|LINE_SIZE
value|((X_DPI_MAX * 85 / 10 + W * 8 - 1) / (W * 8) * W)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|X_DPI
end_ifndef

begin_define
define|#
directive|define
name|X_DPI
value|X_DPI_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Y_DPI
end_ifndef

begin_define
define|#
directive|define
name|Y_DPI
value|Y_DPI_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Printer types */
end_comment

begin_define
define|#
directive|define
name|LJ
value|0
end_define

begin_define
define|#
directive|define
name|LJplus
value|1
end_define

begin_define
define|#
directive|define
name|LJ2p
value|2
end_define

begin_define
define|#
directive|define
name|LJ3
value|3
end_define

begin_define
define|#
directive|define
name|DJ
value|4
end_define

begin_define
define|#
directive|define
name|DJ500
value|5
end_define

begin_comment
comment|/* The printer initialization strings. */
end_comment

begin_decl_stmt
name|private
name|char
modifier|*
name|init_strings
index|[]
init|=
block|{
comment|/* LaserJet PCL 3, no compression */
literal|"\033*r0A\033&l0E\033*p0x0Y\033*b0M"
block|,
comment|/* LaserJet Plus PCL 3, no compression */
literal|"\033*r0A\033&l0E\033*p0x0Y\033*b0M"
block|,
comment|/* LaserJet IIP PCL 4, mode 2 compression */
literal|"\033*r0f0A\033&l0E\033&l-185U\033*p0x0Y\033*b2M"
block|,
comment|/* LaserJet III PCL 5, mode 2&3 compression */
literal|"\033*r0f0A\033&l0E\033&l-185U\033*p0x0Y"
block|,
comment|/* DeskJet almost PCL 4, mode 2 compression */
comment|/* Key to codes: set 8.5x11 paper; portrait orientation; */
comment|/* bidirectional printing; no perf-skip; move to top left; */
comment|/* start raster graphics; mode 2 compression. */
literal|"\033&l2A\033&l0O\033&k1W\033&l0L\033*p0x0Y\033*r0A\033*b2M"
block|,
comment|/* DeskJet 500 almost PCL 4, mode 2&3 compression */
literal|"\033&l2A\033&l0O\033&k1W\033&l0L\033*p0x0Y\033*r0A"
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The patterns for skipping blank lines. */
end_comment

begin_comment
comment|/* (These are all the same now, but I'm not 100% sure this is right.) */
end_comment

begin_decl_stmt
name|private
name|char
modifier|*
name|skip_patterns
index|[]
init|=
block|{
comment|/* LaserJet PCL 3 */
literal|"\033*p+%dY"
block|,
comment|/* LaserJet Plus PCL 3 */
literal|"\033*p+%dY"
block|,
comment|/* LaserJet IIP PCL 4 */
literal|"\033*p+%dY"
block|,
comment|/* LaserJet III PCL 5 */
literal|"\033*p+%dY"
block|,
comment|/* DeskJet almost PCL 4 */
literal|"\033*p+%dY"
block|,
comment|/* DeskJet 500 almost PCL 4 */
literal|"\033*p+%dY"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The device descriptors */
end_comment

begin_function_decl
name|private
name|dev_proc_print_page
parameter_list|(
name|djet_print_page
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|private
name|dev_proc_print_page
parameter_list|(
name|djet500_print_page
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|private
name|dev_proc_print_page
parameter_list|(
name|ljet_print_page
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|private
name|dev_proc_print_page
parameter_list|(
name|ljetplus_print_page
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|private
name|dev_proc_print_page
parameter_list|(
name|ljet2p_print_page
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|private
name|dev_proc_print_page
parameter_list|(
name|ljet3_print_page
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * HP printers need their own get_initial_matrix procedure.  See the  * definition of hp_get_initial_matrix for the reason why.  */
end_comment

begin_function_decl
name|private
name|dev_proc_get_initial_matrix
parameter_list|(
name|hp_get_initial_matrix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* See gdevprn.h and gdevprn.c to understand the NULL entries below. */
end_comment

begin_decl_stmt
name|gx_device_procs
name|prn_hp_procs
init|=
block|{
name|gdev_prn_open
block|,
name|hp_get_initial_matrix
block|,
name|gx_default_sync_output
block|,
name|gdev_prn_output_page
block|,
name|gdev_prn_close
block|,
name|gdev_prn_map_rgb_color
block|,
name|gdev_prn_map_color_rgb
block|,
name|NULL
block|,
comment|/* fill_rectangle */
name|NULL
block|,
comment|/* tile_rectangle */
name|NULL
block|,
comment|/* copy_mono */
name|NULL
block|,
comment|/* copy_color */
name|NULL
block|,
comment|/* draw_line */
name|NULL
block|,
comment|/* get_bits */
name|gdev_prn_get_props
block|,
name|gdev_prn_put_props
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gx_device_printer
name|gs_deskjet_device
init|=
name|prn_device
argument_list|(
name|prn_hp_procs
argument_list|,
literal|"deskjet"
argument_list|,
name|WIDTH_10THS
argument_list|,
name|HEIGHT_10THS
argument_list|,
name|X_DPI
argument_list|,
name|Y_DPI
argument_list|,
literal|0.25
argument_list|,
literal|0.50
argument_list|,
literal|0.25
argument_list|,
literal|0.0625
argument_list|,
comment|/* margins */
literal|1
argument_list|,
name|djet_print_page
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gx_device_printer
name|gs_djet500_device
init|=
name|prn_device
argument_list|(
name|prn_hp_procs
argument_list|,
literal|"djet500"
argument_list|,
name|WIDTH_10THS
argument_list|,
name|HEIGHT_10THS
argument_list|,
name|X_DPI
argument_list|,
name|Y_DPI
argument_list|,
literal|0.25
argument_list|,
literal|0.50
argument_list|,
literal|0.25
argument_list|,
literal|0.0625
argument_list|,
comment|/* margins */
literal|1
argument_list|,
name|djet500_print_page
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gx_device_printer
name|gs_laserjet_device
init|=
name|prn_device
argument_list|(
name|prn_hp_procs
argument_list|,
literal|"laserjet"
argument_list|,
name|WIDTH_10THS
argument_list|,
name|HEIGHT_10THS
argument_list|,
name|X_DPI
argument_list|,
name|Y_DPI
argument_list|,
literal|0.05
argument_list|,
literal|0.25
argument_list|,
literal|0.55
argument_list|,
literal|0.25
argument_list|,
comment|/* margins */
literal|1
argument_list|,
name|ljet_print_page
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gx_device_printer
name|gs_ljetplus_device
init|=
name|prn_device
argument_list|(
name|prn_hp_procs
argument_list|,
literal|"ljetplus"
argument_list|,
name|WIDTH_10THS
argument_list|,
name|HEIGHT_10THS
argument_list|,
name|X_DPI
argument_list|,
name|Y_DPI
argument_list|,
literal|0.05
argument_list|,
literal|0.25
argument_list|,
literal|0.55
argument_list|,
literal|0.25
argument_list|,
comment|/* margins */
literal|1
argument_list|,
name|ljetplus_print_page
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gx_device_printer
name|gs_ljet2p_device
init|=
name|prn_device
argument_list|(
name|prn_hp_procs
argument_list|,
literal|"ljet2p"
argument_list|,
name|WIDTH_10THS
argument_list|,
name|HEIGHT_10THS
argument_list|,
name|X_DPI
argument_list|,
name|Y_DPI
argument_list|,
literal|0.20
argument_list|,
literal|0.25
argument_list|,
literal|0.25
argument_list|,
literal|0.25
argument_list|,
comment|/* margins */
literal|1
argument_list|,
name|ljet2p_print_page
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gx_device_printer
name|gs_ljet3_device
init|=
name|prn_device
argument_list|(
name|prn_hp_procs
argument_list|,
literal|"ljet3"
argument_list|,
name|WIDTH_10THS
argument_list|,
name|HEIGHT_10THS
argument_list|,
name|X_DPI
argument_list|,
name|Y_DPI
argument_list|,
literal|0.20
argument_list|,
literal|0.25
argument_list|,
literal|0.25
argument_list|,
literal|0.25
argument_list|,
comment|/* margins */
literal|1
argument_list|,
name|ljet3_print_page
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward references */
end_comment

begin_decl_stmt
name|private
name|int
name|hpjet_print_page
argument_list|(
name|P3
argument_list|(
name|gx_device_printer
operator|*
argument_list|,
name|FILE
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Internal routines ------ */
end_comment

begin_comment
comment|/* The DeskJet can compress (mode 2) */
end_comment

begin_function
name|private
name|int
name|djet_print_page
parameter_list|(
name|gx_device_printer
modifier|*
name|pdev
parameter_list|,
name|FILE
modifier|*
name|prn_stream
parameter_list|)
block|{
return|return
name|hpjet_print_page
argument_list|(
name|pdev
argument_list|,
name|prn_stream
argument_list|,
name|DJ
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* The DeskJet500 can compress (mode 3) */
end_comment

begin_function
name|private
name|int
name|djet500_print_page
parameter_list|(
name|gx_device_printer
modifier|*
name|pdev
parameter_list|,
name|FILE
modifier|*
name|prn_stream
parameter_list|)
block|{
return|return
name|hpjet_print_page
argument_list|(
name|pdev
argument_list|,
name|prn_stream
argument_list|,
name|DJ500
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* The LaserJet series II can't compress */
end_comment

begin_function
name|private
name|int
name|ljet_print_page
parameter_list|(
name|gx_device_printer
modifier|*
name|pdev
parameter_list|,
name|FILE
modifier|*
name|prn_stream
parameter_list|)
block|{
return|return
name|hpjet_print_page
argument_list|(
name|pdev
argument_list|,
name|prn_stream
argument_list|,
name|LJ
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* The LaserJet Plus can't compress */
end_comment

begin_function
name|private
name|int
name|ljetplus_print_page
parameter_list|(
name|gx_device_printer
modifier|*
name|pdev
parameter_list|,
name|FILE
modifier|*
name|prn_stream
parameter_list|)
block|{
return|return
name|hpjet_print_page
argument_list|(
name|pdev
argument_list|,
name|prn_stream
argument_list|,
name|LJplus
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* All LaserJet series IIIs (III,IIId,IIIp,IIIsi) compress (mode 3) */
end_comment

begin_function
name|private
name|int
name|ljet3_print_page
parameter_list|(
name|gx_device_printer
modifier|*
name|pdev
parameter_list|,
name|FILE
modifier|*
name|prn_stream
parameter_list|)
block|{
return|return
name|hpjet_print_page
argument_list|(
name|pdev
argument_list|,
name|prn_stream
argument_list|,
name|LJ3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* LaserJet series IIp& IId compress (mode 2) */
end_comment

begin_function
name|private
name|int
name|ljet2p_print_page
parameter_list|(
name|gx_device_printer
modifier|*
name|pdev
parameter_list|,
name|FILE
modifier|*
name|prn_stream
parameter_list|)
block|{
return|return
name|hpjet_print_page
argument_list|(
name|pdev
argument_list|,
name|prn_stream
argument_list|,
name|LJ2p
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Send the page to the printer.  For speed, compress each scan line, */
end_comment

begin_comment
comment|/* since computer-to-printer communication time is often a bottleneck. */
end_comment

begin_function
name|private
name|int
name|hpjet_print_page
parameter_list|(
name|gx_device_printer
modifier|*
name|pdev
parameter_list|,
name|FILE
modifier|*
name|prn_stream
parameter_list|,
name|int
name|compress
parameter_list|)
block|{
name|int
name|line_size
init|=
name|gdev_mem_bytes_per_scan_line
argument_list|(
operator|(
name|gx_device
operator|*
operator|)
name|pdev
argument_list|)
decl_stmt|;
name|int
name|line_size_words
init|=
operator|(
name|line_size
operator|+
name|W
operator|-
literal|1
operator|)
operator|/
name|W
decl_stmt|;
name|uint
name|storage_size_words
init|=
name|line_size_words
operator|*
literal|8
decl_stmt|;
comment|/* data, out_row, out_row_alt, prev_row */
name|word
modifier|*
name|storage
init|=
operator|(
name|ulong
operator|*
operator|)
name|gs_malloc
argument_list|(
name|storage_size_words
argument_list|,
name|W
argument_list|,
literal|"hpjet_print_page"
argument_list|)
decl_stmt|;
name|word
modifier|*
name|data_words
decl_stmt|,
modifier|*
name|out_row_words
decl_stmt|,
modifier|*
name|out_row_alt_words
decl_stmt|,
modifier|*
name|prev_row_words
decl_stmt|;
define|#
directive|define
name|data
value|((char *)data_words)
define|#
directive|define
name|out_row
value|((char *)out_row_words)
define|#
directive|define
name|out_row_alt
value|((char *)out_row_alt_words)
define|#
directive|define
name|prev_row
value|((char *)prev_row_words)
name|char
modifier|*
name|out_data
decl_stmt|;
name|int
name|x_dpi
init|=
name|pdev
operator|->
name|x_pixels_per_inch
decl_stmt|;
name|int
name|out_count
decl_stmt|;
name|int
name|compression
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|storage
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
comment|/* can't allocate working area */
name|data_words
operator|=
name|storage
expr_stmt|;
name|out_row_words
operator|=
name|data_words
operator|+
operator|(
name|line_size_words
operator|*
literal|2
operator|)
expr_stmt|;
name|out_row_alt_words
operator|=
name|out_row_words
operator|+
operator|(
name|line_size_words
operator|*
literal|2
operator|)
expr_stmt|;
name|prev_row_words
operator|=
name|out_row_alt_words
operator|+
operator|(
name|line_size_words
operator|*
literal|2
operator|)
expr_stmt|;
comment|/* Clear temp storage */
name|memset
argument_list|(
name|data
argument_list|,
literal|0
argument_list|,
name|storage_size_words
operator|*
name|W
argument_list|)
expr_stmt|;
comment|/* Initialize printer. */
name|fputs
argument_list|(
literal|"\033E"
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
comment|/* reset printer */
name|fputs
argument_list|(
literal|"\033*rB"
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
comment|/* end raster graphics */
name|fprintf
argument_list|(
name|prn_stream
argument_list|,
literal|"\033*t%dR"
argument_list|,
name|x_dpi
argument_list|)
expr_stmt|;
comment|/* set resolution */
name|fputs
argument_list|(
name|init_strings
index|[
name|compress
index|]
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
comment|/* Send each scan line in turn */
block|{
name|int
name|lnum
decl_stmt|;
name|int
name|num_blank_lines
init|=
literal|0
decl_stmt|;
name|word
name|rmask
init|=
operator|~
operator|(
name|word
operator|)
literal|0
operator|<<
operator|(
operator|-
name|pdev
operator|->
name|width
operator|&
operator|(
name|W
operator|*
literal|8
operator|-
literal|1
operator|)
operator|)
decl_stmt|;
comment|/* look for top margin white space... You would think that 		   the normal (raster) white space mechanism would work... it 		   doesn't... Sometimes PCL printers are brain-dead */
for|for
control|(
name|lnum
operator|=
literal|0
init|;
name|lnum
operator|<
name|pdev
operator|->
name|height
condition|;
name|lnum
operator|++
control|)
block|{
specifier|register
name|word
modifier|*
name|end_data
init|=
name|data_words
operator|+
name|line_size_words
decl_stmt|;
name|gdev_prn_copy_scan_lines
argument_list|(
name|pdev
argument_list|,
name|lnum
argument_list|,
operator|(
name|byte
operator|*
operator|)
name|data
argument_list|,
name|line_size
argument_list|)
expr_stmt|;
comment|/* Mask off 1-bits beyond the line width. */
name|end_data
index|[
operator|-
literal|1
index|]
operator|&=
name|rmask
expr_stmt|;
comment|/* Remove trailing 0s. */
while|while
condition|(
name|end_data
operator|>
name|data_words
operator|&&
name|end_data
index|[
operator|-
literal|1
index|]
operator|==
literal|0
condition|)
name|end_data
operator|--
expr_stmt|;
if|if
condition|(
name|end_data
operator|==
name|data_words
condition|)
comment|/* Blank line */
name|num_blank_lines
operator|++
expr_stmt|;
else|else
break|break;
block|}
comment|/* Skip blank lines if any */
if|if
condition|(
name|num_blank_lines
operator|>
literal|0
condition|)
block|{
comment|/* move down from current position */
name|fprintf
argument_list|(
name|prn_stream
argument_list|,
literal|"\033*p+%dY"
argument_list|,
name|num_blank_lines
argument_list|)
expr_stmt|;
name|num_blank_lines
operator|=
literal|0
expr_stmt|;
block|}
comment|/* transfer raster graphics */
for|for
control|(
init|;
name|lnum
operator|<
name|pdev
operator|->
name|height
condition|;
name|lnum
operator|++
control|)
block|{
specifier|register
name|word
modifier|*
name|end_data
init|=
name|data_words
operator|+
name|line_size_words
decl_stmt|;
name|gdev_prn_copy_scan_lines
argument_list|(
name|pdev
argument_list|,
name|lnum
argument_list|,
operator|(
name|byte
operator|*
operator|)
name|data
argument_list|,
name|line_size
argument_list|)
expr_stmt|;
comment|/* Mask off 1-bits beyond the line width. */
name|end_data
index|[
operator|-
literal|1
index|]
operator|&=
name|rmask
expr_stmt|;
comment|/* Remove trailing 0s. */
while|while
condition|(
name|end_data
operator|>
name|data_words
operator|&&
name|end_data
index|[
operator|-
literal|1
index|]
operator|==
literal|0
condition|)
name|end_data
operator|--
expr_stmt|;
if|if
condition|(
name|end_data
operator|==
name|data_words
condition|)
block|{
comment|/* Blank line */
name|num_blank_lines
operator|++
expr_stmt|;
continue|continue;
block|}
switch|switch
condition|(
name|compress
condition|)
block|{
case|case
name|LJ3
case|:
case|case
name|DJ500
case|:
block|{
comment|/* Compression modes 2 and 3 are both */
comment|/* available.  Try both and see which one */
comment|/* produces the least output data. */
name|int
name|count3
init|=
name|gdev_pcl_mode3compress
argument_list|(
name|line_size
argument_list|,
name|data
argument_list|,
name|prev_row
argument_list|,
name|out_row
argument_list|)
decl_stmt|;
name|int
name|count2
init|=
name|gdev_pcl_mode2compress
argument_list|(
name|data_words
argument_list|,
name|end_data
argument_list|,
name|out_row_alt
argument_list|)
decl_stmt|;
name|int
name|penalty3
init|=
operator|(
name|compression
operator|==
literal|3
condition|?
literal|0
else|:
literal|5
operator|)
decl_stmt|;
name|int
name|penalty2
init|=
operator|(
name|compression
operator|==
literal|2
condition|?
literal|0
else|:
literal|5
operator|)
decl_stmt|;
if|if
condition|(
name|count3
operator|+
name|penalty3
operator|<
name|count2
operator|+
name|penalty2
condition|)
block|{
if|if
condition|(
name|compression
operator|!=
literal|3
condition|)
name|fputs
argument_list|(
literal|"\033*b3M"
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
name|compression
operator|=
literal|3
expr_stmt|;
name|out_data
operator|=
name|out_row
expr_stmt|;
name|out_count
operator|=
name|count3
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|compression
operator|!=
literal|2
condition|)
name|fputs
argument_list|(
literal|"\033*b2M"
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
name|compression
operator|=
literal|2
expr_stmt|;
name|out_data
operator|=
name|out_row_alt
expr_stmt|;
name|out_count
operator|=
name|count2
expr_stmt|;
block|}
break|break;
block|}
case|case
name|DJ
case|:
case|case
name|LJ2p
case|:
name|out_data
operator|=
name|out_row
expr_stmt|;
name|out_count
operator|=
name|gdev_pcl_mode2compress
argument_list|(
name|data_words
argument_list|,
name|end_data
argument_list|,
name|out_row
argument_list|)
expr_stmt|;
break|break;
default|default:
name|out_data
operator|=
name|data
expr_stmt|;
name|out_count
operator|=
operator|(
name|char
operator|*
operator|)
name|end_data
operator|-
name|data
expr_stmt|;
block|}
comment|/* Skip blank lines if any */
if|if
condition|(
name|num_blank_lines
operator|>
literal|0
condition|)
block|{
comment|/* move down from current position */
name|fprintf
argument_list|(
name|prn_stream
argument_list|,
name|skip_patterns
index|[
name|compress
index|]
argument_list|,
name|num_blank_lines
argument_list|)
expr_stmt|;
name|num_blank_lines
operator|=
literal|0
expr_stmt|;
block|}
comment|/* transfer raster graphics */
name|fprintf
argument_list|(
name|prn_stream
argument_list|,
literal|"\033*b%dW"
argument_list|,
name|out_count
argument_list|)
expr_stmt|;
comment|/* send the row */
name|fwrite
argument_list|(
name|out_data
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|,
name|out_count
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* end raster graphics */
name|fputs
argument_list|(
literal|"\033*rB"
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
comment|/* eject page */
name|fputs
argument_list|(
literal|"\033&l0H"
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
comment|/* free temporary storage */
name|gs_free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|storage
argument_list|,
name|storage_size_words
argument_list|,
name|W
argument_list|,
literal|"hpjet_print_page"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * PCL has the notion of a LOGICAL and a PHYSICAL page.  The PHYSICAL page is  * the actual paper; the LOGICAL page is the printer specific imageable area.  * The strange part is that coordinates are all relative to the  * LOGICAL page.  This means that all PCL code is inherently device dependent.  * Luckily, in PostScript land, transformation matrices conquer all.  */
end_comment

begin_function
name|private
name|void
name|hp_get_initial_matrix
parameter_list|(
name|gx_device
modifier|*
name|dev
parameter_list|,
name|gs_matrix
modifier|*
name|pmat
parameter_list|)
block|{
name|pmat
operator|->
name|xx
operator|=
name|dev
operator|->
name|x_pixels_per_inch
operator|/
literal|72.0
expr_stmt|;
name|pmat
operator|->
name|xy
operator|=
literal|0
expr_stmt|;
name|pmat
operator|->
name|yx
operator|=
literal|0
expr_stmt|;
name|pmat
operator|->
name|yy
operator|=
name|dev
operator|->
name|y_pixels_per_inch
operator|/
operator|-
literal|72.0
expr_stmt|;
name|pmat
operator|->
name|tx
operator|=
operator|-
operator|(
name|dev
operator|->
name|l_margin
operator|*
name|dev
operator|->
name|x_pixels_per_inch
operator|)
expr_stmt|;
name|pmat
operator|->
name|ty
operator|=
name|dev
operator|->
name|height
operator|-
operator|(
name|dev
operator|->
name|t_margin
operator|*
name|dev
operator|->
name|y_pixels_per_inch
operator|)
expr_stmt|;
block|}
end_function

end_unit

