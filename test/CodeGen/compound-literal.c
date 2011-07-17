begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
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

begin_comment
comment|// Not working; complex constants are broken
end_comment

begin_comment
comment|// _Complex double * x =&(_Complex double){1.0f};
end_comment

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
comment|// CHECK: define void @f()
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

end_unit

