begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gdevbit.c */
end_comment

begin_comment
comment|/* Fake bitmapped device to estimate rendering time. */
end_comment

begin_include
include|#
directive|include
file|"gdevprn.h"
end_include

begin_comment
comment|/* Define the device parameters. */
end_comment

begin_define
define|#
directive|define
name|X_DPI
value|400
end_define

begin_define
define|#
directive|define
name|Y_DPI
value|400
end_define

begin_define
define|#
directive|define
name|WIDTH_10THS
value|80
end_define

begin_comment
comment|/* 440 */
end_comment

begin_define
define|#
directive|define
name|HEIGHT_10THS
value|80
end_define

begin_comment
comment|/* 1080 */
end_comment

begin_comment
comment|/* The device descriptor */
end_comment

begin_function_decl
name|private
name|dev_proc_print_page
parameter_list|(
name|bit_print_page
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|gx_device_printer
name|gs_bit_device
init|=
name|prn_device
argument_list|(
name|prn_std_procs
argument_list|,
literal|"bit"
argument_list|,
name|WIDTH_10THS
argument_list|,
name|HEIGHT_10THS
argument_list|,
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
name|bit_print_page
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send the page to the printer. */
end_comment

begin_function
name|private
name|int
name|bit_print_page
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
comment|/* Just dump the bits on the file. */
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
name|lnum
decl_stmt|;
name|byte
modifier|*
name|in
init|=
operator|(
name|byte
operator|*
operator|)
name|gs_malloc
argument_list|(
name|line_size
argument_list|,
literal|1
argument_list|,
literal|"bit_print_page(in)"
argument_list|)
decl_stmt|;
if|if
condition|(
name|in
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
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
name|in
argument_list|,
name|line_size
argument_list|)
expr_stmt|;
comment|/******		fwrite(in, 1, line_size, prn_stream);  ******/
block|}
name|gs_free
argument_list|(
name|in
argument_list|,
name|line_size
argument_list|,
literal|1
argument_list|,
literal|"bit_print_page(in)"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

