begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=renderscript32-none-linux-gnueabi -emit-llvm -o - -Werror | FileCheck %s -check-prefix=CHECK-RS32
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple=renderscript64-none-linux-android -emit-llvm -o - -Werror | FileCheck %s -check-prefix=CHECK-RS64
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple=armv7-none-linux-gnueabi -emit-llvm -o - -Werror | FileCheck %s -check-prefix=CHECK-ARM
end_comment

begin_comment
comment|// Ensure that the bitcode has the correct triple
end_comment

begin_comment
comment|// CHECK-RS32: target triple = "armv7-none-linux-gnueabi"
end_comment

begin_comment
comment|// CHECK-RS64: target triple = "aarch64-none-linux-android"
end_comment

begin_comment
comment|// CHECK-ARM: target triple = "armv7-none-linux-gnueabi"
end_comment

begin_comment
comment|// Ensure that long data type has 8-byte size and alignment in RenderScript
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__RENDERSCRIPT__
end_ifdef

begin_define
define|#
directive|define
name|LONG_WIDTH_AND_ALIGN
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LONG_WIDTH_AND_ALIGN
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_assert
assert|_Static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|==
name|LONG_WIDTH_AND_ALIGN
argument_list|,
literal|"sizeof long is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
alignof|_Alignof
argument_list|(
name|long
argument_list|)
operator|==
name|LONG_WIDTH_AND_ALIGN
argument_list|,
literal|"sizeof long is wrong"
argument_list|)
assert|;
end_assert

begin_comment
comment|// CHECK-RS32: i64 @test_long(i64 %v)
end_comment

begin_comment
comment|// CHECK-RS64: i64 @test_long(i64 %v)
end_comment

begin_comment
comment|// CHECK-ARM: i32 @test_long(i32 %v)
end_comment

begin_function
name|long
name|test_long
parameter_list|(
name|long
name|v
parameter_list|)
block|{
return|return
name|v
operator|+
literal|1
return|;
block|}
end_function

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// Test coercion of aggregate argument or return value into integer arrays
end_comment

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// aggregate parameter<= 4 bytes: coerced to [a x iNN] for both 32-bit and
end_comment

begin_comment
comment|// 64-bit RenderScript
end_comment

begin_comment
comment|// ==============================================================================
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c1
decl_stmt|,
name|c2
decl_stmt|,
name|c3
decl_stmt|;
block|}
name|sChar3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|s
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
name|sShortChar
typedef|;
end_typedef

begin_comment
comment|// CHECK-RS32: void @argChar3([3 x i8] %s.coerce)
end_comment

begin_comment
comment|// CHECK-RS64: void @argChar3([3 x i8] %s.coerce)
end_comment

