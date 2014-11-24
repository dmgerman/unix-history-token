begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-linux-gnu %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|void
name|ni
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(flatten)
argument_list|)
end_macro

begin_comment
comment|// CHECK: define void @g()
end_comment

begin_function
name|void
name|g
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-NOT: call {{.*}} @f
name|f
argument_list|()
expr_stmt|;
comment|// CHECK: call {{.*}} @ni
name|ni
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|h
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: call {{.*}} @f
name|f
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

