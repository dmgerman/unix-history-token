begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test sanitizers ld flags.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld -fsanitize=address \
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
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld -fsanitize=address -shared-libasan \
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
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld -fsanitize=address -shared-libasan \
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
comment|// RUN:     -target i386-unknown-freebsd -fuse-ld=ld -fsanitize=address \
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
comment|// RUN:     -target i386-unknown-freebsd -fuse-ld=ld -fsanitize=address \
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
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld -stdlib=platform -fsanitize=address \
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
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld -stdlib=platform \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree -lstdc++ -static 2>&1 \
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
comment|// RUN:     -target arm-linux-gnueabi -fuse-ld=ld -fsanitize=address \
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
comment|// RUN:     -target armv7l-linux-gnueabi -fuse-ld=ld -fsanitize=address \
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
comment|// RUN:     -target arm-linux-androideabi -fuse-ld=ld -fsanitize=address \
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
comment|// RUN:     -target arm-linux-androideabi -fuse-ld=ld -fsanitize=address \
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
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target sparcel-myriad-rtems-elf -fuse-ld=ld -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_myriad_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-MYRIAD %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASAN-MYRIAD: "{{(.*[^.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-MYRIAD-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-ASAN-MYRIAD: libclang_rt.asan-sparcel.a"
end_comment

begin_comment
comment|// RUN: %clangxx -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld -stdlib=platform -lstdc++ \
end_comment

begin_comment
comment|// RUN:     -fsanitize=thread \
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
comment|// CHECK-TSAN-LINUX-CXX: "--dynamic-list={{.*}}libclang_rt.tsan-x86_64.a.syms"
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.tsan_cxx-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-TSAN-LINUX-CXX: "--dynamic-list={{.*}}libclang_rt.tsan_cxx-x86_64.a.syms"
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
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld -stdlib=platform -lstdc++ \
end_comment

begin_comment
comment|// RUN:     -fsanitize=memory \
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
comment|// CHECK-MSAN-LINUX-CXX: "--dynamic-list={{.*}}libclang_rt.msan-x86_64.a.syms"
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.msan_cxx-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-MSAN-LINUX-CXX: "--dynamic-list={{.*}}libclang_rt.msan_cxx-x86_64.a.syms"
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
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld \
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
comment|// CHECK-UBSAN-LINUX-NOT: libclang_rt.ubsan_standalone_cxx
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX: "-whole-archive" "{{.*}}libclang_rt.ubsan_standalone-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-NOT: libclang_rt.ubsan_standalone_cxx
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
comment|// CHECK-UBSAN-LINUX-LINK-CXX: "-whole-archive" "{{.*}}libclang_rt.ubsan_standalone_cxx-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-LINK-CXX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// RUN: %clangxx -fsanitize=undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld -stdlib=platform \
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
comment|// CHECK-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.ubsan_standalone-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX-NOT: libclang_rt.asan
end_comment

begin_comment
comment|// CHECK-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.ubsan_standalone_cxx-i386.a" "-no-whole-archive"
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
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld \
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
comment|// CHECK-ASAN-UBSAN-LINUX: "-whole-archive" "{{.*}}libclang_rt.asan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-NOT: libclang_rt.ubsan
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
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld -stdlib=platform \
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
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.asan-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.asan_cxx-i386.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX-NOT: libclang_rt.ubsan
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-UBSAN-LINUX-CXX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clangxx -fsanitize=memory,undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MSAN-UBSAN-LINUX-CXX %s
end_comment

begin_comment
comment|// CHECK-MSAN-UBSAN-LINUX-CXX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MSAN-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.msan-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-MSAN-UBSAN-LINUX-CXX-NOT: libclang_rt.ubsan
end_comment

begin_comment
comment|// RUN: %clangxx -fsanitize=thread,undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-TSAN-UBSAN-LINUX-CXX %s
end_comment

