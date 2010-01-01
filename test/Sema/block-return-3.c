begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify -fblocks
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
lambda|^
name|int
parameter_list|(
name|void
parameter_list|)
block|{ }
argument_list|()
expr_stmt|;
comment|// expected-error {{control reaches end of non-void block}}
block|}
end_function

end_unit

