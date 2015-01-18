begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -triple arm-apple-darwin -o - | FileCheck %s
end_comment

begin_comment
comment|// PR 5406
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|x
index|[
literal|3
index|]
decl_stmt|;
block|}
name|A0
typedef|;
end_typedef

begin_function_decl
name|void
name|foo
parameter_list|(
name|int
name|i
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: call void (i32, ...)* @foo(i32 1, [1 x i32] {{.*}})
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|A0
name|a3
decl_stmt|;
name|a3
operator|.
name|x
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|a3
operator|.
name|x
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|a3
operator|.
name|x
index|[
literal|2
index|]
operator|=
literal|26
expr_stmt|;
name|foo
argument_list|(
literal|1
argument_list|,
name|a3
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

