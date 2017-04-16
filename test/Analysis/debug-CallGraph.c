begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=debug.DumpCallGraph %s -fblocks 2>&1 | FileCheck %s
end_comment

begin_function
name|int
name|get5
parameter_list|()
block|{
return|return
literal|5
return|;
block|}
end_function

begin_function
name|int
name|add
parameter_list|(
name|int
name|val1
parameter_list|,
name|int
name|val2
parameter_list|)
block|{
return|return
name|val1
operator|+
name|val2
return|;
block|}
end_function

begin_function
name|int
name|test_add
parameter_list|()
block|{
return|return
name|add
argument_list|(
literal|10
argument_list|,
name|get5
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|mmm
parameter_list|(
name|int
name|y
parameter_list|)
block|{
if|if
condition|(
name|y
operator|!=
literal|0
condition|)
name|y
operator|++
expr_stmt|;
name|y
operator|=
name|y
operator|/
name|y
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|mmm
argument_list|(
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|!=
literal|0
condition|)
name|x
operator|++
expr_stmt|;
return|return
literal|5
operator|/
name|x
return|;
block|}
end_function

begin_function
name|void
name|aaa
parameter_list|()
block|{
name|foo
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|bbb
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|int
name|x
init|=
operator|(
name|y
operator|>
literal|2
operator|)
decl_stmt|;
lambda|^
block|{
name|foo
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|ccc
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|ddd
parameter_list|()
block|{
name|ccc
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ccc
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|eee
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|eee
parameter_list|()
block|{}
end_function

begin_function
name|void
name|fff
parameter_list|()
block|{
name|eee
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// This test case tests that forward declaration for the top-level function
end_comment

begin_comment
comment|// does not affect call graph construction.
end_comment

begin_function
name|void
name|do_nothing
parameter_list|()
block|{}
end_function

begin_function_decl
name|void
name|test_single_call
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test_single_call
parameter_list|()
block|{
name|do_nothing
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:--- Call graph Dump ---
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function:< root> calls: get5 add test_add mmm foo aaa<> bbb ddd ccc eee fff do_nothing test_single_call $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: test_single_call calls: do_nothing $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: do_nothing calls: $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: fff calls: eee $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: eee calls: $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: ddd calls: ccc $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: ccc calls: $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: bbb calls:<> $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function:<> calls: foo $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: aaa calls: foo $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: foo calls: mmm $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: mmm calls: $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: test_add calls: add get5 $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: add calls: $}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{Function: get5 calls: $}}
end_comment

end_unit

