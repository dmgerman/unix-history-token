begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Intel 386 (OSF/1 with OSF/rose) version.    Copyright (C) 1991, 1992, 1993, 1996, 1998, 1999, 2000    Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"halfpic.h"
end_include

begin_include
include|#
directive|include
file|"i386/gstabs.h"
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
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR) || !strcmp (STR, "pic-names"))
end_define

begin_comment
comment|/* This defines which switch letters take arguments.  On svr4, most of    the normal cases (defined in gcc.c) apply, and we also have -h* and    -z* options (for the linker).  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG(CHAR) \    || (CHAR) == 'h' \    || (CHAR) == 'z')
end_define

begin_define
define|#
directive|define
name|MASK_HALF_PIC
value|010000000000
end_define

begin_comment
comment|/* Mask for half-pic code */
end_comment

begin_define
define|#
directive|define
name|MASK_HALF_PIC_DEBUG
value|004000000000
end_define

begin_comment
comment|/* Debug flag */
end_comment

begin_define
define|#
directive|define
name|MASK_ELF
value|002000000000
end_define

begin_comment
comment|/* ELF not rose */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_UNDERSCORES
value|000400000000
end_define

begin_comment
comment|/* suppress leading _ */
end_comment

begin_define
define|#
directive|define
name|MASK_LARGE_ALIGN
value|000200000000
end_define

begin_comment
comment|/* align to>word boundaries */
end_comment

begin_define
define|#
directive|define
name|MASK_NO_MCOUNT
value|000100000000
end_define

begin_comment
comment|/* profiling uses mcount_ptr */
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

begin_define
define|#
directive|define
name|TARGET_ELF
value|(target_flags& MASK_ELF)
end_define

begin_define
define|#
directive|define
name|TARGET_ROSE
value|((target_flags& MASK_ELF) == 0)
end_define

begin_define
define|#
directive|define
name|TARGET_UNDERSCORES
value|((target_flags& MASK_NO_UNDERSCORES) == 0)
end_define

begin_define
define|#
directive|define
name|TARGET_LARGE_ALIGN
value|(target_flags& MASK_LARGE_ALIGN)
end_define

begin_define
define|#
directive|define
name|TARGET_MCOUNT
value|((target_flags& MASK_NO_MCOUNT) == 0)
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
value|{ "half-pic",		 MASK_HALF_PIC,				\        N_("Emit half-PIC code") },					\      { "no-half-pic",		-MASK_HALF_PIC, "" },			\      { "debug-half-pic",	 MASK_HALF_PIC_DEBUG,			\        0
comment|/* intentionally undoc */
value|},					\      { "debugb",		 MASK_HALF_PIC_DEBUG,			\        0
comment|/* intentionally undoc */
value|},					\      { "elf",			 MASK_ELF,				\        N_("Emit ELF object code") },					\      { "rose",			-MASK_ELF,				\        N_("Emit ROSE object code") },					\      { "underscores",		-MASK_NO_UNDERSCORES,			\        N_("Symbols have a leading underscore") },			\      { "no-underscores",	 MASK_NO_UNDERSCORES, "" },		\      { "large-align",		 MASK_LARGE_ALIGN,			\        N_("Align to>word boundaries") },				\      { "no-large-align",	-MASK_LARGE_ALIGN, "" },		\      { "mcount",		-MASK_NO_MCOUNT,			\        N_("Use mcount for profiling") },				\      { "mcount-ptr",		 MASK_NO_MCOUNT,			\        N_("Use mcount_ptr for profiling") },				\      { "no-mcount",		 MASK_NO_MCOUNT, "" },
end_define

