begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.4 $ ** **  Internal header file for editline library. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
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

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|CRLF
value|"\r\n"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

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
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DIRENT_H
end_ifdef

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|dirent
name|DIRENTRY
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|direct
name|DIRENTRY
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<roken.h>
end_include

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
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(S_ISDIR) */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|CHAR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEM_INC
value|64
end_define

begin_define
define|#
directive|define
name|SCREEN_INC
value|256
end_define

begin_comment
comment|/* **  Variables and routines internal to this package. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_eof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_erase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_intr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_kill
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_quit
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|rl_complete_func_t
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|rl_list_possib_func_t
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|add_history
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|readline
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rl_add_slash
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
name|char
modifier|*
name|rl_complete
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rl_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rl_list_possib
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rl_reset_terminal
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rl_ttyset
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rl_complete_func_t
name|rl_set_complete_func
parameter_list|(
name|rl_complete_func_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rl_list_possib_func_t
name|rl_set_list_possib_func
parameter_list|(
name|rl_list_possib_func_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

