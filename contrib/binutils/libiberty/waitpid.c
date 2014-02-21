begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  @deftypefn Supplemental int waitpid (int @var{pid}, int *@var{status}, int)  This is a wrapper around the @code{wait} function.  Any ``special'' values of @var{pid} depend on your implementation of @code{wait}, as does the return value.  The third argument is unused in @libib{}.  @end deftypefn  */
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
file|"ansidecl.h"
end_include

begin_comment
comment|/* On some systems (such as WindISS), you must include<sys/types.h>    to get the definition of "pid_t" before you include<sys/wait.h>.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
name|pid_t
name|waitpid
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|int
modifier|*
name|stat_loc
parameter_list|,
name|int
name|options
name|ATTRIBUTE_UNUSED
parameter_list|)
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
end_function

end_unit

