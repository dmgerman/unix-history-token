begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test ld invocation on Solaris targets.
end_comment

begin_comment
comment|// Check sparc-sun-solaris2.1
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=sparc-sun-solaris2.11 \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/sparc-sun-solaris2.11 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-cc1" "-triple" "sparc-sun-solaris2.11"
end_comment

begin_comment
comment|// CHECK: ld{{.*}}"
end_comment

begin_comment
comment|// CHECK: "--dynamic-linker" "{{.*}}/usr/lib/ld.so.1"
end_comment

begin_comment
comment|// CHECK: "{{.*}}/usr/gcc/4.8/lib/gcc/sparc-sun-solaris2.11/4.8.2{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK: "{{.*}}/usr/lib/crti.o"
end_comment

begin_comment
comment|// CHECK: "{{.*}}/usr/gcc/4.8/lib/gcc/sparc-sun-solaris2.11/4.8.2{{/|\\\\}}crtbegin.o"
end_comment

begin_comment
comment|// CHECK: "{{.*}}/usr/gcc/4.8/lib/gcc/sparc-sun-solaris2.11/4.8.2{{/|\\\\}}crtend.o"
end_comment

begin_comment
comment|// CHECK: "{{.*}}/usr/lib/crtn.o"
end_comment

begin_comment
comment|// CHECK "-lc"
end_comment

begin_comment
comment|// CHECK "-lgcc_s"
end_comment

begin_comment
comment|// CHECK "-lgcc"
end_comment

begin_comment
comment|// CHECK "-lm"
end_comment

begin_comment
comment|// Check the right -l flags are present with -shared
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o -shared 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=sparc-sun-solaris2.11 \
end_comment

begin_comment
comment|// RUN:     --gcc-toolchain="" \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/sparc-sun-solaris2.11 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SHARED %s
end_comment

begin_comment
comment|// CHECK-SHARED: ld{{.*}}"
end_comment

begin_comment
comment|// CHECK-SHARED "-lc"
end_comment

begin_comment
comment|// CHECK-SHARED "-lgcc_s"
end_comment

begin_comment
comment|// CHECK-SHARED-NOT "-lgcc"
end_comment

begin_comment
comment|// CHECK-SHARED-NOT: "-lm"
end_comment

end_unit

