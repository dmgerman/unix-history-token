begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
name|double
name|atan2
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|r_atn2
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
name|real
modifier|*
name|x
decl_stmt|,
modifier|*
name|y
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

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
endif|#
directive|endif
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

