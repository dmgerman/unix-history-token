begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// 1. Test that __llvm_profile_set_filename has higher precedence than
end_comment

begin_comment
comment|//    the default path.
end_comment

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

begin_comment
comment|// RUN: rm %t.profraw
end_comment

begin_comment
comment|// RUN: rm %t.profdata
end_comment

begin_comment
comment|// 2. Test that __llvm_profile_set_filename has higher precedence than
end_comment

begin_comment
comment|//    environment variable
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.env.profraw %run %t %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.profdata -o - -S -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: rm %t.profraw
end_comment

begin_comment
comment|// RUN: rm %t.profdata
end_comment

begin_comment
comment|// 3. Test that __llvm_profile_set_filename has higher precedence than
end_comment

begin_comment
comment|//    the command line.
end_comment

begin_comment
comment|// RUN: %clang_profgen=%t.cmd.profraw -o %t.cmd -O3 %s
end_comment

begin_comment
comment|// RUN: %run %t.cmd %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.profdata -o - -S -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: rm %t.profraw
end_comment

begin_comment
comment|// RUN: rm %t.profdata
end_comment

begin_comment
comment|// 4. Test that command line has high precedence than the default path
end_comment

begin_comment
comment|// RUN: %clang_profgen=%t.cmd.profraw -DNO_API -o %t.cmd -O3 %s
end_comment

begin_comment
comment|// RUN: %run %t.cmd %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.cmd.profdata %t.cmd.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.cmd.profdata -o - -S -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: rm %t.cmd.profraw
end_comment

begin_comment
comment|// RUN: rm %t.cmd.profdata
end_comment

begin_comment
comment|// 5. Test that the environment variable has higher precedence than
end_comment

begin_comment
comment|//    the command line.
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.env.profraw %run %t.cmd %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.env.profdata %t.env.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.env.profdata -o - -S -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: rm %t.env.profraw
end_comment

begin_comment
comment|// RUN: rm %t.env.profdata
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CALL_SHARED
end_ifdef

begin_function_decl
specifier|extern
name|void
name|func
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
ifndef|#
directive|ifndef
name|NO_API
name|__llvm_profile_set_filename
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CALL_SHARED
name|func
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: ![[PD1]] = !{!"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// SHARED: Total functions: 2
end_comment

end_unit

