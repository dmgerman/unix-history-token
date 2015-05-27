begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|!
name|reallocarray
argument_list|(
name|NULL
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

