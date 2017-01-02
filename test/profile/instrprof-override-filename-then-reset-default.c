begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t.d
end_comment

begin_comment
comment|// RUN: mkdir -p %t.d
end_comment

begin_comment
comment|// RUN: cd %t.d
end_comment

begin_comment
comment|// RUN: %clang_profgen -O3 %s -o %t.out
end_comment

begin_comment
comment|// RUN: %run %t.out %t.d/bad.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.d/default.profdata %t.d/default.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.d/default.profdata -o - -S -emit-llvm %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|__llvm_profile_set_filename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|__llvm_profile_set_filename
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|__llvm_profile_set_filename
argument_list|(
literal|0
argument_list|)
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