begin_comment
comment|/* OSF/rose uses stabs, not dwarf.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DWARF_DEBUGGING_INFO
end_ifndef

begin_define
define|#
directive|define
name|DWARF_DEBUGGING_INFO
end_define

begin_comment
comment|/* enable dwarf debugging for testing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Handle #pragma weak and #pragma pack.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_define
define|#
directive|define
name|SUPPORTS_WEAK
value|TARGET_ELF
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
value|"-DOSF -DOSF1 -Dunix -Asystem=xpg4"
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
value|"%(cpp_cpu) \ %{!melf: -D__ROSE__ %{!pic-none: -D__SHARED__}} \ %{melf: -D__ELF__ %{fpic: -D__SHARED__}} \ %{mno-underscores: -D__NO_UNDERSCORES__} \ %{melf: %{!munderscores: -D__NO_UNDERSCORES__}} \ %{.S:	%{!ansi:%{!traditional:%{!traditional-cpp:%{!ftraditional: -traditional}}}}} \ %{.S:	-D__LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY}} \ %{.cc:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.cxx:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.C:	-D__LANGUAGE_C_PLUS_PLUS} \ %{.m:	-D__LANGUAGE_OBJECTIVE_C} \ %{!.S:	-D__LANGUAGE_C %{!ansi:-DLANGUAGE_C}}"
end_define

begin_comment
comment|/* Turn on -pic-extern by default for OSF/rose, -fpic for ELF.  */
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
value|"%(cc1_cpu) \ %{gline:%{!g:%{!g0:%{!g1:%{!g2: -g1}}}}} \ %{!melf: %{!mrose: -mrose }} \ %{melf: %{!munderscores: %{!mno-underscores: -mno-underscores }} \ 	%{!mmcount: %{!mno-mcount: %{!mmcount-ptr: -mmcount-ptr }}}} \ %{!melf: %{!munderscores: %{!mno-underscores: -munderscores }} \ 	 %{!mmcount: %{!mno-mcount: %{!mmcount-ptr: -mmcount }}} \ 	 %{pic-extern: -mhalf-pic } %{pic-lib: -mhalf-pic } \ 	 %{!pic-extern: %{!pic-lib: %{pic-none: -mno-half-pic} %{!pic-none: -mhalf-pic}}} \ 	 %{pic-calls: } %{pic-names*: }}"
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
value|"%{v*: -v}"
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
value|"%{v*: -v} \ %{!melf:	%{!noshrlib: %{pic-none: -noshrlib} %{!pic-none: -warn_nopic}} \ 		%{nostdlib} %{noshrlib} %{glue}} \ %{melf:		%{dy} %{dn} %{glue: } \ 		%{h*} %{z*} \ 		%{static:-dn -Bstatic} \ 		%{shared:-G -dy} \ 		%{symbolic:-Bsymbolic -G -dy} \ 		%{G:-G} \ 		%{!dy: %{!dn: %{!static: %{!shared: %{!symbolic: \ 			%{noshrlib: -dn } %{pic-none: -dn } \ 			%{!noshrlib: %{!pic-none: -dy}}}}}}}}"
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
comment|/* Define this macro if the system header files support C++ as well    as C.  This macro inhibits the usual method of using system header    files in C++, which is to pretend that the file's contents are    enclosed in `extern "C" {...}'.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* Turn off long double being 96 bits.  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|OSF_PROFILE_BEFORE_PROLOGUE
define|\
value|(!TARGET_MCOUNT							\&& !current_function_needs_context					\&& (!flag_pic							\        || !frame_pointer_needed						\        || (!current_function_uses_pic_offset_table			\&& !current_function_uses_const_pool)))
end_define

begin_comment
comment|/* A C statement or compound statement to output to FILE some assembler code to    call the profiling subroutine `mcount'.  Before calling, the assembler code    must load the address of a counter variable into a register where `mcount'    expects to find the address.  The name of this variable is `LP' followed by    the number LABELNO, so you would generate the name using `LP%d' in a    `fprintf'.     The details of how the address should be passed to `mcount' are determined    by your operating system environment, not by GNU CC.  To figure them out,    compile a small program for profiling using the system's installed C    compiler and look at the assembler code that results.  */
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
value|do									\   {									\     if (!OSF_PROFILE_BEFORE_PROLOGUE)					\       {									\ 	const char *const prefix = (TARGET_UNDERSCORES) ? "_" : "";	\ 	const char *const lprefix = LPREFIX;				\ 	int labelno = LABELNO;						\ 									\
comment|/* Note that OSF/rose blew it in terms of calling mcount,	\ 	   since OSF/rose prepends a leading underscore, but mcount's	\ 	   doesn't.  At present, we keep this kludge for ELF as well	\ 	   to allow old kernels to build profiling.  */
value|\ 									\ 	if (flag_pic							\&& !current_function_uses_pic_offset_table			\&& !current_function_uses_const_pool)			\ 	  abort ();							\ 									\ 	if (TARGET_MCOUNT&& flag_pic)					\ 	  {								\ 	    fprintf (FILE, "\tleal %sP%d@GOTOFF(%%ebx),%%edx\n",	\ 		     lprefix, labelno);					\ 	    fprintf (FILE, "\tcall *%smcount@GOT(%%ebx)\n", prefix);	\ 	  }								\ 									\ 	else if (TARGET_MCOUNT&& HALF_PIC_P ())			\ 	  {								\ 	    rtx symdef;							\ 									\ 	    HALF_PIC_EXTERNAL ("mcount");				\ 	    symdef = HALF_PIC_PTR (gen_rtx_SYMBOL_REF (Pmode, "mcount")); \ 	    fprintf (FILE, "\tmovl $%sP%d,%%edx\n", lprefix, labelno);	\ 	    fprintf (FILE, "\tcall *%s%s\n", prefix, XSTR (symdef, 0));	\ 	  }								\ 									\ 	else if (TARGET_MCOUNT)						\ 	  {								\ 	    fprintf (FILE, "\tmovl $%sP%d,%%edx\n", lprefix, labelno);	\ 	    fprintf (FILE, "\tcall %smcount\n", prefix);		\ 	  }								\ 									\ 	else if (flag_pic&& frame_pointer_needed)			\ 	  {								\ 	    fprintf (FILE, "\tmovl 4(%%ebp),%%ecx\n");			\ 	    fprintf (FILE, "\tpushl %%ecx\n");				\ 	    fprintf (FILE, "\tleal %sP%d@GOTOFF(%%ebx),%%edx\n",	\ 		     lprefix, labelno);					\ 	    fprintf (FILE, "\tmovl _mcount_ptr@GOT(%%ebx),%%eax\n");	\ 	    fprintf (FILE, "\tcall *(%%eax)\n");			\ 	    fprintf (FILE, "\tpopl %%eax\n");				\ 	  }								\ 									\ 	else if (frame_pointer_needed)					\ 	  {								\ 	    fprintf (FILE, "\tmovl 4(%%ebp),%%ecx\n");			\ 	    fprintf (FILE, "\tpushl %%ecx\n");				\ 	    fprintf (FILE, "\tmovl $%sP%d,%%edx\n", lprefix, labelno);	\ 	    fprintf (FILE, "\tcall *_mcount_ptr\n");			\ 	    fprintf (FILE, "\tpopl %%eax\n");				\ 	  }								\ 									\ 	else								\ 	  abort ();							\       }									\   }									\ while (0)
end_define

