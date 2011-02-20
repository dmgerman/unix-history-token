begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-experimental-internal-checks -analyzer-check-objc-mem -analyzer-checker=core.DeadStores -verify -Wno-unreachable-code -analyzer-opt-analyze-nested-blocks -analyzer-stats %s
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
comment|// expected-warning{{Total CFGBlocks}}
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

