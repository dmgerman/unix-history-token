begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_struct
struct|struct
name|test1
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

begin_struct
struct|struct
name|test2
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|test3
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|test4
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|test5
block|{
name|int
name|x
index|[
literal|17
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|test6
block|{
name|int
name|x
index|[
literal|17
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|test7
block|{
name|int
name|x
index|[
literal|17
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|// CHECK: define void @test1(i32 signext %x, i64 %y.coerce)
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|int
name|x
parameter_list|,
name|struct
name|test1
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test2(i32 signext %x, [1 x i128] %y.coerce)
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|int
name|x
parameter_list|,
name|struct
name|test2
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test3(i32 signext %x, [2 x i128] %y.coerce)
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|int
name|x
parameter_list|,
name|struct
name|test3
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test4(i32 signext %x, [2 x i64] %y.coerce)
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|int
name|x
parameter_list|,
name|struct
name|test4
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test5(i32 signext %x, %struct.test5* byval align 8 %y)
end_comment

begin_function
name|void
name|test5
parameter_list|(
name|int
name|x
parameter_list|,
name|struct
name|test5
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @test6(i32 signext %x, %struct.test6* byval align 16 %y)
end_comment

begin_function
name|void
name|test6
parameter_list|(
name|int
name|x
parameter_list|,
name|struct
name|test6
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// This case requires run-time realignment of the incoming struct
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test7(i32 signext %x, %struct.test7* byval align 16)
end_comment

begin_comment
comment|// CHECK: %y = alloca %struct.test7, align 32
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64
end_comment

begin_function
name|void
name|test7
parameter_list|(
name|int
name|x
parameter_list|,
name|struct
name|test7
name|y
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK-LABEL: define void @test1va(%struct.test1* noalias sret %agg.result, i32 signext %x, ...)
end_comment

begin_comment
comment|// CHECK: %y = alloca %struct.test1, align 4
end_comment

begin_comment
comment|// CHECK: %[[CUR:[^ ]+]] = load i8*, i8** %ap
end_comment

begin_comment
comment|// CHECK: %[[NEXT:[^ ]+]] = getelementptr inbounds i8, i8* %[[CUR]], i64 8
end_comment

begin_comment
comment|// CHECK: store i8* %[[NEXT]], i8** %ap
end_comment

begin_comment
comment|// CHECK: [[T0:%.*]] = bitcast i8* %[[CUR]] to %struct.test1*
end_comment

begin_comment
comment|// CHECK: [[DEST:%.*]] = bitcast %struct.test1* %y to i8*
end_comment

begin_comment
comment|// CHECK: [[SRC:%.*]] = bitcast %struct.test1* [[T0]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[DEST]], i8* [[SRC]], i64 8, i32 4, i1 false)
end_comment

begin_function
name|struct
name|test1
name|test1va
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
name|struct
name|test1
name|y
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|y
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|test1
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|y
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test2va(%struct.test2* noalias sret %agg.result, i32 signext %x, ...)
end_comment

begin_comment
comment|// CHECK: %y = alloca %struct.test2, align 16
end_comment

begin_comment
comment|// CHECK: %[[CUR:[^ ]+]] = load i8*, i8** %ap
end_comment

begin_comment
comment|// CHECK: %[[TMP0:[^ ]+]] = ptrtoint i8* %[[CUR]] to i64
end_comment

begin_comment
comment|// CHECK: %[[TMP1:[^ ]+]] = add i64 %[[TMP0]], 15
end_comment

begin_comment
comment|// CHECK: %[[TMP2:[^ ]+]] = and i64 %[[TMP1]], -16
end_comment

begin_comment
comment|// CHECK: %[[ALIGN:[^ ]+]] = inttoptr i64 %[[TMP2]] to i8*
end_comment

begin_comment
comment|// CHECK: %[[NEXT:[^ ]+]] = getelementptr inbounds i8, i8* %[[ALIGN]], i64 16
end_comment

begin_comment
comment|// CHECK: store i8* %[[NEXT]], i8** %ap
end_comment

begin_comment
comment|// CHECK: [[T0:%.*]] = bitcast i8* %[[ALIGN]] to %struct.test2*
end_comment

begin_comment
comment|// CHECK: [[DEST:%.*]] = bitcast %struct.test2* %y to i8*
end_comment

begin_comment
comment|// CHECK: [[SRC:%.*]] = bitcast %struct.test2* [[T0]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[DEST]], i8* [[SRC]], i64 16, i32 16, i1 false)
end_comment

begin_function
name|struct
name|test2
name|test2va
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
name|struct
name|test2
name|y
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|y
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|test2
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|y
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test3va(%struct.test3* noalias sret %agg.result, i32 signext %x, ...)
end_comment

begin_comment
comment|// CHECK: %y = alloca %struct.test3, align 32
end_comment

begin_comment
comment|// CHECK: %[[CUR:[^ ]+]] = load i8*, i8** %ap
end_comment

begin_comment
comment|// CHECK: %[[TMP0:[^ ]+]] = ptrtoint i8* %[[CUR]] to i64
end_comment

begin_comment
comment|// CHECK: %[[TMP1:[^ ]+]] = add i64 %[[TMP0]], 15
end_comment

begin_comment
comment|// CHECK: %[[TMP2:[^ ]+]] = and i64 %[[TMP1]], -16
end_comment

begin_comment
comment|// CHECK: %[[ALIGN:[^ ]+]] = inttoptr i64 %[[TMP2]] to i8*
end_comment

begin_comment
comment|// CHECK: %[[NEXT:[^ ]+]] = getelementptr inbounds i8, i8* %[[ALIGN]], i64 32
end_comment

begin_comment
comment|// CHECK: store i8* %[[NEXT]], i8** %ap
end_comment

begin_comment
comment|// CHECK: [[T0:%.*]] = bitcast i8* %[[ALIGN]] to %struct.test3*
end_comment

begin_comment
comment|// CHECK: [[DEST:%.*]] = bitcast %struct.test3* %y to i8*
end_comment

begin_comment
comment|// CHECK: [[SRC:%.*]] = bitcast %struct.test3* [[T0]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[DEST]], i8* [[SRC]], i64 32, i32 16, i1 false)
end_comment

begin_function
name|struct
name|test3
name|test3va
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
name|struct
name|test3
name|y
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|y
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|test3
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|y
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test4va(%struct.test4* noalias sret %agg.result, i32 signext %x, ...)
end_comment

begin_comment
comment|// CHECK: %y = alloca %struct.test4, align 4
end_comment

begin_comment
comment|// CHECK: %[[CUR:[^ ]+]] = load i8*, i8** %ap
end_comment

begin_comment
comment|// CHECK: %[[NEXT:[^ ]+]] = getelementptr inbounds i8, i8* %[[CUR]], i64 16
end_comment

begin_comment
comment|// CHECK: store i8* %[[NEXT]], i8** %ap
end_comment

begin_comment
comment|// CHECK: [[T0:%.*]] = bitcast i8* %[[CUR]] to %struct.test4*
end_comment

begin_comment
comment|// CHECK: [[DEST:%.*]] = bitcast %struct.test4* %y to i8*
end_comment

begin_comment
comment|// CHECK: [[SRC:%.*]] = bitcast %struct.test4* [[T0]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[DEST]], i8* [[SRC]], i64 12, i32 4, i1 false)
end_comment

begin_function
name|struct
name|test4
name|test4va
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
name|struct
name|test4
name|y
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|y
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|test4
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|y
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testva_longdouble(%struct.test_longdouble* noalias sret %agg.result, i32 signext %x, ...)
end_comment

begin_comment
comment|// CHECK: %y = alloca %struct.test_longdouble, align 16
end_comment

begin_comment
comment|// CHECK: %[[CUR:[^ ]+]] = load i8*, i8** %ap
end_comment

begin_comment
comment|// CHECK: %[[NEXT:[^ ]+]] = getelementptr inbounds i8, i8* %[[CUR]], i64 16
end_comment

begin_comment
comment|// CHECK: store i8* %[[NEXT]], i8** %ap
end_comment

begin_comment
comment|// CHECK: [[T0:%.*]] = bitcast i8* %[[CUR]] to %struct.test_longdouble*
end_comment

begin_comment
comment|// CHECK: [[DEST:%.*]] = bitcast %struct.test_longdouble* %y to i8*
end_comment

begin_comment
comment|// CHECK: [[SRC:%.*]] = bitcast %struct.test_longdouble* [[T0]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[DEST]], i8* [[SRC]], i64 16, i32 8, i1 false)
end_comment

begin_struct
struct|struct
name|test_longdouble
block|{
name|long
name|double
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|test_longdouble
name|testva_longdouble
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
name|struct
name|test_longdouble
name|y
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|y
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|test_longdouble
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|y
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @testva_vector(%struct.test_vector* noalias sret %agg.result, i32 signext %x, ...)
end_comment

begin_comment
comment|// CHECK: %y = alloca %struct.test_vector, align 16
end_comment

begin_comment
comment|// CHECK: %[[CUR:[^ ]+]] = load i8*, i8** %ap
end_comment

begin_comment
comment|// CHECK: %[[TMP0:[^ ]+]] = ptrtoint i8* %[[CUR]] to i64
end_comment

begin_comment
comment|// CHECK: %[[TMP1:[^ ]+]] = add i64 %[[TMP0]], 15
end_comment

begin_comment
comment|// CHECK: %[[TMP2:[^ ]+]] = and i64 %[[TMP1]], -16
end_comment

begin_comment
comment|// CHECK: %[[ALIGN:[^ ]+]] = inttoptr i64 %[[TMP2]] to i8*
end_comment

begin_comment
comment|// CHECK: %[[NEXT:[^ ]+]] = getelementptr inbounds i8, i8* %[[ALIGN]], i64 16
end_comment

begin_comment
comment|// CHECK: store i8* %[[NEXT]], i8** %ap
end_comment

begin_comment
comment|// CHECK: [[T0:%.*]] = bitcast i8* %[[ALIGN]] to %struct.test_vector*
end_comment

begin_comment
comment|// CHECK: [[DEST:%.*]] = bitcast %struct.test_vector* %y to i8*
end_comment

begin_comment
comment|// CHECK: [[SRC:%.*]] = bitcast %struct.test_vector* [[T0]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[DEST]], i8* [[SRC]], i64 16, i32 16, i1 false)
end_comment

begin_struct
struct|struct
name|test_vector
block|{
name|vector
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|test_vector
name|testva_vector
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
name|struct
name|test_vector
name|y
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|y
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|test_vector
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|y
return|;
block|}
end_function

end_unit

