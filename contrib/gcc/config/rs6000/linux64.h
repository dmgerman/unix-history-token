begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for 64 bit powerpc linux.    Copyright (C) 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Yes!  We are AIX! Err. Wait. We're Linux!. No, wait, we're a   combo of both!*/
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_ABI
end_undef

begin_define
define|#
directive|define
name|DEFAULT_ABI
value|ABI_AIX
end_define

begin_undef
undef|#
directive|undef
name|TARGET_AIX
end_undef

begin_define
define|#
directive|define
name|TARGET_AIX
value|1
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
define|\
value|(MASK_POWERPC | MASK_POWERPC64 | MASK_64BIT | MASK_NEW_MNEMONICS)
end_define

begin_undef
undef|#
directive|undef
name|CPP_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_DEFAULT_SPEC
value|"-D_ARCH_PPC64"
end_define

begin_undef
undef|#
directive|undef
name|ASM_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|"-mppc64"
end_define

begin_comment
comment|/* 64-bit PowerPC Linux always has a TOC.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_NO_TOC
end_undef

begin_define
define|#
directive|define
name|TARGET_NO_TOC
value|0
end_define

begin_undef
undef|#
directive|undef
name|TARGET_TOC
end_undef

begin_define
define|#
directive|define
name|TARGET_TOC
value|1
end_define

begin_comment
comment|/* We use glibc _mcount for profiling.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
value|1
end_define

begin_undef
undef|#
directive|undef
name|PROFILE_BEFORE_PROLOGUE
end_undef

begin_comment
comment|/* Define this for kernel profiling, which just saves LR then calls    _mcount without worrying about arg saves.  The idea is to change    the function prologue as little as possible as it isn't easy to    account for arg save/restore code added just for _mcount.  */
end_comment

begin_comment
comment|/* #define PROFILE_KERNEL 1 */
end_comment

begin_if
if|#
directive|if
name|PROFILE_KERNEL
end_if

begin_define
define|#
directive|define
name|PROFILE_BEFORE_PROLOGUE
value|1
end_define

