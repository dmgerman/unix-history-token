begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only %s -verify -fblocks
end_comment

begin_decl_stmt
name|int
name|j
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|j
condition|)
return|return
literal|1
return|;
block|}
argument_list|()
expr_stmt|;
comment|// expected-error {{control may reach end of non-void block}}
block|}
end_function

end_unit

