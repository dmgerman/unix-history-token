begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function
name|double
name|d_prod
parameter_list|(
name|real
modifier|*
name|x
parameter_list|,
name|real
modifier|*
name|y
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|*
name|x
operator|)
operator|*
operator|(
operator|*
name|y
operator|)
operator|)
return|;
block|}
end_function

end_unit

