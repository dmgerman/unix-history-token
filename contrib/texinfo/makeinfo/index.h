begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* index.h -- declarations for index.c.    $Id: index.h,v 1.4 1999/04/19 18:12:17 karl Exp $     Copyright (C) 1998, 99 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INDEX_H
end_ifndef

begin_define
define|#
directive|define
name|INDEX_H
end_define

begin_include
include|#
directive|include
file|"makeinfo.h"
end_include

begin_include
include|#
directive|include
file|"cmds.h"
end_include

begin_comment
comment|/* User commands are only new indices.  (Macros are handled separately.)  */
end_comment

begin_decl_stmt
specifier|extern
name|COMMAND
modifier|*
modifier|*
name|user_command_array
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|user_command_array_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize all indices.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_indices
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Function to compare index entries for sorting.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|index_compare_fn
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !INDEX_H */
end_comment

end_unit

