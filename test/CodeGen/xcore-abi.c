begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: xcore-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple xcore -verify %s
end_comment

begin_assert
assert|_Static_assert
argument_list|(
expr|sizeof
operator|(
name|long
name|long
operator|)
operator|==
literal|8
argument_list|,
literal|"sizeof long long is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
expr|_Alignof
operator|(
name|long
name|long
operator|)
operator|==
literal|4
argument_list|,
literal|"alignof long long is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|double
argument_list|)
operator|==
literal|8
argument_list|,
literal|"sizeof double is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
alignof|_Alignof
argument_list|(
name|double
argument_list|)
operator|==
literal|4
argument_list|,
literal|"alignof double is wrong"
argument_list|)
assert|;
end_assert

begin_comment
comment|// RUN: %clang_cc1 -triple xcore-unknown-unknown -fno-signed-char -fno-common -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: target triple = "xcore-unknown-unknown"
end_comment

begin_comment
comment|// CHECK: @cgx = external constant i32, section ".cp.rodata"
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|cgx
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|fcgx
parameter_list|()
block|{
return|return
name|cgx
return|;
block|}
end_function

begin_comment
comment|// CHECK: @g1 = global i32 0, align 4
end_comment

begin_decl_stmt
name|int
name|g1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @cg1 = constant i32 0, section ".cp.rodata", align 4
end_comment

begin_decl_stmt
specifier|const
name|int
name|cg1
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_struct
struct|struct
name|x
block|{
name|int
name|a
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|f
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|testva
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// CHECK-LABEL: testva
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|n
argument_list|)
expr_stmt|;
comment|// CHECK: [[AP:%[a-z0-9]+]] = alloca i8*, align 4
comment|// CHECK: [[AP1:%[a-z0-9]+]] = bitcast i8** [[AP]] to i8*
comment|// CHECK: call void @llvm.va_start(i8* [[AP1]])
name|char
modifier|*
name|v1
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|;
name|f
argument_list|(
name|v1
argument_list|)
expr_stmt|;
comment|// CHECK: [[I:%[a-z0-9]+]] = load i8** [[AP]]
comment|// CHECK: [[P:%[a-z0-9]+]] = bitcast i8* [[I]] to i8**
comment|// CHECK: [[IN:%[a-z0-9]+]] = getelementptr i8* [[I]], i32 4
comment|// CHECK: store i8* [[IN]], i8** [[AP]]
comment|// CHECK: [[V1:%[a-z0-9]+]] = load i8** [[P]]
comment|// CHECK: store i8* [[V1]], i8** [[V:%[a-z0-9]+]], align 4
comment|// CHECK: [[V2:%[a-z0-9]+]] = load i8** [[V]], align 4
comment|// CHECK: call void @f(i8* [[V2]])
name|char
name|v2
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|char
argument_list|)
decl_stmt|;
comment|// expected-warning{{second argument to 'va_arg' is of promotable type 'char'}}
name|f
argument_list|(
operator|&
name|v2
argument_list|)
expr_stmt|;
comment|// CHECK: [[I:%[a-z0-9]+]] = load i8** [[AP]]
comment|// CHECK: [[IN:%[a-z0-9]+]] = getelementptr i8* [[I]], i32 4
comment|// CHECK: store i8* [[IN]], i8** [[AP]]
comment|// CHECK: [[V1:%[a-z0-9]+]] = load i8* [[I]]
comment|// CHECK: store i8 [[V1]], i8* [[V:%[a-z0-9]+]], align 1
comment|// CHECK: call void @f(i8* [[V]])
name|int
name|v3
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
decl_stmt|;
name|f
argument_list|(
operator|&
name|v3
argument_list|)
expr_stmt|;
comment|// CHECK: [[I:%[a-z0-9]+]] = load i8** [[AP]]
comment|// CHECK: [[P:%[a-z0-9]+]] = bitcast i8* [[I]] to i32*
comment|// CHECK: [[IN:%[a-z0-9]+]] = getelementptr i8* [[I]], i32 4
comment|// CHECK: store i8* [[IN]], i8** [[AP]]
comment|// CHECK: [[V1:%[a-z0-9]+]] = load i32* [[P]]
comment|// CHECK: store i32 [[V1]], i32* [[V:%[a-z0-9]+]], align 4
comment|// CHECK: [[V2:%[a-z0-9]+]] = bitcast i32* [[V]] to i8*
comment|// CHECK: call void @f(i8* [[V2]])
name|long
name|long
name|int
name|v4
init|=
name|va_arg
argument_list|(
argument|ap
argument_list|,
argument|long long int
argument_list|)
decl_stmt|;
name|f
argument_list|(
operator|&
name|v4
argument_list|)
expr_stmt|;
comment|// CHECK: [[I:%[a-z0-9]+]] = load i8** [[AP]]
comment|// CHECK: [[P:%[a-z0-9]+]] = bitcast i8* [[I]] to i64*
comment|// CHECK: [[IN:%[a-z0-9]+]] = getelementptr i8* [[I]], i32 8
comment|// CHECK: store i8* [[IN]], i8** [[AP]]
comment|// CHECK: [[V1:%[a-z0-9]+]] = load i64* [[P]]
comment|// CHECK: store i64 [[V1]], i64* [[V:%[a-z0-9]+]], align 4
comment|// CHECK:[[V2:%[a-z0-9]+]] = bitcast i64* [[V]] to i8*
comment|// CHECK: call void @f(i8* [[V2]])
name|struct
name|x
name|v5
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
expr|struct
name|x
argument_list|)
decl_stmt|;
comment|// typical aggregate type
name|f
argument_list|(
operator|&
name|v5
argument_list|)
expr_stmt|;
comment|// CHECK: [[I:%[a-z0-9]+]] = load i8** [[AP]]
comment|// CHECK: [[I2:%[a-z0-9]+]] = bitcast i8* [[I]] to %struct.x**
comment|// CHECK: [[P:%[a-z0-9]+]] = load %struct.x** [[I2]]
comment|// CHECK: [[IN:%[a-z0-9]+]] = getelementptr i8* [[I]], i32 4
comment|// CHECK: store i8* [[IN]], i8** [[AP]]
comment|// CHECK: [[V1:%[a-z0-9]+]] = bitcast %struct.x* [[V:%[a-z0-9]+]] to i8*
comment|// CHECK: [[P1:%[a-z0-9]+]] = bitcast %struct.x* [[P]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[V1]], i8* [[P1]], i32 20, i32 4, i1 false)
comment|// CHECK: [[V2:%[a-z0-9]+]] = bitcast %struct.x* [[V]] to i8*
comment|// CHECK: call void @f(i8* [[V2]])
name|int
modifier|*
name|v6
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|int
index|[
literal|4
index|]
argument_list|)
decl_stmt|;
comment|// an unusual aggregate type
name|f
argument_list|(
name|v6
argument_list|)
expr_stmt|;
comment|// CHECK: [[I:%[a-z0-9]+]] = load i8** [[AP]]
comment|// CHECK: [[I2:%[a-z0-9]+]] = bitcast i8* [[I]] to [4 x i32]**
comment|// CHECK: [[P:%[a-z0-9]+]] = load [4 x i32]** [[I2]]
comment|// CHECK: [[IN:%[a-z0-9]+]] = getelementptr i8* [[I]], i32 4
comment|// CHECK: store i8* [[IN]], i8** [[AP]]
comment|// CHECK: [[V1:%[a-z0-9]+]] = bitcast [4 x i32]* [[V0:%[a-z0-9]+]] to i8*
comment|// CHECK: [[P1:%[a-z0-9]+]] = bitcast [4 x i32]* [[P]] to i8*
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i32(i8* [[V1]], i8* [[P1]], i32 16, i32 4, i1 false)
comment|// CHECK: [[V2:%[a-z0-9]+]] = getelementptr inbounds [4 x i32]* [[V0]], i32 0, i32 0
comment|// CHECK: store i32* [[V2]], i32** [[V:%[a-z0-9]+]], align 4
comment|// CHECK: [[V3:%[a-z0-9]+]] = load i32** [[V]], align 4
comment|// CHECK: [[V4:%[a-z0-9]+]] = bitcast i32* [[V3]] to i8*
comment|// CHECK: call void @f(i8* [[V4]])
name|double
name|v7
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|double
argument_list|)
decl_stmt|;
name|f
argument_list|(
operator|&
name|v7
argument_list|)
expr_stmt|;
comment|// CHECK: [[I:%[a-z0-9]+]] = load i8** [[AP]]
comment|// CHECK: [[P:%[a-z0-9]+]] = bitcast i8* [[I]] to double*
comment|// CHECK: [[IN:%[a-z0-9]+]] = getelementptr i8* [[I]], i32 8
comment|// CHECK: store i8* [[IN]], i8** [[AP]]
comment|// CHECK: [[V1:%[a-z0-9]+]] = load double* [[P]]
comment|// CHECK: store double [[V1]], double* [[V:%[a-z0-9]+]], align 4
comment|// CHECK: [[V2:%[a-z0-9]+]] = bitcast double* [[V]] to i8*
comment|// CHECK: call void @f(i8* [[V2]])
block|}
end_function

