begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Intel 386 (OSF/1 with OSF/rose) version.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Put leading underscores in front of names. */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|"halfpic.h"
end_include

begin_include
include|#
directive|include
file|"i386gstabs.h"
end_include

begin_define
define|#
directive|define
name|OSF_OS
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
value|(!strcmp (STR, "Tdata") || !strcmp (STR, "Ttext")			\   || !strcmp (STR, "Tbss") || !strcmp (STR, "include")			\   || !strcmp (STR, "imacros") || !strcmp (STR, "aux-info")		\   || !strcmp (STR, "pic-names"))
end_define

begin_define
define|#
directive|define
name|MASK_HALF_PIC
value|0x40000000
end_define

begin_comment
comment|/* Mask for half-pic code */
end_comment

begin_define
define|#
directive|define
name|MASK_HALF_PIC_DEBUG
value|0x20000000
end_define

begin_comment
comment|/* Debug flag */
end_comment

begin_define
define|#
directive|define
name|TARGET_HALF_PIC
value|(target_flags& MASK_HALF_PIC)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG
value|(target_flags& MASK_HALF_PIC_DEBUG)
end_define

begin_define
define|#
directive|define
name|HALF_PIC_DEBUG
value|TARGET_DEBUG
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
value|{ "half-pic",	 MASK_HALF_PIC},				\      { "no-half-pic",	-MASK_HALF_PIC},				\      { "debugb",	 MASK_HALF_PIC_DEBUG},
end_define

begin_comment
comment|/* Prefix that appears before all global/static identifiers, except for    temporary labels.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_PREFIX
value|"_"
end_define

begin_comment
comment|/* Suffix that appears after all global/static identifiers, except for    temporary labels.  */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIER_SUFFIX
value|""
end_define

begin_comment
comment|/* Change default predefines.  */
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
value|"-DOSF -DOSF1 -Dunix -Di386"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{.S:	-D__LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY}} \ %{.cc:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.cxx:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.C:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.m:	-D__LANGUAGE_OBJECTIVE_C} \ %{!.S:	-D__LANGUAGE_C %{!ansi:-DLANGUAGE_C}}"
end_define

begin_comment
comment|/* Turn on -mpic-extern by default.  */
end_comment

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{gline:%{!g:%{!g0:%{!g1:%{!g2: -g1}}}}} \ %{pic-none:   -mno-half-pic} \ %{pic-lib:    -mhalf-pic} \ %{pic-extern: -mhalf-pic} \ %{pic-calls:  -mhalf-pic} \ %{pic-names*: -mhalf-pic} \ %{!pic-*:     -mhalf-pic}"
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
value|""
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{v*: -v}                           \ 	               %{!noshrlib: %{pic-none: -noshrlib} %{!pic-none: -warn_nopic}} \ 	               %{nostdlib} %{noshrlib} %{glue}"
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
value|"-lc"
end_define

begin_undef
undef|#
directive|undef
name|LIBG_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBG_SPEC
value|""
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
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION_INTERNAL
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|I386_VERSION
value|" 80386, OSF/rose objects"
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION_INTERNAL
parameter_list|(
name|STREAM
parameter_list|)
value|fputs (I386_VERSION, STREAM)
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION
value|TARGET_VERSION_INTERNAL (stderr)
end_define

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/ccs/gcc/"
end_define

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/ccs/lib/"
end_define

begin_comment
comment|/* Specify size_t, ptrdiff_t, and wchar_t types.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Tell final.c we don't need a label passed to mcount.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_DATA
end_define

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
value|fprintf (FILE, "\tcall _mcount\n")
end_define

begin_comment
comment|/* Some machines may desire to change what optimizations are    performed for various optimization levels.   This macro, if    defined, is executed once just after the optimization level is    determined and before the remainder of the command options have    been parsed.  Values set in this macro are used as the default    values for the other command line options.     LEVEL is the optimization level specified; 2 if -O2 is    specified, 1 if -O is specified, and 0 if neither is specified.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|)
define|\
value|{									\   flag_gnu_linker = FALSE;						\ 									\   if (LEVEL>= 3)							\     flag_inline_functions = TRUE;					\ }
end_define

begin_comment
comment|/* A C expression that is 1 if the RTX X is a constant which is a    valid address.  On most machines, this can be defined as    `CONSTANT_P (X)', but a few machines are more restrictive in    which constant addresses are supported.     `CONSTANT_P' accepts integer-values expressions whose values are    not explicitly known, such as `symbol_ref', `label_ref', and    `high' expressions and `const' arithmetic expressions, in    addition to `const_int' and `const_double' expressions.  */
end_comment

