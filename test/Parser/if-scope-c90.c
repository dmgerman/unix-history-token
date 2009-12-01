begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify -std=c90 %s
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
name|z
parameter_list|)
block|{
if|if
condition|(
name|z
operator|>
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|enum
block|{
name|a
operator|,
name|b
block|}
block|)
end_function

begin_return
unit|)
return|return
name|a
return|;
end_return

begin_return
return|return
name|b
return|;
end_return

unit|}
end_unit

