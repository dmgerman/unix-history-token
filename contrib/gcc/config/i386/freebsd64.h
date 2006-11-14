begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for AMD x86-64 running FreeBSD with ELF format    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by David O'Brien<obrien@FreeBSD.org>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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
value|fprintf (stderr, " (FreeBSD/x86-64 ELF)");
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
value|do						\     {						\       if (TARGET_64BIT)				\ 	{					\ 	  builtin_define ("__LP64__");		\ 	}					\     }						\   while (0)
end_define

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "fbsd_dynamic_linker", FBSD_DYNAMIC_LINKER }
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for the FreeBSD/x86-64 ELF target.    This is a copy of LINK_SPEC from<i386/freebsd.h> tweaked for    the x86-64 target.  */
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
value|"\   %{m32:-m elf_i386_fbsd} \   %{Wl,*:%*} \   %{v:-V} \   %{assert*} %{R*} %{rpath*} %{defsym*} \   %{shared:-Bshareable %{h*} %{soname*}} \     %{!shared: \       %{!static: \         %{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker %(fbsd_dynamic_linker) }} \     %{static:-Bstatic}} \   %{symbolic:-Bsymbolic}"
end_define

end_unit

