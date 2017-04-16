begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7-unknown-unknown -### -fsyntax-only %s 2> %t \
end_comment

begin_comment
comment|// RUN:   -mno-global-merge
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NGM-ARM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-unknown -### -fsyntax-only %s 2> %t \
end_comment

begin_comment
comment|// RUN:   -mno-global-merge
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NGM-AARCH64< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -### -fsyntax-only %s 2> %t \
end_comment

begin_comment
comment|// RUN:   -mno-global-merge
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NONE< %t %s
end_comment

begin_comment
comment|// CHECK-NGM-ARM: "-backend-option" "-arm-global-merge=false"
end_comment

begin_comment
comment|// CHECK-NGM-AARCH64: "-backend-option" "-aarch64-enable-global-merge=false"
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-unknown -### -fsyntax-only %s 2> %t \
end_comment

begin_comment
comment|// RUN:   -mglobal-merge
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-GM-ARM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-unknown -### -fsyntax-only %s 2> %t \
end_comment

begin_comment
comment|// RUN:   -mglobal-merge
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-GM-AARCH64< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -### -fsyntax-only %s 2> %t \
end_comment

begin_comment
comment|// RUN:   -mglobal-merge
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NONE< %t %s
end_comment

begin_comment
comment|// CHECK-GM-ARM: "-backend-option" "-arm-global-merge=true"
end_comment

begin_comment
comment|// CHECK-GM-AARCH64: "-backend-option" "-aarch64-enable-global-merge=true"
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-unknown -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NONE< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-unknown -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NONE< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-unknown -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NONE< %t %s
end_comment

begin_comment
comment|// CHECK-NONE-NOT: -global-merge=
end_comment

end_unit

