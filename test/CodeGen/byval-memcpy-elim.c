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
comment|// CHECK-LABEL: define void @test1(
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

begin_comment
comment|// The above gets tricker when the byval argument requires higher alignment
end_comment

begin_comment
comment|// than the natural alignment of the type in question.
end_comment

begin_comment
comment|// rdar://9483886
end_comment

begin_comment
comment|// Make sure we do generate a memcpy when we cannot guarantee alignment.
end_comment

begin_struct
struct|struct
name|Test3S
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|,
name|e
decl_stmt|,
name|f
decl_stmt|,
name|g
decl_stmt|,
name|h
decl_stmt|,
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|,
name|l
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|test2a
parameter_list|(
name|struct
name|Test3S
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @test2(
end_comment

begin_comment
comment|// CHECK: alloca %struct.Test3S, align 8
end_comment

begin_comment
comment|// CHECK: memcpy
end_comment

begin_comment
comment|// CHECK: call void @test2a
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|struct
name|Test3S
modifier|*
name|q
parameter_list|)
block|{
name|test2a
argument_list|(
operator|*
name|q
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// But make sure we don't generate a memcpy when we can guarantee alignment.
end_comment

begin_function_decl
name|void
name|fooey
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: define void @test3(
end_comment

begin_comment
comment|// CHECK: alloca %struct.Test3S, align 8
end_comment

begin_comment
comment|// CHECK: call void @fooey
end_comment

begin_comment
comment|// CHECK-NOT: memcpy
end_comment

begin_comment
comment|// CHECK: call void @test2a
end_comment

begin_comment
comment|// CHECK-NOT: memcpy
end_comment

begin_comment
comment|// CHECK: call void @test2a
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|struct
name|Test3S
name|a
parameter_list|)
block|{
name|struct
name|Test3S
name|b
init|=
name|a
decl_stmt|;
name|fooey
argument_list|()
expr_stmt|;
name|test2a
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|test2a
argument_list|(
name|b
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

