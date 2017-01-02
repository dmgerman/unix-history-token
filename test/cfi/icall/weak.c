begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that weak symbols stay weak.
end_comment

begin_comment
comment|// RUN: %clang_cfi -lm -o %t1 %s&& %t1
end_comment

begin_comment
comment|// XFAIL: darwin
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

begin_function_decl
name|void
name|does_not_exist
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|(
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|p
argument_list|()
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
if|if
condition|(
name|does_not_exist
condition|)
name|foo
argument_list|(
name|does_not_exist
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

