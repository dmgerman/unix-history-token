begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* time.c    Get the current time.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_if
if|#
directive|if
name|HAVE_TIME_H
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|time
end_ifndef

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get the time in seconds since the epoch, with optional    microseconds.  We use ixsysdep_process_time to get the microseconds    if it will work (it won't if it uses times, since that returns a    time based only on the process).  */
end_comment

begin_function
name|long
name|ixsysdep_time
parameter_list|(
name|pimicros
parameter_list|)
name|long
modifier|*
name|pimicros
decl_stmt|;
block|{
if|#
directive|if
name|HAVE_GETTIMEOFDAY
operator|||
name|HAVE_FTIME
return|return
name|ixsysdep_process_time
argument_list|(
name|pimicros
argument_list|)
return|;
else|#
directive|else
if|if
condition|(
name|pimicros
operator|!=
name|NULL
condition|)
operator|*
name|pimicros
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|long
operator|)
name|time
argument_list|(
operator|(
name|time_t
operator|*
operator|)
name|NULL
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

