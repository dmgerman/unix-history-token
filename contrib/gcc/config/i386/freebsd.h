begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler for Intel 80386    running FreeBSD.    Copyright (C) 1988, 1992, 1994 Free Software Foundation, Inc.    Contributed by Poul-Henning Kamp<phk@login.dkuug.dk>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is tested by i386gas.h.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_comment
comment|/* Don't assume anything about the header files. */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_include
include|#
directive|include
file|"i386/gstabs.h"
end_include

begin_comment
comment|/* Get perform_* macros to build libgcc.a.  */
end_comment

begin_include
include|#
directive|include
file|"i386/perform.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* This was cloned from ../netbsd.h.  It and several other things in    this file should be in ../freebsd.h.  */
end_comment

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

begin_define
define|#
directive|define
name|MASK_PROFILER_EPILOGUE
value|010000000000
end_define

begin_define
define|#
directive|define
name|TARGET_PROFILER_EPILOGUE
value|(target_flags& MASK_PROFILER_EPILOGUE)
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
value|{ "profiler-epilogue",	 MASK_PROFILER_EPILOGUE},		\      { "no-profiler-epilogue",	-MASK_PROFILER_EPILOGUE},
end_define

begin_escape
end_escape

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -D__FreeBSD__=2 -Asystem(unix) -Asystem(FreeBSD) -Acpu(i386) -Amachine(i386)"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|" %| %{fpic:-k} %{fPIC:-k}"
end_define

begin_comment
comment|/* Like the default, except no -lg.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{!nostdlib:%{!r:%{!e*:-e start}}} -dc -dp %{static:-Bstatic} %{assert*} \    %{p:-Bstatic} %{pg:-Bstatic} %{Z} %{R*}"
end_define

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL_1
value|1
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:%{static:scrt0.o%s}%{!static:crt0.o%s}}}"
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

begin_escape
end_escape

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

begin_escape
end_escape

begin_comment
comment|/* The following macros are stolen from i386v4.h */
end_comment

begin_comment
comment|/* These have to be defined to get PIC code correct */
end_comment

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

begin_comment
comment|/* Indicate that jump tables go in the text section.  This is    necessary when compiling PIC code.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
end_define

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler, and    we want to retain compatibility with older gcc versions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
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

begin_escape
end_escape

begin_comment
comment|/*  * Some imports from svr4.h in support of shared libraries.  * Currently, we need the DECLARE_OBJECT_SIZE stuff.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_comment
comment|/* Define the strings used for the special svr4 .type and .size directives.    These strings generally do not vary from one system running svr4 to    another, but if a given system (e.g. m88k running svr) needs to use    different pseudo-op names for these, they may be overridden in the    file which includes this one.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ASM_OP
value|".type"
end_define

begin_define
define|#
directive|define
name|SIZE_ASM_OP
value|".size"
end_define

begin_define
define|#
directive|define
name|SET_ASM_OP
value|".set"
end_define

begin_comment
comment|/* This is how we tell the assembler that a symbol is weak.  */
end_comment

begin_define
define|#
directive|define
name|ASM_WEAKEN_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME); \        fputc ('\n', FILE); } while (0)
end_define

begin_comment
comment|/* The following macro defines the format used to output the second    operand of the .type assembler directive.  Different svr4 assemblers    expect various different forms for this operand.  The one given here    is just a default.  You may need to override it in your machine-    specific tm.h file (depending upon the particulars of your assembler).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|"@%s"
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare a function's result.    Most svr4 assemblers don't require any special declaration of the    result value, but there are exceptions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_DECLARE_RESULT
end_ifndef

begin_define
define|#
directive|define
name|ASM_DECLARE_RESULT
parameter_list|(
name|FILE
parameter_list|,
name|RESULT
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These macros generate the special .type and .size directives which    are used to set the corresponding fields of the linker symbol table    entries in an ELF object file under SVR4.  These macros also output    the starting labels for the relevant functions/objects.  */
end_comment

begin_comment
comment|/* Write the extra assembler code needed to declare a function properly.    Some svr4 assemblers need to also have something extra said about the    function's return value.  We allow for that here.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     fprintf (FILE, "\t%s\t ", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "function");			\     putc ('\n', FILE);							\     ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare an object properly.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     fprintf (FILE, "\t%s\t ", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "object");				\     putc ('\n', FILE);							\     size_directive_output = 0;						\     if (!flag_inhibit_size_directive&& DECL_SIZE (DECL))		\       {									\         size_directive_output = 1;					\ 	fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, NAME);					\ 	fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL)));	\       }									\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* Output the size directive for a decl in rest_of_decl_compilation    in the case where we did not do so before the initializer.    Once we find the error_mark_node, we know that the value of    size_directive_output was set    by ASM_DECLARE_OBJECT_NAME when it was run for the same decl.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FINISH_DECLARE_OBJECT
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|TOP_LEVEL
parameter_list|,
name|AT_END
parameter_list|)
define|\
value|do {                                                                    \      char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);                  \      if (!flag_inhibit_size_directive&& DECL_SIZE (DECL)	        \&& ! AT_END&& TOP_LEVEL                                       \&& DECL_INITIAL (DECL) == error_mark_node                      \&& !size_directive_output)                                     \        {                                                                \          fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);                        \ 	 assemble_name (FILE, name);                                    \ 	 fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL)));\ 	}								\    } while (0)
end_define

begin_comment
comment|/* This is how to declare the size of a function.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_SIZE
parameter_list|(
name|FILE
parameter_list|,
name|FNAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     if (!flag_inhibit_size_directive)					\       {									\         char label[256];						\ 	static int labelno;						\ 	labelno++;							\ 	ASM_GENERATE_INTERNAL_LABEL (label, "Lfe", labelno);		\ 	ASM_OUTPUT_INTERNAL_LABEL (FILE, "Lfe", labelno);		\ 	fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, (FNAME));					\         fprintf (FILE, ",");						\ 	assemble_name (FILE, label);					\         fprintf (FILE, "-");						\ 	assemble_name (FILE, (FNAME));					\ 	putc ('\n', FILE);						\       }									\   } while (0)
end_define

end_unit