begin_function
name|void
name|argChar3
parameter_list|(
name|sChar3
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-RS32: void @argShortChar([2 x i16] %s.coerce)
end_comment

begin_comment
comment|// CHECK-RS64: void @argShortChar([2 x i16] %s.coerce)
end_comment

begin_function
name|void
name|argShortChar
parameter_list|(
name|sShortChar
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// aggregate return value<= 4 bytes: coerced to [a x iNN] for both 32-bit and
end_comment

begin_comment
comment|// 64-bit RenderScript
end_comment

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// CHECK-RS32: [3 x i8] @retChar3()
end_comment

begin_comment
comment|// CHECK-RS64: [3 x i8] @retChar3()
end_comment

begin_function
name|sChar3
name|retChar3
parameter_list|()
block|{
name|sChar3
name|r
decl_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-RS32: [2 x i16] @retShortChar()
end_comment

begin_comment
comment|// CHECK-RS64: [2 x i16] @retShortChar()
end_comment

begin_function
name|sShortChar
name|retShortChar
parameter_list|()
block|{
name|sShortChar
name|r
decl_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// aggregate parameter<= 16 bytes: coerced to [a x iNN] for both 32-bit and
end_comment

begin_comment
comment|// 64-bit RenderScript
end_comment

begin_comment
comment|// =============================================================================
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|s1
decl_stmt|;
name|char
name|c
decl_stmt|;
name|short
name|s2
decl_stmt|;
block|}
name|sShortCharShort
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i
decl_stmt|;
name|short
name|s
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
name|sIntShortChar
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|l
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
name|sLongInt
typedef|;
end_typedef

begin_comment
comment|// CHECK-RS32: void @argShortCharShort([3 x i16] %s.coerce)
end_comment

begin_comment
comment|// CHECK-RS64: void @argShortCharShort([3 x i16] %s.coerce)
end_comment

begin_function
name|void
name|argShortCharShort
parameter_list|(
name|sShortCharShort
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-RS32: void @argIntShortChar([2 x i32] %s.coerce)
end_comment

begin_comment
comment|// CHECK-RS64: void @argIntShortChar([2 x i32] %s.coerce)
end_comment

begin_function
name|void
name|argIntShortChar
parameter_list|(
name|sIntShortChar
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-RS32: void @argLongInt([2 x i64] %s.coerce)
end_comment

begin_comment
comment|// CHECK-RS64: void @argLongInt([2 x i64] %s.coerce)
end_comment

begin_function
name|void
name|argLongInt
parameter_list|(
name|sLongInt
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// aggregate return value<= 16 bytes: returned on stack for 32-bit RenderScript
end_comment

begin_comment
comment|// and coerced to [a x iNN] for 64-bit RenderScript
end_comment

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// CHECK-RS32: void @retShortCharShort(%struct.sShortCharShort* noalias sret %agg.result)
end_comment

begin_comment
comment|// CHECK-RS64: [3 x i16] @retShortCharShort()
end_comment

begin_function
name|sShortCharShort
name|retShortCharShort
parameter_list|()
block|{
name|sShortCharShort
name|r
decl_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-RS32: void @retIntShortChar(%struct.sIntShortChar* noalias sret %agg.result)
end_comment

begin_comment
comment|// CHECK-RS64: [2 x i32] @retIntShortChar()
end_comment

begin_function
name|sIntShortChar
name|retIntShortChar
parameter_list|()
block|{
name|sIntShortChar
name|r
decl_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-RS32: void @retLongInt(%struct.sLongInt* noalias sret %agg.result)
end_comment

begin_comment
comment|// CHECK-RS64: [2 x i64] @retLongInt()
end_comment

begin_function
name|sLongInt
name|retLongInt
parameter_list|()
block|{
name|sLongInt
name|r
decl_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// aggregate parameter<= 64 bytes: coerced to [a x iNN] for 32-bit RenderScript
end_comment

begin_comment
comment|// and passed on the stack for 64-bit RenderScript
end_comment

begin_comment
comment|// =============================================================================
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i1
decl_stmt|,
name|i2
decl_stmt|,
name|i3
decl_stmt|,
name|i4
decl_stmt|,
name|i5
decl_stmt|;
block|}
name|sInt5
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|l1
decl_stmt|,
name|l2
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
name|sLong2Char
typedef|;
end_typedef

begin_comment
comment|// CHECK-RS32: void @argInt5([5 x i32] %s.coerce)
end_comment

begin_comment
comment|// CHECK-RS64: void @argInt5(%struct.sInt5* %s)
end_comment

begin_function
name|void
name|argInt5
parameter_list|(
name|sInt5
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-RS32: void @argLong2Char([3 x i64] %s.coerce)
end_comment

begin_comment
comment|// CHECK-RS64: void @argLong2Char(%struct.sLong2Char* %s)
end_comment

begin_function
name|void
name|argLong2Char
parameter_list|(
name|sLong2Char
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// aggregate return value<= 64 bytes: returned on stack for both 32-bit and
end_comment

begin_comment
comment|// 64-bit RenderScript
end_comment

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// CHECK-RS32: void @retInt5(%struct.sInt5* noalias sret %agg.result)
end_comment

begin_comment
comment|// CHECK-RS64: void @retInt5(%struct.sInt5* noalias sret %agg.result)
end_comment

begin_function
name|sInt5
name|retInt5
parameter_list|()
block|{
name|sInt5
name|r
decl_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// CHECK-RS32: void @retLong2Char(%struct.sLong2Char* noalias sret %agg.result)
end_comment

begin_comment
comment|// CHECK-RS64: void @retLong2Char(%struct.sLong2Char* noalias sret %agg.result)
end_comment

begin_function
name|sLong2Char
name|retLong2Char
parameter_list|()
block|{
name|sLong2Char
name|r
decl_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// =============================================================================
end_comment

begin_comment
comment|// aggregate parameters and return values> 64 bytes: passed and returned on the
end_comment

begin_comment
comment|// stack for both 32-bit and 64-bit RenderScript
end_comment

begin_comment
comment|// =============================================================================
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|l1
decl_stmt|,
name|l2
decl_stmt|,
name|l3
decl_stmt|,
name|l4
decl_stmt|,
name|l5
decl_stmt|,
name|l6
decl_stmt|,
name|l7
decl_stmt|,
name|l8
decl_stmt|,
name|l9
decl_stmt|;
block|}
name|sLong9
typedef|;
end_typedef

begin_comment
comment|// CHECK-RS32: void @argLong9(%struct.sLong9* byval align 8 %s)
end_comment

begin_comment
comment|// CHECK-RS64: void @argLong9(%struct.sLong9* %s)
end_comment

begin_function
name|void
name|argLong9
parameter_list|(
name|sLong9
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-RS32: void @retLong9(%struct.sLong9* noalias sret %agg.result)
end_comment

begin_comment
comment|// CHECK-RS64: void @retLong9(%struct.sLong9* noalias sret %agg.result)
end_comment

begin_function
name|sLong9
name|retLong9
parameter_list|()
block|{
name|sLong9
name|r
decl_stmt|;
return|return
name|r
return|;
block|}
end_function

end_unit

