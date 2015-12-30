begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7k-apple-watchos2.0 -target-abi aapcs16 -target-cpu cortex-a7 %s -o - -emit-llvm | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// Make sure 64 and 128 bit types are naturally aligned by the v7k ABI:
end_comment

begin_comment
comment|// CHECK: target datalayout = "e-m:o-p:32:32-i64:64-a:0:32-n32-S128"
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|arr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|HFA
typedef|;
end_typedef

begin_comment
comment|// CHECK: define void @simple_hfa([4 x float] %h.coerce)
end_comment

begin_function
name|void
name|simple_hfa
parameter_list|(
name|HFA
name|h
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define %struct.HFA @return_simple_hfa
end_comment

begin_function
name|HFA
name|return_simple_hfa
parameter_list|()
block|{}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|arr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|BigHFA
typedef|;
end_typedef

begin_comment
comment|// We don't want any padding type to be included by Clang when using the
end_comment

begin_comment
comment|// APCS-VFP ABI, that needs to be handled by LLVM if needed.
end_comment

begin_comment
comment|// CHECK: void @no_padding(i32 %r0, i32 %r1, i32 %r2, [4 x double] %d0_d3.coerce, [4 x double] %d4_d7.coerce, [4 x double] %sp.coerce, i64 %split)
end_comment

begin_function
name|void
name|no_padding
parameter_list|(
name|int
name|r0
parameter_list|,
name|int
name|r1
parameter_list|,
name|int
name|r2
parameter_list|,
name|BigHFA
name|d0_d3
parameter_list|,
name|BigHFA
name|d4_d7
parameter_list|,
name|BigHFA
name|sp
parameter_list|,
name|long
name|long
name|split
parameter_list|)
block|{}
end_function

begin_comment
comment|// Structs larger than 16 bytes should be passed indirectly in space allocated
end_comment

begin_comment
comment|// by the caller (a pointer to this storage should be what occurs in the arg
end_comment

begin_comment
comment|// list).
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|;
name|long
name|long
name|y
decl_stmt|;
name|double
name|z
decl_stmt|;
block|}
name|BigStruct
typedef|;
end_typedef

begin_comment
comment|// CHECK: define void @big_struct_indirect(%struct.BigStruct* %b)
end_comment

begin_function
name|void
name|big_struct_indirect
parameter_list|(
name|BigStruct
name|b
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @return_big_struct_indirect(%struct.BigStruct* noalias sret
end_comment

begin_function
name|BigStruct
name|return_big_struct_indirect
parameter_list|()
block|{}
end_function

begin_comment
comment|// Structs smaller than 16 bytes should be passed directly, and coerced to
end_comment

begin_comment
comment|// either [N x i32] or [N x i64] depending on alignment requirements.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|double
name|z
decl_stmt|;
block|}
name|SmallStruct
typedef|;
end_typedef

begin_comment
comment|// CHECK: define void @small_struct_direct([2 x i64] %s.coerce)
end_comment

begin_function
name|void
name|small_struct_direct
parameter_list|(
name|SmallStruct
name|s
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define [4 x i32] @return_small_struct_direct()
end_comment

begin_function
name|SmallStruct
name|return_small_struct_direct
parameter_list|()
block|{}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|z
decl_stmt|;
block|}
name|SmallStructSmallAlign
typedef|;
end_typedef

begin_comment
comment|// CHECK: define void @small_struct_align_direct([3 x i32] %s.coerce)
end_comment

begin_function
name|void
name|small_struct_align_direct
parameter_list|(
name|SmallStructSmallAlign
name|s
parameter_list|)
block|{}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|x
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|PaddedSmallStruct
typedef|;
end_typedef

begin_comment
comment|// CHECK: define i32 @return_padded_small_struct()
end_comment

begin_function
name|PaddedSmallStruct
name|return_padded_small_struct
parameter_list|()
block|{}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|arr
index|[
literal|7
index|]
decl_stmt|;
block|}
name|OddlySizedStruct
typedef|;
end_typedef

begin_comment
comment|// CHECK: define [2 x i32] @return_oddly_sized_struct()
end_comment

begin_function
name|OddlySizedStruct
name|return_oddly_sized_struct
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: define<4 x float> @test_va_arg_vec(i8* %l)
end_comment

begin_comment
comment|// CHECK:   [[ALIGN_TMP:%.*]] = add i32 {{%.*}}, 15
end_comment

begin_comment
comment|// CHECK:   [[ALIGNED:%.*]] = and i32 [[ALIGN_TMP]], -16
end_comment

begin_comment
comment|// CHECK:   [[ALIGNED_I8:%.*]] = inttoptr i32 [[ALIGNED]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[ALIGNED_VEC:%.*]] = bitcast i8* [[ALIGNED_I8]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   load<4 x float>,<4 x float>* [[ALIGNED_VEC]], align 16
end_comment

begin_function
name|float32x4_t
name|test_va_arg_vec
parameter_list|(
name|__builtin_va_list
name|l
parameter_list|)
block|{
return|return
name|__builtin_va_arg
argument_list|(
name|l
argument_list|,
name|float32x4_t
argument_list|)
return|;
block|}
end_function

end_unit