begin_undef
undef|#
directive|undef
name|CONSTANT_ADDRESS_P
end_undef

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(CONSTANT_P (X)&& (!HALF_PIC_P () || !HALF_PIC_ADDRESS_P (X)))
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */
end_comment

begin_undef
undef|#
directive|undef
name|LEGITIMATE_CONSTANT_P
end_undef

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(!HALF_PIC_P ()							\    || GET_CODE (X) == CONST_DOUBLE					\    || GET_CODE (X) == CONST_INT						\    || !HALF_PIC_ADDRESS_P (X))
end_define

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address. */
end_comment

begin_undef
undef|#
directive|undef
name|GO_IF_LEGITIMATE_ADDRESS
end_undef

begin_define
define|#
directive|define
name|GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{									\   if (CONSTANT_P (X))							\     {									\       if (! HALF_PIC_P () || ! HALF_PIC_ADDRESS_P (X))			\ 	goto ADDR;							\     }									\   else									\     {									\       GO_IF_INDEXING (X, ADDR);						\ 									\       if (GET_CODE (X) == PLUS)						\ 	{								\ 	  rtx x1 = XEXP (X, 1);						\ 									\ 	  if (CONSTANT_P (x1))						\ 	    {								\ 	      if (! HALF_PIC_P () || ! HALF_PIC_ADDRESS_P (x1))		\ 		{							\ 		  rtx x0 = XEXP (X, 0);					\ 		  GO_IF_INDEXING (x0, ADDR);				\ 		}							\ 	    }								\ 	}								\     }									\ }
end_define

begin_comment
comment|/* Sometimes certain combinations of command options do not make sense    on a particular target machine.  You can define a macro    `OVERRIDE_OPTIONS' to take account of this.  This macro, if    defined, is executed once just after all the command options have    been parsed.  */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|{									\   if (TARGET_HALF_PIC)							\     half_pic_init ();							\ }
end_define

begin_comment
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     The macro definition, if any, is executed immediately after the    rtl for DECL has been created and stored in `DECL_RTL (DECL)'.     The value of the rtl will be a `mem' whose address is a    `symbol_ref'.     The usual thing for this macro to do is to a flag in the    `symbol_ref' (such as `SYMBOL_REF_FLAG') or to store a modified    name string in the `symbol_ref' (if one bit is not enough    information).     The best way to modify the name string is by adding text to the    beginning, with suitable punctuation to prevent any ambiguity.     Allocate the new name in `saveable_obstack'.  You will have to    modify `ASM_OUTPUT_LABELREF' to remove and decode the added text    and output the name accordingly.     You can also check the information stored in the `symbol_ref' in    the definition of `GO_IF_LEGITIMATE_ADDRESS' or    `PRINT_OPERAND_ADDRESS'. */
end_comment

begin_undef
undef|#
directive|undef
name|ENCODE_SECTION_INFO
end_undef

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|do									\   {									\    if (HALF_PIC_P ())						        \       HALF_PIC_ENCODE (DECL);						\   }									\ while (0)
end_define

begin_comment
comment|/* Given a decl node or constant node, choose the section to output it in    and select that section.  */
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
value|do									\   {									\     if (MODE == Pmode&& HALF_PIC_P ()&& HALF_PIC_ADDRESS_P (RTX))	\       data_section ();							\     else								\       readonly_data_section ();						\   }									\ while (0)
end_define

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|{									\   if (TREE_CODE (DECL) == STRING_CST)					\     {									\       if (flag_writable_strings)					\ 	data_section ();						\       else								\ 	readonly_data_section ();					\     }									\   else if (TREE_CODE (DECL) != VAR_DECL)				\     readonly_data_section ();						\   else if (!TREE_READONLY (DECL))					\     data_section ();							\   else									\     readonly_data_section ();						\ }
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output to the stdio stream    STREAM any text necessary for declaring the name NAME of an    initialized variable which is being defined.  This macro must    output the label definition (perhaps using `ASM_OUTPUT_LABEL').     The argument DECL is the `VAR_DECL' tree node representing the    variable.     If this macro is not defined, then the variable name is defined    in the usual manner as a label (by means of `ASM_OUTPUT_LABEL').  */
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
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do									\  {									\    ASM_OUTPUT_LABEL(STREAM,NAME);                                       \    HALF_PIC_DECLARE (NAME);						\  }									\ while (0)
end_define

