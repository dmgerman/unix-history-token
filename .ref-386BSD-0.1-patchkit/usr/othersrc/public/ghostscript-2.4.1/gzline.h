begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxline.h */
end_comment

begin_comment
comment|/* Private line parameters for GhostScript */
end_comment

begin_comment
comment|/* Requires gsstate.h */
end_comment

begin_comment
comment|/* Line parameter structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dash_params_s
block|{
name|float
modifier|*
name|pattern
decl_stmt|;
name|uint
name|pattern_size
decl_stmt|;
name|float
name|offset
decl_stmt|;
comment|/* The rest of the parameters are computed from the above */
name|int
name|init_ink_on
decl_stmt|;
comment|/* true if ink is initially on */
name|int
name|init_index
decl_stmt|;
comment|/* initial index in pattern */
name|float
name|init_dist_left
decl_stmt|;
block|}
name|dash_params
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|line_params_s
block|{
name|float
name|width
decl_stmt|;
comment|/* one-half line width */
name|gs_line_cap
name|cap
decl_stmt|;
name|gs_line_join
name|join
decl_stmt|;
name|float
name|miter_limit
decl_stmt|;
name|float
name|miter_check
decl_stmt|;
comment|/* computed from miter limit, */
comment|/* see gs_setmiterlimit and */
comment|/* gs_stroke */
name|dash_params
name|dash
decl_stmt|;
block|}
name|line_params
typedef|;
end_typedef

end_unit

