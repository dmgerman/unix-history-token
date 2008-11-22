begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC, for ELF on NetBSD/sparc    and NetBSD/sparc64.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.    Contributed by Matthew Green (mrg@eterna.com.au).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do							\     {							\       NETBSD_OS_CPP_BUILTINS_ELF();			\       if (TARGET_ARCH64)				\ 	{						\ 	  builtin_define ("__sparc64__");		\ 	  builtin_define ("__sparc_v9__");		\ 	  builtin_define ("__sparcv9");			\ 	}						\       else						\ 	builtin_define ("__sparc");			\       builtin_define ("__sparc__");			\     }							\   while (0)
end_define

begin_comment
comment|/* Make sure these are undefined.  */
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
comment|/* CPP defines used by all NetBSD targets.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|"%(netbsd_cpp_spec)"
end_define

begin_comment
comment|/* SIZE_TYPE and PTRDIFF_TYPE are wrong from sparc/sparc.h.  */
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
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF2_DEBUG
end_define

begin_comment
comment|/* This is the char to use for continuation (in case we need to turn    continuation back on).  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_CONTIN_CHAR
end_undef

begin_define
define|#
directive|define
name|DBX_CONTIN_CHAR
value|'?'
end_define

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
name|REGNO
parameter_list|)
define|\
value|(TARGET_FLAT&& REGNO == HARD_FRAME_POINTER_REGNUM ? 31 : REGNO)
end_define

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* This is how to output a reference to an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, ".L%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
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
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf ((LABEL), "*.L%s%ld", (PREFIX), (long)(NUM))
end_define

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
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
value|"%{fpic|fPIC|fpie|fPIE:-K PIC} %{V} %{v:%{!V:-V}} \ %{mlittle-endian:-EL} \ %(asm_cpu) %(asm_arch) %(asm_relax)"
end_define

begin_undef
undef|#
directive|undef
name|STDC_0_IN_SYSTEM_HEADERS
end_undef

begin_comment
comment|/* Attempt to enable execute permissions on the stack.  */
end_comment

begin_define
define|#
directive|define
name|ENABLE_EXECUTE_STACK
value|NETBSD_ENABLE_EXECUTE_STACK
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
value|fprintf (stderr, " (%s)", TARGET_NAME);
end_define

begin_comment
comment|/* Below here exists the merged NetBSD/sparc& NetBSD/sparc64 compiler    description, allowing one to build 32 bit or 64 bit applications    on either.  We define the sparc& sparc64 versions of things,    occasionally a neutral version (should be the same as "netbsd-elf.h")    and then based on SPARC_BI_ARCH, DEFAULT_ARCH32_P, and TARGET_CPU_DEFAULT,    we choose the correct version.  */
end_comment

begin_comment
comment|/* We use the default NetBSD ELF STARTFILE_SPEC and ENDFILE_SPEC    definitions, even for the SPARC_BI_ARCH compiler, because NetBSD does    not have a default place to find these libraries..  */
end_comment

begin_comment
comment|/* Name the port(s).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_NAME64
value|"NetBSD/sparc64 ELF"
end_define

begin_define
define|#
directive|define
name|TARGET_NAME32
value|"NetBSD/sparc ELF"
end_define

begin_comment
comment|/* TARGET_CPU_DEFAULT is set in Makefile.in.  We test for 64-bit default    platform here.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v9
expr|\
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc
end_if

begin_comment
comment|/* A 64 bit v9 compiler with stack-bias,    in a Medium/Low code model environment.  */
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
define|\
value|(MASK_V9 + MASK_PTR64 + MASK_64BIT
comment|/* + MASK_HARD_QUAD */
value|\    + MASK_STACK_BIAS + MASK_APP_REGS + MASK_FPU + MASK_LONG_DOUBLE_128)
end_define

begin_undef
undef|#
directive|undef
name|SPARC_DEFAULT_CMODEL
end_undef

begin_define
define|#
directive|define
name|SPARC_DEFAULT_CMODEL
value|CM_MEDANY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CC1_SPEC for NetBSD/sparc.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC32
define|\
value|"%{sun4:} %{target:} \   %{mcypress:-mcpu=cypress} \   %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \   %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \   %{m32:%{m64:%emay not use both -m32 and -m64}} \   %{m64: \     -mptr64 -mstack-bias -mno-v8plus -mlong-double-128 \     %{!mcpu*: \       %{!mcypress: \         %{!msparclite: \ 	  %{!mf930: \ 	    %{!mf934: \ 	      %{!mv8*: \ 	        %{!msupersparc:-mcpu=ultrasparc}}}}}}} \     %{!mno-vis:%{!mcpu=v9:-mvis}} \     %{p:-mcmodel=medlow} \     %{pg:-mcmodel=medlow}}"
end_define

