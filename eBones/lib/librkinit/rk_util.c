begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * $FreeBSD$  * $Source: /usr/src/eBones/librkinit/RCS/rk_util.c,v $  * $Author: dglo $  *  * This file contains internal routines for general use by the rkinit  * library and server.    *  * See the comment at the top of rk_lib.c for a description of the naming  * conventions used within the rkinit library.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SABER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
name|defined
argument_list|(
name|RCS_HDRS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint || SABER || LOCORE || RCS_HDRS */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_include
include|#
directive|include
file|<rkinit.h>
end_include

begin_include
include|#
directive|include
file|<rkinit_private.h>
end_include

begin_include
include|#
directive|include
file|<rkinit_err.h>
end_include

begin_define
define|#
directive|define
name|RKINIT_TIMEOUTVAL
value|60
end_define

begin_decl_stmt
specifier|static
name|char
name|errbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|jmp_buf
name|timeout_env
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|_rkinit_server_
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|void
name|rki_dmsg
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
else|#
directive|else
function|void rki_dmsg
parameter_list|(
name|string
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
endif|#
directive|endif
comment|/* __STDC__ */
block|{
if|if
condition|(
name|_rkinit_server_
condition|)
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
name|string
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|string
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_decl_stmt
name|void
name|rki_i_am_server
argument_list|(
name|void
argument_list|)
else|#
directive|else
name|void
name|rki_i_am_server
argument_list|()
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|_rkinit_server_
operator|=
name|TRUE
expr_stmt|;
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|void
name|rki_dmsg
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
else|#
directive|else
function|void rki_dmsg
parameter_list|(
name|string
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
endif|#
directive|endif
comment|/* __STDC__ */
block|{
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
specifier|const
name|char
modifier|*
name|rki_mt_to_string
parameter_list|(
name|int
name|mt
parameter_list|)
else|#
directive|else
function|const char *rki_mt_to_string
parameter_list|(
name|mt
parameter_list|)
name|int
name|mt
decl_stmt|;
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|char
modifier|*
name|string
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|mt
condition|)
block|{
case|case
name|MT_STATUS
case|:
name|string
operator|=
literal|"Status message"
expr_stmt|;
break|break;
case|case
name|MT_CVERSION
case|:
name|string
operator|=
literal|"Client version"
expr_stmt|;
break|break;
case|case
name|MT_SVERSION
case|:
name|string
operator|=
literal|"Server version"
expr_stmt|;
break|break;
case|case
name|MT_RKINIT_INFO
case|:
name|string
operator|=
literal|"Rkinit information"
expr_stmt|;
break|break;
case|case
name|MT_SKDC
case|:
name|string
operator|=
literal|"Server kdc packet"
expr_stmt|;
break|break;
case|case
name|MT_CKDC
case|:
name|string
operator|=
literal|"Client kdc packet"
expr_stmt|;
break|break;
case|case
name|MT_AUTH
case|:
name|string
operator|=
literal|"Authenticator"
expr_stmt|;
break|break;
case|case
name|MT_DROP
case|:
name|string
operator|=
literal|"Drop server"
expr_stmt|;
break|break;
default|default:
name|string
operator|=
literal|"Unknown message type"
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|string
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|int
name|rki_choose_version
parameter_list|(
name|int
modifier|*
name|version
parameter_list|)
else|#
directive|else
function|int rki_choose_version
parameter_list|(
name|version
parameter_list|)
name|int
modifier|*
name|version
decl_stmt|;
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|int
name|s_lversion
decl_stmt|;
comment|/* lowest version number server supports */
name|int
name|s_hversion
decl_stmt|;
comment|/* highest version number server supports */
name|int
name|status
init|=
name|RKINIT_SUCCESS
decl_stmt|;
if|if
condition|(
operator|(
name|status
operator|=
name|rki_rpc_exchange_version_info
argument_list|(
name|RKINIT_LVERSION
argument_list|,
name|RKINIT_HVERSION
argument_list|,
operator|&
name|s_lversion
argument_list|,
operator|&
name|s_hversion
argument_list|)
operator|)
operator|!=
name|RKINIT_SUCCESS
condition|)
return|return
operator|(
name|status
operator|)
return|;
operator|*
name|version
operator|=
name|min
argument_list|(
name|RKINIT_HVERSION
argument_list|,
name|s_hversion
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|version
operator|<
name|max
argument_list|(
name|RKINIT_LVERSION
argument_list|,
name|s_lversion
argument_list|)
condition|)
block|{
name|sprintf
argument_list|(
name|errbuf
argument_list|,
literal|"Can't run version %d client against version %d server."
argument_list|,
name|RKINIT_HVERSION
argument_list|,
name|s_hversion
argument_list|)
expr_stmt|;
name|rkinit_errmsg
argument_list|(
name|errbuf
argument_list|)
expr_stmt|;
name|status
operator|=
name|RKINIT_VERSION
expr_stmt|;
block|}
return|return
operator|(
name|status
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|int
name|rki_send_rkinit_info
parameter_list|(
name|int
name|version
parameter_list|,
name|rkinit_info
modifier|*
name|info
parameter_list|)
else|#
directive|else
function|int rki_send_rkinit_info
parameter_list|(
name|version
parameter_list|,
name|info
parameter_list|)
name|int
name|version
decl_stmt|;
name|rkinit_info
modifier|*
name|info
decl_stmt|;
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|int
name|status
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|status
operator|=
name|rki_rpc_send_rkinit_info
argument_list|(
name|info
argument_list|)
operator|)
operator|!=
name|RKINIT_SUCCESS
condition|)
return|return
operator|(
name|status
operator|)
return|;
return|return
operator|(
name|rki_rpc_get_status
argument_list|()
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
specifier|static
name|void
name|rki_timeout
parameter_list|(
name|int
name|signal
parameter_list|)
else|#
directive|else
function|static void rki_timeout
parameter_list|(
name|signal
parameter_list|)
name|int
name|signal
decl_stmt|;
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|sprintf
argument_list|(
name|errbuf
argument_list|,
literal|"%d seconds exceeded."
argument_list|,
name|RKINIT_TIMEOUTVAL
argument_list|)
expr_stmt|;
name|rkinit_errmsg
argument_list|(
name|errbuf
argument_list|)
expr_stmt|;
name|longjmp
argument_list|(
name|timeout_env
argument_list|,
name|RKINIT_TIMEOUT
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
specifier|static
name|void
name|set_timer
parameter_list|(
name|int
name|secs
parameter_list|)
else|#
directive|else
function|static void set_timer
parameter_list|(
name|secs
parameter_list|)
name|int
name|secs
decl_stmt|;
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|struct
name|itimerval
name|timer
decl_stmt|;
comment|/* Time structure for timeout */
comment|/* Set up an itimer structure to send an alarm signal after TIMEOUT        seconds. */
name|timer
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|secs
expr_stmt|;
name|timer
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|timer
operator|.
name|it_value
operator|=
name|timer
operator|.
name|it_interval
expr_stmt|;
operator|(
name|void
operator|)
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|timer
argument_list|,
operator|(
expr|struct
name|itimerval
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_macro
name|void
argument_list|(
argument|*rki_setup_timer(jmp_buf env)
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|int
operator|)
else|#
directive|else
name|void
argument_list|(
argument|*rki_setup_timer(env)
argument_list|)
operator|(
name|int
operator|)
name|jmp_buf
name|env
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_block
block|{
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|env
argument_list|,
operator|(
name|char
operator|*
operator|)
name|timeout_env
argument_list|,
sizeof|sizeof
argument_list|(
name|jmp_buf
argument_list|)
argument_list|)
expr_stmt|;
name|set_timer
argument_list|(
name|RKINIT_TIMEOUTVAL
argument_list|)
expr_stmt|;
return|return
operator|(
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|rki_timeout
argument_list|)
operator|)
return|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_decl_stmt
name|void
name|rki_restore_timer
argument_list|(
name|void
argument_list|(
operator|*
name|old_alrm
argument_list|)
argument_list|(
name|int
argument_list|)
argument_list|)
else|#
directive|else
name|void
name|rki_restore_timer
argument_list|(
name|old_alrm
argument_list|)
name|void
argument_list|(
operator|*
name|old_alrm
argument_list|)
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_block
block|{
name|set_timer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|old_alrm
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

