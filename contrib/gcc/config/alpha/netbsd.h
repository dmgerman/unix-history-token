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

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {					\ 	NETBSD_OS_CPP_BUILTINS_ELF();		\ 	NETBSD_OS_CPP_BUILTINS_LP64();		\     } while (0)
end_define

begin_comment
comment|/* NetBSD doesn't use the LANGUAGE* built-ins.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_LANGUAGE_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_LANGUAGE_CPP_BUILTINS
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

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
comment|/* Provide a CPP_SUBTARGET_SPEC appropriate for NetBSD/alpha.  We use    this to pull in CPP specs that all NetBSD configurations need.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|NETBSD_CPP_SPEC
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
value|{ "netbsd_link_spec", NETBSD_LINK_SPEC_ELF },	\   { "netbsd_entry_point", NETBSD_ENTRY_POINT },	\   { "netbsd_endfile_spec", NETBSD_ENDFILE_SPEC },
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for a NetBSD/alpha ELF target.  */
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
value|"%{G*} %{relax:-relax} \    %{O*:-O3} %{!O*:-O1} \    %(netbsd_link_spec)"
end_define

begin_define
define|#
directive|define
name|NETBSD_ENTRY_POINT
value|"__start"
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
value|"%{ffast-math|funsafe-math-optimizations:crtfm%O%s} \    %(netbsd_endfile_spec)"
end_define

begin_comment
comment|/* Attempt to enable execute permissions on the stack.  */
end_comment

begin_define
define|#
directive|define
name|TRANSFER_FROM_TRAMPOLINE
value|NETBSD_ENABLE_EXECUTE_STACK
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

