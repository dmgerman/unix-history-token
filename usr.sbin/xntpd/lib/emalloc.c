begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * emalloc - return new memory obtained from the system.  Belch if none.  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"ntp_malloc.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_function
name|char
modifier|*
name|emalloc
parameter_list|(
name|size
parameter_list|)
name|u_int
name|size
decl_stmt|;
block|{
name|char
modifier|*
name|mem
decl_stmt|;
if|if
condition|(
operator|(
name|mem
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|size
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"No more memory!"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|mem
return|;
block|}
end_function

end_unit

