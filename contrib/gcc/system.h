begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Get common system includes and various definitions and declarations based    on autoconf macros.    Copyright (C) 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* This is the location of the online document giving information how    to report bugs. If you change this string, also check for strings    not under control of the preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|GCCBUGURL
value|"<URL:http://www.gnu.org/software/gcc/bugs.html>"
end_define

begin_comment
comment|/* We must include stdarg.h/varargs.h before stdio.h.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* The compiler is not a multi-threaded application and therefore we    do not have to use the locking functions.  In fact, using the locking    functions can cause the compiler to be significantly slower under    I/O bound conditions (such as -g -O0 on very large source files).     HAVE_DECL_PUTC_UNLOCKED actually indicates whether or not the stdio    code is multi-thread safe by default.  If it is set to 0, then do    not worry about using the _unlocked functions.        fputs_unlocked, fwrite_unlocked, and fprintf_unlocked are    extensions and need to be prototyped by hand (since we do not    define _GNU_SOURCE).  */
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

begin_decl_stmt
specifier|extern
name|int
name|fputs_unlocked
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|fwrite_unlocked
name|PARAMS
argument_list|(
operator|(
specifier|const
name|PTR
operator|,
name|size_t
operator|,
name|size_t
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|fprintf_unlocked
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|((unsigned HOST_WIDE_INT) ((VALUE) - (LOWER))<= ((UPPER) - (LOWER)))
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

begin_decl_stmt
specifier|extern
name|double
name|atof
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|long
name|atol
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|free
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getcwd
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|getopt
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
specifier|const
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getwd
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|PTR
name|sbrk
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strstr
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|PTR
name|malloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|PTR
name|calloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|PTR
name|realloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the system doesn't provide strsignal, we get it defined in    libiberty but no declaration is supplied.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRSIGNAL
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|strsignal
end_ifndef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|strsignal
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_struct_decl
struct_decl|struct
name|rlimit
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|getrlimit
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|rlimit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_struct_decl
struct_decl|struct
name|rlimit
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|setrlimit
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|rlimit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* HAVE_VOLATILE only refers to the stage1 compiler.  We also check    __STDC__ and assume gcc sets it and has volatile in stage>=2.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_VOLATILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|volatile
argument_list|)
end_if

begin_define
define|#
directive|define
name|volatile
end_define

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

begin_decl_stmt
specifier|extern
name|void
name|abort
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* 1 if we have _Bool.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE__BOOL
end_ifndef

begin_define
define|#
directive|define
name|HAVE__BOOL
define|\
value|((GCC_VERSION>= 3000) || (__STDC_VERSION__>= 199901L))
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
comment|/* Approximate O_NONBLOCK.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_NONBLOCK
end_ifndef

begin_define
define|#
directive|define
name|O_NONBLOCK
value|O_NDELAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Approximate O_NOCTTY.  */
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
comment|/* Provide a way to print an address via printf.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_PTR_PRINTF
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PRINTF_PTR
end_ifdef

begin_define
define|#
directive|define
name|HOST_PTR_PRINTF
value|"%p"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_PTR_PRINTF
define|\
value|(sizeof (int) == sizeof (char *) ? "%x" \      : sizeof (long) == sizeof (char *) ? "%lx" : "%llx")
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
comment|/* ! HOST_PTR_PRINTF */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define IS_DIR_SEPARATOR.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIR_SEPARATOR_2
end_ifndef

begin_define
define|#
directive|define
name|IS_DIR_SEPARATOR
parameter_list|(
name|CH
parameter_list|)
value|((CH) == DIR_SEPARATOR)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DIR_SEPARATOR_2 */
end_comment

begin_define
define|#
directive|define
name|IS_DIR_SEPARATOR
parameter_list|(
name|CH
parameter_list|)
define|\
value|(((CH) == DIR_SEPARATOR) || ((CH) == DIR_SEPARATOR_2))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIR_SEPARATOR_2 */
end_comment

begin_comment
comment|/* Say how to test for an absolute pathname.  On Unix systems, this is if    it starts with a leading slash or a '$', the latter meaning the value of    an environment variable is to be used.  On machien with DOS-based    file systems, it is also absolute if it starts with a drive identifier.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DOS_BASED_FILE_SYSTEM
end_ifdef

begin_define
define|#
directive|define
name|IS_ABSOLUTE_PATHNAME
parameter_list|(
name|STR
parameter_list|)
define|\
value|(IS_DIR_SEPARATOR ((STR)[0]) || (STR)[0] == '$' \    || ((STR)[0] != '\0'&& (STR)[1] == ':'&& IS_DIR_SEPARATOR ((STR)[2])))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_ABSOLUTE_PATHNAME
parameter_list|(
name|STR
parameter_list|)
define|\
value|(IS_DIR_SEPARATOR ((STR)[0]) || (STR)[0] == '$')
end_define

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

begin_include
include|#
directive|include
file|"symcat.h"
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
value|enum TYPE
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
comment|/* Traditional C cannot initialize union members of structs.  Provide    a macro which expands appropriately to handle it.  This only works    if you intend to initialize the union member to zero since it relies    on default initialization to zero in the traditional C case.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|UNION_INIT_ZERO
value|, {0}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNION_INIT_ZERO
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
comment|/* Provide some sort of boolean type.  We use stdbool.h if it's   available.  This must be after all inclusion of system headers,   as some of them will mess us up.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDBOOL_H
end_ifdef

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|HAVE__BOOL
end_if

begin_typedef
typedef|typedef
name|char
name|_Bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bool
value|_Bool
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

begin_endif
endif|#
directive|endif
end_endif

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
name|malloc
end_undef

begin_undef
undef|#
directive|undef
name|realloc
end_undef

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
name|malloc
name|realloc
name|calloc
name|strdup
end_pragma

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
end_pragma

begin_comment
comment|/* And other obsolete target macros, or macros that used to be in target    headers and were not used, and may be obsolete or may never have    been used.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|INT_ASM_OP
name|ASM_OUTPUT_EH_REGION_BEG
pragma|\
name|ASM_OUTPUT_EH_REGION_END
name|ASM_OUTPUT_LABELREF_AS_INT
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

