begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### --driver-mode=g++ -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=ld -stdlib=libstdc++ -rtlib=platform -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-BASIC-LIBSTDCXX
end_comment

begin_comment
comment|// CHECK-BASIC-LIBSTDCXX: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-Bdynamic" "--entry" "mainCRTStartup" "--allow-multiple-definition" "-o" "{{[^"]*}}" "-L{{.*}}/Inputs/Windows/ARM/8.1/usr/lib" "-L{{.*}}/Inputs/Windows/ARM/8.1/usr/lib/gcc" "{{.*}}.o" "-lstdc++" "-lmingw32" "-lmingwex" "-lgcc" "-lmoldname" "-lmingw32" "-lmsvcrt" "-lgcc_s" "-lgcc"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=ld -stdlib=libstdc++ -rtlib=compiler-rt -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-BASIC-LIBCXX
end_comment

begin_comment
comment|// CHECK-BASIC-LIBCXX: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-Bdynamic" "--entry" "mainCRTStartup" "--allow-multiple-definition" "-o" "{{[^"]*}}" "{{[^"]*}}.o" "-lmsvcrt"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %s/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=ld -rtlib=compiler-rt -stdlib=libstdc++ -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-RTLIB
end_comment

begin_comment
comment|// CHECK-RTLIB: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-Bdynamic" "--entry" "mainCRTStartup" "--allow-multiple-definition" "-o" "{{[^"]*}}" "{{.*}}.o" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=ld -rtlib=compiler-rt -stdlib=libc++ -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-C-LIBCXX
end_comment

begin_comment
comment|// CHECK-C-LIBCXX: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-Bdynamic" "--entry" "mainCRTStartup" "--allow-multiple-definition" "-o" "{{[^"]*}}" "{{.*}}.o" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clangxx -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=ld -rtlib=compiler-rt -stdlib=libc++ -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-LIBCXX
end_comment

begin_comment
comment|// CHECK-LIBCXX: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-Bdynamic" "--entry" "mainCRTStartup" "--allow-multiple-definition" "-o" "{{[^"]*}}" "{{.*}}.o" "-lc++" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=ld -shared -rtlib=compiler-rt -stdlib=libc++ -o shared.dll %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-SHARED
end_comment

begin_comment
comment|// CHECK-SHARED: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-shared" "-Bdynamic" "--enable-auto-image-base" "--entry" "_DllMainCRTStartup" "--allow-multiple-definition" "-o" "shared.dll" "--out-implib" "shared.lib" "{{.*}}.o" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %s/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=ld -shared -rtlib=compiler-rt -stdlib=libc++ -nostartfiles -o shared.dll %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-NOSTARTFILES
end_comment

begin_comment
comment|// CHECK-NOSTARTFILES: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-shared" "-Bdynamic" "--enable-auto-image-base" "--entry" "_DllMainCRTStartup" "--allow-multiple-definition" "-o" "shared.dll" "--out-implib" "shared.lib" "{{.*}}.o" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=ld -shared -rtlib=compiler-rt -stdlib=libc++ -nostartfiles -nodefaultlibs -o shared.dll %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-STANDALONE
end_comment

begin_comment
comment|// CHECK-STANDALONE: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-shared" "-Bdynamic" "--enable-auto-image-base" "--entry" "_DllMainCRTStartup" "--allow-multiple-definition" "-o" "shared.dll" "--out-implib" "shared.lib" "{{.*}}.o"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %/Inputs/Windows/ARM/8.1/usr/bin -stdlib=libstdc++ -shared -o shared.dll -x c++ %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix CHECK-LIBSTDCXX
end_comment

begin_comment
comment|// CHECK-LIBSTDCXX:  "-internal-isystem" "{{.*}}/usr/include/c++" "-internal-isystem" "{{.*}}/usr/include/c++/armv7--windows-itanium" "-internal-isystem" "{{.*}}/usr/include/c++/backwards"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=lld-link2 -shared -o shared.dll -x c++ %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix CHECK-FUSE-LD
end_comment

begin_comment
comment|// CHECK-FUSE-LD: "{{.*}}lld-link2"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=lld-link2 -shared -o shared.dll -fsanitize=address -x c++ %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix CHECK-SANITIZE-ADDRESS
end_comment

