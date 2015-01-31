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
comment|// RUN: %clang -no-canonical-prefixes -target aarch64--netbsd \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=AARCH64 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target aarch64--netbsd7.0.0 \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=AARCH64-7 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target arm--netbsd-eabi \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=ARM %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target armeb--netbsd-eabi \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=ARMEB %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target armeb--netbsd-eabi -march=armv7 \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=ARMV7EB %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target armv7eb--netbsd-eabi \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=ARMV7EB %s
end_comment

begin_comment
comment|// RUN: %clang -r -no-canonical-prefixes -target armeb--netbsd-eabi \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=ARMEB-R %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target arm--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=ARM-APCS %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target arm--netbsd-eabihf \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=ARM-HF %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target thumb--netbsd-eabi \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target thumbeb--netbsd-eabi \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=THUMBEB %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target arm--netbsd7.0.0-eabi \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=ARM-7 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target arm--netbsd6.0.0-eabi \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=ARM-6 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target sparc64--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC64 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target powerpc--netbsd \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=POWERPC %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target powerpc64--netbsd \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=POWERPC64 %s
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
comment|// RUN: %clang -no-canonical-prefixes -target aarch64--netbsd -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-AARCH64 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target aarch64--netbsd7.0.0 -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-AARCH64-7 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target arm--netbsd-eabi -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-ARM %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target armeb--netbsd-eabi -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-ARMEB %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target arm--netbsd7.0.0-eabi -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-ARM-7 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target arm--netbsd6.0.0-eabi -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-ARM-6 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target sparc--netbsd -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-SPARC %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target sparc64--netbsd -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-SPARC64 %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target powerpc--netbsd -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-POWERPC %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target powerpc64--netbsd -static \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=S-POWERPC64 %s
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
comment|// X86_64-6: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// AARCH64: clang{{.*}}" "-cc1" "-triple" "aarch64--netbsd"
end_comment

begin_comment
comment|// AARCH64: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// AARCH64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// AARCH64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// AARCH64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// AARCH64-7: clang{{.*}}" "-cc1" "-triple" "aarch64--netbsd7.0.0"
end_comment

begin_comment
comment|// AARCH64-7: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// AARCH64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// AARCH64-7:  "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// AARCH64-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// ARM: clang{{.*}}" "-cc1" "-triple" "armv5e--netbsd-eabi"
end_comment

begin_comment
comment|// ARM: as{{.*}}" "-mcpu=arm926ej-s" "-o"
end_comment

begin_comment
comment|// ARM: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// ARM: "-m" "armelf_nbsd_eabi"
end_comment

begin_comment
comment|// ARM: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// ARM: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// ARM: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// ARM: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// ARMEB: clang{{.*}}" "-cc1" "-triple" "armebv5e--netbsd-eabi"
end_comment

begin_comment
comment|// ARMEB: as{{.*}}" "-mcpu=arm926ej-s" "-o"
end_comment

begin_comment
comment|// ARMEB: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// ARMEB-NOT: "--be8"
end_comment

begin_comment
comment|// ARMEB: "-m" "armelfb_nbsd_eabi"
end_comment

begin_comment
comment|// ARMEB: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// ARMEB: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// ARMEB: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// ARMEB: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// ARMV7EB: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// ARMV7EB: "--be8" "-m" "armelfb_nbsd_eabi"
end_comment

begin_comment
comment|// ARMEB-R: ld{{.*}}"
end_comment

begin_comment
comment|// ARMEB-R-NOT: "--be8"
end_comment

begin_comment
comment|// ARM-APCS: clang{{.*}}" "-cc1" "-triple" "armv4--netbsd"
end_comment

begin_comment
comment|// ARM-APCS: as{{.*}}" "-mcpu=strongarm" "-o"
end_comment

begin_comment
comment|// ARM-APCS: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// ARM-APCS: "-m" "armelf_nbsd"
end_comment

begin_comment
comment|// ARM-APCS: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// ARM-APCS: "{{.*}}/usr/lib{{/|\\\\}}oabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// ARM-APCS: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// ARM-APCS: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// ARM-HF: clang{{.*}}" "-cc1" "-triple" "armv5e--netbsd-eabihf"
end_comment

