begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -### -no-canonical-prefixes --target=x86_64-unknown-fuchsia \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/platform -fuse-ld=ld 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: {{.*}}clang{{.*}}" "-cc1"
end_comment

begin_comment
comment|// CHECK: "-fuse-init-array"
end_comment

begin_comment
comment|// CHECK: "-isysroot" "[[SYSROOT:[^"]+]]"
end_comment

begin_comment
comment|// CHECK: "-internal-externc-isystem" "[[SYSROOT]]{{/|\\\\}}include"
end_comment

begin_comment
comment|// CHECK: {{.*}}lld{{.*}}" "-flavor" "gnu"
end_comment

begin_comment
comment|// CHECK: "-z" "rodynamic"
end_comment

begin_comment
comment|// CHECK: "--sysroot=[[SYSROOT]]"
end_comment

begin_comment
comment|// CHECK: "-pie"
end_comment

begin_comment
comment|// CHECK: "--build-id"
end_comment

begin_comment
comment|// CHECK: "-dynamic-linker" "ld.so.1"
end_comment

begin_comment
comment|// CHECK: Scrt1.o
end_comment

begin_comment
comment|// CHECK-NOT: crti.o
end_comment

begin_comment
comment|// CHECK-NOT: crtbegin.o
end_comment

begin_comment
comment|// CHECK: "-L[[SYSROOT]]{{/|\\\\}}lib"
end_comment

begin_comment
comment|// CHECK: "{{.*[/\\]}}libclang_rt.builtins-x86_64.a"
end_comment

begin_comment
comment|// CHECK: "-lc"
end_comment

begin_comment
comment|// CHECK-NOT: crtend.o
end_comment

begin_comment
comment|// CHECK-NOT: crtn.o
end_comment

begin_comment
comment|// RUN: %clang %s -### --target=x86_64-unknown-fuchsia -rtlib=libgcc 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix=CHECK-RTLIB
end_comment

begin_comment
comment|// CHECK-RTLIB: error: invalid runtime library name in argument '-rtlib=libgcc'
end_comment

begin_comment
comment|// RUN: %clang %s -### --target=x86_64-unknown-fuchsia -static 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix=CHECK-STATIC
end_comment

begin_comment
comment|// CHECK-STATIC: "-Bstatic"
end_comment

begin_comment
comment|// CHECK-STATIC: "-Bdynamic"
end_comment

begin_comment
comment|// CHECK-STATIC: "-lc"
end_comment

begin_comment
comment|// RUN: %clang %s -### --target=x86_64-unknown-fuchsia -shared 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix=CHECK-SHARED
end_comment

begin_comment
comment|// CHECK-SHARED-NOT: "-pie"
end_comment

begin_comment
comment|// CHECK-SHARED: "-shared"
end_comment

begin_comment
comment|// RUN: %clang %s -### --target=x86_64-unknown-fuchsia -r 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix=CHECK-RELOCATABLE
end_comment

begin_comment
comment|// CHECK-RELOCATABLE-NOT: "-pie"
end_comment

begin_comment
comment|// CHECK-RELOCATABLE-NOT: "--build-id"
end_comment

begin_comment
comment|// CHECK-RELOCATABLE: "-r"
end_comment

begin_comment
comment|// RUN: %clang %s -### --target=x86_64-unknown-fuchsia \
end_comment

begin_comment
comment|// RUN:     -fsanitize=safe-stack 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix=CHECK-SAFESTACK
end_comment

begin_comment
comment|// CHECK-SAFESTACK: "-fsanitize=safe-stack"
end_comment

end_unit

