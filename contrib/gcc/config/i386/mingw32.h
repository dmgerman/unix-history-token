begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on Windows32, using GNU tools and the Windows32 API Library,    as distinct from winnt.h, which is used to build GCC for use with a    windows style library and tool set and uses the Microsoft tools.    Copyright (C) 1997, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/* Most of this is the same as for Cygwin32, except for changing some    specs.  */
end_comment

begin_include
include|#
directive|include
file|"i386/cygwin32.h"
end_include

begin_comment
comment|/* Please keep changes to CPP_PREDEFINES in sync with i386/crtdll. The    only difference between the two should be __MSVCRT__ needed to     distinguish MSVC from CRTDLL runtime in mingw headers. */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Di386 -D_WIN32 -DWIN32 -D__WIN32__ \   -D__MINGW32__ -D__MSVCRT__ -DWINNT  -D_X86_=1 -D__STDC__=1\   -D__stdcall=__attribute__((__stdcall__)) \   -D_stdcall=__attribute__((__stdcall__)) \   -D__cdecl=__attribute__((__cdecl__)) \   -D__declspec(x)=__attribute__((x)) \   -Asystem(winnt) -Acpu(i386) -Amachine(i386)"
end_define

begin_comment
comment|/* Specific a different directory for the standard include files.  */
end_comment

begin_undef
undef|#
directive|undef
name|STANDARD_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|"/usr/local/i386-mingw32/include"
end_define

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_COMPONENT
value|"MINGW32"
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
value|"%{mwindows:-luser32 -lgdi32 -lcomdlg32} -lkernel32 -ladvapi32 -lshell32"
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
value|"-lmingw32 -lgcc -lmoldname -lmsvcrt"
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
value|"%{mwindows:--subsystem windows} %{mdll:--dll -e _DllMainCRTStartup@12}"
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
value|"%{mdll:dllcrt2%O%s} %{!mdll:crt2%O%s}"
end_define

begin_define
define|#
directive|define
name|MATH_LIBRARY
value|"-lmsvcrt"
end_define

begin_comment
comment|/* Output STRING, a string representing a filename, to FILE.  We canonicalize    it to be in MS-DOS format.  */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_QUOTED_STRING
parameter_list|(
name|FILE
parameter_list|,
name|STRING
parameter_list|)
define|\
value|do {						\   char c;					\ 						\   putc ('\"', asm_file);			\   if (STRING[1] == ':'				\&& (STRING[2] == '/' || STRING[2] == '\\')) \     {						\       putc ('/', asm_file);			\       putc ('/', asm_file);			\       putc (*string, asm_file);			\       string += 2;				\     }						\ 						\   while ((c = *string++) != 0)			\     {						\       if (c == '\\')				\ 	c = '/';				\ 						\       if (c == '\"')				\ 	putc ('\\', asm_file);			\       putc (c, asm_file);			\     }						\ 						\   putc ('\"', asm_file);			\ } while (0)
end_define

end_unit

