begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running FreeBSD with either a.out or ELF format    Copyright (C) 1994, 1995 Free Software Foundation, Inc.    Contributed by Eric Youngdale.    Modified for stabs-in-ELF by H.J. Lu.    Adapted from Linux version by John Polstra.    Added support for generating "old a.out gas" on the fly by Peter Wemm.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* A lie, I guess, but the general idea behind FreeBSD/ELF is that we are    supposed to be outputting something that will assemble under SVr4.    This gets us pretty close.  */
end_comment

begin_include
include|#
directive|include
file|<i386/i386.h>
end_include

begin_comment
comment|/* Base i386 target machine definitions */
end_comment

begin_include
include|#
directive|include
file|<i386/att.h>
end_include

begin_comment
comment|/* Use the i386 AT&T assembler syntax */
end_comment

begin_include
include|#
directive|include
file|<linux.h>
end_include

begin_comment
comment|/* some common stuff */
end_comment

begin_comment
comment|/* Don't assume anything about the header files. */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* This defines which switch letters take arguments.  On svr4, most of    the normal cases (defined in gcc.c) apply, and we also have -h* and    -z* options (for the linker).  We have a slightly different mix.  We    have -R (alias --rpath), no -z, --soname (-h), --assert etc. */
end_comment

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(   (CHAR) == 'D' \    || (CHAR) == 'U' \    || (CHAR) == 'o' \    || (CHAR) == 'e' \    || (CHAR) == 'T' \    || (CHAR) == 'u' \    || (CHAR) == 'I' \    || (CHAR) == 'm' \    || (CHAR) == 'L' \    || (CHAR) == 'A' \    || (CHAR) == 'h' \    || (CHAR) == 'z'
comment|/* ignored by ld */
value|\    || (CHAR) == 'R')
end_define

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\    || !strcmp (STR, "rpath") || !strcmp (STR, "rpath-link")		\    || !strcmp (STR, "soname") || !strcmp (STR, "defsym") 		\    || !strcmp (STR, "assert") || !strcmp (STR, "dynamic-linker"))
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i386 FreeBSD)");
end_define

begin_define
define|#
directive|define
name|MASK_PROFILER_EPILOGUE
value|010000000000
end_define

begin_define
define|#
directive|define
name|MASK_AOUT
value|004000000000
end_define

begin_comment
comment|/* a.out not elf */
end_comment

begin_define
define|#
directive|define
name|MASK_UNDERSCORES
value|002000000000
end_define

begin_comment
comment|/* use leading _ */
end_comment

begin_define
define|#
directive|define
name|TARGET_PROFILER_EPILOGUE
value|(target_flags& MASK_PROFILER_EPILOGUE)
end_define

begin_define
define|#
directive|define
name|TARGET_AOUT
value|(target_flags& MASK_AOUT)
end_define

begin_define
define|#
directive|define
name|TARGET_ELF
value|((target_flags& MASK_AOUT) == 0)
end_define

begin_define
define|#
directive|define
name|TARGET_UNDERSCORES
value|((target_flags& MASK_UNDERSCORES) != 0)
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{ "profiler-epilogue",	 MASK_PROFILER_EPILOGUE},	\      { "no-profiler-epilogue",	-MASK_PROFILER_EPILOGUE},	\      { "aout",			 MASK_AOUT},			\      { "no-aout",		-MASK_AOUT},			\      { "underscores",		 MASK_UNDERSCORES},		\      { "no-underscores",	-MASK_UNDERSCORES},
end_define

begin_comment
comment|/* The svr4 ABI for the i386 says that records and unions are returned    in memory.  */
end_comment

begin_comment
comment|/* On FreeBSD, we do not. */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PCC_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_define
define|#
directive|define
name|SUPPORTS_WEAK
value|TARGET_ELF
end_define

begin_comment
comment|/* Prefix for internally generated assembler labels.  If we aren't using     underscores, we are using prefix `.'s to identify labels that should      be ignored, as in `i386/gas.h' --karl@cs.umb.edu  */
end_comment

begin_undef
undef|#
directive|undef
name|LPREFIX
end_undef

begin_define
define|#
directive|define
name|LPREFIX
value|((TARGET_UNDERSCORES) ? "L" : ".L")
end_define

