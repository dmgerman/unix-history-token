begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that function entry counts are set correctly.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/func-entry.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -o - -disable-llvm-passes -emit-llvm -fprofile-instrument-use-path=%t.profdata | FileCheck %s
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: @foo() #{{[0-9]}} !prof [[FOO:![0-9]+]]
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
return|return;
block|}
end_function

begin_comment
comment|// CHECK: @main() #{{[0-9]}} !prof [[MAIN:![0-9]+]]
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10000
condition|;
name|i
operator|++
control|)
name|foo
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: [[FOO]] = !{!"function_entry_count", i64 1000}
end_comment

begin_comment
comment|// CHECK: [[MAIN]] = !{!"function_entry_count", i64 1}
end_comment

end_unit

