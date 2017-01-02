begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_function
name|unsigned
name|long
name|long
name|test_rdpmc
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|_rdpmc
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: @test_rdpmc
comment|// CHECK: call i64 @llvm.x86.rdpmc
block|}
end_function

begin_function
name|int
name|test_rdtsc
parameter_list|()
block|{
return|return
name|_rdtsc
argument_list|()
return|;
comment|// CHECK: @test_rdtsc
comment|// CHECK: call i64 @llvm.x86.rdtsc
block|}
end_function

end_unit

