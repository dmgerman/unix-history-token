begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on Windows32, using GNU tools and the Windows32 API Library.    Copyright (C) 1997, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Most of this is the same as for cygwin, except for changing some    specs.  */
end_comment

begin_comment
comment|/* Mingw GCC, unlike Cygwin's, must be relocatable. This macro must     be defined before any other files are included.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32_NO_ABSOLUTE_INST_DIRS
end_ifndef

begin_define
define|#
directive|define
name|WIN32_NO_ABSOLUTE_INST_DIRS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"i386/cygwin.h"
end_include

begin_define
define|#
directive|define
name|TARGET_EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_comment
comment|/* Please keep changes to CPP_PREDEFINES in sync with i386/crtdll. The    only difference between the two should be __MSVCRT__ needed to     distinguish MSVC from CRTDLL runtime in mingw headers.  */
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
value|"-D_WIN32 -D__WIN32 -D__WIN32__ -DWIN32 \   -D__MINGW32__ -D__MSVCRT__ -DWINNT -D_X86_=1 \   -Asystem=winnt"
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
value|"/usr/local/mingw32/include"
end_define

begin_undef
undef|#
directive|undef
name|STANDARD_INCLUDE_COMPONENT
end_undef

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_COMPONENT
value|"MINGW"
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
define|\
value|"-remap %(cpp_cpu) %{posix:-D_POSIX_SOURCE} %{mthreads:-D_MT} \   -D__stdcall=__attribute__((__stdcall__)) \   -D__cdecl=__attribute__((__cdecl__)) \   %{!ansi:-D_stdcall=__attribute__((__stdcall__)) \     -D_cdecl=__attribute__((__cdecl__))} \   -D__declspec(x)=__attribute__((x))"
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
value|"%{pg:-lgmon} %{mwindows:-lgdi32 -lcomdlg32} \                   -luser32 -lkernel32 -ladvapi32 -lshell32"
end_define

begin_comment
comment|/* Include in the mingw32 libraries with libgcc */
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
value|"%{mwindows:--subsystem windows} \   %{mconsole:--subsystem console} \   %{shared: %{mdll: %eshared and mdll are not compatible}} \   %{shared: --shared} %{mdll:--dll} \   %{static:-Bstatic} %{!static:-Bdynamic} \   %{shared|mdll: -e _DllMainCRTStartup@12}"
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
define|\
value|"%{mthreads:-lmingwthrd} -lmingw32 -lgcc -lmoldname -lmsvcrt"
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
value|"%{shared|mdll:dllcrt2%O%s} \   %{!shared:%{!mdll:crt2%O%s}} %{pg:gcrt2%O%s}"
end_define

begin_comment
comment|/* MS runtime does not need a separate math library.  */
end_comment

begin_undef
undef|#
directive|undef
name|MATH_LIBRARY
end_undef

begin_define
define|#
directive|define
name|MATH_LIBRARY
value|""
end_define

begin_comment
comment|/* Output STRING, a string representing a filename, to FILE.    We canonicalize it to be in MS-DOS format.  */
end_comment

begin_undef
undef|#
directive|undef
name|OUTPUT_QUOTED_STRING
end_undef

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
value|do {						\   char c;					\ 						\   putc ('\"', asm_file);			\ 						\   while ((c = *string++) != 0)			\     {						\       if (c == '\\')				\ 	c = '/';				\ 						\       if (c == '\"')				\ 	putc ('\\', asm_file);			\       putc (c, asm_file);			\     }						\ 						\   putc ('\"', asm_file);			\ } while (0)
end_define

begin_comment
comment|/* Override Cygwin's definition. This is necessary now due to the way    Cygwin profiling code is written. Once "fixed", we can remove this.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_PROLOGUE
end_undef

end_unit

