begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for SPARC running Solaris 2    Copyright 1992 Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@ncd.com) and    David V. Henkel-Wallace (gumby@cygnus.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Supposedly the same as vanilla sparc svr4, except for the stuff below: */
end_comment

begin_include
include|#
directive|include
file|"sparcv4.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Dsun -Dsparc -Dunix -D__svr4__ -Asystem(unix) -Acpu(sparc) -Amachine(sparc)"
end_define

begin_comment
comment|/* The sun bundled assembler doesn't accept -Yd, (and neither does gas).    It's safe to pass -s always, even if -g is not used. */
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
define|\
value|"%{V} %{v:%{!V:-V}} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Wa,*:%*} -s \    %{fpic:-K PIC} %{fPIC:-K PIC}"
end_define

begin_comment
comment|/* However it appears that Solaris 2.0 uses the same reg numbering as    the old BSD-style system did. */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_comment
comment|/* Same as sparc.h */
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
comment|/* We use stabs-in-elf for debugging, because that is what the native    toolchain uses.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_define
define|#
directive|define
name|DBX_BLOCKS_FUNCTION_RELATIVE
value|1
end_define

begin_comment
comment|/* "gcc2_compiled." must be a .stabs, not an ordinary symbol, or GDB won't    see it.  Furthermore, since GDB reads the input piecemeal, starting    with each N_SO, it's a lot easier if the gcc2 flag symbol is *after*    the N_SO rather than before it.  So we emit an N_OPT stab here.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_comment
comment|/* Do nothing */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC_AFTER_SOURCE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fputs ("\t.stabs\t\"gcc2_compiled.\", 0x3c, 0, 0, 0\n", FILE)
end_define

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* These seems unnecessary; the ones in sparcv4.h look right.  */
end_comment

begin_undef
undef|#
directive|undef
name|TEXT_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|DATA_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|BSS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|CONST_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.section\t\".text\""
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.section\t\".data\""
end_define

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t\".bss\""
end_define

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP
value|"\t.section\t\".rodata\""
end_define

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section\t\".init\""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\t.section\t\".ctors\",#alloc,#execinstr\n"
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\t.section\t\".dtors\",#alloc,#execinstr\n"
end_define

begin_comment
comment|/* The native assembler can't compute differences between symbols in different    sections when generating pic code, so we must put jump tables in the    text section.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|1
end_define

begin_comment
comment|/* Must use data section for relocatable constants when pic.  */
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
parameter_list|)
define|\
value|{						\   if (flag_pic&& symbolic_operand (RTX))	\     data_section ();				\   else						\     const_section ();				\ }
end_define

begin_comment
comment|/* The Solaris 2 assembler uses .skip, not .zero, so put this back. */
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
value|fprintf (FILE, "\t.skip %u\n", (SIZE))
end_define

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
value|do {									\   fputs ("\t.local\t", (FILE));		\   assemble_name ((FILE), (NAME));					\   putc ('\n', (FILE));							\   ASM_OUTPUT_ALIGNED_COMMON (FILE, NAME, SIZE, ALIGN);			\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|COMMON_ASM_OP
end_undef

begin_define
define|#
directive|define
name|COMMON_ASM_OP
value|"\t.common"
end_define

begin_comment
comment|/* This is how to output a definition of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
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
value|fprintf (FILE, ".L%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output a reference to an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, ".L%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
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
value|sprintf (LABEL, "*.L%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* in Solaris 2.0, linenos are relative to the current fn. */
end_comment

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
value|{ static int sym_lineno = 1;				\     fprintf (file, ".stabn 68,0,%d,.LM%d-%s\n.LM%d:\n",	\ 	     line, sym_lineno, 				\ 	     IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (current_function_decl)),\ 	     sym_lineno);				\     sym_lineno += 1; }
end_define

begin_comment
comment|/* But, to make this work, we have to output the stabs for the function    name *first*...  */
end_comment

begin_define
define|#
directive|define
name|DBX_FUNCTION_FIRST
end_define

begin_escape
end_escape

begin_comment
comment|/* We don't use the standard svr4 STARTFILE_SPEC because it's wrong for us.    We don't use the standard LIB_SPEC only because we don't yet support c++ */
end_comment

begin_comment
comment|/* If we cannot find the GNU *crt*.o files in the STANDARD_STARTFILE_PREFIX    directory, our fallback strategy must be to look for these files instead    in the Sun C 2.0 directory.  */
end_comment

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/opt/SUNWspro/SC2.0/"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{!shared: \ 			 %{!symbolic: \ 			  %{pg:crt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}} \ 			  %{pg:gmon.o%s} \ 			  %{pg:crti.o%s}%{!pg:crti.o%s} \ 			  %{ansi:/usr/ccs/lib/values-Xc.o%s} \ 			  %{!ansi: \ 			   %{traditional:/usr/ccs/lib/values-Xt.o%s} \ 			   %{!traditional:/usr/ccs/lib/values-Xa.o%s}}}} \ 			  crtbegin.o%s"
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{!shared:%{!symbolic:-lc}} \   crtend.o%s \   %{!shared:%{!symbolic:%{pg:crtn.o%s}%{!pg:crtn.o%s}}}"
end_define

begin_comment
comment|/* This should be the same as in svr4.h, except with -R added.  */
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
value|"%{h*} %{V} %{v:%{!V:-V}} \ 		   %{b} %{Wl,*:%*} \ 		   %{static:-dn -Bstatic} \ 		   %{shared:-G -dy} \ 		   %{symbolic:-Bsymbolic -G -dy} \ 		   %{G:-G} \ 		   %{YP,*} \ 		   %{R*} \ 		   %{!YP,*:%{p:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \ 		    %{!p:-Y P,/usr/ccs/lib:/usr/lib}} \ 		   %{Qy:} %{!Qn:-Qy}"
end_define

begin_comment
comment|/* This defines which switch letters take arguments.    It is as in svr4.h but with -R added.  */
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
value|(   (CHAR) == 'D' \    || (CHAR) == 'U' \    || (CHAR) == 'o' \    || (CHAR) == 'e' \    || (CHAR) == 'u' \    || (CHAR) == 'I' \    || (CHAR) == 'm' \    || (CHAR) == 'L' \    || (CHAR) == 'R' \    || (CHAR) == 'A' \    || (CHAR) == 'h' \    || (CHAR) == 'z')
end_define

end_unit

