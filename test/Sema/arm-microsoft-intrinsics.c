begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7 -fms-extensions -fsyntax-only -ffreestanding -verify %s
end_comment

begin_function
name|unsigned
name|int
name|test_MoveFromCoprocessor
parameter_list|(
specifier|const
name|unsigned
name|int
name|value
parameter_list|)
block|{
return|return
name|_MoveFromCoprocessor
argument_list|(
name|value
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
return|;
comment|// expected-error-re {{argument to {{.*}} must be a constant integer}}
block|}
end_function

begin_function
name|void
name|test_MoveToCoprocessor
parameter_list|(
specifier|const
name|unsigned
name|int
name|value
parameter_list|)
block|{
name|_MoveToCoprocessor
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|value
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// expected-error-re {{argument to {{.*}} must be a constant integer}}
block|}
end_function

end_unit

