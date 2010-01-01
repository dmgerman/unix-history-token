begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wfloat-equal -verify %s
end_comment

begin_function
name|int
name|f1
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|)
block|{
return|return
name|x
operator|==
name|y
return|;
comment|// expected-warning {{comparing floating point with ==}}
block|}
end_function

begin_function
name|int
name|f2
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|)
block|{
return|return
name|x
operator|!=
name|y
return|;
comment|// expected-warning {{comparing floating point with ==}}
block|}
end_function

begin_function
name|int
name|f3
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
name|x
operator|==
name|x
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|f4
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
name|x
operator|==
literal|0.0
return|;
comment|// no-warning {{comparing}}
block|}
end_function

begin_function
name|int
name|f5
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
name|x
operator|==
name|__builtin_inf
argument_list|()
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|f7
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
name|x
operator|==
literal|3.14159
return|;
comment|// expected-warning {{comparing}}
block|}
end_function

end_unit

