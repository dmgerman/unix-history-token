begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * setsid() -- create session and set process group ID.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|pid_t
name|setsid
parameter_list|()
block|{
return|return
operator|(
name|setpgrp
argument_list|(
name|getpid
argument_list|()
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

