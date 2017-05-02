begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1< %s -triple armv5e-none-linux-gnueabi -emit-llvm -O1 | FileCheck %s
end_comment

begin_comment
comment|// FIXME: This file should not be checking -O1 output.
end_comment

begin_comment
comment|// Ie, it is testing many IR optimizer passes as part of front-end verification.
end_comment

begin_enum
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
enum|;
end_enum

begin_function
name|int
modifier|*
name|test_c11_atomic_fetch_add_int_ptr
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
comment|// CHECK: test_c11_atomic_fetch_add_int_ptr
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_add_4(i8* {{%[0-9]+}}, i32 12, i32 5)
return|return
name|__c11_atomic_fetch_add
argument_list|(
name|p
argument_list|,
literal|3
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|test_c11_atomic_fetch_sub_int_ptr
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
comment|// CHECK: test_c11_atomic_fetch_sub_int_ptr
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_sub_4(i8* {{%[0-9]+}}, i32 20, i32 5)
return|return
name|__c11_atomic_fetch_sub
argument_list|(
name|p
argument_list|,
literal|5
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_c11_atomic_fetch_add_int
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_c11_atomic_fetch_add_int
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_add_4(i8* {{%[0-9]+}}, i32 3, i32 5)
return|return
name|__c11_atomic_fetch_add
argument_list|(
name|p
argument_list|,
literal|3
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_c11_atomic_fetch_sub_int
parameter_list|(
atomic|_Atomic
argument_list|(
name|int
argument_list|)
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_c11_atomic_fetch_sub_int
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_sub_4(i8* {{%[0-9]+}}, i32 5, i32 5)
return|return
name|__c11_atomic_fetch_sub
argument_list|(
name|p
argument_list|,
literal|5
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|fp2a
parameter_list|(
name|int
modifier|*
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: @fp2a
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_sub_4(i8* {{%[0-9]+}}, i32 4, i32 0)
comment|// Note, the GNU builtins do not multiply by sizeof(T)!
return|return
name|__atomic_fetch_sub
argument_list|(
name|p
argument_list|,
literal|4
argument_list|,
name|memory_order_relaxed
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_fetch_add
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_fetch_add
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_add_4(i8* {{%[0-9]+}}, i32 55, i32 5)
return|return
name|__atomic_fetch_add
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_fetch_sub
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_fetch_sub
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_sub_4(i8* {{%[0-9]+}}, i32 55, i32 5)
return|return
name|__atomic_fetch_sub
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_fetch_and
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_fetch_and
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_and_4(i8* {{%[0-9]+}}, i32 55, i32 5)
return|return
name|__atomic_fetch_and
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_fetch_or
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_fetch_or
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_or_4(i8* {{%[0-9]+}}, i32 55, i32 5)
return|return
name|__atomic_fetch_or
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_fetch_xor
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_fetch_xor
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_xor_4(i8* {{%[0-9]+}}, i32 55, i32 5)
return|return
name|__atomic_fetch_xor
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_fetch_nand
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_fetch_nand
comment|// CHECK: {{%[^ ]*}} = tail call i32 @__atomic_fetch_nand_4(i8* {{%[0-9]+}}, i32 55, i32 5)
return|return
name|__atomic_fetch_nand
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_add_fetch
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_add_fetch
comment|// CHECK: [[CALL:%[^ ]*]] = tail call i32 @__atomic_fetch_add_4(i8* {{%[0-9]+}}, i32 55, i32 5)
comment|// CHECK: {{%[^ ]*}} = add i32 [[CALL]], 55
return|return
name|__atomic_add_fetch
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_sub_fetch
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_sub_fetch
comment|// CHECK: [[CALL:%[^ ]*]] = tail call i32 @__atomic_fetch_sub_4(i8* {{%[0-9]+}}, i32 55, i32 5)
comment|// CHECK: {{%[^ ]*}} = add i32 [[CALL]], -55
return|return
name|__atomic_sub_fetch
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_and_fetch
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_and_fetch
comment|// CHECK: [[CALL:%[^ ]*]] = tail call i32 @__atomic_fetch_and_4(i8* {{%[0-9]+}}, i32 55, i32 5)
comment|// CHECK: {{%[^ ]*}} = and i32 [[CALL]], 55
return|return
name|__atomic_and_fetch
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_or_fetch
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_or_fetch
comment|// CHECK: [[CALL:%[^ ]*]] = tail call i32 @__atomic_fetch_or_4(i8* {{%[0-9]+}}, i32 55, i32 5)
comment|// CHECK: {{%[^ ]*}} = or i32 [[CALL]], 55
return|return
name|__atomic_or_fetch
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_xor_fetch
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_xor_fetch
comment|// CHECK: [[CALL:%[^ ]*]] = tail call i32 @__atomic_fetch_xor_4(i8* {{%[0-9]+}}, i32 55, i32 5)
comment|// CHECK: {{%[^ ]*}} = xor i32 [[CALL]], 55
return|return
name|__atomic_xor_fetch
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_atomic_nand_fetch
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: test_atomic_nand_fetch
comment|// CHECK: [[CALL:%[^ ]*]] = tail call i32 @__atomic_fetch_nand_4(i8* {{%[0-9]+}}, i32 55, i32 5)
comment|// FIXME: We should not be checking optimized IR. It changes independently of clang.
comment|// FIXME-CHECK: [[AND:%[^ ]*]] = and i32 [[CALL]], 55
comment|// FIXME-CHECK: {{%[^ ]*}} = xor i32 [[AND]], -1
return|return
name|__atomic_nand_fetch
argument_list|(
name|p
argument_list|,
literal|55
argument_list|,
name|memory_order_seq_cst
argument_list|)
return|;
block|}
end_function

end_unit

