begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that the driver adds an arch-specific subdirectory in
end_comment

begin_comment
comment|// {RESOURCE_DIR}/lib/linux to the linker search path and to '-rpath'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test the default behavior when neither -frtlib-add-rpath nor
end_comment

begin_comment
comment|// -fno-rtlib-add-rpath is specified, which is to skip -rpath
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-linux \
end_comment

begin_comment
comment|// RUN:     -fsanitize=address -shared-libasan \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-X86_64,NO-RPATH-X86_64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test that -rpath is not added under -fno-rtlib-add-rpath even if other
end_comment

begin_comment
comment|// conditions are met.
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-linux \
end_comment

begin_comment
comment|// RUN:     -fsanitize=address -shared-libasan \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-X86_64,NO-RPATH-X86_64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test that -rpath is added only under the right circumstance even if
end_comment

begin_comment
comment|// -frtlib-add-rpath is specified.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Add LIBPATH but no RPATH for -fsanitizer=address w/o -shared-libasan
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-linux -fsanitize=undefined \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-X86_64,NO-RPATH %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Add LIBPATH but no RPATH for -fsanitizer=address w/o -shared-libasan
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-linux -fsanitize=undefined \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-X86_64,NO-RPATH %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Add LIBPATH, RPATH for -fsanitize=address -shared-libasan
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-linux \
end_comment

begin_comment
comment|// RUN:     -fsanitize=address -shared-libasan \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-X86_64,RPATH-X86_64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Add LIBPATH, RPATH for -fsanitize=address -shared-libasan on aarch64
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target aarch64-linux \
end_comment

begin_comment
comment|// RUN:     -fsanitize=address -shared-libasan \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-AArch64,RPATH-AArch64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Add LIBPATH, RPATH with -fsanitize=address for Android
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-linux-android -fsanitize=address \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-X86_64,RPATH-X86_64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Add LIBPATH, RPATH for OpenMP
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-linux -fopenmp \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-X86_64,RPATH-X86_64 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Add LIBPATH but no RPATH for ubsan (or any other sanitizer)
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -fsanitize=undefined -target x86_64-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-X86_64,NO-RPATH %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Add LIBPATH but no RPATH if no sanitizer or runtime is specified
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir_with_arch_subdir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,LIBPATH-X86_64,NO-RPATH %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Do not add LIBPATH or RPATH if arch-specific subdir doesn't exist
end_comment

begin_comment
comment|// RUN: %clang %s -### 2>&1 -target x86_64-linux \
end_comment

begin_comment
comment|// RUN:     -resource-dir=%S/Inputs/resource_dir \
end_comment

begin_comment
comment|// RUN:     -frtlib-add-rpath \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefixes=RESDIR,NO-LIBPATH,NO-RPATH %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RESDIR: "-resource-dir" "[[RESDIR:[^"]*]]"
end_comment

begin_comment
comment|// LIBPATH-X86_64:  -L[[RESDIR]]{{(/|\\\\)lib(/|\\\\)linux(/|\\\\)x86_64}}
end_comment

begin_comment
comment|// RPATH-X86_64:    "-rpath" "[[RESDIR]]{{(/|\\\\)lib(/|\\\\)linux(/|\\\\)x86_64}}"
end_comment

begin_comment
comment|// LIBPATH-AArch64: -L[[RESDIR]]{{(/|\\\\)lib(/|\\\\)linux(/|\\\\)aarch64}}
end_comment

begin_comment
comment|// RPATH-AArch64:   "-rpath" "[[RESDIR]]{{(/|\\\\)lib(/|\\\\)linux(/|\\\\)aarch64}}"
end_comment

begin_comment
comment|// NO-LIBPATH-NOT:  -L{{.*Inputs(/|\\\\)resource_dir}}
end_comment

begin_comment
comment|// NO-RPATH-NOT:    "-rpath" {{.*(/|\\\\)Inputs(/|\\\\)resource_dir}}
end_comment

end_unit

