begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for AMD x86-64 running Linux-based GNU systems with ELF format.    Copyright (C) 2001, 2002, 2004, 2005, 2006 Free Software Foundation, Inc.    Contributed by Jan Hubicka<jh@suse.cz>, based on linux.h.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (x86-64 Linux/ELF)");
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do								\     {								\ 	LINUX_TARGET_OS_CPP_BUILTINS();				\     }								\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"
end_define

begin_comment
comment|/* The svr4 ABI for the i386 says that records and unions are returned    in memory.  In the 64bit compilation we will turn this flag off in    override_options, as we never do pcc_struct_return scheme on this target.  */
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
value|1
end_define

begin_comment
comment|/* We arrange for the whole %fs segment to map the tls area.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_TLS_DIRECT_SEG_REFS_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_TLS_DIRECT_SEG_REFS_DEFAULT
value|MASK_TLS_DIRECT_SEG_REFS
end_define

begin_comment
comment|/* Provide a LINK_SPEC.  Here we provide support for the special GCC    options -static and -shared, which allow us to link things in one    of these three modes by applying the appropriate combinations of    options at link-time.     When the -shared link option is used a final link is not being    done.  */
end_comment

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER32
value|"/lib/ld-linux.so.2"
end_define

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER64
value|"/lib64/ld-linux-x86-64.so.2"
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
value|"%{!m32:-m elf_x86_64} %{m32:-m elf_i386} \   %{shared:-shared} \   %{!shared: \     %{!static: \       %{rdynamic:-export-dynamic} \       %{m32:%{!dynamic-linker:-dynamic-linker " LINUX_DYNAMIC_LINKER32 "}} \       %{!m32:%{!dynamic-linker:-dynamic-linker " LINUX_DYNAMIC_LINKER64 "}}} \     %{static:-static}}"
end_define

begin_comment
comment|/* Similar to standard Linux, but adding -ffast-math support.  */
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
define|\
value|"%{ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \    %{shared|pie:crtendS.o%s;:crtend.o%s} crtn.o%s"
end_define

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m64" }
end_define

begin_undef
undef|#
directive|undef
name|NEED_INDICATE_EXEC_STACK
end_undef

begin_define
define|#
directive|define
name|NEED_INDICATE_EXEC_STACK
value|1
end_define

begin_define
define|#
directive|define
name|MD_UNWIND_SUPPORT
value|"config/i386/linux-unwind.h"
end_define

begin_comment
comment|/* This macro may be overridden in i386/k*bsd-gnu.h.  */
end_comment

begin_define
define|#
directive|define
name|REG_NAME
parameter_list|(
name|reg
parameter_list|)
value|reg
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_LIBC_PROVIDES_SSP
end_ifdef

begin_comment
comment|/* i386 glibc provides __stack_chk_guard in %gs:0x14,    x86_64 glibc provides it in %fs:0x28.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_THREAD_SSP_OFFSET
value|(TARGET_64BIT ? 0x28 : 0x14)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

