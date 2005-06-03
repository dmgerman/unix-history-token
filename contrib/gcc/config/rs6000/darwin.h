begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for PowerPC running Darwin (Mac OS X).    Copyright (C) 1997, 2000, 2001, 2003, 2004 Free Software Foundation, Inc.    Contributed by Apple Computer Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
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
comment|/* Darwin switches.  */
end_comment

begin_comment
comment|/* Use dynamic-no-pic codegen (no picbase reg; not suitable for shlibs.)  */
end_comment

begin_define
define|#
directive|define
name|MASK_MACHO_DYNAMIC_NO_PIC
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TARGET_DYNAMIC_NO_PIC
value|(target_flags& MASK_MACHO_DYNAMIC_NO_PIC)
end_define

begin_comment
comment|/* Handle #pragma weak and #pragma pack.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                            \     {                                           \       builtin_define ("__ppc__");               \       builtin_define ("__POWERPC__");           \       builtin_define ("__NATURAL_ALIGNMENT__"); \       builtin_define ("__MACH__");              \       builtin_define ("__APPLE__");             \     }                                           \   while (0)
end_define

begin_comment
comment|/*  */
end_comment

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
value|{"dynamic-no-pic",	MASK_MACHO_DYNAMIC_NO_PIC,			\       N_("Generate code suitable for executables (NOT shared libs)")},	\   {"no-dynamic-no-pic",	-MASK_MACHO_DYNAMIC_NO_PIC, ""},
end_define

begin_comment
comment|/* The Darwin ABI always includes AltiVec, can't be (validly) turned    off.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|do {									\   rs6000_altivec_abi = 1;						\   rs6000_altivec_vrsave = 1;						\   if (DEFAULT_ABI == ABI_DARWIN)					\   {									\     if (MACHO_DYNAMIC_NO_PIC_P)						\       {									\         if (flag_pic)							\             warning ("-mdynamic-no-pic overrides -fpic or -fPIC");	\         flag_pic = 0;							\       }									\     else if (flag_pic == 1)						\       {									\
comment|/* Darwin doesn't support -fpic.  */
value|\         warning ("-fpic is not supported; -fPIC assumed");		\         flag_pic = 2;							\       }									\   }									\ }while(0)
end_define

begin_comment
comment|/* We want -fPIC by default, unless we're using -static to compile for    the kernel or some such.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{gused: -feliminate-unused-debug-symbols<gused }\ %{static: %{Zdynamic: %e conflicting code gen style switches are used}}\ %{!static:%{!mdynamic-no-pic:-fPIC}}"
end_define

begin_comment
comment|/* It's virtually impossible to predict all the possible combinations    of -mcpu and -maltivec and whatnot, so just supply    -force_cpusubtype_ALL if any are seen.  Radar 3492132 against the    assembler is asking for a .machine directive so we could get this    really right.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-arch ppc \   %{Zforce_cpusubtype_ALL:-force_cpusubtype_ALL} \   %{!Zforce_cpusubtype_ALL:%{maltivec|mcpu=*|mpowerpc64:-force_cpusubtype_ALL}}"
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
value|{ "darwin_arch", "ppc" },
end_define

begin_comment
comment|/* The "-faltivec" option should have been called "-maltivec" all along.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OPTION_TRANSLATE_TABLE
define|\
value|{ "-faltivec", "-maltivec -include altivec.h" },     \   { "-fno-altivec", "-mno-altivec" },  \   { "-Waltivec-long-deprecated",       "-mwarn-altivec-long" }, \   { "-Wno-altivec-long-deprecated", "-mno-warn-altivec-long" }
end_define

begin_comment
comment|/* Make both r2 and r3 available for allocation.  */
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
name|FRAME_POINTER_REGNUM
end_undef

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
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
value|(RS6000_ALIGN (current_function_outgoing_args_size, 16)		\    + RS6000_VARARGS_AREA						\    + RS6000_SAVE_AREA)
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
value|"__TEXT,__text2,regular,pure_instructions"
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
value|{									\      "r0",  "r1",  "r2",  "r3",  "r4",  "r5",  "r6",  "r7",		\      "r8",  "r9", "r10", "r11", "r12", "r13", "r14", "r15",		\     "r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23",		\     "r24", "r25", "r26", "r27", "r28", "r29", "r30", "r31",		\      "f0",  "f1",  "f2",  "f3",  "f4",  "f5",  "f6",  "f7",		\      "f8",  "f9", "f10", "f11", "f12", "f13", "f14", "f15",		\     "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23",		\     "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31",		\      "mq",  "lr", "ctr",  "ap",						\     "cr0", "cr1", "cr2", "cr3", "cr4", "cr5", "cr6", "cr7",		\     "xer",								\      "v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7",             \      "v8",  "v9", "v10", "v11", "v12", "v13", "v14", "v15",             \     "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23",             \     "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31",             \     "vrsave", "vscr",							\     "spe_acc", "spefscr"                                                \ }
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

begin_comment
comment|/* ? */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_COMMON
end_undef

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
value|do { fputs (".comm ", (FILE));			\        RS6000_OUTPUT_BASENAME ((FILE), (NAME));		\        fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED"\n",\ 		(SIZE)); } while (0)
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
comment|/* Default processor: a G4.  */
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
value|0
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
comment|/* Given an rtx X being reloaded into a reg required to be          in class CLASS, return the class of reg to actually use.         In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.       On the RS/6000, we have to return NO_REGS when we want to reload a    floating-point CONST_DOUBLE to force it to be copied to memory.     Don't allow R0 when loading the address of, or otherwise furtling with,    a SYMBOL_REF.  */
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
value|((GET_CODE (X) == CONST_DOUBLE				\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT)		\    ? NO_REGS							\    : ((GET_CODE (X) == SYMBOL_REF || GET_CODE (X) == HIGH)	\&& reg_class_subset_p (BASE_REGS, (CLASS)))		\    ? BASE_REGS							\    : (GET_MODE_CLASS (GET_MODE (X)) == MODE_INT			\&& (CLASS) == NON_SPECIAL_REGS)				\    ? GENERAL_REGS						\    : (CLASS))
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
value|((TREE_CODE (STRUCT) == RECORD_TYPE					\     || TREE_CODE (STRUCT) == UNION_TYPE					\     || TREE_CODE (STRUCT) == QUAL_UNION_TYPE)				\&& TARGET_ALIGN_NATURAL == 0                         		\    ? rs6000_special_round_type_align (STRUCT, COMPUTED, SPECIFIED)	\    : (TARGET_ALTIVEC&& TREE_CODE (STRUCT) == VECTOR_TYPE) 		\    ? MAX (MAX ((COMPUTED), (SPECIFIED)), 128)          			 \    : MAX ((COMPUTED), (SPECIFIED)))
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
comment|/* Get HOST_WIDE_INT and CONST_INT to be 32 bits, for compile time    space/speed.  */
end_comment

begin_undef
undef|#
directive|undef
name|MAX_LONG_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|MAX_LONG_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* For binary compatibility with 2.95; Darwin C APIs use bool from    stdbool.h, which was an int-sized enum in 2.95.  */
end_comment

begin_define
define|#
directive|define
name|BOOL_TYPE_SIZE
value|INT_TYPE_SIZE
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
value|DARWIN_REGISTER_TARGET_PRAGMAS
end_define

end_unit

