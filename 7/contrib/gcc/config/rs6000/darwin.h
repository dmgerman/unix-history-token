begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for PowerPC running Darwin (Mac OS X).    Copyright (C) 1997, 2000, 2001, 2003, 2004, 2005, 2006    Free Software Foundation, Inc.    Contributed by Apple Computer Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (Darwin/PowerPC)");
end_define

begin_comment
comment|/* The "Darwin ABI" is mostly like AIX, but with some key differences.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_ABI
value|ABI_DARWIN
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
name|__powerpc64__
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
comment|/* The object file format is Mach-O.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OBJECT_FORMAT
value|OBJECT_MACHO
end_define

begin_comment
comment|/* Size of the Obj-C jump buffer.  */
end_comment

begin_define
define|#
directive|define
name|OBJC_JBLEN
value|((TARGET_64BIT) ? (26*2 + 18*2 + 129 + 1) : (26 + 18*2 + 129 + 1))
end_define

begin_comment
comment|/* We're not ever going to do TOCs.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_TOC
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_NO_TOC
value|1
end_define

begin_comment
comment|/* Override the default rs6000 definition.  */
end_comment

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

begin_comment
comment|/* Translate config/rs6000/darwin.opt to config/darwin.h.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DYNAMIC_NO_PIC
value|(TARGET_MACHO_DYNAMIC_NO_PIC)
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                            \     {                                           \       if (!TARGET_64BIT) builtin_define ("__ppc__");   \       if (TARGET_64BIT) builtin_define ("__ppc64__");  \       builtin_define ("__POWERPC__");           \       builtin_define ("__NATURAL_ALIGNMENT__"); \       darwin_cpp_builtins (pfile);		\     }                                           \   while (0)
end_define

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|do {									\
comment|/* The Darwin ABI always includes AltiVec, can't be (validly) turned	\      off.  */
value|\   rs6000_altivec_abi = 1;						\   TARGET_ALTIVEC_VRSAVE = 1;						\   if (DEFAULT_ABI == ABI_DARWIN)					\   {									\     if (MACHO_DYNAMIC_NO_PIC_P)						\       {									\         if (flag_pic)							\             warning (0, "-mdynamic-no-pic overrides -fpic or -fPIC");	\         flag_pic = 0;							\       }									\     else if (flag_pic == 1)						\       {									\         flag_pic = 2;							\       }									\   }									\   if (TARGET_64BIT&& ! TARGET_POWERPC64)				\     {									\       target_flags |= MASK_POWERPC64;					\       warning (0, "-m64 requires PowerPC64 architecture, enabling");	\     }									\   if (flag_mkernel)							\     {									\       rs6000_default_long_calls = 1;					\       target_flags |= MASK_SOFT_FLOAT;					\     }									\ 									\
comment|/* Make -m64 imply -maltivec.  Darwin's 64-bit ABI includes		\      Altivec.  */
value|\   if (!flag_mkernel&& !flag_apple_kext					\&& TARGET_64BIT							\&& ! (target_flags_explicit& MASK_ALTIVEC))			\     target_flags |= MASK_ALTIVEC;					\ 									\
comment|/* Unless the user (not the configurer) has explicitly overridden	\      it with -mcpu=G3 or -mno-altivec, then 10.5+ targets default to	\      G4 unless targetting the kernel.  */
value|\   if (!flag_mkernel							\&& !flag_apple_kext						\&& darwin_macosx_version_min					\&& strverscmp (darwin_macosx_version_min, "10.5")>= 0		\&& ! (target_flags_explicit& MASK_ALTIVEC)			\&& ! rs6000_select[1].string)					\     {									\       target_flags |= MASK_ALTIVEC;					\     }									\ } while(0)
end_define

begin_define
define|#
directive|define
name|C_COMMON_OVERRIDE_OPTIONS
value|do {					\
comment|/* On powerpc, __cxa_get_exception_ptr is available starting in the	\      10.4.6 libstdc++.dylib.  */
value|\   if ((! darwin_macosx_version_min					\        || strverscmp (darwin_macosx_version_min, "10.4.6")< 0)		\&& flag_use_cxa_get_exception_ptr == 2)				\     flag_use_cxa_get_exception_ptr = 0;					\   if (flag_mkernel)							\     flag_no_builtin = 1;						\   SUBTARGET_C_COMMON_OVERRIDE_OPTIONS;					\ } while (0)
end_define

