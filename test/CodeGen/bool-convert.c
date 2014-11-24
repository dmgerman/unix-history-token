begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// All of these should uses the memory representation of _Bool
end_comment

begin_comment
comment|// CHECK-LABEL: %struct.teststruct1 = type { i8, i8 }
end_comment

begin_comment
comment|// CHECK-LABEL: @test1 = common global %struct.teststruct1
end_comment

begin_struct
struct|struct
name|teststruct1
block|{
name|_Bool
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|test1
struct|;
end_struct

begin_comment
comment|// CHECK-LABEL: @test2 = common global i8* null
end_comment

begin_decl_stmt
name|_Bool
modifier|*
name|test2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: @test3 = common global [10 x i8]
end_comment

begin_decl_stmt
name|_Bool
name|test3
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: @test4 = common global [0 x i8]* null
end_comment

begin_expr_stmt
name|_Bool
argument_list|(
operator|*
name|test4
argument_list|)
index|[]
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK-LABEL: define void @f(i32 %x)
end_comment

begin_function
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK: alloca i8, align 1
name|_Bool
name|test5
decl_stmt|;
comment|// CHECK: alloca i8, i32 %{{.*}}, align 1
name|_Bool
name|test6
index|[
name|x
index|]
decl_stmt|;
block|}
end_function

end_unit

