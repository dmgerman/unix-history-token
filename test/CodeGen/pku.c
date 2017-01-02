begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +pku -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|unsigned
name|int
name|test_rdpkru_u32
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_rdpkru_u32
comment|// CHECK: @llvm.x86.rdpkru
return|return
name|_rdpkru_u32
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|test_wrpkru
parameter_list|(
name|unsigned
name|int
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_wrpkru
comment|// CHECK: @llvm.x86.wrpkru
name|_wrpkru
argument_list|(
name|__A
argument_list|)
expr_stmt|;
return|return ;
block|}
end_function

end_unit

