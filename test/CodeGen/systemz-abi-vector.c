begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-feature +vector \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck --check-prefix=CHECK-VECTOR %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu z13 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck --check-prefix=CHECK-VECTOR %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu arch11 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck --check-prefix=CHECK-VECTOR %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu z14 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck --check-prefix=CHECK-VECTOR %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu arch12 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck --check-prefix=CHECK-VECTOR %s
end_comment

begin_comment
comment|// Vector types
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|1
argument|))
argument_list|)
name|char
name|v1i8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|2
argument|))
argument_list|)
name|char
name|v2i8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|2
argument|))
argument_list|)
name|short
name|v1i16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|char
name|v4i8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|short
name|v2i16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|int
name|v1i32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|float
name|v1f32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|char
name|v8i8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|short
name|v4i16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|int
name|v2i32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|long
name|long
name|v1i64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|float
name|v2f32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|double
name|v1f64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|char
name|v16i8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|short
name|v8i16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|int
name|v4i32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|long
name|long
name|v2i64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|__int128
name|v1i128
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|float
name|v4f32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|double
name|v2f64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|long
name|double
name|v1f128
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|32
argument|))
argument_list|)
name|char
name|v32i8
typedef|;
end_typedef

begin_decl_stmt
name|unsigned
name|int
name|align
init|=
name|__alignof__
argument_list|(
name|v16i8
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @align = global i32 16
end_comment

begin_comment
comment|// CHECK-VECTOR: @align = global i32 8
end_comment

begin_function
name|v1i8
name|pass_v1i8
parameter_list|(
name|v1i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v1i8(<1 x i8>* noalias sret %{{.*}},<1 x i8>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<1 x i8> @pass_v1i8(<1 x i8> %{{.*}})
end_comment

begin_function
name|v2i8
name|pass_v2i8
parameter_list|(
name|v2i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v2i8(<2 x i8>* noalias sret %{{.*}},<2 x i8>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<2 x i8> @pass_v2i8(<2 x i8> %{{.*}})
end_comment

begin_function
name|v4i8
name|pass_v4i8
parameter_list|(
name|v4i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v4i8(<4 x i8>* noalias sret %{{.*}},<4 x i8>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<4 x i8> @pass_v4i8(<4 x i8> %{{.*}})
end_comment

begin_function
name|v8i8
name|pass_v8i8
parameter_list|(
name|v8i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v8i8(<8 x i8>* noalias sret %{{.*}},<8 x i8>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<8 x i8> @pass_v8i8(<8 x i8> %{{.*}})
end_comment

begin_function
name|v16i8
name|pass_v16i8
parameter_list|(
name|v16i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v16i8(<16 x i8>* noalias sret %{{.*}},<16 x i8>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<16 x i8> @pass_v16i8(<16 x i8> %{{.*}})
end_comment

begin_function
name|v32i8
name|pass_v32i8
parameter_list|(
name|v32i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v32i8(<32 x i8>* noalias sret %{{.*}},<32 x i8>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_v32i8(<32 x i8>* noalias sret %{{.*}},<32 x i8>*)
end_comment

begin_function
name|v1i16
name|pass_v1i16
parameter_list|(
name|v1i16
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v1i16(<1 x i16>* noalias sret %{{.*}},<1 x i16>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<1 x i16> @pass_v1i16(<1 x i16> %{{.*}})
end_comment

begin_function
name|v2i16
name|pass_v2i16
parameter_list|(
name|v2i16
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v2i16(<2 x i16>* noalias sret %{{.*}},<2 x i16>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<2 x i16> @pass_v2i16(<2 x i16> %{{.*}})
end_comment

begin_function
name|v4i16
name|pass_v4i16
parameter_list|(
name|v4i16
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v4i16(<4 x i16>* noalias sret %{{.*}},<4 x i16>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<4 x i16> @pass_v4i16(<4 x i16> %{{.*}})
end_comment

begin_function
name|v8i16
name|pass_v8i16
parameter_list|(
name|v8i16
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v8i16(<8 x i16>* noalias sret %{{.*}},<8 x i16>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<8 x i16> @pass_v8i16(<8 x i16> %{{.*}})
end_comment

begin_function
name|v1i32
name|pass_v1i32
parameter_list|(
name|v1i32
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v1i32(<1 x i32>* noalias sret %{{.*}},<1 x i32>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<1 x i32> @pass_v1i32(<1 x i32> %{{.*}})
end_comment

begin_function
name|v2i32
name|pass_v2i32
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
comment|// CHECK-LABEL: define void @pass_v2i32(<2 x i32>* noalias sret %{{.*}},<2 x i32>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<2 x i32> @pass_v2i32(<2 x i32> %{{.*}})
end_comment

begin_function
name|v4i32
name|pass_v4i32
parameter_list|(
name|v4i32
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v4i32(<4 x i32>* noalias sret %{{.*}},<4 x i32>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<4 x i32> @pass_v4i32(<4 x i32> %{{.*}})
end_comment

begin_function
name|v1i64
name|pass_v1i64
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
comment|// CHECK-LABEL: define void @pass_v1i64(<1 x i64>* noalias sret %{{.*}},<1 x i64>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<1 x i64> @pass_v1i64(<1 x i64> %{{.*}})
end_comment

begin_function
name|v2i64
name|pass_v2i64
parameter_list|(
name|v2i64
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v2i64(<2 x i64>* noalias sret %{{.*}},<2 x i64>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<2 x i64> @pass_v2i64(<2 x i64> %{{.*}})
end_comment

begin_function
name|v1i128
name|pass_v1i128
parameter_list|(
name|v1i128
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v1i128(<1 x i128>* noalias sret %{{.*}},<1 x i128>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<1 x i128> @pass_v1i128(<1 x i128> %{{.*}})
end_comment

begin_function
name|v1f32
name|pass_v1f32
parameter_list|(
name|v1f32
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v1f32(<1 x float>* noalias sret %{{.*}},<1 x float>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<1 x float> @pass_v1f32(<1 x float> %{{.*}})
end_comment

begin_function
name|v2f32
name|pass_v2f32
parameter_list|(
name|v2f32
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v2f32(<2 x float>* noalias sret %{{.*}},<2 x float>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<2 x float> @pass_v2f32(<2 x float> %{{.*}})
end_comment

begin_function
name|v4f32
name|pass_v4f32
parameter_list|(
name|v4f32
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v4f32(<4 x float>* noalias sret %{{.*}},<4 x float>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<4 x float> @pass_v4f32(<4 x float> %{{.*}})
end_comment

begin_function
name|v1f64
name|pass_v1f64
parameter_list|(
name|v1f64
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v1f64(<1 x double>* noalias sret %{{.*}},<1 x double>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<1 x double> @pass_v1f64(<1 x double> %{{.*}})
end_comment

begin_function
name|v2f64
name|pass_v2f64
parameter_list|(
name|v2f64
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v2f64(<2 x double>* noalias sret %{{.*}},<2 x double>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<2 x double> @pass_v2f64(<2 x double> %{{.*}})
end_comment

begin_function
name|v1f128
name|pass_v1f128
parameter_list|(
name|v1f128
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_v1f128(<1 x fp128>* noalias sret %{{.*}},<1 x fp128>*)
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<1 x fp128> @pass_v1f128(<1 x fp128> %{{.*}})
end_comment

begin_comment
comment|// Vector-like aggregate types
end_comment

begin_struct
struct|struct
name|agg_v1i8
block|{
name|v1i8
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_v1i8
name|pass_agg_v1i8
parameter_list|(
name|struct
name|agg_v1i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_v1i8(%struct.agg_v1i8* noalias sret %{{.*}}, i8 %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_v1i8(%struct.agg_v1i8* noalias sret %{{.*}},<1 x i8> %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_v2i8
block|{
name|v2i8
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_v2i8
name|pass_agg_v2i8
parameter_list|(
name|struct
name|agg_v2i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_v2i8(%struct.agg_v2i8* noalias sret %{{.*}}, i16 %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_v2i8(%struct.agg_v2i8* noalias sret %{{.*}},<2 x i8> %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_v4i8
block|{
name|v4i8
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_v4i8
name|pass_agg_v4i8
parameter_list|(
name|struct
name|agg_v4i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_v4i8(%struct.agg_v4i8* noalias sret %{{.*}}, i32 %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_v4i8(%struct.agg_v4i8* noalias sret %{{.*}},<4 x i8> %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_v8i8
block|{
name|v8i8
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_v8i8
name|pass_agg_v8i8
parameter_list|(
name|struct
name|agg_v8i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_v8i8(%struct.agg_v8i8* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_v8i8(%struct.agg_v8i8* noalias sret %{{.*}},<8 x i8> %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_v16i8
block|{
name|v16i8
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_v16i8
name|pass_agg_v16i8
parameter_list|(
name|struct
name|agg_v16i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_v16i8(%struct.agg_v16i8* noalias sret %{{.*}}, %struct.agg_v16i8* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_v16i8(%struct.agg_v16i8* noalias sret %{{.*}},<16 x i8> %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_v32i8
block|{
name|v32i8
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_v32i8
name|pass_agg_v32i8
parameter_list|(
name|struct
name|agg_v32i8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_v32i8(%struct.agg_v32i8* noalias sret %{{.*}}, %struct.agg_v32i8* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_v32i8(%struct.agg_v32i8* noalias sret %{{.*}}, %struct.agg_v32i8* %{{.*}})
end_comment

begin_comment
comment|// Verify that the following are *not* vector-like aggregate types
end_comment

begin_struct
struct|struct
name|agg_novector1
block|{
name|v4i8
name|a
decl_stmt|;
name|v4i8
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_novector1
name|pass_agg_novector1
parameter_list|(
name|struct
name|agg_novector1
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_novector1(%struct.agg_novector1* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_novector1(%struct.agg_novector1* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_novector2
block|{
name|v4i8
name|a
decl_stmt|;
name|float
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_novector2
name|pass_agg_novector2
parameter_list|(
name|struct
name|agg_novector2
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_novector2(%struct.agg_novector2* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_novector2(%struct.agg_novector2* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_novector3
block|{
name|v4i8
name|a
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_novector3
name|pass_agg_novector3
parameter_list|(
name|struct
name|agg_novector3
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_novector3(%struct.agg_novector3* noalias sret %{{.*}}, i32 %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_novector3(%struct.agg_novector3* noalias sret %{{.*}}, i32 %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_novector4
block|{
name|v4i8
name|a
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_novector4
name|pass_agg_novector4
parameter_list|(
name|struct
name|agg_novector4
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_novector4(%struct.agg_novector4* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @pass_agg_novector4(%struct.agg_novector4* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_comment
comment|// Accessing variable argument lists
end_comment

begin_function
name|v1i8
name|va_v1i8
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
name|v1i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_v1i8(<1 x i8>* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to<1 x i8>**
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to<1 x i8>**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi<1 x i8>** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load<1 x i8>*,<1 x i8>** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<1 x i8> @va_v1i8(%struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to<1 x i8>*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[RET:%[^ ]+]] = load<1 x i8>,<1 x i8>* [[MEM_ADDR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret<1 x i8> [[RET]]
end_comment

begin_function
name|v2i8
name|va_v2i8
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
name|v2i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_v2i8(<2 x i8>* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to<2 x i8>**
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to<2 x i8>**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi<2 x i8>** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load<2 x i8>*,<2 x i8>** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<2 x i8> @va_v2i8(%struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to<2 x i8>*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[RET:%[^ ]+]] = load<2 x i8>,<2 x i8>* [[MEM_ADDR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret<2 x i8> [[RET]]
end_comment

begin_function
name|v4i8
name|va_v4i8
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
name|v4i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_v4i8(<4 x i8>* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to<4 x i8>**
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to<4 x i8>**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi<4 x i8>** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load<4 x i8>*,<4 x i8>** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<4 x i8> @va_v4i8(%struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to<4 x i8>*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[RET:%[^ ]+]] = load<4 x i8>,<4 x i8>* [[MEM_ADDR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret<4 x i8> [[RET]]
end_comment

begin_function
name|v8i8
name|va_v8i8
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
name|v8i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_v8i8(<8 x i8>* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to<8 x i8>**
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to<8 x i8>**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi<8 x i8>** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load<8 x i8>*,<8 x i8>** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<8 x i8> @va_v8i8(%struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[RET:%[^ ]+]] = load<8 x i8>,<8 x i8>* [[MEM_ADDR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret<8 x i8> [[RET]]
end_comment

begin_function
name|v16i8
name|va_v16i8
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
name|v16i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_v16i8(<16 x i8>* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to<16 x i8>**
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to<16 x i8>**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi<16 x i8>** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load<16 x i8>*,<16 x i8>** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define<16 x i8> @va_v16i8(%struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 16
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[RET:%[^ ]+]] = load<16 x i8>,<16 x i8>* [[MEM_ADDR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret<16 x i8> [[RET]]
end_comment

begin_function
name|v32i8
name|va_v32i8
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
name|v32i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_v32i8(<32 x i8>* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to<32 x i8>**
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to<32 x i8>**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi<32 x i8>** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load<32 x i8>*,<32 x i8>** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @va_v32i8(<32 x i8>* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK-VECTOR: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK-VECTOR: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to<32 x i8>**
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK-VECTOR: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to<32 x i8>**
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[VA_ARG_ADDR:%[^ ]+]] = phi<32 x i8>** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[INDIRECT_ARG:%[^ ]+]] = load<32 x i8>*,<32 x i8>** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret void
end_comment

begin_function
name|struct
name|agg_v1i8
name|va_agg_v1i8
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
expr|struct
name|agg_v1i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_v1i8(%struct.agg_v1i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 23
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_v1i8*
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 7
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_v1i8*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_v1i8* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @va_agg_v1i8(%struct.agg_v1i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to %struct.agg_v1i8*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret void
end_comment

begin_function
name|struct
name|agg_v2i8
name|va_agg_v2i8
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
expr|struct
name|agg_v2i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_v2i8(%struct.agg_v2i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 22
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_v2i8*
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 6
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_v2i8*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_v2i8* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @va_agg_v2i8(%struct.agg_v2i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to %struct.agg_v2i8*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret void
end_comment

begin_function
name|struct
name|agg_v4i8
name|va_agg_v4i8
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
expr|struct
name|agg_v4i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_v4i8(%struct.agg_v4i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 20
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_v4i8*
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 4
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_v4i8*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_v4i8* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @va_agg_v4i8(%struct.agg_v4i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to %struct.agg_v4i8*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret void
end_comment

begin_function
name|struct
name|agg_v8i8
name|va_agg_v8i8
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
expr|struct
name|agg_v8i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_v8i8(%struct.agg_v8i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_v8i8*
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_v8i8*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_v8i8* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @va_agg_v8i8(%struct.agg_v8i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to %struct.agg_v8i8*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret void
end_comment

begin_function
name|struct
name|agg_v16i8
name|va_agg_v16i8
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
expr|struct
name|agg_v16i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_v16i8(%struct.agg_v16i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_v16i8**
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_v16i8**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_v16i8** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load %struct.agg_v16i8*, %struct.agg_v16i8** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @va_agg_v16i8(%struct.agg_v16i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[OVERFLOW_ARG_AREA]] to %struct.agg_v16i8*
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA1:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 16
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA1]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret void
end_comment

begin_function
name|struct
name|agg_v32i8
name|va_agg_v32i8
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
expr|struct
name|agg_v32i8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_v32i8(%struct.agg_v32i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_v32i8**
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_v32i8**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_v32i8** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load %struct.agg_v32i8*, %struct.agg_v32i8** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK-VECTOR-LABEL: define void @va_agg_v32i8(%struct.agg_v32i8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 0
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 5
end_comment

begin_comment
comment|// CHECK-VECTOR: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK-VECTOR: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 16
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_SAVE_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 3
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_SAVE_AREA:%[^ ]+]] = load i8*, i8** [[REG_SAVE_AREA_PTR:[^ ]+]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[RAW_REG_ADDR:%[^ ]+]] = getelementptr i8, i8* [[REG_SAVE_AREA]], i64 [[REG_OFFSET]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_v32i8**
end_comment

begin_comment
comment|// CHECK-VECTOR: [[REG_COUNT1:%[^ ]+]] = add i64 [[REG_COUNT]], 1
end_comment

begin_comment
comment|// CHECK-VECTOR: store i64 [[REG_COUNT1]], i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 2
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA:%[^ ]+]] = load i8*, i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[RAW_MEM_ADDR:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 0
end_comment

begin_comment
comment|// CHECK-VECTOR: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_v32i8**
end_comment

begin_comment
comment|// CHECK-VECTOR: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK-VECTOR: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_v32i8** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK-VECTOR: [[INDIRECT_ARG:%[^ ]+]] = load %struct.agg_v32i8*, %struct.agg_v32i8** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK-VECTOR: ret void
end_comment

end_unit

