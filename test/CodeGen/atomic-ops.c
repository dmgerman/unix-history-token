begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9 | FileCheck %s
end_comment

begin_comment
comment|// Basic IRGen tests for __atomic_*
end_comment

begin_comment
comment|// FIXME: Need to implement __atomic_is_lock_free
end_comment

begin_typedef
typedef|typedef
enum|enum
name|memory_order
block|{
name|memory_order_relaxed
block|,
name|memory_order_consume
block|,
name|memory_order_acquire
block|,
name|memory_order_release
block|,
name|memory_order_acq_rel
block|,
name|memory_order_seq_cst
block|}
name|memory_order
typedef|;
end_typedef

begin_function
name|int
name|fi1
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi1
comment|// CHECK: load atomic i32* {{.*}} seq_cst
return|return
name|__atomic_load
argument_list|(
name|i
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|fi2
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi2
comment|// CHECK: store atomic i32 {{.*}} seq_cst
name|__atomic_store
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fi3
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi3
comment|// CHECK: atomicrmw and
name|__atomic_fetch_and
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fi4
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|i
parameter_list|)
block|{
comment|// CHECK: @fi4
comment|// CHECK: cmpxchg i32*
name|int
name|cmp
init|=
literal|0
decl_stmt|;
name|__atomic_compare_exchange_strong
argument_list|(
name|i
argument_list|,
operator|&
name|cmp
argument_list|,
literal|1
argument_list|,
name|memory_order_acquire
argument_list|,
name|memory_order_acquire
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|float
name|ff1
parameter_list|(
atomic|_Atomic
argument_list|(
name|float
argument_list|)
modifier|*
name|d
parameter_list|)
block|{
comment|// CHECK: @ff1
comment|// CHECK: load atomic i32* {{.*}} monotonic
return|return
name|__atomic_load
argument_list|(
name|d
argument_list|,
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|ff2
parameter_list|(
atomic|_Atomic
argument_list|(
name|float
argument_list|)
modifier|*
name|d
parameter_list|)
block|{
comment|// CHECK: @ff2
comment|// CHECK: store atomic i32 {{.*}} release
name|__atomic_store
argument_list|(
name|d
argument_list|,
literal|1
argument_list|,
name|memory_order_release
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|float
name|ff3
parameter_list|(
atomic|_Atomic
argument_list|(
name|float
argument_list|)
modifier|*
name|d
parameter_list|)
block|{
return|return
name|__atomic_exchange
argument_list|(
name|d
argument_list|,
literal|2
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|fp1
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
operator|*
argument_list|)
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: @fp1
comment|// CHECK: load atomic i32* {{.*}} seq_cst
return|return
name|__atomic_load
argument_list|(
name|p
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|fp2
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
operator|*
argument_list|)
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: @fp2
comment|// CHECK: store i32 4
comment|// CHECK: atomicrmw add {{.*}} monotonic
return|return
name|__atomic_fetch_add
argument_list|(
name|p
argument_list|,
literal|1
argument_list|,
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_function

begin_function
specifier|_Complex
name|float
name|fc
parameter_list|(
atomic|_Atomic
argument_list|(
specifier|_Complex
name|float
argument_list|)
modifier|*
name|c
parameter_list|)
block|{
comment|// CHECK: @fc
comment|// CHECK: atomicrmw xchg i64*
return|return
name|__atomic_exchange
argument_list|(
name|c
argument_list|,
literal|2
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
name|X
block|{
name|int
name|x
decl_stmt|;
block|}
name|X
typedef|;
end_typedef

begin_function
name|X
name|fs
parameter_list|(
atomic|_Atomic
argument_list|(
name|X
argument_list|)
modifier|*
name|c
parameter_list|)
block|{
comment|// CHECK: @fs
comment|// CHECK: atomicrmw xchg i32*
return|return
name|__atomic_exchange
argument_list|(
name|c
argument_list|,
operator|(
name|X
operator|)
block|{
literal|2
block|}
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

end_unit

