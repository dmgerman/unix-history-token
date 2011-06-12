begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -triple x86_64-apple-darwin10< %s | FileCheck %s
end_comment

begin_struct
struct|struct
name|Test1S
block|{
name|long
name|NumDecls
decl_stmt|;
name|long
name|X
decl_stmt|;
name|long
name|Y
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Test2S
block|{
name|long
name|NumDecls
decl_stmt|;
name|long
name|X
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Make sure we don't generate extra memcpy for lvalues
end_comment

begin_function_decl
name|void
name|test1a
parameter_list|(
name|struct
name|Test1S
parameter_list|,
name|struct
name|Test2S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: define void @test1(
end_comment

begin_comment
comment|// CHECK-NOT: memcpy
end_comment

begin_comment
comment|// CHECK: call void @test1a
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|struct
name|Test1S
modifier|*
name|A
parameter_list|,
name|struct
name|Test2S
modifier|*
name|B
parameter_list|)
block|{
name|test1a
argument_list|(
operator|*
name|A
argument_list|,
operator|*
name|B
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

