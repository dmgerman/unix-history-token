begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LINT
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: setitimer.c,v 1.1 2001/03/29 06:30:35 marka Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"port_before.h"
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_comment
comment|/*  * Setitimer emulation routine.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_SETITIMER
end_ifndef

begin_decl_stmt
name|int
name|__bindcompat_setitimer
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|__setitimer
parameter_list|(
name|int
name|which
parameter_list|,
specifier|const
name|struct
name|itimerval
modifier|*
name|value
parameter_list|,
name|struct
name|itimerval
modifier|*
name|ovalue
parameter_list|)
block|{
if|if
condition|(
name|alarm
argument_list|(
name|value
operator|->
name|it_value
operator|.
name|tv_sec
argument_list|)
operator|>=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

