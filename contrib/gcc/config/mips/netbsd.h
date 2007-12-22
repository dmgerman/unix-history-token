begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for MIPS NetBSD systems.    Copyright (C) 1993, 1995, 1996, 1997, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Define default target values.  */
end_comment

begin_undef
undef|#
directive|undef
name|MACHINE_TYPE
end_undef

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
name|MACHINE_TYPE
value|"NetBSD/mipseb ELF"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"NetBSD/mipsel ELF"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do							\     {							\       NETBSD_OS_CPP_BUILTINS_ELF();			\       builtin_define ("__NO_LEADING_UNDERSCORES__");	\       builtin_define ("__GP_SUPPORT__");		\       if (TARGET_LONG64)				\ 	builtin_define ("__LONG64");			\ 							\       if (TARGET_ABICALLS)				\ 	builtin_define ("__ABICALLS__");		\ 							\       if (mips_abi == ABI_EABI)				\ 	builtin_define ("__mips_eabi");			\       else if (mips_abi == ABI_N32)			\ 	builtin_define ("__mips_n32");			\       else if (mips_abi == ABI_64)			\ 	builtin_define ("__mips_n64");			\       else if (mips_abi == ABI_O64)			\ 	builtin_define ("__mips_o64");			\     }							\   while (0)
end_define

begin_comment
comment|/* The generic MIPS TARGET_CPU_CPP_BUILTINS are incorrect for NetBSD.    Specifically, they define too many namespace-invasive macros.  Override    them here.  Note this is structured for easy comparison to the version    in mips.h.     FIXME: This probably isn't the best solution.  But in the absence    of something better, it will have to do, for now.  */
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
value|do								\     {								\       builtin_assert ("cpu=mips");				\       builtin_define ("__mips__");				\       builtin_define ("_mips");					\ 								\
comment|/* No _R3000 or _R4000.  */
value|\       if (TARGET_64BIT)						\ 	builtin_define ("__mips64");				\ 								\       if (TARGET_FLOAT64)					\ 	builtin_define ("__mips_fpr=64");			\       else							\ 	builtin_define ("__mips_fpr=32");			\ 								\       if (TARGET_MIPS16)					\ 	builtin_define ("__mips16");				\ 								\       MIPS_CPP_SET_PROCESSOR ("_MIPS_ARCH", mips_arch_info);	\       MIPS_CPP_SET_PROCESSOR ("_MIPS_TUNE", mips_tune_info);	\ 								\       if (ISA_MIPS1)						\ 	builtin_define ("__mips=1");				\       else if (ISA_MIPS2)					\ 	builtin_define ("__mips=2");				\       else if (ISA_MIPS3)					\ 	builtin_define ("__mips=3");				\       else if (ISA_MIPS4)					\ 	builtin_define ("__mips=4");				\       else if (ISA_MIPS32)					\ 	{							\ 	  builtin_define ("__mips=32");				\ 	  builtin_define ("__mips_isa_rev=1");			\ 	}							\       else if (ISA_MIPS32R2)					\ 	{							\ 	  builtin_define ("__mips=32");				\ 	  builtin_define ("__mips_isa_rev=2");			\ 	}							\       else if (ISA_MIPS64)					\ 	{							\ 	  builtin_define ("__mips=64");				\ 	  builtin_define ("__mips_isa_rev=1");			\ 	}							\ 								\       if (TARGET_HARD_FLOAT)					\ 	builtin_define ("__mips_hard_float");			\       else if (TARGET_SOFT_FLOAT)				\ 	builtin_define ("__mips_soft_float");			\ 								\       if (TARGET_SINGLE_FLOAT)					\ 	builtin_define ("__mips_single_float");			\ 								\       if (TARGET_BIG_ENDIAN)					\ 	builtin_define ("__MIPSEB__");				\       else							\ 	builtin_define ("__MIPSEL__");				\ 								\
comment|/* No language dialect defines.  */
value|\ 								\
comment|/* ABIs handled in TARGET_OS_CPP_BUILTINS.  */
value|\     }								\   while (0)
end_define

begin_comment
comment|/* Clean up after the generic MIPS/ELF configuration.  */
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
comment|/* Extra specs we need.  */
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
value|{ "netbsd_cpp_spec",		NETBSD_CPP_SPEC },			\   { "netbsd_link_spec",		NETBSD_LINK_SPEC_ELF },			\   { "netbsd_entry_point",	NETBSD_ENTRY_POINT },
end_define

begin_comment
comment|/* Provide a SUBTARGET_CPP_SPEC appropriate for NetBSD.  */
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
value|"%(netbsd_cpp_spec)"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for a NetBSD/mips target.    This is a copy of LINK_SPEC from<netbsd-elf.h> tweaked for    the MIPS target.  */
end_comment

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
value|"%{EL:-m elf32lmip} \    %{EB:-m elf32bmip} \    %(endian_spec) \    %{G*} %{mips1} %{mips2} %{mips3} %{mips4} %{mips32} %{mips32r2} %{mips64} \    %{bestGnum} %{call_shared} %{no_archive} %{exact_version} \    %(netbsd_link_spec)"
end_define

begin_define
define|#
directive|define
name|NETBSD_ENTRY_POINT
value|"__start"
end_define

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
value|"%{!mno-abicalls: \      %{!fno-PIC:%{!fno-pic:-KPIC}}}"
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
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR)					\    || (CHAR) == 'R'							\    || (CHAR) == 'G')
end_define

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_comment
comment|/* NetBSD hasn't historically provided _flush_cache(), but rather    _cacheflush(), which takes the same arguments as the former.  */
end_comment

begin_undef
undef|#
directive|undef
name|CACHE_FLUSH_FUNC
end_undef

begin_define
define|#
directive|define
name|CACHE_FLUSH_FUNC
value|"_cacheflush"
end_define

begin_comment
comment|/* Make gcc agree with<machine/ansi.h> */
end_comment

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
name|WINT_TYPE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE
value|"int"
end_define

end_unit

