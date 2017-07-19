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
comment|// RUN:   -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu z13 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu arch11 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu z14 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu arch12 \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Scalar types
end_comment

begin_function
name|char
name|pass_char
parameter_list|(
name|char
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define signext i8 @pass_char(i8 signext %{{.*}})
end_comment

begin_function
name|short
name|pass_short
parameter_list|(
name|short
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define signext i16 @pass_short(i16 signext %{{.*}})
end_comment

begin_function
name|int
name|pass_int
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define signext i32 @pass_int(i32 signext %{{.*}})
end_comment

begin_function
name|long
name|pass_long
parameter_list|(
name|long
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @pass_long(i64 %{{.*}})
end_comment

begin_function
name|long
name|long
name|pass_longlong
parameter_list|(
name|long
name|long
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @pass_longlong(i64 %{{.*}})
end_comment

begin_function
name|__int128
name|pass_int128
parameter_list|(
name|__int128
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_int128(i128* noalias sret %{{.*}}, i128*)
end_comment

begin_function
name|float
name|pass_float
parameter_list|(
name|float
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @pass_float(float %{{.*}})
end_comment

begin_function
name|double
name|pass_double
parameter_list|(
name|double
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @pass_double(double %{{.*}})
end_comment

begin_function
name|long
name|double
name|pass_longdouble
parameter_list|(
name|long
name|double
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_longdouble(fp128* noalias sret %{{.*}}, fp128*)
end_comment

begin_comment
comment|// Complex types
end_comment

begin_function
specifier|_Complex
name|char
name|pass_complex_char
parameter_list|(
specifier|_Complex
name|char
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_complex_char({ i8, i8 }* noalias sret %{{.*}}, { i8, i8 }* %{{.*}}arg)
end_comment

begin_function
specifier|_Complex
name|short
name|pass_complex_short
parameter_list|(
specifier|_Complex
name|short
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_complex_short({ i16, i16 }* noalias sret %{{.*}}, { i16, i16 }* %{{.*}}arg)
end_comment

begin_function
specifier|_Complex
name|int
name|pass_complex_int
parameter_list|(
specifier|_Complex
name|int
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_complex_int({ i32, i32 }* noalias sret %{{.*}}, { i32, i32 }* %{{.*}}arg)
end_comment

begin_function
specifier|_Complex
name|long
name|pass_complex_long
parameter_list|(
specifier|_Complex
name|long
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_complex_long({ i64, i64 }* noalias sret %{{.*}}, { i64, i64 }* %{{.*}}arg)
end_comment

begin_function
specifier|_Complex
name|long
name|long
name|pass_complex_longlong
parameter_list|(
specifier|_Complex
name|long
name|long
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_complex_longlong({ i64, i64 }* noalias sret %{{.*}}, { i64, i64 }* %{{.*}}arg)
end_comment

begin_function
specifier|_Complex
name|float
name|pass_complex_float
parameter_list|(
specifier|_Complex
name|float
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_complex_float({ float, float }* noalias sret %{{.*}}, { float, float }* %{{.*}}arg)
end_comment

begin_function
specifier|_Complex
name|double
name|pass_complex_double
parameter_list|(
specifier|_Complex
name|double
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_complex_double({ double, double }* noalias sret %{{.*}}, { double, double }* %{{.*}}arg)
end_comment

begin_function
specifier|_Complex
name|long
name|double
name|pass_complex_longdouble
parameter_list|(
specifier|_Complex
name|long
name|double
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_complex_longdouble({ fp128, fp128 }* noalias sret %{{.*}}, { fp128, fp128 }* %{{.*}}arg)
end_comment

begin_comment
comment|// Aggregate types
end_comment

begin_struct
struct|struct
name|agg_1byte
block|{
name|char
name|a
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_1byte
name|pass_agg_1byte
parameter_list|(
name|struct
name|agg_1byte
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_1byte(%struct.agg_1byte* noalias sret %{{.*}}, i8 %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_2byte
block|{
name|char
name|a
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_2byte
name|pass_agg_2byte
parameter_list|(
name|struct
name|agg_2byte
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_2byte(%struct.agg_2byte* noalias sret %{{.*}}, i16 %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_3byte
block|{
name|char
name|a
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_3byte
name|pass_agg_3byte
parameter_list|(
name|struct
name|agg_3byte
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_3byte(%struct.agg_3byte* noalias sret %{{.*}}, %struct.agg_3byte* %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_4byte
block|{
name|char
name|a
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_4byte
name|pass_agg_4byte
parameter_list|(
name|struct
name|agg_4byte
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_4byte(%struct.agg_4byte* noalias sret %{{.*}}, i32 %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_5byte
block|{
name|char
name|a
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_5byte
name|pass_agg_5byte
parameter_list|(
name|struct
name|agg_5byte
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_5byte(%struct.agg_5byte* noalias sret %{{.*}}, %struct.agg_5byte* %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_6byte
block|{
name|char
name|a
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_6byte
name|pass_agg_6byte
parameter_list|(
name|struct
name|agg_6byte
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_6byte(%struct.agg_6byte* noalias sret %{{.*}}, %struct.agg_6byte* %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_7byte
block|{
name|char
name|a
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_7byte
name|pass_agg_7byte
parameter_list|(
name|struct
name|agg_7byte
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_7byte(%struct.agg_7byte* noalias sret %{{.*}}, %struct.agg_7byte* %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_8byte
block|{
name|char
name|a
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_8byte
name|pass_agg_8byte
parameter_list|(
name|struct
name|agg_8byte
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_8byte(%struct.agg_8byte* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_16byte
block|{
name|char
name|a
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_16byte
name|pass_agg_16byte
parameter_list|(
name|struct
name|agg_16byte
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_16byte(%struct.agg_16byte* noalias sret %{{.*}}, %struct.agg_16byte* %{{.*}})
end_comment

begin_comment
comment|// Float-like aggregate types
end_comment

begin_struct
struct|struct
name|agg_float
block|{
name|float
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_float
name|pass_agg_float
parameter_list|(
name|struct
name|agg_float
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_float(%struct.agg_float* noalias sret %{{.*}}, float %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_double
block|{
name|double
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_double
name|pass_agg_double
parameter_list|(
name|struct
name|agg_double
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_double(%struct.agg_double* noalias sret %{{.*}}, double %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_longdouble
block|{
name|long
name|double
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|agg_longdouble
name|pass_agg_longdouble
parameter_list|(
name|struct
name|agg_longdouble
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_longdouble(%struct.agg_longdouble* noalias sret %{{.*}}, %struct.agg_longdouble* %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_float_a8
block|{
name|float
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
name|agg_float_a8
name|pass_agg_float_a8
parameter_list|(
name|struct
name|agg_float_a8
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_float_a8(%struct.agg_float_a8* noalias sret %{{.*}}, double %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_float_a16
block|{
name|float
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
struct|;
end_struct

begin_function
name|struct
name|agg_float_a16
name|pass_agg_float_a16
parameter_list|(
name|struct
name|agg_float_a16
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_float_a16(%struct.agg_float_a16* noalias sret %{{.*}}, %struct.agg_float_a16* %{{.*}})
end_comment

begin_comment
comment|// Verify that the following are *not* float-like aggregate types
end_comment

begin_struct
struct|struct
name|agg_nofloat1
block|{
name|float
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
name|agg_nofloat1
name|pass_agg_nofloat1
parameter_list|(
name|struct
name|agg_nofloat1
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_nofloat1(%struct.agg_nofloat1* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_nofloat2
block|{
name|float
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
name|agg_nofloat2
name|pass_agg_nofloat2
parameter_list|(
name|struct
name|agg_nofloat2
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_nofloat2(%struct.agg_nofloat2* noalias sret %{{.*}}, i64 %{{.*}})
end_comment

begin_struct
struct|struct
name|agg_nofloat3
block|{
name|float
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
name|agg_nofloat3
name|pass_agg_nofloat3
parameter_list|(
name|struct
name|agg_nofloat3
name|arg
parameter_list|)
block|{
return|return
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @pass_agg_nofloat3(%struct.agg_nofloat3* noalias sret %{{.*}}, i32 %{{.*}})
end_comment

begin_comment
comment|// Accessing variable argument lists
end_comment

begin_function
name|int
name|va_int
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
name|int
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define signext i32 @va_int(%struct.__va_list_tag* %{{.*}})
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to i32*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to i32*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi i32* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[RET:%[^ ]+]] = load i32, i32* [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret i32 [[RET]]
end_comment

begin_function
name|long
name|va_long
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
name|long
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @va_long(%struct.__va_list_tag* %{{.*}})
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to i64*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to i64*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi i64* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[RET:%[^ ]+]] = load i64, i64* [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret i64 [[RET]]
end_comment

begin_function
name|long
name|long
name|va_longlong
parameter_list|(
name|__builtin_va_list
name|l
parameter_list|)
block|{
return|return
name|__builtin_va_arg
argument_list|(
argument|l
argument_list|,
argument|long long
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @va_longlong(%struct.__va_list_tag* %{{.*}})
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to i64*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to i64*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi i64* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[RET:%[^ ]+]] = load i64, i64* [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret i64 [[RET]]
end_comment

begin_function
name|double
name|va_double
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
name|double
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @va_double(%struct.__va_list_tag* %{{.*}})
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 4
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 128
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to double*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to double*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi double* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[RET:%[^ ]+]] = load double, double* [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret double [[RET]]
end_comment

begin_function
name|long
name|double
name|va_longdouble
parameter_list|(
name|__builtin_va_list
name|l
parameter_list|)
block|{
return|return
name|__builtin_va_arg
argument_list|(
argument|l
argument_list|,
argument|long double
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_longdouble(fp128* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}})
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to fp128**
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to fp128**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi fp128** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load fp128*, fp128** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: [[RET:%[^ ]+]] = load fp128, fp128* [[INDIRECT_ARG]]
end_comment

begin_comment
comment|// CHECK: store fp128 [[RET]], fp128* %{{.*}}
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
specifier|_Complex
name|char
name|va_complex_char
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
specifier|_Complex
name|char
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_complex_char({ i8, i8 }* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to { i8, i8 }**
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to { i8, i8 }**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi { i8, i8 }** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load { i8, i8 }*, { i8, i8 }** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_1byte
name|va_agg_1byte
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
name|agg_1byte
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_1byte(%struct.agg_1byte* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_1byte*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_1byte*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_1byte* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_2byte
name|va_agg_2byte
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
name|agg_2byte
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_2byte(%struct.agg_2byte* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_2byte*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_2byte*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_2byte* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_3byte
name|va_agg_3byte
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
name|agg_3byte
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_3byte(%struct.agg_3byte* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_3byte**
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_3byte**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_3byte** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load %struct.agg_3byte*, %struct.agg_3byte** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_4byte
name|va_agg_4byte
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
name|agg_4byte
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_4byte(%struct.agg_4byte* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_4byte*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_4byte*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_4byte* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_8byte
name|va_agg_8byte
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
name|agg_8byte
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_8byte(%struct.agg_8byte* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_8byte*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_8byte*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_8byte* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_float
name|va_agg_float
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
name|agg_float
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_float(%struct.agg_float* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 4
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 128
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_float*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_float*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_float* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_double
name|va_agg_double
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
name|agg_double
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_double(%struct.agg_double* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 4
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 128
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_double*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_double*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_double* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_longdouble
name|va_agg_longdouble
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
name|agg_longdouble
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_longdouble(%struct.agg_longdouble* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_longdouble**
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_longdouble**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_longdouble** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load %struct.agg_longdouble*, %struct.agg_longdouble** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_float_a8
name|va_agg_float_a8
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
name|agg_float_a8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_float_a8(%struct.agg_float_a8* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT_PTR:%[^ ]+]] = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %{{.*}}, i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: [[REG_COUNT:%[^ ]+]] = load i64, i64* [[REG_COUNT_PTR]]
end_comment

begin_comment
comment|// CHECK: [[FITS_IN_REGS:%[^ ]+]] = icmp ult i64 [[REG_COUNT]], 4
end_comment

begin_comment
comment|// CHECK: br i1 [[FITS_IN_REGS]],
end_comment

begin_comment
comment|// CHECK: [[SCALED_REG_COUNT:%[^ ]+]] = mul i64 [[REG_COUNT]], 8
end_comment

begin_comment
comment|// CHECK: [[REG_OFFSET:%[^ ]+]] = add i64 [[SCALED_REG_COUNT]], 128
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_float_a8*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_float_a8*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_float_a8* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_float_a16
name|va_agg_float_a16
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
name|agg_float_a16
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_float_a16(%struct.agg_float_a16* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_float_a16**
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_float_a16**
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_float_a16** [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: [[INDIRECT_ARG:%[^ ]+]] = load %struct.agg_float_a16*, %struct.agg_float_a16** [[VA_ARG_ADDR]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_nofloat1
name|va_agg_nofloat1
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
name|agg_nofloat1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_nofloat1(%struct.agg_nofloat1* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_nofloat1*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_nofloat1*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_nofloat1* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_nofloat2
name|va_agg_nofloat2
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
name|agg_nofloat2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_nofloat2(%struct.agg_nofloat2* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_nofloat2*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_nofloat2*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_nofloat2* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|struct
name|agg_nofloat3
name|va_agg_nofloat3
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
name|agg_nofloat3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @va_agg_nofloat3(%struct.agg_nofloat3* noalias sret %{{.*}}, %struct.__va_list_tag* %{{.*}}
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
comment|// CHECK: [[REG_ADDR:%[^ ]+]] = bitcast i8* [[RAW_REG_ADDR]] to %struct.agg_nofloat3*
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
comment|// CHECK: [[MEM_ADDR:%[^ ]+]] = bitcast i8* [[RAW_MEM_ADDR]] to %struct.agg_nofloat3*
end_comment

begin_comment
comment|// CHECK: [[OVERFLOW_ARG_AREA2:%[^ ]+]] = getelementptr i8, i8* [[OVERFLOW_ARG_AREA]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* [[OVERFLOW_ARG_AREA2]], i8** [[OVERFLOW_ARG_AREA_PTR]]
end_comment

begin_comment
comment|// CHECK: [[VA_ARG_ADDR:%[^ ]+]] = phi %struct.agg_nofloat3* [ [[REG_ADDR]], %{{.*}} ], [ [[MEM_ADDR]], %{{.*}} ]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

end_unit

