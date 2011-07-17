begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wsign-conversion %s
end_comment

begin_comment
comment|// PR9345: make a subgroup of -Wconversion for signedness changes
end_comment

begin_function
name|void
name|test
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|unsigned
name|t0
init|=
name|x
decl_stmt|;
comment|// expected-warning {{implicit conversion changes signedness}}
name|unsigned
name|t1
init|=
operator|(
name|t0
operator|==
literal|5
condition|?
name|x
else|:
literal|0
operator|)
decl_stmt|;
comment|// expected-warning {{operand of ? changes signedness}}
block|}
end_function

end_unit

