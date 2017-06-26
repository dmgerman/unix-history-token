begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s -check-prefix=CHECK -check-prefix=SSE -check-prefix=NO-AVX512
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -target-feature +avx | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s -check-prefix=CHECK -check-prefix=AVX -check-prefix=NO-AVX512
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -target-feature +avx512f | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s -check-prefix=CHECK -check-prefix=AVX -check-prefix=AVX512
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// CHECK-LABEL: define signext i8 @f0()
end_comment

begin_function
name|char
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define signext i16 @f1()
end_comment

begin_function
name|short
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f2()
end_comment

begin_function
name|int
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @f3()
end_comment

begin_function
name|float
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @f4()
end_comment

begin_function
name|double
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define x86_fp80 @f5()
end_comment

begin_function
name|long
name|double
name|f5
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f6(i8 signext %a0, i16 signext %a1, i32 %a2, i64 %a3, i8* %a4)
end_comment

begin_function
name|void
name|f6
parameter_list|(
name|char
name|a0
parameter_list|,
name|short
name|a1
parameter_list|,
name|int
name|a2
parameter_list|,
name|long
name|long
name|a3
parameter_list|,
name|void
modifier|*
name|a4
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK-LABEL: define void @f7(i32 %a0)
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|A
block|,
name|B
block|,
name|C
block|}
name|e7
typedef|;
end_typedef

begin_function
name|void
name|f7
parameter_list|(
name|e7
name|a0
parameter_list|)
block|{ }
end_function

begin_comment
comment|// Test merging/passing of upper eightbyte with X87 class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f8_1(%union.u8* noalias sret %agg.result)
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f8_2(%union.u8* byval align 16 %a0)
end_comment

