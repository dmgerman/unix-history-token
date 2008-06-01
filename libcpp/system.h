begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Get common system includes and various definitions and declarations based    on autoconf macros.    Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.  This file is part of libcpp (aka cpplib).  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBCPP_SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|LIBCPP_SYSTEM_H
end_define

begin_comment
comment|/* We must include stdarg.h before stdio.h.  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDDEF_H
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Define a generic NULL if one hasn't already been defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use the unlocked open routines from libiberty.  */
end_comment

begin_define
define|#
directive|define
name|fopen
parameter_list|(
name|PATH
parameter_list|,
name|MODE
parameter_list|)
value|fopen_unlocked(PATH,MODE)
end_define

begin_define
define|#
directive|define
name|fdopen
parameter_list|(
name|FILDES
parameter_list|,
name|MODE
parameter_list|)
value|fdopen_unlocked(FILDES,MODE)
end_define

begin_define
define|#
directive|define
name|freopen
parameter_list|(
name|PATH
parameter_list|,
name|MODE
parameter_list|,
name|STREAM
parameter_list|)
value|freopen_unlocked(PATH,MODE,STREAM)
end_define

begin_comment
comment|/* The compiler is not a multi-threaded application and therefore we    do not have to use the locking functions.  In fact, using the locking    functions can cause the compiler to be significantly slower under    I/O bound conditions (such as -g -O0 on very large source files).     HAVE_DECL_PUTC_UNLOCKED actually indicates whether or not the stdio    code is multi-thread safe by default.  If it is set to 0, then do    not worry about using the _unlocked functions.     fputs_unlocked, fwrite_unlocked, and fprintf_unlocked are    extensions and need to be prototyped by hand (since we do not    define _GNU_SOURCE).  */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_DECL_PUTC_UNLOCKED
operator|&&
name|HAVE_DECL_PUTC_UNLOCKED
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PUTC_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|C
parameter_list|,
name|Stream
parameter_list|)
value|putc_unlocked (C, Stream)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PUTCHAR_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|C
parameter_list|)
value|putchar_unlocked (C)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GETC_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|getc
end_undef

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|Stream
parameter_list|)
value|getc_unlocked (Stream)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GETCHAR_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|getchar_unlocked ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FPUTC_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|fputc
end_undef

begin_define
define|#
directive|define
name|fputc
parameter_list|(
name|C
parameter_list|,
name|Stream
parameter_list|)
value|fputc_unlocked (C, Stream)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CLEARERR_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|clearerr
end_undef

