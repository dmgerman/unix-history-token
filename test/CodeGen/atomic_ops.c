begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
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
comment|// Check that multiply / divides on atomics produce a cmpxchg loop
name|i
operator|*=
literal|2
expr_stmt|;
comment|// CHECK: cmpxchg
name|i
operator|/=
literal|2
expr_stmt|;
comment|// CHECK: cmpxchg
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

