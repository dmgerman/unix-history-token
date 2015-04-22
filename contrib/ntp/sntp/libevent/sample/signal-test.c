begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Compile with:  * cc -I/usr/local/include -o signal-test \  *   signal-test.c -L/usr/local/lib -levent  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<event2/event-config.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

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
file|<event2/event.h>
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
name|int
name|called
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|signal_cb
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
name|struct
name|event
modifier|*
name|signal
init|=
name|arg
decl_stmt|;
name|printf
argument_list|(
literal|"%s: got signal %d\n"
argument_list|,
name|__func__
argument_list|,
name|event_get_signal
argument_list|(
name|signal
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|called
operator|>=
literal|2
condition|)
name|event_del
argument_list|(
name|signal
argument_list|)
expr_stmt|;
name|called
operator|++
expr_stmt|;
block|}
end_function

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
name|event
modifier|*
name|signal_int
decl_stmt|;
name|struct
name|event_base
modifier|*
name|base
decl_stmt|;
ifdef|#
directive|ifdef
name|_WIN32
name|WORD
name|wVersionRequested
decl_stmt|;
name|WSADATA
name|wsaData
decl_stmt|;
name|wVersionRequested
operator|=
name|MAKEWORD
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|WSAStartup
argument_list|(
name|wVersionRequested
argument_list|,
operator|&
name|wsaData
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Initalize the event library */
name|base
operator|=
name|event_base_new
argument_list|()
expr_stmt|;
comment|/* Initalize one event */
name|signal_int
operator|=
name|evsignal_new
argument_list|(
name|base
argument_list|,
name|SIGINT
argument_list|,
name|signal_cb
argument_list|,
name|event_self_cbarg
argument_list|()
argument_list|)
expr_stmt|;
name|event_add
argument_list|(
name|signal_int
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|event_base_dispatch
argument_list|(
name|base
argument_list|)
expr_stmt|;
name|event_base_free
argument_list|(
name|base
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

