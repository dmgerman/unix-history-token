begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gzdevice.h */
end_comment

begin_comment
comment|/* Private structures for describing devices for GhostScript */
end_comment

begin_comment
comment|/* requires gsmatrix.h */
end_comment

begin_include
include|#
directive|include
file|"gxdevice.h"
end_include

begin_comment
comment|/* Structure for a device in the graphics state */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|device_s
block|{
name|gx_device
modifier|*
name|info
decl_stmt|;
comment|/* points to actual device info */
name|int
name|is_band_device
decl_stmt|;
comment|/* if true, must render in pieces */
name|gx_color_index
name|white
decl_stmt|,
name|black
decl_stmt|;
comment|/* device color codes */
block|}
name|device
typedef|;
end_typedef

end_unit

