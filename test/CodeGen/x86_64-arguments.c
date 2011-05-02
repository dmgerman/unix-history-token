begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s| FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|// CHECK: define signext i8 @f0()
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
comment|// CHECK: define signext i16 @f1()
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
comment|// CHECK: define i32 @f2()
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
comment|// CHECK: define float @f3()
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
comment|// CHECK: define double @f4()
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
comment|// CHECK: define x86_fp80 @f5()
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
comment|// CHECK: define void @f6(i8 signext %a0, i16 signext %a1, i32 %a2, i64 %a3, i8* %a4)
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
comment|// CHECK: define void @f7(i32 %a0)
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
comment|// CHECK: define void @f8_1(%struct.s19* sret %agg.result)
end_comment

begin_comment
comment|// CHECK: define void @f8_2(%struct.s19* byval align 16 %a0)
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
comment|// CHECK: define i64 @f9()
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
comment|// CHECK: define void @f10(i64 %a0.coerce)
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
comment|// CHECK: define void @f11(%struct.s19* sret %agg.result)
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
comment|// CHECK: define i32 @f12_0()
comment|// CHECK: define void @f12_1(i32 %a0.coerce)
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
comment|// CHECK: define void @f13(%struct.s13_0* sret %agg.result, i32 %a, i32 %b, i32 %c, i32 %d, {{.*}}* byval %e, i32 %f)
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
comment|// CHECK: define void @f18(i32 %a, i32 %f18_arg1.coerce)
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
comment|// CHECK: define void @f19(%struct.s19* byval align 16 %x)
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
comment|// CHECK: define void @f20(%struct.s20* byval align 32 %x)
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
comment|// CHECK: define i8* @f21(i64 %S.coerce0, i8* %S.coerce1)
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
comment|// CHECK: define void @f23(i32 %A, i64 %B.coerce0, i32 %B.coerce1)
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
comment|// CHECK: define %struct.f24s @f24(%struct.f23S* %X, %struct.f24s* %P2)
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
comment|// CHECK: define<4 x float> @f25(<4 x float> %X)
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
comment|// CHECK: define %struct.foo26 @f26(%struct.foo26* %P)
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
comment|// CHECK: define<4 x float> @f27(<4 x float> %X.coerce)
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
comment|// CHECK: define void @f28(double %C.coerce0, i32 %C.coerce1)
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
comment|// CHECK: define void @f29a(double %A.coerce0, i32 %A.coerce1)
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
comment|// CHECK: define void @f30(i64 %p_4.coerce0, i24 %p_4.coerce1)
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
comment|// CHECK: define float @f31(<2 x float> %X.coerce0, float %X.coerce1)
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
comment|// CHECK: define<2 x float> @f32(<2 x float> %A.coerce,<2 x float> %B.coerce)
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
comment|// CHECK: define i64 @f34(i64 %arg.coerce)
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
comment|// CHECK: define i64 @f35(i64 %arg.coerce)
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

end_unit