begin_comment
comment|// ARM-HF: as{{.*}}" "-mcpu=arm926ej-s" "-o"
end_comment

begin_comment
comment|// ARM-HF: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// ARM-HF: "-m" "armelf_nbsd_eabihf"
end_comment

begin_comment
comment|// ARM-HF: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// ARM-HF: "{{.*}}/usr/lib{{/|\\\\}}eabihf{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// ARM-HF: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// ARM-HF: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// THUMB: clang{{.*}}" "-cc1" "-triple" "armv5e--netbsd-eabi"
end_comment

begin_comment
comment|// THUMB: as{{.*}}" "-mcpu=arm926ej-s" "-o"
end_comment

begin_comment
comment|// THUMB: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// THUMB: "-m" "armelf_nbsd_eabi"
end_comment

begin_comment
comment|// THUMB: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// THUMB: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// THUMB: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// THUMB: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// THUMBEB: clang{{.*}}" "-cc1" "-triple" "armebv5e--netbsd-eabi"
end_comment

begin_comment
comment|// THUMBEB: as{{.*}}" "-mcpu=arm926ej-s" "-o"
end_comment

begin_comment
comment|// THUMBEB: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// THUMBEB: "-m" "armelfb_nbsd_eabi"
end_comment

begin_comment
comment|// THUMBEB: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// THUMBEB: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// THUMBEB: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// THUMBEB: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// ARM-7: clang{{.*}}" "-cc1" "-triple" "armv5e--netbsd7.0.0-eabi"
end_comment

begin_comment
comment|// ARM-7: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// ARM-7: "-m" "armelf_nbsd_eabi"
end_comment

begin_comment
comment|// ARM-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// ARM-7: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// ARM-7:  "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// ARM-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// ARM-6: clang{{.*}}" "-cc1" "-triple" "armv5e--netbsd6.0.0-eabi"
end_comment

begin_comment
comment|// ARM-6: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// ARM-6: "-m" "armelf_nbsd_eabi"
end_comment

begin_comment
comment|// ARM-6: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// ARM-6: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// ARM-6: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// ARM-6: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// SPARC: clang{{.*}}" "-cc1" "-triple" "sparc--netbsd"
end_comment

begin_comment
comment|// SPARC: as{{.*}}" "-32" "-o"
end_comment

begin_comment
comment|// SPARC: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// SPARC: "-m" "elf32_sparc"
end_comment

begin_comment
comment|// SPARC: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// SPARC: "{{.*}}/usr/lib{{/|\\\\}}sparc{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// SPARC: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// SPARC: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// SPARC64: clang{{.*}}" "-cc1" "-triple" "sparc64--netbsd"
end_comment

begin_comment
comment|// SPARC64: as{{.*}}" "-64" "-Av9" "-o"
end_comment

begin_comment
comment|// SPARC64: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// SPARC64: "-m" "elf64_sparc"
end_comment

begin_comment
comment|// SPARC64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// SPARC64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// SPARC64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// POWERPC: clang{{.*}}" "-cc1" "-triple" "powerpc--netbsd"
end_comment

begin_comment
comment|// POWERPC: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// POWERPC: "-m" "elf32ppc_nbsd"
end_comment

begin_comment
comment|// POWERPC: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// POWERPC: "{{.*}}/usr/lib{{/|\\\\}}powerpc{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// POWERPC: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// POWERPC: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// POWERPC64: clang{{.*}}" "-cc1" "-triple" "powerpc64--netbsd"
end_comment

begin_comment
comment|// POWERPC64: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
end_comment

begin_comment
comment|// POWERPC64: "-m" "elf64ppc"
end_comment

begin_comment
comment|// POWERPC64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// POWERPC64: "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// POWERPC64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// POWERPC64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-X86_64: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd"
end_comment

begin_comment
comment|// S-X86_64: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
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
comment|// S-X86_64-7: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
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
comment|// S-X86_64-6: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
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

