begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Linux-based GNU systems with ELF format    Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.    Contributed by Eric Youngdale.    Modified for stabs-in-ELF by H.J. Lu (hjl@lucon.org).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Don't assume anything about the header files. */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ATEXIT
end_undef

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* GNU/Linux uses ctype from glibc.a. I am not sure how complete it is.    For now, we play safe. It may change later. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_undef
undef|#
directive|undef
name|MULTIBYTE_CHARS
end_undef

begin_define
define|#
directive|define
name|MULTIBYTE_CHARS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_define
define|#
directive|define
name|SET_ASM_OP
value|".set"
end_define

begin_comment
comment|/* Use stabs instead of DWARF debug format.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_include
include|#
directive|include
file|"svr4.h"
end_include

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_comment
comment|/* Output at beginning of assembler file.  */
end_comment

begin_comment
comment|/* The .file command should always begin the output.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {									\ 	output_file_directive (FILE, main_input_filename);		\ 	fprintf (FILE, "\t.version\t\"01.01\"\n");			\   } while (0)
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for GNU/Linux.  Here we add    the GNU/Linux magical crtbegin.o file (see crtstuff.c) which    provides part of the support for getting C++ file-scope static    object constructed before entering `main'. */
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
define|\
value|"%{!shared: \      %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} \ 		       %{!p:%{profile:gcrt1.o%s} \ 			 %{!profile:crt1.o%s}}}} \    crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for GNU/Linux.  Here we tack on    the GNU/Linux magical crtend.o file (see crtstuff.c) which    provides part of the support for getting C++ file-scope static    object constructed before entering `main', followed by a normal    GNU/Linux "finalizer" file, `crtn.o'.  */
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
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
end_define

begin_comment
comment|/* This is for -profile to use -lc_p instead of -lc. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CC1_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{profile:-p}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_GNULIBC_1
end_ifndef

begin_undef
undef|#
directive|undef
name|DEFAULT_VTABLE_THUNKS
end_undef

begin_define
define|#
directive|define
name|DEFAULT_VTABLE_THUNKS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_comment
comment|/* We no longer link with libc_p.a or libg.a by default. If you    want to profile or debug the GNU/Linux C library, please add    -profile or -ggdb to LDFLAGS at the link time, respectively. */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{!shared: %{p:-lgmon} %{pg:-lgmon} %{profile:-lgmon -lc_p} \      %{!profile:%{!ggdb:-lc} %{ggdb:-lg}}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{shared: -lc} \    %{!shared: %{mieee-fp:-lieee} %{pthread:-lpthread} \ 	%{profile:-lc_p} %{!profile: -lc}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{!shared: \      %{p:-lgmon -lc_p} %{pg:-lgmon -lc_p} \        %{!p:%{!pg:%{!g*:-lc} %{g*:-lg}}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

