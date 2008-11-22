begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_define
define|#
directive|define
name|log10e
value|0.43429448190325182765
end_define

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
name|r_lg10
parameter_list|(
name|real
modifier|*
name|x
parameter_list|)
block|{
return|return
operator|(
name|log10e
operator|*
name|log
argument_list|(
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

