begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for MIPS varients running FreeBSD with ELF format    Copyright (C) 2008 Free Software Foundation, Inc.    Continued by David O'Brien<obrien@freebsd.org>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* This defines which switch letters take arguments.  -G is a MIPS    special.  */
end_comment

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(FBSD_SWITCH_TAKES_ARG (CHAR)		\    || (CHAR) == 'R'			\    || (CHAR) == 'G')
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_comment
comment|/* mips.h bogusly defines it.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "fbsd_dynamic_linker",	FBSD_DYNAMIC_LINKER}, \   { "fbsd_link_spec",		FBSD_LINK_SPEC }
end_define

begin_comment
comment|/* config/mips/mips.h defines CC1_SPEC,    but gives us an "out" with SUBTARGET_CC1_SPEC.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CC1_SPEC
value|"%{profile:-p}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for FreeBSD.  Here we provide support    for the special GCC options -static and -shared, which allow us to    link things in one of these three modes by applying the appropriate    combinations of options at link-time. We like to support here for    as many of the other GNU linker options as possible. But I don't    have the time to search for those flags. I am sure how to add    support for -soname shared_object_name. H.J.     When the -shared link option is used a final link is not being    done.  */
end_comment

begin_define
define|#
directive|define
name|FBSD_LINK_SPEC
value|"\     %{p:%nconsider using `-pg' instead of `-p' with gprof(1) } \     %{v:-V} \     %{assert*} %{R*} %{rpath*} %{defsym*} \     %{shared:-Bshareable %{h*} %{soname*}} \     %{!shared: \       %{!static: \ 	%{rdynamic: -export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker %(fbsd_dynamic_linker) }} \       %{static:-Bstatic}} \     %{symbolic:-Bsymbolic} "
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
value|"\     %{G*} %{mips1} %{mips2} %{mips3} %{mips4} %{mips32} %{mips32r2} %{mips64} \     %{bestGnum} %{call_shared} %{no_archive} %{exact_version} \     %(fbsd_link_spec) "
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|%(endian_spec)
endif|#
directive|endif
end_endif

begin_comment
comment|/* Reset our STARTFILE_SPEC which was properly set in config/freebsd.h    but trashed by config/mips/elf.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|FBSD_STARTFILE_SPEC
end_define

begin_comment
comment|/* Provide an ENDFILE_SPEC appropriate for FreeBSD/i386.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|FBSD_ENDFILE_SPEC
end_define

begin_comment
comment|/* Reset our LIB_SPEC which was properly set in config/freebsd.h    but trashed by config/mips/elf.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|FBSD_LIB_SPEC
end_define

begin_comment
comment|/* config/mips/mips.h defines CPP_SPEC, and it expects SUBTARGET_CPP_SPEC.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|FBSD_CPP_SPEC
end_define

begin_comment
comment|/************************[  Target stuff  ]***********************************/
end_comment

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.    Needs to agree with<machine/ansi.h>.  GCC defaults come from c-decl.c,    c-common.c, and config/<arch>/<arch>.h.  */
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
value|(MASK_ABICALLS | MASK_SOFT_FLOAT)
end_define

