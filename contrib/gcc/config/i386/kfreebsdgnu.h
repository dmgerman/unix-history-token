begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running GNU/KFreeBSD systems with ELF format.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Bruno Haible.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|fprintf (stderr, " (i386 KFreeBSD/ELF)");
end_define

begin_comment
comment|/* FIXME: Is a KFreeBSD-specific fallback mechanism necessary?  */
end_comment

begin_undef
undef|#
directive|undef
name|MD_FALLBACK_FRAME_STATE_FOR
end_undef

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m elf_i386_fbsd %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker /lib/ld.so.1}} \ 	%{static:-static}}}"
end_define

end_unit

