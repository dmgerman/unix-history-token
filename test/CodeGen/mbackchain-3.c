begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -mno-backchain --target=s390x-linux -S -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define void @foo() [[NUW:#[0-9]+]]
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK-NOT: "backchain"
end_comment

end_unit

