begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for 64 bit PowerPC linux.    Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RS6000_BI_ARCH
end_ifndef

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
name|TARGET_64BIT
end_undef

begin_define
define|#
directive|define
name|TARGET_64BIT
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARCH64_P
value|1
end_define

begin_define
define|#
directive|define
name|RS6000_BI_ARCH_P
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_ARCH64_P
value|(TARGET_DEFAULT& MASK_64BIT)
end_define

begin_define
define|#
directive|define
name|RS6000_BI_ARCH_P
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_undef
undef|#
directive|undef
name|TARGET_AIX
end_undef

begin_define
define|#
directive|define
name|TARGET_AIX
value|TARGET_64BIT
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

begin_comment
comment|/* We don't need to generate entries in .fixup, except when    -mrelocatable or -mrelocatable-lib is given.  */
end_comment

begin_undef
undef|#
directive|undef
name|RELOCATABLE_NEEDS_FIXUP
end_undef

begin_define
define|#
directive|define
name|RELOCATABLE_NEEDS_FIXUP
define|\
value|(target_flags& target_flags_explicit& MASK_RELOCATABLE)
end_define

begin_undef
undef|#
directive|undef
name|RS6000_ABI_NAME
end_undef

begin_define
define|#
directive|define
name|RS6000_ABI_NAME
value|(TARGET_64BIT ? "aixdesc" : "sysv")
end_define

begin_define
define|#
directive|define
name|INVALID_64BIT
value|"-m%s not supported in this configuration"
end_define

begin_define
define|#
directive|define
name|INVALID_32BIT
value|INVALID_64BIT
end_define

begin_undef
undef|#
directive|undef
name|SUBSUBTARGET_OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|SUBSUBTARGET_OVERRIDE_OPTIONS
define|\
value|do								\     {								\       if (rs6000_alignment_string == 0)				\ 	rs6000_alignment_flags = MASK_ALIGN_NATURAL;		\       if (TARGET_64BIT)						\ 	{							\ 	  if (DEFAULT_ABI != ABI_AIX)				\ 	    {							\ 	      rs6000_current_abi = ABI_AIX;			\ 	      error (INVALID_64BIT, "call");			\ 	    }							\ 	  if (target_flags& MASK_RELOCATABLE)			\ 	    {							\ 	      target_flags&= ~MASK_RELOCATABLE;		\ 	      error (INVALID_64BIT, "relocatable");		\ 	    }							\ 	  if (target_flags& MASK_EABI)				\ 	    {							\ 	      target_flags&= ~MASK_EABI;			\ 	      error (INVALID_64BIT, "eabi");			\ 	    }							\ 	  if (target_flags& MASK_PROTOTYPE)			\ 	    {							\ 	      target_flags&= ~MASK_PROTOTYPE;			\ 	      error (INVALID_64BIT, "prototype");		\ 	    }							\           if ((target_flags& MASK_POWERPC64) == 0)		\ 	    {							\ 	      target_flags |= MASK_POWERPC64;			\ 	      error ("-m64 requires a PowerPC64 cpu");		\ 	    }							\ 	}							\       else							\ 	{							\ 	  if (!RS6000_BI_ARCH_P)				\ 	    error (INVALID_32BIT, "32");			\ 	  if (TARGET_PROFILE_KERNEL)				\ 	    {							\ 	      target_flags&= ~MASK_PROFILE_KERNEL;		\ 	      error (INVALID_32BIT, "profile-kernel");		\ 	    }							\ 	}							\     }								\   while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RS6000_BI_ARCH
end_ifdef

