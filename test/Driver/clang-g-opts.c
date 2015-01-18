begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -S %s        2>&1 | FileCheck --check-prefix=CHECK-WITHOUT-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -target x86_64-apple-darwin 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -target i686-pc-openbsd 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -target x86_64-pc-freebsd10.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0    2>&1 | FileCheck --check-prefix=CHECK-WITHOUT-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -g0 2>&1 | FileCheck --check-prefix=CHECK-WITHOUT-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target x86_64-linux-gnu 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target x86_64-apple-darwin 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target i686-pc-openbsd 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target x86_64-pc-freebsd10.0 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g -target i386-pc-solaris 2>&1 \
end_comment

begin_comment
comment|// RUN:             | FileCheck --check-prefix=CHECK-WITH-G-DWARF2 %s
end_comment

begin_comment
comment|// CHECK-WITHOUT-G-NOT: "-g"
end_comment

begin_comment
comment|// CHECK-WITH-G: "-g"
end_comment

begin_comment
comment|// CHECK-WITH-G-DWARF2: "-gdwarf-2"
end_comment

end_unit

