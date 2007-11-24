begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for IBM RS/6000 POWER running AIX.    Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Yes!  We are AIX!  */
end_comment

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

begin_comment
comment|/* AIX always has a TOC.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_NO_TOC
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_TOC
value|1
end_define

begin_define
define|#
directive|define
name|FIXED_R2
value|1
end_define

begin_comment
comment|/* AIX allows r13 to be used in 32-bit mode.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_R13
value|0
end_define

begin_comment
comment|/* AIX does not support Altivec.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ALTIVEC
end_undef

begin_define
define|#
directive|define
name|TARGET_ALTIVEC
value|0
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ALTIVEC_ABI
end_undef

begin_define
define|#
directive|define
name|TARGET_ALTIVEC_ABI
value|0
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ALTIVEC_VRSAVE
end_undef

begin_define
define|#
directive|define
name|TARGET_ALTIVEC_VRSAVE
value|0
end_define

begin_comment
comment|/* The AIX linker will discard static constructors in object files before    collect has a chance to see them, so scan the object files directly.  */
end_comment

begin_define
define|#
directive|define
name|COLLECT_EXPORT_LIST
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

begin_comment
comment|/* This is the only version of nm that collect2 can work with.  */
end_comment

begin_define
define|#
directive|define
name|REAL_NM_FILE_NAME
value|"/usr/ucb/nm"
end_define

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* Don't turn -B into -L if the argument specifies a relative file name.  */
end_comment

begin_define
define|#
directive|define
name|RELATIVE_PREFIX_NOT_LINKDIR
end_define

begin_comment
comment|/* Because of the above, we must have gcc search itself to find libgcc.a.  */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL_1
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                     \     {                                    \       builtin_define ("_IBMR2");         \       builtin_define ("_POWER");         \       builtin_define ("_AIX");           \       builtin_define ("_AIX32");         \       builtin_define ("_LONG_LONG");     \       builtin_assert ("system=unix");    \       builtin_assert ("system=aix");     \       builtin_assert ("cpu=rs6000");     \       builtin_assert ("machine=rs6000"); \     }                                    \   while (0)
end_define

begin_comment
comment|/* Define appropriate architecture macros for preprocessor depending on    target switches.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{posix: -D_POSIX_SOURCE}\    %{ansi: -D_ANSI_C_SOURCE}"
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
value|""
end_define

begin_comment
comment|/* Tell the assembler to assume that all undefined names are external.     Don't do this until the fixed IBM assembler is more generally available.    When this becomes permanently defined, the ASM_OUTPUT_EXTERNAL,    ASM_OUTPUT_EXTERNAL_LIBCALL, and RS6000_OUTPUT_BASENAME macros will no    longer be needed.  Also, the extern declaration of mcount in     rs6000_xcoff_file_start will no longer be needed.  */
end_comment

begin_comment
comment|/* #define ASM_SPEC "-u %(asm_cpu)" */
end_comment

begin_comment
comment|/* Default location of syscalls.exp under AIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_define
define|#
directive|define
name|LINK_SYSCALLS_SPEC
value|"-bI:/lib/syscalls.exp"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_SYSCALLS_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default location of libg.exp under AIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_define
define|#
directive|define
name|LINK_LIBG_SPEC
value|"-bexport:/usr/lib/libg.exp"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_LIBG_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the options for the binder: Start text at 512, align all segments    to 512 bytes, and warn if there is text relocation.     The -bhalt:4 option supposedly changes the level at which ld will abort,    but it also suppresses warnings about multiply defined symbols and is    used by the AIX cc command.  So we use it here.     -bnodelcsect undoes a poor choice of default relating to multiply-defined    csects.  See AIX documentation for more information about this.     -bM:SRE tells the linker that the output file is Shared REusable.  Note    that to actually build a shared library you will also need to specify an    export list with the -Wl,-bE option.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-T512 -H512 %{!r:-btextro} -bhalt:4 -bnodelcsect\ %{static:-bnso %(link_syscalls) } \ %{!shared:%{g*: %(link_libg) }} %{shared:-bM:SRE}"
end_define

begin_comment
comment|/* Profiled library versions are used by linking with special directories.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{pg:-L/lib/profiled -L/usr/lib/profiled}\ %{p:-L/lib/profiled -L/usr/lib/profiled} %{!shared:%{g*:-lg}} -lc"
end_define

begin_comment
comment|/* This now supports a natural alignment mode.  */
end_comment

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
value|(TARGET_ALIGN_NATURAL ? (COMPUTED) : \   (TYPE_MODE (TREE_CODE (TREE_TYPE (FIELD)) == ARRAY_TYPE \ 	      ? get_inner_array_type (FIELD) \ 	      : TREE_TYPE (FIELD)) == DFmode \    ? MIN ((COMPUTED), 32) : (COMPUTED)))
end_define

