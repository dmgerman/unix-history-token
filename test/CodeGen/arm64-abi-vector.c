begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-abi darwinpcs -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|3
argument|) )
argument_list|)
name|char
name|__char3
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|4
argument|) )
argument_list|)
name|char
name|__char4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|5
argument|) )
argument_list|)
name|char
name|__char5
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|9
argument|) )
argument_list|)
name|char
name|__char9
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|19
argument|) )
argument_list|)
name|char
name|__char19
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|3
argument|) )
argument_list|)
name|short
name|__short3
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|5
argument|) )
argument_list|)
name|short
name|__short5
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|3
argument|) )
argument_list|)
name|int
name|__int3
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|5
argument|) )
argument_list|)
name|int
name|__int5
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|3
argument|) )
argument_list|)
name|double
name|__double3
typedef|;
end_typedef

begin_function
name|double
name|varargs_vec_3c
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_3c
comment|// CHECK: alloca<3 x i8>, align 4
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: bitcast i8* [[AP_CUR]] to<3 x i8>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__char3
name|c3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__char3
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|x
operator|+
name|c3
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_3c
parameter_list|(
name|__char3
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_3c
comment|// CHECK: call double (i32, ...)* @varargs_vec_3c(i32 3, i32 {{%.*}})
return|return
name|varargs_vec_3c
argument_list|(
literal|3
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec_4c
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_4c
comment|// CHECK: alloca<4 x i8>, align 4
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: bitcast i8* [[AP_CUR]] to<4 x i8>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__char4
name|c4
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__char4
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c4
operator|.
name|x
operator|+
name|c4
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_4c
parameter_list|(
name|__char4
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_4c
comment|// CHECK: call double (i32, ...)* @varargs_vec_4c(i32 4, i32 {{%.*}})
return|return
name|varargs_vec_4c
argument_list|(
literal|4
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec_5c
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_5c
comment|// CHECK: alloca<5 x i8>, align 8
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: bitcast i8* [[AP_CUR]] to<5 x i8>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__char5
name|c5
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__char5
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c5
operator|.
name|x
operator|+
name|c5
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_5c
parameter_list|(
name|__char5
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_5c
comment|// CHECK: call double (i32, ...)* @varargs_vec_5c(i32 5,<2 x i32> {{%.*}})
return|return
name|varargs_vec_5c
argument_list|(
literal|5
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec_9c
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_9c
comment|// CHECK: alloca<9 x i8>, align 16
comment|// CHECK: [[ALIGN:%.*]] = and i64 {{%.*}}, -16
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i64 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 16
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to<9 x i8>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__char9
name|c9
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__char9
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c9
operator|.
name|x
operator|+
name|c9
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_9c
parameter_list|(
name|__char9
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_9c
comment|// CHECK: call double (i32, ...)* @varargs_vec_9c(i32 9,<4 x i32> {{%.*}})
return|return
name|varargs_vec_9c
argument_list|(
literal|9
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec_19c
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_19c
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: [[VAR:%.*]] = bitcast i8* [[AP_CUR]] to i8**
comment|// CHECK: [[VAR2:%.*]] = load i8** [[VAR]]
comment|// CHECK: bitcast i8* [[VAR2]] to<19 x i8>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__char19
name|c19
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__char19
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c19
operator|.
name|x
operator|+
name|c19
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_19c
parameter_list|(
name|__char19
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_19c
comment|// CHECK: call double (i32, ...)* @varargs_vec_19c(i32 19,<19 x i8>* {{%.*}})
return|return
name|varargs_vec_19c
argument_list|(
literal|19
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec_3s
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_3s
comment|// CHECK: alloca<3 x i16>, align 8
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: bitcast i8* [[AP_CUR]] to<3 x i16>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__short3
name|c3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__short3
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|x
operator|+
name|c3
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_3s
parameter_list|(
name|__short3
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_3s
comment|// CHECK: call double (i32, ...)* @varargs_vec_3s(i32 3,<2 x i32> {{%.*}})
return|return
name|varargs_vec_3s
argument_list|(
literal|3
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec_5s
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_5s
comment|// CHECK: alloca<5 x i16>, align 16
comment|// CHECK: [[ALIGN:%.*]] = and i64 {{%.*}}, -16
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i64 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 16
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to<5 x i16>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__short5
name|c5
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__short5
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c5
operator|.
name|x
operator|+
name|c5
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_5s
parameter_list|(
name|__short5
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_5s
comment|// CHECK: call double (i32, ...)* @varargs_vec_5s(i32 5,<4 x i32> {{%.*}})
return|return
name|varargs_vec_5s
argument_list|(
literal|5
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec_3i
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_3i
comment|// CHECK: alloca<3 x i32>, align 16
comment|// CHECK: [[ALIGN:%.*]] = and i64 {{%.*}}, -16
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i64 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 16
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to<3 x i32>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__int3
name|c3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__int3
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|x
operator|+
name|c3
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_3i
parameter_list|(
name|__int3
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_3i
comment|// CHECK: call double (i32, ...)* @varargs_vec_3i(i32 3,<4 x i32> {{%.*}})
return|return
name|varargs_vec_3i
argument_list|(
literal|3
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec_5i
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_5i
comment|// CHECK: alloca<5 x i32>, align 16
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: [[VAR:%.*]] = bitcast i8* [[AP_CUR]] to i8**
comment|// CHECK: [[VAR2:%.*]] = load i8** [[VAR]]
comment|// CHECK: bitcast i8* [[VAR2]] to<5 x i32>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__int5
name|c5
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__int5
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c5
operator|.
name|x
operator|+
name|c5
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_5i
parameter_list|(
name|__int5
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_5i
comment|// CHECK: call double (i32, ...)* @varargs_vec_5i(i32 5,<5 x i32>* {{%.*}})
return|return
name|varargs_vec_5i
argument_list|(
literal|5
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec_3d
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_3d
comment|// CHECK: alloca<3 x double>, align 16
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: [[VAR:%.*]] = bitcast i8* [[AP_CUR]] to i8**
comment|// CHECK: [[VAR2:%.*]] = load i8** [[VAR]]
comment|// CHECK: bitcast i8* [[VAR2]] to<3 x double>*
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__double3
name|c3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__double3
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|x
operator|+
name|c3
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test_3d
parameter_list|(
name|__double3
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_3d
comment|// CHECK: call double (i32, ...)* @varargs_vec_3d(i32 3,<3 x double>* {{%.*}})
return|return
name|varargs_vec_3d
argument_list|(
literal|3
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|varargs_vec
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec
name|va_list
name|ap
decl_stmt|;
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fixed
argument_list|)
expr_stmt|;
name|__char3
name|c3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__char3
argument_list|)
decl_stmt|;
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: bitcast i8* [[AP_CUR]] to<3 x i8>*
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|x
operator|+
name|c3
operator|.
name|y
expr_stmt|;
name|__char5
name|c5
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__char5
argument_list|)
decl_stmt|;
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: bitcast i8* [[AP_CUR]] to<5 x i8>*
name|sum
operator|=
name|sum
operator|+
name|c5
operator|.
name|x
operator|+
name|c5
operator|.
name|y
expr_stmt|;
name|__char9
name|c9
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__char9
argument_list|)
decl_stmt|;
comment|// CHECK: [[ALIGN:%.*]] = and i64 {{%.*}}, -16
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i64 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 16
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to<9 x i8>*
name|sum
operator|=
name|sum
operator|+
name|c9
operator|.
name|x
operator|+
name|c9
operator|.
name|y
expr_stmt|;
name|__char19
name|c19
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__char19
argument_list|)
decl_stmt|;
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: [[VAR:%.*]] = bitcast i8* [[AP_CUR]] to i8**
comment|// CHECK: [[VAR2:%.*]] = load i8** [[VAR]]
comment|// CHECK: bitcast i8* [[VAR2]] to<19 x i8>*
name|sum
operator|=
name|sum
operator|+
name|c19
operator|.
name|x
operator|+
name|c19
operator|.
name|y
expr_stmt|;
name|__short3
name|s3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__short3
argument_list|)
decl_stmt|;
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: bitcast i8* [[AP_CUR]] to<3 x i16>*
name|sum
operator|=
name|sum
operator|+
name|s3
operator|.
name|x
operator|+
name|s3
operator|.
name|y
expr_stmt|;
name|__short5
name|s5
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__short5
argument_list|)
decl_stmt|;
comment|// CHECK: [[ALIGN:%.*]] = and i64 {{%.*}}, -16
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i64 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 16
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to<5 x i16>*
name|sum
operator|=
name|sum
operator|+
name|s5
operator|.
name|x
operator|+
name|s5
operator|.
name|y
expr_stmt|;
name|__int3
name|i3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__int3
argument_list|)
decl_stmt|;
comment|// CHECK: [[ALIGN:%.*]] = and i64 {{%.*}}, -16
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i64 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 16
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to<3 x i32>*
name|sum
operator|=
name|sum
operator|+
name|i3
operator|.
name|x
operator|+
name|i3
operator|.
name|y
expr_stmt|;
name|__int5
name|i5
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__int5
argument_list|)
decl_stmt|;
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: [[VAR:%.*]] = bitcast i8* [[AP_CUR]] to i8**
comment|// CHECK: [[VAR2:%.*]] = load i8** [[VAR]]
comment|// CHECK: bitcast i8* [[VAR2]] to<5 x i32>*
name|sum
operator|=
name|sum
operator|+
name|i5
operator|.
name|x
operator|+
name|i5
operator|.
name|y
expr_stmt|;
name|__double3
name|d3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__double3
argument_list|)
decl_stmt|;
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_CUR:%.*]], i32 8
comment|// CHECK: [[VAR:%.*]] = bitcast i8* [[AP_CUR]] to i8**
comment|// CHECK: [[VAR2:%.*]] = load i8** [[VAR]]
comment|// CHECK: bitcast i8* [[VAR2]] to<3 x double>*
name|sum
operator|=
name|sum
operator|+
name|d3
operator|.
name|x
operator|+
name|d3
operator|.
name|y
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|test
parameter_list|(
name|__char3
modifier|*
name|c3
parameter_list|,
name|__char5
modifier|*
name|c5
parameter_list|,
name|__char9
modifier|*
name|c9
parameter_list|,
name|__char19
modifier|*
name|c19
parameter_list|,
name|__short3
modifier|*
name|s3
parameter_list|,
name|__short5
modifier|*
name|s5
parameter_list|,
name|__int3
modifier|*
name|i3
parameter_list|,
name|__int5
modifier|*
name|i5
parameter_list|,
name|__double3
modifier|*
name|d3
parameter_list|)
block|{
name|double
name|ret
init|=
name|varargs_vec
argument_list|(
literal|3
argument_list|,
operator|*
name|c3
argument_list|,
operator|*
name|c5
argument_list|,
operator|*
name|c9
argument_list|,
operator|*
name|c19
argument_list|,
operator|*
name|s3
argument_list|,
operator|*
name|s5
argument_list|,
operator|*
name|i3
argument_list|,
operator|*
name|i5
argument_list|,
operator|*
name|d3
argument_list|)
decl_stmt|;
comment|// CHECK: call double (i32, ...)* @varargs_vec(i32 3, i32 {{%.*}},<2 x i32> {{%.*}},<4 x i32> {{%.*}},<19 x i8>* {{%.*}},<2 x i32> {{%.*}},<4 x i32> {{%.*}},<4 x i32> {{%.*}},<5 x i32>* {{%.*}},<3 x double>* {{%.*}})
return|return
name|ret
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|double
name|args_vec_3c
parameter_list|(
name|int
name|fixed
parameter_list|,
name|__char3
name|c3
parameter_list|)
block|{
comment|// CHECK: args_vec_3c
comment|// CHECK: [[C3:%.*]] = alloca<3 x i8>, align 4
comment|// CHECK: [[TMP:%.*]] = bitcast<3 x i8>* [[C3]] to i32*
comment|// CHECK: store i32 {{%.*}}, i32* [[TMP]]
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|x
operator|+
name|c3
operator|.
name|y
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|fixed_3c
parameter_list|(
name|__char3
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: fixed_3c
comment|// CHECK: call double @args_vec_3c(i32 3, i32 {{%.*}})
return|return
name|args_vec_3c
argument_list|(
literal|3
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|double
name|args_vec_5c
parameter_list|(
name|int
name|fixed
parameter_list|,
name|__char5
name|c5
parameter_list|)
block|{
comment|// CHECK: args_vec_5c
comment|// CHECK: [[C5:%.*]] = alloca<5 x i8>, align 8
comment|// CHECK: [[TMP:%.*]] = bitcast<5 x i8>* [[C5]] to<2 x i32>*
comment|// CHECK: store<2 x i32> {{%.*}},<2 x i32>* [[TMP]], align 1
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c5
operator|.
name|x
operator|+
name|c5
operator|.
name|y
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|fixed_5c
parameter_list|(
name|__char5
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: fixed_5c
comment|// CHECK: call double @args_vec_5c(i32 5,<2 x i32> {{%.*}})
return|return
name|args_vec_5c
argument_list|(
literal|5
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|double
name|args_vec_9c
parameter_list|(
name|int
name|fixed
parameter_list|,
name|__char9
name|c9
parameter_list|)
block|{
comment|// CHECK: args_vec_9c
comment|// CHECK: [[C9:%.*]] = alloca<9 x i8>, align 16
comment|// CHECK: [[TMP:%.*]] = bitcast<9 x i8>* [[C9]] to<4 x i32>*
comment|// CHECK: store<4 x i32> {{%.*}},<4 x i32>* [[TMP]], align 1
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c9
operator|.
name|x
operator|+
name|c9
operator|.
name|y
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|fixed_9c
parameter_list|(
name|__char9
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: fixed_9c
comment|// CHECK: call double @args_vec_9c(i32 9,<4 x i32> {{%.*}})
return|return
name|args_vec_9c
argument_list|(
literal|9
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|double
name|args_vec_19c
parameter_list|(
name|int
name|fixed
parameter_list|,
name|__char19
name|c19
parameter_list|)
block|{
comment|// CHECK: args_vec_19c
comment|// CHECK: [[C19:%.*]] = load<19 x i8>* {{.*}}, align 16
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c19
operator|.
name|x
operator|+
name|c19
operator|.
name|y
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|fixed_19c
parameter_list|(
name|__char19
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: fixed_19c
comment|// CHECK: call double @args_vec_19c(i32 19,<19 x i8>* {{%.*}})
return|return
name|args_vec_19c
argument_list|(
literal|19
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|double
name|args_vec_3s
parameter_list|(
name|int
name|fixed
parameter_list|,
name|__short3
name|c3
parameter_list|)
block|{
comment|// CHECK: args_vec_3s
comment|// CHECK: [[C3:%.*]] = alloca<3 x i16>, align 8
comment|// CHECK: [[TMP:%.*]] = bitcast<3 x i16>* [[C3]] to<2 x i32>*
comment|// CHECK: store<2 x i32> {{%.*}},<2 x i32>* [[TMP]], align 1
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|x
operator|+
name|c3
operator|.
name|y
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|fixed_3s
parameter_list|(
name|__short3
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: fixed_3s
comment|// CHECK: call double @args_vec_3s(i32 3,<2 x i32> {{%.*}})
return|return
name|args_vec_3s
argument_list|(
literal|3
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|double
name|args_vec_5s
parameter_list|(
name|int
name|fixed
parameter_list|,
name|__short5
name|c5
parameter_list|)
block|{
comment|// CHECK: args_vec_5s
comment|// CHECK: [[C5:%.*]] = alloca<5 x i16>, align 16
comment|// CHECK: [[TMP:%.*]] = bitcast<5 x i16>* [[C5]] to<4 x i32>*
comment|// CHECK: store<4 x i32> {{%.*}},<4 x i32>* [[TMP]], align 1
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c5
operator|.
name|x
operator|+
name|c5
operator|.
name|y
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|fixed_5s
parameter_list|(
name|__short5
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: fixed_5s
comment|// CHECK: call double @args_vec_5s(i32 5,<4 x i32> {{%.*}})
return|return
name|args_vec_5s
argument_list|(
literal|5
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|double
name|args_vec_3i
parameter_list|(
name|int
name|fixed
parameter_list|,
name|__int3
name|c3
parameter_list|)
block|{
comment|// CHECK: args_vec_3i
comment|// CHECK: [[C3:%.*]] = alloca<3 x i32>, align 16
comment|// CHECK: [[TMP:%.*]] = bitcast<3 x i32>* [[C3]] to<4 x i32>*
comment|// CHECK: store<4 x i32> {{%.*}},<4 x i32>* [[TMP]], align 1
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|x
operator|+
name|c3
operator|.
name|y
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|fixed_3i
parameter_list|(
name|__int3
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: fixed_3i
comment|// CHECK: call double @args_vec_3i(i32 3,<4 x i32> {{%.*}})
return|return
name|args_vec_3i
argument_list|(
literal|3
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|double
name|args_vec_5i
parameter_list|(
name|int
name|fixed
parameter_list|,
name|__int5
name|c5
parameter_list|)
block|{
comment|// CHECK: args_vec_5i
comment|// CHECK: [[C5:%.*]] = load<5 x i32>* {{%.*}}, align 16
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c5
operator|.
name|x
operator|+
name|c5
operator|.
name|y
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|fixed_5i
parameter_list|(
name|__int5
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: fixed_5i
comment|// CHECK: call double @args_vec_5i(i32 5,<5 x i32>* {{%.*}})
return|return
name|args_vec_5i
argument_list|(
literal|5
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|double
name|args_vec_3d
parameter_list|(
name|int
name|fixed
parameter_list|,
name|__double3
name|c3
parameter_list|)
block|{
comment|// CHECK: args_vec_3d
comment|// CHECK: [[CAST:%.*]] = bitcast<3 x double>* {{%.*}} to<4 x double>*
comment|// CHECK: [[LOAD:%.*]] = load<4 x double>* [[CAST]]
comment|// CHECK: shufflevector<4 x double> [[LOAD]],<4 x double> undef,<3 x i32><i32 0, i32 1, i32 2>
name|double
name|sum
init|=
name|fixed
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|x
operator|+
name|c3
operator|.
name|y
expr_stmt|;
return|return
name|sum
return|;
block|}
end_function

begin_function
name|double
name|fixed_3d
parameter_list|(
name|__double3
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: fixed_3d
comment|// CHECK: call double @args_vec_3d(i32 3,<3 x double>* {{%.*}})
return|return
name|args_vec_3d
argument_list|(
literal|3
argument_list|,
operator|*
name|in
argument_list|)
return|;
block|}
end_function

end_unit

