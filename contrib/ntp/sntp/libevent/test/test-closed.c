begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2007 Niels Provos<provos@citi.umich.edu>  * Copyright (c) 2007-2013 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"event2/event-config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT__HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<event.h>
end_include

begin_include
include|#
directive|include
file|<evutil.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EVENT____func__
end_ifdef

begin_define
define|#
directive|define
name|__func__
value|EVENT____func__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|timeval
name|timeout
init|=
block|{
literal|3
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|closed_cb
parameter_list|(
name|evutil_socket_t
name|fd
parameter_list|,
name|short
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
if|if
condition|(
name|EV_TIMEOUT
operator|&
name|event
condition|)
block|{
name|printf
argument_list|(
literal|"%s: Timeout!\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|EV_CLOSED
operator|&
name|event
condition|)
block|{
name|printf
argument_list|(
literal|"%s: detected socket close with success\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return;
block|}
name|printf
argument_list|(
literal|"%s: unable to detect socket close\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|SHUT_WR
end_ifndef

begin_define
define|#
directive|define
name|SHUT_WR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|struct
name|event_base
modifier|*
name|base
decl_stmt|;
name|struct
name|event_config
modifier|*
name|cfg
decl_stmt|;
name|struct
name|event
modifier|*
name|ev
decl_stmt|;
specifier|const
name|char
modifier|*
name|test
init|=
literal|"test string"
decl_stmt|;
name|evutil_socket_t
name|pair
index|[
literal|2
index|]
decl_stmt|;
comment|/* Initialize the library and check if the backend 	   supports EV_FEATURE_EARLY_CLOSE 	*/
name|cfg
operator|=
name|event_config_new
argument_list|()
expr_stmt|;
name|event_config_require_features
argument_list|(
name|cfg
argument_list|,
name|EV_FEATURE_EARLY_CLOSE
argument_list|)
expr_stmt|;
name|base
operator|=
name|event_base_new_with_config
argument_list|(
name|cfg
argument_list|)
expr_stmt|;
name|event_config_free
argument_list|(
name|cfg
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|base
condition|)
block|{
comment|/* Backend doesn't support EV_FEATURE_EARLY_CLOSE */
return|return
literal|0
return|;
block|}
comment|/* Create a pair of sockets */
if|if
condition|(
name|evutil_socketpair
argument_list|(
name|AF_UNIX
argument_list|,
name|SOCK_STREAM
argument_list|,
literal|0
argument_list|,
name|pair
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Send some data on socket 0 and immediately close it */
if|if
condition|(
name|send
argument_list|(
name|pair
index|[
literal|0
index|]
argument_list|,
name|test
argument_list|,
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|test
argument_list|)
operator|+
literal|1
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|shutdown
argument_list|(
name|pair
index|[
literal|0
index|]
argument_list|,
name|SHUT_WR
argument_list|)
expr_stmt|;
comment|/* Dispatch */
name|ev
operator|=
name|event_new
argument_list|(
name|base
argument_list|,
name|pair
index|[
literal|1
index|]
argument_list|,
name|EV_CLOSED
operator||
name|EV_TIMEOUT
argument_list|,
name|closed_cb
argument_list|,
name|event_self_cbarg
argument_list|()
argument_list|)
expr_stmt|;
name|event_add
argument_list|(
name|ev
argument_list|,
operator|&
name|timeout
argument_list|)
expr_stmt|;
name|event_base_dispatch
argument_list|(
name|base
argument_list|)
expr_stmt|;
comment|/* Finalize library */
name|event_base_free
argument_list|(
name|base
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

