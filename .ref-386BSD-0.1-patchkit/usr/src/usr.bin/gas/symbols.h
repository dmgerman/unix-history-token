begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* symbols.h -    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|obstack
name|notes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* eg FixS live here. */
end_comment

begin_define
define|#
directive|define
name|symbol_table_lookup
parameter_list|(
name|name
parameter_list|)
value|((symbolS *)(symbol_find (name)))
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|local_bss_counter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Zeroed before a pass. */
end_comment

begin_comment
comment|/* Only used by .lcomm directive. */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|symbol_rootP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* all the symbol nodes */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|symbol_lastP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last struct symbol we made, or NULL */
end_comment

begin_decl_stmt
specifier|extern
name|symbolS
name|abs_symbol
decl_stmt|;
end_decl_stmt

begin_function_decl
name|symbolS
modifier|*
name|symbol_find
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|local_label_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|local_colon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|colon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symbol_table_insert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|symbolS
modifier|*
name|symbol_find_or_make
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* end: symbols.h */
end_comment

end_unit

