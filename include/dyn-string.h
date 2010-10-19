begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* An abstract string datatype.    Copyright (C) 1998, 1999, 2000, 2002, 2004 Free Software Foundation, Inc.    Contributed by Mark Mitchell (mark@markmitchell.com).  This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dyn_string
block|{
name|int
name|allocated
decl_stmt|;
comment|/* The amount of space allocated for the string.  */
name|int
name|length
decl_stmt|;
comment|/* The actual length of the string.  */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* The string itself, NUL-terminated.  */
block|}
typedef|*
name|dyn_string_t
typedef|;
end_typedef

begin_comment
comment|/* The length STR, in bytes, not including the terminating NUL.  */
end_comment

begin_define
define|#
directive|define
name|dyn_string_length
parameter_list|(
name|STR
parameter_list|)
define|\
value|((STR)->length)
end_define

begin_comment
comment|/* The NTBS in which the contents of STR are stored.  */
end_comment

begin_define
define|#
directive|define
name|dyn_string_buf
parameter_list|(
name|STR
parameter_list|)
define|\
value|((STR)->s)
end_define

begin_comment
comment|/* Compare DS1 to DS2 with strcmp.  */
end_comment

begin_define
define|#
directive|define
name|dyn_string_compare
parameter_list|(
name|DS1
parameter_list|,
name|DS2
parameter_list|)
define|\
value|(strcmp ((DS1)->s, (DS2)->s))
end_define

begin_function_decl
specifier|extern
name|int
name|dyn_string_init
parameter_list|(
name|struct
name|dyn_string
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|dyn_string_t
name|dyn_string_new
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dyn_string_delete
parameter_list|(
name|dyn_string_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dyn_string_release
parameter_list|(
name|dyn_string_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|dyn_string_t
name|dyn_string_resize
parameter_list|(
name|dyn_string_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dyn_string_clear
parameter_list|(
name|dyn_string_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_copy
parameter_list|(
name|dyn_string_t
parameter_list|,
name|dyn_string_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_copy_cstr
parameter_list|(
name|dyn_string_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_prepend
parameter_list|(
name|dyn_string_t
parameter_list|,
name|dyn_string_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_prepend_cstr
parameter_list|(
name|dyn_string_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_insert
parameter_list|(
name|dyn_string_t
parameter_list|,
name|int
parameter_list|,
name|dyn_string_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_insert_cstr
parameter_list|(
name|dyn_string_t
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_insert_char
parameter_list|(
name|dyn_string_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_append
parameter_list|(
name|dyn_string_t
parameter_list|,
name|dyn_string_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_append_cstr
parameter_list|(
name|dyn_string_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_append_char
parameter_list|(
name|dyn_string_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_substring
parameter_list|(
name|dyn_string_t
parameter_list|,
name|dyn_string_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dyn_string_eq
parameter_list|(
name|dyn_string_t
parameter_list|,
name|dyn_string_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

