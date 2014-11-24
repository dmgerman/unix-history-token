begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Clang does wildcard expansion on Windows. On other OSs, it's done by the shell.
end_comment

begin_comment
comment|// REQUIRES: system-windows
end_comment

begin_comment
comment|// RUN: %clang -c -### %S/Inputs/wildcard*.c 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -c -### %S/Inputs/wildcard?.c 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: wildcard1.c
end_comment

begin_comment
comment|// CHECK: wildcard2.c
end_comment

end_unit

