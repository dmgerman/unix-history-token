begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for AMD x86-64 running Linux-based GNU systems with ELF format.    Copyright (C) 2001 Free Software Foundation, Inc.    Contributed by Jan Hubicka<jh@suse.cz>, based on linux.h.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|LINUX_DEFAULT_ELF
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
value|fprintf (stderr, " (x86-64 Linux/ELF)");
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
value|"-D__ELF__ -Dunix -Dlinux -Asystem(posix)"
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
value|"%(cpp_cpu) %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} %{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT} %{!m32:-D__LONG_MAX__=9223372036854775807L}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC.  Here we provide support for the special GCC    options -static and -shared, which allow us to link things in one    of these three modes by applying the appropriate combinations of    options at link-time.     When the -shared link option is used a final link is not being    done.  */
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
value|"%{!m32:-m elf_x86_64} %{m32:-m elf_i386} %{shared:-shared} \   %{!shared: \     %{!static: \       %{rdynamic:-export-dynamic} \       %{!dynamic-linker:-dynamic-linker /lib64/ld-linux-x86-64.so.2}} \       %{static:-static}}"
end_define

end_unit

