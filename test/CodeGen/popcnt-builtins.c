begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +popcnt -emit-llvm -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_function
name|unsigned
name|int
name|test_mm_popcnt_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|)
block|{
comment|//CHECK: call i32 @llvm.ctpop.i32
return|return
name|_mm_popcnt_u32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_popcnt_32
parameter_list|(
name|int
name|__X
parameter_list|)
block|{
comment|//CHECK: call i32 @llvm.ctpop.i32
return|return
name|_popcnt32
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_mm_popcnt_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|)
block|{
comment|//CHECK: call i64 @llvm.ctpop.i64
return|return
name|_mm_popcnt_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_popcnt_64
parameter_list|(
name|long
name|long
name|__X
parameter_list|)
block|{
comment|//CHECK: call i64 @llvm.ctpop.i64
return|return
name|_popcnt64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

end_unit

