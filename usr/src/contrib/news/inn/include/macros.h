begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.13 $ ** **  Here be some useful macros. */
end_comment

begin_comment
comment|/* **  Memory allocation.  Wrappers around wrapper functions. **  Don't replace any existing definitions, for use with malloc-debug **  packages, e.g. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DEBUG_MALLOC_INC
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|_DEBUG_MALLOC_INC
end_undef

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|malloc_enter
parameter_list|(
name|func
parameter_list|)
end_define

begin_define
define|#
directive|define
name|malloc_leave
parameter_list|(
name|func
parameter_list|)
end_define

begin_define
define|#
directive|define
name|malloc_chain_check
parameter_list|()
end_define

begin_define
define|#
directive|define
name|malloc_dump
parameter_list|(
name|fd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|malloc_list
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|malloc_size
parameter_list|(
name|hist
parameter_list|)
value|(*(hist) = 0, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_DEBUG_MALLOC_INC) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NEW
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|T
parameter_list|,
name|c
parameter_list|)
define|\
value|((T *)xmalloc((unsigned int)(sizeof (T) * (c))))
end_define

begin_define
define|#
directive|define
name|RENEW
parameter_list|(
name|p
parameter_list|,
name|T
parameter_list|,
name|c
parameter_list|)
define|\
value|(p = (T *)xrealloc((char *)(p), (unsigned int)(sizeof (T) * (c))))
end_define

begin_comment
comment|/* =()<#define DISPOSE(p)		free((@<POINTER>@ *)p)>()= */
end_comment

begin_define
define|#
directive|define
name|DISPOSE
parameter_list|(
name|p
parameter_list|)
value|free((void *)p)
end_define

begin_comment
comment|/* This properly belongs in libinn.h. */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|xmemfailure
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ONALLLOCFAIL
parameter_list|(
name|func
parameter_list|)
value|(xmemfailure = (func))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NEW) */
end_comment

begin_comment
comment|/* **  Copy a string to allocated memory. */
end_comment

begin_define
define|#
directive|define
name|COPY
parameter_list|(
name|p
parameter_list|)
define|\
value|strcpy(NEW(char, strlen(p) + 1), p)
end_define

begin_comment
comment|/* **  Wrappers around str[n]cmp.  Don't add the ((a) == (b)) test here; it's **  already been done in places where it's time-critical. */
end_comment

begin_define
define|#
directive|define
name|EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp((a), (b)) == 0)
end_define

begin_define
define|#
directive|define
name|EQn
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|(strncmp((a), (b), (SIZE_T)(n)) == 0)
end_define

begin_define
define|#
directive|define
name|caseEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcasecmp((a), (b)) == 0)
end_define

begin_define
define|#
directive|define
name|caseEQn
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|(strncasecmp((a), (b), (SIZE_T)(n)) == 0)
end_define

begin_comment
comment|/* **  Cast a pointer into another point, but keep lint quiet. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_define
define|#
directive|define
name|CAST
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
value|((t)(p))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CAST
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
value|((p) ? (t)NULL : (t)NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(lint) */
end_comment

begin_comment
comment|/* **<ctype.h> usually includes \n, which is not what we want. */
end_comment

begin_define
define|#
directive|define
name|ISWHITE
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_comment
comment|/* **  Get the number of elements in a fixed-size array, or a pointer just **  past the end of it. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF
parameter_list|(
name|array
parameter_list|)
value|((int)(sizeof array / sizeof array[0]))
end_define

begin_define
define|#
directive|define
name|ENDOF
parameter_list|(
name|array
parameter_list|)
value|(&array[SIZEOF(array)])
end_define

begin_comment
comment|/* **  Get the length of a string constant. */
end_comment

begin_define
define|#
directive|define
name|STRLEN
parameter_list|(
name|string
parameter_list|)
value|((int)(sizeof string - 1))
end_define

begin_comment
comment|/* **  Turn a TIMEINFO into a floating point number. */
end_comment

begin_define
define|#
directive|define
name|TIMEINFOasDOUBLE
parameter_list|(
name|t
parameter_list|)
define|\
value|((double)(t).time + ((double)(t).usec) / 1000000.0)
end_define

begin_comment
comment|/* **  Test data from a stat(2) call to see if it's a file or directory. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|st_mode
parameter_list|)
value|(((st_mode)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(S_ISDIR) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISREG
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|st_mode
parameter_list|)
value|(((st_mode)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(S_ISREG) */
end_comment

begin_comment
comment|/* **  Get the size when binding an AF_UNIX socket. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DO_BIND_USE_SIZEOF
argument_list|)
end_if

begin_define
define|#
directive|define
name|AF_UNIX_SOCKSIZE
parameter_list|(
name|S
parameter_list|)
value|(sizeof S)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AF_UNIX_SOCKSIZE
parameter_list|(
name|S
parameter_list|)
value|(sizeof S.sun_family + strlen(S.sun_path) + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DO_BIND_USE_SIZEOF) */
end_comment

begin_comment
comment|/* **  Use a read or recv call to read a descriptor. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DO_HAVE_UNIX_DOMAIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|RECVorREAD
parameter_list|(
name|fd
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|)
value|recv((fd), (p), (s), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RECVorREAD
parameter_list|(
name|fd
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|)
value|read((fd), (p), (s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DO_HAVE_UNIX_DOMAIN) */
end_comment

end_unit

