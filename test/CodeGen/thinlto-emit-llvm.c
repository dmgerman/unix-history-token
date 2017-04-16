begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test to ensure -emit-llvm and -emit-llvm-bc work when invoking the
end_comment

begin_comment
comment|// ThinLTO backend path.
end_comment

begin_comment
comment|// RUN: %clang -O2 %s -flto=thin -c -o %t.o
end_comment

begin_comment
comment|// RUN: llvm-lto -thinlto -o %t %t.o
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -x ir %t.o -fthinlto-index=%t.thinlto.bc -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -x ir %t.o -fthinlto-index=%t.thinlto.bc -emit-llvm-bc -o - | llvm-dis -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: define void @foo()
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{ }
end_function

end_unit

