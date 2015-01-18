begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test sanitizers ld flags.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX: libclang_rt.asan-i386.a"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-NOT: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX: "--dynamic-list={{.*}}libclang_rt.asan-i386.a.syms"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-NOT: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX: "-lpthread"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX: "-lrt"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX: "-ldl"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fsanitize=address -shared-libasan \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SHARED-ASAN-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX-NOT: libclang_rt.asan-i386.a"
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX: libclang_rt.asan-i386.so"
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX: "-whole-archive" "{{.*}}libclang_rt.asan-preinit-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX-NOT: "-lpthread"
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX-NOT: "-lrt"
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX-NOT: "-ldl"
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX-NOT: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-SHARED-ASAN-LINUX-NOT: "--dynamic-list"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.so -shared 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fsanitize=address -shared-libasan \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DSO-SHARED-ASAN-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX-NOT: libclang_rt.asan-i386.a"
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX-NOT: "libclang_rt.asan-preinit-i386.a"
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX: libclang_rt.asan-i386.so"
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX-NOT: "-lpthread"
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX-NOT: "-lrt"
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX-NOT: "-ldl"
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX-NOT: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-DSO-SHARED-ASAN-LINUX-NOT: "--dynamic-list"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-freebsd -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_freebsd_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-FREEBSD %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD-NOT: libclang_rt.asan_cxx
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD: freebsd{{/|\\+}}libclang_rt.asan-i386.a"
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD-NOT: libclang_rt.asan_cxx
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD-NOT: "--dynamic-list"
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD: "-lpthread"
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD: "-lrt"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-freebsd -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_freebsd_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-FREEBSD-LDL %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD-LDL: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-FREEBSD-LDL-NOT: "-ldl"
end_comment

begin_comment
comment|// RUN: %clangxx -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/empty_resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-LINUX-CXX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.asan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.asan_cxx-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX-NOT: "--dynamic-list"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX: stdc++
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX: "-lpthread"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX: "-lrt"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX: "-ldl"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o /dev/null -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:     -lstdc++ -static 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-LINUX-CXX-STATIC %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX-STATIC: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX-STATIC-NOT: stdc++
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX-STATIC: "-whole-archive" "{{.*}}libclang_rt.asan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-LINUX-CXX-STATIC: stdc++
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-gnueabi -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-ARM %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-ARM: "{{(.*[^.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-ARM-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ASAN-ARM: libclang_rt.asan-arm.a"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target armv7l-linux-gnueabi -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-ARMv7 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-ARMv7: "{{(.*[^.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-ARMv7-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ASAN-ARMv7: libclang_rt.asan-arm.a"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-ANDROID %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID: "{{(.*[^.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID: "-pie"
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID-NOT: "-lpthread"
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID: libclang_rt.asan-arm-android.so"
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID-NOT: "-lpthread"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -shared-libasan \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-ANDROID-SHARED-LIBASAN %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID-SHARED-LIBASAN-NOT: argument unused during compilation: '-shared-libasan'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-ANDROID-SHARED %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID-SHARED: "{{(.*[^.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID-SHARED-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID-SHARED: libclang_rt.asan-arm-android.so"
end_comment

begin_comment
comment|// CHECK-ASAN-ANDROID-SHARED-NOT: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clangxx -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -lstdc++ -fsanitize=thread \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-TSAN-LINUX-CXX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX-NOT: stdc++
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.tsan-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX-NOT: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX: "--dynamic-list={{.*}}libclang_rt.tsan-x86_64.a.syms"
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX-NOT: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX: stdc++
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX: "-lpthread"
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX: "-lrt"
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX: "-ldl"
end_comment

begin_comment
comment|// RUN: %clangxx -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -lstdc++ -fsanitize=memory \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MSAN-LINUX-CXX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX-NOT: stdc++
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.msan-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX-NOT: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX: "--dynamic-list={{.*}}libclang_rt.msan-x86_64.a.syms"
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX-NOT: "-export-dynamic"
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX: stdc++
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX: "-lpthread"
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX: "-lrt"
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX: "-ldl"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBSAN-LINUX %s
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-NOT: libclang_rt.ubsan_cxx
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX: "-whole-archive" "{{.*}}libclang_rt.san-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-NOT: libclang_rt.ubsan_cxx
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX: "-whole-archive" "{{.*}}libclang_rt.ubsan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-NOT: libclang_rt.ubsan_cxx
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=undefined -fsanitize-link-c++-runtime %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBSAN-LINUX-LINK-CXX %s
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-LINK-CXX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-LINK-CXX: "-whole-archive" "{{.*}}libclang_rt.ubsan_cxx-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-LINK-CXX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// RUN: %clangxx -fsanitize=undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBSAN-LINUX-CXX %s
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.san-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.ubsan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX: "--dynamic-list={{.*}}libclang_rt.ubsan-i386.a.syms"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.ubsan_cxx-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX: "--dynamic-list={{.*}}libclang_rt.ubsan_cxx-i386.a.syms"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=address,undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-UBSAN-LINUX %s
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-NOT: libclang_rt.san
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX: "-whole-archive" "{{.*}}libclang_rt.asan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-NOT: libclang_rt.san
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX: "-whole-archive" "{{.*}}libclang_rt.ubsan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-NOT: libclang_rt.ubsan_cxx
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clangxx -fsanitize=address,undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-UBSAN-LINUX-CXX %s
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX-NOT: libclang_rt.san
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.asan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX-NOT: libclang_rt.san
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.ubsan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.ubsan_cxx-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBSAN-LINUX-SHARED %s
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-SHARED: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-SHARED-NOT: --export-dynamic
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-SHARED-NOT: --dynamic-list
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-SHARED-NOT: libclang_rt.ubsan-i386.a"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-SHARED-NOT: --export-dynamic
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-SHARED-NOT: --dynamic-list
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fsanitize=leak \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LSAN-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LSAN-LINUX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LSAN-LINUX-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-LSAN-LINUX: libclang_rt.lsan-x86_64.a"
end_comment

begin_comment
comment|// CHECK-LSAN-LINUX: "-lpthread"
end_comment

begin_comment
comment|// CHECK-LSAN-LINUX: "-ldl"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=leak,undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LSAN-UBSAN-LINUX %s
end_comment

begin_comment
comment|// CHECK-LSAN-UBSAN-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LSAN-UBSAN-LINUX-NOT: libclang_rt.san
end_comment

begin_comment
comment|// CHECK-LSAN-UBSAN-LINUX: "-whole-archive" "{{.*}}libclang_rt.lsan-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-LSAN-UBSAN-LINUX-NOT: libclang_rt.san
end_comment

begin_comment
comment|// CHECK-LSAN-UBSAN-LINUX: "-whole-archive" "{{.*}}libclang_rt.ubsan-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-LSAN-UBSAN-LINUX-NOT: libclang_rt.ubsan_cxx
end_comment

begin_comment
comment|// CHECK-LSAN-UBSAN-LINUX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-LSAN-UBSAN-LINUX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=leak,address %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LSAN-ASAN-LINUX %s
end_comment

begin_comment
comment|// CHECK-LSAN-ASAN-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LSAN-ASAN-LINUX-NOT: libclang_rt.lsan
end_comment

begin_comment
comment|// CHECK-LSAN-ASAN-LINUX: libclang_rt.asan-x86_64
end_comment

begin_comment
comment|// CHECK-LSAN-ASAN-LINUX-NOT: libclang_rt.lsan
end_comment

end_unit

