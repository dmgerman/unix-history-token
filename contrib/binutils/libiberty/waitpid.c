begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|waitpid
parameter_list|(
name|pid
parameter_list|,
name|stat_loc
parameter_list|,
name|options
parameter_list|)
name|int
name|pid
decl_stmt|,
decl|*
name|stat_loc
decl_stmt|,
name|options
decl_stmt|;
end_function

begin_block
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
name|int
name|wpid
init|=
name|wait
argument_list|(
name|stat_loc
argument_list|)
decl_stmt|;
if|if
condition|(
name|wpid
operator|==
name|pid
operator|||
name|wpid
operator|==
operator|-
literal|1
condition|)
return|return
name|wpid
return|;
block|}
block|}
end_block

end_unit

