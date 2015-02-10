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

begin_decl_stmt
name|int
name|__llvm_profile_runtime
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|__llvm_profile_initialize_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__llvm_profile_write_file
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

begin_function_decl
name|int
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
comment|// CHECK-LABEL: define {{.*}} @main(
comment|// CHECK: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD1:[0-9]+]]
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
return|return
literal|1
return|;
comment|// Since the runtime has been suppressed, initialize the file name, as the
comment|// writing will fail below as the file name has not been specified.
name|__llvm_profile_initialize_file
argument_list|()
expr_stmt|;
comment|// Write out the profile.
name|__llvm_profile_write_file
argument_list|()
expr_stmt|;
comment|// Change the profile.
return|return
name|foo
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|foo
parameter_list|(
name|int
name|X
parameter_list|)
block|{
comment|// There should be no profiling information for @foo, since it was called
comment|// after the profile was written (and the atexit was suppressed by defining
comment|// profile_runtime).
comment|// CHECK-LABEL: define {{.*}} @foo(
comment|// CHECK: br i1 %{{.*}}, label %{{.*}}, label %{{[^,]+$}}
return|return
name|X
operator|<=
literal|0
condition|?
operator|-
name|X
else|:
name|X
return|;
block|}
end_function

begin_comment
comment|// CHECK: ![[PD1]] = !{!"branch_weights", i32 1, i32 2}
end_comment

end_unit

