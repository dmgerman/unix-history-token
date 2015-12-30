begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -### -S %s -O0 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -### -S %s -O1 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -### -S %s -O2 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -### -S %s -O3 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -### -S %s -Os -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -### -S %s -O0 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -### -S %s -O1 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -### -S %s -O2 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -### -S %s -O3 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -### -S %s -Os -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fomit-frame-pointer -### -S %s -O0 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fomit-frame-pointer -### -S %s -O1 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fomit-frame-pointer -### -S %s -O2 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fomit-frame-pointer -### -S %s -O3 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fomit-frame-pointer -### -S %s -Os -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fomit-frame-pointer -### -S %s -O0 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fomit-frame-pointer -### -S %s -O1 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fomit-frame-pointer -### -S %s -O2 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fomit-frame-pointer -### -S %s -O3 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fomit-frame-pointer -### -S %s -Os -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fno-omit-frame-pointer -### -S %s -O0 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fno-omit-frame-pointer -### -S %s -O1 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fno-omit-frame-pointer -### -S %s -O2 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fno-omit-frame-pointer -### -S %s -O3 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-msvc -fno-omit-frame-pointer -### -S %s -Os -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fno-omit-frame-pointer -### -S %s -O0 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fno-omit-frame-pointer -### -S %s -O1 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fno-omit-frame-pointer -### -S %s -O2 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fno-omit-frame-pointer -### -S %s -O3 -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// RUN: %clang -target armv7-windows-itanium -fno-omit-frame-pointer -### -S %s -Os -o /dev/null 2>&1 | FileCheck %s -check-prefix CHECK-NO-FPO
end_comment

begin_comment
comment|// CHECK-DEFAULT: "-mdisable-fp-elim"
end_comment

begin_comment
comment|// CHECK-FPO-NOT: "-mdisable-fp-elim"
end_comment

begin_comment
comment|// CHECK-NO-FPO: "-mdisable-fp-elim"
end_comment

end_unit