begin_comment
comment|/* AIX increases natural record alignment to doubleword if the first    field is an FP double while the FP fields remain word aligned.  */
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
value|((TREE_CODE (STRUCT) == RECORD_TYPE						\     || TREE_CODE (STRUCT) == UNION_TYPE						\     || TREE_CODE (STRUCT) == QUAL_UNION_TYPE)					\&& TARGET_ALIGN_NATURAL == 0							\    ? rs6000_special_round_type_align (STRUCT, COMPUTED, SPECIFIED)		\    : MAX ((COMPUTED), (SPECIFIED)))
end_define

begin_comment
comment|/* The AIX ABI isn't explicit on whether aggregates smaller than a    word/doubleword should be padded upward or downward.  One could    reasonably assume that they follow the normal rules for structure    layout treating the parameter area as any other block of memory,    then map the reg param area to registers, i.e., pad upward, which    is the way IBM Compilers for AIX behave.    Setting both of the following defines results in this behavior.  */
end_comment

begin_define
define|#
directive|define
name|AGGREGATE_PADDING_FIXED
value|1
end_define

begin_define
define|#
directive|define
name|AGGREGATES_PAD_UPWARD_ALWAYS
value|1
end_define

begin_comment
comment|/* We don't want anything in the reg parm area being passed on the    stack.  */
end_comment

begin_define
define|#
directive|define
name|MUST_PASS_IN_STACK
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|((TYPE) != 0							\&& (TREE_CODE (TYPE_SIZE (TYPE)) != INTEGER_CST		\ 	|| TREE_ADDRESSABLE (TYPE)))
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
comment|/* Indicate that jump tables go in the text section.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|1
end_define

begin_comment
comment|/* Enable AIX XL compiler calling convention breakage compatibility.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_XL_COMPAT
end_undef

begin_define
define|#
directive|define
name|MASK_XL_COMPAT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TARGET_XL_COMPAT
value|(target_flags& MASK_XL_COMPAT)
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
value|{"xl-compat",		MASK_XL_COMPAT,					\    N_("Conform more closely to IBM XLC semantics") },			\   {"no-xl-compat",	- MASK_XL_COMPAT,				\    N_("Default GCC semantics that differ from IBM XLC") },		\   SUBSUBTARGET_SWITCHES
end_define

begin_define
define|#
directive|define
name|SUBSUBTARGET_SWITCHES
end_define

begin_comment
comment|/* Define any extra SPECS that the compiler needs to generate.  */
end_comment

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
value|{ "link_syscalls",            LINK_SYSCALLS_SPEC },			\   { "link_libg",                LINK_LIBG_SPEC }
end_define

begin_comment
comment|/* Define cutoff for using external functions to save floating point.  */
end_comment

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
comment|/* If the current unwind info (FS) does not contain explicit info    saving R2, then we have to do a minor amount of code reading to    figure out if it was saved.  The big problem here is that the    code that does the save/restore is generated by the linker, so    we have no good way to determine at compile time what to do.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__64BIT__
end_ifdef

begin_define
define|#
directive|define
name|MD_FROB_UPDATE_CONTEXT
parameter_list|(
name|CTX
parameter_list|,
name|FS
parameter_list|)
define|\
value|do {									\     if ((FS)->regs.reg[2].how == REG_UNSAVED)				\       {									\ 	unsigned int *insn						\ 	  = (unsigned int *)						\ 	    _Unwind_GetGR ((CTX), LINK_REGISTER_REGNUM);		\ 	if (*insn == 0xE8410028)					\ 	  _Unwind_SetGRPtr ((CTX), 2, (CTX)->cfa + 40);			\       }									\   } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MD_FROB_UPDATE_CONTEXT
parameter_list|(
name|CTX
parameter_list|,
name|FS
parameter_list|)
define|\
value|do {									\     if ((FS)->regs.reg[2].how == REG_UNSAVED)				\       {									\ 	unsigned int *insn						\ 	  = (unsigned int *)						\ 	    _Unwind_GetGR ((CTX), LINK_REGISTER_REGNUM);		\ 	if (*insn == 0x80410014)					\ 	  _Unwind_SetGRPtr ((CTX), 2, (CTX)->cfa + 20);			\       }									\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|;
end_define

begin_comment
comment|/* No version of AIX fully supports AltiVec or 64-bit instructions in    32-bit mode.  */
end_comment

begin_define
define|#
directive|define
name|OS_MISSING_POWERPC64
value|1
end_define

begin_define
define|#
directive|define
name|OS_MISSING_ALTIVEC
value|1
end_define

end_unit

