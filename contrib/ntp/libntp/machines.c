begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* machines.c - provide special support for peculiar architectures  *  * Real bummers unite !  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_machine.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME_H
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
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_include
include|#
directive|include
file|<conio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_VXWORKS
end_ifdef

begin_include
include|#
directive|include
file|"taskLib.h"
end_include

begin_include
include|#
directive|include
file|"sysLib.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_comment
comment|/*	some translations to the world of vxWorkings -casey */
end_comment

begin_comment
comment|/* first some netdb type things */
end_comment

begin_include
include|#
directive|include
file|"ioLib.h"
end_include

begin_include
include|#
directive|include
file|<socket.h>
end_include

begin_decl_stmt
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_function
name|struct
name|hostent
modifier|*
name|gethostbyname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
block|{
name|struct
name|hostent
modifier|*
name|host1
decl_stmt|;
name|h_errno
operator|=
literal|0
expr_stmt|;
comment|/* we are always successful!!! */
name|host1
operator|=
operator|(
expr|struct
name|hostent
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|hostent
argument_list|)
argument_list|)
expr_stmt|;
name|host1
operator|->
name|h_name
operator|=
name|name
expr_stmt|;
name|host1
operator|->
name|h_addrtype
operator|=
name|AF_INET
expr_stmt|;
name|host1
operator|->
name|h_aliases
operator|=
name|name
expr_stmt|;
name|host1
operator|->
name|h_length
operator|=
literal|4
expr_stmt|;
name|host1
operator|->
name|h_addr_list
index|[
literal|0
index|]
operator|=
operator|(
name|char
operator|*
operator|)
name|hostGetByName
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|host1
operator|->
name|h_addr_list
index|[
literal|1
index|]
operator|=
name|NULL
expr_stmt|;
return|return
name|host1
return|;
block|}
end_function

begin_function
name|struct
name|hostent
modifier|*
name|gethostbyaddr
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|addr_type
parameter_list|)
block|{
name|struct
name|hostent
modifier|*
name|host1
decl_stmt|;
name|h_errno
operator|=
literal|0
expr_stmt|;
comment|/* we are always successful!!! */
name|host1
operator|=
operator|(
expr|struct
name|hostent
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|hostent
argument_list|)
argument_list|)
expr_stmt|;
name|host1
operator|->
name|h_name
operator|=
name|name
expr_stmt|;
name|host1
operator|->
name|h_addrtype
operator|=
name|AF_INET
expr_stmt|;
name|host1
operator|->
name|h_aliases
operator|=
name|name
expr_stmt|;
name|host1
operator|->
name|h_length
operator|=
literal|4
expr_stmt|;
name|host1
operator|->
name|h_addr_list
operator|=
name|NULL
expr_stmt|;
return|return
name|host1
return|;
block|}
end_function

begin_function
name|struct
name|servent
modifier|*
name|getservbyname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|type
parameter_list|)
block|{
name|struct
name|servent
modifier|*
name|serv1
decl_stmt|;
name|serv1
operator|=
operator|(
expr|struct
name|servent
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|servent
argument_list|)
argument_list|)
expr_stmt|;
name|serv1
operator|->
name|s_name
operator|=
literal|"ntp"
expr_stmt|;
comment|/* official service name */
name|serv1
operator|->
name|s_aliases
operator|=
name|NULL
expr_stmt|;
comment|/* alias list */
name|serv1
operator|->
name|s_port
operator|=
literal|123
expr_stmt|;
comment|/* port # */
name|serv1
operator|->
name|s_proto
operator|=
literal|"udp"
expr_stmt|;
comment|/* protocol to use */
return|return
name|serv1
return|;
block|}
end_function

begin_comment
comment|/* second  * vxworks thinks it has insomnia  * we have to sleep for number of seconds  */
end_comment

begin_define
define|#
directive|define
name|CLKRATE
value|sysClkRateGet()
end_define

begin_comment
comment|/* I am not sure how valid the granularity is - it is from G. Eger's port */
end_comment

begin_define
define|#
directive|define
name|CLK_GRANULARITY
value|1
end_define

begin_comment
comment|/* Granularity of system clock in usec	*/
end_comment

begin_comment
comment|/* Used to round down # usecs/tick		*/
end_comment

begin_comment
comment|/* On a VCOM-100, PIT gets 8 MHz clk,	*/
end_comment

begin_comment
comment|/*& it prescales by 32, thus 4 usec	*/
end_comment

begin_comment
comment|/* on mv167, granularity is 1usec anyway*/
end_comment

begin_comment
comment|/* To defeat rounding, set to 1 		*/
end_comment

begin_define
define|#
directive|define
name|USECS_PER_SEC
value|MILLION
end_define

begin_comment
comment|/* Microseconds per second	*/
end_comment

