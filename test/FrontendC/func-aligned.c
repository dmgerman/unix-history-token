begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// rdar://7270273
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(aligned
parameter_list|(
function_decl|64
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// CHECK: define void @foo() {{.*}} align 64
block|}
end_function

end_unit

