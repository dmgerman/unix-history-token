begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -flto causes a switch to llvm-bc object files.
end_comment

begin_comment
comment|// RUN: %clang -ccc-print-phases -c %s -flto 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-COMPILE-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-COMPILE-ACTIONS: 2: compiler, {1}, ir
end_comment

begin_comment
comment|// CHECK-COMPILE-ACTIONS: 3: backend, {2}, lto-bc
end_comment

begin_comment
comment|// RUN: %clang -ccc-print-phases %s -flto 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-COMPILELINK-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-COMPILELINK-ACTIONS: 0: input, "{{.*}}lto.c", c
end_comment

begin_comment
comment|// CHECK-COMPILELINK-ACTIONS: 1: preprocessor, {0}, cpp-output
end_comment

begin_comment
comment|// CHECK-COMPILELINK-ACTIONS: 2: compiler, {1}, ir
end_comment

begin_comment
comment|// CHECK-COMPILELINK-ACTIONS: 3: backend, {2}, lto-bc
end_comment

begin_comment
comment|// CHECK-COMPILELINK-ACTIONS: 4: linker, {3}, image
end_comment

begin_comment
comment|// llvm-bc and llvm-ll outputs need to match regular suffixes
end_comment

begin_comment
comment|// (unfortunately).
end_comment

begin_comment
comment|// RUN: %clang %s -flto -save-temps -### 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-COMPILELINK-SUFFIXES< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-COMPILELINK-SUFFIXES: "-o" "{{.*}}lto.i" "-x" "c" "{{.*}}lto.c"
end_comment

begin_comment
comment|// CHECK-COMPILELINK-SUFFIXES: "-o" "{{.*}}lto.bc" {{.*}}"{{.*}}lto.i"
end_comment

begin_comment
comment|// CHECK-COMPILELINK-SUFFIXES: "-o" "{{.*}}lto.o" {{.*}}"{{.*}}lto.bc"
end_comment

begin_comment
comment|// CHECK-COMPILELINK-SUFFIXES: "{{.*}}a.{{(out|exe)}}" {{.*}}"{{.*}}lto.o"
end_comment

begin_comment
comment|// RUN: %clang %s -flto -S -### 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-COMPILE-SUFFIXES< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-COMPILE-SUFFIXES: "-o" "{{.*}}lto.s" "-x" "c" "{{.*}}lto.c"
end_comment

begin_comment
comment|// RUN: not %clang %s -emit-llvm 2>&1 | FileCheck --check-prefix=LLVM-LINK %s
end_comment

begin_comment
comment|// LLVM-LINK: -emit-llvm cannot be used when linking
end_comment

begin_comment
comment|// -flto should cause link using gold plugin
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-LINK-LTO-ACTION< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINK-LTO-ACTION: "-plugin" "{{.*}}/LLVMgold.so"
end_comment

begin_comment
comment|// -flto=full should cause link using gold plugin
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto=full 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-LINK-FULL-ACTION< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINK-FULL-ACTION: "-plugin" "{{.*}}/LLVMgold.so"
end_comment

begin_comment
comment|// Check that subsequent -fno-lto takes precedence
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto=full -fno-lto 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-LINK-NOLTO-ACTION< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINK-NOLTO-ACTION-NOT: "-plugin" "{{.*}}/LLVMgold.so"
end_comment

begin_comment
comment|// -flto passes along an explicit debugger tuning argument.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto -glldb 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-TUNING-LLDB< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto -g 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-NO-TUNING< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-TUNING-LLDB:   "-plugin-opt=-debugger-tune=lldb"
end_comment

begin_comment
comment|// CHECK-NO-TUNING-NOT: "-plugin-opt=-debugger-tune
end_comment

end_unit

