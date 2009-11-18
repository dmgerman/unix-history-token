begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple x86_64-unknown-unknown -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep 'define signext i8 @f0()' %t
end_comment

begin_comment
comment|// RUN: grep 'define signext i16 @f1()' %t
end_comment

begin_comment
comment|// RUN: grep 'define i32 @f2()' %t
end_comment

begin_comment
comment|// RUN: grep 'define float @f3()' %t
end_comment

begin_comment
comment|// RUN: grep 'define double @f4()' %t
end_comment

begin_comment
comment|// RUN: grep 'define x86_fp80 @f5()' %t
end_comment

begin_comment
comment|// RUN: grep 'define void @f6(i8 signext %a0, i16 signext %a1, i32 %a2, i64 %a3, i8\* %a4)' %t
end_comment

begin_comment
comment|// RUN: grep 'define void @f7(i32 %a0)' %t
end_comment

begin_comment
comment|// RUN: grep '.0 = type { i64, double }' %t
end_comment

begin_comment
comment|// RUN: grep 'define .0 @f8_1()' %t
end_comment

begin_comment
comment|// RUN: grep 'define void @f8_2(.0)' %t
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
name|E
typedef|;
end_typedef

begin_function
name|void
name|f7
parameter_list|(
name|E
name|a0
parameter_list|)
block|{ }
end_function

begin_comment
comment|// Test merging/passing of upper eightbyte with X87 class.
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
comment|// RUN: grep 'define i64 @f9()' %t
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
comment|// RUN: grep 'define void @f10(i64)' %t
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
comment|// RUN: grep 'define void @f11(.union.anon. noalias sret .agg.result)' %t
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
comment|// RUN: grep 'define i64 @f12_0()' %t
comment|// RUN: grep 'define void @f12_1(i64)' %t
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
comment|// RUN: grep 'define void @f13(.struct.s13_0. noalias sret .agg.result, i32 .a, i32 .b, i32 .c, i32 .d, .struct.s13_1. byval .e, i32 .f)' %t
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
comment|// RUN: grep 'define void @f14(.*, i8 signext .X)' %t
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
comment|// RUN: grep 'define void @f15(.*, i8\* .X)' %t
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
comment|// RUN: grep 'define void @f16(.*, float .X)' %t
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
comment|// RUN: grep 'define void @f17(.*, x86_fp80 .X)' %t
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
comment|// Check for valid coercion.
end_comment

begin_comment
comment|// RUN: grep '.. = bitcast i64. .* to .struct.f18_s0.' %t
end_comment

begin_comment
comment|// RUN: grep '.. = load .struct.f18_s0. .., align 1' %t
end_comment

begin_comment
comment|// RUN: grep 'store .struct.f18_s0 .., .struct.f18_s0. .f18_arg1' %t
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

end_unit

