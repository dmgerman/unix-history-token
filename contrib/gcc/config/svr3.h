begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    generic System V Release 3 system.    Copyright (C) 1991, 1996, 2000 Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@monkeys.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     To use this file, make up a file with a name like:  	?????svr3.h     where ????? is replaced by the name of the basic hardware that you    are targeting for.  Then, in the file ?????svr3.h, put something    like:  	#include "?????.h" 	#include "svr3.h"     followed by any really system-specific defines (or overrides of    defines) which you find that you need.  For example, CPP_PREDEFINES    is defined here with only the defined -Dunix and -DSVR3.  You should    probably override that in your target-specific ?????svr3.h file    with a set of defines that includes these, but also contains an    appropriate define for the type of hardware that you are targeting. */
end_comment

begin_comment
comment|/* Define a symbol indicating that we are using svr3.h.  */
end_comment

begin_define
define|#
directive|define
name|USING_SVR3_H
end_define

begin_comment
comment|/* Define a symbol so that libgcc* can know what sort of operating    environment and assembler syntax we are targeting for.  */
end_comment

begin_define
define|#
directive|define
name|SVR3_target
end_define

begin_comment
comment|/* Cpp, assembler, linker, library, and startfile spec's.  */
end_comment

begin_comment
comment|/* You should redefine CPP_PREDEFINES in any file which includes this one.    The definition should be appropriate for the type of target system    involved, and it should include any -A (assertion) options which are    appropriate for the given target system.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_comment
comment|/* Output at beginning of assembler file.  */
end_comment

begin_comment
comment|/* The .file command should always begin the output.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do { output_file_directive ((FILE), main_input_filename);	\        if (optimize) { ASM_FILE_START_1 (FILE); }		\      } while (0)
end_define

begin_comment
comment|/* By default, do nothing: a few machines support .optim, but not most.  */
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
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_comment
comment|/* We don't use ROUNDED because the standard compiler doesn't,    and the linker gives error messages if a common symbol    has more than one length value.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
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
value|( fputs (".comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (SIZE)))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

begin_comment
comment|/* Note that using bss_section here caused errors    in building shared libraries on system V.3.  */
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
value|do {							\     int align = exact_log2 (ROUNDED);			\     if (align> 2) align = 2;				\     data_section ();					\     ASM_OUTPUT_ALIGN ((FILE), align == -1 ? 2 : align);	\     ASM_OUTPUT_LABEL ((FILE), (NAME));			\     fprintf ((FILE), "\t.set .,.+%u\n", (ROUNDED));	\   } while (0)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* For now, let's leave these machine-specific.  */
end_comment

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"-lc crtn.o%s"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp} -lc crtn.o%s"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Special flags for the linker.  I don't know what they do.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{T*} %{z:-lm}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allow #sccs in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Output #ident as a .ident.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_IDENT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "\t.ident \"%s\"\n", NAME);
end_define

begin_comment
comment|/* Use periods rather than dollar signs in special g++ assembler names.  */
end_comment

begin_define
define|#
directive|define
name|NO_DOLLAR_IN_LABEL
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* System V Release 3 uses COFF debugging info.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* We don't want to output DBX debugging information.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

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

begin_comment
comment|/* The prefix to add to user-visible assembler symbols.     For System V Release 3 the convention is to prepend a leading    underscore onto user-level symbol names.  */
end_comment

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|"_"
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.     For most svr3 systems, the convention is that any symbol which begins    with a period is not put into the linker symbol table by the assembler.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|asm_fprintf (FILE, "%0L%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.     For most svr3 systems, the convention is that any symbol which begins    with a period is not put into the linker symbol table by the assembler.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf (LABEL, "*%s%s%ld", LOCAL_LABEL_PREFIX, PREFIX, (long)(NUM))
end_define

begin_comment
comment|/* We want local labels to start with period if made with asm_fprintf.  */
end_comment

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* Support const sections and the ctors and dtors sections for g++.    Note that there appears to be two different ways to support const    sections at the moment.  You can either #define the symbol    READONLY_DATA_SECTION (giving it some code which switches to the    readonly data section) or else you can #define the symbols    EXTRA_SECTIONS, EXTRA_SECTION_FUNCTIONS, SELECT_SECTION, and    SELECT_RTX_SECTION.  We do both here just to be on the safe side.    However, use of the const section is turned off by default    unless the specific tm.h file turns it on by defining    USE_CONST_SECTION as 1.  */
end_comment

begin_comment
comment|/* Define a few machine-specific details of the implementation of    constructors.     The __CTORS_LIST__ goes in the .init section.  Define CTOR_LIST_BEGIN    and CTOR_LIST_END to contribute to the .init section an instruction to    push a word containing 0 (or some equivalent of that).     Define TARGET_ASM_CONSTRUCTOR to push the address of the constructor.  */
end_comment

begin_define
define|#
directive|define
name|USE_CONST_SECTION
value|0
end_define

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
name|CONST_SECTION_ASM_OP
value|"\t.section\t.rodata, \"x\""
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

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_GROWS_DOWNWARD
end_ifndef

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Constructor list on stack is in correct order.  Just call them.  */
end_comment

begin_define
define|#
directive|define
name|DO_GLOBAL_CTORS_BODY
define|\
value|do {								\   func_ptr *p, *beg = alloca (0);				\   for (p = beg; *p; )						\     (*p++) ();							\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STACK_GROWS_DOWNWARD */
end_comment

begin_comment
comment|/* Add extra sections .rodata, .init and .fini.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_const, in_init, in_fini
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
value|CONST_SECTION_FUNCTION					\   INIT_SECTION_FUNCTION						\   FINI_SECTION_FUNCTION
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
name|READONLY_DATA_SECTION
parameter_list|()
value|const_section ()
end_define

begin_define
define|#
directive|define
name|CONST_SECTION_FUNCTION
define|\
value|void									\ const_section ()							\ {									\   if (!USE_CONST_SECTION)						\     text_section();							\   else if (in_section != in_const)					\     {									\       fprintf (asm_out_file, "%s\n", CONST_SECTION_ASM_OP);		\       in_section = in_const;						\     }									\ }
end_define

begin_comment
comment|/* A C statement or statements to switch to the appropriate    section for output of DECL.  DECL is either a `VAR_DECL' node    or a constant of some sort.  RELOC indicates whether forming    the initial value of DECL requires link-time relocations.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|{									\   if (TREE_CODE (DECL) == STRING_CST)					\     {									\       if (! flag_writable_strings)					\ 	const_section ();						\       else								\ 	data_section ();						\     }									\   else if (TREE_CODE (DECL) == VAR_DECL)				\     {									\       if ((0&& RELOC)
comment|/* should be (flag_pic&& RELOC) */
value|\ 	  || !TREE_READONLY (DECL) || TREE_SIDE_EFFECTS (DECL)		\ 	  || !DECL_INITIAL (DECL)					\ 	  || (DECL_INITIAL (DECL) != error_mark_node			\&& !TREE_CONSTANT (DECL_INITIAL (DECL))))			\ 	data_section ();						\       else								\ 	const_section ();						\     }									\   else									\     const_section ();							\ }
end_define

begin_comment
comment|/* A C statement or statements to switch to the appropriate    section for output of RTX in mode MODE.  RTX is some kind    of constant in RTL.  The argument MODE is redundant except    in the case of a `const_int' rtx.  Currently, these always    go into the const section.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|RTX
parameter_list|,
name|ALIGN
parameter_list|)
value|const_section()
end_define

end_unit

