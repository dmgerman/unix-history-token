begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_function
name|void
name|f
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|a
parameter_list|,
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|b
parameter_list|)
block|{
if|if
condition|(
name|a
operator|>
name|b
condition|)
block|{}
comment|// no warning
if|if
condition|(
name|a
operator|<
name|b
condition|)
block|{}
comment|// no warning
if|if
condition|(
name|a
operator|>=
name|b
condition|)
block|{}
comment|// no warning
if|if
condition|(
name|a
operator|<=
name|b
condition|)
block|{}
comment|// no warning
if|if
condition|(
name|a
operator|==
name|b
condition|)
block|{}
comment|// no warning
if|if
condition|(
name|a
operator|!=
name|b
condition|)
block|{}
comment|// no warning
if|if
condition|(
name|a
operator|==
literal|0
condition|)
block|{}
comment|// no warning
if|if
condition|(
name|a
operator|>
literal|0
condition|)
block|{}
comment|// no warning
if|if
condition|(
name|a
operator|>
literal|1
condition|)
block|{}
comment|// no warning
if|if
condition|(
name|a
operator|>
literal|2
condition|)
block|{}
comment|// no warning
if|if
condition|(
operator|!
name|a
operator|>
literal|0
condition|)
block|{}
comment|// no warning
if|if
condition|(
operator|!
name|a
operator|>
literal|1
condition|)
block|{}
comment|// expected-warning {{comparison of constant 1 with boolean expression is always false}}
if|if
condition|(
operator|!
name|a
operator|>
literal|2
condition|)
block|{}
comment|// expected-warning {{comparison of constant 2 with boolean expression is always false}}
if|if
condition|(
operator|!
name|a
operator|>
name|b
condition|)
block|{}
comment|// no warning
if|if
condition|(
operator|!
name|a
operator|>
operator|-
literal|1
condition|)
block|{}
comment|// expected-warning {{comparison of constant -1 with boolean expression is always true}}
block|}
end_function

end_unit

