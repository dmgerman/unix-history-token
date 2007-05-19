begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Get common system includes and various definitions and declarations based    on autoconf macros.    Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_SYSTEM_H
end_define

begin_comment
comment|/* We must include stdarg.h before stdio.h.  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|va_copy
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__va_copy
end_ifdef

begin_define
define|#
directive|define
name|va_copy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|__va_copy((d),(s))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_copy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|((d) = (s))
end_define

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

begin_comment
comment|/* There are an extraordinary number of issues with<ctype.h>.    The last straw is that it varies with the locale.  Use libiberty's    replacement instead.  */
end_comment

begin_include
include|#
directive|include
file|<safe-ctype.h>
end_include

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

begin_comment
comment|/* If we don't have an overriding definition, set SUCCESS_EXIT_CODE and    FATAL_EXIT_CODE to EXIT_SUCCESS and EXIT_FAILURE respectively,    or 0 and 1 if those macros are not defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUCCESS_EXIT_CODE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|EXIT_SUCCESS
end_ifdef

begin_define
define|#
directive|define
name|SUCCESS_EXIT_CODE
value|EXIT_SUCCESS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SUCCESS_EXIT_CODE
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

begin_ifndef
ifndef|#
directive|ifndef
name|FATAL_EXIT_CODE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|EXIT_FAILURE
end_ifdef

begin_define
define|#
directive|define
name|FATAL_EXIT_CODE
value|EXIT_FAILURE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FATAL_EXIT_CODE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ICE_EXIT_CODE
value|4
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* We use this identifier later and it appears in some vendor param.h's.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFETCH
end_undef

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
comment|/* Get definitions of HOST_WIDE_INT and HOST_WIDEST_INT.  */
end_comment

begin_include
include|#
directive|include
file|"hwint.h"
end_include

begin_comment
comment|/* A macro to determine whether a VALUE lies inclusively within a    certain range without evaluating the VALUE more than once.  This    macro won't warn if the VALUE is unsigned and the LOWER bound is    zero, as it would e.g. with "VALUE>= 0&& ...".  Note the LOWER    bound *is* evaluated twice, and LOWER must not be greater than    UPPER.  However the bounds themselves can be either positive or    negative.  */
end_comment

begin_define
define|#
directive|define
name|IN_RANGE
parameter_list|(
name|VALUE
parameter_list|,
name|LOWER
parameter_list|,
name|UPPER
parameter_list|)
define|\
value|((unsigned HOST_WIDE_INT)((VALUE) - (LOWER))<= ((UPPER) - (LOWER)))
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_WRONLY
end_ifndef

begin_define
define|#
directive|define
name|O_WRONLY
value|1
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
comment|/* Returns the least number N such that N * Y>= X.  */
end_comment