begin_comment
comment|/* Darwin has 128-bit long double support in libc in 10.4 and later.    Default to 128-bit long doubles even on earlier platforms for ABI    consistency; arithmetic will work even if libc and libm support is    not available.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_DEFAULT_LONG_DOUBLE_SIZE
value|128
end_define

begin_comment
comment|/* We want -fPIC by default, unless we're using -static to compile for    the kernel or some such.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\   %{g: %{!fno-eliminate-unused-debug-symbols: -feliminate-unused-debug-symbols }} \   %{static: %{Zdynamic: %e conflicting code gen style switches are used}}\   %{!mkernel:%{!static:%{!mdynamic-no-pic:-fPIC}}}"
end_define

begin_define
define|#
directive|define
name|DARWIN_ARCH_SPEC
value|"%{m64:ppc64;:ppc}"
end_define

begin_define
define|#
directive|define
name|DARWIN_SUBARCH_SPEC
value|"			\  %{m64: ppc64}					\  %{!m64:					\  %{mcpu=601:ppc601;				\    mcpu=603:ppc603;				\    mcpu=603e:ppc603;				\    mcpu=604:ppc604;				\    mcpu=604e:ppc604e;				\    mcpu=740:ppc750;				\    mcpu=750:ppc750;				\    mcpu=G3:ppc750;				\    mcpu=7400:ppc7400;				\    mcpu=G4:ppc7400;				\    mcpu=7450:ppc7450;				\    mcpu=970:ppc970;				\    mcpu=power4:ppc970;				\    mcpu=G5:ppc970;				\    :ppc}}"
end_define

begin_comment
comment|/* crt2.o is at least partially required for 10.3.x and earlier.  */
end_comment

begin_define
define|#
directive|define
name|DARWIN_CRT2_SPEC
define|\
value|"%{!m64:%:version-compare(!> 10.4 mmacosx-version-min= crt2.o%s)}"
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
value|{ "darwin_arch", DARWIN_ARCH_SPEC },		\   { "darwin_crt2", DARWIN_CRT2_SPEC },		\   { "darwin_subarch", DARWIN_SUBARCH_SPEC },
end_define

begin_comment
comment|/* Output a .machine directive.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START
value|rs6000_darwin_file_start
end_define

begin_comment
comment|/* The "-faltivec" option should have been called "-maltivec" all    along.  -ffix-and-continue and -findirect-data is for compatibility    for old compilers.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OPTION_TRANSLATE_TABLE
define|\
value|{ "-ffix-and-continue", "-mfix-and-continue" },			\   { "-findirect-data", "-mfix-and-continue" },				\   { "-faltivec", "-maltivec -include altivec.h" },			\   { "-fno-altivec", "-mno-altivec" },					\   { "-Waltivec-long-deprecated",	"-mwarn-altivec-long" },	\   { "-Wno-altivec-long-deprecated", "-mno-warn-altivec-long" }
end_define

begin_comment
comment|/* Make both r2 and r13 available for allocation.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_R2
value|0
end_define

begin_define
define|#
directive|define
name|FIXED_R13
value|0
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_undef
undef|#
directive|undef
name|HARD_FRAME_POINTER_REGNUM
end_undef

begin_define
define|#
directive|define
name|HARD_FRAME_POINTER_REGNUM
value|30
end_define

begin_undef
undef|#
directive|undef
name|RS6000_PIC_OFFSET_TABLE_REGNUM
end_undef

begin_define
define|#
directive|define
name|RS6000_PIC_OFFSET_TABLE_REGNUM
value|31
end_define

begin_comment
comment|/* Pad the outgoing args area to 16 bytes instead of the usual 8.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTING_FRAME_OFFSET
end_undef

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
define|\
value|(FRAME_GROWS_DOWNWARD							\    ? 0									\    : (RS6000_ALIGN (current_function_outgoing_args_size, 16)		\       + RS6000_SAVE_AREA))
end_define

begin_undef
undef|#
directive|undef
name|STACK_DYNAMIC_OFFSET
end_undef

begin_define
define|#
directive|define
name|STACK_DYNAMIC_OFFSET
parameter_list|(
name|FUNDECL
parameter_list|)
define|\
value|(RS6000_ALIGN (current_function_outgoing_args_size, 16)		\    + (STACK_POINTER_OFFSET))
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
comment|/* Define cutoff for using external functions to save floating point.    Currently on Darwin, always use inline stores.  */
end_comment

