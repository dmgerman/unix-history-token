begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for value printing routines for GDB, the GNU debugger.    Copyright 1986, 1988, 1989, 1991, 1992, 1993, 1994              Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|prettyprint_arrays
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls pretty printing of arrays.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|prettyprint_structs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls pretty printing of structures */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|prettyprint_arrays
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls pretty printing of arrays.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vtblprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls printing of vtbl's */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unionprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls printing of nested unions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|addressprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls pretty printing of addresses.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|objectprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Controls looking up an object's derived type 				   using what we find in its vtables.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|print_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max # of chars for strings/vectors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|output_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stop_print_at_null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stop printing at null char? */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|val_print_array_elements
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|CORE_ADDR
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|val_prettyprint
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|val_print_type_code_int
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|GDB_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_binary_chars
name|PARAMS
argument_list|(
operator|(
name|GDB_FILE
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_octal_chars
name|PARAMS
argument_list|(
operator|(
name|GDB_FILE
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_decimal_chars
name|PARAMS
argument_list|(
operator|(
name|GDB_FILE
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

