begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Test checks that 'mode' attribute is handled correctly with enums, i. e. code
end_comment

begin_comment
comment|//   1. "typedef enum { A } __attribute__((mode(HI))) T;" is accepted,
end_comment

begin_comment
comment|//   2. "enum X __attribute__((mode(QI))) var;" forms a complete integer type.
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: [[X1:%.+]] = alloca i8
enum|enum
block|{
name|A1
block|,
name|B1
block|}
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
name|x1
init|=
name|A1
enum|;
comment|// CHECK: [[X2:%.+]] = alloca i16
enum|enum
block|{
name|A2
block|,
name|B2
block|}
name|x2
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|HI
argument_list|)
operator|)
argument_list|)
init|=
name|B2
enum|;
comment|// CHECK: [[X3:%.+]] = alloca i32
typedef|typedef
enum|enum
block|{
name|A3
block|,
name|B3
block|}
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)))
name|T3
typedef|;
name|T3
name|x3
init|=
name|A3
decl_stmt|;
comment|// CHECK: [[X4:%.+]] = alloca i64
typedef|typedef
enum|enum
block|{
name|A4
block|,
name|B4
block|}
name|T4
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
name|T4
name|x4
init|=
name|B4
decl_stmt|;
comment|// CHECK: [[X5:%.+]] = alloca i8
typedef|typedef
name|enum
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
block|{
name|A5
operator|,
name|B5
block|}
name|T5
expr_stmt|;
name|T5
name|x5
init|=
name|A5
decl_stmt|;
comment|// CHECK: [[X6:%.+]] = alloca i8
typedef|typedef
name|enum
name|X
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
name|T6
typedef|;
name|T6
name|x6
decl_stmt|;
comment|// CHECK: [[X7:%.+]] = alloca i128
enum|enum
block|{
name|A7
block|,
name|B7
block|}
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|TI
argument_list|)
operator|)
argument_list|)
name|x7
init|=
name|A7
enum|;
comment|// CHECK: [[X8:%.+]] = alloca i8
name|enum
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
block|{
name|A8
operator|,
name|B8
block|}
name|x8
operator|=
name|B8
expr_stmt|;
comment|// CHECK: store i8 0, i8* [[X1]]
comment|// CHECK: store i16 1, i16* [[X2]]
comment|// CHECK: store i32 0, i32* [[X3]]
comment|// CHECK: store i64 1, i64* [[X4]]
comment|// CHECK: store i8 0, i8* [[X5]]
comment|// CHECK: store i128 0, i128* [[X7]]
comment|// CHECK: store i8 1, i8* [[X8]]
return|return
name|x1
operator|+
name|x2
operator|+
name|x3
operator|+
name|x4
operator|+
name|x5
operator|+
name|x6
operator|+
name|x7
operator|+
name|x8
return|;
block|}
end_function

end_unit

