begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* General-purpose hooks.    Copyright (C) 2002 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.   In other words, you are welcome to use, share and improve this program.  You are forbidden to forbid anyone else to use, share and improve  what you give them.   Help stamp out software-hoarding!  */
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
file|"hooks.h"
end_include

begin_comment
comment|/* Generic hook that does absolutely zappo.  */
end_comment

begin_function
name|void
name|hook_void_void
parameter_list|()
block|{ }
end_function

begin_comment
comment|/* Generic hook that takes no arguments and returns false.  */
end_comment

begin_function
name|bool
name|hook_void_bool_false
parameter_list|()
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Generic hook that takes (tree) and returns false.  */
end_comment

begin_function
name|bool
name|hook_tree_bool_false
parameter_list|(
name|a
parameter_list|)
name|tree
name|a
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
return|return
name|false
return|;
block|}
end_function

end_unit

