begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-apple-darwin -target-feature +popcnt -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Don't include mm_malloc.h, it's system specific.
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

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
comment|// CHECK: @llvm.ctpop.i32
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
comment|// CHECK: @llvm.ctpop.i64
return|return
name|_mm_popcnt_u64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

end_unit

