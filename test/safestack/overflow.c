begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_safestack %s -o %t
end_comment

begin_comment
comment|// RUN: %run %t
end_comment

begin_comment
comment|// RUN: %clang_nosafestack -fno-stack-protector %s -o %t
end_comment

begin_comment
comment|// RUN: not %run %t
end_comment

begin_comment
comment|// Test that buffer overflows on the unsafe stack do not affect variables on the
end_comment

begin_comment
comment|// safe stack.
end_comment

begin_comment
comment|// REQUIRES: stable-runtime
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|void
name|fct
parameter_list|(
specifier|volatile
name|int
modifier|*
name|buffer
parameter_list|)
block|{
name|memset
argument_list|(
name|buffer
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|7
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|value1
init|=
literal|42
decl_stmt|;
name|int
name|buffer
index|[
literal|5
index|]
decl_stmt|;
name|int
name|value2
init|=
literal|42
decl_stmt|;
name|fct
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
return|return
name|value1
operator|!=
literal|42
operator|||
name|value2
operator|!=
literal|42
return|;
block|}
end_function

end_unit

