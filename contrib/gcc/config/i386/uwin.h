begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on U/WIN (Windows32), using GNU tools and the Windows32 API     Library, as distinct from winnt.h, which is used to build GCC for use     with a windows style library and tool set and uses the Microsoft tools.    Copyright (C) 1999, 2002 Free Software Foundation, Inc.    Contributed by Mumit Khan<khan@xraylith.wisc.edu>.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Most of this is the same as for Cygwin32, except for changing some    specs.  */
end_comment

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_COMPONENT
value|"UWIN"
end_define

begin_define
define|#
directive|define
name|SYSTEM_INCLUDE_DIR
value|"/usr/gnu/include"
end_define

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/gnu/lib/"
end_define

begin_undef
undef|#
directive|undef
name|MAYBE_UWIN_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|MAYBE_UWIN_CPP_BUILTINS
parameter_list|()
define|\
value|do							\     {							\ 	builtin_define_std ("WINNT");			\ 	builtin_define ("_WIN32");			\ 	builtin_define ("__WIN32__");			\ 	builtin_define ("_UWIN");			\ 	builtin_define ("__UWIN__");			\ 	builtin_define ("__MSVCRT__");			\ 	builtin_define ("_STD_INCLUDE_DIR=mingw32");	\     }							\   while (0)
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
value|"-remap %{posix:-D_POSIX_SOURCE} \   -include /usr/include/astwin32.h \   -idirafter /usr/gnu/include/mingw32"
end_define

begin_comment
comment|/* For Windows applications, include more libraries, but always include    kernel32.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{pg:-lgmon} %{mwindows:-luser32 -lgdi32 -lcomdlg32} -lkernel32 -ladvapi32"
end_define

begin_comment
comment|/* This is needed in g77spec.c for now. Will be removed in the future.  */
end_comment

begin_define
define|#
directive|define
name|WIN32_UWIN_TARGET
value|1
end_define

begin_comment
comment|/* Include in the mingw32 libraries with libgcc */
end_comment

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"-lgnuwin -lposix -lgcc -last -lmoldname -lmsvcrt"
end_define

begin_comment
comment|/* Specify a different entry point when linking a DLL */
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
value|"%{mwindows:--subsystem windows} %{mdll:--dll -e _DllMainCRTStartup@12} \   %{!mdll:-u _main}"
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
value|"%{mdll:dllcrt2%O%s} %{!mdll:crt2%O%s} %{pg:gcrt2%O%s}"
end_define

begin_comment
comment|/* These are PE BFD bug workarounds. Should go away eventually.  */
end_comment

begin_comment
comment|/* Write the extra assembler code needed to declare a function    properly.  If we are generating SDB debugging information, this    will happen automatically, so we only need to handle other cases.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do									\     {									\       if (i386_pe_dllexport_name_p (NAME))				\ 	i386_pe_record_exported_symbol (NAME, 0);			\
comment|/* UWIN binutils bug workaround.  */
value|\       if (0&& write_symbols != SDB_DEBUG)				\ 	i386_pe_declare_function_type (FILE, NAME, TREE_PUBLIC (DECL));	\       ASM_OUTPUT_LABEL (FILE, NAME);					\     }									\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_EXTERNAL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_EXTERNAL_LIBCALL
end_undef

begin_comment
comment|/* Override Cygwin's definition. This is necessary now due to the way    Cygwin profiling code is written. Once "fixed", we can remove this.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_PROLOGUE
end_undef

end_unit

