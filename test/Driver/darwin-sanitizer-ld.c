begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test sanitizer link flags on Darwin.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -fsanitize=address %s -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN %s
end_comment

begin_comment
comment|// CHECK-ASAN: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN: stdc++
end_comment

begin_comment
comment|// CHECK-ASAN: libclang_rt.asan_osx_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-ASAN: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-ASAN: "-rpath" "{{.*}}lib{{.*}}darwin"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -fsanitize=address -mios-simulator-version-min=7.0 %s -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-IOSSIM %s
end_comment

begin_comment
comment|// CHECK-ASAN-IOSSIM: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-IOSSIM: lc++
end_comment

begin_comment
comment|// CHECK-ASAN-IOSSIM: libclang_rt.asan_iossim_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-ASAN-IOSSIM: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-ASAN-IOSSIM: "-rpath" "{{.*}}lib{{.*}}darwin"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -fPIC -shared -fsanitize=address %s -o %t.so 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DYN-ASAN %s
end_comment

begin_comment
comment|// CHECK-DYN-ASAN: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-DYN-ASAN: "-dylib"
end_comment

begin_comment
comment|// CHECK-DYN-ASAN: libclang_rt.asan_osx_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-DYN-ASAN: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-DYN-ASAN: "-rpath" "{{.*}}lib{{.*}}darwin"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -fsanitize=undefined %s -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBSAN %s
end_comment

begin_comment
comment|// CHECK-UBSAN: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-UBSAN: libclang_rt.ubsan_osx.a"
end_comment

begin_comment
comment|// CHECK-UBSAN: stdc++
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -fsanitize=bounds -fsanitize-undefined-trap-on-error \
end_comment

begin_comment
comment|// RUN:   %s -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BOUNDS %s
end_comment

begin_comment
comment|// CHECK-BOUNDS: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-BOUNDS-NOT: libclang_rt.ubsan_osx.a"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -fPIC -shared -fsanitize=undefined %s -o %t.so 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DYN-UBSAN %s
end_comment

begin_comment
comment|// CHECK-DYN-UBSAN: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-DYN-UBSAN: "-dylib"
end_comment

begin_comment
comment|// CHECK-DYN-UBSAN: libclang_rt.ubsan_osx.a
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -fsanitize=bounds -fsanitize-undefined-trap-on-error \
end_comment

begin_comment
comment|// RUN:   %s -o %t.so -fPIC -shared 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DYN-BOUNDS %s
end_comment

begin_comment
comment|// CHECK-DYN-BOUNDS: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-DYN-BOUNDS-NOT: libclang_rt.ubsan_osx.a
end_comment

end_unit

