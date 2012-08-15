begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test AddressSanitizer ld flags.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -faddress-sanitizer \
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
comment|// CHECK-LINUX: libclang_rt.asan-i386.a"
end_comment

begin_comment
comment|// CHECK-LINUX: "-lpthread"
end_comment

begin_comment
comment|// CHECK-LINUX: "-ldl"
end_comment

begin_comment
comment|// CHECK-LINUX: "-export-dynamic"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi -faddress-sanitizer \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID %s
end_comment

begin_comment
comment|// CHECK-ANDROID: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ANDROID-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ANDROID: "-u" "__asan_preinit" "-lasan"
end_comment

begin_comment
comment|// CHECK-ANDROID: "-lasan_preload" "-ldl"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi -faddress-sanitizer \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ANDROID-SHARED %s
end_comment

begin_comment
comment|// CHECK-ANDROID-SHARED: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ANDROID-SHARED-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ANDROID-SHARED-NOT: "-lasan"
end_comment

begin_comment
comment|// CHECK-ANDROID-SHARED: "-lasan_preload" "-ldl"
end_comment

end_unit

