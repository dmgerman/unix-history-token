begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -triple x86_64-unknown-linux-gnu -target-cpu x86-64 %s -o %t -dwarf-column-info -opt-record-file %t.yaml -emit-obj
end_comment

begin_comment
comment|// RUN: cat %t.yaml | FileCheck %s
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/opt-record.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O3 -triple x86_64-unknown-linux-gnu -target-cpu x86-64 -fprofile-instrument-use-path=%t.profdata %s -o %t -dwarf-column-info -opt-record-file %t.yaml -emit-obj
end_comment

begin_comment
comment|// RUN: cat %t.yaml | FileCheck -check-prefix=CHECK -check-prefix=CHECK-PGO %s
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|bar
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|Test
parameter_list|(
name|int
modifier|*
name|res
parameter_list|,
name|int
modifier|*
name|c
parameter_list|,
name|int
modifier|*
name|d
parameter_list|,
name|int
modifier|*
name|p
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|loop
name|vectorize
name|(
name|assume_safety
name|)
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|1600
condition|;
name|i
operator|++
control|)
block|{
name|res
index|[
name|i
index|]
operator|=
operator|(
name|p
index|[
name|i
index|]
operator|==
literal|0
operator|)
condition|?
name|res
index|[
name|i
index|]
else|:
name|res
index|[
name|i
index|]
operator|+
name|d
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// CHECK: --- !Missed
end_comment

begin_comment
comment|// CHECK: Pass:            inline
end_comment

begin_comment
comment|// CHECK: Name:            NoDefinition
end_comment

begin_comment
comment|// CHECK: DebugLoc:
end_comment

begin_comment
comment|// CHECK: Function:        foo
end_comment

begin_comment
comment|// CHECK-PGO: Hotness:
end_comment

begin_comment
comment|// CHECK: --- !Passed
end_comment

begin_comment
comment|// CHECK: Pass:            loop-vectorize
end_comment

begin_comment
comment|// CHECK: Name:            Vectorized
end_comment

begin_comment
comment|// CHECK: DebugLoc:
end_comment

begin_comment
comment|// CHECK: Function:        Test
end_comment

begin_comment
comment|// CHECK-PGO: Hotness:
end_comment

end_unit

