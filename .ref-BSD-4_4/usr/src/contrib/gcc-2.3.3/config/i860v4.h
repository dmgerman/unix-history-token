begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel 80860 running System V.4    Copyright (C) 1991 Free Software Foundation, Inc.     Written by Ron Guilmette (rfg@ncd.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i860.h"
end_include

begin_include
include|#
directive|include
file|"svr4.h"
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
value|fprintf (stderr, " (i860 System V Release 4)");
end_define

begin_comment
comment|/* Provide a set of pre-definitions and pre-assertions appropriate for    the i860 running svr4.  Note that the symbol `__SVR4__' MUST BE    DEFINED!  It is needed so that the va_list struct in va-i860.h    will get correctly defined for the svr4 (ABI compliant) case rather    than for the previous (svr3, svr2, ...) case.  It also needs to be    defined so that the correct (svr4) version of __builtin_saveregs    will be selected when we are building gnulib2.c.    __svr4__ is our extension.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Di860 -Dunix -DSVR4 -D__svr4__ -Asystem(unix) -Acpu(i860) -Amachine(i860)"
end_define

begin_comment
comment|/* The prefix to be used in assembler output for all names of registers.    This string gets prepended to all i860 register names (svr4 only).  */
end_comment

begin_define
define|#
directive|define
name|I860_REG_PREFIX
value|"%"
end_define

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_undef
undef|#
directive|undef
name|TYPE_OPERAND_FMT
end_undef

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|"\"%s\""
end_define

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
comment|/* The following macro definition overrides the one in i860.h    because the svr4 i860 assembler requires a different syntax    for getting parts of constant/relocatable values.  */
end_comment

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND_PART
end_undef

begin_define
define|#
directive|define
name|PRINT_OPERAND_PART
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|PART_CODE
parameter_list|)
define|\
value|do { fprintf (FILE, "[");						\ 	output_address (X);						\ 	fprintf (FILE, "]@%s", PART_CODE);				\   } while (0)
end_define

begin_comment
comment|/* If the host and target formats match, output the floats as hex.  */
end_comment

begin_if
if|#
directive|if
name|HOST_FLOAT_FORMAT
operator|==
name|TARGET_FLOAT_FORMAT
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HOST_WORDS_BIG_ENDIAN
argument_list|)
operator|==
name|WORDS_BIG_ENDIAN
end_if

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.    Note that the native i860/svr4 ELF assembler can't properly handle    infinity.  It generates an incorrect (non-infinity) value when given    `.double 99e9999' and it doesn't grok `inf' at all.  It also mishandles    NaNs and -0.0.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\     if (REAL_VALUE_ISINF (VALUE)					\         || REAL_VALUE_ISNAN (VALUE)					\ 	|| REAL_VALUE_MINUS_ZERO (VALUE))				\       {									\ 	long t[2];							\ 	REAL_VALUE_TO_TARGET_DOUBLE ((VALUE), t);			\ 	fprintf (FILE, "\t.word 0x%lx\n\t.word 0x%lx\n", t[0], t[1]);	\       }									\     else								\       fprintf (FILE, "\t.double %.20e\n", VALUE);			\   }
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.    Note that the native i860/svr4 ELF assembler can't properly handle    infinity.  It actually generates an assembly time error when given    `.float 99e9999' and it doesn't grok `inf' at all.  It also mishandles    NaNs and -0.0.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\     if (REAL_VALUE_ISINF (VALUE)					\         || REAL_VALUE_ISNAN (VALUE)					\ 	|| REAL_VALUE_MINUS_ZERO (VALUE))				\       {									\ 	long t;								\ 	REAL_VALUE_TO_TARGET_SINGLE ((VALUE), t);			\ 	fprintf (FILE, "\t.word 0x%lx\n", t);				\       }									\     else								\       fprintf (FILE, "\t.float %.12e\n", VALUE);			\   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* word order matches */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOST_FLOAT_FORMAT == TARGET_FLOAT_FORMAT */
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
value|do {	output_file_directive (FILE, main_input_filename);		\ 	fprintf (FILE, "\t.version\t\"01.01\"\n");			\   } while (0)
end_define

begin_comment
comment|/* Output the special word the svr4 SDB wants to see just before    the first word of each function's prologue code.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_function_original_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This special macro is used to output a magic word just before the    first word of each function.  On some versions of UNIX running on    the i860, this word can be any word that looks like a NOP, however    under svr4, this neds to be an `shr r0,r0,r0' instruction in which    the normally unused low-order bits contain the length of the function    prologue code (in bytes).  This is needed to make the svr4 SDB debugger    happy.  */
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

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".section\t.ctors,\"a\",\"progbits\""
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|".section\t.dtors,\"a\",\"progbits\""
end_define

begin_comment
comment|/* Add definitions to support the .tdesc section as specified in the svr4    ABI for the i860.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|OUTPUT_TDESC
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_FILE_END
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {				 				\      if (current_function_original_name != NULL) {		\        tdesc_section();						\        fprintf ((FILE), "%s __ETEXT\n", ASM_LONG);		\        fprintf ((FILE), "%s 0\n", ASM_LONG);			\        text_section();						\        fputs("__ETEXT:\n", (FILE));				\      }								\      fprintf ((FILE), "\t.ident\t\"GCC: (GNU) %s\"\n",		\ 	      version_string);					\    } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

