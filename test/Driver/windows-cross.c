begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-BASIC
end_comment

begin_comment
comment|// CHECK-BASIC: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-Bdynamic" "--entry" "mainCRTStartup" "--allow-multiple-definition" "-o" "{{[^"]*}}" "{{.*}}/Inputs/Windows/ARM/8.1/usr/lib/crtbegin.obj" "-L{{.*}}/Inputs/Windows/ARM/8.1/usr/lib" "-L{{.*}}/Inputs/Windows/ARM/8.1/usr/lib/gcc" "{{.*}}.o" "-lmsvcrt" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %s/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -rtlib=compiler-rt -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-RTLIB
end_comment

begin_comment
comment|// CHECK-RTLIB: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-Bdynamic" "--entry" "mainCRTStartup" "--allow-multiple-definition" "-o" "{{[^"]*}}" "{{.*}}/Inputs/Windows/ARM/8.1/usr/lib/crtbegin.obj" "-L{{.*}}/Inputs/Windows/ARM/8.1/usr/lib" "-L{{.*}}/Inputs/Windows/ARM/8.1/usr/lib/gcc" "{{.*}}.o" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -rtlib=compiler-rt -stdlib=libc++ -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-C-LIBCXX
end_comment

begin_comment
comment|// CHECK-C-LIBCXX: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-Bdynamic" "--entry" "mainCRTStartup" "--allow-multiple-definition" "-o" "{{[^"]*}}" "{{.*}}/Inputs/Windows/ARM/8.1/usr/lib/crtbegin.obj" "{{.*}}.o" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clangxx -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -rtlib=compiler-rt -stdlib=libc++ -o /dev/null %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-LIBCXX
end_comment

begin_comment
comment|// CHECK-LIBCXX: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-Bdynamic" "--entry" "mainCRTStartup" "--allow-multiple-definition" "-o" "{{[^"]*}}" "{{.*}}/Inputs/Windows/ARM/8.1/usr/lib/crtbegin.obj" "{{.*}}.o" "-lc++" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -shared -rtlib=compiler-rt -stdlib=libc++ -o shared.dll %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-SHARED
end_comment

begin_comment
comment|// CHECK-SHARED: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-shared" "-Bdynamic" "--enable-auto-image-base" "--entry" "_DllMainCRTStartup" "--allow-multiple-definition" "-o" "shared.dll" "--out-implib" "shared.lib" "{{.*}}/Inputs/Windows/ARM/8.1/usr/lib/crtbeginS.obj" "{{.*}}.o" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %s/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -shared -rtlib=compiler-rt -stdlib=libc++ -nostartfiles -o shared.dll %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-NOSTARTFILES
end_comment

begin_comment
comment|// CHECK-NOSTARTFILES: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-shared" "-Bdynamic" "--enable-auto-image-base" "--entry" "_DllMainCRTStartup" "--allow-multiple-definition" "-o" "shared.dll" "--out-implib" "shared.lib" "{{.*}}.o" "-lmsvcrt" "{{.*[\\/]}}clang_rt.builtins-arm.lib"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %S/Inputs/Windows/ARM/8.1/usr/bin -shared -rtlib=compiler-rt -stdlib=libc++ -nostartfiles -nodefaultlibs -o shared.dll %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix CHECK-STANDALONE
end_comment

begin_comment
comment|// CHECK-STANDALONE: armv7-windows-itanium-ld" "--sysroot={{.*}}/Inputs/Windows/ARM/8.1" "-m" "thumb2pe" "-shared" "-Bdynamic" "--enable-auto-image-base" "--entry" "_DllMainCRTStartup" "--allow-multiple-definition" "-o" "shared.dll" "--out-implib" "shared.lib" "{{.*}}.o"
end_comment

begin_comment
comment|// RUN: %clang -### -target armv7-windows-itanium --sysroot %S/Inputs/Windows/ARM/8.1 -B %/Inputs/Windows/ARM/8.1/usr/bin -shared -o shared.dll -x c++ %s 2>&1 \
end_comment

begin_comment
comment|// RUN:    | FileCheck %s --check-prefix CHECK-LIBSTDCXX
end_comment

begin_comment
comment|// CHECK-LIBSTDCXX:  "-internal-isystem" "{{.*}}/usr/include/c++" "-internal-isystem" "{{.*}}/usr/include/c++/armv7--windows-itanium" "-internal-isystem" "{{.*}}/usr/include/c++/backwards"
end_comment

end_unit

