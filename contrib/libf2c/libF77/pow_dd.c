begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_undef
undef|#
directive|undef
name|abs
end_undef

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function
name|double
name|pow_dd
parameter_list|(
name|doublereal
modifier|*
name|ap
parameter_list|,
name|doublereal
modifier|*
name|bp
parameter_list|)
block|{
return|return
operator|(
name|pow
argument_list|(
operator|*
name|ap
argument_list|,
operator|*
name|bp
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

