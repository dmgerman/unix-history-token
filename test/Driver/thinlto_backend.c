begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -O2 %s -flto=thin -c -o %t.o
end_comment

begin_comment
comment|// RUN: llvm-lto -thinlto -o %t %t.o
end_comment

begin_comment
comment|// -fthinlto_index should be passed to cc1
end_comment

begin_comment
comment|// RUN: %clang -O2 -o %t1.o -x ir %t.o -c -fthinlto-index=%t.thinlto.bc -### 2>&1 | FileCheck %s -check-prefix=CHECK-THINLTOBE-ACTION
end_comment

begin_comment
comment|// CHECK-THINLTOBE-ACTION: -fthinlto-index=
end_comment

begin_comment
comment|// Ensure clang driver gives the expected error for incorrect input type
end_comment

begin_comment
comment|// RUN: not %clang -O2 -o %t1.o %s -c -fthinlto-index=%t.thinlto.bc 2>&1 | FileCheck %s -check-prefix=CHECK-WARNING
end_comment

begin_comment
comment|// CHECK-WARNING: error: invalid argument '-fthinlto-index={{.*}}' only allowed with '-x ir'
end_comment

end_unit

