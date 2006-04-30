begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Do-nothing debug hooks for GCC.    Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"debug.h"
end_include

begin_comment
comment|/* The do-nothing debug hooks.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|gcc_debug_hooks
name|do_nothing_debug_hooks
init|=
block|{
name|debug_nothing_charstar
block|,
name|debug_nothing_charstar
block|,
name|debug_nothing_int_charstar
block|,
name|debug_nothing_int_charstar
block|,
name|debug_nothing_int_charstar
block|,
name|debug_nothing_int
block|,
name|debug_nothing_int_int
block|,
comment|/* begin_block */
name|debug_nothing_int_int
block|,
comment|/* end_block */
name|debug_true_tree
block|,
comment|/* ignore_block */
name|debug_nothing_int_charstar
block|,
comment|/* source_line */
name|debug_nothing_int_charstar
block|,
comment|/* begin_prologue */
name|debug_nothing_int_charstar
block|,
comment|/* end_prologue */
name|debug_nothing_int_charstar
block|,
comment|/* end_epilogue */
name|debug_nothing_tree
block|,
comment|/* begin_function */
name|debug_nothing_int
block|,
comment|/* end_function */
name|debug_nothing_tree
block|,
comment|/* function_decl */
name|debug_nothing_tree
block|,
comment|/* global_decl */
name|debug_nothing_tree
block|,
comment|/* deferred_inline_function */
name|debug_nothing_tree
block|,
comment|/* outlining_inline_function */
name|debug_nothing_rtx
block|,
comment|/* label */
name|debug_nothing_int
comment|/* handle_pch */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This file contains implementations of each debug hook that do    nothing.  */
end_comment

begin_function
name|void
name|debug_nothing_void
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|debug_nothing_tree
parameter_list|(
name|tree
name|decl
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_function
name|bool
name|debug_true_tree
parameter_list|(
name|tree
name|block
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_function
name|void
name|debug_nothing_rtx
parameter_list|(
name|rtx
name|insn
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|debug_nothing_charstar
parameter_list|(
specifier|const
name|char
modifier|*
name|main_filename
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|debug_nothing_int_charstar
parameter_list|(
name|unsigned
name|int
name|line
name|ATTRIBUTE_UNUSED
parameter_list|,
specifier|const
name|char
modifier|*
name|text
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|debug_nothing_int
parameter_list|(
name|unsigned
name|int
name|line
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|debug_nothing_int_int
parameter_list|(
name|unsigned
name|int
name|line
name|ATTRIBUTE_UNUSED
parameter_list|,
name|unsigned
name|int
name|n
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

end_unit

