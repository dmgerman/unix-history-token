begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -Wmicrosoft -verify -fms-extensions
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|a
decl_stmt|;
name|__try
name|a
decl_stmt|;
comment|// expected-error {{expected '{'}} expected-warning {{expression result unused}}
name|__try
block|{   }
block|}
end_function

begin_comment
comment|// expected-error {{expected '__except' or '__finally' block}}
end_comment

begin_function
name|void
name|g
parameter_list|()
block|{
name|int
name|a
decl_stmt|;
name|__try
block|{   }
name|__except
argument_list|(
literal|1
argument_list|)
name|a
expr_stmt|;
comment|// expected-error {{expected '{'}} expected-warning {{expression result unused}}
block|}
end_function

begin_function
name|void
name|h
parameter_list|()
block|{
name|int
name|a
decl_stmt|;
name|__try
block|{   }
name|__finally
name|a
decl_stmt|;
comment|// expected-error {{expected '{'}} expected-warning {{expression result unused}}
block|}
end_function

end_unit

