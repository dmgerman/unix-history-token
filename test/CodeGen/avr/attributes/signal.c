begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple avr-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define void @foo() #0
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(signal)
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: attributes #0 = {{{.*signal.*}}}
end_comment

end_unit

