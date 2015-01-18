begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check passing PowerPC ABI options to the backend.
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ELFv1 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   -mabi=elfv1 | FileCheck -check-prefix=CHECK-ELFv1 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   -mabi=elfv2 | FileCheck -check-prefix=CHECK-ELFv2 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64le-unknown-linux-gnu %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-ELFv2 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64le-unknown-linux-gnu %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   -mabi=elfv1 | FileCheck -check-prefix=CHECK-ELFv1 %s
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64le-unknown-linux-gnu %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   -mabi=elfv2 | FileCheck -check-prefix=CHECK-ELFv2 %s
end_comment

begin_comment
comment|// CHECK-ELFv1: "-target-abi" "elfv1"
end_comment

begin_comment
comment|// CHECK-ELFv2: "-target-abi" "elfv2"
end_comment

end_unit