begin_comment
comment|// CHECK-TSAN-UBSAN-LINUX-CXX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-TSAN-UBSAN-LINUX-CXX: "-whole-archive" "{{.*}}libclang_rt.tsan-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-TSAN-UBSAN-LINUX-CXX-NOT: libclang_rt.ubsan
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i386-unknown-linux -fuse-ld=ld \
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
comment|// CHECK-UBSAN-LINUX-SHARED-NOT: libclang_rt.ubsan
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld -fsanitize=leak \
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
comment|// CHECK-LSAN-LINUX-NOT: libclang_rt.ubsan
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
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:  -target x86_64-unknown-linux -fuse-ld=ld -fsanitize=leak -fsanitize-coverage=func \
end_comment

begin_comment
comment|// RUN:  --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LSAN-COV-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LSAN-COV-LINUX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LSAN-COV-LINUX-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-LSAN-COV-LINUX-NOT: libclang_rt.ubsan
end_comment

begin_comment
comment|// CHECK-LSAV-COV-LINUX: libclang_rt.lsan-x86_64.a"
end_comment

begin_comment
comment|// CHECK-LSAN-COV-LINUX-NOT: libclang_rt.ubsan
end_comment

begin_comment
comment|// CHECK-LSAN-COV-LINUX: "-lpthread"
end_comment

begin_comment
comment|// CHECK-LSAN-COV-LINUX: "-ldl"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=leak,address %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
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

begin_comment
comment|// RUN: %clang -fsanitize=address -fsanitize-coverage=func %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-COV-LINUX %s
end_comment

begin_comment
comment|// CHECK-ASAN-COV-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-COV-LINUX: "-whole-archive" "{{.*}}libclang_rt.asan-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-ASAN-COV-LINUX-NOT: libclang_rt.ubsan
end_comment

begin_comment
comment|// CHECK-ASAN-COV-LINUX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-COV-LINUX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=memory -fsanitize-coverage=func %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MSAN-COV-LINUX %s
end_comment

begin_comment
comment|// CHECK-MSAN-COV-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-MSAN-COV-LINUX: "-whole-archive" "{{.*}}libclang_rt.msan-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-MSAN-COV-LINUX-NOT: libclang_rt.ubsan
end_comment

begin_comment
comment|// CHECK-MSAN-COV-LINUX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-MSAN-COV-LINUX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=dataflow -fsanitize-coverage=func %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DFSAN-COV-LINUX %s
end_comment

begin_comment
comment|// CHECK-DFSAN-COV-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-DFSAN-COV-LINUX: "-whole-archive" "{{.*}}libclang_rt.dfsan-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-DFSAN-COV-LINUX-NOT: libclang_rt.ubsan
end_comment

begin_comment
comment|// CHECK-DFSAN-COV-LINUX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-DFSAN-COV-LINUX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=undefined -fsanitize-coverage=func %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBSAN-COV-LINUX %s
end_comment

begin_comment
comment|// CHECK-UBSAN-COV-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-UBSAN-COV-LINUX: "-whole-archive" "{{.*}}libclang_rt.ubsan_standalone-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-UBSAN-COV-LINUX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-UBSAN-COV-LINUX: "-lpthread"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize-coverage=func %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-COV-LINUX %s
end_comment

begin_comment
comment|// CHECK-COV-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-COV-LINUX: "-whole-archive" "{{.*}}libclang_rt.ubsan_standalone-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-COV-LINUX-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-COV-LINUX: "-lpthread"
end_comment

begin_comment
comment|// CFI by itself does not link runtime libraries.
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=cfi %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld -rtlib=platform \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CFI-LINUX %s
end_comment

begin_comment
comment|// CHECK-CFI-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-CFI-LINUX-NOT: libclang_rt.
end_comment

begin_comment
comment|// CFI with diagnostics links the UBSan runtime.
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=cfi -fno-sanitize-trap=cfi -fsanitize-recover=cfi \
end_comment

begin_comment
comment|// RUN:     %s -### -o %t.o 2>&1\
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CFI-DIAG-LINUX %s
end_comment

