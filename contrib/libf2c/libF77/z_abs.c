begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function_decl
name|double
name|f__cabs
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|double
name|z_abs
parameter_list|(
name|doublecomplex
modifier|*
name|z
parameter_list|)
block|{
return|return
operator|(
name|f__cabs
argument_list|(
name|z
operator|->
name|r
argument_list|,
name|z
operator|->
name|i
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

