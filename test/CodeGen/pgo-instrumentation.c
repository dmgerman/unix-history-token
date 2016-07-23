begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test if PGO instrumentation and use pass are invoked.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure Pass PGOInstrumentationGenPass is invoked.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -fprofile-instrument=llvm %s -mllvm -debug-pass=Structure -emit-llvm -o - 2>&1 | FileCheck %s -check-prefix=CHECK-PGOGENPASS-INVOKED-INSTR-GEN
end_comment

begin_comment
comment|// CHECK-PGOGENPASS-INVOKED-INSTR-GEN: PGOInstrumentationGenPass
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure Pass PGOInstrumentationGenPass is not invoked.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -fprofile-instrument=clang %s -mllvm -debug-pass=Structure -emit-llvm -o - 2>&1 | FileCheck %s -check-prefix=CHECK-PGOGENPASS-INVOKED-INSTR-GEN-CLANG
end_comment

begin_comment
comment|// CHECK-PGOGENPASS-INVOKED-INSTR-GEN-CLANG-NOT: PGOInstrumentationGenPass
end_comment

begin_comment
comment|// Ensure Pass PGOInstrumentationUsePass is invoked.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %S/Inputs/pgotestir.profraw
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -fprofile-instrument-use-path=%t.profdata %s -mllvm -debug-pass=Structure -emit-llvm -o - 2>&1 | FileCheck %s -check-prefix=CHECK-PGOUSEPASS-INVOKED-INSTR-USE
end_comment

begin_comment
comment|// CHECK-PGOUSEPASS-INVOKED-INSTR-USE: PGOInstrumentationUsePass
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure Pass PGOInstrumentationUsePass is not invoked.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %S/Inputs/pgotestclang.profraw
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -fprofile-instrument-use-path=%t.profdata %s -mllvm -debug-pass=Structure -emit-llvm -o - 2>&1 | FileCheck %s -check-prefix=CHECK-PGOUSEPASS-INVOKED-USE-CLANG
end_comment

begin_comment
comment|// CHECK-PGOUSEPASS-INVOKED-USE-CLANG-NOT: PGOInstrumentationUsePass
end_comment

end_unit

