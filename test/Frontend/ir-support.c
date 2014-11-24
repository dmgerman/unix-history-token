begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that we can consume LLVM IR/bitcode in the frontend and produce
end_comment

begin_comment
comment|// equivalent output to a standard compilation.
end_comment

begin_comment
comment|// We strip differing '.file' directives before comparing.
end_comment

begin_comment
comment|// Reference output:
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -o - %s | grep -v '\.file'> %t.s
end_comment

begin_comment
comment|// LLVM bitcode:
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm-bc -o %t.bc %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -o - %t.bc | grep -v '\.file'> %t.bc.s
end_comment

begin_comment
comment|// RUN: diff %t.s %t.bc.s
end_comment

begin_comment
comment|// LLVM IR source code:
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o %t.ll %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -o - %t.ll | grep -v '\.file'> %t.ll.s
end_comment

begin_comment
comment|// RUN: diff %t.s %t.ll.s
end_comment

begin_function
name|int
name|f
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

