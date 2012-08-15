begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
atomic|_Atomic
argument_list|(
name|int
argument_list|)
name|i
init|=
literal|0
decl_stmt|;
atomic|_Atomic
argument_list|(
name|short
argument_list|)
name|j
init|=
literal|0
decl_stmt|;
comment|// Check that multiply / divides on atomics produce a cmpxchg loop
name|i
operator|*=
literal|2
expr_stmt|;
comment|// CHECK: mul nsw i32
comment|// CHECK: cmpxchg i32*
name|i
operator|/=
literal|2
expr_stmt|;
comment|// CHECK: sdiv i32
comment|// CHECK: cmpxchg i32*
name|j
operator|/=
name|x
expr_stmt|;
comment|// CHECK: sdiv i32
comment|// CHECK: cmpxchg i16*
comment|// These should be emitting atomicrmw instructions, but they aren't yet
name|i
operator|+=
literal|2
expr_stmt|;
comment|// CHECK: cmpxchg
name|i
operator|-=
literal|2
expr_stmt|;
comment|// CHECK: cmpxchg
name|i
operator|++
expr_stmt|;
comment|// CHECK: cmpxchg
name|i
operator|--
expr_stmt|;
comment|// CHECK: cmpxchg
block|}
end_function

end_unit

