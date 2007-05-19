begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* General-purpose hooks.    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_comment
comment|/* This file contains generic hooks that can be used as defaults for    target or language-dependent hook initializers.  */
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
file|"hooks.h"
end_include

begin_comment
comment|/* Generic hook that does absolutely zappo.  */
end_comment

begin_function
name|void
name|hook_void_void
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* Generic hook that takes no arguments and returns false.  */
end_comment

begin_function
name|bool
name|hook_bool_void_false
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes no arguments and returns true.  */
end_comment

begin_function
name|bool
name|hook_bool_void_true
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes no arguments and returns NO_REGS.  */
end_comment

begin_function
name|int
name|hook_int_void_no_regs
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|NO_REGS
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes (bool) and returns false.  */
end_comment

begin_function
name|bool
name|hook_bool_bool_false
parameter_list|(
name|bool
name|a
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes (enum machine_mode) and returns false.  */
end_comment

begin_function
name|bool
name|hook_bool_mode_false
parameter_list|(
name|enum
name|machine_mode
name|mode
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes (enum machine_mode, rtx) and returns false.  */
end_comment

begin_function
name|bool
name|hook_bool_mode_rtx_false
parameter_list|(
name|enum
name|machine_mode
name|mode
name|ATTRIBUTE_UNUSED
parameter_list|,
name|rtx
name|value
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes (enum machine_mode, rtx) and returns true.  */
end_comment

begin_function
name|bool
name|hook_bool_mode_rtx_true
parameter_list|(
name|enum
name|machine_mode
name|mode
name|ATTRIBUTE_UNUSED
parameter_list|,
name|rtx
name|value
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes (FILE *, const char *) and does nothing.  */
end_comment

begin_function
name|void
name|hook_void_FILEptr_constcharptr
parameter_list|(
name|FILE
modifier|*
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
specifier|const
name|char
modifier|*
name|b
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* Used for the TARGET_ASM_CAN_OUTPUT_MI_THUNK hook.  */
end_comment

begin_function
name|bool
name|hook_bool_tree_hwi_hwi_tree_false
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|HOST_WIDE_INT
name|b
name|ATTRIBUTE_UNUSED
parameter_list|,
name|HOST_WIDE_INT
name|c
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|d
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|hook_bool_tree_hwi_hwi_tree_true
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|HOST_WIDE_INT
name|b
name|ATTRIBUTE_UNUSED
parameter_list|,
name|HOST_WIDE_INT
name|c
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|d
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_function
name|bool
name|hook_bool_constcharptr_size_t_false
parameter_list|(
specifier|const
name|char
modifier|*
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|size_t
name|b
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|hook_bool_size_t_constcharptr_int_true
parameter_list|(
name|size_t
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
specifier|const
name|char
modifier|*
name|b
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|c
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_function
name|bool
name|default_can_output_mi_thunk_no_vcall
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|HOST_WIDE_INT
name|b
name|ATTRIBUTE_UNUSED
parameter_list|,
name|HOST_WIDE_INT
name|c
parameter_list|,
name|tree
name|d
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|c
operator|==
literal|0
return|;
block|}
end_function

begin_function
name|int
name|hook_int_tree_0
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ??? Used for comp_type_attributes, which ought to return bool.  */
end_comment

begin_function
name|int
name|hook_int_tree_tree_1
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|b
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|hook_int_rtx_0
parameter_list|(
name|rtx
name|a
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|hook_int_size_t_constcharptr_int_0
parameter_list|(
name|size_t
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
specifier|const
name|char
modifier|*
name|b
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|c
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|hook_uint_uint_constcharptrptr_0
parameter_list|(
name|unsigned
name|int
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|b
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|hook_void_tree
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|hook_void_constcharptr
parameter_list|(
specifier|const
name|char
modifier|*
name|a
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|hook_void_tree_treeptr
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
modifier|*
name|b
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{ }
end_function

begin_function
name|bool
name|hook_bool_tree_false
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|hook_bool_tree_true
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_function
name|bool
name|hook_bool_tree_tree_false
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|b
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|hook_bool_tree_bool_false
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|bool
name|b
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|hook_bool_rtx_false
parameter_list|(
name|rtx
name|a
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|hook_bool_uintp_uintp_false
parameter_list|(
name|unsigned
name|int
modifier|*
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|unsigned
name|int
modifier|*
name|b
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|hook_bool_rtx_int_int_intp_false
parameter_list|(
name|rtx
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|b
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|c
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
modifier|*
name|d
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes an rtx and returns it.  */
end_comment

begin_function
name|rtx
name|hook_rtx_rtx_identity
parameter_list|(
name|rtx
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes an rtx and returns NULL_RTX.  */
end_comment

begin_function
name|rtx
name|hook_rtx_rtx_null
parameter_list|(
name|rtx
name|x
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes a tree and an int and returns NULL_RTX.  */
end_comment

begin_function
name|rtx
name|hook_rtx_tree_int_null
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|b
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes three trees and returns the last one as is.  */
end_comment

begin_function
name|tree
name|hook_tree_tree_tree_tree_3rd_identity
parameter_list|(
name|tree
name|a
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|b
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|c
parameter_list|)
block|{
return|return
name|c
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes a tree and returns a NULL string.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|hook_constcharptr_tree_null
parameter_list|(
name|tree
name|t
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|tree
name|hook_tree_tree_tree_bool_null
parameter_list|(
name|tree
name|t0
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|t1
name|ATTRIBUTE_UNUSED
parameter_list|,
name|bool
name|ignore
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|tree
name|hook_tree_tree_tree_null
parameter_list|(
name|tree
name|t0
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|t1
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes a rtx and returns a NULL string.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|hook_constcharptr_rtx_null
parameter_list|(
name|rtx
name|r
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|hook_constcharptr_tree_tree_null
parameter_list|(
name|tree
name|t0
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|t1
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|hook_constcharptr_int_tree_null
parameter_list|(
name|int
name|i
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|t0
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|hook_constcharptr_int_tree_tree_null
parameter_list|(
name|int
name|i
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|t0
name|ATTRIBUTE_UNUSED
parameter_list|,
name|tree
name|t1
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
end_function

end_unit

