begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -fsanitize=float-divide-by-zero -o - | FileCheck %s
end_comment

begin_decl_stmt
name|_Bool
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @f(
end_comment

begin_function
name|double
name|f
parameter_list|()
block|{
comment|// CHECK: %[[B:.*]] = load {{.*}} @b
comment|// CHECK: %[[COND:.*]] = trunc {{.*}} %[[B]] to i1
comment|// CHECK: br i1 %[[COND]]
return|return
name|b
condition|?
literal|0.0
operator|/
literal|0.0
else|:
literal|0.0
return|;
block|}
end_function

end_unit

