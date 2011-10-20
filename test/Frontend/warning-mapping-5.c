begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that #pragma diagnostic warning overrides -Werror. This matches GCC's
end_comment

begin_comment
comment|// original documentation, but not its earlier implementations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -Werror %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|warning
literal|"-Wsign-compare"
end_pragma

begin_function
name|int
name|f0
parameter_list|(
name|int
name|x
parameter_list|,
name|unsigned
name|y
parameter_list|)
block|{
return|return
name|x
operator|<
name|y
return|;
comment|// expected-warning {{comparison of integers}}
block|}
end_function

end_unit

