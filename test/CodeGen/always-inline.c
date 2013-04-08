begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fno-inline -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: foo
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{ }
end_function

begin_decl_stmt
specifier|inline
name|void
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|)
argument_list|)
name|foo
argument_list|()
block|{
name|bar
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|void
name|i_want_bar
parameter_list|()
block|{
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