begin_undef
undef|#
directive|undef
name|PROFILE_HOOK
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROFILE_HOOK
parameter_list|(
name|LABEL
parameter_list|)
value|output_profile_hook (LABEL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We don't need to generate entries in .fixup.  */
end_comment

begin_undef
undef|#
directive|undef
name|RELOCATABLE_NEEDS_FIXUP
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* AIX word-aligns FP doubles but doubleword-aligns 64-bit ints.  */
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
comment|/* AIX increases natural record alignment to doubleword if the first    field is an FP double while the FP fields remain word aligned.  */
end_comment

begin_undef
undef|#
directive|undef
name|ROUND_TYPE_ALIGN
end_undef

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
comment|/* Indicate that jump tables go in the text section.  */
end_comment

begin_undef
undef|#
directive|undef
name|JUMP_TABLES_IN_TEXT_SECTION
end_undef

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|1
end_define

begin_comment
comment|/* Define cutoff for using external functions to save floating point.  */
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
value|((FIRST_REG) == 62 || (FIRST_REG) == 63)
end_define

begin_comment
comment|/* 64-bit PowerPC Linux always has GPR13 fixed.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_R13
value|1
end_define

begin_comment
comment|/* __throw will restore its own return address to be the same as the    return address of the function that the throw is being made to.    This is unfortunate, because we want to check the original    return address to see if we need to restore the TOC.    So we have to squirrel it away with this.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_FRAME_ADDRESSES
parameter_list|()
value|rs6000_aix_emit_builtin_unwind_init ()
end_define

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-D_PPC_ -D__PPC__ -D_PPC64_ -D__PPC64__ -D__powerpc__ -D__powerpc64__ \   -D_PIC_ -D__PIC__ -D_BIG_ENDIAN -D__BIG_ENDIAN__ -D__ELF__ \   -D__LONG_MAX__=9223372036854775807L \   -Acpu=powerpc64 -Amachine=powerpc64"
end_define

begin_undef
undef|#
directive|undef
name|CPP_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_OS_DEFAULT_SPEC
value|"%(cpp_os_linux)"
end_define

begin_comment
comment|/* The GNU C++ standard library currently requires _GNU_SOURCE being    defined on glibc-based systems. This temporary hack accomplishes this,    it should go away as soon as libstdc++-v3 has a real fix.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUSPLUS_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPLUSPLUS_CPP_SPEC
value|"-D_GNU_SOURCE %(cpp)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SHLIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SHLIB_SPEC
value|"%{shared:-shared} %{!shared: %{static:-static}}"
end_define

begin_undef
undef|#
directive|undef
name|LIB_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_DEFAULT_SPEC
value|"%(lib_linux)"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_DEFAULT_SPEC
value|"%(startfile_linux)"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_DEFAULT_SPEC
value|"%(endfile_linux)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_START_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_START_DEFAULT_SPEC
value|"%(link_start_linux)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_OS_DEFAULT_SPEC
value|"%(link_os_linux)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_OS_LINUX_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_OS_LINUX_SPEC
value|"-m elf64ppc %{!shared: %{!static: \   %{rdynamic:-export-dynamic} \   %{!dynamic-linker:-dynamic-linker /lib/ld.so.1}}}"
end_define

begin_undef
undef|#
directive|undef
name|TOC_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TOC_SECTION_ASM_OP
value|"\t.section\t\".toc\",\"aw\""
end_define

begin_undef
undef|#
directive|undef
name|MINIMAL_TOC_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|MINIMAL_TOC_SECTION_ASM_OP
value|"\t.section\t\".toc1\",\"aw\""
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (PowerPC64 GNU/Linux)");
end_define

begin_comment
comment|/* Must be at least as big as our pointer type.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
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
value|"long int"
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

begin_comment
comment|/* Override rs6000.h definition.  */
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
comment|/* Override rs6000.h definition.  */
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

begin_comment
comment|/* PowerPC no-op instruction.  */
end_comment

begin_undef
undef|#
directive|undef
name|RS6000_CALL_GLUE
end_undef

begin_define
define|#
directive|define
name|RS6000_CALL_GLUE
value|"nop"
end_define

begin_undef
undef|#
directive|undef
name|RS6000_MCOUNT
end_undef

begin_define
define|#
directive|define
name|RS6000_MCOUNT
value|"_mcount"
end_define

begin_comment
comment|/* FP save and restore routines.  */
end_comment

begin_undef
undef|#
directive|undef
name|SAVE_FP_PREFIX
end_undef

begin_define
define|#
directive|define
name|SAVE_FP_PREFIX
value|"._savef"
end_define

begin_undef
undef|#
directive|undef
name|SAVE_FP_SUFFIX
end_undef

begin_define
define|#
directive|define
name|SAVE_FP_SUFFIX
value|""
end_define

begin_undef
undef|#
directive|undef
name|RESTORE_FP_PREFIX
end_undef

begin_define
define|#
directive|define
name|RESTORE_FP_PREFIX
value|"._restf"
end_define

begin_undef
undef|#
directive|undef
name|RESTORE_FP_SUFFIX
end_undef

begin_define
define|#
directive|define
name|RESTORE_FP_SUFFIX
value|""
end_define

begin_comment
comment|/* Dwarf2 debugging.  */
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
value|DWARF2_DEBUG
end_define

begin_comment
comment|/* If we are referencing a function that is static or is known to be    in this file, make the SYMBOL_REF special.  We can use this to indicate    that we can branch to this function without emitting a no-op after the    call.  Do not set this flag if the function is weakly defined.  */
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
value|if (TREE_CODE (DECL) == FUNCTION_DECL				\&& (TREE_ASM_WRITTEN (DECL) || ! TREE_PUBLIC (DECL))	\&& ! DECL_WEAK (DECL))					\     SYMBOL_REF_FLAG (XEXP (DECL_RTL (DECL), 0)) = 1;
end_define

begin_comment
comment|/* This macro gets just the user-specified name    out of the string in a SYMBOL_REF.  Discard    a leading * or @.  */
end_comment

begin_define
define|#
directive|define
name|STRIP_NAME_ENCODING
parameter_list|(
name|VAR
parameter_list|,
name|SYMBOL_NAME
parameter_list|)
define|\
value|do {						\   const char *_name = (SYMBOL_NAME);		\   while (*_name == '*' || *_name == '@')	\     _name++;					\   (VAR) = _name;				\ } while (0)
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.    `assemble_name' uses this.  */
end_comment

begin_comment
comment|/* Override elfos.h definition.  */
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
value|do {						\   const char *_name = NAME;			\   if (*_name == '@')				\     _name++;					\  						\   if (*_name == '*')				\     fprintf (FILE, "%s", _name + 1);		\   else						\     asm_fprintf (FILE, "%U%s", _name);		\ } while (0)
end_define

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
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do									\     {									\       fputs ("\t.section\t\".opd\",\"aw\"\n\t.align 3\n", (FILE));	\       ASM_OUTPUT_LABEL ((FILE), (NAME));				\       fputs (DOUBLE_INT_ASM_OP, (FILE));				\       putc ('.', (FILE));						\       assemble_name ((FILE), (NAME));					\       putc ('\n', (FILE));						\       fputs (DOUBLE_INT_ASM_OP, (FILE));				\       fputs (".TOC.@tocbase, 0\n\t.previous\n", (FILE));		\ 									\       if (TREE_PUBLIC (DECL))						\         {								\ 	  if (DECL_WEAK (DECL))						\ 	    fputs ("\t.weak\t", (FILE));				\ 	  else								\ 	    fputs ("\t.globl\t", (FILE));				\ 	  putc ('.', (FILE));						\ 	  assemble_name ((FILE), (NAME));				\ 	  putc ('\n', (FILE));						\         }								\       fputs (TYPE_ASM_OP, (FILE));					\       putc ('.', (FILE));						\       assemble_name ((FILE), (NAME));					\       putc (',', (FILE));						\       fprintf ((FILE), TYPE_OPERAND_FMT, "function");			\       putc ('\n', (FILE));						\       ASM_DECLARE_RESULT ((FILE), DECL_RESULT (DECL));			\       putc ('.', (FILE));						\       ASM_OUTPUT_LABEL ((FILE), (NAME));				\     }									\   while (0)
end_define

begin_comment
comment|/* Return non-zero if this entry is to be written into the constant    pool in a special way.  We do so if this is a SYMBOL_REF, LABEL_REF    or a CONST containing one of them.  If -mfp-in-toc (the default),    we also do this for floating-point constants.  We actually can only    do this if the FP formats of the target and host machines are the    same, but we can't check that since not every file that uses    GO_IF_LEGITIMATE_ADDRESS_P includes real.h.  We also do this when    we can write the entry into the TOC and the entry is not larger    than a TOC entry.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY_P
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY_P
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(TARGET_TOC								\&& (GET_CODE (X) == SYMBOL_REF					\        || (GET_CODE (X) == CONST&& GET_CODE (XEXP (X, 0)) == PLUS	\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == SYMBOL_REF)		\        || GET_CODE (X) == LABEL_REF					\        || (GET_CODE (X) == CONST_INT 					\&& GET_MODE_BITSIZE (MODE)<= GET_MODE_BITSIZE (Pmode))	\        || (GET_CODE (X) == CONST_DOUBLE					\&& (TARGET_POWERPC64						\ 	       || TARGET_MINIMAL_TOC					\ 	       || (GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT		\&& ! TARGET_NO_FP_IN_TOC)))))
end_define

end_unit

