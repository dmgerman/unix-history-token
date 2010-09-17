begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-apple-darwin -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|x0
index|[
literal|1073741824
index|]
decl_stmt|;
comment|// expected-error{{array is too large}}
name|int
name|x1
index|[
literal|1073741824
operator|+
literal|1
index|]
decl_stmt|;
comment|// expected-error{{array is too large}}
name|int
name|x2
index|[
operator|(
name|unsigned
operator|)
literal|1073741824
index|]
decl_stmt|;
comment|// expected-error{{array is too large}}
name|int
name|x3
index|[
operator|(
name|unsigned
operator|)
literal|1073741824
operator|+
literal|1
index|]
decl_stmt|;
comment|// expected-error{{array is too large}}
name|int
name|x4
index|[
literal|1073741824
operator|-
literal|1
index|]
decl_stmt|;
block|}
end_function

end_unit