begin_undef
undef|#
directive|undef
name|OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|rs6000_override_options (((TARGET_DEFAULT ^ target_flags)& MASK_64BIT) \ 			   ? (char *) 0 : TARGET_CPU_DEFAULT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ASM_DEFAULT_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|LINK_OS_LINUX_SPEC
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|RS6000_BI_ARCH
end_ifndef

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|"-mppc64"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%(asm_spec64) %(asm_spec_common)"
end_define

begin_define
define|#
directive|define
name|LINK_OS_LINUX_SPEC
value|"%(link_os_linux_spec64)"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|DEFAULT_ARCH64_P
end_if

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|"-mppc%{!m32:64}"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{m32:%(asm_spec32)}%{!m32:%(asm_spec64)} %(asm_spec_common)"
end_define

begin_define
define|#
directive|define
name|LINK_OS_LINUX_SPEC
value|"%{m32:%(link_os_linux_spec32)}%{!m32:%(link_os_linux_spec64)}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|"-mppc%{m64:64}"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{!m64:%(asm_spec32)}%{m64:%(asm_spec64)} %(asm_spec_common)"
end_define

begin_define
define|#
directive|define
name|LINK_OS_LINUX_SPEC
value|"%{!m64:%(link_os_linux_spec32)}%{m64:%(link_os_linux_spec64)}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_SPEC32
value|"-a32 %{n} %{T} %{Ym,*} %{Yd,*} \ %{mrelocatable} %{mrelocatable-lib} %{fpic:-K PIC} %{fPIC:-K PIC} \ %{memb} %{!memb: %{msdata: -memb} %{msdata=eabi: -memb}} \ %{!mlittle: %{!mlittle-endian: %{!mbig: %{!mbig-endian: \     %{mcall-freebsd: -mbig} \     %{mcall-i960-old: -mlittle} \     %{mcall-linux: -mbig} \     %{mcall-gnu: -mbig} \     %{mcall-netbsd: -mbig} \ }}}}"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC64
value|"-a64"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC_COMMON
value|"%(asm_cpu) \ %{.s: %{mregnames} %{mno-regnames}} %{.S: %{mregnames} %{mno-regnames}} \ %{v:-V} %{Qy:} %{!Qn:-Qy} %{Wa,*:%*} \ %{mlittle} %{mlittle-endian} %{mbig} %{mbig-endian}"
end_define

begin_undef
undef|#
directive|undef
name|SUBSUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBSUBTARGET_EXTRA_SPECS
define|\
value|{ "asm_spec_common",		ASM_SPEC_COMMON },			\   { "asm_spec32",		ASM_SPEC32 },				\   { "asm_spec64",		ASM_SPEC64 },				\   { "link_os_linux_spec32",	LINK_OS_LINUX_SPEC32 },			\   { "link_os_linux_spec64",	LINK_OS_LINUX_SPEC64 },
end_define

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_if
if|#
directive|if
name|DEFAULT_ARCH64_P
end_if

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m64" }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m32" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RS6000_BI_ARCH
end_ifndef

begin_comment
comment|/* 64-bit PowerPC Linux is always big-endian.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_LITTLE_ENDIAN
end_undef

begin_define
define|#
directive|define
name|TARGET_LITTLE_ENDIAN
value|0
end_define

begin_comment
comment|/* 64-bit PowerPC Linux always has a TOC.  */
end_comment

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
comment|/* Some things from sysv4.h we don't do when 64 bit.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_RELOCATABLE
end_undef

begin_define
define|#
directive|define
name|TARGET_RELOCATABLE
value|0
end_define

begin_undef
undef|#
directive|undef
name|TARGET_EABI
end_undef

begin_define
define|#
directive|define
name|TARGET_EABI
value|0
end_define

begin_undef
undef|#
directive|undef
name|TARGET_PROTOTYPE
end_undef

begin_define
define|#
directive|define
name|TARGET_PROTOTYPE
value|0
end_define

begin_undef
undef|#
directive|undef
name|RELOCATABLE_NEEDS_FIXUP
end_undef

begin_define
define|#
directive|define
name|RELOCATABLE_NEEDS_FIXUP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MASK_PROFILE_KERNEL
value|0x00100000
end_define

begin_comment
comment|/* Non-standard profiling for kernels, which just saves LR then calls    _mcount without worrying about arg saves.  The idea is to change    the function prologue as little as possible as it isn't easy to    account for arg save/restore code added just for _mcount.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PROFILE_KERNEL
value|(target_flags& MASK_PROFILE_KERNEL)
end_define

begin_comment
comment|/* Override sysv4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|EXTRA_SUBTARGET_SWITCHES
define|\
value|{"profile-kernel",	 MASK_PROFILE_KERNEL,				\    N_("Call mcount for profiling before a function prologue") },	\   {"no-profile-kernel",	-MASK_PROFILE_KERNEL,				\    N_("Call mcount for profiling after a function prologue") },
end_define

begin_comment
comment|/* We use glibc _mcount for profiling.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
value|TARGET_64BIT
end_define

begin_define
define|#
directive|define
name|PROFILE_HOOK
parameter_list|(
name|LABEL
parameter_list|)
define|\
value|do { if (TARGET_64BIT) output_profile_hook (LABEL); } while (0)
end_define

begin_comment
comment|/* PowerPC64 Linux word-aligns FP doubles when -malign-power is given.  */
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
value|((TARGET_ALTIVEC&& TREE_CODE (TREE_TYPE (FIELD)) == VECTOR_TYPE)	\    ? 128								\    : (TARGET_64BIT							\&& TARGET_ALIGN_NATURAL == 0					\&& TYPE_MODE (TREE_CODE (TREE_TYPE (FIELD)) == ARRAY_TYPE		\ 		    ? get_inner_array_type (FIELD)			\ 		    : TREE_TYPE (FIELD)) == DFmode)			\    ? MIN ((COMPUTED), 32)						\    : (COMPUTED))
end_define

begin_comment
comment|/* PowerPC64 Linux increases natural record alignment to doubleword if    the first field is an FP double, only if in power alignment mode.  */
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
value|((TARGET_ALTIVEC&& TREE_CODE (STRUCT) == VECTOR_TYPE)		\    ? MAX (MAX ((COMPUTED), (SPECIFIED)), 128)				\    : (TARGET_64BIT							\&& (TREE_CODE (STRUCT) == RECORD_TYPE				\ 	  || TREE_CODE (STRUCT) == UNION_TYPE				\ 	  || TREE_CODE (STRUCT) == QUAL_UNION_TYPE)			\&& TARGET_ALIGN_NATURAL == 0)					\    ? rs6000_special_round_type_align (STRUCT, COMPUTED, SPECIFIED)	\    : MAX ((COMPUTED), (SPECIFIED)))
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
value|TARGET_64BIT
end_define

begin_comment
comment|/* The linux ppc64 ABI isn't explicit on whether aggregates smaller    than a doubleword should be padded upward or downward.  You could    reasonably assume that they follow the normal rules for structure    layout treating the parameter area as any other block of memory,    then map the reg param area to registers.  ie. pad updard.    Setting both of the following defines results in this behavior.    Setting just the first one will result in aggregates that fit in a    doubleword being padded downward, and others being padded upward.    Not a bad idea as this results in struct { int x; } being passed    the same way as an int.  */
end_comment

begin_define
define|#
directive|define
name|AGGREGATE_PADDING_FIXED
value|TARGET_64BIT
end_define

begin_define
define|#
directive|define
name|AGGREGATES_PAD_UPWARD_ALWAYS
value|0
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
value|((TARGET_64BIT						\&& (TYPE) != 0						\&& (TREE_CODE (TYPE_SIZE (TYPE)) != INTEGER_CST		\ 	|| TREE_ADDRESSABLE (TYPE)))				\    || (!TARGET_64BIT						\&& default_must_pass_in_stack ((MODE), (TYPE))))
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
comment|/* __throw will restore its own return address to be the same as the    return address of the function that the throw is being made to.    This is unfortunate, because we want to check the original    return address to see if we need to restore the TOC.    So we have to squirrel it away with this.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_FRAME_ADDRESSES
parameter_list|()
define|\
value|do { if (TARGET_64BIT) rs6000_aix_emit_builtin_unwind_init (); } while (0)
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

begin_comment
comment|/* Linux doesn't support saving and restoring 64-bit regs in a 32-bit    process.  */
end_comment

begin_define
define|#
directive|define
name|OS_MISSING_POWERPC64
value|!TARGET_64BIT
end_define

begin_comment
comment|/* glibc has float and long double forms of math functions.  */
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
value|1
end_define

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
value|do							\     {							\       if (TARGET_64BIT)					\ 	{						\ 	  builtin_define ("__PPC__");			\ 	  builtin_define ("__PPC64__");			\ 	  builtin_define ("__powerpc__");		\ 	  builtin_define ("__powerpc64__");		\ 	  builtin_define ("__PIC__");			\ 	  builtin_assert ("cpu=powerpc64");		\ 	  builtin_assert ("machine=powerpc64");		\ 	}						\       else						\ 	{						\ 	  builtin_define_std ("PPC");			\ 	  builtin_define_std ("powerpc");		\ 	  builtin_assert ("cpu=powerpc");		\ 	  builtin_assert ("machine=powerpc");		\ 	  TARGET_OS_SYSV_CPP_BUILTINS ();		\ 	}						\     }							\   while (0)
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

begin_define
define|#
directive|define
name|LINK_OS_LINUX_SPEC32
value|"-m elf32ppclinux %{!shared: %{!static: \   %{rdynamic:-export-dynamic} \   %{!dynamic-linker:-dynamic-linker /lib/ld.so.1}}}"
end_define

begin_define
define|#
directive|define
name|LINK_OS_LINUX_SPEC64
value|"-m elf64ppc %{!shared: %{!static: \   %{rdynamic:-export-dynamic} \   %{!dynamic-linker:-dynamic-linker /lib64/ld64.so.1}}}"
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
define|\
value|(TARGET_64BIT						\    ? "\t.section\t\".toc\",\"aw\""			\    : "\t.section\t\".got\",\"aw\"")
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
define|\
value|(TARGET_64BIT						\    ? "\t.section\t\".toc1\",\"aw\""			\    : ((TARGET_RELOCATABLE || flag_pic)			\       ? "\t.section\t\".got2\",\"aw\""			\       : "\t.section\t\".got1\",\"aw\""))
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
value|(TARGET_64BIT ? "long unsigned int" : "unsigned int")
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
value|(TARGET_64BIT ? "int" : "long int")
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
value|(TARGET_64BIT ? "nop" : "cror 31,31,31")
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
value|(TARGET_64BIT ? "._savef" : "_savefpr_")
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
value|(TARGET_64BIT ? "" : "_l")
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
value|(TARGET_64BIT ? "._restf" : "_restfpr_")
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
value|(TARGET_64BIT ? "" : "_l")
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
value|do									\     {									\       if (!flag_inhibit_size_directive)					\ 	{								\ 	  fputs ("\t.size\t", (FILE));					\ 	  if (TARGET_64BIT)						\ 	    putc ('.', (FILE));						\ 	  assemble_name ((FILE), (FNAME));				\ 	  fputs (",.-", (FILE));					\ 	  if (TARGET_64BIT)						\ 	    putc ('.', (FILE));						\ 	  assemble_name ((FILE), (FNAME));				\ 	  putc ('\n', (FILE));						\ 	}								\     }									\   while (0)
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
value|(TARGET_TOC								\&& (GET_CODE (X) == SYMBOL_REF					\        || (GET_CODE (X) == CONST&& GET_CODE (XEXP (X, 0)) == PLUS	\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == SYMBOL_REF)		\        || GET_CODE (X) == LABEL_REF					\        || (GET_CODE (X) == CONST_INT 					\&& GET_MODE_BITSIZE (MODE)<= GET_MODE_BITSIZE (Pmode))	\        || (GET_CODE (X) == CONST_DOUBLE					\&& ((TARGET_64BIT						\&& (TARGET_POWERPC64					\ 		    || TARGET_MINIMAL_TOC				\ 		    || (GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT	\&& ! TARGET_NO_FP_IN_TOC)))			\ 	       || (!TARGET_64BIT					\&& !TARGET_NO_FP_IN_TOC				\&& !TARGET_RELOCATABLE				\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT	\&& BITS_PER_WORD == HOST_BITS_PER_INT)))))
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
parameter_list|,
name|COUNTER
parameter_list|)
define|\
value|do									\   {									\     char temp[256];							\     ASM_GENERATE_INTERNAL_LABEL (temp, "LM", COUNTER);			\     fprintf (FILE, "\t.stabn 68,0,%d,", LINE);				\     assemble_name (FILE, temp);						\     putc ('-', FILE);							\     if (TARGET_64BIT)							\       putc ('.', FILE);							\     assemble_name (FILE,						\ 		   XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));\     putc ('\n', FILE);							\     (*targetm.asm_out.internal_label) (FILE, "LM", COUNTER);		\   }									\ while (0)
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
value|do									\     {									\       const char *flab;							\       fprintf (FILE, "%s%d,0,0,", ASM_STABN_OP, BRAC);			\       assemble_name (FILE, NAME);					\       putc ('-', FILE);							\       if (current_function_func_begin_label != NULL_TREE)		\ 	flab = IDENTIFIER_POINTER (current_function_func_begin_label);	\       else								\ 	{								\ 	  if (TARGET_64BIT)						\ 	    putc ('.', FILE);						\ 	  flab = XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0);	\ 	}								\       assemble_name (FILE, flab);					\       putc ('\n', FILE);						\     }									\   while (0)
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
value|do									\     {									\       fprintf (FILE, "%s\"\",%d,0,0,", ASM_STABS_OP, N_FUN);		\       assemble_name (FILE, LSCOPE);					\       putc ('-', FILE);							\       if (TARGET_64BIT)							\         putc ('.', FILE);						\       assemble_name (FILE, XSTR (XEXP (DECL_RTL (DECL), 0), 0));	\       putc ('\n', FILE);						\     }									\   while (0)
end_define

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
value|((TARGET_64BIT || flag_pic || TARGET_RELOCATABLE)			\    ? (((GLOBAL) ? DW_EH_PE_indirect : 0) | DW_EH_PE_pcrel		\       | (TARGET_64BIT ? DW_EH_PE_udata8 : DW_EH_PE_sdata4))		\    : DW_EH_PE_absptr)
end_define

begin_comment
comment|/* For backward compatibility, we must continue to use the AIX    structure return convention.  */
end_comment

begin_undef
undef|#
directive|undef
name|DRAFT_V4_STRUCT_RET
end_undef

begin_define
define|#
directive|define
name|DRAFT_V4_STRUCT_RET
value|(!TARGET_64BIT)
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|rs6000_elf_end_indicate_exec_stack
end_define

begin_define
define|#
directive|define
name|TARGET_HAS_F_SETLKW
end_define

begin_define
define|#
directive|define
name|LINK_GCC_C_SEQUENCE_SPEC
define|\
value|"%{static:--start-group} %G %L %{static:--end-group}%{!static:%G}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_include
include|#
directive|include
file|"config/rs6000/linux-unwind.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

