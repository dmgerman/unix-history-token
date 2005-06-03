begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for x86 running Darwin.    Copyright (C) 2001, 2002 Free Software Foundation, Inc.    Contributed by Apple Computer Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Enable Mach-O bits in generic x86 code.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_MACHO
end_undef

begin_define
define|#
directive|define
name|TARGET_MACHO
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i386 Darwin)");
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                            \     {                                           \       builtin_define ("__i386__");              \       builtin_define ("__LITTLE_ENDIAN__");     \       builtin_define ("__MACH__");              \       builtin_define ("__APPLE__");             \     }                                           \   while (0)
end_define

begin_comment
comment|/* We want -fPIC by default, unless we're using -static to compile for    the kernel or some such.  */
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
value|"%{!static:-fPIC}"
end_define

begin_comment
comment|/* Use the following macro for any Darwin/x86-specific command-line option    translation.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OPTION_TRANSLATE_TABLE
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-arch i386 \   %{Zforce_cpusubtype_ALL:-force_cpusubtype_ALL} \   %{!Zforce_cpusubtype_ALL:%{mmmx:-force_cpusubtype_ALL}\ 			   %{msse:-force_cpusubtype_ALL}\ 			   %{msse2:-force_cpusubtype_ALL}}"
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "darwin_arch", "i386" },
end_define

begin_comment
comment|/* The Darwin assembler mostly follows AT&T syntax.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASSEMBLER_DIALECT
end_undef

begin_define
define|#
directive|define
name|ASSEMBLER_DIALECT
value|ASM_ATT
end_define

begin_comment
comment|/* Define macro used to output shift-double opcodes when the shift    count is in %cl.  Some assemblers require %cl as an argument;    some don't.  This macro controls what to do: by default, don't    print %cl.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_DOUBLE_OMITS_COUNT
value|0
end_define

begin_comment
comment|/* Define the syntax of pseudo-ops, labels and comments.  */
end_comment

begin_comment
comment|/* String containing the assembler's comment-starter.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_comment
comment|/* By default, target has a 80387, uses IEEE compatible arithmetic,    and returns float values in the 387.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS)
end_define

begin_comment
comment|/* TARGET_DEEP_BRANCH_PREDICTION is incompatible with Mach-O PIC.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEEP_BRANCH_PREDICTION
end_undef

begin_define
define|#
directive|define
name|TARGET_DEEP_BRANCH_PREDICTION
value|0
end_define

begin_comment
comment|/* For now, disable dynamic-no-pic.  We'll need to go through i386.c    with a fine-tooth comb looking for refs to flag_pic!  */
end_comment

begin_define
define|#
directive|define
name|MASK_MACHO_DYNAMIC_NO_PIC
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_DYNAMIC_NO_PIC
value|(target_flags& MASK_MACHO_DYNAMIC_NO_PIC)
end_define

begin_comment
comment|/* Define the syntax of pseudo-ops, labels and comments.  */
end_comment

begin_define
define|#
directive|define
name|LPREFIX
value|"L"
end_define

begin_comment
comment|/* Assembler pseudos to introduce constants of various size.  */
end_comment

begin_define
define|#
directive|define
name|ASM_BYTE_OP
value|"\t.byte\t"
end_define

begin_define
define|#
directive|define
name|ASM_SHORT
value|"\t.word\t"
end_define

begin_define
define|#
directive|define
name|ASM_LONG
value|"\t.long\t"
end_define

begin_comment
comment|/* Darwin as doesn't do ".quad".  */
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
value|do { if ((LOG) != 0)			\         {				\           if (in_text_section ())	\             fprintf (FILE, "\t%s %d,0x90\n", ALIGN_ASM_OP, (LOG)); \           else				\             fprintf (FILE, "\t%s %d\n", ALIGN_ASM_OP, (LOG)); \         }				\     } while (0)
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( fputs (".comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%lu\n", (unsigned long)(ROUNDED)))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( fputs (".lcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED"\n", (ROUNDED)))
end_define

begin_comment
comment|/* Darwin profiling -- call mcount.  */
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
value|do {								\       if (MACHOPIC_INDIRECT)						\ 	{								\ 	  const char *name = machopic_stub_name ("*mcount");		\ 	  fprintf (FILE, "\tcall %s\n", name+1);
comment|/*  skip '&'  */
value|\ 	  machopic_validate_stub_or_non_lazy_ptr (name,
comment|/*stub:*/
value|1);	\ 	}								\       else fprintf (FILE, "\tcall mcount\n");				\     } while (0)
end_define

end_unit

