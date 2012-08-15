begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -target-feature +rdrnd -emit-llvm -S -emit-llvm -o - %s | FileCheck %s
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
file|<immintrin.h>
end_include

begin_function
name|int
name|rdrand16
parameter_list|(
name|unsigned
name|short
modifier|*
name|p
parameter_list|)
block|{
return|return
name|_rdrand16_step
argument_list|(
name|p
argument_list|)
return|;
comment|// CHECK: @rdrand16
comment|// CHECK: call { i16, i32 } @llvm.x86.rdrand.16
comment|// CHECK: store i16
block|}
end_function

begin_function
name|int
name|rdrand32
parameter_list|(
name|unsigned
modifier|*
name|p
parameter_list|)
block|{
return|return
name|_rdrand32_step
argument_list|(
name|p
argument_list|)
return|;
comment|// CHECK: @rdrand32
comment|// CHECK: call { i32, i32 } @llvm.x86.rdrand.32
comment|// CHECK: store i32
block|}
end_function

begin_function
name|int
name|rdrand64
parameter_list|(
name|unsigned
name|long
name|long
modifier|*
name|p
parameter_list|)
block|{
return|return
name|_rdrand64_step
argument_list|(
name|p
argument_list|)
return|;
comment|// CHECK: @rdrand64
comment|// CHECK: call { i64, i32 } @llvm.x86.rdrand.64
comment|// CHECK: store i64
block|}
end_function

end_unit

