begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen=%t.bad.profraw -o %t -O3 %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.good.profraw %run %t %t.bad.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.good.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.profdata -o - -S -emit-llvm %s | FileCheck %s
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{}
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
comment|// CHECK: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD1:[0-9]+]]
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
return|return
literal|1
return|;
name|bar
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: ![[PD1]] = !{!"branch_weights", i32 1, i32 2}
end_comment

end_unit

