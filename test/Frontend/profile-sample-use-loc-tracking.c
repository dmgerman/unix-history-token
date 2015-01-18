begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This file tests that -fprofile-sample-use enables location tracking
end_comment

begin_comment
comment|// generation in the same way that -Rpass does. The sample profiler needs
end_comment

begin_comment
comment|// to associate line locations in the profile to the code, so it needs the
end_comment

begin_comment
comment|// frontend to emit source location annotations.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fprofile-sample-use=%S/Inputs/profile-sample-use-loc-tracking.prof -emit-llvm -o - 2>/dev/null | FileCheck %s
end_comment

begin_comment
comment|// -fprofile-sample-use should produce source location annotations, exclusively
end_comment

begin_comment
comment|// (just like -gmlt).
end_comment

begin_comment
comment|// CHECK: , !dbg !
end_comment

begin_comment
comment|// CHECK-NOT: DW_TAG_base_type
end_comment

begin_comment
comment|// But llvm.dbg.cu should be missing (to prevent writing debug info to
end_comment

begin_comment
comment|// the final output).
end_comment

begin_comment
comment|// CHECK-NOT: !llvm.dbg.cu = !{
end_comment

begin_function
name|int
name|bar
parameter_list|(
name|int
name|j
parameter_list|)
block|{
return|return
operator|(
name|j
operator|+
name|j
operator|-
literal|2
operator|)
operator|*
operator|(
name|j
operator|-
literal|2
operator|)
operator|*
name|j
return|;
block|}
end_function

end_unit

