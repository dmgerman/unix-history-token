begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for PowerPC running Darwin (Mac OS X).    Copyright (C) 1997, 2000, 2001 Free Software Foundation, Inc.    Contributed by Apple Computer Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* The Darwin ABI always includes AltiVec, can't be (validly) turned    off.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|rs6000_altivec_abi = 1;
end_define

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__ppc__ -D__POWERPC__ -D__NATURAL_ALIGNMENT__ -D__MACH__ -D__BIG_ENDIAN__ -D__APPLE__"
end_define

begin_comment
comment|/* We want -fPIC by default, unless we're using -static to compile for    the kernel or some such.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{!static:-fPIC}"
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
name|PIC_OFFSET_TABLE_REGNUM
end_undef

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
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
comment|/* Always use the "debug" register names, they're what the assembler    wants to see.  */
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
value|DEBUG_REGISTER_NAMES
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
value|assemble_name (FILE, NAME);
end_define

begin_comment
comment|/* Output before instructions.  */
end_comment

begin_comment
comment|/* This is how to output the definition of a user-level label named NAME,    such as the label on a static function or variable NAME.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { assemble_name (FILE, NAME); fputs (":\n", FILE); } while (0)
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GLOBALIZE_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { fputs ("\t.globl ", FILE);	\        RS6000_OUTPUT_BASENAME (FILE, NAME); putc ('\n', FILE);} while (0)
end_define

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

begin_undef
undef|#
directive|undef
name|TEXT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_undef
undef|#
directive|undef
name|DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
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
value|do { fputs (".comm ", (FILE));			\        RS6000_OUTPUT_BASENAME ((FILE), (NAME));		\        fprintf ((FILE), ",%d\n", (SIZE)); } while (0)
end_define

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
value|fprintf (FILE, "\t.space %d\n", SIZE)
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
comment|/* Default target flag settings.  Despite the fact that STMW/LMW    serializes, it's still a big codesize win to use them.  Use FSEL by    default as well.  */
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
value|(((GET_CODE (X) == CONST_DOUBLE			\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT)	\    ? NO_REGS						\    : (GET_MODE_CLASS (GET_MODE (X)) == MODE_INT 	\&& (CLASS) == NON_SPECIAL_REGS)			\    ? GENERAL_REGS					\    : (GET_CODE (X) == SYMBOL_REF || GET_CODE (X) == HIGH)	\    ? BASE_REGS						\    : (CLASS)))
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
value|(TYPE_MODE (TREE_CODE (TREE_TYPE (FIELD)) == ARRAY_TYPE \ 	      ? get_inner_array_type (FIELD) \ 	      : TREE_TYPE (FIELD)) == DFmode \    ? MIN ((COMPUTED), 32) : (COMPUTED))
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
value|((TREE_CODE (STRUCT) == RECORD_TYPE			\     || TREE_CODE (STRUCT) == UNION_TYPE			\     || TREE_CODE (STRUCT) == QUAL_UNION_TYPE)		\&& TYPE_FIELDS (STRUCT) != 0				\&& DECL_MODE (TYPE_FIELDS (STRUCT)) == DFmode	\    ? MAX (MAX ((COMPUTED), (SPECIFIED)), 64)		\    : MAX ((COMPUTED), (SPECIFIED)))
end_define

begin_comment
comment|/* XXX: Darwin supports neither .quad, or .llong, but it also doesn't    support 64 bit powerpc either, so this just keeps things happy.  */
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

end_unit

