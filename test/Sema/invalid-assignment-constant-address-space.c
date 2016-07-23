begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -pedantic -fsyntax-only
end_comment

begin_define
define|#
directive|define
name|OPENCL_CONSTANT
value|8388354
end_define

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
name|OPENCL_CONSTANT
argument_list|)
operator|)
argument_list|)
name|c
index|[
literal|3
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|c
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
comment|//expected-error{{read-only variable is not assignable}}
block|}
end_function

end_unit

