begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|int
modifier|*
name|foo
parameter_list|(
name|int
modifier|*
modifier|*
name|a
parameter_list|,
name|int
modifier|*
name|b
parameter_list|,
name|int
modifier|*
name|c
parameter_list|)
block|{
return|return
name|__sync_val_compare_and_swap
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32* @foo
end_comment

begin_comment
comment|// CHECK: cmpxchg
end_comment

begin_function
name|int
name|foo2
parameter_list|(
name|int
modifier|*
modifier|*
name|a
parameter_list|,
name|int
modifier|*
name|b
parameter_list|,
name|int
modifier|*
name|c
parameter_list|)
block|{
return|return
name|__sync_bool_compare_and_swap
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @foo2
end_comment

begin_comment
comment|// CHECK: cmpxchg
end_comment

begin_function
name|int
modifier|*
name|foo3
parameter_list|(
name|int
modifier|*
modifier|*
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|__sync_fetch_and_add
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32* @foo3
end_comment

begin_comment
comment|// CHECK: atomicrmw add
end_comment

begin_function
name|int
modifier|*
name|foo4
parameter_list|(
name|int
modifier|*
modifier|*
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|__sync_fetch_and_sub
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32* @foo4
end_comment

begin_comment
comment|// CHECK: atomicrmw sub
end_comment

begin_function
name|int
modifier|*
name|foo5
parameter_list|(
name|int
modifier|*
modifier|*
name|a
parameter_list|,
name|int
modifier|*
name|b
parameter_list|)
block|{
return|return
name|__sync_lock_test_and_set
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32* @foo5
end_comment

begin_comment
comment|// CHECK: atomicrmw xchg
end_comment

begin_function
name|int
modifier|*
name|foo6
parameter_list|(
name|int
modifier|*
modifier|*
name|a
parameter_list|,
name|int
modifier|*
modifier|*
modifier|*
name|b
parameter_list|)
block|{
return|return
name|__sync_lock_test_and_set
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32* @foo6
end_comment

begin_comment
comment|// CHECK: atomicrmw xchg
end_comment

end_unit

