begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler for Intel 80386    running FreeBSD.    Copyright (C) 1988, 1992, 1994, 1996, 1997, 1999, 2000, 2002 Free Software    Foundation, Inc.    Contributed by Poul-Henning Kamp<phk@login.dkuug.dk>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Don't assume anything about the header files.  */
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
comment|/* This goes away when the math-emulator is fixed */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SUBTARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
define|\
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS | MASK_NO_FANCY_MATH_387)
end_define

begin_comment
comment|/* The macro defined in i386.h doesn't work with the old gas of    FreeBSD 2.x.  The definition in sco.h and sol2.h appears to work,    but it turns out that, even though the assembler doesn't complain,    we get incorrect results.  Fortunately, the definition in    defaults.h works.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_PREFERRED_EH_DATA_FORMAT
end_undef

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -D__FreeBSD__\  -Asystem=unix -Asystem=bsd -Asystem=FreeBSD"
end_define

begin_comment
comment|/* Like the default, except no -lg.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!shared:%{!pg:-lc}%{pg:-lc_p}}"
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

begin_comment
comment|/* FreeBSD using a.out does not support DWARF2 unwinding mechanisms.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* Don't default to pcc-struct-return, because in FreeBSD we prefer the    superior nature of the older gcc way.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* Ensure we the configuration knows our system correctly so we can link with    libraries compiled with the native cc.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_escape
end_escape

begin_comment
comment|/* i386 freebsd still uses old binutils that don't insert nops by default    when the .align directive demands to insert extra space in the text    segment.  */
end_comment

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
value|if ((LOG)!=0) fprintf ((FILE), "\t.align %d,0x90\n", (LOG))
end_define

begin_escape
end_escape

begin_comment
comment|/* Profiling routines, partially copied from i386/osfrose.h.  */
end_comment

begin_comment
comment|/* Redefine this to use %eax instead of %edx.  */
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
value|{									\   if (flag_pic)								\     {									\       fprintf (FILE, "\tleal %sP%d@GOTOFF(%%ebx),%%eax\n",		\ 	       LPREFIX, (LABELNO));					\       fprintf (FILE, "\tcall *mcount@GOT(%%ebx)\n");			\     }									\   else									\     {									\       fprintf (FILE, "\tmovl $%sP%d,%%eax\n", LPREFIX, (LABELNO));	\       fprintf (FILE, "\tcall mcount\n");				\     }									\ }
end_define

begin_comment
comment|/*  * Some imports from svr4.h in support of shared libraries.  * Currently, we need the DECLARE_OBJECT_SIZE stuff.  */
end_comment

begin_comment
comment|/* Define the strings used for the special svr4 .type and .size directives.    These strings generally do not vary from one system running svr4 to    another, but if a given system (e.g. m88k running svr) needs to use    different pseudo-op names for these, they may be overridden in the    file which includes this one.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ASM_OP
value|"\t.type\t"
end_define

begin_define
define|#
directive|define
name|SIZE_ASM_OP
value|"\t.size\t"
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
value|do {									\     fprintf (FILE, "%s", TYPE_ASM_OP);					\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "function");			\     putc ('\n', FILE);							\     ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
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
value|do {									\     fprintf (FILE, "%s", TYPE_ASM_OP);					\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "object");				\     putc ('\n', FILE);							\     size_directive_output = 0;						\     if (!flag_inhibit_size_directive&& DECL_SIZE (DECL))		\       {									\         size_directive_output = 1;					\ 	fprintf (FILE, "%s", SIZE_ASM_OP);				\ 	assemble_name (FILE, NAME);					\ 	fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL)));	\       }									\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
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
value|do {                                                                    \      const char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);            \      if (!flag_inhibit_size_directive&& DECL_SIZE (DECL)	        \&& ! AT_END&& TOP_LEVEL                                       \&& DECL_INITIAL (DECL) == error_mark_node                      \&& !size_directive_output)                                     \        {                                                                \          fprintf (FILE, "%s", SIZE_ASM_OP);                             \ 	 assemble_name (FILE, name);                                    \ 	 fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL)));\ 	}								\    } while (0)
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
value|do {									\     if (!flag_inhibit_size_directive)					\       {									\         char label[256];						\ 	static int labelno;						\ 	labelno++;							\ 	ASM_GENERATE_INTERNAL_LABEL (label, "Lfe", labelno);		\ 	ASM_OUTPUT_INTERNAL_LABEL (FILE, "Lfe", labelno);		\ 	fprintf (FILE, "%s", SIZE_ASM_OP);				\ 	assemble_name (FILE, (FNAME));					\         fprintf (FILE, ",");						\ 	assemble_name (FILE, label);					\         fprintf (FILE, "-");						\ 	assemble_name (FILE, (FNAME));					\ 	putc ('\n', FILE);						\       }									\   } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|" %| %{fpic:-k} %{fPIC:-k}"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{p:%e`-p' not supported; use `-pg' and gprof(1)} \    %{shared:-Bshareable} \    %{!shared:%{!nostdlib:%{!r:%{!e*:-e start}}} -dc -dp %{static:-Bstatic} \    %{pg:-Bstatic} %{Z}} \    %{assert*} %{R*}"
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{shared:c++rt0.o%s} \    %{!shared:%{pg:gcrt0.o%s}%{!pg:%{static:scrt0.o%s}%{!static:crt0.o%s}}}"
end_define

begin_comment
comment|/* Define this so we can compile MS code for use with WINE.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
end_define

begin_comment
comment|/* FreeBSD 2.2.7's assembler does not support .quad properly.  Do not    use it.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_QUAD
end_undef

end_unit

