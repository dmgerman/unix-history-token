begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Util.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_util_h_
end_ifndef

begin_define
define|#
directive|define
name|_util_h_
end_define

begin_comment
comment|/*  $RCSfile: util.h,v $  *  $Revision: 14020.12 $  *  $Date: 93/07/09 11:32:49 $  */
end_comment

begin_typedef
typedef|typedef
name|char
name|string
index|[
literal|128
index|]
typedef|,
name|str32
index|[
literal|32
index|]
typedef|,
name|longstring
index|[
literal|512
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|Hostname
index|[
literal|64
index|]
typedef|;
end_typedef

begin_comment
comment|/* For Perror. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DB_ERRS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__LINE__
end_ifdef

begin_define
define|#
directive|define
name|PERROR
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|)
value|Perror(p, __LINE__, e)
end_define

begin_function_decl
name|void
name|Perror
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERROR
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|)
value|Perror(p, e)
end_define

begin_function_decl
name|void
name|Perror
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
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

begin_define
define|#
directive|define
name|PERROR
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|)
value|Perror(e)
end_define

begin_function_decl
name|void
name|Perror
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

begin_ifdef
ifdef|#
directive|ifdef
name|NO_VARARGS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dbprintf
value|if (debug) (void) printf
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|DB_STREAM
end_ifndef

begin_define
define|#
directive|define
name|DB_STREAM
value|stdout
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STDARGH
end_ifndef

begin_function_decl
name|void
name|dbprintf
parameter_list|(
name|char
modifier|*
name|fmt0
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|dbprintf
parameter_list|(
name|int
name|va_alist
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

begin_comment
comment|/* For 'Getopt.' */
end_comment

begin_define
define|#
directive|define
name|BADCH
value|((int)'?')
end_define

begin_define
define|#
directive|define
name|EMSG
value|""
end_define

begin_comment
comment|/* Handy macros. */
end_comment

begin_define
define|#
directive|define
name|Strncpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|_Strncpy((char *) (d), (char *) (s), (size_t) sizeof(d))
end_define

begin_define
define|#
directive|define
name|Strncat
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|_Strncat((char *) (d), (char *) (s), (size_t) sizeof(d))
end_define

begin_define
define|#
directive|define
name|FGets
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|fgets((a), (int) (sizeof(a) - 2), (b))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CONST
end_ifndef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|cmp_t
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|cmp_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|QSort
parameter_list|(
name|base
parameter_list|,
name|n
parameter_list|,
name|sz
parameter_list|,
name|cmp
parameter_list|)
define|\
value|qsort(base, (size_t)(n), (size_t)(sz), (cmp_t)(cmp))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_PARAMS
end_ifndef

begin_define
define|#
directive|define
name|SIG_PARAMS
value|(int sig)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*Sig_t
argument_list|)
name|SIG_PARAMS
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|Signal
parameter_list|(
name|a
parameter_list|,
name|proc
parameter_list|)
value|signal((a), (Sig_t)(proc))
end_define

begin_comment
comment|/* Quiets warnings */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_comment
comment|/* ...actually, any UNIX system */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|SIG_DFL
end_undef

begin_undef
undef|#
directive|undef
name|SIG_IGN
end_undef

begin_define
define|#
directive|define
name|SIG_DFL
value|(Sig_t)0
end_define

begin_define
define|#
directive|define
name|SIG_IGN
value|(Sig_t)1
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
comment|/* Protos. */
end_comment

begin_function_decl
name|char
modifier|*
name|_Strncat
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
name|char
modifier|*
name|src
parameter_list|,
specifier|register
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_Strncpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
name|char
modifier|*
name|src
parameter_list|,
specifier|register
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|StrLCase
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|NewString
parameter_list|(
name|char
modifier|*
name|oldstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|re_makeargv
parameter_list|(
name|char
modifier|*
name|promptstr
parameter_list|,
name|int
modifier|*
name|argc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|onoff
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|StrToBool
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|confirm
parameter_list|(
name|char
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_cwd
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmp_name
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Getopt
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
name|opstring
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Getopt_Reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Gets
parameter_list|(
name|char
modifier|*
name|promptstr
parameter_list|,
name|char
modifier|*
name|sline
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|RemoveTrailingNewline
parameter_list|(
name|char
modifier|*
name|cp
parameter_list|,
name|int
modifier|*
name|stripped
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|UnLSDate
parameter_list|(
name|char
modifier|*
name|dstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|UnMDTMDate
parameter_list|(
name|char
modifier|*
name|dstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Strpcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|UserLoggedIn
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|LocalPath
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|LocalDotPath
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NO_STRSTR
end_ifdef

begin_function_decl
name|char
modifier|*
name|strstr
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
name|char
modifier|*
name|s2
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

begin_comment
comment|/* _util_h_ */
end_comment

end_unit

