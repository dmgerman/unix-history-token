begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for 64 bit PowerPC linux.    Copyright (C) 2000, 2001, 2002 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|PROCESSOR_DEFAULT
end_undef

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT
value|PROCESSOR_PPC630
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
value|PROCESSOR_PPC630
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

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{.s: %{mregnames} %{mno-regnames}} \ %{.S: %{mregnames} %{mno-regnames}} \ %{mlittle} %{mlittle-endian} %{mbig} %{mbig-endian} \ %{v:-V} %{Qy:} %{!Qn:-Qy} -a64 %(asm_cpu) %{Wa,*:%*}"
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

begin_undef
undef|#
directive|undef
name|ADJUST_FIELD_ALIGN
end_undef

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
comment|/* Override svr4.h  */
end_comment

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
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                        \     {                                       \       builtin_define ("__PPC__");           \       builtin_define ("__PPC64__");         \       builtin_define ("__powerpc__");       \       builtin_define ("__powerpc64__");     \       builtin_define ("__PIC__");           \       builtin_define ("__ELF__");           \       builtin_assert ("cpu=powerpc64");     \       builtin_assert ("machine=powerpc64"); \     }                                       \   while (0)
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
value|"-m elf64ppc %{!shared: %{!static: \   %{rdynamic:-export-dynamic} \   %{!dynamic-linker:-dynamic-linker /lib64/ld64.so.1}}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NATIVE_CROSS
end_ifdef

begin_define
define|#
directive|define
name|STARTFILE_PREFIX_SPEC
value|"/usr/local/lib64/ /lib64/ /usr/lib64/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|STARTFILE_LINUX_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_LINUX_SPEC
value|"\ %{!shared: %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}} crti.o%s \ %{static:crtbeginT.o%s} \ %{!static:%{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}}"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_LINUX_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_LINUX_SPEC
value|"\ %{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
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

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_comment
comment|/* _init and _fini functions are built from bits spread across many    object files, each potentially with a different TOC pointer.  For    that reason, place a nop after the call so that the linker can    restore the TOC pointer if a TOC adjusting call stub is needed.  */
end_comment

