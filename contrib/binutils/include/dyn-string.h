begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* An abstract string datatype.    Copyright (C) 1998, 1999, 2000 Free Software Foundation, Inc.    Contributed by Mark Mitchell (mark@markmitchell.com).  This file is part of GNU CC.     GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* dyn_string functions are used in the demangling implementation    included in the G++ runtime library.  To prevent collisions with    names in user programs, the functions that are used in the    demangler are given implementation-reserved names.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_define
define|#
directive|define
name|dyn_string_init
value|__cxa_dyn_string_init
end_define

begin_define
define|#
directive|define
name|dyn_string_new
value|__cxa_dyn_string_new
end_define

begin_define
define|#
directive|define
name|dyn_string_delete
value|__cxa_dyn_string_delete
end_define

begin_define
define|#
directive|define
name|dyn_string_release
value|__cxa_dyn_string_release
end_define

begin_define
define|#
directive|define
name|dyn_string_resize
value|__cxa_dyn_string_resize
end_define

begin_define
define|#
directive|define
name|dyn_string_clear
value|__cxa_dyn_string_clear
end_define

begin_define
define|#
directive|define
name|dyn_string_copy
value|__cxa_dyn_string_copy
end_define

begin_define
define|#
directive|define
name|dyn_string_copy_cstr
value|__cxa_dyn_string_copy_cstr
end_define

begin_define
define|#
directive|define
name|dyn_string_prepend
value|__cxa_dyn_string_prepend
end_define

begin_define
define|#
directive|define
name|dyn_string_prepend_cstr
value|__cxa_dyn_string_prepend_cstr
end_define

begin_define
define|#
directive|define
name|dyn_string_insert
value|__cxa_dyn_string_insert
end_define

begin_define
define|#
directive|define
name|dyn_string_insert_cstr
value|__cxa_dyn_string_insert_cstr
end_define

begin_define
define|#
directive|define
name|dyn_string_insert_char
value|__cxa_dyn_string_insert_char
end_define

begin_define
define|#
directive|define
name|dyn_string_append
value|__cxa_dyn_string_append
end_define

begin_define
define|#
directive|define
name|dyn_string_append_cstr
value|__cxa_dyn_string_append_cstr
end_define

begin_define
define|#
directive|define
name|dyn_string_append_char
value|__cxa_dyn_string_append_char
end_define

begin_define
define|#
directive|define
name|dyn_string_substring
value|__cxa_dyn_string_substring
end_define

begin_define
define|#
directive|define
name|dyn_string_eq
value|__cxa_dyn_string_eq
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IN_LIBGCC2 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_init
name|PARAMS
argument_list|(
operator|(
expr|struct
name|dyn_string
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dyn_string_t
name|dyn_string_new
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dyn_string_delete
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dyn_string_release
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dyn_string_t
name|dyn_string_resize
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dyn_string_clear
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_copy
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|dyn_string_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_copy_cstr
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_prepend
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|dyn_string_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_prepend_cstr
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_insert
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|int
operator|,
name|dyn_string_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_insert_cstr
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_insert_char
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_append
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|dyn_string_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_append_cstr
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_append_char
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_substring
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|dyn_string_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dyn_string_eq
name|PARAMS
argument_list|(
operator|(
name|dyn_string_t
operator|,
name|dyn_string_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

