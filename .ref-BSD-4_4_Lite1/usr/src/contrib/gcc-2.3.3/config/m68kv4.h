begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for mc680x0 running System V.4    Copyright (C) 1991 Free Software Foundation, Inc.     Written by Ron Guilmette (rfg@ncd.com) and Fred Fish (fnf@cygnus.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Use SGS_* macros to control compilation in m68k.md */
end_comment

begin_define
define|#
directive|define
name|SGS_SWITCH_TABLES
end_define

begin_comment
comment|/* Different switch table handling */
end_comment

begin_include
include|#
directive|include
file|"m68ksgs.h"
end_include

begin_comment
comment|/* The m68k/SVR4 assembler is SGS based */
end_comment

begin_include
include|#
directive|include
file|"svr4.h"
end_include

begin_comment
comment|/* Pick up the generic SVR4 macros */
end_comment

begin_comment
comment|/* See m68k.h.  7 means 68020 with 68881.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(5
comment|/*68020*/
value|+ 2
comment|/*68881*/
value|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  Override the definition of NO_DOLLAR_IN_LABEL in svr4.h, for special     g++ assembler names.  When this is defined, g++ uses embedded '.'     characters and some m68k assemblers have problems with this.  The     chances are much greater that any particular assembler will permit     embedded '$' characters. */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_comment
comment|/* Define PCC_STATIC_STRUCT_RETURN if the convention on the target machine    is to use the nonreentrant technique for returning structure and union    values, as commonly implemented by the AT&T Portable C Compiler (PCC).    When defined, the gcc option -fpcc-struct-return can be used to cause    this form to be generated.  When undefined, the option does nothing.    For m68k SVR4, the convention is to use a reentrant technique compatible    with the gcc default, so override the definition of this macro in m68k.h */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_STATIC_STRUCT_RETURN
end_undef

begin_comment
comment|/* Provide a set of pre-definitions and pre-assertions appropriate for    the m68k running svr4.  __svr4__ is our extension.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Dm68k -Dunix -D__svr4__ -Asystem(unix) -Acpu(m68k) -Amachine(m68k)"
end_define

begin_comment
comment|/* Test to see if the target includes a 68881 by default, and use CPP_SPEC    to control whether or not __HAVE_68881__ is defined by default or not.    If a 68881 is the default, gcc will use inline 68881 instructions, by    predefining __HAVE_68881__, unless -msoft-float is specified.    If a 68881 is not the default, gcc will only define __HAVE_68881__ if    -m68881 is specified. */
end_comment

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|2
end_if

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!msoft-float:-D__HAVE_68881__}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m68881:-D__HAVE_68881__}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  We override the definition in m68k.h    and match the way the native m68k/SVR4 compiler does profiling, with the    address of the profile counter in a1, not a0, and using bsr rather    than jsr. */
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
value|asm_fprintf ((FILE), "\tlea.l\t(%LLP%d,%Rpc),%Ra1\n\tbsr\t_mcount\n", \ 	       (LABELNO))
end_define

begin_comment
comment|/* Local common symbols are declared to the assembler with ".lcomm" rather    than ".bss", so override the definition in svr4.h */
end_comment

begin_undef
undef|#
directive|undef
name|BSS_ASM_OP
end_undef

begin_define
define|#
directive|define
name|BSS_ASM_OP
value|".lcomm"
end_define

begin_comment
comment|/* Register in which address to store a structure value is passed to a    function.  The default in m68k.h is a1.  For m68k/SVR4 it is a0. */
end_comment

begin_undef
undef|#
directive|undef
name|STRUCT_VALUE_REGNUM
end_undef

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|8
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
value|"@%s"
end_define

begin_comment
comment|/* Define how the m68k registers should be numbered for Dwarf output.    The numbering provided here should be compatible with the native    SVR4 SDB debugger in the m68k/SVR4 reference port, where d0-d7    are 0-7, a0-a8 are 8-15, and fp0-fp7 are 16-23. */
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
comment|/* The ASM_OUTPUT_SKIP macro is first defined in m68k.h, using ".skip".    It is then overridden by m68ksgs.h to use ".space", and again by svr4.h    to use ".zero".  The m68k/SVR4 assembler uses ".space", so repeat the    definition from m68ksgs.h here.  Note that ASM_NO_SKIP_IN_TEXT is    defined in m68ksgs.h, so we don't have to repeat it here. */
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
value|fprintf (FILE, "\t%s %u\n", SPACE_ASM_OP, (SIZE))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    For m68k/SVR4 allow d0, a0, or fp0 as return registers, for integral,    pointer, or floating types, respectively. Reject fp0 if not using a    68881 coprocessor. */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_VALUE_REGNO_P
end_undef

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((N) == 0 || (N) == 8 || (TARGET_68881&& (N) == 16))
end_define

