begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gdevtrfx.c */
end_comment

begin_comment
comment|/* TruFax driver for Ghostscript. */
end_comment

begin_comment
comment|/******  ****** Note: this file requires encode_l.o as supplied by TruFax.  ******/
end_comment

begin_include
include|#
directive|include
file|"gdevprn.h"
end_include

begin_comment
comment|/* The device descriptor */
end_comment

begin_define
define|#
directive|define
name|X_DPI
value|204
end_define

begin_define
define|#
directive|define
name|Y_DPI
value|196
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

begin_function_decl
name|private
name|dev_proc_print_page
parameter_list|(
name|trufax_print_page
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|gx_device_printer
name|gs_trufax_device
init|=
name|prn_device
argument_list|(
name|prn_std_procs
argument_list|,
literal|"TruFax"
argument_list|,
literal|85
argument_list|,
comment|/* width_10ths, 8.5" */
literal|110
argument_list|,
comment|/* height_10ths, 11" */
name|X_DPI
argument_list|,
name|Y_DPI
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* margins */
literal|1
argument_list|,
name|trufax_print_page
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Internal routines ------ */
end_comment

begin_function
name|private
name|int
name|trufax_print_page
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
operator|+
literal|4
index|]
decl_stmt|;
name|int
name|lnum
decl_stmt|;
name|int
name|line_size
decl_stmt|;
name|char
name|out_data
index|[
literal|5
operator|*
literal|1734
index|]
decl_stmt|;
comment|/* Sized according to TruFax */
name|int
name|out_count
decl_stmt|;
comment|/* write TruFax header */
name|strcpy
argument_list|(
name|out_data
argument_list|,
literal|"COSIf2"
argument_list|)
expr_stmt|;
name|out_data
index|[
literal|6
index|]
operator|=
literal|1
expr_stmt|;
name|out_data
index|[
literal|7
index|]
operator|=
literal|0
expr_stmt|;
name|out_data
index|[
literal|8
index|]
operator|=
literal|1
expr_stmt|;
name|out_data
index|[
literal|9
index|]
operator|=
literal|0
expr_stmt|;
name|fwrite
argument_list|(
name|out_data
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|,
literal|10
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
name|line_size
operator|=
name|gdev_mem_bytes_per_scan_line
argument_list|(
operator|(
name|gx_device
operator|*
operator|)
name|pdev
argument_list|)
expr_stmt|;
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
comment|/* 1728 = Sized according to TruFax */
name|out_count
operator|=
name|encode_line
argument_list|(
literal|1728
argument_list|,
name|data
argument_list|,
name|out_data
argument_list|)
expr_stmt|;
name|putc
argument_list|(
name|out_count
operator|%
literal|256
argument_list|,
name|prn_stream
argument_list|)
expr_stmt|;
name|putc
argument_list|(
name|out_count
operator|/
literal|256
argument_list|,
name|prn_stream
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
return|return
literal|0
return|;
block|}
end_function

end_unit

