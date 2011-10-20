begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -mllvm -asm-verbose -S -O2 -g %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Radar 8122864
end_comment

begin_comment
comment|// Code is not generated for function foo, but preserve type information of
end_comment

begin_comment
comment|// local variable xyz.
end_comment

begin_function
specifier|static
name|void
name|foo
parameter_list|()
block|{
comment|// CHECK: DW_TAG_structure_type
struct|struct
name|X
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
name|xyz
struct|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

