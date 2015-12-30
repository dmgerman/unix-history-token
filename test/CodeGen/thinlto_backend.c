begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -O2 %s -flto=thin -c -o %t.o
end_comment

begin_comment
comment|// RUN: llvm-lto -thinlto -o %t %t.o
end_comment

begin_comment
comment|// Ensure clang -cc1 give expected error for incorrect input type
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -O2 -o %t1.o %s -c -fthinlto-index=%t.thinlto.bc 2>&1 | FileCheck %s -check-prefix=CHECK-WARNING
end_comment

begin_comment
comment|// CHECK-WARNING: error: invalid argument '-fthinlto-index={{.*}}' only allowed with '-x ir'
end_comment

begin_comment
comment|// Ensure we get expected error for missing index file
end_comment

begin_comment
comment|// RUN: %clang -O2 -o %t1.o -x ir %t.o -c -fthinlto-index=bad.thinlto.bc 2>&1 | FileCheck %s -check-prefix=CHECK-ERROR
end_comment

begin_comment
comment|// CHECK-ERROR: Error loading index file 'bad.thinlto.bc'
end_comment

begin_comment
comment|// Ensure Function Importing pass added
end_comment

begin_comment
comment|// RUN: %clang -O2 -o %t1.o -x ir %t.o -c -fthinlto-index=%t.thinlto.bc -mllvm -debug-pass=Structure 2>&1 | FileCheck %s -check-prefix=CHECK-PASS
end_comment

begin_comment
comment|// CHECK-PASS: Function Importing
end_comment

end_unit

