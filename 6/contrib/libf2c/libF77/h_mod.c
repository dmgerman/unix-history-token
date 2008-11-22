begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function
name|shortint
name|h_mod
parameter_list|(
name|short
modifier|*
name|a
parameter_list|,
name|short
modifier|*
name|b
parameter_list|)
block|{
return|return
operator|(
operator|*
name|a
operator|%
operator|*
name|b
operator|)
return|;
block|}
end_function

end_unit

