begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running system V.    Copyright (C) 1988, 1996, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/i386.h"
end_include

begin_comment
comment|/* Use default settings for system V.3.  */
end_comment

begin_include
include|#
directive|include
file|"svr3.h"
end_include

begin_comment
comment|/* Use the ATT assembler syntax.    This overrides at least one macro (USER_LABEL_PREFIX) from svr3.h.  */
end_comment

begin_include
include|#
directive|include
file|"i386/att.h"
end_include

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt1.o%s}%{!pg:%{posix:%{p:mcrtp1.o%s}%{!p:crtp1.o%s}}%{!posix:%{p:mcrt1.o%s}%{!p:crt1.o%s}}} crtbegin.o%s\    %{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp}"
end_define

begin_comment
comment|/* ??? There is a suggestion that -lg is needed here.    Does anyone know whether this is right?  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{posix:-lcposix} %{shlib:-lc_s} -lc crtend.o%s crtn.o%s"
end_define

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Asystem=svr3"
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %{posix:-D_POSIX_SOURCE}"
end_define

begin_comment
comment|/* Writing `int' for a bitfield forces int alignment for the structure.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* Don't write a `.optim' pseudo; this assembler doesn't handle them.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START_1
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START_1
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_comment
comment|/* We want to be able to get DBX debugging information via -gstabs.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|SDB_DEBUG
end_define

begin_escape
end_escape

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
comment|/* Modify ASM_OUTPUT_LOCAL slightly to test -msvr3-shlib.  */
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
value|do {							\     int align = exact_log2 (ROUNDED);			\     if (align> 2) align = 2;				\     if (TARGET_SVR3_SHLIB)				\       data_section ();					\     else						\       bss_section ();					\     ASM_OUTPUT_ALIGN ((FILE), align == -1 ? 2 : align);	\     ASM_OUTPUT_LABEL ((FILE), (NAME));			\     fprintf ((FILE), "\t.set .,.+%u\n", (ROUNDED));	\   } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a few machine-specific details of the implementation of    constructors.     The __CTORS_LIST__ goes in the .init section.  Define CTOR_LIST_BEGIN    and CTOR_LIST_END to contribute to the .init section an instruction to    push a word containing 0 (or some equivalent of that).  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section .init,\"x\""
end_define

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

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|ix86_svr3_asm_out_constructor
end_define

end_unit

