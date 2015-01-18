begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -ffreestanding -target-feature +adx -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_function
name|unsigned
name|char
name|test_addcarryx_u32
parameter_list|(
name|unsigned
name|char
name|__cf
parameter_list|,
name|unsigned
name|int
name|__x
parameter_list|,
name|unsigned
name|int
name|__y
parameter_list|,
name|unsigned
name|int
modifier|*
name|__p
parameter_list|)
block|{
comment|// CHECK-LABEL: test_addcarryx_u32
comment|// CHECK: call i8 @llvm.x86.addcarryx.u32
return|return
name|_addcarryx_u32
argument_list|(
name|__cf
argument_list|,
name|__x
argument_list|,
name|__y
argument_list|,
name|__p
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|char
name|test_addcarryx_u64
parameter_list|(
name|unsigned
name|char
name|__cf
parameter_list|,
name|unsigned
name|long
name|long
name|__x
parameter_list|,
name|unsigned
name|long
name|long
name|__y
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
name|__p
parameter_list|)
block|{
comment|// CHECK-LABEL: test_addcarryx_u64
comment|// CHECK: call i8 @llvm.x86.addcarryx.u64
return|return
name|_addcarryx_u64
argument_list|(
name|__cf
argument_list|,
name|__x
argument_list|,
name|__y
argument_list|,
name|__p
argument_list|)
return|;
block|}
end_function

end_unit

