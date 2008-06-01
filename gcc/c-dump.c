begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Tree-dumping functionality for C-family languages.    Copyright (C) 2002, 2004, 2005 Free Software Foundation, Inc.    Written by Mark Mitchell<mark@codesourcery.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"c-tree.h"
end_include

begin_include
include|#
directive|include
file|"tree-dump.h"
end_include

begin_comment
comment|/* Dump information common to statements from STMT.  */
end_comment

begin_function
name|void
name|dump_stmt
parameter_list|(
name|dump_info_p
name|di
parameter_list|,
name|tree
name|t
parameter_list|)
block|{
if|if
condition|(
name|EXPR_HAS_LOCATION
argument_list|(
name|t
argument_list|)
condition|)
name|dump_int
argument_list|(
name|di
argument_list|,
literal|"line"
argument_list|,
name|EXPR_LINENO
argument_list|(
name|t
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Dump any C-specific tree codes and attributes of common codes.  */
end_comment

begin_function
name|bool
name|c_dump_tree
parameter_list|(
name|void
modifier|*
name|dump_info
parameter_list|,
name|tree
name|t
parameter_list|)
block|{
name|enum
name|tree_code
name|code
decl_stmt|;
name|dump_info_p
name|di
init|=
operator|(
name|dump_info_p
operator|)
name|dump_info
decl_stmt|;
comment|/* Figure out what kind of node this is.  */
name|code
operator|=
name|TREE_CODE
argument_list|(
name|t
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|FIELD_DECL
case|:
if|if
condition|(
name|DECL_C_BIT_FIELD
argument_list|(
name|t
argument_list|)
condition|)
name|dump_string
argument_list|(
name|di
argument_list|,
literal|"bitfield"
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|false
return|;
block|}
end_function

end_unit

