begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel x86 CPU running NeXTSTEP    Copyright (C) 1993, 1995, 1996, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/gas.h"
end_include

begin_include
include|#
directive|include
file|"nextstep.h"
end_include

begin_comment
comment|/* By default, target has a 80387, with IEEE FP.  */
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
value|(MASK_80387 | MASK_IEEE_FP)
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Machines that use the AT&T assembler syntax    also return floating point values in an FP register.    Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_undef
undef|#
directive|undef
name|VALUE_REGNO
end_undef

begin_define
define|#
directive|define
name|VALUE_REGNO
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == SFmode || (MODE) == DFmode || (MODE) == XFmode	\    ? FIRST_FLOAT_REG : 0)
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value. */
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
value|((N) == 0 || (N)== FIRST_FLOAT_REG)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_VALUE_TO_TARGET_LONG_DOUBLE
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LONG_DOUBLE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LONG_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do {									\     long hex[3];							\     REAL_VALUE_TO_TARGET_LONG_DOUBLE (VALUE, hex);			\     if (sizeof (int) == sizeof (long))					\       fprintf (FILE, "\t.long 0x%x\n\t.long 0x%x\n\t.long 0x%x\n",	\ 		hex[0], hex[1], hex[2]);				\     else								\       fprintf (FILE, "\t.long 0x%lx\n\t.long 0x%lx\n\t.long 0x%lx\n",	\ 		hex[0], hex[1], hex[2]);				\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_VALUE_TO_TARGET_DOUBLE
end_ifdef

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
value|do {									\     long hex[2];							\     REAL_VALUE_TO_TARGET_DOUBLE (VALUE, hex);				\     if (sizeof (int) == sizeof (long))					\       fprintf (FILE, "\t.long 0x%x\n\t.long 0x%x\n", hex[0], hex[1]);	\     else								\       fprintf (FILE, "\t.long 0x%lx\n\t.long 0x%lx\n", hex[0], hex[1]);	\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_VALUE_TO_TARGET_SINGLE
end_ifdef

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
value|do {									\     long hex;								\     REAL_VALUE_TO_TARGET_SINGLE (VALUE, hex);				\     if (sizeof (int) == sizeof (long))					\       fprintf (FILE, "\t.long 0x%x\n", hex);				\     else								\       fprintf (FILE, "\t.long 0x%lx\n", hex);				\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A C statement or statements which output an assembler instruction    opcode to the stdio stream STREAM.  The macro-operand PTR is a    variable of type `char *' which points to the opcode name in its    "internal" form--the form that is written in the machine description.     GAS version 1.38.1 doesn't understand the `repz' opcode mnemonic.    So use `repe' instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_OPCODE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|STREAM
parameter_list|,
name|PTR
parameter_list|)
define|\
value|{							\   if ((PTR)[0] == 'r'					\&& (PTR)[1] == 'e'				\&& (PTR)[2] == 'p')				\     {							\       if ((PTR)[3] == 'z')				\ 	{						\ 	  fprintf (STREAM, "repe");			\ 	  (PTR) += 4;					\ 	}						\       else if ((PTR)[3] == 'n'&& (PTR)[4] == 'z')	\ 	{						\ 	  fprintf (STREAM, "repne");			\ 	  (PTR) += 5;					\ 	}						\     }							\ }
end_define

begin_comment
comment|/* Define macro used to output shift-double opcodes when the shift    count is in %cl.  Some assemblers require %cl as an argument;    some don't.     GAS requires the %cl argument, so override unx386.h. */
end_comment

begin_undef
undef|#
directive|undef
name|SHIFT_DOUBLE_OMITS_COUNT
end_undef

begin_define
define|#
directive|define
name|SHIFT_DOUBLE_OMITS_COUNT
value|0
end_define

begin_comment
comment|/* Print opcodes the way that GAS expects them. */
end_comment

begin_define
define|#
directive|define
name|GAS_MNEMONICS
value|1
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
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
value|"-Di386 -DNeXT -Dunix -D__MACH__ -D__LITTLE_ENDIAN__ -D__ARCHITECTURE__=\"i386\" -Asystem(unix) -Asystem(mach) -Acpu(i386) -Amachine(i386)"
end_define

begin_comment
comment|/* This accounts for the return pc and saved fp on the i386. */
end_comment

begin_define
define|#
directive|define
name|OBJC_FORWARDING_STACK_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|OBJC_FORWARDING_MIN_OFFSET
value|8
end_define

begin_comment
comment|/* We do not want a dot in internal labels.  */
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
value|"L"
end_define

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
value|sprintf ((BUF), "*%s%d", (PREFIX), (NUMBER))
end_define

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
value|fprintf (FILE, "%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

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

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

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

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_PUSH
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tpushl %se%s\n", "%", reg_names[REGNO])
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_POP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tpopl %se%s\n", "%", reg_names[REGNO])
end_define

begin_comment
comment|/* This is being overridden because the default i386 configuration    generates calls to "_mcount".  NeXT system libraries all use    "mcount".  */
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
value|{									\   if (flag_pic)								\     {									\       fprintf (FILE, "\tleal %sP%d@GOTOFF(%%ebx),%%edx\n",		\                LPREFIX, (LABELNO));					\       fprintf (FILE, "\tcall *mcount@GOT(%%ebx)\n");			\     }									\   else									\     {								  	\       fprintf (FILE, "\tmovl $%sP%d,%%edx\n", LPREFIX, (LABELNO));	\       fprintf (FILE, "\tcall mcount\n");				\     }									\ }
end_define

begin_comment
comment|/* BEGIN Calling Convention CHANGES */
end_comment

begin_comment
comment|/* These changes violate the Intel/Unix ABI.  Specifically, they    change the way that space for a block return value is passed to a    function.  The ABI says that the pointer is passed on the stack.    We change to pass the pointer in %ebx.  This makes the NeXT    Objective-C forwarding mechanism possible to implement on an i386.  */
end_comment

begin_comment
comment|/* Do NOT pass address of structure values on the stack.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRUCT_VALUE_INCOMING
end_undef

begin_undef
undef|#
directive|undef
name|STRUCT_VALUE
end_undef

begin_comment
comment|/* Pass them in %ebx.  */
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
value|3
end_define

begin_comment
comment|/* Because we are passing the pointer in a register, we don't need to    rely on the callee to pop it.  */
end_comment

begin_undef
undef|#
directive|undef
name|RETURN_POPS_ARGS
end_undef

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNDECL
parameter_list|,
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|((FUNDECL)&& TREE_CODE (FUNDECL) == IDENTIFIER_NODE		\    ? 0								\    : (TARGET_RTD						\&& (TYPE_ARG_TYPES (FUNTYPE) == 0				\           || (TREE_VALUE (tree_last (TYPE_ARG_TYPES (FUNTYPE)))	\               == void_type_node))) ? (SIZE) : 0)
end_define

begin_comment
comment|/* END Calling Convention CHANGES */
end_comment

begin_comment
comment|/* NeXT still uses old binutils that don't insert nops by default    when the .align directive demands to insert extra space in the text    segment.  */
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

end_unit