begin_undef
undef|#
directive|undef
name|FP_SAVE_INLINE
end_undef

begin_define
define|#
directive|define
name|FP_SAVE_INLINE
parameter_list|(
name|FIRST_REG
parameter_list|)
value|((FIRST_REG)< 64)
end_define

begin_comment
comment|/* Darwin uses a function call if everything needs to be saved/restored.  */
end_comment

begin_undef
undef|#
directive|undef
name|WORLD_SAVE_P
end_undef

begin_define
define|#
directive|define
name|WORLD_SAVE_P
parameter_list|(
name|INFO
parameter_list|)
value|((INFO)->world_save_p)
end_define

begin_comment
comment|/* The assembler wants the alternate register names, but without    leading percent sign.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{									\      "r0",  "r1",  "r2",  "r3",  "r4",  "r5",  "r6",  "r7",		\      "r8",  "r9", "r10", "r11", "r12", "r13", "r14", "r15",		\     "r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23",		\     "r24", "r25", "r26", "r27", "r28", "r29", "r30", "r31",		\      "f0",  "f1",  "f2",  "f3",  "f4",  "f5",  "f6",  "f7",		\      "f8",  "f9", "f10", "f11", "f12", "f13", "f14", "f15",		\     "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23",		\     "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31",		\      "mq",  "lr", "ctr",  "ap",						\     "cr0", "cr1", "cr2", "cr3", "cr4", "cr5", "cr6", "cr7",		\     "xer",								\      "v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7",             \      "v8",  "v9", "v10", "v11", "v12", "v13", "v14", "v15",             \     "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23",             \     "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31",             \     "vrsave", "vscr",							\     "spe_acc", "spefscr",                                               \     "sfp"								\ }
end_define

begin_comment
comment|/* This outputs NAME to FILE.  */
end_comment

begin_undef
undef|#
directive|undef
name|RS6000_OUTPUT_BASENAME
end_undef

begin_define
define|#
directive|define
name|RS6000_OUTPUT_BASENAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|assemble_name (FILE, NAME)
end_define

begin_comment
comment|/* Globalizing directive for a label.  */
end_comment

begin_undef
undef|#
directive|undef
name|GLOBAL_ASM_OP
end_undef

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|"\t.globl "
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_GLOBALIZE_LABEL
end_undef

begin_comment
comment|/* This is how to output an internal label prefix.  rs6000.c uses this    when generating traceback tables.  */
end_comment

begin_comment
comment|/* Not really used for Darwin?  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL_PREFIX
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|)
define|\
value|fprintf (FILE, "%s", PREFIX)
end_define

begin_comment
comment|/* This says how to output an assembler line to define a global common    symbol.  */
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
value|do {									\     unsigned HOST_WIDE_INT _new_size = SIZE;				\     fputs (".comm ", (FILE));						\     RS6000_OUTPUT_BASENAME ((FILE), (NAME));				\     if (_new_size == 0) _new_size = 1;					\     fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED"\n", _new_size);	\   } while (0)
end_define

begin_comment
comment|/* Override the standard rs6000 definition.  */
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
value|";"
end_define

begin_comment
comment|/* FP save and restore routines.  */
end_comment

begin_define
define|#
directive|define
name|SAVE_FP_PREFIX
value|"._savef"
end_define

begin_define
define|#
directive|define
name|SAVE_FP_SUFFIX
value|""
end_define

begin_define
define|#
directive|define
name|RESTORE_FP_PREFIX
value|"._restf"
end_define

begin_define
define|#
directive|define
name|RESTORE_FP_SUFFIX
value|""
end_define

begin_comment
comment|/* This is how to output an assembler line that says to advance    the location counter to a multiple of 2**LOG bytes using the    "nop" instruction as padding.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN_WITH_NOP
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|do                                                          \     {                                                         \       if ((LOG)< 3)                                          \         {                                                     \           ASM_OUTPUT_ALIGN (FILE,LOG);                        \         }                                                     \       else
comment|/* nop == ori r0,r0,0 */
value|\         fprintf (FILE, "\t.align32 %d,0x60000000\n", (LOG));  \     } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

