begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple wasm32-unknown-unknown -o - -emit-llvm %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function
name|int
name|test_i32
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|int
name|v
init|=
name|va_arg
argument_list|(
name|va
argument_list|,
name|int
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_i32(i8*{{.*}} %fmt, ...) {{.*}} {
end_comment

begin_comment
comment|// CHECK:   [[FMT_ADDR:%[^,=]+]] = alloca i8*, align 4
end_comment

begin_comment
comment|// CHECK:   [[VA:%[^,=]+]] = alloca i8*, align 4
end_comment

begin_comment
comment|// CHECK:   [[V:%[^,=]+]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK:   store i8* %fmt, i8** [[FMT_ADDR]], align 4
end_comment

begin_comment
comment|// CHECK:   [[VA1:%[^,=]+]] = bitcast i8** [[VA]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.va_start(i8* [[VA1]])
end_comment

begin_comment
comment|// CHECK:   [[ARGP_CUR:%[^,=]+]] = load i8*, i8** [[VA]], align 4
end_comment

begin_comment
comment|// CHECK:   [[ARGP_NEXT:%[^,=]+]] = getelementptr inbounds i8, i8* [[ARGP_CUR]], i32 4
end_comment

begin_comment
comment|// CHECK:   store i8* [[ARGP_NEXT]], i8** [[VA]], align 4
end_comment

begin_comment
comment|// CHECK:   [[R3:%[^,=]+]] = bitcast i8* [[ARGP_CUR]] to i32*
end_comment

begin_comment
comment|// CHECK:   [[R4:%[^,=]+]] = load i32, i32* [[R3]], align 4
end_comment

begin_comment
comment|// CHECK:   store i32 [[R4]], i32* [[V]], align 4
end_comment

begin_comment
comment|// CHECK:   [[VA2:%[^,=]+]] = bitcast i8** [[VA]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.va_end(i8* [[VA2]])
end_comment

begin_comment
comment|// CHECK:   [[R5:%[^,=]+]] = load i32, i32* [[V]], align 4
end_comment

begin_comment
comment|// CHECK:   ret i32 [[R5]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|long
name|long
name|test_i64
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|long
name|long
name|v
init|=
name|va_arg
argument_list|(
argument|va
argument_list|,
argument|long long
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_i64(i8*{{.*}} %fmt, ...) {{.*}} {
end_comment

begin_comment
comment|// CHECK:   [[FMT_ADDR:%[^,=]+]] = alloca i8*, align 4
end_comment

begin_comment
comment|// CHECK:   [[VA:%[^,=]+]] = alloca i8*, align 4
end_comment

begin_comment
comment|// CHECK:   [[V:%[^,=]+]] = alloca i64, align 8
end_comment

begin_comment
comment|// CHECK:   store i8* %fmt, i8** [[FMT_ADDR]], align 4
end_comment

begin_comment
comment|// CHECK:   [[VA1:%[^,=]+]] = bitcast i8** [[VA]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.va_start(i8* [[VA1]])
end_comment

begin_comment
comment|// CHECK:   [[ARGP_CUR:%[^,=]+]] = load i8*, i8** [[VA]], align 4
end_comment

begin_comment
comment|// CHECK:   [[R0:%[^,=]+]] = ptrtoint i8* [[ARGP_CUR]] to i32
end_comment

begin_comment
comment|// CHECK:   [[R1:%[^,=]+]] = add i32 [[R0]], 7
end_comment

begin_comment
comment|// CHECK:   [[R2:%[^,=]+]] = and i32 [[R1]], -8
end_comment

begin_comment
comment|// CHECK:   [[ARGP_CUR_ALIGNED:%[^,=]+]] = inttoptr i32 [[R2]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[ARGP_NEXT:%[^,=]+]] = getelementptr inbounds i8, i8* [[ARGP_CUR_ALIGNED]], i32 8
end_comment

begin_comment
comment|// CHECK:   store i8* [[ARGP_NEXT]], i8** [[VA]], align 4
end_comment

begin_comment
comment|// CHECK:   [[R3:%[^,=]+]] = bitcast i8* [[ARGP_CUR_ALIGNED]] to i64*
end_comment

begin_comment
comment|// CHECK:   [[R4:%[^,=]+]] = load i64, i64* [[R3]], align 8
end_comment

begin_comment
comment|// CHECK:   store i64 [[R4]], i64* [[V]], align 8
end_comment

begin_comment
comment|// CHECK:   [[VA2:%[^,=]+]] = bitcast i8** [[VA]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.va_end(i8* [[VA2]])
end_comment

begin_comment
comment|// CHECK:   [[R5:%[^,=]+]] = load i64, i64* [[V]], align 8
end_comment

begin_comment
comment|// CHECK:   ret i64 [[R5]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_struct
struct|struct
name|S
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

begin_function
name|struct
name|S
name|test_struct
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|struct
name|S
name|v
init|=
name|va_arg
argument_list|(
name|va
argument_list|,
expr|struct
name|S
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
return|return
name|v
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @test_struct([[STRUCT_S:%[^,=]+]]*{{.*}} noalias sret %agg.result, i8*{{.*}} %fmt, ...) {{.*}} {
end_comment

begin_comment
comment|// CHECK:   [[FMT_ADDR:%[^,=]+]] = alloca i8*, align 4
end_comment

begin_comment
comment|// CHECK:   [[VA:%[^,=]+]] = alloca i8*, align 4
end_comment

begin_comment
comment|// CHECK:   [[V:%[^,=]+]] = alloca [[STRUCT_S]], align 4
end_comment

begin_comment
comment|// CHECK:   store i8* %fmt, i8** [[FMT_ADDR]], align 4
end_comment

begin_comment
comment|// CHECK:   [[VA1:%[^,=]+]] = bitcast i8** [[VA]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.va_start(i8* [[VA1]])
end_comment

begin_comment
comment|// CHECK:   [[ARGP_CUR:%[^,=]+]] = load i8*, i8** [[VA]], align 4
end_comment

begin_comment
comment|// CHECK:   [[ARGP_NEXT:%[^,=]+]] = getelementptr inbounds i8, i8* [[ARGP_CUR]], i32 12
end_comment

begin_comment
comment|// CHECK:   store i8* [[ARGP_NEXT]], i8** [[VA]], align 4
end_comment

begin_comment
comment|// CHECK:   [[R3:%[^,=]+]] = bitcast i8* [[ARGP_CUR]] to [[STRUCT_S]]*
end_comment

begin_comment
comment|// CHECK:   [[R4:%[^,=]+]] = bitcast [[STRUCT_S]]* [[V]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[R5:%[^,=]+]] = bitcast [[STRUCT_S]]* [[R3]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[R4]], i8* [[R5]], i32 12, i32 4, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[VA2:%[^,=]+]] = bitcast i8** [[VA]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.va_end(i8* [[VA2]])
end_comment

begin_comment
comment|// CHECK:   [[R6:%[^,=]+]] = bitcast [[STRUCT_S]]* %agg.result to i8*
end_comment

begin_comment
comment|// CHECK:   [[R7:%[^,=]+]] = bitcast [[STRUCT_S]]* [[V]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[R6]], i8* [[R7]], i32 12, i32 4, i1 false)
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
end_comment

end_unit

