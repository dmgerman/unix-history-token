begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for PowerPC NetBSD systems.    Copyright 2002 Free Software Foundation, Inc.    Contributed by Wasabi Systems, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_comment
comment|/* FIXME: sysv4.h should not define this! */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       NETBSD_OS_CPP_BUILTINS_ELF();		\       builtin_define ("__powerpc__");		\       builtin_assert ("cpu=powerpc");		\       builtin_assert ("machine=powerpc");	\     }						\   while (0)
end_define

begin_comment
comment|/* Override the default from rs6000.h to avoid conflicts with macros    defined in NetBSD header files.  */
end_comment

begin_undef
undef|#
directive|undef
name|RS6000_CPU_CPP_ENDIAN_BUILTINS
end_undef

begin_define
define|#
directive|define
name|RS6000_CPU_CPP_ENDIAN_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       if (BYTES_BIG_ENDIAN)			\ 	{					\ 	  builtin_define ("__BIG_ENDIAN__");	\ 	  builtin_assert ("machine=bigendian");	\ 	}					\       else					\ 	{					\ 	  builtin_define ("__LITTLE_ENDIAN__");	\ 	  builtin_assert ("machine=littleendian"); \ 	}					\     }						\   while (0)
end_define

begin_comment
comment|/* Make GCC agree with<machine/ansi.h>.  */
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
comment|/* Undo the spec mess from sysv4.h, and just define the specs    the way NetBSD systems actually expect.  */
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
value|NETBSD_CPP_SPEC
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
define|\
value|"%{!msdata=none:%{G*}} %{msdata=none:-G0} \    %(netbsd_link_spec)"
end_define

begin_define
define|#
directive|define
name|NETBSD_ENTRY_POINT
value|"_start"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|NETBSD_STARTFILE_SPEC
end_define

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
value|"crtsavres%O%s %(netbsd_endfile_spec)"
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
value|NETBSD_LIB_SPEC
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
value|{ "netbsd_link_spec",		NETBSD_LINK_SPEC_ELF },		\   { "netbsd_entry_point",	NETBSD_ENTRY_POINT },		\   { "netbsd_endfile_spec",	NETBSD_ENDFILE_SPEC },
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
value|fprintf (stderr, " (NetBSD/powerpc ELF)");
end_define

end_unit

