begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * defs.h  *  * By Ross Ridge  * Public Domain  * 92/06/04 11:37:02  *  * @(#) mytinfo defs.h 3.3 92/06/04 public domain, By Ross Ridge  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEFS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TEST
end_ifdef

begin_undef
undef|#
directive|undef
name|NOTLIB
end_undef

begin_define
define|#
directive|define
name|NOTLIB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NOTLIB
end_ifdef

begin_undef
undef|#
directive|undef
name|USE_FAKE_STDIO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STDDEF
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STDLIB
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PROTOTYPES
end_ifdef

begin_function_decl
name|anyptr
name|malloc
parameter_list|(
name|mysize_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|anyptr
name|realloc
parameter_list|(
name|anyptr
parameter_list|,
name|mysize_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|anyptr
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|anyptr
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STDARG
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
name|_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_FAKE_STDIO
end_ifdef

begin_include
include|#
directive|include
file|"fake_stdio.h"
end_include

begin_define
define|#
directive|define
name|sprintf
value|_fake_sprintf
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PROTOTYPES
end_ifdef

begin_function_decl
name|int
name|sprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
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
name|int
name|sprintf
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
comment|/* USE_FAKE_STDIO */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_FAKE_STDIO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STRINGS
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_define
define|#
directive|define
name|strchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|index(s, c)
end_define

begin_define
define|#
directive|define
name|strrchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|rindex(s, c)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USE_MYSTRTOK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PROTOTYPES
end_ifdef

begin_function_decl
name|char
modifier|*
name|strtok
parameter_list|(
name|char
modifier|*
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

begin_function_decl
name|char
modifier|*
name|strtok
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

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MEMORY
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|b
parameter_list|,
name|a
parameter_list|,
name|n
parameter_list|)
value|bcopy(a, b, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|MAX_BUF
value|4096
end_define

begin_define
define|#
directive|define
name|MAX_LINE
value|640
end_define

begin_define
define|#
directive|define
name|MAX_NAME
value|128
end_define

begin_define
define|#
directive|define
name|MAX_CHUNK
value|MAX_LINE
end_define

begin_define
define|#
directive|define
name|MAX_DEPTH
value|32
end_define

begin_define
define|#
directive|define
name|MAX_VARNAME
value|32
end_define

begin_define
define|#
directive|define
name|MAX_TINFONAME
value|5
end_define

begin_define
define|#
directive|define
name|MAX_TCAPNAME
value|2
end_define

begin_struct
struct|struct
name|caplist
block|{
name|char
name|type
decl_stmt|;
name|char
name|flag
decl_stmt|;
name|char
name|var
index|[
name|MAX_VARNAME
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|tinfo
index|[
name|MAX_TINFONAME
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|tcap
index|[
name|MAX_TCAPNAME
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|term_path
block|{
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* 0 = file, 1 = TERMCAP env, 2 = TERMINFO env */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|_terminal
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PROTOTYPES
end_ifdef

begin_function_decl
name|int
name|_gettcap
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|_terminal
modifier|*
parameter_list|,
name|struct
name|term_path
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_gettinfo
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|_terminal
modifier|*
parameter_list|,
name|struct
name|term_path
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_fillterm
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|term_path
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_findterm
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|term_path
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|_init_tty
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|_lit_output
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|_check_tty
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|_figure_termcap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_tmatch
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_norm_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readcaps
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|caplist
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|noreturn
name|void
name|quit
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|term_path
modifier|*
name|_buildpath
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_delpath
parameter_list|(
name|struct
name|term_path
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_addstr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|strbuf
modifier|*
name|_endstr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_del_strs
parameter_list|(
name|struct
name|_terminal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_tcapconv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_tcapdefault
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_getother
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|term_path
modifier|*
parameter_list|,
name|struct
name|_terminal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_gettbin
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|_terminal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|_findboolcode
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|_findnumcode
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|_findstrcode
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_findboolname
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|_findnumname
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|_findstrname
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_findboolfname
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|_findnumfname
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|_findstrfname
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ANSIC
end_ifdef

begin_function_decl
name|int
name|_compar
parameter_list|(
name|void
specifier|const
modifier|*
parameter_list|,
name|void
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|compar_fn
function_decl|)
parameter_list|(
name|void
specifier|const
modifier|*
parameter_list|,
name|void
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|_compar
parameter_list|(
name|anyptr
parameter_list|,
name|anyptr
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|compar_fn
function_decl|)
parameter_list|(
name|anyptr
parameter_list|,
name|anyptr
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_PROTOTYPES */
end_comment

begin_decl_stmt
name|int
name|_gettcap
argument_list|()
decl_stmt|,
name|_gettinfo
argument_list|()
decl_stmt|,
name|_fillterm
argument_list|()
decl_stmt|,
name|_findterm
argument_list|()
decl_stmt|,
name|_init_tty
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_lit_output
argument_list|()
decl_stmt|,
name|_check_tty
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|_figure_termcap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_tmatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_norm_output
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readcaps
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|noreturn
name|void
comment|/* GOTO */
name|quit
parameter_list|(
comment|/*FORMAT2*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|term_path
modifier|*
name|_buildpath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_delpath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_addstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|strbuf
modifier|*
name|_endstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_del_strs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_tcapconv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_tcapdefault
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_getother
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_gettbin
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|_findboolcode
argument_list|()
decl_stmt|,
name|_findnumcode
argument_list|()
decl_stmt|,
name|_findstrcode
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_findboolname
argument_list|()
decl_stmt|,
name|_findnumname
argument_list|()
decl_stmt|,
name|_findstrname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_findboolfname
argument_list|()
decl_stmt|,
name|_findnumfname
argument_list|()
decl_stmt|,
name|_findstrfname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|_compar
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|compar_fn
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_PROTOTYPES */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|_strflags
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|_mytinfo_version
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for quit.c */
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
name|prg_name
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEFS_H_ */
end_comment

end_unit

