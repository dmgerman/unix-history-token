begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for variables relating to reading the source file.    Used by parsers, lexical analyzers, and error message routines.    Copyright (C) 1993, 1997, 1998, 2000 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Source file current line is coming from.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|input_filename
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* Line number in current source file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stream for reading from input file.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|finput
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|file_stack
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|file_stack
modifier|*
name|next
decl_stmt|;
name|int
name|line
decl_stmt|;
name|int
name|indent_level
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* Incremented on each change to input_file_stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|input_file_stack_tick
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_srcloc
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
name|int
name|line
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_srcloc
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