begin_define
define|#
directive|define
name|CRT_CALL_STATIC_FUNCTION
parameter_list|(
name|SECTION_OP
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|asm (SECTION_OP "\n"					\ "	bl ." #FUNC "\n"				\ "	nop\n"						\ "	.previous");
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_undef
undef|#
directive|undef
name|TARGET_ENCODE_SECTION_INFO
end_undef

begin_define
define|#
directive|define
name|TARGET_ENCODE_SECTION_INFO
value|rs6000_xcoff_encode_section_info
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
value|do									\     {									\       fputs ("\t.section\t\".opd\",\"aw\"\n\t.align 3\n", (FILE));	\       ASM_OUTPUT_LABEL ((FILE), (NAME));				\       fputs (DOUBLE_INT_ASM_OP, (FILE));				\       putc ('.', (FILE));						\       assemble_name ((FILE), (NAME));					\       fputs (",.TOC.@tocbase,0\n\t.previous\n\t.size\t", (FILE));	\       assemble_name ((FILE), (NAME));					\       fputs (",24\n\t.type\t.", (FILE));				\       assemble_name ((FILE), (NAME));					\       fputs (",@function\n", (FILE));					\       if (TREE_PUBLIC (DECL)&& ! DECL_WEAK (DECL))			\         {								\ 	  fputs ("\t.globl\t.", (FILE));				\ 	  assemble_name ((FILE), (NAME));				\ 	  putc ('\n', (FILE));						\         }								\       ASM_DECLARE_RESULT ((FILE), DECL_RESULT (DECL));			\       putc ('.', (FILE));						\       ASM_OUTPUT_LABEL ((FILE), (NAME));				\     }									\   while (0)
end_define

begin_comment
comment|/* This is how to declare the size of a function.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_SIZE
end_undef

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
value|do									\     {									\       if (!flag_inhibit_size_directive)					\ 	{								\ 	  fputs ("\t.size\t.", (FILE));					\ 	  assemble_name ((FILE), (FNAME));				\ 	  fputs (",.-.", (FILE));					\ 	  assemble_name ((FILE), (FNAME));				\ 	  putc ('\n', (FILE));						\ 	}								\     }									\   while (0)
end_define

begin_comment
comment|/* Return nonzero if this entry is to be written into the constant    pool in a special way.  We do so if this is a SYMBOL_REF, LABEL_REF    or a CONST containing one of them.  If -mfp-in-toc (the default),    we also do this for floating-point constants.  We actually can only    do this if the FP formats of the target and host machines are the    same, but we can't check that since not every file that uses    GO_IF_LEGITIMATE_ADDRESS_P includes real.h.  We also do this when    we can write the entry into the TOC and the entry is not larger    than a TOC entry.  */
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

begin_comment
comment|/* This is the same as the dbxelf.h version, except that we need to    use the function code label, not the function descriptor.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_LINE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|FILE
parameter_list|,
name|LINE
parameter_list|)
define|\
value|do									\   {									\     static int sym_lineno = 1;						\     char temp[256];							\     ASM_GENERATE_INTERNAL_LABEL (temp, "LM", sym_lineno);		\     fprintf (FILE, "\t.stabn 68,0,%d,", LINE);				\     assemble_name (FILE, temp);						\     fputs ("-.", FILE);							\     assemble_name (FILE,						\ 		   XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));\     putc ('\n', FILE);							\     ASM_OUTPUT_INTERNAL_LABEL (FILE, "LM", sym_lineno);			\     sym_lineno += 1;							\   }									\ while (0)
end_define

begin_comment
comment|/* Similarly, we want the function code label here.  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_BRAC
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|BRAC
parameter_list|)
define|\
value|do									\     {									\       const char *flab;							\       fprintf (FILE, "%s%d,0,0,", ASM_STABN_OP, BRAC);			\       assemble_name (FILE, NAME);					\       putc ('-', FILE);							\       if (current_function_func_begin_label != NULL_TREE)		\ 	flab = IDENTIFIER_POINTER (current_function_func_begin_label);	\       else								\ 	{								\ 	  putc ('.', FILE);						\ 	  flab = XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0);	\ 	}								\       assemble_name (FILE, flab);					\       putc ('\n', FILE);						\     }									\   while (0)
end_define

begin_define
define|#
directive|define
name|DBX_OUTPUT_LBRAC
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|DBX_OUTPUT_BRAC (FILE, NAME, N_LBRAC)
end_define

begin_define
define|#
directive|define
name|DBX_OUTPUT_RBRAC
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|DBX_OUTPUT_BRAC (FILE, NAME, N_RBRAC)
end_define

begin_comment
comment|/* Another case where we want the dot name.  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_NFUN
parameter_list|(
name|FILE
parameter_list|,
name|LSCOPE
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do									\     {									\       fprintf (FILE, "%s\"\",%d,0,0,", ASM_STABS_OP, N_FUN);		\       assemble_name (FILE, LSCOPE);					\       fputs ("-.", FILE);						\       assemble_name (FILE, XSTR (XEXP (DECL_RTL (DECL), 0), 0));	\       putc ('\n', FILE);						\     }									\   while (0)
end_define

begin_comment
comment|/* Override sysv4.h as these are ABI_V4 only.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_PUSH
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_POP
end_undef

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  CODE    is 0 for data, 1 for code labels, 2 for function pointers.  GLOBAL is    true if the symbol may be affected by dynamic relocations.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_PREFERRED_EH_DATA_FORMAT
end_undef

begin_define
define|#
directive|define
name|ASM_PREFERRED_EH_DATA_FORMAT
parameter_list|(
name|CODE
parameter_list|,
name|GLOBAL
parameter_list|)
define|\
value|(((GLOBAL) ? DW_EH_PE_indirect : 0) | DW_EH_PE_pcrel | DW_EH_PE_udata8)
end_define

end_unit

