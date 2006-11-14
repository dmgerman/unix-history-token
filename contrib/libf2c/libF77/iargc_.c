begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function
name|ftnint
name|G77_iargc_0
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|int
name|f__xargc
decl_stmt|;
return|return
operator|(
name|f__xargc
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

