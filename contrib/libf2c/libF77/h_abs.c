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
name|shortint
name|h_abs
argument_list|(
name|x
argument_list|)
name|shortint
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|shortint
name|h_abs
parameter_list|(
name|shortint
modifier|*
name|x
parameter_list|)
endif|#
directive|endif
block|{
if|if
condition|(
operator|*
name|x
operator|>=
literal|0
condition|)
return|return
operator|(
operator|*
name|x
operator|)
return|;
return|return
operator|(
operator|-
operator|*
name|x
operator|)
return|;
block|}
end_function

end_unit

