begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2004 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_MISC_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_MISC_H
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_function_decl
name|char
modifier|*
name|ssh_get_progname
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETSID
end_ifndef

begin_define
define|#
directive|define
name|setsid
parameter_list|()
value|setpgrp(0, getpid())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SETSID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETENV
end_ifndef

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SETENV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETLOGIN
end_ifndef

begin_function_decl
name|int
name|setlogin
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

begin_comment
comment|/* !HAVE_SETLOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INNETGR
end_ifndef

begin_function_decl
name|int
name|innetgr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
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

begin_comment
comment|/* HAVE_INNETGR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SETEUID
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SETREUID
argument_list|)
end_if

begin_function_decl
name|int
name|seteuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_SETEUID)&& defined(HAVE_SETREUID) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SETEGID
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SETRESGID
argument_list|)
end_if

begin_function_decl
name|int
name|setegid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_SETEGID)&& defined(HAVE_SETRESGID) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STRERROR
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_ERRLIST
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_NERR
argument_list|)
end_if

begin_function_decl
specifier|const
name|char
modifier|*
name|strerror
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
operator|!
name|defined
argument_list|(
name|HAVE_SETLINEBUF
argument_list|)
end_if

begin_define
define|#
directive|define
name|setlinebuf
parameter_list|(
name|a
parameter_list|)
value|(setvbuf((a), NULL, _IOLBF, 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UTIMES
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_TIMEVAL
end_ifndef

begin_struct
struct|struct
name|timeval
block|{
name|long
name|tv_sec
decl_stmt|;
name|long
name|tv_usec
decl_stmt|;
block|}
endif|#
directive|endif
comment|/* HAVE_STRUCT_TIMEVAL */
name|int
name|utimes
argument_list|(
name|char
operator|*
argument_list|,
expr|struct
name|timeval
operator|*
argument_list|)
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UTIMES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TRUNCATE
end_ifndef

begin_function_decl
name|int
name|truncate
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TRUNCATE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_NANOSLEEP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_NSLEEP
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_TIMESPEC
end_ifndef

begin_struct
struct|struct
name|timespec
block|{
name|time_t
name|tv_sec
decl_stmt|;
name|long
name|tv_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|nanosleep
parameter_list|(
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_USLEEP
end_ifndef

begin_function_decl
name|int
name|usleep
parameter_list|(
name|unsigned
name|int
name|useconds
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TCGETPGRP
end_ifndef

begin_function_decl
name|pid_t
name|tcgetpgrp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TCSENDBREAK
end_ifndef

begin_function_decl
name|int
name|tcsendbreak
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UNSETENV
end_ifndef

begin_function_decl
name|int
name|unsetenv
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

begin_comment
comment|/* wrapper for signal interface */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|mysig_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|mysig_t
name|mysignal
parameter_list|(
name|int
name|sig
parameter_list|,
name|mysig_t
name|act
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|signal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|mysignal(a,b)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ISBLANK
end_ifndef

begin_function_decl
name|int
name|isblank
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETPGID
end_ifndef

begin_function_decl
name|pid_t
name|getpgid
parameter_list|(
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ENDGRENT
end_ifndef

begin_define
define|#
directive|define
name|endgrent
parameter_list|()
value|do { } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_KRB5_GET_ERROR_MESSAGE
end_ifndef

begin_define
define|#
directive|define
name|krb5_get_error_message
value|krb5_get_err_text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_KRB5_FREE_ERROR_MESSAGE
end_ifndef

begin_define
define|#
directive|define
name|krb5_free_error_message
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|do { } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PLEDGE
end_ifndef

begin_function_decl
name|int
name|pledge
parameter_list|(
specifier|const
name|char
modifier|*
name|promises
parameter_list|,
specifier|const
name|char
modifier|*
name|paths
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bsd-err.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ERR
end_ifndef

begin_function_decl
name|void
name|err
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ERRX
end_ifndef

begin_function_decl
name|void
name|errx
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_WARN
end_ifndef

begin_function_decl
name|void
name|warn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_LLABS
end_ifndef

begin_function_decl
name|long
name|long
name|llabs
parameter_list|(
name|long
name|long
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
comment|/* _BSD_MISC_H */
end_comment

end_unit