begin_define
define|#
directive|define
name|CC1_SPEC64
define|\
value|"%{sun4:} %{target:} \   %{mcypress:-mcpu=cypress} \   %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \   %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \   %{m32:%{m64:%emay not use both -m32 and -m64}} \   %{m32: \     -mptr32 -mno-stack-bias \     %{!mlong-double-128:-mlong-double-64} \     %{!mcpu*: \       %{!mcypress: \ 	%{!msparclite: \ 	  %{!mf930: \ 	    %{!mf934: \ 	      %{!mv8*: \ 		%{!msupersparc:-mcpu=cypress}}}}}}}} \   %{!m32: \     %{p:-mcmodel=medlow} \     %{pg:-mcmodel=medlow}}"
end_define

begin_comment
comment|/* Make sure we use the right output format.  Pick a default and then    make sure -m32/-m64 switch to the right one.  */
end_comment

begin_define
define|#
directive|define
name|LINK_ARCH32_SPEC
value|"-m elf32_sparc"
end_define

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC
value|"-m elf64_sparc"
end_define

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
define|\
value|"%{m32:%(link_arch32)} \   %{m64:%(link_arch64)} \   %{!m32:%{!m64:%(link_arch_default)}}"
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
define|\
value|"%(link_arch) \   %{!mno-relax:%{!r:-relax}} \   %(netbsd_link_spec)"
end_define

begin_define
define|#
directive|define
name|NETBSD_ENTRY_POINT
value|"__start"
end_define

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|LINK_ARCH_DEFAULT_SPEC
value|LINK_ARCH32_SPEC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_ARCH_DEFAULT_SPEC
value|LINK_ARCH64_SPEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* What extra spec entries do we need?  */
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
value|{ "link_arch32",		LINK_ARCH32_SPEC }, \   { "link_arch64",		LINK_ARCH64_SPEC }, \   { "link_arch_default",	LINK_ARCH_DEFAULT_SPEC }, \   { "link_arch",		LINK_ARCH_SPEC }, \   { "netbsd_cpp_spec",		NETBSD_CPP_SPEC }, \   { "netbsd_link_spec",		NETBSD_LINK_SPEC_ELF }, \   { "netbsd_entry_point",	NETBSD_ENTRY_POINT },
end_define

begin_comment
comment|/* What extra switches do we need?  */
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
value|{"long-double-64", -MASK_LONG_DOUBLE_128, N_("Use 64 bit long doubles") }, \   {"long-double-128", MASK_LONG_DOUBLE_128, N_("Use 128 bit long doubles") },
end_define

begin_comment
comment|/* Build a compiler that supports -m32 and -m64?  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
end_ifdef

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|(TARGET_LONG_DOUBLE_128 ? 128 : 64)
end_define

begin_undef
undef|#
directive|undef
name|MAX_LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|MAX_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__LONG_DOUBLE_128__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|CC1_SPEC
value|CC1_SPEC32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CC1_SPEC
value|CC1_SPEC64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m32" }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m64" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Name the port. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_NAME
end_undef

begin_define
define|#
directive|define
name|TARGET_NAME
value|(DEFAULT_ARCH32_P ? TARGET_NAME32 : TARGET_NAME64)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SPARC_BI_ARCH */
end_comment

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v9
expr|\
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc
end_if

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_undef
undef|#
directive|undef
name|MAX_LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|MAX_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_undef
undef|#
directive|undef
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|CC1_SPEC64
end_define

begin_undef
undef|#
directive|undef
name|TARGET_NAME
end_undef

begin_define
define|#
directive|define
name|TARGET_NAME
value|TARGET_NAME64
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TARGET_CPU_DEFAULT == TARGET_CPU_v9 \ 	|| TARGET_CPU_DEFAULT == TARGET_CPU_ultrasparc */
end_comment

begin_comment
comment|/* A 32-bit only compiler.  NetBSD don't support 128 bit `long double'    for 32-bit code, unlike Solaris.  */
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

begin_undef
undef|#
directive|undef
name|MAX_LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|MAX_LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_undef
undef|#
directive|undef
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|CC1_SPEC32
end_define

begin_undef
undef|#
directive|undef
name|TARGET_NAME
end_undef

begin_define
define|#
directive|define
name|TARGET_NAME
value|TARGET_NAME32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_CPU_DEFAULT == TARGET_CPU_v9 \ 	|| TARGET_CPU_DEFAULT == TARGET_CPU_ultrasparc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPARC_BI_ARCH */
end_comment

begin_comment
comment|/* We use GNU ld so undefine this so that attribute((init_priority)) works.  */
end_comment

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

end_unit