begin_define
define|#
directive|define
name|CEIL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) + (y) - 1) / (y))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFSIGNALED
end_ifndef

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|S
parameter_list|)
value|(((S)& 0xff) != 0&& ((S)& 0xff) != 0x7f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WTERMSIG
end_ifndef

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|S
parameter_list|)
value|((S)& 0x7f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|S
parameter_list|)
value|(((S)& 0xff) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|S
parameter_list|)
value|(((S)& 0xff00)>> 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSTOPSIG
end_ifndef

begin_define
define|#
directive|define
name|WSTOPSIG
value|WEXITSTATUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCOREDUMP
end_ifndef

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|S
parameter_list|)
value|((S)& WCOREFLG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCOREFLG
end_ifndef

begin_define
define|#
directive|define
name|WCOREFLG
value|0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The HAVE_DECL_* macros are three-state, undefined, 0 or 1.  If they    are defined to 0 then we must provide the relevant declaration    here.  These checks will be in the undefined state while configure    is running so be careful to test "defined (HAVE_DECL_*)".  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_ATOF
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_ATOF
end_if

begin_function_decl
specifier|extern
name|double
name|atof
parameter_list|(
specifier|const
name|char
modifier|*
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
name|defined
argument_list|(
name|HAVE_DECL_ATOL
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_ATOL
end_if

begin_function_decl
specifier|extern
name|long
name|atol
parameter_list|(
specifier|const
name|char
modifier|*
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
name|defined
argument_list|(
name|HAVE_DECL_FREE
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_FREE
end_if

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|(
name|void
modifier|*
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
name|defined
argument_list|(
name|HAVE_DECL_GETCWD
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_GETCWD
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|getcwd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
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
name|defined
argument_list|(
name|HAVE_DECL_GETENV
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_GETENV
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|(
specifier|const
name|char
modifier|*
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
name|defined
argument_list|(
name|HAVE_DECL_GETOPT
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_GETOPT
end_if

begin_function_decl
specifier|extern
name|int
name|getopt
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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
name|defined
argument_list|(
name|HAVE_DECL_GETPAGESIZE
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_GETPAGESIZE
end_if

begin_function_decl
specifier|extern
name|int
name|getpagesize
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
name|defined
argument_list|(
name|HAVE_DECL_GETWD
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_GETWD
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|(
name|char
modifier|*
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
name|defined
argument_list|(
name|HAVE_DECL_SBRK
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_SBRK
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|sbrk
parameter_list|(
name|int
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
name|defined
argument_list|(
name|HAVE_DECL_STRSTR
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_STRSTR
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|strstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MALLOC_H
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_MALLOC
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_MALLOC
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
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
name|defined
argument_list|(
name|HAVE_DECL_CALLOC
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_CALLOC
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
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
name|defined
argument_list|(
name|HAVE_DECL_REALLOC
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_REALLOC
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the system doesn't provide strsignal, we get it defined in    libiberty but no declaration is supplied.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STRSIGNAL
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|HAVE_DECL_STRSIGNAL
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_STRSIGNAL
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|strsignal
end_ifndef

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|strsignal
parameter_list|(
name|int
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
name|HAVE_GETRLIMIT
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_GETRLIMIT
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_GETRLIMIT
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|getrlimit
end_ifndef

begin_struct_decl
struct_decl|struct
name|rlimit
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|getrlimit
parameter_list|(
name|int
parameter_list|,
name|struct
name|rlimit
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SETRLIMIT
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_SETRLIMIT
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_SETRLIMIT
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|setrlimit
end_ifndef

begin_struct_decl
struct_decl|struct
name|rlimit
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|setrlimit
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|rlimit
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

begin_endif
endif|#
directive|endif
end_endif

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
name|defined
argument_list|(
name|HAVE_DECL_SNPRINTF
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_SNPRINTF
end_if

begin_function_decl
specifier|extern
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_VSNPRINTF
argument_list|)
operator|&&
operator|!
name|HAVE_DECL_VSNPRINTF
end_if

begin_function_decl
specifier|extern
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 1 if we have C99 designated initializers.  */
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
value|((GCC_VERSION>= 2007) || (__STDC_VERSION__>= 199901L))
end_define

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
comment|/* Define well known filenos if the system does not define them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some systems have mkdir that takes a single argument.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MKDIR_TAKES_ONE_ARG
end_ifdef

begin_define
define|#
directive|define
name|mkdir
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|mkdir(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, colon separates directories in a path.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_SEPARATOR
end_ifndef

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|':'
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
comment|/* These should be phased out in favor of IS_DIR_SEPARATOR, where possible.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIR_SEPARATOR
end_ifndef

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'/'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DOS_BASED_FILE_SYSTEM
end_ifdef

begin_define
define|#
directive|define
name|DIR_SEPARATOR_2
value|'\\'
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
comment|/* Get libiberty declarations.  */
end_comment

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_comment
comment|/* Provide a default for the HOST_BIT_BUCKET.    This suffices for POSIX-like hosts.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_BIT_BUCKET
end_ifndef

begin_define
define|#
directive|define
name|HOST_BIT_BUCKET
value|"/dev/null"
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
comment|/* Various error reporting routines want to use __FUNCTION__.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|<
literal|2007
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__FUNCTION__
end_ifndef

begin_define
define|#
directive|define
name|__FUNCTION__
value|"?"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __FUNCTION__ */
end_comment

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
comment|/* Redefine abort to report an internal error w/o coredump, and    reporting the location of the error in the source file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fancy_abort
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|abort
parameter_list|()
value|fancy_abort (__FILE__, __LINE__, __FUNCTION__)
end_define

begin_comment
comment|/* Use gcc_assert(EXPR) to test invariants.  */
end_comment

begin_if
if|#
directive|if
name|ENABLE_ASSERT_CHECKING
end_if

begin_define
define|#
directive|define
name|gcc_assert
parameter_list|(
name|EXPR
parameter_list|)
define|\
value|((void)(!(EXPR) ? fancy_abort (__FILE__, __LINE__, __FUNCTION__), 0 : 0))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Include EXPR, so that unused variable warnings do not occur.  */
end_comment

begin_define
define|#
directive|define
name|gcc_assert
parameter_list|(
name|EXPR
parameter_list|)
value|((void)(0&& (EXPR)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use gcc_unreachable() to mark unreachable locations (like an    unreachable default case of a switch.  Do not use gcc_assert(0).  */
end_comment

begin_define
define|#
directive|define
name|gcc_unreachable
parameter_list|()
value|(fancy_abort (__FILE__, __LINE__, __FUNCTION__))
end_define

begin_comment
comment|/* Provide a fake boolean type.  We make no attempt to use the    C99 _Bool, as it may not be available in the bootstrap compiler,    and even if it is, it is liable to be buggy.    This must be after all inclusion of system headers, as some of    them will mess us up.  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|/* Obsolete.  */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|true
end_define

begin_define
define|#
directive|define
name|FALSE
value|false
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
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

begin_define
define|#
directive|define
name|bool
value|unsigned char
end_define

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
comment|/* Obsolete.  */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|true
end_define

begin_define
define|#
directive|define
name|FALSE
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__cplusplus */
end_comment

begin_comment
comment|/* Get definition of double_int.  */
end_comment

begin_include
include|#
directive|include
file|"double-int.h"
end_include

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
comment|/* As the last action in this file, we poison the identifiers that    shouldn't be used.  Note, luckily gcc-3.0's token-based integrated    preprocessor won't trip on poisoned identifiers that arrive from    the expansion of macros.  E.g. #define strrchr rindex, won't error    if rindex is poisoned after this directive is issued and later on    strrchr is called.     Note: We define bypass macros for the few cases where we really    want to use the libc memory allocation routines.  Otherwise we    insist you use the "x" versions from libiberty.  */
end_comment

begin_define
define|#
directive|define
name|really_call_malloc
value|malloc
end_define

begin_define
define|#
directive|define
name|really_call_calloc
value|calloc
end_define

begin_define
define|#
directive|define
name|really_call_realloc
value|realloc
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FLEX_SCANNER
argument_list|)
operator|||
name|defined
argument_list|(
name|YYBISON
argument_list|)
operator|||
name|defined
argument_list|(
name|YYBYACC
argument_list|)
end_if

begin_comment
comment|/* Flex and bison use malloc and realloc.  Yuk.  Note that this means    really_call_* cannot be used in a .l or .y file.  */
end_comment

begin_define
define|#
directive|define
name|malloc
value|xmalloc
end_define

begin_define
define|#
directive|define
name|realloc
value|xrealloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|>=
literal|3000
operator|)
end_if

begin_comment
comment|/* Note autoconf checks for prototype declarations and includes    system.h while doing so.  Only poison these tokens if actually    compiling gcc, so that the autoconf declaration tests for malloc    etc don't spuriously fail.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_GCC
end_ifdef

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

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|calloc
name|strdup
end_pragma

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FLEX_SCANNER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|YYBISON
argument_list|)
end_if

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
name|malloc
name|realloc
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Old target macros that have moved to the target hooks structure.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|ASM_OPEN_PAREN
name|ASM_CLOSE_PAREN
pragma|\
name|FUNCTION_PROLOGUE
name|FUNCTION_EPILOGUE
pragma|\
name|FUNCTION_END_PROLOGUE
name|FUNCTION_BEGIN_EPILOGUE
pragma|\
name|DECL_MACHINE_ATTRIBUTES
name|COMP_TYPE_ATTRIBUTES
name|INSERT_ATTRIBUTES
pragma|\
name|VALID_MACHINE_DECL_ATTRIBUTE
name|VALID_MACHINE_TYPE_ATTRIBUTE
pragma|\
name|SET_DEFAULT_TYPE_ATTRIBUTES
name|SET_DEFAULT_DECL_ATTRIBUTES
pragma|\
name|MERGE_MACHINE_TYPE_ATTRIBUTES
name|MERGE_MACHINE_DECL_ATTRIBUTES
pragma|\
name|MD_INIT_BUILTINS
name|MD_EXPAND_BUILTIN
name|ASM_OUTPUT_CONSTRUCTOR
pragma|\
name|ASM_OUTPUT_DESTRUCTOR
name|SIGNED_CHAR_SPEC
name|MAX_CHAR_TYPE_SIZE
pragma|\
name|WCHAR_UNSIGNED
name|UNIQUE_SECTION
name|SELECT_SECTION
name|SELECT_RTX_SECTION
pragma|\
name|ENCODE_SECTION_INFO
name|STRIP_NAME_ENCODING
name|ASM_GLOBALIZE_LABEL
pragma|\
name|ASM_OUTPUT_MI_THUNK
name|CONST_COSTS
name|RTX_COSTS
name|DEFAULT_RTX_COSTS
pragma|\
name|ADDRESS_COST
name|MACHINE_DEPENDENT_REORG
name|ASM_FILE_START
name|ASM_FILE_END
pragma|\
name|ASM_SIMPLIFY_DWARF_ADDR
name|INIT_TARGET_OPTABS
name|INIT_SUBTARGET_OPTABS
pragma|\
name|INIT_GOFAST_OPTABS
name|MULSI3_LIBCALL
name|MULDI3_LIBCALL
name|DIVSI3_LIBCALL
pragma|\
name|DIVDI3_LIBCALL
name|UDIVSI3_LIBCALL
name|UDIVDI3_LIBCALL
name|MODSI3_LIBCALL
pragma|\
name|MODDI3_LIBCALL
name|UMODSI3_LIBCALL
name|UMODDI3_LIBCALL
name|BUILD_VA_LIST_TYPE
pragma|\
name|PRETEND_OUTGOING_VARARGS_NAMED
name|STRUCT_VALUE_INCOMING_REGNUM
pragma|\
name|ASM_OUTPUT_SECTION_NAME
name|PROMOTE_FUNCTION_ARGS
pragma|\
name|STRUCT_VALUE_INCOMING
name|STRICT_ARGUMENT_NAMING
pragma|\
name|PROMOTE_FUNCTION_RETURN
name|PROMOTE_PROTOTYPES
name|STRUCT_VALUE_REGNUM
pragma|\
name|SETUP_INCOMING_VARARGS
name|EXPAND_BUILTIN_SAVEREGS
pragma|\
name|DEFAULT_SHORT_ENUMS
name|SPLIT_COMPLEX_ARGS
name|MD_ASM_CLOBBERS
pragma|\
name|HANDLE_PRAGMA_REDEFINE_EXTNAME
name|HANDLE_PRAGMA_EXTERN_PREFIX
pragma|\
name|MUST_PASS_IN_STACK
name|FUNCTION_ARG_PASS_BY_REFERENCE
pragma|\
name|VECTOR_MODE_SUPPORTED_P
name|TARGET_SUPPORTS_HIDDEN
pragma|\
name|FUNCTION_ARG_PARTIAL_NREGS
name|ASM_OUTPUT_DWARF_DTPREL
pragma|\
name|ALLOCATE_INITIAL_VALUE
end_pragma

begin_comment
comment|/* Other obsolete target macros, or macros that used to be in target    headers and were not used, and may be obsolete or may never have    been used.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|INT_ASM_OP
name|ASM_OUTPUT_EH_REGION_BEG
name|CPP_PREDEFINES
pragma|\
name|ASM_OUTPUT_EH_REGION_END
name|ASM_OUTPUT_LABELREF_AS_INT
name|SMALL_STACK
pragma|\
name|DOESNT_NEED_UNWINDER
name|EH_TABLE_LOOKUP
name|OBJC_SELECTORS_WITHOUT_LABELS
pragma|\
name|OMIT_EH_TABLE
name|EASY_DIV_EXPR
name|IMPLICIT_FIX_EXPR
pragma|\
name|LONGJMP_RESTORE_FROM_STACK
name|MAX_INT_TYPE_SIZE
name|ASM_IDENTIFY_GCC
pragma|\
name|STDC_VALUE
name|TRAMPOLINE_ALIGN
name|ASM_IDENTIFY_GCC_AFTER_SOURCE
pragma|\
name|SLOW_ZERO_EXTEND
name|SUBREG_REGNO_OFFSET
name|DWARF_LINE_MIN_INSTR_LENGTH
pragma|\
name|TRADITIONAL_RETURN_FLOAT
name|NO_BUILTIN_SIZE_TYPE
pragma|\
name|NO_BUILTIN_PTRDIFF_TYPE
name|NO_BUILTIN_WCHAR_TYPE
name|NO_BUILTIN_WINT_TYPE
pragma|\
name|BLOCK_PROFILER
name|BLOCK_PROFILER_CODE
name|FUNCTION_BLOCK_PROFILER
pragma|\
name|FUNCTION_BLOCK_PROFILER_EXIT
name|MACHINE_STATE_SAVE
pragma|\
name|MACHINE_STATE_RESTORE
name|SCCS_DIRECTIVE
name|SECTION_ASM_OP
name|BYTEORDER
pragma|\
name|ASM_OUTPUT_DEFINE_LABEL_DIFFERENCE_SYMBOL
name|HOST_WORDS_BIG_ENDIAN
pragma|\
name|OBJC_PROLOGUE
name|ALLOCATE_TRAMPOLINE
name|HANDLE_PRAGMA
name|ROUND_TYPE_SIZE
pragma|\
name|ROUND_TYPE_SIZE_UNIT
name|CONST_SECTION_ASM_OP
name|CRT_GET_RFIB_TEXT
pragma|\
name|DBX_LBRAC_FIRST
name|DBX_OUTPUT_ENUM
name|DBX_OUTPUT_SOURCE_FILENAME
pragma|\
name|DBX_WORKING_DIRECTORY
name|INSN_CACHE_DEPTH
name|INSN_CACHE_SIZE
pragma|\
name|INSN_CACHE_LINE_WIDTH
name|INIT_SECTION_PREAMBLE
name|NEED_ATEXIT
name|ON_EXIT
pragma|\
name|EXIT_BODY
name|OBJECT_FORMAT_ROSE
name|MULTIBYTE_CHARS
name|MAP_CHARACTER
pragma|\
name|LIBGCC_NEEDS_DOUBLE
name|FINAL_PRESCAN_LABEL
name|DEFAULT_CALLER_SAVES
pragma|\
name|LOAD_ARGS_REVERSED
name|MAX_INTEGER_COMPUTATION_MODE
pragma|\
name|CONVERT_HARD_REGISTER_TO_SSA_P
name|ASM_OUTPUT_MAIN_SOURCE_FILENAME
pragma|\
name|FIRST_INSN_ADDRESS
name|TEXT_SECTION
name|SHARED_BSS_SECTION_ASM_OP
pragma|\
name|PROMOTED_MODE
name|EXPAND_BUILTIN_VA_END
pragma|\
name|LINKER_DOES_NOT_WORK_WITH_DWARF2
name|FUNCTION_ARG_KEEP_AS_REFERENCE
pragma|\
name|GIV_SORT_CRITERION
name|MAX_LONG_TYPE_SIZE
name|MAX_LONG_DOUBLE_TYPE_SIZE
pragma|\
name|MAX_WCHAR_TYPE_SIZE
name|SHARED_SECTION_ASM_OP
name|INTEGRATE_THRESHOLD
pragma|\
name|FINAL_REG_PARM_STACK_SPACE
name|MAYBE_REG_PARM_STACK_SPACE
pragma|\
name|TRADITIONAL_PIPELINE_INTERFACE
name|DFA_PIPELINE_INTERFACE
pragma|\
name|DBX_OUTPUT_STANDARD_TYPES
name|BUILTIN_SETJMP_FRAME_VALUE
pragma|\
name|SUNOS4_SHARED_LIBRARIES
name|PROMOTE_FOR_CALL_ONLY
pragma|\
name|SPACE_AFTER_L_OPTION
name|NO_RECURSIVE_FUNCTION_CSE
pragma|\
name|DEFAULT_MAIN_RETURN
name|TARGET_MEM_FUNCTIONS
name|EXPAND_BUILTIN_VA_ARG
pragma|\
name|COLLECT_PARSE_FLAG
name|DWARF2_GENERATE_TEXT_SECTION_LABEL
name|WINNING_GDB
pragma|\
name|ASM_OUTPUT_FILENAME
name|ASM_OUTPUT_SOURCE_LINE
name|FILE_NAME_JOINER
pragma|\
name|GDB_INV_REF_REGPARM_STABS_LETTER
name|DBX_MEMPARM_STABS_LETTER
pragma|\
name|PUT_SDB_SRC_FILE
name|STABS_GCC_MARKER
name|DBX_OUTPUT_FUNCTION_END
pragma|\
name|DBX_OUTPUT_GCC_MARKER
name|DBX_FINISH_SYMBOL
name|SDB_GENERATE_FAKE
pragma|\
name|NON_SAVING_SETJMP
name|TARGET_LATE_RTL_PROLOGUE_EPILOGUE
pragma|\
name|CASE_DROPS_THROUGH
name|TARGET_BELL
name|TARGET_BS
name|TARGET_CR
name|TARGET_DIGIT0
pragma|\
name|TARGET_ESC
name|TARGET_FF
name|TARGET_NEWLINE
name|TARGET_TAB
name|TARGET_VT
pragma|\
name|LINK_LIBGCC_SPECIAL
name|DONT_ACCESS_GBLS_AFTER_EPILOGUE
pragma|\
name|TARGET_OPTIONS
name|TARGET_SWITCHES
name|EXTRA_CC_MODES
name|FINALIZE_PIC
pragma|\
name|PREDICATE_CODES
name|SPECIAL_MODE_PREDICATES
name|HOST_PTR_PRINTF
pragma|\
name|EXTRA_SECTIONS
name|EXTRA_SECTION_FUNCTIONS
name|READONLY_DATA_SECTION
pragma|\
name|TARGET_ASM_EXCEPTION_SECTION
name|TARGET_ASM_EH_FRAME_SECTION
pragma|\
name|SMALL_ARG_MAX
name|ASM_OUTPUT_SHARED_BSS
name|ASM_OUTPUT_SHARED_COMMON
pragma|\
name|ASM_OUTPUT_SHARED_LOCAL
name|UNALIGNED_WORD_ASM_OP
end_pragma

begin_comment
comment|/* Hooks that are no longer used.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|LANG_HOOKS_FUNCTION_MARK
name|LANG_HOOKS_FUNCTION_FREE
pragma|\
name|LANG_HOOKS_MARK_TREE
name|LANG_HOOKS_INSERT_DEFAULT_ATTRIBUTES
pragma|\
name|LANG_HOOKS_TREE_INLINING_ESTIMATE_NUM_INSNS
pragma|\
name|LANG_HOOKS_PUSHLEVEL
name|LANG_HOOKS_SET_BLOCK
pragma|\
name|LANG_HOOKS_MAYBE_BUILD_CLEANUP
name|LANG_HOOKS_UPDATE_DECL_AFTER_SAVING
pragma|\
name|LANG_HOOKS_POPLEVEL
name|LANG_HOOKS_TRUTHVALUE_CONVERSION
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IN_GCC */
end_comment

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
comment|/* ! GCC_SYSTEM_H */
end_comment

end_unit

