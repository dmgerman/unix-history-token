begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -o %t -O3 %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.profraw %run %t
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.profdata -o - -S -emit-llvm %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|__llvm_profile_reset_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|foo
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|__llvm_profile_reset_counters
argument_list|()
expr_stmt|;
name|foo
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|foo
parameter_list|(
name|int
name|N
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @foo(
comment|// CHECK: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[FOO:[0-9]+]]
if|if
condition|(
name|N
condition|)
block|{}
block|}
end_function

begin_comment
comment|// CHECK: ![[FOO]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

end_unit

