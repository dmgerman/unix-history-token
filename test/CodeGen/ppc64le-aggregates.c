begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -triple powerpc64le-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

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
comment|// CHECK: define [1 x float] @func_f1(float inreg %x.coerce)
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
comment|// CHECK: define [2 x float] @func_f2([2 x float] %x.coerce)
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
comment|// CHECK: define [3 x float] @func_f3([3 x float] %x.coerce)
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
comment|// CHECK: define [4 x float] @func_f4([4 x float] %x.coerce)
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
comment|// CHECK: define [5 x float] @func_f5([5 x float] %x.coerce)
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
comment|// CHECK: define [6 x float] @func_f6([6 x float] %x.coerce)
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
comment|// CHECK: define [7 x float] @func_f7([7 x float] %x.coerce)
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
comment|// CHECK: define [8 x float] @func_f8([8 x float] %x.coerce)
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
comment|// CHECK: define [2 x float] @func_fab([2 x float] %x.coerce)
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
comment|// CHECK: define [3 x float] @func_fabc([3 x float] %x.coerce)
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
comment|// CHECK: define [4 x float] @func_f2a2b([4 x float] %x.coerce)
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
comment|// CHECK: %[[TMP:[^ ]+]] = load float, float* getelementptr inbounds (%struct.f1, %struct.f1* @global_f1, i32 0, i32 0, i32 0), align 4
end_comment

begin_comment
comment|// CHECK: call [1 x float] @func_f1(float inreg %[[TMP]])
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
comment|// CHECK: %[[TMP:[^ ]+]] = load [2 x float], [2 x float]* getelementptr inbounds (%struct.f2, %struct.f2* @global_f2, i32 0, i32 0), align 4
end_comment

begin_comment
comment|// CHECK: call [2 x float] @func_f2([2 x float] %[[TMP]])
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
comment|// CHECK: %[[TMP:[^ ]+]] = load [3 x float], [3 x float]* getelementptr inbounds (%struct.f3, %struct.f3* @global_f3, i32 0, i32 0), align 4
end_comment

begin_comment
comment|// CHECK: call [3 x float] @func_f3([3 x float] %[[TMP]])
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
comment|// CHECK: %[[TMP:[^ ]+]] = load [4 x float], [4 x float]* getelementptr inbounds (%struct.f4, %struct.f4* @global_f4, i32 0, i32 0), align 4
end_comment

begin_comment
comment|// CHECK: call [4 x float] @func_f4([4 x float] %[[TMP]])
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
comment|// CHECK: %[[TMP:[^ ]+]] = load [5 x float], [5 x float]* getelementptr inbounds (%struct.f5, %struct.f5* @global_f5, i32 0, i32 0), align 4
end_comment

begin_comment
comment|// CHECK: call [5 x float] @func_f5([5 x float] %[[TMP]])
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
comment|// CHECK: %[[TMP:[^ ]+]] = load [6 x float], [6 x float]* getelementptr inbounds (%struct.f6, %struct.f6* @global_f6, i32 0, i32 0), align 4
end_comment

begin_comment
comment|// CHECK: call [6 x float] @func_f6([6 x float] %[[TMP]])
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
comment|// CHECK: %[[TMP:[^ ]+]] = load [7 x float], [7 x float]* getelementptr inbounds (%struct.f7, %struct.f7* @global_f7, i32 0, i32 0), align 4
end_comment

begin_comment
comment|// CHECK: call [7 x float] @func_f7([7 x float] %[[TMP]])
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
comment|// CHECK: %[[TMP:[^ ]+]] = load [8 x float], [8 x float]* getelementptr inbounds (%struct.f8, %struct.f8* @global_f8, i32 0, i32 0), align 4
end_comment

begin_comment
comment|// CHECK: call [8 x float] @func_f8([8 x float] %[[TMP]])
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
comment|// CHECK: %[[TMP:[^ ]+]] = load [2 x float], [2 x float]* bitcast (%struct.fab* @global_fab to [2 x float]*)
end_comment

begin_comment
comment|// CHECK: call [2 x float] @func_fab([2 x float] %[[TMP]])
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
comment|// CHECK: %[[TMP:[^ ]+]] = load [3 x float], [3 x float]* bitcast (%struct.fabc* @global_fabc to [3 x float]*)
end_comment

begin_comment
comment|// CHECK: call [3 x float] @func_fabc([3 x float] %[[TMP]])
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

begin_comment
comment|// Test homogeneous vector aggregate passing and returning.
end_comment

