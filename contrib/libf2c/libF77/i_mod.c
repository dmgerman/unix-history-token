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
name|integer
name|i_mod
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
name|integer
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|integer
name|i_mod
parameter_list|(
name|integer
modifier|*
name|a
parameter_list|,
name|integer
modifier|*
name|b
parameter_list|)
endif|#
directive|endif
block|{
return|return
operator|(
operator|*
name|a
operator|%
operator|*
name|b
operator|)
return|;
block|}
end_function

end_unit

