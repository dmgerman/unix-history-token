begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -### -target x86_64-unknown-cloudabi 2>&1 | FileCheck %s -check-prefix=SAFESTACK
end_comment

begin_comment
comment|// SAFESTACK: "-cc1" "-triple" "x86_64-unknown-cloudabi" {{.*}} "-ffunction-sections" "-fdata-sections" {{.*}} "-fsanitize=safe-stack"
end_comment

begin_comment
comment|// SAFESTACK: "-Bstatic" "--no-dynamic-linker" "-pie" "-zrelro" "--eh-frame-hdr" "--gc-sections" "-o" "a.out" "crt0.o" "crtbegin.o" "{{.*}}" "{{.*}}" "-lc" "-lcompiler_rt" "crtend.o"
end_comment

begin_comment
comment|// RUN: %clang %s -### -target x86_64-unknown-cloudabi -fno-sanitize=safe-stack 2>&1 | FileCheck %s -check-prefix=NOSAFESTACK
end_comment

begin_comment
comment|// NOSAFESTACK: "-cc1" "-triple" "x86_64-unknown-cloudabi" {{.*}} "-ffunction-sections" "-fdata-sections"
end_comment

begin_comment
comment|// NOSAFESTACK-NOT: "-fsanitize=safe-stack"
end_comment

begin_comment
comment|// NOSAFESTACK: "-Bstatic" "--no-dynamic-linker" "-pie" "-zrelro" "--eh-frame-hdr" "--gc-sections" "-o" "a.out" "crt0.o" "crtbegin.o" "{{.*}}" "{{.*}}" "-lc" "-lcompiler_rt" "crtend.o"
end_comment

begin_comment
comment|// PIE shouldn't be enabled on i686. Just on architectures that provide
end_comment

begin_comment
comment|// PC-relative addressing.
end_comment

begin_comment
comment|// RUN: %clang %s -### -target i686-unknown-cloudabi 2>&1 | FileCheck %s -check-prefix=NOPIE
end_comment

begin_comment
comment|// NOPIE: "-cc1" "-triple" "i686-unknown-cloudabi" {{.*}} "-ffunction-sections" "-fdata-sections" {{.*}} "-fsanitize=safe-stack"
end_comment

begin_comment
comment|// NOPIE: "-Bstatic" "--no-dynamic-linker" "--eh-frame-hdr" "--gc-sections" "-o" "a.out" "crt0.o" "crtbegin.o" "{{.*}}" "{{.*}}" "-lc" "-lcompiler_rt" "crtend.o"
end_comment

end_unit

