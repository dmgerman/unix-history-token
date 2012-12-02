begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin -target-abi aapcs -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin -target-abi apcs-gnu -emit-llvm -o - %s | FileCheck -check-prefix=APCS-GNU %s
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
literal|2
argument|) )
argument_list|)
name|int
name|__int2
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
name|char
name|__char3
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

begin_comment
comment|// Passing legal vector types as varargs.
end_comment

begin_function
name|double
name|varargs_vec_2i
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_vec_2i
comment|// CHECK: alloca<2 x i32>, align 8
comment|// CHECK: [[ALIGN:%.*]] = and i32 [[VAR:%.*]], -8
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i32 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 8
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to<2 x i32>*
comment|// APCS-GNU: varargs_vec_2i
comment|// APCS-GNU: alloca<2 x i32>, align 8
comment|// APCS-GNU: [[VAR_ALIGN:%.*]] = alloca<2 x i32>
comment|// APCS-GNU: [[AP_NEXT:%.*]] = getelementptr i8* {{%.*}}, i32 8
comment|// APCS-GNU: bitcast<2 x i32>* [[VAR_ALIGN]] to i8*
comment|// APCS-GNU: call void @llvm.memcpy
comment|// APCS-GNU: load<2 x i32>* [[VAR_ALIGN]]
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
name|__int2
name|c3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|__int2
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
name|test_2i
parameter_list|(
name|__int2
modifier|*
name|in
parameter_list|)
block|{
comment|// CHECK: test_2i
comment|// CHECK: call arm_aapcscc double (i32, ...)* @varargs_vec_2i(i32 3,<2 x i32> {{%.*}})
comment|// APCS-GNU: test_2i
comment|// APCS-GNU: call double (i32, ...)* @varargs_vec_2i(i32 3,<2 x i32> {{%.*}})
return|return
name|varargs_vec_2i
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
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP:%.*]], i32 4
comment|// CHECK: bitcast i8* [[AP]] to<3 x i8>*
comment|// APCS-GNU: varargs_vec_3c
comment|// APCS-GNU: alloca<3 x i8>, align 4
comment|// APCS-GNU: [[AP_NEXT:%.*]] = getelementptr i8* [[AP:%.*]], i32 4
comment|// APCS-GNU: bitcast i8* [[AP]] to<3 x i8>*
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
comment|// CHECK: call arm_aapcscc double (i32, ...)* @varargs_vec_3c(i32 3, i32 {{%.*}})
comment|// APCS-GNU: test_3c
comment|// APCS-GNU: call double (i32, ...)* @varargs_vec_3c(i32 3, i32 {{%.*}})
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
comment|// CHECK: [[ALIGN:%.*]] = and i32 {{%.*}}, -8
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i32 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 8
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to<5 x i8>*
comment|// APCS-GNU: varargs_vec_5c
comment|// APCS-GNU: alloca<5 x i8>, align 8
comment|// APCS-GNU: [[VAR_ALIGN:%.*]] = alloca<5 x i8>
comment|// APCS-GNU: [[AP_NEXT:%.*]] = getelementptr i8* {{%.*}}, i32 8
comment|// APCS-GNU: bitcast<5 x i8>* [[VAR_ALIGN]] to i8*
comment|// APCS-GNU: call void @llvm.memcpy
comment|// APCS-GNU: load<5 x i8>* [[VAR_ALIGN]]
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
comment|// CHECK: call arm_aapcscc double (i32, ...)* @varargs_vec_5c(i32 5,<2 x i32> {{%.*}})
comment|// APCS-GNU: test_5c
comment|// APCS-GNU: call double (i32, ...)* @varargs_vec_5c(i32 5,<2 x i32> {{%.*}})
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
comment|// CHECK: [[VAR_ALIGN:%.*]] = alloca<9 x i8>
comment|// CHECK: [[ALIGN:%.*]] = and i32 {{%.*}}, -8
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i32 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 16
comment|// CHECK: bitcast<9 x i8>* [[VAR_ALIGN]] to i8*
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK: load<9 x i8>* [[VAR_ALIGN]]
comment|// APCS-GNU: varargs_vec_9c
comment|// APCS-GNU: alloca<9 x i8>, align 16
comment|// APCS-GNU: [[VAR_ALIGN:%.*]] = alloca<9 x i8>
comment|// APCS-GNU: [[AP_NEXT:%.*]] = getelementptr i8* {{%.*}}, i32 16
comment|// APCS-GNU: bitcast<9 x i8>* [[VAR_ALIGN]] to i8*
comment|// APCS-GNU: call void @llvm.memcpy
comment|// APCS-GNU: load<9 x i8>* [[VAR_ALIGN]]
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
comment|// CHECK: call arm_aapcscc double (i32, ...)* @varargs_vec_9c(i32 9,<4 x i32> {{%.*}})
comment|// APCS-GNU: test_9c
comment|// APCS-GNU: call double (i32, ...)* @varargs_vec_9c(i32 9,<4 x i32> {{%.*}})
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
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP:%.*]], i32 4
comment|// CHECK: [[VAR:%.*]] = bitcast i8* [[AP]] to i8**
comment|// CHECK: [[VAR2:%.*]] = load i8** [[VAR]]
comment|// CHECK: bitcast i8* [[VAR2]] to<19 x i8>*
comment|// APCS-GNU: varargs_vec_19c
comment|// APCS-GNU: [[AP_NEXT:%.*]] = getelementptr i8* [[AP:%.*]], i32 4
comment|// APCS-GNU: [[VAR:%.*]] = bitcast i8* [[AP]] to i8**
comment|// APCS-GNU: [[VAR2:%.*]] = load i8** [[VAR]]
comment|// APCS-GNU: bitcast i8* [[VAR2]] to<19 x i8>*
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
comment|// CHECK: call arm_aapcscc double (i32, ...)* @varargs_vec_19c(i32 19,<19 x i8>* {{%.*}})
comment|// APCS-GNU: test_19c
comment|// APCS-GNU: call double (i32, ...)* @varargs_vec_19c(i32 19,<19 x i8>* {{%.*}})
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
comment|// CHECK: [[ALIGN:%.*]] = and i32 {{%.*}}, -8
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i32 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 8
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to<3 x i16>*
comment|// APCS-GNU: varargs_vec_3s
comment|// APCS-GNU: alloca<3 x i16>, align 8
comment|// APCS-GNU: [[VAR_ALIGN:%.*]] = alloca<3 x i16>
comment|// APCS-GNU: [[AP_NEXT:%.*]] = getelementptr i8* {{%.*}}, i32 8
comment|// APCS-GNU: bitcast<3 x i16>* [[VAR_ALIGN]] to i8*
comment|// APCS-GNU: call void @llvm.memcpy
comment|// APCS-GNU: load<3 x i16>* [[VAR_ALIGN]]
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
comment|// CHECK: call arm_aapcscc double (i32, ...)* @varargs_vec_3s(i32 3,<2 x i32> {{%.*}})
comment|// APCS-GNU: test_3s
comment|// APCS-GNU: call double (i32, ...)* @varargs_vec_3s(i32 3,<2 x i32> {{%.*}})
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
comment|// CHECK: [[VAR_ALIGN:%.*]] = alloca<5 x i16>
comment|// CHECK: [[ALIGN:%.*]] = and i32 {{%.*}}, -8
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i32 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 16
comment|// CHECK: bitcast<5 x i16>* [[VAR_ALIGN]] to i8*
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK: load<5 x i16>* [[VAR_ALIGN]]
comment|// APCS-GNU: varargs_vec_5s
comment|// APCS-GNU: alloca<5 x i16>, align 16
comment|// APCS-GNU: [[VAR_ALIGN:%.*]] = alloca<5 x i16>
comment|// APCS-GNU: [[AP_NEXT:%.*]] = getelementptr i8* {{%.*}}, i32 16
comment|// APCS-GNU: bitcast<5 x i16>* [[VAR_ALIGN]] to i8*
comment|// APCS-GNU: call void @llvm.memcpy
comment|// APCS-GNU: load<5 x i16>* [[VAR_ALIGN]]
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
comment|// CHECK: call arm_aapcscc double (i32, ...)* @varargs_vec_5s(i32 5,<4 x i32> {{%.*}})
comment|// APCS-GNU: test_5s
comment|// APCS-GNU: call double (i32, ...)* @varargs_vec_5s(i32 5,<4 x i32> {{%.*}})
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

