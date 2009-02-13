begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function
name|double
name|d_imag
parameter_list|(
name|doublecomplex
modifier|*
name|z
parameter_list|)
block|{
return|return
operator|(
name|z
operator|->
name|i
operator|)
return|;
block|}
end_function

end_unit

