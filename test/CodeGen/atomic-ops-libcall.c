begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1< %s -triple armv5e-none-linux-gnueabi -emit-llvm -O1 | FileCheck %s
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

end_unit