begin_comment
comment|// CHECK-SANITIZE-ADDRESS: "-fsanitize=address"
end_comment

begin_comment
comment|// CHECK-SANITIZE-ADDRESS: "{{.*}}clang_rt.asan_dll_thunk-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=lld-link2 -o test.exe -fsanitize=address -x c++ %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix CHECK-SANITIZE-ADDRESS-EXE
end_comment

begin_comment
comment|// CHECK-SANITIZE-ADDRESS-EXE: "-fsanitize=address"
end_comment

begin_comment
comment|// CHECK-SANITIZE-ADDRESS-EXE: "{{.*}}clang_rt.asan_dynamic-arm.lib" "{{.*}}clang_rt.asan_dynamic_runtime_thunk-arm.lib" "--undefined" "__asan_seh_interceptor"
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-windows-itanium -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=lld-link2 -o test.exe -fsanitize=address -x c++ %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix CHECK-SANITIZE-ADDRESS-EXE-X86
end_comment

begin_comment
comment|// CHECK-SANITIZE-ADDRESS-EXE-X86: "-fsanitize=address"
end_comment

begin_comment
comment|// CHECK-SANITIZE-ADDRESS-EXE-X86: "{{.*}}clang_rt.asan_dynamic-i686.lib" "{{.*}}clang_rt.asan_dynamic_runtime_thunk-i686.lib" "--undefined" "___asan_seh_interceptor"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -fuse-ld=lld-link2 -shared -o shared.dll -fsanitize=tsan -x c++ %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix CHECK-SANITIZE-TSAN
end_comment

begin_comment
comment|// CHECK-SANITIZE-TSAN: error: unsupported argument 'tsan' to option 'fsanitize='
end_comment

begin_comment
comment|// CHECK-SANITIZE-TSAN-NOT: "-fsanitize={{.*}}"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium -isystem-after "Windows Kits/10/Include/10.0.10586.0/ucrt" -isystem-after "Windows Kits/10/Include/10.0.10586.0/um" -isystem-after "Windows Kits/10/Include/10.0.10586.0/shared" -c %s -o /dev/null 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s --check-prefix CHECK-ISYSTEM-AFTER
end_comment

begin_comment
comment|// CHECK-ISYSTEM-AFTER: "-resource-dir" "[[RESOURCE_DIR:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-ISYSTEM-AFTER: "-internal-isystem" "[[RESOURCE_DIR]]{{(/|\\\\)}}include"
end_comment

begin_comment
comment|// CHECK-ISYSTEM-AFTER: "-internal-isystem" "Windows Kits{{[/\\]}}10{{[/\\]}}Include{{[/\\]}}10.0.10586.0{{[/\\]}}ucrt"
end_comment

begin_comment
comment|// CHECK-ISYSTEM-AFTER: "-internal-isystem" "Windows Kits{{[/\\]}}10{{[/\\]}}Include{{[/\\]}}10.0.10586.0{{[/\\]}}um"
end_comment

begin_comment
comment|// CHECK-ISYSTEM-AFTER: "-internal-isystem" "Windows Kits{{[/\\]}}10{{[/\\]}}Include{{[/\\]}}10.0.10586.0{{[/\\]}}shared"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium -nostdinc -isystem-after "Windows Kits/10/Include/10.0.10586.0/ucrt" -c %s -o /dev/null 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s --check-prefix CHECK-NOSTDINC-ISYSTEM-AFTER
end_comment

begin_comment
comment|// CHECK-NOSTDINC-ISYSTEM-AFTER: "-resource-dir" "[[RESOURCE_DIR:[^"]+]]"
end_comment

begin_comment
comment|// CHECK-NOSTDINC-ISYSTEM-AFTER-NOT: "-internal-isystem" "[[RESOURCE_DIR]]{{(/|\\\\)}}include"
end_comment

begin_comment
comment|// CHECK-NOSTDINC-ISYSTEM-AFTER: "-internal-isystem" "Windows Kits{{[/\\]}}10{{[/\\]}}Include{{[/\\]}}10.0.10586.0{{[/\\]}}ucrt"
end_comment

end_unit

