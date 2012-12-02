begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -fblocks
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_Block_byref_release
parameter_list|(
name|void
modifier|*
name|src
parameter_list|)
block|{}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|__block
name|int
name|X
init|=
literal|1234
decl_stmt|;
specifier|__block
specifier|const
name|char
modifier|*
name|message
init|=
literal|"HELLO"
decl_stmt|;
name|X
operator|=
name|X
operator|-
literal|1234
expr_stmt|;
name|X
operator|+=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|"%s(%d)\n"
argument_list|,
name|message
argument_list|,
name|X
argument_list|)
expr_stmt|;
name|X
operator|-=
literal|1
expr_stmt|;
return|return
name|X
return|;
block|}
end_function

end_unit

