begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: shell
end_comment

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
comment|// RUN: %clang_profuse=%t.profdata -o - -S -emit-llvm %s | FileCheck %s --check-prefix=COMMON --check-prefix=ORIG
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -f %t.profraw_e_*
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.profraw_e_%1m %run %t
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.profraw_e_%1m %run %t
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.em.profdata %t.profraw_e_*
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.em.profdata -o - -S -emit-llvm %s | FileCheck %s --check-prefix=COMMON --check-prefix=MERGE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_profgen=%t.%m.profraw -o %t.merge -O3 %s
end_comment

begin_comment
comment|// RUN: rm -f %t.*.profraw*
end_comment

begin_comment
comment|// RUN: %run %t.merge
end_comment

begin_comment
comment|// RUN: %run %t.merge
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.m.profdata %t.*.profraw
end_comment

begin_comment
comment|// RUN: %clang_profuse=%t.m.profdata -o - -S -emit-llvm %s | FileCheck %s --check-prefix=COMMON --check-prefix=MERGE
end_comment

begin_function
name|int
name|begin
parameter_list|(
name|int
name|i
parameter_list|)
block|{
comment|// COMMON: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD1:[0-9]+]]
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
comment|// COMMON: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD2:[0-9]+]]
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
comment|// COMMON: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD2:[0-9]+]]
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
comment|// ORIG: ![[PD1]] = !{!"branch_weights", i32 1, i32 2}
end_comment

begin_comment
comment|// ORIG: ![[PD2]] = !{!"branch_weights", i32 2, i32 1}
end_comment

begin_comment
comment|// MERGE: ![[PD1]] = !{!"branch_weights", i32 1, i32 3}
end_comment

begin_comment
comment|// MERGE: ![[PD2]] = !{!"branch_weights", i32 3, i32 1}
end_comment

end_unit

