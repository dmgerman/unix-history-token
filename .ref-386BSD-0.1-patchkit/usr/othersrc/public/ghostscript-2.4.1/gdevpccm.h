begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gdevpccm.h */
end_comment

begin_comment
comment|/* Interface to PC color mapping utilities for Ghostscript */
end_comment

begin_comment
comment|/* Requires gxdevice.h */
end_comment

begin_comment
comment|/* Color mapping routines for EGA/VGA-style color. */
end_comment

begin_extern
extern|extern dev_proc_map_rgb_color(pc_4bit_map_rgb_color
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern dev_proc_map_color_rgb(pc_4bit_map_color_rgb
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Color mapping routines for 8-bit color (with a fixed palette). */
end_comment

begin_extern
extern|extern dev_proc_map_rgb_color(pc_8bit_map_rgb_color
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern dev_proc_map_color_rgb(pc_8bit_map_color_rgb
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Write the palette on a file. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pc_write_palette
argument_list|(
name|P3
argument_list|(
name|gx_device
operator|*
argument_list|,
name|uint
argument_list|,
name|FILE
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

