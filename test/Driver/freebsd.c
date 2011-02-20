begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-clang-archs "" -ccc-host-triple powerpc64-pc-freebsd8 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-PPC< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PPC: clang{{.*}}" "-cc1" "-triple" "powerpc64-pc-freebsd8"
end_comment

begin_comment
comment|// CHECK-PPC: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "{{.*}}ld-elf{{.*}}" "-o" "a.out" "{{.*}}crt1.o" "{{.*}}crti.o" "{{.*}}crtbegin.o" "-L/usr/lib" "{{.*}}.o" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed" "{{.*}}crtend.o" "{{.*}}crtn.o"
end_comment

begin_comment
comment|// Check that -m32 properly adjusts the toolchain flags.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-pc-freebsd8 -m32 -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-LIB32< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LIB32: clang{{.*}}" "-cc1" "-triple" "i386-pc-freebsd8"
end_comment

begin_comment
comment|// CHECK-LIB32: ld{{.*}}" {{.*}} "-m" "elf_i386_fbsd"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-pc-freebsd8 -m32 -print-search-dirs %s> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-LIB32PATHS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LIB32PATHS: libraries: ={{.*:?}}/usr/lib32
end_comment

end_unit

