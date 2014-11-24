begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// rdar://7536390
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|__INT32_TYPE__
name|uint32_t
typedef|;
end_typedef

begin_function
name|unsigned
name|t
parameter_list|(
name|uint32_t
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
comment|// CHECK:      @t
comment|// CHECK: atomicrmw xchg i32* {{.*}} seq_cst
return|return
name|__sync_lock_test_and_set
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

end_unit