begin_function
name|void
name|testbuiltin
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: testbuiltin
comment|// CHECK: call i32 @llvm.xcore.getid()
comment|// CHECK: call i32 @llvm.xcore.getps(i32 {{%[a-z0-9]+}})
comment|// CHECK: call i32 @llvm.xcore.bitrev(i32 {{%[a-z0-9]+}})
comment|// CHECK: call void @llvm.xcore.setps(i32 {{%[a-z0-9]+}}, i32 {{%[a-z0-9]+}})
specifier|volatile
name|int
name|i
init|=
name|__builtin_getid
argument_list|()
decl_stmt|;
specifier|volatile
name|unsigned
name|int
name|ui
init|=
name|__builtin_getps
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|ui
operator|=
name|__builtin_bitrev
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|__builtin_setps
argument_list|(
name|i
argument_list|,
name|ui
argument_list|)
expr_stmt|;
comment|// CHECK: store volatile i32 0, i32* {{%[a-z0-9]+}}, align 4
comment|// CHECK: store volatile i32 1, i32* {{%[a-z0-9]+}}, align 4
comment|// CHECK: store volatile i32 -1, i32* {{%[a-z0-9]+}}, align 4
specifier|volatile
name|int
name|res
decl_stmt|;
name|res
operator|=
name|__builtin_eh_return_data_regno
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|res
operator|=
name|__builtin_eh_return_data_regno
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|res
operator|=
name|__builtin_eh_return_data_regno
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define zeroext i8 @testchar()
end_comment

begin_comment
comment|// CHECK: ret i8 -1
end_comment

begin_function
name|char
name|testchar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|char
operator|)
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|// CHECK: "no-frame-pointer-elim"="false"
end_comment

begin_comment
comment|// CHECK-NOT: "no-frame-pointer-elim-non-leaf"
end_comment

end_unit

