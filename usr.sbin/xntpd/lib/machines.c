begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* machines.c - provide special support for peculiar architectures  *  * Real bummers unite !  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_PTX
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/procstats.h>
end_include

begin_function
name|int
name|settimeofday
parameter_list|(
name|tvp
parameter_list|)
name|struct
name|timeval
modifier|*
name|tvp
decl_stmt|;
block|{
return|return
operator|(
name|stime
argument_list|(
operator|&
name|tvp
operator|->
name|tv_sec
argument_list|)
operator|)
return|;
comment|/* lie as bad as SysVR4 */
block|}
end_function

begin_function
name|int
name|gettimeofday
parameter_list|(
name|tvp
parameter_list|)
name|struct
name|timeval
modifier|*
name|tvp
decl_stmt|;
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NTP_POSIX_SOURCE
argument_list|)
operator|||
name|defined
argument_list|(
name|NTP_NEED_BOPS
argument_list|)
end_if

begin_function
name|void
name|ntp_memset
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|,
name|c
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|;
name|int
name|x
decl_stmt|,
name|c
decl_stmt|;
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_CLOCK_SETTIME
argument_list|)
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_function
name|int
name|settimeofday
parameter_list|(
name|tvp
parameter_list|)
name|struct
name|timeval
modifier|*
name|tvp
decl_stmt|;
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
return|return
name|clock_settime
argument_list|(
name|CLOCK_REALTIME
argument_list|,
operator|&
name|ts
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_CLOCK_SETTIME */
end_comment

end_unit

