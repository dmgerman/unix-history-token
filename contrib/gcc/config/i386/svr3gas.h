begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running system V, using gas.    Copyright (C) 1992, 1996, 2000, 2002 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (80386, ATT syntax)");
end_define

begin_comment
comment|/* Add stuff that normally comes from i386/sysv3.h */
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
name|SUBTARGET_FRAME_POINTER_REQUIRED
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_FRAME_POINTER_REQUIRED
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
comment|/* Add stuff that normally comes from i386/sysv3.h via svr3.h */
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

begin_escape
end_escape

begin_comment
comment|/* ??? This stuff is copied from config/svr3.h.  In the future,    this file should be rewritten to include config/svr3.h    and override what isn't right.  */
end_comment

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section\t.init"
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|"\t.section .fini,\"x\""
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|INIT_SECTION_ASM_OP
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|FINI_SECTION_ASM_OP
end_define

begin_comment
comment|/* CTOR_LIST_BEGIN and CTOR_LIST_END are machine-dependent    because they push on the stack.  */
end_comment

begin_comment
comment|/* This is copied from i386/sysv3.h.  */
end_comment

begin_define
define|#
directive|define
name|CTOR_LIST_BEGIN
define|\
value|asm (INIT_SECTION_ASM_OP);			\   asm ("pushl $0")
end_define

begin_define
define|#
directive|define
name|CTOR_LIST_END
value|CTOR_LIST_BEGIN
end_define

begin_comment
comment|/* Constructor list on stack is in reverse order.  Go to the end of the    list and go backwards to call constructors in the right order.  */
end_comment

begin_define
define|#
directive|define
name|DO_GLOBAL_CTORS_BODY
define|\
value|do {								\   func_ptr *p, *beg = alloca (0);				\   for (p = beg; *p; p++)					\     ;								\   while (p != beg)						\     (*--p) ();							\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_init, in_fini
end_define

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|INIT_SECTION_FUNCTION						\   FINI_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|INIT_SECTION_FUNCTION
define|\
value|void								\ init_section ()							\ {								\   if (in_section != in_init)					\     {								\       fprintf (asm_out_file, "%s\n", INIT_SECTION_ASM_OP);	\       in_section = in_init;					\     }								\ }
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_FUNCTION
define|\
value|void								\ fini_section ()							\ {								\   if (in_section != in_fini)					\     {								\       fprintf (asm_out_file, "%s\n", FINI_SECTION_ASM_OP);	\       in_section = in_fini;					\     }								\ }
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|ix86_svr3_asm_out_constructor
end_define

end_unit

