begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -target-cpu core2 %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// All atomics up to 16 bytes should be emitted inline on x86_64. The
end_comment

begin_comment
comment|// backend can reform __sync_whatever calls if necessary (e.g. the CPU
end_comment

begin_comment
comment|// doesn't have cmpxchg16b).
end_comment

begin_function
name|__int128
name|test_sync_call
parameter_list|(
name|__int128
modifier|*
name|addr
parameter_list|,
name|__int128
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_sync_call
comment|// CHECK: atomicrmw add i128
return|return
name|__sync_fetch_and_add
argument_list|(
name|addr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_function
name|__int128
name|test_c11_call
parameter_list|(
specifier|_Atomic
name|__int128
modifier|*
name|addr
parameter_list|,
name|__int128
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_c11_call
comment|// CHECK: atomicrmw sub
return|return
name|__c11_atomic_fetch_sub
argument_list|(
name|addr
argument_list|,
name|val
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__int128
name|test_atomic_call
parameter_list|(
name|__int128
modifier|*
name|addr
parameter_list|,
name|__int128
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_atomic_call
comment|// CHECK: atomicrmw or
return|return
name|__atomic_fetch_or
argument_list|(
name|addr
argument_list|,
name|val
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__int128
name|test_expression
parameter_list|(
specifier|_Atomic
name|__int128
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_expression
comment|// CHECK: atomicrmw and
operator|*
name|addr
operator|&=
literal|1
expr_stmt|;
block|}
end_function

end_unit

