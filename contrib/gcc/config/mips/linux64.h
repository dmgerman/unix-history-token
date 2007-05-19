begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for MIPS running Linux-based GNU systems with ELF format    using n32/64 abi.    Copyright 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Force the default endianness and ABI flags onto the command line    in order to make the other specs easier to write.  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_SELF_SPECS
define|\
value|"%{!EB:%{!EL:%(endian_spec)}}", \ "%{!mabi=*: -mabi=n32}"
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
value|"\ %{!fno-PIC:%{!fno-pic:-KPIC}} \ %{fno-PIC:-non_shared} %{fno-pic:-non_shared}"
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"\ %{shared: -lc} \ %{!shared: %{pthread:-lpthread} \   %{profile:-lc_p} %{!profile: -lc}}"
end_define

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER32
value|"/lib/ld.so.1"
end_define

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER64
value|"/lib64/ld.so.1"
end_define

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKERN32
value|"/lib32/ld.so.1"
end_define

begin_define
define|#
directive|define
name|UCLIBC_DYNAMIC_LINKERN32
value|"/lib32/ld-uClibc.so.0"
end_define

begin_define
define|#
directive|define
name|LINUX_DYNAMIC_LINKERN32
define|\
value|CHOOSE_DYNAMIC_LINKER (GLIBC_DYNAMIC_LINKERN32, UCLIBC_DYNAMIC_LINKERN32)
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
value|"\ %{G*} %{EB} %{EL} %{mips1} %{mips2} %{mips3} %{mips4} \ %{bestGnum} %{shared} %{non_shared} \ %{call_shared} %{no_archive} %{exact_version} \  %(endian_spec) \   %{!shared: \     %{!ibcs: \       %{!static: \         %{rdynamic:-export-dynamic} \         %{!dynamic-linker: \ 	  %{mabi=n32: -dynamic-linker " LINUX_DYNAMIC_LINKERN32 "} \ 	  %{mabi=64: -dynamic-linker " LINUX_DYNAMIC_LINKER64 "} \ 	  %{mabi=32: -dynamic-linker " LINUX_DYNAMIC_LINKER32 "}}} \       %{static:-static}}} \ %{mabi=n32:-melf32%{EB:b}%{EL:l}tsmipn32} \ %{mabi=64:-melf64%{EB:b}%{EL:l}tsmip} \ %{mabi=32:-melf32%{EB:b}%{EL:l}tsmip}"
end_define

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|(TARGET_OLDABI ? "$" : ".")
end_define

begin_comment
comment|/* GNU/Linux doesn't use the same floating-point format that IRIX uses    for long double.  There's no need to override this here, since    ieee_quad_format is the default, but let's put this here to make    sure nobody thinks we just forgot to set it to something else.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_TFMODE_FORMAT
value|mips_quad_format
end_define

end_unit

