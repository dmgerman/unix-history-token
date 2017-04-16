begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -w -analyzer-checker=core,unix.Malloc -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Test that strange prototypes doesn't crash the analyzer
end_comment

begin_function_decl
name|void
name|malloc
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|valloc
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test1
parameter_list|()
block|{
name|malloc
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
name|valloc
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

