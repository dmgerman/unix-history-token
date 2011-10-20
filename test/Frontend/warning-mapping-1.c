begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that -w has higher priority than -Werror.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -Wsign-compare -Werror -w %s
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|int
name|x
parameter_list|,
name|unsigned
name|y
parameter_list|)
block|{
return|return
name|x
operator|<
name|y
return|;
block|}
end_function

end_unit

