begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Check that we don't generate unnecessary reloads.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f0()
end_comment

begin_comment
comment|// CHECK:      [[x_0:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK-NEXT: [[y_0:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 1, i32* [[x_0]]
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 1, i32* [[x_0]]
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 1, i32* [[y_0]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|x
operator|=
literal|1
expr_stmt|;
name|y
operator|=
operator|(
name|x
operator|=
literal|1
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// This used to test that we generate reloads for volatile access,
end_comment

begin_comment
comment|// but that does not appear to be correct behavior for C.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define void @f1()
end_comment

begin_comment
comment|// CHECK:      [[x_1:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK-NEXT: [[y_1:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK-NEXT: store volatile i32 1, i32* [[x_1]]
end_comment

begin_comment
comment|// CHECK-NEXT: store volatile i32 1, i32* [[x_1]]
end_comment

begin_comment
comment|// CHECK-NEXT: store volatile i32 1, i32* [[y_1]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
specifier|volatile
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|x
operator|=
literal|1
expr_stmt|;
name|y
operator|=
operator|(
name|x
operator|=
literal|1
operator|)
expr_stmt|;
block|}
end_function

end_unit

