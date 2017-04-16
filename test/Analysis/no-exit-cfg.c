begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,alpha.core -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// This is a test case for the issue reported in PR 2819:
end_comment

begin_comment
comment|//  http://llvm.org/bugs/show_bug.cgi?id=2819
end_comment

begin_comment
comment|// The flow-sensitive dataflow solver should work even when no block in
end_comment

begin_comment
comment|// the CFG reaches the exit block.
end_comment

begin_function_decl
name|int
name|g
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|h
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|out_err
label|:
if|if
condition|(
name|g
argument_list|(
name|x
argument_list|)
condition|)
block|{
name|h
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
goto|goto
name|out_err
goto|;
block|}
end_function

end_unit

