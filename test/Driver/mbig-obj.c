begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang --target=x86_64-windows -c -Wa,-mbig-obj %s -### 2>&1 | FileCheck %s --check-prefix=WINDOWS
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-windows -c -Xassembler -mbig-obj %s -### 2>&1 | FileCheck %s --check-prefix=WINDOWS
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-linux -c -Wa,-mbig-obj %s -### 2>&1 | FileCheck %s --check-prefix=LINUX
end_comment

begin_comment
comment|// RUN: %clang --target=x86_64-linux -c -Xassembler -mbig-obj %s -### 2>&1 | FileCheck %s --check-prefix=LINUX
end_comment

begin_comment
comment|// WINDOWS-NOT: argument unused during compilation
end_comment

begin_comment
comment|// LINUX: unsupported argument '-mbig-obj' to option '{{(Wa,|Xassembler)}}'
end_comment

end_unit

