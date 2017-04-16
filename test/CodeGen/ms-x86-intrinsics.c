begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple i686--windows -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s -check-prefix=CHECK -check-prefix=CHECK-I386
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -fms-extensions -fms-compatibility -fms-compatibility-version=17.00 \
end_comment

begin_comment
comment|// RUN:         -triple x86_64--windows -Oz -emit-llvm %s -o - \
end_comment

begin_comment
comment|// RUN:         | FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-X64
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_function
name|char
name|test__readfsbyte
parameter_list|(
name|unsigned
name|long
name|Offset
parameter_list|)
block|{
return|return
name|__readfsbyte
argument_list|(
name|Offset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-I386-LABEL: define signext i8 @test__readfsbyte(i32 %Offset)
end_comment

begin_comment
comment|// CHECK-I386:   [[PTR:%[0-9]+]] = inttoptr i32 %Offset to i8 addrspace(257)*
end_comment

begin_comment
comment|// CHECK-I386:   [[VALUE:%[0-9]+]] = load volatile i8, i8 addrspace(257)* [[PTR]], align 1
end_comment

begin_comment
comment|// CHECK-I386:   ret i8 [[VALUE:%[0-9]+]]
end_comment

begin_function
name|short
name|test__readfsword
parameter_list|(
name|unsigned
name|long
name|Offset
parameter_list|)
block|{
return|return
name|__readfsword
argument_list|(
name|Offset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-I386-LABEL: define signext i16 @test__readfsword(i32 %Offset)
end_comment

begin_comment
comment|// CHECK-I386:   [[PTR:%[0-9]+]] = inttoptr i32 %Offset to i16 addrspace(257)*
end_comment

begin_comment
comment|// CHECK-I386:   [[VALUE:%[0-9]+]] = load volatile i16, i16 addrspace(257)* [[PTR]], align 2
end_comment

begin_comment
comment|// CHECK-I386:   ret i16 [[VALUE:%[0-9]+]]
end_comment

begin_function
name|long
name|test__readfsdword
parameter_list|(
name|unsigned
name|long
name|Offset
parameter_list|)
block|{
return|return
name|__readfsdword
argument_list|(
name|Offset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-I386-LABEL: define i32 @test__readfsdword(i32 %Offset)
end_comment

begin_comment
comment|// CHECK-I386:   [[PTR:%[0-9]+]] = inttoptr i32 %Offset to i32 addrspace(257)*
end_comment

begin_comment
comment|// CHECK-I386:   [[VALUE:%[0-9]+]] = load volatile i32, i32 addrspace(257)* [[PTR]], align 4
end_comment

begin_comment
comment|// CHECK-I386:   ret i32 [[VALUE:%[0-9]+]]
end_comment

begin_function
name|long
name|long
name|test__readfsqword
parameter_list|(
name|unsigned
name|long
name|Offset
parameter_list|)
block|{
return|return
name|__readfsqword
argument_list|(
name|Offset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-I386-LABEL: define i64 @test__readfsqword(i32 %Offset)
end_comment

begin_comment
comment|// CHECK-I386:   [[PTR:%[0-9]+]] = inttoptr i32 %Offset to i64 addrspace(257)*
end_comment

begin_comment
comment|// CHECK-I386:   [[VALUE:%[0-9]+]] = load volatile i64, i64 addrspace(257)* [[PTR]], align 8
end_comment

begin_comment
comment|// CHECK-I386:   ret i64 [[VALUE:%[0-9]+]]
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__int64
name|test__emul
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|__emul
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test__emul(i32 %a, i32 %b)
end_comment

begin_comment
comment|// CHECK: [[X:%[0-9]+]] = sext i32 %a to i64
end_comment

begin_comment
comment|// CHECK: [[Y:%[0-9]+]] = sext i32 %b to i64
end_comment

begin_comment
comment|// CHECK: [[RES:%[0-9]+]] = mul nsw i64 [[Y]], [[X]]
end_comment

begin_comment
comment|// CHECK: ret i64 [[RES]]
end_comment

begin_function
name|unsigned
name|__int64
name|test__emulu
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|,
name|unsigned
name|int
name|b
parameter_list|)
block|{
return|return
name|__emulu
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test__emulu(i32 %a, i32 %b)
end_comment

begin_comment
comment|// CHECK: [[X:%[0-9]+]] = zext i32 %a to i64
end_comment

begin_comment
comment|// CHECK: [[Y:%[0-9]+]] = zext i32 %b to i64
end_comment

begin_comment
comment|// CHECK: [[RES:%[0-9]+]] = mul nuw i64 [[Y]], [[X]]
end_comment

begin_comment
comment|// CHECK: ret i64 [[RES]]
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_function
name|char
name|test__readgsbyte
parameter_list|(
name|unsigned
name|long
name|Offset
parameter_list|)
block|{
return|return
name|__readgsbyte
argument_list|(
name|Offset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define i8 @test__readgsbyte(i32 %Offset)
end_comment

begin_comment
comment|// CHECK-X64:   [[ZEXT:%[0-9]+]] = zext i32 %Offset to i64
end_comment

begin_comment
comment|// CHECK-X64:   [[PTR:%[0-9]+]] = inttoptr i64 [[ZEXT]] to i8 addrspace(256)*
end_comment

begin_comment
comment|// CHECK-X64:   [[VALUE:%[0-9]+]] = load volatile i8, i8 addrspace(256)* [[PTR]], align 1
end_comment

begin_comment
comment|// CHECK-X64:   ret i8 [[VALUE:%[0-9]+]]
end_comment

begin_function
name|short
name|test__readgsword
parameter_list|(
name|unsigned
name|long
name|Offset
parameter_list|)
block|{
return|return
name|__readgsword
argument_list|(
name|Offset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define i16 @test__readgsword(i32 %Offset)
end_comment

begin_comment
comment|// CHECK-X64:   [[ZEXT:%[0-9]+]] = zext i32 %Offset to i64
end_comment

begin_comment
comment|// CHECK-X64:   [[PTR:%[0-9]+]] = inttoptr i64 [[ZEXT]] to i16 addrspace(256)*
end_comment

begin_comment
comment|// CHECK-X64:   [[VALUE:%[0-9]+]] = load volatile i16, i16 addrspace(256)* [[PTR]], align 2
end_comment

begin_comment
comment|// CHECK-X64:   ret i16 [[VALUE:%[0-9]+]]
end_comment

begin_function
name|long
name|test__readgsdword
parameter_list|(
name|unsigned
name|long
name|Offset
parameter_list|)
block|{
return|return
name|__readgsdword
argument_list|(
name|Offset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define i32 @test__readgsdword(i32 %Offset)
end_comment

begin_comment
comment|// CHECK-X64:   [[ZEXT:%[0-9]+]] = zext i32 %Offset to i64
end_comment

begin_comment
comment|// CHECK-X64:   [[PTR:%[0-9]+]] = inttoptr i64 [[ZEXT]] to i32 addrspace(256)*
end_comment

begin_comment
comment|// CHECK-X64:   [[VALUE:%[0-9]+]] = load volatile i32, i32 addrspace(256)* [[PTR]], align 4
end_comment

begin_comment
comment|// CHECK-X64:   ret i32 [[VALUE:%[0-9]+]]
end_comment

begin_function
name|long
name|long
name|test__readgsqword
parameter_list|(
name|unsigned
name|long
name|Offset
parameter_list|)
block|{
return|return
name|__readgsqword
argument_list|(
name|Offset
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define i64 @test__readgsqword(i32 %Offset)
end_comment

begin_comment
comment|// CHECK-X64:   [[ZEXT:%[0-9]+]] = zext i32 %Offset to i64
end_comment

begin_comment
comment|// CHECK-X64:   [[PTR:%[0-9]+]] = inttoptr i64 [[ZEXT]] to i64 addrspace(256)*
end_comment

begin_comment
comment|// CHECK-X64:   [[VALUE:%[0-9]+]] = load volatile i64, i64 addrspace(256)* [[PTR]], align 8
end_comment

begin_comment
comment|// CHECK-X64:   ret i64 [[VALUE:%[0-9]+]]
end_comment

begin_function
name|__int64
name|test__mulh
parameter_list|(
name|__int64
name|a
parameter_list|,
name|__int64
name|b
parameter_list|)
block|{
return|return
name|__mulh
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define i64 @test__mulh(i64 %a, i64 %b)
end_comment

begin_comment
comment|// CHECK-X64: = mul nsw i128 %
end_comment

begin_function
name|unsigned
name|__int64
name|test__umulh
parameter_list|(
name|unsigned
name|__int64
name|a
parameter_list|,
name|unsigned
name|__int64
name|b
parameter_list|)
block|{
return|return
name|__umulh
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define i64 @test__umulh(i64 %a, i64 %b)
end_comment

begin_comment
comment|// CHECK-X64: = mul nuw i128 %
end_comment

begin_function
name|__int64
name|test_mul128
parameter_list|(
name|__int64
name|Multiplier
parameter_list|,
name|__int64
name|Multiplicand
parameter_list|,
name|__int64
modifier|*
name|HighProduct
parameter_list|)
block|{
return|return
name|_mul128
argument_list|(
name|Multiplier
argument_list|,
name|Multiplicand
argument_list|,
name|HighProduct
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define i64 @test_mul128(i64 %Multiplier, i64 %Multiplicand, i64*{{[a-z_ ]*}}%HighProduct)
end_comment

begin_comment
comment|// CHECK-X64: = sext i64 %Multiplier to i128
end_comment

begin_comment
comment|// CHECK-X64: = sext i64 %Multiplicand to i128
end_comment

begin_comment
comment|// CHECK-X64: = mul nsw i128 %
end_comment

begin_comment
comment|// CHECK-X64: store i64 %
end_comment

begin_comment
comment|// CHECK-X64: ret i64 %
end_comment

begin_function
name|unsigned
name|__int64
name|test_umul128
parameter_list|(
name|unsigned
name|__int64
name|Multiplier
parameter_list|,
name|unsigned
name|__int64
name|Multiplicand
parameter_list|,
name|unsigned
name|__int64
modifier|*
name|HighProduct
parameter_list|)
block|{
return|return
name|_umul128
argument_list|(
name|Multiplier
argument_list|,
name|Multiplicand
argument_list|,
name|HighProduct
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-X64-LABEL: define i64 @test_umul128(i64 %Multiplier, i64 %Multiplicand, i64*{{[a-z_ ]*}}%HighProduct)
end_comment

begin_comment
comment|// CHECK-X64: = zext i64 %Multiplier to i128
end_comment

begin_comment
comment|// CHECK-X64: = zext i64 %Multiplicand to i128
end_comment

begin_comment
comment|// CHECK-X64: = mul nuw i128 %
end_comment

begin_comment
comment|// CHECK-X64: store i64 %
end_comment

begin_comment
comment|// CHECK-X64: ret i64 %
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