begin_define
define|#
directive|define
name|TICK
value|(((USECS_PER_SEC / CLKRATE) / CLK_GRANULARITY) * CLK_GRANULARITY)
end_define

begin_comment
comment|/* emulate unix sleep  * casey  */
end_comment

begin_function
name|void
name|sleep
parameter_list|(
name|int
name|seconds
parameter_list|)
block|{
name|taskDelay
argument_list|(
name|seconds
operator|*
name|TICK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* emulate unix alarm  * that pauses and calls SIGALRM after the seconds are up...  * so ... taskDelay() fudged for seconds should amount to the same thing.  * casey  */
end_comment

begin_function
name|void
name|alarm
parameter_list|(
name|int
name|seconds
parameter_list|)
block|{
name|sleep
argument_list|(
name|seconds
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_VXWORKS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_PTX
end_ifdef

begin_comment
comment|/* Does PTX still need this? */
end_comment

begin_comment
comment|/*#include<sys/types.h>	*/
end_comment

begin_include
include|#
directive|include
file|<sys/procstats.h>
end_include

begin_function
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|)
block|{
comment|/* 	 * hi, this is Sequents sneak path to get to a clock 	 * this is also the most logical syscall for such a function 	 */
return|return
operator|(
name|get_process_stats
argument_list|(
name|tvp
argument_list|,
name|PS_SELF
argument_list|,
operator|(
expr|struct
name|procstats
operator|*
operator|)
literal|0
argument_list|,
operator|(
expr|struct
name|procstats
operator|*
operator|)
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_PTX */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|set_tod_using
init|=
literal|"UNKNOWN"
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|ntp_set_tod
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|,
name|void
modifier|*
name|tzp
parameter_list|)
block|{
name|int
name|rc
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_CLOCK_SETTIME
block|{
name|struct
name|timespec
name|ts
decl_stmt|;
comment|/* Convert timeval to timespec */
name|ts
operator|.
name|tv_sec
operator|=
name|tvp
operator|->
name|tv_sec
expr_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
literal|1000
operator|*
name|tvp
operator|->
name|tv_usec
expr_stmt|;
name|rc
operator|=
name|clock_settime
argument_list|(
name|CLOCK_REALTIME
argument_list|,
operator|&
name|ts
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|rc
condition|)
block|{
name|set_tod_using
operator|=
literal|"clock_settime"
expr_stmt|;
return|return
name|rc
return|;
block|}
block|}
endif|#
directive|endif
comment|/* HAVE_CLOCK_SETTIME */
ifdef|#
directive|ifdef
name|HAVE_SETTIMEOFDAY
block|{
name|rc
operator|=
name|SETTIMEOFDAY
argument_list|(
name|tvp
argument_list|,
name|tzp
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|rc
condition|)
block|{
name|set_tod_using
operator|=
literal|"settimeofday"
expr_stmt|;
return|return
name|rc
return|;
block|}
block|}
endif|#
directive|endif
comment|/* HAVE_SETTIMEOFDAY */
ifdef|#
directive|ifdef
name|HAVE_STIME
block|{
name|long
name|tp
init|=
name|tvp
operator|->
name|tv_sec
decl_stmt|;
name|rc
operator|=
name|stime
argument_list|(
operator|&
name|tp
argument_list|)
expr_stmt|;
comment|/* lie as bad as SysVR4 */
if|if
condition|(
operator|!
name|rc
condition|)
block|{
name|set_tod_using
operator|=
literal|"stime"
expr_stmt|;
return|return
name|rc
return|;
block|}
block|}
endif|#
directive|endif
comment|/* HAVE_STIME */
name|set_tod_using
operator|=
literal|"Failed!"
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not SYS_WINNT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_VXWORKS
argument_list|)
end_if

begin_comment
comment|/* getpass is used in ntpq.c and ntpdc.c */
end_comment

begin_function
name|char
modifier|*
name|getpass
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt
parameter_list|)
block|{
name|int
name|c
decl_stmt|,
name|i
decl_stmt|;
specifier|static
name|char
name|password
index|[
literal|32
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s"
argument_list|,
name|prompt
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|password
argument_list|)
operator|-
literal|1
operator|&&
operator|(
operator|(
name|c
operator|=
name|_getch
argument_list|()
operator|)
operator|!=
literal|'\n'
operator|)
condition|;
name|i
operator|++
control|)
block|{
name|password
index|[
name|i
index|]
operator|=
operator|(
name|char
operator|)
name|c
expr_stmt|;
block|}
name|password
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|password
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_MEMSET
argument_list|)
end_if

begin_function
name|void
name|ntp_memset
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|c
parameter_list|)
block|{
while|while
condition|(
name|c
operator|--
operator|>
literal|0
condition|)
operator|*
name|a
operator|++
operator|=
operator|(
name|char
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*POSIX*/
end_comment

end_unit

