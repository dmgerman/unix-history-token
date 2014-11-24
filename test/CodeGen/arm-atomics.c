begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=thumbv7-none--eabi | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=armv6-none--eabi | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=armv7-unknown-openbsd | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|long
name|l
decl_stmt|;
end_decl_stmt

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
name|void
name|test_presence
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_presence
comment|// CHECK: atomicrmw add i32* {{.*}} seq_cst
name|__atomic_fetch_add
argument_list|(
operator|&
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i32* {{.*}} seq_cst
name|__atomic_fetch_sub
argument_list|(
operator|&
name|i
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// CHECK: load atomic i32* {{.*}} seq_cst
name|int
name|r
decl_stmt|;
name|__atomic_load
argument_list|(
operator|&
name|i
argument_list|,
operator|&
name|r
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic i32 {{.*}} seq_cst
name|r
operator|=
literal|0
expr_stmt|;
name|__atomic_store
argument_list|(
operator|&
name|i
argument_list|,
operator|&
name|r
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw add i64* {{.*}} seq_cst
name|__atomic_fetch_add
argument_list|(
operator|&
name|l
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// CHECK: atomicrmw sub i64* {{.*}} seq_cst
name|__atomic_fetch_sub
argument_list|(
operator|&
name|l
argument_list|,
literal|1
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// CHECK: load atomic i64* {{.*}} seq_cst
name|long
name|long
name|rl
decl_stmt|;
name|__atomic_load
argument_list|(
operator|&
name|l
argument_list|,
operator|&
name|rl
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
comment|// CHECK: store atomic i64 {{.*}} seq_cst
name|rl
operator|=
literal|0
expr_stmt|;
name|__atomic_store
argument_list|(
operator|&
name|l
argument_list|,
operator|&
name|rl
argument_list|,
name|memory_order_seq_cst
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

