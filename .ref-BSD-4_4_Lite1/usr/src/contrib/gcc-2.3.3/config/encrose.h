begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.      Encore Multimax (OSF/1 with OSF/rose) version.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Output a '?' so the encore assembler won't complain about  * externals on branches it hasn't seen yet. */
end_comment

begin_define
define|#
directive|define
name|EXTERNAL_PREFIX
value|'?'
end_define

begin_include
include|#
directive|include
file|"encore.h"
end_include

begin_comment
comment|/* External variables defined in ns32k.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ns32k_num_files
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OSF_OS
end_define

begin_define
define|#
directive|define
name|NO_J_SWITCH
end_define

begin_comment
comment|/* MACHINE MACROS controlling the compilation driver, 'gcc' */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPP_SPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{.S:	-D__LANGUAGE_ASSEMBLY__			\ 				-D_LANGUAGE_ASSEMBLY			\ 				%{!ansi:-DLANGUAGE_ASSEMBLY}}		\ 			 %{!.S:	-D__LANGUAGE_C__			\ 				-D_LANGUAGE_C				\ 				%{!ansi:-DLANGUAGE_C}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CC1_SPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CC1_SPEC
value|""
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_J_SWITCH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_SPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{!j: -j}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NO_J_SWITCH
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_SPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LINK_SPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{nostdlib}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LIB_SPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-lprof1} -lc"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LIBG_SPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|LIBG_SPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LIBG_SPEC
value|""
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STARTFILE_SPEC
end_ifdef

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MACHINE_TYPE
end_ifdef

begin_undef
undef|#
directive|undef
name|MACHINE_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"Encore Multimax running OSF/1 with OSF/rose objects"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_VERSION
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_VERSION
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_VERSION
value|"Encore syntax using GAS/stabs"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MD_EXEC_PREFIX
end_ifdef

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/ccs/gcc/"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MD_STARTFILE_PREFIX
end_ifdef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/ccs/lib/"
end_define

begin_comment
comment|/* MACHINE MACROS controlling run-time target specification */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPP_PREDEFINES
end_ifdef

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dns32000 -Dn16 -Dns16000 -Dns32332 -Dunix -Dmultimax -DMULTIMAX -DOSF -DOSF1"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_DEFAULT
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|33
end_define

begin_comment
comment|/* 32081 and no (sb) register */
end_comment

begin_comment
comment|/* MACHINE MACROS controlling the layout of C types */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIZE_TYPE
end_ifdef

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PTRDIFF_TYPE
end_ifdef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WCHAR_TYPE
end_ifdef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned int"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WCHAR_TYPE_SIZE
end_ifdef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|((TARGET_WC8)					\ 				? "unsigned char"			\ 				: ((TARGET_WC16)			\ 					? "short unsigned int"		\ 					: "long unsigned int"))
end_define

begin_define
define|#
directive|define
name|MULTIBYTE_CHARS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MACHINE MACROS describing stack layout and calling conventions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FUNCTION_PROFILER
end_ifdef

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
value|fprintf (FILE, "\tjsr mcount\n")
end_define

begin_comment
comment|/* MACHINE MACROS describing the overall framework of an    assembly file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PRINT_OPERAND
end_ifdef

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
value|print_operand(FILE, X, CODE)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PRINT_OPERAND_ADDRESS
end_ifdef

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND_ADDRESS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|FILE
parameter_list|,
name|ADDR
parameter_list|)
value|print_operand_address(FILE, ADDR)
end_define

begin_define
define|#
directive|define
name|STABS_DIRECTIVE
value|"\t.stabs"
end_define

begin_comment
comment|/* align .stabs */
end_comment

begin_define
define|#
directive|define
name|STABN_DIRECTIVE
value|"\t.stabn"
end_define

begin_comment
comment|/* align .stabn */
end_comment

begin_define
define|#
directive|define
name|STABD_DIRECTIVE
value|"\t.stabd"
end_define

begin_comment
comment|/* align .stabd */
end_comment

begin_comment
comment|/* How to tell the debugger about changes of source files.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_OUTPUT_SOURCE_FILENAME
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_FILENAME
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Perhaps it is no longer necessary to redefine this, now that dbxout.c    uses another macro instead.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|{									\   if (ns32k_num_files++ == 0)						\     fprintf (FILE, "\t.file \"%s\"\n", NAME);				\   else if (write_symbols == DBX_DEBUG)					\   {                                                                     \     char ltext_label_name[100];                                         \     ASM_GENERATE_INTERNAL_LABEL(ltext_label_name, "Ltext", 0);          \     fprintf (FILE, "%s \"%s\",%d,0,0,%s\n", STABS_DIRECTIVE,		\ 	     NAME, 0x84
comment|/* N_SOL */
value|,&ltext_label_name[1]);		\   }                                                                     \   else									\     fprintf (FILE, "\t#.file \"%s\"\n", NAME);				\ }
end_define

begin_comment
comment|/* This is how to output a note the debugger telling it the line number    to which the following sequence of instructions corresponds.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_OUTPUT_SOURCE_LINE
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_LINE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|FILE
parameter_list|,
name|LINE
parameter_list|)
define|\
value|{									\   if (write_symbols != DBX_DEBUG)					\     fprintf (FILE, "\t.ln %d\n", LINE);					\   else									\     fprintf (file, "%s %d,0,%d\n", STABD_DIRECTIVE, 0x44
comment|/* N_SLINE */
value|,	\ 	     LINE);							\ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_OUTPUT_INT
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COLLECT
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\t.double "),					\   output_addr_const (FILE, (VALUE)),				\   fprintf (FILE, "\n"))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (STREAM, "\t.double\t%d\n", VALUE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MACHINE MACROS describing debugging information */
end_comment

begin_comment
comment|/* We need to have the capability to generate either    .stabs or COFF style debug info. The file ns32k.h    define DBX_DEBUGGING_INFO. We disambiguate between    the two based on a combination of command line or    default behavior. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SDB_DEBUGGING_INFO
end_ifndef

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* Generate COFF style debug info */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DBX_DEBUGGING_INFO
end_ifndef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Generate .stabs style debug info */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the user just types -g, we want to use stabs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PREFERRED_DEBUGGING_TYPE
end_ifdef

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_comment
comment|/* Define the gdb extensions */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_GDB_EXTENSIONS
value|1
end_define

begin_comment
comment|/* Tell collect that the object format is OSF/rose.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ROSE
end_define

begin_comment
comment|/* Use atexit for static constructors/destructors, instead of defining    our own exit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Generate calls to memcpy, etc., not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* A C statement to output assembler commands which will identify    the object file as having been compiled with GNU CC (or another    GNU compiler).     If you don't define this macro, the string `gcc2_compiled.:' is    output.  This string is calculated to define a symbol which, on    BSD systems, will never be defined for any other reason.  GDB    checks for the presence of this symbol when reading the symbol    table of an executable.     On non-BSD systems, you must arrange communication with GDB in    some other fashion.  If GDB is not used on your system, you can    define this macro with an empty body.     On OSF/1, gcc2_compiled. confuses the kernel debugger, so don't    put it out.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|STREAM
parameter_list|)
end_define

end_unit

