begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -load %llvmshlibdir/SampleAnalyzerPlugin%pluginext -analyzer-checker='example.MainCallChecker' -verify %s
end_comment

begin_comment
comment|// REQUIRES: plugins, examples
end_comment

begin_comment
comment|// Test that the MainCallChecker example analyzer plugin loads and runs.
end_comment

begin_function_decl
name|int
name|main
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|caller
parameter_list|()
block|{
name|main
parameter_list|()
function_decl|;
comment|// expected-warning {{call to main}}
block|}
end_function

end_unit

