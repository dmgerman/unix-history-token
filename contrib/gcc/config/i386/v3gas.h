begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running system V, using gas.    Copyright (C) 1992, 1995 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<i386/gas.h>
end_include

begin_comment
comment|/* Add stuff that normally comes from i386v.h */
end_comment

begin_comment
comment|/* longjmp may fail to restore the registers if called from the same    function that called setjmp.  To compensate, the compiler avoids    putting variables in registers in functions that use both setjmp    and longjmp.  */
end_comment

begin_define
define|#
directive|define
name|NON_SAVING_SETJMP
define|\
value|(current_function_calls_setjmp&& current_function_calls_longjmp)
end_define

begin_comment
comment|/* longjmp may fail to restore the stack pointer if the saved frame    pointer is the same as the caller's frame pointer.  Requiring a frame    pointer in any function that calls setjmp or longjmp avoids this    problem, unless setjmp and longjmp are called from the same function.    Since a frame pointer will be required in such a function, it is OK    that the stack pointer is not restored.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_POINTER_REQUIRED
end_undef

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
define|\
value|(current_function_calls_setjmp || current_function_calls_longjmp)
end_define

begin_comment
comment|/* Modify ASM_OUTPUT_LOCAL slightly to test -msvr3-shlib, adapted to gas  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|do {							\     int align = exact_log2 (ROUNDED);			\     if (align> 2) align = 2;				\     if (TARGET_SVR3_SHLIB)				\       {							\ 	data_section ();				\ 	ASM_OUTPUT_ALIGN ((FILE), align == -1 ? 2 : align); \ 	ASM_OUTPUT_LABEL ((FILE), (NAME));		\ 	fprintf ((FILE), "\t.set .,.+%u\n", (ROUNDED));	\       }							\     else						\       {							\ 	fputs (".lcomm ", (FILE));			\ 	assemble_name ((FILE), (NAME));			\ 	fprintf ((FILE), ",%u\n", (ROUNDED));		\       }							\   } while (0)
end_define

begin_comment
comment|/* Add stuff that normally comes from i386v.h via svr3.h */
end_comment

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.  These    definitions should work for most SVR3 systems.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"long int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

end_unit

