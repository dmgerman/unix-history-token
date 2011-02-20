begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pg -triple i386-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: call void @mcount()
block|}
end_function

end_unit

