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
name|pow
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|pow_dd
argument_list|(
name|ap
argument_list|,
name|bp
argument_list|)
name|doublereal
modifier|*
name|ap
decl_stmt|,
modifier|*
name|bp
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
endif|#
directive|endif
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