begin_comment
comment|/* This is supported in cctools 465 and later.  The macro test    above prevents using it in earlier build environments.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_MAX_SKIP_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|,
name|MAX_SKIP
parameter_list|)
define|\
value|if ((LOG) != 0)                                             \     {                                                         \       if ((MAX_SKIP) == 0)                                    \         fprintf ((FILE), "\t.p2align %d\n", (LOG));           \       else                                                    \         fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP)); \     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Generate insns to call the profiler.  */
end_comment

begin_define
define|#
directive|define
name|PROFILE_HOOK
parameter_list|(
name|LABEL
parameter_list|)
value|output_profile_hook (LABEL)
end_define

begin_comment
comment|/* Function name to call to do profiling.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_MCOUNT
value|"*mcount"
end_define

begin_comment
comment|/* Default processor: G4, and G5 for 64-bit.  */
end_comment

begin_undef
undef|#
directive|undef
name|PROCESSOR_DEFAULT
end_undef

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT
value|PROCESSOR_PPC7400
end_define

begin_undef
undef|#
directive|undef
name|PROCESSOR_DEFAULT64
end_undef

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT64
value|PROCESSOR_POWER4
end_define

begin_comment
comment|/* Default target flag settings.  Despite the fact that STMW/LMW    serializes, it's still a big code size win to use them.  Use FSEL by    default as well.  */
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
value|(MASK_POWERPC | MASK_MULTIPLE | MASK_NEW_MNEMONICS \                       | MASK_PPC_GFXOPT)
end_define

begin_comment
comment|/* Darwin only runs on PowerPC, so short-circuit POWER patterns.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_POWER
end_undef

begin_define
define|#
directive|define
name|TARGET_POWER
value|0
end_define

begin_undef
undef|#
directive|undef
name|TARGET_IEEEQUAD
end_undef

begin_define
define|#
directive|define
name|TARGET_IEEEQUAD
value|0
end_define

begin_comment
comment|/* Since Darwin doesn't do TOCs, stub this out.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
value|((void)X, (void)MODE, 0)
end_define

begin_comment
comment|/* Unlike most other PowerPC targets, chars are signed, for    consistency with other Darwin architectures.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_SIGNED_CHAR
end_undef

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|(1)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.     On the RS/6000, we have to return NO_REGS when we want to reload a    floating-point CONST_DOUBLE to force it to be copied to memory.     Don't allow R0 when loading the address of, or otherwise furtling with,    a SYMBOL_REF.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_RELOAD_CLASS
end_undef

begin_define
define|#
directive|define
name|PREFERRED_RELOAD_CLASS
parameter_list|(
name|X
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|((CONSTANT_P (X)						\&& reg_classes_intersect_p ((CLASS), FLOAT_REGS))		\    ? NO_REGS							\    : ((GET_CODE (X) == SYMBOL_REF || GET_CODE (X) == HIGH)	\&& reg_class_subset_p (BASE_REGS, (CLASS)))		\    ? BASE_REGS							\    : (GET_MODE_CLASS (GET_MODE (X)) == MODE_INT			\&& (CLASS) == NON_SPECIAL_REGS)				\    ? GENERAL_REGS						\    : (CLASS))
end_define

begin_comment
comment|/* Fix for emit_group_load (): force large constants to be pushed via regs.  */
end_comment

begin_define
define|#
directive|define
name|ALWAYS_PUSH_CONSTS_USING_REGS_P
value|1
end_define

begin_comment
comment|/* This now supports a natural alignment mode */
end_comment

begin_comment
comment|/* Darwin word-aligns FP doubles but doubleword-aligns 64-bit ints.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_FIELD_ALIGN
parameter_list|(
name|FIELD
parameter_list|,
name|COMPUTED
parameter_list|)
define|\
value|(TARGET_ALIGN_NATURAL ? (COMPUTED) : \   (TYPE_MODE (TREE_CODE (TREE_TYPE (FIELD)) == ARRAY_TYPE \ 	      ? get_inner_array_type (FIELD) \ 	      : TREE_TYPE (FIELD)) == DFmode \    ? MIN ((COMPUTED), 32) : (COMPUTED)))
end_define

begin_comment
comment|/* Darwin increases natural record alignment to doubleword if the first    field is an FP double while the FP fields remain word aligned.  */
end_comment

