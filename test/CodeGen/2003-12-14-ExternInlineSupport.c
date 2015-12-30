begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple %itanium_abi_triple -std=gnu89 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function
specifier|extern
name|__inline__
name|void
name|dead_function
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK-NOT: dead_function
end_comment

end_unit

