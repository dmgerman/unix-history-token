begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for StrongARM running FreeBSD using the ELF format    Copyright (C) 2001, 2004 Free Software Foundation, Inc.    Contributed by David E. O'Brien<obrien@FreeBSD.org> and BSDi.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
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
value|{ "subtarget_extra_asm_spec",	SUBTARGET_EXTRA_ASM_SPEC }, \   { "subtarget_asm_float_spec", SUBTARGET_ASM_FLOAT_SPEC }, \   { "fbsd_dynamic_linker", FBSD_DYNAMIC_LINKER }
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_ASM_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_ARM_EABI
end_ifdef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_ASM_SPEC
define|\
value|"%{mabi=apcs-gnu|mabi=atpcs:-meabi=gnu;:-meabi=4} %{fpic|fpie:-k} %{fPIC|fPIE:-k}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_ASM_SPEC
define|\
value|"-matpcs %{fpic|fpie:-k} %{fPIC|fPIE:-k}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default to full FPA if -mhard-float is specified. */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_ASM_FLOAT_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_ASM_FLOAT_SPEC
define|\
value|"%{mhard-float:-mfpu=fpa}			\    %{mfloat-abi=hard:{!mfpu=*:-mfpu=fpa}}	\    %{!mhard-float: %{msoft-float:-mfpu=softvfp;:-mfpu=softvfp}}"
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
value|"							\   %{p:%nconsider using `-pg' instead of `-p' with gprof(1) }		\   %{v:-V}								\   %{assert*} %{R*} %{rpath*} %{defsym*}					\   %{shared:-Bshareable %{h*} %{soname*}}				\   %{!shared:								\     %{!static:								\       %{rdynamic:-export-dynamic}					\       %{!dynamic-linker:-dynamic-linker %(fbsd_dynamic_linker) }}	\     %{static:-Bstatic}}							\   %{!static:--hash-style=both --enable-new-dtags}			\   %{symbolic:-Bsymbolic}						\   -X %{mbig-endian:-EB} %{mlittle-endian:-EL}"
end_define

begin_comment
comment|/************************[  Target stuff  ]***********************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ENDIAN_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ENDIAN_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_ARM_EABI
end_ifdef

begin_comment
comment|/* We default to a soft-float ABI so that binaries can run on all    target hardware.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT_FLOAT_ABI
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT_FLOAT_ABI
value|ARM_FLOAT_ABI_SOFT
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
value|(MASK_INTERWORK | TARGET_ENDIAN_DEFAULT)
end_define

begin_undef
undef|#
directive|undef
name|ARM_DEFAULT_ABI
end_undef

begin_define
define|#
directive|define
name|ARM_DEFAULT_ABI
value|ARM_ABI_AAPCS_LINUX
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
value|do						\     {						\       FBSD_TARGET_OS_CPP_BUILTINS();		\       TARGET_BPABI_CPP_BUILTINS();		\     }						\   while (false)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Default it to use ATPCS with soft-VFP.  */
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
value|(MASK_APCS_FRAME			\    | TARGET_ENDIAN_DEFAULT)
end_define

begin_undef
undef|#
directive|undef
name|ARM_DEFAULT_ABI
end_undef

begin_define
define|#
directive|define
name|ARM_DEFAULT_ABI
value|ARM_ABI_ATPCS
end_define

begin_undef
undef|#
directive|undef
name|FPUTYPE_DEFAULT
end_undef

begin_define
define|#
directive|define
name|FPUTYPE_DEFAULT
value|FPUTYPE_VFP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.    Needs to agree with<machine/ansi.h>.  GCC defaults come from c-decl.c,    c-common.c, and config/<arch>/<arch>.h.  */
end_comment

begin_comment
comment|/* arm.h gets this wrong for FreeBSD.  We use the GCC defaults instead.  */
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
value|"unsigned int"
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
value|"int"
end_define

begin_comment
comment|/* We use the GCC defaults here.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FREEBSD_ARCH_armv6
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPU_DEFAULT
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPU_DEFAULT
value|TARGET_CPU_arm1176jzs
end_define

begin_undef
undef|#
directive|undef
name|FBSD_TARGET_CPU_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|FBSD_TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do {						\     builtin_define ("__FreeBSD_ARCH_armv6__");	\   } while (0)
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
value|fprintf (stderr, " (FreeBSD/armv6 ELF)");
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPU_DEFAULT
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPU_DEFAULT
value|TARGET_CPU_arm9
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
value|fprintf (stderr, " (FreeBSD/StrongARM ELF)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FreeBSD does its profiling differently to the Acorn compiler. We    don't need a word following the mcount call; and to skip it    requires either an assembly stub or use of fomit-frame-pointer when    compiling the profiling functions.  Since we break Acorn CC    compatibility below a little more won't hurt.  */
end_comment

begin_undef
undef|#
directive|undef
name|ARM_FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|ARM_FUNCTION_PROFILER
parameter_list|(
name|STREAM
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{							\   asm_fprintf (STREAM, "\tmov\t%Rip, %Rlr\n");		\   asm_fprintf (STREAM, "\tbl\t__mcount%s\n",		\ 	       (TARGET_ARM&& NEED_PLT_RELOC)		\ 	       ? "(PLT)" : "");				\ }
end_define

begin_comment
comment|/* Clear the instruction cache from `BEG' to `END'.  This makes a    call to the ARM_SYNC_ICACHE architecture specific syscall.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_INSN_CACHE
parameter_list|(
name|BEG
parameter_list|,
name|END
parameter_list|)
define|\
value|do									\   {									\     extern int sysarch(int number, void *args);				\     struct								\       {									\ 	unsigned int addr;						\ 	int          len;						\       } s;								\     s.addr = (unsigned int)(BEG);					\     s.len = (END) - (BEG);						\     (void) sysarch (0,&s);						\   }									\ while (0)
end_define

end_unit

