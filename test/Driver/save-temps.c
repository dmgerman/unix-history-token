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
comment|// CHECK: "-disable-llvm-optzns"
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

end_unit

