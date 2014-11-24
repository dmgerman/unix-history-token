begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-apple-macosx10.4.0 -emit-llvm -o - %s -O2 -disable-llvm-optzns | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|boolsize
init|=
sizeof|sizeof
argument_list|(
name|_Bool
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: boolsize = global i32 4, align 4
end_comment

begin_function
name|void
name|f
parameter_list|(
name|_Bool
modifier|*
name|x
parameter_list|,
name|_Bool
modifier|*
name|y
parameter_list|)
block|{
operator|*
name|x
operator|=
operator|*
name|y
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f(
end_comment

begin_comment
comment|// CHECK: [[FROMMEM:%.*]] = load i32* %
end_comment

begin_comment
comment|// CHECK: [[BOOLVAL:%.*]] = trunc i32 [[FROMMEM]] to i1
end_comment

begin_comment
comment|// CHECK: [[TOMEM:%.*]] = zext i1 [[BOOLVAL]] to i32
end_comment

begin_comment
comment|// CHECK: store i32 [[TOMEM]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK: metadata !{i32 0, i32 2}
end_comment

end_unit

