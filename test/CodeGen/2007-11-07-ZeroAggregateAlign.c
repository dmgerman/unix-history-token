begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_struct
struct|struct
name|A
block|{
name|short
name|s
decl_stmt|;
name|short
name|t
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: %a = alloca %struct.A, align 4
end_comment

begin_comment
comment|// CHECK: call void @llvm.memset.p0i8.{{.*}}i32 4, i1 false)
end_comment

begin_function
name|void
name|q
parameter_list|()
block|{
name|struct
name|A
name|a
init|=
block|{
literal|0
block|}
decl_stmt|;
block|}
end_function

end_unit

