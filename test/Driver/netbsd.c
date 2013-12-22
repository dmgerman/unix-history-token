begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64--netbsd \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=X86_64 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64--netbsd7.0.0 \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=X86_64-7 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64--netbsd6.0.0 \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=X86_64-6 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64--netbsd -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-X86_64 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64--netbsd7.0.0 -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-X86_64-7 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64--netbsd6.0.0 -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-X86_64-6 %s
end_comment

begin_comment
comment|// X86_64: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd"
end_comment

begin_comment
comment|// X86_64: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// X86_64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// X86_64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// X86_64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// X86_64-7: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd7.0.0"
end_comment

begin_comment
comment|// X86_64-7: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// X86_64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// X86_64-7:  "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// X86_64-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// X86_64-6: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd6.0.0"
end_comment

begin_comment
comment|// X86_64-6: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// X86_64-6: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// X86_64-6: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// X86_64-6: "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
end_comment

begin_comment
comment|// X86_64-6: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-X86_64: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd"
end_comment

begin_comment
comment|// S-X86_64: ld{{.*}}" "-Bstatic"
end_comment

begin_comment
comment|// S-X86_64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-X86_64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-X86_64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-X86_64-7: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd7.0.0"
end_comment

begin_comment
comment|// S-X86_64-7: ld{{.*}}" "-Bstatic"
end_comment

begin_comment
comment|// S-X86_64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-X86_64-7: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-X86_64-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-X86_64-6: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd6.0.0"
end_comment

begin_comment
comment|// S-X86_64-6: ld{{.*}}" "-Bstatic"
end_comment

begin_comment
comment|// S-X86_64-6: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-X86_64-6: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-X86_64-6: "-lgcc_eh" "-lc" "-lgcc"
end_comment

begin_comment
comment|// S-X86_64-6: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

end_unit

