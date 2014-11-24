begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -x c++ %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|s
operator|=
operator|(
name|char
index|[]
operator|)
block|{
literal|"whatever"
block|}
expr_stmt|;
name|s
operator|=
operator|(
name|char
argument_list|(
operator|*
argument_list|)
operator|)
block|{
name|s
block|}
expr_stmt|;
block|}
end_function

end_unit

