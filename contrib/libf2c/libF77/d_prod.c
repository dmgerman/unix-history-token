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
name|d_prod
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

begin_function
name|double
name|d_prod
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
operator|(
operator|*
name|x
operator|)
operator|*
operator|(
operator|*
name|y
operator|)
operator|)
return|;
block|}
end_function

end_unit

