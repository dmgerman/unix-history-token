begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system.h - Get common system includes and various definitions and    declarations based on autoconf macros.    Copyright (C) 1998, 1999, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GCC_SYSTEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__GCC_SYSTEM_H__
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
comment|/* We must include stdarg.h/varargs.h before stdio.h. */
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
comment|/* The compiler is not a multi-threaded application and therefore we    do not have to use the locking functions.     NEED_DECLARATION_PUTC_UNLOCKED actually indicates whether or not    the IO code is multi-thread safe by default.  If it is not declared,    then do not worry about using the _unlocked functions.        fputs_unlocked is an extension and needs to be prototyped specially.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|HAVE_PUTC_UNLOCKED
operator|&&
operator|!
name|defined
name|NEED_DECLARATION_PUTC_UNLOCKED
end_if

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

begin_if
if|#
directive|if
name|defined
name|HAVE_FPUTC_UNLOCKED
operator|&&
operator|!
name|defined
name|NEED_DECLARATION_PUTC_UNLOCKED
end_if

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

begin_if
if|#
directive|if
name|defined
name|HAVE_FPUTS_UNLOCKED
operator|&&
operator|!
name|defined
name|NEED_DECLARATION_PUTC_UNLOCKED
end_if

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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_FPUTS_UNLOCKED
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|fputs_unlocked
name|PROTO
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

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* Jim Meyering writes:     "... Some ctype macros are valid only for character codes that    isascii says are ASCII (SGI's IRIX-4.0.5 is one such system --when    using /bin/cc or gcc but without giving an ansi option).  So, all    ctype uses should be through macros like ISPRINT...  If    STDC_HEADERS is defined, then autoconf has verified that the ctype    macros don't need to be guarded with references to isascii. ...    Defining isascii to 1 should let any compiler worth its salt    eliminate the&& through constant folding."     Bruno Haible adds:     "... Furthermore, isupper(c) etc. have an undefined result if c is    outside the range -1<= c<= 255. One is tempted to write isupper(c)    with c being of type `char', but this is wrong if c is an 8-bit    character>= 128 which gets sign-extended to a negative value.    The macro ISUPPER protects against this as well."  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|isascii
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ISASCII
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|isascii(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isblank
end_ifdef

begin_define
define|#
directive|define
name|ISBLANK
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isblank (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISBLANK
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isgraph
end_ifdef

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isgraph (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isprint (c)&& !isspace (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isprint (c))
end_define

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isalnum (c))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isalpha (c))
end_define

begin_define
define|#
directive|define
name|ISCNTRL
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& iscntrl (c))
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& islower (c))
end_define

begin_define
define|#
directive|define
name|ISPUNCT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& ispunct (c))
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isspace (c))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isupper (c))
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isxdigit (c))
end_define

begin_define
define|#
directive|define
name|ISDIGIT_LOCALE
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isdigit (c))
end_define

begin_comment
comment|/* ISDIGIT differs from ISDIGIT_LOCALE, as follows:    - Its arg may be any int or unsigned int; it need not be an unsigned char.    - It's guaranteed to evaluate its argument exactly once.    - It's typically faster.    Posix 1003.2-1992 section 2.5.2.1 page 50 lines 1556-1558 says that    only '0' through '9' are digits.  Prefer ISDIGIT to ISDIGIT_LOCALE unless    it's important to use the locale's definition of `digit' even when the    host does not conform to Posix.  */
end_comment

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|((unsigned) (c) - '0'<= 9)
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

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
comment|/* Find HOST_WIDEST_INT and set its bit size, type and print macros.    It will be the largest integer mode supported by the host which may    (or may not) be larger than HOST_WIDE_INT.  This must appear after<limits.h> since we only use `long long' if its bigger than a    `long' and also if it is supported by macros in limits.h.  For old    hosts which don't have a limits.h (and thus won't include it in    stage2 cause we don't rerun configure) we assume gcc supports long    long.)  Note, you won't get these defined if you don't include    {ht}config.h before this file to set the HOST_BITS_PER_* macros. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_WIDEST_INT
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HOST_BITS_PER_LONG
argument_list|)
operator|&&
name|defined
argument_list|(
name|HOST_BITS_PER_LONGLONG
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|HOST_BITS_PER_LONGLONG
operator|>
name|HOST_BITS_PER_LONG
operator|)
operator|&&
operator|(
name|defined
argument_list|(
name|LONG_LONG_MAX
argument_list|)
operator|||
name|defined
argument_list|(
name|LONGLONG_MAX
argument_list|)
operator|||
name|defined
argument_list|(
name|LLONG_MAX
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDEST_INT
value|HOST_BITS_PER_LONGLONG
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT
value|long long
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DEC
value|"%lld"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_UNSIGNED
value|"%llu"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_HEX
value|"0x%llx"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDEST_INT
value|HOST_BITS_PER_LONG
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT
value|long
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_DEC
value|"%ld"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_UNSIGNED
value|"%lu"
end_define

begin_define
define|#
directive|define
name|HOST_WIDEST_INT_PRINT_HEX
value|"0x%lx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*(long long>long)&& (LONG_LONG_MAX||LONGLONG_MAX||LLONG_MAX||GNUC)*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(HOST_BITS_PER_LONG)&& defined(HOST_BITS_PER_LONGLONG) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HOST_WIDEST_INT */
end_comment

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
name|bcopy
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BCOPY
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_BCOPY
end_ifdef

