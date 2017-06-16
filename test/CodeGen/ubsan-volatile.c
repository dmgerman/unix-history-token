begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsanitize=null,alignment,object-size,vptr -S -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @volatile_null_deref
end_comment

begin_function
name|void
name|volatile_null_deref
parameter_list|(
specifier|volatile
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-NOT: call{{.*}}ubsan
operator|*
name|p
expr_stmt|;
block|}
end_function

end_unit

