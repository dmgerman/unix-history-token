begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on Windows32, using GNU tools and the Windows32 API Library.    Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|fprintf (stderr, " (x86 MinGW)");
end_define

begin_comment
comment|/* See i386/crtdll.h for an alternative definition.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do								\     {								\       builtin_define ("__MSVCRT__");				\       builtin_define ("__MINGW32__");			   	\       builtin_define ("_WIN32");				\       builtin_define_std ("WIN32");				\       builtin_define_std ("WINNT");				\     }								\   while (0)
end_define

begin_comment
comment|/* Override the standard choice of /usr/include as the default prefix    to try when searching for header files.  */
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
value|"/mingw/include"
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
value|"%{posix:-D_POSIX_SOURCE} %{mthreads:-D_MT}"
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
value|"%{mthreads:-lmingwthrd} -lmingw32 -lgcc -lmoldname -lmingwex -lmsvcrt"
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
comment|/* An additional prefix to try after the standard prefixes.  */
end_comment

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/mingw/lib/"
end_define

begin_comment
comment|/* Output STRING, a string representing a filename, to FILE.    We canonicalize it to be in Unix format (backslashes are replaced    forward slashes.  */
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
value|do {						         \   char c;					         \ 						         \   putc ('\"', asm_file);			         \ 						         \   while ((c = *string++) != 0)			         \     {						         \       if (c == '\\')				         \ 	c = '/';				         \ 						         \       if (ISPRINT (c))                                   \         {                                                \           if (c == '\"')			         \ 	    putc ('\\', asm_file);		         \           putc (c, asm_file);			         \         }                                                \       else                                               \         fprintf (asm_file, "\\%03o", (unsigned char) c); \     }						         \ 						         \   putc ('\"', asm_file);			         \ } while (0)
end_define

begin_comment
comment|/* Define as short unsigned for compatibility with MS runtime.  */
end_comment

begin_undef
undef|#
directive|undef
name|WINT_TYPE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE
value|"short unsigned int"
end_define

end_unit

