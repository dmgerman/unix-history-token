begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for DEC Alpha/AXP running FreeBSD using the ELF format    Copyright (C) 2000, 2002 Free Software Foundation, Inc.    Contributed by David E. O'Brien<obrien@FreeBSD.org> and BSDi.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Provide a FBSD_TARGET_CPU_CPP_BUILTINS and CPP_SPEC appropriate for    FreeBSD/alpha.  Besides the dealing with    the GCC option `-posix', and PIC issues as on all FreeBSD platforms, we must    deal with the Alpha's FP issues.  */
end_comment

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
value|do						\     {						\       if (flag_pic)				\ 	{					\ 	  builtin_define ("__PIC__");		\ 	  builtin_define ("__pic__");		\ 	}					\     }						\   while (0)
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
value|"%(cpp_subtarget) %{posix:-D_POSIX_SOURCE}"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{G*} %{relax:-relax}				\   %{p:%e`-p' not supported; use `-pg' and gprof(1)}			\   %{Wl,*:%*}								\   %{assert*} %{R*} %{rpath*} %{defsym*}					\   %{shared:-Bshareable %{h*} %{soname*}}				\   %{symbolic:-Bsymbolic}						\   %{!shared:								\     %{!static:								\       %{rdynamic:-export-dynamic}					\       %{!dynamic-linker:-dynamic-linker /usr/libexec/ld-elf.so.1}}	\     %{static:-Bstatic}}"
end_define

begin_comment
comment|/* We now have to provide a STARTFILE_SPEC because of a moronic pigheaded    Linuxism(glibc'ism) that was added to alpha/elf.h.  */
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
define|\
value|"%{!shared: \       %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}}\    crti.o%s %{shared:crtbeginS.o%s}%{!shared:crtbegin.o%s}"
end_define

begin_comment
comment|/************************[  Target stuff  ]***********************************/
end_comment

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.      Needs to agree with<machine/ansi.h>.  GCC defaults come from c-decl.c,    c-common.c, and config/<arch>/<arch>.h.  */
end_comment

begin_comment
comment|/* alpha.h gets this wrong for FreeBSD.  We use the GCC defaults instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

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
comment|/* Handle cross-compilation on 32-bits machines (such as i386) for 64-bits    machines (Alpha in this case).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HOST_BITS_PER_LONG
end_undef

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|32
end_define

begin_undef
undef|#
directive|undef
name|HOST_WIDE_INT
end_undef

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long long
end_define

begin_undef
undef|#
directive|undef
name|HOST_BITS_PER_WIDE_INT
end_undef

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the pseudo-op used to generate a 64-bit word of data with a    specific value in some section.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (FreeBSD/Alpha ELF)");
end_define

begin_define
define|#
directive|define
name|TARGET_ELF
value|1
end_define

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_COFF
end_undef

begin_undef
undef|#
directive|undef
name|EXTENDED_COFF
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_FP | MASK_FPREGS | MASK_GAS)
end_define

begin_undef
undef|#
directive|undef
name|HAS_INIT_SECTION
end_undef

begin_comment
comment|/* Show that we need a GP when profiling.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_PROFILING_NEEDS_GP
end_undef

begin_define
define|#
directive|define
name|TARGET_PROFILING_NEEDS_GP
value|1
end_define

begin_comment
comment|/* We always use gas here, so we don't worry about ECOFF assembler problems.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_GAS
end_undef

begin_define
define|#
directive|define
name|TARGET_GAS
value|1
end_define

begin_comment
comment|/************************[  Assembler stuff  ]********************************/
end_comment

begin_comment
comment|/************************[  Debugger stuff  ]*********************************/
end_comment

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

begin_comment
comment|/* Don't default to pcc-struct-return, we want to retain compatibility with    older FreeBSD releases AND pcc-struct-return may not be reentrant.  */
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

end_unit

