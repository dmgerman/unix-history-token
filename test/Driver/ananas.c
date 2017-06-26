begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-unknown-ananas -static %s \
end_comment

begin_comment
comment|// RUN:   --sysroot=%S/Inputs/ananas-tree -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-STATIC %s
end_comment

begin_comment
comment|// CHECK-STATIC: ld{{.*}}" "-Bstatic"
end_comment

begin_comment
comment|// CHECK-STATIC: crt0.o
end_comment

begin_comment
comment|// CHECK-STATIC: crti.o
end_comment

begin_comment
comment|// CHECK-STATIC: crtbegin.o
end_comment

begin_comment
comment|// CHECK-STATIC: crtend.o
end_comment

begin_comment
comment|// CHECK-STATIC: crtn.o
end_comment

end_unit

