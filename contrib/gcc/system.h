begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* system.h - Get common system includes and various definitions and    declarations based on autoconf macros.    Copyright (C) 1998 Free Software Foundation, Inc.   */
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
value|memcpy ((dst),(src),(len))
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
comment|/* Redefine abort to report an internal error w/o coredump, and reporting the    location of the error in the source file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|abort
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|USE_SYSTEM_ABORT
end_ifndef

begin_define
define|#
directive|define
name|USE_SYSTEM_ABORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_SYSTEM_ABORT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SYSTEM_ABORT
end_ifdef

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

begin_else
else|#
directive|else
end_else

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
define|\
value|(fprintf (stderr,							\ 	  "%s:%d: Internal compiler error\n", __FILE__, __LINE__),	\  exit (FATAL_EXIT_CODE))
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
define|\
value|(fprintf (stderr,							\ 	  "%s:%d: Internal compiler error in function %s\n",		\ 	  __FILE__, __LINE__, __PRETTY_FUNCTION__),			\  exit (FATAL_EXIT_CODE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* recent gcc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_SYSTEM_ABORT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !abort */
end_comment

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

begin_comment
comment|/* These macros are here in preparation for the use of gettext in egcs.  */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|String
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|String
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GCC_SYSTEM_H__ */
end_comment

end_unit

