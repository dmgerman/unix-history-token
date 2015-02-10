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

begin_function
name|int
name|begin
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// CHECK: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD1:[0-9]+]]
if|if
condition|(
name|i
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|end
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// CHECK: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD2:[0-9]+]]
if|if
condition|(
name|i
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|begin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|end
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD2:[0-9]+]]
if|if
condition|(
name|argc
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK: ![[PD1]] = !{!"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// CHECK: ![[PD2]] = !{!"branch_weights", i32 2, i32 1}
end_comment

end_unit

