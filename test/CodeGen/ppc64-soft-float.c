begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -msoft-float -mfloat-abi soft -triple powerpc64le-unknown-linux-gnu -emit-llvm -o - %s | FileCheck -check-prefix=CHECK -check-prefix=CHECK-LE %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -msoft-float -mfloat-abi soft -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck -check-prefix=CHECK -check-prefix=CHECK-BE %s
end_comment

begin_comment
comment|// Test float returns and params.
end_comment

begin_comment
comment|// CHECK: define float @func_p1(float %x)
end_comment

begin_function
name|float
name|func_p1
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define double @func_p2(double %x)
end_comment

begin_function
name|double
name|func_p2
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define ppc_fp128 @func_p3(ppc_fp128 %x)
end_comment

begin_function
name|long
name|double
name|func_p3
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Test homogeneous float aggregate passing and returning.
end_comment

begin_struct
struct|struct
name|f1
block|{
name|float
name|f
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|f2
block|{
name|float
name|f
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|f3
block|{
name|float
name|f
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|f4
block|{
name|float
name|f
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|f5
block|{
name|float
name|f
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|f6
block|{
name|float
name|f
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|f7
block|{
name|float
name|f
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|f8
block|{
name|float
name|f
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|f9
block|{
name|float
name|f
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fab
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

begin_struct
struct|struct
name|fabc
block|{
name|float
name|a
decl_stmt|;
name|float
name|b
decl_stmt|;
name|float
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|f2a2b
block|{
name|float
name|a
index|[
literal|2
index|]
decl_stmt|;
name|float
name|b
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-LE: define i32 @func_f1(float inreg %x.coerce)
end_comment

begin_comment
comment|// CHECK-BE: define void @func_f1(%struct.f1* noalias sret %agg.result, float inreg %x.coerce)
end_comment

begin_function
name|struct
name|f1
name|func_f1
parameter_list|(
name|struct
name|f1
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LE: define i64 @func_f2(i64 %x.coerce)
end_comment

begin_comment
comment|// CHECK-BE: define void @func_f2(%struct.f2* noalias sret %agg.result, i64 %x.coerce)
end_comment

begin_function
name|struct
name|f2
name|func_f2
parameter_list|(
name|struct
name|f2
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LE: define { i64, i64 } @func_f3([2 x i64] %x.coerce)
end_comment

begin_comment
comment|// CHECK-BE: define void @func_f3(%struct.f3* noalias sret %agg.result, [2 x i64] %x.coerce)
end_comment

begin_function
name|struct
name|f3
name|func_f3
parameter_list|(
name|struct
name|f3
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LE: define { i64, i64 } @func_f4([2 x i64] %x.coerce)
end_comment

begin_comment
comment|// CHECK-BE: define void @func_f4(%struct.f4* noalias sret %agg.result, [2 x i64] %x.coerce)
end_comment

begin_function
name|struct
name|f4
name|func_f4
parameter_list|(
name|struct
name|f4
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @func_f5(%struct.f5* noalias sret %agg.result, [3 x i64] %x.coerce)
end_comment

begin_function
name|struct
name|f5
name|func_f5
parameter_list|(
name|struct
name|f5
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @func_f6(%struct.f6* noalias sret %agg.result, [3 x i64] %x.coerce)
end_comment

begin_function
name|struct
name|f6
name|func_f6
parameter_list|(
name|struct
name|f6
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @func_f7(%struct.f7* noalias sret %agg.result, [4 x i64] %x.coerce)
end_comment

begin_function
name|struct
name|f7
name|func_f7
parameter_list|(
name|struct
name|f7
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @func_f8(%struct.f8* noalias sret %agg.result, [4 x i64] %x.coerce)
end_comment

begin_function
name|struct
name|f8
name|func_f8
parameter_list|(
name|struct
name|f8
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @func_f9(%struct.f9* noalias sret %agg.result, [5 x i64] %x.coerce)
end_comment

begin_function
name|struct
name|f9
name|func_f9
parameter_list|(
name|struct
name|f9
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LE: define i64 @func_fab(i64 %x.coerce)
end_comment

begin_comment
comment|// CHECK-BE: define void @func_fab(%struct.fab* noalias sret %agg.result, i64 %x.coerce)
end_comment

begin_function
name|struct
name|fab
name|func_fab
parameter_list|(
name|struct
name|fab
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LE: define { i64, i64 } @func_fabc([2 x i64] %x.coerce)
end_comment

begin_comment
comment|// CHECK-BE: define void @func_fabc(%struct.fabc* noalias sret %agg.result, [2 x i64] %x.coerce)
end_comment

begin_function
name|struct
name|fabc
name|func_fabc
parameter_list|(
name|struct
name|fabc
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LE: define { i64, i64 } @func_f2a2b([2 x i64] %x.coerce)
end_comment

begin_comment
comment|// CHECK-BE: define void @func_f2a2b(%struct.f2a2b* noalias sret %agg.result, [2 x i64] %x.coerce)
end_comment

begin_function
name|struct
name|f2a2b
name|func_f2a2b
parameter_list|(
name|struct
name|f2a2b
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_f1
end_comment

begin_comment
comment|// CHECK-BE: %[[TMP0:[^ ]+]] = alloca %struct.f1, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load float, float* getelementptr inbounds (%struct.f1, %struct.f1* @global_f1, i32 0, i32 0, i32 0), align 4
end_comment

begin_comment
comment|// CHECK-LE: call i32 @func_f1(float inreg %[[TMP]])
end_comment

begin_comment
comment|// CHECK-BE: call void @func_f1(%struct.f1* sret %[[TMP0]], float inreg %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|f1
name|global_f1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_f1
parameter_list|(
name|void
parameter_list|)
block|{
name|global_f1
operator|=
name|func_f1
argument_list|(
name|global_f1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_f2
end_comment

begin_comment
comment|// CHECK-BE: %[[TMP0:[^ ]+]] = alloca %struct.f2, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load i64, i64* bitcast (%struct.f2* @global_f2 to i64*), align 4
end_comment

begin_comment
comment|// CHECK-LE: call i64 @func_f2(i64 %[[TMP]])
end_comment

begin_comment
comment|// CHECK-BE: call void @func_f2(%struct.f2* sret %[[TMP0]], i64 %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|f2
name|global_f2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_f2
parameter_list|(
name|void
parameter_list|)
block|{
name|global_f2
operator|=
name|func_f2
argument_list|(
name|global_f2
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_f3
end_comment

begin_comment
comment|// CHECK-BE: %[[TMP0:[^ ]+]] = alloca %struct.f3, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP1:[^ ]+]] = alloca [2 x i64]
end_comment

begin_comment
comment|// CHECK: %[[TMP2:[^ ]+]] = bitcast [2 x i64]* %[[TMP1]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* %[[TMP2]], i8* bitcast (%struct.f3* @global_f3 to i8*), i64 12, i32 4, i1 false)
end_comment

begin_comment
comment|// CHECK: %[[TMP3:[^ ]+]] = load [2 x i64], [2 x i64]* %[[TMP1]]
end_comment

begin_comment
comment|// CHECK-LE: call { i64, i64 } @func_f3([2 x i64] %[[TMP3]])
end_comment

begin_comment
comment|// CHECK-BE: call void @func_f3(%struct.f3* sret %[[TMP0]], [2 x i64] %[[TMP3]])
end_comment

begin_decl_stmt
name|struct
name|f3
name|global_f3
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_f3
parameter_list|(
name|void
parameter_list|)
block|{
name|global_f3
operator|=
name|func_f3
argument_list|(
name|global_f3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_f4
end_comment

begin_comment
comment|// CHECK-BE: %[[TMP0:[^ ]+]] = alloca %struct.f4, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [2 x i64], [2 x i64]* bitcast (%struct.f4* @global_f4 to [2 x i64]*), align 4
end_comment

begin_comment
comment|// CHECK-LE: call { i64, i64 } @func_f4([2 x i64] %[[TMP]])
end_comment

begin_comment
comment|// CHECK-BE: call void @func_f4(%struct.f4* sret %[[TMP0]], [2 x i64] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|f4
name|global_f4
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_f4
parameter_list|(
name|void
parameter_list|)
block|{
name|global_f4
operator|=
name|func_f4
argument_list|(
name|global_f4
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_f5
end_comment

begin_comment
comment|// CHECK: %[[TMP0:[^ ]+]] = alloca %struct.f5, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP1:[^ ]+]] = alloca [3 x i64]
end_comment

begin_comment
comment|// CHECK: %[[TMP2:[^ ]+]] = bitcast [3 x i64]* %[[TMP1]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* %[[TMP2]], i8* bitcast (%struct.f5* @global_f5 to i8*), i64 20, i32 4, i1 false)
end_comment

begin_comment
comment|// CHECK: %[[TMP3:[^ ]+]] = load [3 x i64], [3 x i64]* %[[TMP1]]
end_comment

begin_comment
comment|// CHECK: call void @func_f5(%struct.f5* sret %[[TMP0]], [3 x i64] %[[TMP3]])
end_comment

begin_decl_stmt
name|struct
name|f5
name|global_f5
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_f5
parameter_list|(
name|void
parameter_list|)
block|{
name|global_f5
operator|=
name|func_f5
argument_list|(
name|global_f5
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_f6
end_comment

begin_comment
comment|// CHECK: %[[TMP0:[^ ]+]] = alloca %struct.f6, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [3 x i64], [3 x i64]* bitcast (%struct.f6* @global_f6 to [3 x i64]*), align 4
end_comment

begin_comment
comment|// CHECK: call void @func_f6(%struct.f6* sret %[[TMP0]], [3 x i64] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|f6
name|global_f6
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_f6
parameter_list|(
name|void
parameter_list|)
block|{
name|global_f6
operator|=
name|func_f6
argument_list|(
name|global_f6
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_f7
end_comment

begin_comment
comment|// CHECK: %[[TMP0:[^ ]+]] = alloca %struct.f7, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP1:[^ ]+]] = alloca [4 x i64], align 8
end_comment

begin_comment
comment|// CHECK: %[[TMP2:[^ ]+]] = bitcast [4 x i64]* %[[TMP1]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* %[[TMP2]], i8* bitcast (%struct.f7* @global_f7 to i8*), i64 28, i32 4, i1 false)
end_comment

begin_comment
comment|// CHECK: %[[TMP3:[^ ]+]] = load [4 x i64], [4 x i64]* %[[TMP1]], align 8
end_comment

begin_comment
comment|// CHECK: call void @func_f7(%struct.f7* sret %[[TMP0]], [4 x i64] %[[TMP3]])
end_comment

begin_decl_stmt
name|struct
name|f7
name|global_f7
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_f7
parameter_list|(
name|void
parameter_list|)
block|{
name|global_f7
operator|=
name|func_f7
argument_list|(
name|global_f7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_f8
end_comment

begin_comment
comment|// CHECK: %[[TMP0:[^ ]+]] = alloca %struct.f8, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [4 x i64], [4 x i64]* bitcast (%struct.f8* @global_f8 to [4 x i64]*), align 4
end_comment

begin_comment
comment|// CHECK: call void @func_f8(%struct.f8* sret %[[TMP0]], [4 x i64] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|f8
name|global_f8
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_f8
parameter_list|(
name|void
parameter_list|)
block|{
name|global_f8
operator|=
name|func_f8
argument_list|(
name|global_f8
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_f9
end_comment

begin_comment
comment|// CHECK: %[[TMP1:[^ ]+]] = alloca [5 x i64]
end_comment

begin_comment
comment|// CHECK: %[[TMP2:[^ ]+]] = bitcast [5 x i64]* %[[TMP1]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* %[[TMP2]], i8* bitcast (%struct.f9* @global_f9 to i8*), i64 36, i32 4, i1 false)
end_comment

begin_comment
comment|// CHECK: %[[TMP3:[^ ]+]] = load [5 x i64], [5 x i64]* %[[TMP1]]
end_comment

begin_comment
comment|// CHECK: call void @func_f9(%struct.f9* sret %{{[^ ]+}}, [5 x i64] %[[TMP3]])
end_comment

begin_decl_stmt
name|struct
name|f9
name|global_f9
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_f9
parameter_list|(
name|void
parameter_list|)
block|{
name|global_f9
operator|=
name|func_f9
argument_list|(
name|global_f9
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_fab
end_comment

begin_comment
comment|// CHECK: %[[TMP0:[^ ]+]] = alloca %struct.fab, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load i64, i64* bitcast (%struct.fab* @global_fab to i64*), align 4
end_comment

begin_comment
comment|// CHECK-LE: %call = call i64 @func_fab(i64 %[[TMP]])
end_comment

begin_comment
comment|// CHECK-BE: call void @func_fab(%struct.fab* sret %[[TMP0]], i64 %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|fab
name|global_fab
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_fab
parameter_list|(
name|void
parameter_list|)
block|{
name|global_fab
operator|=
name|func_fab
argument_list|(
name|global_fab
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_fabc
end_comment

begin_comment
comment|// CHECK-BE: %[[TMPX:[^ ]+]] = alloca %struct.fabc, align 4
end_comment

begin_comment
comment|// CHECK: %[[TMP0:[^ ]+]] = alloca [2 x i64], align 8
end_comment

begin_comment
comment|// CHECK: %[[TMP2:[^ ]+]] = bitcast [2 x i64]* %[[TMP0]] to i8*
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* %[[TMP2]], i8* bitcast (%struct.fabc* @global_fabc to i8*), i64 12, i32 4, i1 false)
end_comment

begin_comment
comment|// CHECK: %[[TMP3:[^ ]+]] = load [2 x i64], [2 x i64]* %[[TMP0]], align 8
end_comment

begin_comment
comment|// CHECK-LE: %call = call { i64, i64 } @func_fabc([2 x i64] %[[TMP3]])
end_comment

begin_comment
comment|// CHECK-BE: call void @func_fabc(%struct.fabc* sret %[[TMPX]], [2 x i64] %[[TMP3]])
end_comment

begin_decl_stmt
name|struct
name|fabc
name|global_fabc
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_fabc
parameter_list|(
name|void
parameter_list|)
block|{
name|global_fabc
operator|=
name|func_fabc
argument_list|(
name|global_fabc
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

