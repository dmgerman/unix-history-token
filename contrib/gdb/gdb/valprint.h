begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for value printing routines for GDB, the GNU debugger.    Copyright 1986, 1988, 1989, 1991-1994, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALPRINT_H
end_ifndef

begin_define
define|#
directive|define
name|VALPRINT_H
end_define

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

begin_comment
comment|/* Flag to low-level print routines that this value is being printed    in an epoch window.  We'd like to pass this as a parameter, but    every routine would need to take it.  Perhaps we can encapsulate    this in the I/O stream once we have GNU stdio. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inspect_it
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print repeat counts if there are more than this many repetitions of an    element in an array.  Referenced by the low level language dependent    print routines. */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|repeat_count_threshold
decl_stmt|;
end_decl_stmt

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

begin_function_decl
specifier|extern
name|void
name|val_print_array_elements
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|val_prettyprint
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|val_print_type_code_int
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_binary_chars
parameter_list|(
name|struct
name|ui_file
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_octal_chars
parameter_list|(
name|struct
name|ui_file
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_decimal_chars
parameter_list|(
name|struct
name|ui_file
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_hex_chars
parameter_list|(
name|struct
name|ui_file
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_char_chars
parameter_list|(
name|struct
name|ui_file
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

