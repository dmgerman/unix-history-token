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
name|h_len
argument_list|(
name|s
argument_list|,
name|n
argument_list|)
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|n
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|shortint
name|h_len
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|ftnlen
name|n
parameter_list|)
endif|#
directive|endif
block|{
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

end_unit

