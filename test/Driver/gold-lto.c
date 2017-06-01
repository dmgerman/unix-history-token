begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %t.o -flto 2>&1 \
end_comment

begin_comment
comment|// RUN:     -Wl,-plugin-opt=foo -O3 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s --check-prefix=CHECK-X86-64-BASIC
end_comment

begin_comment
comment|// CHECK-X86-64-BASIC: "-plugin" "{{.*}}/LLVMgold.so"
end_comment

begin_comment
comment|// CHECK-X86-64-BASIC: "-plugin-opt=O3"
end_comment

begin_comment
comment|// CHECK-X86-64-BASIC: "-plugin-opt=foo"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux -### %t.o -flto 2>&1 \
end_comment

begin_comment
comment|// RUN:     -march=corei7 -Wl,-plugin-opt=foo -Ofast \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s --check-prefix=CHECK-X86-64-COREI7
end_comment

begin_comment
comment|// CHECK-X86-64-COREI7: "-plugin" "{{.*}}/LLVMgold.so"
end_comment

begin_comment
comment|// CHECK-X86-64-COREI7: "-plugin-opt=mcpu=corei7"
end_comment

begin_comment
comment|// CHECK-X86-64-COREI7: "-plugin-opt=O3"
end_comment

begin_comment
comment|// CHECK-X86-64-COREI7: "-plugin-opt=foo"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target arm-unknown-linux -### %t.o -flto 2>&1 \
end_comment

begin_comment
comment|// RUN:     -march=armv7a -Wl,-plugin-opt=foo -O0 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s --check-prefix=CHECK-ARM-V7A
end_comment

begin_comment
comment|// CHECK-ARM-V7A: "-plugin" "{{.*}}/LLVMgold.so"
end_comment

begin_comment
comment|// CHECK-ARM-V7A: "-plugin-opt=mcpu=generic"
end_comment

begin_comment
comment|// CHECK-ARM-V7A: "-plugin-opt=O0"
end_comment

begin_comment
comment|// CHECK-ARM-V7A: "-plugin-opt=foo"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target i686-linux-android -### %t.o -flto 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s --check-prefix=CHECK-X86-ANDROID
end_comment

begin_comment
comment|// CHECK-X86-ANDROID: "-plugin" "{{.*}}/LLVMgold.so"
end_comment

end_unit