begin_comment
comment|// Pass struct as varargs.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|__int2
name|i2
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|StructWithVec
typedef|;
end_typedef

begin_function
name|double
name|varargs_struct
parameter_list|(
name|int
name|fixed
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK: varargs_struct
comment|// CHECK: [[ALIGN:%.*]] = and i32 {{%.*}}, -8
comment|// CHECK: [[AP_ALIGN:%.*]] = inttoptr i32 [[ALIGN]] to i8*
comment|// CHECK: [[AP_NEXT:%.*]] = getelementptr i8* [[AP_ALIGN]], i32 16
comment|// CHECK: bitcast i8* [[AP_ALIGN]] to %struct.StructWithVec*
comment|// APCS-GNU: varargs_struct
comment|// APCS-GNU: [[VAR_ALIGN:%.*]] = alloca %struct.StructWithVec
comment|// APCS-GNU: [[AP_NEXT:%.*]] = getelementptr i8* {{%.*}}, i32 16
comment|// APCS-GNU: bitcast %struct.StructWithVec* [[VAR_ALIGN]] to i8*
comment|// APCS-GNU: call void @llvm.memcpy
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
name|StructWithVec
name|c3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|StructWithVec
argument_list|)
decl_stmt|;
name|sum
operator|=
name|sum
operator|+
name|c3
operator|.
name|i2
operator|.
name|x
operator|+
name|c3
operator|.
name|i2
operator|.
name|y
operator|+
name|c3
operator|.
name|f
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
name|test_struct
parameter_list|(
name|StructWithVec
modifier|*
name|d
parameter_list|)
block|{
comment|// CHECK: test_struct
comment|// CHECK: call arm_aapcscc double (i32, ...)* @varargs_struct(i32 3, [2 x i64] {{%.*}})
comment|// APCS-GNU: test_struct
comment|// APCS-GNU: call double (i32, ...)* @varargs_struct(i32 3, [2 x i64] {{%.*}})
return|return
name|varargs_struct
argument_list|(
literal|3
argument_list|,
operator|*
name|d
argument_list|)
return|;
block|}
end_function

end_unit

