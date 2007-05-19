begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*   @deftypefn Supplemental int gettimeofday (struct timeval *@var{tp}, void *@var{tz})  Writes the current time to @var{tp}.  This implementation requires that @var{tz} be NULL.  Returns 0 on success, -1 on failure.  @end deftypefn  */
end_comment

begin_function
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tp
parameter_list|,
name|void
modifier|*
name|tz
parameter_list|)
block|{
if|if
condition|(
name|tz
condition|)
name|abort
argument_list|()
expr_stmt|;
name|tp
operator|->
name|tv_usec
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|time
argument_list|(
operator|&
name|tp
operator|->
name|tv_sec
argument_list|)
operator|==
operator|(
name|time_t
operator|)
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

