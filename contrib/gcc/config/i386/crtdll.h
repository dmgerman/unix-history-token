begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on Windows32, using GNU tools and the Windows32 API Library.    This variant uses CRTDLL.DLL instead of MSVCRTDLL.DLL.    Copyright (C) 1998, 1999, 2000 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|EXTRA_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do								\     {								\       builtin_define ("__CRTDLL__");				\       builtin_define ("__MINGW32__");			   	\       builtin_define ("_WIN32");				\       builtin_define_std ("WIN32");				\       builtin_define_std ("WINNT");				\     }								\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
define|\
value|"%{mthreads:-lmingwthrd} -lmingw32 -lgcc -lcoldname -libmingwex -lcrtdll"
end_define

begin_comment
comment|/* Specify a different entry point when linking a DLL */
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
value|"%{shared|mdll:dllcrt1%O%s} \   %{!shared:%{!mdll:crt1%O%s}} %{pg:gcrt1%O%s}"
end_define

end_unit

