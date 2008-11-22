begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for variables relating to reading the source file.    Used by parsers, lexical analyzers, and error message routines.    Copyright (C) 1993, 1997, 1998, 2000, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_INPUT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_INPUT_H
end_define

begin_comment
comment|/* The data structure used to record a location in a translation unit.  */
end_comment

begin_comment
comment|/* Long-term, we want to get rid of this and typedef fileline location_t.  */
end_comment

begin_decl_stmt
name|struct
name|location_s
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The name of the source file involved.  */
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
comment|/* The line-location in the source file.  */
name|int
name|line
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|location_s
name|location_t
typedef|;
end_typedef

begin_struct
struct|struct
name|file_stack
block|{
name|struct
name|file_stack
modifier|*
name|next
decl_stmt|;
name|location_t
name|location
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Top-level source file.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|main_input_filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|location_t
name|input_location
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|input_line
value|(input_location.line)
end_define

begin_define
define|#
directive|define
name|input_filename
value|(input_location.file)
end_define

begin_comment
comment|/* Stack of currently pending input files.    The line member is not accurate for the innermost file on the stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|file_stack
modifier|*
name|input_file_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack of EXPR_WITH_FILE_LOCATION nested expressions.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|file_stack
modifier|*
name|expr_wfl_stack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Incremented on each change to input_file_stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|input_file_stack_tick
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|push_srcloc
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pop_srcloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

