begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple x86_64-unknown-unknown -target-feature +prfchw -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_function
name|void
name|test_m_prefetch
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
name|_m_prefetch
argument_list|(
name|p
argument_list|)
return|;
comment|// CHECK-LABEL: define void @test_m_prefetch
comment|// CHECK: call void @llvm.prefetch({{.*}}, i32 0, i32 3, i32 1)
block|}
end_function

begin_function
name|void
name|test_m_prefetch_w
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
name|_m_prefetchw
argument_list|(
name|p
argument_list|)
return|;
comment|// CHECK-LABEL: define void @test_m_prefetch_w
comment|// CHECK: call void @llvm.prefetch({{.*}}, i32 1, i32 3, i32 1)
block|}
end_function

end_unit

