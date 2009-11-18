begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -std=c90 -verify
end_comment

begin_comment
comment|// RUN: clang-cc %s -std=c99
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
operator|+
sizeof|sizeof
argument_list|(
expr|enum
block|{
name|a
block|}
block|)
end_function

begin_comment
unit|)
comment|// expected-note {{previous definition is here}}
end_comment

begin_return
return|return
literal|1
operator|+
sizeof|sizeof
argument_list|(
expr|enum
block|{
name|a
block|}
argument_list|)
return|;
end_return

begin_comment
comment|// expected-error {{redefinition of enumerator 'a'}}
end_comment

begin_return
return|return
literal|0
return|;
end_return

unit|}
end_unit

