begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test the that the driver produces reasonable linker invocations with
end_comment

begin_comment
comment|// -fopenmp.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-32 %s
end_comment

begin_comment
comment|// CHECK-LD-32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-32: "-lgomp" "-lrt" "-lgcc"
end_comment

begin_comment
comment|// CHECK-LD-32: "-lpthread" "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp -target x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-64 %s
end_comment

begin_comment
comment|// CHECK-LD-64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-64: "-lgomp" "-lrt" "-lgcc"
end_comment

begin_comment
comment|// CHECK-LD-64: "-lpthread" "-lc"
end_comment

end_unit

