begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common configuration file for NetBSD a.out targets.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Wasabi Systems, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This defines which switch letters take arguments. */
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
value|(DEFAULT_SWITCH_TAKES_ARG(CHAR)	\    || (CHAR) == 'R')
end_define

begin_comment
comment|/* Provide an ASM_SPEC appropriate for NetBSD.  Currently we only deal    with the options for generating PIC code.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|" %| %{fpic:-k} %{fPIC:-k -K}"
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for NetBSD a.out.  Here we    provide support for the special GCC option -static.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared:				\      %{pg:gcrt0%O%s}			\      %{!pg:				\        %{p:mcrt0%O%s}			\        %{!p:				\ 	 %{!static:crt0%O%s}		\ 	 %{static:scrt0%O%s}}}}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for NetBSD a.out.  Here we provide    support for the special GCC options -static, -assert, and -nostdlib.  */
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
define|\
value|"%{nostdlib:-nostdlib}		\    %{!shared:				\      %{!nostdlib:			\        %{!r*:				\ 	 %{!e*:-e start}}}		\      -dc -dp				\      %{static:-Bstatic}}		\    %{shared:-Bshareable}		\    %{R*}				\    %{assert*}"
end_define

begin_comment
comment|/* Some imports from svr4.h in support of shared libraries.  */
end_comment

begin_comment
comment|/* Define the strings used for the .type, .size, and .set directives.    These strings generally do not vary from one system running NetBSD    to another, but if a given system needs to use different pseudo-op    names for these, they may be overridden in the file included after    this one.  */
end_comment

begin_undef
undef|#
directive|undef
name|TYPE_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SIZE_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

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

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set\t"
end_define

begin_comment
comment|/* This is how we tell the assembler that a symbol is weak.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_WEAKEN_LABEL
end_undef

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
value|do 									\     {									\       fputs ("\t.globl\t", FILE); assemble_name (FILE, NAME);		\       fputc ('\n', FILE);						\       fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME);		\       fputc ('\n', FILE);						\     }									\   while (0)
end_define

begin_comment
comment|/* The following macro defines the format used to output the second    operand of the .type assembler directive.  Different svr4 assemblers    expect various different forms of this operand.  The one given here    is just a default.  You may need to override it in your machine-    specific tm.h file (depending on the particulars of your assembler).  */
end_comment

begin_undef
undef|#
directive|undef
name|TYPE_OPERAND_FMT
end_undef

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
comment|/* These macros generate the special .type and .size directives which    are used to set the corresponding fields of the linker symbol table    entries in an ELF object file under SVR4 (and a.out on NetBSD).    These macros also output the starting labels for the relevant    functions/objects.  */
end_comment

begin_comment
comment|/* Write the extra assembler code needed to declare a function properly.    Some svr4 assemblers need to also have something extra said about the    function's return value.  We allow for that here.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

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
value|do									\     {									\       fprintf (FILE, "%s", TYPE_ASM_OP);				\       assemble_name (FILE, NAME);					\       putc (',', FILE);							\       fprintf (FILE, TYPE_OPERAND_FMT, "function");			\       putc ('\n', FILE);						\       ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\       ASM_OUTPUT_LABEL(FILE, NAME);					\     }									\   while (0)
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare an object properly.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

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
value|do									\     {									\       fprintf (FILE, "%s", TYPE_ASM_OP);				\       assemble_name (FILE, NAME);					\       putc (',', FILE);							\       fprintf (FILE, TYPE_OPERAND_FMT, "object");			\       putc ('\n', FILE);						\       size_directive_output = 0;					\       if (!flag_inhibit_size_directive&& DECL_SIZE (DECL))		\ 	{								\ 	  size_directive_output = 1;					\ 	  fprintf (FILE, "%s", SIZE_ASM_OP);				\ 	  assemble_name (FILE, NAME);					\ 	  fprintf (FILE, ",%d\n",					\ 	           int_size_in_bytes (TREE_TYPE (DECL)));		\ 	}								\       ASM_OUTPUT_LABEL(FILE, NAME);					\     }									\   while (0)
end_define

begin_comment
comment|/* Output the size directive for a decl in rest_of_decl_compilation    in the case where we did not do so before the initializer.    Once we find the error_mark_node, we know that the value of    size_directive_output was set    by ASM_DECLARE_OBJECT_NAME when it was run for the same decl.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FINISH_DECLARE_OBJECT
end_undef

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
value|do									\     {									\       const char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);		\       if (!flag_inhibit_size_directive&& DECL_SIZE (DECL)		\&& ! AT_END&& TOP_LEVEL					\&& DECL_INITIAL (DECL) == error_mark_node			\&& !size_directive_output)					\ 	{								\ 	  size_directive_output = 1;					\ 	  fprintf (FILE, "%s", SIZE_ASM_OP);				\ 	  assemble_name (FILE, name);					\ 	  fprintf (FILE, ",%d\n",					\ 		   int_size_in_bytes (TREE_TYPE (DECL)));		\ 	}								\     }									\   while (0)
end_define

begin_comment
comment|/* This is how to declare the size of a function.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_SIZE
end_undef

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
value|do									\     {									\       if (!flag_inhibit_size_directive)					\ 	{								\ 	  char label[256];						\ 	  static int labelno;						\ 	  labelno++;							\ 	  ASM_GENERATE_INTERNAL_LABEL (label, "Lfe", labelno);		\ 	  ASM_OUTPUT_INTERNAL_LABEL (FILE, "Lfe", labelno);		\ 	  fprintf (FILE, "%s", SIZE_ASM_OP);				\ 	  assemble_name (FILE, (FNAME));				\ 	  fprintf (FILE, ",");						\ 	  assemble_name (FILE, label);					\ 	  fprintf (FILE, "-");						\ 	  assemble_name (FILE, (FNAME));				\ 	  putc ('\n', FILE);						\ 	}								\     }									\   while (0)
end_define

end_unit

