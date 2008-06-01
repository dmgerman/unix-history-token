begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration file for ARM GNU/Linux EABI targets.    Copyright (C) 2004, 2005, 2006    Free Software Foundation, Inc.    Contributed by CodeSourcery, LLC        This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* On EABI GNU/Linux, we want both the BPABI builtins and the    GNU/Linux builtins.  */
end_comment

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
value|do 						\     {						\       TARGET_BPABI_CPP_BUILTINS();		\       LINUX_TARGET_OS_CPP_BUILTINS();		\     }						\   while (false)
end_define

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

begin_comment
comment|/* We default to the "aapcs-linux" ABI so that enums are int-sized by    default.  */
end_comment

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

begin_comment
comment|/* Default to armv5t so that thumb shared libraries work.    The ARM10TDMI core is the default for armv5t, so set    SUBTARGET_CPU_DEFAULT to achieve this.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPU_DEFAULT
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPU_DEFAULT
value|TARGET_CPU_arm10tdmi
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_LINK_SPEC
value|" -m armelf_linux_eabi"
end_define

begin_comment
comment|/* Use ld-linux.so.3 so that it will be possible to run "classic"    GNU/Linux binaries on an EABI system.  */
end_comment

begin_undef
undef|#
directive|undef
name|GLIBC_DYNAMIC_LINKER
end_undef

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER
value|"/lib/ld-linux.so.3"
end_define

begin_comment
comment|/* At this point, bpabi.h will have clobbered LINK_SPEC.  We want to    use the GNU/Linux version, not the generic BPABI version.  */
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
value|LINUX_TARGET_LINK_SPEC
end_define

begin_comment
comment|/* Use the default LIBGCC_SPEC, not the version in linux-elf.h, as we    do not use -lfloat.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_comment
comment|/* Use the AAPCS type for wchar_t, or the previous Linux default for    non-AAPCS.  */
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
value|(TARGET_AAPCS_BASED ? "unsigned int" : "long int")
end_define

begin_comment
comment|/* Clear the instruction cache from `beg' to `end'.  This makes an    inline system call to SYS_cacheflush.  It is modified to work with    both the original and EABI-only syscall interfaces.  */
end_comment

begin_undef
undef|#
directive|undef
name|CLEAR_INSN_CACHE
end_undef

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
value|{									\   register unsigned long _beg __asm ("a1") = (unsigned long) (BEG);	\   register unsigned long _end __asm ("a2") = (unsigned long) (END);	\   register unsigned long _flg __asm ("a3") = 0;				\   register unsigned long _scno __asm ("r7") = 0xf0002;			\   __asm __volatile ("swi 0x9f0002		@ sys_cacheflush"	\ 		    : "=r" (_beg)					\ 		    : "0" (_beg), "r" (_end), "r" (_flg), "r" (_scno));	\ }
end_define

end_unit

