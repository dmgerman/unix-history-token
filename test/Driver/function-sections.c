begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test handling of -f(no-)function-sections and -f(no-)data-sections
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-FS: -ffunction-sections
end_comment

begin_comment
comment|// CHECK-NOFS-NOT: -ffunction-sections
end_comment

begin_comment
comment|// CHECK-DS: -fdata-sections
end_comment

begin_comment
comment|// CHECK-NODS-NOT: -fdata-sections
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOFS --check-prefix=CHECK-NODS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -ffunction-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -fno-function-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOFS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -ffunction-sections -fno-function-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NOFS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -fno-function-sections -ffunction-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -ffunction-sections -fno-function-sections -ffunction-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -fdata-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -fno-data-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NODS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -fdata-sections -fno-data-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NODS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -fno-data-sections -fdata-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -fsyntax-only 2>&1       \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -fdata-sections -fno-data-sections -fdata-sections \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DS %s
end_comment

end_unit