begin_comment
comment|/* This is how to declare a function name. */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do									\  {									\    ASM_OUTPUT_LABEL(STREAM,NAME);                                       \    HALF_PIC_DECLARE (NAME);						\  }									\ while (0)
end_define

begin_comment
comment|/* This says what to print at the end of the assembly file */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|do									\   {									\     if (HALF_PIC_P ())							\       HALF_PIC_FINISH (STREAM);						\   }									\ while (0)
end_define

begin_comment
comment|/* Tell collect that the object format is OSF/rose.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ROSE
end_define

begin_comment
comment|/* Tell collect where the appropriate binaries are.  */
end_comment

begin_define
define|#
directive|define
name|REAL_LD_FILE_NAME
value|"/usr/ccs/gcc/gld"
end_define

begin_define
define|#
directive|define
name|REAL_NM_FILE_NAME
value|"/usr/ccs/bin/nm"
end_define

begin_define
define|#
directive|define
name|REAL_STRIP_FILE_NAME
value|"/usr/ccs/bin/strip"
end_define

begin_comment
comment|/* Use atexit for static constructors/destructors, instead of defining    our own exit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Define this macro meaning that gcc should find the library 'libgcc.a'    by hand, rather than passing the argument '-lgcc' to tell the linker    to do the search */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL
end_define

begin_comment
comment|/* A C statement to output assembler commands which will identify the object   file as having been compile with GNU CC. We don't need or want this for   OSF1. GDB doesn't need it and kdb doesn't like it */
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
comment|/* This is how to output an assembler line defining a `double' constant.    Use "word" pseudos to avoid printing NaNs, infinity, etc.  */
end_comment

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do									\   {									\     long value_long[2];							\     REAL_VALUE_TO_TARGET_DOUBLE (VALUE, value_long);			\ 									\     fprintf (STREAM, "\t.long\t0x%08lx\t\t# %.20g\n\t.long\t0x%08lx\n",	\ 	   value_long[0], VALUE, value_long[1]);			\   }									\ while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (STREAM, "\t.double\t%.20g\n", VALUE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do									\   {									\     long value_long;							\     REAL_VALUE_TO_TARGET_SINGLE (VALUE, value_long);			\ 									\     fprintf (STREAM, "\t.long\t0x%08lx\t\t# %.12g (float)\n",		\ 	   value_long, VALUE);						\   }									\ while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (STREAM, "\t.float\t%.12g\n", VALUE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Generate calls to memcpy, etc., not bcopy, etc. */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_escape
end_escape

begin_comment
comment|/* Defines to be able to build libgcc.a with GCC.  */
end_comment

begin_comment
comment|/* It might seem that these are not important, since gcc 2 will never    call libgcc for these functions.  But programs might be linked with    code compiled by gcc 1, and then these will be used.  */
end_comment

begin_define
define|#
directive|define
name|perform_udivsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   dx = 0;								\   ax = a;								\   asm ("divl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (b), "d" (dx));	\   return ax;								\ }
end_define

begin_define
define|#
directive|define
name|perform_divsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   ax = a;								\   asm ("cltd\n\tidivl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (b));	\   return ax;								\ }
end_define

begin_define
define|#
directive|define
name|perform_umodsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   dx = 0;								\   ax = a;								\   asm ("divl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (b), "d" (dx));	\   return dx;								\ }
end_define

begin_define
define|#
directive|define
name|perform_modsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   ax = a;								\   asm ("cltd\n\tidivl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (b));	\   return dx;								\ }
end_define

begin_define
define|#
directive|define
name|perform_fixdfsi
parameter_list|(
name|a
parameter_list|)
define|\
value|{									\   auto unsigned short ostatus;						\   auto unsigned short nstatus;						\   auto int ret;								\   auto double tmp;							\ 									\&ostatus;
comment|/* guarantee these land in memory */
value|\&nstatus;								\&ret;									\&tmp;									\ 									\   asm volatile ("fnstcw %0" : "=m" (ostatus));				\   nstatus = ostatus | 0x0c00;						\   asm volatile ("fldcw %0" :
comment|/* no outputs */
value|: "m" (nstatus));		\   tmp = a;								\   asm volatile ("fldl %0" :
comment|/* no outputs */
value|: "m" (tmp));		\   asm volatile ("fistpl %0" : "=m" (ret));				\   asm volatile ("fldcw %0" :
comment|/* no outputs */
value|: "m" (ostatus));		\ 									\   return ret;								\ }
end_define

end_unit