begin_comment
comment|/* A C function or functions which are needed in the library to    support block profiling.  When support goes into libc, undo    the #if 0.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_undef
undef|#
directive|undef
name|BLOCK_PROFILING_CODE
end_undef

begin_define
define|#
directive|define
name|BLOCK_PROFILING_CODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prefix for internally generated assembler labels.  If we aren't using    underscores, we are using prefix `.'s to identify labels that should    be ignored, as in `i386/gas.h' --karl@cs.umb.edu  */
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
comment|/* This is how to store into the string BUF    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
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
value|sprintf ((BUF), "*%s%s%ld", (TARGET_UNDERSCORES) ? "" : ".",	\ 	     (PREFIX), (long)(NUMBER))
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
comment|/* The prefix to add to user-visible assembler symbols.  */
end_comment

begin_comment
comment|/* target_flags is not accessible by the preprocessor */
end_comment

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|"_"
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
comment|/* This is how to output an element of a case-vector that is relative.    This is only used for PIC code.  See comments by the `casesi' insn in    i386.md for an explanation of the expression this outputs.  */
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

begin_comment
comment|/* Output a definition */
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
value|do									\ {									\     fprintf ((FILE), "%s", SET_ASM_OP);					\     assemble_name (FILE, LABEL1);					\     fprintf (FILE, ",");						\     assemble_name (FILE, LABEL2);					\     fprintf (FILE, "\n");						\     }									\ while (0)
end_define

begin_comment
comment|/* A C expression to output text to align the location counter in the    way that is desirable at a point in the code that is reached only    by jumping.     This macro need not be defined if you don't want any special    alignment to be done at such a time.  Most machine descriptions do    not currently define the macro.  */
end_comment

begin_undef
undef|#
directive|undef
name|LABEL_ALIGN_AFTER_BARRIER
end_undef

begin_define
define|#
directive|define
name|LABEL_ALIGN_AFTER_BARRIER
parameter_list|(
name|LABEL
parameter_list|)
define|\
value|((!TARGET_LARGE_ALIGN&& i386_align_jumps> 2) ? 2 : i386_align_jumps)
end_define

begin_comment
comment|/* A C expression to output text to align the location counter in the    way that is desirable at the beginning of a loop.     This macro need not be defined if you don't want any special    alignment to be done at such a time.  Most machine descriptions do    not currently define the macro.  */
end_comment

begin_undef
undef|#
directive|undef
name|LOOP_ALIGN
end_undef

begin_define
define|#
directive|define
name|LOOP_ALIGN
parameter_list|(
name|LABEL
parameter_list|)
value|(i386_align_loops)
end_define

