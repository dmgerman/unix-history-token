begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gdevlbp8.c */
end_comment

begin_comment
comment|/* Canon LBP-8II driver for Ghostscript */
end_comment

begin_include
include|#
directive|include
file|"gdevprn.h"
end_include

begin_define
define|#
directive|define
name|X_DPI
value|300
end_define

begin_define
define|#
directive|define
name|Y_DPI
value|300
end_define

begin_define
define|#
directive|define
name|LINE_SIZE
value|((X_DPI * 85 / 10 + 7) / 8)
end_define

begin_comment
comment|/* bytes per line */
end_comment

begin_comment
comment|/* The device descriptors */
end_comment

begin_function_decl
name|private
name|dev_proc_print_page
parameter_list|(
name|lbp8_print_page
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|gx_device_printer
name|gs_lbp8_device
init|=
name|prn_device
argument_list|(
name|prn_std_procs
argument_list|,
literal|"lbp8"
argument_list|,
literal|83
argument_list|,
comment|/* width_10ths, 8.3" */
literal|117
argument_list|,
comment|/* height_10ths, 11.7" */
name|X_DPI
argument_list|,
name|Y_DPI
argument_list|,
literal|0.16
argument_list|,
literal|0.20
argument_list|,
literal|0.32
argument_list|,
literal|0.20
argument_list|,
comment|/* margins */
literal|1
argument_list|,
name|lbp8_print_page
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Internal routines ------ */
end_comment

begin_define
define|#
directive|define
name|ESC
value|0x1b
end_define

begin_define
define|#
directive|define
name|CSI
value|0233
end_define

begin_decl_stmt
specifier|static
name|char
name|can_inits
index|[]
init|=
block|{
name|ESC
block|,
literal|';'
block|,
name|ESC
block|,
literal|'c'
block|,
name|ESC
block|,
literal|';'
block|,
comment|/* reset, ISO */
name|CSI
block|,
literal|'2'
block|,
literal|'&'
block|,
literal|'z'
block|,
comment|/* fullpaint mode */
name|CSI
block|,
literal|'1'
block|,
literal|'4'
block|,
literal|'p'
block|,
comment|/* select page type (A4) */
name|CSI
block|,
literal|'1'
block|,
literal|'1'
block|,
literal|'h'
block|,
comment|/* set mode */
name|CSI
block|,
literal|'7'
block|,
literal|' '
block|,
literal|'I'
block|,
comment|/* select unit size (300dpi)*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send the page to the printer.  */
end_comment

begin_function
name|private
name|int
name|lbp8_print_page
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
name|char
name|data
index|[
name|LINE_SIZE
operator|*
literal|2
index|]
decl_stmt|;
name|char
modifier|*
name|out_data
decl_stmt|;
name|int
name|out_count
decl_stmt|;
define|#
directive|define
name|CSI_print
parameter_list|(
name|str
parameter_list|)
value|fprintf(prn_stream, str, CSI)
define|#
directive|define
name|CSI_print_1
parameter_list|(
name|str
parameter_list|,
name|arg
parameter_list|)
value|fprintf(prn_stream, str, CSI, arg)
comment|/* initialize */
name|fwrite
argument_list|(
name|can_inits
argument_list|,
sizeof|sizeof
argument_list|(
name|can_inits
argument_list|)
argument_list|,
literal|1
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
name|byte
name|rmask
init|=
call|(
name|byte
call|)
argument_list|(
literal|0xff
operator|<<
operator|(
operator|-
name|pdev
operator|->
name|width
operator|&
literal|7
operator|)
argument_list|)
decl_stmt|;
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
name|char
modifier|*
name|end_data
init|=
name|data
operator|+
name|LINE_SIZE
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
name|data
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
operator|!=
name|data
condition|)
block|{
name|int
name|num_cols
init|=
literal|0
decl_stmt|;
name|out_data
operator|=
name|data
expr_stmt|;
while|while
condition|(
name|out_data
operator|<
name|end_data
operator|&&
operator|*
name|out_data
operator|==
literal|0
condition|)
block|{
name|num_cols
operator|+=
literal|8
expr_stmt|;
name|out_data
operator|++
expr_stmt|;
block|}
name|out_count
operator|=
name|end_data
operator|-
name|out_data
expr_stmt|;
comment|/* move down */
name|CSI_print_1
argument_list|(
literal|"%c%dd"
argument_list|,
name|lnum
argument_list|)
expr_stmt|;
comment|/* move across */
name|CSI_print_1
argument_list|(
literal|"%c%d`"
argument_list|,
name|num_cols
argument_list|)
expr_stmt|;
comment|/* transfer raster graphics */
name|fprintf
argument_list|(
name|prn_stream
argument_list|,
literal|"%c%d;%d;300;.r"
argument_list|,
name|CSI
argument_list|,
name|out_count
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
block|}
comment|/* eject page */
name|fprintf
argument_list|(
name|prn_stream
argument_list|,
literal|"%c="
argument_list|,
name|ESC
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

