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
if|#
directive|if
name|HAVE_NAPMS
operator|||
name|HAVE_NAP
operator|||
name|HAVE_USLEEP
operator|||
name|HAVE_SELECT
operator|||
name|HAVE_POLL
name|int
name|i
decl_stmt|;
comment|/* In this case, usysdep_pause is accurate.  */
for|for
control|(
name|i
operator|=
literal|2
operator|*
name|c
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
name|usysdep_pause
argument_list|()
expr_stmt|;
else|#
directive|else
comment|/* On some system sleep (1) may not sleep at all.  Avoid this sort      of problem by always doing at least sleep (2).  */
if|if
condition|(
name|c
operator|<
literal|2
condition|)
name|c
operator|=
literal|2
expr_stmt|;
operator|(
name|void
operator|)
name|sleep
argument_list|(
name|c
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

