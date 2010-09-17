begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|a
index|[
literal|2147483647U
index|]
index|[
literal|2147483647U
index|]
decl_stmt|;
comment|// expected-error{{array is too large}}
name|int
name|b
index|[
literal|1073741825U
operator|-
literal|1U
index|]
index|[
literal|2147483647U
index|]
decl_stmt|;
name|int
name|c
index|[
literal|18446744073709551615U
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|/
literal|2
index|]
decl_stmt|;
block|}
end_function

end_unit

