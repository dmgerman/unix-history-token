begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -O0 -emit-llvm -S -o - | FileCheck %s
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|fold_if
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @fold_if(
comment|// CHECK-NOT: = phi
comment|// CHECK: }
if|if
condition|(
name|a
operator|&&
name|b
condition|)
name|foo
argument_list|()
expr_stmt|;
else|else
name|bar
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