begin_comment
comment|/* Define how to generate (in the callee) the output value of a function    and how to find (in the caller) the value returned by a function.  VALTYPE    is the data type of the value (as a tree).  If the precise function being    called is known, FUNC is its FUNCTION_DECL; otherwise, FUNC is 0.    For m68k/SVR4 generate the result in d0, a0, or fp0 as appropriate. */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_VALUE
end_undef

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|(TREE_CODE (VALTYPE) == REAL_TYPE&& TARGET_68881			\    ? gen_rtx (REG, TYPE_MODE (VALTYPE), 16)				\    : (TREE_CODE (VALTYPE) == POINTER_TYPE				\       ? gen_rtx (REG, TYPE_MODE (VALTYPE), 8)				\       : gen_rtx (REG, TYPE_MODE (VALTYPE), 0)))
end_define

begin_comment
comment|/* For compatibility with the large body of existing code which does not    always properly declare external functions returning pointer types, the    m68k/SVR4 convention is to copy the value returned for pointer functions    from a0 to d0 in the function epilogue, so that callers that have    neglected to properly declare the callee can still find the correct return    value. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_pointer
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FUNCTION_EXTRA_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|do {									\   if ((current_function_returns_pointer)&& 				\       ! find_equiv_reg (0, get_last_insn (), 0, 0, 0, 8, Pmode))	\     asm_fprintf (FILE, "\tmov.l %Ra0,%Rd0\n");				\ } while (0);
end_define

begin_comment
comment|/* Define how to find the value returned by a library function assuming the    value has mode MODE.    For m68k/SVR4 look for integer values in d0, pointer values in d0    (returned in both d0 and a0), and floating values in fp0. */
end_comment

begin_undef
undef|#
directive|undef
name|LIBCALL_VALUE
end_undef

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(((MODE) == SFmode || (MODE) == DFmode)&& TARGET_68881		\    ? gen_rtx (REG, (MODE), 16)						\    : gen_rtx (REG, (MODE), 0))
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.    The m68k/SVR4 convention is to keep the stack pointer longword aligned. */
end_comment

begin_undef
undef|#
directive|undef
name|STACK_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|32
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure.    For m68k/SVR4, this is the next longword boundary. */
end_comment

begin_undef
undef|#
directive|undef
name|EMPTY_FIELD_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.    For m68k/SVR4, some types (doubles for example) are aligned on 8 byte    boundaries */
end_comment

begin_undef
undef|#
directive|undef
name|BIGGEST_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|64
end_define

begin_comment
comment|/* SVR4 m68k assembler is bitching on the `comm i,1,1' which askes for     1 byte alignment. Don't generate alignment for COMMON seems to be    safer until we the assembler is fixed. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_COMMON
end_undef

begin_comment
comment|/* Same problem with this one.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_undef

begin_comment
comment|/* The `string' directive on m68k svr4 does not handle string with    escape char (ie., `\') right. Use normal way to output ASCII bytes    seems to be safer. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|PTR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|{								\   register int sp = 0, lp = 0, ch;				\   fprintf ((FILE), "\t%s ", BYTE_ASM_OP);			\   do {								\     ch = (PTR)[sp];						\     if (ch> ' '&& ! (ch& 0x80)&& ch != '\\')		\       {								\ 	fprintf ((FILE), "'%c", ch);				\       }								\     else							\       {								\ 	fprintf ((FILE), "0x%x", ch);				\       }								\     if (++sp< (LEN))						\       {								\ 	if ((sp % 10) == 0)					\ 	  {							\ 	    fprintf ((FILE), "\n\t%s ", BYTE_ASM_OP);		\ 	  }							\ 	else							\ 	  {							\ 	    putc (',', (FILE));					\ 	  }							\       }								\   } while (sp< (LEN));						\   putc ('\n', (FILE));						\ }
end_define

begin_comment
comment|/* SVR4 m68k assembler is bitching on the syntax `2.b'.    So use the "LLDnnn-LLnnn" format.  Define LLDnnn after the table.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CASE_END
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_END
parameter_list|(
name|FILE
parameter_list|,
name|NUM
parameter_list|,
name|TABLE
parameter_list|)
define|\
value|do {									\   if (switch_table_difference_label_flag)				\     asm_fprintf ((FILE), "\t%s %LLD%d,%LL%d\n", SET_ASM_OP, (NUM), (NUM));\   switch_table_difference_label_flag = 0;				\ } while (0)
end_define

begin_decl_stmt
name|int
name|switch_table_difference_label_flag
decl_stmt|;
end_decl_stmt

end_unit