begin_union
union|union
name|u8
block|{
name|long
name|double
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|u8
name|f8_1
parameter_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f8_2
parameter_list|(
name|union
name|u8
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @f9()
end_comment

begin_struct
struct|struct
name|s9
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
name|f9
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK-LABEL: define void @f10(i64 %a0.coerce)
decl|struct
name|s10
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f10
parameter_list|(
name|struct
name|s10
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f11(%union.anon* noalias sret %agg.result)
end_comment

begin_union
union|union
block|{
name|long
name|double
name|a
decl_stmt|;
name|float
name|b
decl_stmt|;
block|}
name|f11
argument_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK-LABEL: define i32 @f12_0()
comment|// CHECK-LABEL: define void @f12_1(i32 %a0.coerce)
decl|struct
name|s12
block|{
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
decl_stmt|;
block|}
union|;
end_union

begin_function
name|struct
name|s12
name|f12_0
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f12_1
parameter_list|(
name|struct
name|s12
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// Check that sret parameter is accounted for when checking available integer
end_comment

begin_comment
comment|// registers.
end_comment

begin_comment
comment|// CHECK: define void @f13(%struct.s13_0* noalias sret %agg.result, i32 %a, i32 %b, i32 %c, i32 %d, {{.*}}* byval align 8 %e, i32 %f)
end_comment

begin_struct
struct|struct
name|s13_0
block|{
name|long
name|long
name|f0
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s13_1
block|{
name|long
name|long
name|f0
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s13_0
name|f13
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|d
parameter_list|,
name|struct
name|s13_1
name|e
parameter_list|,
name|int
name|f
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// CHECK: define void @f14({{.*}}, i8 signext %X)
end_comment

begin_function
name|void
name|f14
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|d
parameter_list|,
name|int
name|e
parameter_list|,
name|int
name|f
parameter_list|,
name|char
name|X
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f15({{.*}}, i8* %X)
end_comment

begin_function
name|void
name|f15
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|d
parameter_list|,
name|int
name|e
parameter_list|,
name|int
name|f
parameter_list|,
name|void
modifier|*
name|X
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f16({{.*}}, float %X)
end_comment

begin_function
name|void
name|f16
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|,
name|float
name|d
parameter_list|,
name|float
name|e
parameter_list|,
name|float
name|f
parameter_list|,
name|float
name|g
parameter_list|,
name|float
name|h
parameter_list|,
name|float
name|X
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f17({{.*}}, x86_fp80 %X)
end_comment

begin_function
name|void
name|f17
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|,
name|float
name|d
parameter_list|,
name|float
name|e
parameter_list|,
name|float
name|f
parameter_list|,
name|float
name|g
parameter_list|,
name|float
name|h
parameter_list|,
name|long
name|double
name|X
parameter_list|)
block|{}
end_function

begin_comment
comment|// Check for valid coercion.  The struct should be passed/returned as i32, not
end_comment

begin_comment
comment|// as i64 for better code quality.
end_comment

begin_comment
comment|// rdar://8135035
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f18(i32 %a, i32 %f18_arg1.coerce)
end_comment

begin_struct
struct|struct
name|f18_s0
block|{
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f18
parameter_list|(
name|int
name|a
parameter_list|,
name|struct
name|f18_s0
name|f18_arg1
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// Check byval alignment.
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f19(%struct.s19* byval align 16 %x)
end_comment

begin_struct
struct|struct
name|s19
block|{
name|long
name|double
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f19
parameter_list|(
name|struct
name|s19
name|x
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f20(%struct.s20* byval align 32 %x)
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(aligned(
literal|32
argument|))
argument_list|)
name|s20
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f20
parameter_list|(
name|struct
name|s20
name|x
parameter_list|)
block|{}
end_function

begin_struct
struct|struct
name|StringRef
block|{
name|long
name|x
decl_stmt|;
specifier|const
name|char
modifier|*
name|Ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// rdar://7375902
end_comment

begin_comment
comment|// CHECK-LABEL: define i8* @f21(i64 %S.coerce0, i8* %S.coerce1)
end_comment

begin_function
specifier|const
name|char
modifier|*
name|f21
parameter_list|(
name|struct
name|StringRef
name|S
parameter_list|)
block|{
return|return
name|S
operator|.
name|x
operator|+
name|S
operator|.
name|Ptr
return|;
block|}
end_function

begin_comment
comment|// PR7567
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(aligned(
literal|16
argument|))
argument_list|)
struct|struct
name|f22s
block|{
name|unsigned
name|long
name|long
name|x
index|[
literal|2
index|]
decl_stmt|;
block|}
name|L
typedef|;
end_typedef

begin_function
name|void
name|f22
parameter_list|(
name|L
name|x
parameter_list|,
name|L
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: @f22
end_comment

begin_comment
comment|// CHECK: %x = alloca{{.*}}, align 16
end_comment

begin_comment
comment|// CHECK: %y = alloca{{.*}}, align 16
end_comment

begin_comment
comment|// PR7714
end_comment

begin_struct
struct|struct
name|f23S
block|{
name|short
name|f0
decl_stmt|;
name|unsigned
name|f1
decl_stmt|;
name|int
name|f2
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f23
parameter_list|(
name|int
name|A
parameter_list|,
name|struct
name|f23S
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @f23(i32 %A, i64 %B.coerce0, i32 %B.coerce1)
block|}
end_function

begin_struct
struct|struct
name|f24s
block|{
name|long
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|f23S
name|f24
parameter_list|(
name|struct
name|f23S
modifier|*
name|X
parameter_list|,
name|struct
name|f24s
modifier|*
name|P2
parameter_list|)
block|{
return|return
operator|*
name|X
return|;
comment|// CHECK: define { i64, i32 } @f24(%struct.f23S* %X, %struct.f24s* %P2)
block|}
end_function

begin_comment
comment|// rdar://8248065
end_comment

begin_typedef
typedef|typedef
name|float
name|v4f32
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function
name|v4f32
name|f25
parameter_list|(
name|v4f32
name|X
parameter_list|)
block|{
comment|// CHECK-LABEL: define<4 x float> @f25(<4 x float> %X)
comment|// CHECK-NOT: alloca
comment|// CHECK: alloca<4 x float>
comment|// CHECK-NOT: alloca
comment|// CHECK: store<4 x float> %X,<4 x float>*
comment|// CHECK-NOT: store
comment|// CHECK: ret<4 x float>
return|return
name|X
operator|+
name|X
return|;
block|}
end_function

begin_struct
struct|struct
name|foo26
block|{
name|int
modifier|*
name|X
decl_stmt|;
name|float
modifier|*
name|Y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|foo26
name|f26
parameter_list|(
name|struct
name|foo26
modifier|*
name|P
parameter_list|)
block|{
comment|// CHECK: define { i32*, float* } @f26(%struct.foo26* %P)
return|return
operator|*
name|P
return|;
block|}
end_function

begin_struct
struct|struct
name|v4f32wrapper
block|{
name|v4f32
name|v
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|v4f32wrapper
name|f27
parameter_list|(
name|struct
name|v4f32wrapper
name|X
parameter_list|)
block|{
comment|// CHECK-LABEL: define<4 x float> @f27(<4 x float> %X.coerce)
return|return
name|X
return|;
block|}
end_function

begin_comment
comment|// PR22563 - We should unwrap simple structs and arrays to pass
end_comment

begin_comment
comment|// and return them in the appropriate vector registers if possible.
end_comment

begin_typedef
typedef|typedef
name|float
name|v8f32
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_struct
struct|struct
name|v8f32wrapper
block|{
name|v8f32
name|v
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|v8f32wrapper
name|f27a
parameter_list|(
name|struct
name|v8f32wrapper
name|X
parameter_list|)
block|{
comment|// AVX-LABEL: define<8 x float> @f27a(<8 x float> %X.coerce)
return|return
name|X
return|;
block|}
end_function

begin_struct
struct|struct
name|v8f32wrapper_wrapper
block|{
name|v8f32
name|v
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|v8f32wrapper_wrapper
name|f27b
parameter_list|(
name|struct
name|v8f32wrapper_wrapper
name|X
parameter_list|)
block|{
comment|// AVX-LABEL: define<8 x float> @f27b(<8 x float> %X.coerce)
return|return
name|X
return|;
block|}
end_function

begin_comment
comment|// rdar://5711709
end_comment

begin_struct
struct|struct
name|f28c
block|{
name|double
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f28
parameter_list|(
name|struct
name|f28c
name|C
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @f28(double %C.coerce0, i32 %C.coerce1)
block|}
end_function

begin_struct
struct|struct
name|f29a
block|{
struct|struct
name|c
block|{
name|double
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|x
index|[
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_function
name|void
name|f29a
parameter_list|(
name|struct
name|f29a
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @f29a(double %A.coerce0, i32 %A.coerce1)
block|}
end_function

begin_comment
comment|// rdar://8249586
end_comment

begin_struct
struct|struct
name|S0
block|{
name|char
name|f0
index|[
literal|8
index|]
decl_stmt|;
name|char
name|f2
decl_stmt|;
name|char
name|f3
decl_stmt|;
name|char
name|f4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f30
parameter_list|(
name|struct
name|S0
name|p_4
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @f30(i64 %p_4.coerce0, i24 %p_4.coerce1)
block|}
end_function

begin_comment
comment|// Pass the third element as a float when followed by tail padding.
end_comment

begin_comment
comment|// rdar://8251384
end_comment

begin_struct
struct|struct
name|f31foo
block|{
name|float
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|float
name|f31
parameter_list|(
name|struct
name|f31foo
name|X
parameter_list|)
block|{
comment|// CHECK-LABEL: define float @f31(<2 x float> %X.coerce0, float %X.coerce1)
return|return
name|X
operator|.
name|c
return|;
block|}
end_function

begin_function
specifier|_Complex
name|float
name|f32
parameter_list|(
specifier|_Complex
name|float
name|A
parameter_list|,
specifier|_Complex
name|float
name|B
parameter_list|)
block|{
comment|// rdar://6379669
comment|// CHECK-LABEL: define<2 x float> @f32(<2 x float> %A.coerce,<2 x float> %B.coerce)
return|return
name|A
operator|+
name|B
return|;
block|}
end_function

begin_comment
comment|// rdar://8357396
end_comment

begin_struct
struct|struct
name|f33s
block|{
name|long
name|x
decl_stmt|;
name|float
name|c
decl_stmt|,
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f33
parameter_list|(
name|va_list
name|X
parameter_list|)
block|{
name|va_arg
argument_list|(
name|X
argument_list|,
expr|struct
name|f33s
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|v1i64
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_comment
comment|// rdar://8359248
end_comment

begin_comment
comment|// CHECK-LABEL: define double @f34(double %arg.coerce)
end_comment

begin_function
name|v1i64
name|f34
parameter_list|(
name|v1i64
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// rdar://8358475
end_comment

begin_comment
comment|// CHECK-LABEL: define double @f35(double %arg.coerce)
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|v1i64_2
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_function
name|v1i64_2
name|f35
parameter_list|(
name|v1i64_2
name|arg
parameter_list|)
block|{
return|return
name|arg
operator|+
name|arg
return|;
block|}
end_function

begin_comment
comment|// rdar://9122143
end_comment

begin_comment
comment|// CHECK: declare void @func(%struct._str* byval align 16)
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_str
block|{
union|union
block|{
name|long
name|double
name|a
decl_stmt|;
name|long
name|c
decl_stmt|;
block|}
union|;
block|}
name|str
typedef|;
end_typedef

begin_function_decl
name|void
name|func
parameter_list|(
name|str
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|str
name|ss
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f9122143
parameter_list|()
block|{
name|func
argument_list|(
name|ss
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @f36(double %arg.coerce)
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|v2i32
name|__attribute
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_function
name|v2i32
name|f36
parameter_list|(
name|v2i32
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// AVX: declare void @f38(<8 x float>)
end_comment

begin_comment
comment|// AVX: declare void @f37(<8 x float>)
end_comment

begin_comment
comment|// SSE: declare void @f38(%struct.s256* byval align 32)
end_comment

begin_comment
comment|// SSE: declare void @f37(<8 x float>* byval align 32)
end_comment

begin_typedef
typedef|typedef
name|float
name|__m256
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|__m256
name|m
decl_stmt|;
block|}
name|s256
typedef|;
end_typedef

begin_decl_stmt
name|s256
name|x38
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__m256
name|x37
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|f38
parameter_list|(
name|s256
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f37
parameter_list|(
name|__m256
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f39
parameter_list|()
block|{
name|f38
argument_list|(
name|x38
argument_list|)
expr_stmt|;
name|f37
argument_list|(
name|x37
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// The two next tests make sure that the struct below is passed
end_comment

begin_comment
comment|// in the same way regardless of avx being used
end_comment

begin_comment
comment|// CHECK: declare void @func40(%struct.t128* byval align 16)
end_comment

begin_typedef
typedef|typedef
name|float
name|__m128
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t128
block|{
name|__m128
name|m
decl_stmt|;
name|__m128
name|n
decl_stmt|;
block|}
name|two128
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|func40
parameter_list|(
name|two128
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|func41
parameter_list|(
name|two128
name|s
parameter_list|)
block|{
name|func40
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare void @func42(%struct.t128_2* byval align 16)
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xxx
block|{
name|__m128
name|array
index|[
literal|2
index|]
decl_stmt|;
block|}
name|Atwo128
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t128_2
block|{
name|Atwo128
name|x
decl_stmt|;
block|}
name|SA
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|func42
parameter_list|(
name|SA
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|func43
parameter_list|(
name|SA
name|s
parameter_list|)
block|{
name|func42
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @f44
end_comment

begin_comment
comment|// CHECK: ptrtoint
end_comment

begin_comment
comment|// CHECK-NEXT: add i64 %{{[0-9]+}}, 31
end_comment

begin_comment
comment|// CHECK-NEXT: and i64 %{{[0-9]+}}, -32
end_comment

begin_comment
comment|// CHECK-NEXT: inttoptr
end_comment

begin_typedef
typedef|typedef
name|int
name|T44
name|__attribute
typedef|((
name|vector_size
typedef|(32)));
end_typedef

begin_struct
struct|struct
name|s44
block|{
name|T44
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|f44
parameter_list|(
name|int
name|i
parameter_list|,
modifier|...
parameter_list|)
block|{
name|__builtin_va_list
name|ap
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|ap
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|struct
name|s44
name|s
init|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|s44
argument_list|)
decl_stmt|;
name|__builtin_va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|s
operator|.
name|y
return|;
block|}
end_function

begin_comment
comment|// Text that vec3 returns the correct LLVM IR type.
end_comment

begin_comment
comment|// AVX-LABEL: define i32 @foo(<3 x i64> %X)
end_comment

begin_typedef
typedef|typedef
name|long
name|long3
name|__attribute
typedef|((
name|ext_vector_type
typedef|(3)));
end_typedef

begin_function
name|int
name|foo
parameter_list|(
name|long3
name|X
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Make sure we don't use a varargs convention for a function without a
end_comment

begin_comment
comment|// prototype where AVX types are involved.
end_comment

begin_comment
comment|// AVX: @test45
end_comment

begin_comment
comment|// AVX: call i32 bitcast (i32 (...)* @f45 to i32 (<8 x float>)*)
end_comment

begin_function_decl
name|int
name|f45
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|__m256
name|x45
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test45
parameter_list|()
block|{
name|f45
argument_list|(
name|x45
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Make sure we use byval to pass 64-bit vectors in memory; the LLVM call
end_comment

begin_comment
comment|// lowering can't handle this case correctly because it runs after legalization.
end_comment

begin_comment
comment|// CHECK: @test46
end_comment

begin_comment
comment|// CHECK: call void @f46({{.*}}<2 x float>* byval align 8 {{.*}},<2 x float>* byval align 8 {{.*}})
end_comment

begin_typedef
typedef|typedef
name|float
name|v46
name|__attribute
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_function_decl
name|void
name|f46
parameter_list|(
name|v46
parameter_list|,
name|v46
parameter_list|,
name|v46
parameter_list|,
name|v46
parameter_list|,
name|v46
parameter_list|,
name|v46
parameter_list|,
name|v46
parameter_list|,
name|v46
parameter_list|,
name|v46
parameter_list|,
name|v46
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test46
parameter_list|()
block|{
name|v46
name|x
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
name|f46
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
name|x
argument_list|,
name|x
argument_list|,
name|x
argument_list|,
name|x
argument_list|,
name|x
argument_list|,
name|x
argument_list|,
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Check that we pass the struct below without using byval, which helps out
end_comment

begin_comment
comment|// codegen.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: @test47
end_comment

begin_comment
comment|// CHECK: call void @f47(i32 {{.*}}, i32 {{.*}}, i32 {{.*}}, i32 {{.*}}, i32 {{.*}}, i32 {{.*}}, i32 {{.*}})
end_comment

begin_struct
struct|struct
name|s47
block|{
name|unsigned
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|f47
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|s47
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test47
parameter_list|(
name|int
name|a
parameter_list|,
name|struct
name|s47
name|b
parameter_list|)
block|{
name|f47
argument_list|(
name|a
argument_list|,
name|a
argument_list|,
name|a
argument_list|,
name|a
argument_list|,
name|a
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://12723368
end_comment

begin_comment
comment|// In the following example, there are holes in T4 at the 3rd byte and the 4th
end_comment

begin_comment
comment|// byte, however, T2 does not have those holes. T4 is chosen to be the
end_comment

begin_comment
comment|// representing type for union T1, but we can't use load or store of T4 since
end_comment

begin_comment
comment|// it will skip the 3rd byte and the 4th byte.
end_comment

begin_comment
comment|// In general, Since we don't accurately represent the data fields of a union,
end_comment

begin_comment
comment|// do not use load or store of the representing llvm type for the union.
end_comment

begin_typedef
typedef|typedef
specifier|_Complex
name|int
name|T2
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|_Complex
name|char
name|T5
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|_Complex
name|int
name|T7
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|T4
block|{
name|T5
name|field0
decl_stmt|;
name|T7
name|field1
decl_stmt|;
block|}
name|T4
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|T1
block|{
name|T2
name|field0
decl_stmt|;
name|T4
name|field1
decl_stmt|;
block|}
name|T1
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|T1
name|T1_retval
decl_stmt|;
end_decl_stmt

begin_function
name|T1
name|test48
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: @test48
comment|// CHECK: memcpy
comment|// CHECK: memcpy
return|return
name|T1_retval
return|;
block|}
end_function

begin_function_decl
name|void
name|test49_helper
parameter_list|(
name|double
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test49
parameter_list|(
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|)
block|{
name|test49_helper
argument_list|(
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL:    define void @test49(
end_comment

begin_comment
comment|// CHECK:      [[T0:%.*]] = load double, double*
end_comment

begin_comment
comment|// CHECK-NEXT: [[T1:%.*]] = load double, double*
end_comment

begin_comment
comment|// CHECK-NEXT: call void (double, ...) @test49_helper(double [[T0]], double [[T1]])
end_comment

begin_function_decl
name|void
name|test50_helper
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test50
parameter_list|(
name|double
name|d
parameter_list|,
name|double
name|e
parameter_list|)
block|{
name|test50_helper
argument_list|(
name|d
argument_list|,
name|e
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL:    define void @test50(
end_comment

begin_comment
comment|// CHECK:      [[T0:%.*]] = load double, double*
end_comment

begin_comment
comment|// CHECK-NEXT: [[T1:%.*]] = load double, double*
end_comment

begin_comment
comment|// CHECK-NEXT: call void (double, double, ...) bitcast (void (...)* @test50_helper to void (double, double, ...)*)(double [[T0]], double [[T1]])
end_comment

begin_struct
struct|struct
name|test51_s
block|{
name|__uint128_t
name|intval
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test51
parameter_list|(
name|struct
name|test51_s
modifier|*
name|s
parameter_list|,
name|__builtin_va_list
name|argList
parameter_list|)
block|{
operator|*
name|s
operator|=
name|__builtin_va_arg
argument_list|(
name|argList
argument_list|,
expr|struct
name|test51_s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test51
end_comment

begin_comment
comment|// CHECK: [[TMP_ADDR:%.*]] = alloca [[STRUCT_TEST51:%.*]], align 16
end_comment

begin_comment
comment|// CHECK: br i1
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%.*]] = getelementptr inbounds {{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK-NEXT: [[REG_SAVE_AREA:%.*]] = load i8*, i8** [[REG_SAVE_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-NEXT: [[VALUE_ADDR:%.*]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i32 {{.*}}
end_comment

begin_comment
comment|// CHECK-NEXT: [[CASTED_VALUE_ADDR:%.*]] = bitcast i8* [[VALUE_ADDR]] to [[STRUCT_TEST51]]
end_comment

begin_comment
comment|// CHECK-NEXT: [[CASTED_TMP_ADDR:%.*]] = bitcast [[STRUCT_TEST51]]* [[TMP_ADDR]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: [[RECASTED_VALUE_ADDR:%.*]] = bitcast [[STRUCT_TEST51]]* [[CASTED_VALUE_ADDR]] to i8*
end_comment

begin_comment
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[CASTED_TMP_ADDR]], i8* [[RECASTED_VALUE_ADDR]], i64 16, i32 8, i1 false)
end_comment

begin_comment
comment|// CHECK-NEXT: add i32 {{.*}}, 16
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 {{.*}}, i32* {{.*}}
end_comment

begin_comment
comment|// CHECK-NEXT: br label
end_comment

begin_function_decl
name|void
name|test52_helper
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__m256
name|x52
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test52
parameter_list|()
block|{
name|test52_helper
argument_list|(
literal|0
argument_list|,
name|x52
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// AVX: @test52_helper(i32 0,<8 x float> {{%[a-zA-Z0-9]+}}, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double {{%[a-zA-Z0-9]+}}, double {{%[a-zA-Z0-9]+}})
end_comment

begin_function
name|void
name|test53
parameter_list|(
name|__m256
modifier|*
name|m
parameter_list|,
name|__builtin_va_list
name|argList
parameter_list|)
block|{
operator|*
name|m
operator|=
name|__builtin_va_arg
argument_list|(
name|argList
argument_list|,
name|__m256
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// AVX-LABEL: define void @test53
end_comment

begin_comment
comment|// AVX-NOT: br i1
end_comment

begin_comment
comment|// AVX: ret void
end_comment

begin_function_decl
name|void
name|test54_helper
parameter_list|(
name|__m256
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__m256
name|x54
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test54
parameter_list|()
block|{
name|test54_helper
argument_list|(
name|x54
argument_list|,
name|x54
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0i
argument_list|)
expr_stmt|;
name|test54_helper
argument_list|(
name|x54
argument_list|,
name|x54
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// AVX: @test54_helper(<8 x float> {{%[a-zA-Z0-9]+}},<8 x float> {{%[a-zA-Z0-9]+}}, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double {{%[a-zA-Z0-9]+}}, double {{%[a-zA-Z0-9]+}})
end_comment

begin_comment
comment|// AVX: @test54_helper(<8 x float> {{%[a-zA-Z0-9]+}},<8 x float> {{%[a-zA-Z0-9]+}}, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, { double, double }* byval align 8 {{%[^)]+}})
end_comment

begin_typedef
typedef|typedef
name|float
name|__m512
name|__attribute__
typedef|((
name|__vector_size__
typedef|(64)));
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|__m512
name|m
decl_stmt|;
block|}
name|s512
typedef|;
end_typedef

begin_decl_stmt
name|s512
name|x55
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__m512
name|x56
decl_stmt|;
end_decl_stmt

begin_comment
comment|// On AVX512, aggregates which contain a __m512 type are classified as SSE/SSEUP
end_comment

begin_comment
comment|// as per https://github.com/hjl-tools/x86-psABI/commit/30f9c9 3.2.3p2 Rule 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// AVX512: declare void @f55(<16 x float>)
end_comment

begin_comment
comment|// NO-AVX512: declare void @f55(%struct.s512* byval align 64)
end_comment

begin_function_decl
name|void
name|f55
parameter_list|(
name|s512
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// __m512 has type SSE/SSEUP on AVX512.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// AVX512: declare void @f56(<16 x float>)
end_comment

begin_comment
comment|// NO-AVX512: declare void @f56(<16 x float>* byval align 64)
end_comment

begin_function_decl
name|void
name|f56
parameter_list|(
name|__m512
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f57
parameter_list|()
block|{
name|f55
argument_list|(
name|x55
argument_list|)
expr_stmt|;
name|f56
argument_list|(
name|x56
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Like for __m128 on AVX, check that the struct below is passed
end_comment

begin_comment
comment|// in the same way regardless of AVX512 being used.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: declare void @f58(%struct.t256* byval align 32)
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t256
block|{
name|__m256
name|m
decl_stmt|;
name|__m256
name|n
decl_stmt|;
block|}
name|two256
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|f58
parameter_list|(
name|two256
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f59
parameter_list|(
name|two256
name|s
parameter_list|)
block|{
name|f58
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare void @f60(%struct.sat256* byval align 32)
end_comment

begin_typedef
typedef|typedef
struct|struct
name|at256
block|{
name|__m256
name|array
index|[
literal|2
index|]
decl_stmt|;
block|}
name|Atwo256
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|sat256
block|{
name|Atwo256
name|x
decl_stmt|;
block|}
name|SAtwo256
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|f60
parameter_list|(
name|SAtwo256
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f61
parameter_list|(
name|SAtwo256
name|s
parameter_list|)
block|{
name|f60
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// AVX512: @f62_helper(i32 0,<16 x float> {{%[a-zA-Z0-9]+}}, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double {{%[a-zA-Z0-9]+}}, double {{%[a-zA-Z0-9]+}})
end_comment

begin_function_decl
name|void
name|f62_helper
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__m512
name|x62
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f62
parameter_list|()
block|{
name|f62_helper
argument_list|(
literal|0
argument_list|,
name|x62
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Like for __m256 on AVX, we always pass __m512 in memory, and don't
end_comment

begin_comment
comment|// need to use the register save area.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// AVX512-LABEL: define void @f63
end_comment

begin_comment
comment|// AVX512-NOT: br i1
end_comment

begin_comment
comment|// AVX512: ret void
end_comment

begin_function
name|void
name|f63
parameter_list|(
name|__m512
modifier|*
name|m
parameter_list|,
name|__builtin_va_list
name|argList
parameter_list|)
block|{
operator|*
name|m
operator|=
name|__builtin_va_arg
argument_list|(
name|argList
argument_list|,
name|__m512
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// AVX512: @f64_helper(<16 x float> {{%[a-zA-Z0-9]+}},<16 x float> {{%[a-zA-Z0-9]+}}, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double {{%[a-zA-Z0-9]+}}, double {{%[a-zA-Z0-9]+}})
end_comment

begin_comment
comment|// AVX512: @f64_helper(<16 x float> {{%[a-zA-Z0-9]+}},<16 x float> {{%[a-zA-Z0-9]+}}, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, { double, double }* byval align 8 {{%[^)]+}})
end_comment

begin_function_decl
name|void
name|f64_helper
parameter_list|(
name|__m512
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__m512
name|x64
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f64
parameter_list|()
block|{
name|f64_helper
argument_list|(
name|x64
argument_list|,
name|x64
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0i
argument_list|)
expr_stmt|;
name|f64_helper
argument_list|(
name|x64
argument_list|,
name|x64
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0
argument_list|,
literal|1.0i
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|t65
block|{
name|__m256
name|m
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// SSE-LABEL: @f65(%struct.t65* byval align 32 %{{[^,)]+}})
end_comment

begin_comment
comment|// AVX: @f65(<8 x float> %{{[^,)]+}})
end_comment

begin_function
name|void
name|f65
parameter_list|(
name|struct
name|t65
name|a0
parameter_list|)
block|{ }
end_function

end_unit

