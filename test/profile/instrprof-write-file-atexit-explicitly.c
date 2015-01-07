begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -o %t -O3 %s
end_comment

begin_comment
comment|// RUN: %run %t %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.profdata -o - -S -emit-llvm %s | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|__llvm_profile_runtime
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|__llvm_profile_register_write_file_atexit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|__llvm_profile_register_write_file_atexit
argument_list|()
expr_stmt|;
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
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: ![[PD1]] = metadata !{metadata !"branch_weights", i32 1, i32 2}
end_comment

end_unit

