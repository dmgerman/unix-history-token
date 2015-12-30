begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -flto=thin causes a switch to llvm-bc object files.
end_comment

begin_comment
comment|// RUN: %clang -ccc-print-phases -c %s -flto=thin 2> %t
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
comment|// RUN: %clang -ccc-print-phases %s -flto=thin 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-COMPILELINK-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-COMPILELINK-ACTIONS: 0: input, "{{.*}}thinlto.c", c
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
comment|// -flto=thin should cause link using gold plugin with thinlto option,
end_comment

begin_comment
comment|// also confirm that it takes precedence over earlier -fno-lto and -flto=full.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto=full -fno-lto -flto=thin 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-LINK-THIN-ACTION< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LINK-THIN-ACTION: "-plugin" "{{.*}}/LLVMgold.so"
end_comment

begin_comment
comment|// CHECK-LINK-THIN-ACTION: "-plugin-opt=thinlto"
end_comment

begin_comment
comment|// Check that subsequent -flto=full takes precedence
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto=thin -flto=full 2> %t
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
comment|// CHECK-LINK-FULL-ACTION-NOT: "-plugin-opt=thinlto"
end_comment

begin_comment
comment|// Check that subsequent -fno-lto takes precedence
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %s -flto=thin -fno-lto 2> %t
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
comment|// CHECK-LINK-NOLTO-ACTION-NOT: "-plugin-opt=thinlto"
end_comment

end_unit

