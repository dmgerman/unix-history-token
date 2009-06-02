begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep readnone
end_comment

begin_comment
comment|// PR2520
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function
name|double
name|f
parameter_list|(
name|double
modifier|*
name|x
parameter_list|,
name|double
modifier|*
name|y
parameter_list|)
block|{
return|return
name|fabs
argument_list|(
operator|*
name|x
operator|+
operator|*
name|y
argument_list|)
return|;
block|}
end_function

end_unit

