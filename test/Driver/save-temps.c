begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-temps -arch x86_64 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-o" "save-temps.i"
end_comment

begin_comment
comment|// CHECK: "-emit-llvm-uselists"
end_comment

begin_comment
comment|// CHECK: "-disable-llvm-passes"
end_comment

begin_comment
comment|// CHECK: "-o" "save-temps.bc"
end_comment

begin_comment
comment|// CHECK: "-o" "save-temps.s"
end_comment

begin_comment
comment|// CHECK: "-o" "save-temps.o"
end_comment

begin_comment
comment|// CHECK: "-o" "a.out"
end_comment

begin_comment
comment|// Check -save-temps=cwd which should work the same as -save-temps above
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-temps=cwd -arch x86_64 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CWD
end_comment

begin_comment
comment|// CWD: "-o" "save-temps.i"
end_comment

begin_comment
comment|// CWD: "-emit-llvm-uselists"
end_comment

begin_comment
comment|// CWD: "-disable-llvm-passes"
end_comment

begin_comment
comment|// CWD: "-o" "save-temps.bc"
end_comment

begin_comment
comment|// CWD: "-o" "save-temps.s"
end_comment

begin_comment
comment|// CWD: "-o" "save-temps.o"
end_comment

begin_comment
comment|// CWD: "-o" "a.out"
end_comment

begin_comment
comment|// Check for a single clang cc1 invocation when NOT using -save-temps.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch x86_64 -S %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=NO-TEMPS
end_comment

begin_comment
comment|// NO-TEMPS: "-cc1"
end_comment

begin_comment
comment|// NO-TEMPS: "-S"
end_comment

begin_comment
comment|// NO-TEMPS: "-x" "c"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-temps -arch i386 -arch x86_64 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=MULT-ARCH
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "save-temps-i386.i"
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "save-temps-i386.bc"
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "save-temps-i386.s"
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "save-temps-i386.o"
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "a.out-i386"
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "save-temps-x86_64.i"
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "save-temps-x86_64.bc"
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "save-temps-x86_64.s"
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "save-temps-x86_64.o"
end_comment

begin_comment
comment|// MULT-ARCH: "-o" "a.out-x86_64"
end_comment

begin_comment
comment|// MULT-ARCH: lipo
end_comment

begin_comment
comment|// MULT-ARCH: "-create" "-output" "a.out" "a.out-i386" "a.out-x86_64"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-temps=cwd -arch i386 -arch x86_64 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=MULT-ARCH-CWD
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "save-temps-i386.i"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "save-temps-i386.bc"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "save-temps-i386.s"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "save-temps-i386.o"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "a.out-i386"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "save-temps-x86_64.i"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "save-temps-x86_64.bc"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "save-temps-x86_64.s"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "save-temps-x86_64.o"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-o" "a.out-x86_64"
end_comment

begin_comment
comment|// MULT-ARCH-CWD: lipo
end_comment

begin_comment
comment|// MULT-ARCH-CWD: "-create" "-output" "a.out" "a.out-i386" "a.out-x86_64"
end_comment

begin_comment
comment|// Check that temp files are saved in the same directory as the output file
end_comment

begin_comment
comment|// regardless of whether -o is specified.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-temps=obj -o obj/dir/a.out -arch x86_64 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-OBJ
end_comment

begin_comment
comment|// CHECK-OBJ: "-o" "obj/dir{{/|\\\\}}save-temps.i"
end_comment

begin_comment
comment|// CHECK-OBJ: "-disable-llvm-passes"
end_comment

begin_comment
comment|// CHECK-OBJ: "-o" "obj/dir{{/|\\\\}}save-temps.bc"
end_comment

begin_comment
comment|// CHECK-OBJ: "-o" "obj/dir{{/|\\\\}}save-temps.s"
end_comment

begin_comment
comment|// CHECK-OBJ: "-o" "obj/dir{{/|\\\\}}save-temps.o"
end_comment

begin_comment
comment|// CHECK-OBJ: "-o" "obj/dir{{/|\\\\}}a.out"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -save-temps=obj -arch x86_64 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-OBJ-NOO
end_comment

begin_comment
comment|// CHECK-OBJ-NOO: "-o" "save-temps.i"
end_comment

begin_comment
comment|// CHECK-OBJ-NOO: "-disable-llvm-passes"
end_comment

begin_comment
comment|// CHECK-OBJ-NOO: "-o" "save-temps.bc"
end_comment

begin_comment
comment|// CHECK-OBJ-NOO: "-o" "save-temps.s"
end_comment

begin_comment
comment|// CHECK-OBJ-NOO: "-o" "save-temps.o"
end_comment

begin_comment
comment|// CHECK-OBJ-NOO: "-o" "a.out"
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-freebsd -save-temps -g -c %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=CHECK-SAVE-TEMPS
end_comment

begin_comment
comment|// CHECK-SAVE-TEMPS: "-cc1as"
end_comment

begin_comment
comment|// CHECK-SAVE-TEMPS: "-dwarf-version={{.}}"
end_comment

end_unit

