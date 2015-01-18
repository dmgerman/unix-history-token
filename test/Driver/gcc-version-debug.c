begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -v --target=i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:           --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:           --sysroot=%S/Inputs/debian_multiarch_tree 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Found candidate GCC installation: {{.*}}Inputs{{.}}debian_multiarch_tree{{.}}usr{{.}}lib{{.}}gcc{{.}}i686-linux-gnu{{.}}4.5
end_comment

begin_comment
comment|// CHECK-NEXT: Found candidate GCC installation: {{.*}}Inputs{{.}}debian_multiarch_tree{{.}}usr{{.}}lib{{.}}gcc{{.}}x86_64-linux-gnu{{.}}4.5
end_comment

begin_comment
comment|// CHECK-NEXT: Selected GCC installation: {{.*}}Inputs{{.}}debian_multiarch_tree{{.}}usr{{.}}lib{{.}}gcc{{.}}i686-linux-gnu{{.}}4.5
end_comment

end_unit

