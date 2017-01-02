begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_profgen -O2 -mllvm -enable-value-profiling=true -mllvm -vp-static-alloc=true -mllvm -vp-counters-per-site=3 -o %t %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.profraw %run %t
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t.profdata | FileCheck %s
end_comment

begin_comment
comment|// IR level instrumentation
end_comment

begin_comment
comment|// RUN: %clang_pgogen -O2 -mllvm -disable-vp=false -mllvm -vp-static-alloc=true  -mllvm -vp-counters-per-site=3 -o %t.ir  %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.ir.profraw %run %t.ir
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.ir.profdata %t.ir.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t.ir.profdata | FileCheck  %s
end_comment

begin_comment
comment|// IR level instrumentation, dynamic allocation
end_comment

begin_comment
comment|// RUN: %clang_pgogen -O2 -mllvm -disable-vp=false -mllvm -vp-static-alloc=false -o %t.ir.dyn  %s
end_comment

begin_comment
comment|// RUN: env LLVM_PROFILE_FILE=%t.ir.dyn.profraw %run %t.ir.dyn
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.ir.dyn.profdata %t.ir.dyn.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions -ic-targets  %t.ir.dyn.profdata | FileCheck  %s
end_comment

begin_function
name|void
name|callee_0
parameter_list|()
block|{}
end_function

begin_function
name|void
name|callee_1
parameter_list|()
block|{}
end_function

begin_function
name|void
name|callee_2
parameter_list|()
block|{}
end_function

begin_decl_stmt
name|void
modifier|*
name|CalleeAddrs
index|[]
init|=
block|{
name|callee_0
block|,
name|callee_1
block|,
name|callee_2
block|,
name|callee_2
block|,
name|callee_2
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|lprofSetMaxValsPerSite
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__llvm_profile_reset_counters
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|FPT
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Testing value profiling eviction algorithm.
end_comment

begin_function
name|FPT
name|getCalleeFunc
parameter_list|(
name|int
name|I
parameter_list|)
block|{
return|return
name|CalleeAddrs
index|[
name|I
index|]
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|I
decl_stmt|;
comment|// First fill up two value profile entries with two targets
name|lprofSetMaxValsPerSite
argument_list|(
literal|2
argument_list|)
expr_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<
literal|5
condition|;
name|I
operator|++
control|)
block|{
if|if
condition|(
name|I
operator|==
literal|2
condition|)
block|{
name|__llvm_profile_reset_counters
argument_list|()
expr_stmt|;
block|}
comment|// CHECK:  callee_2, 3
comment|// CHECK-NEXT: callee_1, 0
comment|// CHECK-NOT: callee_0,
name|FPT
name|FP
init|=
name|getCalleeFunc
argument_list|(
name|I
argument_list|)
decl_stmt|;
name|FP
argument_list|()
expr_stmt|;
block|}
block|}
end_function

end_unit

