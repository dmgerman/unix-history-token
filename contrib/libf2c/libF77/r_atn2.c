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
name|r_atn2
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
name|atan2
argument_list|(
operator|*
name|x
argument_list|,
operator|*
name|y
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

