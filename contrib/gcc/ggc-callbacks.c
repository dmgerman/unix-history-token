begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Empty GC callbacks to be used by languages that don't support GC.    Copyright (C) 1999, 2000 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"tm_p.h"
end_include

begin_include
include|#
directive|include
file|"ggc.h"
end_include

begin_function
name|void
name|ATTRIBUTE_NORETURN
name|lang_mark_tree
parameter_list|(
name|t
parameter_list|)
name|union
name|tree_node
modifier|*
name|t
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
comment|/* If this function is called, we are doing GC.  But, this file is      only included in compilers for languages that don't support GC.  */
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