begin_comment
comment|// CHECK-CFI-DIAG-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-CFI-DIAG-LINUX: "-whole-archive" "{{[^"]*}}libclang_rt.ubsan_standalone-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// Cross-DSO CFI links the CFI runtime.
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=cfi -fsanitize-cfi-cross-dso %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CFI-CROSS-DSO-LINUX %s
end_comment

begin_comment
comment|// CHECK-CFI-CROSS-DSO-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-CFI-CROSS-DSO-LINUX: "-whole-archive" "{{[^"]*}}libclang_rt.cfi-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-CFI-CROSS-DSO-LINUX: -export-dynamic
end_comment

begin_comment
comment|// Cross-DSO CFI with diagnostics links just the CFI runtime.
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=cfi -fsanitize-cfi-cross-dso %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fno-sanitize-trap=cfi -fsanitize-recover=cfi \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CFI-CROSS-DSO-DIAG-LINUX %s
end_comment

begin_comment
comment|// CHECK-CFI-CROSS-DSO-DIAG-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-CFI-CROSS-DSO-DIAG-LINUX: "-whole-archive" "{{[^"]*}}libclang_rt.cfi_diag-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-CFI-CROSS-DSO-DIAG-LINUX: -export-dynamic
end_comment

begin_comment
comment|// RUN: %clangxx -fsanitize=address %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -mmacosx-version-min=10.6 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-apple-darwin13.4.0 -fuse-ld=ld -stdlib=platform \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-DARWIN106-CXX %s
end_comment

begin_comment
comment|// CHECK-ASAN-DARWIN106-CXX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-DARWIN106-CXX: libclang_rt.asan_osx_dynamic.dylib
end_comment

begin_comment
comment|// CHECK-ASAN-DARWIN106-CXX-NOT: -lc++abi
end_comment

begin_comment
comment|// RUN: %clangxx -fsanitize=leak %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -mmacosx-version-min=10.6 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-apple-darwin13.4.0 -fuse-ld=ld -stdlib=platform \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LSAN-DARWIN106-CXX %s
end_comment

begin_comment
comment|// CHECK-LSAN-DARWIN106-CXX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LSAN-DARWIN106-CXX: libclang_rt.lsan_osx_dynamic.dylib
end_comment

begin_comment
comment|// CHECK-LSAN-DARWIN106-CXX-NOT: -lc++abi
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld -fsanitize=safe-stack \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SAFESTACK-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SAFESTACK-LINUX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-SAFESTACK-LINUX-NOT: "-lc"
end_comment

begin_comment
comment|// CHECK-SAFESTACK-LINUX-NOT: whole-archive
end_comment

begin_comment
comment|// CHECK-SAFESTACK-LINUX: libclang_rt.safestack-x86_64.a"
end_comment

begin_comment
comment|// CHECK-SAFESTACK-LINUX: "-u" "__safestack_init"
end_comment

begin_comment
comment|// CHECK-SAFESTACK-LINUX: "-lpthread"
end_comment

begin_comment
comment|// CHECK-SAFESTACK-LINUX: "-ldl"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=cfi -fsanitize-stats %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CFI-STATS-LINUX %s
end_comment

begin_comment
comment|// CHECK-CFI-STATS-LINUX: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-CFI-STATS-LINUX: "-whole-archive" "{{[^"]*}}libclang_rt.stats_client-x86_64.a" "-no-whole-archive"
end_comment

begin_comment
comment|// CHECK-CFI-STATS-LINUX-NOT: "-whole-archive"
end_comment

begin_comment
comment|// CHECK-CFI-STATS-LINUX: "{{[^"]*}}libclang_rt.stats-x86_64.a"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=cfi -fsanitize-stats %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-apple-darwin -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CFI-STATS-DARWIN %s
end_comment

begin_comment
comment|// CHECK-CFI-STATS-DARWIN: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-CFI-STATS-DARWIN: "{{[^"]*}}libclang_rt.stats_client_osx.a"
end_comment

begin_comment
comment|// CHECK-CFI-STATS-DARWIN: "{{[^"]*}}libclang_rt.stats_osx_dynamic.dylib"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=cfi -fsanitize-stats %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-pc-windows \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CFI-STATS-WIN64 %s
end_comment

