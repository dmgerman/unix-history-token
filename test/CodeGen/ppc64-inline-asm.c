begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -O2 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|_Bool
name|test_wc_i1
parameter_list|(
name|_Bool
name|b1
parameter_list|,
name|_Bool
name|b2
parameter_list|)
block|{
name|_Bool
name|o
decl_stmt|;
asm|asm("crand %0, %1, %2" : "=wc"(o) : "wc"(b1), "wc"(b2) : );
return|return
name|o
return|;
comment|// CHECK-LABEL: define zeroext i1 @test_wc_i1(i1 zeroext %b1, i1 zeroext %b2)
comment|// CHECK: call i8 asm "crand $0, $1, $2", "=^wc,^wc,^wc"(i1 %b1, i1 %b2)
block|}
end_function

begin_function
name|int
name|test_wc_i32
parameter_list|(
name|int
name|b1
parameter_list|,
name|int
name|b2
parameter_list|)
block|{
name|int
name|o
decl_stmt|;
asm|asm("crand %0, %1, %2" : "=wc"(o) : "wc"(b1), "wc"(b2) : );
return|return
name|o
return|;
comment|// CHECK-LABEL: signext i32 @test_wc_i32(i32 signext %b1, i32 signext %b2)
comment|// CHECK: call i32 asm "crand $0, $1, $2", "=^wc,^wc,^wc"(i32 %b1, i32 %b2)
block|}
end_function

begin_function
name|unsigned
name|char
name|test_wc_i8
parameter_list|(
name|unsigned
name|char
name|b1
parameter_list|,
name|unsigned
name|char
name|b2
parameter_list|)
block|{
name|unsigned
name|char
name|o
decl_stmt|;
asm|asm("crand %0, %1, %2" : "=wc"(o) : "wc"(b1), "wc"(b2) : );
return|return
name|o
return|;
comment|// CHECK-LABEL: zeroext i8 @test_wc_i8(i8 zeroext %b1, i8 zeroext %b2)
comment|// CHECK: call i8 asm "crand $0, $1, $2", "=^wc,^wc,^wc"(i8 %b1, i8 %b2)
block|}
end_function

end_unit

