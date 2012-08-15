begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-win32 -emit-llvm -fms-extensions< %s | FileCheck %s
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{ }
end_function

begin_comment
comment|// CHECK-NOT: foo
end_comment

begin_function
name|__forceinline
name|void
name|foo
parameter_list|()
block|{
name|bar
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|i_want_bar
parameter_list|()
block|{
comment|// CHECK: call void @bar
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