begin_function_decl
specifier|extern
name|void
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_BCOPY */
end_comment

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|len
parameter_list|)
value|memmove((dst),(src),(len))
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
name|bcmp
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BCMP
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_BCMP
end_ifdef

begin_function_decl
specifier|extern
name|int
name|bcmp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_BCMP */
end_comment

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|left
parameter_list|,
name|right
parameter_list|,
name|len
parameter_list|)
value|memcmp ((left),(right),(len))
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
name|bzero
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BZERO
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_BZERO
end_ifdef

begin_function_decl
specifier|extern
name|void
name|bzero
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_BZERO */
end_comment

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|dst
parameter_list|,
name|len
parameter_list|)
value|memset ((dst),0,(len))
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
name|index
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_INDEX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_INDEX
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_INDEX */
end_comment

begin_define
define|#
directive|define
name|index
value|strchr
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
name|rindex
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RINDEX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_RINDEX
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_RINDEX */
end_comment

begin_define
define|#
directive|define
name|rindex
value|strrchr
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
name|NEED_DECLARATION_ATOF
end_ifdef

begin_function_decl
specifier|extern
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_ATOL
end_ifdef

begin_function_decl
specifier|extern
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_FREE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_GETCWD
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getcwd
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_GETENV
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_GETWD
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_SBRK
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|sbrk
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_STRSTR
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strstr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRERROR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_STRERROR
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|strerror
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strerror
parameter_list|()
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_STRERROR */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRERROR */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRSIGNAL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_STRSIGNAL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|strsignal
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsignal
parameter_list|()
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_STRSIGNAL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_SIGLIST_DECLARED
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYS_SIGLIST
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_siglist
index|[]
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
comment|/* HAVE_STRSIGNAL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GETRLIMIT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_GETRLIMIT
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|getrlimit
end_ifndef

begin_function_decl
specifier|extern
name|int
name|getrlimit
parameter_list|()
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_SETRLIMIT
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|setrlimit
end_ifndef

begin_function_decl
specifier|extern
name|int
name|setrlimit
parameter_list|()
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
comment|/* HAVE_VOLATILE only refers to the stage1 compiler.  We also check    __STDC__ and assume gcc sets it and has volatile in stage>=2. */
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

begin_comment
comment|/* Redefine abort to report an internal error w/o coredump, and reporting the    location of the error in the source file.    Some files undefine abort again, so we must prototype the real thing    for their sake.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_ABORT
end_ifdef

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|fatal
name|PVPROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTRIBUTE_PRINTF_1
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|)
end_if

begin_define
define|#
directive|define
name|abort
parameter_list|()
value|fatal ("Internal compiler error at %s:%d\n", \ 		       trim_filename (__FILE__), __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|abort
parameter_list|()
value|fatal ("Internal compiler error in `%s', at %s:%d\n"	\   "Please submit a full bug report.\n"	\   "See %s for instructions.", \   __PRETTY_FUNCTION__, trim_filename (__FILE__), __LINE__, GCCBUGURL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* recent gcc */
end_comment

begin_comment
comment|/* trim_filename is in toplev.c.  Define a stub macro for files that    don't link toplev.c.  toplev.h will reset it to the real version.  */
end_comment

begin_define
define|#
directive|define
name|trim_filename
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* Define a STRINGIFY macro that's right for ANSI or traditional C.    HAVE_CPP_STRINGIFY only refers to the stage1 compiler.  Assume that    (non-traditional) gcc used in stage2 or later has this feature.     Note: if the argument passed to STRINGIFY is itself a macro, eg    #define foo bar, STRINGIFY(foo) will produce "foo", not "bar".    Although the __STDC__ case could be made to expand this via a layer    of indirection, the traditional C case can not do so.  Therefore    this behavior is not supported. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STRINGIFY
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CPP_STRINGIFY
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|STRINGIFY
parameter_list|(
name|STRING
parameter_list|)
value|#STRING
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRINGIFY
parameter_list|(
name|STRING
parameter_list|)
value|"STRING"
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
comment|/* ! STRINGIFY */
end_comment

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
comment|/* Some systems have mkdir that takes a single argument. */
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
comment|/* Get libiberty declarations. */
end_comment

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GCC_SYSTEM_H__ */
end_comment

end_unit

