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
comment|// expected-error{{array is too large}}
block|}
end_function

begin_function
name|void
name|pr8256
parameter_list|()
block|{
typedef|typedef
name|char
name|a
index|[
literal|1LL
operator|<<
literal|61
index|]
typedef|;
comment|// expected-error {{array is too large}}
typedef|typedef
name|char
name|b
index|[
operator|(
name|long
name|long
operator|)
sizeof|sizeof
argument_list|(
name|a
argument_list|)
operator|-
literal|1
index|]
typedef|;
block|}
end_function

end_unit

