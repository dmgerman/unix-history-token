begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm %s -o - | FileCheck %s
end_comment

begin_decl_stmt
name|int
modifier|*
name|a
init|=
operator|&
operator|(
name|int
operator|)
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|s
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
block|}
modifier|*
name|b
init|=
operator|&
operator|(
expr|struct
name|s
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
struct|;
end_struct

begin_decl_stmt
specifier|_Complex
name|double
modifier|*
name|x
init|=
operator|&
operator|(
specifier|_Complex
name|double
operator|)
block|{
literal|1.0f
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|v4i32
name|__attribute
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_decl_stmt
name|v4i32
modifier|*
name|y
init|=
operator|&
operator|(
name|v4i32
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|xxx
parameter_list|()
block|{
name|int
modifier|*
name|a
init|=
operator|&
operator|(
name|int
operator|)
block|{
literal|1
block|}
decl_stmt|;
struct|struct
name|s
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
block|}
modifier|*
name|b
init|=
operator|&
operator|(
expr|struct
name|s
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
struct|;
specifier|_Complex
name|double
modifier|*
name|x
init|=
operator|&
operator|(
specifier|_Complex
name|double
operator|)
block|{
literal|1.0f
block|}
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f()
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
typedef|typedef
struct|struct
name|S
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|S
typedef|;
comment|// CHECK: [[S:%[a-zA-Z0-9.]+]] = alloca [[STRUCT:%[a-zA-Z0-9.]+]],
name|struct
name|S
name|s
decl_stmt|;
comment|// CHECK-NEXT: [[COMPOUNDLIT:%[a-zA-Z0-9.]+]] = alloca [[STRUCT]]
comment|// CHECK-NEXT: [[CX:%[a-zA-Z0-9.]+]] = getelementptr inbounds [[STRUCT]]* [[COMPOUNDLIT]], i32 0, i32 0
comment|// CHECK-NEXT: [[SY:%[a-zA-Z0-9.]+]] = getelementptr inbounds [[STRUCT]]* [[S]], i32 0, i32 1
comment|// CHECK-NEXT: [[TMP:%[a-zA-Z0-9.]+]] = load i32* [[SY]]
comment|// CHECK-NEXT: store i32 [[TMP]], i32* [[CX]]
comment|// CHECK-NEXT: [[CY:%[a-zA-Z0-9.]+]] = getelementptr inbounds [[STRUCT]]* [[COMPOUNDLIT]], i32 0, i32 1
comment|// CHECK-NEXT: [[SX:%[a-zA-Z0-9.]+]] = getelementptr inbounds [[STRUCT]]* [[S]], i32 0, i32 0
comment|// CHECK-NEXT: [[TMP:%[a-zA-Z0-9.]+]] = load i32* [[SX]]
comment|// CHECK-NEXT: store i32 [[TMP]], i32* [[CY]]
comment|// CHECK-NEXT: [[SI8:%[a-zA-Z0-9.]+]] = bitcast [[STRUCT]]* [[S]] to i8*
comment|// CHECK-NEXT: [[COMPOUNDLITI8:%[a-zA-Z0-9.]+]] = bitcast [[STRUCT]]* [[COMPOUNDLIT]] to i8*
comment|// CHECK-NEXT: call void @llvm.memcpy{{.*}}(i8* [[SI8]], i8* [[COMPOUNDLITI8]]
name|s
operator|=
operator|(
name|S
operator|)
block|{
name|s
operator|.
name|y
block|,
name|s
operator|.
name|x
block|}
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i48 @g(
end_comment

begin_struct
struct|struct
name|G
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|G
name|g
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|z
parameter_list|)
block|{
comment|// CHECK:      [[RESULT:%.*]] = alloca [[G:%.*]], align 2
comment|// CHECK-NEXT: [[X:%.*]] = alloca i32, align 4
comment|// CHECK-NEXT: [[Y:%.*]] = alloca i32, align 4
comment|// CHECK-NEXT: [[Z:%.*]] = alloca i32, align 4
comment|// CHECK-NEXT: [[COERCE_TEMP:%.*]] = alloca i48
comment|// CHECK-NEXT: store i32
comment|// CHECK-NEXT: store i32
comment|// CHECK-NEXT: store i32
comment|// Evaluate the compound literal directly in the result value slot.
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[G]]* [[RESULT]], i32 0, i32 0
comment|// CHECK-NEXT: [[T1:%.*]] = load i32* [[X]], align 4
comment|// CHECK-NEXT: [[T2:%.*]] = trunc i32 [[T1]] to i16
comment|// CHECK-NEXT: store i16 [[T2]], i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[G]]* [[RESULT]], i32 0, i32 1
comment|// CHECK-NEXT: [[T1:%.*]] = load i32* [[Y]], align 4
comment|// CHECK-NEXT: [[T2:%.*]] = trunc i32 [[T1]] to i16
comment|// CHECK-NEXT: store i16 [[T2]], i16* [[T0]], align 2
comment|// CHECK-NEXT: [[T0:%.*]] = getelementptr inbounds [[G]]* [[RESULT]], i32 0, i32 2
comment|// CHECK-NEXT: [[T1:%.*]] = load i32* [[Z]], align 4
comment|// CHECK-NEXT: [[T2:%.*]] = trunc i32 [[T1]] to i16
comment|// CHECK-NEXT: store i16 [[T2]], i16* [[T0]], align 2
return|return
operator|(
expr|struct
name|G
operator|)
block|{
name|x
block|,
name|y
block|,
name|z
block|}
return|;
comment|// CHECK-NEXT: [[T0:%.*]] = bitcast i48* [[COERCE_TEMP]] to i8*
comment|// CHECK-NEXT: [[T1:%.*]] = bitcast [[G]]* [[RESULT]] to i8*
comment|// CHECK-NEXT: call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[T0]], i8* [[T1]], i64 6
comment|// CHECK-NEXT: [[T0:%.*]] = load i48* [[COERCE_TEMP]]
comment|// CHECK-NEXT: ret i48 [[T0]]
block|}
end_function

end_unit

