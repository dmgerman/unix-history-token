begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* putchard - putchar that takes a double and returns 0. */
end_comment

begin_function
specifier|extern
name|double
name|putchard
parameter_list|(
name|double
name|X
parameter_list|)
block|{
name|putchar
argument_list|(
operator|(
name|char
operator|)
name|X
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

