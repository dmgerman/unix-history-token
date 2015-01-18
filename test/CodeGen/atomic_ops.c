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
comment|// CHECK: {{(cmpxchg i32*|i1 @__atomic_compare_exchange\(i32 4,)}}
name|i
operator|/=
literal|2
expr_stmt|;
comment|// CHECK: sdiv i32
comment|// CHECK: {{(cmpxchg i32*|i1 @__atomic_compare_exchange\(i32 4, )}}
name|j
operator|/=
name|x
expr_stmt|;
comment|// CHECK: sdiv i32
comment|// CHECK: {{(cmpxchg i16*|i1 @__atomic_compare_exchange\(i32 2, )}}
block|}
end_function

end_unit

