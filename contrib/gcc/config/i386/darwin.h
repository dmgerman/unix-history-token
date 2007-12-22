begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for x86 running Darwin.    Copyright (C) 2001, 2002, 2004, 2005 Free Software Foundation, Inc.    Contributed by Apple Computer Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
value|fprintf (stderr, " (i686 Darwin)");
end_define

begin_undef
undef|#
directive|undef
name|TARGET_64BIT
end_undef

begin_define
define|#
directive|define
name|TARGET_64BIT
value|(target_flags& MASK_64BIT)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_64BIT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_define
define|#
directive|define
name|TARGET_64BIT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_64BIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Size of the Obj-C jump buffer.  */
end_comment

begin_define
define|#
directive|define
name|OBJC_JBLEN
value|((TARGET_64BIT) ? ((9 * 2) + 3 + 16) : (18))
end_define

begin_undef
undef|#
directive|undef
name|TARGET_FPMATH_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_FPMATH_DEFAULT
value|(TARGET_SSE ? FPMATH_SSE : FPMATH_387)
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                            \     {                                           \       builtin_define ("__LITTLE_ENDIAN__");     \       darwin_cpp_builtins (pfile);		\     }                                           \   while (0)
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
value|(TARGET_64BIT ? "long int" : "int")
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

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_undef
undef|#
directive|undef
name|MAX_BITS_PER_WORD
end_undef

begin_define
define|#
directive|define
name|MAX_BITS_PER_WORD
value|64
end_define

begin_undef
undef|#
directive|undef
name|FORCE_PREFERRED_STACK_BOUNDARY_IN_MAIN
end_undef

begin_define
define|#
directive|define
name|FORCE_PREFERRED_STACK_BOUNDARY_IN_MAIN
value|(0)
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
value|"%{!mkernel:%{!static:%{!mdynamic-no-pic:-fPIC}}} \   %{g: %{!fno-eliminate-unused-debug-symbols: -feliminate-unused-debug-symbols }}"
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
value|"-arch %(darwin_arch) -force_cpusubtype_ALL"
end_define

begin_define
define|#
directive|define
name|DARWIN_ARCH_SPEC
value|"%{m64:x86_64;:i386}"
end_define

begin_define
define|#
directive|define
name|DARWIN_SUBARCH_SPEC
value|DARWIN_ARCH_SPEC
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
value|{ "darwin_arch", DARWIN_ARCH_SPEC },                          \   { "darwin_crt2", "" },                                        \   { "darwin_subarch", DARWIN_SUBARCH_SPEC },
end_define

begin_comment
comment|/* Use the following macro for any Darwin/x86-specific command-line option    translation.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OPTION_TRANSLATE_TABLE
define|\
value|{ "", "" }
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

begin_function_decl
specifier|extern
name|void
name|darwin_x86_file_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|TARGET_ASM_FILE_END
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|darwin_x86_file_end
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
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS | MASK_128BIT_LONG_DOUBLE)
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

begin_undef
undef|#
directive|undef
name|GOT_SYMBOL_NAME
end_undef

begin_define
define|#
directive|define
name|GOT_SYMBOL_NAME
value|(machopic_function_base_name ())
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
comment|/* These are used by -fbranch-probabilities */
end_comment

begin_define
define|#
directive|define
name|HOT_TEXT_SECTION_NAME
value|"__TEXT,__text,regular,pure_instructions"
end_define

begin_define
define|#
directive|define
name|UNLIKELY_EXECUTED_TEXT_SECTION_NAME
define|\
value|"__TEXT,__unlikely,regular,pure_instructions"
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

begin_define
define|#
directive|define
name|ASM_QUAD
value|"\t.quad\t"
end_define

begin_define
define|#
directive|define
name|SUBTARGET_ENCODE_SECTION_INFO
value|darwin_encode_section_info
end_define

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
value|do { if ((LOG) != 0)			\         {				\           if (in_section == text_section) \             fprintf (FILE, "\t%s %d,0x90\n", ALIGN_ASM_OP, (LOG)); \           else				\             fprintf (FILE, "\t%s %d\n", ALIGN_ASM_OP, (LOG)); \         }				\     } while (0)
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
value|do {								\       if (MACHOPIC_INDIRECT&& !TARGET_64BIT)				\ 	{								\ 	  const char *name = machopic_mcount_stub_name ();		\ 	  fprintf (FILE, "\tcall %s\n", name+1);
comment|/*  skip '&'  */
value|\ 	  machopic_validate_stub_or_non_lazy_ptr (name);		\ 	}								\       else fprintf (FILE, "\tcall mcount\n");				\     } while (0)
end_define

