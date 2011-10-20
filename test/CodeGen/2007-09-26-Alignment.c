begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_extern
extern|extern p(int *
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|q
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: alloca i32, align 16
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|p
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

