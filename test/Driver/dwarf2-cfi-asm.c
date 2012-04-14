begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -### -S -integrated-as %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-DARWIN-MC-DEFAULT %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -### -S -integrated-as -fdwarf2-cfi-asm %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-DARWIN-MC-CFI %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -### -S -integrated-as -fno-dwarf2-cfi-asm %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-DARWIN-MC-NOCFI %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -### -S -no-integrated-as %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-DARWIN-AS-DEFAULT %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -### -S -no-integrated-as -fdwarf2-cfi-asm %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-DARWIN-AS-CFI %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -### -S -no-integrated-as -fno-dwarf2-cfi-asm %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-DARWIN-AS-NOCFI %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -integrated-as %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-LINUX-MC-DEFAULT %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -integrated-as -fdwarf2-cfi-asm %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-LINUX-MC-CFI %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -integrated-as -fno-dwarf2-cfi-asm %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-LINUX-MC-NOCFI %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -no-integrated-as %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-LINUX-AS-DEFAULT %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -no-integrated-as -fdwarf2-cfi-asm %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-LINUX-AS-CFI %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux -### -S -no-integrated-as -fno-dwarf2-cfi-asm %s -o %t.s 2>&1 | FileCheck -check-prefix=CHECK-LINUX-AS-NOCFI %s
end_comment

begin_comment
comment|// CHECK-DARWIN-MC-DEFAULT-NOT: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-DARWIN-MC-CFI-NOT: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-DARWIN-MC-NOCFI: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-DARWIN-AS-DEFAULT: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-DARWIN-AS-CFI-NOT: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-DARWIN-AS-NOCFI: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-LINUX-MC-DEFAULT-NOT: -fno-dwarf2-cfi-asmx
end_comment

begin_comment
comment|// CHECK-LINUX-MC-CFI-NOT: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-LINUX-MC-NOCFI: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-LINUX-AS-DEFAULT-NOT: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-LINUX-AS-CFI-NOT: -fno-dwarf2-cfi-asm
end_comment

begin_comment
comment|// CHECK-LINUX-AS-NOCFI: -fno-dwarf2-cfi-asm
end_comment

end_unit

