begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,deadcode.DeadStores,debug.Stats -verify -Wno-unreachable-code -analyzer-opt-analyze-nested-blocks %s
end_comment

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|test
parameter_list|()
block|{
comment|// expected-warning-re{{test -> Total CFGBlocks: {{[0-9]+}} | Unreachable CFGBlocks: 0 | Exhausted Block: no | Empty WorkList: yes}}
name|int
name|a
init|=
literal|1
decl_stmt|;
name|a
operator|=
literal|34
operator|/
literal|12
expr_stmt|;
if|if
condition|(
name|foo
argument_list|()
condition|)
return|return
name|a
return|;
name|a
operator|/=
literal|4
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

end_unit

