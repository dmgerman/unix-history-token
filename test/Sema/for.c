begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Check C99 6.8.5p3
end_comment

begin_function
name|void
name|b1
parameter_list|(
name|void
parameter_list|)
block|{
for|for
control|(
name|void
argument_list|(
operator|*
name|f
argument_list|)
argument_list|(
name|void
argument_list|)
init|;
condition|;
control|)
empty_stmt|;
block|}
end_function

begin_function
name|void
name|b2
parameter_list|(
name|void
parameter_list|)
block|{
for|for
control|(
name|void
name|f
argument_list|(
name|void
argument_list|)
init|;
condition|;
control|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{declaration of non-local variable}}
end_comment

begin_function
name|void
name|b3
parameter_list|(
name|void
parameter_list|)
block|{
for|for
control|(
specifier|static
name|int
name|f
init|;
condition|;
control|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{declaration of non-local variable}}
end_comment

begin_function
name|void
name|b4
parameter_list|(
name|void
parameter_list|)
block|{
for|for
control|(typedef
name|int
name|f
init|;
condition|;
control|)
empty_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{declaration of non-local variable}}
end_comment

end_unit

