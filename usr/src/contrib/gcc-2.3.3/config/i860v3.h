begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel 80860 running System V.3    Copyright (C) 1991 Free Software Foundation, Inc.     Written by Ron Guilmette (rfg@ncd.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i860.h"
end_include

begin_include
include|#
directive|include
file|"svr3.h"
end_include

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i860, System V Release 3)")
end_define

begin_comment
comment|/* Provide a set of pre-definitions and pre-assertions appropriate for    the i860 running svr3.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Di860 -Dunix -D__svr3__"
end_define

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

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp} -lc crtn.o%s"
end_define

begin_comment
comment|/* Special flags for the linker.  I don't know what they do.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{T*} %{z:-lm}"
end_define

begin_comment
comment|/* The prefix to be used in assembler output for all names of registers.    None is needed in V.3.  */
end_comment

begin_define
define|#
directive|define
name|I860_REG_PREFIX
value|""
end_define

begin_comment
comment|/* Delimiter that starts comments in the assembler code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"//"
end_define

begin_comment
comment|/* Don't renumber the regusters for debugger output.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|(REGNO)
end_define

begin_comment
comment|/* Output the special word the System V SDB wants to see just before    the first word of each function's prologue code.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_function_original_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This special macro is used to output a magic word just before the    first word of each function.  On some versions of UNIX running on    the i860, this word can be any word that looks like a NOP, however    under svr4, this neds to be an `shr r0,r0,r0' instruction in which    the normally unused low-order bits contain the length of the function    prologue code (in bytes).  This is needed to make the System V SDB    debugger happy.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FUNCTION_PREFIX
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FUNCTION_PREFIX
parameter_list|(
name|FILE
parameter_list|,
name|FNNAME
parameter_list|)
define|\
value|do {	ASM_OUTPUT_ALIGN (FILE, 2);					\   	fprintf ((FILE), "\t.long\t.ep.");				\ 	assemble_name (FILE, FNNAME);					\ 	fprintf (FILE, "-");						\ 	assemble_name (FILE, FNNAME);					\ 	fprintf (FILE, "+0xc8000000\n");				\ 	current_function_original_name = (FNNAME);			\   } while (0)
end_define

begin_comment
comment|/* Output the special label that must go just after each function's    prologue code to support svr4 SDB.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_PROLOGUE_SUFFIX
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {	fprintf (FILE, ".ep.");						\ 	assemble_name (FILE, current_function_original_name);		\ 	fprintf (FILE, ":\n");						\   } while (0)
end_define

begin_comment
comment|/* The routine used to output string literals.  #define ASCII_DATA_ASM_OP	".byte"  #define ASM_OUTPUT_ASCII(FILE, STR, LENGTH)				\   do									\     {									\       register unsigned char *str = (unsigned char *) (STR);		\       register unsigned char *limit = str + (LENGTH);			\       register unsigned bytes_in_chunk = 0;				\       for (; str< limit; str++)					\         {								\           register unsigned ch = *str;					\           if (ch< 32 || ch == '\\' || ch == '"' || ch>= 127)		\ 	    {								\ 	      if (bytes_in_chunk> 0)					\ 	        {							\ 	          fprintf ((FILE), "\"\n");				\ 	          bytes_in_chunk = 0;					\ 	        }							\ 	      fprintf ((FILE), "\t%s\t%d\n", ASM_BYTE_OP, ch);		\ 	    }								\           else								\ 	    {								\ 	      if (bytes_in_chunk>= 60)					\ 	        {							\ 	          fprintf ((FILE), "\"\n");				\ 	          bytes_in_chunk = 0;					\ 	        }							\ 	      if (bytes_in_chunk == 0)					\ 	        fprintf ((FILE), "\t%s\t\"", ASCII_DATA_ASM_OP);	\ 	      putc (ch, (FILE));					\ 	      bytes_in_chunk++;						\ 	    }								\         }								\       if (bytes_in_chunk> 0)						\         fprintf ((FILE), "\"\n");					\     }									\   while (0)   #undef CTORS_SECTION_ASM_OP #define CTORS_SECTION_ASM_OP	".section\t.ctors,\"x\"" #undef DTORS_SECTION_ASM_OP #define DTORS_SECTION_ASM_OP	".section\t.dtors,\"x\""  /* Add definitions to support the .tdesc section as specified in the svr4    ABI for the i860.  */
end_comment

begin_define
define|#
directive|define
name|TDESC_SECTION_ASM_OP
value|".section\t.tdesc"
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
value|in_const, in_ctors, in_dtors, in_tdesc
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
value|CONST_SECTION_FUNCTION						\   CTORS_SECTION_FUNCTION						\   DTORS_SECTION_FUNCTION						\   TDESC_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|TDESC_SECTION_FUNCTION
define|\
value|void									\ tdesc_section ()							\ {									\   if (in_section != in_tdesc)						\     {									\       fprintf (asm_out_file, "%s\n", TDESC_SECTION_ASM_OP);		\       in_section = in_tdesc;						\     }									\ }
end_define

begin_comment
comment|/* Enable the `const' section that svr3.h defines how to use.  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_CONST_SECTION
end_undef

begin_define
define|#
directive|define
name|USE_CONST_SECTION
value|1
end_define

end_unit

