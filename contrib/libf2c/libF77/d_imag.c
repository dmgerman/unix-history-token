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

begin_decl_stmt
name|double
name|d_imag
argument_list|(
name|z
argument_list|)
name|doublecomplex
modifier|*
name|z
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|double
name|d_imag
parameter_list|(
name|doublecomplex
modifier|*
name|z
parameter_list|)
endif|#
directive|endif
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

