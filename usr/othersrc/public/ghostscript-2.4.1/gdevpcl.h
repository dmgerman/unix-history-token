begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gdevpcl.h */
end_comment

begin_comment
comment|/* Interface to PCL utilities for Ghostscript printer drivers */
end_comment

begin_comment
comment|/* Requires gdevprn.h */
end_comment

begin_comment
comment|/* Color mapping procedures for 3-bit-per-pixel RGB printers */
end_comment

begin_extern
extern|extern dev_proc_map_rgb_color(gdev_pcl_3bit_map_rgb_color
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern dev_proc_map_color_rgb(gdev_pcl_3bit_map_color_rgb
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Row compression routines */
end_comment

begin_typedef
typedef|typedef
name|ulong
name|word
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|gdev_pcl_mode2compress
argument_list|(
name|P3
argument_list|(
specifier|const
name|word
operator|*
name|row
argument_list|,
specifier|const
name|word
operator|*
name|end_row
argument_list|,
name|char
operator|*
name|compressed
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gdev_pcl_mode3compress
argument_list|(
name|P4
argument_list|(
argument|int bytecount
argument_list|,
argument|const char *current
argument_list|,
argument|char *previous
argument_list|,
argument|char *compressed
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