begin_define
define|#
directive|define
name|clearerr
parameter_list|(
name|Stream
parameter_list|)
value|clearerr_unlocked (Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_CLEARERR_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_CLEARERR_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|void
name|clearerr_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FEOF_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|feof
end_undef

begin_define
define|#
directive|define
name|feof
parameter_list|(
name|Stream
parameter_list|)
value|feof_unlocked (Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FEOF_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FEOF_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|int
name|feof_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FILENO_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|fileno
end_undef

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|Stream
parameter_list|)
value|fileno_unlocked (Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FILENO_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FILENO_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|int
name|fileno_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FFLUSH_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|fflush
end_undef

begin_define
define|#
directive|define
name|fflush
parameter_list|(
name|Stream
parameter_list|)
value|fflush_unlocked (Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FFLUSH_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FFLUSH_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|int
name|fflush_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FGETC_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|fgetc
end_undef

begin_define
define|#
directive|define
name|fgetc
parameter_list|(
name|Stream
parameter_list|)
value|fgetc_unlocked (Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FGETC_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FGETC_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|int
name|fgetc_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FGETS_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|fgets
end_undef

begin_define
define|#
directive|define
name|fgets
parameter_list|(
name|S
parameter_list|,
name|n
parameter_list|,
name|Stream
parameter_list|)
value|fgets_unlocked (S, n, Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FGETS_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FGETS_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|fgets_unlocked
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FPUTS_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|fputs
end_undef

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|String
parameter_list|,
name|Stream
parameter_list|)
value|fputs_unlocked (String, Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FPUTS_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FPUTS_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|int
name|fputs_unlocked
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FERROR_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|ferror
end_undef

begin_define
define|#
directive|define
name|ferror
parameter_list|(
name|Stream
parameter_list|)
value|ferror_unlocked (Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FERROR_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FERROR_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|int
name|ferror_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FREAD_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|fread
end_undef

begin_define
define|#
directive|define
name|fread
parameter_list|(
name|Ptr
parameter_list|,
name|Size
parameter_list|,
name|N
parameter_list|,
name|Stream
parameter_list|)
value|fread_unlocked (Ptr, Size, N, Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FREAD_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FREAD_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|size_t
name|fread_unlocked
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FWRITE_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|fwrite
end_undef

begin_define
define|#
directive|define
name|fwrite
parameter_list|(
name|Ptr
parameter_list|,
name|Size
parameter_list|,
name|N
parameter_list|,
name|Stream
parameter_list|)
value|fwrite_unlocked (Ptr, Size, N, Stream)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FWRITE_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FWRITE_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|size_t
name|fwrite_unlocked
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FPRINTF_UNLOCKED
end_ifdef

begin_undef
undef|#
directive|undef
name|fprintf
end_undef

begin_comment
comment|/* We can't use a function-like macro here because we don't know if    we have varargs macros.  */
end_comment

begin_define
define|#
directive|define
name|fprintf
value|fprintf_unlocked
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_FPRINTF_UNLOCKED
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FPRINTF_UNLOCKED
end_if

begin_function_decl
specifier|extern
name|int
name|fprintf_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ??? Glibc's fwrite/fread_unlocked macros cause    "warning: signed and unsigned type in conditional expression".  */
end_comment

begin_undef
undef|#
directive|undef
name|fread_unlocked
end_undef

begin_undef
undef|#
directive|undef
name|fwrite_unlocked
end_undef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|errno
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_DECL_ERRNO
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_ERRNO
end_if

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some of glibc's string inlines cause warnings.  Plus we'd rather    rely on (and therefore test) GCC's string builtins.  */
end_comment

begin_define
define|#
directive|define
name|__NO_STRING_INLINES
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STRING_WITH_STRINGS
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_LIMITS_H
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Infrastructure for defining missing _MAX and _MIN macros.  Note that    macros defined with these cannot be used in #if.  */
end_comment

begin_comment
comment|/* The extra casts work around common compiler bugs.  */
end_comment

begin_define
define|#
directive|define
name|INTTYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_comment
comment|/* The outer cast is needed to work around a bug in Cray C 5.0.3.0.    It is necessary at least when t == time_t.  */
end_comment

begin_define
define|#
directive|define
name|INTTYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (INTTYPE_SIGNED (t) \                              ? ~ (t) 0<< (sizeof(t) * CHAR_BIT - 1) : (t) 0))
end_define

begin_define
define|#
directive|define
name|INTTYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (~ (t) 0 - INTTYPE_MINIMUM (t)))
end_define

begin_comment
comment|/* Use that infrastructure to provide a few constants.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|UCHAR_MAX
value|INTTYPE_MAXIMUM (unsigned char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LANGINFO_CODESET
end_ifdef

begin_include
include|#
directive|include
file|<langinfo.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETLOCALE
end_ifndef

begin_define
define|#
directive|define
name|setlocale
parameter_list|(
name|category
parameter_list|,
name|locale
parameter_list|)
value|(locale)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Stubs.  */
end_comment

begin_undef
undef|#
directive|undef
name|dgettext
end_undef

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|package
parameter_list|,
name|msgid
parameter_list|)
value|(msgid)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_
end_ifndef

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|dgettext (PACKAGE, msgid)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_
end_ifndef

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|msgid
parameter_list|)
value|msgid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some systems define these in, e.g., param.h.  We undefine these names    here to avoid the warnings.  We prefer to use our definitions since we    know they are correct.  */
end_comment

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|((X)< (Y) ? (X) : (Y))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|((X)> (Y) ? (X) : (Y))
end_define

begin_comment
comment|/* The HAVE_DECL_* macros are three-state, undefined, 0 or 1.  If they    are defined to 0 then we must provide the relevant declaration    here.  These checks will be in the undefined state while configure    is running so be careful to test "defined (HAVE_DECL_*)".  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_ABORT
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_ABORT
end_if

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SYS_STAT_H
end_if

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test if something is a normal file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test if something is a directory.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test if something is a character special file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISCHR
end_ifndef

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFCHR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test if something is a block special file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISBLK
end_ifndef

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFBLK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test if something is a socket.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISSOCK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFSOCK
end_ifdef

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFSOCK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test if something is a FIFO.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISFIFO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFIFO
end_ifdef

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFIFO)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Approximate O_NOCTTY and O_BINARY.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_NOCTTY
end_ifndef

begin_define
define|#
directive|define
name|O_NOCTTY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Filename handling macros.  */
end_comment

begin_include
include|#
directive|include
file|"filenames.h"
end_include

begin_comment
comment|/* Get libiberty declarations.  */
end_comment

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_include
include|#
directive|include
file|"safe-ctype.h"
end_include

begin_comment
comment|/* 1 if we have C99 designated initializers.     ??? C99 designated initializers are not supported by most C++    compilers, including G++.  -- gdr, 2005-05-18  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_DESIGNATED_INITIALIZERS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_DESIGNATED_INITIALIZERS
define|\
value|((!defined(__cplusplus)&& (GCC_VERSION>= 2007)) \    || (__STDC_VERSION__>= 199901L))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Be conservative and only use enum bitfields with GCC.    FIXME: provide a complete autoconf test for buggy enum bitfields.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|>
literal|2000
operator|)
end_if

begin_define
define|#
directive|define
name|ENUM_BITFIELD
parameter_list|(
name|TYPE
parameter_list|)
value|__extension__ enum TYPE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENUM_BITFIELD
parameter_list|(
name|TYPE
parameter_list|)
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|TYPE
parameter_list|,
name|MEMBER
parameter_list|)
value|((size_t)&((TYPE *) 0)->MEMBER)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __builtin_expect(A, B) evaluates to A, but notifies the compiler that    the most likely value of A is B.  This feature was added at some point    between 2.95 and 3.0.  Let's use 3.0 as the lower bound for now.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|<
literal|3000
operator|)
end_if

begin_define
define|#
directive|define
name|__builtin_expect
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide a fake boolean type.  We make no attempt to use the    C99 _Bool, as it may not be available in the bootstrap compiler,    and even if it is, it is liable to be buggy.      This must be after all inclusion of system headers, as some of    them will mess us up.  */
end_comment

begin_undef
undef|#
directive|undef
name|bool
end_undef

begin_undef
undef|#
directive|undef
name|true
end_undef

begin_undef
undef|#
directive|undef
name|false
end_undef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_define
define|#
directive|define
name|bool
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_comment
comment|/* Some compilers do not allow the use of unsigned char in bitfields.  */
end_comment

begin_define
define|#
directive|define
name|BOOL_BITFIELD
value|unsigned int
end_define

begin_comment
comment|/* Poison identifiers we do not want to use.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|>=
literal|3000
operator|)
end_if

begin_undef
undef|#
directive|undef
name|calloc
end_undef

begin_undef
undef|#
directive|undef
name|strdup
end_undef

begin_undef
undef|#
directive|undef
name|malloc
end_undef

begin_undef
undef|#
directive|undef
name|realloc
end_undef

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|calloc
name|strdup
end_pragma

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|malloc
name|realloc
end_pragma

begin_comment
comment|/* Libiberty macros that are no longer used in GCC.  */
end_comment

begin_undef
undef|#
directive|undef
name|ANSI_PROTOTYPES
end_undef

begin_undef
undef|#
directive|undef
name|PTR_CONST
end_undef

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE
end_undef

begin_undef
undef|#
directive|undef
name|VPARAMS
end_undef

begin_undef
undef|#
directive|undef
name|VA_OPEN
end_undef

begin_undef
undef|#
directive|undef
name|VA_FIXEDARG
end_undef

begin_undef
undef|#
directive|undef
name|VA_CLOSE
end_undef

begin_undef
undef|#
directive|undef
name|VA_START
end_undef

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|ANSI_PROTOTYPES
name|PTR_CONST
name|LONG_DOUBLE
name|VPARAMS
name|VA_OPEN
pragma|\
name|VA_FIXEDARG
name|VA_CLOSE
name|VA_START
end_pragma

begin_comment
comment|/* Note: not all uses of the `index' token (e.g. variable names and    structure members) have been eliminated.  */
end_comment

begin_undef
undef|#
directive|undef
name|bcopy
end_undef

begin_undef
undef|#
directive|undef
name|bzero
end_undef

begin_undef
undef|#
directive|undef
name|bcmp
end_undef

begin_undef
undef|#
directive|undef
name|rindex
end_undef

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|bcopy
name|bzero
name|bcmp
name|rindex
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC>= 3.0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! LIBCPP_SYSTEM_H */
end_comment

end_unit