begin_comment
comment|// S-AARCH64: clang{{.*}}" "-cc1" "-triple" "aarch64--netbsd"
end_comment

begin_comment
comment|// S-AARCH64: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-AARCH64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-AARCH64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-AARCH64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-AARCH64-7: clang{{.*}}" "-cc1" "-triple" "aarch64--netbsd7.0.0"
end_comment

begin_comment
comment|// S-AARCH64-7: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-AARCH64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-AARCH64-7: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-AARCH64-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-ARM: clang{{.*}}" "-cc1" "-triple" "armv5e--netbsd-eabi"
end_comment

begin_comment
comment|// S-ARM: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-ARM: "-m" "armelf_nbsd_eabi"
end_comment

begin_comment
comment|// S-ARM: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// S-ARM: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-ARM: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-ARM: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-ARMEB: clang{{.*}}" "-cc1" "-triple" "armebv5e--netbsd-eabi"
end_comment

begin_comment
comment|// S-ARMEB: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-ARMEB: "-m" "armelfb_nbsd_eabi"
end_comment

begin_comment
comment|// S-ARMEB: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// S-ARMEB: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-ARMEB: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-ARMEB: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-ARM-7: clang{{.*}}" "-cc1" "-triple" "armv5e--netbsd7.0.0-eabi"
end_comment

begin_comment
comment|// S-ARM-7: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-ARM-7: "-m" "armelf_nbsd_eabi"
end_comment

begin_comment
comment|// S-ARM-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// S-ARM-7: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-ARM-7: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-ARM-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-ARM-6: clang{{.*}}" "-cc1" "-triple" "armv5e--netbsd6.0.0-eabi"
end_comment

begin_comment
comment|// S-ARM-6: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-ARM-6: "-m" "armelf_nbsd_eabi"
end_comment

begin_comment
comment|// S-ARM-6: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// S-ARM-6: "{{.*}}/usr/lib{{/|\\\\}}eabi{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-ARM-6: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-ARM-6: "-lgcc_eh" "-lc" "-lgcc"
end_comment

begin_comment
comment|// S-ARM-6: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-SPARC: clang{{.*}}" "-cc1" "-triple" "sparc--netbsd"
end_comment

begin_comment
comment|// S-SPARC: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-SPARC: "-m" "elf32_sparc"
end_comment

begin_comment
comment|// S-SPARC: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// S-SPARC: "{{.*}}/usr/lib{{/|\\\\}}sparc{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-SPARC: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-SPARC: "-lgcc_eh" "-lc" "-lgcc"
end_comment

begin_comment
comment|// S-SPARC: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-SPARC64: clang{{.*}}" "-cc1" "-triple" "sparc64--netbsd"
end_comment

begin_comment
comment|// S-SPARC64: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-SPARC64: "-m" "elf64_sparc"
end_comment

begin_comment
comment|// S-SPARC64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-SPARC64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-SPARC64: "-lgcc_eh" "-lc" "-lgcc"
end_comment

begin_comment
comment|// S-SPARC64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-POWERPC: clang{{.*}}" "-cc1" "-triple" "powerpc--netbsd"
end_comment

begin_comment
comment|// S-POWERPC: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-POWERPC: "-m" "elf32ppc_nbsd"
end_comment

begin_comment
comment|// S-POWERPC: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// S-POWERPC: "{{.*}}/usr/lib{{/|\\\\}}powerpc{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-POWERPC: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-POWERPC: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// S-POWERPC64: clang{{.*}}" "-cc1" "-triple" "powerpc64--netbsd"
end_comment

begin_comment
comment|// S-POWERPC64: ld{{.*}}" "--eh-frame-hdr" "-Bstatic"
end_comment

begin_comment
comment|// S-POWERPC64: "-m" "elf64ppc"
end_comment

begin_comment
comment|// S-POWERPC64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
end_comment

begin_comment
comment|// S-POWERPC64: "{{.*}}/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// S-POWERPC64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc"
end_comment

begin_comment
comment|// S-POWERPC64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
end_comment

end_unit

