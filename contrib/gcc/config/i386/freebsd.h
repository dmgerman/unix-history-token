begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running FreeBSD with either a.out or ELF format    Copyright (C) 1996 Free Software Foundation, Inc.    Contributed by Eric Youngdale.    Modified for stabs-in-ELF by H.J. Lu.    Adapted from GNU/Linux version by John Polstra.    Added support for generating "old a.out gas" on the fly by Peter Wemm.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i386 FreeBSD/ELF)");
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

begin_comment
comment|/* This gets defined in tm.h->linux.h->svr4.h, and keeps us from using    libraries compiled with the native cc, so undef it. */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_IMPLICIT_EXTERN_C
end_undef

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* This defines which switch letters take arguments.  On FreeBSD, most of    the normal cases (defined in gcc.c) apply, and we also have -h* and    -z* options (for the linker) (comming from svr4).    We also have -R (alias --rpath), no -z, --soname (-h), --assert etc.  */
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
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR)					\    || (CHAR) == 'h'							\    || (CHAR) == 'z'
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

begin_define
define|#
directive|define
name|SET_ASM_OP
value|".set"
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
name|BODY
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
value|if ((LOG)!=0) {							\     if (in_text_section())						\       fprintf ((FILE), "\t.p2align %d,0x90\n", (LOG));			\     else								\       fprintf ((FILE), "\t.p2align %d\n", (LOG));			\   }
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
comment|/* The a.out tools do not support "linkonce" sections. */
end_comment

begin_define
define|#
directive|define
name|SUPPORTS_ONE_ONLY
value|TARGET_ELF
end_define

begin_comment
comment|/* The a.out tools do not support "Lscope" .stabs symbols. */
end_comment

begin_define
define|#
directive|define
name|NO_DBX_FUNCTION_END
value|TARGET_AOUT
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

begin_undef
undef|#
directive|undef
name|DEFAULT_VTABLE_THUNKS
end_undef

begin_define
define|#
directive|define
name|DEFAULT_VTABLE_THUNKS
value|1
end_define

begin_comment
comment|/* This is BSD, so we want the DBX format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Use stabs instead of DWARF debug format.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
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
value|(flag_pic)
end_define

begin_comment
comment|/* override the exception table positioning */
end_comment

begin_define
define|#
directive|define
name|EXCEPTION_SECTION
parameter_list|()
define|\
value|do {									\   if (TARGET_ELF) {							\     named_section (NULL_TREE, ".gcc_except_table", 0);			\   } else {								\     if (flag_pic)							\       data_section ();							\     else								\       readonly_data_section ();						\   }									\ } while (0);
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
comment|/* Copy this from the svr4 specifications... */
end_comment

