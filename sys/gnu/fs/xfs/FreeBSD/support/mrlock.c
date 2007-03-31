begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<support/debug.h>
end_include

begin_include
include|#
directive|include
file|<support/mrlock.h>
end_include

begin_function
name|int
name|ismrlocked
parameter_list|(
name|mrlock_t
modifier|*
name|mrp
parameter_list|,
name|int
name|type
parameter_list|)
block|{
name|sx_assert
argument_list|(
name|mrp
argument_list|,
name|SX_LOCKED
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|MR_UPDATE
condition|)
return|return
name|sx_xlocked
argument_list|(
name|mrp
argument_list|)
return|;
return|return
literal|1
return|;
block|}
end_function

end_unit

