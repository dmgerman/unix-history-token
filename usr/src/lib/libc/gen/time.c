begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	time.c	4.2	83/02/27	*/
end_comment

begin_comment
comment|/*  * Backwards compatible time call.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_function
name|time_t
name|time
parameter_list|(
name|t
parameter_list|)
name|time_t
modifier|*
name|t
decl_stmt|;
block|{
name|struct
name|timeval
name|tt
decl_stmt|;
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|tt
argument_list|,
operator|(
expr|struct
name|timezone
operator|*
operator|)
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|t
condition|)
operator|*
name|t
operator|=
name|tt
operator|.
name|tv_sec
expr_stmt|;
return|return
operator|(
name|tt
operator|.
name|tv_sec
operator|)
return|;
block|}
end_function

end_unit

