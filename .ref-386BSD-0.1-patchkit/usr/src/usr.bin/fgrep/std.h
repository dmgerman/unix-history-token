begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* std.h - automagically adapt to old and new compilers.    In the Public Domain; written by Mike Haertel. */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_typedef
typedef|typedef
name|void
modifier|*
name|PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|PTRCONST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AND
value|,
end_define

begin_define
define|#
directive|define
name|DEFUN
parameter_list|(
name|F
parameter_list|,
name|L
parameter_list|,
name|P
parameter_list|)
value|F(P)
end_define

begin_define
define|#
directive|define
name|EXFUN
parameter_list|(
name|F
parameter_list|,
name|P
parameter_list|)
value|F P
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_comment
comment|/* The following approximations of<stddef.h> and<limits.h> are appropriate    for most machines. */
end_comment

begin_typedef
typedef|typedef
name|int
name|ptrdiff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|T
parameter_list|,
name|M
parameter_list|)
value|((size_t)&((T *) 0)->(M))
end_define

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_define
define|#
directive|define
name|SCHAR_MIN
value|-128
end_define

begin_define
define|#
directive|define
name|SCHAR_MAX
value|127
end_define

begin_define
define|#
directive|define
name|UCHAR_MAX
value|255
end_define

begin_define
define|#
directive|define
name|CHAR_MIN
value|((char) UCHAR_MAX< 0 ? SCHAR_MIN : 0)
end_define

begin_define
define|#
directive|define
name|CHAR_MAX
value|((char) UCHAR_MAX< 0 ? SCHAR_MAX : UCHAR_MAX)
end_define

begin_define
define|#
directive|define
name|SHRT_MIN
value|-32768
end_define

begin_define
define|#
directive|define
name|SHRT_MAX
value|32767
end_define

begin_define
define|#
directive|define
name|USHRT_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|INT_MIN
value|(sizeof (int) == 2 ? -32768 : -2147483648)
end_define

begin_define
define|#
directive|define
name|INT_MAX
value|(sizeof (int) == 2 ? 32767 : 2147483647)
end_define

begin_define
define|#
directive|define
name|UINT_MAX
value|(sizeof (int) == 2 ? 65535 : 4294967295)
end_define

begin_define
define|#
directive|define
name|LONG_MIN
value|-2147483648L
end_define

begin_define
define|#
directive|define
name|LONG_MAX
value|2147483647L
end_define

begin_define
define|#
directive|define
name|ULONG_MAX
value|4294967295
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
name|PTRCONST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AND
value|;
end_define

begin_define
define|#
directive|define
name|DEFUN
parameter_list|(
name|F
parameter_list|,
name|L
parameter_list|,
name|P
parameter_list|)
value|F L P ;
end_define

begin_define
define|#
directive|define
name|EXFUN
parameter_list|(
name|F
parameter_list|,
name|P
parameter_list|)
value|F()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Deal with<ctype.h> lossage. */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|isascii
end_ifndef

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|C
parameter_list|)
value|isalnum(C)
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|C
parameter_list|)
value|isalpha(C)
end_define

begin_define
define|#
directive|define
name|ISCNTRL
parameter_list|(
name|C
parameter_list|)
value|iscntrl(C)
end_define

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|C
parameter_list|)
value|isdigit(C)
end_define

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|C
parameter_list|)
value|isgraph(C)
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|C
parameter_list|)
value|islower(C)
end_define

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|C
parameter_list|)
value|isprint(C)
end_define

begin_define
define|#
directive|define
name|ISPUNCT
parameter_list|(
name|C
parameter_list|)
value|ispunct(C)
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|C
parameter_list|)
value|isspace(C)
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|C
parameter_list|)
value|isupper(C)
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|C
parameter_list|)
value|isxdigit(C)
end_define

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|C
parameter_list|)
value|tolower(C)
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|C
parameter_list|)
value|toupper(C)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& isalnum(C))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& isalpha(C))
end_define

begin_define
define|#
directive|define
name|ISCNTRL
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& iscntrl(C))
end_define

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& isdigit(C))
end_define

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& isgraph(C))
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& islower(C))
end_define

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& isprint(C))
end_define

begin_define
define|#
directive|define
name|ISPUNCT
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& ispunct(C))
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& isspace(C))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& isupper(C))
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|C
parameter_list|)
value|(isascii(C)&& isxdigit(C))
end_define

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|C
parameter_list|)
value|(ISUPPER(C) ? tolower(C) : (C))
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|C
parameter_list|)
value|(ISLOWER(C) ? toupper(C) : (C))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Declaring this here should be safe.  Some losing<errno.h>'s don't. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Adapt variable arguments to new implementations (with<stdarg.h>)    or old (which are assumed to have<varargs.h>). */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|VA_ALIST
value|...
end_define

begin_define
define|#
directive|define
name|VA_DCL
value|...
end_define

begin_define
define|#
directive|define
name|VA_LIST
value|va_list
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
value|va_start(AP, LASTARG)
end_define

begin_define
define|#
directive|define
name|VA_ARG
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
value|va_arg(AP, TYPE)
end_define

begin_define
define|#
directive|define
name|VA_END
parameter_list|(
name|AP
parameter_list|)
value|va_end(AP)
end_define

begin_define
define|#
directive|define
name|VA_DEFUN
parameter_list|(
name|F
parameter_list|,
name|L
parameter_list|,
name|P
parameter_list|)
value|F(P)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_define
define|#
directive|define
name|VA_ALIST
value|va_alist
end_define

begin_define
define|#
directive|define
name|VA_DCL
value|va_dcl
end_define

begin_define
define|#
directive|define
name|VA_LIST
value|va_list
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|AP
parameter_list|,
name|LASTARG
parameter_list|)
value|va_start(AP)
end_define

begin_define
define|#
directive|define
name|VA_ARG
parameter_list|(
name|AP
parameter_list|,
name|TYPE
parameter_list|)
value|va_arg(AP, TYPE)
end_define

begin_define
define|#
directive|define
name|VA_END
parameter_list|(
name|AP
parameter_list|)
value|va_end(AP)
end_define

begin_define
define|#
directive|define
name|VA_DEFUN
parameter_list|(
name|F
parameter_list|,
name|L
parameter_list|,
name|P
parameter_list|)
value|F L P
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Declarations of traditional library routines. */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|EXFUN
argument_list|(
name|atof
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|atoi
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|int
name|EXFUN
argument_list|(
name|atol
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|rand
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|srand
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|EXFUN
argument_list|(
name|calloc
argument_list|,
operator|(
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|free
argument_list|,
operator|(
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|EXFUN
argument_list|(
name|malloc
argument_list|,
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|EXFUN
argument_list|(
name|realloc
argument_list|,
operator|(
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|abort
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|exit
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|EXFUN
argument_list|(
name|getenv
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|system
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXFUN
argument_list|(
name|qsort
argument_list|,
operator|(
name|PTR
operator|,
name|size_t
operator|,
name|size_t
operator|,
name|int
name|EXFUN
argument_list|(
operator|(
operator|*
operator|)
argument_list|,
operator|(
name|PTRCONST
operator|,
name|PTRCONST
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|EXFUN
argument_list|(
name|abs
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|int
name|EXFUN
argument_list|(
name|labs
argument_list|,
operator|(
name|long
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|X_strerror
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|EXFUN
argument_list|(
name|strerror
argument_list|,
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

end_unit

