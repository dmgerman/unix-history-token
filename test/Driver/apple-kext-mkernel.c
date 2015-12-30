begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mkernel -### -fsyntax-only %s 2>&1 | FileCheck --check-prefix=CHECK-X86 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mkernel -### -fsyntax-only -fbuiltin -fno-builtin -fcommon -fno-common %s 2>&1 | FileCheck --check-prefix=CHECK-X86 %s
end_comment

begin_comment
comment|// CHECK-X86: "-disable-red-zone"
end_comment

begin_comment
comment|// CHECK-X86: "-fno-builtin"
end_comment

begin_comment
comment|// CHECK-X86: "-fno-rtti"
end_comment

begin_comment
comment|// CHECK-X86: "-fno-common"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mkernel -### -fsyntax-only -fbuiltin -fcommon %s 2>&1 | FileCheck --check-prefix=CHECK-X86-2 %s
end_comment

begin_comment
comment|// CHECK-X86-2: "-disable-red-zone"
end_comment

begin_comment
comment|// CHECK-X86-2-NOT: "-fno-builtin"
end_comment

begin_comment
comment|// CHECK-X86-2: "-fno-rtti"
end_comment

begin_comment
comment|// CHECK-X86-2-NOT: "-fno-common"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -arch armv7 -mkernel -mstrict-align -### -fsyntax-only %s 2>&1 | FileCheck --check-prefix=CHECK-ARM %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -arch armv7 -mkernel -mstrict-align -### -fsyntax-only -fbuiltin -fno-builtin -fcommon -fno-common %s 2>&1 | FileCheck --check-prefix=CHECK-ARM %s
end_comment

begin_comment
comment|// CHECK-ARM: "-target-feature" "+long-calls"
end_comment

begin_comment
comment|// CHECK-ARM: "-target-feature" "+strict-align"
end_comment

begin_comment
comment|// CHECK-ARM-NOT: "-target-feature" "+strict-align"
end_comment

begin_comment
comment|// CHECK-ARM: "-fno-builtin"
end_comment

begin_comment
comment|// CHECK-ARM: "-fno-rtti"
end_comment

begin_comment
comment|// CHECK-ARM: "-fno-common"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -Werror -fno-builtin -fno-exceptions -fno-common -fno-rtti \
end_comment

begin_comment
comment|// RUN:   -mkernel -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang -c %s -target armv7k-apple-watchos -fapple-kext -mwatchos-version-min=1.0.0 -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-WATCH
end_comment

begin_comment
comment|// CHECK-WATCH-NOT: "-backend-option" "-arm-long-calls"
end_comment

end_unit

