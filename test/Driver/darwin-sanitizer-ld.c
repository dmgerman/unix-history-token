begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test sanitizer link flags on Darwin.
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -stdlib=platform -fsanitize=address %s -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN %s
end_comment

begin_comment
comment|// CHECK-ASAN: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-NOT: "-lc++"
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
comment|// RUN:   -stdlib=platform -fsanitize=undefined %s -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UBSAN %s
end_comment

begin_comment
comment|// CHECK-UBSAN: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-UBSAN-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-UBSAN-NOT: "-lc++"
end_comment

begin_comment
comment|// CHECK-UBSAN: libclang_rt.ubsan_osx_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-UBSAN: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-UBSAN: "-rpath" "{{.*}}lib{{.*}}darwin"
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
comment|// CHECK-DYN-UBSAN: libclang_rt.ubsan_osx_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-DYN-UBSAN: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-DYN-UBSAN: "-rpath" "{{.*}}lib{{.*}}darwin"
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
comment|// CHECK-DYN-BOUNDS-NOT: ubsan_osx
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -stdlib=platform -fsanitize=address -mios-simulator-version-min=7.0 \
end_comment

begin_comment
comment|// RUN:   %s -o %t.o 2>&1 | FileCheck --check-prefix=CHECK-ASAN-IOSSIM %s
end_comment

begin_comment
comment|// CHECK-ASAN-IOSSIM: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-IOSSIM-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-IOSSIM-NOT: "-lc++"
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
comment|// RUN:   -stdlib=platform -fsanitize=address \
end_comment

begin_comment
comment|// RUN:   -mtvos-simulator-version-min=8.3.0 %s -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-TVOSSIM %s
end_comment

begin_comment
comment|// CHECK-ASAN-TVOSSIM: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOSSIM-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOSSIM-NOT: "-lc++"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOSSIM: libclang_rt.asan_tvossim_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOSSIM: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOSSIM: "-rpath" "{{.*}}lib{{.*}}darwin"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target x86_64-darwin \
end_comment

begin_comment
comment|// RUN:   -stdlib=platform -fsanitize=address \
end_comment

begin_comment
comment|// RUN:   -mwatchos-simulator-version-min=2.0.0 %s -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ASAN-WATCHOSSIM %s
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOSSIM: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOSSIM-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOSSIM-NOT: "-lc++"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOSSIM: libclang_rt.asan_watchossim_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOSSIM: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOSSIM: "-rpath" "{{.*}}lib{{.*}}darwin"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target armv7-apple-ios  \
end_comment

begin_comment
comment|// RUN:   -stdlib=platform -fsanitize=address -miphoneos-version-min=7 \
end_comment

begin_comment
comment|// RUN:   %s -o %t.o 2>&1 | FileCheck --check-prefix=CHECK-ASAN-IOS %s
end_comment

begin_comment
comment|// CHECK-ASAN-IOS: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-IOS-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-IOS-NOT: "-lc++"
end_comment

begin_comment
comment|// CHECK-ASAN-IOS: libclang_rt.asan_ios_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-ASAN-IOS: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-ASAN-IOS: "-rpath" "{{.*}}lib{{.*}}darwin"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target arm64-apple-tvos \
end_comment

begin_comment
comment|// RUN:   -stdlib=platform -fsanitize=address -mtvos-version-min=8.3 \
end_comment

begin_comment
comment|// RUN:   %s -o %t.o 2>&1 | FileCheck --check-prefix=CHECK-ASAN-TVOS %s
end_comment

begin_comment
comment|// CHECK-ASAN-TVOS: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOS-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOS-NOT: "-lc++"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOS: libclang_rt.asan_tvos_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOS: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-ASAN-TVOS: "-rpath" "{{.*}}lib{{.*}}darwin"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -### -target armv7k-apple-watchos \
end_comment

begin_comment
comment|// RUN:   -stdlib=platform -fsanitize=address -mwatchos-version-min=2.0 \
end_comment

begin_comment
comment|// RUN:   %s -o %t.o 2>&1 | FileCheck --check-prefix=CHECK-ASAN-WATCHOS %s
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOS: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOS-NOT: "-lstdc++"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOS-NOT: "-lc++"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOS: libclang_rt.asan_watchos_dynamic.dylib"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOS: "-rpath" "@executable_path"
end_comment

begin_comment
comment|// CHECK-ASAN-WATCHOS: "-rpath" "{{.*}}lib{{.*}}darwin"
end_comment

end_unit