begin_define
define|#
directive|define
name|ROUND_TYPE_ALIGN
parameter_list|(
name|STRUCT
parameter_list|,
name|COMPUTED
parameter_list|,
name|SPECIFIED
parameter_list|)
define|\
value|((TREE_CODE (STRUCT) == RECORD_TYPE					\     || TREE_CODE (STRUCT) == UNION_TYPE					\     || TREE_CODE (STRUCT) == QUAL_UNION_TYPE)				\&& TARGET_ALIGN_NATURAL == 0                         		\    ? rs6000_special_round_type_align (STRUCT, COMPUTED, SPECIFIED)	\    : (TREE_CODE (STRUCT) == VECTOR_TYPE					\&& ALTIVEC_VECTOR_MODE (TYPE_MODE (STRUCT))) 			\    ? MAX (MAX ((COMPUTED), (SPECIFIED)), 128)          			 \    : MAX ((COMPUTED), (SPECIFIED)))
end_define

begin_comment
comment|/* Specify padding for the last element of a block move between    registers and memory.  FIRST is nonzero if this is the only    element.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_REG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|FIRST
parameter_list|)
define|\
value|(!(FIRST) ? upward : FUNCTION_ARG_PADDING (MODE, TYPE))
end_define

begin_comment
comment|/* XXX: Darwin supports neither .quad, or .llong, but it also doesn't    support 64 bit PowerPC either, so this just keeps things happy.  */
end_comment

begin_define
define|#
directive|define
name|DOUBLE_INT_ASM_OP
value|"\t.quad\t"
end_define

begin_comment
comment|/* For binary compatibility with 2.95; Darwin C APIs use bool from    stdbool.h, which was an int-sized enum in 2.95.  Users can explicitly    choose to have sizeof(bool)==1 with the -mone-byte-bool switch. */
end_comment

begin_define
define|#
directive|define
name|BOOL_TYPE_SIZE
value|(darwin_one_byte_bool ? CHAR_TYPE_SIZE : INT_TYPE_SIZE)
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
define|\
value|do \     { \       DARWIN_REGISTER_TARGET_PRAGMAS(); \       targetm.resolve_overloaded_builtin = altivec_resolve_overloaded_builtin; \     } \   while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MD_UNWIND_SUPPORT
value|"config/rs6000/darwin-unwind.h"
end_define

begin_define
define|#
directive|define
name|HAS_MD_FALLBACK_FRAME_STATE_FOR
value|1
end_define

begin_comment
comment|/* True, iff we're generating fast turn around debugging code.  When    true, we arrange for function prologues to start with 5 nops so    that gdb may insert code to redirect them, and for data to be    accessed indirectly.  The runtime uses this indirection to forward    references for data to the original instance of that data.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FIX_AND_CONTINUE
value|(darwin_fix_and_continue)
end_define

begin_comment
comment|/* This is the reserved direct dispatch address for Objective-C.  */
end_comment

begin_define
define|#
directive|define
name|OFFS_MSGSEND_FAST
value|0xFFFEFF00
end_define

begin_comment
comment|/* This is the reserved ivar address Objective-C.  */
end_comment

begin_define
define|#
directive|define
name|OFFS_ASSIGNIVAR_FAST
value|0xFFFEFEC0
end_define

begin_comment
comment|/* Old versions of Mac OS/Darwin don't have C99 functions available.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_C99_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|TARGET_C99_FUNCTIONS
define|\
value|(TARGET_64BIT							\    || (darwin_macosx_version_min				\&& strverscmp (darwin_macosx_version_min, "10.3")>= 0))
end_define

begin_comment
comment|/* When generating kernel code or kexts, we don't use Altivec by    default, as kernel code doesn't save/restore those registers.  */
end_comment

begin_define
define|#
directive|define
name|OS_MISSING_ALTIVEC
value|(flag_mkernel || flag_apple_kext)
end_define

end_unit

