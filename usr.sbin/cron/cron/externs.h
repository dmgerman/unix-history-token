begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 1993,1994 by Paul Vixie  * All rights reserved  *  * Distribute freely, except: don't remove my name from the source or  * documentation (don't take credit for my work), mark your changes (don't  * get me blamed for your possible bugs), don't alter or remove this  * notice.  May be sold if buildable source is provided to buyer.  No  * warrantee of any kind, express or implied, is included with this  * software; use at your own risk, responsibility for damages (if any) to  * anyone resulting from the use of this software rests entirely with the  * user.  *  * Send bug reports, bug fixes, enhancements, requests, flames, etc., and  * I'll try to keep a version up to date.  I can be reached as follows:  * Paul Vixie<paul@vix.com>          uunet!decwrl!vixie!paul  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|||
name|defined
argument_list|(
name|ATT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_define
define|#
directive|define
name|DIR_T
value|struct dirent
end_define

begin_define
define|#
directive|define
name|WAIT_T
value|int
end_define

begin_define
define|#
directive|define
name|WAIT_IS_INT
value|1
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tzname
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TZONE
parameter_list|(
name|tm
parameter_list|)
value|tzname[(tm).tm_isdst]
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
name|UNIXPC
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|WAIT_T
end_undef

begin_undef
undef|#
directive|undef
name|WAIT_IS_INT
end_undef

begin_define
define|#
directive|define
name|WAIT_T
value|union wait
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
name|POSIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIG_T
value|sig_t
end_define

begin_define
define|#
directive|define
name|TIME_T
value|time_t
end_define

begin_define
define|#
directive|define
name|PID_T
value|pid_t
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
name|ATT
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIG_T
value|void
end_define

begin_define
define|#
directive|define
name|TIME_T
value|long
end_define

begin_define
define|#
directive|define
name|PID_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ATT
argument_list|)
end_if

begin_comment
comment|/* classic BSD */
end_comment

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|sleep
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|perror
argument_list|()
decl_stmt|,
name|exit
argument_list|()
decl_stmt|,
name|free
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strtok
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIG_T
value|void
end_define

begin_define
define|#
directive|define
name|TIME_T
value|long
end_define

begin_define
define|#
directive|define
name|PID_T
value|int
end_define

begin_define
define|#
directive|define
name|WAIT_T
value|union wait
end_define

begin_define
define|#
directive|define
name|DIR_T
value|struct direct
end_define

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_define
define|#
directive|define
name|TZONE
parameter_list|(
name|tm
parameter_list|)
value|(tm).tm_zone
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* getopt() isn't part of POSIX.  some systems define it in<stdlib.h> anyway.  * of those that do, some complain that our definition is different and some  * do not.  to add to the misery and confusion, some systems define getopt()  * in ways that we cannot predict or comprehend, yet do not define the adjunct  * external variables needed for the interface.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
operator|||
operator|(
name|BSD
operator|<
literal|198911
operator|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|ATT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UNICOS
argument_list|)
end_if

begin_decl_stmt
name|int
name|getopt
name|__P
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
operator|(
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
operator|||
operator|(
name|BSD
operator|<
literal|199103
operator|)
operator|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|,
name|opterr
decl_stmt|,
name|optopt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|WAIT_IS_INT
end_if

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
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
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
name|x
parameter_list|)
value|((x)& 0x7f)
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
name|x
parameter_list|)
value|((x)& 0x80)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*WAIT_IS_INT*/
end_comment

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
name|x
parameter_list|)
value|((x).w_retcode)
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
name|x
parameter_list|)
value|((x).w_termsig)
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
name|x
parameter_list|)
value|((x).w_coredump)
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
comment|/*WAIT_IS_INT*/
end_comment

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
name|x
parameter_list|)
value|(WTERMSIG(x) != 0)
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
name|x
parameter_list|)
value|(WTERMSIG(x) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_STRCASECMP
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|strcasecmp
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
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
name|NEED_STRDUP
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strdup
name|__P
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_STRERROR
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|__P
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_FLOCK
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|flock
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LOCK_SH
value|1
end_define

begin_define
define|#
directive|define
name|LOCK_EX
value|2
end_define

begin_define
define|#
directive|define
name|LOCK_NB
value|4
end_define

begin_define
define|#
directive|define
name|LOCK_UN
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SETSID
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|setsid
name|__P
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_GETDTABLESIZE
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|getdtablesize
name|__P
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_SETENV
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|setenv
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
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
name|NEED_VFORK
end_ifdef

begin_decl_stmt
specifier|extern
name|PID_T
name|vfork
name|__P
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

end_unit

