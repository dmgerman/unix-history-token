begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for x86-64/ELF NetBSD systems.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Wasabi Systems, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Provide a LINK_SPEC appropriate for a NetBSD/x86-64 ELF target.    This is a copy of LINK_SPEC from<netbsd-elf.h> tweaked for    the x86-64 target.  */
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
value|"%{!m32:-m elf_x86_64}						\    %{m32:-m elf_i386}							\    %{assert*} %{R*}							\    %{shared:-shared}							\    %{!shared:								\      -dc -dp								\      %{!nostdlib:							\        %{!r*:								\ 	  %{!e*:-e _start}}}						\      %{!static:								\        %{rdynamic:-export-dynamic}					\        %{!dynamic-linker:-dynamic-linker /usr/libexec/ld.elf_so}}	\      %{static:-static}}"
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-D__NetBSD__ -D__ELF__ -Asystem=unix -Asystem=NetBSD"
end_define

begin_comment
comment|/* Output assembler code to FILE to call the profiler.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{									\   if (TARGET_64BIT&& flag_pic)						\     fprintf (FILE, "\tcall *__mcount@PLT\n");				\   else if (flag_pic)							\     fprintf (FILE, "\tcall *__mcount@PLT\n");				\   else									\     fprintf (FILE, "\tcall __mcount\n");				\ }
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
value|fprintf (stderr, " (NetBSD/x86_64 ELF)");
end_define

end_unit