begin_comment
comment|/* Override the default comment-starter of "/".  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_undef
undef|#
directive|undef
name|COMMENT_BEGIN
end_undef

begin_define
define|#
directive|define
name|COMMENT_BEGIN
value|"#"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

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
value|do {									\         output_file_directive (FILE, main_input_filename);		\ 	if (TARGET_ELF)							\           fprintf (FILE, "\t.version\t\"01.01\"\n");			\   } while (0)
end_define

begin_comment
comment|/* Identify the front-end which produced this file.  To keep symbol    space down, and not confuse kdb, only do this if the language is    not C. (svr4.h defines ASM_IDENTIFY_GCC but neglects this) */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_IDENTIFY_LANGUAGE
end_undef

begin_define
define|#
directive|define
name|ASM_IDENTIFY_LANGUAGE
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|{									\   if (strcmp (lang_identify (), "c") != 0)				\     output_lang_identify (STREAM);					\ }
end_define

begin_comment
comment|/* This is how to store into the string BUF    the symbol_ref name of an internal numbered label where          PREFIX is the class of label and NUM is the number within the class.      This is suitable for output with `assemble_name'.  */
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
name|BUF
parameter_list|,
name|PREFIX
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|sprintf ((BUF), "*%s%s%d", (TARGET_UNDERSCORES) ? "" : ".",		\ 	     (PREFIX), (NUMBER))
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
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
value|fprintf (FILE, "%s%s%d:\n", (TARGET_UNDERSCORES) ? "" : ".",		\ 	   PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "%s%s", (TARGET_UNDERSCORES) ? "_" : "", NAME)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    This is only used for PIC code.  See comments by the `casesi' insn in    i386.md for an explanation of the expression this outputs. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_DIFF_ELT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf (FILE, "\t.long _GLOBAL_OFFSET_TABLE_+[.-%s%d]\n", LPREFIX, VALUE)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)!=0) fprintf ((FILE), "\t.p2align %d\n", (LOG))
end_define

begin_comment
comment|/* Align labels, etc. at 4-byte boundaries.    For the 486, align to 16-byte boundary for sake of cache.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN_CODE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN_CODE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf ((FILE), "\t.p2align %d,0x90\n", i386_align_jumps)
end_define

begin_comment
comment|/* Align start of loop at 4-byte boundary.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOOP_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOOP_ALIGN
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf ((FILE), "\t.p2align %d,0x90\n", i386_align_loops)
end_define

begin_comment
comment|/* conditionalize the use of ".section rodata" on elf mode - otherwise .text */
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
value|TARGET_ELF
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global constructors.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CONSTRUCTOR
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CONSTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\     if (TARGET_ELF) {							\       ctors_section ();							\       fprintf (FILE, "\t%s\t ", INT_ASM_OP);				\       assemble_name (FILE, NAME);					\       fprintf (FILE, "\n");						\     } else {								\       fprintf (asm_out_file, "%s \"%s__CTOR_LIST__\",22,0,0,", ASM_STABS_OP, \ 	       (TARGET_UNDERSCORES) ? "_" : "");			\       assemble_name (asm_out_file, name);				\       fputc ('\n', asm_out_file);					\     }									\   } while (0)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global destructors.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DESTRUCTOR
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DESTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\     if (TARGET_ELF) {							\       dtors_section ();							\       fprintf (FILE, "\t%s\t ", INT_ASM_OP);				\       assemble_name (FILE, NAME);					\       fprintf (FILE, "\n");						\     } else {								\       fprintf (asm_out_file, "%s \"%s__DTOR_LIST__\",22,0,0,", ASM_STABS_OP, \ 	       (TARGET_UNDERSCORES) ? "_" : "");			\       assemble_name (asm_out_file, name);				\       fputc ('\n', asm_out_file);					\     }									\   } while (0)
end_define

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized internal linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\   if (TARGET_ELF) {							\     fprintf ((FILE), "\t%s\t", LOCAL_ASM_OP);				\     assemble_name ((FILE), (NAME));					\     fprintf ((FILE), "\n");						\     ASM_OUTPUT_ALIGNED_COMMON (FILE, NAME, SIZE, ALIGN);		\   } else {								\     int rounded = (SIZE);						\     if (rounded == 0) rounded = 1;					\     rounded += (BIGGEST_ALIGNMENT / BITS_PER_UNIT) - 1;			\     rounded = (rounded / (BIGGEST_ALIGNMENT / BITS_PER_UNIT)		\ 			   * (BIGGEST_ALIGNMENT / BITS_PER_UNIT));	\     fputs (".lcomm ", (FILE));						\     assemble_name ((FILE), (NAME));					\     fprintf ((FILE), ",%u\n", (rounded));				\   }									\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\   if (TARGET_ELF) {							\     fprintf ((FILE), "\t%s\t", COMMON_ASM_OP);				\     assemble_name ((FILE), (NAME));					\     fprintf ((FILE), ",%u,%u\n", (SIZE), (ALIGN) / BITS_PER_UNIT);	\   } else {								\     int rounded = (SIZE);						\     if (rounded == 0) rounded = 1;					\     rounded += (BIGGEST_ALIGNMENT / BITS_PER_UNIT) - 1;			\     rounded = (rounded / (BIGGEST_ALIGNMENT / BITS_PER_UNIT)		\ 			   * (BIGGEST_ALIGNMENT / BITS_PER_UNIT));	\     fputs (".comm ", (FILE));						\     assemble_name ((FILE), (NAME));					\     fprintf ((FILE), ",%u\n", (rounded));				\   }									\ } while (0)
end_define

begin_comment
comment|/* Turn off svr4.h version, it chokes the old gas.  The old layout    works fine under new gas anyway. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_comment
comment|/* How to output some space */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SKIP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|do {									\   if (TARGET_ELF) {							\     fprintf (FILE, "\t%s\t%u\n", SKIP_ASM_OP, (SIZE));			\   } else {								\     fprintf (FILE, "\t.space %u\n", (SIZE));				\   }									\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_LINE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|do {									\   static int sym_lineno = 1;						\   if (TARGET_ELF) {							\     fprintf (file, ".stabn 68,0,%d,.LM%d-", line, sym_lineno);		\     assemble_name (file, XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));\     fprintf (file, "\n.LM%d:\n", sym_lineno);				\     sym_lineno += 1;							\   } else {								\     fprintf (file, "\t%s %d,0,%d\n", ASM_STABD_OP, N_SLINE, lineno);	\   }									\ } while (0)
end_define

begin_comment
comment|/* in elf, the function stabs come first, before the relative offsets */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_FUNCTION_FIRST
end_undef

begin_define
define|#
directive|define
name|DBX_CHECK_FUNCTION_FIRST
value|TARGET_ELF
end_define

begin_comment
comment|/* tag end of file in elf mode */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_MAIN_SOURCE_FILE_END
end_undef

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_FILE_END
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
define|\
value|do {									\   if (TARGET_ELF) {							\     fprintf (FILE, "\t.text\n\t.stabs \"\",%d,0,0,.Letext\n.Letext:\n", N_SO); \   }									\ } while (0)
end_define

begin_comment
comment|/* stabs-in-elf has offsets relative to function beginning */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_LBRAC
end_undef

begin_define
define|#
directive|define
name|DBX_OUTPUT_LBRAC
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
define|\
value|do {									\   fprintf (asmfile, "%s %d,0,0,", ASM_STABN_OP, N_LBRAC);		\   assemble_name (asmfile, buf);						\   if (TARGET_ELF) {							\     fputc ('-', asmfile);						\     assemble_name (asmfile, XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0)); \   }									\   fprintf (asmfile, "\n");						\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_RBRAC
end_undef

begin_define
define|#
directive|define
name|DBX_OUTPUT_RBRAC
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
define|\
value|do {									\   fprintf (asmfile, "%s %d,0,0,", ASM_STABN_OP, N_RBRAC);		\   assemble_name (asmfile, buf);						\   if (TARGET_ELF) {							\     fputc ('-', asmfile);						\     assemble_name (asmfile, XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0)); \   }									\   fprintf (asmfile, "\n");						\ } while (0)
end_define

begin_comment
comment|/* Define macro used to output shift-double opcodes when the shift    count is in %cl.  Some assemblers require %cl as an argument;    some don't.     *OLD* GAS requires the %cl argument, so override i386/unix.h. */
end_comment

begin_undef
undef|#
directive|undef
name|AS3_SHIFT_DOUBLE
end_undef

begin_define
define|#
directive|define
name|AS3_SHIFT_DOUBLE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|AS3 (a,b,c,d)
end_define

begin_comment
comment|/* Indicate that jump tables go in the text section.  This is    necessary when compiling PIC code.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
end_define

begin_comment
comment|/* override the exception table positioning */
end_comment

begin_define
define|#
directive|define
name|EXCEPTION_SECTION_FUNCTION
define|\
value|do {									\   if (TARGET_ELF) {							\     named_section (NULL_TREE, ".gcc_except_table");			\   } else {								\     if (flag_pic)							\       data_section ();							\     else								\       readonly_data_section ();						\   }									\ } while (0);
end_define

begin_comment
comment|/* supply our own hook for calling __main() from main() */
end_comment

begin_define
define|#
directive|define
name|GEN_CALL__MAIN
define|\
value|do {									\     if (!(TARGET_ELF))							\       emit_library_call (gen_rtx (SYMBOL_REF, Pmode, NAME__MAIN), 0,	\ 			 VOIDmode, 0);					\   } while (0)
end_define

begin_comment
comment|/* Map i386 registers to the numbers dwarf expects.  Of course this is different    from what stabs expects.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF_DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DWARF_DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
define|\
value|((n) == 0 ? 0 \  : (n) == 1 ? 2 \  : (n) == 2 ? 1 \  : (n) == 3 ? 3 \  : (n) == 4 ? 6 \  : (n) == 5 ? 7 \  : (n) == 6 ? 5 \  : (n) == 7 ? 4 \  : ((n)>= FIRST_STACK_REG&& (n)<= LAST_STACK_REG) ? (n)+3 \  : (-1))
end_define

begin_comment
comment|/* Now what stabs expects in the register.  */
end_comment

begin_define
define|#
directive|define
name|STABS_DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
define|\
value|((n) == 0 ? 0 : \  (n) == 1 ? 2 : \  (n) == 2 ? 1 : \  (n) == 3 ? 3 : \  (n) == 4 ? 6 : \  (n) == 5 ? 7 : \  (n) == 6 ? 4 : \  (n) == 7 ? 5 : \  (n) + 4)
end_define

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
value|((write_symbols == DWARF_DEBUG)	\ 				? DWARF_DBX_REGISTER_NUMBER(n)	\ 				: STABS_DBX_REGISTER_NUMBER(n))
end_define

begin_comment
comment|/* Tell final.c that we don't need a label passed to mcount.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_DATA
end_define

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  */
end_comment

begin_comment
comment|/* Redefine this to not pass an unused label in %edx.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{									\   if (flag_pic)								\     fprintf (FILE, "\tcall *mcount@GOT(%%ebx)\n");			\   else									\     fprintf (FILE, "\tcall mcount\n");					\ }
end_define

begin_define
define|#
directive|define
name|FUNCTION_PROFILER_EPILOGUE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{									\   if (TARGET_PROFILER_EPILOGUE)						\     {									\       if (flag_pic)							\ 	fprintf (FILE, "\tcall *mexitcount@GOT(%%ebx)\n");		\       else								\ 	fprintf (FILE, "\tcall mexitcount\n");				\     }									\ }
end_define

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
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|0
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
comment|/* FREEBSD_NATIVE is defined when gcc is integrated into the FreeBSD    source tree so it can be configured appropriately without using    the GNU configure/build mechanism. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FREEBSD_NATIVE
end_ifdef

begin_comment
comment|/* Look for the include files in the system-defined places.  */
end_comment

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|"/usr/include/g++"
end_define

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|"/usr/include"
end_define

begin_comment
comment|/* FreeBSD has GCC_INCLUDE_DIR first.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{					\     { GCC_INCLUDE_DIR, 0, 0 },		\     { GPLUSPLUS_INCLUDE_DIR, 1, 1 },	\     { 0, 0, 0 }				\   }
end_define

begin_comment
comment|/* Under FreeBSD, the normal location of the compiler back ends is the    /usr/libexec directory.  */
end_comment

begin_define
define|#
directive|define
name|STANDARD_EXEC_PREFIX
value|"/usr/libexec/"
end_define

begin_comment
comment|/* Under FreeBSD, the normal location of the various *crt*.o files is the    /usr/lib directory.  */
end_comment

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"/usr/lib/"
end_define

begin_comment
comment|/* On FreeBSD, gcc is called 'cc' */
end_comment

begin_define
define|#
directive|define
name|GCC_NAME
value|"cc"
end_define

begin_comment
comment|/* FreeBSD is 4.4BSD derived */
end_comment

begin_define
define|#
directive|define
name|bsd4_4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FREEBSD_NATIVE */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -D__FreeBSD__=3 -Asystem(unix) -Asystem(FreeBSD) -Acpu(i386) -Amachine(i386)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{!maout: -D__ELF__} \ %{munderscores: -D__UNDERSCORES__} \ %{maout: %{!mno-underscores: -D__UNDERSCORES__}} \ %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} %{!m386:-D__i486__}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{!maout: -D__ELF__} \ %{munderscores: -D__UNDERSCORES__} \ %{maout: %{!mno-underscores: -D__UNDERSCORES__}} \ %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} %{m486:-D__i486__}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{gline:%{!g:%{!g0:%{!g1:%{!g2: -g1}}}}} \ %{maout: %{!mno-underscores: %{!munderscores: -munderscores }}}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{v*: -v} %{maout: %{fpic:-k} %{fPIC:-k}}"
end_define

begin_comment
comment|/* Like the default, except no -lg, and no -p.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!shared:%{!pg:%{!pthread:%{!kthread:-lc}%{kthread:-lpthread -lc}}%{pthread:-lc_r}}%{pg:%{!pthread:%{!kthread:-lc_r}%{kthread:-lpthread_p -lc_p}}%{pthread:-lc_r_p}}}"
end_define

begin_comment
comment|/* Let gcc locate this for us according to the -m rules */
end_comment

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"%{!shared:libgcc.a%s}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for FreeBSD.  Here we provide support    for the special GCC options -static and -shared, which allow us to    link things in one of these three modes by applying the appropriate    combinations of options at link-time. We like to support here for    as many of the other GNU linker options as possible. But I don't    have the time to search for those flags. I am sure how to add    support for -soname shared_object_name. H.J.     When the -shared link option is used a final link is not being    done.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\  %{p:%e`-p' not supported; use `-pg' and gprof(1)} \   %{maout: %{shared:-Bshareable} \     %{!shared:%{!nostdlib:%{!r:%{!e*:-e start}}} -dc -dp %{static:-Bstatic} \       %{pg:-Bstatic} %{Z}} \     %{assert*} %{R*}} \   %{!maout: \     -m elf_i386 \     %{Wl,*:%*} \     %{assert*} %{R*} %{rpath*} %{defsym*} \     %{shared:-Bshareable %{h*} %{soname*}} \     %{symbolic:-Bsymbolic} \     %{!shared: \       %{!static: \ 	%{rdynamic: -export-dynamic} \ 	%{!dynamic-linker: -dynamic-linker /usr/libexec/ld-elf.so.1}} \       %{static:-Bstatic}}}"
end_define

begin_comment
comment|/* Get perform_* macros to build libgcc.a.  */
end_comment

begin_include
include|#
directive|include
file|"i386/perform.h"
end_include

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"\   %{maout: %{shared:c++rt0.o%s} \     %{!shared:%{pg:gcrt0.o%s}%{!pg:%{static:scrt0.o%s}%{!static:crt0.o%s}}}} \   %{!maout:  %{!shared: \     %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}} \     crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}}"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
define|\
value|"%{!maout: %{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s}"
end_define

begin_comment
comment|/* This goes away when the math emulator is fixed.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_NO_FANCY_MATH_387 | 0301)
end_define

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_define
define|#
directive|define
name|HAVE_PUTENV
end_define

begin_comment
comment|/* to assist building libgcc2.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ELF__
end_ifndef

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_ELF
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