begin_comment
comment|/* A C statement to output to the stdio stream STREAM an assembler    command to advance the location counter to a multiple of 2 to the    POWER bytes.  POWER will be a C expression of type `int'.  */
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
name|STREAM
parameter_list|,
name|POWER
parameter_list|)
define|\
value|fprintf (STREAM, "\t.align\t%d\n",					\ 	   (!TARGET_LARGE_ALIGN&& (POWER)> 2) ? 2 : (POWER))
end_define

begin_comment
comment|/* A C expression that is 1 if the RTX X is a constant which is a    valid address.  On most machines, this can be defined as    `CONSTANT_P (X)', but a few machines are more restrictive in    which constant addresses are supported.     `CONSTANT_P' accepts integer-values expressions whose values are    not explicitly known, such as `symbol_ref', `label_ref', and    `high' expressions and `const' arithmetic expressions, in    addition to `const_int' and `const_double' expressions.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P_ORIG
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF		\    || GET_CODE (X) == CONST_INT || GET_CODE (X) == CONST		\    || GET_CODE (X) == HIGH)
end_define

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
value|((CONSTANT_ADDRESS_P_ORIG (X))&& (!HALF_PIC_P () || !HALF_PIC_ADDRESS_P (X)))
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
comment|/* Sometimes certain combinations of command options do not make sense    on a particular target machine.  You can define a macro    `OVERRIDE_OPTIONS' to take account of this.  This macro, if    defined, is executed once just after all the command options have    been parsed.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|{									\
comment|/*									\   if (TARGET_ELF&& TARGET_HALF_PIC)					\     {									\       target_flags&= ~MASK_HALF_PIC;					\       flag_pic = 1;							\     }									\   */
value|\ 									\   if (TARGET_ROSE&& flag_pic)						\     {									\       target_flags |= MASK_HALF_PIC;					\       flag_pic = 0;							\     }									\ 									\   if (TARGET_HALF_PIC)							\     half_pic_init ();							\ }
end_define

begin_comment
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     The macro definition, if any, is executed immediately after the    rtl for DECL has been created and stored in `DECL_RTL (DECL)'.    The value of the rtl will be a `mem' whose address is a    `symbol_ref'.     The usual thing for this macro to do is to a flag in the    `symbol_ref' (such as `SYMBOL_REF_FLAG') or to store a modified    name string in the `symbol_ref' (if one bit is not enough    information).     The best way to modify the name string is by adding text to the    beginning, with suitable punctuation to prevent any ambiguity.    Allocate the new name in `saveable_obstack'.  You will have to    modify `ASM_OUTPUT_LABELREF' to remove and decode the added text    and output the name accordingly.     You can also check the information stored in the `symbol_ref' in    the definition of `GO_IF_LEGITIMATE_ADDRESS' or    `PRINT_OPERAND_ADDRESS'.  */
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
value|do									\   {									\    if (HALF_PIC_P ())							\       HALF_PIC_ENCODE (DECL);						\ 									\    else if (flag_pic)							\      {									\        rtx rtl = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'		\ 		  ? TREE_CST_RTL (DECL) : DECL_RTL (DECL));		\        SYMBOL_REF_FLAG (XEXP (rtl, 0))					\ 	 = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'			\ 	    || ! TREE_PUBLIC (DECL));					\       }									\   }									\ while (0)
end_define