begin_comment
comment|/* Define the register numbers to be used in Dwarf debugging information.    The SVR4 reference port C compiler uses the following register numbers    in its Dwarf output code: 	0 for %eax (gnu regno = 0) 	1 for %ecx (gnu regno = 2) 	2 for %edx (gnu regno = 1) 	3 for %ebx (gnu regno = 3) 	4 for %esp (gnu regno = 7) 	5 for %ebp (gnu regno = 6) 	6 for %esi (gnu regno = 4) 	7 for %edi (gnu regno = 5)    The following three DWARF register numbers are never generated by    the SVR4 C compiler or by the GNU compilers, but SDB on x86/svr4    believes these numbers have these meanings. 	8  for %eip    (no gnu equivalent) 	9  for %eflags (no gnu equivalent) 	10 for %trapno (no gnu equivalent)    It is not at all clear how we should number the FP stack registers    for the x86 architecture.  If the version of SDB on x86/svr4 were    a bit less brain dead with respect to floating-point then we would    have a precedent to follow with respect to DWARF register numbers    for x86 FP registers, but the SDB on x86/svr4 is so completely    broken with respect to FP registers that it is hardly worth thinking    of it as something to strive for compatibility with.    The version of x86/svr4 SDB I have at the moment does (partially)    seem to believe that DWARF register number 11 is associated with    the x86 register %st(0), but that's about all.  Higher DWARF    register numbers don't seem to be associated with anything in    particular, and even for DWARF regno 11, SDB only seems to under-    stand that it should say that a variable lives in %st(0) (when    asked via an `=' command) if we said it was in DWARF regno 11,    but SDB still prints garbage when asked for the value of the    variable in question (via a `/' command).    (Also note that the labels SDB prints for various FP stack regs    when doing an `x' command are all wrong.)    Note that these problems generally don't affect the native SVR4    C compiler because it doesn't allow the use of -O with -g and    because when it is *not* optimizing, it allocates a memory    location for each floating-point variable, and the memory    location is what gets described in the DWARF AT_location    attribute for the variable in question.    Regardless of the severe mental illness of the x86/svr4 SDB, we    do something sensible here and we use the following DWARF    register numbers.  Note that these are all stack-top-relative    numbers. 	11 for %st(0) (gnu regno = 8) 	12 for %st(1) (gnu regno = 9) 	13 for %st(2) (gnu regno = 10) 	14 for %st(3) (gnu regno = 11) 	15 for %st(4) (gnu regno = 12) 	16 for %st(5) (gnu regno = 13) 	17 for %st(6) (gnu regno = 14) 	18 for %st(7) (gnu regno = 15) */
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
value|{									\   if (flag_pic)								\     {									\       fprintf (FILE, "\tcall *%s@GOT(%%ebx)\n",				\       TARGET_AOUT ? "mcount" : ".mcount");				\     }									\   else									\     {									\       fprintf (FILE, "\tcall %s\n", TARGET_AOUT ? "mcount" : ".mcount");	\     }									\ }
end_define

begin_define
define|#
directive|define
name|FUNCTION_PROFILER_EPILOGUE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{									\   if (TARGET_PROFILER_EPILOGUE)						\     {									\       if (flag_pic)							\ 	fprintf (FILE, "\tcall *%s@GOT(%%ebx)\n",			\ 	  TARGET_AOUT ? "mexitcount" : ".mexitcount");			\       else								\ 	fprintf (FILE, "\tcall %s\n",					\ 	  TARGET_AOUT ? "mexitcount" : ".mexitcount");			\     }									\ }
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

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Di386 -Dunix -D__FreeBSD__=4 -D__FreeBSD_cc_version=400002 -Asystem(unix) -Asystem(FreeBSD) -Acpu(i386) -Amachine(i386)"
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
value|"%{!shared:%{!pg:%{!pthread:%{!kthread:-lc}%{kthread:-lpthread -lc}}%{pthread:-lc_r}}%{pg:%{!pthread:%{!kthread:-lc_p}%{kthread:-lpthread_p -lc_p}}%{pthread:-lc_r_p}}}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for FreeBSD.  Here we provide support    for the special GCC options -static and -shared, which allow us to    link things in one of these three modes by applying the appropriate    combinations of options at link-time. We like to support here for    as many of the other GNU linker options as possible. But I don't    have the time to search for those flags. I am sure how to add    support for -soname shared_object_name. H.J.     I took out %{v:%{!V:-V}}. It is too much :-(. They can use    -Wl,-V.     When the -shared link option is used a final link is not being    done.  */
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
comment|/* A C statement to output to the stdio stream FILE an assembler    command to advance the location counter to a multiple of 1<<LOG    bytes if it is within MAX_SKIP bytes.     This is used to align code labels according to Intel recommendations.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

begin_error
error|#
directive|error
literal|"we don't have this for the aout gas"
end_error

begin_define
define|#
directive|define
name|ASM_OUTPUT_MAX_SKIP_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|,
name|MAX_SKIP
parameter_list|)
define|\
value|if ((LOG)!=0) \     if ((MAX_SKIP)==0) fprintf ((FILE), "\t.p2align %d\n", (LOG)); \     else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* FreeBSD ELF using our home-grown crtbegin.o/crtend.o does not support the    DWARF2 unwinding mechanisms.  Once `make world' bootstraping problems with    the EGCS crtstuff.c is overcome, we will switch to the non-sjlj-exceptions     type exception machanism.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

end_unit

