begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for Alpha NetBSD systems.    Copyright (C) 1998, 2002 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|(MASK_FP | MASK_FPREGS | MASK_GAS)
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-D__NetBSD__ -D__ELF__ -Asystem=unix -Asystem=NetBSD"
end_define

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
comment|/* Provide a CPP_SPEC appropriate for NetBSD/alpha.  In addition to    the standard NetBSD specs, we also handle Alpha FP mode indications.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{mieee:-D_IEEE_FP}							\    %{mieee-with-inexact:-D_IEEE_FP -D_IEEE_FP_INEXACT}			\    %(cpp_cpu) %(cpp_subtarget)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
define|\
value|"%{posix:-D_POSIX_SOURCE}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for a NetBSD/alpha ELF target.    This is a copy of LINK_SPEC from<netbsd-elf.h> tweaked for    the alpha target.  */
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
value|"%{G*} %{relax:-relax}						\    %{O*:-O3} %{!O*:-O1}							\    %{assert*} %{R*}							\    %{shared:-shared}							\    %{!shared:								\      -dc -dp								\      %{!nostdlib:							\        %{!r*:								\ 	 %{!e*:-e __start}}}						\      %{!static:								\        %{rdynamic:-export-dynamic}					\        %{!dynamic-linker:-dynamic-linker /usr/libexec/ld.elf_so}}	\      %{static:-static}}"
end_define

begin_comment
comment|/* Provide an ENDFILE_SPEC appropriate for NetBSD/alpha ELF.  Here we    add crtend.o, which provides part of the support for getting    C++ file-scope static objects deconstructed after exiting "main".     We also need to handle the GCC option `-ffast-math'.  */
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
value|"%{ffast-math|funsafe-math-optimizations:crtfm%O%s} \    %{!shared:crtend%O%s} %{shared:crtendS%O%s}"
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
name|WCHAR_UNSIGNED
end_undef

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|0
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

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (NetBSD/alpha ELF)");
end_define

end_unit

