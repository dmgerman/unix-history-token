begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -g< %s | grep  lexical | count 5
end_comment

begin_comment
comment|// Test to check number of lexical scope identified in debug info.
end_comment

begin_function_decl
specifier|extern
name|int
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|foobar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|int
name|s
parameter_list|)
block|{
name|unsigned
name|loc
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|s
condition|)
block|{
if|if
condition|(
name|bar
argument_list|()
condition|)
block|{
name|foobar
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|loc
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|bar
argument_list|()
condition|)
block|{
name|loc
operator|=
literal|2
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

