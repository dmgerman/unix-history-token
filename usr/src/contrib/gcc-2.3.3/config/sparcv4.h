begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Sparc running System V.4    Copyright (C) 1991, 1992 Free Software Foundation, Inc.     Written by Ron Guilmette (rfg@ncd.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"sparc.h"
end_include

begin_comment
comment|/* Undefine some symbols which are defined in "sparc.h" but which are    appropriate only for SunOS 4.x, and not for svr4.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

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

begin_include
include|#
directive|include
file|"svr4.h"
end_include

begin_comment
comment|/* Undefined some symbols which are defined in "svr4.h" but which are    appropriate only for typical svr4 systems, but not for the specific    case of svr4 running on a Sparc.  */
end_comment

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

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|CONST_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|TYPE_OPERAND_FMT
end_undef

begin_undef
undef|#
directive|undef
name|PUSHSECTION_FORMAT
end_undef

begin_undef
undef|#
directive|undef
name|STRING_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|COMMON_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SKIP_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_comment
comment|/* Has no equivalent.  See ASM_OUTPUT_DEF below.  */
end_comment

begin_comment
comment|/* Provide a set of pre-definitions and pre-assertions appropriate for    the Sparc running svr4.  __svr4__ is our extension.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Dsparc -Dunix -D__svr4__ -Asystem(unix) -Acpu(sparc) -Amachine(sparc)"
end_define

begin_comment
comment|/* The specialized code which needs to appear in the .init section prior    to the prologue code for `__do_global_ctors' (see crtstuff.c).     On Sparcs running svr4, the /usr/ccs/lib/crti.o file (with gets linked    in prior to the crtbegin.o file) has a single `save' instruction in its    .init section.  That `save' instruction tries to setup a stack frame for    the sake of any subsequent code in the .init section.  Unfortunately,    the size it uses for the stack frame is only a guess, and is not really    adequate for our purposes.  More importantly, we independently put our    own standard function prologue (for __do_global_ctors) into the .init    section and that function prologue includes its own `save' instruction!    Thus, unless we do something to correct the situation, we'll get *two*    stack frames allocated when crt0.o calls the code in the .init section,    and havoc will ensue.  The following macro definition prevents such woes. */
end_comment

begin_define
define|#
directive|define
name|INIT_SECTION_PREAMBLE
value|asm ("restore")
end_define

begin_comment
comment|/* This is the string used to begin an assembly language comment for the    Sparc/svr4 assembler.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"!"
end_define

begin_comment
comment|/* Define the names of various pseudo-op used by the Sparc/svr4 assembler.    Note that many of these are different from the typical pseudo-ops used    by most svr4 assemblers.  That is probably due to a (misguided?) attempt    to keep the Sparc/svr4 assembler somewhat compatible with the Sparc/SunOS    assembler.  */
end_comment

begin_define
define|#
directive|define
name|STRING_ASM_OP
value|".asciz"
end_define

begin_define
define|#
directive|define
name|COMMON_ASM_OP
value|".common"
end_define

begin_define
define|#
directive|define
name|SKIP_ASM_OP
value|".skip"
end_define

begin_define
define|#
directive|define
name|UNALIGNED_INT_ASM_OP
value|".uaword"
end_define

begin_define
define|#
directive|define
name|UNALIGNED_SHORT_ASM_OP
value|".uahalf"
end_define

begin_define
define|#
directive|define
name|PUSHSECTION_ASM_OP
value|".pushsection"
end_define

begin_define
define|#
directive|define
name|POPSECTION_ASM_OP
value|".popsection"
end_define

begin_comment
comment|/* This is the format used to print the second operand of a .type pseudo-op    for the Sparc/svr4 assembler.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|"#%s"
end_define

begin_comment
comment|/* This is the format used to print a .pushsection pseudo-op (and its operand)    for the Sparc/svr4 assembler.  */
end_comment

begin_define
define|#
directive|define
name|PUSHSECTION_FORMAT
value|"\t%s\t\"%s\"\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CASE_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|JUMPTABLE
parameter_list|)
define|\
value|do { ASM_OUTPUT_ALIGN ((FILE), 2);					\      ASM_OUTPUT_INTERNAL_LABEL ((FILE), PREFIX, NUM);			\    } while (0)
end_define

begin_comment
comment|/* This is how to equate one symbol to another symbol.  The syntax used is    `SYM1=SYM2'.  Note that this is different from the way equates are done    with most svr4 assemblers, where the syntax is `.set SYM1,SYM2'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|LABEL1
parameter_list|,
name|LABEL2
parameter_list|)
define|\
value|do {	fprintf ((FILE), "\t");						\ 	assemble_name (FILE, LABEL1);					\ 	fprintf (FILE, " = ");						\ 	assemble_name (FILE, LABEL2);					\ 	fprintf (FILE, "\n");						\   } while (0)
end_define

begin_comment
comment|/* Define how the Sparc registers should be numbered for Dwarf output.    The numbering provided here should be compatible with the native    svr4 SDB debugger in the Sparc/svr4 reference port.  The numbering    is as follows:     Assembly name	gcc internal regno	Dwarf regno    ----------------------------------------------------------    g0-g7		0-7			0-7    o0-o7		8-15			8-15    l0-l7		16-23			16-23    i0-i7		24-31			24-31    f0-f31		32-63			40-71 */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO)< 32) ? (REGNO)						\    : ((REGNO)< 63) ? ((REGNO) + 8)					\    : (abort (), 0))
end_define

begin_comment
comment|/* A set of symbol definitions for assembly pseudo-ops which will    get us switched to various sections of interest.  These are used    in all places where we simply want to switch to a section, and    *not* to push the previous section name onto the assembler's    section names stack (as we do often in dwarfout.c).  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".section\t\".text\""
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".section\t\".data\""
end_define

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|".section\t\".bss\""
end_define

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP
value|".section\t\".rodata\""
end_define

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|".section\t\".init\",#alloc"
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".section\t\".ctors\",#alloc"
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|".section\t\".dtors\",#alloc"
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
comment|/* This is how to output assembly code to define a `float' constant.    We always have to use a .long pseudo-op to do this because the native    SVR4 ELF assembler is buggy and it generates incorrect values when we    try to use the .float pseudo-op instead.  */
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
value|do { long value;							\      REAL_VALUE_TO_TARGET_SINGLE ((VALUE), value);			\      fprintf((FILE), "\t.long\t0x%x\n", value);				\    } while (0)
end_define

begin_comment
comment|/* This is how to output assembly code to define a `double' constant.    We always have to use a pair of .long pseudo-ops to do this because    the native SVR4 ELF assembler is buggy and it generates incorrect    values when we try to use the the .double pseudo-op instead.  */
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
value|do { long value[2];							\      REAL_VALUE_TO_TARGET_DOUBLE ((VALUE), value);			\      fprintf((FILE), "\t.long\t0x%x\n", value[0]);			\      fprintf((FILE), "\t.long\t0x%x\n", value[1]);			\    } while (0)
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

end_unit

