begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc19 -S -emit-llvm %s -o - | FileCheck %s --check-prefix=TARGET-19
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc   -S -emit-llvm %s -o - -fms-compatibility-version=19 | FileCheck %s --check-prefix=OVERRIDE-19
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc-elf -S -emit-llvm %s -o - | FileCheck %s --check-prefix=ELF-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target i686-pc-windows-msvc   -S -emit-llvm %s -o - | FileCheck %s --check-prefix=DEFAULT
end_comment

begin_comment
comment|// TARGET-19:   target triple = "i686-pc-windows-msvc19.0.0"
end_comment

begin_comment
comment|// OVERRIDE-19: target triple = "i686-pc-windows-msvc19.0.0"
end_comment

begin_comment
comment|// ELF-DEFAULT: target triple = "i686-pc-windows-msvc{{.*}}-elf"
end_comment

begin_comment
comment|// DEFAULT:     target triple = "i686-pc-windows-msvc{{[^-]+}}"
end_comment

end_unit