begin_if
if|#
directive|if
name|TARGET_ENDIAN_DEFAULT
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (FreeBSD/mips)");
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (FreeBSD/mipsel)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The generic MIPS TARGET_CPU_CPP_BUILTINS are incorrect for FreeBSD.    Specifically, they define too many namespace-invasive macros.  Override    them here.  Note this is structured for easy comparison to the version    in mips.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_CPU_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do								\     {								\       builtin_assert ("machine=mips");				\       builtin_assert ("cpu=mips");				\       builtin_define ("__mips__");				\ 								\       if (TARGET_64BIT)						\ 	builtin_define ("__mips64__");				\ 								\       if (TARGET_FLOAT64)					\ 	builtin_define ("__mips_fpr=64");			\       else							\ 	builtin_define ("__mips_fpr=32");			\ 								\       if (TARGET_MIPS16)					\ 	builtin_define ("__mips16");				\ 								\       MIPS_CPP_SET_PROCESSOR ("_MIPS_ARCH", mips_arch_info);	\       MIPS_CPP_SET_PROCESSOR ("_MIPS_TUNE", mips_tune_info);	\ 								\       if (ISA_MIPS3)						\ 	builtin_define ("__mips=3");				\       else if (ISA_MIPS4)					\ 	builtin_define ("__mips=4");				\       else if (ISA_MIPS32)					\ 	{							\ 	  builtin_define ("__mips=32");				\ 	  builtin_define ("__mips_isa_rev=1");			\ 	}							\       else if (ISA_MIPS32R2)					\ 	{							\ 	  builtin_define ("__mips=32");				\ 	  builtin_define ("__mips_isa_rev=2");			\ 	}							\       else if (ISA_MIPS64)					\ 	{							\ 	  builtin_define ("__mips=64");				\ 	  builtin_define ("__mips_isa_rev=1");			\ 	}							\ 								\       if (TARGET_HARD_FLOAT)					\ 	builtin_define ("__mips_hard_float");			\       else if (TARGET_SOFT_FLOAT)				\ 	builtin_define ("__mips_soft_float");			\ 								\       if (TARGET_SINGLE_FLOAT)					\ 	builtin_define ("__mips_single_float");			\ 								\       if (TARGET_BIG_ENDIAN)					\ 	builtin_define ("__MIPSEB__");				\       else							\ 	builtin_define ("__MIPSEL__");				\ 								\
comment|/* No language dialect defines.  */
value|\ 								\       if (mips_abi == ABI_EABI)					\ 	builtin_define ("__mips_eabi");				\       else if (mips_abi == ABI_N32)				\ 	builtin_define ("__mips_n32");				\       else if (mips_abi == ABI_64)				\ 	builtin_define ("__mips_n64");				\       else if (mips_abi == ABI_O64)				\ 	builtin_define ("__mips_o64");				\       else							\ 	builtin_define ("__mips_o32");				\ 								\       if (TARGET_ABICALLS)					\ 	builtin_define ("__ABICALLS__");			\     }								\   while (0)
end_define

begin_comment
comment|/* Default to the mips32 ISA */
end_comment

begin_undef
undef|#
directive|undef
name|DRIVER_SELF_SPECS
end_undef

begin_define
define|#
directive|define
name|DRIVER_SELF_SPECS
define|\
value|"%{!march=*: -march=mips32}"
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|"%{!EB:%{!EL:%(endian_spec)}}",
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Don't default to pcc-struct-return, we want to retain compatibility with    older gcc versions AND pcc-struct-return is nonreentrant.    (even though the SVR4 ABI for the i386 says that records and unions are    returned in memory).  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PCC_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************[  Assembler stuff  ]********************************/
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_ASM_SPEC
define|\
value|"%{!mno-abicalls: %{!fno-PIC:%{!fno-pic:-KPIC}}}"
end_define

begin_comment
comment|/* -G is incompatible with -KPIC which is the default, so only allow objects    in the small data section if the user explicitly asks for it.  */
end_comment

begin_undef
undef|#
directive|undef
name|MIPS_DEFAULT_GVALUE
end_undef

begin_define
define|#
directive|define
name|MIPS_DEFAULT_GVALUE
value|0
end_define

begin_comment
comment|/* If defined, a C expression whose value is a string containing the    assembler operation to identify the following data as    uninitialized global data.  If not defined, and neither    `ASM_OUTPUT_BSS' nor `ASM_OUTPUT_ALIGNED_BSS' are defined,    uninitialized global data will be output in the data section if    `-fno-common' is passed, otherwise `ASM_OUTPUT_COMMON' will be    used.  */
end_comment

begin_undef
undef|#
directive|undef
name|BSS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t.bss"
end_define

begin_comment
comment|/* Like `ASM_OUTPUT_BSS' except takes the required alignment as a    separate, explicit argument.  If you define this macro, it is used    in place of `ASM_OUTPUT_BSS', and gives you more flexibility in    handling the required alignment of the variable.  The alignment is    specified as the number of bits.     Try to use function `asm_output_aligned_bss' defined in file    `varasm.c' when defining this macro.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_BSS
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)
end_define

begin_comment
comment|/* Standard AT&T UNIX 'as' local label spelling.  */
end_comment

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
comment|/************************[  Debugger stuff  ]*********************************/
end_comment

end_unit

