begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-print-bindings -c %s -fembed-bitcode 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: clang
end_comment

begin_comment
comment|// CHECK: clang
end_comment

begin_comment
comment|// RUN: %clang %s -c -fembed-bitcode -fintegrated-as 2>&1 -### | FileCheck %s -check-prefix=CHECK-CC
end_comment

begin_comment
comment|// CHECK-CC: -cc1
end_comment

begin_comment
comment|// CHECK-CC: -emit-llvm-bc
end_comment

begin_comment
comment|// CHECK-CC: -cc1
end_comment

begin_comment
comment|// CHECK-CC: -emit-obj
end_comment

begin_comment
comment|// CHECK-CC: -fembed-bitcode=all
end_comment

begin_comment
comment|// RUN: %clang %s -c -fembed-bitcode=bitcode -fintegrated-as 2>&1 -### | FileCheck %s -check-prefix=CHECK-BITCODE
end_comment

begin_comment
comment|// CHECK-BITCODE: -cc1
end_comment

begin_comment
comment|// CHECK-BITCODE: -emit-llvm-bc
end_comment

begin_comment
comment|// CHECK-BITCODE: -cc1
end_comment

begin_comment
comment|// CHECK-BITCODE: -emit-obj
end_comment

begin_comment
comment|// CHECK-BITCODE: -fembed-bitcode=bitcode
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -c -save-temps -fembed-bitcode -fintegrated-as 2>&1 -### | FileCheck %s -check-prefix=CHECK-SAVE-TEMP
end_comment

begin_comment
comment|// CHECK-SAVE-TEMP: -cc1
end_comment

begin_comment
comment|// CHECK-SAVE-TEMP: -E
end_comment

begin_comment
comment|// CHECK-SAVE-TEMP: -cc1
end_comment

begin_comment
comment|// CHECK-SAVE-TEMP: -emit-llvm-bc
end_comment

begin_comment
comment|// CHECK-SAVE-TEMP: -cc1
end_comment

begin_comment
comment|// CHECK-SAVE-TEMP: -S
end_comment

begin_comment
comment|// CHECK-SAVE-TEMP: -fembed-bitcode=all
end_comment

begin_comment
comment|// CHECK-SAVE-TEMP: -cc1as
end_comment

begin_comment
comment|// RUN: %clang -c %s -flto -fembed-bitcode 2>&1 -### | FileCheck %s -check-prefix=CHECK-LTO
end_comment

begin_comment
comment|// RUN: %clang -c %s -flto=full -fembed-bitcode 2>&1 -### | FileCheck %s -check-prefix=CHECK-LTO
end_comment

begin_comment
comment|// RUN: %clang -c %s -flto=thin -fembed-bitcode 2>&1 -### | FileCheck %s -check-prefix=CHECK-LTO
end_comment

begin_comment
comment|// CHECK-LTO: -cc1
end_comment

begin_comment
comment|// CHECK-LTO: -emit-llvm-bc
end_comment

begin_comment
comment|// CHECK-LTO-NOT: warning: argument unused during compilation: '-fembed-bitcode'
end_comment

begin_comment
comment|// CHECK-LTO-NOT: -cc1
end_comment

begin_comment
comment|// CHECK-LTO-NOT: -fembed-bitcode=all
end_comment

begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: %clang  -target armv7-apple-darwin -miphoneos-version-min=6.0 %t.o -fembed-bitcode  -fembed-bitcode-marker -mlinker-version=277  2>&1 -### | FileCheck %s -check-prefix=CHECK-LTO-MARKER-277
end_comment

begin_comment
comment|// RUN: %clang  -target armv7-apple-darwin -miphoneos-version-min=6.0 %t.o -fembed-bitcode  -fembed-bitcode-marker -mlinker-version=278  2>&1 -### | FileCheck %s -check-prefix=CHECK-LTO-MARKER-278
end_comment

begin_comment
comment|// CHECK-LTO-MARKER-277-NOT: bitcode_process_mode
end_comment

begin_comment
comment|// CHECK-LTO-MARKER-278: bitcode_process_mode
end_comment

begin_comment
comment|// RUN: %clang -c %s -fembed-bitcode-marker -fintegrated-as 2>&1 -### | FileCheck %s -check-prefix=CHECK-MARKER
end_comment

begin_comment
comment|// CHECK-MARKER: -cc1
end_comment

begin_comment
comment|// CHECK-MARKER: -emit-obj
end_comment

begin_comment
comment|// CHECK-MARKER: -fembed-bitcode=marker
end_comment

begin_comment
comment|// CHECK-MARKER-NOT: -cc1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin -miphoneos-version-min=6.0 %s -fembed-bitcode=all -fintegrated-as 2>&1 -### | FileCheck %s -check-prefix=CHECK-LINKER
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin -miphoneos-version-min=6.0 %s -fembed-bitcode=marker -fintegrated-as 2>&1 -### | FileCheck %s -check-prefix=CHECK-LINKER
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin -miphoneos-version-min=6.0 %s -flto=full -fembed-bitcode=bitcode -fintegrated-as 2>&1 -### | FileCheck %s -check-prefix=CHECK-LINKER
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin -miphoneos-version-min=6.0 %s -flto=thin -fembed-bitcode=bitcode -fintegrated-as 2>&1 -### | FileCheck %s -check-prefix=CHECK-LINKER
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin -miphoneos-version-min=6.0 %s -fembed-bitcode=off -fintegrated-as 2>&1 -### | FileCheck %s -check-prefix=CHECK-NO-LINKER
end_comment

begin_comment
comment|// CHECK-LINKER: ld
end_comment

begin_comment
comment|// CHECK-LINKER: -bitcode_bundle
end_comment

begin_comment
comment|// CHECK-NO-LINKER-NOT: -bitcode_bundle
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin -miphoneos-version-min=5.0 %s -fembed-bitcode -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck %s -check-prefix=CHECK-PLATFORM-NOTSUPPORTED
end_comment

begin_comment
comment|// CHECK-PLATFORM-NOTSUPPORTED: -fembed-bitcode is not supported on versions of iOS prior to 6.0
end_comment

end_unit