begin_comment
comment|// CHECK-CFI-STATS-WIN64: "--dependent-lib={{[^"]*}}clang_rt.stats_client-x86_64.lib"
end_comment

begin_comment
comment|// CHECK-CFI-STATS-WIN64: "--dependent-lib={{[^"]*}}clang_rt.stats-x86_64.lib"
end_comment

begin_comment
comment|// CHECK-CFI-STATS-WIN64: "--linker-option=/include:__sanitizer_stats_register"
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=cfi -fsanitize-stats %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target i686-pc-windows \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_linux_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CFI-STATS-WIN32 %s
end_comment

begin_comment
comment|// CHECK-CFI-STATS-WIN32: "--dependent-lib={{[^"]*}}clang_rt.stats_client-i386.lib"
end_comment

begin_comment
comment|// CHECK-CFI-STATS-WIN32: "--dependent-lib={{[^"]*}}clang_rt.stats-i386.lib"
end_comment

begin_comment
comment|// CHECK-CFI-STATS-WIN32: "--linker-option=/include:___sanitizer_stats_register"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi -fuse-ld=ld -fsanitize=safe-stack \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SAFESTACK-ANDROID-ARM %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SAFESTACK-ANDROID-ARM: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-SAFESTACK-ANDROID-ARM-NOT: libclang_rt.safestack
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o -shared 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi -fuse-ld=ld -fsanitize=safe-stack \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SAFESTACK-SHARED-ANDROID-ARM %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SAFESTACK-SHARED-ANDROID-ARM: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-SAFESTACK-SHARED-ANDROID-ARM-NOT: libclang_rt.safestack
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target aarch64-linux-android -fuse-ld=ld -fsanitize=safe-stack \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SAFESTACK-ANDROID-AARCH64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SAFESTACK-ANDROID-AARCH64: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-SAFESTACK-ANDROID-AARCH64-NOT: libclang_rt.safestack
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi -fuse-ld=ld -fsanitize=cfi \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CFI-ANDROID %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-CFI-ANDROID: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-CFI-ANDROID-NOT: libclang_rt.cfi
end_comment

begin_comment
comment|// CHECK-CFI-ANDROID-NOT: __cfi_check
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target arm-linux-androideabi -fuse-ld=ld -fsanitize=cfi \
end_comment

begin_comment
comment|// RUN:     -fsanitize-cfi-cross-dso \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/basic_android_tree \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-CROSSDSO-CFI-ANDROID %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-CROSSDSO-CFI-ANDROID: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-CROSSDSO-CFI-ANDROID-NOT: libclang_rt.cfi
end_comment

begin_comment
comment|// CHECK-CROSSDSO-CFI-ANDROID: -export-dynamic-symbol=__cfi_check
end_comment

begin_comment
comment|// CHECK-CROSSDSO-CFI-ANDROID-NOT: libclang_rt.cfi
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-scei-ps4 -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBSAN-PS4 %s
end_comment

begin_comment
comment|// CHECK-UBSAN-PS4: "{{.*}}ld{{(.gold)?(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-UBSAN-PS4: -lSceDbgUBSanitizer_stub_weak
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=address %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-scei-ps4 -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-PS4 %s
end_comment

begin_comment
comment|// CHECK-ASAN-PS4: "{{.*}}ld{{(.gold)?(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-PS4: -lSceDbgAddressSanitizer_stub_weak
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=address,undefined %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-scei-ps4 -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     -shared \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-AUBSAN-PS4 %s
end_comment

begin_comment
comment|// CHECK-AUBSAN-PS4: "{{.*}}ld{{(.gold)?(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-AUBSAN-PS4: -lSceDbgAddressSanitizer_stub_weak
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=efficiency-cache-frag %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ESAN-LINUX %s
end_comment

begin_comment
comment|// RUN: %clang -fsanitize=efficiency-working-set %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target x86_64-unknown-linux -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ESAN-LINUX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ESAN-LINUX: "{{(.*[^-.0-9A-Z_a-z])?}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ESAN-LINUX: libclang_rt.esan-x86_64.a
end_comment

end_unit