begin_struct
struct|struct
name|v1
block|{
name|vector
name|int
name|v
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v2
block|{
name|vector
name|int
name|v
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3
block|{
name|vector
name|int
name|v
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4
block|{
name|vector
name|int
name|v
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v5
block|{
name|vector
name|int
name|v
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v6
block|{
name|vector
name|int
name|v
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v7
block|{
name|vector
name|int
name|v
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v8
block|{
name|vector
name|int
name|v
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v9
block|{
name|vector
name|int
name|v
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vab
block|{
name|vector
name|int
name|a
decl_stmt|;
name|vector
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vabc
block|{
name|vector
name|int
name|a
decl_stmt|;
name|vector
name|int
name|b
decl_stmt|;
name|vector
name|int
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define [1 x<4 x i32>] @func_v1(<4 x i32> inreg %x.coerce)
end_comment

begin_function
name|struct
name|v1
name|func_v1
parameter_list|(
name|struct
name|v1
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [2 x<4 x i32>] @func_v2([2 x<4 x i32>] %x.coerce)
end_comment

begin_function
name|struct
name|v2
name|func_v2
parameter_list|(
name|struct
name|v2
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [3 x<4 x i32>] @func_v3([3 x<4 x i32>] %x.coerce)
end_comment

begin_function
name|struct
name|v3
name|func_v3
parameter_list|(
name|struct
name|v3
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [4 x<4 x i32>] @func_v4([4 x<4 x i32>] %x.coerce)
end_comment

begin_function
name|struct
name|v4
name|func_v4
parameter_list|(
name|struct
name|v4
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [5 x<4 x i32>] @func_v5([5 x<4 x i32>] %x.coerce)
end_comment

begin_function
name|struct
name|v5
name|func_v5
parameter_list|(
name|struct
name|v5
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [6 x<4 x i32>] @func_v6([6 x<4 x i32>] %x.coerce)
end_comment

begin_function
name|struct
name|v6
name|func_v6
parameter_list|(
name|struct
name|v6
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [7 x<4 x i32>] @func_v7([7 x<4 x i32>] %x.coerce)
end_comment

begin_function
name|struct
name|v7
name|func_v7
parameter_list|(
name|struct
name|v7
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [8 x<4 x i32>] @func_v8([8 x<4 x i32>] %x.coerce)
end_comment

begin_function
name|struct
name|v8
name|func_v8
parameter_list|(
name|struct
name|v8
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @func_v9(%struct.v9* noalias sret %agg.result, %struct.v9* byval align 16 %x)
end_comment

begin_function
name|struct
name|v9
name|func_v9
parameter_list|(
name|struct
name|v9
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [2 x<4 x i32>] @func_vab([2 x<4 x i32>] %x.coerce)
end_comment

begin_function
name|struct
name|vab
name|func_vab
parameter_list|(
name|struct
name|vab
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [3 x<4 x i32>] @func_vabc([3 x<4 x i32>] %x.coerce)
end_comment

begin_function
name|struct
name|vabc
name|func_vabc
parameter_list|(
name|struct
name|vabc
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v1
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load<4 x i32>,<4 x i32>* getelementptr inbounds (%struct.v1, %struct.v1* @global_v1, i32 0, i32 0, i32 0), align 1
end_comment

begin_comment
comment|// CHECK: call [1 x<4 x i32>] @func_v1(<4 x i32> inreg %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v1
name|global_v1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v1
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v1
operator|=
name|func_v1
argument_list|(
name|global_v1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v2
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [2 x<4 x i32>], [2 x<4 x i32>]* getelementptr inbounds (%struct.v2, %struct.v2* @global_v2, i32 0, i32 0), align 1
end_comment

begin_comment
comment|// CHECK: call [2 x<4 x i32>] @func_v2([2 x<4 x i32>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v2
name|global_v2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v2
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v2
operator|=
name|func_v2
argument_list|(
name|global_v2
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [3 x<4 x i32>], [3 x<4 x i32>]* getelementptr inbounds (%struct.v3, %struct.v3* @global_v3, i32 0, i32 0), align 1
end_comment

begin_comment
comment|// CHECK: call [3 x<4 x i32>] @func_v3([3 x<4 x i32>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3
name|global_v3
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3
operator|=
name|func_v3
argument_list|(
name|global_v3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v4
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [4 x<4 x i32>], [4 x<4 x i32>]* getelementptr inbounds (%struct.v4, %struct.v4* @global_v4, i32 0, i32 0), align 1
end_comment

begin_comment
comment|// CHECK: call [4 x<4 x i32>] @func_v4([4 x<4 x i32>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v4
name|global_v4
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v4
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v4
operator|=
name|func_v4
argument_list|(
name|global_v4
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v5
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [5 x<4 x i32>], [5 x<4 x i32>]* getelementptr inbounds (%struct.v5, %struct.v5* @global_v5, i32 0, i32 0), align 1
end_comment

begin_comment
comment|// CHECK: call [5 x<4 x i32>] @func_v5([5 x<4 x i32>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v5
name|global_v5
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v5
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v5
operator|=
name|func_v5
argument_list|(
name|global_v5
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v6
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [6 x<4 x i32>], [6 x<4 x i32>]* getelementptr inbounds (%struct.v6, %struct.v6* @global_v6, i32 0, i32 0), align 1
end_comment

begin_comment
comment|// CHECK: call [6 x<4 x i32>] @func_v6([6 x<4 x i32>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v6
name|global_v6
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v6
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v6
operator|=
name|func_v6
argument_list|(
name|global_v6
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v7
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [7 x<4 x i32>], [7 x<4 x i32>]* getelementptr inbounds (%struct.v7, %struct.v7* @global_v7, i32 0, i32 0), align 1
end_comment

begin_comment
comment|// CHECK: call [7 x<4 x i32>] @func_v7([7 x<4 x i32>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v7
name|global_v7
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v7
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v7
operator|=
name|func_v7
argument_list|(
name|global_v7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v8
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [8 x<4 x i32>], [8 x<4 x i32>]* getelementptr inbounds (%struct.v8, %struct.v8* @global_v8, i32 0, i32 0), align 1
end_comment

begin_comment
comment|// CHECK: call [8 x<4 x i32>] @func_v8([8 x<4 x i32>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v8
name|global_v8
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v8
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v8
operator|=
name|func_v8
argument_list|(
name|global_v8
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v9
end_comment

begin_comment
comment|// CHECK: call void @func_v9(%struct.v9* sret %{{[^ ]+}}, %struct.v9* byval align 16 @global_v9)
end_comment

begin_decl_stmt
name|struct
name|v9
name|global_v9
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v9
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v9
operator|=
name|func_v9
argument_list|(
name|global_v9
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_vab
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [2 x<4 x i32>], [2 x<4 x i32>]* bitcast (%struct.vab* @global_vab to [2 x<4 x i32>]*)
end_comment

begin_comment
comment|// CHECK: call [2 x<4 x i32>] @func_vab([2 x<4 x i32>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|vab
name|global_vab
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_vab
parameter_list|(
name|void
parameter_list|)
block|{
name|global_vab
operator|=
name|func_vab
argument_list|(
name|global_vab
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_vabc
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [3 x<4 x i32>], [3 x<4 x i32>]* bitcast (%struct.vabc* @global_vabc to [3 x<4 x i32>]*)
end_comment

begin_comment
comment|// CHECK: call [3 x<4 x i32>] @func_vabc([3 x<4 x i32>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|vabc
name|global_vabc
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_vabc
parameter_list|(
name|void
parameter_list|)
block|{
name|global_vabc
operator|=
name|func_vabc
argument_list|(
name|global_vabc
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// As clang extension, non-power-of-two vectors may also be part of
end_comment

begin_comment
comment|// homogeneous aggregates.
end_comment

begin_typedef
typedef|typedef
name|float
name|float3
name|__attribute__
typedef|((
name|vector_size
typedef|(12)));
end_typedef

begin_struct
struct|struct
name|v3f1
block|{
name|float3
name|v
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3f2
block|{
name|float3
name|v
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3f3
block|{
name|float3
name|v
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3f4
block|{
name|float3
name|v
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3f5
block|{
name|float3
name|v
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3f6
block|{
name|float3
name|v
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3f7
block|{
name|float3
name|v
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3f8
block|{
name|float3
name|v
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3f9
block|{
name|float3
name|v
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3fab
block|{
name|float3
name|a
decl_stmt|;
name|float3
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v3fabc
block|{
name|float3
name|a
decl_stmt|;
name|float3
name|b
decl_stmt|;
name|float3
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define [1 x<4 x float>] @func_v3f1(<3 x float> inreg %x.coerce)
end_comment

begin_function
name|struct
name|v3f1
name|func_v3f1
parameter_list|(
name|struct
name|v3f1
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [2 x<4 x float>] @func_v3f2([2 x<4 x float>] %x.coerce)
end_comment

begin_function
name|struct
name|v3f2
name|func_v3f2
parameter_list|(
name|struct
name|v3f2
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [3 x<4 x float>] @func_v3f3([3 x<4 x float>] %x.coerce)
end_comment

begin_function
name|struct
name|v3f3
name|func_v3f3
parameter_list|(
name|struct
name|v3f3
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [4 x<4 x float>] @func_v3f4([4 x<4 x float>] %x.coerce)
end_comment

begin_function
name|struct
name|v3f4
name|func_v3f4
parameter_list|(
name|struct
name|v3f4
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [5 x<4 x float>] @func_v3f5([5 x<4 x float>] %x.coerce)
end_comment

begin_function
name|struct
name|v3f5
name|func_v3f5
parameter_list|(
name|struct
name|v3f5
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [6 x<4 x float>] @func_v3f6([6 x<4 x float>] %x.coerce)
end_comment

begin_function
name|struct
name|v3f6
name|func_v3f6
parameter_list|(
name|struct
name|v3f6
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [7 x<4 x float>] @func_v3f7([7 x<4 x float>] %x.coerce)
end_comment

begin_function
name|struct
name|v3f7
name|func_v3f7
parameter_list|(
name|struct
name|v3f7
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [8 x<4 x float>] @func_v3f8([8 x<4 x float>] %x.coerce)
end_comment

begin_function
name|struct
name|v3f8
name|func_v3f8
parameter_list|(
name|struct
name|v3f8
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @func_v3f9(%struct.v3f9* noalias sret %agg.result, %struct.v3f9* byval align 16 %x)
end_comment

begin_function
name|struct
name|v3f9
name|func_v3f9
parameter_list|(
name|struct
name|v3f9
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [2 x<4 x float>] @func_v3fab([2 x<4 x float>] %x.coerce)
end_comment

begin_function
name|struct
name|v3fab
name|func_v3fab
parameter_list|(
name|struct
name|v3fab
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define [3 x<4 x float>] @func_v3fabc([3 x<4 x float>] %x.coerce)
end_comment

begin_function
name|struct
name|v3fabc
name|func_v3fabc
parameter_list|(
name|struct
name|v3fabc
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3f1
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load<3 x float>,<3 x float>* getelementptr inbounds (%struct.v3f1, %struct.v3f1* @global_v3f1, i32 0, i32 0, i32 0), align 1
end_comment

begin_comment
comment|// CHECK: call [1 x<4 x float>] @func_v3f1(<3 x float> inreg %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3f1
name|global_v3f1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3f1
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3f1
operator|=
name|func_v3f1
argument_list|(
name|global_v3f1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3f2
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [2 x<4 x float>], [2 x<4 x float>]* bitcast (%struct.v3f2* @global_v3f2 to [2 x<4 x float>]*), align 16
end_comment

begin_comment
comment|// CHECK: call [2 x<4 x float>] @func_v3f2([2 x<4 x float>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3f2
name|global_v3f2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3f2
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3f2
operator|=
name|func_v3f2
argument_list|(
name|global_v3f2
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3f3
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [3 x<4 x float>], [3 x<4 x float>]* bitcast (%struct.v3f3* @global_v3f3 to [3 x<4 x float>]*), align 16
end_comment

begin_comment
comment|// CHECK: call [3 x<4 x float>] @func_v3f3([3 x<4 x float>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3f3
name|global_v3f3
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3f3
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3f3
operator|=
name|func_v3f3
argument_list|(
name|global_v3f3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3f4
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [4 x<4 x float>], [4 x<4 x float>]* bitcast (%struct.v3f4* @global_v3f4 to [4 x<4 x float>]*), align 16
end_comment

begin_comment
comment|// CHECK: call [4 x<4 x float>] @func_v3f4([4 x<4 x float>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3f4
name|global_v3f4
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3f4
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3f4
operator|=
name|func_v3f4
argument_list|(
name|global_v3f4
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3f5
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [5 x<4 x float>], [5 x<4 x float>]* bitcast (%struct.v3f5* @global_v3f5 to [5 x<4 x float>]*), align 16
end_comment

begin_comment
comment|// CHECK: call [5 x<4 x float>] @func_v3f5([5 x<4 x float>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3f5
name|global_v3f5
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3f5
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3f5
operator|=
name|func_v3f5
argument_list|(
name|global_v3f5
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3f6
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [6 x<4 x float>], [6 x<4 x float>]* bitcast (%struct.v3f6* @global_v3f6 to [6 x<4 x float>]*), align 16
end_comment

begin_comment
comment|// CHECK: call [6 x<4 x float>] @func_v3f6([6 x<4 x float>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3f6
name|global_v3f6
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3f6
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3f6
operator|=
name|func_v3f6
argument_list|(
name|global_v3f6
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3f7
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [7 x<4 x float>], [7 x<4 x float>]* bitcast (%struct.v3f7* @global_v3f7 to [7 x<4 x float>]*), align 16
end_comment

begin_comment
comment|// CHECK: call [7 x<4 x float>] @func_v3f7([7 x<4 x float>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3f7
name|global_v3f7
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3f7
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3f7
operator|=
name|func_v3f7
argument_list|(
name|global_v3f7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3f8
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [8 x<4 x float>], [8 x<4 x float>]* bitcast (%struct.v3f8* @global_v3f8 to [8 x<4 x float>]*), align 16
end_comment

begin_comment
comment|// CHECK: call [8 x<4 x float>] @func_v3f8([8 x<4 x float>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3f8
name|global_v3f8
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3f8
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3f8
operator|=
name|func_v3f8
argument_list|(
name|global_v3f8
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3f9
end_comment

begin_comment
comment|// CHECK: call void @func_v3f9(%struct.v3f9* sret %{{[^ ]+}}, %struct.v3f9* byval align 16 @global_v3f9)
end_comment

begin_decl_stmt
name|struct
name|v3f9
name|global_v3f9
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3f9
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3f9
operator|=
name|func_v3f9
argument_list|(
name|global_v3f9
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3fab
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [2 x<4 x float>], [2 x<4 x float>]* bitcast (%struct.v3fab* @global_v3fab to [2 x<4 x float>]*), align 16
end_comment

begin_comment
comment|// CHECK: call [2 x<4 x float>] @func_v3fab([2 x<4 x float>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3fab
name|global_v3fab
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3fab
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3fab
operator|=
name|func_v3fab
argument_list|(
name|global_v3fab
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @call_v3fabc
end_comment

begin_comment
comment|// CHECK: %[[TMP:[^ ]+]] = load [3 x<4 x float>], [3 x<4 x float>]* bitcast (%struct.v3fabc* @global_v3fabc to [3 x<4 x float>]*), align 16
end_comment

begin_comment
comment|// CHECK: call [3 x<4 x float>] @func_v3fabc([3 x<4 x float>] %[[TMP]])
end_comment

begin_decl_stmt
name|struct
name|v3fabc
name|global_v3fabc
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|call_v3fabc
parameter_list|(
name|void
parameter_list|)
block|{
name|global_v3fabc
operator|=
name|func_v3fabc
argument_list|(
name|global_v3fabc
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test returning small aggregates.
end_comment

begin_struct
struct|struct
name|s1
block|{
name|char
name|c
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s2
block|{
name|char
name|c
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s3
block|{
name|char
name|c
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s4
block|{
name|char
name|c
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s5
block|{
name|char
name|c
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s6
block|{
name|char
name|c
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s7
block|{
name|char
name|c
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s8
block|{
name|char
name|c
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s9
block|{
name|char
name|c
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s16
block|{
name|char
name|c
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s17
block|{
name|char
name|c
index|[
literal|17
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define i8 @ret_s1()
end_comment

begin_function
name|struct
name|s1
name|ret_s1
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s1
operator|)
block|{
literal|17
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i16 @ret_s2()
end_comment

begin_function
name|struct
name|s2
name|ret_s2
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s2
operator|)
block|{
literal|17
block|,
literal|18
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i24 @ret_s3()
end_comment

begin_function
name|struct
name|s3
name|ret_s3
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s3
operator|)
block|{
literal|17
block|,
literal|18
block|,
literal|19
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i32 @ret_s4()
end_comment

begin_function
name|struct
name|s4
name|ret_s4
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s4
operator|)
block|{
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i40 @ret_s5()
end_comment

begin_function
name|struct
name|s5
name|ret_s5
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s5
operator|)
block|{
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i48 @ret_s6()
end_comment

begin_function
name|struct
name|s6
name|ret_s6
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s6
operator|)
block|{
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i56 @ret_s7()
end_comment

begin_function
name|struct
name|s7
name|ret_s7
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s7
operator|)
block|{
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i64 @ret_s8()
end_comment

begin_function
name|struct
name|s8
name|ret_s8
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s8
operator|)
block|{
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { i64, i64 } @ret_s9()
end_comment

begin_function
name|struct
name|s9
name|ret_s9
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s9
operator|)
block|{
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define { i64, i64 } @ret_s16()
end_comment

begin_function
name|struct
name|s16
name|ret_s16
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s16
operator|)
block|{
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|}
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @ret_s17(%struct.s17*
end_comment

begin_function
name|struct
name|s17
name|ret_s17
parameter_list|()
block|{
return|return
operator|(
expr|struct
name|s17
operator|)
block|{
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|}
return|;
block|}
end_function

end_unit

