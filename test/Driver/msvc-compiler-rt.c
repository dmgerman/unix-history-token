begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-pc-windows-msvc --rtlib=compiler-rt -### %s 2>&1 | FileCheck %s -check-prefix MSVC-COMPILER-RT
end_comment

begin_comment
comment|// RUN: not %clang %s -target x86_64-pc-windows-msvc --rtlib=libgcc 2>&1 | FileCheck %s -check-prefix CHECK-ERROR
end_comment

begin_comment
comment|// MSVC-COMPILER-RT: "{{.*}}clang_rt.builtins{{.*}}"
end_comment

begin_comment
comment|// CHECK-ERROR: unsupported runtime library 'libgcc' for platform 'MSVC'
end_comment

end_unit

