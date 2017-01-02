begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test if PGO sample use passes are invoked.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure Pass PGOInstrumentationGenPass is invoked.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -fprofile-sample-use=%S/Inputs/pgo-sample.prof %s -mllvm -debug-pass=Structure -emit-llvm -o - 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Remove unused exception handling info
end_comment

begin_comment
comment|// CHECK: Sample profile pass
end_comment

end_unit

