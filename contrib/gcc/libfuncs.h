begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for code generation pass of GNU compiler.    Copyright (C) 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_LIBFUNCS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_LIBFUNCS_H
end_define

begin_comment
comment|/* Enumeration of indexes into libfunc_table.  */
end_comment

begin_enum
enum|enum
name|libfunc_index
block|{
name|LTI_abort
block|,
name|LTI_memcpy
block|,
name|LTI_memmove
block|,
name|LTI_bcopy
block|,
name|LTI_memcmp
block|,
name|LTI_bcmp
block|,
name|LTI_memset
block|,
name|LTI_bzero
block|,
name|LTI_setbits
block|,
name|LTI_unwind_resume
block|,
name|LTI_eh_personality
block|,
name|LTI_setjmp
block|,
name|LTI_longjmp
block|,
name|LTI_unwind_sjlj_register
block|,
name|LTI_unwind_sjlj_unregister
block|,
name|LTI_profile_function_entry
block|,
name|LTI_profile_function_exit
block|,
name|LTI_gcov_flush
block|,
name|LTI_gcov_init
block|,
name|LTI_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* SYMBOL_REF rtx's for the library functions that are called    implicitly and not via optabs.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|libfunc_table
index|[
name|LTI_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Accessor macros for libfunc_table.  */
end_comment

begin_define
define|#
directive|define
name|abort_libfunc
value|(libfunc_table[LTI_abort])
end_define

begin_define
define|#
directive|define
name|memcpy_libfunc
value|(libfunc_table[LTI_memcpy])
end_define

begin_define
define|#
directive|define
name|memmove_libfunc
value|(libfunc_table[LTI_memmove])
end_define

begin_define
define|#
directive|define
name|bcopy_libfunc
value|(libfunc_table[LTI_bcopy])
end_define

begin_define
define|#
directive|define
name|memcmp_libfunc
value|(libfunc_table[LTI_memcmp])
end_define

begin_define
define|#
directive|define
name|bcmp_libfunc
value|(libfunc_table[LTI_bcmp])
end_define

begin_define
define|#
directive|define
name|memset_libfunc
value|(libfunc_table[LTI_memset])
end_define

begin_define
define|#
directive|define
name|bzero_libfunc
value|(libfunc_table[LTI_bzero])
end_define

begin_define
define|#
directive|define
name|setbits_libfunc
value|(libfunc_table[LTI_setbits])
end_define

begin_define
define|#
directive|define
name|unwind_resume_libfunc
value|(libfunc_table[LTI_unwind_resume])
end_define

begin_define
define|#
directive|define
name|eh_personality_libfunc
value|(libfunc_table[LTI_eh_personality])
end_define

begin_define
define|#
directive|define
name|setjmp_libfunc
value|(libfunc_table[LTI_setjmp])
end_define

begin_define
define|#
directive|define
name|longjmp_libfunc
value|(libfunc_table[LTI_longjmp])
end_define

begin_define
define|#
directive|define
name|unwind_sjlj_register_libfunc
value|(libfunc_table[LTI_unwind_sjlj_register])
end_define

begin_define
define|#
directive|define
name|unwind_sjlj_unregister_libfunc
define|\
value|(libfunc_table[LTI_unwind_sjlj_unregister])
end_define

begin_define
define|#
directive|define
name|profile_function_entry_libfunc
value|(libfunc_table[LTI_profile_function_entry])
end_define

begin_define
define|#
directive|define
name|profile_function_exit_libfunc
value|(libfunc_table[LTI_profile_function_exit])
end_define

begin_define
define|#
directive|define
name|gcov_flush_libfunc
value|(libfunc_table[LTI_gcov_flush])
end_define

begin_define
define|#
directive|define
name|gcov_init_libfunc
value|(libfunc_table[LTI_gcov_init])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_LIBFUNCS_H */
end_comment

end_unit

