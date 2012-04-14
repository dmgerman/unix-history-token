begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fdebug-compilation-dir /nonsense -emit-llvm -g %s -o - | FileCheck -check-prefix=CHECK-NONSENSE %s
end_comment

begin_comment
comment|// CHECK-NONSENSE: nonsense
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -g %s -o - | FileCheck -check-prefix=CHECK-DIR %s
end_comment

begin_comment
comment|// CHECK-DIR: CodeGen
end_comment

end_unit

