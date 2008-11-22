begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Hooks for cfg representation specific functions.    Copyright (C) 2003 Free Software Foundation, Inc.    Contributed by Sebastian Pop<s.pop@laposte.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_decl_stmt
specifier|extern
name|struct
name|cfg_hooks
name|rtl_cfg_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cfg_hooks
name|cfg_layout_rtl_cfg_hooks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A pointer to one of the hooks containers.  */
end_comment

begin_decl_stmt
name|struct
name|cfg_hooks
modifier|*
name|cfg_hooks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialization of functions specific to the rtl IR.  */
end_comment

begin_function
name|void
name|rtl_register_cfg_hooks
parameter_list|(
name|void
parameter_list|)
block|{
name|cfg_hooks
operator|=
operator|&
name|rtl_cfg_hooks
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Initialization of functions specific to the rtl IR.  */
end_comment

begin_function
name|void
name|cfg_layout_rtl_register_cfg_hooks
parameter_list|(
name|void
parameter_list|)
block|{
name|cfg_hooks
operator|=
operator|&
name|cfg_layout_rtl_cfg_hooks
expr_stmt|;
block|}
end_function

end_unit