begin_comment
comment|/* On most machines, read-only variables, constants, and jump tables    are placed in the text section.  If this is not the case on your    machine, this macro should be defined to be the name of a function    (either `data_section' or a function defined in `EXTRA_SECTIONS')    that switches to the section to be used for read-only items.     If these items should be placed in the text section, this macro    should not be defined.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION
end_undef

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION
parameter_list|()
define|\
value|do									\   {									\     if (TARGET_ELF)							\       {									\ 	if (in_section != in_rodata)					\ 	  {								\ 	    fprintf (asm_out_file, "\t.section \"rodata\"\n");		\ 	    in_section = in_rodata;					\ 	  }								\       }									\     else								\       text_section ();							\   }									\ while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A list of names for sections other than the standard two, which are    `in_text' and `in_data'.  You need not define this macro on a    system with no other sections (that GCC needs to use).  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_rodata, in_data1
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
parameter_list|,
name|ALIGN
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
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|{									\   if (RELOC&& HALF_PIC_P ())						\     data_section ();							\ 									\   else if (TREE_CODE (DECL) == STRING_CST)				\     {									\       if (flag_writable_strings)					\ 	data_section ();						\       else								\ 	readonly_data_section ();					\     }									\ 									\   else if (TREE_CODE (DECL) != VAR_DECL)				\     readonly_data_section ();						\ 									\   else if (!TREE_READONLY (DECL) || TREE_SIDE_EFFECTS (DECL)		\ 	   || !DECL_INITIAL (DECL)					\ 	   || (DECL_INITIAL (DECL) != error_mark_node			\&& !TREE_CONSTANT (DECL_INITIAL (DECL))))		\     data_section ();							\ 									\   else									\     readonly_data_section ();						\ }
end_define

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

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set\t"
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
comment|/* A C statement (sans semicolon) to output to the stdio stream    STREAM any text necessary for declaring the name NAME of an    initialized variable which is being defined.  This macro must    output the label definition (perhaps using `ASM_OUTPUT_LABEL').    The argument DECL is the `VAR_DECL' tree node representing the    variable.     If this macro is not defined, then the variable name is defined    in the usual manner as a label (by means of `ASM_OUTPUT_LABEL').  */
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
value|do									     \  {									     \    ASM_OUTPUT_LABEL(STREAM,NAME);					     \    HALF_PIC_DECLARE (NAME);						     \    if (TARGET_ELF)							     \      {									     \        fprintf (STREAM, "%s", TYPE_ASM_OP);			 	    \        assemble_name (STREAM, NAME);					     \        putc (',', STREAM);						     \        fprintf (STREAM, TYPE_OPERAND_FMT, "object");			     \        putc ('\n', STREAM);						     \        size_directive_output = 0;					     \        if (!flag_inhibit_size_directive&& DECL_SIZE (DECL))		     \ 	 {								     \            size_directive_output = 1;					     \ 	   fprintf (STREAM, "%s", SIZE_ASM_OP);				     \ 	   assemble_name (STREAM, NAME);				     \ 	   fprintf (STREAM, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL))); \ 	 }								     \      }									     \  }									     \ while (0)
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
value|do {									 \      const char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);		 \      if (TARGET_ELF							 \&& !flag_inhibit_size_directive&& DECL_SIZE (DECL)		 \&& ! AT_END&& TOP_LEVEL					 \&& DECL_INITIAL (DECL) == error_mark_node			 \&& !size_directive_output)					 \        {								 \ 	 fprintf (FILE, "%s", SIZE_ASM_OP);				 \ 	 assemble_name (FILE, name);					 \ 	 fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL))); \        }								 \    } while (0)
end_define

begin_comment
comment|/* This is how to declare a function name.  */
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
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do									\  {									\    ASM_OUTPUT_LABEL(STREAM,NAME);					\    HALF_PIC_DECLARE (NAME);						\    if (TARGET_ELF)							\      {									\        fprintf (STREAM, "%s", TYPE_ASM_OP);				\        assemble_name (STREAM, NAME);					\        putc (',', STREAM);						\        fprintf (STREAM, TYPE_OPERAND_FMT, "function");			\        putc ('\n', STREAM);						\        ASM_DECLARE_RESULT (STREAM, DECL_RESULT (DECL));			\      }									\  }									\ while (0)
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
value|do									\   {									\     if (TARGET_ELF&& !flag_inhibit_size_directive)			\       {									\         char label[256];						\ 	static int labelno;						\ 	labelno++;							\ 	ASM_GENERATE_INTERNAL_LABEL (label, "Lfe", labelno);		\ 	ASM_OUTPUT_INTERNAL_LABEL (FILE, "Lfe", labelno);		\ 	fprintf (FILE, "%s", SIZE_ASM_OP);				\ 	assemble_name (FILE, (FNAME));					\         fprintf (FILE, ",");						\ 	assemble_name (FILE, label);					\         fprintf (FILE, "-");						\ 	assemble_name (FILE, (FNAME));					\ 	putc ('\n', FILE);						\       }									\   }									\ while (0)
end_define

begin_define
define|#
directive|define
name|IDENT_ASM_OP
value|"\t.ident\t"
end_define

begin_comment
comment|/* Allow #sccs in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* This says what to print at the end of the assembly file */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_END
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|do									\   {									\     if (HALF_PIC_P ())							\       HALF_PIC_FINISH (STREAM);						\     ix86_asm_file_end (STREAM);						\   }									\ while (0)
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
name|REAL_NM_FILE_NAME
value|"/usr/ccs/gcc/bfd-nm"
end_define

begin_define
define|#
directive|define
name|REAL_STRIP_FILE_NAME
value|"/usr/ccs/bin/strip"
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
comment|/* Generate calls to memcpy, etc., not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
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
comment|/* Map i386 registers to the numbers dwarf expects.  Of course this is    different from what stabs expects.  */
end_comment

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
value|((write_symbols == DWARF_DEBUG)	\ 				 ? svr4_dbx_register_map[n]	\ 				 : dbx_register_map[n])
end_define

end_unit

