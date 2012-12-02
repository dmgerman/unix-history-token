begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test UndefinedBehaviorSanitizer ld flags.
end_comment

begin_comment
comment|// RUN: %clang -fcatch-undefined-behavior %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LINUX %s
end_comment

begin_comment
comment|// CHECK-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LINUX-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-LINUX: libclang_rt.ubsan-i386.a"
end_comment

begin_comment
comment|// CHECK-LINUX: "-lpthread"
end_comment

end_unit

