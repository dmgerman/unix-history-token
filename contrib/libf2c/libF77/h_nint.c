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
name|floor
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|shortint
name|h_nint
argument_list|(
name|x
argument_list|)
name|real
modifier|*
name|x
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
name|shortint
name|h_nint
parameter_list|(
name|real
modifier|*
name|x
parameter_list|)
endif|#
directive|endif
block|{
return|return
call|(
name|shortint
call|)
argument_list|(
operator|*
name|x
operator|>=
literal|0
condition|?
name|floor
argument_list|(
operator|*
name|x
operator|+
literal|.5
argument_list|)
else|:
operator|-
name|floor
argument_list|(
literal|.5
operator|-
operator|*
name|x
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

