begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify -fblocks -Wmissing-noreturn
end_comment

begin_decl_stmt
name|int
name|j
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// expected-warning {{function could be attribute 'noreturn'}}
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
argument_list|()
expr_stmt|;
comment|// expected-warning {{block could be attribute 'noreturn'}}
lambda|^
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|j
condition|)
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
argument_list|()
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
if|if
condition|(
name|j
condition|)
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(__noreturn__)
argument_list|)
end_macro

begin_function
name|void
name|test2_positive
parameter_list|()
block|{
if|if
condition|(
name|j
condition|)
while|while
condition|(
literal|1
condition|)
block|{ }
block|}
end_function

begin_comment
comment|// expected-warning{{function declared 'noreturn' should not return}}
end_comment

begin_comment
comment|// This test case illustrates that we don't warn about the missing return
end_comment

begin_comment
comment|// because the function is marked noreturn and there is an infinite loop.
end_comment

begin_function_decl
specifier|extern
name|int
name|foo_test_3
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(__noreturn__)
argument_list|)
end_macro

begin_function
name|void
modifier|*
name|test3
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
name|foo_test_3
argument_list|()
expr_stmt|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(__noreturn__)
argument_list|)
end_macro

begin_function
name|void
modifier|*
name|test3_positive
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
while|while
condition|(
literal|0
condition|)
name|foo_test_3
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning{{function declared 'noreturn' should not return}}
end_comment

begin_comment
comment|// PR5298 - -Wmissing-noreturn shouldn't warn if the function is already
end_comment

begin_comment
comment|// declared noreturn.
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
name|test4
argument_list|()
block|{
name|test2_positive
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

end_unit