begin_define
define|#
directive|define
name|C_COMMON_OVERRIDE_OPTIONS
define|\
value|do {									\     SUBTARGET_C_COMMON_OVERRIDE_OPTIONS;				\   } while (0)
end_define

begin_comment
comment|/* Darwin on x86_64 uses dwarf-2 by default.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|(TARGET_64BIT ? DWARF2_DEBUG : DBX_DEBUG)
end_define

begin_comment
comment|/* Darwin uses the standard DWARF register numbers but the default    register numbers for STABS.  Fortunately for 64-bit code the    default and the standard are the same.  */
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
define|\
value|(TARGET_64BIT ? dbx64_register_map[n]				\    : write_symbols == DWARF2_DEBUG ? svr4_dbx_register_map[n]	\    : dbx_register_map[n])
end_define

begin_comment
comment|/* Unfortunately, the 32-bit EH information also doesn't use the standard    DWARF register numbers.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_FRAME_REG_OUT
parameter_list|(
name|n
parameter_list|,
name|for_eh
parameter_list|)
define|\
value|(! (for_eh) || write_symbols != DWARF2_DEBUG || TARGET_64BIT ? (n)	\    : (n) == 5 ? 4							\    : (n) == 4 ? 5							\    : (n)>= 11&& (n)<= 18 ? (n) + 1					\    : (n))
end_define

begin_undef
undef|#
directive|undef
name|REGISTER_TARGET_PRAGMAS
end_undef

begin_define
define|#
directive|define
name|REGISTER_TARGET_PRAGMAS
parameter_list|()
value|DARWIN_REGISTER_TARGET_PRAGMAS()
end_define

begin_undef
undef|#
directive|undef
name|TARGET_SET_DEFAULT_TYPE_ATTRIBUTES
end_undef

begin_define
define|#
directive|define
name|TARGET_SET_DEFAULT_TYPE_ATTRIBUTES
value|darwin_set_default_type_attributes
end_define

begin_comment
comment|/* For 64-bit, we need to add 4 because @GOTPCREL is relative to the    end of the instruction, but without the 4 we'd only have the right    address for the start of the instruction.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_MAYBE_OUTPUT_ENCODED_ADDR_RTX
end_undef

begin_define
define|#
directive|define
name|ASM_MAYBE_OUTPUT_ENCODED_ADDR_RTX
parameter_list|(
name|FILE
parameter_list|,
name|ENCODING
parameter_list|,
name|SIZE
parameter_list|,
name|ADDR
parameter_list|,
name|DONE
parameter_list|)
define|\
value|if (TARGET_64BIT)				                                \     {                                                                           \       if ((SIZE) == 4&& ((ENCODING)& 0x70) == DW_EH_PE_pcrel)			\         {                                                                       \ 	   fputs (ASM_LONG, FILE);                                              \ 	   assemble_name (FILE, XSTR (ADDR, 0));				\ 	   fputs ("+4@GOTPCREL", FILE);                                         \ 	   goto DONE;                                                           \         }									\     }										\   else                                                                          \     {										\       if (ENCODING == ASM_PREFERRED_EH_DATA_FORMAT (2, 1))                      \         {                                                                       \           darwin_non_lazy_pcrel (FILE, ADDR);                                   \           goto DONE;								\         }                                                                       \     }
end_define

begin_comment
comment|/* This needs to move since i386 uses the first flag and other flags are    used in Mach-O.  */
end_comment

begin_undef
undef|#
directive|undef
name|MACHO_SYMBOL_FLAG_VARIABLE
end_undef

begin_define
define|#
directive|define
name|MACHO_SYMBOL_FLAG_VARIABLE
value|((SYMBOL_FLAG_MACH_DEP)<< 3)
end_define

end_unit

