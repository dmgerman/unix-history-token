begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxop1.h */
end_comment

begin_comment
comment|/* Type 1 state shared between interpreter and compiled fonts. */
end_comment

begin_comment
comment|/* Define the shared Type 1 interpreter state. */
end_comment

begin_define
define|#
directive|define
name|max_coeff_bits
value|11
end_define

begin_comment
comment|/* max coefficient in char space */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_op1_state_s
block|{
name|struct
name|gx_path_s
modifier|*
name|ppath
decl_stmt|;
name|struct
name|gs_type1_state_s
modifier|*
name|pis
decl_stmt|;
name|fixed_coeff
name|fc
decl_stmt|;
name|fixed
name|ctx
decl_stmt|,
name|cty
decl_stmt|;
comment|/* character origin (device space) */
name|fixed
name|px
decl_stmt|,
name|py
decl_stmt|;
comment|/* current point (char space) */
block|}
name|gs_op1_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|gs_op1_state
name|_ss
modifier|*
name|is_ptr
typedef|;
end_typedef

end_unit

