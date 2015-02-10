begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -o %t -O3 %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t1.profraw %run %t %t2.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t1.profdata %t1.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t1.profdata -o - -S -emit-llvm %s | FileCheck %s --check-prefix=CHECK1 --check-prefix=CHECK
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t2.profdata %t2.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t2.profdata -o - -S -emit-llvm %s | FileCheck %s --check-prefix=CHECK2 --check-prefix=CHECK
end_comment

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
operator|<
literal|2
condition|)
return|return
literal|1
return|;
comment|// Write out the profile.
name|__llvm_profile_write_file
argument_list|()
expr_stmt|;
comment|// Change the profile.
name|int
name|Ret
init|=
name|foo
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// It'll write out again at exit; change the filename so we get two files.
name|__llvm_profile_set_filename
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
return|return
name|Ret
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
comment|// CHECK-LABEL: define {{.*}} @foo(
comment|// CHECK1: br i1 %{{.*}}, label %{{.*}}, label %{{[^,]+$}}
comment|// CHECK2: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD2:[0-9]+]]
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

begin_comment
comment|// CHECK2: ![[PD2]] = !{!"branch_weights", i32 2, i32 1}
end_comment

end_unit

