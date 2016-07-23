begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7-unknown-linux-gnueabi -### /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-DYNAMIC-LINKER %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-linux-gnu -### /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-DYNAMIC-LINKER %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-linux-gnu -### /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-DYNAMIC-LINKER %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu -### /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-DYNAMIC-LINKER %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -### /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-DYNAMIC-LINKER %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-linux-gnueabi -### -shared /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-linux-gnu -### -shared /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-linux-gnu -### -shared /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu -### -shared /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -### -shared /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-linux-gnueabi -### -shared -rdynamic /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED -check-prefix CHECK-RDYNAMIC %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-linux-gnu -### -shared -rdynamic /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED -check-prefix CHECK-RDYNAMIC %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-linux-gnu -### -shared -rdynamic /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED -check-prefix CHECK-RDYNAMIC %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu -### -shared -rdynamic /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED -check-prefix CHECK-RDYNAMIC %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -### -shared -rdynamic /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-SHARED -check-prefix CHECK-RDYNAMIC %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-linux-gnueabi -### -static /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-linux-gnu -### -static /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-linux-gnu -### -static /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu -### -static /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-STATIC %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -### -static /dev/null -o /dev/null 2>&1 | FileCheck -check-prefix CHECK-STATIC %s
end_comment

begin_comment
comment|// CHECK-RDYNAMIC: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-SHARED: "-shared"
end_comment

begin_comment
comment|// CHECK-STATIC: "-{{B?}}static"
end_comment

begin_comment
comment|// CHECK-DYNAMIC-LINKER: "-dynamic-linker"
end_comment

begin_comment
comment|// CHECK-SHARED-NOT: "-dynamic-linker"
end_comment

begin_comment
comment|// CHECK-STATIC-NOT: "-dynamic-linker"
end_comment

end_unit

