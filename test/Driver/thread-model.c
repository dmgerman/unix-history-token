begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -mthread-model posix -v 2>&1 | FileCheck -check-prefix=CHECK-POSIX %s
end_comment

begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -mthread-model single -v 2>&1 | FileCheck -check-prefix=CHECK-SINGLE %s
end_comment

begin_comment
comment|// RUN: not %clang -target arm-unknown-linux-gnu -c %s -mthread-model silly -v 2>&1 | FileCheck -check-prefix=CHECK-INVALID %s
end_comment

begin_comment
comment|// CHECK-POSIX: "-mthread-model" "posix"
end_comment

begin_comment
comment|// CHECK-SINGLE: "-mthread-model" "single"
end_comment

begin_comment
comment|// CHECK-INVALID: error: invalid thread model 'silly' in '-mthread-model silly' for this target
end_comment

begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -v 2>&1 | FileCheck -check-prefix=CHECK-LINUX-POSIX %s
end_comment

begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -v -mthread-model single 2>&1 | FileCheck -check-prefix=CHECK-LINUX-SINGLE %s
end_comment

begin_comment
comment|// RUN: %clang -### -target arm-unknown-linux-gnu -c %s -v -mthread-model silly 2>&1 | FileCheck -check-prefix=CHECK-LINUX-INVALID %s
end_comment

begin_comment
comment|// CHECK-LINUX-POSIX: Thread model: posix
end_comment

begin_comment
comment|// CHECK-LINUX-POSIX: "-mthread-model" "posix"
end_comment

begin_comment
comment|// CHECK-LINUX-SINGLE: Thread model: single
end_comment

begin_comment
comment|// CHECK-LINUX-SINGLE: "-mthread-model" "single"
end_comment

begin_comment
comment|// CHECK-LINUX-INVALID-NOT: Thread model:
end_comment

begin_comment
comment|// RUN: %clang -### -target wasm32-unknown-linux-gnu -c %s -v 2>&1 | FileCheck -check-prefix=CHECK-WEBASSEMBLY-DEFAULT %s
end_comment

begin_comment
comment|// RUN: %clang -### -target wasm32-unknown-linux-gnu -c %s -v -mthread-model single 2>&1 | FileCheck -check-prefix=CHECK-WEBASSEMBLY-SINGLE %s
end_comment

begin_comment
comment|// RUN: %clang -### -target wasm32-unknown-linux-gnu -c %s -v -mthread-model posix 2>&1 | FileCheck -check-prefix=CHECK-WEBASSEMBLY-POSIX %s
end_comment

begin_comment
comment|// RUN: %clang -### -target wasm32-unknown-linux-gnu -c %s -v -mthread-model silly 2>&1 | FileCheck -check-prefix=CHECK-WEBASSEMBLY-INVALID %s
end_comment

begin_comment
comment|// RUN: %clang -### -target wasm64-unknown-linux-gnu -c %s -v 2>&1 | FileCheck -check-prefix=CHECK-WEBASSEMBLY-DEFAULT %s
end_comment

begin_comment
comment|// RUN: %clang -### -target wasm64-unknown-linux-gnu -c %s -v -mthread-model single 2>&1 | FileCheck -check-prefix=CHECK-WEBASSEMBLY-SINGLE %s
end_comment

begin_comment
comment|// RUN: %clang -### -target wasm64-unknown-linux-gnu -c %s -v -mthread-model posix 2>&1 | FileCheck -check-prefix=CHECK-WEBASSEMBLY-POSIX %s
end_comment

begin_comment
comment|// RUN: %clang -### -target wasm64-unknown-linux-gnu -c %s -v -mthread-model silly 2>&1 | FileCheck -check-prefix=CHECK-WEBASSEMBLY-INVALID %s
end_comment

begin_comment
comment|// CHECK-WEBASSEMBLY-DEFAULT: Thread model: posix
end_comment

begin_comment
comment|// CHECK-WEBASSEMBLY-DEFAULT: "-mthread-model" "posix"
end_comment

begin_comment
comment|// CHECK-WEBASSEMBLY-SINGLE: Thread model: single
end_comment

begin_comment
comment|// CHECK-WEBASSEMBLY-SINGLE: "-mthread-model" "single"
end_comment

begin_comment
comment|// CHECK-WEBASSEMBLY-POSIX: Thread model: posix
end_comment

begin_comment
comment|// CHECK-WEBASSEMBLY-POSIX: "-mthread-model" "posix"
end_comment

begin_comment
comment|// CHECK-WEBASSEMBLY-INVALID-NOT: Thread model:
end_comment

end_unit

