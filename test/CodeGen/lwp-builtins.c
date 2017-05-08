begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +lwp -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_function
name|void
name|test_llwpcb
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_llwpcb
comment|// CHECK: call void @llvm.x86.llwpcb(i8* %{{.*}})
name|__llwpcb
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|test_slwpcb
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_slwpcb
comment|// CHECK: call i8* @llvm.x86.slwpcb()
return|return
name|__slwpcb
argument_list|()
return|;
block|}
end_function

begin_function
name|unsigned
name|char
name|test_lwpins32
parameter_list|(
name|unsigned
name|val2
parameter_list|,
name|unsigned
name|val1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_lwpins32
comment|// CHECK: call i8 @llvm.x86.lwpins32(i32
return|return
name|__lwpins32
argument_list|(
name|val2
argument_list|,
name|val1
argument_list|,
literal|0x01234
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|char
name|test_lwpins64
parameter_list|(
name|unsigned
name|long
name|long
name|val2
parameter_list|,
name|unsigned
name|val1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_lwpins64
comment|// CHECK: call i8 @llvm.x86.lwpins64(i64
return|return
name|__lwpins64
argument_list|(
name|val2
argument_list|,
name|val1
argument_list|,
literal|0x56789
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_lwpval32
parameter_list|(
name|unsigned
name|val2
parameter_list|,
name|unsigned
name|val1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_lwpval32
comment|// CHECK: call void @llvm.x86.lwpval32(i32
name|__lwpval32
argument_list|(
name|val2
argument_list|,
name|val1
argument_list|,
literal|0x01234
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_lwpval64
parameter_list|(
name|unsigned
name|long
name|long
name|val2
parameter_list|,
name|unsigned
name|val1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_lwpval64
comment|// CHECK: call void @llvm.x86.lwpval64(i64
name|__lwpval64
argument_list|(
name|val2
argument_list|,
name|val1
argument_list|,
literal|0xABCDEF
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

