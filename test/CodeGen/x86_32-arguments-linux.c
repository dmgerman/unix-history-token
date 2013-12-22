begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -fblocks -triple i386-pc-linux-gnu -target-cpu pentium4 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f56(
end_comment

begin_comment
comment|// CHECK: i8 signext %a0, %struct.s56_0* byval align 4 %a1,
end_comment

begin_comment
comment|// CHECK: i64 %a2.coerce, %struct.s56_1* byval align 4,
end_comment

begin_comment
comment|// CHECK:<1 x double> %a4, %struct.s56_2* byval align 4,
end_comment

begin_comment
comment|// CHECK:<4 x i32> %a6, %struct.s56_3* byval align 4,
end_comment

begin_comment
comment|// CHECK:<2 x double> %a8, %struct.s56_4* byval align 4,
end_comment

begin_comment
comment|// CHECK:<8 x i32> %a10, %struct.s56_5* byval align 4,
end_comment

begin_comment
comment|// CHECK:<4 x double> %a12, %struct.s56_6* byval align 4)
end_comment

begin_comment
comment|// CHECK: call void (i32, ...)* @f56_0(i32 1,
end_comment

begin_comment
comment|// CHECK: i32 %{{.*}}, %struct.s56_0* byval align 4 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK: i64 %{{[^ ]*}}, %struct.s56_1* byval align 4 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK:<1 x double> %{{[^ ]*}}, %struct.s56_2* byval align 4 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK:<4 x i32> %{{[^ ]*}}, %struct.s56_3* byval align 4 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK:<2 x double> %{{[^ ]*}}, %struct.s56_4* byval align 4 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK:<8 x i32> %{{[^ ]*}}, %struct.s56_5* byval align 4 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK:<4 x double> %{{[^ ]*}}, %struct.s56_6* byval align 4 %{{[^ ]*}})
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<rdar://problem/7964854> [i386] clang misaligns long double in structures
end_comment

begin_comment
comment|// when passed byval
end_comment

begin_comment
comment|//<rdar://problem/8431367> clang misaligns parameters on stack
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|t56_v2i
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|t56_v1d
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|t56_v4i
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|t56_v2d
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
name|t56_v8i
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
name|t56_v4d
typedef|;
end_typedef

begin_struct
struct|struct
name|s56_0
block|{
name|char
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_1
block|{
name|t56_v2i
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_2
block|{
name|t56_v1d
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_3
block|{
name|t56_v4i
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_4
block|{
name|t56_v2d
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_5
block|{
name|t56_v8i
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_6
block|{
name|t56_v4d
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f56
parameter_list|(
name|char
name|a0
parameter_list|,
name|struct
name|s56_0
name|a1
parameter_list|,
name|t56_v2i
name|a2
parameter_list|,
name|struct
name|s56_1
name|a3
parameter_list|,
name|t56_v1d
name|a4
parameter_list|,
name|struct
name|s56_2
name|a5
parameter_list|,
name|t56_v4i
name|a6
parameter_list|,
name|struct
name|s56_3
name|a7
parameter_list|,
name|t56_v2d
name|a8
parameter_list|,
name|struct
name|s56_4
name|a9
parameter_list|,
name|t56_v8i
name|a10
parameter_list|,
name|struct
name|s56_5
name|a11
parameter_list|,
name|t56_v4d
name|a12
parameter_list|,
name|struct
name|s56_6
name|a13
parameter_list|)
block|{
specifier|extern
name|void
name|f56_0
argument_list|(
name|int
name|x
argument_list|,
operator|...
argument_list|)
decl_stmt|;
name|f56_0
argument_list|(
literal|1
argument_list|,
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|,
name|a6
argument_list|,
name|a7
argument_list|,
name|a8
argument_list|,
name|a9
argument_list|,
name|a10
argument_list|,
name|a11
argument_list|,
name|a12
argument_list|,
name|a13
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

