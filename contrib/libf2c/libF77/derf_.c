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
name|erf
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|G77_derf_0
argument_list|(
name|x
argument_list|)
name|doublereal
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|double
name|erf
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|double
name|G77_derf_0
parameter_list|(
name|doublereal
modifier|*
name|x
parameter_list|)
endif|#
directive|endif
block|{
return|return
operator|(
name|erf
argument_list|(
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

