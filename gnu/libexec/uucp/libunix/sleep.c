begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sleep.c    Sleep for a number of seconds.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_function
name|void
name|usysdep_sleep
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|sleep
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

