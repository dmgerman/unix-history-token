begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC,    for x86-64/ELF NetBSD systems.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Wasabi Systems, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       NETBSD_OS_CPP_BUILTINS_ELF();		\     }						\   while (0)
end_define

begin_comment
comment|/* Extra specs needed for NetBSD/x86-64 ELF.  */
end_comment

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
value|{ "netbsd_cpp_spec", NETBSD_CPP_SPEC },	\   { "netbsd_link_spec", NETBSD_LINK_SPEC_ELF },	\   { "netbsd_entry_point", NETBSD_ENTRY_POINT },
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for a NetBSD/x86-64 ELF target.  */
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
value|"%{m32:-m elf_i386} \    %{m64:-m elf_x86_64} \    %(netbsd_link_spec)"
end_define

begin_define
define|#
directive|define
name|NETBSD_ENTRY_POINT
value|"_start"
end_define

begin_comment
comment|/* Provide a CPP_SPEC appropriate for NetBSD.  */
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
value|"%(netbsd_cpp_spec)"
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

begin_comment
comment|/* Attempt to enable execute permissions on the stack.  */
end_comment

begin_define
define|#
directive|define
name|ENABLE_EXECUTE_STACK
value|NETBSD_ENABLE_EXECUTE_STACK
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (NetBSD/x86_64 ELF)");
end_define

end_unit

